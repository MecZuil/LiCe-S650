/********************************************************************************
** Form generated from reading UI file 'hp_main_task.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_MAIN_TASK_H
#define UI_HP_MAIN_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Main_Task
{
public:
    QLabel *task_focus;
    QLabel *task_headset;
    QLabel *task_ble;
    QLabel *task_usb;
    QLabel *task_wifi;
    QLabel *task_sd;
    QLabel *label_battery;
    QLabel *task_4g;

    void setupUi(QWidget *Hp_Main_Task)
    {
        if (Hp_Main_Task->objectName().isEmpty())
            Hp_Main_Task->setObjectName(QStringLiteral("Hp_Main_Task"));
        Hp_Main_Task->resize(264, 29);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Hp_Main_Task->sizePolicy().hasHeightForWidth());
        Hp_Main_Task->setSizePolicy(sizePolicy);
        Hp_Main_Task->setMinimumSize(QSize(0, 0));
        Hp_Main_Task->setMaximumSize(QSize(16777215, 16777215));
        Hp_Main_Task->setStyleSheet(QStringLiteral(""));
        task_focus = new QLabel(Hp_Main_Task);
        task_focus->setObjectName(QStringLiteral("task_focus"));
        task_focus->setGeometry(QRect(39, 0, 28, 28));
        task_focus->setMinimumSize(QSize(10, 10));
        task_focus->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(15);
        task_focus->setFont(font);
        task_focus->setStyleSheet(QLatin1String("/*color:#7CA6C9; */\n"
"color:#ffffff;\n"
"border-image: url(:/res/res/main_task_beidou.png);"));
        task_focus->setAlignment(Qt::AlignCenter);
        task_headset = new QLabel(Hp_Main_Task);
        task_headset->setObjectName(QStringLiteral("task_headset"));
        task_headset->setGeometry(QRect(67, 0, 28, 28));
        task_headset->setMinimumSize(QSize(10, 10));
        task_headset->setMaximumSize(QSize(16777215, 16777215));
        task_headset->setStyleSheet(QStringLiteral("border-image:url(:/res/res/main_task_headset.png);"));
        task_ble = new QLabel(Hp_Main_Task);
        task_ble->setObjectName(QStringLiteral("task_ble"));
        task_ble->setGeometry(QRect(95, 0, 28, 28));
        task_ble->setMinimumSize(QSize(10, 10));
        task_ble->setMaximumSize(QSize(16777215, 16777215));
        task_ble->setStyleSheet(QStringLiteral("border-image:url(:/res/res/main_task_ble.png);"));
        task_usb = new QLabel(Hp_Main_Task);
        task_usb->setObjectName(QStringLiteral("task_usb"));
        task_usb->setGeometry(QRect(123, 0, 28, 28));
        task_usb->setMinimumSize(QSize(10, 10));
        task_usb->setMaximumSize(QSize(16777215, 16777215));
        task_usb->setStyleSheet(QStringLiteral("border-image:url(:/res/res/main_task_usb.png);"));
        task_wifi = new QLabel(Hp_Main_Task);
        task_wifi->setObjectName(QStringLiteral("task_wifi"));
        task_wifi->setGeometry(QRect(151, 0, 28, 28));
        task_wifi->setMinimumSize(QSize(10, 10));
        task_wifi->setMaximumSize(QSize(16777215, 16777215));
        task_wifi->setStyleSheet(QStringLiteral("border-image:url(:/res/res/main_task_wifi.png);"));
        task_sd = new QLabel(Hp_Main_Task);
        task_sd->setObjectName(QStringLiteral("task_sd"));
        task_sd->setGeometry(QRect(179, 0, 28, 28));
        task_sd->setMinimumSize(QSize(10, 10));
        task_sd->setMaximumSize(QSize(16777215, 16777215));
        task_sd->setStyleSheet(QStringLiteral("border-image:url(:/res/res/main_task_sd.png);"));
        label_battery = new QLabel(Hp_Main_Task);
        label_battery->setObjectName(QStringLiteral("label_battery"));
        label_battery->setEnabled(true);
        label_battery->setGeometry(QRect(207, 0, 56, 28));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_battery->sizePolicy().hasHeightForWidth());
        label_battery->setSizePolicy(sizePolicy1);
        label_battery->setMinimumSize(QSize(10, 10));
        label_battery->setMaximumSize(QSize(10000, 10000));
        label_battery->setStyleSheet(QStringLiteral(""));
        task_4g = new QLabel(Hp_Main_Task);
        task_4g->setObjectName(QStringLiteral("task_4g"));
        task_4g->setGeometry(QRect(10, 1, 28, 28));
        task_4g->setMinimumSize(QSize(10, 10));
        task_4g->setMaximumSize(QSize(16777215, 16777215));
        task_4g->setFont(font);
        task_4g->setStyleSheet(QLatin1String("/*color:#7CA6C9; */\n"
"color:#ffffff;"));
        task_4g->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_Main_Task);

        QMetaObject::connectSlotsByName(Hp_Main_Task);
    } // setupUi

    void retranslateUi(QWidget *Hp_Main_Task)
    {
        Hp_Main_Task->setWindowTitle(QApplication::translate("Hp_Main_Task", "Form", nullptr));
        task_focus->setText(QApplication::translate("Hp_Main_Task", "<html><head/><body><p><br/></p></body></html>", nullptr));
        task_headset->setText(QString());
        task_ble->setText(QString());
        task_usb->setText(QString());
        task_wifi->setText(QString());
        task_sd->setText(QString());
        label_battery->setText(QString());
        task_4g->setText(QApplication::translate("Hp_Main_Task", "<html><head/><body><p><img src=\":/res/res/main_task_4G.png\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Main_Task: public Ui_Hp_Main_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_MAIN_TASK_H
