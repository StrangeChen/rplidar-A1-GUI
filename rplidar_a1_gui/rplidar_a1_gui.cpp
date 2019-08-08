#include "rplidar_a1_gui.h"

rplidar_a1_gui::rplidar_a1_gui(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QString qss;
	qss.append(u8"QObject{font-family:΢���ź�;color:#192e4b}");
	qss.append("QPushButton{ padding:0px;  border-radius:5px; color:#FFFFFF; background:#4c73a8; border:2px solid #4c73a8; }");
	qss.append("QPushButton:hover{color:#4c73a8;background:#88b5f1;}");
	qss.append("QPushButton:pressed{color:#FFFFFF;background:#CCCCCC;}");
	qss.append("QPushButton:disabled{color:#CCCCCC;background:#999999;}");
	qss.append("QTabWidget{color:#FFFFFF; background:#4c73a8;}QTabWidget::tab-bar{left:5px}QTabBar::tab{color:#FFFFFF; background:#4c73a8;width:100px;height:25px;border:2px solid #4c73a8;border-radius:2px}");
	qss.append("QTabBar::tab:hover{color:#4c73a8; background:#FFFFFF;}QTabBar::tab:selected{color:#4c73a8; background:#FFFFFF;}");
	qApp->setStyleSheet(qss);

	currentSerialPort = new QSerialPort(this);
	rplidar = new Rplidar();
	rplidarThread = new QThread(this);
	rplidar->moveToThread(rplidarThread);
	//�����߳̿�ʼ
	rplidarThread->start();

	uartInit();
	qDebug() << u8"���߳�" << QThread::currentThread() << endl;
	qDebug() << rplidarThread->isRunning() << endl;
	qDebug() << rplidar->thread() << endl;
	// �״￪ʼ
	connect(this, &rplidar_a1_gui::startRadar, rplidar, &Rplidar::startScan);
	//�״ﱨ��
	connect(rplidar, &Rplidar::reportError, this, [this](QString err) {QMessageBox::critical(this, tr("Error"), err); });
	//�״ﴦ�����
	connect(rplidar, &Rplidar::sendNearestPoint, this, &rplidar_a1_gui::uartSendCommand);
	connect(rplidar, &Rplidar::scanCompleted, ui.rplidarWidget, &RplidarWidget::showPoint);
}

rplidar_a1_gui::~rplidar_a1_gui(void)
{
	currentSerialPort->deleteLater();
	rplidar->deleteLater();
	rplidarThread->deleteLater();
}

void rplidar_a1_gui::closeEvent(QCloseEvent *e)
{
	if (currentUartState == UartState::ON)
		//currentSerialPort-
		currentSerialPort->close();
	if (rplidarThread->isRunning())
	{
		rplidar->setStop(true);
		rplidarThread->quit();
		rplidarThread->wait();
	}
	e->accept();
}

void rplidar_a1_gui::on_pushButton_uart_rfresh_clicked()
{
	if (currentUartState == UartState::ON || rplidarUartState == UartState::ON)
		QToolTip::showText(QCursor::pos(), tr("Please turn off the current device first."));
	else
		uartInit();
}

void rplidar_a1_gui::on_pushButton_uart_sw_clicked()
{
	if (currentUartState == UartState::ON)
	{
		currentSerialPort->close();
		currentUartState = UartState::OFF;
		ui.pushButton_uart_sw->setText(QString::fromUtf8(u8"�򿪴���"));

		ui.comboBox_com->setEnabled(true);
		ui.comboBox_baud->setEnabled(true);
	}
	else
	{
		currentSerialPort->setPortName(ui.comboBox_com->currentText().split(':').at(0));
		currentSerialPort->setBaudRate(ui.comboBox_baud->currentText().toInt());
		//Ĭ�ϲ�������
		currentSerialPort->setFlowControl(QSerialPort::NoFlowControl);// ��������
		currentSerialPort->setDataBits(QSerialPort::Data8);//����Ϊ 8
		currentSerialPort->setStopBits(QSerialPort::OneStop);//ֹͣλһλ
		currentSerialPort->setParity(QSerialPort::NoParity);//��У��λ
		currentSerialPort->setReadBufferSize(10); //���ջ���10���ֽ�

		if (currentSerialPort->open(QSerialPort::ReadWrite))
		{
			currentUartState = UartState::ON;

			ui.pushButton_uart_sw->setText(u8"�رմ���");
			ui.comboBox_com->setEnabled(false);
			ui.comboBox_baud->setEnabled(false);
		}
		else {
			QMessageBox::critical(this, tr("Error"), tr("Fail to turn on this device!"));
		}
	}
}

