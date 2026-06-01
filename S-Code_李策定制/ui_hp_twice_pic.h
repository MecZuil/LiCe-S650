/********************************************************************************
** Form generated from reading UI file 'hp_twice_pic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_TWICE_PIC_H
#define UI_HP_TWICE_PIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HP_Twice_Pic
{
public:
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_3;
    QFrame *frame_4;
    QPushButton *pushButton_return;
    QPushButton *pushButton_cut;
    QFrame *frame_5;
    QLabel *label_name;
    QFrame *frame_6;

    void setupUi(QWidget *HP_Twice_Pic)
    {
        if (HP_Twice_Pic->objectName().isEmpty())
            HP_Twice_Pic->setObjectName(QStringLiteral("HP_Twice_Pic"));
        HP_Twice_Pic->resize(800, 480);
        HP_Twice_Pic->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(HP_Twice_Pic);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 800, 480));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(160, 60, 480, 360));
        frame_2->setStyleSheet(QStringLiteral(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(0, 0, 161, 420));
        frame_3->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"border-right-color: rgb(0, 0, 0);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(0, 419, 800, 61));
        frame_4->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"border-top-color: rgb(0, 0, 0,0);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        pushButton_return = new QPushButton(frame_4);
        pushButton_return->setObjectName(QStringLiteral("pushButton_return"));
        pushButton_return->setGeometry(QRect(680, 10, 91, 41));
        QFont font;
        font.setPointSize(15);
        pushButton_return->setFont(font);
        pushButton_return->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton_cut = new QPushButton(frame_4);
        pushButton_cut->setObjectName(QStringLiteral("pushButton_cut"));
        pushButton_cut->setGeometry(QRect(570, 10, 91, 41));
        pushButton_cut->setFont(font);
        pushButton_cut->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(160, 0, 480, 61));
        frame_5->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_name = new QLabel(frame_5);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(20, 10, 440, 40));
        QFont font1;
        font1.setPointSize(17);
        label_name->setFont(font1);
        label_name->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        label_name->setAlignment(Qt::AlignCenter);
        frame_6 = new QFrame(frame);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(639, 0, 161, 420));
        frame_6->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0,);\n"
"border-left-color: rgb(0, 0, 0.0);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);

        retranslateUi(HP_Twice_Pic);

        QMetaObject::connectSlotsByName(HP_Twice_Pic);
    } // setupUi

    void retranslateUi(QWidget *HP_Twice_Pic)
    {
        HP_Twice_Pic->setWindowTitle(QApplication::translate("HP_Twice_Pic", "Form", nullptr));
        pushButton_return->setText(QApplication::translate("HP_Twice_Pic", "return", nullptr));
        pushButton_cut->setText(QApplication::translate("HP_Twice_Pic", "\345\210\267\346\226\260", nullptr));
        label_name->setText(QApplication::translate("HP_Twice_Pic", "name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HP_Twice_Pic: public Ui_HP_Twice_Pic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_TWICE_PIC_H
