/********************************************************************************
** Form generated from reading UI file 'hp_main_task_3.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_MAIN_TASK_3_H
#define UI_HP_MAIN_TASK_3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Main_Task_3
{
public:
    QLabel *task_sd;
    QLabel *task_gps;
    QLabel *task_wifi;
    QLabel *task_headset;
    QLabel *label_battery;
    QLabel *task_usb;
    QLabel *task_ble;
    QLabel *task_4G;

    void setupUi(QWidget *Hp_Main_Task_3)
    {
        if (Hp_Main_Task_3->objectName().isEmpty())
            Hp_Main_Task_3->setObjectName(QStringLiteral("Hp_Main_Task_3"));
        Hp_Main_Task_3->resize(28, 240);
        Hp_Main_Task_3->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        task_sd = new QLabel(Hp_Main_Task_3);
        task_sd->setObjectName(QStringLiteral("task_sd"));
        task_sd->setGeometry(QRect(0, 45, 29, 28));
        task_sd->setMinimumSize(QSize(28, 28));
        task_sd->setMaximumSize(QSize(16777215, 16777215));
        task_sd->setStyleSheet(QStringLiteral("border-image: url(:/res/res/left/main_task_sd.png);"));
        task_gps = new QLabel(Hp_Main_Task_3);
        task_gps->setObjectName(QStringLiteral("task_gps"));
        task_gps->setGeometry(QRect(0, 185, 29, 28));
        task_gps->setMinimumSize(QSize(28, 28));
        task_gps->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(15);
        task_gps->setFont(font);
        task_gps->setStyleSheet(QStringLiteral("border-image: url(:/res/res/left/main_task_beidou.png);"));
        task_gps->setAlignment(Qt::AlignCenter);
        task_wifi = new QLabel(Hp_Main_Task_3);
        task_wifi->setObjectName(QStringLiteral("task_wifi"));
        task_wifi->setGeometry(QRect(0, 73, 29, 28));
        task_wifi->setMinimumSize(QSize(28, 28));
        task_wifi->setMaximumSize(QSize(16777215, 16777215));
        task_wifi->setStyleSheet(QStringLiteral("border-image: url(:/res/res/left/main_task_wifi.png);"));
        task_headset = new QLabel(Hp_Main_Task_3);
        task_headset->setObjectName(QStringLiteral("task_headset"));
        task_headset->setGeometry(QRect(0, 157, 29, 28));
        task_headset->setMinimumSize(QSize(28, 28));
        task_headset->setMaximumSize(QSize(16777215, 16777215));
        task_headset->setStyleSheet(QStringLiteral("border-image: url(:/res/res/left/main_task_headset.png);"));
        label_battery = new QLabel(Hp_Main_Task_3);
        label_battery->setObjectName(QStringLiteral("label_battery"));
        label_battery->setEnabled(true);
        label_battery->setGeometry(QRect(0, 0, 28, 45));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_battery->sizePolicy().hasHeightForWidth());
        label_battery->setSizePolicy(sizePolicy);
        label_battery->setMinimumSize(QSize(28, 45));
        label_battery->setMaximumSize(QSize(28, 45));
        label_battery->setStyleSheet(QStringLiteral(""));
        task_usb = new QLabel(Hp_Main_Task_3);
        task_usb->setObjectName(QStringLiteral("task_usb"));
        task_usb->setGeometry(QRect(0, 101, 29, 28));
        task_usb->setMinimumSize(QSize(28, 28));
        task_usb->setMaximumSize(QSize(16777215, 16777215));
        task_usb->setStyleSheet(QStringLiteral("border-image: url(:/res/res/left/main_task_usb.png);"));
        task_ble = new QLabel(Hp_Main_Task_3);
        task_ble->setObjectName(QStringLiteral("task_ble"));
        task_ble->setGeometry(QRect(0, 129, 29, 28));
        task_ble->setMinimumSize(QSize(28, 28));
        task_ble->setMaximumSize(QSize(16777215, 16777215));
        task_ble->setStyleSheet(QStringLiteral("border-image: url(:/res/res/left/main_task_ble.png);"));
        task_4G = new QLabel(Hp_Main_Task_3);
        task_4G->setObjectName(QStringLiteral("task_4G"));
        task_4G->setGeometry(QRect(0, 213, 29, 28));
        task_4G->setMinimumSize(QSize(28, 28));
        task_4G->setMaximumSize(QSize(16777215, 16777215));
        task_4G->setFont(font);
        task_4G->setStyleSheet(QStringLiteral("border-image: url(:/res/res/main_task_4G_3.png);"));
        task_4G->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_Main_Task_3);

        QMetaObject::connectSlotsByName(Hp_Main_Task_3);
    } // setupUi

    void retranslateUi(QWidget *Hp_Main_Task_3)
    {
        Hp_Main_Task_3->setWindowTitle(QApplication::translate("Hp_Main_Task_3", "Form", nullptr));
        task_sd->setText(QString());
        task_gps->setText(QString());
        task_wifi->setText(QString());
        task_headset->setText(QString());
        label_battery->setText(QString());
        task_usb->setText(QString());
        task_ble->setText(QString());
        task_4G->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Hp_Main_Task_3: public Ui_Hp_Main_Task_3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_MAIN_TASK_3_H
