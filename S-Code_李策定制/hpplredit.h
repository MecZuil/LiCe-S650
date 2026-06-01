#ifndef HPPLREDIT_H
#define HPPLREDIT_H

#include  <QWidget>
#include  <QKeyEvent>
#include  "hi384_protocol.h"
namespace Ui {
class HpPLREdit;
}

typedef enum
{
    echeckBox_radiance,
    eframe_radiance,
    ehs_radiance,
    ehs_distance,
    ecb_refer,
    eframe_temptype,
    ehs_reflect,
    epb_cancle,
    epb_finish,
}PLR_OBJECTNAME;

class HpPLREdit : public QWidget
{
    Q_OBJECT

public:
    explicit HpPLREdit(QWidget *parent = 0);
    ~HpPLREdit();

    int  part_radTable_switch;
    int  part_radTable_id;
    int  part_radTable_value100;
    int  listwidget_type;                       //下拉框的状态，0--->没有下拉框打开。 1--->测温类型。2--->辐射率

    void set_checkBox_radiance_state(bool checked);
    void listwidget_type_manage();                                          //用于切换界面。和一些按钮，根据是否打开listwidget列表进行处理

    void setTaskstyleSheet(bool IsTask);

    Ui::HpPLREdit *ui;
    void hp_setDefine_S3x0(bool isSelect);
//public slots:
//    void hp_slot_checkBox_volcal_checked(bool checked);

//    void hp_slot_checkBox_angle_checked(bool checked);
private slots:
//    void hp_slot_cb_linedepth(bool checked);
//    void slot_pc_image_set_abnormalexitend(unsigned char return_value);
    void on_cb_temptype_currentIndexChanged(int index);
    void on_listWidget_temptype_currentRowChanged(int currentRow);

    void on_pb_cancle_clicked();

    void on_pb_finish_clicked();

    void on_checkBox_radiance_clicked(bool checked);

    void on_listWidget_radiance_currentRowChanged(int currentRow);

signals:
    void signal_temptype_changed(int index);
    void signal_part_radTable_change(int id, int value);
    void signal_part_radTable_mode(int mode);
    void signal_cb_refer_clicked(bool checked);
    void signal_update_lcdoff_time(bool isKey);
    void SignalRefreshDisplayMaxRect();
private:
    ComAbnormalExtendPara abnormalpara;
    bool language_changing;
    PLR_OBJECTNAME plr_onject;
    void changeEvent(QEvent *e);
    void AssemblyStyleSet(PLR_OBJECTNAME objectSel,bool state);
    int  part_radTable_value[24] = {96, 80, 90, 93, 20, 55, 22, 61, 78, 74, 65, 64, 21, 37, 79, 85, 95, 98, 92, 97, 94, 93, 90, 92};

    void listwidget_drop_manage_temptype(bool type);        // 拉框处理。主要是处理其它图标的使能状态。  true--->表示打开。false--->表示关闭
    void listwidget_drop_manage_radiance(bool type);
protected:
    virtual bool eventFilter(QObject *w, QEvent *e);
};

#endif // HPPLREDIT_H
