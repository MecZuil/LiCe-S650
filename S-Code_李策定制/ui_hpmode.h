/********************************************************************************
** Form generated from reading UI file 'hpmode.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPMODE_H
#define UI_HPMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "hp_handfution.h"

QT_BEGIN_NAMESPACE

class Ui_HpMode
{
public:
    QFrame *frame;
    QToolButton *toolButton_hongwai;
    QToolButton *toolButton_kejian;
    QToolButton *toolButton_msx;
    QToolButton *toolButton_hzh;
    QToolButton *toolButton_rdj;
    QFrame *frame_pip;
    QToolButton *toolButton_auto;
    QToolButton *toolButton_1_2;
    QToolButton *toolButton_1_4;
    QToolButton *toolButton_3_4;
    QToolButton *toolButton_rect_adjust;
    QFrame *frame_rdj;
    QToolButton *toolButton_rdj_adjust;
    QFrame *frame_2;
    QToolButton *toolButton_handfusion;
    QFrame *frame_handfution;
    Hp_HandFution *widget_handfution;
    QFrame *frame_rdj_2;
    QToolButton *toolButton_rdj_adjust_2;
    QButtonGroup *buttonGroup_pip;
    QButtonGroup *buttonGroup_mode;

    void setupUi(QWidget *HpMode)
    {
        if (HpMode->objectName().isEmpty())
            HpMode->setObjectName(QStringLiteral("HpMode"));
        HpMode->setWindowModality(Qt::NonModal);
        HpMode->resize(520, 425);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HpMode->sizePolicy().hasHeightForWidth());
        HpMode->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        HpMode->setFont(font);
        HpMode->setWindowOpacity(1);
        HpMode->setAutoFillBackground(false);
        HpMode->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        frame = new QFrame(HpMode);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(143, 325, 360, 69));
        frame->setFont(font);
        frame->setStyleSheet(QStringLiteral("background-image:url(:/res/res/mode_bg.png);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        toolButton_hongwai = new QToolButton(frame);
        buttonGroup_mode = new QButtonGroup(HpMode);
        buttonGroup_mode->setObjectName(QStringLiteral("buttonGroup_mode"));
        buttonGroup_mode->addButton(toolButton_hongwai);
        toolButton_hongwai->setObjectName(QStringLiteral("toolButton_hongwai"));
        toolButton_hongwai->setGeometry(QRect(2, 0, 69, 69));
        QFont font1;
        font1.setPointSize(17);
        toolButton_hongwai->setFont(font1);
        toolButton_hongwai->setFocusPolicy(Qt::NoFocus);
        toolButton_hongwai->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_hongwai_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_hongwai_s.png);\n"
"}"));
        toolButton_hongwai->setCheckable(true);
        toolButton_hongwai->setAutoRaise(true);
        toolButton_kejian = new QToolButton(frame);
        buttonGroup_mode->addButton(toolButton_kejian);
        toolButton_kejian->setObjectName(QStringLiteral("toolButton_kejian"));
        toolButton_kejian->setGeometry(QRect(74, 0, 69, 69));
        toolButton_kejian->setFont(font1);
        toolButton_kejian->setFocusPolicy(Qt::NoFocus);
        toolButton_kejian->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_kejian_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_kejian_s.png);\n"
"}"));
        toolButton_kejian->setCheckable(true);
        toolButton_kejian->setAutoRaise(true);
        toolButton_msx = new QToolButton(frame);
        buttonGroup_mode->addButton(toolButton_msx);
        toolButton_msx->setObjectName(QStringLiteral("toolButton_msx"));
        toolButton_msx->setGeometry(QRect(146, 0, 69, 69));
        toolButton_msx->setFont(font1);
        toolButton_msx->setFocusPolicy(Qt::NoFocus);
        toolButton_msx->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_msx_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_msx_s.png);\n"
"}"));
        toolButton_msx->setCheckable(true);
        toolButton_msx->setAutoRaise(true);
        toolButton_hzh = new QToolButton(frame);
        buttonGroup_mode->addButton(toolButton_hzh);
        toolButton_hzh->setObjectName(QStringLiteral("toolButton_hzh"));
        toolButton_hzh->setGeometry(QRect(218, 0, 69, 69));
        toolButton_hzh->setFont(font1);
        toolButton_hzh->setFocusPolicy(Qt::NoFocus);
        toolButton_hzh->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_hzh_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_hzh_s.png);\n"
"}"));
        toolButton_hzh->setCheckable(true);
        toolButton_hzh->setAutoRaise(true);
        toolButton_rdj = new QToolButton(frame);
        buttonGroup_mode->addButton(toolButton_rdj);
        toolButton_rdj->setObjectName(QStringLiteral("toolButton_rdj"));
        toolButton_rdj->setGeometry(QRect(290, 0, 69, 69));
        toolButton_rdj->setFont(font1);
        toolButton_rdj->setFocusPolicy(Qt::NoFocus);
        toolButton_rdj->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_rdj_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_rdj_s.png);\n"
"}"));
        toolButton_rdj->setCheckable(true);
        toolButton_rdj->setAutoRaise(true);
        frame_pip = new QFrame(HpMode);
        frame_pip->setObjectName(QStringLiteral("frame_pip"));
        frame_pip->setGeometry(QRect(150, 1, 358, 69));
        frame_pip->setFont(font);
        frame_pip->setStyleSheet(QStringLiteral("background-image:url(:/res/res/mode_bg.png);"));
        frame_pip->setFrameShape(QFrame::NoFrame);
        frame_pip->setFrameShadow(QFrame::Raised);
        toolButton_auto = new QToolButton(frame_pip);
        buttonGroup_pip = new QButtonGroup(HpMode);
        buttonGroup_pip->setObjectName(QStringLiteral("buttonGroup_pip"));
        buttonGroup_pip->addButton(toolButton_auto);
        toolButton_auto->setObjectName(QStringLiteral("toolButton_auto"));
        toolButton_auto->setGeometry(QRect(0, 0, 69, 70));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(17);
        toolButton_auto->setFont(font2);
        toolButton_auto->setFocusPolicy(Qt::NoFocus);
        toolButton_auto->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_auto->setCheckable(true);
        toolButton_1_2 = new QToolButton(frame_pip);
        buttonGroup_pip->addButton(toolButton_1_2);
        toolButton_1_2->setObjectName(QStringLiteral("toolButton_1_2"));
        toolButton_1_2->setGeometry(QRect(72, 0, 69, 70));
        toolButton_1_2->setFont(font2);
        toolButton_1_2->setFocusPolicy(Qt::NoFocus);
        toolButton_1_2->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_1_2->setCheckable(true);
        toolButton_1_2->setAutoRaise(true);
        toolButton_1_4 = new QToolButton(frame_pip);
        buttonGroup_pip->addButton(toolButton_1_4);
        toolButton_1_4->setObjectName(QStringLiteral("toolButton_1_4"));
        toolButton_1_4->setGeometry(QRect(144, 0, 69, 70));
        toolButton_1_4->setFont(font2);
        toolButton_1_4->setFocusPolicy(Qt::NoFocus);
        toolButton_1_4->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_1_4->setCheckable(true);
        toolButton_1_4->setAutoRaise(true);
        toolButton_3_4 = new QToolButton(frame_pip);
        buttonGroup_pip->addButton(toolButton_3_4);
        toolButton_3_4->setObjectName(QStringLiteral("toolButton_3_4"));
        toolButton_3_4->setGeometry(QRect(216, 0, 69, 70));
        toolButton_3_4->setFont(font2);
        toolButton_3_4->setFocusPolicy(Qt::NoFocus);
        toolButton_3_4->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_3_4->setCheckable(true);
        toolButton_3_4->setAutoRaise(true);
        toolButton_rect_adjust = new QToolButton(frame_pip);
        toolButton_rect_adjust->setObjectName(QStringLiteral("toolButton_rect_adjust"));
        toolButton_rect_adjust->setGeometry(QRect(288, 0, 69, 70));
        toolButton_rect_adjust->setFont(font2);
        toolButton_rect_adjust->setFocusPolicy(Qt::NoFocus);
        toolButton_rect_adjust->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_rect_adjust->setCheckable(false);
        toolButton_rect_adjust->setAutoRaise(true);
        frame_rdj = new QFrame(HpMode);
        frame_rdj->setObjectName(QStringLiteral("frame_rdj"));
        frame_rdj->setGeometry(QRect(340, 110, 69, 69));
        frame_rdj->setFont(font);
        frame_rdj->setStyleSheet(QStringLiteral("background-image:url(:/res/res/mode_bg.png);"));
        frame_rdj->setFrameShape(QFrame::NoFrame);
        frame_rdj->setFrameShadow(QFrame::Raised);
        toolButton_rdj_adjust = new QToolButton(frame_rdj);
        buttonGroup_mode->addButton(toolButton_rdj_adjust);
        toolButton_rdj_adjust->setObjectName(QStringLiteral("toolButton_rdj_adjust"));
        toolButton_rdj_adjust->setGeometry(QRect(0, 0, 69, 69));
        toolButton_rdj_adjust->setFont(font2);
        toolButton_rdj_adjust->setFocusPolicy(Qt::NoFocus);
        toolButton_rdj_adjust->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_rdj_adjust->setCheckable(false);
        toolButton_rdj_adjust->setAutoRaise(true);
        frame_2 = new QFrame(HpMode);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(75, 325, 69, 69));
        frame_2->setFont(font);
        frame_2->setStyleSheet(QStringLiteral("background-image:url(:/res/res/mode_bg.png);"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        toolButton_handfusion = new QToolButton(frame_2);
        toolButton_handfusion->setObjectName(QStringLiteral("toolButton_handfusion"));
        toolButton_handfusion->setGeometry(QRect(0, 0, 69, 69));
        toolButton_handfusion->setFont(font1);
        toolButton_handfusion->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image: url(:/res/res/hangfution_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/hangfution_s.png);\n"
"}"));
        toolButton_handfusion->setCheckable(true);
        toolButton_handfusion->setAutoRaise(true);
        frame_handfution = new QFrame(HpMode);
        frame_handfution->setObjectName(QStringLiteral("frame_handfution"));
        frame_handfution->setGeometry(QRect(80, 75, 61, 241));
        frame_handfution->setFont(font);
        frame_handfution->setStyleSheet(QStringLiteral(""));
        frame_handfution->setFrameShape(QFrame::NoFrame);
        frame_handfution->setFrameShadow(QFrame::Plain);
        widget_handfution = new Hp_HandFution(frame_handfution);
        widget_handfution->setObjectName(QStringLiteral("widget_handfution"));
        widget_handfution->setGeometry(QRect(0, 0, 61, 241));
        widget_handfution->setFont(font1);
        frame_rdj_2 = new QFrame(HpMode);
        frame_rdj_2->setObjectName(QStringLiteral("frame_rdj_2"));
        frame_rdj_2->setGeometry(QRect(295, 1, 69, 69));
        frame_rdj_2->setFont(font);
        frame_rdj_2->setStyleSheet(QStringLiteral("background-image:url(:/res/res/mode_bg.png);"));
        frame_rdj_2->setFrameShape(QFrame::NoFrame);
        frame_rdj_2->setFrameShadow(QFrame::Raised);
        toolButton_rdj_adjust_2 = new QToolButton(frame_rdj_2);
        toolButton_rdj_adjust_2->setObjectName(QStringLiteral("toolButton_rdj_adjust_2"));
        toolButton_rdj_adjust_2->setGeometry(QRect(0, 0, 69, 69));
        toolButton_rdj_adjust_2->setFont(font2);
        toolButton_rdj_adjust_2->setFocusPolicy(Qt::NoFocus);
        toolButton_rdj_adjust_2->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_rdj_adjust_2->setCheckable(false);
        toolButton_rdj_adjust_2->setAutoRaise(true);

        retranslateUi(HpMode);

        QMetaObject::connectSlotsByName(HpMode);
    } // setupUi

    void retranslateUi(QWidget *HpMode)
    {
        HpMode->setWindowTitle(QApplication::translate("HpMode", "Form", nullptr));
        toolButton_hongwai->setText(QString());
        toolButton_kejian->setText(QString());
        toolButton_msx->setText(QString());
        toolButton_hzh->setText(QString());
        toolButton_rdj->setText(QString());
        toolButton_auto->setText(QApplication::translate("HpMode", "\350\207\252\345\212\250", nullptr));
        toolButton_1_2->setText(QApplication::translate("HpMode", "1/2", nullptr));
        toolButton_1_4->setText(QApplication::translate("HpMode", "1/4", nullptr));
        toolButton_3_4->setText(QApplication::translate("HpMode", "3/4", nullptr));
        toolButton_rect_adjust->setText(QApplication::translate("HpMode", "\350\260\203\346\225\264", nullptr));
        toolButton_rdj_adjust->setText(QApplication::translate("HpMode", "\350\260\203\346\225\264", nullptr));
        toolButton_handfusion->setText(QString());
        toolButton_rdj_adjust_2->setText(QApplication::translate("HpMode", "\350\260\203\346\225\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HpMode: public Ui_HpMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPMODE_H
