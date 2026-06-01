/********************************************************************************
** Form generated from reading UI file 'hp_isotherm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_ISOTHERM_H
#define UI_HP_ISOTHERM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hp_Isotherm
{
public:
    QFrame *frame;
    QListWidget *listWidget_dengwense;
    QFrame *frame_dengwense;
    QLabel *label_dengwen;
    QLabel *label_dengwen_2;
    QDoubleSpinBox *comboBox_dengwenwendu;
    QDoubleSpinBox *comboBox_dengwengaodu;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;

    void setupUi(QWidget *hp_Isotherm)
    {
        if (hp_Isotherm->objectName().isEmpty())
            hp_Isotherm->setObjectName(QStringLiteral("hp_Isotherm"));
        hp_Isotherm->resize(805, 485);
        frame = new QFrame(hp_Isotherm);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-3, -3, 805, 485));
        QFont font;
        font.setPointSize(17);
        frame->setFont(font);
        frame->setStyleSheet(QLatin1String("background-image:url(:/res/res/setting_background.png);\n"
"border:0px solid #000000;"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        listWidget_dengwense = new QListWidget(frame);
        new QListWidgetItem(listWidget_dengwense);
        new QListWidgetItem(listWidget_dengwense);
        new QListWidgetItem(listWidget_dengwense);
        new QListWidgetItem(listWidget_dengwense);
        new QListWidgetItem(listWidget_dengwense);
        new QListWidgetItem(listWidget_dengwense);
        new QListWidgetItem(listWidget_dengwense);
        new QListWidgetItem(listWidget_dengwense);
        new QListWidgetItem(listWidget_dengwense);
        new QListWidgetItem(listWidget_dengwense);
        listWidget_dengwense->setObjectName(QStringLiteral("listWidget_dengwense"));
        listWidget_dengwense->setGeometry(QRect(610, 130, 243, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Sans"));
        font1.setPointSize(17);
        listWidget_dengwense->setFont(font1);
        listWidget_dengwense->setFocusPolicy(Qt::NoFocus);
        listWidget_dengwense->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_dengwense = new QFrame(frame);
        frame_dengwense->setObjectName(QStringLiteral("frame_dengwense"));
        frame_dengwense->setGeometry(QRect(300, 100, 243, 44));
        frame_dengwense->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_dengwense->setFrameShape(QFrame::StyledPanel);
        frame_dengwense->setFrameShadow(QFrame::Raised);
        label_dengwen = new QLabel(frame_dengwense);
        label_dengwen->setObjectName(QStringLiteral("label_dengwen"));
        label_dengwen->setGeometry(QRect(0, 0, 201, 44));
        label_dengwen->setFont(font1);
        label_dengwen->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_dengwen->setAlignment(Qt::AlignCenter);
        label_dengwen_2 = new QLabel(frame_dengwense);
        label_dengwen_2->setObjectName(QStringLiteral("label_dengwen_2"));
        label_dengwen_2->setGeometry(QRect(201, 2, 40, 40));
        label_dengwen_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        comboBox_dengwenwendu = new QDoubleSpinBox(frame);
        comboBox_dengwenwendu->setObjectName(QStringLiteral("comboBox_dengwenwendu"));
        comboBox_dengwenwendu->setGeometry(QRect(300, 200, 385, 44));
        comboBox_dengwenwendu->setFont(font1);
        comboBox_dengwenwendu->setFocusPolicy(Qt::NoFocus);
        comboBox_dengwenwendu->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
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
                        "QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
""));
        comboBox_dengwenwendu->setAlignment(Qt::AlignCenter);
        comboBox_dengwenwendu->setAccelerated(true);
        comboBox_dengwenwendu->setDecimals(1);
        comboBox_dengwenwendu->setMinimum(-1000);
        comboBox_dengwenwendu->setMaximum(10000);
        comboBox_dengwenwendu->setSingleStep(0.1);
        comboBox_dengwengaodu = new QDoubleSpinBox(frame);
        comboBox_dengwengaodu->setObjectName(QStringLiteral("comboBox_dengwengaodu"));
        comboBox_dengwengaodu->setGeometry(QRect(300, 300, 385, 44));
        comboBox_dengwengaodu->setFont(font1);
        comboBox_dengwengaodu->setFocusPolicy(Qt::NoFocus);
        comboBox_dengwengaodu->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
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
                        "QDoubleSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
""));
        comboBox_dengwengaodu->setAlignment(Qt::AlignCenter);
        comboBox_dengwengaodu->setAccelerated(true);
        comboBox_dengwengaodu->setDecimals(1);
        comboBox_dengwengaodu->setMinimum(0);
        comboBox_dengwengaodu->setMaximum(10000);
        comboBox_dengwengaodu->setSingleStep(0.1);
        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 100, 261, 41));
        label_15->setFont(font);
        label_15->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 200, 261, 41));
        label_16->setFont(font);
        label_16->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 300, 261, 41));
        label_17->setFont(font);
        label_17->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_dengwengaodu->raise();
        comboBox_dengwenwendu->raise();
        frame_dengwense->raise();
        listWidget_dengwense->raise();
        label_15->raise();
        label_16->raise();
        label_17->raise();

        retranslateUi(hp_Isotherm);

        QMetaObject::connectSlotsByName(hp_Isotherm);
    } // setupUi

    void retranslateUi(QWidget *hp_Isotherm)
    {
        hp_Isotherm->setWindowTitle(QApplication::translate("hp_Isotherm", "Form", nullptr));

        const bool __sortingEnabled = listWidget_dengwense->isSortingEnabled();
        listWidget_dengwense->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_dengwense->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("hp_Isotherm", "\350\207\252\345\212\250", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_dengwense->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("hp_Isotherm", "\347\272\242\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_dengwense->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("hp_Isotherm", "\346\251\231\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_dengwense->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("hp_Isotherm", "\351\273\204\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_dengwense->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("hp_Isotherm", "\347\273\277\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_dengwense->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("hp_Isotherm", "\351\273\221\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_dengwense->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("hp_Isotherm", "\347\201\260\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_dengwense->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("hp_Isotherm", "\347\264\253\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_dengwense->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("hp_Isotherm", "\350\223\235\350\211\262", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget_dengwense->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("hp_Isotherm", "\347\231\275\350\211\262", nullptr));
        listWidget_dengwense->setSortingEnabled(__sortingEnabled);

        label_dengwen->setText(QApplication::translate("hp_Isotherm", "\347\255\211\346\270\251\351\242\234\350\211\262", nullptr));
        label_dengwen_2->setText(QString());
        comboBox_dengwenwendu->setPrefix(QApplication::translate("hp_Isotherm", "\347\255\211\346\270\251\346\270\251\345\272\246:", nullptr));
        comboBox_dengwengaodu->setPrefix(QApplication::translate("hp_Isotherm", "\347\255\211\346\270\251\351\253\230\345\272\246 :", nullptr));
        label_15->setText(QApplication::translate("hp_Isotherm", "\347\255\211\346\270\251\350\211\262", nullptr));
        label_16->setText(QApplication::translate("hp_Isotherm", "\347\255\211\346\270\251\346\270\251\345\272\246", nullptr));
        label_17->setText(QApplication::translate("hp_Isotherm", "\347\255\211\346\270\251\351\253\230\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hp_Isotherm: public Ui_hp_Isotherm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_ISOTHERM_H
