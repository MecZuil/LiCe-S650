/********************************************************************************
** Form generated from reading UI file 'hpsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPSETTING_H
#define UI_HPSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <hp_qdoublespinboxset.h>
#include <hp_style_scrollarea.h>
#include "hp_button.h"
#include "hp_qspinbox.h"
#include "hp_qspinboxset.h"
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_HpSetting
{
public:
    QFrame *frame;
    QTabWidget *tabWidget;
    QWidget *tab_6;
    QWidget *tab;
    hp_QDoubleSpinBoxSet *ScrollBar_Distance;
    QCheckBox *checkBox_ReferTemp_enable;
    hp_QSpinBoxSet *ScrollBar_Humidity;
    hp_QSpinBoxSet *ScrollBar_transmission;
    hp_QDoubleSpinBoxSet *ScrollBar_ReflectTemp;
    hp_QSpinBoxSet *ScrollBar_Radiance;
    hp_QDoubleSpinBoxSet *ScrollBar_ReferTemp;
    Hp_QSpinBox *ScrollBar_TempUnit;
    hp_QDoubleSpinBoxSet *ScrollBar_AmbientTempManu;
    QFrame *frame_Radiance;
    QLabel *label_Radiance;
    QLabel *label_Radiance_2;
    QCheckBox *checkBox_Radiance;
    QListWidget *listWidget_Radiance;
    QFrame *frame_ReflectTemp;
    QLabel *label_ReflectTemp;
    QLabel *label_ReflectTemp_2;
    QListWidget *listWidget_ReflectTemp;
    QCheckBox *checkBox_ReflectTemp_enable;
    QWidget *tab_2;
    QLabel *label_13;
    QComboBox *comboBox_jingtou;
    QLabel *label_10;
    QLabel *label_11;
    QComboBox *comboBox_baojingshezhi;
    QLabel *label_15;
    QComboBox *comboBox_baojingse;
    QLabel *label_9;
    QComboBox *comboBox_dangwei;
    hp_QSpinBoxSet *cwfw_autorectify;
    QFrame *frame_jingtou;
    QLabel *label_jingtou;
    QLabel *label_jingtou_2;
    QListWidget *listWidget_jingtou;
    QFrame *frame_wendang;
    QLabel *label_wendang;
    QLabel *label_wendang_2;
    QListWidget *listWidget_wendang;
    QListWidget *listWidget_baojingshezhi;
    QListWidget *listWidget_baojingse;
    QFrame *frame_bangjingshehzi;
    QLabel *label_bangjingshehzi;
    QLabel *label_bangjingshehzi_2;
    QFrame *frame_baojingse;
    QLabel *label_baojingse;
    QLabel *label_baojingse_2;
    QPushButton *pushButton_qiehuan;
    hp_QDoubleSpinBoxSet *comboBox_baojingwendu;
    QLabel *label_20;
    QCheckBox *checkBox_Catch;
    hp_QDoubleSpinBoxSet *comboBox_buchangwendu;
    QLabel *label_30;
    QToolButton *dengwengse_edit;
    hp_QDoubleSpinBoxSet *comboBox_baojingjuli;
    QWidget *tab_3;
    hp_QSpinBoxSet *spinBox_autosave;
    QLabel *label_24;
    QComboBox *comboBox_usbmode;
    QLabel *label_19;
    QFrame *frame_usbmode;
    QLabel *label_usbmode;
    QLabel *label_usbmode_2;
    QListWidget *listWidget_usbmode;
    QLabel *label_29;
    QFrame *frame_recordmode;
    QLabel *label_recordmode;
    QLabel *label_recordmode_2;
    QListWidget *listWidget_recordmode;
    QFrame *frame_modeSelect;
    QLabel *label_modeSelect;
    QLabel *label_modeSelect_2;
    QListWidget *listWidget_modeSelect;
    QLabel *label_32;
    hp_style_scrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_16;
    QLabel *label_21;
    QLabel *label_26;
    QLabel *label_18;
    QCheckBox *checkBox_ble;
    QCheckBox *checkBox_area;
    QCheckBox *buguangdeng;
    QCheckBox *checkBox_sr;
    QLabel *label_17;
    QLabel *label_27;
    QLabel *label_28;
    QCheckBox *checkBox_fid;
    QCheckBox *checkBox_pid;
    QLabel *label_31;
    QCheckBox *checkBox_autoUpload;
    QToolButton *ble_edit;
    QToolButton *wifi_edit;
    QToolButton *autoUpload_edit;
    QToolButton *btautoUpload_once;
    QToolButton *btdownload;
    QCheckBox *checkBox_wifi;
    QLabel *label_33;
    QCheckBox *checkBox_hdmi;
    QCheckBox *checkBox_sis;
    QLabel *label_34;
    QLabel *label_35;
    QCheckBox *checkBox_mulhom;
    QToolButton *mulhom_edit;
    QCheckBox *checkBox_gw;
    QLabel *label_36;
    QCheckBox *checkBox_angel;
    QCheckBox *checkBox_volume;
    QLabel *label_37;
    QCheckBox *checkBox_panorama;
    QCheckBox *checkBox_zoomSave;
    QLabel *label_39;
    QCheckBox *checkBox_oritoggle;
    QLabel *label_40;
    QCheckBox *checkBox_homogeneity;
    QLabel *label_41;
    QLabel *label_42;
    QCheckBox *checkBox_stepZero;
    QLabel *label_43;
    QCheckBox *checkBox_4G;
    QLabel *label_44;
    QCheckBox *checkBox_compass;
    QToolButton *calbration_edit;
    QCheckBox *checkBox_GPS;
    QLabel *label_46;
    QLabel *label_47;
    QCheckBox *checkBox_avgTemp;
    QLabel *label_48;
    QCheckBox *checkBox_nonCool;
    QCheckBox *checkBox_eth;
    QLabel *label_50;
    QLabel *label_51;
    QCheckBox *checkBox_sketch;
    QToolButton *sketch_edit;
    QLabel *label_52;
    QCheckBox *checkBox_flip;
    QCheckBox *checkBox_transmission;
    QLabel *label_53;
    QToolButton *trmission_edit;
    QCheckBox *checkBox_bmp;
    QLabel *label_54;
    QCheckBox *checkBox_contrustFocus;
    QLabel *label_55;
    QCheckBox *checkBox_brightness;
    QLabel *label_56;
    QLabel *label_57;
    QCheckBox *checkBox_autoReg;
    QLabel *label_58;
    QCheckBox *checkBox_preset1;
    QCheckBox *checkBox_preset2;
    QLabel *label_59;
    myLabel *label_scroll;
    QListWidget *listWidget_focusmode;
    QFrame *frame_focusmode;
    QLabel *label_focusmode;
    QLabel *label_focusmode_2;
    QLabel *label_45;
    QFrame *frame_imageType;
    QLabel *label__imageType;
    QLabel *label__imageType_2;
    QListWidget *listWidget_imageType;
    QLabel *label_38;
    QWidget *tab_4;
    QPushButton *pushButton_default;
    QComboBox *comboBox_language;
    QDateTimeEdit *dateTimeEdit;
    QComboBox *auto_lcdoff;
    QLabel *label_23;
    QLabel *label_22;
    QComboBox *auto_poweroff;
    QFrame *frame_language;
    QLabel *label_language;
    QLabel *label_language2;
    QListWidget *listWidget_language;
    QFrame *frame_poweroff;
    QLabel *label_poweroff;
    QLabel *label_poweroff_2;
    QFrame *frame_lcdoff;
    QLabel *label_lcdoff;
    QLabel *label_lcdoff_2;
    QListWidget *listWidget_poweroff;
    QListWidget *listWidget_lcdoff;
    QLabel *label_25;
    QPushButton *pushButton_3;
    QLabel *label_49;
    QPushButton *pushButton_hotkey;
    QWidget *tab_5;
    QLabel *label_yiqibianhao;
    QLabel *label_shengchanriqi;
    QLabel *label_ruanjianbanben;
    QLabel *label_yiqixinghao;
    QLabel *label_xinghao_text;
    QLabel *label_bianhao_text;
    QLabel *label_banben_text;
    QLabel *label_riqi_text;
    hp_button *hp_logo;
    QLabel *label_gujianbanben;
    QLabel *label_gujianbanben_text;
    QFrame *frame_other;
    QLabel *label;

    void setupUi(QWidget *HpSetting)
    {
        if (HpSetting->objectName().isEmpty())
            HpSetting->setObjectName(QStringLiteral("HpSetting"));
        HpSetting->setWindowModality(Qt::NonModal);
        HpSetting->resize(972, 534);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HpSetting->sizePolicy().hasHeightForWidth());
        HpSetting->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        HpSetting->setFont(font);
        HpSetting->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(HpSetting);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 971, 480));
        frame->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 871, 480));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(0, 480));
        tabWidget->setSizeIncrement(QSize(0, 0));
        tabWidget->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setWeight(50);
        font1.setStyleStrategy(QFont::PreferAntialias);
        tabWidget->setFont(font1);
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setAcceptDrops(false);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QLatin1String("\n"
"QTabWidget::pane { \n"
"	\n"
"border: 0px;\n"
"background:transparent;\n"
"};\n"
"\n"
""));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(0, 0));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setTabBarAutoHide(false);
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tab_6->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setPointSize(20);
        tab_6->setFont(font2);
        tabWidget->addTab(tab_6, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setSizeIncrement(QSize(0, 0));
        QFont font3;
        font3.setPointSize(20);
        font3.setStyleStrategy(QFont::PreferAntialias);
        tab->setFont(font3);
        tab->setContextMenuPolicy(Qt::DefaultContextMenu);
        tab->setAutoFillBackground(false);
        tab->setStyleSheet(QStringLiteral(""));
        ScrollBar_Distance = new hp_QDoubleSpinBoxSet(tab);
        ScrollBar_Distance->setObjectName(QStringLiteral("ScrollBar_Distance"));
        ScrollBar_Distance->setGeometry(QRect(116, 68, 366, 44));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ScrollBar_Distance->sizePolicy().hasHeightForWidth());
        ScrollBar_Distance->setSizePolicy(sizePolicy2);
        ScrollBar_Distance->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(17);
        ScrollBar_Distance->setFont(font4);
        ScrollBar_Distance->setFocusPolicy(Qt::NoFocus);
        ScrollBar_Distance->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
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
        ScrollBar_Distance->setAlignment(Qt::AlignCenter);
        ScrollBar_Distance->setAccelerated(true);
        ScrollBar_Distance->setKeyboardTracking(false);
        ScrollBar_Distance->setDecimals(1);
        ScrollBar_Distance->setMinimum(1);
        ScrollBar_Distance->setSingleStep(0.1);
        checkBox_ReferTemp_enable = new QCheckBox(tab);
        checkBox_ReferTemp_enable->setObjectName(QStringLiteral("checkBox_ReferTemp_enable"));
        checkBox_ReferTemp_enable->setGeometry(QRect(41, 348, 70, 40));
        sizePolicy2.setHeightForWidth(checkBox_ReferTemp_enable->sizePolicy().hasHeightForWidth());
        checkBox_ReferTemp_enable->setSizePolicy(sizePolicy2);
        checkBox_ReferTemp_enable->setMinimumSize(QSize(40, 0));
        QFont font5;
        font5.setPointSize(10);
        font5.setStyleStrategy(QFont::PreferAntialias);
        checkBox_ReferTemp_enable->setFont(font5);
        checkBox_ReferTemp_enable->setFocusPolicy(Qt::NoFocus);
        checkBox_ReferTemp_enable->setLayoutDirection(Qt::RightToLeft);
        checkBox_ReferTemp_enable->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        checkBox_ReferTemp_enable->setIconSize(QSize(30, 30));
        checkBox_ReferTemp_enable->setTristate(false);
        ScrollBar_Humidity = new hp_QSpinBoxSet(tab);
        ScrollBar_Humidity->setObjectName(QStringLiteral("ScrollBar_Humidity"));
        ScrollBar_Humidity->setGeometry(QRect(116, 124, 366, 44));
        sizePolicy2.setHeightForWidth(ScrollBar_Humidity->sizePolicy().hasHeightForWidth());
        ScrollBar_Humidity->setSizePolicy(sizePolicy2);
        ScrollBar_Humidity->setMaximumSize(QSize(16777215, 16777215));
        ScrollBar_Humidity->setFont(font4);
        ScrollBar_Humidity->setFocusPolicy(Qt::NoFocus);
        ScrollBar_Humidity->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"\n"
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
"QSpinBox::down-arrow:dis"
                        "abled,QSpinBox::down-arrow:off \n"
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
        ScrollBar_Humidity->setAlignment(Qt::AlignCenter);
        ScrollBar_Humidity->setAccelerated(true);
        ScrollBar_Humidity->setMinimum(1);
        ScrollBar_Humidity->setMaximum(100);
        ScrollBar_transmission = new hp_QSpinBoxSet(tab);
        ScrollBar_transmission->setObjectName(QStringLiteral("ScrollBar_transmission"));
        ScrollBar_transmission->setGeometry(QRect(116, 292, 366, 44));
        sizePolicy2.setHeightForWidth(ScrollBar_transmission->sizePolicy().hasHeightForWidth());
        ScrollBar_transmission->setSizePolicy(sizePolicy2);
        ScrollBar_transmission->setMaximumSize(QSize(16777215, 16777215));
        ScrollBar_transmission->setFont(font4);
        ScrollBar_transmission->setFocusPolicy(Qt::NoFocus);
        ScrollBar_transmission->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"\n"
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
"QSpinBox::down-arrow:dis"
                        "abled,QSpinBox::down-arrow:off \n"
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
        ScrollBar_transmission->setAlignment(Qt::AlignCenter);
        ScrollBar_transmission->setAccelerated(true);
        ScrollBar_transmission->setMinimum(1);
        ScrollBar_transmission->setMaximum(100);
        ScrollBar_ReflectTemp = new hp_QDoubleSpinBoxSet(tab);
        ScrollBar_ReflectTemp->setObjectName(QStringLiteral("ScrollBar_ReflectTemp"));
        ScrollBar_ReflectTemp->setGeometry(QRect(116, 236, 366, 44));
        sizePolicy2.setHeightForWidth(ScrollBar_ReflectTemp->sizePolicy().hasHeightForWidth());
        ScrollBar_ReflectTemp->setSizePolicy(sizePolicy2);
        ScrollBar_ReflectTemp->setMaximumSize(QSize(16777215, 16777215));
        ScrollBar_ReflectTemp->setFont(font4);
        ScrollBar_ReflectTemp->setFocusPolicy(Qt::NoFocus);
        ScrollBar_ReflectTemp->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
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
        ScrollBar_ReflectTemp->setAlignment(Qt::AlignCenter);
        ScrollBar_ReflectTemp->setAccelerated(true);
        ScrollBar_ReflectTemp->setDecimals(1);
        ScrollBar_ReflectTemp->setMinimum(-100);
        ScrollBar_ReflectTemp->setMaximum(200);
        ScrollBar_ReflectTemp->setSingleStep(0.1);
        ScrollBar_Radiance = new hp_QSpinBoxSet(tab);
        ScrollBar_Radiance->setObjectName(QStringLiteral("ScrollBar_Radiance"));
        ScrollBar_Radiance->setGeometry(QRect(116, 12, 366, 44));
        sizePolicy2.setHeightForWidth(ScrollBar_Radiance->sizePolicy().hasHeightForWidth());
        ScrollBar_Radiance->setSizePolicy(sizePolicy2);
        ScrollBar_Radiance->setMaximumSize(QSize(16777215, 16777215));
        ScrollBar_Radiance->setFont(font4);
        ScrollBar_Radiance->setFocusPolicy(Qt::NoFocus);
        ScrollBar_Radiance->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"\n"
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
"QSpinBox::down-arrow:dis"
                        "abled,QSpinBox::down-arrow:off \n"
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
        ScrollBar_Radiance->setFrame(false);
        ScrollBar_Radiance->setAlignment(Qt::AlignCenter);
        ScrollBar_Radiance->setReadOnly(false);
        ScrollBar_Radiance->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        ScrollBar_Radiance->setAccelerated(true);
        ScrollBar_Radiance->setKeyboardTracking(false);
        ScrollBar_Radiance->setProperty("showGroupSeparator", QVariant(false));
        ScrollBar_Radiance->setMinimum(1);
        ScrollBar_Radiance->setMaximum(100);
        ScrollBar_ReferTemp = new hp_QDoubleSpinBoxSet(tab);
        ScrollBar_ReferTemp->setObjectName(QStringLiteral("ScrollBar_ReferTemp"));
        ScrollBar_ReferTemp->setGeometry(QRect(116, 348, 366, 44));
        sizePolicy2.setHeightForWidth(ScrollBar_ReferTemp->sizePolicy().hasHeightForWidth());
        ScrollBar_ReferTemp->setSizePolicy(sizePolicy2);
        ScrollBar_ReferTemp->setMaximumSize(QSize(16777215, 16777215));
        ScrollBar_ReferTemp->setFont(font4);
        ScrollBar_ReferTemp->setFocusPolicy(Qt::NoFocus);
        ScrollBar_ReferTemp->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
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
        ScrollBar_ReferTemp->setAlignment(Qt::AlignCenter);
        ScrollBar_ReferTemp->setAccelerated(true);
        ScrollBar_ReferTemp->setDecimals(1);
        ScrollBar_ReferTemp->setSingleStep(0.1);
        ScrollBar_TempUnit = new Hp_QSpinBox(tab);
        ScrollBar_TempUnit->setObjectName(QStringLiteral("ScrollBar_TempUnit"));
        ScrollBar_TempUnit->setGeometry(QRect(116, 404, 366, 40));
        sizePolicy2.setHeightForWidth(ScrollBar_TempUnit->sizePolicy().hasHeightForWidth());
        ScrollBar_TempUnit->setSizePolicy(sizePolicy2);
        ScrollBar_TempUnit->setMaximumSize(QSize(16777215, 16777215));
        ScrollBar_TempUnit->setFont(font4);
        ScrollBar_TempUnit->setFocusPolicy(Qt::NoFocus);
        ScrollBar_TempUnit->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px; \n"
"}\n"
"QSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 40;\n"
"    height:40;     \n"
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
"    height: 40;\n"
"}\n"
"  \n"
"QSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"	width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QSpinBox::down-arrow:disabled,QSpinBox::d"
                        "own-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"	width: 40;\n"
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
        ScrollBar_TempUnit->setWrapping(true);
        ScrollBar_TempUnit->setFrame(false);
        ScrollBar_TempUnit->setAlignment(Qt::AlignCenter);
        ScrollBar_TempUnit->setMaximum(2);
        ScrollBar_AmbientTempManu = new hp_QDoubleSpinBoxSet(tab);
        ScrollBar_AmbientTempManu->setObjectName(QStringLiteral("ScrollBar_AmbientTempManu"));
        ScrollBar_AmbientTempManu->setGeometry(QRect(116, 180, 366, 44));
        sizePolicy2.setHeightForWidth(ScrollBar_AmbientTempManu->sizePolicy().hasHeightForWidth());
        ScrollBar_AmbientTempManu->setSizePolicy(sizePolicy2);
        ScrollBar_AmbientTempManu->setMaximumSize(QSize(16777215, 16777215));
        ScrollBar_AmbientTempManu->setFont(font4);
        ScrollBar_AmbientTempManu->setFocusPolicy(Qt::NoFocus);
        ScrollBar_AmbientTempManu->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
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
        ScrollBar_AmbientTempManu->setAlignment(Qt::AlignCenter);
        ScrollBar_AmbientTempManu->setAccelerated(true);
        ScrollBar_AmbientTempManu->setDecimals(1);
        ScrollBar_AmbientTempManu->setMinimum(-20);
        ScrollBar_AmbientTempManu->setMaximum(50);
        ScrollBar_AmbientTempManu->setSingleStep(0.1);
        frame_Radiance = new QFrame(tab);
        frame_Radiance->setObjectName(QStringLiteral("frame_Radiance"));
        frame_Radiance->setGeometry(QRect(490, 30, 366, 44));
        frame_Radiance->setStyleSheet(QLatin1String("background-color:transparent;\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_Radiance->setFrameShape(QFrame::StyledPanel);
        frame_Radiance->setFrameShadow(QFrame::Raised);
        label_Radiance = new QLabel(frame_Radiance);
        label_Radiance->setObjectName(QStringLiteral("label_Radiance"));
        label_Radiance->setGeometry(QRect(0, 0, 322, 44));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(17);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setWeight(50);
        label_Radiance->setFont(font6);
        label_Radiance->setLayoutDirection(Qt::LeftToRight);
        label_Radiance->setStyleSheet(QLatin1String("/*background-color:transparent;*/\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;"));
        label_Radiance->setAlignment(Qt::AlignCenter);
        label_Radiance_2 = new QLabel(frame_Radiance);
        label_Radiance_2->setObjectName(QStringLiteral("label_Radiance_2"));
        label_Radiance_2->setGeometry(QRect(322, 1, 44, 44));
        label_Radiance_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        checkBox_Radiance = new QCheckBox(tab);
        checkBox_Radiance->setObjectName(QStringLiteral("checkBox_Radiance"));
        checkBox_Radiance->setGeometry(QRect(41, 12, 70, 40));
        sizePolicy2.setHeightForWidth(checkBox_Radiance->sizePolicy().hasHeightForWidth());
        checkBox_Radiance->setSizePolicy(sizePolicy2);
        checkBox_Radiance->setMinimumSize(QSize(40, 0));
        checkBox_Radiance->setFont(font5);
        checkBox_Radiance->setFocusPolicy(Qt::NoFocus);
        checkBox_Radiance->setLayoutDirection(Qt::RightToLeft);
        checkBox_Radiance->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        checkBox_Radiance->setIconSize(QSize(30, 30));
        checkBox_Radiance->setTristate(false);
        listWidget_Radiance = new QListWidget(tab);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        new QListWidgetItem(listWidget_Radiance);
        listWidget_Radiance->setObjectName(QStringLiteral("listWidget_Radiance"));
        listWidget_Radiance->setGeometry(QRect(490, 80, 281, 191));
        listWidget_Radiance->setFont(font4);
        listWidget_Radiance->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"	\n"
