/********************************************************************************
** Form generated from reading UI file 'hp_poweroff_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_POWEROFF_DIALOG_H
#define UI_HP_POWEROFF_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_PowerOff_Dialog
{
public:
    QFrame *frame;
    QLabel *label;
    QLabel *label_timer;

    void setupUi(QWidget *Hp_PowerOff_Dialog)
    {
        if (Hp_PowerOff_Dialog->objectName().isEmpty())
            Hp_PowerOff_Dialog->setObjectName(QStringLiteral("Hp_PowerOff_Dialog"));
        Hp_PowerOff_Dialog->resize(366, 140);
        Hp_PowerOff_Dialog->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(Hp_PowerOff_Dialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 366, 140));
        frame->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/format_default_bg.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 366, 70));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_timer = new QLabel(frame);
        label_timer->setObjectName(QStringLiteral("label_timer"));
        label_timer->setGeometry(QRect(0, 70, 366, 70));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(21);
        label_timer->setFont(font1);
        label_timer->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_PowerOff_Dialog);

        QMetaObject::connectSlotsByName(Hp_PowerOff_Dialog);
    } // setupUi

    void retranslateUi(QWidget *Hp_PowerOff_Dialog)
    {
        Hp_PowerOff_Dialog->setWindowTitle(QApplication::translate("Hp_PowerOff_Dialog", "Form", nullptr));
        label->setText(QApplication::translate("Hp_PowerOff_Dialog", " \347\224\265\351\207\217\344\275\216\357\274\214\347\263\273\347\273\237\345\215\263\345\260\206\345\205\263\346\234\272", nullptr));
        label_timer->setText(QApplication::translate("Hp_PowerOff_Dialog", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_PowerOff_Dialog: public Ui_Hp_PowerOff_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_POWEROFF_DIALOG_H
