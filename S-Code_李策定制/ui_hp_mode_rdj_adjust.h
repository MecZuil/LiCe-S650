/********************************************************************************
** Form generated from reading UI file 'hp_mode_rdj_adjust.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_MODE_RDJ_ADJUST_H
#define UI_HP_MODE_RDJ_ADJUST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <hp_qdoublespinboxset.h>

QT_BEGIN_NAMESPACE

class Ui_Hp_Mode_Rdj_Adjust
{
public:
    QFrame *frame;
    QToolButton *toolButton_finish;
    QToolButton *toolButton_default;
    QFrame *frame_back;
    QFrame *frame_rdj;
    hp_QDoubleSpinBoxSet *doubleSpinBox_high;
    hp_QDoubleSpinBoxSet *doubleSpinBox_low;
    hp_QDoubleSpinBoxSet *doubleSpinBox_above;
    hp_QDoubleSpinBoxSet *doubleSpinBox_below;
    QLabel *label_rdj_type;
    QComboBox *comboBox_rdj_type;
    QFrame *frame_rdj_back;
    QFrame *frame_rdj_type;
    QLabel *label_rdj_type_2;
    QLabel *label_rdj_type_3;
    QListWidget *listWidget_rdj_type;
    QFrame *frame_all;

    void setupUi(QWidget *Hp_Mode_Rdj_Adjust)
    {
        if (Hp_Mode_Rdj_Adjust->objectName().isEmpty())
            Hp_Mode_Rdj_Adjust->setObjectName(QStringLiteral("Hp_Mode_Rdj_Adjust"));
        Hp_Mode_Rdj_Adjust->resize(800, 480);
        Hp_Mode_Rdj_Adjust->setStyleSheet(QLatin1String("background-color: rgb(0, 8, 16);\n"
"background-image:url(:/res/res/setting_background.png);"));
        frame = new QFrame(Hp_Mode_Rdj_Adjust);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 160, 480));
        frame->setStyleSheet(QStringLiteral("background-image:url(:/res/res/main_background.png);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        toolButton_finish = new QToolButton(frame);
        toolButton_finish->setObjectName(QStringLiteral("toolButton_finish"));
        toolButton_finish->setGeometry(QRect(0, 0, 160, 70));
        QFont font;
        font.setPointSize(17);
        toolButton_finish->setFont(font);
        toolButton_finish->setFocusPolicy(Qt::NoFocus);
        toolButton_finish->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/setting_back.png);\n"
"}  \n"
""));
        toolButton_finish->setIconSize(QSize(25, 25));
        toolButton_finish->setAutoRaise(true);
        toolButton_finish->setArrowType(Qt::NoArrow);
        toolButton_default = new QToolButton(frame);
        toolButton_default->setObjectName(QStringLiteral("toolButton_default"));
        toolButton_default->setGeometry(QRect(3, 80, 151, 70));
        toolButton_default->setFont(font);
        toolButton_default->setFocusPolicy(Qt::NoFocus);
        toolButton_default->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton_default->setAutoRaise(true);
        frame_back = new QFrame(frame);
        frame_back->setObjectName(QStringLiteral("frame_back"));
        frame_back->setGeometry(QRect(-2, 0, 180, 481));
        frame_back->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        frame_back->setFrameShape(QFrame::StyledPanel);
        frame_back->setFrameShadow(QFrame::Raised);
        frame_back->raise();
        toolButton_default->raise();
        toolButton_finish->raise();
        frame_rdj = new QFrame(Hp_Mode_Rdj_Adjust);
        frame_rdj->setObjectName(QStringLiteral("frame_rdj"));
        frame_rdj->setGeometry(QRect(283, 123, 353, 231));
        frame_rdj->setStyleSheet(QStringLiteral("background-image:url(:/res/res/mode_bg.png);"));
        frame_rdj->setFrameShape(QFrame::NoFrame);
        frame_rdj->setFrameShadow(QFrame::Raised);
        doubleSpinBox_high = new hp_QDoubleSpinBoxSet(frame_rdj);
        doubleSpinBox_high->setObjectName(QStringLiteral("doubleSpinBox_high"));
        doubleSpinBox_high->setGeometry(QRect(1, 47, 350, 44));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(17);
        doubleSpinBox_high->setFont(font1);
        doubleSpinBox_high->setFocusPolicy(Qt::NoFocus);
        doubleSpinBox_high->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
""
                        "QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}"));
        doubleSpinBox_high->setAlignment(Qt::AlignCenter);
        doubleSpinBox_high->setAccelerated(true);
        doubleSpinBox_high->setDecimals(1);
        doubleSpinBox_high->setMinimum(-200);
        doubleSpinBox_high->setMaximum(2000);
        doubleSpinBox_high->setSingleStep(0.1);
        doubleSpinBox_low = new hp_QDoubleSpinBoxSet(frame_rdj);
        doubleSpinBox_low->setObjectName(QStringLiteral("doubleSpinBox_low"));
        doubleSpinBox_low->setGeometry(QRect(1, 93, 350, 44));
        doubleSpinBox_low->setFont(font1);
        doubleSpinBox_low->setFocusPolicy(Qt::NoFocus);
        doubleSpinBox_low->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
""
                        "QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}"));
        doubleSpinBox_low->setAlignment(Qt::AlignCenter);
        doubleSpinBox_low->setAccelerated(true);
        doubleSpinBox_low->setDecimals(1);
        doubleSpinBox_low->setMinimum(-200);
        doubleSpinBox_low->setMaximum(2000);
        doubleSpinBox_low->setSingleStep(0.1);
        doubleSpinBox_above = new hp_QDoubleSpinBoxSet(frame_rdj);
        doubleSpinBox_above->setObjectName(QStringLiteral("doubleSpinBox_above"));
        doubleSpinBox_above->setGeometry(QRect(1, 139, 350, 44));
        doubleSpinBox_above->setFont(font1);
        doubleSpinBox_above->setFocusPolicy(Qt::NoFocus);
        doubleSpinBox_above->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
""
                        "QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}"));
        doubleSpinBox_above->setAlignment(Qt::AlignCenter);
        doubleSpinBox_above->setAccelerated(true);
        doubleSpinBox_above->setDecimals(1);
        doubleSpinBox_above->setMinimum(-200);
        doubleSpinBox_above->setMaximum(2000);
        doubleSpinBox_above->setSingleStep(0.1);
        doubleSpinBox_below = new hp_QDoubleSpinBoxSet(frame_rdj);
        doubleSpinBox_below->setObjectName(QStringLiteral("doubleSpinBox_below"));
        doubleSpinBox_below->setGeometry(QRect(1, 185, 350, 44));
        doubleSpinBox_below->setFont(font1);
        doubleSpinBox_below->setFocusPolicy(Qt::NoFocus);
        doubleSpinBox_below->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
""
                        "QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}"));
        doubleSpinBox_below->setAlignment(Qt::AlignCenter);
        doubleSpinBox_below->setAccelerated(true);
        doubleSpinBox_below->setDecimals(1);
        doubleSpinBox_below->setMinimum(-200);
        doubleSpinBox_below->setMaximum(2000);
        doubleSpinBox_below->setSingleStep(0.1);
        label_rdj_type = new QLabel(frame_rdj);
        label_rdj_type->setObjectName(QStringLiteral("label_rdj_type"));
        label_rdj_type->setGeometry(QRect(1, 1, 180, 44));
        label_rdj_type->setFont(font);
        label_rdj_type->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_rdj_type->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_rdj_type = new QComboBox(frame_rdj);
        comboBox_rdj_type->addItem(QString());
        comboBox_rdj_type->addItem(QString());
        comboBox_rdj_type->addItem(QString());
        comboBox_rdj_type->setObjectName(QStringLiteral("comboBox_rdj_type"));
        comboBox_rdj_type->setGeometry(QRect(179, 1, 171, 44));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(17);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        comboBox_rdj_type->setFont(font2);
        comboBox_rdj_type->setStyleSheet(QLatin1String("\n"
"QComboBox {\n"
"	color:red;\n"
"	font: 17pt \"Arial\";\n"
"    border: 0px solid #7CA6C9;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"/*    background-color: #0a1a29;*/\n"
"background-color:transparent;\n"
"    border: 1px solid #7CA6C9;\n"
"	color:#7CA6C9;\n"
"}\n"
"QComboBox:editable {\n"
"	background:transparent;\n"
"	color:#7CA6C9;\n"
"}\n"
"\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"\n"
"	color:#7CA6C9;\n"
"	background-image:url(:/res/res/combox_bg2.png);\n"
"}\n"
"\n"
"/* QComboBox gets the \"on\" state when the popup is open */\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"	color:#7CA6C9;\n"
"	background:transparent;\n"
"\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"    padding-top: 0px;\n"
"    padding-left: 0px;\n"
"	width:40px;\n"
"	height:40px;\n"
"	color:#7CA6C9;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: rig"
                        "ht;\n"
