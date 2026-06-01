/********************************************************************************
** Form generated from reading UI file 'hpresize.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPRESIZE_H
#define UI_HPRESIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <hp_qslider.h>

QT_BEGIN_NAMESPACE

class Ui_HpResize
{
public:
    hp_QSlider *slider_contrast;
    QLabel *label_contrast_value;
    hp_QSlider *slider_brightness;
    QLabel *label_brightness_value;
    hp_QSlider *slider_resize;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *HpResize)
    {
        if (HpResize->objectName().isEmpty())
            HpResize->setObjectName(QStringLiteral("HpResize"));
        HpResize->resize(640, 210);
        HpResize->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        slider_contrast = new hp_QSlider(HpResize);
        slider_contrast->setObjectName(QStringLiteral("slider_contrast"));
        slider_contrast->setGeometry(QRect(200, 0, 420, 60));
        QFont font;
        font.setPointSize(15);
        slider_contrast->setFont(font);
        slider_contrast->setFocusPolicy(Qt::NoFocus);
        slider_contrast->setAutoFillBackground(false);
        slider_contrast->setStyleSheet(QLatin1String("\n"
"  \n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 1px;  \n"
"    background: qlineargradient(x1:1, y1:0, x2:0, y2:0, stop:1 #5F80AA, stop:0 #5F80AA);  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{   \n"
"/*\n"
" background: qlineargradient(x1:0, y1:1, x2:0, y2:0, stop:1 #67A4E0, stop:0 #336CA5);  \n"
"*/\n"
"    width: 16px;  \n"
"    height: 30px;  \n"
"     margin: -12px 0px -12px 0px;\n"
"    border: 0px solid #000810;\n"
"border-image:url(:/res/res/huakuai.png);  \n"
"}  "));
        slider_contrast->setMinimum(-255);
        slider_contrast->setMaximum(255);
        slider_contrast->setSingleStep(1);
        slider_contrast->setPageStep(1);
        slider_contrast->setValue(0);
        slider_contrast->setOrientation(Qt::Horizontal);
        slider_contrast->setInvertedAppearance(false);
        slider_contrast->setInvertedControls(true);
        slider_contrast->setTickPosition(QSlider::TicksBelow);
        slider_contrast->setTickInterval(1);
        label_contrast_value = new QLabel(HpResize);
        label_contrast_value->setObjectName(QStringLiteral("label_contrast_value"));
        label_contrast_value->setGeometry(QRect(130, 0, 60, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(17);
        font1.setStyleStrategy(QFont::NoAntialias);
        label_contrast_value->setFont(font1);
        label_contrast_value->setStyleSheet(QLatin1String("background-color: rgb(0, 8, 16);\n"
"color:#7CA6C9;"));
        slider_brightness = new hp_QSlider(HpResize);
        slider_brightness->setObjectName(QStringLiteral("slider_brightness"));
        slider_brightness->setGeometry(QRect(200, 70, 420, 60));
        slider_brightness->setFont(font);
        slider_brightness->setFocusPolicy(Qt::NoFocus);
        slider_brightness->setAutoFillBackground(false);
        slider_brightness->setStyleSheet(QLatin1String("\n"
"  \n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 1px;  \n"
"    background: qlineargradient(x1:1, y1:0, x2:0, y2:0, stop:1 #5F80AA, stop:0 #5F80AA);  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{   \n"
"/*\n"
" background: qlineargradient(x1:0, y1:1, x2:0, y2:0, stop:1 #67A4E0, stop:0 #336CA5);  \n"
"*/\n"
"    width: 16px;  \n"
"    height: 30px;  \n"
"     margin: -12px 0px -12px 0px;\n"
"    border: 0px solid #000810;\n"
"border-image:url(:/res/res/huakuai.png);  \n"
"}  "));
        slider_brightness->setMinimum(-255);
        slider_brightness->setMaximum(255);
        slider_brightness->setSingleStep(1);
        slider_brightness->setPageStep(1);
        slider_brightness->setValue(0);
        slider_brightness->setOrientation(Qt::Horizontal);
        slider_brightness->setInvertedAppearance(false);
        slider_brightness->setInvertedControls(true);
        slider_brightness->setTickPosition(QSlider::TicksBelow);
        slider_brightness->setTickInterval(1);
        label_brightness_value = new QLabel(HpResize);
        label_brightness_value->setObjectName(QStringLiteral("label_brightness_value"));
        label_brightness_value->setGeometry(QRect(130, 70, 60, 60));
        label_brightness_value->setFont(font1);
        label_brightness_value->setStyleSheet(QLatin1String("background-color: rgb(0, 8, 16);\n"
"color:#7CA6C9;"));
        slider_resize = new hp_QSlider(HpResize);
        slider_resize->setObjectName(QStringLiteral("slider_resize"));
        slider_resize->setGeometry(QRect(200, 140, 420, 60));
        slider_resize->setFont(font);
        slider_resize->setFocusPolicy(Qt::NoFocus);
        slider_resize->setAutoFillBackground(false);
        slider_resize->setStyleSheet(QLatin1String("\n"
"  \n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 1px;  \n"
"    background: qlineargradient(x1:1, y1:0, x2:0, y2:0, stop:1 #5F80AA, stop:0 #5F80AA);  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{   \n"
"/*\n"
" background: qlineargradient(x1:0, y1:1, x2:0, y2:0, stop:1 #67A4E0, stop:0 #336CA5);  \n"
"*/\n"
"    width: 16px;  \n"
"    height: 30px;  \n"
"     margin: -12px 0px -12px 0px;\n"
"    border: 0px solid #000810;\n"
"border-image:url(:/res/res/huakuai.png);  \n"
"}  "));
        slider_resize->setMinimum(10);
        slider_resize->setMaximum(80);
        slider_resize->setSingleStep(10);
        slider_resize->setPageStep(10);
        slider_resize->setOrientation(Qt::Horizontal);
        slider_resize->setInvertedAppearance(false);
        slider_resize->setInvertedControls(true);
        slider_resize->setTickPosition(QSlider::TicksBelow);
        slider_resize->setTickInterval(1);
        label = new QLabel(HpResize);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 140, 60, 60));
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("background-color: rgb(0, 8, 16);\n"
"color:#7CA6C9;"));
        label_4 = new QLabel(HpResize);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 100, 60));
        label_4->setFont(font1);
        label_4->setStyleSheet(QLatin1String("background-color: rgb(0, 8, 16);\n"
"color:#7CA6C9;"));
        label_5 = new QLabel(HpResize);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 0, 100, 60));
        label_5->setFont(font1);
        label_5->setStyleSheet(QLatin1String("background-color: rgb(0, 8, 16);\n"
"color:#7CA6C9;"));
        label_6 = new QLabel(HpResize);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 140, 100, 60));
        label_6->setFont(font1);
        label_6->setStyleSheet(QLatin1String("background-color: rgb(0, 8, 16);\n"
"color:#7CA6C9;"));

        retranslateUi(HpResize);

        QMetaObject::connectSlotsByName(HpResize);
    } // setupUi

    void retranslateUi(QWidget *HpResize)
    {
        HpResize->setWindowTitle(QApplication::translate("HpResize", "Form", nullptr));
        label_contrast_value->setText(QString());
        label_brightness_value->setText(QString());
        label->setText(QString());
        label_4->setText(QApplication::translate("HpResize", "\344\272\256\345\272\246", nullptr));
        label_5->setText(QApplication::translate("HpResize", "\345\257\271\346\257\224\345\272\246", nullptr));
        label_6->setText(QApplication::translate("HpResize", "\347\224\273\351\235\242\345\244\247\345\260\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HpResize: public Ui_HpResize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPRESIZE_H
