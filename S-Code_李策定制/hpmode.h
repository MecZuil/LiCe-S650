#ifndef HPMODE_H
#define HPMODE_H

#include  <QWidget>
#include  "hi384_protocol.h"
namespace Ui {
class HpMode;
}

class HpMode : public QWidget
{
    Q_OBJECT

public:
    explicit HpMode(QWidget *parent = 0);
    ~HpMode();

    bool set_mode(int m);
    int get_mode();

    bool fidpid;    //用于标识fidpid是否开启

    Ui::HpMode *ui;

    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_update_lcdoff_time(bool iskey);
    void signal_rdj_set_adjust();
private slots:
    void on_toolButton_rdj_adjust_2_clicked();

private:

    void changeEvent(QEvent *e);

    int mode;
};

#endif // HPMODE_H
