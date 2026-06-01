/********************************************************************************
** Form generated from reading UI file 'hp_poweroff_warn.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_POWEROFF_WARN_H
#define UI_HP_POWEROFF_WARN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HP_Poweroff_Warn
{
public:
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QToolButton *toolButton;

    void setupUi(QWidget *HP_Poweroff_Warn)
    {
        if (HP_Poweroff_Warn->objectName().isEmpty())
            HP_Poweroff_Warn->setObjectName(QStringLiteral("HP_Poweroff_Warn"));
        HP_Poweroff_Warn->resize(366, 140);
        frame = new QFrame(HP_Poweroff_Warn);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 366, 140));
        frame->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/format_default_bg.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 71, 361, 71));
        QFont font;
        font.setPointSize(21);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 361, 71));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(323, 0, 41, 31));
        QFont font1;
        font1.setPointSize(15);
        toolButton->setFont(font1);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton->setAutoRaise(true);

        retranslateUi(HP_Poweroff_Warn);

        QMetaObject::connectSlotsByName(HP_Poweroff_Warn);
    } // setupUi

    void retranslateUi(QWidget *HP_Poweroff_Warn)
    {
        HP_Poweroff_Warn->setWindowTitle(QApplication::translate("HP_Poweroff_Warn", "Form", nullptr));
        label->setText(QApplication::translate("HP_Poweroff_Warn", "\350\257\267\345\217\212\346\227\266\345\205\205\347\224\265", nullptr));
        label_2->setText(QApplication::translate("HP_Poweroff_Warn", "\347\224\265\351\207\217\344\275\216", nullptr));
        toolButton->setText(QApplication::translate("HP_Poweroff_Warn", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HP_Poweroff_Warn: public Ui_HP_Poweroff_Warn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_POWEROFF_WARN_H
