/********************************************************************************
** Form generated from reading UI file 'hp_bel_search_old.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_BEL_SEARCH_OLD_H
#define UI_HP_BEL_SEARCH_OLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Bel_Search_Old
{
public:
    QFrame *frame;
    QToolButton *toolButton_back;
    QToolButton *toolButton_connect;
    QToolButton *toolButton_search;
    QToolButton *toolButton_disconnect;
    QFrame *frame_2;
    QListWidget *listWidget;
    QListWidget *listWidget_match;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_3;

    void setupUi(QWidget *Hp_Bel_Search_Old)
    {
        if (Hp_Bel_Search_Old->objectName().isEmpty())
            Hp_Bel_Search_Old->setObjectName(QStringLiteral("Hp_Bel_Search_Old"));
        Hp_Bel_Search_Old->resize(800, 480);
        Hp_Bel_Search_Old->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        frame = new QFrame(Hp_Bel_Search_Old);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 160, 480));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        toolButton_back = new QToolButton(frame);
        toolButton_back->setObjectName(QStringLiteral("toolButton_back"));
        toolButton_back->setGeometry(QRect(3, 10, 155, 70));
        QPalette palette;
        QBrush brush(QColor(124, 166, 201, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(128, 128, 128, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        toolButton_back->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        toolButton_back->setFont(font);
        toolButton_back->setStyleSheet(QLatin1String("/*QToolButton {\n"
"background-image:url(:/res/res/setting_back.png);\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"background-image:url(:/res/res/setting_back.png);\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}\n"
"QToolButton:disabled{\n"
"background-image:url(:/res/res/setting_back.png);\n"
"border-image:url(:/res/res/mode_button_d.png);\n"
"\n"
"color:gray;\n"
"}*/\n"
"\n"
"border-image:url(:/res/res/setting_back.png);"));
        toolButton_connect = new QToolButton(frame);
        toolButton_connect->setObjectName(QStringLiteral("toolButton_connect"));
        toolButton_connect->setGeometry(QRect(3, 360, 155, 70));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        toolButton_connect->setFont(font1);
        toolButton_connect->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/mode_button_d.png);\n"
"\n"
"color:gray;\n"
"}"));
        toolButton_search = new QToolButton(frame);
        toolButton_search->setObjectName(QStringLiteral("toolButton_search"));
        toolButton_search->setGeometry(QRect(3, 120, 155, 70));
        toolButton_search->setFont(font1);
        toolButton_search->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/mode_button_d.png);\n"
"\n"
"color:gray;\n"
"}"));
        toolButton_disconnect = new QToolButton(frame);
        toolButton_disconnect->setObjectName(QStringLiteral("toolButton_disconnect"));
        toolButton_disconnect->setGeometry(QRect(3, 240, 155, 70));
        toolButton_disconnect->setFont(font1);
        toolButton_disconnect->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/mode_button_d.png);\n"
"\n"
"color:gray;\n"
"}"));
        frame_2 = new QFrame(Hp_Bel_Search_Old);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(160, 0, 640, 480));
        QFont font2;
        font2.setKerning(true);
        frame_2->setFont(font2);
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(0);
        listWidget = new QListWidget(frame_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(150, 44, 301, 200));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        listWidget->setFont(font3);
        listWidget->setStyleSheet(QLatin1String("border-top-color: rgb(19, 31, 200);\n"
"border-right-color: rgb(255, 255, 0);\n"
"border-bottom-color: rgb(255, 0, 0);\n"
"border-left-color: rgb(255, 255, 127);"));
        listWidget->setFrameShape(QFrame::Box);
        listWidget->setFrameShadow(QFrame::Plain);
        listWidget->setLineWidth(0);
        listWidget->setMidLineWidth(0);
        listWidget_match = new QListWidget(frame_2);
        listWidget_match->setObjectName(QStringLiteral("listWidget_match"));
        listWidget_match->setGeometry(QRect(150, 277, 301, 200));
        listWidget_match->setFont(font3);
        listWidget_match->setStyleSheet(QLatin1String("border-top-color: rgb(19, 31, 200);\n"
"border-right-color: rgb(255, 255, 0);\n"
"border-bottom-color: rgb(255, 0, 0);\n"
"border-left-color: rgb(255, 255, 127);"));
        listWidget_match->setFrameShape(QFrame::Box);
        listWidget_match->setFrameShadow(QFrame::Plain);
        listWidget_match->setLineWidth(0);
        listWidget_match->setMidLineWidth(0);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(139, 240, 311, 38));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        label_2->setFont(font4);
        label_2->setStyleSheet(QLatin1String("color:#7CA6C9;\n"
"\n"
"background:transparent;"));
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(34, 60, 81, 61));
        QFont font5;
        font5.setPointSize(19);
        pushButton->setFont(font5);
        pushButton->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(281, 10, 341, 31));
        label->setFont(font4);
        label->setStyleSheet(QLatin1String("color:#7CA6C9;\n"
"background:transparent;"));
        label->setFrameShape(QFrame::NoFrame);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(139, 10, 141, 31));
        label_3->setFont(font4);
        label_3->setStyleSheet(QLatin1String("color:#7CA6C9;\n"
"\n"
"background:transparent;"));
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(Hp_Bel_Search_Old);

        QMetaObject::connectSlotsByName(Hp_Bel_Search_Old);
    } // setupUi

    void retranslateUi(QWidget *Hp_Bel_Search_Old)
    {
        Hp_Bel_Search_Old->setWindowTitle(QApplication::translate("Hp_Bel_Search_Old", "Form", nullptr));
        toolButton_back->setText(QString());
        toolButton_connect->setText(QApplication::translate("Hp_Bel_Search_Old", "\350\277\236\346\216\245\350\200\263\346\234\272", nullptr));
        toolButton_search->setText(QApplication::translate("Hp_Bel_Search_Old", "\346\220\234\347\264\242\350\200\263\346\234\272", nullptr));
        toolButton_disconnect->setText(QApplication::translate("Hp_Bel_Search_Old", "\346\226\255\345\274\200\350\200\263\346\234\272", nullptr));
        label_2->setText(QApplication::translate("Hp_Bel_Search_Old", "\345\267\262\351\205\215\345\257\271\350\256\276\345\244\207\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("Hp_Bel_Search_Old", "\345\210\267\346\226\260", nullptr));
        label->setText(QString());
        label_3->setText(QApplication::translate("Hp_Bel_Search_Old", "\345\217\257\347\224\250\350\256\276\345\244\207\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Bel_Search_Old: public Ui_Hp_Bel_Search_Old {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_BEL_SEARCH_OLD_H