"	background-image: url(:/res/res/setting_background.png);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:#32CC99;\n"
"	width:40px;\n"
"	margin:40 0 40 0px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\350\256\276\347\275\256 */\n"
"QScrollBar::handle:vertical {\n"
"/*	background-color:#7CA6C9;*/	\n"
"	background-color: rgb(83, 166, 249);\n"
"	border:1px solid #7CA6C9;\n"
"	height:30px;\n"
"	max-height:20px;\n"
"}\n"
"\n"
"/* \345\272\225\351\203\250\346\216\247\345\210\266\345\235\227 */\n"
"QScrollBar::add-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:transparent;\n"
"	width:40px;\n"
"	height:40px;\n"
"	subcontrol-position:bottom;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_down_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \351\241\266\351\203\250\346\216\247\345\210\266\345\235\227 */\n"
"QScrollBar::sub-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
""
                        "	background-color:transparent;\n"
"	width:40px;\n"
"	height:40px;\n"
"	subcontrol-position:top;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_up_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \346\216\247\345\210\266\345\235\227\344\270\212\347\232\204\345\260\217\347\256\255\345\244\264 */\n"
"QScrollBar::up-arrow:vertical,QScrollBar::down-arrow:vertical {\n"
"	border:0px;\n"
"	width:40px;\n"
"	height:40px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\212\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::add-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\213\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::sub-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
""));
        frame_ReflectTemp = new QFrame(tab);
        frame_ReflectTemp->setObjectName(QStringLiteral("frame_ReflectTemp"));
        frame_ReflectTemp->setGeometry(QRect(490, 280, 366, 44));
        frame_ReflectTemp->setStyleSheet(QLatin1String("background-color:transparent;\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_ReflectTemp->setFrameShape(QFrame::StyledPanel);
        frame_ReflectTemp->setFrameShadow(QFrame::Raised);
        label_ReflectTemp = new QLabel(frame_ReflectTemp);
        label_ReflectTemp->setObjectName(QStringLiteral("label_ReflectTemp"));
        label_ReflectTemp->setGeometry(QRect(0, 0, 322, 44));
        label_ReflectTemp->setFont(font6);
        label_ReflectTemp->setLayoutDirection(Qt::LeftToRight);
        label_ReflectTemp->setStyleSheet(QLatin1String("/*background-color:transparent;*/\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;"));
        label_ReflectTemp->setAlignment(Qt::AlignCenter);
        label_ReflectTemp_2 = new QLabel(frame_ReflectTemp);
        label_ReflectTemp_2->setObjectName(QStringLiteral("label_ReflectTemp_2"));
        label_ReflectTemp_2->setGeometry(QRect(322, 1, 44, 44));
        label_ReflectTemp_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        listWidget_ReflectTemp = new QListWidget(tab);
        new QListWidgetItem(listWidget_ReflectTemp);
        new QListWidgetItem(listWidget_ReflectTemp);
        new QListWidgetItem(listWidget_ReflectTemp);
        listWidget_ReflectTemp->setObjectName(QStringLiteral("listWidget_ReflectTemp"));
        listWidget_ReflectTemp->setGeometry(QRect(490, 320, 281, 101));
        listWidget_ReflectTemp->setFont(font4);
        listWidget_ReflectTemp->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"	\n"
"	background-image: url(:/res/res/setting_background.png);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:#32CC99;\n"
"	width:40px;\n"
"	margin:40 0 40 0px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\350\256\276\347\275\256 */\n"
"QScrollBar::handle:vertical {\n"
"/*	background-color:#7CA6C9;*/	\n"
"	background-color: rgb(83, 166, 249);\n"
"	border:1px solid #7CA6C9;\n"
"	height:30px;\n"
"	max-height:20px;\n"
"}\n"
"\n"
"/* \345\272\225\351\203\250\346\216\247\345\210\266\345\235\227 */\n"
"QScrollBar::add-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:transparent;\n"
"	width:40px;\n"
"	height:40px;\n"
"	subcontrol-position:bottom;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_down_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \351\241\266\351\203\250\346\216\247\345\210\266\345\235\227 */\n"
"QScrollBar::sub-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
""
                        "	background-color:transparent;\n"
"	width:40px;\n"
"	height:40px;\n"
"	subcontrol-position:top;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_up_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \346\216\247\345\210\266\345\235\227\344\270\212\347\232\204\345\260\217\347\256\255\345\244\264 */\n"
"QScrollBar::up-arrow:vertical,QScrollBar::down-arrow:vertical {\n"
"	border:0px;\n"
"	width:40px;\n"
"	height:40px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\212\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::add-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\213\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::sub-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
""));
        checkBox_ReflectTemp_enable = new QCheckBox(tab);
        checkBox_ReflectTemp_enable->setObjectName(QStringLiteral("checkBox_ReflectTemp_enable"));
        checkBox_ReflectTemp_enable->setGeometry(QRect(41, 236, 70, 40));
        sizePolicy2.setHeightForWidth(checkBox_ReflectTemp_enable->sizePolicy().hasHeightForWidth());
        checkBox_ReflectTemp_enable->setSizePolicy(sizePolicy2);
        checkBox_ReflectTemp_enable->setMinimumSize(QSize(40, 0));
        checkBox_ReflectTemp_enable->setFont(font5);
        checkBox_ReflectTemp_enable->setFocusPolicy(Qt::NoFocus);
        checkBox_ReflectTemp_enable->setLayoutDirection(Qt::RightToLeft);
        checkBox_ReflectTemp_enable->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        checkBox_ReflectTemp_enable->setIconSize(QSize(30, 30));
        checkBox_ReflectTemp_enable->setTristate(false);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setBaseSize(QSize(0, 0));
        tab_2->setFont(font2);
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(33, 224, 185, 44));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(17);
        font7.setStyleStrategy(QFont::PreferAntialias);
        label_13->setFont(font7);
        label_13->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_jingtou = new QComboBox(tab_2);
        comboBox_jingtou->setObjectName(QStringLiteral("comboBox_jingtou"));
        comboBox_jingtou->setGeometry(QRect(40, 0, 191, 44));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox_jingtou->sizePolicy().hasHeightForWidth());
        comboBox_jingtou->setSizePolicy(sizePolicy3);
        comboBox_jingtou->setFont(font7);
        comboBox_jingtou->setFocusPolicy(Qt::ClickFocus);
        comboBox_jingtou->setStyleSheet(QLatin1String("\n"
"QComboBox {\n"
"	color:#7CA6C9;\n"
"    border: 0px solid #7CA6C9;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #0a1a29;\n"
"    border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"}\n"
"QComboBox:editable {\n"
"	background:transparent;\n"
"	color:#7CA6C9;\n"
"}\n"
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
"    border-left-width: 0px;\n"
"    border-left-c"
                        "olor: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 0px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/res/res/down_arrow_n.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 0px;\n"
"    left: 0px;\n"
"}"));
        comboBox_jingtou->setEditable(false);
        comboBox_jingtou->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        comboBox_jingtou->setIconSize(QSize(24, 24));
        comboBox_jingtou->setDuplicatesEnabled(false);
        comboBox_jingtou->setFrame(true);
        comboBox_jingtou->setModelColumn(0);
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(33, 66, 185, 44));
        label_10->setFont(font7);
        label_10->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 363, 20, 31));
        label_11->setFont(font7);
        label_11->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_baojingshezhi = new QComboBox(tab_2);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/res/combobox_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_baojingshezhi->addItem(icon, QString());
        comboBox_baojingshezhi->addItem(icon, QString());
        comboBox_baojingshezhi->addItem(icon, QString());
        comboBox_baojingshezhi->setObjectName(QStringLiteral("comboBox_baojingshezhi"));
        comboBox_baojingshezhi->setGeometry(QRect(470, 210, 243, 44));
        comboBox_baojingshezhi->setFont(font7);
        comboBox_baojingshezhi->setFocusPolicy(Qt::ClickFocus);
        comboBox_baojingshezhi->setStyleSheet(QLatin1String("\n"
"QComboBox {\n"
"	color:#7CA6C9;\n"
"    border: 0px solid #7CA6C9;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #0a1a29;\n"
"    border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"}\n"
"QComboBox:editable {\n"
"	background:transparent;\n"
"	color:#7CA6C9;\n"
"}\n"
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
"    border-left-width: 0px;\n"
"    border-left-c"
                        "olor: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 0px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/res/res/down_arrow_n.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 0px;\n"
"    left: 0px;\n"
"}"));
        comboBox_baojingshezhi->setMaxVisibleItems(3);
        comboBox_baojingshezhi->setIconSize(QSize(24, 24));
        comboBox_baojingshezhi->setFrame(true);
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(33, 278, 185, 44));
        label_15->setFont(font7);
        label_15->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_baojingse = new QComboBox(tab_2);
        comboBox_baojingse->addItem(icon, QString());
        comboBox_baojingse->addItem(icon, QString());
        comboBox_baojingse->addItem(icon, QString());
        comboBox_baojingse->addItem(icon, QString());
        comboBox_baojingse->addItem(icon, QString());
        comboBox_baojingse->addItem(icon, QString());
        comboBox_baojingse->addItem(icon, QString());
        comboBox_baojingse->addItem(icon, QString());
        comboBox_baojingse->addItem(icon, QString());
        comboBox_baojingse->addItem(icon, QString());
        comboBox_baojingse->setObjectName(QStringLiteral("comboBox_baojingse"));
        comboBox_baojingse->setGeometry(QRect(480, 260, 243, 44));
        comboBox_baojingse->setFont(font7);
        comboBox_baojingse->setFocusPolicy(Qt::ClickFocus);
        comboBox_baojingse->setStyleSheet(QLatin1String("\n"
"QComboBox {\n"
"	color:#7CA6C9;\n"
"    border: 0px solid #7CA6C9;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #0a1a29;\n"
"    border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"}\n"
"QComboBox:editable {\n"
"	background:transparent;\n"
"	color:#7CA6C9;\n"
"}\n"
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
"    border-left-width: 0px;\n"
"    border-left-c"
                        "olor: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 0px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/res/res/down_arrow_n.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 0px;\n"
"    left: 0px;\n"
"}"));
        comboBox_baojingse->setInsertPolicy(QComboBox::NoInsert);
        comboBox_baojingse->setIconSize(QSize(24, 16));
        comboBox_baojingse->setDuplicatesEnabled(false);
        comboBox_baojingse->setFrame(true);
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(33, 12, 185, 44));
        label_9->setMinimumSize(QSize(96, 0));
        label_9->setFont(font7);
        label_9->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_dangwei = new QComboBox(tab_2);
        comboBox_dangwei->setObjectName(QStringLiteral("comboBox_dangwei"));
        comboBox_dangwei->setGeometry(QRect(240, 0, 243, 44));
        comboBox_dangwei->setFont(font7);
        comboBox_dangwei->setFocusPolicy(Qt::ClickFocus);
        comboBox_dangwei->setStyleSheet(QLatin1String("\n"
"QComboBox {\n"
"	color:#7CA6C9;\n"
"    border: 0px solid #7CA6C9;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #0a1a29;\n"
"    border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"}\n"
"QComboBox:editable {\n"
"	background:transparent;\n"
"	color:#7CA6C9;\n"
"}\n"
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
"    border-left-width: 0px;\n"
"    border-left-c"
                        "olor: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 0px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/res/res/down_arrow_n.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 0px;\n"
"    left: 0px;\n"
"}"));
        comboBox_dangwei->setIconSize(QSize(24, 24));
        cwfw_autorectify = new hp_QSpinBoxSet(tab_2);
        cwfw_autorectify->setObjectName(QStringLiteral("cwfw_autorectify"));
        cwfw_autorectify->setGeometry(QRect(125, 120, 350, 44));
        cwfw_autorectify->setFont(font4);
        cwfw_autorectify->setFocusPolicy(Qt::NoFocus);
        cwfw_autorectify->setStyleSheet(QString::fromUtf8("QSpinBox\n"
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
        cwfw_autorectify->setAlignment(Qt::AlignCenter);
        cwfw_autorectify->setAccelerated(true);
        cwfw_autorectify->setProperty("showGroupSeparator", QVariant(false));
        cwfw_autorectify->setMinimum(8);
        cwfw_autorectify->setMaximum(1800);
        frame_jingtou = new QFrame(tab_2);
        frame_jingtou->setObjectName(QStringLiteral("frame_jingtou"));
        frame_jingtou->setGeometry(QRect(233, 12, 243, 44));
        frame_jingtou->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_jingtou->setFrameShape(QFrame::StyledPanel);
        frame_jingtou->setFrameShadow(QFrame::Raised);
        label_jingtou = new QLabel(frame_jingtou);
        label_jingtou->setObjectName(QStringLiteral("label_jingtou"));
        label_jingtou->setGeometry(QRect(0, 0, 201, 44));
        label_jingtou->setFont(font4);
        label_jingtou->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_jingtou->setAlignment(Qt::AlignCenter);
        label_jingtou_2 = new QLabel(frame_jingtou);
        label_jingtou_2->setObjectName(QStringLiteral("label_jingtou_2"));
        label_jingtou_2->setGeometry(QRect(201, 2, 40, 40));
        label_jingtou_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        listWidget_jingtou = new QListWidget(tab_2);
        listWidget_jingtou->setObjectName(QStringLiteral("listWidget_jingtou"));
        listWidget_jingtou->setGeometry(QRect(530, 0, 181, 41));
        listWidget_jingtou->setFont(font4);
        listWidget_jingtou->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_wendang = new QFrame(tab_2);
        frame_wendang->setObjectName(QStringLiteral("frame_wendang"));
        frame_wendang->setGeometry(QRect(233, 66, 243, 44));
        frame_wendang->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_wendang->setFrameShape(QFrame::StyledPanel);
        frame_wendang->setFrameShadow(QFrame::Raised);
        label_wendang = new QLabel(frame_wendang);
        label_wendang->setObjectName(QStringLiteral("label_wendang"));
        label_wendang->setGeometry(QRect(0, 0, 201, 44));
        label_wendang->setFont(font4);
        label_wendang->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_wendang->setAlignment(Qt::AlignCenter);
        label_wendang_2 = new QLabel(frame_wendang);
        label_wendang_2->setObjectName(QStringLiteral("label_wendang_2"));
        label_wendang_2->setGeometry(QRect(201, 2, 40, 40));
        label_wendang_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        listWidget_wendang = new QListWidget(tab_2);
        listWidget_wendang->setObjectName(QStringLiteral("listWidget_wendang"));
        listWidget_wendang->setGeometry(QRect(530, 160, 181, 41));
        listWidget_wendang->setFont(font4);
        listWidget_wendang->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        listWidget_baojingshezhi = new QListWidget(tab_2);
        new QListWidgetItem(listWidget_baojingshezhi);
        new QListWidgetItem(listWidget_baojingshezhi);
        new QListWidgetItem(listWidget_baojingshezhi);
        listWidget_baojingshezhi->setObjectName(QStringLiteral("listWidget_baojingshezhi"));
        listWidget_baojingshezhi->setGeometry(QRect(520, 312, 181, 131));
        listWidget_baojingshezhi->setFont(font4);
        listWidget_baojingshezhi->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        listWidget_baojingse = new QListWidget(tab_2);
        new QListWidgetItem(listWidget_baojingse);
        new QListWidgetItem(listWidget_baojingse);
        new QListWidgetItem(listWidget_baojingse);
        new QListWidgetItem(listWidget_baojingse);
        new QListWidgetItem(listWidget_baojingse);
        new QListWidgetItem(listWidget_baojingse);
        new QListWidgetItem(listWidget_baojingse);
        new QListWidgetItem(listWidget_baojingse);
        new QListWidgetItem(listWidget_baojingse);
        new QListWidgetItem(listWidget_baojingse);
        listWidget_baojingse->setObjectName(QStringLiteral("listWidget_baojingse"));
        listWidget_baojingse->setGeometry(QRect(510, 369, 181, 81));
        listWidget_baojingse->setFont(font4);
        listWidget_baojingse->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_bangjingshehzi = new QFrame(tab_2);
        frame_bangjingshehzi->setObjectName(QStringLiteral("frame_bangjingshehzi"));
        frame_bangjingshehzi->setGeometry(QRect(233, 224, 243, 44));
        frame_bangjingshehzi->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_bangjingshehzi->setFrameShape(QFrame::StyledPanel);
        frame_bangjingshehzi->setFrameShadow(QFrame::Raised);
        label_bangjingshehzi = new QLabel(frame_bangjingshehzi);
        label_bangjingshehzi->setObjectName(QStringLiteral("label_bangjingshehzi"));
        label_bangjingshehzi->setGeometry(QRect(0, 0, 201, 44));
        label_bangjingshehzi->setFont(font4);
        label_bangjingshehzi->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_bangjingshehzi->setAlignment(Qt::AlignCenter);
        label_bangjingshehzi_2 = new QLabel(frame_bangjingshehzi);
        label_bangjingshehzi_2->setObjectName(QStringLiteral("label_bangjingshehzi_2"));
        label_bangjingshehzi_2->setGeometry(QRect(201, 2, 40, 40));
        label_bangjingshehzi_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        frame_baojingse = new QFrame(tab_2);
        frame_baojingse->setObjectName(QStringLiteral("frame_baojingse"));
        frame_baojingse->setGeometry(QRect(233, 278, 243, 44));
        frame_baojingse->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_baojingse->setFrameShape(QFrame::StyledPanel);
        frame_baojingse->setFrameShadow(QFrame::Raised);
        label_baojingse = new QLabel(frame_baojingse);
        label_baojingse->setObjectName(QStringLiteral("label_baojingse"));
        label_baojingse->setGeometry(QRect(0, 0, 201, 44));
        label_baojingse->setFont(font4);
        label_baojingse->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_baojingse->setAlignment(Qt::AlignCenter);
        label_baojingse_2 = new QLabel(frame_baojingse);
        label_baojingse_2->setObjectName(QStringLiteral("label_baojingse_2"));
        label_baojingse_2->setGeometry(QRect(201, 2, 40, 40));
        label_baojingse_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        pushButton_qiehuan = new QPushButton(tab_2);
        pushButton_qiehuan->setObjectName(QStringLiteral("pushButton_qiehuan"));
        pushButton_qiehuan->setGeometry(QRect(490, 74, 90, 45));
        pushButton_qiehuan->setMinimumSize(QSize(0, 0));
        pushButton_qiehuan->setMaximumSize(QSize(16777215, 16777215));
        pushButton_qiehuan->setFont(font7);
        pushButton_qiehuan->setFocusPolicy(Qt::NoFocus);
        pushButton_qiehuan->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"border-image:url(:/res/res/button_n.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
"QPushButton:pressed{\n"
"border-image:url(:/res/res/setting_selected.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
""));
        pushButton_qiehuan->setAutoDefault(false);
        pushButton_qiehuan->setFlat(true);
        comboBox_baojingwendu = new hp_QDoubleSpinBoxSet(tab_2);
        comboBox_baojingwendu->setObjectName(QStringLiteral("comboBox_baojingwendu"));
        comboBox_baojingwendu->setGeometry(QRect(125, 174, 350, 44));
        comboBox_baojingwendu->setFont(font4);
        comboBox_baojingwendu->setFocusPolicy(Qt::NoFocus);
        comboBox_baojingwendu->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
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
                        "QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
