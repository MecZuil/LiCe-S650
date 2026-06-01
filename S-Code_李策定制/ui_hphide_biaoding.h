/********************************************************************************
** Form generated from reading UI file 'hphide_biaoding.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPHIDE_BIAODING_H
#define UI_HPHIDE_BIAODING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HpHide_Biaoding
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *frame;
    QPushButton *Button_HI;
    QPushButton *Button_LO;
    QPushButton *Button_set;
    QPushButton *Button_save;
    QPushButton *Button_cancel;
    QLabel *label_ZN;
    QLabel *label_VS;
    QLabel *label_VF;
    QLabel *label_Gain;
    QLabel *label_INT;
    QLabel *label_Max;
    QLabel *label_Min;
    QLabel *label_B;
    QSpinBox *spinBox_vs;
    QSpinBox *spinBox_vf;
    QSpinBox *spinBox_gain;
    QSpinBox *spinBox_tnt;
    QLabel *label_inmax;
    QLabel *label_inmin;
    QLabel *label_inB;
    QSpinBox *spinBox_zn;
    QSpinBox *spinBox_max;
    QSpinBox *spinBox_min;
    QSpinBox *spinBox_b;
    QLabel *label_B_2;
    QSpinBox *spinBox_facus;
    QLabel *label_B_3;
    QLabel *label_B_4;
    QSpinBox *spinBox_x;
    QSpinBox *spinBox_y;
    QLabel *label_DDE;
    QCheckBox *checkBox_DDE;
    QLabel *label_rotate;
    QCheckBox *checkBox_rotate;
    QLabel *label_oritoggle;
    QLabel *label_auto_badpixel;
    QCheckBox *checkBox_auto_badpixel;
    QSpinBox *spinBox_auto_badpixel;
    QPushButton *Button_recover;
    QPushButton *Button_oritoggle_0;
    QPushButton *Button_oritoggle_1;
    QPushButton *Button_save_focus;
    QLabel *label_B_5;
    QSpinBox *spinBox_facus_2;
    QSpinBox *spinBox_Para;
    QSpinBox *spinBox_Zoom;
    QLabel *label_Zoom;
    QLabel *label_Para;
    QPushButton *Button_X;
    QPushButton *Button_Y;
    QSpinBox *spinBox_SensibilityRange;
    QLabel *label_SensibilityRange;
    QSpinBox *spinBox_SensibilityGain;
    QCheckBox *checkBox_Sensibility;
    QLabel *label_SensibilityGain;
    QLabel *label_B_6;
    QSpinBox *spinBox_facus_3;
    QLabel *label_INTCP;
    QSpinBox *spinBox_intcp;
    QSpinBox *spinBox_adgain;
    QLabel *label_ADGAIN;
    QLabel *label_SVRD;
    QSpinBox *spinBox_svrd;
    QSpinBox *spinBox_fos;
    QLabel *label_FOS;
    QCheckBox *checkBox_OCC;
    QLabel *label_OCC;
    QSpinBox *spinBox_3DHDFF;
    QLabel *label_3DSD;
    QLabel *label_3DHDFF;
    QSpinBox *spinBox_3DSD;
    QLabel *label_OCC_4;
    QCheckBox *checkBox_VERTICAL;
    QLabel *label_OCC_3;
    QCheckBox *checkBox_SUPPRESSION;

    void setupUi(QWidget *HpHide_Biaoding)
    {
        if (HpHide_Biaoding->objectName().isEmpty())
            HpHide_Biaoding->setObjectName(QStringLiteral("HpHide_Biaoding"));
        HpHide_Biaoding->resize(800, 480);
        scrollArea = new QScrollArea(HpHide_Biaoding);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 800, 480));
        scrollArea->setStyleSheet(QLatin1String("QScrollBar:vertical{\n"
"width:38px;\n"
"border-style:flat;\n"
"}/*\n"
"QScrollBar::handle:vertical{\n"
"background:#2d3033;\n"
"width:38px;\n"
"border: 0px solid #E5E5E5;\n"
"min-height:38px;\n"
"border-radius:4px;\n"
"border-style:flat;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"height: 38px;\n"
"subcontrol-origin:margin;\n"
"border-style:flat;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"height: 38px;\n"
"subcontrol-origin:margin;\n"
"border-style:flat;\n"
"}\n"
"QScrollBar::up-arrow:vertical{\n"
"subcontrol-origin: margin;\n"
"height:38px;\n"
"width:38px;\n"
"border:0 0 0 0;\n"
"border-style:flat;\n"
"border-image: url(:/res_history/up.png);\n"
"}\n"
"QScrollBar::down-arrow:vertical{\n"
"subcontrol-origin: margin;\n"
"height:38px;\n"
"width:38px;\n"
"border-style:flat;\n"
"border-image: url(:/res_history/down.png);\n"
"}\n"
"\n"
"QScrollBar::sub-page:vertical,QScrollBar::add-page:vertical\n"
"{\n"
"    background-color:#16181a;\n"
"}*/"));
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 750, 1200));
        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 800, 1200));
        QFont font;
        font.setPointSize(9);
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Button_HI = new QPushButton(frame);
        Button_HI->setObjectName(QStringLiteral("Button_HI"));
        Button_HI->setGeometry(QRect(650, 20, 90, 45));
        QFont font1;
        font1.setPointSize(17);
        Button_HI->setFont(font1);
        Button_HI->setAutoDefault(false);
        Button_LO = new QPushButton(frame);
        Button_LO->setObjectName(QStringLiteral("Button_LO"));
        Button_LO->setGeometry(QRect(650, 100, 90, 45));
        Button_LO->setFont(font1);
        Button_set = new QPushButton(frame);
        Button_set->setObjectName(QStringLiteral("Button_set"));
        Button_set->setGeometry(QRect(650, 260, 90, 45));
        Button_set->setFont(font1);
        Button_save = new QPushButton(frame);
        Button_save->setObjectName(QStringLiteral("Button_save"));
        Button_save->setGeometry(QRect(650, 180, 90, 45));
        Button_save->setFont(font1);
        Button_cancel = new QPushButton(frame);
        Button_cancel->setObjectName(QStringLiteral("Button_cancel"));
        Button_cancel->setGeometry(QRect(650, 340, 90, 45));
        Button_cancel->setFont(font1);
        label_ZN = new QLabel(frame);
        label_ZN->setObjectName(QStringLiteral("label_ZN"));
        label_ZN->setGeometry(QRect(10, 20, 70, 40));
        label_ZN->setFont(font1);
        label_ZN->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_VS = new QLabel(frame);
        label_VS->setObjectName(QStringLiteral("label_VS"));
        label_VS->setGeometry(QRect(10, 70, 70, 40));
        label_VS->setFont(font1);
        label_VS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_VF = new QLabel(frame);
        label_VF->setObjectName(QStringLiteral("label_VF"));
        label_VF->setGeometry(QRect(10, 120, 70, 40));
        label_VF->setFont(font1);
        label_VF->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_Gain = new QLabel(frame);
        label_Gain->setObjectName(QStringLiteral("label_Gain"));
        label_Gain->setGeometry(QRect(10, 170, 70, 40));
        label_Gain->setFont(font1);
        label_Gain->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_INT = new QLabel(frame);
        label_INT->setObjectName(QStringLiteral("label_INT"));
        label_INT->setGeometry(QRect(10, 220, 70, 40));
        label_INT->setFont(font1);
        label_INT->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_Max = new QLabel(frame);
        label_Max->setObjectName(QStringLiteral("label_Max"));
        label_Max->setGeometry(QRect(10, 270, 70, 40));
        label_Max->setFont(font1);
        label_Max->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_Min = new QLabel(frame);
        label_Min->setObjectName(QStringLiteral("label_Min"));
        label_Min->setGeometry(QRect(10, 320, 70, 40));
        label_Min->setFont(font1);
        label_Min->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_B = new QLabel(frame);
        label_B->setObjectName(QStringLiteral("label_B"));
        label_B->setGeometry(QRect(10, 370, 70, 40));
        label_B->setFont(font1);
        label_B->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_vs = new QSpinBox(frame);
        spinBox_vs->setObjectName(QStringLiteral("spinBox_vs"));
        spinBox_vs->setGeometry(QRect(90, 75, 200, 30));
        QFont font2;
        font2.setPointSize(16);
        spinBox_vs->setFont(font2);
        spinBox_vs->setLayoutDirection(Qt::LeftToRight);
        spinBox_vs->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}"));
        spinBox_vs->setAlignment(Qt::AlignCenter);
        spinBox_vs->setMinimum(0);
        spinBox_vs->setMaximum(65535);
        spinBox_vf = new QSpinBox(frame);
        spinBox_vf->setObjectName(QStringLiteral("spinBox_vf"));
        spinBox_vf->setGeometry(QRect(90, 125, 200, 30));
        spinBox_vf->setFont(font2);
        spinBox_vf->setLayoutDirection(Qt::LeftToRight);
        spinBox_vf->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}"));
        spinBox_vf->setAlignment(Qt::AlignCenter);
        spinBox_vf->setMinimum(0);
        spinBox_vf->setMaximum(65535);
        spinBox_gain = new QSpinBox(frame);
        spinBox_gain->setObjectName(QStringLiteral("spinBox_gain"));
        spinBox_gain->setGeometry(QRect(90, 175, 200, 30));
        spinBox_gain->setFont(font2);
        spinBox_gain->setLayoutDirection(Qt::LeftToRight);
        spinBox_gain->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
