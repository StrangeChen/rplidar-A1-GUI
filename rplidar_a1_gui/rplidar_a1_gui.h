#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_rplidar_a1_gui.h"
#include <qserialport.h>
#include <qstring.h>
#include <qbytearray.h>
#include <qserialportinfo.h>
#include <qmessagebox.h>
#include <qtooltip.h>
#include <qdebug.h>
#include <qpainter.h>
#include <qbitmap.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <qthread.h>
#include "rplidar_widget.h"
#include "rplidar.h"
#include <qevent.h>
enum class UartState { ON, OFF };

class rplidar_a1_gui : public QMainWindow
{
	Q_OBJECT

public:
	rplidar_a1_gui(QWidget *parent = Q_NULLPTR);
	~rplidar_a1_gui(void);

protected:
	void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_uart_rfresh_clicked();

    void on_pushButton_uart_sw_clicked();

    void on_pushButton_lidar_sw_clicked();

    void on_pushButton_lidar_rfresh_clicked();

signals:
	void startRadar(QString com);
signals:
	void stopRadar(void);

private:
	void uartInit(void);

	void uartSendCommand(char cmd, int data1 = 0, int data2 = 0, int data3 = 0);

	Ui::rplidar_a1_guiClass ui;

	//���ڽ��պ����߳�
	UartState currentUartState = UartState::OFF;
	QSerialPort *currentSerialPort;
	//�״Ｐ�䴮��
	UartState rplidarUartState = UartState::OFF;
	Rplidar *rplidar;
	QThread *rplidarThread;
	int showTimerId;
};
