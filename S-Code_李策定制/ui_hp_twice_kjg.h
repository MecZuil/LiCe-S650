/********************************************************************************
** Form generated from reading UI file 'hp_twice_kjg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_TWICE_KJG_H
#define UI_HP_TWICE_KJG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Twice_kjg
{
public:
    QFrame *frame;
    QPushButton *pushButton_close;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_pic;
    QFrame *frame_2;
    QLabel *label_name;

    void setupUi(QWidget *Hp_Twice_kjg)
    {
        if (Hp_Twice_kjg->objectName().isEmpty())
            Hp_Twice_kjg->setObjectName(QStringLiteral("Hp_Twice_kjg"));
        Hp_Twice_kjg->resize(791, 480);
        Hp_Twice_kjg->setStyleSheet(QLatin1String("\n"
"background-image:url(:/res/res/setting_background.png);\n"
"\n"
"border:1px solid #2B5C83;\n"
"\n"
""));
        frame = new QFrame(Hp_Twice_kjg);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 791, 401));
        frame->setStyleSheet(QLatin1String("background-image:url(:/res/res/setting_background.png);\n"
"/*\n"
"border:1px solid #2B5C83;\n"
"*/"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_close = new QPushButton(frame);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setGeometry(QRect(660, 150, 101, 61));
        QFont font;
        font.setPointSize(17);
        pushButton_close->setFont(font);
        pushButton_close->setStyleSheet(QLatin1String("border:1px solid #2B5C83;\n"
"color: rgb(255, 255, 255);"));
        scrollArea = new QScrollArea(frame);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(90, 18, 480, 360));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 478, 358));
        label_pic = new QLabel(scrollAreaWidgetContents);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(0, 0, 480, 360));
        scrollArea->setWidget(scrollAreaWidgetContents);
        frame_2 = new QFrame(Hp_Twice_kjg);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 401, 791, 79));
        frame_2->setStyleSheet(QStringLiteral("border:0px solid #2B5C83;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_name = new QLabel(frame_2);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(13, 10, 771, 51));
        QFont font1;
        font1.setPointSize(15);
        label_name->setFont(font1);
        label_name->setStyleSheet(QLatin1String("/*border-top:1px solid #2B5C83;*/\n"
"background-color: rgb(255, 255, 255,255);\n"
"color: rgb(255, 255, 255);\n"
"border:0px solid #2B5C83;"));
        label_name->setAlignment(Qt::AlignCenter);
        label_name->setWordWrap(true);

        retranslateUi(Hp_Twice_kjg);

        QMetaObject::connectSlotsByName(Hp_Twice_kjg);
    } // setupUi

    void retranslateUi(QWidget *Hp_Twice_kjg)
    {
        Hp_Twice_kjg->setWindowTitle(QApplication::translate("Hp_Twice_kjg", "Form", nullptr));
        pushButton_close->setText(QApplication::translate("Hp_Twice_kjg", "close", nullptr));
        label_pic->setText(QString());
        label_name->setText(QApplication::translate("Hp_Twice_kjg", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Twice_kjg: public Ui_Hp_Twice_kjg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_TWICE_KJG_H
