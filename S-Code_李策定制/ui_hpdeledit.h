/********************************************************************************
** Form generated from reading UI file 'hpdeledit.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPDELEDIT_H
#define UI_HPDELEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hpDelEdit
{
public:
    QFrame *frame;
    QToolButton *del;
    QToolButton *edit;

    void setupUi(QWidget *hpDelEdit)
    {
        if (hpDelEdit->objectName().isEmpty())
            hpDelEdit->setObjectName(QStringLiteral("hpDelEdit"));
        hpDelEdit->resize(129, 66);
        QFont font;
        font.setPointSize(15);
        hpDelEdit->setFont(font);
        hpDelEdit->setStyleSheet(QStringLiteral("background-color: rgb(41, 20, 20);"));
        frame = new QFrame(hpDelEdit);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 129, 66));
        frame->setFont(font);
        frame->setStyleSheet(QStringLiteral("background-image:url(:/res/res/editdel_bg.png);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        del = new QToolButton(frame);
        del->setObjectName(QStringLiteral("del"));
        del->setGeometry(QRect(1, 2, 62, 62));
        QFont font1;
        font1.setPointSize(17);
        del->setFont(font1);
        del->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/de_del_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/de_del_s.png);\n"
"}"));
        edit = new QToolButton(frame);
        edit->setObjectName(QStringLiteral("edit"));
        edit->setGeometry(QRect(66, 2, 62, 62));
        edit->setFont(font1);
        edit->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/de_edit_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/de_edit_s.png);\n"
"}"));

        retranslateUi(hpDelEdit);

        QMetaObject::connectSlotsByName(hpDelEdit);
    } // setupUi

    void retranslateUi(QWidget *hpDelEdit)
    {
        hpDelEdit->setWindowTitle(QApplication::translate("hpDelEdit", "Form", nullptr));
        del->setText(QString());
        edit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class hpDelEdit: public Ui_hpDelEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPDELEDIT_H