""));
        spinBox_gain->setAlignment(Qt::AlignCenter);
        spinBox_gain->setMinimum(0);
        spinBox_gain->setMaximum(9);
        spinBox_tnt = new QSpinBox(frame);
        spinBox_tnt->setObjectName(QStringLiteral("spinBox_tnt"));
        spinBox_tnt->setGeometry(QRect(90, 225, 200, 30));
        spinBox_tnt->setFont(font2);
        spinBox_tnt->setLayoutDirection(Qt::LeftToRight);
        spinBox_tnt->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}"));
        spinBox_tnt->setAlignment(Qt::AlignCenter);
        spinBox_tnt->setMinimum(0);
        spinBox_tnt->setMaximum(1000);
        label_inmax = new QLabel(frame);
        label_inmax->setObjectName(QStringLiteral("label_inmax"));
        label_inmax->setGeometry(QRect(190, 285, 200, 30));
        label_inmax->setFont(font2);
        label_inmax->setAlignment(Qt::AlignCenter);
        label_inmin = new QLabel(frame);
        label_inmin->setObjectName(QStringLiteral("label_inmin"));
        label_inmin->setGeometry(QRect(190, 335, 200, 30));
        label_inmin->setFont(font2);
        label_inmin->setAlignment(Qt::AlignCenter);
        label_inB = new QLabel(frame);
        label_inB->setObjectName(QStringLiteral("label_inB"));
        label_inB->setGeometry(QRect(190, 385, 200, 30));
        label_inB->setFont(font2);
        label_inB->setAlignment(Qt::AlignCenter);
        spinBox_zn = new QSpinBox(frame);
        spinBox_zn->setObjectName(QStringLiteral("spinBox_zn"));
        spinBox_zn->setGeometry(QRect(90, 25, 200, 30));
        spinBox_zn->setFont(font2);
        spinBox_zn->setLayoutDirection(Qt::LeftToRight);
        spinBox_zn->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"   "
                        " height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}"));
        spinBox_zn->setAlignment(Qt::AlignCenter);
        spinBox_zn->setMinimum(-1000000);
        spinBox_zn->setMaximum(10000000);
        spinBox_max = new QSpinBox(frame);
        spinBox_max->setObjectName(QStringLiteral("spinBox_max"));
        spinBox_max->setGeometry(QRect(90, 275, 200, 30));
        spinBox_max->setFont(font2);
        spinBox_max->setLayoutDirection(Qt::LeftToRight);
        spinBox_max->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"   "
                        " height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}"));
        spinBox_max->setAlignment(Qt::AlignCenter);
        spinBox_max->setMinimum(-10000000);
        spinBox_max->setMaximum(100000000);
        spinBox_max->setSingleStep(0);
        spinBox_min = new QSpinBox(frame);
        spinBox_min->setObjectName(QStringLiteral("spinBox_min"));
        spinBox_min->setGeometry(QRect(90, 325, 200, 30));
        spinBox_min->setFont(font2);
        spinBox_min->setLayoutDirection(Qt::LeftToRight);
        spinBox_min->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"   "
                        " height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}"));
        spinBox_min->setAlignment(Qt::AlignCenter);
        spinBox_min->setMinimum(-100000000);
        spinBox_min->setMaximum(100000000);
        spinBox_b = new QSpinBox(frame);
        spinBox_b->setObjectName(QStringLiteral("spinBox_b"));
        spinBox_b->setGeometry(QRect(90, 380, 200, 30));
        spinBox_b->setFont(font2);
        spinBox_b->setLayoutDirection(Qt::LeftToRight);
        spinBox_b->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"   "
                        " height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/mwiyou.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_b->setAlignment(Qt::AlignCenter);
        spinBox_b->setMinimum(-10000000);
        spinBox_b->setMaximum(10000000);
        label_B_2 = new QLabel(frame);
        label_B_2->setObjectName(QStringLiteral("label_B_2"));
        label_B_2->setGeometry(QRect(29, 435, 171, 40));
        label_B_2->setFont(font1);
        label_B_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_facus = new QSpinBox(frame);
        spinBox_facus->setObjectName(QStringLiteral("spinBox_facus"));
        spinBox_facus->setGeometry(QRect(221, 440, 200, 30));
        spinBox_facus->setFont(font2);
        spinBox_facus->setLayoutDirection(Qt::LeftToRight);
        spinBox_facus->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_facus->setAlignment(Qt::AlignCenter);
        spinBox_facus->setMinimum(0);
        spinBox_facus->setMaximum(1000);
        label_B_3 = new QLabel(frame);
        label_B_3->setObjectName(QStringLiteral("label_B_3"));
        label_B_3->setGeometry(QRect(80, 595, 51, 40));
        label_B_3->setFont(font1);
        label_B_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_B_4 = new QLabel(frame);
        label_B_4->setObjectName(QStringLiteral("label_B_4"));
        label_B_4->setGeometry(QRect(80, 660, 51, 40));
        label_B_4->setFont(font1);
        label_B_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_x = new QSpinBox(frame);
        spinBox_x->setObjectName(QStringLiteral("spinBox_x"));
        spinBox_x->setGeometry(QRect(160, 595, 200, 30));
        spinBox_x->setFont(font2);
        spinBox_x->setLayoutDirection(Qt::LeftToRight);
        spinBox_x->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_x->setAlignment(Qt::AlignCenter);
        spinBox_x->setMinimum(0);
        spinBox_x->setMaximum(1000);
        spinBox_y = new QSpinBox(frame);
        spinBox_y->setObjectName(QStringLiteral("spinBox_y"));
        spinBox_y->setGeometry(QRect(160, 660, 200, 30));
        spinBox_y->setFont(font2);
        spinBox_y->setLayoutDirection(Qt::LeftToRight);
        spinBox_y->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_y->setAlignment(Qt::AlignCenter);
        spinBox_y->setMinimum(0);
        spinBox_y->setMaximum(1000);
        label_DDE = new QLabel(frame);
        label_DDE->setObjectName(QStringLiteral("label_DDE"));
        label_DDE->setGeometry(QRect(410, 895, 111, 40));
        label_DDE->setFont(font1);
        label_DDE->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_DDE = new QCheckBox(frame);
        checkBox_DDE->setObjectName(QStringLiteral("checkBox_DDE"));
        checkBox_DDE->setEnabled(true);
        checkBox_DDE->setGeometry(QRect(540, 890, 70, 50));
        checkBox_DDE->setFont(font1);
        checkBox_DDE->setFocusPolicy(Qt::NoFocus);
        checkBox_DDE->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
