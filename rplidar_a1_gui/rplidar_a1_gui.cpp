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
}

void rplidar_a1_gui::on_pushButton_uart_rfresh_clicked()
{

}

void rplidar_a1_gui::on_pushButton_uart_sw_clicked()
{

}

void rplidar_a1_gui::on_pushButton_lidar_sw_clicked()
{

}

void rplidar_a1_gui::on_pushButton_lidar_rfresh_clicked()
{

}
