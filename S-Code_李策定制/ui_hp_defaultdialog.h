/********************************************************************************
** Form generated from reading UI file 'hp_defaultdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_DEFAULTDIALOG_H
#define UI_HP_DEFAULTDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_hp_DefaultDialog
{
public:
    QFrame *frame;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *hp_DefaultDialog)
    {
        if (hp_DefaultDialog->objectName().isEmpty())
            hp_DefaultDialog->setObjectName(QStringLiteral("hp_DefaultDialog"));
        hp_DefaultDialog->resize(366, 151);
        QFont font;
        font.setStyleStrategy(QFont::PreferDefault);
        hp_DefaultDialog->setFont(font);
        hp_DefaultDialog->setStyleSheet(QStringLiteral(""));
        hp_DefaultDialog->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        hp_DefaultDialog->setSizeGripEnabled(false);
        hp_DefaultDialog->setModal(false);
        frame = new QFrame(hp_DefaultDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-1, -1, 368, 153));
        frame->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border:0px solid #000000;\n"
"color:#7CA6C9;\n"
"background-image:url(:/res/res/format_default_bg.png);"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1, 1, 362, 87));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(17);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label_2->setFont(font1);
        label_2->setMouseTracking(true);
        label_2->setAcceptDrops(false);
        label_2->setStyleSheet(QLatin1String("\n"
"color:#7CA6C9;"));
        label_2->setLineWidth(0);
        buttonBox = new QDialogButtonBox(frame);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(80, 500, 181, 62));
        QPalette palette;
        QBrush brush(QColor(124, 166, 201, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(240, 119, 70, 0));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush3(QColor(240, 240, 240, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        buttonBox->setPalette(palette);
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(17);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        buttonBox->setFont(font2);
        buttonBox->setCursor(QCursor(Qt::BlankCursor));
        buttonBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        buttonBox->setAcceptDrops(false);
        buttonBox->setAutoFillBackground(false);
        buttonBox->setStyleSheet(QLatin1String("border-color: rgba(255, 255, 255, 0);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	color:#7CA6C9;\n"
"font: 17pt \"Arial\";"));
        buttonBox->setInputMethodHints(Qt::ImhNone);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        pushButton_ok = new QPushButton(frame);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(80, 90, 75, 41));
        QFont font3;
        font3.setPointSize(17);
        pushButton_ok->setFont(font3);
        pushButton_ok->setStyleSheet(QStringLiteral("border: 1px solid  #7CA6C9;"));
        pushButton_cancel = new QPushButton(frame);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(210, 90, 73, 41));
        QFont font4;
        font4.setPointSize(14);
        pushButton_cancel->setFont(font4);
        pushButton_cancel->setStyleSheet(QStringLiteral("border: 1px solid  #7CA6C9;"));

        retranslateUi(hp_DefaultDialog);

        QMetaObject::connectSlotsByName(hp_DefaultDialog);
    } // setupUi

    void retranslateUi(QDialog *hp_DefaultDialog)
    {
        hp_DefaultDialog->setWindowTitle(QApplication::translate("hp_DefaultDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("hp_DefaultDialog", "<html><head/><body><p align=\"center\">\347\241\256\345\256\232\346\201\242\345\244\215\345\207\272\345\216\202\350\256\276\347\275\256\357\274\237</p></body></html>", nullptr));
        pushButton_ok->setText(QApplication::translate("hp_DefaultDialog", "OK", nullptr));
        pushButton_cancel->setText(QApplication::translate("hp_DefaultDialog", "CANCEL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hp_DefaultDialog: public Ui_hp_DefaultDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_DEFAULTDIALOG_H
