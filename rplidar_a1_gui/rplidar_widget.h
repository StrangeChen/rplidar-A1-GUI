#pragma once

#include <QWidget>
#include <qdebug.h>


class RplidarWidget : public QWidget
{
	Q_OBJECT

public:
	RplidarWidget(QWidget *parent = nullptr);
	~RplidarWidget();
	void showPoint(QList<QPoint> p);

protected:
	void paintEvent(QPaintEvent *event);    //绘制事件
	void resizeEvent(QResizeEvent *event);  //大小重置事件
	void timerEvent(QTimerEvent *event);    //定时器事件

private:
	QRect         m_drawArea;      //绘制区域
	int           m_pieRotate;     //扇形旋转区域
	int           m_timerId;       //定时器ID
	int           m_pointTimerId;  //变更点定时器
	int           m_nSpeed;        //速度
	QList<QPoint> m_points;        //绘制点
	QList<int>    m_pointsAlapha;  //绘制点颜色alapha值
};
