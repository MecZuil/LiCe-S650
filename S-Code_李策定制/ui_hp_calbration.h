/********************************************************************************
** Form generated from reading UI file 'hp_calbration.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_CALBRATION_H
#define UI_HP_CALBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hp_calbration
{
public:
    QFrame *frame;
    QPushButton *pushButton;
    QToolButton *toolButton;
    QToolButton *toolButton_2;

    void setupUi(QWidget *hp_calbration)
    {
        if (hp_calbration->objectName().isEmpty())
            hp_calbration->setObjectName(QStringLiteral("hp_calbration"));
        hp_calbration->resize(800, 480);
        hp_calbration->setStyleSheet(QStringLiteral("background-image:url(:/res/res/setting_background.png);"));
        frame = new QFrame(hp_calbration);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 800, 480));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 127, 300, 50));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(250, 200, 300, 50));
        toolButton->setFont(font);
        toolButton->setStyleSheet(QLatin1String("QToolButton{\n"
"border-image:url(:/res/res/button_n.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/setting_selected.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
""));
        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(250, 270, 300, 50));
        toolButton_2->setFont(font);
        toolButton_2->setStyleSheet(QLatin1String("QToolButton{\n"
"border-image:url(:/res/res/button_n.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/setting_selected.png);\n"
"color:#7CA6C9;\n"
"width:146px;\n"
"height:25px\n"
"}\n"
""));

        retranslateUi(hp_calbration);

        QMetaObject::connectSlotsByName(hp_calbration);
    } // setupUi

    void retranslateUi(QWidget *hp_calbration)
    {
        hp_calbration->setWindowTitle(QApplication::translate("hp_calbration", "Form", nullptr));
        pushButton->setText(QApplication::translate("hp_calbration", "\345\274\200\345\247\213\346\240\241\345\207\206", nullptr));
        toolButton->setText(QApplication::translate("hp_calbration", "\347\273\223\346\235\237\346\240\241\345\207\206", nullptr));
        toolButton_2->setText(QApplication::translate("hp_calbration", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hp_calbration: public Ui_hp_calbration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_CALBRATION_H
