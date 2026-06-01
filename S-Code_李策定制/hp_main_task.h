#ifndef HP_MAIN_TASK_H
#define HP_MAIN_TASK_H

#include  <QWidget>
#include  <QDebug>

namespace Ui {
class Hp_Main_Task;
}

class Hp_Main_Task : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Main_Task(QWidget *parent = 0);
    ~Hp_Main_Task();
    void update_sd(bool s);
    void update_wifi(bool s);
    void update_usb(bool s);
    void update_ble(bool s);
    void update_headset(bool s);
    void update_battery_stylesheet(QString style);

    void update_4g(bool s);
    void update_auto_focus(bool s);
    void hp_setDefine_S3x0(bool isSelect);
private:
    Ui::Hp_Main_Task *ui;
    void changeEvent(QEvent *e);
};

#endif // HP_MAIN_TASK_H
