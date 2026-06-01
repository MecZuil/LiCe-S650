/********************************************************************************
** Form generated from reading UI file 'hp_handfution.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_HANDFUTION_H
#define UI_HP_HANDFUTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_HandFution
{
public:
    QToolButton *toolButton_up;
    QLabel *label;
    QToolButton *toolButton_down;

    void setupUi(QWidget *Hp_HandFution)
    {
        if (Hp_HandFution->objectName().isEmpty())
            Hp_HandFution->setObjectName(QStringLiteral("Hp_HandFution"));
        Hp_HandFution->resize(60, 225);
        Hp_HandFution->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        toolButton_up = new QToolButton(Hp_HandFution);
        toolButton_up->setObjectName(QStringLiteral("toolButton_up"));
        toolButton_up->setGeometry(QRect(0, 0, 60, 60));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_up->sizePolicy().hasHeightForWidth());
        toolButton_up->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        toolButton_up->setFont(font);
        toolButton_up->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image: url(:/res/res/m_up_arrow_n.png);\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image: url(:/res/res/m_up_arrow_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image: url(:/res/res/m_up_arrow_d.png);\n"
"}"));
        toolButton_up->setIconSize(QSize(16, 16));
        toolButton_up->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_up->setAutoRaise(false);
        toolButton_up->setArrowType(Qt::UpArrow);
        label = new QLabel(Hp_HandFution);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 80, 60, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(17);
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("	background-color: rgb(49, 69, 116);\n"
"color: rgb(255, 255, 255);"));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setAlignment(Qt::AlignCenter);
        label->setTextInteractionFlags(Qt::NoTextInteraction);
        toolButton_down = new QToolButton(Hp_HandFution);
        toolButton_down->setObjectName(QStringLiteral("toolButton_down"));
        toolButton_down->setGeometry(QRect(0, 165, 60, 60));
        sizePolicy.setHeightForWidth(toolButton_down->sizePolicy().hasHeightForWidth());
        toolButton_down->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(14);
        toolButton_down->setFont(font2);
        toolButton_down->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image: url(:/res/res/m_down_arrow_n.png);\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image: url(:/res/res/m_down_arrow_s.png);\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"border-image: url(:/res/res/m_down_arrow_d.png);\n"
"}"));
        toolButton_down->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_down->setAutoRaise(false);
        toolButton_down->setArrowType(Qt::DownArrow);

        retranslateUi(Hp_HandFution);

        QMetaObject::connectSlotsByName(Hp_HandFution);
    } // setupUi

    void retranslateUi(QWidget *Hp_HandFution)
    {
        Hp_HandFution->setWindowTitle(QApplication::translate("Hp_HandFution", "Form", nullptr));
        toolButton_up->setText(QString());
        label->setText(QApplication::translate("Hp_HandFution", "1", nullptr));
        toolButton_down->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Hp_HandFution: public Ui_Hp_HandFution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_HANDFUTION_H
