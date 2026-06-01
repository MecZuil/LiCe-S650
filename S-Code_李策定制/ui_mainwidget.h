/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "hp_button.h"
#include "hp_display.h"
#include "hp_main_task.h"
#include "hp_main_task_1.h"
#include "hp_main_task_2.h"
#include "hp_main_task_3.h"
#include "hpmylabel.h"
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QFrame *frame;
    hp_button *preview;
    hp_button *bright_mode;
    hp_button *line;
    hp_button *rect;
    hp_button *mode;
    hp_button *resize;
    hp_button *point;
    hp_button *setting;
    hp_button *sebiao;
    hp_button *clean;
    QToolButton *toolButton_pause;
    Hp_Display *display;
    QFrame *frame_task;
    Hp_Main_Task *widget_task;
    QWidget *widget_laser;
    QToolButton *last_page;
    QToolButton *next_page;
    QToolButton *focus_far;
    QToolButton *focus_near;
    QLabel *label_focus;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_autosave;
    hp_button *circle;
    QLabel *label_alarm;
    QLabel *label_tempAvg;
    QLabel *label_laserRange;
    hp_button *polygon;
    QCheckBox *checkBox_polygon;
    QPushButton *pushButton_confirm;
    QFrame *frame_task_2;
    Hp_Main_Task_2 *widget_task_2;
    QFrame *frame_task_3;
    Hp_Main_Task_3 *widget_task_3;
    QFrame *frame_task_4;
    Hp_Main_Task_1 *widget_task_1;
    QLabel *label_insulation;
    QLabel *label_insulation_2;
    QLabel *label_insulation_3;
    QLabel *label_insulation_4;
    QLabel *label_insulation_5;
    QLabel *label_insulation_6;
    QLabel *label_insulation_7;
    QLabel *label_insulation_8;
    QLabel *label_insulation_9;
    QListWidget *listWidget_jingtou;
    QLabel *label_focusWarning;
    QLabel *label_insulation_10;
    QLabel *label_insulation_11;
    QFrame *frame_tool;
    QToolButton *toolButton_AM;
    QToolButton *toolButton_up;
    QToolButton *toolButton_down;
    hpmylabel *toolButton_min;
    hpmylabel *toolButton_max;
    myLabel *compass;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->setWindowModality(Qt::NonModal);
        MainWidget->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWidget->sizePolicy().hasHeightForWidth());
        MainWidget->setSizePolicy(sizePolicy);
        MainWidget->setLayoutDirection(Qt::LeftToRight);
        MainWidget->setAutoFillBackground(false);
        MainWidget->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        frame = new QFrame(MainWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 160, 480));
        frame->setStyleSheet(QStringLiteral("background-image:url(:/res/res/main_background.png);"));
        preview = new hp_button(frame);
        preview->setObjectName(QStringLiteral("preview"));
        preview->setGeometry(QRect(1, 1, 78, 159));
        bright_mode = new hp_button(frame);
        bright_mode->setObjectName(QStringLiteral("bright_mode"));
        bright_mode->setGeometry(QRect(1, 321, 78, 79));
        line = new hp_button(frame);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(81, 81, 78, 79));
        rect = new hp_button(frame);
        rect->setObjectName(QStringLiteral("rect"));
        rect->setGeometry(QRect(81, 161, 78, 79));
        mode = new hp_button(frame);
        mode->setObjectName(QStringLiteral("mode"));
        mode->setGeometry(QRect(1, 241, 78, 79));
        resize = new hp_button(frame);
        resize->setObjectName(QStringLiteral("resize"));
        resize->setGeometry(QRect(81, 321, 78, 79));
        point = new hp_button(frame);
        point->setObjectName(QStringLiteral("point"));
        point->setGeometry(QRect(81, 1, 78, 79));
        setting = new hp_button(frame);
        setting->setObjectName(QStringLiteral("setting"));
        setting->setGeometry(QRect(1, 401, 158, 79));
        sebiao = new hp_button(frame);
        sebiao->setObjectName(QStringLiteral("sebiao"));
        sebiao->setGeometry(QRect(1, 161, 78, 79));
        clean = new hp_button(frame);
        clean->setObjectName(QStringLiteral("clean"));
        clean->setGeometry(QRect(81, 241, 78, 79));
        toolButton_pause = new QToolButton(frame);
        toolButton_pause->setObjectName(QStringLiteral("toolButton_pause"));
        toolButton_pause->setGeometry(QRect(70, 240, 150, 70));
        QFont font;
        font.setPointSize(17);
        toolButton_pause->setFont(font);
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
        display = new Hp_Display(MainWidget);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(160, 0, 631, 480));
        display->setAutoFillBackground(false);
        display->setStyleSheet(QStringLiteral(""));
        frame_task = new QFrame(display);
        frame_task->setObjectName(QStringLiteral("frame_task"));
        frame_task->setGeometry(QRect(359, 0, 280, 28));
        frame_task->setStyleSheet(QStringLiteral(""));
        frame_task->setFrameShape(QFrame::NoFrame);
        frame_task->setFrameShadow(QFrame::Raised);
        widget_task = new Hp_Main_Task(frame_task);
        widget_task->setObjectName(QStringLiteral("widget_task"));
        widget_task->setGeometry(QRect(0, 0, 280, 28));
        widget_laser = new QWidget(display);
        widget_laser->setObjectName(QStringLiteral("widget_laser"));
        widget_laser->setGeometry(QRect(300, 218, 40, 40));
        widget_laser->setStyleSheet(QStringLiteral("border-image: url(:/res/res/laser.png);"));
        last_page = new QToolButton(display);
        last_page->setObjectName(QStringLiteral("last_page"));
        last_page->setGeometry(QRect(445, 300, 61, 62));
        QFont font1;
        font1.setPointSize(18);
        last_page->setFont(font1);
        last_page->setFocusPolicy(Qt::NoFocus);
        last_page->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/pre_page_2n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/pre_page_2s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/pre_page_2d.png);\n"
