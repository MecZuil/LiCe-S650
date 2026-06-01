/********************************************************************************
** Form generated from reading UI file 'hp_common_dialog_cancel.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_COMMON_DIALOG_CANCEL_H
#define UI_HP_COMMON_DIALOG_CANCEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hp_common_dialog_cancel
{
public:
    QFrame *frame;
    QLabel *label_3;
    QPushButton *pushButton_ok;

    void setupUi(QWidget *hp_common_dialog_cancel)
    {
        if (hp_common_dialog_cancel->objectName().isEmpty())
            hp_common_dialog_cancel->setObjectName(QStringLiteral("hp_common_dialog_cancel"));
        hp_common_dialog_cancel->resize(300, 150);
        frame = new QFrame(hp_common_dialog_cancel);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 300, 150));
        frame->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/setting_background.png);"));
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

        retranslateUi(hp_common_dialog_cancel);

        QMetaObject::connectSlotsByName(hp_common_dialog_cancel);
    } // setupUi

    void retranslateUi(QWidget *hp_common_dialog_cancel)
    {
        hp_common_dialog_cancel->setWindowTitle(QApplication::translate("hp_common_dialog_cancel", "Form", nullptr));
        label_3->setText(QApplication::translate("hp_common_dialog_cancel", "<html><head/><body><p align=\"center\">\344\277\241\346\201\257</p></body></html>", nullptr));
        pushButton_ok->setText(QApplication::translate("hp_common_dialog_cancel", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hp_common_dialog_cancel: public Ui_hp_common_dialog_cancel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_COMMON_DIALOG_CANCEL_H
