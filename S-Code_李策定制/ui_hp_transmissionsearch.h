/********************************************************************************
** Form generated from reading UI file 'hp_transmissionsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_TRANSMISSIONSEARCH_H
#define UI_HP_TRANSMISSIONSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_TransmissionSearch
{
public:
    QWidget *widget;
    QToolButton *toolButton_back;
    QLabel *label_4;
    QListWidget *listWidget_2;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_getXml;
    QPushButton *pushButton_search;

    void setupUi(QWidget *Hp_TransmissionSearch)
    {
        if (Hp_TransmissionSearch->objectName().isEmpty())
            Hp_TransmissionSearch->setObjectName(QStringLiteral("Hp_TransmissionSearch"));
        Hp_TransmissionSearch->resize(800, 480);
        Hp_TransmissionSearch->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        widget = new QWidget(Hp_TransmissionSearch);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 800, 480));
        toolButton_back = new QToolButton(widget);
        toolButton_back->setObjectName(QStringLiteral("toolButton_back"));
        toolButton_back->setGeometry(QRect(-10, 0, 110, 70));
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
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        toolButton_back->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        toolButton_back->setFont(font);
        toolButton_back->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/back_n.png);\n"
"color:#7CA6C9;\n"
"background:transparent;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/back_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/back_d.png);\n"
"}"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 30, 421, 61));
        QFont font1;
        font1.setPointSize(25);
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        listWidget_2 = new QListWidget(widget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(90, 100, 501, 321));
        listWidget_2->setFont(font1);
        listWidget_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(220, 430, 371, 41));
        QFont font2;
        font2.setPointSize(35);
        label_5->setFont(font2);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(620, 220, 151, 71));
        pushButton_3->setMinimumSize(QSize(0, 0));
        pushButton_3->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(25);
        font3.setStyleStrategy(QFont::PreferAntialias);
        pushButton_3->setFont(font3);
        pushButton_3->setFocusPolicy(Qt::WheelFocus);
        pushButton_3->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
"QPushButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
""));
        pushButton_3->setAutoDefault(false);
        pushButton_3->setFlat(true);
        pushButton_getXml = new QPushButton(widget);
        pushButton_getXml->setObjectName(QStringLiteral("pushButton_getXml"));
        pushButton_getXml->setGeometry(QRect(620, 330, 151, 71));
        pushButton_getXml->setMinimumSize(QSize(0, 0));
        pushButton_getXml->setMaximumSize(QSize(16777215, 16777215));
        pushButton_getXml->setFont(font3);
        pushButton_getXml->setFocusPolicy(Qt::WheelFocus);
        pushButton_getXml->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
"QPushButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
""));
        pushButton_getXml->setAutoDefault(false);
        pushButton_getXml->setFlat(true);
        pushButton_search = new QPushButton(widget);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));
        pushButton_search->setGeometry(QRect(620, 110, 151, 71));
        pushButton_search->setMinimumSize(QSize(0, 0));
        pushButton_search->setMaximumSize(QSize(16777215, 16777215));
        pushButton_search->setFont(font3);
        pushButton_search->setFocusPolicy(Qt::WheelFocus);
        pushButton_search->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
"QPushButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
""));
        pushButton_search->setAutoDefault(false);
        pushButton_search->setFlat(true);

        retranslateUi(Hp_TransmissionSearch);

        QMetaObject::connectSlotsByName(Hp_TransmissionSearch);
    } // setupUi

    void retranslateUi(QWidget *Hp_TransmissionSearch)
    {
        Hp_TransmissionSearch->setWindowTitle(QApplication::translate("Hp_TransmissionSearch", "Form", nullptr));
        toolButton_back->setText(QString());
        label_4->setText(QApplication::translate("Hp_TransmissionSearch", "\345\276\205\350\277\236\346\216\245\345\210\227\350\241\250", nullptr));
        label_5->setText(QApplication::translate("Hp_TransmissionSearch", "\346\255\243\345\234\250\345\217\221\351\200\201\350\277\236\346\216\245\350\257\267\346\261\202", nullptr));
        pushButton_3->setText(QApplication::translate("Hp_TransmissionSearch", "\350\277\236\346\216\245", nullptr));
        pushButton_getXml->setText(QApplication::translate("Hp_TransmissionSearch", "\346\216\245\346\224\266", nullptr));
        pushButton_search->setText(QApplication::translate("Hp_TransmissionSearch", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_TransmissionSearch: public Ui_Hp_TransmissionSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_TRANSMISSIONSEARCH_H
