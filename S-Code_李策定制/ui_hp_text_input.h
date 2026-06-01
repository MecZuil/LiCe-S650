/********************************************************************************
** Form generated from reading UI file 'hp_text_input.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_TEXT_INPUT_H
#define UI_HP_TEXT_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <hp_style_listwidget.h>
#include "frminput.h"

QT_BEGIN_NAMESPACE

class Ui_Hp_Text_Input
{
public:
    QFrame *frame;
    QToolButton *toolButton_back;
    QFrame *frame_2;
    QLineEdit *lineEdit;
    QLabel *label;
    frmInput *widget;
    hp_style_listwidget *listWidget;

    void setupUi(QWidget *Hp_Text_Input)
    {
        if (Hp_Text_Input->objectName().isEmpty())
            Hp_Text_Input->setObjectName(QStringLiteral("Hp_Text_Input"));
        Hp_Text_Input->resize(800, 480);
        QFont font;
        font.setPointSize(17);
        Hp_Text_Input->setFont(font);
        Hp_Text_Input->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(Hp_Text_Input);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 160, 480));
        frame->setFont(font);
        frame->setStyleSheet(QStringLiteral("background-image:url(:/res/res/main_background.png);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        toolButton_back = new QToolButton(frame);
        toolButton_back->setObjectName(QStringLiteral("toolButton_back"));
        toolButton_back->setGeometry(QRect(10, 16, 141, 54));
        toolButton_back->setFont(font);
        toolButton_back->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_back->setAutoRaise(true);
        frame_2 = new QFrame(Hp_Text_Input);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(160, 0, 640, 480));
        QFont font1;
        font1.setPointSize(15);
        frame_2->setFont(font1);
        frame_2->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(3, 51, 633, 56));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(21);
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid #7CA6C9;\n"
"    border-radius: 1px;\n"
"    padding: 0 8px;\n"
"\n"
"background-color: rgba(51, 82, 126,200);\n"
"color:#7CA6C9;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit->setMaxLength(32);
        lineEdit->setFrame(false);
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 640, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(20);
        label->setFont(font3);
        label->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        widget = new frmInput(frame_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 110, 640, 361));
        widget->setFont(font);
        listWidget = new hp_style_listwidget(frame_2);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 110, 640, 361));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"	border:0px solid #ffffff;\n"
"	background-image:url(:/res/res/setting_background.png);\n"
"}\n"
"QListWidget::Item{\n"
"	height:50px;\n"
"	color:#7CA6C9;\n"
"}\n"
"QListWidget::Item:selected{\n"
"	height:50px;\n"
"	color:#ffffff;\n"
"}QScrollBar:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:#32CC99;\n"
"	width:40px;\n"
"	margin:40 0 40 0px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\350\256\276\347\275\256 */\n"
"QScrollBar::handle:vertical {\n"
"/*	background-color:#7CA6C9;*/	\n"
"	background-color: rgb(83, 166, 249);\n"
"	border:1px solid #7CA6C9;\n"
"	height:30px;\n"
"	max-height:20px;\n"
"}\n"
"\n"
"/* \345\272\225\351\203\250\346\216\247\345\210\266\345\235\227 */\n"
"QScrollBar::add-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:transparent;\n"
"	width:40px;\n"
"	height:40px;\n"
"	subcontrol-position:bottom;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_down_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \351\241\266\351\203\250\346\216"
                        "\247\345\210\266\345\235\227 */\n"
