/********************************************************************************
** Form generated from reading UI file 'hpplredit.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPPLREDIT_H
#define UI_HPPLREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <hp_qdoublespinboxset.h>
#include "hp_qspinboxset.h"

QT_BEGIN_NAMESPACE

class Ui_HpPLREdit
{
public:
    QFrame *frame;
    hp_QSpinBoxSet *hs_radiance;
    hp_QDoubleSpinBoxSet *hs_distance;
    QCheckBox *cb_refer;
    QComboBox *cb_temptype;
    hp_QDoubleSpinBoxSet *hs_reflect;
    QToolButton *pb_finish;
    QToolButton *pb_cancle;
    QFrame *frame_temptype;
    QLabel *label_temptype_2;
    QLabel *label_temptype_3;
    QListWidget *listWidget_temptype;
    QFrame *frame_radiance;
    QLabel *label_radiance_2;
    QLabel *label_radiance_3;
    QCheckBox *checkBox_radiance;
    QListWidget *listWidget_radiance;
    QCheckBox *cb_linedepth;
    hp_QDoubleSpinBoxSet *hs_rectTemp;
    QCheckBox *cb_rectTemp;

    void setupUi(QWidget *HpPLREdit)
    {
        if (HpPLREdit->objectName().isEmpty())
            HpPLREdit->setObjectName(QStringLiteral("HpPLREdit"));
        HpPLREdit->resize(640, 480);
        QFont font;
        font.setPointSize(15);
        HpPLREdit->setFont(font);
        HpPLREdit->setAutoFillBackground(false);
        HpPLREdit->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(HpPLREdit);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 640, 480));
        frame->setFont(font);
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QLatin1String("background-image: url(:/res/res/setting_background.png);\n"
"/*background-image: url(:/res/res/PreviewBackground.png);*/"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        hs_radiance = new hp_QSpinBoxSet(frame);
        hs_radiance->setObjectName(QStringLiteral("hs_radiance"));
        hs_radiance->setGeometry(QRect(133, 50, 385, 45));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(17);
        hs_radiance->setFont(font1);
        hs_radiance->setFocusPolicy(Qt::NoFocus);
        hs_radiance->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled"
                        ",QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
""));
        hs_radiance->setAlignment(Qt::AlignCenter);
        hs_radiance->setAccelerated(true);
        hs_radiance->setMinimum(1);
        hs_radiance->setMaximum(100);
        hs_distance = new hp_QDoubleSpinBoxSet(frame);
        hs_distance->setObjectName(QStringLiteral("hs_distance"));
        hs_distance->setGeometry(QRect(133, 103, 385, 45));
        hs_distance->setFont(font1);
        hs_distance->setFocusPolicy(Qt::NoFocus);
        hs_distance->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"\n"
"border:0px;\n"
"}\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
""
                        "QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}"));
        hs_distance->setAlignment(Qt::AlignCenter);
        hs_distance->setAccelerated(true);
        hs_distance->setDecimals(1);
        hs_distance->setMinimum(1);
        hs_distance->setSingleStep(0.1);
        cb_refer = new QCheckBox(frame);
        cb_refer->setObjectName(QStringLiteral("cb_refer"));
        cb_refer->setGeometry(QRect(133, 156, 385, 45));
        cb_refer->setFont(font1);
        cb_refer->setFocusPolicy(Qt::NoFocus);
        cb_refer->setLayoutDirection(Qt::RightToLeft);
        cb_refer->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"color:#7CA6C9;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"	color:#7CA6C9;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"     image: url(:/res/res/switch_on.png);\n"
