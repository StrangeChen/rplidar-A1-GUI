/********************************************************************************
** Form generated from reading UI file 'rplidar_a1_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RPLIDAR_A1_GUI_H
#define UI_RPLIDAR_A1_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rplidar_a1_guiClass
{
public:
    QWidget *centralWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *rplidar_a1_guiClass)
    {
        if (rplidar_a1_guiClass->objectName().isEmpty())
            rplidar_a1_guiClass->setObjectName(QStringLiteral("rplidar_a1_guiClass"));
        rplidar_a1_guiClass->resize(600, 400);
        centralWidget = new QWidget(rplidar_a1_guiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        rplidar_a1_guiClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(rplidar_a1_guiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        rplidar_a1_guiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(rplidar_a1_guiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        rplidar_a1_guiClass->setStatusBar(statusBar);

        retranslateUi(rplidar_a1_guiClass);

        QMetaObject::connectSlotsByName(rplidar_a1_guiClass);
    } // setupUi

    void retranslateUi(QMainWindow *rplidar_a1_guiClass)
    {
        rplidar_a1_guiClass->setWindowTitle(QApplication::translate("rplidar_a1_guiClass", "rplidar_a1_gui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rplidar_a1_guiClass: public Ui_rplidar_a1_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RPLIDAR_A1_GUI_H
