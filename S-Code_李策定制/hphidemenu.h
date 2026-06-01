#ifndef HPHIDEMENU_H
#define HPHIDEMENU_H

#include  <QWidget>
#include  <QDebug>

#include  "hi384_protocol.h"
#include  "hpxmlreader.h"
#include  "hp_defaultdialog.h"

namespace Ui {
class HpHideMenu;
}

class HpHideMenu : public QWidget
{
    Q_OBJECT

public:
    explicit HpHideMenu(QWidget *parent = 0);
    ~HpHideMenu();

    void hp_setDefine_S3x0(bool isSelect);
    void setDefineCompass(bool isDefineCompass);
    void setStartPower(bool isOpen);
 //   ComHideMenuPara com_hidemenu_para;

 // ComHideMenuPara hideMenuPara;
signals:
    void signal_pc_sys_set_hidemenu(ComHideMenuPara para);
    void signal_printscreen_checked(bool checked);
    void signal_gray_enable(bool checked);
    void signal_laser_enable(bool checked);

    void signal_point_enable(bool checked);
    void signal_rect_enable(bool checked);

    void signal_painter_rect(bool checked);
    void signal_painter_point(bool checked);

    void signal_pc_sys_set_mag_affset(int trans);
    void signal_set_compass_trans(int trans);
    void signal_pc_sys_mag_calsw_stop();
    void signal_pc_sys_mag_calsw_start();
    void signal_pc_get_measure_get_collect(int value);
public slots:
    void slot_set_para_2123();          //改变镜头或者挡位后，重新设置 para_ 的值
    void slot_core_hidemenu_get_para(ComHideMenuPara data);

private slots:
//    void slot_solid_value_change(int v);
    void slot_cap_enable(bool checked);
    void slot_start_get_gray();
    void slot_laser_enable(bool checked);
    void slot_gray_enable(bool checked);
    void slot_pc_sys_set_hidemenu(unsigned char return_value);
    void on_checkBox_printscreen_clicked(bool checked);


    void slot_point_enable(bool checked);
    void slot_rect_enable(bool checket);
    void slot_homogeneity_enable(bool checked);

    void on_doubleSpinBox_21_valueChanged(double arg1);
    void on_doubleSpinBox_23_valueChanged(double arg1);
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_3_clicked();
    void on_toolButton_4_clicked();
    void on_save_sys_2_clicked();
    void on_save_sys_3_clicked();


private:
    Ui::HpHideMenu *ui;

    int trans;
    hp_DefaultDialog *m_collectDialog;
    ComHideMenuPara hideMenuPara;
     HpXmlReader hpxmlreader;
    void update_hidemenuparam();
    void hidemenu_configpara_init();
};

#endif // HPHIDEMENU_H
