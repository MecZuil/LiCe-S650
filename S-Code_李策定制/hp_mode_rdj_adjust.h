#ifndef HP_MODE_RDJ_ADJUST_H
#define HP_MODE_RDJ_ADJUST_H

#include  <QWidget>
#include  "hi384_protocol.h"
#include  "hptempunitconvert.h"
#include  <QKeyEvent>

namespace Ui {
class Hp_Mode_Rdj_Adjust;
}

class Hp_Mode_Rdj_Adjust : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Mode_Rdj_Adjust(QWidget *parent = 0);
    ~Hp_Mode_Rdj_Adjust();

    void setTempUnit(int unit);
    void setTempRang(int min,int max);

    void setFusion(FusionPara fp);
    FusionPara getFusion();
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void sync_fusion_para();
    void signal_update_lcdoff_time(bool iskey);
private slots:
    //void on_spinBox_type_valueChanged(int arg1);

    void on_doubleSpinBox_high_valueChanged(double arg1);

    void on_doubleSpinBox_low_valueChanged(double arg1);

    void on_doubleSpinBox_above_valueChanged(double arg1);

    void on_doubleSpinBox_below_valueChanged(double arg1);

    void on_toolButton_default_released();

    void on_toolButton_finish_released();

    void rdj_current_current_index_changed(int value);

    void on_listWidget_rdj_type_currentRowChanged(int currentRow);

private:
    Ui::Hp_Mode_Rdj_Adjust *ui;
    FusionPara fusionpara,bak_fusionpara;
    int tempunit;
    int rang_min,rang_max;

    HpTempUnitConvert htuc;

    void mode_rdj_signal_slot_init(bool flag);
    void changeEvent(QEvent *e);

    /************************/
//    bool rdj_type_init;                        // true 表示第一次初始化
    int  listwidget_type;                       //下拉框的状态，0--->没有下拉框打开。 1--->第一个下拉框打开。以此类推

    void listwidget_drop_manage_rdj_type(bool type);        // 第一个下拉框处理。主要是处理其它图标的使能状态。  true--->表示打开。false--->表示关闭


protected:
    virtual bool eventFilter(QObject *w, QEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *ev);

};

#endif // HP_MODE_RDJ_ADJUST_H
