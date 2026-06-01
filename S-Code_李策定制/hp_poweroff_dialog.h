#ifndef HP_POWEROFF_DIALOG_H
#define HP_POWEROFF_DIALOG_H

#include  <QWidget>
#include  <QTimer>
#include  <QDebug>
#include  "hpxmlreader.h"

namespace Ui {
class Hp_PowerOff_Dialog;
}

class Hp_PowerOff_Dialog : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_PowerOff_Dialog(QWidget *parent = 0);
    ~Hp_PowerOff_Dialog();
    void start_delay();
    bool get_shutting();

    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_pc_sys_set_powerdown(int power);
private slots:
    void timer_out();

private:
    Ui::Hp_PowerOff_Dialog *ui;
    QTimer timer_1s;
    int timer_cnt;

    bool shutting;

    HpXmlReader hpxmlreader;
    void changeEvent(QEvent *e);
};

#endif // HP_POWEROFF_DIALOG_H
