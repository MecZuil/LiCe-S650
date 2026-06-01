/********************************************************************************
** Form generated from reading UI file 'hp_formatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_FORMATDIALOG_H
#define UI_HP_FORMATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Hp_FormatDialog
{
public:
    QFrame *frame;
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *Hp_FormatDialog)
    {
        if (Hp_FormatDialog->objectName().isEmpty())
            Hp_FormatDialog->setObjectName(QStringLiteral("Hp_FormatDialog"));
        Hp_FormatDialog->resize(366, 152);
        Hp_FormatDialog->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(Hp_FormatDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-1, -1, 368, 153));
        frame->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border:0px solid #000000;\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/format_default_bg.png);"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        buttonBox = new QDialogButtonBox(frame);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(60, 500, 241, 62));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(17);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        buttonBox->setFont(font);
        buttonBox->setStyleSheet(QLatin1String("\n"
"font: 17pt \"Arial\";"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 10, 331, 50));
        QFont font1;
        font1.setPointSize(19);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color:#7CA6C9;"));
        label_3->setFrameShape(QFrame::NoFrame);
        pushButton_ok = new QPushButton(frame);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(80, 80, 75, 41));
        QFont font2;
        font2.setPointSize(17);
        pushButton_ok->setFont(font2);
        pushButton_ok->setStyleSheet(QStringLiteral("border: 1px solid  #7CA6C9;"));
        pushButton_cancel = new QPushButton(frame);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(210, 80, 73, 41));
        QFont font3;
        font3.setPointSize(14);
        pushButton_cancel->setFont(font3);
        pushButton_cancel->setStyleSheet(QStringLiteral("border: 1px solid  #7CA6C9;"));

        retranslateUi(Hp_FormatDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Hp_FormatDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Hp_FormatDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Hp_FormatDialog);
    } // setupUi

    void retranslateUi(QDialog *Hp_FormatDialog)
    {
        Hp_FormatDialog->setWindowTitle(QString());
        label_3->setText(QApplication::translate("Hp_FormatDialog", "<html><head/><body><p align=\"center\"><span style=\" color:#7ca6c9;\">\347\241\256\345\256\232\346\240\274\345\274\217\345\214\226SD\345\215\241\357\274\237</span></p></body></html>", nullptr));
        pushButton_ok->setText(QApplication::translate("Hp_FormatDialog", "OK", nullptr));
        pushButton_cancel->setText(QApplication::translate("Hp_FormatDialog", "CANCEL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_FormatDialog: public Ui_Hp_FormatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_FORMATDIALOG_H