""));
        comboBox_baojingwendu->setAlignment(Qt::AlignCenter);
        comboBox_baojingwendu->setAccelerated(true);
        comboBox_baojingwendu->setDecimals(1);
        comboBox_baojingwendu->setMinimum(-1000);
        comboBox_baojingwendu->setMaximum(10000);
        comboBox_baojingwendu->setSingleStep(0.1);
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(130, 382, 271, 44));
        label_20->setFont(font7);
        label_20->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        checkBox_Catch = new QCheckBox(tab_2);
        checkBox_Catch->setObjectName(QStringLiteral("checkBox_Catch"));
        checkBox_Catch->setEnabled(true);
        checkBox_Catch->setGeometry(QRect(406, 380, 70, 44));
        QFont font8;
        font8.setPointSize(17);
        checkBox_Catch->setFont(font8);
        checkBox_Catch->setFocusPolicy(Qt::NoFocus);
        checkBox_Catch->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        comboBox_buchangwendu = new hp_QDoubleSpinBoxSet(tab_2);
        comboBox_buchangwendu->setObjectName(QStringLiteral("comboBox_buchangwendu"));
        comboBox_buchangwendu->setGeometry(QRect(125, 430, 350, 44));
        comboBox_buchangwendu->setFont(font4);
        comboBox_buchangwendu->setFocusPolicy(Qt::NoFocus);
        comboBox_buchangwendu->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
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
                        "QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
""));
        comboBox_buchangwendu->setAlignment(Qt::AlignCenter);
        comboBox_buchangwendu->setAccelerated(true);
        comboBox_buchangwendu->setDecimals(1);
        comboBox_buchangwendu->setMinimum(-1000);
        comboBox_buchangwendu->setMaximum(10000);
        comboBox_buchangwendu->setSingleStep(0.1);
        label_30 = new QLabel(tab_2);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(560, 60, 251, 44));
        label_30->setMinimumSize(QSize(0, 0));
        label_30->setMaximumSize(QSize(16777215, 9999999));
        label_30->setSizeIncrement(QSize(0, 0));
        label_30->setFont(font7);
        label_30->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_30->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        dengwengse_edit = new QToolButton(tab_2);
        dengwengse_edit->setObjectName(QStringLiteral("dengwengse_edit"));
        dengwengse_edit->setGeometry(QRect(770, 90, 121, 62));
        dengwengse_edit->setFont(font8);
        dengwengse_edit->setFocusPolicy(Qt::NoFocus);
        dengwengse_edit->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        dengwengse_edit->setAutoRaise(true);
        comboBox_baojingjuli = new hp_QDoubleSpinBoxSet(tab_2);
        comboBox_baojingjuli->setObjectName(QStringLiteral("comboBox_baojingjuli"));
        comboBox_baojingjuli->setGeometry(QRect(125, 332, 350, 44));
        comboBox_baojingjuli->setFont(font4);
        comboBox_baojingjuli->setFocusPolicy(Qt::NoFocus);
        comboBox_baojingjuli->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
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
                        "QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
