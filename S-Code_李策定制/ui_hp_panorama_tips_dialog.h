/********************************************************************************
** Form generated from reading UI file 'hp_panorama_tips_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_PANORAMA_TIPS_DIALOG_H
#define UI_HP_PANORAMA_TIPS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Panorama_Tips_Dialog
{
public:
    QFrame *frame;
    QLabel *label_text;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_ok;

    void setupUi(QWidget *Hp_Panorama_Tips_Dialog)
    {
        if (Hp_Panorama_Tips_Dialog->objectName().isEmpty())
            Hp_Panorama_Tips_Dialog->setObjectName(QStringLiteral("Hp_Panorama_Tips_Dialog"));
        Hp_Panorama_Tips_Dialog->resize(300, 150);
        Hp_Panorama_Tips_Dialog->setAutoFillBackground(false);
        Hp_Panorama_Tips_Dialog->setStyleSheet(QLatin1String("background-image:url(:/res/res/setting_background.png);\n"
"border: 1px solid  #7CA6C9;"));
        frame = new QFrame(Hp_Panorama_Tips_Dialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 300, 150));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_text = new QLabel(frame);
        label_text->setObjectName(QStringLiteral("label_text"));
        label_text->setGeometry(QRect(10, 10, 280, 65));
        QFont font;
        font.setPointSize(70);
        label_text->setFont(font);
        label_text->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"color:#7CA6C9;"));
        label_text->setAlignment(Qt::AlignCenter);
        pushButton_cancel = new QPushButton(frame);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(175, 100, 75, 41));
        pushButton_cancel->setFont(font);
        pushButton_cancel->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"color:#7CA6C9;"));
        pushButton_ok = new QPushButton(frame);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(50, 100, 75, 41));
        pushButton_ok->setFont(font);
        pushButton_ok->setStyleSheet(QLatin1String("border: 1px solid  #00FFFF;\n"
"color: rgb(0, 255, 255);"));

        retranslateUi(Hp_Panorama_Tips_Dialog);

        QMetaObject::connectSlotsByName(Hp_Panorama_Tips_Dialog);
    } // setupUi

    void retranslateUi(QWidget *Hp_Panorama_Tips_Dialog)
    {
        Hp_Panorama_Tips_Dialog->setWindowTitle(QApplication::translate("Hp_Panorama_Tips_Dialog", "Form", nullptr));
        label_text->setText(QApplication::translate("Hp_Panorama_Tips_Dialog", "Panorama", nullptr));
        pushButton_cancel->setText(QApplication::translate("Hp_Panorama_Tips_Dialog", "NO", nullptr));
        pushButton_ok->setText(QApplication::translate("Hp_Panorama_Tips_Dialog", "YES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Panorama_Tips_Dialog: public Ui_Hp_Panorama_Tips_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_PANORAMA_TIPS_DIALOG_H
