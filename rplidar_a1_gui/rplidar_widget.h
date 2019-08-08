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
	void paintEvent(QPaintEvent *event);    //�����¼�
	void resizeEvent(QResizeEvent *event);  //��С�����¼�
	void timerEvent(QTimerEvent *event);    //��ʱ���¼�

private:
	QRect         m_drawArea;      //��������
	int           m_pieRotate;     //������ת����
	int           m_timerId;       //��ʱ��ID
	int           m_pointTimerId;  //����㶨ʱ��
	int           m_nSpeed;        //�ٶ�
	QList<QPoint> m_points;        //���Ƶ�
	QList<int>    m_pointsAlapha;  //���Ƶ���ɫalaphaֵ
};
