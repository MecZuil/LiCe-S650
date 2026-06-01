/********************************************************************************
** Form generated from reading UI file 'hp_pic_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_PIC_DIALOG_H
#define UI_HP_PIC_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Pic_Dialog
{
public:
    QFrame *frame;
    QLabel *label_text;
    QPushButton *pushButton_exit;

    void setupUi(QWidget *Hp_Pic_Dialog)
    {
        if (Hp_Pic_Dialog->objectName().isEmpty())
            Hp_Pic_Dialog->setObjectName(QStringLiteral("Hp_Pic_Dialog"));
        Hp_Pic_Dialog->resize(400, 240);
        frame = new QFrame(Hp_Pic_Dialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 400, 240));
        frame->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/format_default_bg.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_text = new QLabel(frame);
        label_text->setObjectName(QStringLiteral("label_text"));
        label_text->setGeometry(QRect(0, 60, 391, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        label_text->setFont(font);
        label_text->setStyleSheet(QStringLiteral("border: 0px solid  #7CA6C9;"));
        label_text->setAlignment(Qt::AlignCenter);
        pushButton_exit = new QPushButton(frame);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(360, 0, 41, 41));
        QFont font1;
        font1.setPointSize(20);
        pushButton_exit->setFont(font1);
        pushButton_exit->setStyleSheet(QStringLiteral("border: 1px solid  #7CA6C9;"));
        pushButton_exit->raise();
        label_text->raise();

        retranslateUi(Hp_Pic_Dialog);

        QMetaObject::connectSlotsByName(Hp_Pic_Dialog);
    } // setupUi

    void retranslateUi(QWidget *Hp_Pic_Dialog)
    {
        Hp_Pic_Dialog->setWindowTitle(QApplication::translate("Hp_Pic_Dialog", "Form", nullptr));
        label_text->setText(QApplication::translate("Hp_Pic_Dialog", "\346\217\220\347\244\272\357\274\232\345\233\276\347\211\207\345\267\262\346\215\237\345\235\217", nullptr));
        pushButton_exit->setText(QApplication::translate("Hp_Pic_Dialog", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Pic_Dialog: public Ui_Hp_Pic_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_PIC_DIALOG_H
