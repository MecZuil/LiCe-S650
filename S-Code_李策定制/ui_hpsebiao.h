/********************************************************************************
** Form generated from reading UI file 'hpsebiao.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPSEBIAO_H
#define UI_HPSEBIAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HpSebiao
{
public:
    QFrame *frame_2;
    QToolButton *toolButton_sb01;
    QToolButton *toolButton_sb12;
    QToolButton *toolButton_sb11;
    QToolButton *toolButton_sb10;
    QToolButton *toolButton_sb09;
    QToolButton *toolButton_sb08;
    QToolButton *toolButton_sb07;
    QToolButton *toolButton_sb06;
    QToolButton *toolButton_sb05;
    QToolButton *toolButton_sb04;
    QToolButton *toolButton_sb03;
    QToolButton *toolButton_sb02;
    QToolButton *toolButton_sb13;
    QToolButton *toolButton_sb14;
    QToolButton *toolButton_sb15;
    QToolButton *toolButton_sb16;
    QToolButton *toolButton_sb17;
    QCheckBox *checkBox_reverse;
    QLabel *label;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *HpSebiao)
    {
        if (HpSebiao->objectName().isEmpty())
            HpSebiao->setObjectName(QStringLiteral("HpSebiao"));
        HpSebiao->resize(609, 173);
        HpSebiao->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        frame_2 = new QFrame(HpSebiao);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 40, 609, 133));
        frame_2->setStyleSheet(QStringLiteral("background-image:url(:/res/res/sebiao_bg.png);"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        toolButton_sb01 = new QToolButton(frame_2);
        buttonGroup = new QButtonGroup(HpSebiao);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(toolButton_sb01);
        toolButton_sb01->setObjectName(QStringLiteral("toolButton_sb01"));
        toolButton_sb01->setGeometry(QRect(0, 0, 65, 65));
        toolButton_sb01->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao01_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao01_s.png);\n"
"}"));
        toolButton_sb01->setCheckable(true);
        toolButton_sb01->setAutoRaise(true);
        toolButton_sb12 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb12);
        toolButton_sb12->setObjectName(QStringLiteral("toolButton_sb12"));
        toolButton_sb12->setGeometry(QRect(68, 0, 65, 65));
        toolButton_sb12->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao02_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao02_s.png);\n"
"}"));
        toolButton_sb12->setCheckable(true);
        toolButton_sb12->setAutoRaise(true);
        toolButton_sb11 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb11);
        toolButton_sb11->setObjectName(QStringLiteral("toolButton_sb11"));
        toolButton_sb11->setGeometry(QRect(136, 0, 65, 65));
        toolButton_sb11->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao03_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao03_s.png);\n"
"}"));
        toolButton_sb11->setCheckable(true);
        toolButton_sb11->setAutoRaise(true);
        toolButton_sb10 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb10);
        toolButton_sb10->setObjectName(QStringLiteral("toolButton_sb10"));
        toolButton_sb10->setGeometry(QRect(204, 0, 65, 65));
        toolButton_sb10->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao04_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao04_s.png);\n"
"}"));
        toolButton_sb10->setCheckable(true);
        toolButton_sb10->setAutoRaise(true);
        toolButton_sb09 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb09);
        toolButton_sb09->setObjectName(QStringLiteral("toolButton_sb09"));
        toolButton_sb09->setGeometry(QRect(272, 0, 65, 65));
        toolButton_sb09->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao05_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao05_s.png);\n"
"}"));
        toolButton_sb09->setCheckable(true);
        toolButton_sb09->setAutoRaise(true);
        toolButton_sb08 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb08);
        toolButton_sb08->setObjectName(QStringLiteral("toolButton_sb08"));
        toolButton_sb08->setGeometry(QRect(340, 0, 65, 65));
        toolButton_sb08->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao06_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao06_s.png);\n"
"}"));
        toolButton_sb08->setCheckable(true);
        toolButton_sb08->setAutoRaise(true);
        toolButton_sb07 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb07);
        toolButton_sb07->setObjectName(QStringLiteral("toolButton_sb07"));
        toolButton_sb07->setGeometry(QRect(408, 0, 65, 65));
        toolButton_sb07->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao07_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao07_s.png);\n"
"}"));
        toolButton_sb07->setCheckable(true);
        toolButton_sb07->setAutoRaise(true);
        toolButton_sb06 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb06);
        toolButton_sb06->setObjectName(QStringLiteral("toolButton_sb06"));
        toolButton_sb06->setGeometry(QRect(476, 0, 65, 65));
        toolButton_sb06->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao08_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao08_s.png);\n"
"}"));
        toolButton_sb06->setCheckable(true);
        toolButton_sb06->setAutoRaise(true);
        toolButton_sb05 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb05);
        toolButton_sb05->setObjectName(QStringLiteral("toolButton_sb05"));
        toolButton_sb05->setGeometry(QRect(544, 0, 65, 65));
        toolButton_sb05->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao09_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao09_s.png);\n"
"}"));
        toolButton_sb05->setCheckable(true);
        toolButton_sb05->setAutoRaise(true);
        toolButton_sb04 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb04);
        toolButton_sb04->setObjectName(QStringLiteral("toolButton_sb04"));
        toolButton_sb04->setGeometry(QRect(0, 68, 65, 65));
        toolButton_sb04->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao10_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao10_s.png);\n"
"}"));
        toolButton_sb04->setCheckable(true);
        toolButton_sb04->setAutoRaise(true);
        toolButton_sb03 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb03);
        toolButton_sb03->setObjectName(QStringLiteral("toolButton_sb03"));
        toolButton_sb03->setGeometry(QRect(68, 68, 65, 65));
        toolButton_sb03->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao11_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao11_s.png);\n"
"}"));
        toolButton_sb03->setCheckable(true);
        toolButton_sb03->setAutoRaise(true);
        toolButton_sb02 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb02);
        toolButton_sb02->setObjectName(QStringLiteral("toolButton_sb02"));
        toolButton_sb02->setGeometry(QRect(136, 68, 65, 65));
        toolButton_sb02->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao12_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao12_s.png);\n"
"}"));
        toolButton_sb02->setCheckable(true);
        toolButton_sb02->setAutoRaise(true);
        toolButton_sb13 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb13);
        toolButton_sb13->setObjectName(QStringLiteral("toolButton_sb13"));
        toolButton_sb13->setGeometry(QRect(204, 68, 65, 65));
        toolButton_sb13->setStyleSheet(QLatin1String("QToolButton {\n"
"	border-image: url(:/res/res/sebiao13_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"	border-image: url(:/res/res/sebiao13_s.png);\n"
"}"));
        toolButton_sb13->setCheckable(true);
        toolButton_sb13->setAutoRaise(true);
        toolButton_sb14 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb14);
        toolButton_sb14->setObjectName(QStringLiteral("toolButton_sb14"));
        toolButton_sb14->setGeometry(QRect(272, 68, 65, 65));
        toolButton_sb14->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao14_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao14_s.png);\n"
"}"));
        toolButton_sb14->setCheckable(true);
        toolButton_sb14->setAutoRaise(true);
        toolButton_sb15 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb15);
        toolButton_sb15->setObjectName(QStringLiteral("toolButton_sb15"));
        toolButton_sb15->setGeometry(QRect(340, 68, 65, 65));
        toolButton_sb15->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao15_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao15_s.png);\n"
"}"));
        toolButton_sb15->setCheckable(true);
        toolButton_sb15->setAutoRaise(true);
        toolButton_sb16 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb16);
        toolButton_sb16->setObjectName(QStringLiteral("toolButton_sb16"));
        toolButton_sb16->setGeometry(QRect(408, 68, 65, 65));
        toolButton_sb16->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao16_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao16_s.png);\n"
"}"));
        toolButton_sb16->setCheckable(true);
        toolButton_sb16->setAutoRaise(true);
        toolButton_sb17 = new QToolButton(frame_2);
        buttonGroup->addButton(toolButton_sb17);
        toolButton_sb17->setObjectName(QStringLiteral("toolButton_sb17"));
        toolButton_sb17->setGeometry(QRect(476, 68, 65, 65));
        toolButton_sb17->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/sebiao17_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/sebiao17_s.png);\n"
"}"));
        toolButton_sb17->setCheckable(true);
        toolButton_sb17->setAutoRaise(true);
        checkBox_reverse = new QCheckBox(HpSebiao);
        checkBox_reverse->setObjectName(QStringLiteral("checkBox_reverse"));
        checkBox_reverse->setEnabled(true);
        checkBox_reverse->setGeometry(QRect(90, 0, 70, 41));
        QFont font;
        font.setPointSize(17);
        checkBox_reverse->setFont(font);
        checkBox_reverse->setFocusPolicy(Qt::NoFocus);
        checkBox_reverse->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/res/res/switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"     image: url(:/res/res/switch_on.png);\n"
"}\n"
"\n"
"\n"
""));
        label = new QLabel(HpSebiao);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 81, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(HpSebiao);

        QMetaObject::connectSlotsByName(HpSebiao);
    } // setupUi

    void retranslateUi(QWidget *HpSebiao)
    {
        HpSebiao->setWindowTitle(QApplication::translate("HpSebiao", "Form", nullptr));
        toolButton_sb01->setText(QString());
        toolButton_sb12->setText(QString());
        toolButton_sb11->setText(QString());
        toolButton_sb10->setText(QString());
        toolButton_sb09->setText(QString());
        toolButton_sb08->setText(QString());
        toolButton_sb07->setText(QString());
        toolButton_sb06->setText(QString());
        toolButton_sb05->setText(QString());
        toolButton_sb04->setText(QString());
        toolButton_sb03->setText(QString());
        toolButton_sb02->setText(QString());
        toolButton_sb13->setText(QString());
        toolButton_sb14->setText(QString());
        toolButton_sb15->setText(QString());
        toolButton_sb16->setText(QString());
        toolButton_sb17->setText(QString());
        checkBox_reverse->setText(QString());
        label->setText(QApplication::translate("HpSebiao", "\345\217\215\350\275\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HpSebiao: public Ui_HpSebiao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPSEBIAO_H
