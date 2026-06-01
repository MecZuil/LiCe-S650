/********************************************************************************
** Form generated from reading UI file 'hppreview.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPPREVIEW_H
#define UI_HPPREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HpPreview
{
public:
    QFrame *frame;
    QToolButton *next_page;
    QToolButton *last_page;
    QLabel *pages_info;
    QToolButton *twice_analisys;
    QToolButton *delete_pic;
    QToolButton *close;
    QListWidget *listWidget;
    QLabel *label;
    QLabel *voice_1;
    QLabel *text_1;
    QLabel *text_2;
    QLabel *voice_2;
    QLabel *text_3;
    QLabel *voice_3;
    QLabel *text_4;
    QLabel *voice_4;
    QLabel *voice_5;
    QLabel *text_5;
    QLabel *text_6;
    QLabel *voice_6;
    QLabel *voice_7;
    QLabel *text_7;
    QLabel *text_8;
    QLabel *voice_8;
    QLabel *label_sd;
    QToolButton *list_type;
    QLabel *sr_1;
    QLabel *sr_2;
    QLabel *sr_3;
    QLabel *sr_4;
    QLabel *sr_5;
    QLabel *sr_6;
    QLabel *sr_7;
    QLabel *sr_8;

    void setupUi(QWidget *HpPreview)
    {
        if (HpPreview->objectName().isEmpty())
            HpPreview->setObjectName(QStringLiteral("HpPreview"));
        HpPreview->resize(800, 480);
        QFont font;
        font.setPointSize(15);
        HpPreview->setFont(font);
        HpPreview->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(HpPreview);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 800, 480));
        QFont font1;
        font1.setPointSize(17);
        frame->setFont(font1);
        frame->setStyleSheet(QLatin1String("background-image:url(:/res/res/setting_background.png);\n"
""));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        next_page = new QToolButton(frame);
        next_page->setObjectName(QStringLiteral("next_page"));
        next_page->setGeometry(QRect(700, 410, 65, 65));
        QFont font2;
        font2.setPointSize(18);
        next_page->setFont(font2);
        next_page->setFocusPolicy(Qt::NoFocus);
        next_page->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/next_page_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/next_page_s.png);\n"
"}\n"
"\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/next_page_d.png);\n"
"}"));
        next_page->setAutoRaise(true);
        next_page->setArrowType(Qt::NoArrow);
        last_page = new QToolButton(frame);
        last_page->setObjectName(QStringLiteral("last_page"));
        last_page->setGeometry(QRect(630, 410, 65, 65));
        last_page->setFont(font2);
        last_page->setFocusPolicy(Qt::NoFocus);
        last_page->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/pre_page_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/pre_page_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/pre_page_d.png);\n"
"}"));
        last_page->setAutoRaise(true);
        pages_info = new QLabel(frame);
        pages_info->setObjectName(QStringLiteral("pages_info"));
        pages_info->setGeometry(QRect(510, 410, 111, 65));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\346\255\243\351\273\221"));
        font3.setPointSize(20);
        pages_info->setFont(font3);
        pages_info->setStyleSheet(QLatin1String("background: transparent;\n"
"color:#7CA6C9;"));
        pages_info->setFrameShape(QFrame::NoFrame);
        pages_info->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        twice_analisys = new QToolButton(frame);
        twice_analisys->setObjectName(QStringLiteral("twice_analisys"));
        twice_analisys->setGeometry(QRect(367, 410, 65, 65));
        twice_analisys->setFont(font2);
        twice_analisys->setFocusPolicy(Qt::NoFocus);
        twice_analisys->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/play_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/play_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/play_d.png);\n"
"}"));
        twice_analisys->setAutoRaise(true);
        delete_pic = new QToolButton(frame);
        delete_pic->setObjectName(QStringLiteral("delete_pic"));
        delete_pic->setGeometry(QRect(295, 410, 65, 65));
        delete_pic->setFont(font1);
        delete_pic->setFocusPolicy(Qt::NoFocus);
        delete_pic->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/delete_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/delete_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/delete_d.png);\n"
"}"));
        delete_pic->setAutoRaise(true);
        close = new QToolButton(frame);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(210, 410, 81, 65));
        close->setFont(font1);
        close->setFocusPolicy(Qt::NoFocus);
        close->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/back_n.png);\n"
"color:#7CA6C9;\n"
"background:transparent;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/back_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/back_d.png);\n"
"}"));
        close->setAutoRaise(true);
        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(4, 4, 791, 401));
        QFont font4;
        font4.setPointSize(11);
        listWidget->setFont(font4);
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setAutoFillBackground(true);
        listWidget->setStyleSheet(QLatin1String("color:#7CA6C9;\n"
"background:transparent;\n"
"selection-color: rgb(82, 107, 161);\n"
"selection-background-color: rgb(179, 163, 163);\n"
"border:1px solid #2B5C83;\n"
"\n"
"padding-top: 10px;\n"
"padding-left:10px;\n"
""));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setFrameShadow(QFrame::Plain);
        listWidget->setLineWidth(1);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        listWidget->setAutoScroll(false);
        listWidget->setAutoScrollMargin(0);
        listWidget->setEditTriggers(QAbstractItemView::SelectedClicked);
        listWidget->setProperty("showDropIndicator", QVariant(false));
        listWidget->setAlternatingRowColors(false);
        listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        listWidget->setIconSize(QSize(180, 135));
        listWidget->setTextElideMode(Qt::ElideLeft);
        listWidget->setMovement(QListView::Static);
        listWidget->setProperty("isWrapping", QVariant(true));
        listWidget->setResizeMode(QListView::Fixed);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setSpacing(10);
        listWidget->setGridSize(QSize(192, 200));
        listWidget->setViewMode(QListView::IconMode);
        listWidget->setModelColumn(0);
        listWidget->setUniformItemSizes(false);
        listWidget->setBatchSize(120);
        listWidget->setSelectionRectVisible(false);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(25, 410, 40, 61));
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("border-image:url(:/res/res/sd_ok.png);\n"
"border-color: transparent;"));
        voice_1 = new QLabel(frame);
        voice_1->setObjectName(QStringLiteral("voice_1"));
        voice_1->setGeometry(QRect(95, 20, 31, 31));
        voice_1->setStyleSheet(QStringLiteral("border-image: url(:/res/res/audio_64.png);"));
        text_1 = new QLabel(frame);
        text_1->setObjectName(QStringLiteral("text_1"));
        text_1->setGeometry(QRect(60, 20, 30, 30));
        text_1->setStyleSheet(QStringLiteral("border-image: url(:/res/res/text_64.png);"));
        text_2 = new QLabel(frame);
        text_2->setObjectName(QStringLiteral("text_2"));
        text_2->setGeometry(QRect(252, 20, 30, 30));
        text_2->setStyleSheet(QStringLiteral("border-image: url(:/res/res/text_64.png);"));
        voice_2 = new QLabel(frame);
        voice_2->setObjectName(QStringLiteral("voice_2"));
        voice_2->setGeometry(QRect(287, 20, 30, 30));
        voice_2->setStyleSheet(QStringLiteral("border-image: url(:/res/res/audio_64.png);"));
        text_3 = new QLabel(frame);
        text_3->setObjectName(QStringLiteral("text_3"));
        text_3->setGeometry(QRect(444, 20, 30, 30));
        text_3->setStyleSheet(QStringLiteral("border-image: url(:/res/res/text_64.png);"));
        voice_3 = new QLabel(frame);
        voice_3->setObjectName(QStringLiteral("voice_3"));
        voice_3->setGeometry(QRect(479, 20, 30, 30));
        voice_3->setStyleSheet(QStringLiteral("border-image: url(:/res/res/audio_64.png);"));
        text_4 = new QLabel(frame);
        text_4->setObjectName(QStringLiteral("text_4"));
        text_4->setGeometry(QRect(636, 20, 30, 30));
        text_4->setStyleSheet(QStringLiteral("border-image: url(:/res/res/text_64.png);"));
        voice_4 = new QLabel(frame);
        voice_4->setObjectName(QStringLiteral("voice_4"));
        voice_4->setGeometry(QRect(671, 20, 30, 30));
        voice_4->setStyleSheet(QStringLiteral("border-image: url(:/res/res/audio_64.png);"));
        voice_5 = new QLabel(frame);
        voice_5->setObjectName(QStringLiteral("voice_5"));
        voice_5->setGeometry(QRect(95, 220, 30, 30));
        voice_5->setStyleSheet(QStringLiteral("border-image: url(:/res/res/audio_64.png);"));
        text_5 = new QLabel(frame);
        text_5->setObjectName(QStringLiteral("text_5"));
        text_5->setGeometry(QRect(60, 220, 30, 30));
        text_5->setStyleSheet(QStringLiteral("border-image: url(:/res/res/text_64.png);"));
        text_6 = new QLabel(frame);
        text_6->setObjectName(QStringLiteral("text_6"));
        text_6->setGeometry(QRect(252, 220, 30, 30));
        text_6->setStyleSheet(QStringLiteral("border-image: url(:/res/res/text_64.png);"));
        voice_6 = new QLabel(frame);
        voice_6->setObjectName(QStringLiteral("voice_6"));
        voice_6->setGeometry(QRect(287, 220, 30, 30));
        voice_6->setStyleSheet(QStringLiteral("border-image: url(:/res/res/audio_64.png);"));
        voice_7 = new QLabel(frame);
        voice_7->setObjectName(QStringLiteral("voice_7"));
        voice_7->setGeometry(QRect(479, 220, 30, 30));
        voice_7->setStyleSheet(QStringLiteral("border-image: url(:/res/res/audio_64.png);"));
        text_7 = new QLabel(frame);
        text_7->setObjectName(QStringLiteral("text_7"));
        text_7->setGeometry(QRect(444, 220, 30, 30));
        text_7->setStyleSheet(QStringLiteral("border-image: url(:/res/res/text_64.png);"));
        text_8 = new QLabel(frame);
        text_8->setObjectName(QStringLiteral("text_8"));
        text_8->setGeometry(QRect(636, 220, 30, 30));
        text_8->setStyleSheet(QStringLiteral("border-image: url(:/res/res/text_64.png);"));
        voice_8 = new QLabel(frame);
        voice_8->setObjectName(QStringLiteral("voice_8"));
        voice_8->setGeometry(QRect(671, 220, 30, 30));
        voice_8->setStyleSheet(QStringLiteral("border-image: url(:/res/res/audio_64.png);"));
        label_sd = new QLabel(frame);
        label_sd->setObjectName(QStringLiteral("label_sd"));
        label_sd->setGeometry(QRect(65, 410, 141, 65));
        QFont font5;
        font5.setPointSize(16);
        label_sd->setFont(font5);
        label_sd->setStyleSheet(QLatin1String("background: transparent;\n"
"background-color: transparent;\n"
"color:#7CA6C9;"));
        label_sd->setAlignment(Qt::AlignCenter);
        list_type = new QToolButton(frame);
        list_type->setObjectName(QStringLiteral("list_type"));
        list_type->setGeometry(QRect(440, 410, 65, 65));
        list_type->setFont(font4);
        list_type->setFocusPolicy(Qt::NoFocus);
        list_type->setStyleSheet(QStringLiteral(""));
        list_type->setAutoRaise(true);
        sr_1 = new QLabel(frame);
        sr_1->setObjectName(QStringLiteral("sr_1"));
        sr_1->setGeometry(QRect(130, 20, 31, 31));
        sr_1->setStyleSheet(QLatin1String("border-image: url(:/res/res/sr_64.png);\n"
"background:transparent;"));
        sr_2 = new QLabel(frame);
        sr_2->setObjectName(QStringLiteral("sr_2"));
        sr_2->setGeometry(QRect(322, 20, 31, 31));
        sr_2->setStyleSheet(QLatin1String("border-image: url(:/res/res/sr_64.png);\n"
"background:transparent;"));
        sr_3 = new QLabel(frame);
        sr_3->setObjectName(QStringLiteral("sr_3"));
        sr_3->setGeometry(QRect(514, 20, 31, 31));
        sr_3->setStyleSheet(QLatin1String("border-image: url(:/res/res/sr_64.png);\n"
"background:transparent;"));
        sr_4 = new QLabel(frame);
        sr_4->setObjectName(QStringLiteral("sr_4"));
        sr_4->setGeometry(QRect(706, 20, 31, 31));
        sr_4->setStyleSheet(QLatin1String("border-image: url(:/res/res/sr_64.png);\n"
"background:transparent;"));
        sr_5 = new QLabel(frame);
        sr_5->setObjectName(QStringLiteral("sr_5"));
        sr_5->setGeometry(QRect(130, 220, 31, 31));
        sr_5->setStyleSheet(QLatin1String("border-image: url(:/res/res/sr_64.png);\n"
"background:transparent;"));
        sr_6 = new QLabel(frame);
        sr_6->setObjectName(QStringLiteral("sr_6"));
        sr_6->setGeometry(QRect(322, 220, 31, 31));
        sr_6->setStyleSheet(QLatin1String("border-image: url(:/res/res/sr_64.png);\n"
"background:transparent;"));
        sr_7 = new QLabel(frame);
        sr_7->setObjectName(QStringLiteral("sr_7"));
        sr_7->setGeometry(QRect(514, 220, 31, 31));
        sr_7->setStyleSheet(QLatin1String("border-image: url(:/res/res/sr_64.png);\n"
"background:transparent;"));
        sr_8 = new QLabel(frame);
        sr_8->setObjectName(QStringLiteral("sr_8"));
        sr_8->setGeometry(QRect(706, 220, 31, 31));
        sr_8->setStyleSheet(QLatin1String("border-image: url(:/res/res/sr_64.png);\n"
"background:transparent;"));

        retranslateUi(HpPreview);

        QMetaObject::connectSlotsByName(HpPreview);
    } // setupUi

    void retranslateUi(QWidget *HpPreview)
    {
        HpPreview->setWindowTitle(QApplication::translate("HpPreview", "Form", nullptr));
        next_page->setText(QString());
        last_page->setText(QString());
        pages_info->setText(QApplication::translate("HpPreview", "<html><head/><body><p align=\"center\">CP/TP</p></body></html>", nullptr));
        twice_analisys->setText(QString());
        delete_pic->setText(QString());
        close->setText(QString());
        label->setText(QString());
        voice_1->setText(QString());
        text_1->setText(QString());
        text_2->setText(QString());
        voice_2->setText(QString());
        text_3->setText(QString());
        voice_3->setText(QString());
        text_4->setText(QString());
        voice_4->setText(QString());
        voice_5->setText(QString());
        text_5->setText(QString());
        text_6->setText(QString());
        voice_6->setText(QString());
        voice_7->setText(QString());
        text_7->setText(QString());
        text_8->setText(QString());
        voice_8->setText(QString());
        label_sd->setText(QApplication::translate("HpPreview", "15264/15264MB", nullptr));
        list_type->setText(QString());
        sr_1->setText(QString());
        sr_2->setText(QString());
        sr_3->setText(QString());
        sr_4->setText(QString());
        sr_5->setText(QString());
        sr_6->setText(QString());
        sr_7->setText(QString());
        sr_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HpPreview: public Ui_HpPreview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPPREVIEW_H
