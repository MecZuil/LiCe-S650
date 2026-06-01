/********************************************************************************
** Form generated from reading UI file 'hp_wifi_search_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_WIFI_SEARCH_DIALOG_H
#define UI_HP_WIFI_SEARCH_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Wifi_search_Dialog
{
public:
    QFrame *frame;
    QLabel *label_3;
    QPushButton *pushButton_ok;

    void setupUi(QWidget *Hp_Wifi_search_Dialog)
    {
        if (Hp_Wifi_search_Dialog->objectName().isEmpty())
            Hp_Wifi_search_Dialog->setObjectName(QStringLiteral("Hp_Wifi_search_Dialog"));
        Hp_Wifi_search_Dialog->resize(300, 150);
        Hp_Wifi_search_Dialog->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(Hp_Wifi_search_Dialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 300, 150));
        frame->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/format_default_bg.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 281, 46));
        QFont font;
        font.setPointSize(15);
        font.setStyleStrategy(QFont::PreferAntialias);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setAlignment(Qt::AlignCenter);
        pushButton_ok = new QPushButton(frame);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(110, 90, 75, 41));
        QFont font1;
        font1.setPointSize(17);
        pushButton_ok->setFont(font1);

        retranslateUi(Hp_Wifi_search_Dialog);

        QMetaObject::connectSlotsByName(Hp_Wifi_search_Dialog);
    } // setupUi

    void retranslateUi(QWidget *Hp_Wifi_search_Dialog)
    {
        Hp_Wifi_search_Dialog->setWindowTitle(QApplication::translate("Hp_Wifi_search_Dialog", "Form", nullptr));
        label_3->setText(QApplication::translate("Hp_Wifi_search_Dialog", "<html><head/><body><p align=\"center\">\344\277\241\346\201\257</p></body></html>", nullptr));
        pushButton_ok->setText(QApplication::translate("Hp_Wifi_search_Dialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Wifi_search_Dialog: public Ui_Hp_Wifi_search_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_WIFI_SEARCH_DIALOG_H
