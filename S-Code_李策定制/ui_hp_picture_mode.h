/********************************************************************************
** Form generated from reading UI file 'hp_picture_mode.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_PICTURE_MODE_H
#define UI_HP_PICTURE_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hp_picture_mode
{
public:
    QFrame *frame;
    QPushButton *pushButton_temp;
    QPushButton *pushButton_row;
    QToolButton *toolButton;
    QLabel *label;

    void setupUi(QWidget *hp_picture_mode)
    {
        if (hp_picture_mode->objectName().isEmpty())
            hp_picture_mode->setObjectName(QStringLiteral("hp_picture_mode"));
        hp_picture_mode->resize(366, 151);
        hp_picture_mode->setStyleSheet(QLatin1String("background-image:url(:/res/res/setting_background.png);\n"
"border:1px solid #2B5C83;"));
        frame = new QFrame(hp_picture_mode);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 366, 151));
        frame->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/setting_background.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_temp = new QPushButton(frame);
        pushButton_temp->setObjectName(QStringLiteral("pushButton_temp"));
        pushButton_temp->setGeometry(QRect(24, 70, 141, 51));
        QFont font;
        font.setPointSize(17);
        pushButton_temp->setFont(font);
        pushButton_temp->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}\n"
"QPushButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        pushButton_row = new QPushButton(frame);
        pushButton_row->setObjectName(QStringLiteral("pushButton_row"));
        pushButton_row->setGeometry(QRect(200, 70, 141, 51));
        pushButton_row->setFont(font);
        pushButton_row->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}\n"
"QPushButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(315, 0, 51, 31));
        QFont font1;
        font1.setPointSize(21);
        toolButton->setFont(font1);
        toolButton->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
""));
        toolButton->setAutoRaise(true);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 251, 41));
        label->setFont(font);
        label->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(hp_picture_mode);

        QMetaObject::connectSlotsByName(hp_picture_mode);
    } // setupUi

    void retranslateUi(QWidget *hp_picture_mode)
    {
        hp_picture_mode->setWindowTitle(QApplication::translate("hp_picture_mode", "Form", nullptr));
        pushButton_temp->setText(QApplication::translate("hp_picture_mode", "\346\270\251\345\272\246\346\265\201", nullptr));
        pushButton_row->setText(QApplication::translate("hp_picture_mode", "\347\201\260\345\272\246\346\265\201", nullptr));
        toolButton->setText(QApplication::translate("hp_picture_mode", "x", nullptr));
        label->setText(QApplication::translate("hp_picture_mode", "\350\257\267\351\200\211\346\213\251\346\250\241\345\274\217\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hp_picture_mode: public Ui_hp_picture_mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_PICTURE_MODE_H