"width:40px;\n"
"height:40px;\n"
"\n"
"    border-left-width: 0px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 0px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/res/res/down_arrow_n.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 0px;\n"
"    left: 0px;\n"
"}"));
        comboBox_rdj_type->setEditable(true);
        frame_rdj_back = new QFrame(frame_rdj);
        frame_rdj_back->setObjectName(QStringLiteral("frame_rdj_back"));
        frame_rdj_back->setGeometry(QRect(-1, -1, 360, 240));
        frame_rdj_back->setStyleSheet(QStringLiteral("background-image:url(:/res/res/mode_bg.png);"));
        frame_rdj_back->setFrameShape(QFrame::StyledPanel);
        frame_rdj_back->setFrameShadow(QFrame::Raised);
        frame_rdj_type = new QFrame(frame_rdj);
        frame_rdj_type->setObjectName(QStringLiteral("frame_rdj_type"));
        frame_rdj_type->setGeometry(QRect(179, 1, 171, 44));
        frame_rdj_type->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_rdj_type->setFrameShape(QFrame::StyledPanel);
        frame_rdj_type->setFrameShadow(QFrame::Raised);
        label_rdj_type_2 = new QLabel(frame_rdj_type);
        label_rdj_type_2->setObjectName(QStringLiteral("label_rdj_type_2"));
        label_rdj_type_2->setGeometry(QRect(0, 0, 129, 44));
        label_rdj_type_2->setFont(font2);
        label_rdj_type_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_rdj_type_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_rdj_type_3 = new QLabel(frame_rdj_type);
        label_rdj_type_3->setObjectName(QStringLiteral("label_rdj_type_3"));
        label_rdj_type_3->setGeometry(QRect(129, 2, 40, 40));
        label_rdj_type_3->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        listWidget_rdj_type = new QListWidget(frame_rdj);
        new QListWidgetItem(listWidget_rdj_type);
        new QListWidgetItem(listWidget_rdj_type);
        new QListWidgetItem(listWidget_rdj_type);
        listWidget_rdj_type->setObjectName(QStringLiteral("listWidget_rdj_type"));
        listWidget_rdj_type->setGeometry(QRect(179, 45, 171, 31));
        listWidget_rdj_type->setFont(font1);
        listWidget_rdj_type->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        comboBox_rdj_type->raise();
        frame_rdj_back->raise();
        doubleSpinBox_high->raise();
        doubleSpinBox_low->raise();
        doubleSpinBox_above->raise();
        doubleSpinBox_below->raise();
        label_rdj_type->raise();
        frame_rdj_type->raise();
        listWidget_rdj_type->raise();
        frame_all = new QFrame(Hp_Mode_Rdj_Adjust);
        frame_all->setObjectName(QStringLiteral("frame_all"));
        frame_all->setGeometry(QRect(0, 0, 800, 480));
        frame_all->setFrameShape(QFrame::StyledPanel);
        frame_all->setFrameShadow(QFrame::Raised);
        frame_all->raise();
        frame->raise();
        frame_rdj->raise();

        retranslateUi(Hp_Mode_Rdj_Adjust);

        comboBox_rdj_type->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Hp_Mode_Rdj_Adjust);
    } // setupUi

    void retranslateUi(QWidget *Hp_Mode_Rdj_Adjust)
    {
        Hp_Mode_Rdj_Adjust->setWindowTitle(QApplication::translate("Hp_Mode_Rdj_Adjust", "Form", nullptr));
        toolButton_finish->setText(QString());
        toolButton_default->setText(QApplication::translate("Hp_Mode_Rdj_Adjust", "\351\207\215\347\275\256", nullptr));
        doubleSpinBox_high->setPrefix(QApplication::translate("Hp_Mode_Rdj_Adjust", "\351\227\264\351\232\224\344\270\212\351\231\220:", nullptr));
        doubleSpinBox_low->setPrefix(QApplication::translate("Hp_Mode_Rdj_Adjust", "\351\227\264\351\232\224\344\270\213\351\231\220:", nullptr));
        doubleSpinBox_above->setPrefix(QApplication::translate("Hp_Mode_Rdj_Adjust", "\344\271\213\344\270\212\346\270\251\345\272\246:", nullptr));
        doubleSpinBox_below->setPrefix(QApplication::translate("Hp_Mode_Rdj_Adjust", "\344\271\213\344\270\213\346\270\251\345\272\246:", nullptr));
        label_rdj_type->setText(QApplication::translate("Hp_Mode_Rdj_Adjust", "\347\261\273\345\236\213:", nullptr));
        comboBox_rdj_type->setItemText(0, QApplication::translate("Hp_Mode_Rdj_Adjust", "\344\271\213\351\227\264", nullptr));
        comboBox_rdj_type->setItemText(1, QApplication::translate("Hp_Mode_Rdj_Adjust", "\344\271\213\344\270\212", nullptr));
        comboBox_rdj_type->setItemText(2, QApplication::translate("Hp_Mode_Rdj_Adjust", "\344\271\213\344\270\213", nullptr));

        label_rdj_type_2->setText(QApplication::translate("Hp_Mode_Rdj_Adjust", "\344\271\213\351\227\264", nullptr));
        label_rdj_type_3->setText(QString());

        const bool __sortingEnabled = listWidget_rdj_type->isSortingEnabled();
        listWidget_rdj_type->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_rdj_type->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Hp_Mode_Rdj_Adjust", "\344\271\213\351\227\264", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_rdj_type->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Hp_Mode_Rdj_Adjust", "\344\271\213\344\270\212", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_rdj_type->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Hp_Mode_Rdj_Adjust", "\344\271\213\344\270\213", nullptr));
        listWidget_rdj_type->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Hp_Mode_Rdj_Adjust: public Ui_Hp_Mode_Rdj_Adjust {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_MODE_RDJ_ADJUST_H
