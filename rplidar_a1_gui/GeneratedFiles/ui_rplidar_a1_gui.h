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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <rplidar_widget.h>

QT_BEGIN_NAMESPACE

class Ui_rplidar_a1_guiClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *label_29;
    QLabel *label_30;
    QComboBox *comboBox_baud;
    QComboBox *comboBox_com;
    QPushButton *pushButton_uart_sw;
    QPushButton *pushButton_uart_rfresh;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_33;
    QComboBox *comboBox_rplidar;
    QPushButton *pushButton_lidar_rfresh;
    QPushButton *pushButton_lidar_sw;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_32;
    QLineEdit *lineEdit_a;
    QLabel *label_31;
    QLineEdit *lineEdit_d;
    RplidarWidget *rplidarWidget;

    void setupUi(QMainWindow *rplidar_a1_guiClass)
    {
        if (rplidar_a1_guiClass->objectName().isEmpty())
            rplidar_a1_guiClass->setObjectName(QStringLiteral("rplidar_a1_guiClass"));
        rplidar_a1_guiClass->resize(612, 746);
        centralWidget = new QWidget(rplidar_a1_guiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setStyleSheet(QStringLiteral(""));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_5->addWidget(label_29, 1, 0, 1, 1);

        label_30 = new QLabel(groupBox);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setMaximumSize(QSize(90, 16777215));

        gridLayout_5->addWidget(label_30, 0, 0, 1, 1);

        comboBox_baud = new QComboBox(groupBox);
        comboBox_baud->addItem(QString());
        comboBox_baud->addItem(QString());
        comboBox_baud->addItem(QString());
        comboBox_baud->setObjectName(QStringLiteral("comboBox_baud"));
        comboBox_baud->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);

        gridLayout_5->addWidget(comboBox_baud, 1, 1, 1, 2);

        comboBox_com = new QComboBox(groupBox);
        comboBox_com->setObjectName(QStringLiteral("comboBox_com"));
        comboBox_com->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);

        gridLayout_5->addWidget(comboBox_com, 0, 1, 1, 2);

        pushButton_uart_sw = new QPushButton(groupBox);
        pushButton_uart_sw->setObjectName(QStringLiteral("pushButton_uart_sw"));
        pushButton_uart_sw->setMinimumSize(QSize(0, 33));
        pushButton_uart_sw->setStyleSheet(QLatin1String("border:1px solid gray;\n"
"        border-radius:10px;\n"
"        padding:2px 4px;"));

        gridLayout_5->addWidget(pushButton_uart_sw, 2, 2, 1, 1);

        pushButton_uart_rfresh = new QPushButton(groupBox);
        pushButton_uart_rfresh->setObjectName(QStringLiteral("pushButton_uart_rfresh"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_uart_rfresh->sizePolicy().hasHeightForWidth());
        pushButton_uart_rfresh->setSizePolicy(sizePolicy1);
        pushButton_uart_rfresh->setMinimumSize(QSize(0, 33));
        pushButton_uart_rfresh->setBaseSize(QSize(0, 0));
        pushButton_uart_rfresh->setLayoutDirection(Qt::LeftToRight);
        pushButton_uart_rfresh->setStyleSheet(QLatin1String("border:1px solid gray;\n"
"        border-radius:10px;\n"
"        padding:2px 4px;"));
        pushButton_uart_rfresh->setIconSize(QSize(12, 12));
        pushButton_uart_rfresh->setCheckable(true);
        pushButton_uart_rfresh->setChecked(false);
        pushButton_uart_rfresh->setAutoExclusive(false);

        gridLayout_5->addWidget(pushButton_uart_rfresh, 2, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 4, 6, 4);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_33 = new QLabel(groupBox_2);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setMaximumSize(QSize(90, 16777215));

        gridLayout->addWidget(label_33, 0, 0, 1, 1);

        comboBox_rplidar = new QComboBox(groupBox_2);
        comboBox_rplidar->setObjectName(QStringLiteral("comboBox_rplidar"));
        comboBox_rplidar->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);

        gridLayout->addWidget(comboBox_rplidar, 0, 1, 1, 2);

        pushButton_lidar_rfresh = new QPushButton(groupBox_2);
        pushButton_lidar_rfresh->setObjectName(QStringLiteral("pushButton_lidar_rfresh"));
        sizePolicy1.setHeightForWidth(pushButton_lidar_rfresh->sizePolicy().hasHeightForWidth());
        pushButton_lidar_rfresh->setSizePolicy(sizePolicy1);
        pushButton_lidar_rfresh->setMinimumSize(QSize(0, 33));
        pushButton_lidar_rfresh->setBaseSize(QSize(0, 0));
        pushButton_lidar_rfresh->setLayoutDirection(Qt::LeftToRight);
        pushButton_lidar_rfresh->setStyleSheet(QLatin1String("border:1px solid gray;\n"
"        border-radius:10px;\n"
"        padding:2px 4px;"));
        pushButton_lidar_rfresh->setIconSize(QSize(12, 12));
        pushButton_lidar_rfresh->setCheckable(true);
        pushButton_lidar_rfresh->setChecked(false);
        pushButton_lidar_rfresh->setAutoExclusive(false);

        gridLayout->addWidget(pushButton_lidar_rfresh, 1, 1, 1, 1);

        pushButton_lidar_sw = new QPushButton(groupBox_2);
        pushButton_lidar_sw->setObjectName(QStringLiteral("pushButton_lidar_sw"));
        sizePolicy1.setHeightForWidth(pushButton_lidar_sw->sizePolicy().hasHeightForWidth());
        pushButton_lidar_sw->setSizePolicy(sizePolicy1);
        pushButton_lidar_sw->setMinimumSize(QSize(0, 33));
        pushButton_lidar_sw->setBaseSize(QSize(0, 0));
        pushButton_lidar_sw->setLayoutDirection(Qt::LeftToRight);
        pushButton_lidar_sw->setStyleSheet(QLatin1String("border:1px solid gray;\n"
"        border-radius:10px;\n"
"        padding:2px 4px;"));
        pushButton_lidar_sw->setIconSize(QSize(12, 12));
        pushButton_lidar_sw->setCheckable(true);
        pushButton_lidar_sw->setChecked(false);
        pushButton_lidar_sw->setAutoExclusive(false);

        gridLayout->addWidget(pushButton_lidar_sw, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_32 = new QLabel(groupBox_2);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(9);
        label_32->setFont(font);

        horizontalLayout_2->addWidget(label_32);

        lineEdit_a = new QLineEdit(groupBox_2);
        lineEdit_a->setObjectName(QStringLiteral("lineEdit_a"));

        horizontalLayout_2->addWidget(lineEdit_a);

        label_31 = new QLabel(groupBox_2);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setMinimumSize(QSize(0, 0));
        label_31->setMaximumSize(QSize(90, 16777215));
        label_31->setFont(font);

        horizontalLayout_2->addWidget(label_31);

        lineEdit_d = new QLineEdit(groupBox_2);
        lineEdit_d->setObjectName(QStringLiteral("lineEdit_d"));

        horizontalLayout_2->addWidget(lineEdit_d);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 2);

        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 2);

        horizontalLayout->addWidget(groupBox_2);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout);

        rplidarWidget = new RplidarWidget(centralWidget);
        rplidarWidget->setObjectName(QStringLiteral("rplidarWidget"));
        rplidarWidget->setMinimumSize(QSize(600, 600));
        rplidarWidget->setAutoFillBackground(false);

        verticalLayout->addWidget(rplidarWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 4);
        rplidar_a1_guiClass->setCentralWidget(centralWidget);

        retranslateUi(rplidar_a1_guiClass);

        QMetaObject::connectSlotsByName(rplidar_a1_guiClass);
    } // setupUi

    void retranslateUi(QMainWindow *rplidar_a1_guiClass)
    {
        rplidar_a1_guiClass->setWindowTitle(QApplication::translate("rplidar_a1_guiClass", "rplidar_a1_gui", nullptr));
        groupBox->setTitle(QApplication::translate("rplidar_a1_guiClass", "\351\200\232\350\256\257\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        label_29->setText(QApplication::translate("rplidar_a1_guiClass", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_30->setText(QApplication::translate("rplidar_a1_guiClass", "\344\270\262\345\217\243\345\217\267", nullptr));
        comboBox_baud->setItemText(0, QApplication::translate("rplidar_a1_guiClass", "115200", nullptr));
        comboBox_baud->setItemText(1, QApplication::translate("rplidar_a1_guiClass", "9600", nullptr));
        comboBox_baud->setItemText(2, QApplication::translate("rplidar_a1_guiClass", "38400", nullptr));

        pushButton_uart_sw->setText(QApplication::translate("rplidar_a1_guiClass", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        pushButton_uart_rfresh->setText(QApplication::translate("rplidar_a1_guiClass", "\345\210\267\346\226\260", nullptr));
        groupBox_2->setTitle(QApplication::translate("rplidar_a1_guiClass", "\351\233\267\350\276\276", nullptr));
        label_33->setText(QApplication::translate("rplidar_a1_guiClass", "\344\270\262\345\217\243\345\217\267", nullptr));
        pushButton_lidar_rfresh->setText(QApplication::translate("rplidar_a1_guiClass", "\345\210\267\346\226\260", nullptr));
        pushButton_lidar_sw->setText(QApplication::translate("rplidar_a1_guiClass", "\345\274\200\345\247\213", nullptr));
        label_32->setText(QApplication::translate("rplidar_a1_guiClass", "\350\247\222\345\272\246", nullptr));
        label_31->setText(QApplication::translate("rplidar_a1_guiClass", "\350\267\235\347\246\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rplidar_a1_guiClass: public Ui_rplidar_a1_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RPLIDAR_A1_GUI_H
