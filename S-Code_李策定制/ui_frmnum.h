/********************************************************************************
** Form generated from reading UI file 'frmnum.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMNUM_H
#define UI_FRMNUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmNum
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_title;
    QGridLayout *gridLayout_2;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btnClose;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btnSpace;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btnEnter;
    QPushButton *btn0;
    QPushButton *btn00;
    QPushButton *btnDot;
    QPushButton *btnDelete;

    void setupUi(QWidget *frmNum)
    {
        if (frmNum->objectName().isEmpty())
            frmNum->setObjectName(QStringLiteral("frmNum"));
        frmNum->resize(350, 271);
        QFont font;
        font.setPointSize(15);
        frmNum->setFont(font);
        gridLayout = new QGridLayout(frmNum);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(frmNum);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_title->sizePolicy().hasHeightForWidth());
        widget_title->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(17);
        widget_title->setFont(font1);
        gridLayout_2 = new QGridLayout(widget_title);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btn7 = new QPushButton(widget_title);
        btn7->setObjectName(QStringLiteral("btn7"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn7->sizePolicy().hasHeightForWidth());
        btn7->setSizePolicy(sizePolicy1);
        btn7->setFocusPolicy(Qt::NoFocus);
        btn7->setFlat(false);

        gridLayout_2->addWidget(btn7, 0, 0, 1, 1);

        btn8 = new QPushButton(widget_title);
        btn8->setObjectName(QStringLiteral("btn8"));
        sizePolicy1.setHeightForWidth(btn8->sizePolicy().hasHeightForWidth());
        btn8->setSizePolicy(sizePolicy1);
        btn8->setFocusPolicy(Qt::NoFocus);
        btn8->setFlat(false);

        gridLayout_2->addWidget(btn8, 0, 1, 1, 1);

        btn9 = new QPushButton(widget_title);
        btn9->setObjectName(QStringLiteral("btn9"));
        sizePolicy1.setHeightForWidth(btn9->sizePolicy().hasHeightForWidth());
        btn9->setSizePolicy(sizePolicy1);
        btn9->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn9, 0, 2, 1, 1);

        btnClose = new QPushButton(widget_title);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        sizePolicy1.setHeightForWidth(btnClose->sizePolicy().hasHeightForWidth());
        btnClose->setSizePolicy(sizePolicy1);
        btnClose->setFont(font);
        btnClose->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnClose, 0, 3, 1, 1);

        btn4 = new QPushButton(widget_title);
        btn4->setObjectName(QStringLiteral("btn4"));
        sizePolicy1.setHeightForWidth(btn4->sizePolicy().hasHeightForWidth());
        btn4->setSizePolicy(sizePolicy1);
        btn4->setFocusPolicy(Qt::NoFocus);
        btn4->setFlat(false);

        gridLayout_2->addWidget(btn4, 1, 0, 1, 1);

        btn5 = new QPushButton(widget_title);
        btn5->setObjectName(QStringLiteral("btn5"));
        sizePolicy1.setHeightForWidth(btn5->sizePolicy().hasHeightForWidth());
        btn5->setSizePolicy(sizePolicy1);
        btn5->setFocusPolicy(Qt::NoFocus);
        btn5->setFlat(false);

        gridLayout_2->addWidget(btn5, 1, 1, 1, 1);

        btn6 = new QPushButton(widget_title);
        btn6->setObjectName(QStringLiteral("btn6"));
        sizePolicy1.setHeightForWidth(btn6->sizePolicy().hasHeightForWidth());
        btn6->setSizePolicy(sizePolicy1);
        btn6->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn6, 1, 2, 1, 1);

        btnSpace = new QPushButton(widget_title);
        btnSpace->setObjectName(QStringLiteral("btnSpace"));
        sizePolicy1.setHeightForWidth(btnSpace->sizePolicy().hasHeightForWidth());
        btnSpace->setSizePolicy(sizePolicy1);
        btnSpace->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnSpace, 1, 3, 1, 1);

        btn1 = new QPushButton(widget_title);
        btn1->setObjectName(QStringLiteral("btn1"));
        sizePolicy1.setHeightForWidth(btn1->sizePolicy().hasHeightForWidth());
        btn1->setSizePolicy(sizePolicy1);
        btn1->setFocusPolicy(Qt::NoFocus);
        btn1->setFlat(false);

        gridLayout_2->addWidget(btn1, 2, 0, 1, 1);

        btn2 = new QPushButton(widget_title);
        btn2->setObjectName(QStringLiteral("btn2"));
        sizePolicy1.setHeightForWidth(btn2->sizePolicy().hasHeightForWidth());
        btn2->setSizePolicy(sizePolicy1);
        btn2->setFocusPolicy(Qt::NoFocus);
        btn2->setFlat(false);

        gridLayout_2->addWidget(btn2, 2, 1, 1, 1);

        btn3 = new QPushButton(widget_title);
        btn3->setObjectName(QStringLiteral("btn3"));
        sizePolicy1.setHeightForWidth(btn3->sizePolicy().hasHeightForWidth());
        btn3->setSizePolicy(sizePolicy1);
        btn3->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn3, 2, 2, 1, 1);

        btnEnter = new QPushButton(widget_title);
        btnEnter->setObjectName(QStringLiteral("btnEnter"));
        sizePolicy1.setHeightForWidth(btnEnter->sizePolicy().hasHeightForWidth());
        btnEnter->setSizePolicy(sizePolicy1);
        btnEnter->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnEnter, 2, 3, 1, 1);

        btn0 = new QPushButton(widget_title);
        btn0->setObjectName(QStringLiteral("btn0"));
        sizePolicy1.setHeightForWidth(btn0->sizePolicy().hasHeightForWidth());
        btn0->setSizePolicy(sizePolicy1);
        btn0->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn0, 3, 0, 1, 1);

        btn00 = new QPushButton(widget_title);
        btn00->setObjectName(QStringLiteral("btn00"));
        sizePolicy1.setHeightForWidth(btn00->sizePolicy().hasHeightForWidth());
        btn00->setSizePolicy(sizePolicy1);
        btn00->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn00, 3, 1, 1, 1);

        btnDot = new QPushButton(widget_title);
        btnDot->setObjectName(QStringLiteral("btnDot"));
        sizePolicy1.setHeightForWidth(btnDot->sizePolicy().hasHeightForWidth());
        btnDot->setSizePolicy(sizePolicy1);
        btnDot->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnDot, 3, 2, 1, 1);

        btnDelete = new QPushButton(widget_title);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        sizePolicy1.setHeightForWidth(btnDelete->sizePolicy().hasHeightForWidth());
        btnDelete->setSizePolicy(sizePolicy1);
        btnDelete->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnDelete, 3, 3, 1, 1);


        gridLayout->addWidget(widget_title, 0, 0, 1, 2);


        retranslateUi(frmNum);

        QMetaObject::connectSlotsByName(frmNum);
    } // setupUi

    void retranslateUi(QWidget *frmNum)
    {
        frmNum->setWindowTitle(QApplication::translate("frmNum", "\346\225\260\345\255\227\351\224\256\347\233\230", nullptr));
        btn7->setText(QApplication::translate("frmNum", "7", nullptr));
        btn8->setText(QApplication::translate("frmNum", "8", nullptr));
        btn9->setText(QApplication::translate("frmNum", "9", nullptr));
        btnClose->setText(QApplication::translate("frmNum", "\345\205\263\351\227\255", nullptr));
        btn4->setText(QApplication::translate("frmNum", "4", nullptr));
        btn5->setText(QApplication::translate("frmNum", "5", nullptr));
        btn6->setText(QApplication::translate("frmNum", "6", nullptr));
        btnSpace->setText(QApplication::translate("frmNum", "\347\251\272\346\240\274", nullptr));
        btn1->setText(QApplication::translate("frmNum", "1", nullptr));
        btn2->setText(QApplication::translate("frmNum", "2", nullptr));
        btn3->setText(QApplication::translate("frmNum", "3", nullptr));
        btnEnter->setText(QApplication::translate("frmNum", "\345\233\236\350\275\246", nullptr));
        btn0->setText(QApplication::translate("frmNum", "0", nullptr));
        btn00->setText(QApplication::translate("frmNum", "00", nullptr));
        btnDot->setText(QApplication::translate("frmNum", ".", nullptr));
        btnDelete->setText(QApplication::translate("frmNum", "\342\206\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmNum: public Ui_frmNum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMNUM_H
