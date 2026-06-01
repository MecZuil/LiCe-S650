/********************************************************************************
** Form generated from reading UI file 'hp_sis_content.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_SIS_CONTENT_H
#define UI_HP_SIS_CONTENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hp_sis_content
{
public:
    QFrame *frame;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QLabel *label_text;

    void setupUi(QWidget *hp_sis_content)
    {
        if (hp_sis_content->objectName().isEmpty())
            hp_sis_content->setObjectName(QStringLiteral("hp_sis_content"));
        hp_sis_content->resize(400, 180);
        hp_sis_content->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(hp_sis_content);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 400, 180));
        QFont font;
        font.setPointSize(17);
        frame->setFont(font);
        frame->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/setting_background.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_ok = new QPushButton(frame);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(70, 100, 80, 50));
        pushButton_ok->setFont(font);
        pushButton_ok->setStyleSheet(QLatin1String("border: 1px solid  #7CA6C9;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#7CA6C9;"));
        pushButton_cancel = new QPushButton(frame);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(250, 100, 80, 50));
        pushButton_cancel->setFont(font);
        pushButton_cancel->setStyleSheet(QStringLiteral(""));
        label_text = new QLabel(frame);
        label_text->setObjectName(QStringLiteral("label_text"));
        label_text->setGeometry(QRect(0, 0, 400, 90));
        label_text->setFont(font);
        label_text->setStyleSheet(QStringLiteral("border: 0px solid  #7CA6C9;"));
        label_text->setAlignment(Qt::AlignCenter);
        label_text->setWordWrap(true);

        retranslateUi(hp_sis_content);

        QMetaObject::connectSlotsByName(hp_sis_content);
    } // setupUi

    void retranslateUi(QWidget *hp_sis_content)
    {
        hp_sis_content->setWindowTitle(QApplication::translate("hp_sis_content", "Form", nullptr));
        pushButton_ok->setText(QApplication::translate("hp_sis_content", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QApplication::translate("hp_sis_content", "\345\217\226\346\266\210", nullptr));
        label_text->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class hp_sis_content: public Ui_hp_sis_content {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_SIS_CONTENT_H
