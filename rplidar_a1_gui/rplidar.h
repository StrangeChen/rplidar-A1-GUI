#pragma once

#include "rptypes.h"
#include "rplidar_protocol.h"
#include "rplidar_cmd.h"

#include "rplidar_driver.h"

#define RPLIDAR_SDK_VERSION  "1.5.7"

#include <QObject>
#include <QMetaType>
#include <qpoint.h>
#include <Windows.h>

#ifndef _countof
#define _countof(_Array) (int)(sizeof(_Array) / sizeof(_Array[0]))
#endif

#define delay(x)   ::Sleep(x)

Q_DECLARE_METATYPE(QList<QPoint>);
using namespace rp::standalone::rplidar;

struct scanDot {
	_u8   quality;
	float angle;
	float dist;
};

class Rplidar : public QObject
{
	Q_OBJECT

public:
	Rplidar();
	~Rplidar();
	void setCom(QString com);
	//Í£Ö¹À×´ï
	void setStop(bool v);

	void startScan(QString com);

signals:
	void scanCompleted(QList<QPoint> point);
	void reportError(QString _err);
	void sendNearestPoint(char cmd, int d1, int d2, int d3);
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
	QList<QPoint> m_points;        //»æÖÆµã
};