"}"));
        last_page->setAutoRaise(true);
        next_page = new QToolButton(display);
        next_page->setObjectName(QStringLiteral("next_page"));
        next_page->setGeometry(QRect(445, 370, 61, 62));
        next_page->setFont(font1);
        next_page->setFocusPolicy(Qt::NoFocus);
        next_page->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/next_page_2n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/next_page_2s.png);\n"
"}\n"
"\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/next_page_2d.png);\n"
"}"));
        next_page->setAutoRaise(true);
        next_page->setArrowType(Qt::NoArrow);
        focus_far = new QToolButton(display);
        focus_far->setObjectName(QStringLiteral("focus_far"));
        focus_far->setGeometry(QRect(320, 380, 65, 65));
        QFont font2;
        font2.setPointSize(21);
        focus_far->setFont(font2);
        focus_far->setFocusPolicy(Qt::NoFocus);
        focus_far->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/focus_t_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/focus_t_s.png);\n"
"}"));
        focus_far->setAutoRaise(true);
        focus_near = new QToolButton(display);
        focus_near->setObjectName(QStringLiteral("focus_near"));
        focus_near->setGeometry(QRect(220, 380, 65, 65));
        focus_near->setFont(font2);
        focus_near->setFocusPolicy(Qt::NoFocus);
        focus_near->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/focus_w_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/focus_w_s.png);\n"
"}"));
        label_focus = new QLabel(display);
        label_focus->setObjectName(QStringLiteral("label_focus"));
        label_focus->setGeometry(QRect(190, 230, 80, 40));
        QFont font3;
        font3.setPointSize(15);
        label_focus->setFont(font3);
        label_focus->setStyleSheet(QStringLiteral("color:#c87b37;"));
        label_focus->setAlignment(Qt::AlignCenter);
        label = new QLabel(display);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 260, 330, 60));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(16);
        label->setFont(font4);
        label->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#ffffff;\n"
"/*background-color:rgb(255,0,0);*/"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(display);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 290, 330, 60));
        label_2->setFont(font4);
        label_2->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#ffffff;\n"
