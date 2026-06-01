/********************************************************************************
** Form generated from reading UI file 'hp_panorama_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_PANORAMA_DIALOG_H
#define UI_HP_PANORAMA_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Hp_Panorama_Dialog
{
public:
    QFrame *frame;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QLabel *label_text;

    void setupUi(QDialog *Hp_Panorama_Dialog)
    {
        if (Hp_Panorama_Dialog->objectName().isEmpty())
            Hp_Panorama_Dialog->setObjectName(QStringLiteral("Hp_Panorama_Dialog"));
        Hp_Panorama_Dialog->resize(300, 150);
        frame = new QFrame(Hp_Panorama_Dialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 300, 150));
        QFont font;
        font.setPointSize(17);
        frame->setFont(font);
        frame->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/format_default_bg.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_ok = new QPushButton(frame);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(50, 80, 75, 41));
        pushButton_ok->setFont(font);
        pushButton_cancel = new QPushButton(frame);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(160, 80, 75, 41));
        pushButton_cancel->setFont(font);
        label_text = new QLabel(frame);
        label_text->setObjectName(QStringLiteral("label_text"));
        label_text->setGeometry(QRect(10, 5, 281, 71));
        label_text->setFont(font);
        label_text->setStyleSheet(QStringLiteral("border: 0px solid  #7CA6C9;"));
        label_text->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_Panorama_Dialog);

        QMetaObject::connectSlotsByName(Hp_Panorama_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Hp_Panorama_Dialog)
    {
        Hp_Panorama_Dialog->setWindowTitle(QApplication::translate("Hp_Panorama_Dialog", "Dialog", nullptr));
        pushButton_ok->setText(QApplication::translate("Hp_Panorama_Dialog", "YES", nullptr));
        pushButton_cancel->setText(QApplication::translate("Hp_Panorama_Dialog", "NO", nullptr));
        label_text->setText(QApplication::translate("Hp_Panorama_Dialog", "Panorama", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Panorama_Dialog: public Ui_Hp_Panorama_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_PANORAMA_DIALOG_H
