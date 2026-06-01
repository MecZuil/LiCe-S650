/********************************************************************************
** Form generated from reading UI file 'hp_autoupload_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_AUTOUPLOAD_DIALOG_H
#define UI_HP_AUTOUPLOAD_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Autoupload_Dialog
{
public:
    QFrame *frame;
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *label_3;
    QFrame *frame_2;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QLabel *label_2;
    QFrame *frame_3;
    QPushButton *pushButton_ok_3;
    QLabel *label_5;

    void setupUi(QWidget *Hp_Autoupload_Dialog)
    {
        if (Hp_Autoupload_Dialog->objectName().isEmpty())
            Hp_Autoupload_Dialog->setObjectName(QStringLiteral("Hp_Autoupload_Dialog"));
        Hp_Autoupload_Dialog->resize(800, 480);
        Hp_Autoupload_Dialog->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        frame = new QFrame(Hp_Autoupload_Dialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(140, 310, 531, 161));
        frame->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/format_default_bg.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(40, 70, 451, 21));
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar\357\274\232\357\274\232chunk{\n"
"	background-color:#7CA6C9;\n"
"}"));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 110, 191, 31));
        QFont font;
        font.setPointSize(19);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 511, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_3->setAlignment(Qt::AlignCenter);
        frame_2 = new QFrame(Hp_Autoupload_Dialog);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(130, 140, 551, 161));
        frame_2->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/format_default_bg.png);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButton_ok = new QPushButton(frame_2);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(140, 100, 75, 41));
        QFont font1;
        font1.setPointSize(17);
        pushButton_ok->setFont(font1);
        pushButton_cancel = new QPushButton(frame_2);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(330, 100, 75, 41));
        pushButton_cancel->setFont(font1);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 531, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_2->setAlignment(Qt::AlignCenter);
        frame_3 = new QFrame(Hp_Autoupload_Dialog);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(170, 10, 461, 161));
        frame_3->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/format_default_bg.png);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        pushButton_ok_3 = new QPushButton(frame_3);
        pushButton_ok_3->setObjectName(QStringLiteral("pushButton_ok_3"));
        pushButton_ok_3->setGeometry(QRect(190, 100, 75, 41));
        pushButton_ok_3->setFont(font1);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 30, 441, 41));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_5->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_Autoupload_Dialog);

        QMetaObject::connectSlotsByName(Hp_Autoupload_Dialog);
    } // setupUi

    void retranslateUi(QWidget *Hp_Autoupload_Dialog)
    {
        Hp_Autoupload_Dialog->setWindowTitle(QApplication::translate("Hp_Autoupload_Dialog", "Form", nullptr));
        label->setText(QApplication::translate("Hp_Autoupload_Dialog", "0/0", nullptr));
        label_3->setText(QApplication::translate("Hp_Autoupload_Dialog", "\346\255\243\345\234\250\344\270\212\344\274\240", nullptr));
        pushButton_ok->setText(QApplication::translate("Hp_Autoupload_Dialog", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QApplication::translate("Hp_Autoupload_Dialog", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QApplication::translate("Hp_Autoupload_Dialog", "\347\241\256\350\256\244\346\230\257\345\220\246\344\270\200\351\224\256\344\270\212\344\274\240\357\274\237", nullptr));
        pushButton_ok_3->setText(QApplication::translate("Hp_Autoupload_Dialog", "\347\241\256\345\256\232", nullptr));
        label_5->setText(QApplication::translate("Hp_Autoupload_Dialog", "\344\270\212\344\274\240\350\266\205\346\227\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Autoupload_Dialog: public Ui_Hp_Autoupload_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_AUTOUPLOAD_DIALOG_H
