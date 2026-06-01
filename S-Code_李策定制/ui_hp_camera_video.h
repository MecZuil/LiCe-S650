/********************************************************************************
** Form generated from reading UI file 'hp_camera_video.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HP_CAMERA_VIDEO_H
#define UI_HP_CAMERA_VIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hp_Camera_Video
{
public:
    QLabel *label;
    QLabel *label_second;

    void setupUi(QWidget *Hp_Camera_Video)
    {
        if (Hp_Camera_Video->objectName().isEmpty())
            Hp_Camera_Video->setObjectName(QStringLiteral("Hp_Camera_Video"));
        Hp_Camera_Video->resize(640, 480);
        Hp_Camera_Video->setStyleSheet(QStringLiteral("background-color: rgb(0, 8, 16);"));
        label = new QLabel(Hp_Camera_Video);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(395, 0, 121, 30));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_second = new QLabel(Hp_Camera_Video);
        label_second->setObjectName(QStringLiteral("label_second"));
        label_second->setGeometry(QRect(526, 0, 101, 30));
        label_second->setFont(font);
        label_second->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        retranslateUi(Hp_Camera_Video);

        QMetaObject::connectSlotsByName(Hp_Camera_Video);
    } // setupUi

    void retranslateUi(QWidget *Hp_Camera_Video)
    {
        Hp_Camera_Video->setWindowTitle(QApplication::translate("Hp_Camera_Video", "Form", nullptr));
        label->setText(QApplication::translate("Hp_Camera_Video", "\345\275\225\345\203\217\344\270\255", nullptr));
        label_second->setText(QApplication::translate("Hp_Camera_Video", "00:00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hp_Camera_Video: public Ui_Hp_Camera_Video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HP_CAMERA_VIDEO_H
