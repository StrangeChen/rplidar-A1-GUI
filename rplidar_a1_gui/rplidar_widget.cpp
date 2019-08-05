#include "rplidar_widget.h"
#include <QPainter>
#include <QTimerEvent>
#include <QConicalGradient>
#include <qDebug>
#include <qthread.h>

#include <signal.h>
bool ctrl_c_pressed;
void ctrlc(int)
{
	ctrl_c_pressed = true;
}

const float PI = (float)3.14159265;
RplidarWidget::RplidarWidget(QWidget *parent):
	QWidget(parent)
{
	//初始化
	m_pieRotate = 0;
	m_timerId = -1;
	m_nSpeed = 50;

	drv = RPlidarDriver::CreateDriver(RPlidarDriver::DRIVER_TYPE_SERIALPORT);
	//启动定时器
	m_timerId = startTimer(m_nSpeed);
}

RplidarWidget::~RplidarWidget()
{
	RPlidarDriver::DisposeDriver(drv);
}

void RplidarWidget::setCom(QString com)
{
	std::string tem;
	tem = com.toLower().toLatin1().toStdString();
	tem = "\\\\.\\" + tem;
	const char *_com = tem.c_str();
	qDebug() << _com << endl;
	//"\\\\.\\com3"
	opt_com_path = tem.c_str();
	//opt_com_path = "\\\\.\\com5";

	qDebug() << opt_com_path << endl;
}

void RplidarWidget::setStop(bool v)
{
	stop = v;
}

void RplidarWidget::startScan(QString com)
{
	std::string tem;
	tem = com.toLower().toLatin1().toStdString();
	tem = "\\\\.\\" + tem;
	opt_com_path = tem.c_str();

	//opt_com_path = "\\\\.\\com5";
	//qDebug() << u8"雷达线程" << QThread::currentThread() << endl;

	if (!drv)
	{
		/*fprintf(stderr, "insufficent memory, exit\n");
		exit(-2);*/

		qDebug() << "insufficent memory, exit\n";
		emit reportError("insufficent memory, exit");
		//QMessageBox::critical()
	}

	// make connection...
	if (IS_FAIL(drv->connect(opt_com_path, opt_com_baudrate)))
	{
		//fprintf(stderr, "Error, cannot bind to the specified serial port %s.\n"		, opt_com_path);
		qDebug() << "Error, cannot bind to the specified serial port " << opt_com_path << endl;
		emit reportError("Error, cannot bind to the specified serial port " + com);

		RPlidarDriver::DisposeDriver(drv);
		drv = RPlidarDriver::CreateDriver(RPlidarDriver::DRIVER_TYPE_SERIALPORT);
		return;
	}


	// check health...
	if (!checkRPLIDARHealth(drv))
	{
		RPlidarDriver::DisposeDriver(drv);
		drv = RPlidarDriver::CreateDriver(RPlidarDriver::DRIVER_TYPE_SERIALPORT);
		return;
	}

	signal(SIGINT, ctrlc);

	drv->startMotor();
	// start scan...
	drv->startScan();

	// fetech result and print it out...
	while (false == stop)
	{
		rplidar_response_measurement_node_t nodes[360 * 2];
		size_t   count = _countof(nodes);

		op_result = drv->grabScanData(nodes, count);

		if (IS_OK(op_result))
		{
			drv->ascendScanData(nodes, count);
			_scan_data.clear();
			for (int pos = 0; pos < (int)count; ++pos)
			{
				scanDot dot;
				/*qDebug() << ((nodes[pos].sync_quality & RPLIDAR_RESP_MEASUREMENT_SYNCBIT) ? "S " : "  ")
					<< "theta:"<< (nodes[pos].angle_q6_checkbit >> RPLIDAR_RESP_MEASUREMENT_ANGLE_SHIFT) / 64.0f
					<<" Dist: "<< nodes[pos].distance_q2 / 4.0f
					<< "Q:" << (nodes[pos].sync_quality >> RPLIDAR_RESP_MEASUREMENT_QUALITY_SHIFT) << endl;
				*/
				dot.quality = (nodes[pos].sync_quality >> RPLIDAR_RESP_MEASUREMENT_QUALITY_SHIFT);
				dot.angle = (nodes[pos].angle_q6_checkbit >> RPLIDAR_RESP_MEASUREMENT_ANGLE_SHIFT) / 64.0f;
				dot.dist = nodes[pos].distance_q2 / 4.0f;
				_scan_data.push_back(dot);

			}
			getNearest();
		}

		if (ctrl_c_pressed)
			break;
	}
	drv->stop();
	drv->stopMotor();
}

