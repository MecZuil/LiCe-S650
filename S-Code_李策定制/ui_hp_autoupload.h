/********************************************************************************
** Form generated from reading UI file 'hp_autoupload.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_AUTOUPLOAD_H
#define UI_HP_AUTOUPLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hp_AutoUpLoad
{
public:
    QFrame *frame;
    QLabel *label_IP;
    QLabel *label_3;
    QLabel *label_Account;
    QToolButton *toolButton_back;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_Password;
    QLabel *label_server_act;
    QLabel *label_6;
    QLabel *label_server_paswd;
    QLabel *label_7;
    QCheckBox *checkBox_srvopen;
    QLabel *label_5;

    void setupUi(QWidget *hp_AutoUpLoad)
    {
        if (hp_AutoUpLoad->objectName().isEmpty())
            hp_AutoUpLoad->setObjectName(QStringLiteral("hp_AutoUpLoad"));
        hp_AutoUpLoad->resize(800, 480);
        hp_AutoUpLoad->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        frame = new QFrame(hp_AutoUpLoad);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 800, 480));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        label_IP = new QLabel(frame);
        label_IP->setObjectName(QStringLiteral("label_IP"));
        label_IP->setGeometry(QRect(390, 200, 243, 44));
        QFont font;
        font.setPointSize(19);
        label_IP->setFont(font);
        label_IP->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_IP->setText(QStringLiteral(""));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 270, 271, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_Account = new QLabel(frame);
        label_Account->setObjectName(QStringLiteral("label_Account"));
        label_Account->setGeometry(QRect(390, 260, 243, 44));
        label_Account->setFont(font);
        label_Account->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_Account->setText(QStringLiteral(""));
        toolButton_back = new QToolButton(frame);
        toolButton_back->setObjectName(QStringLiteral("toolButton_back"));
        toolButton_back->setGeometry(QRect(0, 0, 155, 81));
        QPalette palette;
        QBrush brush(QColor(124, 166, 201, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        toolButton_back->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        toolButton_back->setFont(font1);
        toolButton_back->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/setting_back.png);\n"
"}  \n"
""));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 330, 271, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 210, 271, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_Password = new QLabel(frame);
        label_Password->setObjectName(QStringLiteral("label_Password"));
        label_Password->setGeometry(QRect(390, 320, 243, 44));
        label_Password->setFont(font);
        label_Password->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_Password->setText(QStringLiteral(""));
        label_server_act = new QLabel(frame);
        label_server_act->setObjectName(QStringLiteral("label_server_act"));
        label_server_act->setGeometry(QRect(390, 80, 243, 44));
        label_server_act->setFont(font);
        label_server_act->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_server_act->setText(QStringLiteral(""));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 90, 271, 31));
        label_6->setFont(font);
        label_6->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_server_paswd = new QLabel(frame);
        label_server_paswd->setObjectName(QStringLiteral("label_server_paswd"));
        label_server_paswd->setGeometry(QRect(390, 140, 243, 44));
        label_server_paswd->setFont(font);
        label_server_paswd->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_server_paswd->setText(QStringLiteral(""));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 150, 271, 31));
        label_7->setFont(font);
        label_7->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_srvopen = new QCheckBox(frame);
        checkBox_srvopen->setObjectName(QStringLiteral("checkBox_srvopen"));
        checkBox_srvopen->setEnabled(true);
        checkBox_srvopen->setGeometry(QRect(390, 380, 70, 50));
        QFont font2;
        font2.setPointSize(17);
        checkBox_srvopen->setFont(font2);
        checkBox_srvopen->setMouseTracking(false);
        checkBox_srvopen->setFocusPolicy(Qt::NoFocus);
        checkBox_srvopen->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"     image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 390, 271, 31));
        label_5->setFont(font);
        label_5->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(hp_AutoUpLoad);

        QMetaObject::connectSlotsByName(hp_AutoUpLoad);
    } // setupUi

    void retranslateUi(QWidget *hp_AutoUpLoad)
    {
        hp_AutoUpLoad->setWindowTitle(QApplication::translate("hp_AutoUpLoad", "Form", nullptr));
        label_3->setText(QApplication::translate("hp_AutoUpLoad", "\347\224\250\346\210\267\345\220\215", nullptr));
        toolButton_back->setText(QString());
        label_4->setText(QApplication::translate("hp_AutoUpLoad", "\345\257\206\347\240\201", nullptr));
        label_2->setText(QApplication::translate("hp_AutoUpLoad", "\346\234\215\345\212\241\345\231\250IP", nullptr));
        label_6->setText(QApplication::translate("hp_AutoUpLoad", "\346\234\215\345\212\241\345\231\250\347\224\250\346\210\267\345\220\215", nullptr));
        label_7->setText(QApplication::translate("hp_AutoUpLoad", "\346\234\215\345\212\241\345\231\250\347\224\250\346\210\267\345\257\206\347\240\201", nullptr));
        checkBox_srvopen->setText(QString());
        label_5->setText(QApplication::translate("hp_AutoUpLoad", "\345\274\200\345\220\257\345\256\242\346\210\267\347\253\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hp_AutoUpLoad: public Ui_hp_AutoUpLoad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_AUTOUPLOAD_H
