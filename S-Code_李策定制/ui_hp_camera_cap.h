/********************************************************************************
** Form generated from reading UI file 'hp_camera_cap.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_CAMERA_CAP_H
#define UI_HP_CAMERA_CAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Camera_Cap
{
public:
    QFrame *frame;
    QProgressBar *progressBar;
    QLabel *label;
    QFrame *frame_2;
    QToolButton *toolButton_text;
    QToolButton *toolButton_voice;
    QToolButton *toolButton_save;
    QToolButton *toolButton_cancel;
    QToolButton *toolButton_error;
    QLabel *label_jpgname_2;
    QLabel *label_jpgname;
    QLabel *flag_warning;
    QLabel *title_warning;
    QLabel *text_warning;
    QLabel *label_time;

    void setupUi(QWidget *Hp_Camera_Cap)
    {
        if (Hp_Camera_Cap->objectName().isEmpty())
            Hp_Camera_Cap->setObjectName(QStringLiteral("Hp_Camera_Cap"));
        Hp_Camera_Cap->resize(640, 480);
        Hp_Camera_Cap->setWindowOpacity(1);
        Hp_Camera_Cap->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        frame = new QFrame(Hp_Camera_Cap);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(183, 206, 275, 201));
        QFont font;
        font.setPointSize(15);
        frame->setFont(font);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(0, 170, 269, 28));
        QFont font1;
        font1.setPointSize(17);
        progressBar->setFont(font1);
        progressBar->setStyleSheet(QLatin1String("\n"
"\n"
"QProgressBar {\n"
"    border: 1px solid #2B5C83;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #7CA6C9;\n"
"    width: 1px;\n"
"\n"
"}\n"
""));
        progressBar->setMinimum(0);
        progressBar->setMaximum(59);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(false);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 269, 28));
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label->setAlignment(Qt::AlignCenter);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 100, 271, 65));
        frame_2->setFont(font);
        frame_2->setStyleSheet(QStringLiteral("background-image:url(:/res/res/mode_bg.png);"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        toolButton_text = new QToolButton(frame_2);
        toolButton_text->setObjectName(QStringLiteral("toolButton_text"));
        toolButton_text->setEnabled(true);
        toolButton_text->setGeometry(QRect(0, 0, 65, 65));
        toolButton_text->setFont(font1);
        toolButton_text->setFocusPolicy(Qt::NoFocus);
        toolButton_text->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/cap_text_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/cap_text_s.png);\n"
"}\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/cap_text_d.png);\n"
"}"));
        toolButton_text->setAutoRaise(true);
        toolButton_voice = new QToolButton(frame_2);
        toolButton_voice->setObjectName(QStringLiteral("toolButton_voice"));
        toolButton_voice->setEnabled(true);
        toolButton_voice->setGeometry(QRect(68, 0, 65, 65));
        toolButton_voice->setFont(font1);
        toolButton_voice->setFocusPolicy(Qt::NoFocus);
        toolButton_voice->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/cap_voice_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/cap_voice_s.png);\n"
"}\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/cap_voice_d.png);\n"
"}"));
        toolButton_voice->setCheckable(true);
        toolButton_voice->setAutoRaise(true);
        toolButton_save = new QToolButton(frame_2);
        toolButton_save->setObjectName(QStringLiteral("toolButton_save"));
        toolButton_save->setGeometry(QRect(136, 0, 65, 65));
        toolButton_save->setFont(font1);
        toolButton_save->setFocusPolicy(Qt::NoFocus);
        toolButton_save->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/cap_save_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/cap_save_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/cap_save_d.png);\n"
"}"));
        toolButton_save->setAutoRaise(true);
        toolButton_cancel = new QToolButton(frame_2);
        toolButton_cancel->setObjectName(QStringLiteral("toolButton_cancel"));
        toolButton_cancel->setGeometry(QRect(204, 0, 65, 65));
        toolButton_cancel->setFont(font1);
        toolButton_cancel->setFocusPolicy(Qt::NoFocus);
        toolButton_cancel->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/cap_cancle_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/cap_cancle_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/cap_cancle_d.png);\n"
"}"));
        toolButton_cancel->setAutoRaise(true);
        toolButton_error = new QToolButton(frame_2);
        toolButton_error->setObjectName(QStringLiteral("toolButton_error"));
        toolButton_error->setEnabled(true);
        toolButton_error->setGeometry(QRect(68, 0, 65, 65));
        toolButton_error->setFont(font1);
        toolButton_error->setFocusPolicy(Qt::NoFocus);
        toolButton_error->setStyleSheet(QLatin1String("QToolButton {\n"
"	border-image: url(:/res/res/twice_draw_3n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"	border-image: url(:/res/res/twice_draw_3s.png);\n"
"}\n"
"QToolButton:disabled{\n"
"	border-image: url(:/res/res/twice_draw_3d.png);\n"
"}"));
        toolButton_error->setCheckable(true);
        toolButton_error->setAutoRaise(true);
        label_jpgname_2 = new QLabel(frame);
        label_jpgname_2->setObjectName(QStringLiteral("label_jpgname_2"));
        label_jpgname_2->setGeometry(QRect(0, 60, 269, 28));
        label_jpgname_2->setFont(font1);
        label_jpgname_2->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_jpgname_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_jpgname = new QLabel(frame);
        label_jpgname->setObjectName(QStringLiteral("label_jpgname"));
        label_jpgname->setGeometry(QRect(0, 30, 269, 28));
        label_jpgname->setFont(font1);
        label_jpgname->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_jpgname->setAlignment(Qt::AlignCenter);
        flag_warning = new QLabel(Hp_Camera_Cap);
        flag_warning->setObjectName(QStringLiteral("flag_warning"));
        flag_warning->setGeometry(QRect(240, 10, 161, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(16);
        flag_warning->setFont(font2);
        flag_warning->setStyleSheet(QString::fromUtf8("/*font: 16pt \"\351\273\221\344\275\223\";*/\n"
