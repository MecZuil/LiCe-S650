/********************************************************************************
** Form generated from reading UI file 'hp_common_dialog_select.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_COMMON_DIALOG_SELECT_H
#define UI_HP_COMMON_DIALOG_SELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hp_common_dialog_select
{
public:
    QFrame *frame;
    QPushButton *pushButton_task;
    QPushButton *pushButton_normal;
    QLabel *label;
    QPushButton *pushButton_cancel;

    void setupUi(QWidget *hp_common_dialog_select)
    {
        if (hp_common_dialog_select->objectName().isEmpty())
            hp_common_dialog_select->setObjectName(QStringLiteral("hp_common_dialog_select"));
        hp_common_dialog_select->resize(800, 480);
        frame = new QFrame(hp_common_dialog_select);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(120, 150, 551, 161));
        frame->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/setting_background.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_task = new QPushButton(frame);
        pushButton_task->setObjectName(QStringLiteral("pushButton_task"));
        pushButton_task->setGeometry(QRect(90, 100, 75, 41));
        QFont font;
        font.setPointSize(17);
        pushButton_task->setFont(font);
        pushButton_task->setStyleSheet(QLatin1String("border: 0px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/setting_background.png);"));
        pushButton_normal = new QPushButton(frame);
        pushButton_normal->setObjectName(QStringLiteral("pushButton_normal"));
        pushButton_normal->setGeometry(QRect(240, 100, 75, 41));
        pushButton_normal->setFont(font);
        pushButton_normal->setStyleSheet(QLatin1String("border: 0px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/setting_background.png);"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 531, 41));
        QFont font1;
        font1.setPointSize(19);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label->setAlignment(Qt::AlignCenter);
        pushButton_cancel = new QPushButton(frame);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(390, 100, 75, 41));
        pushButton_cancel->setFont(font);
        pushButton_cancel->setStyleSheet(QLatin1String("border: 0px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/setting_background.png);"));

        retranslateUi(hp_common_dialog_select);

        QMetaObject::connectSlotsByName(hp_common_dialog_select);
    } // setupUi

    void retranslateUi(QWidget *hp_common_dialog_select)
    {
        hp_common_dialog_select->setWindowTitle(QApplication::translate("hp_common_dialog_select", "Form", nullptr));
        pushButton_task->setText(QApplication::translate("hp_common_dialog_select", "\345\217\260\350\264\246", nullptr));
        pushButton_normal->setText(QApplication::translate("hp_common_dialog_select", "\346\231\256\351\200\232", nullptr));
        label->setText(QApplication::translate("hp_common_dialog_select", "\350\257\267\351\200\211\346\213\251\351\234\200\350\246\201\344\270\212\344\274\240\347\232\204\345\233\276\347\211\207", nullptr));
        pushButton_cancel->setText(QApplication::translate("hp_common_dialog_select", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hp_common_dialog_select: public Ui_hp_common_dialog_select {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_COMMON_DIALOG_SELECT_H
