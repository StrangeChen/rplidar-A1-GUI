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
	//��ʼ��
	m_pieRotate = 0;
	m_timerId = -1;
	m_nSpeed = 50;
	//������ʱ��
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
	//�����
	painter.setRenderHint(QPainter::Antialiasing);
	//����
	//painter.fillRect(rect(), QColor(15, 45, 188));
	//painter.fillRect(rect(), QColor(Qt::black));
	//�߳�
	int len = m_drawArea.width();
	//����(x�ᡢy���3��Բ)
	painter.setPen(QPen(Qt::white));
	painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
	painter.drawEllipse(m_drawArea.center(), len / 2, len / 2);
	painter.drawEllipse(m_drawArea.center(), len / 3, len / 3);
	painter.drawEllipse(m_drawArea.center(), len / 6, len / 6);
	painter.drawLine(m_drawArea.topLeft() + QPoint(0, len / 2), m_drawArea.topRight() + QPoint(0, len / 2));
	painter.drawLine(m_drawArea.topLeft() + QPoint(len / 2, 0), m_drawArea.bottomLeft() + QPoint(len / 2, 0));

	//ת������
	//---//��
	m_pieRotate -= 30;
	qreal x = m_drawArea.center().x() + (qreal)len / 2 * cos(-m_pieRotate * 3.14159 / 180);
	qreal y = m_drawArea.center().y() + (qreal)len / 2 * sin(-m_pieRotate * 3.14159 / 180);
	painter.setPen(QPen(Qt::white));
	painter.drawLine(m_drawArea.center(), QPointF(x, y));
	//----//����
	QConicalGradient gradient;
	gradient.setCenter(m_drawArea.center());
	gradient.setAngle(m_pieRotate + 180); //��������ת����ǡ���෴���������෴�ı���Ϊ����Ƕȡ�
	gradient.setColorAt(0.4, QColor(255, 255, 255, 100)); //�ӽ���Ƕȿ�ʼ0.5 - 0.75Ϊ������������Int���ͼ��㲻��ȷ������Χ����0.4-0.8
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
	//�Խ϶̵ı߳���Ϊ��������߳�
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