""));
        comboBox_baojingjuli->setAlignment(Qt::AlignCenter);
        comboBox_baojingjuli->setAccelerated(true);
        comboBox_baojingjuli->setDecimals(1);
        comboBox_baojingjuli->setMinimum(0);
        comboBox_baojingjuli->setMaximum(100);
        comboBox_baojingjuli->setSingleStep(0.1);
        tabWidget->addTab(tab_2, QString());
        comboBox_baojingjuli->raise();
        comboBox_buchangwendu->raise();
        checkBox_Catch->raise();
        label_20->raise();
        label_13->raise();
        comboBox_jingtou->raise();
        label_10->raise();
        label_11->raise();
        label_15->raise();
        label_9->raise();
        comboBox_dangwei->raise();
        comboBox_baojingse->raise();
        comboBox_baojingshezhi->raise();
        cwfw_autorectify->raise();
        frame_jingtou->raise();
        frame_wendang->raise();
        frame_bangjingshehzi->raise();
        frame_baojingse->raise();
        pushButton_qiehuan->raise();
        comboBox_baojingwendu->raise();
        listWidget_baojingse->raise();
        listWidget_wendang->raise();
        listWidget_jingtou->raise();
        label_30->raise();
        dengwengse_edit->raise();
        listWidget_baojingshezhi->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tab_3->setSizeIncrement(QSize(0, 0));
        tab_3->setBaseSize(QSize(0, 0));
        tab_3->setFont(font2);
        spinBox_autosave = new hp_QSpinBoxSet(tab_3);
        spinBox_autosave->setObjectName(QStringLiteral("spinBox_autosave"));
        spinBox_autosave->setGeometry(QRect(240, 430, 243, 44));
        spinBox_autosave->setFont(font8);
        spinBox_autosave->setFocusPolicy(Qt::NoFocus);
        spinBox_autosave->setStyleSheet(QString::fromUtf8("QSpinBox\n"
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
        spinBox_autosave->setAlignment(Qt::AlignCenter);
        spinBox_autosave->setAccelerated(true);
        spinBox_autosave->setMinimum(7);
        spinBox_autosave->setMaximum(200000);
        spinBox_autosave->setValue(7);
        label_24 = new QLabel(tab_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(45, 430, 168, 45));
        label_24->setMinimumSize(QSize(0, 0));
        label_24->setMaximumSize(QSize(16777215, 16777215));
        label_24->setFont(font7);
        label_24->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_usbmode = new QComboBox(tab_3);
        comboBox_usbmode->addItem(icon, QString());
        comboBox_usbmode->addItem(icon, QString());
        comboBox_usbmode->setObjectName(QStringLiteral("comboBox_usbmode"));
        comboBox_usbmode->setEnabled(true);
        comboBox_usbmode->setGeometry(QRect(600, 300, 243, 44));
        QPalette palette;
        QBrush brush(QColor(124, 166, 201, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(186, 185, 185, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush3(QColor(255, 255, 255, 0));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        comboBox_usbmode->setPalette(palette);
        comboBox_usbmode->setFont(font7);
        comboBox_usbmode->setFocusPolicy(Qt::WheelFocus);
        comboBox_usbmode->setLayoutDirection(Qt::RightToLeft);
        comboBox_usbmode->setStyleSheet(QLatin1String("\n"
"QComboBox {\n"
"	color:#7CA6C9;\n"
"    border: 0px solid #7CA6C9;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #0a1a29;\n"
"    border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"}\n"
"QComboBox:editable {\n"
"	background:transparent;\n"
"	color:#7CA6C9;\n"
"}\n"
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
"    border-left-width: 0px;\n"
"    border-left-c"
                        "olor: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 0px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/res/res/down_arrow_n.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 0px;\n"
"    left: 0px;\n"
"}"));
        comboBox_usbmode->setMaxVisibleItems(2);
        comboBox_usbmode->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        comboBox_usbmode->setIconSize(QSize(24, 24));
        comboBox_usbmode->setFrame(true);
        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(45, 380, 168, 45));
        label_19->setMinimumSize(QSize(0, 0));
        label_19->setMaximumSize(QSize(16777215, 16777215));
        label_19->setFont(font7);
        label_19->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frame_usbmode = new QFrame(tab_3);
        frame_usbmode->setObjectName(QStringLiteral("frame_usbmode"));
        frame_usbmode->setGeometry(QRect(240, 380, 243, 44));
        frame_usbmode->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_usbmode->setFrameShape(QFrame::StyledPanel);
        frame_usbmode->setFrameShadow(QFrame::Raised);
        label_usbmode = new QLabel(frame_usbmode);
        label_usbmode->setObjectName(QStringLiteral("label_usbmode"));
        label_usbmode->setGeometry(QRect(0, 0, 201, 44));
        label_usbmode->setFont(font4);
        label_usbmode->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_usbmode->setAlignment(Qt::AlignCenter);
        label_usbmode_2 = new QLabel(frame_usbmode);
        label_usbmode_2->setObjectName(QStringLiteral("label_usbmode_2"));
        label_usbmode_2->setGeometry(QRect(201, 2, 40, 40));
        label_usbmode_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        listWidget_usbmode = new QListWidget(tab_3);
        new QListWidgetItem(listWidget_usbmode);
        new QListWidgetItem(listWidget_usbmode);
        listWidget_usbmode->setObjectName(QStringLiteral("listWidget_usbmode"));
        listWidget_usbmode->setGeometry(QRect(510, 340, 181, 70));
        listWidget_usbmode->setFont(font4);
        listWidget_usbmode->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_29 = new QLabel(tab_3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(45, 330, 168, 45));
        label_29->setMinimumSize(QSize(0, 0));
        label_29->setMaximumSize(QSize(16777215, 16777215));
        label_29->setFont(font7);
        label_29->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frame_recordmode = new QFrame(tab_3);
        frame_recordmode->setObjectName(QStringLiteral("frame_recordmode"));
        frame_recordmode->setGeometry(QRect(240, 330, 243, 44));
        frame_recordmode->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_recordmode->setFrameShape(QFrame::StyledPanel);
        frame_recordmode->setFrameShadow(QFrame::Raised);
        label_recordmode = new QLabel(frame_recordmode);
        label_recordmode->setObjectName(QStringLiteral("label_recordmode"));
        label_recordmode->setGeometry(QRect(0, 0, 201, 44));
        label_recordmode->setFont(font4);
        label_recordmode->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_recordmode->setAlignment(Qt::AlignCenter);
        label_recordmode_2 = new QLabel(frame_recordmode);
        label_recordmode_2->setObjectName(QStringLiteral("label_recordmode_2"));
        label_recordmode_2->setGeometry(QRect(201, 2, 40, 40));
        label_recordmode_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        listWidget_recordmode = new QListWidget(tab_3);
        new QListWidgetItem(listWidget_recordmode);
        new QListWidgetItem(listWidget_recordmode);
        listWidget_recordmode->setObjectName(QStringLiteral("listWidget_recordmode"));
        listWidget_recordmode->setGeometry(QRect(520, 390, 181, 70));
        listWidget_recordmode->setFont(font4);
        listWidget_recordmode->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_modeSelect = new QFrame(tab_3);
        frame_modeSelect->setObjectName(QStringLiteral("frame_modeSelect"));
        frame_modeSelect->setGeometry(QRect(240, 280, 243, 44));
        frame_modeSelect->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_modeSelect->setFrameShape(QFrame::StyledPanel);
        frame_modeSelect->setFrameShadow(QFrame::Raised);
        label_modeSelect = new QLabel(frame_modeSelect);
        label_modeSelect->setObjectName(QStringLiteral("label_modeSelect"));
        label_modeSelect->setGeometry(QRect(0, 0, 201, 44));
        label_modeSelect->setFont(font4);
        label_modeSelect->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_modeSelect->setAlignment(Qt::AlignCenter);
        label_modeSelect_2 = new QLabel(frame_modeSelect);
        label_modeSelect_2->setObjectName(QStringLiteral("label_modeSelect_2"));
        label_modeSelect_2->setGeometry(QRect(201, 2, 40, 40));
        label_modeSelect_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        listWidget_modeSelect = new QListWidget(tab_3);
        new QListWidgetItem(listWidget_modeSelect);
        new QListWidgetItem(listWidget_modeSelect);
        listWidget_modeSelect->setObjectName(QStringLiteral("listWidget_modeSelect"));
        listWidget_modeSelect->setGeometry(QRect(600, 390, 181, 70));
        listWidget_modeSelect->setFont(font4);
        listWidget_modeSelect->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_32 = new QLabel(tab_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(45, 280, 168, 45));
        label_32->setMinimumSize(QSize(0, 0));
        label_32->setMaximumSize(QSize(16777215, 16777215));
        label_32->setFont(font4);
        label_32->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        scrollArea = new hp_style_scrollArea(tab_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(30, 10, 594, 231));
        scrollArea->setStyleSheet(QStringLiteral("background:transparent;"));
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 2900, 210));
        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 0, 168, 65));
        label_16->setMinimumSize(QSize(0, 0));
        label_16->setMaximumSize(QSize(16777215, 16777215));
        label_16->setFont(font7);
        label_16->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(20, 100, 168, 65));
        label_21->setMinimumSize(QSize(0, 0));
        label_21->setSizeIncrement(QSize(0, 0));
        label_21->setFont(font7);
        label_21->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_26 = new QLabel(scrollAreaWidgetContents);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(20, 150, 168, 65));
        label_26->setMinimumSize(QSize(0, 0));
        label_26->setSizeIncrement(QSize(0, 0));
        label_26->setFont(font7);
        label_26->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 50, 168, 65));
        label_18->setMinimumSize(QSize(0, 0));
        label_18->setMaximumSize(QSize(16777215, 9999999));
        label_18->setSizeIncrement(QSize(0, 0));
        label_18->setFont(font7);
        label_18->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_ble = new QCheckBox(scrollAreaWidgetContents);
        checkBox_ble->setObjectName(QStringLiteral("checkBox_ble"));
        checkBox_ble->setEnabled(true);
        checkBox_ble->setGeometry(QRect(200, 50, 70, 65));
        checkBox_ble->setFont(font8);
        checkBox_ble->setFocusPolicy(Qt::NoFocus);
        checkBox_ble->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        checkBox_area = new QCheckBox(scrollAreaWidgetContents);
        checkBox_area->setObjectName(QStringLiteral("checkBox_area"));
        checkBox_area->setEnabled(true);
        checkBox_area->setGeometry(QRect(200, 100, 70, 65));
        checkBox_area->setFont(font8);
        checkBox_area->setFocusPolicy(Qt::NoFocus);
        checkBox_area->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        buguangdeng = new QCheckBox(scrollAreaWidgetContents);
        buguangdeng->setObjectName(QStringLiteral("buguangdeng"));
        buguangdeng->setEnabled(true);
        buguangdeng->setGeometry(QRect(780, 0, 70, 65));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font9.setPointSize(17);
        font9.setStyleStrategy(QFont::PreferAntialias);
        buguangdeng->setFont(font9);
        buguangdeng->setFocusPolicy(Qt::NoFocus);
        buguangdeng->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        checkBox_sr = new QCheckBox(scrollAreaWidgetContents);
        checkBox_sr->setObjectName(QStringLiteral("checkBox_sr"));
        checkBox_sr->setEnabled(true);
        checkBox_sr->setGeometry(QRect(200, 150, 70, 65));
        checkBox_sr->setFont(font8);
        checkBox_sr->setFocusPolicy(Qt::NoFocus);
        checkBox_sr->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(600, 0, 168, 65));
        label_17->setMinimumSize(QSize(0, 0));
        label_17->setSizeIncrement(QSize(0, 0));
        label_17->setFont(font7);
        label_17->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_27 = new QLabel(scrollAreaWidgetContents);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(720, 50, 41, 65));
        label_27->setMinimumSize(QSize(0, 0));
        label_27->setSizeIncrement(QSize(0, 0));
        label_27->setFont(font7);
        label_27->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_28 = new QLabel(scrollAreaWidgetContents);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(720, 100, 41, 65));
        label_28->setMinimumSize(QSize(0, 0));
        label_28->setSizeIncrement(QSize(0, 0));
        label_28->setFont(font7);
        label_28->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_fid = new QCheckBox(scrollAreaWidgetContents);
        checkBox_fid->setObjectName(QStringLiteral("checkBox_fid"));
        checkBox_fid->setEnabled(true);
        checkBox_fid->setGeometry(QRect(780, 50, 70, 65));
        checkBox_fid->setFont(font8);
        checkBox_fid->setFocusPolicy(Qt::NoFocus);
        checkBox_fid->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        checkBox_pid = new QCheckBox(scrollAreaWidgetContents);
        checkBox_pid->setObjectName(QStringLiteral("checkBox_pid"));
        checkBox_pid->setEnabled(true);
        checkBox_pid->setGeometry(QRect(780, 100, 70, 65));
        checkBox_pid->setFont(font8);
        checkBox_pid->setFocusPolicy(Qt::NoFocus);
        checkBox_pid->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        label_31 = new QLabel(scrollAreaWidgetContents);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(600, 150, 168, 65));
        label_31->setMinimumSize(QSize(0, 0));
        label_31->setMaximumSize(QSize(16777215, 16777215));
        label_31->setFont(font7);
        label_31->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_autoUpload = new QCheckBox(scrollAreaWidgetContents);
        checkBox_autoUpload->setObjectName(QStringLiteral("checkBox_autoUpload"));
        checkBox_autoUpload->setEnabled(true);
        checkBox_autoUpload->setGeometry(QRect(780, 150, 70, 65));
        checkBox_autoUpload->setFont(font8);
        checkBox_autoUpload->setFocusPolicy(Qt::NoFocus);
        checkBox_autoUpload->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        ble_edit = new QToolButton(scrollAreaWidgetContents);
        ble_edit->setObjectName(QStringLiteral("ble_edit"));
        ble_edit->setGeometry(QRect(290, 67, 100, 30));
        ble_edit->setFont(font8);
        ble_edit->setFocusPolicy(Qt::NoFocus);
        ble_edit->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        ble_edit->setAutoRaise(false);
        wifi_edit = new QToolButton(scrollAreaWidgetContents);
        wifi_edit->setObjectName(QStringLiteral("wifi_edit"));
        wifi_edit->setGeometry(QRect(290, 17, 100, 30));
        wifi_edit->setFont(font8);
        wifi_edit->setFocusPolicy(Qt::NoFocus);
        wifi_edit->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        wifi_edit->setAutoRaise(true);
        autoUpload_edit = new QToolButton(scrollAreaWidgetContents);
        autoUpload_edit->setObjectName(QStringLiteral("autoUpload_edit"));
        autoUpload_edit->setGeometry(QRect(870, 167, 100, 30));
        autoUpload_edit->setFont(font8);
        autoUpload_edit->setFocusPolicy(Qt::NoFocus);
        autoUpload_edit->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        autoUpload_edit->setAutoRaise(true);
        btautoUpload_once = new QToolButton(scrollAreaWidgetContents);
        btautoUpload_once->setObjectName(QStringLiteral("btautoUpload_once"));
        btautoUpload_once->setGeometry(QRect(980, 167, 141, 30));
        btautoUpload_once->setFont(font8);
        btautoUpload_once->setFocusPolicy(Qt::NoFocus);
        btautoUpload_once->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        btautoUpload_once->setAutoRaise(true);
        btdownload = new QToolButton(scrollAreaWidgetContents);
        btdownload->setObjectName(QStringLiteral("btdownload"));
        btdownload->setGeometry(QRect(1130, 167, 141, 30));
        btdownload->setFont(font8);
        btdownload->setFocusPolicy(Qt::NoFocus);
        btdownload->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        btdownload->setAutoRaise(true);
        checkBox_wifi = new QCheckBox(scrollAreaWidgetContents);
        checkBox_wifi->setObjectName(QStringLiteral("checkBox_wifi"));
        checkBox_wifi->setEnabled(true);
        checkBox_wifi->setGeometry(QRect(200, 0, 70, 65));
        checkBox_wifi->setFont(font8);
        checkBox_wifi->setFocusPolicy(Qt::NoFocus);
        checkBox_wifi->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        label_33 = new QLabel(scrollAreaWidgetContents);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(1110, 0, 168, 65));
        label_33->setMinimumSize(QSize(0, 0));
        label_33->setSizeIncrement(QSize(0, 0));
        label_33->setFont(font7);
        label_33->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_hdmi = new QCheckBox(scrollAreaWidgetContents);
        checkBox_hdmi->setObjectName(QStringLiteral("checkBox_hdmi"));
        checkBox_hdmi->setEnabled(true);
        checkBox_hdmi->setGeometry(QRect(1290, 0, 70, 65));
        checkBox_hdmi->setFont(font9);
        checkBox_hdmi->setFocusPolicy(Qt::NoFocus);
        checkBox_hdmi->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        checkBox_sis = new QCheckBox(scrollAreaWidgetContents);
        checkBox_sis->setObjectName(QStringLiteral("checkBox_sis"));
        checkBox_sis->setEnabled(true);
        checkBox_sis->setGeometry(QRect(1290, 60, 70, 40));
        checkBox_sis->setFont(font8);
        checkBox_sis->setMouseTracking(false);
        checkBox_sis->setFocusPolicy(Qt::NoFocus);
        checkBox_sis->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_34 = new QLabel(scrollAreaWidgetContents);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(1180, 60, 91, 45));
        label_34->setMinimumSize(QSize(0, 0));
        label_34->setMaximumSize(QSize(16777215, 16777215));
        label_34->setFont(font7);
        label_34->setMouseTracking(true);
        label_34->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_35 = new QLabel(scrollAreaWidgetContents);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(1160, 110, 111, 45));
        label_35->setMinimumSize(QSize(0, 0));
        label_35->setMaximumSize(QSize(16777215, 16777215));
        label_35->setFont(font7);
        label_35->setMouseTracking(true);
        label_35->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_mulhom = new QCheckBox(scrollAreaWidgetContents);
        checkBox_mulhom->setObjectName(QStringLiteral("checkBox_mulhom"));
        checkBox_mulhom->setEnabled(true);
        checkBox_mulhom->setGeometry(QRect(1290, 110, 70, 40));
        checkBox_mulhom->setFont(font8);
        checkBox_mulhom->setMouseTracking(false);
        checkBox_mulhom->setFocusPolicy(Qt::NoFocus);
        checkBox_mulhom->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        mulhom_edit = new QToolButton(scrollAreaWidgetContents);
        mulhom_edit->setObjectName(QStringLiteral("mulhom_edit"));
        mulhom_edit->setGeometry(QRect(1370, 114, 100, 30));
        mulhom_edit->setFont(font8);
        mulhom_edit->setFocusPolicy(Qt::NoFocus);
        mulhom_edit->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        mulhom_edit->setAutoRaise(true);
        checkBox_gw = new QCheckBox(scrollAreaWidgetContents);
        checkBox_gw->setObjectName(QStringLiteral("checkBox_gw"));
        checkBox_gw->setEnabled(true);
        checkBox_gw->setGeometry(QRect(1510, 160, 70, 40));
        checkBox_gw->setFont(font8);
        checkBox_gw->setMouseTracking(false);
        checkBox_gw->setFocusPolicy(Qt::NoFocus);
        checkBox_gw->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_36 = new QLabel(scrollAreaWidgetContents);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(1380, 160, 111, 45));
        label_36->setMinimumSize(QSize(0, 0));
        label_36->setMaximumSize(QSize(16777215, 16777215));
        label_36->setFont(font7);
        label_36->setMouseTracking(true);
        label_36->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_angel = new QCheckBox(scrollAreaWidgetContents);
        checkBox_angel->setObjectName(QStringLiteral("checkBox_angel"));
        checkBox_angel->setEnabled(true);
        checkBox_angel->setGeometry(QRect(280, 100, 171, 65));
        checkBox_angel->setFont(font8);
        checkBox_angel->setFocusPolicy(Qt::NoFocus);
        checkBox_angel->setLayoutDirection(Qt::RightToLeft);
        checkBox_angel->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"color:#7CA6C9;\n"
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
        checkBox_volume = new QCheckBox(scrollAreaWidgetContents);
        checkBox_volume->setObjectName(QStringLiteral("checkBox_volume"));
        checkBox_volume->setEnabled(true);
        checkBox_volume->setGeometry(QRect(280, 150, 171, 65));
        checkBox_volume->setFont(font8);
        checkBox_volume->setFocusPolicy(Qt::NoFocus);
        checkBox_volume->setLayoutDirection(Qt::RightToLeft);
        checkBox_volume->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"color:#7CA6C9;\n"
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
        label_37 = new QLabel(scrollAreaWidgetContents);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(1650, 10, 111, 45));
        label_37->setMinimumSize(QSize(0, 0));
        label_37->setMaximumSize(QSize(16777215, 16777215));
        label_37->setFont(font7);
        label_37->setMouseTracking(true);
        label_37->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_panorama = new QCheckBox(scrollAreaWidgetContents);
        checkBox_panorama->setObjectName(QStringLiteral("checkBox_panorama"));
        checkBox_panorama->setEnabled(true);
        checkBox_panorama->setGeometry(QRect(1780, 10, 70, 40));
        checkBox_panorama->setFont(font8);
        checkBox_panorama->setMouseTracking(false);
        checkBox_panorama->setFocusPolicy(Qt::NoFocus);
        checkBox_panorama->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        checkBox_zoomSave = new QCheckBox(scrollAreaWidgetContents);
        checkBox_zoomSave->setObjectName(QStringLiteral("checkBox_zoomSave"));
        checkBox_zoomSave->setEnabled(true);
        checkBox_zoomSave->setGeometry(QRect(1780, 70, 70, 40));
        checkBox_zoomSave->setFont(font8);
        checkBox_zoomSave->setMouseTracking(false);
        checkBox_zoomSave->setFocusPolicy(Qt::NoFocus);
        checkBox_zoomSave->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_39 = new QLabel(scrollAreaWidgetContents);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(1650, 70, 111, 45));
        label_39->setMinimumSize(QSize(0, 0));
        label_39->setMaximumSize(QSize(16777215, 16777215));
        label_39->setFont(font7);
        label_39->setMouseTracking(true);
        label_39->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_39->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_oritoggle = new QCheckBox(scrollAreaWidgetContents);
        checkBox_oritoggle->setObjectName(QStringLiteral("checkBox_oritoggle"));
        checkBox_oritoggle->setEnabled(true);
        checkBox_oritoggle->setGeometry(QRect(1780, 120, 70, 65));
        checkBox_oritoggle->setFont(font8);
        checkBox_oritoggle->setFocusPolicy(Qt::NoFocus);
        checkBox_oritoggle->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        label_40 = new QLabel(scrollAreaWidgetContents);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(1600, 120, 168, 65));
        label_40->setMinimumSize(QSize(0, 0));
        label_40->setSizeIncrement(QSize(0, 0));
        label_40->setFont(font7);
        label_40->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_40->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_homogeneity = new QCheckBox(scrollAreaWidgetContents);
        checkBox_homogeneity->setObjectName(QStringLiteral("checkBox_homogeneity"));
        checkBox_homogeneity->setEnabled(true);
        checkBox_homogeneity->setGeometry(QRect(1780, 170, 70, 65));
        checkBox_homogeneity->setFont(font8);
        checkBox_homogeneity->setFocusPolicy(Qt::NoFocus);
        checkBox_homogeneity->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        label_41 = new QLabel(scrollAreaWidgetContents);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(1600, 170, 168, 65));
        label_41->setMinimumSize(QSize(0, 0));
        label_41->setSizeIncrement(QSize(0, 0));
        label_41->setFont(font7);
        label_41->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_42 = new QLabel(scrollAreaWidgetContents);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(1870, 0, 168, 65));
        label_42->setMinimumSize(QSize(0, 0));
        label_42->setSizeIncrement(QSize(0, 0));
        label_42->setFont(font7);
        label_42->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_42->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_stepZero = new QCheckBox(scrollAreaWidgetContents);
        checkBox_stepZero->setObjectName(QStringLiteral("checkBox_stepZero"));
        checkBox_stepZero->setEnabled(true);
        checkBox_stepZero->setGeometry(QRect(2050, 0, 70, 65));
        checkBox_stepZero->setFont(font8);
        checkBox_stepZero->setFocusPolicy(Qt::NoFocus);
        checkBox_stepZero->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        label_43 = new QLabel(scrollAreaWidgetContents);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(1920, 70, 111, 45));
        label_43->setMinimumSize(QSize(0, 0));
        label_43->setMaximumSize(QSize(16777215, 16777215));
        label_43->setFont(font7);
        label_43->setMouseTracking(true);
        label_43->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_43->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_4G = new QCheckBox(scrollAreaWidgetContents);
        checkBox_4G->setObjectName(QStringLiteral("checkBox_4G"));
        checkBox_4G->setEnabled(true);
        checkBox_4G->setGeometry(QRect(2050, 70, 70, 40));
        checkBox_4G->setFont(font8);
        checkBox_4G->setMouseTracking(false);
        checkBox_4G->setFocusPolicy(Qt::NoFocus);
        checkBox_4G->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_44 = new QLabel(scrollAreaWidgetContents);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(1920, 120, 111, 45));
        label_44->setMinimumSize(QSize(0, 0));
        label_44->setMaximumSize(QSize(16777215, 16777215));
        label_44->setFont(font7);
        label_44->setMouseTracking(true);
        label_44->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_44->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_compass = new QCheckBox(scrollAreaWidgetContents);
        checkBox_compass->setObjectName(QStringLiteral("checkBox_compass"));
        checkBox_compass->setEnabled(true);
        checkBox_compass->setGeometry(QRect(2050, 120, 70, 40));
        checkBox_compass->setFont(font8);
        checkBox_compass->setMouseTracking(false);
        checkBox_compass->setFocusPolicy(Qt::NoFocus);
        checkBox_compass->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        calbration_edit = new QToolButton(scrollAreaWidgetContents);
        calbration_edit->setObjectName(QStringLiteral("calbration_edit"));
        calbration_edit->setGeometry(QRect(2140, 130, 91, 41));
        QFont font10;
        font10.setPointSize(16);
        calbration_edit->setFont(font10);
        calbration_edit->setFocusPolicy(Qt::NoFocus);
        calbration_edit->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        calbration_edit->setAutoRaise(true);
        checkBox_GPS = new QCheckBox(scrollAreaWidgetContents);
        checkBox_GPS->setObjectName(QStringLiteral("checkBox_GPS"));
        checkBox_GPS->setEnabled(true);
        checkBox_GPS->setGeometry(QRect(2050, 170, 70, 40));
        checkBox_GPS->setFont(font8);
        checkBox_GPS->setMouseTracking(false);
        checkBox_GPS->setFocusPolicy(Qt::NoFocus);
        checkBox_GPS->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_46 = new QLabel(scrollAreaWidgetContents);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(1920, 170, 111, 45));
        label_46->setMinimumSize(QSize(0, 0));
        label_46->setMaximumSize(QSize(16777215, 16777215));
        label_46->setFont(font7);
        label_46->setMouseTracking(true);
        label_46->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_46->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_47 = new QLabel(scrollAreaWidgetContents);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(2140, 10, 111, 45));
        label_47->setMinimumSize(QSize(0, 0));
        label_47->setMaximumSize(QSize(16777215, 16777215));
        label_47->setFont(font7);
        label_47->setMouseTracking(true);
        label_47->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_47->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_avgTemp = new QCheckBox(scrollAreaWidgetContents);
        checkBox_avgTemp->setObjectName(QStringLiteral("checkBox_avgTemp"));
        checkBox_avgTemp->setEnabled(true);
        checkBox_avgTemp->setGeometry(QRect(2270, 10, 70, 40));
        checkBox_avgTemp->setFont(font8);
        checkBox_avgTemp->setMouseTracking(false);
        checkBox_avgTemp->setFocusPolicy(Qt::NoFocus);
        checkBox_avgTemp->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_48 = new QLabel(scrollAreaWidgetContents);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setGeometry(QRect(2140, 70, 111, 45));
        label_48->setMinimumSize(QSize(0, 0));
        label_48->setMaximumSize(QSize(16777215, 16777215));
        label_48->setFont(font7);
        label_48->setMouseTracking(true);
        label_48->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_48->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_nonCool = new QCheckBox(scrollAreaWidgetContents);
        checkBox_nonCool->setObjectName(QStringLiteral("checkBox_nonCool"));
        checkBox_nonCool->setEnabled(true);
        checkBox_nonCool->setGeometry(QRect(2270, 70, 70, 40));
        checkBox_nonCool->setFont(font8);
        checkBox_nonCool->setMouseTracking(false);
        checkBox_nonCool->setFocusPolicy(Qt::NoFocus);
        checkBox_nonCool->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        checkBox_eth = new QCheckBox(scrollAreaWidgetContents);
        checkBox_eth->setObjectName(QStringLiteral("checkBox_eth"));
        checkBox_eth->setEnabled(true);
        checkBox_eth->setGeometry(QRect(2270, 120, 70, 40));
        checkBox_eth->setFont(font8);
        checkBox_eth->setMouseTracking(false);
        checkBox_eth->setFocusPolicy(Qt::NoFocus);
        checkBox_eth->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_50 = new QLabel(scrollAreaWidgetContents);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setGeometry(QRect(2140, 120, 111, 45));
        label_50->setMinimumSize(QSize(0, 0));
        label_50->setMaximumSize(QSize(16777215, 16777215));
        label_50->setFont(font7);
        label_50->setMouseTracking(true);
        label_50->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_50->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_51 = new QLabel(scrollAreaWidgetContents);
        label_51->setObjectName(QStringLiteral("label_51"));
        label_51->setGeometry(QRect(2140, 170, 111, 45));
        label_51->setMinimumSize(QSize(0, 0));
        label_51->setMaximumSize(QSize(16777215, 16777215));
        label_51->setFont(font7);
        label_51->setMouseTracking(true);
        label_51->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_51->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_sketch = new QCheckBox(scrollAreaWidgetContents);
        checkBox_sketch->setObjectName(QStringLiteral("checkBox_sketch"));
        checkBox_sketch->setEnabled(true);
        checkBox_sketch->setGeometry(QRect(2270, 170, 70, 40));
        checkBox_sketch->setFont(font8);
        checkBox_sketch->setMouseTracking(false);
        checkBox_sketch->setFocusPolicy(Qt::NoFocus);
        checkBox_sketch->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        sketch_edit = new QToolButton(scrollAreaWidgetContents);
        sketch_edit->setObjectName(QStringLiteral("sketch_edit"));
        sketch_edit->setGeometry(QRect(2350, 170, 91, 41));
        sketch_edit->setFont(font10);
        sketch_edit->setFocusPolicy(Qt::NoFocus);
        sketch_edit->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        sketch_edit->setAutoRaise(true);
        label_52 = new QLabel(scrollAreaWidgetContents);
        label_52->setObjectName(QStringLiteral("label_52"));
        label_52->setGeometry(QRect(2360, 10, 111, 45));
        label_52->setMinimumSize(QSize(0, 0));
        label_52->setMaximumSize(QSize(16777215, 16777215));
        label_52->setFont(font7);
        label_52->setMouseTracking(true);
        label_52->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_52->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_flip = new QCheckBox(scrollAreaWidgetContents);
        checkBox_flip->setObjectName(QStringLiteral("checkBox_flip"));
        checkBox_flip->setEnabled(true);
        checkBox_flip->setGeometry(QRect(2490, 10, 70, 40));
        checkBox_flip->setFont(font8);
        checkBox_flip->setMouseTracking(false);
        checkBox_flip->setFocusPolicy(Qt::NoFocus);
        checkBox_flip->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        checkBox_transmission = new QCheckBox(scrollAreaWidgetContents);
        checkBox_transmission->setObjectName(QStringLiteral("checkBox_transmission"));
        checkBox_transmission->setEnabled(true);
        checkBox_transmission->setGeometry(QRect(2480, 60, 70, 40));
        checkBox_transmission->setFont(font8);
        checkBox_transmission->setFocusPolicy(Qt::NoFocus);
        checkBox_transmission->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_53 = new QLabel(scrollAreaWidgetContents);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(2350, 60, 121, 51));
        label_53->setMinimumSize(QSize(0, 0));
        label_53->setMaximumSize(QSize(16777215, 16777215));
        label_53->setFont(font7);
        label_53->setMouseTracking(true);
        label_53->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_53->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        trmission_edit = new QToolButton(scrollAreaWidgetContents);
        trmission_edit->setObjectName(QStringLiteral("trmission_edit"));
        trmission_edit->setGeometry(QRect(2390, 110, 91, 41));
        trmission_edit->setFont(font10);
        trmission_edit->setFocusPolicy(Qt::NoFocus);
        trmission_edit->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        trmission_edit->setAutoRaise(true);
        checkBox_bmp = new QCheckBox(scrollAreaWidgetContents);
        checkBox_bmp->setObjectName(QStringLiteral("checkBox_bmp"));
        checkBox_bmp->setEnabled(true);
        checkBox_bmp->setGeometry(QRect(2480, 110, 70, 40));
        checkBox_bmp->setFont(font8);
        checkBox_bmp->setFocusPolicy(Qt::NoFocus);
        checkBox_bmp->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_54 = new QLabel(scrollAreaWidgetContents);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setGeometry(QRect(2350, 110, 121, 51));
        label_54->setMinimumSize(QSize(0, 0));
        label_54->setMaximumSize(QSize(16777215, 16777215));
        label_54->setFont(font7);
        label_54->setMouseTracking(true);
        label_54->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_54->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_contrustFocus = new QCheckBox(scrollAreaWidgetContents);
        checkBox_contrustFocus->setObjectName(QStringLiteral("checkBox_contrustFocus"));
        checkBox_contrustFocus->setEnabled(true);
        checkBox_contrustFocus->setGeometry(QRect(2480, 160, 70, 40));
        checkBox_contrustFocus->setFont(font8);
        checkBox_contrustFocus->setFocusPolicy(Qt::NoFocus);
        checkBox_contrustFocus->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_55 = new QLabel(scrollAreaWidgetContents);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setGeometry(QRect(2330, 160, 141, 51));
        label_55->setMinimumSize(QSize(0, 0));
        label_55->setMaximumSize(QSize(16777215, 16777215));
        label_55->setFont(font7);
        label_55->setMouseTracking(true);
        label_55->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_55->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_brightness = new QCheckBox(scrollAreaWidgetContents);
        checkBox_brightness->setObjectName(QStringLiteral("checkBox_brightness"));
        checkBox_brightness->setEnabled(true);
        checkBox_brightness->setGeometry(QRect(2710, 10, 70, 40));
        checkBox_brightness->setFont(font8);
        checkBox_brightness->setMouseTracking(false);
        checkBox_brightness->setFocusPolicy(Qt::NoFocus);
        checkBox_brightness->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_56 = new QLabel(scrollAreaWidgetContents);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setGeometry(QRect(2580, 10, 111, 45));
        label_56->setMinimumSize(QSize(0, 0));
        label_56->setMaximumSize(QSize(16777215, 16777215));
        label_56->setFont(font7);
        label_56->setMouseTracking(true);
        label_56->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_56->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_57 = new QLabel(scrollAreaWidgetContents);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setGeometry(QRect(2580, 60, 111, 45));
        label_57->setMinimumSize(QSize(0, 0));
        label_57->setMaximumSize(QSize(16777215, 16777215));
        label_57->setFont(font7);
        label_57->setMouseTracking(true);
        label_57->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_57->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_autoReg = new QCheckBox(scrollAreaWidgetContents);
        checkBox_autoReg->setObjectName(QStringLiteral("checkBox_autoReg"));
        checkBox_autoReg->setEnabled(true);
        checkBox_autoReg->setGeometry(QRect(2710, 60, 70, 40));
        checkBox_autoReg->setFont(font8);
        checkBox_autoReg->setMouseTracking(false);
        checkBox_autoReg->setFocusPolicy(Qt::NoFocus);
        checkBox_autoReg->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_58 = new QLabel(scrollAreaWidgetContents);
        label_58->setObjectName(QStringLiteral("label_58"));
        label_58->setGeometry(QRect(2580, 110, 111, 45));
        label_58->setMinimumSize(QSize(0, 0));
        label_58->setMaximumSize(QSize(16777215, 16777215));
        label_58->setFont(font7);
        label_58->setMouseTracking(true);
        label_58->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_58->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_preset1 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_preset1->setObjectName(QStringLiteral("checkBox_preset1"));
        checkBox_preset1->setEnabled(true);
        checkBox_preset1->setGeometry(QRect(2710, 110, 70, 40));
        checkBox_preset1->setFont(font8);
        checkBox_preset1->setMouseTracking(false);
        checkBox_preset1->setFocusPolicy(Qt::NoFocus);
        checkBox_preset1->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        checkBox_preset2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_preset2->setObjectName(QStringLiteral("checkBox_preset2"));
        checkBox_preset2->setEnabled(true);
        checkBox_preset2->setGeometry(QRect(2710, 160, 70, 40));
        checkBox_preset2->setFont(font8);
        checkBox_preset2->setMouseTracking(false);
        checkBox_preset2->setFocusPolicy(Qt::NoFocus);
        checkBox_preset2->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:70px;\n"
