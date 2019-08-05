#include "rplidar_a1_gui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	rplidar_a1_gui w;
	w.show();
	return a.exec();
}