"QScrollBar::sub-line:vertical {\n"
"	border:0px solid #7CA6C9;\n"
"	background-color:transparent;\n"
"	width:40px;\n"
"	height:40px;\n"
"	subcontrol-position:top;\n"
"	subcontrol-origin:margin;\n"
"	border-image: url(:/res/res/m_up_arrow_s.png);\n"
"	\n"
"}\n"
"\n"
"/* \346\216\247\345\210\266\345\235\227\344\270\212\347\232\204\345\260\217\347\256\255\345\244\264 */\n"
"QScrollBar::up-arrow:vertical,QScrollBar::down-arrow:vertical {\n"
"	border:0px;\n"
"	width:40px;\n"
"	height:40px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\212\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::add-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\344\270\213\350\276\271\345\214\272\345\237\237 */\n"
"QScrollBar::sub-page:vertical {\n"
"	background-color:transparent;\n"
"}\n"
""));
        lineEdit->raise();
        label->raise();
        listWidget->raise();
        widget->raise();

        retranslateUi(Hp_Text_Input);
        QObject::connect(toolButton_back, SIGNAL(released()), Hp_Text_Input, SLOT(close()));

        QMetaObject::connectSlotsByName(Hp_Text_Input);
    } // setupUi

    void retranslateUi(QWidget *Hp_Text_Input)
    {
        Hp_Text_Input->setWindowTitle(QApplication::translate("Hp_Text_Input", "Form", nullptr));
        toolButton_back->setText(QApplication::translate("Hp_Text_Input", "OK", nullptr));
        lineEdit->setText(QString());
        label->setText(QApplication::translate("Hp_Text_Input", "INPUT:", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Hp_Text_Input", "1: \344\270\273\345\217\230\345\216\213\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Hp_Text_Input", "2: \345\245\227\347\256\241", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Hp_Text_Input", "3: \347\224\265\346\265\201\344\272\222\346\204\237\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Hp_Text_Input", "4: \347\224\265\345\216\213\344\272\222\346\204\237\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("Hp_Text_Input", "5: \346\262\271\346\265\270\345\274\217\345\217\230\345\216\213\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("Hp_Text_Input", "6: \351\253\230\345\216\213\347\273\204\345\220\210\344\272\222\346\204\237\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("Hp_Text_Input", "7: \351\232\224\347\246\273\345\274\200\345\205\263", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("Hp_Text_Input", "8: \351\253\230\345\216\213\351\232\224\347\246\273\345\274\200\345\205\263", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("Hp_Text_Input", "9: \344\275\216\345\216\213\345\210\200\351\227\270\345\274\200\345\205\263", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("Hp_Text_Input", "10: \346\257\215\347\272\277\344\276\247\351\232\224\347\246\273\345\274\200\345\205\263", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = listWidget->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("Hp_Text_Input", "11: \347\272\277\350\267\257\344\276\247\351\232\224\347\246\273\345\274\200\345\205\263", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = listWidget->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("Hp_Text_Input", "12: \345\217\230\345\216\213\345\231\250\351\232\224\347\246\273\345\274\200\345\205\263", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = listWidget->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("Hp_Text_Input", "13: \347\224\265\345\216\213\344\272\222\346\204\237\345\231\250\351\232\224\347\246\273\345\274\200\345\205\263", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = listWidget->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("Hp_Text_Input", "14: \346\257\215\347\272\277\344\270\216\346\227\201\350\267\257\346\257\215\347\272\277\350\201\224\347\273\234\351\227\270\345\210\200", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = listWidget->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("Hp_Text_Input", "15: \345\217\230\345\216\213\345\231\250\344\270\255\346\200\247\347\202\271\346\216\245\345\234\260\347\224\250\351\232\224\347\246\273\345\274\200\345\205\263", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = listWidget->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("Hp_Text_Input", "16: \351\201\277\351\233\267\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = listWidget->item(16);
        ___qlistwidgetitem16->setText(QApplication::translate("Hp_Text_Input", "17: \346\226\255\350\267\257\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = listWidget->item(17);
        ___qlistwidgetitem17->setText(QApplication::translate("Hp_Text_Input", "18: \347\251\272\346\260\224\346\226\255\350\267\257\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem18 = listWidget->item(18);
        ___qlistwidgetitem18->setText(QApplication::translate("Hp_Text_Input", "19: \351\253\230\345\216\213\350\267\214\350\220\275\345\274\217\347\206\224\346\226\255\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem19 = listWidget->item(19);
        ___qlistwidgetitem19->setText(QApplication::translate("Hp_Text_Input", "20: \347\224\265\347\274\206", nullptr));
        QListWidgetItem *___qlistwidgetitem20 = listWidget->item(20);
        ___qlistwidgetitem20->setText(QApplication::translate("Hp_Text_Input", "21: \346\257\215\347\272\277", nullptr));
        QListWidgetItem *___qlistwidgetitem21 = listWidget->item(21);
        ___qlistwidgetitem21->setText(QApplication::translate("Hp_Text_Input", "22: \346\227\201\350\267\257\346\257\215\347\272\277", nullptr));
        QListWidgetItem *___qlistwidgetitem22 = listWidget->item(22);
        ___qlistwidgetitem22->setText(QApplication::translate("Hp_Text_Input", "23: \345\271\266\350\201\224\347\224\265\345\256\271\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem23 = listWidget->item(23);
        ___qlistwidgetitem23->setText(QApplication::translate("Hp_Text_Input", "24: \344\270\262\350\201\224\347\224\265\345\256\271\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem24 = listWidget->item(24);
        ___qlistwidgetitem24->setText(QApplication::translate("Hp_Text_Input", "25: \347\224\265\346\212\227\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem25 = listWidget->item(25);
        ___qlistwidgetitem25->setText(QApplication::translate("Hp_Text_Input", "26: \346\266\210\345\274\247\347\272\277\345\234\210", nullptr));
        QListWidgetItem *___qlistwidgetitem26 = listWidget->item(26);
        ___qlistwidgetitem26->setText(QApplication::translate("Hp_Text_Input", "27: \346\216\245\345\234\260\347\224\265\351\230\273", nullptr));
        QListWidgetItem *___qlistwidgetitem27 = listWidget->item(27);
        ___qlistwidgetitem27->setText(QApplication::translate("Hp_Text_Input", "28: \347\251\272\346\260\224\345\210\266\345\212\250\347\224\265\351\230\273", nullptr));
        QListWidgetItem *___qlistwidgetitem28 = listWidget->item(28);
        ___qlistwidgetitem28->setText(QApplication::translate("Hp_Text_Input", "29: \350\200\246\345\220\210\347\224\265\345\256\271\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem29 = listWidget->item(29);
        ___qlistwidgetitem29->setText(QApplication::translate("Hp_Text_Input", "30: \347\273\223\345\220\210\347\224\265\345\256\271\345\231\250", nullptr));
        QListWidgetItem *___qlistwidgetitem30 = listWidget->item(30);
        ___qlistwidgetitem30->setText(QApplication::translate("Hp_Text_Input", "31: \351\230\273\346\263\242\345\231\250", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Hp_Text_Input: public Ui_Hp_Text_Input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_TEXT_INPUT_H
