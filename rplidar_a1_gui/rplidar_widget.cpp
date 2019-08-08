#include "rplidar_widget.h"
#include <QPainter>
#include <QTimerEvent>
#include <QConicalGradient>
#include <qDebug>
#include <qthread.h>

const float PI = (float)3.14159265;
RplidarWidget::RplidarWidget(QWidget *parent)
	: QWidget(parent)
{
	//初始化
	m_pieRotate = 0;
	m_timerId = -1;
	m_nSpeed = 50;
	//启动定时器
	m_timerId = startTimer(m_nSpeed);
}
RplidarWidget::~RplidarWidget()
{
}

void RplidarWidget::showPoint(QList<QPoint> p)
{
	m_points = p;
	update();
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
	m_pieRotate -= 30;
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
			painter.setPen(QPen(QColor(Qt::red), 3));
			//x()-->angle y()-->distance
			int offsetX = m_drawArea.center().x() + cos(m_points[i].x() *PI / 180.0)*m_points[i].y() / 1000 * len / 2;
			int offsetY = m_drawArea.center().y() + sin(m_points[i].x() *PI / 180.0)*m_points[i].y() / 1000 * len / 2;
			painter.drawPoint(offsetX, offsetY);
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
		//m_pieRotate -= 10;
		//update();
	}
}