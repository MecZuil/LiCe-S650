/********************************************************************************
** Form generated from reading UI file 'hphide_laser.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPHIDE_LASER_H
#define UI_HPHIDE_LASER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hphide_laser
{
public:
    QFrame *line_horizon;
    QFrame *line_vertical;
    QLabel *laser_pos;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_pos1;
    QLabel *label_pos2;
    QLabel *label_pos3;
    QLabel *label_pos4;
    QLabel *label_mode;

    void setupUi(QWidget *hphide_laser)
    {
        if (hphide_laser->objectName().isEmpty())
            hphide_laser->setObjectName(QStringLiteral("hphide_laser"));
        hphide_laser->resize(640, 480);
        hphide_laser->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        line_horizon = new QFrame(hphide_laser);
        line_horizon->setObjectName(QStringLiteral("line_horizon"));
        line_horizon->setGeometry(QRect(0, 239, 640, 2));
        line_horizon->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 150);"));
        line_horizon->setFrameShape(QFrame::HLine);
        line_horizon->setFrameShadow(QFrame::Sunken);
        line_vertical = new QFrame(hphide_laser);
        line_vertical->setObjectName(QStringLiteral("line_vertical"));
        line_vertical->setGeometry(QRect(319, 0, 2, 480));
        line_vertical->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 150);"));
        line_vertical->setFrameShape(QFrame::VLine);
        line_vertical->setFrameShadow(QFrame::Sunken);
        laser_pos = new QLabel(hphide_laser);
        laser_pos->setObjectName(QStringLiteral("laser_pos"));
        laser_pos->setGeometry(QRect(307, 227, 20, 20));
        laser_pos->setStyleSheet(QStringLiteral("border-image: url(:/res/res/laser.png);"));
        label_2 = new QLabel(hphide_laser);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 0, 241, 101));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(18);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);\\nbackground-color: rgba(255, 255, 255, 150);"));
        label = new QLabel(hphide_laser);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(510, 420, 231, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setPointSize(30);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 170, 0);"));
        label_pos1 = new QLabel(hphide_laser);
        label_pos1->setObjectName(QStringLiteral("label_pos1"));
        label_pos1->setGeometry(QRect(140, 260, 81, 31));
        label_pos1->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_pos2 = new QLabel(hphide_laser);
        label_pos2->setObjectName(QStringLiteral("label_pos2"));
        label_pos2->setGeometry(QRect(140, 300, 81, 31));
        label_pos2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_pos3 = new QLabel(hphide_laser);
        label_pos3->setObjectName(QStringLiteral("label_pos3"));
        label_pos3->setGeometry(QRect(230, 260, 81, 31));
        label_pos3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_pos4 = new QLabel(hphide_laser);
        label_pos4->setObjectName(QStringLiteral("label_pos4"));
        label_pos4->setGeometry(QRect(230, 300, 81, 31));
        label_pos4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_mode = new QLabel(hphide_laser);
        label_mode->setObjectName(QStringLiteral("label_mode"));
        label_mode->setGeometry(QRect(0, 430, 101, 51));
        label_mode->setFont(font1);
        label_mode->setStyleSheet(QStringLiteral("color: rgb(255, 170, 0);"));

        retranslateUi(hphide_laser);

        QMetaObject::connectSlotsByName(hphide_laser);
    } // setupUi

    void retranslateUi(QWidget *hphide_laser)
    {
        hphide_laser->setWindowTitle(QApplication::translate("hphide_laser", "Form", nullptr));
        laser_pos->setText(QApplication::translate("hphide_laser", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("hphide_laser", "\346\211\213\345\212\250\347\202\271\345\207\273\345\261\217\345\271\225\n"
"\344\270\216\346\277\200\345\205\211\347\202\271\344\275\215\347\275\256\344\270\255\345\277\203\351\207\215\345\220\210\n"
"\344\275\277\347\224\250WASD\345\276\256\350\260\203", nullptr));
        label->setText(QApplication::translate("hphide_laser", "0.5m", nullptr));
        label_pos1->setText(QString());
        label_pos2->setText(QString());
        label_pos3->setText(QString());
        label_pos4->setText(QString());
        label_mode->setText(QApplication::translate("hphide_laser", "CCD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hphide_laser: public Ui_hphide_laser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPHIDE_LASER_H
