/********************************************************************************
** Form generated from reading UI file 'hp_hotkey.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_HOTKEY_H
#define UI_HP_HOTKEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_hotkey
{
public:
    QFrame *frame;
    QLabel *label_keyCamera;
    QListWidget *listWidget_keyCamera;
    QFrame *frame_keyCamera;
    QLabel *label_keyCamera_2;
    QLabel *label_keyCamera_3;
    QToolButton *toolButton_back;
    QFrame *frame_keyFocus;
    QLabel *label_keyFocus_2;
    QLabel *label_keyFocus_3;
    QLabel *label_keyFocus;
    QListWidget *listWidget_keyFocus;

    void setupUi(QWidget *Hp_hotkey)
    {
        if (Hp_hotkey->objectName().isEmpty())
            Hp_hotkey->setObjectName(QStringLiteral("Hp_hotkey"));
        Hp_hotkey->resize(800, 480);
        frame = new QFrame(Hp_hotkey);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 800, 480));
        frame->setStyleSheet(QLatin1String("background-image:url(:/res/res/setting_background.png);\n"
"border:0px solid #000000;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_keyCamera = new QLabel(frame);
        label_keyCamera->setObjectName(QStringLiteral("label_keyCamera"));
        label_keyCamera->setGeometry(QRect(30, 120, 271, 41));
        QFont font;
        font.setPointSize(17);
        label_keyCamera->setFont(font);
        label_keyCamera->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_keyCamera->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        listWidget_keyCamera = new QListWidget(frame);
        new QListWidgetItem(listWidget_keyCamera);
        new QListWidgetItem(listWidget_keyCamera);
        new QListWidgetItem(listWidget_keyCamera);
        new QListWidgetItem(listWidget_keyCamera);
        new QListWidgetItem(listWidget_keyCamera);
        new QListWidgetItem(listWidget_keyCamera);
        listWidget_keyCamera->setObjectName(QStringLiteral("listWidget_keyCamera"));
        listWidget_keyCamera->setGeometry(QRect(320, 161, 235, 201));
        QFont font1;
        font1.setFamily(QStringLiteral("Sans"));
        font1.setPointSize(17);
        listWidget_keyCamera->setFont(font1);
        listWidget_keyCamera->setFocusPolicy(Qt::NoFocus);
        listWidget_keyCamera->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_keyCamera = new QFrame(frame);
        frame_keyCamera->setObjectName(QStringLiteral("frame_keyCamera"));
        frame_keyCamera->setGeometry(QRect(320, 120, 243, 44));
        frame_keyCamera->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_keyCamera->setFrameShape(QFrame::StyledPanel);
        frame_keyCamera->setFrameShadow(QFrame::Raised);
        label_keyCamera_2 = new QLabel(frame_keyCamera);
        label_keyCamera_2->setObjectName(QStringLiteral("label_keyCamera_2"));
        label_keyCamera_2->setGeometry(QRect(0, 0, 201, 44));
        label_keyCamera_2->setFont(font1);
        label_keyCamera_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        label_keyCamera_2->setAlignment(Qt::AlignCenter);
        label_keyCamera_3 = new QLabel(frame_keyCamera);
        label_keyCamera_3->setObjectName(QStringLiteral("label_keyCamera_3"));
        label_keyCamera_3->setGeometry(QRect(201, 2, 40, 40));
        label_keyCamera_3->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        toolButton_back = new QToolButton(frame);
        toolButton_back->setObjectName(QStringLiteral("toolButton_back"));
        toolButton_back->setGeometry(QRect(0, 0, 155, 81));
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
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        toolButton_back->setFont(font2);
        toolButton_back->setStyleSheet(QLatin1String("QToolButton {\n"
"border-image:url(:/res/res/setting_back.png);\n"
"}  \n"
""));
        frame_keyFocus = new QFrame(frame);
        frame_keyFocus->setObjectName(QStringLiteral("frame_keyFocus"));
        frame_keyFocus->setGeometry(QRect(320, 220, 243, 44));
        frame_keyFocus->setStyleSheet(QLatin1String("background-image:url(:/res/res/combox_bg2.png);\n"
"/*background:transparent;*/\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        frame_keyFocus->setFrameShape(QFrame::StyledPanel);
        frame_keyFocus->setFrameShadow(QFrame::Raised);
        label_keyFocus_2 = new QLabel(frame_keyFocus);
        label_keyFocus_2->setObjectName(QStringLiteral("label_keyFocus_2"));
        label_keyFocus_2->setGeometry(QRect(0, 0, 201, 44));
        label_keyFocus_2->setFont(font1);
        label_keyFocus_2->setStyleSheet(QStringLiteral(""));
        label_keyFocus_2->setAlignment(Qt::AlignCenter);
        label_keyFocus_3 = new QLabel(frame_keyFocus);
        label_keyFocus_3->setObjectName(QStringLiteral("label_keyFocus_3"));
        label_keyFocus_3->setGeometry(QRect(201, 2, 40, 40));
        label_keyFocus_3->setStyleSheet(QLatin1String("background:transparent;\n"
"border: 0px solid #7CA6C9;\n"
"color:#7CA6C9;\n"
"border-image:url(:/res/res/down_arrow_n.png);"));
        label_keyFocus = new QLabel(frame);
        label_keyFocus->setObjectName(QStringLiteral("label_keyFocus"));
        label_keyFocus->setGeometry(QRect(30, 220, 271, 41));
        label_keyFocus->setFont(font);
        label_keyFocus->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#7CA6C9;"));
        label_keyFocus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        listWidget_keyFocus = new QListWidget(frame);
        new QListWidgetItem(listWidget_keyFocus);
        new QListWidgetItem(listWidget_keyFocus);
        new QListWidgetItem(listWidget_keyFocus);
        new QListWidgetItem(listWidget_keyFocus);
        new QListWidgetItem(listWidget_keyFocus);
        new QListWidgetItem(listWidget_keyFocus);
        listWidget_keyFocus->setObjectName(QStringLiteral("listWidget_keyFocus"));
        listWidget_keyFocus->setGeometry(QRect(320, 260, 235, 211));
        listWidget_keyFocus->setFont(font1);
        listWidget_keyFocus->setFocusPolicy(Qt::NoFocus);
        listWidget_keyFocus->setStyleSheet(QLatin1String("border: 1px solid #7CA6C9;\n"
"color:#7CA6C9;"));
        toolButton_back->raise();
        frame_keyFocus->raise();
        label_keyFocus->raise();
        listWidget_keyFocus->raise();
        listWidget_keyCamera->raise();
        frame_keyCamera->raise();
        label_keyCamera->raise();

        retranslateUi(Hp_hotkey);

        QMetaObject::connectSlotsByName(Hp_hotkey);
    } // setupUi

    void retranslateUi(QWidget *Hp_hotkey)
    {
        Hp_hotkey->setWindowTitle(QApplication::translate("Hp_hotkey", "Form", nullptr));
        label_keyCamera->setText(QApplication::translate("Hp_hotkey", "\346\213\215\347\205\247\351\224\256", nullptr));

        const bool __sortingEnabled = listWidget_keyCamera->isSortingEnabled();
        listWidget_keyCamera->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_keyCamera->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Hp_hotkey", "\346\213\215\347\205\247/\345\275\225\345\203\217", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_keyCamera->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Hp_hotkey", "\345\274\200\345\205\263\350\241\245\345\205\211\347\201\257", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_keyCamera->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Hp_hotkey", "\345\210\207\346\215\242\350\211\262\346\240\207", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_keyCamera->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Hp_hotkey", "\345\274\200\345\205\263SR\346\250\241\345\274\217", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_keyCamera->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("Hp_hotkey", "\345\274\200\345\205\263WIFI", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_keyCamera->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("Hp_hotkey", "\345\274\200\345\205\263\350\223\235\347\211\231", nullptr));
        listWidget_keyCamera->setSortingEnabled(__sortingEnabled);

        label_keyCamera_2->setText(QApplication::translate("Hp_hotkey", "\346\213\215\347\205\247/\345\275\225\345\203\217", nullptr));
        label_keyCamera_3->setText(QString());
        toolButton_back->setText(QString());
        label_keyFocus_2->setText(QApplication::translate("Hp_hotkey", "\350\201\232\347\204\246", nullptr));
        label_keyFocus_3->setText(QString());
        label_keyFocus->setText(QApplication::translate("Hp_hotkey", "\350\201\232\347\204\246\351\224\256", nullptr));

        const bool __sortingEnabled1 = listWidget_keyFocus->isSortingEnabled();
        listWidget_keyFocus->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem6 = listWidget_keyFocus->item(0);
        ___qlistwidgetitem6->setText(QApplication::translate("Hp_hotkey", "\350\201\232\347\204\246", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_keyFocus->item(1);
        ___qlistwidgetitem7->setText(QApplication::translate("Hp_hotkey", "\345\274\200\345\205\263\350\241\245\345\205\211\347\201\257", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_keyFocus->item(2);
        ___qlistwidgetitem8->setText(QApplication::translate("Hp_hotkey", "\345\210\207\346\215\242\350\211\262\346\240\207", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget_keyFocus->item(3);
        ___qlistwidgetitem9->setText(QApplication::translate("Hp_hotkey", "\345\274\200\345\205\263SR\346\250\241\345\274\217", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = listWidget_keyFocus->item(4);
        ___qlistwidgetitem10->setText(QApplication::translate("Hp_hotkey", "\345\274\200\345\205\263WIFI", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = listWidget_keyFocus->item(5);
        ___qlistwidgetitem11->setText(QApplication::translate("Hp_hotkey", "\345\274\200\345\205\263\350\223\235\347\211\231", nullptr));
        listWidget_keyFocus->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class Hp_hotkey: public Ui_Hp_hotkey {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_HOTKEY_H