"	height:40px;\n"
"    border-image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label_59 = new QLabel(scrollAreaWidgetContents);
        label_59->setObjectName(QStringLiteral("label_59"));
        label_59->setGeometry(QRect(2580, 160, 111, 45));
        label_59->setMinimumSize(QSize(0, 0));
        label_59->setMaximumSize(QSize(16777215, 16777215));
        label_59->setFont(font7);
        label_59->setMouseTracking(true);
        label_59->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_59->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_scroll = new myLabel(tab_3);
        label_scroll->setObjectName(QStringLiteral("label_scroll"));
        label_scroll->setGeometry(QRect(626, 10, 15, 231));
        label_scroll->setStyleSheet(QStringLiteral("background:transparent;"));
        listWidget_focusmode = new QListWidget(tab_3);
        new QListWidgetItem(listWidget_focusmode);
        new QListWidgetItem(listWidget_focusmode);
        new QListWidgetItem(listWidget_focusmode);
        listWidget_focusmode->setObjectName(QStringLiteral("listWidget_focusmode"));
        listWidget_focusmode->setGeometry(QRect(610, 190, 201, 101));
        listWidget_focusmode->setFont(font4);
        listWidget_focusmode->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_focusmode = new QFrame(tab_3);
        frame_focusmode->setObjectName(QStringLiteral("frame_focusmode"));
        frame_focusmode->setGeometry(QRect(240, 230, 243, 44));
        frame_focusmode->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_focusmode->setFrameShape(QFrame::StyledPanel);
        frame_focusmode->setFrameShadow(QFrame::Raised);
        label_focusmode = new QLabel(frame_focusmode);
        label_focusmode->setObjectName(QStringLiteral("label_focusmode"));
        label_focusmode->setGeometry(QRect(0, 0, 201, 44));
        label_focusmode->setFont(font4);
        label_focusmode->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_focusmode->setAlignment(Qt::AlignCenter);
        label_focusmode_2 = new QLabel(frame_focusmode);
        label_focusmode_2->setObjectName(QStringLiteral("label_focusmode_2"));
        label_focusmode_2->setGeometry(QRect(201, 2, 40, 40));
        label_focusmode_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/down_arrow_n.png);"));
        label_45 = new QLabel(tab_3);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(45, 230, 168, 45));
        label_45->setMinimumSize(QSize(0, 0));
        label_45->setMaximumSize(QSize(16777215, 16777215));
        label_45->setFont(font4);
        label_45->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_45->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frame_imageType = new QFrame(tab_3);
        frame_imageType->setObjectName(QStringLiteral("frame_imageType"));
        frame_imageType->setGeometry(QRect(830, 30, 243, 44));
        frame_imageType->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_imageType->setFrameShape(QFrame::StyledPanel);
        frame_imageType->setFrameShadow(QFrame::Raised);
        label__imageType = new QLabel(frame_imageType);
        label__imageType->setObjectName(QStringLiteral("label__imageType"));
        label__imageType->setGeometry(QRect(0, 0, 201, 44));
        label__imageType->setFont(font4);
        label__imageType->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label__imageType->setAlignment(Qt::AlignCenter);
        label__imageType_2 = new QLabel(frame_imageType);
        label__imageType_2->setObjectName(QStringLiteral("label__imageType_2"));
        label__imageType_2->setGeometry(QRect(201, 2, 40, 40));
        label__imageType_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        listWidget_imageType = new QListWidget(tab_3);
        new QListWidgetItem(listWidget_imageType);
        new QListWidgetItem(listWidget_imageType);
        new QListWidgetItem(listWidget_imageType);
        listWidget_imageType->setObjectName(QStringLiteral("listWidget_imageType"));
        listWidget_imageType->setGeometry(QRect(650, 320, 201, 101));
        listWidget_imageType->setFont(font4);
        listWidget_imageType->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_38 = new QLabel(tab_3);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(650, 30, 168, 50));
        label_38->setMinimumSize(QSize(0, 0));
        label_38->setMaximumSize(QSize(16777215, 16777215));
        label_38->setFont(font4);
        label_38->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_38->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabWidget->addTab(tab_3, QString());
        scrollArea->raise();
        frame_recordmode->raise();
        spinBox_autosave->raise();
        label_24->raise();
        comboBox_usbmode->raise();
        label_19->raise();
        frame_usbmode->raise();
        label_29->raise();
        listWidget_recordmode->raise();
        listWidget_usbmode->raise();
        frame_modeSelect->raise();
        listWidget_modeSelect->raise();
        label_32->raise();
        label_scroll->raise();
        label_45->raise();
        frame_focusmode->raise();
        listWidget_focusmode->raise();
        frame_imageType->raise();
        listWidget_imageType->raise();
        label_38->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tab_4->setFont(font2);
        pushButton_default = new QPushButton(tab_4);
        pushButton_default->setObjectName(QStringLiteral("pushButton_default"));
        pushButton_default->setEnabled(true);
        pushButton_default->setGeometry(QRect(131, 410, 371, 45));
        pushButton_default->setFont(font7);
        pushButton_default->setFocusPolicy(Qt::NoFocus);
        pushButton_default->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image:url(:/res/res/button_n.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
"QPushButton:pressed{\n"
"border-image:url(:/res/res/setting_selected.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
""));
        pushButton_default->setFlat(true);
        comboBox_language = new QComboBox(tab_4);
        comboBox_language->addItem(QString());
        comboBox_language->addItem(QString());
        comboBox_language->addItem(QString());
        comboBox_language->addItem(QString());
        comboBox_language->addItem(QString());
        comboBox_language->addItem(QString());
        comboBox_language->setObjectName(QStringLiteral("comboBox_language"));
        comboBox_language->setEnabled(true);
        comboBox_language->setGeometry(QRect(20, 10, 141, 45));
        QFont font11;
        font11.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font11.setPointSize(17);
        font11.setStyleStrategy(QFont::PreferDefault);
        comboBox_language->setFont(font11);
        comboBox_language->setFocusPolicy(Qt::StrongFocus);
        comboBox_language->setContextMenuPolicy(Qt::DefaultContextMenu);
        comboBox_language->setStyleSheet(QLatin1String("\n"
"QComboBox {\n"
"	color:red;\n"
"    border: 0px solid #7CA6C9;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"\n"
"background-color:transparent;\n"
"\n"
"    border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"}\n"
"QComboBox:editable {\n"
"	background:transparent;\n"
"	color:#7CA6C9;\n"
"}\n"
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
"    border"
                        "-left-width: 0px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 0px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/res/res/down_arrow_n.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 0px;\n"
"    left: 0px;\n"
"}\n"
"\n"
""));
        comboBox_language->setEditable(false);
        comboBox_language->setInsertPolicy(QComboBox::InsertAtBottom);
        comboBox_language->setIconSize(QSize(24, 24));
        comboBox_language->setFrame(true);
        dateTimeEdit = new QDateTimeEdit(tab_4);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(131, 86, 371, 45));
        sizePolicy1.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy1);
        dateTimeEdit->setFont(font11);
        dateTimeEdit->setFocusPolicy(Qt::WheelFocus);
        dateTimeEdit->setAutoFillBackground(false);
        dateTimeEdit->setStyleSheet(QString::fromUtf8("QDateTimeEdit\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QDateTimeEdit::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"QDateTimeEdit::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDateTimeEdit::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"  \n"
"QDateTimeEdit::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDat"
                        "eTimeEdit::down-arrow:disabled,QDateTimeEdit::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDateTimeEdit::up-arrow:disabled,QDateTimeEdit::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
""));
        dateTimeEdit->setWrapping(false);
        dateTimeEdit->setAlignment(Qt::AlignCenter);
        dateTimeEdit->setAccelerated(true);
        dateTimeEdit->setCurrentSectionIndex(0);
        dateTimeEdit->setTimeSpec(Qt::LocalTime);
        auto_lcdoff = new QComboBox(tab_4);
        auto_lcdoff->addItem(icon, QString());
        auto_lcdoff->addItem(icon, QString());
        auto_lcdoff->addItem(icon, QString());
        auto_lcdoff->addItem(icon, QString());
        auto_lcdoff->setObjectName(QStringLiteral("auto_lcdoff"));
        auto_lcdoff->setGeometry(QRect(530, 350, 271, 45));
        auto_lcdoff->setMinimumSize(QSize(0, 0));
        auto_lcdoff->setMaximumSize(QSize(16777215, 16777215));
        auto_lcdoff->setFont(font4);
        auto_lcdoff->setFocusPolicy(Qt::StrongFocus);
        auto_lcdoff->setLayoutDirection(Qt::LeftToRight);
        auto_lcdoff->setStyleSheet(QLatin1String("\n"
"QComboBox {\n"
"	color:red;\n"
"    border: 0px solid #7CA6C9;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"\n"
"background-color:transparent;\n"
"\n"
"    border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"}\n"
"QComboBox:editable {\n"
"	background:transparent;\n"
"	color:#7CA6C9;\n"
"}\n"
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
"    border"
                        "-left-width: 0px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 0px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/res/res/down_arrow_n.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 0px;\n"
"    left: 0px;\n"
"}\n"
"\n"
""));
        auto_lcdoff->setMaxVisibleItems(4);
        auto_lcdoff->setIconSize(QSize(24, 24));
        auto_lcdoff->setFrame(true);
        label_23 = new QLabel(tab_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(83, 219, 138, 45));
        label_23->setMinimumSize(QSize(0, 0));
        label_23->setMaximumSize(QSize(16777215, 16777215));
        label_23->setFont(font4);
        label_23->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_22 = new QLabel(tab_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(83, 154, 138, 45));
        label_22->setMaximumSize(QSize(200, 200));
        label_22->setFont(font4);
        label_22->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        auto_poweroff = new QComboBox(tab_4);
        auto_poweroff->addItem(icon, QString());
        auto_poweroff->addItem(icon, QString());
        auto_poweroff->addItem(icon, QString());
        auto_poweroff->addItem(icon, QString());
        auto_poweroff->setObjectName(QStringLiteral("auto_poweroff"));
        auto_poweroff->setGeometry(QRect(540, 420, 241, 45));
        auto_poweroff->setMinimumSize(QSize(0, 0));
        auto_poweroff->setFont(font4);
        auto_poweroff->setFocusPolicy(Qt::StrongFocus);
        auto_poweroff->setStyleSheet(QLatin1String("\n"
"QComboBox {\n"
"	color:red;\n"
"    border: 0px solid #7CA6C9;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"\n"
"background-color:transparent;\n"
"\n"
"    border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"}\n"
"QComboBox:editable {\n"
"	background:transparent;\n"
"	color:#7CA6C9;\n"
"}\n"
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
"    border"
                        "-left-width: 0px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 0px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/res/res/down_arrow_n.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 0px;\n"
"    left: 0px;\n"
"}\n"
"\n"
""));
        auto_poweroff->setMaxVisibleItems(4);
        auto_poweroff->setIconSize(QSize(24, 24));
        auto_poweroff->setFrame(true);
        frame_language = new QFrame(tab_4);
        frame_language->setObjectName(QStringLiteral("frame_language"));
        frame_language->setGeometry(QRect(133, 21, 371, 44));
        frame_language->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_language->setFrameShape(QFrame::StyledPanel);
        frame_language->setFrameShadow(QFrame::Raised);
        label_language = new QLabel(frame_language);
        label_language->setObjectName(QStringLiteral("label_language"));
        label_language->setGeometry(QRect(0, 0, 311, 44));
        label_language->setFont(font4);
        label_language->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_language->setAlignment(Qt::AlignCenter);
        label_language2 = new QLabel(frame_language);
        label_language2->setObjectName(QStringLiteral("label_language2"));
        label_language2->setGeometry(QRect(329, 2, 40, 40));
        label_language2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        listWidget_language = new QListWidget(tab_4);
        new QListWidgetItem(listWidget_language);
        new QListWidgetItem(listWidget_language);
        new QListWidgetItem(listWidget_language);
        new QListWidgetItem(listWidget_language);
        new QListWidgetItem(listWidget_language);
        new QListWidgetItem(listWidget_language);
        listWidget_language->setObjectName(QStringLiteral("listWidget_language"));
        listWidget_language->setGeometry(QRect(520, 50, 181, 251));
        listWidget_language->setFont(font4);
        listWidget_language->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"	\n"
