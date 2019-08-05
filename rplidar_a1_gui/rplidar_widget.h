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
	//停止雷达
	void setStop(bool v);

	void startScan(QString com);

signals:
	//void completeScan(QList<QPoint> point);
	void reportError(QString _err);
	void sendNearestPoint(char cmd, int d1, int d2, int d3);

protected:
	void paintEvent(QPaintEvent *event);    //绘制事件
	void resizeEvent(QResizeEvent *event);  //大小重置事件
	void timerEvent(QTimerEvent *event);    //定时器事件

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

	QRect         m_drawArea;      //绘制区域
	int           m_pieRotate;     //扇形旋转区域
	int           m_timerId;       //定时器ID
	int           m_pointTimerId;  //变更点定时器
	int           m_nSpeed;        //速度
	QList<QPoint> m_points;        //绘制点
	QList<int>    m_pointsAlapha;  //绘制点颜色alapha值
};
