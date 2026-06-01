/********************************************************************************
** Form generated from reading UI file 'hp_adjust_cmd.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_ADJUST_CMD_H
#define UI_HP_ADJUST_CMD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Adjust_Cmd
{
public:
    QSpinBox *spinBox_N1;
    QSpinBox *spinBox_X1;
    QSpinBox *spinBox_X2;
    QSpinBox *spinBox_Y1;
    QSpinBox *spinBox_N2;
    QSpinBox *spinBox_Y2;
    QSpinBox *spinBox_N3;
    QSpinBox *spinBox_X3;
    QSpinBox *spinBox_Y3;
    QSpinBox *spinBox_N4;
    QSpinBox *spinBox_X4;
    QSpinBox *spinBox_Y4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_b;
    QLabel *label_s;

    void setupUi(QWidget *Hp_Adjust_Cmd)
    {
        if (Hp_Adjust_Cmd->objectName().isEmpty())
            Hp_Adjust_Cmd->setObjectName(QStringLiteral("Hp_Adjust_Cmd"));
        Hp_Adjust_Cmd->resize(640, 480);
        QFont font;
        font.setPointSize(15);
        Hp_Adjust_Cmd->setFont(font);
        Hp_Adjust_Cmd->setWindowOpacity(0.7);
        Hp_Adjust_Cmd->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        spinBox_N1 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_N1->setObjectName(QStringLiteral("spinBox_N1"));
        spinBox_N1->setGeometry(QRect(16, 35, 201, 35));
        QFont font1;
        font1.setPointSize(17);
        spinBox_N1->setFont(font1);
        spinBox_N1->setFocusPolicy(Qt::NoFocus);
        spinBox_N1->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_N1->setFrame(false);
        spinBox_N1->setAlignment(Qt::AlignCenter);
        spinBox_N1->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_N1->setAccelerated(true);
        spinBox_N1->setMaximum(100000);
        spinBox_N1->setValue(26000);
        spinBox_X1 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_X1->setObjectName(QStringLiteral("spinBox_X1"));
        spinBox_X1->setGeometry(QRect(250, 35, 166, 35));
        spinBox_X1->setFont(font1);
        spinBox_X1->setFocusPolicy(Qt::NoFocus);
        spinBox_X1->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_X1->setFrame(false);
        spinBox_X1->setAlignment(Qt::AlignCenter);
        spinBox_X1->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_X1->setAccelerated(true);
        spinBox_X1->setMaximum(100000);
        spinBox_X1->setValue(350);
        spinBox_X2 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_X2->setObjectName(QStringLiteral("spinBox_X2"));
        spinBox_X2->setGeometry(QRect(250, 85, 166, 35));
        spinBox_X2->setFont(font1);
        spinBox_X2->setFocusPolicy(Qt::NoFocus);
        spinBox_X2->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_X2->setFrame(false);
        spinBox_X2->setAlignment(Qt::AlignCenter);
        spinBox_X2->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_X2->setAccelerated(true);
        spinBox_X2->setMaximum(100000);
        spinBox_X2->setValue(350);
        spinBox_Y1 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_Y1->setObjectName(QStringLiteral("spinBox_Y1"));
        spinBox_Y1->setGeometry(QRect(450, 35, 166, 35));
        spinBox_Y1->setFont(font1);
        spinBox_Y1->setFocusPolicy(Qt::NoFocus);
        spinBox_Y1->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_Y1->setFrame(false);
        spinBox_Y1->setAlignment(Qt::AlignCenter);
        spinBox_Y1->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_Y1->setAccelerated(true);
        spinBox_Y1->setMaximum(100000);
        spinBox_Y1->setValue(350);
        spinBox_N2 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_N2->setObjectName(QStringLiteral("spinBox_N2"));
        spinBox_N2->setGeometry(QRect(16, 85, 201, 35));
        spinBox_N2->setFont(font1);
        spinBox_N2->setFocusPolicy(Qt::NoFocus);
        spinBox_N2->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_N2->setFrame(false);
        spinBox_N2->setAlignment(Qt::AlignCenter);
        spinBox_N2->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_N2->setAccelerated(true);
        spinBox_N2->setMaximum(100000);
        spinBox_N2->setValue(23000);
        spinBox_Y2 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_Y2->setObjectName(QStringLiteral("spinBox_Y2"));
        spinBox_Y2->setGeometry(QRect(450, 85, 166, 35));
        spinBox_Y2->setFont(font1);
        spinBox_Y2->setFocusPolicy(Qt::NoFocus);
        spinBox_Y2->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_Y2->setFrame(false);
        spinBox_Y2->setAlignment(Qt::AlignCenter);
        spinBox_Y2->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_Y2->setAccelerated(true);
        spinBox_Y2->setMaximum(100000);
        spinBox_Y2->setValue(350);
        spinBox_N3 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_N3->setObjectName(QStringLiteral("spinBox_N3"));
        spinBox_N3->setGeometry(QRect(16, 355, 201, 35));
        spinBox_N3->setFont(font1);
        spinBox_N3->setFocusPolicy(Qt::NoFocus);
        spinBox_N3->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_N3->setFrame(false);
        spinBox_N3->setAlignment(Qt::AlignCenter);
        spinBox_N3->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_N3->setAccelerated(true);
        spinBox_N3->setMaximum(100000);
        spinBox_N3->setValue(26000);
        spinBox_X3 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_X3->setObjectName(QStringLiteral("spinBox_X3"));
        spinBox_X3->setGeometry(QRect(250, 355, 166, 35));
        spinBox_X3->setFont(font1);
        spinBox_X3->setFocusPolicy(Qt::NoFocus);
        spinBox_X3->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_X3->setFrame(false);
        spinBox_X3->setAlignment(Qt::AlignCenter);
        spinBox_X3->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_X3->setAccelerated(true);
        spinBox_X3->setMaximum(100000);
        spinBox_X3->setValue(350);
        spinBox_Y3 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_Y3->setObjectName(QStringLiteral("spinBox_Y3"));
        spinBox_Y3->setGeometry(QRect(450, 355, 166, 35));
        spinBox_Y3->setFont(font1);
        spinBox_Y3->setFocusPolicy(Qt::NoFocus);
        spinBox_Y3->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_Y3->setFrame(false);
        spinBox_Y3->setAlignment(Qt::AlignCenter);
        spinBox_Y3->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_Y3->setAccelerated(true);
        spinBox_Y3->setMaximum(100000);
        spinBox_Y3->setValue(350);
        spinBox_N4 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_N4->setObjectName(QStringLiteral("spinBox_N4"));
        spinBox_N4->setGeometry(QRect(16, 405, 201, 35));
        spinBox_N4->setFont(font1);
        spinBox_N4->setFocusPolicy(Qt::NoFocus);
        spinBox_N4->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_N4->setFrame(false);
        spinBox_N4->setAlignment(Qt::AlignCenter);
        spinBox_N4->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_N4->setAccelerated(true);
        spinBox_N4->setMaximum(100000);
        spinBox_N4->setValue(23000);
        spinBox_X4 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_X4->setObjectName(QStringLiteral("spinBox_X4"));
        spinBox_X4->setGeometry(QRect(250, 405, 166, 35));
        spinBox_X4->setFont(font1);
        spinBox_X4->setFocusPolicy(Qt::NoFocus);
        spinBox_X4->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_X4->setFrame(false);
        spinBox_X4->setAlignment(Qt::AlignCenter);
        spinBox_X4->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_X4->setAccelerated(true);
        spinBox_X4->setMaximum(100000);
        spinBox_X4->setValue(350);
        spinBox_Y4 = new QSpinBox(Hp_Adjust_Cmd);
        spinBox_Y4->setObjectName(QStringLiteral("spinBox_Y4"));
        spinBox_Y4->setGeometry(QRect(450, 405, 166, 35));
        spinBox_Y4->setFont(font1);
        spinBox_Y4->setFocusPolicy(Qt::NoFocus);
        spinBox_Y4->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(0, 8, 16);\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disab"
                        "led,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 35;\n"
"    height: 35;\n"
"}\n"
""));
        spinBox_Y4->setFrame(false);
        spinBox_Y4->setAlignment(Qt::AlignCenter);
        spinBox_Y4->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_Y4->setAccelerated(true);
        spinBox_Y4->setMaximum(100000);
        spinBox_Y4->setValue(350);
        label = new QLabel(Hp_Adjust_Cmd);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 441, 100, 35));
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2 = new QLabel(Hp_Adjust_Cmd);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 441, 100, 35));
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_b = new QLabel(Hp_Adjust_Cmd);
        label_b->setObjectName(QStringLiteral("label_b"));
        label_b->setGeometry(QRect(269, 441, 30, 35));
        label_b->setFont(font1);
        label_b->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_b->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_s = new QLabel(Hp_Adjust_Cmd);
        label_s->setObjectName(QStringLiteral("label_s"));
        label_s->setGeometry(QRect(130, 441, 30, 35));
        label_s->setFont(font1);
        label_s->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_s->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(Hp_Adjust_Cmd);

        QMetaObject::connectSlotsByName(Hp_Adjust_Cmd);
    } // setupUi

    void retranslateUi(QWidget *Hp_Adjust_Cmd)
    {
        Hp_Adjust_Cmd->setWindowTitle(QApplication::translate("Hp_Adjust_Cmd", "Form", nullptr));
        spinBox_N1->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "N1:", nullptr));
        spinBox_X1->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "X1:", nullptr));
        spinBox_X2->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "X2:", nullptr));
        spinBox_Y1->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "Y1:", nullptr));
        spinBox_N2->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "N2:", nullptr));
        spinBox_Y2->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "Y2:", nullptr));
        spinBox_N3->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "N3:", nullptr));
        spinBox_X3->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "X3:", nullptr));
        spinBox_Y3->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "Y3:", nullptr));
        spinBox_N4->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "N4:", nullptr));
        spinBox_X4->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "X4:", nullptr));
        spinBox_Y4->setPrefix(QApplication::translate("Hp_Adjust_Cmd", "Y4:", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_b->setText(QApplication::translate("Hp_Adjust_Cmd", "B:", nullptr));
        label_s->setText(QApplication::translate("Hp_Adjust_Cmd", "S:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Adjust_Cmd: public Ui_Hp_Adjust_Cmd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_ADJUST_CMD_H