"/*background-color:rgb(255,0,0);*/"));
        label_2->setAlignment(Qt::AlignCenter);
        label_autosave = new QLabel(display);
        label_autosave->setObjectName(QStringLiteral("label_autosave"));
        label_autosave->setGeometry(QRect(270, 200, 100, 30));
        QFont font5;
        font5.setPointSize(13);
        label_autosave->setFont(font5);
        label_autosave->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_autosave->setAlignment(Qt::AlignCenter);
        circle = new hp_button(display);
        circle->setObjectName(QStringLiteral("circle"));
        circle->setGeometry(QRect(0, 160, 78, 79));
        circle->setStyleSheet(QStringLiteral("background-image:url(:/res/res/main_background.png);"));
        label_alarm = new QLabel(display);
        label_alarm->setObjectName(QStringLiteral("label_alarm"));
        label_alarm->setGeometry(QRect(241, 72, 321, 41));
        label_alarm->setFont(font3);
        label_alarm->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_alarm->setAlignment(Qt::AlignCenter);
        label_tempAvg = new QLabel(display);
        label_tempAvg->setObjectName(QStringLiteral("label_tempAvg"));
        label_tempAvg->setGeometry(QRect(351, 35, 211, 41));
        label_tempAvg->setFont(font3);
        label_tempAvg->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_tempAvg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_laserRange = new QLabel(display);
        label_laserRange->setObjectName(QStringLiteral("label_laserRange"));
        label_laserRange->setGeometry(QRect(460, 38, 111, 41));
        label_laserRange->setFont(font5);
        label_laserRange->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_laserRange->setAlignment(Qt::AlignCenter);
        polygon = new hp_button(display);
        polygon->setObjectName(QStringLiteral("polygon"));
        polygon->setGeometry(QRect(0, 160, 78, 79));
        polygon->setStyleSheet(QStringLiteral("background-image:url(:/res/res/main_background.png);"));
        checkBox_polygon = new QCheckBox(display);
        checkBox_polygon->setObjectName(QStringLiteral("checkBox_polygon"));
        checkBox_polygon->setGeometry(QRect(480, 120, 70, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox_polygon->sizePolicy().hasHeightForWidth());
        checkBox_polygon->setSizePolicy(sizePolicy1);
        checkBox_polygon->setMinimumSize(QSize(40, 0));
        QFont font6;
        font6.setPointSize(10);
        font6.setStyleStrategy(QFont::PreferAntialias);
        checkBox_polygon->setFont(font6);
        checkBox_polygon->setFocusPolicy(Qt::NoFocus);
        checkBox_polygon->setLayoutDirection(Qt::RightToLeft);
        checkBox_polygon->setStyleSheet(QLatin1String("QCheckBox{\n"
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
        checkBox_polygon->setIconSize(QSize(30, 30));
        checkBox_polygon->setTristate(false);
        pushButton_confirm = new QPushButton(display);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(480, 170, 70, 40));
        pushButton_confirm->setMinimumSize(QSize(0, 0));
        pushButton_confirm->setMaximumSize(QSize(16777215, 16777215));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(17);
        font7.setStyleStrategy(QFont::PreferAntialias);
        pushButton_confirm->setFont(font7);
        pushButton_confirm->setFocusPolicy(Qt::NoFocus);
        pushButton_confirm->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"border-image:url(:/res/res/button_n.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
"QPushButton:pressed{\n"
"border-image:url(:/res/res/setting_selected.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
""));
        pushButton_confirm->setAutoDefault(false);
        pushButton_confirm->setFlat(true);
        frame_task_2 = new QFrame(display);
        frame_task_2->setObjectName(QStringLiteral("frame_task_2"));
        frame_task_2->setGeometry(QRect(0, 452, 280, 28));
        frame_task_2->setStyleSheet(QStringLiteral(""));
        frame_task_2->setFrameShape(QFrame::NoFrame);
        frame_task_2->setFrameShadow(QFrame::Raised);
        widget_task_2 = new Hp_Main_Task_2(frame_task_2);
        widget_task_2->setObjectName(QStringLiteral("widget_task_2"));
        widget_task_2->setGeometry(QRect(0, 0, 280, 28));
        frame_task_3 = new QFrame(display);
        frame_task_3->setObjectName(QStringLiteral("frame_task_3"));
        frame_task_3->setGeometry(QRect(0, 0, 31, 280));
        frame_task_3->setStyleSheet(QStringLiteral(""));
        frame_task_3->setFrameShape(QFrame::NoFrame);
        frame_task_3->setFrameShadow(QFrame::Raised);
        widget_task_3 = new Hp_Main_Task_3(frame_task_3);
        widget_task_3->setObjectName(QStringLiteral("widget_task_3"));
        widget_task_3->setGeometry(QRect(0, 0, 31, 280));
        frame_task_4 = new QFrame(display);
        frame_task_4->setObjectName(QStringLiteral("frame_task_4"));
        frame_task_4->setGeometry(QRect(609, 200, 31, 280));
        frame_task_4->setStyleSheet(QStringLiteral(""));
        frame_task_4->setFrameShape(QFrame::NoFrame);
        frame_task_4->setFrameShadow(QFrame::Raised);
        widget_task_1 = new Hp_Main_Task_1(frame_task_4);
        widget_task_1->setObjectName(QStringLiteral("widget_task_1"));
        widget_task_1->setGeometry(QRect(0, 0, 31, 280));
        label_insulation = new QLabel(display);
        label_insulation->setObjectName(QStringLiteral("label_insulation"));
        label_insulation->setGeometry(QRect(900, 140, 31, 31));
        label_insulation->setFont(font5);
        label_insulation->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-image: url(:/res/res/insulation.png);"));
        label_insulation->setAlignment(Qt::AlignCenter);
        label_insulation_2 = new QLabel(display);
        label_insulation_2->setObjectName(QStringLiteral("label_insulation_2"));
        label_insulation_2->setGeometry(QRect(900, 200, 31, 31));
        label_insulation_2->setFont(font5);
        label_insulation_2->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-image: url(:/res/res/insulation.png);"));
        label_insulation_2->setAlignment(Qt::AlignCenter);
        label_insulation_3 = new QLabel(display);
        label_insulation_3->setObjectName(QStringLiteral("label_insulation_3"));
        label_insulation_3->setGeometry(QRect(900, 210, 31, 31));
        label_insulation_3->setFont(font5);
        label_insulation_3->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-image: url(:/res/res/insulation.png);"));
        label_insulation_3->setAlignment(Qt::AlignCenter);
        label_insulation_4 = new QLabel(display);
        label_insulation_4->setObjectName(QStringLiteral("label_insulation_4"));
        label_insulation_4->setGeometry(QRect(900, 220, 31, 31));
        label_insulation_4->setFont(font5);
        label_insulation_4->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-image: url(:/res/res/insulation.png);"));
        label_insulation_4->setAlignment(Qt::AlignCenter);
        label_insulation_5 = new QLabel(display);
        label_insulation_5->setObjectName(QStringLiteral("label_insulation_5"));
        label_insulation_5->setGeometry(QRect(900, 230, 31, 31));
        label_insulation_5->setFont(font5);
        label_insulation_5->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-image: url(:/res/res/insulation.png);"));
        label_insulation_5->setAlignment(Qt::AlignCenter);
        label_insulation_6 = new QLabel(display);
        label_insulation_6->setObjectName(QStringLiteral("label_insulation_6"));
        label_insulation_6->setGeometry(QRect(900, 240, 31, 31));
        label_insulation_6->setFont(font5);
        label_insulation_6->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-image: url(:/res/res/insulation.png);"));
        label_insulation_6->setAlignment(Qt::AlignCenter);
        label_insulation_7 = new QLabel(display);
        label_insulation_7->setObjectName(QStringLiteral("label_insulation_7"));
        label_insulation_7->setGeometry(QRect(900, 250, 31, 31));
        label_insulation_7->setFont(font5);
        label_insulation_7->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-image: url(:/res/res/insulation.png);"));
        label_insulation_7->setAlignment(Qt::AlignCenter);
        label_insulation_8 = new QLabel(display);
        label_insulation_8->setObjectName(QStringLiteral("label_insulation_8"));
        label_insulation_8->setGeometry(QRect(900, 260, 31, 31));
        label_insulation_8->setFont(font5);
        label_insulation_8->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-image: url(:/res/res/insulation.png);"));
        label_insulation_8->setAlignment(Qt::AlignCenter);
        label_insulation_9 = new QLabel(display);
        label_insulation_9->setObjectName(QStringLiteral("label_insulation_9"));
        label_insulation_9->setGeometry(QRect(900, 410, 31, 31));
        label_insulation_9->setFont(font5);
        label_insulation_9->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-image: url(:/res/res/insulation.png);"));
        label_insulation_9->setAlignment(Qt::AlignCenter);
        listWidget_jingtou = new QListWidget(display);
        listWidget_jingtou->setObjectName(QStringLiteral("listWidget_jingtou"));
        listWidget_jingtou->setGeometry(QRect(170, 310, 181, 41));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font8.setPointSize(17);
        listWidget_jingtou->setFont(font8);
        listWidget_jingtou->setStyleSheet(QStringLiteral("background-image:url(:/res/res/main_background.png);"));
        label_focusWarning = new QLabel(display);
        label_focusWarning->setObjectName(QStringLiteral("label_focusWarning"));
        label_focusWarning->setGeometry(QRect(190, 270, 161, 40));
        label_focusWarning->setFont(font3);
        label_focusWarning->setStyleSheet(QStringLiteral("color:#c87b37;"));
        label_focusWarning->setAlignment(Qt::AlignCenter);
        label_insulation_10 = new QLabel(display);
        label_insulation_10->setObjectName(QStringLiteral("label_insulation_10"));
        label_insulation_10->setGeometry(QRect(1000, 450, 31, 31));
        label_insulation_10->setFont(font5);
        label_insulation_10->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-image: url(:/res/res/insulation.png);"));
        label_insulation_10->setAlignment(Qt::AlignCenter);
        label_insulation_11 = new QLabel(display);
        label_insulation_11->setObjectName(QStringLiteral("label_insulation_11"));
        label_insulation_11->setGeometry(QRect(1000, 460, 31, 31));
        label_insulation_11->setFont(font5);
        label_insulation_11->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-image: url(:/res/res/insulation.png);"));
        label_insulation_11->setAlignment(Qt::AlignCenter);
        frame_tool = new QFrame(display);
        frame_tool->setObjectName(QStringLiteral("frame_tool"));
        frame_tool->setGeometry(QRect(500, 30, 140, 421));
        frame_tool->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        frame_tool->setFrameShape(QFrame::NoFrame);
        frame_tool->setFrameShadow(QFrame::Raised);
        toolButton_AM = new QToolButton(frame_tool);
        toolButton_AM->setObjectName(QStringLiteral("toolButton_AM"));
        toolButton_AM->setGeometry(QRect(85, 10, 30, 30));
        toolButton_AM->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/auto_2.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/manual_2.png);\n"