"	border-right-color: 0px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:#32CC99;\n"
"	width:40px;\n"
"	margin:40 0 40 0px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\350\256\276\347\275\256 */\n"
"QScrollBar::handle:vertical {\n"
"/*	background-color:#7CA6C9;*/	\n"
"	background-color: rgb(83, 166, 249);\n"
"	border:1px solid #7CA6C9;\n"
"	height:30px;\n"
"	max-height:20px;\n"
"}\n"
"\n"
"/* \345\272\225\351\203\250\346\216\247\345\210\266\345\235\227 */\n"
"QScrollBar::add-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:transparent;\n"
"	width:40px;\n"
"	height:40px;\n"
"	subcontrol-position:bottom;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_down_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \351\241\266\351\203\250\346\216\247\345\210\266\345\235\227 */\n"
"QScrollBar::sub-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:transparent"
                        ";\n"
"	width:40px;\n"
"	height:40px;\n"
"	subcontrol-position:top;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_up_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \346\216\247\345\210\266\345\235\227\344\270\212\347\232\204\345\260\217\347\256\255\345\244\264 */\n"
"QScrollBar::up-arrow:vertical,QScrollBar::down-arrow:vertical {\n"
"	border:0px;\n"
"	width:40px;\n"
"	height:40px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\212\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::add-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\213\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::sub-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"\n"
""));
        listWidget_language->setBatchSize(100);
        frame_poweroff = new QFrame(tab_4);
        frame_poweroff->setObjectName(QStringLiteral("frame_poweroff"));
        frame_poweroff->setGeometry(QRect(234, 154, 271, 44));
        frame_poweroff->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_poweroff->setFrameShape(QFrame::StyledPanel);
        frame_poweroff->setFrameShadow(QFrame::Raised);
        label_poweroff = new QLabel(frame_poweroff);
        label_poweroff->setObjectName(QStringLiteral("label_poweroff"));
        label_poweroff->setGeometry(QRect(0, 0, 221, 44));
        label_poweroff->setFont(font4);
        label_poweroff->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_poweroff->setAlignment(Qt::AlignCenter);
        label_poweroff_2 = new QLabel(frame_poweroff);
        label_poweroff_2->setObjectName(QStringLiteral("label_poweroff_2"));
        label_poweroff_2->setGeometry(QRect(229, 2, 40, 40));
        label_poweroff_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        frame_lcdoff = new QFrame(tab_4);
        frame_lcdoff->setObjectName(QStringLiteral("frame_lcdoff"));
        frame_lcdoff->setGeometry(QRect(234, 219, 271, 44));
        frame_lcdoff->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_lcdoff->setFrameShape(QFrame::StyledPanel);
        frame_lcdoff->setFrameShadow(QFrame::Raised);
        label_lcdoff = new QLabel(frame_lcdoff);
        label_lcdoff->setObjectName(QStringLiteral("label_lcdoff"));
        label_lcdoff->setGeometry(QRect(0, 0, 221, 44));
        label_lcdoff->setFont(font4);
        label_lcdoff->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_lcdoff->setAlignment(Qt::AlignCenter);
        label_lcdoff_2 = new QLabel(frame_lcdoff);
        label_lcdoff_2->setObjectName(QStringLiteral("label_lcdoff_2"));
        label_lcdoff_2->setGeometry(QRect(229, 2, 40, 40));
        label_lcdoff_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        listWidget_poweroff = new QListWidget(tab_4);
        new QListWidgetItem(listWidget_poweroff);
        new QListWidgetItem(listWidget_poweroff);
        new QListWidgetItem(listWidget_poweroff);
        new QListWidgetItem(listWidget_poweroff);
        new QListWidgetItem(listWidget_poweroff);
        new QListWidgetItem(listWidget_poweroff);
        new QListWidgetItem(listWidget_poweroff);
        new QListWidgetItem(listWidget_poweroff);
        listWidget_poweroff->setObjectName(QStringLiteral("listWidget_poweroff"));
        listWidget_poweroff->setGeometry(QRect(500, 180, 181, 161));
        listWidget_poweroff->setFont(font4);
        listWidget_poweroff->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"	\n"
"	background-image: url(:/res/res/setting_background.png);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:#32CC99;\n"
"	width:25px;\n"
"	margin:25 0 25 0px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\350\256\276\347\275\256 */\n"
"QScrollBar::handle:vertical {\n"
"/*	background-color:#7CA6C9;*/	\n"
"	background-color: rgb(83, 166, 249);\n"
"	border:1px solid #7CA6C9;\n"
"	height:30px;\n"
"	max-height:20px;\n"
"}\n"
"\n"
"/* \345\272\225\351\203\250\346\216\247\345\210\266\345\235\227 */\n"
"QScrollBar::add-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:transparent;\n"
"	width:25px;\n"
"	height:25px;\n"
"	subcontrol-position:bottom;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_down_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \351\241\266\351\203\250\346\216\247\345\210\266\345\235\227 */\n"
"QScrollBar::sub-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
""
                        "	background-color:transparent;\n"
"	width:25px;\n"
"	height:25px;\n"
"	subcontrol-position:top;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_up_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \346\216\247\345\210\266\345\235\227\344\270\212\347\232\204\345\260\217\347\256\255\345\244\264 */\n"
"QScrollBar::up-arrow:vertical,QScrollBar::down-arrow:vertical {\n"
"	border:0px;\n"
"	width:25px;\n"
"	height:25px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\212\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::add-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\213\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::sub-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
""));
        listWidget_lcdoff = new QListWidget(tab_4);
        new QListWidgetItem(listWidget_lcdoff);
        new QListWidgetItem(listWidget_lcdoff);
        new QListWidgetItem(listWidget_lcdoff);
        new QListWidgetItem(listWidget_lcdoff);
        new QListWidgetItem(listWidget_lcdoff);
        new QListWidgetItem(listWidget_lcdoff);
        new QListWidgetItem(listWidget_lcdoff);
        new QListWidgetItem(listWidget_lcdoff);
        listWidget_lcdoff->setObjectName(QStringLiteral("listWidget_lcdoff"));
        listWidget_lcdoff->setGeometry(QRect(620, 90, 181, 161));
        listWidget_lcdoff->setFont(font4);
        listWidget_lcdoff->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"	\n"
"	background-image: url(:/res/res/setting_background.png);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:#32CC99;\n"
"	width:25px;\n"
"	margin:25 0 25 0px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\350\256\276\347\275\256 */\n"
"QScrollBar::handle:vertical {\n"
"/*	background-color:#7CA6C9;*/	\n"
"	background-color: rgb(83, 166, 249);\n"
"	border:1px solid #7CA6C9;\n"
"	height:30px;\n"
"	max-height:20px;\n"
"}\n"
"\n"
"/* \345\272\225\351\203\250\346\216\247\345\210\266\345\235\227 */\n"
"QScrollBar::add-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:transparent;\n"
"	width:25px;\n"
"	height:25px;\n"
"	subcontrol-position:bottom;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_down_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \351\241\266\351\203\250\346\216\247\345\210\266\345\235\227 */\n"
"QScrollBar::sub-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
""
                        "	background-color:transparent;\n"
