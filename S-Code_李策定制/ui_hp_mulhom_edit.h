/********************************************************************************
** Form generated from reading UI file 'hp_mulhom_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_MULHOM_EDIT_H
#define UI_HP_MULHOM_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <hp_qdoublespinboxset.h>

QT_BEGIN_NAMESPACE

class Ui_hp_mulhom_edit
{
public:
    QFrame *frame;
    QToolButton *toolButton_back;
    QLabel *label_16;
    hp_QDoubleSpinBoxSet *ScrollBar_mulhom;

    void setupUi(QWidget *hp_mulhom_edit)
    {
        if (hp_mulhom_edit->objectName().isEmpty())
            hp_mulhom_edit->setObjectName(QStringLiteral("hp_mulhom_edit"));
        hp_mulhom_edit->resize(800, 480);
        frame = new QFrame(hp_mulhom_edit);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 800, 480));
        frame->setStyleSheet(QLatin1String("background-image:url(:/res/res/setting_background.png);\n"
"border:0px solid #000000;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        toolButton_back = new QToolButton(frame);
        toolButton_back->setObjectName(QStringLiteral("toolButton_back"));
        toolButton_back->setGeometry(QRect(0, 0, 131, 61));
        QPalette palette;
        QBrush brush(QColor(124, 166, 201, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        toolButton_back->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        toolButton_back->setFont(font);
        toolButton_back->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/setting_back.png);\n"
"}  \n"
""));
        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 210, 281, 41));
        QFont font1;
        font1.setPointSize(17);
        label_16->setFont(font1);
        label_16->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ScrollBar_mulhom = new hp_QDoubleSpinBoxSet(frame);
        ScrollBar_mulhom->setObjectName(QStringLiteral("ScrollBar_mulhom"));
        ScrollBar_mulhom->setGeometry(QRect(310, 210, 366, 44));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScrollBar_mulhom->sizePolicy().hasHeightForWidth());
        ScrollBar_mulhom->setSizePolicy(sizePolicy);
        ScrollBar_mulhom->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(17);
        ScrollBar_mulhom->setFont(font2);
        ScrollBar_mulhom->setFocusPolicy(Qt::NoFocus);
        ScrollBar_mulhom->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
"background-color:transparent;\n"
"\n"
"background-image:url(:/res/res/spinbox_text_bg.png);\n"
"color:#7CA6C9;\n"
"border:0px;\n"
"}\n"
"QDoubleSpinBox::up-button {\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/res/res/left_arrow_n.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\240\267\345\274\217*/\n"
"QDoubleSpinBox::up-button:pressed{\n"
"	subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/res/res/right_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;       \n"
"}\n"
"  \n"
"QDoubleSpinBox::down-button:pressed{\n"
"    subcontrol-position:left;\n"
"    image: url(:/res/res/left_arrow_s.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
""
                        "QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/left_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off \n"
"{ \n"
"   border-image: url(:/res/res/right_arrow_d.png);\n"
"    width: 40;\n"
"    height: 40;\n"
"}"));
        ScrollBar_mulhom->setAlignment(Qt::AlignCenter);
        ScrollBar_mulhom->setAccelerated(true);
        ScrollBar_mulhom->setDecimals(1);
        ScrollBar_mulhom->setMinimum(300);
        ScrollBar_mulhom->setMaximum(1000);
        ScrollBar_mulhom->setSingleStep(0.1);
        ScrollBar_mulhom->setValue(600);

        retranslateUi(hp_mulhom_edit);

        QMetaObject::connectSlotsByName(hp_mulhom_edit);
    } // setupUi

    void retranslateUi(QWidget *hp_mulhom_edit)
    {
        hp_mulhom_edit->setWindowTitle(QApplication::translate("hp_mulhom_edit", "Form", nullptr));
        toolButton_back->setText(QString());
        label_16->setText(QApplication::translate("hp_mulhom_edit", "\346\270\251\345\272\246\344\270\212\351\231\220", nullptr));
        ScrollBar_mulhom->setPrefix(QApplication::translate("hp_mulhom_edit", "\346\270\251\345\272\246\344\270\212\351\231\220:", nullptr));
        ScrollBar_mulhom->setSuffix(QApplication::translate("hp_mulhom_edit", "\342\204\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hp_mulhom_edit: public Ui_hp_mulhom_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_MULHOM_EDIT_H