"	 color:#7CA6C9;\n"
"}\n"
"\n"
"\n"
""));
        cb_refer->setTristate(false);
        cb_temptype = new QComboBox(frame);
        cb_temptype->addItem(QString());
        cb_temptype->addItem(QString());
        cb_temptype->addItem(QString());
        cb_temptype->addItem(QString());
        cb_temptype->addItem(QString());
        cb_temptype->setObjectName(QStringLiteral("cb_temptype"));
        cb_temptype->setGeometry(QRect(10, 0, 181, 45));
        cb_temptype->setFont(font1);
        cb_temptype->setFocusPolicy(Qt::NoFocus);
        cb_temptype->setStyleSheet(QLatin1String("\n"
"QComboBox {\n"
"	color:#7CA6C9;\n"
"border:0px solid;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"/*    background-color: #0a1a29;*/\n"
"background-color:transparent;\n"
"    border: 0px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"}\n"
"\n"
"\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"\n"
"	color:#7CA6C9;\n"
"	background-image:url(:/res/res/combox_bg2.png);\n"
"}\n"
"\n"
"/* QComboBox gets the \"on\" state when the popup is open */\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"	color:#7CA6C9;\n"
"	background:transparent;\n"
"\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"    padding-top: 0px;\n"
"    padding-left: 0px;\n"
"	width:40px;\n"
"	height:40px;\n"
"	color:#7CA6C9;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: right;\n"
"width:40px;\n"
"height:40px;\n"
"\n"
"\n"
"    border-top-right-radius: 0px; /* same radius as the QCom"
                        "boBox */\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/res/res/down_arrow_n.png);\n"
"\n"
"width:40px;\n"
"height:40px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 0px;\n"
"    left: 0px;\n"
"}"));
        cb_temptype->setDuplicatesEnabled(false);
        cb_temptype->setFrame(false);
        hs_reflect = new hp_QDoubleSpinBoxSet(frame);
        hs_reflect->setObjectName(QStringLiteral("hs_reflect"));
        hs_reflect->setGeometry(QRect(133, 262, 385, 45));
        hs_reflect->setFont(font1);
        hs_reflect->setFocusPolicy(Qt::NoFocus);
        hs_reflect->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"\n"
