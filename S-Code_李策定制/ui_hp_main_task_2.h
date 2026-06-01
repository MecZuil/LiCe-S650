/********************************************************************************
** Form generated from reading UI file 'hp_main_task_2.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_MAIN_TASK_2_H
#define UI_HP_MAIN_TASK_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Main_Task_2
{
public:
    QLabel *task_sd;
    QLabel *label_battery;
    QLabel *task_wifi;
    QLabel *task_gps;
    QLabel *task_ble;
    QLabel *task_usb;
    QLabel *task_headset;
    QLabel *task_4G;

    void setupUi(QWidget *Hp_Main_Task_2)
    {
        if (Hp_Main_Task_2->objectName().isEmpty())
            Hp_Main_Task_2->setObjectName(QStringLiteral("Hp_Main_Task_2"));
        Hp_Main_Task_2->resize(240, 28);
        Hp_Main_Task_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        task_sd = new QLabel(Hp_Main_Task_2);
        task_sd->setObjectName(QStringLiteral("task_sd"));
        task_sd->setGeometry(QRect(45, 0, 28, 29));
        task_sd->setMinimumSize(QSize(28, 28));
        task_sd->setMaximumSize(QSize(16777215, 16777215));
        task_sd->setStyleSheet(QStringLiteral("border-image: url(:/res/res/down/main_task_sd.png);"));
        label_battery = new QLabel(Hp_Main_Task_2);
        label_battery->setObjectName(QStringLiteral("label_battery"));
        label_battery->setEnabled(true);
        label_battery->setGeometry(QRect(0, 0, 45, 28));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_battery->sizePolicy().hasHeightForWidth());
        label_battery->setSizePolicy(sizePolicy);
        label_battery->setMinimumSize(QSize(45, 28));
        label_battery->setMaximumSize(QSize(45, 28));
        label_battery->setStyleSheet(QStringLiteral(""));
        task_wifi = new QLabel(Hp_Main_Task_2);
        task_wifi->setObjectName(QStringLiteral("task_wifi"));
        task_wifi->setGeometry(QRect(73, 0, 28, 29));
        task_wifi->setMinimumSize(QSize(28, 28));
        task_wifi->setMaximumSize(QSize(16777215, 16777215));
        task_wifi->setStyleSheet(QStringLiteral("border-image: url(:/res/res/down/main_task_wifi.png);"));
        task_gps = new QLabel(Hp_Main_Task_2);
        task_gps->setObjectName(QStringLiteral("task_gps"));
        task_gps->setGeometry(QRect(185, 0, 28, 29));
        task_gps->setMinimumSize(QSize(28, 28));
        task_gps->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(15);
        task_gps->setFont(font);
        task_gps->setStyleSheet(QStringLiteral("border-image: url(:/res/res/down/main_task_beidou.png);"));
        task_gps->setAlignment(Qt::AlignCenter);
        task_ble = new QLabel(Hp_Main_Task_2);
        task_ble->setObjectName(QStringLiteral("task_ble"));
        task_ble->setGeometry(QRect(129, 0, 28, 29));
        task_ble->setMinimumSize(QSize(28, 28));
        task_ble->setMaximumSize(QSize(16777215, 16777215));
        task_ble->setStyleSheet(QStringLiteral("border-image: url(:/res/res/down/main_task_ble.png);"));
        task_usb = new QLabel(Hp_Main_Task_2);
        task_usb->setObjectName(QStringLiteral("task_usb"));
        task_usb->setGeometry(QRect(101, 0, 28, 29));
        task_usb->setMinimumSize(QSize(28, 28));
        task_usb->setMaximumSize(QSize(16777215, 16777215));
        task_usb->setStyleSheet(QStringLiteral("border-image: url(:/res/res/down/main_task_usb.png);"));
        task_headset = new QLabel(Hp_Main_Task_2);
        task_headset->setObjectName(QStringLiteral("task_headset"));
        task_headset->setGeometry(QRect(157, 0, 28, 29));
        task_headset->setMinimumSize(QSize(28, 28));
        task_headset->setMaximumSize(QSize(16777215, 16777215));
        task_headset->setStyleSheet(QStringLiteral("border-image: url(:/res/res/down/main_task_headset.png);"));
        task_4G = new QLabel(Hp_Main_Task_2);
        task_4G->setObjectName(QStringLiteral("task_4G"));
        task_4G->setGeometry(QRect(213, 0, 29, 28));
        task_4G->setMinimumSize(QSize(28, 28));
        task_4G->setMaximumSize(QSize(16777215, 16777215));
        task_4G->setFont(font);
        task_4G->setStyleSheet(QStringLiteral("border-image: url(:/res/res/main_task_4G_2.png);"));
        task_4G->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_Main_Task_2);

        QMetaObject::connectSlotsByName(Hp_Main_Task_2);
    } // setupUi

    void retranslateUi(QWidget *Hp_Main_Task_2)
    {
        Hp_Main_Task_2->setWindowTitle(QApplication::translate("Hp_Main_Task_2", "Form", nullptr));
        task_sd->setText(QString());
        label_battery->setText(QString());
        task_wifi->setText(QString());
        task_gps->setText(QString());
        task_ble->setText(QString());
        task_usb->setText(QString());
        task_headset->setText(QString());
        task_4G->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Hp_Main_Task_2: public Ui_Hp_Main_Task_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_MAIN_TASK_2_H
