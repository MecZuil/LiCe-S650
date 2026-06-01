/********************************************************************************
** Form generated from reading UI file 'hp_media_player.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_MEDIA_PLAYER_H
#define UI_HP_MEDIA_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Media_Player
{
public:
    QFrame *frame_control;
    QToolButton *toolButton_close;
    QToolButton *toolButton_pause;
    QFrame *frame_display;
    QSlider *hs_time;
    QFrame *frame_control_2;

    void setupUi(QWidget *Hp_Media_Player)
    {
        if (Hp_Media_Player->objectName().isEmpty())
            Hp_Media_Player->setObjectName(QStringLiteral("Hp_Media_Player"));
        Hp_Media_Player->resize(800, 480);
        QFont font;
        font.setPointSize(15);
        Hp_Media_Player->setFont(font);
        frame_control = new QFrame(Hp_Media_Player);
        frame_control->setObjectName(QStringLiteral("frame_control"));
        frame_control->setGeometry(QRect(0, 0, 80, 480));
        QFont font1;
        font1.setPointSize(17);
        frame_control->setFont(font1);
        frame_control->setStyleSheet(QStringLiteral("background-image:url(:/res/res/main_background.png);"));
        frame_control->setFrameShape(QFrame::NoFrame);
        frame_control->setFrameShadow(QFrame::Raised);
        toolButton_close = new QToolButton(frame_control);
        toolButton_close->setObjectName(QStringLiteral("toolButton_close"));
        toolButton_close->setGeometry(QRect(3, 0, 75, 70));
        toolButton_close->setFont(font1);
        toolButton_close->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/setting_back.png);\n"
"background:transparent;\n"
"}  \n"
""));
        toolButton_pause = new QToolButton(frame_control);
        toolButton_pause->setObjectName(QStringLiteral("toolButton_pause"));
        toolButton_pause->setGeometry(QRect(3, 160, 75, 70));
        toolButton_pause->setFont(font1);
        toolButton_pause->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/media_pause.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/media_play.png);\n"
"}\n"
""));
        toolButton_pause->setCheckable(true);
        frame_display = new QFrame(Hp_Media_Player);
        frame_display->setObjectName(QStringLiteral("frame_display"));
        frame_display->setGeometry(QRect(80, 0, 640, 480));
        frame_display->setFont(font1);
        frame_display->setStyleSheet(QStringLiteral("background-color: rgb(0,0,0);"));
        frame_display->setFrameShape(QFrame::NoFrame);
        frame_display->setFrameShadow(QFrame::Raised);
        hs_time = new QSlider(frame_display);
        hs_time->setObjectName(QStringLiteral("hs_time"));
        hs_time->setGeometry(QRect(85, 388, 473, 51));
        hs_time->setFont(font1);
        hs_time->setFocusPolicy(Qt::NoFocus);
        hs_time->setStyleSheet(QLatin1String("  \n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 1px;  \n"
"    background: qlineargradient(x1:1, y1:0, x2:0, y2:0, stop:1 #5F80AA, stop:0 #5F80AA);  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{   \n"
"/*\n"
" background: qlineargradient(x1:0, y1:1, x2:0, y2:0, stop:1 #67A4E0, stop:0 #336CA5);  \n"
"*/\n"
"    width: 16px;  \n"
"    height: 30px;  \n"
"     margin: -12px 0px -12px 0px;\n"
"    border: 0px solid #000810;\n"
"border-image:url(:/res/res/huakuai.png);  \n"
"}  "));
        hs_time->setOrientation(Qt::Horizontal);
        hs_time->setTickPosition(QSlider::NoTicks);
        frame_control_2 = new QFrame(Hp_Media_Player);
        frame_control_2->setObjectName(QStringLiteral("frame_control_2"));
        frame_control_2->setGeometry(QRect(720, 0, 80, 480));
        frame_control_2->setFont(font1);
        frame_control_2->setStyleSheet(QStringLiteral("background-image:url(:/res/res/main_background.png);"));
        frame_control_2->setFrameShape(QFrame::NoFrame);
        frame_control_2->setFrameShadow(QFrame::Raised);

        retranslateUi(Hp_Media_Player);

        QMetaObject::connectSlotsByName(Hp_Media_Player);
    } // setupUi

    void retranslateUi(QWidget *Hp_Media_Player)
    {
        Hp_Media_Player->setWindowTitle(QApplication::translate("Hp_Media_Player", "Form", nullptr));
        toolButton_close->setText(QString());
        toolButton_pause->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Hp_Media_Player: public Ui_Hp_Media_Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_MEDIA_PLAYER_H
