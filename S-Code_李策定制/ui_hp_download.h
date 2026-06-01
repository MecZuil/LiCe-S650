/********************************************************************************
** Form generated from reading UI file 'hp_download.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_DOWNLOAD_H
#define UI_HP_DOWNLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hp_DownLoad
{
public:
    QFrame *frame;
    QToolButton *toolButton_back;
    QLabel *label;
    QToolButton *wifi_Flush;
    QToolButton *get_file;
    QLabel *label_3;
    QLabel *label_2;
    QListWidget *listWidget_father;
    QListWidget *listWidget_child;
    QToolButton *godown;
    QToolButton *goup;

    void setupUi(QWidget *hp_DownLoad)
    {
        if (hp_DownLoad->objectName().isEmpty())
            hp_DownLoad->setObjectName(QStringLiteral("hp_DownLoad"));
        hp_DownLoad->resize(800, 480);
        hp_DownLoad->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        frame = new QFrame(hp_DownLoad);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 800, 480));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
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
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        toolButton_back->setFont(font);
        toolButton_back->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/setting_back.png);\n"
"}  \n"
""));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 20, 641, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("color:#7CA6C9;\n"
"font: 20pt \"Arial\";\n"
"\n"
"background:transparent;"));
        wifi_Flush = new QToolButton(frame);
        wifi_Flush->setObjectName(QStringLiteral("wifi_Flush"));
        wifi_Flush->setGeometry(QRect(690, 292, 100, 86));
        QFont font2;
        font2.setPointSize(17);
        wifi_Flush->setFont(font2);
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
        get_file = new QToolButton(frame);
        get_file->setObjectName(QStringLiteral("get_file"));
        get_file->setGeometry(QRect(690, 383, 100, 86));
        get_file->setFont(font2);
        get_file->setFocusPolicy(Qt::NoFocus);
        get_file->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        get_file->setAutoRaise(true);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 70, 441, 31));
        QFont font3;
        font3.setPointSize(19);
        label_3->setFont(font3);
        label_3->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 201, 31));
        label_2->setFont(font3);
        label_2->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        listWidget_father = new QListWidget(frame);
        listWidget_father->setObjectName(QStringLiteral("listWidget_father"));
        listWidget_father->setGeometry(QRect(10, 110, 201, 361));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(17);
        listWidget_father->setFont(font4);
        listWidget_father->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        listWidget_child = new QListWidget(frame);
        listWidget_child->setObjectName(QStringLiteral("listWidget_child"));
        listWidget_child->setGeometry(QRect(220, 110, 461, 361));
        listWidget_child->setFont(font4);
        listWidget_child->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
""));
        listWidget_child->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listWidget_child->setAutoScrollMargin(16);
        godown = new QToolButton(frame);
        godown->setObjectName(QStringLiteral("godown"));
        godown->setGeometry(QRect(690, 110, 100, 86));
        godown->setFont(font2);
        godown->setFocusPolicy(Qt::NoFocus);
        godown->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        godown->setAutoRaise(true);
        goup = new QToolButton(frame);
        goup->setObjectName(QStringLiteral("goup"));
        goup->setGeometry(QRect(690, 201, 100, 86));
        goup->setFont(font2);
        goup->setFocusPolicy(Qt::NoFocus);
        goup->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        goup->setAutoRaise(true);

        retranslateUi(hp_DownLoad);

        QMetaObject::connectSlotsByName(hp_DownLoad);
    } // setupUi

    void retranslateUi(QWidget *hp_DownLoad)
    {
        hp_DownLoad->setWindowTitle(QApplication::translate("hp_DownLoad", "Form", nullptr));
        toolButton_back->setText(QString());
        label->setText(QString());
        wifi_Flush->setText(QApplication::translate("hp_DownLoad", "\345\210\267\346\226\260", nullptr));
        get_file->setText(QApplication::translate("hp_DownLoad", "\350\216\267\345\217\226", nullptr));
        label_3->setText(QApplication::translate("hp_DownLoad", "\345\255\220\347\233\256\345\275\225", nullptr));
        label_2->setText(QApplication::translate("hp_DownLoad", "\344\270\273\347\233\256\345\275\225", nullptr));
        godown->setText(QApplication::translate("hp_DownLoad", "\350\277\233\345\205\245\n"
"\344\270\213\344\270\200\347\272\247", nullptr));
        goup->setText(QApplication::translate("hp_DownLoad", "\350\277\224\345\233\236\n"
"\344\270\212\344\270\200\347\272\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hp_DownLoad: public Ui_hp_DownLoad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_DOWNLOAD_H