"border:0px;\n"
"}\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
""
                        "QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}"));
        hs_reflect->setFrame(false);
        hs_reflect->setAlignment(Qt::AlignCenter);
        hs_reflect->setAccelerated(true);
        hs_reflect->setDecimals(1);
        hs_reflect->setMinimum(-1e+09);
        hs_reflect->setMaximum(1e+10);
        hs_reflect->setSingleStep(0.1);
        pb_finish = new QToolButton(frame);
        pb_finish->setObjectName(QStringLiteral("pb_finish"));
        pb_finish->setGeometry(QRect(400, 380, 118, 45));
        pb_finish->setFont(font1);
        pb_finish->setFocusPolicy(Qt::NoFocus);
        pb_finish->setAutoFillBackground(false);
        pb_finish->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        pb_finish->setAutoRaise(true);
        pb_cancle = new QToolButton(frame);
        pb_cancle->setObjectName(QStringLiteral("pb_cancle"));
        pb_cancle->setGeometry(QRect(133, 380, 118, 45));
        pb_cancle->setFont(font1);
        pb_cancle->setFocusPolicy(Qt::NoFocus);
        pb_cancle->setAutoFillBackground(false);
        pb_cancle->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        pb_cancle->setAutoRaise(true);
        frame_temptype = new QFrame(frame);
        frame_temptype->setObjectName(QStringLiteral("frame_temptype"));
        frame_temptype->setGeometry(QRect(133, 209, 385, 45));
        frame_temptype->setStyleSheet(QLatin1String("background-color:transparent;\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_temptype->setFrameShape(QFrame::StyledPanel);
        frame_temptype->setFrameShadow(QFrame::Raised);
        label_temptype_2 = new QLabel(frame_temptype);
        label_temptype_2->setObjectName(QStringLiteral("label_temptype_2"));
        label_temptype_2->setGeometry(QRect(0, 0, 340, 45));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(17);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_temptype_2->setFont(font2);
        label_temptype_2->setLayoutDirection(Qt::LeftToRight);
        label_temptype_2->setStyleSheet(QLatin1String("/*background-color:transparent;*/\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;"));
        label_temptype_2->setAlignment(Qt::AlignCenter);
        label_temptype_3 = new QLabel(frame_temptype);
        label_temptype_3->setObjectName(QStringLiteral("label_temptype_3"));
        label_temptype_3->setGeometry(QRect(340, 1, 43, 43));
        label_temptype_3->setFont(font1);
        label_temptype_3->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        listWidget_temptype = new QListWidget(frame);
        new QListWidgetItem(listWidget_temptype);
        new QListWidgetItem(listWidget_temptype);
        new QListWidgetItem(listWidget_temptype);
        new QListWidgetItem(listWidget_temptype);
        new QListWidgetItem(listWidget_temptype);
        listWidget_temptype->setObjectName(QStringLiteral("listWidget_temptype"));
        listWidget_temptype->setGeometry(QRect(320, 10, 261, 31));
        listWidget_temptype->setFont(font1);
        listWidget_temptype->setLayoutDirection(Qt::LeftToRight);
        listWidget_temptype->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_radiance = new QFrame(frame);
        frame_radiance->setObjectName(QStringLiteral("frame_radiance"));
        frame_radiance->setGeometry(QRect(10, 410, 385, 44));
        frame_radiance->setStyleSheet(QLatin1String("background-color:transparent;\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_radiance->setFrameShape(QFrame::StyledPanel);
        frame_radiance->setFrameShadow(QFrame::Raised);
        label_radiance_2 = new QLabel(frame_radiance);
        label_radiance_2->setObjectName(QStringLiteral("label_radiance_2"));
        label_radiance_2->setGeometry(QRect(0, 0, 341, 44));
        label_radiance_2->setFont(font2);
        label_radiance_2->setLayoutDirection(Qt::LeftToRight);
        label_radiance_2->setStyleSheet(QLatin1String("/*background-color:transparent;*/\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;"));
        label_radiance_2->setAlignment(Qt::AlignCenter);
        label_radiance_3 = new QLabel(frame_radiance);
        label_radiance_3->setObjectName(QStringLiteral("label_radiance_3"));
        label_radiance_3->setGeometry(QRect(341, 1, 44, 44));
        label_radiance_3->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        checkBox_radiance = new QCheckBox(frame);
        checkBox_radiance->setObjectName(QStringLiteral("checkBox_radiance"));
        checkBox_radiance->setGeometry(QRect(20, 50, 80, 45));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox_radiance->sizePolicy().hasHeightForWidth());
        checkBox_radiance->setSizePolicy(sizePolicy);
        checkBox_radiance->setMinimumSize(QSize(40, 0));
        QFont font3;
        font3.setPointSize(10);
        font3.setStyleStrategy(QFont::PreferAntialias);
        checkBox_radiance->setFont(font3);
        checkBox_radiance->setFocusPolicy(Qt::NoFocus);
        checkBox_radiance->setLayoutDirection(Qt::RightToLeft);
        checkBox_radiance->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        checkBox_radiance->setIconSize(QSize(30, 30));
        checkBox_radiance->setTristate(false);
        listWidget_radiance = new QListWidget(frame);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        new QListWidgetItem(listWidget_radiance);
        listWidget_radiance->setObjectName(QStringLiteral("listWidget_radiance"));
        listWidget_radiance->setGeometry(QRect(410, 280, 281, 191));
        listWidget_radiance->setFont(font1);
        listWidget_radiance->setStyleSheet(QLatin1String("QListWidget\n"
"        {\n"
"        border: 1px solid #7CA6C9;\n"
"        color:#7CA6C9;\n"
"        background-image: url(:/res/res/list_background.png);\n"
"        border-right-color: 0px;\n"
"        }\n"
"        QScrollBar:vertical\n"
"        {\n"
"        border:0px solid #7CA6C9;\n"
"        background-color:#32CC99;\n"
"        width:25px;\n"
"        margin:25 0 25 0px;\n"
"        }\n"
"        QScrollBar::handle:vertical\n"
"        {\n"
"        background-color: rgb(83, 166, 249);\n"
"        border:1px solid #7CA6C9;\n"
"        }\n"
"        QScrollBar::add-line:vertical\n"
"        {\n"
"        border:0px solid #7CA6C9;\n"
"        background-color:transparent;\n"
"        width:25px;\n"
"        height:25px;\n"
"        subcontrol-position:bottom;\n"
"        subcontrol-origin:margin;\n"
"        border-image: url(:/res/res/m_down_arrow_s.png);\n"
"        }\n"
"        QScrollBar::sub-line:vertical\n"
"        {\n"
"        border:0px solid #7CA6C9;\n"
"        background-color:transpar"
                        "ent;\n"
"        width:25px;\n"
"        height:25px;\n"
"        subcontrol-position:top;\n"
"        subcontrol-origin:margin;\n"
"        border-image: url(:/res/res/m_up_arrow_s.png);\n"
"        }QScrollBar::up-arrow:vertical,QScrollBar::down-arrow:vertical\n"
"        {\n"
"        border:0px;\n"
"        width:25px;\n"
"        height:25px;\n"
"        }\n"
"        QScrollBar::add-page:vertical\n"
"        {\n"
"        background-color:transparent;\n"
"        }\n"
"        QScrollBar::sub-page:vertical\n"
"        {\n"
"        background-color:transparent;\n"
"        }"));
        cb_linedepth = new QCheckBox(frame);
        cb_linedepth->setObjectName(QStringLiteral("cb_linedepth"));
        cb_linedepth->setGeometry(QRect(130, 310, 385, 45));
        cb_linedepth->setFont(font1);
        cb_linedepth->setFocusPolicy(Qt::NoFocus);
        cb_linedepth->setLayoutDirection(Qt::RightToLeft);
        cb_linedepth->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"color:#7CA6C9;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"	color:#7CA6C9;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"     image: url(:/res/res/switch_on.png);\n"
"	 color:#7CA6C9;\n"
"}\n"
"\n"
"\n"
""));
        cb_linedepth->setTristate(false);
        hs_rectTemp = new hp_QDoubleSpinBoxSet(frame);
        hs_rectTemp->setObjectName(QStringLiteral("hs_rectTemp"));
        hs_rectTemp->setGeometry(QRect(133, 370, 385, 45));
        hs_rectTemp->setFont(font1);
        hs_rectTemp->setFocusPolicy(Qt::NoFocus);
        hs_rectTemp->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"\n"
"border:0px;\n"
"}\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
""
                        "QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}"));
        hs_rectTemp->setFrame(false);
        hs_rectTemp->setAlignment(Qt::AlignCenter);
        hs_rectTemp->setAccelerated(true);
        hs_rectTemp->setDecimals(1);
        hs_rectTemp->setMinimum(-1e+09);
        hs_rectTemp->setMaximum(1e+10);
        hs_rectTemp->setSingleStep(0.1);
        cb_rectTemp = new QCheckBox(frame);
        cb_rectTemp->setObjectName(QStringLiteral("cb_rectTemp"));
        cb_rectTemp->setGeometry(QRect(130, 320, 385, 45));
        cb_rectTemp->setFont(font1);
        cb_rectTemp->setFocusPolicy(Qt::NoFocus);
        cb_rectTemp->setLayoutDirection(Qt::RightToLeft);
        cb_rectTemp->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"color:#7CA6C9;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/res/res/switch_on.png);\n"
