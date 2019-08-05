#pragma once

#include <QWidget>
#include <qdebug.h>
#include <rplidar.h>
#include <Windows.h>

#ifndef _countof
#define _countof(_Array) (int)(sizeof(_Array) / sizeof(_Array[0]))
#endif

//#define delay(x)   ::Sleep(x)
using namespace rp::standalone::rplidar;

struct scanDot {
	_u8   quality;
	float angle;
	float dist;
};

class RplidarWidget : public QWidget
{
	Q_OBJECT

public:
	RplidarWidget(QWidget *parent);
	~RplidarWidget();

	void setCom(QString com);
	//ֹͣ�״�
	void setStop(bool v);

	void startScan(QString com);

signals:
	//void completeScan(QList<QPoint> point);
	void reportError(QString _err);
	void sendNearestPoint(char cmd, int d1, int d2, int d3);

protected:
	void paintEvent(QPaintEvent *event);    //�����¼�
	void resizeEvent(QResizeEvent *event);  //��С�����¼�
	void timerEvent(QTimerEvent *event);    //��ʱ���¼�

private:
	bool checkRPLIDARHealth(RPlidarDriver * drv);

	void getNearest();

	bool stop = false;
	const char * opt_com_path = NULL;
	_u32         opt_com_baudrate = 115200;
	u_result     op_result;
	RPlidarDriver * drv;
	rplidar_response_measurement_node_t nodes[360 * 2];
	std::vector<scanDot> _scan_data;

	QRect         m_drawArea;      //��������
	int           m_pieRotate;     //������ת����
	int           m_timerId;       //��ʱ��ID
	int           m_pointTimerId;  //����㶨ʱ��
	int           m_nSpeed;        //�ٶ�
	QList<QPoint> m_points;        //���Ƶ�
	QList<int>    m_pointsAlapha;  //���Ƶ���ɫalaphaֵ
};
