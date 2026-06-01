/********************************************************************************
** Form generated from reading UI file 'hp_wifi_search.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_WIFI_SEARCH_H
#define UI_HP_WIFI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Wifi_Search
{
public:
    QFrame *frame;
    QLabel *label;
    QListWidget *listWidget_Wifimode;
    QToolButton *toolButton_back;
    QFrame *frame_Wifimode;
    QLabel *label_Wifimode;
    QLabel *label_Wifimode_2;
    QCheckBox *checkBox_wifi;
    QLabel *label_6;
    QCheckBox *checkBox_localServer;
    QFrame *frame_2;
    QFrame *frame_WifiNum;
    QLabel *label_WifiNum;
    QLabel *label_WifiNum_2;
    QLabel *label_2;
    QLabel *label_3;
    QToolButton *wifi_Flush;
    QListWidget *listWidget_WifiNum;
    QLabel *label_PassWord;
    QFrame *frame_equipment;
    QLabel *label_equipment;
    QLabel *label_equipment_2;
    QToolButton *equip_Flush_2;
    QLabel *label_4;
    QLabel *label_5;
    QCheckBox *checkBox_equipment;
    QListWidget *listWidget_equip;
    QCheckBox *checkBox_getFlow;
    QLabel *label_10;

    void setupUi(QWidget *Hp_Wifi_Search)
    {
        if (Hp_Wifi_Search->objectName().isEmpty())
            Hp_Wifi_Search->setObjectName(QStringLiteral("Hp_Wifi_Search"));
        Hp_Wifi_Search->resize(800, 480);
        Hp_Wifi_Search->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        frame = new QFrame(Hp_Wifi_Search);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 800, 180));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 75, 271, 31));
        QFont font;
        font.setPointSize(19);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        listWidget_Wifimode = new QListWidget(frame);
        new QListWidgetItem(listWidget_Wifimode);
        new QListWidgetItem(listWidget_Wifimode);
        listWidget_Wifimode->setObjectName(QStringLiteral("listWidget_Wifimode"));
        listWidget_Wifimode->setGeometry(QRect(330, 109, 241, 70));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(17);
        listWidget_Wifimode->setFont(font1);
        listWidget_Wifimode->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        toolButton_back = new QToolButton(frame);
        toolButton_back->setObjectName(QStringLiteral("toolButton_back"));
        toolButton_back->setGeometry(QRect(0, 0, 131, 61));
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
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        toolButton_back->setFont(font2);
        toolButton_back->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/setting_back.png);\n"
"}  \n"
""));
        frame_Wifimode = new QFrame(frame);
        frame_Wifimode->setObjectName(QStringLiteral("frame_Wifimode"));
        frame_Wifimode->setGeometry(QRect(330, 65, 243, 44));
        frame_Wifimode->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_Wifimode->setFrameShape(QFrame::StyledPanel);
        frame_Wifimode->setFrameShadow(QFrame::Raised);
        label_Wifimode = new QLabel(frame_Wifimode);
        label_Wifimode->setObjectName(QStringLiteral("label_Wifimode"));
        label_Wifimode->setGeometry(QRect(0, 0, 201, 44));
        label_Wifimode->setFont(font1);
        label_Wifimode->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_Wifimode->setText(QStringLiteral(""));
        label_Wifimode->setAlignment(Qt::AlignCenter);
        label_Wifimode_2 = new QLabel(frame_Wifimode);
        label_Wifimode_2->setObjectName(QStringLiteral("label_Wifimode_2"));
        label_Wifimode_2->setGeometry(QRect(201, 2, 40, 40));
        label_Wifimode_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        checkBox_wifi = new QCheckBox(frame);
        checkBox_wifi->setObjectName(QStringLiteral("checkBox_wifi"));
        checkBox_wifi->setEnabled(true);
        checkBox_wifi->setGeometry(QRect(640, 55, 70, 65));
        QFont font3;
        font3.setPointSize(17);
        checkBox_wifi->setFont(font3);
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
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 140, 271, 31));
        label_6->setFont(font);
        label_6->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_localServer = new QCheckBox(frame);
        checkBox_localServer->setObjectName(QStringLiteral("checkBox_localServer"));
        checkBox_localServer->setEnabled(true);
        checkBox_localServer->setGeometry(QRect(640, 120, 70, 65));
        checkBox_localServer->setFont(font3);
        checkBox_localServer->setFocusPolicy(Qt::NoFocus);
        checkBox_localServer->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        frame_2 = new QFrame(Hp_Wifi_Search);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 180, 800, 300));
        frame_2->setAutoFillBackground(false);
        frame_2->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_WifiNum = new QFrame(frame_2);
        frame_WifiNum->setObjectName(QStringLiteral("frame_WifiNum"));
        frame_WifiNum->setGeometry(QRect(330, 7, 243, 44));
        frame_WifiNum->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_WifiNum->setFrameShape(QFrame::StyledPanel);
        frame_WifiNum->setFrameShadow(QFrame::Raised);
        label_WifiNum = new QLabel(frame_WifiNum);
        label_WifiNum->setObjectName(QStringLiteral("label_WifiNum"));
        label_WifiNum->setGeometry(QRect(0, 0, 201, 44));
        label_WifiNum->setFont(font1);
        label_WifiNum->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_WifiNum->setText(QStringLiteral(""));
        label_WifiNum->setAlignment(Qt::AlignCenter);
        label_WifiNum_2 = new QLabel(frame_WifiNum);
        label_WifiNum_2->setObjectName(QStringLiteral("label_WifiNum_2"));
        label_WifiNum_2->setGeometry(QRect(201, 2, 40, 40));
        label_WifiNum_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 17, 271, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(48, 85, 271, 31));
        label_3->setFont(font);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        wifi_Flush = new QToolButton(frame_2);
        wifi_Flush->setObjectName(QStringLiteral("wifi_Flush"));
        wifi_Flush->setGeometry(QRect(640, 7, 91, 44));
        wifi_Flush->setFont(font3);
        wifi_Flush->setFocusPolicy(Qt::NoFocus);
        wifi_Flush->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        wifi_Flush->setAutoRaise(true);
        listWidget_WifiNum = new QListWidget(frame_2);
        listWidget_WifiNum->setObjectName(QStringLiteral("listWidget_WifiNum"));
        listWidget_WifiNum->setGeometry(QRect(330, 43, 241, 161));
        listWidget_WifiNum->setFont(font1);
        listWidget_WifiNum->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
""));
        listWidget_WifiNum->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listWidget_WifiNum->setAutoScrollMargin(16);
        label_PassWord = new QLabel(frame_2);
        label_PassWord->setObjectName(QStringLiteral("label_PassWord"));
        label_PassWord->setGeometry(QRect(328, 75, 243, 44));
        label_PassWord->setFont(font);
        label_PassWord->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_PassWord->setText(QStringLiteral(""));
        frame_equipment = new QFrame(frame_2);
        frame_equipment->setObjectName(QStringLiteral("frame_equipment"));
        frame_equipment->setGeometry(QRect(330, 144, 243, 44));
        frame_equipment->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_equipment->setFrameShape(QFrame::StyledPanel);
        frame_equipment->setFrameShadow(QFrame::Raised);
        label_equipment = new QLabel(frame_equipment);
        label_equipment->setObjectName(QStringLiteral("label_equipment"));
        label_equipment->setGeometry(QRect(0, 0, 201, 44));
        label_equipment->setFont(font1);
        label_equipment->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_equipment->setText(QStringLiteral(""));
        label_equipment->setAlignment(Qt::AlignCenter);
        label_equipment_2 = new QLabel(frame_equipment);
        label_equipment_2->setObjectName(QStringLiteral("label_equipment_2"));
        label_equipment_2->setGeometry(QRect(201, 2, 40, 40));
        label_equipment_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        equip_Flush_2 = new QToolButton(frame_2);
        equip_Flush_2->setObjectName(QStringLiteral("equip_Flush_2"));
        equip_Flush_2->setGeometry(QRect(640, 144, 91, 44));
        equip_Flush_2->setFont(font3);
        equip_Flush_2->setFocusPolicy(Qt::NoFocus);
        equip_Flush_2->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        equip_Flush_2->setAutoRaise(true);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 154, 271, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(520, 220, 101, 31));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_equipment = new QCheckBox(frame_2);
        checkBox_equipment->setObjectName(QStringLiteral("checkBox_equipment"));
        checkBox_equipment->setEnabled(true);
        checkBox_equipment->setGeometry(QRect(330, 216, 70, 41));
        checkBox_equipment->setFont(font3);
        checkBox_equipment->setFocusPolicy(Qt::NoFocus);
        checkBox_equipment->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        listWidget_equip = new QListWidget(frame_2);
        listWidget_equip->setObjectName(QStringLiteral("listWidget_equip"));
        listWidget_equip->setGeometry(QRect(330, 190, 241, 161));
        listWidget_equip->setFont(font1);
        listWidget_equip->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
""));
        listWidget_equip->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listWidget_equip->setAutoScrollMargin(16);
        checkBox_getFlow = new QCheckBox(frame_2);
        checkBox_getFlow->setObjectName(QStringLiteral("checkBox_getFlow"));
        checkBox_getFlow->setEnabled(true);
        checkBox_getFlow->setGeometry(QRect(640, 215, 70, 41));
        checkBox_getFlow->setFont(font3);
        checkBox_getFlow->setFocusPolicy(Qt::NoFocus);
        checkBox_getFlow->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(220, 220, 101, 31));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frame_WifiNum->raise();
        label_2->raise();
        label_3->raise();
        wifi_Flush->raise();
        label_PassWord->raise();
        listWidget_WifiNum->raise();
        frame_equipment->raise();
        equip_Flush_2->raise();
        label_4->raise();
        label_5->raise();
        checkBox_equipment->raise();
        listWidget_equip->raise();
        checkBox_getFlow->raise();
        label_10->raise();

        retranslateUi(Hp_Wifi_Search);

        QMetaObject::connectSlotsByName(Hp_Wifi_Search);
    } // setupUi

    void retranslateUi(QWidget *Hp_Wifi_Search)
    {
        Hp_Wifi_Search->setWindowTitle(QApplication::translate("Hp_Wifi_Search", "Form", nullptr));
        label->setText(QApplication::translate("Hp_Wifi_Search", "\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));

        const bool __sortingEnabled = listWidget_Wifimode->isSortingEnabled();
        listWidget_Wifimode->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_Wifimode->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Hp_Wifi_Search", "AP", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_Wifimode->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Hp_Wifi_Search", "STA", nullptr));
        listWidget_Wifimode->setSortingEnabled(__sortingEnabled);

        toolButton_back->setText(QString());
        label_Wifimode_2->setText(QString());
        checkBox_wifi->setText(QString());
        label_6->setText(QApplication::translate("Hp_Wifi_Search", "\346\234\254\345\234\260\346\234\215\345\212\241", nullptr));
        checkBox_localServer->setText(QString());
        label_WifiNum_2->setText(QString());
        label_2->setText(QApplication::translate("Hp_Wifi_Search", "Wifi\351\200\211\346\213\251", nullptr));
        label_3->setText(QApplication::translate("Hp_Wifi_Search", "Wifi\345\257\206\347\240\201", nullptr));
        wifi_Flush->setText(QApplication::translate("Hp_Wifi_Search", "\345\210\267\346\226\260", nullptr));
        label_equipment_2->setText(QString());
        equip_Flush_2->setText(QApplication::translate("Hp_Wifi_Search", "\345\210\267\346\226\260", nullptr));
        label_4->setText(QApplication::translate("Hp_Wifi_Search", "\350\256\276\345\244\207\347\233\256\345\275\225", nullptr));
        label_5->setText(QApplication::translate("Hp_Wifi_Search", "\344\273\252\345\231\250\345\217\226\346\265\201", nullptr));
        checkBox_equipment->setText(QString());
        checkBox_getFlow->setText(QString());
        label_10->setText(QApplication::translate("Hp_Wifi_Search", "\350\256\276\345\244\207\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Wifi_Search: public Ui_Hp_Wifi_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_WIFI_SEARCH_H
