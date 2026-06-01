#ifndef HP_HOTKEY_H
#define HP_HOTKEY_H

#include <QWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>
#include "hi384_protocol.h"

enum KEYSETTING
{
    HOTKEY_CAMERA=0,
    HOTKEY_FOCUS,
    HOTKEY_LED,
    HOTKEY_PALLET,
    HOTKEY_SR,
    HOTKEY_WIFI,
    HOTKEY_BLUETOOTH,
};

namespace Ui {
class Hp_hotkey;
}

class Hp_hotkey : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_hotkey(QWidget *parent = nullptr);
    ~Hp_hotkey();
    void setFocusType(int keyType);
    void setCameraType(int keyType);
    void showText();
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_hotkey_set_key_camera(KEYSETTING value);

    void signal_hotkey_set_key_focus(KEYSETTING value);
private slots:
    void on_listWidget_keyCamera_currentRowChanged(int currentRow);

    void on_listWidget_keyFocus_currentRowChanged(int currentRow);

    void on_toolButton_back_clicked();
protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    Ui::Hp_hotkey *ui;
    void changeEvent(QEvent *e);
};

#endif // HP_HOTKEY_H