"}"));
        cb_rectTemp->setTristate(false);

        retranslateUi(HpPLREdit);

        QMetaObject::connectSlotsByName(HpPLREdit);
    } // setupUi

    void retranslateUi(QWidget *HpPLREdit)
    {
        HpPLREdit->setWindowTitle(QApplication::translate("HpPLREdit", "Form", nullptr));
        hs_radiance->setSuffix(QApplication::translate("HpPLREdit", "%", nullptr));
        hs_radiance->setPrefix(QApplication::translate("HpPLREdit", "\345\271\205\345\260\204\347\216\207:", nullptr));
        hs_distance->setPrefix(QApplication::translate("HpPLREdit", "\350\267\235\347\246\273:", nullptr));
        hs_distance->setSuffix(QApplication::translate("HpPLREdit", "m", nullptr));
        cb_refer->setText(QApplication::translate("HpPLREdit", "\350\256\276\344\270\272\345\217\202\350\200\203                           ", nullptr));
        cb_temptype->setItemText(0, QApplication::translate("HpPLREdit", "\346\265\213\346\270\251\347\261\273\345\236\213:\346\234\200\345\244\247\345\200\274", nullptr));
        cb_temptype->setItemText(1, QApplication::translate("HpPLREdit", "\346\265\213\346\270\251\347\261\273\345\236\213:\346\234\200\345\260\217\345\200\274", nullptr));
        cb_temptype->setItemText(2, QApplication::translate("HpPLREdit", "\346\265\213\346\270\251\347\261\273\345\236\213:\345\271\263\345\235\207\345\200\274", nullptr));
        cb_temptype->setItemText(3, QApplication::translate("HpPLREdit", "\346\265\213\346\270\251\347\261\273\345\236\213:\346\211\200\346\234\211\345\200\274", nullptr));
        cb_temptype->setItemText(4, QApplication::translate("HpPLREdit", "\346\265\213\346\270\251\347\261\273\345\236\213:\346\236\201\345\267\256\345\200\274", nullptr));

        hs_reflect->setPrefix(QApplication::translate("HpPLREdit", "\345\217\215\345\260\204\346\270\251\345\272\246:", nullptr));
        pb_finish->setText(QApplication::translate("HpPLREdit", "\345\256\214\346\210\220", nullptr));
        pb_cancle->setText(QApplication::translate("HpPLREdit", "\345\217\226\346\266\210", nullptr));
        label_temptype_2->setText(QApplication::translate("HpPLREdit", "\346\265\213\346\270\251\347\261\273\345\236\213\357\274\232\346\234\200\345\244\247\345\200\274", nullptr));
        label_temptype_3->setText(QString());

        const bool __sortingEnabled = listWidget_temptype->isSortingEnabled();
        listWidget_temptype->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_temptype->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("HpPLREdit", "\346\265\213\346\270\251\347\261\273\345\236\213\357\274\232\346\234\200\345\244\247\345\200\274", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_temptype->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("HpPLREdit", "\346\265\213\346\270\251\347\261\273\345\236\213\357\274\232\346\234\200\345\260\217\345\200\274", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_temptype->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("HpPLREdit", "\346\265\213\346\270\251\347\261\273\345\236\213\357\274\232\345\271\263\345\235\207\345\200\274", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_temptype->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("HpPLREdit", "\346\265\213\346\270\251\347\261\273\345\236\213\357\274\232\346\211\200\346\234\211\345\200\274", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_temptype->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("HpPLREdit", "\346\265\213\346\270\251\347\261\273\345\236\213\357\274\232\346\236\201\345\267\256\345\200\274", nullptr));
        listWidget_temptype->setSortingEnabled(__sortingEnabled);

        label_radiance_2->setText(QApplication::translate("HpPLREdit", "\350\276\220\345\260\204\347\261\273\345\236\213\357\274\232\350\276\220\345\260\204\347\216\207", nullptr));
        label_radiance_3->setText(QString());
        checkBox_radiance->setText(QString());

        const bool __sortingEnabled1 = listWidget_radiance->isSortingEnabled();
        listWidget_radiance->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem5 = listWidget_radiance->item(0);
        ___qlistwidgetitem5->setText(QApplication::translate("HpPLREdit", "\346\260\264:            0.96", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_radiance->item(1);
        ___qlistwidgetitem6->setText(QApplication::translate("HpPLREdit", "\347\232\256\350\202\244:         0.80", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_radiance->item(2);
        ___qlistwidgetitem7->setText(QApplication::translate("HpPLREdit", "\351\231\266\347\223\267(\347\273\206):    0.90", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_radiance->item(3);
        ___qlistwidgetitem8->setText(QApplication::translate("HpPLREdit", "\351\231\266\347\223\267(\347\262\227):    0.93", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget_radiance->item(4);
        ___qlistwidgetitem9->setText(QApplication::translate("HpPLREdit", "\351\223\235:             0.20", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = listWidget_radiance->item(5);
        ___qlistwidgetitem10->setText(QApplication::translate("HpPLREdit", "\351\223\235(\346\260\247\345\214\226):    0.55", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = listWidget_radiance->item(6);
        ___qlistwidgetitem11->setText(QApplication::translate("HpPLREdit", "\351\273\204\351\223\234:          0.22", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = listWidget_radiance->item(7);
        ___qlistwidgetitem12->setText(QApplication::translate("HpPLREdit", "\351\273\204\351\223\234(\346\260\247\345\214\226): 0.61", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = listWidget_radiance->item(8);
        ___qlistwidgetitem13->setText(QApplication::translate("HpPLREdit", "\351\223\234(\346\267\261\345\272\246\346\260\247\345\214\226):0.78", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = listWidget_radiance->item(9);
        ___qlistwidgetitem14->setText(QApplication::translate("HpPLREdit", "\351\223\201(\346\260\247\345\214\226):    0.74", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = listWidget_radiance->item(10);
        ___qlistwidgetitem15->setText(QApplication::translate("HpPLREdit", "\351\223\201(\347\224\237\351\224\210):    0.65", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = listWidget_radiance->item(11);
        ___qlistwidgetitem16->setText(QApplication::translate("HpPLREdit", "\351\223\270\351\223\201(\346\260\247\345\214\226): 0.64 ", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = listWidget_radiance->item(12);
        ___qlistwidgetitem17->setText(QApplication::translate("HpPLREdit", "\351\223\270\351\223\201:          0.21", nullptr));
        QListWidgetItem *___qlistwidgetitem18 = listWidget_radiance->item(13);
        ___qlistwidgetitem18->setText(QApplication::translate("HpPLREdit", "\351\225\215(\346\260\247\345\214\226):    0.37", nullptr));
        QListWidgetItem *___qlistwidgetitem19 = listWidget_radiance->item(14);
        ___qlistwidgetitem19->setText(QApplication::translate("HpPLREdit", "\351\222\242(\346\260\247\345\214\226):    0.79", nullptr));
        QListWidgetItem *___qlistwidgetitem20 = listWidget_radiance->item(15);
        ___qlistwidgetitem20->setText(QApplication::translate("HpPLREdit", "\344\270\215\351\224\210\351\222\242(\346\260\247\345\214\226):0.85", nullptr));
        QListWidgetItem *___qlistwidgetitem21 = listWidget_radiance->item(16);
        ___qlistwidgetitem21->setText(QApplication::translate("HpPLREdit", "\347\242\263(\347\203\237\345\260\230):    0.95", nullptr));
        QListWidgetItem *___qlistwidgetitem22 = listWidget_radiance->item(17);
        ___qlistwidgetitem22->setText(QApplication::translate("HpPLREdit", "\347\242\263(\347\237\263\345\242\250):    0.98", nullptr));
        QListWidgetItem *___qlistwidgetitem23 = listWidget_radiance->item(18);
        ___qlistwidgetitem23->setText(QApplication::translate("HpPLREdit", "\346\274\206(\347\231\275\350\211\262):    0.92", nullptr));
        QListWidgetItem *___qlistwidgetitem24 = listWidget_radiance->item(19);
        ___qlistwidgetitem24->setText(QApplication::translate("HpPLREdit", "\346\274\206(\351\273\221\350\211\262):    0.97", nullptr));
        QListWidgetItem *___qlistwidgetitem25 = listWidget_radiance->item(20);
        ___qlistwidgetitem25->setText(QApplication::translate("HpPLREdit", "\346\262\271\346\274\206:         0.94", nullptr));
        QListWidgetItem *___qlistwidgetitem26 = listWidget_radiance->item(21);
        ___qlistwidgetitem26->setText(QApplication::translate("HpPLREdit", "\347\272\270:             0.93", nullptr));
        QListWidgetItem *___qlistwidgetitem27 = listWidget_radiance->item(22);
        ___qlistwidgetitem27->setText(QApplication::translate("HpPLREdit", "\346\262\231\345\234\237:          0.90", nullptr));
        QListWidgetItem *___qlistwidgetitem28 = listWidget_radiance->item(23);
        ___qlistwidgetitem28->setText(QApplication::translate("HpPLREdit", "\346\267\267\345\207\235\345\234\237:       0.92", nullptr));
        listWidget_radiance->setSortingEnabled(__sortingEnabled1);

        cb_linedepth->setText(QApplication::translate("HpPLREdit", "\347\272\277\351\225\277\345\272\246\347\211\251\344\275\223\346\267\261\345\272\246\350\265\213\345\200\274             ", nullptr));
        hs_rectTemp->setPrefix(QApplication::translate("HpPLREdit", "\351\232\224\347\203\255\346\212\245\350\255\246\346\270\251\345\272\246:", nullptr));
        cb_rectTemp->setText(QApplication::translate("HpPLREdit", "\351\232\224\347\203\255\346\212\245\350\255\246                           ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HpPLREdit: public Ui_HpPLREdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPPLREDIT_H