""));
        checkBox_DDE->setTristate(false);
        label_rotate = new QLabel(frame);
        label_rotate->setObjectName(QStringLiteral("label_rotate"));
        label_rotate->setGeometry(QRect(70, 900, 111, 40));
        label_rotate->setFont(font1);
        label_rotate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_rotate = new QCheckBox(frame);
        checkBox_rotate->setObjectName(QStringLiteral("checkBox_rotate"));
        checkBox_rotate->setEnabled(true);
        checkBox_rotate->setGeometry(QRect(200, 895, 70, 50));
        checkBox_rotate->setFont(font1);
        checkBox_rotate->setFocusPolicy(Qt::NoFocus);
        checkBox_rotate->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
""));
        checkBox_rotate->setTristate(false);
        label_oritoggle = new QLabel(frame);
        label_oritoggle->setObjectName(QStringLiteral("label_oritoggle"));
        label_oritoggle->setGeometry(QRect(10, 950, 171, 40));
        label_oritoggle->setFont(font1);
        label_oritoggle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_auto_badpixel = new QLabel(frame);
        label_auto_badpixel->setObjectName(QStringLiteral("label_auto_badpixel"));
        label_auto_badpixel->setGeometry(QRect(10, 1010, 171, 40));
        label_auto_badpixel->setFont(font1);
        label_auto_badpixel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_auto_badpixel = new QCheckBox(frame);
        checkBox_auto_badpixel->setObjectName(QStringLiteral("checkBox_auto_badpixel"));
        checkBox_auto_badpixel->setEnabled(true);
        checkBox_auto_badpixel->setGeometry(QRect(430, 1005, 70, 50));
        checkBox_auto_badpixel->setFont(font1);
        checkBox_auto_badpixel->setFocusPolicy(Qt::NoFocus);
        checkBox_auto_badpixel->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
