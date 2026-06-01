/********************************************************************************
** Form generated from reading UI file 'hp_gstreamer_player.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_GSTREAMER_PLAYER_H
#define UI_HP_GSTREAMER_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hp_gstreamer_player
{
public:
    QFrame *frame_control_2;
    QToolButton *toolButton_close;
    QCheckBox *checkBox;
    QToolButton *toolButton_speed;
    QSlider *verticalSlider;

    void setupUi(QWidget *hp_gstreamer_player)
    {
        if (hp_gstreamer_player->objectName().isEmpty())
            hp_gstreamer_player->setObjectName(QStringLiteral("hp_gstreamer_player"));
        hp_gstreamer_player->resize(800, 480);
        hp_gstreamer_player->setStyleSheet(QStringLiteral("background-color:#000000;"));
        frame_control_2 = new QFrame(hp_gstreamer_player);
        frame_control_2->setObjectName(QStringLiteral("frame_control_2"));
        frame_control_2->setGeometry(QRect(0, 0, 160, 480));
        QFont font;
        font.setPointSize(17);
        frame_control_2->setFont(font);
        frame_control_2->setStyleSheet(QStringLiteral("background-image:url(:/res/res/main_background.png);"));
        frame_control_2->setFrameShape(QFrame::NoFrame);
        frame_control_2->setFrameShadow(QFrame::Raised);
        toolButton_close = new QToolButton(frame_control_2);
        toolButton_close->setObjectName(QStringLiteral("toolButton_close"));
        toolButton_close->setGeometry(QRect(3, 0, 150, 70));
        toolButton_close->setFont(font);
        toolButton_close->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/setting_back.png);\n"
"background:transparent;\n"
"}  \n"
""));
        checkBox = new QCheckBox(frame_control_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(3, 80, 150, 70));
        checkBox->setStyleSheet(QLatin1String("QCheckBox{\n"
"background:transparent;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    border-image:url(:/res/res/media_play.png);\n"
"	/*background-color:rgba(97,223,249,45);*/\n"
"	width:150px;\n"
"	height:70px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    border-image:url(:/res/res/media_pause.png);\n"
"	/*border-radius:28px;\n"
"	background-color:#3c3c3c;*/\n"
"	width:150px;\n"
"	height:70px;\n"
"}\n"
"\n"
""));
        checkBox->setChecked(true);
        toolButton_speed = new QToolButton(frame_control_2);
        toolButton_speed->setObjectName(QStringLiteral("toolButton_speed"));
        toolButton_speed->setGeometry(QRect(10, 400, 91, 70));
        QFont font1;
        font1.setPointSize(20);
        toolButton_speed->setFont(font1);
        toolButton_speed->setStyleSheet(QLatin1String("QToolButton {\n"
"	color:#7CA6C9;\n"
"	border:2px solid #7CA6C9;\n"
"	background:transparent;\n"
"	/*background-color:rgba(97,223,249,45);*/\n"
"}"));
        toolButton_speed->setCheckable(true);
        verticalSlider = new QSlider(frame_control_2);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(110, 160, 41, 311));
        verticalSlider->setStyleSheet(QLatin1String("QSlider{\n"
"	border:2px solid #7CA6C9;\n"
"	padding-top:5px;\n"
"	padding-bottom:5px;\n"
"}\n"
"\n"
"QSlider::groove:verizontal  \n"
"{  \n"
"    width: 1px;  \n"
"    background: qlineargradient(x1:1, y1:0, x2:0, y2:0, stop:1 #5F80AA, stop:0 #5F80AA);  \n"
"}\n"
"QSlider::handle:verizontal   \n"
"{   \n"
"/*\n"
" background: qlineargradient(x1:0, y1:1, x2:0, y2:0, stop:1 #67A4E0, stop:0 #336CA5);  \n"
"*/\n"
"    width: 30px;  \n"
"    height: 16px;  \n"
"     margin: 0px -12px 0px -12px;\n"
"    border: 0px solid #000810;\n"
"border-image:url(:/res/res/huakuai.png);  \n"
"}  "));
        verticalSlider->setOrientation(Qt::Vertical);
        toolButton_close->raise();
        checkBox->raise();
        checkBox->raise();
        toolButton_speed->raise();
        verticalSlider->raise();

        retranslateUi(hp_gstreamer_player);

        QMetaObject::connectSlotsByName(hp_gstreamer_player);
    } // setupUi

    void retranslateUi(QWidget *hp_gstreamer_player)
    {
        hp_gstreamer_player->setWindowTitle(QApplication::translate("hp_gstreamer_player", "Form", nullptr));
        toolButton_close->setText(QString());
        checkBox->setText(QString());
        toolButton_speed->setText(QApplication::translate("hp_gstreamer_player", "1X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hp_gstreamer_player: public Ui_hp_gstreamer_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_GSTREAMER_PLAYER_H
