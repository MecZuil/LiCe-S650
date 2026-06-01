/********************************************************************************
** Form generated from reading UI file 'hp_hir_player.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_HIR_PLAYER_H
#define UI_HP_HIR_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hp_Hir_Player
{
public:
    QFrame *frame_control;
    QToolButton *toolButton_close;
    QToolButton *toolButton_pause;
    QToolButton *toolButton_hir_analyse;
    QFrame *frame_display;

    void setupUi(QWidget *hp_Hir_Player)
    {
        if (hp_Hir_Player->objectName().isEmpty())
            hp_Hir_Player->setObjectName(QStringLiteral("hp_Hir_Player"));
        hp_Hir_Player->resize(800, 480);
        frame_control = new QFrame(hp_Hir_Player);
        frame_control->setObjectName(QStringLiteral("frame_control"));
        frame_control->setGeometry(QRect(0, 0, 160, 480));
        QFont font;
        font.setPointSize(17);
        frame_control->setFont(font);
        frame_control->setStyleSheet(QStringLiteral("background-image:url(:/res/res/main_background.png);"));
        frame_control->setFrameShape(QFrame::NoFrame);
        frame_control->setFrameShadow(QFrame::Raised);
        toolButton_close = new QToolButton(frame_control);
        toolButton_close->setObjectName(QStringLiteral("toolButton_close"));
        toolButton_close->setGeometry(QRect(3, 40, 150, 70));
        toolButton_close->setFont(font);
        toolButton_close->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/setting_back.png);\n"
"background:transparent;\n"
"}  \n"
""));
        toolButton_pause = new QToolButton(frame_control);
        toolButton_pause->setObjectName(QStringLiteral("toolButton_pause"));
        toolButton_pause->setGeometry(QRect(3, 190, 150, 70));
        toolButton_pause->setFont(font);
        toolButton_pause->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/media_pause.png);\n"
"color:#7CA6C9;\n"
"}  \n"
"\n"
"QToolButton:checked{\n"
"border-image:url(:/res/res/media_play.png);\n"
"}\n"
""));
        toolButton_pause->setCheckable(true);
        toolButton_hir_analyse = new QToolButton(frame_control);
        toolButton_hir_analyse->setObjectName(QStringLiteral("toolButton_hir_analyse"));
        toolButton_hir_analyse->setGeometry(QRect(3, 350, 150, 70));
        toolButton_hir_analyse->setFont(font);
        toolButton_hir_analyse->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/hir_analyse.png);\n"
"color:#7CA6C9;\n"
"}  \n"
" "));
        toolButton_hir_analyse->setCheckable(true);
        toolButton_close->raise();
        toolButton_pause->raise();
        toolButton_hir_analyse->raise();
        frame_display = new QFrame(hp_Hir_Player);
        frame_display->setObjectName(QStringLiteral("frame_display"));
        frame_display->setGeometry(QRect(160, 0, 641, 480));
        frame_display->setFont(font);
        frame_display->setStyleSheet(QStringLiteral("background-color: rgb(0,8,16);"));
        frame_display->setFrameShape(QFrame::NoFrame);
        frame_display->setFrameShadow(QFrame::Raised);

        retranslateUi(hp_Hir_Player);

        QMetaObject::connectSlotsByName(hp_Hir_Player);
    } // setupUi

    void retranslateUi(QWidget *hp_Hir_Player)
    {
        hp_Hir_Player->setWindowTitle(QApplication::translate("hp_Hir_Player", "Form", nullptr));
        toolButton_close->setText(QString());
        toolButton_pause->setText(QString());
        toolButton_hir_analyse->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class hp_Hir_Player: public Ui_hp_Hir_Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_HIR_PLAYER_H