""));
        checkBox_auto_badpixel->setTristate(false);
        spinBox_auto_badpixel = new QSpinBox(frame);
        spinBox_auto_badpixel->setObjectName(QStringLiteral("spinBox_auto_badpixel"));
        spinBox_auto_badpixel->setGeometry(QRect(200, 1015, 200, 30));
        spinBox_auto_badpixel->setFont(font2);
        spinBox_auto_badpixel->setLayoutDirection(Qt::LeftToRight);
        spinBox_auto_badpixel->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_auto_badpixel->setAlignment(Qt::AlignCenter);
        spinBox_auto_badpixel->setMinimum(0);
        spinBox_auto_badpixel->setMaximum(255);
        Button_recover = new QPushButton(frame);
        Button_recover->setObjectName(QStringLiteral("Button_recover"));
        Button_recover->setGeometry(QRect(60, 1075, 191, 45));
        Button_recover->setFont(font1);
        Button_recover->setStyleSheet(QStringLiteral("background-color: rgb(170, 85, 255);"));
        Button_recover->setAutoDefault(false);
        Button_oritoggle_0 = new QPushButton(frame);
        Button_oritoggle_0->setObjectName(QStringLiteral("Button_oritoggle_0"));
        Button_oritoggle_0->setGeometry(QRect(200, 955, 191, 45));
        Button_oritoggle_0->setFont(font1);
        Button_oritoggle_0->setAutoDefault(false);
        Button_oritoggle_1 = new QPushButton(frame);
        Button_oritoggle_1->setObjectName(QStringLiteral("Button_oritoggle_1"));
        Button_oritoggle_1->setGeometry(QRect(410, 955, 191, 45));
        Button_oritoggle_1->setFont(font1);
        Button_oritoggle_1->setAutoDefault(false);
        Button_save_focus = new QPushButton(frame);
        Button_save_focus->setObjectName(QStringLiteral("Button_save_focus"));
        Button_save_focus->setGeometry(QRect(440, 460, 161, 71));
        Button_save_focus->setFont(font1);
        label_B_5 = new QLabel(frame);
        label_B_5->setObjectName(QStringLiteral("label_B_5"));
        label_B_5->setGeometry(QRect(20, 475, 181, 40));
        label_B_5->setFont(font1);
        label_B_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_facus_2 = new QSpinBox(frame);
        spinBox_facus_2->setObjectName(QStringLiteral("spinBox_facus_2"));
        spinBox_facus_2->setGeometry(QRect(221, 480, 200, 30));
        spinBox_facus_2->setFont(font2);
        spinBox_facus_2->setLayoutDirection(Qt::LeftToRight);
        spinBox_facus_2->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_n."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_facus_2->setAlignment(Qt::AlignCenter);
        spinBox_facus_2->setMinimum(0);
        spinBox_facus_2->setMaximum(1000);
        spinBox_Para = new QSpinBox(frame);
        spinBox_Para->setObjectName(QStringLiteral("spinBox_Para"));
        spinBox_Para->setGeometry(QRect(220, 726, 200, 30));
        spinBox_Para->setFont(font2);
        spinBox_Para->setLayoutDirection(Qt::LeftToRight);
        spinBox_Para->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_Para->setAlignment(Qt::AlignCenter);
        spinBox_Para->setMinimum(0);
        spinBox_Para->setMaximum(255);
        spinBox_Zoom = new QSpinBox(frame);
        spinBox_Zoom->setObjectName(QStringLiteral("spinBox_Zoom"));
        spinBox_Zoom->setGeometry(QRect(220, 765, 200, 30));
        spinBox_Zoom->setFont(font2);
        spinBox_Zoom->setLayoutDirection(Qt::LeftToRight);
        spinBox_Zoom->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_Zoom->setAlignment(Qt::AlignCenter);
        spinBox_Zoom->setMinimum(0);
        spinBox_Zoom->setMaximum(255);
        label_Zoom = new QLabel(frame);
        label_Zoom->setObjectName(QStringLiteral("label_Zoom"));
        label_Zoom->setGeometry(QRect(0, 760, 201, 40));
        label_Zoom->setFont(font1);
        label_Zoom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_Para = new QLabel(frame);
        label_Para->setObjectName(QStringLiteral("label_Para"));
        label_Para->setGeometry(QRect(-1, 721, 201, 40));
        label_Para->setFont(font1);
        label_Para->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Button_X = new QPushButton(frame);
        Button_X->setObjectName(QStringLiteral("Button_X"));
        Button_X->setGeometry(QRect(400, 590, 211, 41));
        Button_X->setFont(font1);
        Button_Y = new QPushButton(frame);
        Button_Y->setObjectName(QStringLiteral("Button_Y"));
        Button_Y->setGeometry(QRect(400, 650, 211, 41));
        Button_Y->setFont(font1);
        spinBox_SensibilityRange = new QSpinBox(frame);
        spinBox_SensibilityRange->setObjectName(QStringLiteral("spinBox_SensibilityRange"));
        spinBox_SensibilityRange->setGeometry(QRect(421, 1080, 200, 30));
        spinBox_SensibilityRange->setFont(font2);
        spinBox_SensibilityRange->setLayoutDirection(Qt::LeftToRight);
        spinBox_SensibilityRange->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_SensibilityRange->setAlignment(Qt::AlignCenter);
        spinBox_SensibilityRange->setMinimum(1);
        spinBox_SensibilityRange->setMaximum(16);
        label_SensibilityRange = new QLabel(frame);
        label_SensibilityRange->setObjectName(QStringLiteral("label_SensibilityRange"));
        label_SensibilityRange->setGeometry(QRect(260, 1075, 141, 40));
        label_SensibilityRange->setFont(font1);
        label_SensibilityRange->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_SensibilityGain = new QSpinBox(frame);
        spinBox_SensibilityGain->setObjectName(QStringLiteral("spinBox_SensibilityGain"));
        spinBox_SensibilityGain->setGeometry(QRect(420, 1145, 200, 30));
        spinBox_SensibilityGain->setFont(font2);
        spinBox_SensibilityGain->setLayoutDirection(Qt::LeftToRight);
        spinBox_SensibilityGain->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_SensibilityGain->setAlignment(Qt::AlignCenter);
        spinBox_SensibilityGain->setMinimum(1);
        spinBox_SensibilityGain->setMaximum(9);
        checkBox_Sensibility = new QCheckBox(frame);
        checkBox_Sensibility->setObjectName(QStringLiteral("checkBox_Sensibility"));
        checkBox_Sensibility->setEnabled(true);
        checkBox_Sensibility->setGeometry(QRect(650, 1075, 70, 50));
        checkBox_Sensibility->setFont(font1);
        checkBox_Sensibility->setFocusPolicy(Qt::NoFocus);
        checkBox_Sensibility->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
