/********************************************************************************
** Form generated from reading UI file 'hp_createpdf.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_CREATEPDF_H
#define UI_HP_CREATEPDF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_CreatePDF
{
public:

    void setupUi(QWidget *Hp_CreatePDF)
    {
        if (Hp_CreatePDF->objectName().isEmpty())
            Hp_CreatePDF->setObjectName(QStringLiteral("Hp_CreatePDF"));
        Hp_CreatePDF->resize(400, 300);

        retranslateUi(Hp_CreatePDF);

        QMetaObject::connectSlotsByName(Hp_CreatePDF);
    } // setupUi

    void retranslateUi(QWidget *Hp_CreatePDF)
    {
        Hp_CreatePDF->setWindowTitle(QApplication::translate("Hp_CreatePDF", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_CreatePDF: public Ui_Hp_CreatePDF {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_CREATEPDF_H
