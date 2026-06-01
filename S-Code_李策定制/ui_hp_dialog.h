/********************************************************************************
** Form generated from reading UI file 'hp_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_DIALOG_H
#define UI_HP_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Dialog
{
public:
    QLabel *label;

    void setupUi(QWidget *Hp_Dialog)
    {
        if (Hp_Dialog->objectName().isEmpty())
            Hp_Dialog->setObjectName(QStringLiteral("Hp_Dialog"));
        Hp_Dialog->resize(240, 106);
        Hp_Dialog->setStyleSheet(QStringLiteral(""));
        label = new QLabel(Hp_Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 240, 106));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("border: 0px solid  #7CA6C9;\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/main_background.png);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_Dialog);

        QMetaObject::connectSlotsByName(Hp_Dialog);
    } // setupUi

    void retranslateUi(QWidget *Hp_Dialog)
    {
        Hp_Dialog->setWindowTitle(QApplication::translate("Hp_Dialog", "Form", nullptr));
        label->setText(QApplication::translate("Hp_Dialog", "\346\241\243\344\275\215\350\260\203\346\225\264\344\270\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Dialog: public Ui_Hp_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_DIALOG_H