"	width:25px;\n"
"	height:25px;\n"
"	subcontrol-position:top;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_up_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \346\216\247\345\210\266\345\235\227\344\270\212\347\232\204\345\260\217\347\256\255\345\244\264 */\n"
"QScrollBar::up-arrow:vertical,QScrollBar::down-arrow:vertical {\n"
"	border:0px;\n"
"	width:25px;\n"
"	height:25px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\212\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::add-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\213\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::sub-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
""));
        label_25 = new QLabel(tab_4);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(1300, 380, 168, 65));
        label_25->setMinimumSize(QSize(0, 0));
        label_25->setMaximumSize(QSize(16777215, 16777215));
        label_25->setFont(font7);
        label_25->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_3 = new QPushButton(tab_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(131, 343, 371, 45));
        pushButton_3->setMinimumSize(QSize(0, 0));
        pushButton_3->setMaximumSize(QSize(16777215, 16777215));
        pushButton_3->setFont(font7);
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        pushButton_3->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image:url(:/res/res/button_n.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
"QPushButton:pressed{\n"
"border-image:url(:/res/res/setting_selected.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
""));
        pushButton_3->setAutoDefault(false);
        pushButton_3->setFlat(true);
        label_49 = new QLabel(tab_4);
        label_49->setObjectName(QStringLiteral("label_49"));
        label_49->setGeometry(QRect(83, 282, 138, 45));
        label_49->setMinimumSize(QSize(0, 0));
        label_49->setMaximumSize(QSize(16777215, 16777215));
        label_49->setFont(font4);
        label_49->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_49->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_hotkey = new QPushButton(tab_4);
        pushButton_hotkey->setObjectName(QStringLiteral("pushButton_hotkey"));
        pushButton_hotkey->setEnabled(true);
        pushButton_hotkey->setGeometry(QRect(234, 282, 261, 45));
        pushButton_hotkey->setFont(font7);
        pushButton_hotkey->setFocusPolicy(Qt::NoFocus);
        pushButton_hotkey->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image:url(:/res/res/button_n.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
"QPushButton:pressed{\n"
"border-image:url(:/res/res/setting_selected.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
""));
        pushButton_hotkey->setFlat(true);
        tabWidget->addTab(tab_4, QString());
        pushButton_default->raise();
        dateTimeEdit->raise();
        label_23->raise();
        label_22->raise();
        auto_poweroff->raise();
        auto_lcdoff->raise();
        comboBox_language->raise();
        frame_language->raise();
        frame_poweroff->raise();
        frame_lcdoff->raise();
        listWidget_language->raise();
        listWidget_poweroff->raise();
        listWidget_lcdoff->raise();
        label_25->raise();
        pushButton_3->raise();
        label_49->raise();
        pushButton_hotkey->raise();
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        QFont font12;
        font12.setPointSize(9);
        tab_5->setFont(font12);
        label_yiqibianhao = new QLabel(tab_5);
        label_yiqibianhao->setObjectName(QStringLiteral("label_yiqibianhao"));
        label_yiqibianhao->setGeometry(QRect(66, 210, 168, 31));
        label_yiqibianhao->setFont(font7);
        label_yiqibianhao->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_shengchanriqi = new QLabel(tab_5);
        label_shengchanriqi->setObjectName(QStringLiteral("label_shengchanriqi"));
        label_shengchanriqi->setGeometry(QRect(62, 330, 168, 31));
        label_shengchanriqi->setFont(font7);
        label_shengchanriqi->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_ruanjianbanben = new QLabel(tab_5);
        label_ruanjianbanben->setObjectName(QStringLiteral("label_ruanjianbanben"));
        label_ruanjianbanben->setGeometry(QRect(62, 250, 168, 31));
        label_ruanjianbanben->setFont(font7);
        label_ruanjianbanben->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_yiqixinghao = new QLabel(tab_5);
        label_yiqixinghao->setObjectName(QStringLiteral("label_yiqixinghao"));
        label_yiqixinghao->setGeometry(QRect(66, 170, 168, 31));
        label_yiqixinghao->setFont(font7);
        label_yiqixinghao->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_xinghao_text = new QLabel(tab_5);
        label_xinghao_text->setObjectName(QStringLiteral("label_xinghao_text"));
        label_xinghao_text->setGeometry(QRect(234, 170, 218, 31));
        label_xinghao_text->setFont(font7);
        label_xinghao_text->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_bianhao_text = new QLabel(tab_5);
        label_bianhao_text->setObjectName(QStringLiteral("label_bianhao_text"));
        label_bianhao_text->setGeometry(QRect(234, 210, 218, 31));
        label_bianhao_text->setFont(font7);
        label_bianhao_text->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_banben_text = new QLabel(tab_5);
        label_banben_text->setObjectName(QStringLiteral("label_banben_text"));
        label_banben_text->setGeometry(QRect(230, 250, 218, 31));
        label_banben_text->setFont(font7);
        label_banben_text->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_riqi_text = new QLabel(tab_5);
        label_riqi_text->setObjectName(QStringLiteral("label_riqi_text"));
        label_riqi_text->setGeometry(QRect(230, 330, 218, 31));
        label_riqi_text->setFont(font7);
        label_riqi_text->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        hp_logo = new hp_button(tab_5);
        hp_logo->setObjectName(QStringLiteral("hp_logo"));
        hp_logo->setGeometry(QRect(100, 100, 318, 60));
        hp_logo->setMinimumSize(QSize(318, 60));
        hp_logo->setMaximumSize(QSize(318, 60));
        hp_logo->setStyleSheet(QStringLiteral("border-image:url(hp_logo);"));
        label_gujianbanben = new QLabel(tab_5);
        label_gujianbanben->setObjectName(QStringLiteral("label_gujianbanben"));
        label_gujianbanben->setGeometry(QRect(66, 290, 168, 31));
        label_gujianbanben->setFont(font7);
        label_gujianbanben->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_gujianbanben->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_gujianbanben_text = new QLabel(tab_5);
        label_gujianbanben_text->setObjectName(QStringLiteral("label_gujianbanben_text"));
        label_gujianbanben_text->setGeometry(QRect(234, 290, 260, 31));
        label_gujianbanben_text->setFont(font7);
        label_gujianbanben_text->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        tabWidget->addTab(tab_5, QString());
        frame_other = new QFrame(HpSetting);
        frame_other->setObjectName(QStringLiteral("frame_other"));
        frame_other->setGeometry(QRect(0, 240, 96, 32));
        frame_other->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        frame_other->setFrameShape(QFrame::StyledPanel);
        frame_other->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_other);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 96, 40));
        label->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));

        retranslateUi(HpSetting);
        QObject::connect(checkBox_ble, SIGNAL(clicked(bool)), ble_edit, SLOT(setVisible(bool)));

        tabWidget->setCurrentIndex(4);
        comboBox_jingtou->setCurrentIndex(-1);
        comboBox_usbmode->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HpSetting);
    } // setupUi

    void retranslateUi(QWidget *HpSetting)
    {
        HpSetting->setWindowTitle(QApplication::translate("HpSetting", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("HpSetting", "back", nullptr));
        ScrollBar_Distance->setPrefix(QApplication::translate("HpSetting", "\350\267\235\347\246\273:", nullptr));
        ScrollBar_Distance->setSuffix(QApplication::translate("HpSetting", "m", nullptr));
        checkBox_ReferTemp_enable->setText(QString());
        ScrollBar_Humidity->setSuffix(QApplication::translate("HpSetting", "%", nullptr));
        ScrollBar_Humidity->setPrefix(QApplication::translate("HpSetting", "\347\233\270\345\257\271\346\271\277\345\272\246:", nullptr));
        ScrollBar_transmission->setSuffix(QApplication::translate("HpSetting", "%", nullptr));
        ScrollBar_transmission->setPrefix(QApplication::translate("HpSetting", "\347\252\227\345\217\243\351\200\217\350\277\207\347\216\207:", nullptr));
        ScrollBar_ReflectTemp->setPrefix(QApplication::translate("HpSetting", "\345\217\215\345\260\204\346\270\251\345\272\246:", "1"));
        ScrollBar_Radiance->setSuffix(QApplication::translate("HpSetting", "%", nullptr));
        ScrollBar_Radiance->setPrefix(QApplication::translate("HpSetting", "\350\276\220\345\260\204\347\216\207:", nullptr));
        ScrollBar_ReferTemp->setPrefix(QApplication::translate("HpSetting", "\345\217\202\350\200\203\346\270\251\345\272\246:", nullptr));
        ScrollBar_TempUnit->setPrefix(QApplication::translate("HpSetting", "\346\270\251\345\272\246\345\215\225\344\275\215:", nullptr));
        ScrollBar_AmbientTempManu->setPrefix(QApplication::translate("HpSetting", "\347\216\257\345\242\203\346\270\251\345\272\246:", nullptr));
        ScrollBar_AmbientTempManu->setSuffix(QString());
        label_Radiance->setText(QApplication::translate("HpSetting", "\350\276\220\345\260\204\347\261\273\345\236\213\357\274\232\350\276\220\345\260\204\347\216\207", nullptr));
        label_Radiance_2->setText(QString());
        checkBox_Radiance->setText(QString());

        const bool __sortingEnabled = listWidget_Radiance->isSortingEnabled();
        listWidget_Radiance->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_Radiance->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("HpSetting", "\346\260\264:            0.96", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_Radiance->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("HpSetting", "\347\232\256\350\202\244:         0.80", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_Radiance->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("HpSetting", "\351\231\266\347\223\267(\347\273\206):    0.90", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_Radiance->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("HpSetting", "\351\231\266\347\223\267(\347\262\227):    0.93", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_Radiance->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("HpSetting", "\351\223\235:             0.20", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_Radiance->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("HpSetting", "\351\223\235(\346\260\247\345\214\226):    0.55", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_Radiance->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("HpSetting", "\351\273\204\351\223\234:          0.22", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_Radiance->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("HpSetting", "\351\273\204\351\223\234(\346\260\247\345\214\226): 0.61", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_Radiance->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("HpSetting", "\351\223\234(\346\267\261\345\272\246\346\260\247\345\214\226):0.78", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget_Radiance->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("HpSetting", "\351\223\201(\346\260\247\345\214\226):    0.74", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = listWidget_Radiance->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("HpSetting", "\351\223\201(\347\224\237\351\224\210):    0.65", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = listWidget_Radiance->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("HpSetting", "\351\223\270\351\223\201(\346\260\247\345\214\226): 0.64 ", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = listWidget_Radiance->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("HpSetting", "\351\223\270\351\223\201:          0.21", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = listWidget_Radiance->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("HpSetting", "\351\225\215(\346\260\247\345\214\226):    0.37", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = listWidget_Radiance->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("HpSetting", "\351\222\242(\346\260\247\345\214\226):    0.79", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = listWidget_Radiance->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("HpSetting", "\344\270\215\351\224\210\351\222\242(\346\260\247\345\214\226):0.85", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = listWidget_Radiance->item(16);
        ___qlistwidgetitem16->setText(QApplication::translate("HpSetting", "\347\242\263(\347\203\237\345\260\230):    0.95", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = listWidget_Radiance->item(17);
        ___qlistwidgetitem17->setText(QApplication::translate("HpSetting", "\347\242\263(\347\237\263\345\242\250):    0.98", nullptr));
        QListWidgetItem *___qlistwidgetitem18 = listWidget_Radiance->item(18);
        ___qlistwidgetitem18->setText(QApplication::translate("HpSetting", "\346\274\206(\347\231\275\350\211\262):    0.92", nullptr));
        QListWidgetItem *___qlistwidgetitem19 = listWidget_Radiance->item(19);
        ___qlistwidgetitem19->setText(QApplication::translate("HpSetting", "\346\274\206(\351\273\221\350\211\262):    0.97", nullptr));
        QListWidgetItem *___qlistwidgetitem20 = listWidget_Radiance->item(20);
        ___qlistwidgetitem20->setText(QApplication::translate("HpSetting", "\346\262\271\346\274\206:         0.94", nullptr));
        QListWidgetItem *___qlistwidgetitem21 = listWidget_Radiance->item(21);
        ___qlistwidgetitem21->setText(QApplication::translate("HpSetting", "\347\272\270:             0.93", nullptr));
        QListWidgetItem *___qlistwidgetitem22 = listWidget_Radiance->item(22);
        ___qlistwidgetitem22->setText(QApplication::translate("HpSetting", "\346\262\231\345\234\237:          0.90", nullptr));
        QListWidgetItem *___qlistwidgetitem23 = listWidget_Radiance->item(23);
        ___qlistwidgetitem23->setText(QApplication::translate("HpSetting", "\346\267\267\345\207\235\345\234\237:       0.92", nullptr));
        listWidget_Radiance->setSortingEnabled(__sortingEnabled);

        label_ReflectTemp->setText(QApplication::translate("HpSetting", "\345\217\215\345\260\204\347\261\273\345\236\213\357\274\232\346\234\200\351\253\230\346\270\251\345\272\246", nullptr));
        label_ReflectTemp_2->setText(QString());

        const bool __sortingEnabled1 = listWidget_ReflectTemp->isSortingEnabled();
        listWidget_ReflectTemp->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem24 = listWidget_ReflectTemp->item(0);
        ___qlistwidgetitem24->setText(QApplication::translate("HpSetting", "\346\234\200\351\253\230\346\270\251\345\272\246", nullptr));
        QListWidgetItem *___qlistwidgetitem25 = listWidget_ReflectTemp->item(1);
        ___qlistwidgetitem25->setText(QApplication::translate("HpSetting", "\346\234\200\344\275\216\346\270\251\345\272\246", nullptr));
        QListWidgetItem *___qlistwidgetitem26 = listWidget_ReflectTemp->item(2);
        ___qlistwidgetitem26->setText(QApplication::translate("HpSetting", "\345\271\263\345\235\207\346\270\251\345\272\246", nullptr));
        listWidget_ReflectTemp->setSortingEnabled(__sortingEnabled1);

        checkBox_ReflectTemp_enable->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("HpSetting", "\346\270\251\345\272\246\344\277\256\346\255\243", nullptr));
        label_13->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\346\212\245\350\255\246\350\256\276\347\275\256</p></body></html>", nullptr));
        label_10->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\346\265\213\346\270\251\346\241\243\344\275\215</p></body></html>", nullptr));
        label_11->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\350\207\252\345\212\250\345\210\207\346\215\242</p></body></html>", nullptr));
        comboBox_baojingshezhi->setItemText(0, QApplication::translate("HpSetting", "\345\205\263\351\227\255", nullptr));
        comboBox_baojingshezhi->setItemText(1, QApplication::translate("HpSetting", "\346\234\200\351\253\230\346\270\251", nullptr));
        comboBox_baojingshezhi->setItemText(2, QApplication::translate("HpSetting", "\346\234\200\344\275\216\346\270\251", nullptr));

        label_15->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\346\212\245\350\255\246\351\242\234\350\211\262</p></body></html>", nullptr));
        comboBox_baojingse->setItemText(0, QApplication::translate("HpSetting", "\350\207\252\345\212\250", nullptr));
        comboBox_baojingse->setItemText(1, QApplication::translate("HpSetting", "\347\272\242\350\211\262", nullptr));
        comboBox_baojingse->setItemText(2, QApplication::translate("HpSetting", "\346\251\231\350\211\262", nullptr));
        comboBox_baojingse->setItemText(3, QApplication::translate("HpSetting", "\351\273\204\350\211\262", nullptr));
        comboBox_baojingse->setItemText(4, QApplication::translate("HpSetting", "\347\273\277\350\211\262", nullptr));
        comboBox_baojingse->setItemText(5, QApplication::translate("HpSetting", "\351\273\221\350\211\262", nullptr));
        comboBox_baojingse->setItemText(6, QApplication::translate("HpSetting", "\347\201\260\350\211\262", nullptr));
        comboBox_baojingse->setItemText(7, QApplication::translate("HpSetting", "\347\264\253\350\211\262", nullptr));
        comboBox_baojingse->setItemText(8, QApplication::translate("HpSetting", "\350\223\235\350\211\262", nullptr));
        comboBox_baojingse->setItemText(9, QApplication::translate("HpSetting", "\347\231\275\350\211\262", nullptr));

        label_9->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\344\273\252\345\231\250\351\225\234\345\244\264</p></body></html>", nullptr));
        cwfw_autorectify->setSpecialValueText(QApplication::translate("HpSetting", "\350\207\252\345\212\250\346\240\241\346\255\243\351\227\264\351\232\224\357\274\232\345\205\263\351\227\255", nullptr));
        cwfw_autorectify->setSuffix(QApplication::translate("HpSetting", " s", nullptr));
        cwfw_autorectify->setPrefix(QApplication::translate("HpSetting", "\350\207\252\345\212\250\346\240\241\346\255\243\351\227\264\351\232\224:", nullptr));
        label_jingtou->setText(QApplication::translate("HpSetting", "\351\225\234\345\244\264", nullptr));
        label_jingtou_2->setText(QString());
        label_wendang->setText(QApplication::translate("HpSetting", "\346\270\251\346\241\243", nullptr));
        label_wendang_2->setText(QString());

        const bool __sortingEnabled2 = listWidget_baojingshezhi->isSortingEnabled();
        listWidget_baojingshezhi->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem27 = listWidget_baojingshezhi->item(0);
        ___qlistwidgetitem27->setText(QApplication::translate("HpSetting", "\345\205\263\351\227\255", nullptr));
        QListWidgetItem *___qlistwidgetitem28 = listWidget_baojingshezhi->item(1);
        ___qlistwidgetitem28->setText(QApplication::translate("HpSetting", "\346\234\200\351\253\230\346\270\251", nullptr));
        QListWidgetItem *___qlistwidgetitem29 = listWidget_baojingshezhi->item(2);
        ___qlistwidgetitem29->setText(QApplication::translate("HpSetting", "\346\234\200\344\275\216\346\270\251", nullptr));
        listWidget_baojingshezhi->setSortingEnabled(__sortingEnabled2);


        const bool __sortingEnabled3 = listWidget_baojingse->isSortingEnabled();
        listWidget_baojingse->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem30 = listWidget_baojingse->item(0);
        ___qlistwidgetitem30->setText(QApplication::translate("HpSetting", "\350\207\252\345\212\250", nullptr));
        QListWidgetItem *___qlistwidgetitem31 = listWidget_baojingse->item(1);
        ___qlistwidgetitem31->setText(QApplication::translate("HpSetting", "\347\272\242\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem32 = listWidget_baojingse->item(2);
        ___qlistwidgetitem32->setText(QApplication::translate("HpSetting", "\346\251\231\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem33 = listWidget_baojingse->item(3);
        ___qlistwidgetitem33->setText(QApplication::translate("HpSetting", "\351\273\204\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem34 = listWidget_baojingse->item(4);
        ___qlistwidgetitem34->setText(QApplication::translate("HpSetting", "\347\273\277\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem35 = listWidget_baojingse->item(5);
        ___qlistwidgetitem35->setText(QApplication::translate("HpSetting", "\351\273\221\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem36 = listWidget_baojingse->item(6);
        ___qlistwidgetitem36->setText(QApplication::translate("HpSetting", "\347\201\260\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem37 = listWidget_baojingse->item(7);
        ___qlistwidgetitem37->setText(QApplication::translate("HpSetting", "\347\264\253\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem38 = listWidget_baojingse->item(8);
        ___qlistwidgetitem38->setText(QApplication::translate("HpSetting", "\350\223\235\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem39 = listWidget_baojingse->item(9);
        ___qlistwidgetitem39->setText(QApplication::translate("HpSetting", "\347\231\275\350\211\262", nullptr));
        listWidget_baojingse->setSortingEnabled(__sortingEnabled3);

        label_bangjingshehzi->setText(QApplication::translate("HpSetting", "\346\212\245\350\255\246\350\256\276\347\275\256", nullptr));
        label_bangjingshehzi_2->setText(QString());
        label_baojingse->setText(QApplication::translate("HpSetting", "\346\212\245\350\255\246\351\242\234\350\211\262", nullptr));
        label_baojingse_2->setText(QString());
        pushButton_qiehuan->setText(QApplication::translate("HpSetting", "OK", nullptr));
        comboBox_baojingwendu->setPrefix(QApplication::translate("HpSetting", "\346\212\245\350\255\246\346\270\251\345\272\246:", nullptr));
        label_20->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\351\253\230\344\275\216\346\270\251\346\215\225\346\215\211</p></body></html>", nullptr));
        checkBox_Catch->setText(QString());
        comboBox_buchangwendu->setPrefix(QApplication::translate("HpSetting", "\350\241\245\345\201\277\346\270\251\345\272\246:", nullptr));
        label_30->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\347\255\211\346\270\251\350\211\262</p></body></html>", nullptr));
        dengwengse_edit->setText(QApplication::translate("HpSetting", "\350\256\276\347\275\256", nullptr));
        comboBox_baojingjuli->setPrefix(QApplication::translate("HpSetting", "\346\212\245\350\255\246\350\267\235\347\246\273:", nullptr));
        comboBox_baojingjuli->setSuffix(QApplication::translate("HpSetting", "m", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("HpSetting", "\346\265\213\346\270\251\350\214\203\345\233\264", nullptr));
        spinBox_autosave->setSpecialValueText(QApplication::translate("HpSetting", "\345\205\263\351\227\255", nullptr));
        spinBox_autosave->setSuffix(QApplication::translate("HpSetting", " s", nullptr));
        label_24->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\350\207\252\345\212\250\345\255\230\345\202\250</p></body></html>", nullptr));
        comboBox_usbmode->setItemText(0, QApplication::translate("HpSetting", "\350\247\206\351\242\221\344\274\240\350\276\223", nullptr));
        comboBox_usbmode->setItemText(1, QApplication::translate("HpSetting", "\345\244\247\345\256\271\351\207\217\345\255\230\345\202\250", nullptr));

        label_19->setText(QApplication::translate("HpSetting", "<html><head/><body><p>USB\346\250\241\345\274\217</p></body></html>", nullptr));
        label_usbmode->setText(QApplication::translate("HpSetting", "\350\247\206\351\242\221\344\274\240\350\276\223", nullptr));
        label_usbmode_2->setText(QString());

        const bool __sortingEnabled4 = listWidget_usbmode->isSortingEnabled();
        listWidget_usbmode->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem40 = listWidget_usbmode->item(0);
        ___qlistwidgetitem40->setText(QApplication::translate("HpSetting", "\350\247\206\351\242\221\344\274\240\350\276\223", nullptr));
        QListWidgetItem *___qlistwidgetitem41 = listWidget_usbmode->item(1);
        ___qlistwidgetitem41->setText(QApplication::translate("HpSetting", "\345\244\247\345\256\271\351\207\217\345\255\230\345\202\250", nullptr));
        listWidget_usbmode->setSortingEnabled(__sortingEnabled4);

        label_29->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\345\275\225\345\210\266\346\250\241\345\274\217</p></body></html>", nullptr));
        label_recordmode->setText(QApplication::translate("HpSetting", "\350\247\206\351\242\221\346\265\201", nullptr));
        label_recordmode_2->setText(QString());

        const bool __sortingEnabled5 = listWidget_recordmode->isSortingEnabled();
        listWidget_recordmode->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem42 = listWidget_recordmode->item(0);
        ___qlistwidgetitem42->setText(QApplication::translate("HpSetting", "\350\247\206\351\242\221\346\265\201", nullptr));
        QListWidgetItem *___qlistwidgetitem43 = listWidget_recordmode->item(1);
        ___qlistwidgetitem43->setText(QApplication::translate("HpSetting", "\350\276\220\345\260\204\346\265\201", nullptr));
        listWidget_recordmode->setSortingEnabled(__sortingEnabled5);

        label_modeSelect->setText(QApplication::translate("HpSetting", "\346\227\240", nullptr));
        label_modeSelect_2->setText(QString());

        const bool __sortingEnabled6 = listWidget_modeSelect->isSortingEnabled();
        listWidget_modeSelect->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem44 = listWidget_modeSelect->item(0);
        ___qlistwidgetitem44->setText(QApplication::translate("HpSetting", "\345\270\270\350\247\204", nullptr));
        QListWidgetItem *___qlistwidgetitem45 = listWidget_modeSelect->item(1);
        ___qlistwidgetitem45->setText(QApplication::translate("HpSetting", "\344\275\234\344\270\232", nullptr));
        listWidget_modeSelect->setSortingEnabled(__sortingEnabled6);

        label_32->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\345\267\245\344\275\234\346\250\241\345\274\217</p></body></html>", nullptr));
        label_16->setText(QApplication::translate("HpSetting", "<html><head/><body><p>WIFI</p></body></html>", nullptr));
        label_21->setText(QApplication::translate("HpSetting", "<html><head/><body><p>area</p></body></html>", nullptr));
        label_26->setText(QApplication::translate("HpSetting", "<html><head/><body><p>SR</p></body></html>", nullptr));
        label_18->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\350\223\235\347\211\231</p></body></html>", nullptr));
        checkBox_ble->setText(QString());
        checkBox_area->setText(QString());
        buguangdeng->setText(QString());
        checkBox_sr->setText(QString());
        label_17->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\350\241\245\345\205\211\347\201\257</p></body></html>", nullptr));
        label_27->setText(QApplication::translate("HpSetting", "<html><head/><body><p>FID</p></body></html>", nullptr));
        label_28->setText(QApplication::translate("HpSetting", "<html><head/><body><p>PID</p></body></html>", nullptr));
        checkBox_fid->setText(QString());
        checkBox_pid->setText(QString());
        label_31->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\350\207\252\345\212\250\344\270\212\344\274\240</p></body></html>", nullptr));
        checkBox_autoUpload->setText(QString());
        ble_edit->setText(QApplication::translate("HpSetting", "\350\256\276\347\275\256", nullptr));
        wifi_edit->setText(QApplication::translate("HpSetting", "\350\256\276\347\275\256", nullptr));
        autoUpload_edit->setText(QApplication::translate("HpSetting", "\350\256\276\347\275\256", nullptr));
        btautoUpload_once->setText(QApplication::translate("HpSetting", "\344\270\200\351\224\256\344\270\212\344\274\240", nullptr));
        btdownload->setText(QApplication::translate("HpSetting", "\346\226\207\344\273\266\344\270\213\350\275\275", nullptr));
        checkBox_wifi->setText(QString());
        label_33->setText(QApplication::translate("HpSetting", "<html><head/><body><p>HDMI</p></body></html>", nullptr));
        checkBox_hdmi->setText(QString());
        checkBox_sis->setText(QString());
        label_34->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\346\211\253\344\270\200\346\211\253</p></body></html>", nullptr));
        label_35->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\351\253\230\346\270\251\345\256\232\345\210\266</p></body></html>", nullptr));
        checkBox_mulhom->setText(QString());
        mulhom_edit->setText(QApplication::translate("HpSetting", "\350\256\276\347\275\256", nullptr));
        checkBox_gw->setText(QString());
        label_36->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\345\233\275\347\275\221\346\250\241\345\274\217</p></body></html>", nullptr));
        checkBox_angel->setText(QApplication::translate("HpSetting", "\350\247\222\345\272\246\350\276\205\345\212\251", nullptr));
        checkBox_volume->setText(QApplication::translate("HpSetting", "\344\275\223\347\247\257\346\265\213\347\256\227", nullptr));
        label_37->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\345\205\250\346\231\257\346\213\274\346\216\245</p></body></html>", nullptr));
        checkBox_panorama->setText(QString());
        checkBox_zoomSave->setText(QString());
        label_39->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\345\216\237\345\233\276</p></body></html>", nullptr));
        checkBox_oritoggle->setText(QString());
        label_40->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\344\270\244\347\202\271\345\210\207\346\215\242</p></body></html>", nullptr));
        checkBox_homogeneity->setText(QString());
        label_41->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\345\235\207\345\214\200\346\200\247</p></body></html>", nullptr));
        label_42->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\351\230\266\346\242\257\350\260\203\351\233\266</p></body></html>", nullptr));
        checkBox_stepZero->setText(QString());
        label_43->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">4G</p></body></html>", nullptr));
        checkBox_4G->setText(QString());
        label_44->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\346\214\207\345\215\227\351\222\210</p></body></html>", nullptr));
        checkBox_compass->setText(QString());
        calbration_edit->setText(QApplication::translate("HpSetting", "\346\240\241\345\207\206", nullptr));
        checkBox_GPS->setText(QString());
        label_46->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\345\214\227\346\226\227\345\256\232\344\275\215</p></body></html>", nullptr));
        label_47->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\345\271\263\345\235\207\346\270\251\345\272\246</p></body></html>", nullptr));
        checkBox_avgTemp->setText(QString());
        label_48->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\346\211\213\345\212\250\346\240\241\345\207\206</p></body></html>", nullptr));
        checkBox_nonCool->setText(QString());
        checkBox_eth->setText(QString());
        label_50->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">ETH</p></body></html>", nullptr));
        label_51->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\350\215\211\345\233\276</p></body></html>", nullptr));
        checkBox_sketch->setText(QString());
        sketch_edit->setText(QApplication::translate("HpSetting", "\346\270\205\347\251\272", nullptr));
        label_52->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\351\207\215\345\212\233\346\204\237\345\272\224</p></body></html>", nullptr));
        checkBox_flip->setText(QString());
        checkBox_transmission->setText(QString());
        label_53->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\345\270\246\347\224\265\346\243\200\346\265\213</p></body></html>", nullptr));
        trmission_edit->setText(QApplication::translate("HpSetting", "\350\256\276\347\275\256", nullptr));
        checkBox_bmp->setText(QString());
        label_54->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">BMP</p></body></html>", nullptr));
        checkBox_contrustFocus->setText(QString());
        label_55->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\350\277\236\347\273\255\350\207\252\345\212\250\350\201\232\347\204\246</p></body></html>", nullptr));
        checkBox_brightness->setText(QString());
        label_56->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\347\231\275\346\230\274\346\250\241\345\274\217</p></body></html>", nullptr));
        label_57->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\350\207\252\345\212\250\350\257\206\345\210\253</p></body></html>", nullptr));
        checkBox_autoReg->setText(QString());
        label_58->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\351\242\204\350\256\276\346\250\241\345\274\2171</p></body></html>", nullptr));
        checkBox_preset1->setText(QString());
        checkBox_preset2->setText(QString());
        label_59->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\351\242\204\350\256\276\346\250\241\345\274\2172</p></body></html>", nullptr));
        label_scroll->setText(QString());

        const bool __sortingEnabled7 = listWidget_focusmode->isSortingEnabled();
        listWidget_focusmode->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem46 = listWidget_focusmode->item(0);
        ___qlistwidgetitem46->setText(QApplication::translate("HpSetting", "\345\233\276\345\203\217\350\207\252\345\212\250\350\201\232\347\204\246", nullptr));
        QListWidgetItem *___qlistwidgetitem47 = listWidget_focusmode->item(1);
        ___qlistwidgetitem47->setText(QApplication::translate("HpSetting", "\346\277\200\345\205\211\350\276\205\345\212\251\350\207\252\345\212\250\350\201\232\347\204\246", nullptr));
        QListWidgetItem *___qlistwidgetitem48 = listWidget_focusmode->item(2);
        ___qlistwidgetitem48->setText(QApplication::translate("HpSetting", "\345\233\276\345\203\217\345\277\253\351\200\237\350\201\232\347\204\246", nullptr));
        listWidget_focusmode->setSortingEnabled(__sortingEnabled7);

        label_focusmode->setText(QApplication::translate("HpSetting", "\345\233\276\345\203\217\350\207\252\345\212\250\350\201\232\347\204\246", nullptr));
        label_focusmode_2->setText(QString());
        label_45->setText(QApplication::translate("HpSetting", "\350\201\232\347\204\246\346\250\241\345\274\217", nullptr));
        label__imageType->setText(QApplication::translate("HpSetting", "\346\227\240", nullptr));
        label__imageType_2->setText(QString());

        const bool __sortingEnabled8 = listWidget_imageType->isSortingEnabled();
        listWidget_imageType->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem49 = listWidget_imageType->item(0);
        ___qlistwidgetitem49->setText(QApplication::translate("HpSetting", "\346\227\240", nullptr));
        QListWidgetItem *___qlistwidgetitem50 = listWidget_imageType->item(1);
        ___qlistwidgetitem50->setText(QApplication::translate("HpSetting", "\345\244\215\345\220\210\350\260\203\350\211\262\350\201\232\347\204\246\346\210\220\345\203\217", nullptr));
        QListWidgetItem *___qlistwidgetitem51 = listWidget_imageType->item(2);
        ___qlistwidgetitem51->setText(QApplication::translate("HpSetting", "\351\253\230\346\270\251\345\267\256\345\235\207\350\241\241\346\210\220\345\203\217", nullptr));
        listWidget_imageType->setSortingEnabled(__sortingEnabled8);

        label_38->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\346\210\220\345\203\217\346\250\241\345\274\217</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("HpSetting", "\344\273\252\345\231\250\350\256\276\347\275\256", nullptr));
        pushButton_default->setText(QApplication::translate("HpSetting", "\351\207\215\347\275\256", nullptr));
        comboBox_language->setItemText(0, QApplication::translate("HpSetting", "\344\270\255\346\226\207\347\256\200\344\275\223", nullptr));
        comboBox_language->setItemText(1, QApplication::translate("HpSetting", "\344\270\255\346\226\207\347\271\201\351\253\224", nullptr));
        comboBox_language->setItemText(2, QApplication::translate("HpSetting", "English", nullptr));
        comboBox_language->setItemText(3, QApplication::translate("HpSetting", "\320\240\320\243\320\241\320\241\320\232\320\230\320\231 ", nullptr));
        comboBox_language->setItemText(4, QApplication::translate("HpSetting", "Magyar", nullptr));
        comboBox_language->setItemText(5, QApplication::translate("HpSetting", "Espa\303\261ol", nullptr));

        dateTimeEdit->setDisplayFormat(QApplication::translate("HpSetting", "yyyy - MM - dd hh : mm : ss", nullptr));
        auto_lcdoff->setItemText(0, QApplication::translate("HpSetting", "\346\227\240", nullptr));
        auto_lcdoff->setItemText(1, QApplication::translate("HpSetting", "5\345\210\206\351\222\237", nullptr));
        auto_lcdoff->setItemText(2, QApplication::translate("HpSetting", "10\345\210\206\351\222\237", nullptr));
        auto_lcdoff->setItemText(3, QApplication::translate("HpSetting", "30\345\210\206\351\222\237", nullptr));

        label_23->setText(QApplication::translate("HpSetting", "\350\207\252\345\212\250\345\205\263\345\261\217", nullptr));
        label_22->setText(QApplication::translate("HpSetting", "\350\207\252\345\212\250\345\205\263\346\234\272", nullptr));
        auto_poweroff->setItemText(0, QApplication::translate("HpSetting", "\346\227\240", nullptr));
        auto_poweroff->setItemText(1, QApplication::translate("HpSetting", "5\345\210\206\351\222\237", nullptr));
        auto_poweroff->setItemText(2, QApplication::translate("HpSetting", "10\345\210\206\351\222\237", nullptr));
        auto_poweroff->setItemText(3, QApplication::translate("HpSetting", "30\345\210\206\351\222\237", nullptr));

        label_language->setText(QString());
        label_language2->setText(QString());

        const bool __sortingEnabled9 = listWidget_language->isSortingEnabled();
        listWidget_language->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem52 = listWidget_language->item(0);
        ___qlistwidgetitem52->setText(QApplication::translate("HpSetting", "\344\270\255\346\226\207\347\256\200\344\275\223", nullptr));
        QListWidgetItem *___qlistwidgetitem53 = listWidget_language->item(1);
        ___qlistwidgetitem53->setText(QApplication::translate("HpSetting", "\344\270\255\346\226\207\347\271\201\344\275\223", nullptr));
        QListWidgetItem *___qlistwidgetitem54 = listWidget_language->item(2);
        ___qlistwidgetitem54->setText(QApplication::translate("HpSetting", "English", nullptr));
        QListWidgetItem *___qlistwidgetitem55 = listWidget_language->item(3);
        ___qlistwidgetitem55->setText(QApplication::translate("HpSetting", "\320\240\320\243\320\241\320\241\320\232\320\230\320\231 ", nullptr));
        QListWidgetItem *___qlistwidgetitem56 = listWidget_language->item(4);
        ___qlistwidgetitem56->setText(QApplication::translate("HpSetting", "Magyar", nullptr));
        QListWidgetItem *___qlistwidgetitem57 = listWidget_language->item(5);
        ___qlistwidgetitem57->setText(QApplication::translate("HpSetting", "Espa\303\261ol", nullptr));
        listWidget_language->setSortingEnabled(__sortingEnabled9);

        label_poweroff->setText(QApplication::translate("HpSetting", "\346\227\240", nullptr));
        label_poweroff_2->setText(QString());
        label_lcdoff->setText(QApplication::translate("HpSetting", "\346\227\240", nullptr));
        label_lcdoff_2->setText(QString());

        const bool __sortingEnabled10 = listWidget_poweroff->isSortingEnabled();
        listWidget_poweroff->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem58 = listWidget_poweroff->item(0);
        ___qlistwidgetitem58->setText(QApplication::translate("HpSetting", "\346\227\240", nullptr));
        QListWidgetItem *___qlistwidgetitem59 = listWidget_poweroff->item(1);
        ___qlistwidgetitem59->setText(QApplication::translate("HpSetting", "15s", nullptr));
        QListWidgetItem *___qlistwidgetitem60 = listWidget_poweroff->item(2);
        ___qlistwidgetitem60->setText(QApplication::translate("HpSetting", "1min", nullptr));
        QListWidgetItem *___qlistwidgetitem61 = listWidget_poweroff->item(3);
        ___qlistwidgetitem61->setText(QApplication::translate("HpSetting", "5min", nullptr));
        QListWidgetItem *___qlistwidgetitem62 = listWidget_poweroff->item(4);
        ___qlistwidgetitem62->setText(QApplication::translate("HpSetting", "30min", nullptr));
        QListWidgetItem *___qlistwidgetitem63 = listWidget_poweroff->item(5);
        ___qlistwidgetitem63->setText(QApplication::translate("HpSetting", "1h", nullptr));
        QListWidgetItem *___qlistwidgetitem64 = listWidget_poweroff->item(6);
        ___qlistwidgetitem64->setText(QApplication::translate("HpSetting", "3h", nullptr));
        QListWidgetItem *___qlistwidgetitem65 = listWidget_poweroff->item(7);
        ___qlistwidgetitem65->setText(QApplication::translate("HpSetting", "6h", nullptr));
        listWidget_poweroff->setSortingEnabled(__sortingEnabled10);


        const bool __sortingEnabled11 = listWidget_lcdoff->isSortingEnabled();
        listWidget_lcdoff->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem66 = listWidget_lcdoff->item(0);
        ___qlistwidgetitem66->setText(QApplication::translate("HpSetting", "\346\227\240", nullptr));
        QListWidgetItem *___qlistwidgetitem67 = listWidget_lcdoff->item(1);
        ___qlistwidgetitem67->setText(QApplication::translate("HpSetting", "15s", nullptr));
        QListWidgetItem *___qlistwidgetitem68 = listWidget_lcdoff->item(2);
        ___qlistwidgetitem68->setText(QApplication::translate("HpSetting", "1min", nullptr));
        QListWidgetItem *___qlistwidgetitem69 = listWidget_lcdoff->item(3);
        ___qlistwidgetitem69->setText(QApplication::translate("HpSetting", "5min", nullptr));
        QListWidgetItem *___qlistwidgetitem70 = listWidget_lcdoff->item(4);
        ___qlistwidgetitem70->setText(QApplication::translate("HpSetting", "30min", nullptr));
        QListWidgetItem *___qlistwidgetitem71 = listWidget_lcdoff->item(5);
        ___qlistwidgetitem71->setText(QApplication::translate("HpSetting", "1h", nullptr));
        QListWidgetItem *___qlistwidgetitem72 = listWidget_lcdoff->item(6);
        ___qlistwidgetitem72->setText(QApplication::translate("HpSetting", "3h", nullptr));
        QListWidgetItem *___qlistwidgetitem73 = listWidget_lcdoff->item(7);
        ___qlistwidgetitem73->setText(QApplication::translate("HpSetting", "6h", nullptr));
        listWidget_lcdoff->setSortingEnabled(__sortingEnabled11);

        label_25->setText(QApplication::translate("HpSetting", "<html><head/><body><p>\346\240\274\345\274\217\345\214\226</p></body></html>", nullptr));
        pushButton_3->setText(QApplication::translate("HpSetting", "SD\345\215\241", nullptr));
        label_49->setText(QApplication::translate("HpSetting", "\345\277\253\346\215\267\351\224\256\350\256\276\347\275\256", nullptr));
        pushButton_hotkey->setText(QApplication::translate("HpSetting", "\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("HpSetting", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        label_yiqibianhao->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\344\273\252\345\231\250\347\274\226\345\217\267:     </p></body></html>", nullptr));
        label_shengchanriqi->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\347\224\237\344\272\247\346\227\245\346\234\237:     </p></body></html>", nullptr));
        label_ruanjianbanben->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\350\275\257\344\273\266\347\211\210\346\234\254:     </p></body></html>", nullptr));
        label_yiqixinghao->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">\344\273\252\345\231\250\345\236\213\345\217\267:     </p></body></html>", nullptr));
        label_xinghao_text->setText(QString());
        label_bianhao_text->setText(QString());
        label_banben_text->setText(QString());
        label_riqi_text->setText(QString());
        label_gujianbanben->setText(QApplication::translate("HpSetting", "<html><head/><body><p align=\"right\">FPGA\347\211\210\346\234\254: </p></body></html>", nullptr));
        label_gujianbanben_text->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("HpSetting", "\344\273\252\345\231\250\344\277\241\346\201\257", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HpSetting: public Ui_HpSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPSETTING_H