""));
        checkBox_Sensibility->setTristate(false);
        label_SensibilityGain = new QLabel(frame);
        label_SensibilityGain->setObjectName(QStringLiteral("label_SensibilityGain"));
        label_SensibilityGain->setGeometry(QRect(270, 1140, 131, 40));
        label_SensibilityGain->setFont(font1);
        label_SensibilityGain->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_B_6 = new QLabel(frame);
        label_B_6->setObjectName(QStringLiteral("label_B_6"));
        label_B_6->setGeometry(QRect(20, 513, 181, 40));
        label_B_6->setFont(font1);
        label_B_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_facus_3 = new QSpinBox(frame);
        spinBox_facus_3->setObjectName(QStringLiteral("spinBox_facus_3"));
        spinBox_facus_3->setGeometry(QRect(221, 518, 200, 30));
        spinBox_facus_3->setFont(font2);
        spinBox_facus_3->setLayoutDirection(Qt::LeftToRight);
        spinBox_facus_3->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_n."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_facus_3->setAlignment(Qt::AlignCenter);
        spinBox_facus_3->setMinimum(0);
        spinBox_facus_3->setMaximum(1000);
        label_INTCP = new QLabel(frame);
        label_INTCP->setObjectName(QStringLiteral("label_INTCP"));
        label_INTCP->setGeometry(QRect(305, 20, 100, 40));
        label_INTCP->setFont(font1);
        label_INTCP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_intcp = new QSpinBox(frame);
        spinBox_intcp->setObjectName(QStringLiteral("spinBox_intcp"));
        spinBox_intcp->setGeometry(QRect(410, 25, 200, 30));
        spinBox_intcp->setFont(font2);
        spinBox_intcp->setLayoutDirection(Qt::LeftToRight);
        spinBox_intcp->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}"));
        spinBox_intcp->setAlignment(Qt::AlignCenter);
        spinBox_intcp->setMinimum(0);
        spinBox_intcp->setMaximum(1000);
        spinBox_adgain = new QSpinBox(frame);
        spinBox_adgain->setObjectName(QStringLiteral("spinBox_adgain"));
        spinBox_adgain->setGeometry(QRect(410, 75, 200, 30));
        spinBox_adgain->setFont(font2);
        spinBox_adgain->setLayoutDirection(Qt::LeftToRight);
        spinBox_adgain->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