void RplidarWidget::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	//抗锯齿
	painter.setRenderHint(QPainter::Antialiasing);
	//背景
	//painter.fillRect(rect(), QColor(15, 45, 188));
	//painter.fillRect(rect(), QColor(Qt::black));

	//边长
	int len = m_drawArea.width();

	//底盘(x轴、y轴和3个圆)
	painter.setPen(QPen(Qt::white));
	painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
	painter.drawEllipse(m_drawArea.center(), len / 2, len / 2);
	painter.drawEllipse(m_drawArea.center(), len / 3, len / 3);
	painter.drawEllipse(m_drawArea.center(), len / 6, len / 6);
	painter.drawLine(m_drawArea.topLeft() + QPoint(0, len / 2), m_drawArea.topRight() + QPoint(0, len / 2));
	painter.drawLine(m_drawArea.topLeft() + QPoint(len / 2, 0), m_drawArea.bottomLeft() + QPoint(len / 2, 0));

	//转动部分
	//---//线
	qreal x = m_drawArea.center().x() + (qreal)len / 2 * cos(-m_pieRotate * 3.14159 / 180);
	qreal y = m_drawArea.center().y() + (qreal)len / 2 * sin(-m_pieRotate * 3.14159 / 180);
	painter.setPen(QPen(Qt::white));
	painter.drawLine(m_drawArea.center(), QPointF(x, y));

	//----//扇形
	QConicalGradient gradient;
	gradient.setCenter(m_drawArea.center());
	gradient.setAngle(m_pieRotate + 180); //渐变与旋转方向恰好相反，以扇形相反的边作为渐变角度。
	gradient.setColorAt(0.4, QColor(255, 255, 255, 100)); //从渐变角度开始0.5 - 0.75为扇形区域，由于Int类型计算不精确，将范围扩大到0.4-0.8
	gradient.setColorAt(0.8, QColor(255, 255, 255, 0));
	painter.setBrush(QBrush(gradient));
	painter.setPen(Qt::NoPen);
	painter.drawPie(m_drawArea, m_pieRotate * 16, 90 * 16);

	if (!m_points.isEmpty())
	{
		for (int i = 0; i < m_points.count(); ++i)
		{
			//int colorAlaph = m_pointsAlapha.at(i);
			//painter.setPen(QPen(QColor(255, 255, 255, colorAlaph), 3));
			painter.setPen(QPen(QColor(Qt::red), 3));
			painter.drawPoint(m_points.at(i));
		}
	}
}

void RplidarWidget::resizeEvent(QResizeEvent * event)
{
	//以较短的边长作为绘制区域边长
	if (width() > height())
	{
		m_drawArea = QRect((width() - height()) / 2, 0, height(), height());
	}
	else
	{
		m_drawArea = QRect(0, (height() - width()) / 2, width(), width());
	}

	m_drawArea.adjust(10, 10, -10, -10);
}

void RplidarWidget::timerEvent(QTimerEvent * event)
{
	if (m_timerId == event->timerId())
	{
		m_pieRotate -= 10;
		update();
	}
}

bool RplidarWidget::checkRPLIDARHealth(RPlidarDriver * drv)
{
	u_result     op_result;
	rplidar_response_device_health_t healthinfo;

	op_result = drv->getHealth(healthinfo);
	if (IS_OK(op_result))
	{ // the macro IS_OK is the preperred way to judge whether the operation is succeed.
		//printf("RPLidar health status : %d\n", healthinfo.status);
		qDebug() << "RPLidar health status :" << healthinfo.status << endl;
		//emit reportError("RPLidar health status :"  + healthinfo.status);
		if (healthinfo.status == RPLIDAR_STATUS_ERROR)
		{
			//fprintf(stderr, "Error, rplidar internal error detected. Please reboot the device to retry.\n");
			qDebug() << "Error, rplidar internal error detected. Please reboot the device to retry.\n";
			emit reportError("Error, rplidar internal error detected. Please reboot the device to retry.");
			// enable the following code if you want rplidar to be reboot by software
			// drv->reset();
			return false;
		}
		else
			return true;

	}
	else
	{
		//fprintf(stderr, "Error, cannot retrieve the lidar health code: %x\n", op_result);
		qDebug() << "Error, cannot retrieve the lidar health code:" << op_result << endl;
		emit reportError("Error, cannot retrieve the lidar health code: " + QString::number(op_result));
		return false;
	}
}

void RplidarWidget::getNearest()
{
	float min_dep = 5000, min_ang = 0;							//最近点角度、距离（实际位置）
	float dep_pre = 5000, ang_pre = 240;						//前一个采样点角度、距离
	m_points.clear();
	for (int pos = 0; pos < (int)_scan_data.size(); ++pos)
	{
		float rad = (float)(_scan_data[pos].angle*PI / 180.0);

		if (rad < 5.23599f && rad>4.18879f)
		{
			if (_scan_data[pos].dist > 10)
			{
				//取最近点
				if (min_dep > _scan_data[pos].dist)
				{
					min_dep = _scan_data[pos].dist;
					min_ang = _scan_data[pos].angle;
				}
			}
			if (_scan_data[pos].dist < 1000)
			{
				int offsetX = 350 / 2 + cos(_scan_data[pos].angle*PI / 180.0)*_scan_data[pos].dist / 1000 * 350 / 2;
				int offsetY = 350 / 2 + sin(_scan_data[pos].angle*PI / 180.0)*_scan_data[pos].dist / 1000 * 350 / 2;
				m_points << QPoint(offsetX, offsetY);
			}
		}
	}

	emit sendNearestPoint('r', min_ang, min_dep, 0);
}
