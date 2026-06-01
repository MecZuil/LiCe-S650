/********************************************************************************
** Form generated from reading UI file 'hphidemenu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPHIDEMENU_H
#define UI_HPHIDEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HpHideMenu
{
public:
    QCheckBox *checkBox_cap;
    QCheckBox *checkBox_gray;
    QPushButton *cancel;
    QCheckBox *checkBox_printscreen;
    QCheckBox *checkBox_point;
    QCheckBox *checkBox_rect;
    QLabel *label_para_21;
    QLabel *label_para_23;
    QDoubleSpinBox *doubleSpinBox_21;
    QDoubleSpinBox *doubleSpinBox_23;
    QCheckBox *checkBox_homogeneity;
    QCheckBox *checkBox_laser;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLabel *label_para_22;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QDoubleSpinBox *doubleSpinBox_hd;
    QDoubleSpinBox *doubleSpinBox_ld;
    QLabel *label_para_24;
    QLabel *label_para_25;
    QDoubleSpinBox *doubleSpinBox_ht1;
    QDoubleSpinBox *doubleSpinBox_lt1;
    QLabel *label_para_26;
    QLabel *label_para_27;
    QDoubleSpinBox *doubleSpinBox_ht2;
    QDoubleSpinBox *doubleSpinBox_lt2;
    QLabel *label_para_28;
    QLabel *label_para_29;
    QPushButton *cancel_2;
    QPushButton *save_sys_2;
    QLabel *label_para_30;
    QPushButton *save_sys_3;

    void setupUi(QWidget *HpHideMenu)
    {
        if (HpHideMenu->objectName().isEmpty())
            HpHideMenu->setObjectName(QStringLiteral("HpHideMenu"));
        HpHideMenu->resize(800, 480);
        QFont font;
        font.setPointSize(15);
        HpHideMenu->setFont(font);
        checkBox_cap = new QCheckBox(HpHideMenu);
        checkBox_cap->setObjectName(QStringLiteral("checkBox_cap"));
        checkBox_cap->setGeometry(QRect(10, 270, 185, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(19);
        checkBox_cap->setFont(font1);
        checkBox_cap->setStyleSheet(QLatin1String("/*\n"
"image: url(:/res/res/hidemenu_enabled.png);\n"
"QCheckBox\n"
"{\n"
"    font-family:Consolas;\n"
"    height:40px;\n"
" /*   font-size:20px; */\n"
"/*    border-radius:10px;\n"
"}\n"
"*/\n"
"QCheckBox::indicator\n"
"{\n"
"    width:25px;\n"
"    height:25px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"    image:url(:/res/res/hidemenu_unabled.png);\n"
"}\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/res/res/hidemenu_enabled.png);\n"
"}\n"
""));
        checkBox_cap->setCheckable(true);
        checkBox_gray = new QCheckBox(HpHideMenu);
        checkBox_gray->setObjectName(QStringLiteral("checkBox_gray"));
        checkBox_gray->setGeometry(QRect(200, 270, 185, 50));
        checkBox_gray->setFont(font1);
        checkBox_gray->setStyleSheet(QLatin1String("/*\n"
"image: url(:/res/res/hidemenu_enabled.png);\n"
"QCheckBox\n"
"{\n"
"    font-family:Consolas;\n"
"    height:40px;\n"
" /*   font-size:20px; */\n"
"/*    border-radius:10px;\n"
"}\n"
"*/\n"
"QCheckBox::indicator\n"
"{\n"
"    width:25px;\n"
"    height:25px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"    image:url(:/res/res/hidemenu_unabled.png);\n"
"}\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/res/res/hidemenu_enabled.png);\n"
"}\n"
""));
        cancel = new QPushButton(HpHideMenu);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(630, 410, 165, 47));
        QFont font2;
        font2.setPointSize(20);
        cancel->setFont(font2);
        checkBox_printscreen = new QCheckBox(HpHideMenu);
        checkBox_printscreen->setObjectName(QStringLiteral("checkBox_printscreen"));
        checkBox_printscreen->setGeometry(QRect(400, 270, 185, 50));
        checkBox_printscreen->setFont(font1);
        checkBox_printscreen->setStyleSheet(QLatin1String("/*\n"
"image: url(:/res/res/hidemenu_enabled.png);\n"
"QCheckBox\n"
"{\n"
"    font-family:Consolas;\n"
"    height:40px;\n"
" /*   font-size:20px; */\n"
"/*    border-radius:10px;\n"
"}\n"
"*/\n"
"QCheckBox::indicator\n"
"{\n"
"    width:25px;\n"
"    height:25px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"    image:url(:/res/res/hidemenu_unabled.png);\n"
"}\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/res/res/hidemenu_enabled.png);\n"
"}\n"
""));
        checkBox_point = new QCheckBox(HpHideMenu);
        checkBox_point->setObjectName(QStringLiteral("checkBox_point"));
        checkBox_point->setGeometry(QRect(600, 270, 185, 50));
        checkBox_point->setFont(font1);
        checkBox_point->setStyleSheet(QLatin1String("/*\n"
"image: url(:/res/res/hidemenu_enabled.png);\n"
"QCheckBox\n"
"{\n"
"    font-family:Consolas;\n"
"    height:40px;\n"
" /*   font-size:20px; */\n"
"/*    border-radius:10px;\n"
"}\n"
"*/\n"
"QCheckBox::indicator\n"
"{\n"
"    width:25px;\n"
"    height:25px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"    image:url(:/res/res/hidemenu_unabled.png);\n"
"}\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/res/res/hidemenu_enabled.png);\n"
"}\n"
""));
        checkBox_rect = new QCheckBox(HpHideMenu);
        checkBox_rect->setObjectName(QStringLiteral("checkBox_rect"));
        checkBox_rect->setGeometry(QRect(300, 330, 185, 50));
        checkBox_rect->setFont(font1);
        checkBox_rect->setStyleSheet(QLatin1String("/*\n"
"image: url(:/res/res/hidemenu_enabled.png);\n"
"QCheckBox\n"
"{\n"
"    font-family:Consolas;\n"
"    height:40px;\n"
" /*   font-size:20px; */\n"
"/*    border-radius:10px;\n"
"}\n"
"*/\n"
"QCheckBox::indicator\n"
"{\n"
"    width:25px;\n"
"    height:25px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"    image:url(:/res/res/hidemenu_unabled.png);\n"
"}\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/res/res/hidemenu_enabled.png);\n"
"}\n"
""));
        label_para_21 = new QLabel(HpHideMenu);
        label_para_21->setObjectName(QStringLiteral("label_para_21"));
        label_para_21->setGeometry(QRect(10, 0, 150, 50));
        QFont font3;
        font3.setPointSize(17);
        label_para_21->setFont(font3);
        label_para_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_para_23 = new QLabel(HpHideMenu);
        label_para_23->setObjectName(QStringLiteral("label_para_23"));
        label_para_23->setGeometry(QRect(410, 0, 150, 50));
        label_para_23->setFont(font3);
        label_para_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_21 = new QDoubleSpinBox(HpHideMenu);
        doubleSpinBox_21->setObjectName(QStringLiteral("doubleSpinBox_21"));
        doubleSpinBox_21->setGeometry(QRect(170, 10, 181, 31));
        doubleSpinBox_21->setFont(font3);
        doubleSpinBox_21->setStyleSheet(QString::fromUtf8("\n"
"QDoubleSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
""
                        "   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        doubleSpinBox_21->setAlignment(Qt::AlignCenter);
        doubleSpinBox_21->setMinimum(-10000);
        doubleSpinBox_21->setMaximum(10000);
        doubleSpinBox_21->setSingleStep(0.1);
        doubleSpinBox_23 = new QDoubleSpinBox(HpHideMenu);
        doubleSpinBox_23->setObjectName(QStringLiteral("doubleSpinBox_23"));
        doubleSpinBox_23->setGeometry(QRect(570, 10, 181, 31));
        doubleSpinBox_23->setFont(font3);
        doubleSpinBox_23->setStyleSheet(QString::fromUtf8("\n"
"QDoubleSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
""
                        "   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        doubleSpinBox_23->setAlignment(Qt::AlignCenter);
        doubleSpinBox_23->setMinimum(-10000);
        doubleSpinBox_23->setMaximum(10000);
        doubleSpinBox_23->setSingleStep(0.1);
        checkBox_homogeneity = new QCheckBox(HpHideMenu);
        checkBox_homogeneity->setObjectName(QStringLiteral("checkBox_homogeneity"));
        checkBox_homogeneity->setGeometry(QRect(550, 330, 141, 51));
        checkBox_homogeneity->setFont(font1);
        checkBox_homogeneity->setStyleSheet(QLatin1String("/*\n"
"image: url(:/res/res/hidemenu_enabled.png);\n"
"QCheckBox\n"
"{\n"
"    font-family:Consolas;\n"
"    height:40px;\n"
" /*   font-size:20px; */\n"
"/*    border-radius:10px;\n"
"}\n"
"*/\n"
"QCheckBox::indicator\n"
"{\n"
"    width:25px;\n"
"    height:25px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"    image:url(:/res/res/hidemenu_unabled.png);\n"
"}\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/res/res/hidemenu_enabled.png);\n"
"}\n"
""));
        checkBox_laser = new QCheckBox(HpHideMenu);
        checkBox_laser->setObjectName(QStringLiteral("checkBox_laser"));
        checkBox_laser->setGeometry(QRect(50, 330, 185, 50));
        checkBox_laser->setFont(font1);
        checkBox_laser->setStyleSheet(QLatin1String("/*\n"
"image: url(:/res/res/hidemenu_enabled.png);\n"
"QCheckBox\n"
"{\n"
"    font-family:Consolas;\n"
"    height:40px;\n"
" /*   font-size:20px; */\n"
"/*    border-radius:10px;\n"
"}\n"
"*/\n"
"QCheckBox::indicator\n"
"{\n"
"    width:25px;\n"
"    height:25px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"    image:url(:/res/res/hidemenu_unabled.png);\n"
"}\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/res/res/hidemenu_enabled.png);\n"
"}\n"
""));
        checkBox_laser->setCheckable(true);
        toolButton = new QToolButton(HpHideMenu);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(10, 400, 100, 60));
        QFont font4;
        font4.setPointSize(18);
        toolButton->setFont(font4);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"	background-color: rgb(49, 69, 116);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_2 = new QToolButton(HpHideMenu);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(130, 400, 100, 60));
        toolButton_2->setFont(font4);
        toolButton_2->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"	background-color: rgb(49, 69, 116);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        label_para_22 = new QLabel(HpHideMenu);
        label_para_22->setObjectName(QStringLiteral("label_para_22"));
        label_para_22->setGeometry(QRect(420, 400, 80, 60));
        label_para_22->setFont(font3);
        label_para_22->setStyleSheet(QLatin1String("color:#7CA6C9;\n"
"\n"
""));
        label_para_22->setAlignment(Qt::AlignCenter);
        toolButton_3 = new QToolButton(HpHideMenu);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(270, 400, 80, 60));
        toolButton_3->setFont(font4);
        toolButton_3->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"	background-color: rgb(49, 69, 116);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_4 = new QToolButton(HpHideMenu);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(540, 400, 80, 60));
        toolButton_4->setFont(font4);
        toolButton_4->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"	background-color: rgb(49, 69, 116);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        doubleSpinBox_hd = new QDoubleSpinBox(HpHideMenu);
        doubleSpinBox_hd->setObjectName(QStringLiteral("doubleSpinBox_hd"));
        doubleSpinBox_hd->setGeometry(QRect(170, 70, 181, 31));
        doubleSpinBox_hd->setFont(font3);
        doubleSpinBox_hd->setStyleSheet(QString::fromUtf8("\n"
"QDoubleSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
""
                        "   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        doubleSpinBox_hd->setAlignment(Qt::AlignCenter);
        doubleSpinBox_hd->setMinimum(-10000);
        doubleSpinBox_hd->setMaximum(10000);
        doubleSpinBox_hd->setSingleStep(0.1);
        doubleSpinBox_ld = new QDoubleSpinBox(HpHideMenu);
        doubleSpinBox_ld->setObjectName(QStringLiteral("doubleSpinBox_ld"));
        doubleSpinBox_ld->setGeometry(QRect(570, 70, 181, 31));
        doubleSpinBox_ld->setFont(font3);
        doubleSpinBox_ld->setStyleSheet(QString::fromUtf8("\n"
"QDoubleSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
""
                        "   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        doubleSpinBox_ld->setAlignment(Qt::AlignCenter);
        doubleSpinBox_ld->setMinimum(-10000);
        doubleSpinBox_ld->setMaximum(10000);
        doubleSpinBox_ld->setSingleStep(0.1);
        label_para_24 = new QLabel(HpHideMenu);
        label_para_24->setObjectName(QStringLiteral("label_para_24"));
        label_para_24->setGeometry(QRect(410, 60, 150, 50));
        label_para_24->setFont(font3);
        label_para_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_para_25 = new QLabel(HpHideMenu);
        label_para_25->setObjectName(QStringLiteral("label_para_25"));
        label_para_25->setGeometry(QRect(10, 60, 150, 50));
        label_para_25->setFont(font3);
        label_para_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_ht1 = new QDoubleSpinBox(HpHideMenu);
        doubleSpinBox_ht1->setObjectName(QStringLiteral("doubleSpinBox_ht1"));
        doubleSpinBox_ht1->setGeometry(QRect(170, 130, 181, 31));
        doubleSpinBox_ht1->setFont(font3);
        doubleSpinBox_ht1->setStyleSheet(QString::fromUtf8("\n"
"QDoubleSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
""
                        "   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        doubleSpinBox_ht1->setAlignment(Qt::AlignCenter);
        doubleSpinBox_ht1->setMinimum(-10000);
        doubleSpinBox_ht1->setMaximum(10000);
        doubleSpinBox_ht1->setSingleStep(0.1);
        doubleSpinBox_lt1 = new QDoubleSpinBox(HpHideMenu);
        doubleSpinBox_lt1->setObjectName(QStringLiteral("doubleSpinBox_lt1"));
        doubleSpinBox_lt1->setGeometry(QRect(570, 130, 181, 31));
        doubleSpinBox_lt1->setFont(font3);
        doubleSpinBox_lt1->setStyleSheet(QString::fromUtf8("\n"
"QDoubleSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
""
                        "   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        doubleSpinBox_lt1->setAlignment(Qt::AlignCenter);
        doubleSpinBox_lt1->setMinimum(-10000);
        doubleSpinBox_lt1->setMaximum(10000);
        doubleSpinBox_lt1->setSingleStep(0.1);
        label_para_26 = new QLabel(HpHideMenu);
        label_para_26->setObjectName(QStringLiteral("label_para_26"));
        label_para_26->setGeometry(QRect(410, 120, 150, 50));
        label_para_26->setFont(font3);
        label_para_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_para_27 = new QLabel(HpHideMenu);
        label_para_27->setObjectName(QStringLiteral("label_para_27"));
        label_para_27->setGeometry(QRect(10, 120, 150, 50));
        label_para_27->setFont(font3);
        label_para_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_ht2 = new QDoubleSpinBox(HpHideMenu);
        doubleSpinBox_ht2->setObjectName(QStringLiteral("doubleSpinBox_ht2"));
        doubleSpinBox_ht2->setGeometry(QRect(170, 190, 181, 31));
        doubleSpinBox_ht2->setFont(font3);
        doubleSpinBox_ht2->setStyleSheet(QString::fromUtf8("\n"
"QDoubleSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
""
                        "   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        doubleSpinBox_ht2->setAlignment(Qt::AlignCenter);
        doubleSpinBox_ht2->setMinimum(-10000);
        doubleSpinBox_ht2->setMaximum(10000);
        doubleSpinBox_ht2->setSingleStep(0.1);
        doubleSpinBox_lt2 = new QDoubleSpinBox(HpHideMenu);
        doubleSpinBox_lt2->setObjectName(QStringLiteral("doubleSpinBox_lt2"));
        doubleSpinBox_lt2->setGeometry(QRect(570, 190, 181, 31));
        doubleSpinBox_lt2->setFont(font3);
        doubleSpinBox_lt2->setStyleSheet(QString::fromUtf8("\n"
"QDoubleSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
""
                        "   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        doubleSpinBox_lt2->setAlignment(Qt::AlignCenter);
        doubleSpinBox_lt2->setMinimum(-10000);
        doubleSpinBox_lt2->setMaximum(10000);
        doubleSpinBox_lt2->setSingleStep(0.1);
        label_para_28 = new QLabel(HpHideMenu);
        label_para_28->setObjectName(QStringLiteral("label_para_28"));
        label_para_28->setGeometry(QRect(410, 180, 150, 50));
        label_para_28->setFont(font3);
        label_para_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_para_29 = new QLabel(HpHideMenu);
        label_para_29->setObjectName(QStringLiteral("label_para_29"));
        label_para_29->setGeometry(QRect(10, 180, 150, 50));
        label_para_29->setFont(font3);
        label_para_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cancel_2 = new QPushButton(HpHideMenu);
        cancel_2->setObjectName(QStringLiteral("cancel_2"));
        cancel_2->setGeometry(QRect(630, 230, 165, 47));
        cancel_2->setFont(font2);
        save_sys_2 = new QPushButton(HpHideMenu);
        save_sys_2->setObjectName(QStringLiteral("save_sys_2"));
        save_sys_2->setGeometry(QRect(0, 230, 131, 47));
        save_sys_2->setFont(font2);
        label_para_30 = new QLabel(HpHideMenu);
        label_para_30->setObjectName(QStringLiteral("label_para_30"));
        label_para_30->setGeometry(QRect(340, 230, 271, 50));
        label_para_30->setFont(font3);
        label_para_30->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_para_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        save_sys_3 = new QPushButton(HpHideMenu);
        save_sys_3->setObjectName(QStringLiteral("save_sys_3"));
        save_sys_3->setGeometry(QRect(160, 230, 131, 47));
        save_sys_3->setFont(font2);

        retranslateUi(HpHideMenu);
        QObject::connect(cancel, SIGNAL(released()), HpHideMenu, SLOT(close()));

        QMetaObject::connectSlotsByName(HpHideMenu);
    } // setupUi

    void retranslateUi(QWidget *HpHideMenu)
    {
        HpHideMenu->setWindowTitle(QApplication::translate("HpHideMenu", "Form", nullptr));
        checkBox_cap->setText(QApplication::translate("HpHideMenu", "\351\207\207\351\233\206\344\275\277\350\203\275", nullptr));
        checkBox_gray->setText(QApplication::translate("HpHideMenu", "\347\201\260\345\272\246\344\275\277\350\203\275", nullptr));
        cancel->setText(QApplication::translate("HpHideMenu", "\351\200\200\345\207\272", nullptr));
        checkBox_printscreen->setText(QApplication::translate("HpHideMenu", "\346\210\252\345\233\276\344\275\277\350\203\275", nullptr));
        checkBox_point->setText(QApplication::translate("HpHideMenu", "\345\215\225\347\202\271\344\275\277\350\203\275", nullptr));
        checkBox_rect->setText(QApplication::translate("HpHideMenu", "\345\214\272\345\237\237\344\275\277\350\203\275", nullptr));
        label_para_21->setText(QApplication::translate("HpHideMenu", "\351\253\230\346\270\251\350\241\245\345\201\277", nullptr));
        label_para_23->setText(QApplication::translate("HpHideMenu", "\344\275\216\346\270\251\350\241\245\345\201\277", nullptr));
        checkBox_homogeneity->setText(QApplication::translate("HpHideMenu", "\345\235\207\345\214\200\346\200\247", nullptr));
        checkBox_laser->setText(QApplication::translate("HpHideMenu", "\346\277\200\345\205\211\350\260\203\350\212\202", nullptr));
        toolButton->setText(QApplication::translate("HpHideMenu", "\345\274\200\345\247\213\346\240\241\345\207\206", nullptr));
        toolButton_2->setText(QApplication::translate("HpHideMenu", "\347\273\223\346\235\237\346\240\241\345\207\206", nullptr));
        label_para_22->setText(QApplication::translate("HpHideMenu", "0", nullptr));
        toolButton_3->setText(QApplication::translate("HpHideMenu", "\345\212\240\350\247\222\345\272\246", nullptr));
        toolButton_4->setText(QApplication::translate("HpHideMenu", "\345\207\217\350\247\222\345\272\246", nullptr));
        label_para_24->setText(QApplication::translate("HpHideMenu", "ld", nullptr));
        label_para_25->setText(QApplication::translate("HpHideMenu", "hd", nullptr));
        label_para_26->setText(QApplication::translate("HpHideMenu", "lt1", nullptr));
        label_para_27->setText(QApplication::translate("HpHideMenu", "ht1", nullptr));
        label_para_28->setText(QApplication::translate("HpHideMenu", "lt2", nullptr));
        label_para_29->setText(QApplication::translate("HpHideMenu", "ht2", nullptr));
        cancel_2->setText(QApplication::translate("HpHideMenu", "\344\277\235\345\255\230\350\267\235\347\246\273\350\241\245\345\201\277", nullptr));
        save_sys_2->setText(QApplication::translate("HpHideMenu", "\344\277\235\345\255\230\351\207\207\351\233\206", nullptr));
        label_para_30->setText(QApplication::translate("HpHideMenu", "\345\205\263\351\227\255\351\207\207\351\233\206\344\275\277\350\203\275\345\220\216\345\206\215\350\277\233\350\241\214\344\277\235\345\255\230", nullptr));
        save_sys_3->setText(QApplication::translate("HpHideMenu", "\346\270\205\347\251\272\351\207\207\351\233\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HpHideMenu: public Ui_HpHideMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPHIDEMENU_H
