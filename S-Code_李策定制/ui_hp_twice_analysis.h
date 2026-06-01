/********************************************************************************
** Form generated from reading UI file 'hp_twice_analysis.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_TWICE_ANALYSIS_H
#define UI_HP_TWICE_ANALYSIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Twice_Analysis
{
public:
    QToolButton *toolButton;
    QFrame *frame;
    QToolButton *toolButton_text;
    QToolButton *toolButton_voice_r;
    QToolButton *toolButton_voice_p;
    QToolButton *toolButton_save;
    QToolButton *toolButton_cancle;
    QToolButton *toolButton_text_2;
    QProgressBar *progressBar;
    QLabel *label_time;

    void setupUi(QWidget *Hp_Twice_Analysis)
    {
        if (Hp_Twice_Analysis->objectName().isEmpty())
            Hp_Twice_Analysis->setObjectName(QStringLiteral("Hp_Twice_Analysis"));
        Hp_Twice_Analysis->resize(435, 102);
        Hp_Twice_Analysis->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        toolButton = new QToolButton(Hp_Twice_Analysis);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setEnabled(true);
        toolButton->setGeometry(QRect(0, 0, 60, 60));
        toolButton->setMinimumSize(QSize(0, 0));
        toolButton->setMaximumSize(QSize(1777, 1777));
        QFont font;
        font.setPointSize(17);
        toolButton->setFont(font);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/next_page_n.png);\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/pre_page_n.png);\n"
"}\n"
"\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/next_page_d.png);\n"
"}"));
        toolButton->setCheckable(true);
        frame = new QFrame(Hp_Twice_Analysis);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(60, 0, 375, 60));
        frame->setMinimumSize(QSize(0, 0));
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setStyleSheet(QStringLiteral("background-image:url(:/res/res/mode_bg.png);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        toolButton_text = new QToolButton(frame);
        toolButton_text->setObjectName(QStringLiteral("toolButton_text"));
        toolButton_text->setGeometry(QRect(0, 0, 60, 60));
        toolButton_text->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/twice_text_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/twice_text_s.png);\n"
"}\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/twice_text_d.png);\n"
"}"));
        toolButton_voice_r = new QToolButton(frame);
        toolButton_voice_r->setObjectName(QStringLiteral("toolButton_voice_r"));
        toolButton_voice_r->setGeometry(QRect(63, 0, 60, 60));
        toolButton_voice_r->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/twice_voice_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/twice_voice_s.png);\n"
"}\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/twice_voice_d.png);\n"
"}"));
        toolButton_voice_r->setCheckable(true);
        toolButton_voice_p = new QToolButton(frame);
        toolButton_voice_p->setObjectName(QStringLiteral("toolButton_voice_p"));
        toolButton_voice_p->setGeometry(QRect(126, 0, 60, 60));
        toolButton_voice_p->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/twice_voice_play_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/twice_voice_play_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/twice_voice_play_d.png);\n"
"}"));
        toolButton_voice_p->setCheckable(true);
        toolButton_save = new QToolButton(frame);
        toolButton_save->setObjectName(QStringLiteral("toolButton_save"));
        toolButton_save->setGeometry(QRect(189, 0, 60, 60));
        toolButton_save->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/twice_save_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/twice_save_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/twice_save_d.png);\n"
"}"));
        toolButton_cancle = new QToolButton(frame);
        toolButton_cancle->setObjectName(QStringLiteral("toolButton_cancle"));
        toolButton_cancle->setGeometry(QRect(252, 0, 60, 60));
        QFont font1;
        font1.setPointSize(15);
        toolButton_cancle->setFont(font1);
        toolButton_cancle->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/twice_cancle_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/twice_cancle_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/twice_cancle_d.png);\n"
"}"));
        toolButton_text_2 = new QToolButton(frame);
        toolButton_text_2->setObjectName(QStringLiteral("toolButton_text_2"));
        toolButton_text_2->setGeometry(QRect(315, 0, 60, 60));
        toolButton_text_2->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/twice_draw_3n.png);\n"
"}  \n"
" \n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/twice_draw_3s.png);\n"
"}"));
        toolButton_text_2->setCheckable(true);
        progressBar = new QProgressBar(Hp_Twice_Analysis);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(59, 61, 313, 41));
        progressBar->setFont(font);
        progressBar->setStyleSheet(QLatin1String("\n"
"QProgressBar {\n"
"    border: 1px solid #2B5C83;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #7CA6C9;\n"
"    width: 1px;\n"
"\n"
"}"));
        progressBar->setMaximum(60);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        label_time = new QLabel(Hp_Twice_Analysis);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setGeometry(QRect(370, 60, 61, 41));
        label_time->setFont(font1);
        label_time->setStyleSheet(QLatin1String("background-color: transparent;\n"
"color: \"#7CA6C9\";"));
        label_time->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_Twice_Analysis);
        QObject::connect(toolButton_voice_p, SIGNAL(toggled(bool)), toolButton_voice_r, SLOT(setDisabled(bool)));
        QObject::connect(toolButton_voice_p, SIGNAL(toggled(bool)), toolButton_text, SLOT(setDisabled(bool)));
        QObject::connect(toolButton_voice_p, SIGNAL(toggled(bool)), toolButton_save, SLOT(setDisabled(bool)));
        QObject::connect(toolButton_voice_p, SIGNAL(toggled(bool)), toolButton_cancle, SLOT(setDisabled(bool)));
        QObject::connect(toolButton_voice_r, SIGNAL(toggled(bool)), toolButton_cancle, SLOT(setDisabled(bool)));
        QObject::connect(toolButton_voice_r, SIGNAL(toggled(bool)), toolButton_save, SLOT(setDisabled(bool)));
        QObject::connect(toolButton_voice_r, SIGNAL(toggled(bool)), toolButton_text, SLOT(setDisabled(bool)));
        QObject::connect(toolButton_voice_r, SIGNAL(toggled(bool)), toolButton_voice_p, SLOT(setDisabled(bool)));
        QObject::connect(toolButton_voice_p, SIGNAL(toggled(bool)), progressBar, SLOT(setVisible(bool)));
        QObject::connect(toolButton_voice_r, SIGNAL(toggled(bool)), progressBar, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(Hp_Twice_Analysis);
    } // setupUi

    void retranslateUi(QWidget *Hp_Twice_Analysis)
    {
        Hp_Twice_Analysis->setWindowTitle(QApplication::translate("Hp_Twice_Analysis", "Form", nullptr));
        toolButton->setText(QString());
        toolButton_text->setText(QString());
        toolButton_voice_r->setText(QString());
        toolButton_voice_p->setText(QString());
        toolButton_save->setText(QString());
        toolButton_cancle->setText(QString());
        toolButton_text_2->setText(QString());
        label_time->setText(QApplication::translate("Hp_Twice_Analysis", "0s", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Twice_Analysis: public Ui_Hp_Twice_Analysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_TWICE_ANALYSIS_H