""));
        spinBox_adgain->setAlignment(Qt::AlignCenter);
        spinBox_adgain->setMinimum(0);
        spinBox_adgain->setMaximum(10001);
        label_ADGAIN = new QLabel(frame);
        label_ADGAIN->setObjectName(QStringLiteral("label_ADGAIN"));
        label_ADGAIN->setGeometry(QRect(305, 70, 100, 40));
        label_ADGAIN->setFont(font1);
        label_ADGAIN->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_SVRD = new QLabel(frame);
        label_SVRD->setObjectName(QStringLiteral("label_SVRD"));
        label_SVRD->setGeometry(QRect(305, 120, 100, 40));
        label_SVRD->setFont(font1);
        label_SVRD->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_svrd = new QSpinBox(frame);
        spinBox_svrd->setObjectName(QStringLiteral("spinBox_svrd"));
        spinBox_svrd->setGeometry(QRect(410, 125, 200, 30));
        spinBox_svrd->setFont(font2);
        spinBox_svrd->setLayoutDirection(Qt::LeftToRight);
        spinBox_svrd->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
""));
        spinBox_svrd->setAlignment(Qt::AlignCenter);
        spinBox_svrd->setMinimum(0);
        spinBox_svrd->setMaximum(10000);
        spinBox_fos = new QSpinBox(frame);
        spinBox_fos->setObjectName(QStringLiteral("spinBox_fos"));
        spinBox_fos->setGeometry(QRect(411, 175, 200, 30));
        spinBox_fos->setFont(font2);
        spinBox_fos->setLayoutDirection(Qt::LeftToRight);
        spinBox_fos->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
""));
        spinBox_fos->setAlignment(Qt::AlignCenter);
        spinBox_fos->setMinimum(0);
        spinBox_fos->setMaximum(10000);
        label_FOS = new QLabel(frame);
        label_FOS->setObjectName(QStringLiteral("label_FOS"));
        label_FOS->setGeometry(QRect(305, 170, 100, 40));
        label_FOS->setFont(font1);
        label_FOS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_OCC = new QCheckBox(frame);
        checkBox_OCC->setObjectName(QStringLiteral("checkBox_OCC"));
        checkBox_OCC->setEnabled(true);
        checkBox_OCC->setGeometry(QRect(560, 220, 70, 50));
        checkBox_OCC->setFont(font1);
        checkBox_OCC->setFocusPolicy(Qt::NoFocus);
        checkBox_OCC->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
""));
        checkBox_OCC->setTristate(false);
        label_OCC = new QLabel(frame);
        label_OCC->setObjectName(QStringLiteral("label_OCC"));
        label_OCC->setGeometry(QRect(445, 225, 100, 40));
        label_OCC->setFont(font1);
        label_OCC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_3DHDFF = new QSpinBox(frame);
        spinBox_3DHDFF->setObjectName(QStringLiteral("spinBox_3DHDFF"));
        spinBox_3DHDFF->setGeometry(QRect(220, 810, 200, 30));
        spinBox_3DHDFF->setFont(font2);
        spinBox_3DHDFF->setLayoutDirection(Qt::LeftToRight);
        spinBox_3DHDFF->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_3DHDFF->setAlignment(Qt::AlignCenter);
        spinBox_3DHDFF->setMinimum(0);
        spinBox_3DHDFF->setMaximum(255);
        label_3DSD = new QLabel(frame);
        label_3DSD->setObjectName(QStringLiteral("label_3DSD"));
        label_3DSD->setGeometry(QRect(0, 845, 201, 40));
        label_3DSD->setFont(font1);
        label_3DSD->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3DHDFF = new QLabel(frame);
        label_3DHDFF->setObjectName(QStringLiteral("label_3DHDFF"));
        label_3DHDFF->setGeometry(QRect(-1, 805, 201, 40));
        label_3DHDFF->setFont(font1);
        label_3DHDFF->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_3DSD = new QSpinBox(frame);
        spinBox_3DSD->setObjectName(QStringLiteral("spinBox_3DSD"));
        spinBox_3DSD->setGeometry(QRect(220, 850, 200, 30));
        spinBox_3DSD->setFont(font2);
        spinBox_3DSD->setLayoutDirection(Qt::LeftToRight);
        spinBox_3DSD->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"		background-color: rgb(173, 173, 173);\n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"\n"
"}\n"
"QSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;       \n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d."
                        "png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
