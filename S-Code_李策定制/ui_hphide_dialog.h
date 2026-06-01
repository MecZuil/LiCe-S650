/********************************************************************************
** Form generated from reading UI file 'hphide_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPHIDE_DIALOG_H
#define UI_HPHIDE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hphide_Dialog
{
public:
    QFrame *frame;
    QLabel *label;

    void setupUi(QWidget *Hphide_Dialog)
    {
        if (Hphide_Dialog->objectName().isEmpty())
            Hphide_Dialog->setObjectName(QStringLiteral("Hphide_Dialog"));
        Hphide_Dialog->resize(200, 45);
        frame = new QFrame(Hphide_Dialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 200, 45));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 200, 45));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Hphide_Dialog);

        QMetaObject::connectSlotsByName(Hphide_Dialog);
    } // setupUi

    void retranslateUi(QWidget *Hphide_Dialog)
    {
        Hphide_Dialog->setWindowTitle(QApplication::translate("Hphide_Dialog", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Hphide_Dialog: public Ui_Hphide_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPHIDE_DIALOG_H
