/********************************************************************************
** Form generated from reading UI file 'hp_avi_mode.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_AVI_MODE_H
#define UI_HP_AVI_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HP_Avi_mode
{
public:
    QFrame *frame;
    QPushButton *pushButton_avi;
    QPushButton *pushButton_hir;
    QToolButton *toolButton;
    QLabel *label;

    void setupUi(QWidget *HP_Avi_mode)
    {
        if (HP_Avi_mode->objectName().isEmpty())
            HP_Avi_mode->setObjectName(QStringLiteral("HP_Avi_mode"));
        HP_Avi_mode->resize(366, 151);
        HP_Avi_mode->setStyleSheet(QLatin1String("background-image:url(:/res/res/format_default_bg.png);\n"
"border:1px solid #2B5C83;"));
        frame = new QFrame(HP_Avi_mode);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 366, 151));
        frame->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/format_default_bg.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_avi = new QPushButton(frame);
        pushButton_avi->setObjectName(QStringLiteral("pushButton_avi"));
        pushButton_avi->setGeometry(QRect(24, 70, 141, 51));
        QFont font;
        font.setPointSize(17);
        pushButton_avi->setFont(font);
        pushButton_avi->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}\n"
"QPushButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        pushButton_hir = new QPushButton(frame);
        pushButton_hir->setObjectName(QStringLiteral("pushButton_hir"));
        pushButton_hir->setGeometry(QRect(200, 70, 141, 51));
        pushButton_hir->setFont(font);
        pushButton_hir->setStyleSheet(QLatin1String("QPushButton{\n"
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
"color:#7CA6C9;"));
        toolButton->setAutoRaise(true);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 251, 41));
        label->setFont(font);
        label->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(HP_Avi_mode);

        QMetaObject::connectSlotsByName(HP_Avi_mode);
    } // setupUi

    void retranslateUi(QWidget *HP_Avi_mode)
    {
        HP_Avi_mode->setWindowTitle(QApplication::translate("HP_Avi_mode", "Form", nullptr));
        pushButton_avi->setText(QApplication::translate("HP_Avi_mode", "\350\247\206\351\242\221\346\265\201", nullptr));
        pushButton_hir->setText(QApplication::translate("HP_Avi_mode", "\350\276\220\345\260\204\346\265\201", nullptr));
        toolButton->setText(QApplication::translate("HP_Avi_mode", "x", nullptr));
        label->setText(QApplication::translate("HP_Avi_mode", "\350\257\267\351\200\211\346\213\251\346\250\241\345\274\217\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HP_Avi_mode: public Ui_HP_Avi_mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_AVI_MODE_H