"\n"
"QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 28;\n"
"    height: 28;\n"
"}\n"
""));
        spinBox_3DSD->setAlignment(Qt::AlignCenter);
        spinBox_3DSD->setMinimum(0);
        spinBox_3DSD->setMaximum(255);
        label_OCC_4 = new QLabel(frame);
        label_OCC_4->setObjectName(QStringLiteral("label_OCC_4"));
        label_OCC_4->setGeometry(QRect(330, 341, 221, 51));
        label_OCC_4->setFont(font1);
        label_OCC_4->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label_OCC_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_VERTICAL = new QCheckBox(frame);
        checkBox_VERTICAL->setObjectName(QStringLiteral("checkBox_VERTICAL"));
        checkBox_VERTICAL->setEnabled(true);
        checkBox_VERTICAL->setGeometry(QRect(560, 292, 70, 50));
        checkBox_VERTICAL->setFont(font1);
        checkBox_VERTICAL->setFocusPolicy(Qt::NoFocus);
        checkBox_VERTICAL->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
""));
        checkBox_VERTICAL->setTristate(false);
        label_OCC_3 = new QLabel(frame);
        label_OCC_3->setObjectName(QStringLiteral("label_OCC_3"));
        label_OCC_3->setGeometry(QRect(380, 290, 171, 51));
        label_OCC_3->setFont(font1);
        label_OCC_3->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label_OCC_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_SUPPRESSION = new QCheckBox(frame);
        checkBox_SUPPRESSION->setObjectName(QStringLiteral("checkBox_SUPPRESSION"));
        checkBox_SUPPRESSION->setEnabled(true);
        checkBox_SUPPRESSION->setGeometry(QRect(560, 340, 70, 50));
        checkBox_SUPPRESSION->setFont(font1);
        checkBox_SUPPRESSION->setFocusPolicy(Qt::NoFocus);
        checkBox_SUPPRESSION->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