"background-color: transparent;\n"
"color: \"#ffffff\";"));
        flag_warning->setAlignment(Qt::AlignCenter);
        flag_warning->setWordWrap(false);
        title_warning = new QLabel(Hp_Camera_Cap);
        title_warning->setObjectName(QStringLiteral("title_warning"));
        title_warning->setGeometry(QRect(10, 40, 621, 31));
        title_warning->setFont(font2);
        title_warning->setStyleSheet(QString::fromUtf8("/*font: 16pt \"\351\273\221\344\275\223\";*/\n"
"background-color: transparent;\n"
"color: \"#7CA6C9\";"));
        title_warning->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        title_warning->setWordWrap(true);
        text_warning = new QLabel(Hp_Camera_Cap);
        text_warning->setObjectName(QStringLiteral("text_warning"));
        text_warning->setGeometry(QRect(10, 70, 621, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(13);
        text_warning->setFont(font3);
        text_warning->setStyleSheet(QString::fromUtf8("/*font: 13pt \"\351\273\221\344\275\223\";*/\n"
"background-color: transparent;\n"
"color: \"#7CA6C9\";"));
        text_warning->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        text_warning->setWordWrap(true);
        label_time = new QLabel(Hp_Camera_Cap);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setGeometry(QRect(120, 380, 61, 21));
        label_time->setFont(font);
        label_time->setStyleSheet(QLatin1String("background-color: transparent;\n"
"color: \"#7CA6C9\";"));
        label_time->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_Camera_Cap);

        QMetaObject::connectSlotsByName(Hp_Camera_Cap);
    } // setupUi

    void retranslateUi(QWidget *Hp_Camera_Cap)
    {
        Hp_Camera_Cap->setWindowTitle(QApplication::translate("Hp_Camera_Cap", "Form", nullptr));
        progressBar->setFormat(QApplication::translate("Hp_Camera_Cap", "%p%", nullptr));
        label->setText(QApplication::translate("Hp_Camera_Cap", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        toolButton_text->setText(QString());
        toolButton_voice->setText(QString());
        toolButton_save->setText(QString());
        toolButton_cancel->setText(QString());
        toolButton_error->setText(QString());
        label_jpgname_2->setText(QString());
        label_jpgname->setText(QString());
        flag_warning->setText(QApplication::translate("Hp_Camera_Cap", "\350\255\246\345\221\212\347\255\211\347\272\247", nullptr));
        title_warning->setText(QApplication::translate("Hp_Camera_Cap", "\350\255\246\345\221\212\346\226\207\346\234\254", nullptr));
        text_warning->setText(QApplication::translate("Hp_Camera_Cap", "\350\255\246\345\221\212\346\226\207\346\234\254", nullptr));
        label_time->setText(QApplication::translate("Hp_Camera_Cap", "0S", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Camera_Cap: public Ui_Hp_Camera_Cap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_CAMERA_CAP_H