"}"));
        toolButton_AM->setCheckable(true);
        toolButton_AM->setAutoRaise(true);
        toolButton_up = new QToolButton(frame_tool);
        toolButton_up->setObjectName(QStringLiteral("toolButton_up"));
        toolButton_up->setGeometry(QRect(0, 158, 66, 66));
        toolButton_up->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/m_up_arrow_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/m_up_arrow_s.png);\n"
"}"));
        toolButton_up->setAutoRepeat(true);
        toolButton_up->setAutoRepeatDelay(800);
        toolButton_up->setAutoRepeatInterval(50);
        toolButton_up->setAutoRaise(true);
        toolButton_up->setArrowType(Qt::NoArrow);
        toolButton_down = new QToolButton(frame_tool);
        toolButton_down->setObjectName(QStringLiteral("toolButton_down"));
        toolButton_down->setGeometry(QRect(0, 247, 66, 66));
        toolButton_down->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/m_down_arrow_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/m_down_arrow_s.png);\n"
"}"));
        toolButton_down->setAutoRepeat(true);
        toolButton_down->setAutoRepeatDelay(800);
        toolButton_down->setAutoRepeatInterval(50);
        toolButton_down->setAutoRaise(true);
        toolButton_down->setArrowType(Qt::NoArrow);
        toolButton_min = new hpmylabel(frame_tool);
        toolButton_min->setObjectName(QStringLiteral("toolButton_min"));
        toolButton_min->setGeometry(QRect(70, 375, 66, 35));
        toolButton_min->setFont(font3);
        toolButton_min->setStyleSheet(QLatin1String("QLabel {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"	background-color: rgb(49, 69, 116);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QLabel:checked{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_min->setAlignment(Qt::AlignCenter);
        toolButton_max = new hpmylabel(frame_tool);
        toolButton_max->setObjectName(QStringLiteral("toolButton_max"));
        toolButton_max->setGeometry(QRect(70, 50, 66, 35));
        toolButton_max->setFont(font3);
        toolButton_max->setStyleSheet(QLatin1String("QLabel {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"	background-color: rgb(49, 69, 116);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QLabel:checked{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_max->setAlignment(Qt::AlignCenter);
        toolButton_AM->raise();
        toolButton_up->raise();
        toolButton_down->raise();
        toolButton_max->raise();
        toolButton_min->raise();
        frame_task_4->raise();
        frame_task->raise();
        last_page->raise();
        focus_far->raise();
        focus_near->raise();
        label_focus->raise();
        label->raise();
        label_2->raise();
        next_page->raise();
        label_autosave->raise();
        circle->raise();
        label_alarm->raise();
        label_tempAvg->raise();
        widget_laser->raise();
        label_laserRange->raise();
        checkBox_polygon->raise();
        pushButton_confirm->raise();
        frame_task_2->raise();
        frame_task_3->raise();
        polygon->raise();
        label_insulation->raise();
        label_insulation_2->raise();
        label_insulation_3->raise();
        label_insulation_4->raise();
        label_insulation_5->raise();
        label_insulation_6->raise();
        label_insulation_7->raise();
        label_insulation_8->raise();
        label_insulation_9->raise();
        listWidget_jingtou->raise();
        label_focusWarning->raise();
        label_insulation_10->raise();
        label_insulation_11->raise();
        frame_tool->raise();
        compass = new myLabel(MainWidget);
        compass->setObjectName(QStringLiteral("compass"));
        compass->setGeometry(QRect(200, 50, 72, 72));
        compass->setStyleSheet(QStringLiteral(""));
        display->raise();
        frame->raise();
        compass->raise();

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", nullptr));
        toolButton_pause->setText(QString());
        last_page->setText(QString());
        next_page->setText(QString());
        focus_far->setText(QString());
        focus_near->setText(QString());
        label_focus->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_autosave->setText(QApplication::translate("MainWidget", "AUTOSAVE", nullptr));
        label_alarm->setText(QString());
        label_tempAvg->setText(QString());
        label_laserRange->setText(QString());
        checkBox_polygon->setText(QString());
        pushButton_confirm->setText(QApplication::translate("MainWidget", "OK", nullptr));
        label_insulation->setText(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_insulation_2->setText(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_insulation_3->setText(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_insulation_4->setText(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_insulation_5->setText(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_insulation_6->setText(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_insulation_7->setText(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_insulation_8->setText(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_insulation_9->setText(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_focusWarning->setText(QApplication::translate("MainWidget", "\350\267\235\347\246\273\350\266\205\345\207\272\351\231\220\345\210\266\357\274\201", nullptr));
        label_insulation_10->setText(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_insulation_11->setText(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        toolButton_AM->setText(QString());
        toolButton_up->setText(QString());
        toolButton_down->setText(QString());
        toolButton_min->setText(QString());
        toolButton_max->setText(QString());
        compass->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