""));
        checkBox_SUPPRESSION->setTristate(false);
        label_DDE->raise();
        label_rotate->raise();
        checkBox_DDE->raise();
        checkBox_rotate->raise();
        label_B_3->raise();
        spinBox_x->raise();
        label_B_4->raise();
        spinBox_y->raise();
        Button_HI->raise();
        Button_LO->raise();
        Button_set->raise();
        Button_save->raise();
        Button_cancel->raise();
        label_ZN->raise();
        label_VS->raise();
        label_VF->raise();
        label_Gain->raise();
        label_INT->raise();
        label_Max->raise();
        label_Min->raise();
        label_B->raise();
        spinBox_vs->raise();
        spinBox_vf->raise();
        spinBox_gain->raise();
        spinBox_tnt->raise();
        label_inmax->raise();
        label_inmin->raise();
        label_inB->raise();
        spinBox_zn->raise();
        spinBox_max->raise();
        spinBox_min->raise();
        spinBox_b->raise();
        label_B_2->raise();
        spinBox_facus->raise();
        label_oritoggle->raise();
        label_auto_badpixel->raise();
        checkBox_auto_badpixel->raise();
        spinBox_auto_badpixel->raise();
        Button_recover->raise();
        Button_oritoggle_0->raise();
        Button_oritoggle_1->raise();
        Button_save_focus->raise();
        label_B_5->raise();
        spinBox_facus_2->raise();
        spinBox_Para->raise();
        spinBox_Zoom->raise();
        label_Zoom->raise();
        label_Para->raise();
        Button_X->raise();
        Button_Y->raise();
        spinBox_SensibilityRange->raise();
        label_SensibilityRange->raise();
        spinBox_SensibilityGain->raise();
        checkBox_Sensibility->raise();
        label_SensibilityGain->raise();
        label_B_6->raise();
        spinBox_facus_3->raise();
        label_INTCP->raise();
        spinBox_intcp->raise();
        spinBox_adgain->raise();
        label_ADGAIN->raise();
        label_SVRD->raise();
        spinBox_svrd->raise();
        spinBox_fos->raise();
        label_FOS->raise();
        checkBox_OCC->raise();
        label_OCC->raise();
        spinBox_3DHDFF->raise();
        label_3DSD->raise();
        label_3DHDFF->raise();
        spinBox_3DSD->raise();
        label_OCC_4->raise();
        checkBox_VERTICAL->raise();
        label_OCC_3->raise();
        checkBox_SUPPRESSION->raise();
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(HpHide_Biaoding);

        Button_HI->setDefault(false);
        Button_recover->setDefault(false);
        Button_oritoggle_0->setDefault(false);
        Button_oritoggle_1->setDefault(false);


        QMetaObject::connectSlotsByName(HpHide_Biaoding);
    } // setupUi

    void retranslateUi(QWidget *HpHide_Biaoding)
    {
        HpHide_Biaoding->setWindowTitle(QApplication::translate("HpHide_Biaoding", "Form", nullptr));
        Button_HI->setText(QApplication::translate("HpHide_Biaoding", "HI", nullptr));
        Button_LO->setText(QApplication::translate("HpHide_Biaoding", "LO", nullptr));
        Button_set->setText(QApplication::translate("HpHide_Biaoding", "\350\256\276\347\275\256", nullptr));
        Button_save->setText(QApplication::translate("HpHide_Biaoding", "\344\277\235\345\255\230", nullptr));
        Button_cancel->setText(QApplication::translate("HpHide_Biaoding", "\351\200\200\345\207\272", nullptr));
        label_ZN->setText(QApplication::translate("HpHide_Biaoding", "ZN:", nullptr));
        label_VS->setText(QApplication::translate("HpHide_Biaoding", "VS:", nullptr));
        label_VF->setText(QApplication::translate("HpHide_Biaoding", "VF:", nullptr));
        label_Gain->setText(QApplication::translate("HpHide_Biaoding", "Gain:", nullptr));
        label_INT->setText(QApplication::translate("HpHide_Biaoding", "INT:", nullptr));
        label_Max->setText(QApplication::translate("HpHide_Biaoding", "Max:", nullptr));
        label_Min->setText(QApplication::translate("HpHide_Biaoding", "Min:", nullptr));
        label_B->setText(QApplication::translate("HpHide_Biaoding", "B:", nullptr));
        label_inmax->setText(QString());
        label_inmin->setText(QString());
        label_inB->setText(QString());
        label_B_2->setText(QApplication::translate("HpHide_Biaoding", "laser_FOCUS:", nullptr));
        label_B_3->setText(QApplication::translate("HpHide_Biaoding", "X:", nullptr));
        label_B_4->setText(QApplication::translate("HpHide_Biaoding", "Y:", nullptr));
        label_DDE->setText(QApplication::translate("HpHide_Biaoding", "DDE:", nullptr));
        checkBox_DDE->setText(QString());
        label_rotate->setText(QApplication::translate("HpHide_Biaoding", "\345\233\276\345\203\217\346\227\213\350\275\254:", nullptr));
        checkBox_rotate->setText(QString());
        label_oritoggle->setText(QApplication::translate("HpHide_Biaoding", "\345\216\237\345\247\213\344\270\244\347\202\271\345\210\207\346\215\242:", nullptr));
        label_auto_badpixel->setText(QApplication::translate("HpHide_Biaoding", "\350\207\252\345\212\250\346\211\223\346\255\273\347\202\271:", nullptr));
        checkBox_auto_badpixel->setText(QString());
        Button_recover->setText(QApplication::translate("HpHide_Biaoding", "\346\201\242\345\244\215\346\255\273\347\202\271", nullptr));
        Button_oritoggle_0->setText(QApplication::translate("HpHide_Biaoding", "\346\230\276\347\244\272\344\270\244\347\202\271\345\233\276\345\203\217", nullptr));
        Button_oritoggle_1->setText(QApplication::translate("HpHide_Biaoding", "\346\230\276\347\244\272\345\216\237\345\247\213\345\233\276\345\203\217", nullptr));
        Button_save_focus->setText(QApplication::translate("HpHide_Biaoding", "\344\277\235\345\255\230FOCUS\345\200\274", nullptr));
        label_B_5->setText(QApplication::translate("HpHide_Biaoding", "general_FOCUS:", nullptr));
        label_Zoom->setText(QApplication::translate("HpHide_Biaoding", "\347\273\206\350\212\202\345\242\236\345\274\272\345\200\215\346\225\260:", nullptr));
        label_Para->setText(QApplication::translate("HpHide_Biaoding", "\345\274\225\345\257\274\346\273\244\346\263\242\345\217\202\346\225\260:", nullptr));
        Button_X->setText(QApplication::translate("HpHide_Biaoding", "\350\256\276\347\275\256X\345\200\274", nullptr));
        Button_Y->setText(QApplication::translate("HpHide_Biaoding", "\350\256\276\347\275\256Y\345\200\274", nullptr));
        label_SensibilityRange->setText(QApplication::translate("HpHide_Biaoding", "\347\201\265\346\225\217\345\272\246\346\241\243\344\275\215:", nullptr));
        checkBox_Sensibility->setText(QString());
        label_SensibilityGain->setText(QApplication::translate("HpHide_Biaoding", "\347\201\265\346\225\217\345\272\246\345\242\236\347\233\212:", nullptr));
        label_B_6->setText(QApplication::translate("HpHide_Biaoding", "fast_FOCUS:", nullptr));
        label_INTCP->setText(QApplication::translate("HpHide_Biaoding", "INTCP:", nullptr));
        label_ADGAIN->setText(QApplication::translate("HpHide_Biaoding", "ADGain:", nullptr));
        label_SVRD->setText(QApplication::translate("HpHide_Biaoding", "SVRD:", nullptr));
        label_FOS->setText(QApplication::translate("HpHide_Biaoding", "FOS:", nullptr));
        checkBox_OCC->setText(QString());
        label_OCC->setText(QApplication::translate("HpHide_Biaoding", "OCC:", nullptr));
        label_3DSD->setText(QApplication::translate("HpHide_Biaoding", "3D\347\251\272\345\237\237\345\217\202\346\225\260:", nullptr));
        label_3DHDFF->setText(QApplication::translate("HpHide_Biaoding", "3D\346\227\266\345\237\237\345\217\202\346\225\260:", nullptr));
        label_OCC_4->setText(QApplication::translate("HpHide_Biaoding", "\345\235\207\345\214\200\351\235\242\346\212\221\345\210\266\345\244\204\347\220\206\357\274\232", nullptr));
        checkBox_VERTICAL->setText(QString());
        label_OCC_3->setText(QApplication::translate("HpHide_Biaoding", "\347\253\226\347\272\271\345\244\204\347\220\206\357\274\232", nullptr));
        checkBox_SUPPRESSION->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HpHide_Biaoding: public Ui_HpHide_Biaoding {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPHIDE_BIAODING_H
