/********************************************************************************
** Form generated from reading UI file 'hpsetting_adjust.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPSETTING_ADJUST_H
#define UI_HPSETTING_ADJUST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HpSetting_adjust
{
public:
    QFrame *frame;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QWidget *HpSetting_adjust)
    {
        if (HpSetting_adjust->objectName().isEmpty())
            HpSetting_adjust->setObjectName(QStringLiteral("HpSetting_adjust"));
        HpSetting_adjust->resize(240, 106);
        frame = new QFrame(HpSetting_adjust);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 240, 115));
        frame->setStyleSheet(QLatin1String("\n"
"border: 1px solid  #7CA6C9;\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/setting_background.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_ok = new QPushButton(frame);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(30, 30, 75, 41));
        QFont font;
        font.setPointSize(17);
        pushButton_ok->setFont(font);
        pushButton_cancel = new QPushButton(frame);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(135, 30, 75, 41));
        pushButton_cancel->setFont(font);

        retranslateUi(HpSetting_adjust);

        QMetaObject::connectSlotsByName(HpSetting_adjust);
    } // setupUi

    void retranslateUi(QWidget *HpSetting_adjust)
    {
        HpSetting_adjust->setWindowTitle(QApplication::translate("HpSetting_adjust", "Form", nullptr));
        pushButton_ok->setText(QApplication::translate("HpSetting_adjust", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QApplication::translate("HpSetting_adjust", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HpSetting_adjust: public Ui_HpSetting_adjust {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPSETTING_ADJUST_H
