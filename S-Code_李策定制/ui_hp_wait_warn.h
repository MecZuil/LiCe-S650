/********************************************************************************
** Form generated from reading UI file 'hp_wait_warn.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_WAIT_WARN_H
#define UI_HP_WAIT_WARN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_wait_warn
{
public:
    QLabel *label_2;

    void setupUi(QWidget *Hp_wait_warn)
    {
        if (Hp_wait_warn->objectName().isEmpty())
            Hp_wait_warn->setObjectName(QStringLiteral("Hp_wait_warn"));
        Hp_wait_warn->setEnabled(true);
        Hp_wait_warn->resize(340, 140);
        Hp_wait_warn->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/setting_background.png);"));
        label_2 = new QLabel(Hp_wait_warn);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 340, 140));
        QPalette palette;
        QBrush brush(QColor(124, 166, 201, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(160, 160, 160, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush3(QColor(50, 152, 253, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush5(QColor(240, 240, 240, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        label_2->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("AR PL UKai CN"));
        font.setPointSize(21);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_wait_warn);

        QMetaObject::connectSlotsByName(Hp_wait_warn);
    } // setupUi

    void retranslateUi(QWidget *Hp_wait_warn)
    {
        Hp_wait_warn->setWindowTitle(QApplication::translate("Hp_wait_warn", "Form", nullptr));
        label_2->setText(QApplication::translate("Hp_wait_warn", "\345\233\276\345\203\217\345\244\204\347\220\206\344\270\255,\350\257\267\347\255\211\345\276\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_wait_warn: public Ui_Hp_wait_warn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_WAIT_WARN_H