void rplidar_a1_gui::on_pushButton_lidar_sw_clicked()
{
	qDebug() << u8"���߳�" << QThread::currentThread() << endl;
	if (currentUartState == UartState::OFF)
		QToolTip::showText(QCursor::pos(), u8"���ȴ�ͨ�Ŵ���");
	else
	{
		if (rplidarUartState == UartState::ON)
		{
			rplidarUartState = UartState::OFF;
			ui.pushButton_lidar_sw->setText(QString::fromUtf8(u8"��ʼ"));
			ui.comboBox_rplidar->setEnabled(true);
			//�ر��߳�
			if (rplidarThread->isRunning())
			{
				rplidar->setStop(true);
				rplidarThread->quit();
				rplidarThread->wait();
			}
		}
		else
		{
			qDebug() << ui.comboBox_rplidar->currentText().split(':').at(0);
			rplidarUartState = UartState::ON;
			rplidarThread->start();
			rplidar->setStop(false);
			emit startRadar(ui.comboBox_rplidar->currentText().split(':').at(0));
			ui.pushButton_lidar_sw->setText(u8"ֹͣ");
			ui.comboBox_rplidar->setEnabled(false);
		}
	}
}

void rplidar_a1_gui::on_pushButton_lidar_rfresh_clicked()
{
	if (currentUartState == UartState::ON || rplidarUartState == UartState::ON)
		QToolTip::showText(QCursor::pos(), tr("Please turn off the current device first."));
	else
		uartInit();
}

void rplidar_a1_gui::uartInit(void)
{
	currentUartState = UartState::OFF;
	rplidarUartState = UartState::OFF;
	/* ���п��ô��� */
	ui.comboBox_com->clear();
	ui.comboBox_rplidar->clear();
	foreach(auto const &info, QSerialPortInfo::availablePorts())
	{
		ui.comboBox_com->addItem(info.portName() + ": " + info.description());
		ui.comboBox_rplidar->addItem(info.portName() + ": " + info.description());
	}

	ui.comboBox_com->setCurrentIndex(0);
	ui.comboBox_com->setToolTip(ui.comboBox_com->currentText());

	ui.comboBox_rplidar->setCurrentIndex(0);
	ui.comboBox_rplidar->setToolTip(ui.comboBox_com->currentText());
}
/*��λ������λ������Э��
*	��ʼ1	��ʼ2	������	����1	����1	����2	����2	����3	����3	У���
*	@(0x40) ^(0x5E)	cmd		H1		L2		H2		L2		H3		L3		sum
* SUM = 0x40 + 0x5E + cmd + H1 + L1 + H2 + L2 + H3 + L3
*/
void rplidar_a1_gui::uartSendCommand(char cmd, int data1, int data2, int data3)
{
	ui.lineEdit_a->setText(QString::number(data1));
	ui.lineEdit_d->setText(QString::number(data2));
	char sendData[10];
	sendData[0] = '@';
	sendData[1] = '^';
	sendData[2] = cmd;
	sendData[3] = (data1 >> 8) & 0xff;
	sendData[4] = data1 & 0xff;
	sendData[5] = (data2 >> 8) & 0xff;
	sendData[6] = data2 & 0xff;
	sendData[7] = (data2 >> 8) & 0xff;
	sendData[8] = data3 & 0xff;
	sendData[9] = 0;
	for (int i = 0; i < 9; i++)
		sendData[9] += sendData[i];
	//qDebug() << int(sendData[9]) << endl;
	currentSerialPort->write(sendData, 10);
}
