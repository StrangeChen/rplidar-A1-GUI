#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_rplidar_a1_gui.h"

class rplidar_a1_gui : public QMainWindow
{
	Q_OBJECT

public:
	rplidar_a1_gui(QWidget *parent = Q_NULLPTR);

private slots:
    void on_pushButton_uart_rfresh_clicked();

    void on_pushButton_uart_sw_clicked();

    void on_pushButton_lidar_sw_clicked();

    void on_pushButton_lidar_rfresh_clicked();

private:
	Ui::rplidar_a1_guiClass ui;
};
