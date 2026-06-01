/********************************************************************************
** Form generated from reading UI file 'hp_pms.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_PMS_H
#define UI_HP_PMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hp_pms
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QToolButton *toolButton;
    QLabel *label_2;
    QLabel *label_3;
    QToolButton *pms_upload;
    QLabel *label_4;

    void setupUi(QWidget *hp_pms)
    {
        if (hp_pms->objectName().isEmpty())
            hp_pms->setObjectName(QStringLiteral("hp_pms"));
        hp_pms->resize(800, 480);
        hp_pms->setStyleSheet(QStringLiteral(""));
        listWidget = new QListWidget(hp_pms);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(-20, 50, 181, 381));
        QFont font;
        font.setPointSize(12);
        listWidget->setFont(font);
        listWidget->setStyleSheet(QLatin1String("QListWidget{\n"
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
"}"));
        listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget->setWordWrap(true);
        label = new QLabel(hp_pms);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 0, 640, 480));
        label->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        toolButton = new QToolButton(hp_pms);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(40, 2, 81, 51));
        QFont font1;
        font1.setPointSize(17);
        toolButton->setFont(font1);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/back_n.png);\n"
"color:#7CA6C9;\n"
"background:transparent;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/back_s_2.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image:url(:/res/res/back_d.png);\n"
"}"));
        label_2 = new QLabel(hp_pms);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 430, 161, 51));
        label_2->setStyleSheet(QLatin1String("\n"
"	background-image:url(:/res/res/setting_background.png);"));
        label_3 = new QLabel(hp_pms);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 161, 51));
        label_3->setStyleSheet(QLatin1String("\n"
"	background-image:url(:/res/res/setting_background.png);"));
        pms_upload = new QToolButton(hp_pms);
        pms_upload->setObjectName(QStringLiteral("pms_upload"));
        pms_upload->setGeometry(QRect(0, 430, 160, 50));
        pms_upload->setFont(font1);
        pms_upload->setFocusPolicy(Qt::NoFocus);
        pms_upload->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        pms_upload->setAutoRaise(false);
        label_4 = new QLabel(hp_pms);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 0, 320, 70));
        label_4->setWordWrap(true);
        label_2->raise();
        label->raise();
        listWidget->raise();
        label_3->raise();
        toolButton->raise();
        pms_upload->raise();
        label_4->raise();

        retranslateUi(hp_pms);

        QMetaObject::connectSlotsByName(hp_pms);
    } // setupUi

    void retranslateUi(QWidget *hp_pms)
    {
        hp_pms->setWindowTitle(QApplication::translate("hp_pms", "Form", nullptr));
        label->setText(QString());
        toolButton->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pms_upload->setText(QApplication::translate("hp_pms", "\344\270\212\344\274\240", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class hp_pms: public Ui_hp_pms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_PMS_H
