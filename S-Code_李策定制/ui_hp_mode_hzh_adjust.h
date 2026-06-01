/********************************************************************************
** Form generated from reading UI file 'hp_mode_hzh_adjust.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_MODE_HZH_ADJUST_H
#define UI_HP_MODE_HZH_ADJUST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Mode_Hzh_Adjust
{
public:
    QFrame *frame;
    QToolButton *toolButton_finish;
    QToolButton *toolButton_default;
    QWidget *adjust_area;

    void setupUi(QWidget *Hp_Mode_Hzh_Adjust)
    {
        if (Hp_Mode_Hzh_Adjust->objectName().isEmpty())
            Hp_Mode_Hzh_Adjust->setObjectName(QStringLiteral("Hp_Mode_Hzh_Adjust"));
        Hp_Mode_Hzh_Adjust->resize(800, 480);
        frame = new QFrame(Hp_Mode_Hzh_Adjust);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 160, 480));
        QFont font;
        font.setPointSize(15);
        frame->setFont(font);
        frame->setStyleSheet(QStringLiteral("background-image:url(:/res/res/main_background.png);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        toolButton_finish = new QToolButton(frame);
        toolButton_finish->setObjectName(QStringLiteral("toolButton_finish"));
        toolButton_finish->setGeometry(QRect(0, 0, 160, 70));
        QFont font1;
        font1.setPointSize(17);
        toolButton_finish->setFont(font1);
        toolButton_finish->setFocusPolicy(Qt::NoFocus);
        toolButton_finish->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/setting_back.png);\n"
"}  \n"
""));
        toolButton_finish->setIconSize(QSize(25, 25));
        toolButton_finish->setAutoRaise(true);
        toolButton_finish->setArrowType(Qt::NoArrow);
        toolButton_default = new QToolButton(frame);
        toolButton_default->setObjectName(QStringLiteral("toolButton_default"));
        toolButton_default->setGeometry(QRect(3, 80, 153, 70));
        toolButton_default->setFont(font1);
        toolButton_default->setFocusPolicy(Qt::NoFocus);
        toolButton_default->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_default->setAutoRaise(true);
        adjust_area = new QWidget(Hp_Mode_Hzh_Adjust);
        adjust_area->setObjectName(QStringLiteral("adjust_area"));
        adjust_area->setGeometry(QRect(160, 0, 640, 480));
        adjust_area->setFont(font);
        adjust_area->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));

        retranslateUi(Hp_Mode_Hzh_Adjust);

        QMetaObject::connectSlotsByName(Hp_Mode_Hzh_Adjust);
    } // setupUi

    void retranslateUi(QWidget *Hp_Mode_Hzh_Adjust)
    {
        Hp_Mode_Hzh_Adjust->setWindowTitle(QApplication::translate("Hp_Mode_Hzh_Adjust", "Form", nullptr));
        toolButton_finish->setText(QString());
        toolButton_default->setText(QApplication::translate("Hp_Mode_Hzh_Adjust", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Mode_Hzh_Adjust: public Ui_Hp_Mode_Hzh_Adjust {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_MODE_HZH_ADJUST_H
