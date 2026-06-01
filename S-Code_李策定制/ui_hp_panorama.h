/********************************************************************************
** Form generated from reading UI file 'hp_panorama.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_PANORAMA_H
#define UI_HP_PANORAMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Panorama
{
public:
    QFrame *frame_5;
    QFrame *frame_3;
    QFrame *line;
    QLabel *panoramaView;
    QLabel *panoramaView_2;
    QToolButton *panorema_ok_2;
    QFrame *frame_4;
    QLabel *label_5;
    QToolButton *panorema_ok;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QFrame *line_14;
    QFrame *line_15;
    QFrame *line_16;
    QLabel *label_7;
    QFrame *line_17;
    QFrame *line_18;
    QFrame *line_19;
    QWidget *widget_2;
    QLabel *label_degree;
    QLabel *label_degreeTips;
    QToolButton *panorema_save;
    QLabel *previewPanorama;
    QToolButton *panorema_cancel;
    QLabel *label_8;

    void setupUi(QWidget *Hp_Panorama)
    {
        if (Hp_Panorama->objectName().isEmpty())
            Hp_Panorama->setObjectName(QStringLiteral("Hp_Panorama"));
        Hp_Panorama->resize(641, 480);
        frame_5 = new QFrame(Hp_Panorama);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(0, 0, 640, 481));
        frame_5->setStyleSheet(QStringLiteral(""));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_5);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(0, 160, 641, 105));
        frame_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border: 2px solid white; border-radius: 5px;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        line = new QFrame(frame_3);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(120, 53, 540, 2));
        line->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 150);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        panoramaView = new QLabel(frame_3);
        panoramaView->setObjectName(QStringLiteral("panoramaView"));
        panoramaView->setGeometry(QRect(5, 5, 111, 95));
        panoramaView->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 20);"));
        panoramaView_2 = new QLabel(frame_3);
        panoramaView_2->setObjectName(QStringLiteral("panoramaView_2"));
        panoramaView_2->setGeometry(QRect(116, 5, 111, 95));
        panoramaView_2->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 20);"));
        panorema_ok_2 = new QToolButton(frame_3);
        panorema_ok_2->setObjectName(QStringLiteral("panorema_ok_2"));
        panorema_ok_2->setGeometry(QRect(581, 24, 61, 61));
        QFont font;
        font.setPointSize(17);
        panorema_ok_2->setFont(font);
        panorema_ok_2->setFocusPolicy(Qt::NoFocus);
        panorema_ok_2->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: transparent;\n"
"border-image:url(:/res/res/right.png);\n"
"}  \n"
""));
        panorema_ok_2->setIconSize(QSize(25, 25));
        panorema_ok_2->setAutoRepeat(true);
        panorema_ok_2->setAutoRepeatDelay(1000);
        panorema_ok_2->setAutoRepeatInterval(300);
        panorema_ok_2->setAutoRaise(true);
        panorema_ok_2->setArrowType(Qt::NoArrow);
        panoramaView_2->raise();
        panoramaView->raise();
        line->raise();
        panorema_ok_2->raise();
        frame_4 = new QFrame(frame_5);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(90, 360, 461, 61));
        frame_4->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border:0px;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 0, 351, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        font1.setPointSize(20);
        label_5->setFont(font1);
        label_5->setStyleSheet(QStringLiteral(""));
        label_5->setAlignment(Qt::AlignCenter);
        panorema_ok = new QToolButton(frame_4);
        panorema_ok->setObjectName(QStringLiteral("panorema_ok"));
        panorema_ok->setGeometry(QRect(400, 0, 51, 51));
        panorema_ok->setFont(font);
        panorema_ok->setFocusPolicy(Qt::NoFocus);
        panorema_ok->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: transparent;\n"
"border-image:url(:/res/res/pic_confirm_ok.png);\n"
"}  \n"
""));
        panorema_ok->setIconSize(QSize(25, 25));
        panorema_ok->setAutoRepeat(true);
        panorema_ok->setAutoRepeatDelay(1000);
        panorema_ok->setAutoRepeatInterval(300);
        panorema_ok->setAutoRaise(true);
        panorema_ok->setArrowType(Qt::NoArrow);
        line_11 = new QFrame(frame_5);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setGeometry(QRect(320, 80, 2, 20));
        line_11->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);
        line_12 = new QFrame(frame_5);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setGeometry(QRect(260, 80, 120, 3));
        line_12->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);
        line_13 = new QFrame(frame_5);
        line_13->setObjectName(QStringLiteral("line_13"));
        line_13->setGeometry(QRect(340, 80, 2, 20));
        line_13->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        line_13->setFrameShape(QFrame::VLine);
        line_13->setFrameShadow(QFrame::Sunken);
        line_14 = new QFrame(frame_5);
        line_14->setObjectName(QStringLiteral("line_14"));
        line_14->setGeometry(QRect(280, 80, 2, 20));
        line_14->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);
        line_15 = new QFrame(frame_5);
        line_15->setObjectName(QStringLiteral("line_15"));
        line_15->setGeometry(QRect(378, 81, 2, 20));
        line_15->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);
        line_16 = new QFrame(frame_5);
        line_16->setObjectName(QStringLiteral("line_16"));
        line_16->setGeometry(QRect(260, 80, 2, 20));
        line_16->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        line_16->setFrameShape(QFrame::VLine);
        line_16->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(frame_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 30, 381, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei"));
        font2.setPointSize(20);
        label_7->setFont(font2);
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_7->setAlignment(Qt::AlignCenter);
        line_17 = new QFrame(frame_5);
        line_17->setObjectName(QStringLiteral("line_17"));
        line_17->setGeometry(QRect(261, 99, 119, 3));
        line_17->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        line_17->setFrameShape(QFrame::HLine);
        line_17->setFrameShadow(QFrame::Sunken);
        line_18 = new QFrame(frame_5);
        line_18->setObjectName(QStringLiteral("line_18"));
        line_18->setGeometry(QRect(300, 80, 2, 20));
        line_18->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        line_18->setFrameShape(QFrame::VLine);
        line_18->setFrameShadow(QFrame::Sunken);
        line_19 = new QFrame(frame_5);
        line_19->setObjectName(QStringLiteral("line_19"));
        line_19->setGeometry(QRect(360, 80, 2, 20));
        line_19->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        line_19->setFrameShape(QFrame::VLine);
        line_19->setFrameShadow(QFrame::Sunken);
        widget_2 = new QWidget(frame_5);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(260, 100, 121, 31));
        widget_2->setStyleSheet(QStringLiteral("border: 0px solid white;"));
        label_degree = new QLabel(widget_2);
        label_degree->setObjectName(QStringLiteral("label_degree"));
        label_degree->setGeometry(QRect(0, 0, 121, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei"));
        font3.setPointSize(17);
        label_degree->setFont(font3);
        label_degree->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border: 0px solid white;"));
        label_degree->setTextFormat(Qt::AutoText);
        label_degree->setAlignment(Qt::AlignCenter);
        label_degree->setWordWrap(false);
        label_degreeTips = new QLabel(frame_5);
        label_degreeTips->setObjectName(QStringLiteral("label_degreeTips"));
        label_degreeTips->setGeometry(QRect(160, 270, 331, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Microsoft YaHei"));
        font4.setPointSize(15);
        label_degreeTips->setFont(font4);
        label_degreeTips->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_degreeTips->setAlignment(Qt::AlignCenter);
        panorema_save = new QToolButton(Hp_Panorama);
        panorema_save->setObjectName(QStringLiteral("panorema_save"));
        panorema_save->setGeometry(QRect(640, 290, 51, 51));
        panorema_save->setFont(font);
        panorema_save->setFocusPolicy(Qt::NoFocus);
        panorema_save->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: transparent;\n"
"border-image:url(:/res/res/pic_confirm_ok.png);\n"
"}  \n"
""));
        panorema_save->setIconSize(QSize(25, 25));
        panorema_save->setAutoRepeat(true);
        panorema_save->setAutoRepeatDelay(1000);
        panorema_save->setAutoRepeatInterval(300);
        panorema_save->setAutoRaise(true);
        panorema_save->setArrowType(Qt::NoArrow);
        previewPanorama = new QLabel(Hp_Panorama);
        previewPanorama->setObjectName(QStringLiteral("previewPanorama"));
        previewPanorama->setGeometry(QRect(640, 40, 111, 95));
        previewPanorama->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 70);"));
        panorema_cancel = new QToolButton(Hp_Panorama);
        panorema_cancel->setObjectName(QStringLiteral("panorema_cancel"));
        panorema_cancel->setGeometry(QRect(640, 370, 51, 51));
        panorema_cancel->setFont(font);
        panorema_cancel->setFocusPolicy(Qt::NoFocus);
        panorema_cancel->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: transparent;\n"
"border-image:url(:/res/res/cancel_panorama.png);\n"
"}\n"
""));
        panorema_cancel->setIconSize(QSize(25, 25));
        panorema_cancel->setAutoRepeat(true);
        panorema_cancel->setAutoRepeatDelay(1000);
        panorema_cancel->setAutoRepeatInterval(300);
        panorema_cancel->setAutoRaise(true);
        panorema_cancel->setArrowType(Qt::NoArrow);
        label_8 = new QLabel(Hp_Panorama);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(650, 200, 381, 41));
        label_8->setFont(font2);
        label_8->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: transparent;"));
        label_8->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_Panorama);

        QMetaObject::connectSlotsByName(Hp_Panorama);
    } // setupUi

    void retranslateUi(QWidget *Hp_Panorama)
    {
        Hp_Panorama->setWindowTitle(QApplication::translate("Hp_Panorama", "Form", nullptr));
        panoramaView->setText(QString());
        panoramaView_2->setText(QString());
        panorema_ok_2->setText(QString());
        label_5->setText(QApplication::translate("Hp_Panorama", "\345\215\225\345\207\273\345\217\263\344\276\247\346\214\211\351\222\256\347\273\223\346\235\237\346\213\274\346\216\245", nullptr));
        panorema_ok->setText(QString());
        label_7->setText(QApplication::translate("Hp_Panorama", "\346\250\252\345\220\221\345\205\250\346\231\257", nullptr));
        label_degree->setText(QApplication::translate("Hp_Panorama", "100%", nullptr));
        label_degreeTips->setText(QApplication::translate("Hp_Panorama", "\345\214\271\351\205\215\345\272\246\351\234\200\345\244\247\344\272\21630%", nullptr));
        panorema_save->setText(QString());
        previewPanorama->setText(QString());
        panorema_cancel->setText(QString());
        label_8->setText(QApplication::translate("Hp_Panorama", "\345\215\225\345\207\273\344\270\213\346\226\271\346\214\211\351\222\256\351\200\211\346\213\251\346\230\257\345\220\246\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Panorama: public Ui_Hp_Panorama {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_PANORAMA_H
