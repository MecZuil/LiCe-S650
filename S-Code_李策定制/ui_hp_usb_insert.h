/********************************************************************************
** Form generated from reading UI file 'hp_usb_insert.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_USB_INSERT_H
#define UI_HP_USB_INSERT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HP_USB_insert
{
public:
    QLabel *label;

    void setupUi(QWidget *HP_USB_insert)
    {
        if (HP_USB_insert->objectName().isEmpty())
            HP_USB_insert->setObjectName(QStringLiteral("HP_USB_insert"));
        HP_USB_insert->resize(800, 480);
        label = new QLabel(HP_USB_insert);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 90, 480, 272));
        label->setStyleSheet(QLatin1String("background:transparent;\n"
"border-image: url(:/res/res/sd_insert.png);"));

        retranslateUi(HP_USB_insert);

        QMetaObject::connectSlotsByName(HP_USB_insert);
    } // setupUi

    void retranslateUi(QWidget *HP_USB_insert)
    {
        HP_USB_insert->setWindowTitle(QApplication::translate("HP_USB_insert", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HP_USB_insert: public Ui_HP_USB_insert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_USB_INSERT_H
