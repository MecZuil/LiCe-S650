#ifndef HP_ADJUST_CMD_H
#define HP_ADJUST_CMD_H

#include  <QWidget>
#include  <QTimer>
#include  <QDebug>
#include  "hi384_protocol.h"
#include  "hpxmlreader.h"

namespace Ui {
class Hp_Adjust_Cmd;
}

class Hp_Adjust_Cmd : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Adjust_Cmd(QWidget *parent = 0);
    ~Hp_Adjust_Cmd();
    void startBnTimer();
    void stopBnTimer();
    void set_focus_styles(bool AF_focus);
    void set_spinbox_value();
    void change_spinbox_value(QString adjust_name);
    bool adjust_cmd_open;               //true表示打开这个界面
    int get_focus_mode();
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_FusionAdjust(FusionAdjust fa);

    void signal_pc_sys_get_bn();
    void signal_pc_sys_get_focus();
public slots:
    void slot_pc_measure_set_temprange_ok(unsigned char return_value);
private slots:

    void on_spinBox_N1_valueChanged(int arg1);

    void on_spinBox_N2_valueChanged(int arg1);

    void on_spinBox_N3_valueChanged(int arg1);

    void on_spinBox_N4_valueChanged(int arg1);

    void on_spinBox_X1_valueChanged(int arg1);

    void on_spinBox_X2_valueChanged(int arg1);

    void on_spinBox_X3_valueChanged(int arg1);

    void on_spinBox_X4_valueChanged(int arg1);

    void on_spinBox_Y1_valueChanged(int arg1);

    void on_spinBox_Y2_valueChanged(int arg1);

    void on_spinBox_Y3_valueChanged(int arg1);

    void on_spinBox_Y4_valueChanged(int arg1);

    void slot_FusionAdjust(unsigned char return_value);

    void slot_bn_timer();

    void slot_pc_sys_get_bn(unsigned char return_value,int bn);
    void slot_pc_sys_get_focus(unsigned char return_value,int bn);
private:
    Ui::Hp_Adjust_Cmd *ui;

    QTimer *bnTimer;
     HpXmlReader xml;
    bool init_flag;
    int lens_id;                //镜头id  0--->3
    int focus_mode;         //聚焦模式。 0--->自动调焦，1--->手动调焦

};

#endif // HP_ADJUST_CMD_H
