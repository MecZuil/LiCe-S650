#ifndef HP_MAIN_TASK_3_H
#define HP_MAIN_TASK_3_H

#include  <QWidget>
#include  <QList>
#include <QDebug>
namespace Ui {
class Hp_Main_Task_3;
}

class Hp_Main_Task_3 : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Main_Task_3(QWidget *parent = 0);
    ~Hp_Main_Task_3();
    void update_sd(bool s);
    void update_wifi(bool s);
    void update_4G(bool s);
    void update_usb(bool s);
    void update_ble(bool s);
    void update_headset(bool s);
    void update_battery_stylesheet(QString style);

    void update_auto_focus(bool s);
    void hp_setDefine5_5(bool isSelect);
private:
    Ui::Hp_Main_Task_3 *ui;
    void changeEvent(QEvent *e);
};

#endif // HP_MAIN_TASK_3_H
