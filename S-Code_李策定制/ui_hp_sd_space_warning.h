/********************************************************************************
** Form generated from reading UI file 'hp_sd_space_warning.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_SD_SPACE_WARNING_H
#define UI_HP_SD_SPACE_WARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Sd_Space_Warning
{
public:
    QFrame *frame;
    QToolButton *toolButton;
    QLabel *label_title;
    QLabel *label_text;

    void setupUi(QWidget *Hp_Sd_Space_Warning)
    {
        if (Hp_Sd_Space_Warning->objectName().isEmpty())
            Hp_Sd_Space_Warning->setObjectName(QStringLiteral("Hp_Sd_Space_Warning"));
        Hp_Sd_Space_Warning->resize(433, 141);
        QFont font;
        font.setPointSize(17);
        Hp_Sd_Space_Warning->setFont(font);
        Hp_Sd_Space_Warning->setStyleSheet(QStringLiteral("background-image:url(:/res/res/format_default_bg.png);"));
        frame = new QFrame(Hp_Sd_Space_Warning);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 433, 52));
        QFont font1;
        font1.setPointSize(15);
        frame->setFont(font1);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(124, 166, 201);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(381, 0, 52, 52));
        toolButton->setFont(font);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/mode_button_n.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:pressed{\n"
"border-image:url(:/res/res/mode_button_s.png);\n"
"}"));
        toolButton->setAutoRaise(true);
        label_title = new QLabel(frame);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(60, 0, 300, 52));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(17);
        label_title->setFont(font2);
        label_title->setStyleSheet(QStringLiteral("color: rgb(240, 31, 31);"));
        label_title->setAlignment(Qt::AlignCenter);
        label_text = new QLabel(Hp_Sd_Space_Warning);
        label_text->setObjectName(QStringLiteral("label_text"));
        label_text->setGeometry(QRect(0, 52, 433, 90));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(15);
        label_text->setFont(font3);
        label_text->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_text->setFrameShape(QFrame::NoFrame);
        label_text->setAlignment(Qt::AlignCenter);

        retranslateUi(Hp_Sd_Space_Warning);
        QObject::connect(toolButton, SIGNAL(released()), Hp_Sd_Space_Warning, SLOT(close()));

        QMetaObject::connectSlotsByName(Hp_Sd_Space_Warning);
    } // setupUi

    void retranslateUi(QWidget *Hp_Sd_Space_Warning)
    {
        Hp_Sd_Space_Warning->setWindowTitle(QApplication::translate("Hp_Sd_Space_Warning", "Form", nullptr));
        toolButton->setText(QApplication::translate("Hp_Sd_Space_Warning", "x", nullptr));
        label_title->setText(QApplication::translate("Hp_Sd_Space_Warning", "\345\207\272\351\224\231", nullptr));
        label_text->setText(QApplication::translate("Hp_Sd_Space_Warning", "SD\345\215\241\347\251\272\351\227\264\344\270\215\345\244\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Sd_Space_Warning: public Ui_Hp_Sd_Space_Warning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_SD_SPACE_WARNING_H
