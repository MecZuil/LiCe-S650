/********************************************************************************
** Form generated from reading UI file 'hpcpumem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPCPUMEM_H
#define UI_HPCPUMEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "hp_cpudrawwidget.h"

QT_BEGIN_NAMESPACE

class Ui_HpCpuMem
{
public:
    QLabel *label;
    Hp_CpuDrawWidget *widget;

    void setupUi(QWidget *HpCpuMem)
    {
        if (HpCpuMem->objectName().isEmpty())
            HpCpuMem->setObjectName(QStringLiteral("HpCpuMem"));
        HpCpuMem->resize(520, 270);
        QFont font;
        font.setPointSize(15);
        HpCpuMem->setFont(font);
        HpCpuMem->setStyleSheet(QStringLiteral("background-color: rgb(110, 153, 243);"));
        label = new QLabel(HpCpuMem);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(16, 9, 333, 35));
        QFont font1;
        font1.setPointSize(17);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: rgb(30, 159, 25);"));
        widget = new Hp_CpuDrawWidget(HpCpuMem);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(16, 53, 333, 194));
        widget->setFont(font);
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QLatin1String("background-color: rgb(18, 10, 10);\n"
"border-color: rgb(203, 61, 61);"));

        retranslateUi(HpCpuMem);

        QMetaObject::connectSlotsByName(HpCpuMem);
    } // setupUi

    void retranslateUi(QWidget *HpCpuMem)
    {
        HpCpuMem->setWindowTitle(QApplication::translate("HpCpuMem", "Form", nullptr));
        label->setText(QApplication::translate("HpCpuMem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HpCpuMem: public Ui_HpCpuMem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPCPUMEM_H
