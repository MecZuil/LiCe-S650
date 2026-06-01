#ifndef HPHIDE_BIAODING_H
#define HPHIDE_BIAODING_H

#include  <QWidget>
#include  "hi384_protocol.h"
#include  "hpxmlreader.h"

#include  "hphide_dialog.h"
#include  "hphide_dialog_lo.h"
#include  "hphide_dialog_save.h"

#define BIG_SPINBOX_STYLESHEET "QSpinBox \
{ \
        background-color: rgb(173, 173, 173); \
} \
QSpinBox::up-button { \
    subcontrol-origin:border; \
    subcontrol-position:right; \
    width: 40; \
    height: 28; \
    image: url(:/res/res/right_arrow_n.png); \
} \
QSpinBox::down-button { \
subcontrol-origin:border; \
    subcontrol-position:left; \
    width: 40; \
    height: 28; \
    border-image: url(:/res/res/left_arrow_n.png); \
} \
QSpinBox::up-button:pressed{ \
    subcontrol-origin:border; \
    subcontrol-position:right; \
    width: 40; \
    height: 28; \
    image: url(:/res/res/right_arrow_s.png); \
} \
QSpinBox::down-button:pressed{ \
    subcontrol-position:left; \
    width: 40; \
    height: 28; \
    image: url(:/res/res/left_arrow_s.png); \
} \
QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off \
{ \
    width: 40; \
    height: 28; \
    border-image: url(:/res/res/left_arrow_d.png); \
} \
QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off \
{ \
    width: 40; \
    height: 28; \
    border-image: url(:/res/res/right_arrow_d.png); \
}"

namespace Ui {
class HpHide_Biaoding;
}

class HpHide_Biaoding : public QWidget
{
    Q_OBJECT



public:
    explicit HpHide_Biaoding(QWidget *parent = 0);
    ~HpHide_Biaoding();

    FPGAMenuPara fpgamenupara;
    Hphide_Dialog *hp_hide_dialog;
    Hphide_Dialog_LO *hp_hide_dialog_lo;
    Hphide_Dialog_SAVE *hp_hide_dialog_save;

    void hp_setDefine_S3x0(bool isSelect);
    bool define_S6X0_S3X0;//相当于宏定义HP_640_pro
    void setStructSave(bool structSave);
    void setCheckboxrotate(int val);
signals:
    void signal_biaoding_ceshi_2();
    void single_pc_biaoding_canshu(FPGAMenuPara para);
    void signal_biaoding_para_ok( );
    void single_biaoding_HI( );
    void single_biaoding_LO( );
    void single_biaoding_SAVE( );
    void single_biaoding_tiaoling( );
    void signal_pc_save_focus_offset(int value);
    void signal_pc_focus_offset(ComFocusOffset focusVal);
    void signal_biaoding_gray();        //获取灰度

    void signal_set_core_fpgamenu_badline_x(int x);
    void signal_set_core_fpgamenu_badline_y(int y);

    void signal_biaoding_DDE(int val);
    void signal_pc_checkbox_rotate(bool isChecked);
    void signal_core_fpgamenu_oritoggle(int val);
    void signal_core_fpgamenu_auto_badixel(int val);
    void signal_core_fpgamenu_value_badixel(int val);
    void signal_core_fpgamenu_badpixel_recover();
    void signal_pc_spinbox_para(int val);
    void signal_pc_spinbox_zoom(int val);
    void signal_image_set_gas(GasPara para);

    void signal_core_fpgamenu_set_intcp(int val);
    void signal_core_fpgamenu_set_adgain(int val);
    void signal_core_fpgamenu_set_fos(int val);
    void signal_core_fpgamenu_set_svrd(int val);
    void signal_core_fpgamenu_occ_enable(int val);
    void signal_core_fpgamenu_noise_time_para(int val);
    void signal_core_fpgamenu_noise_airspace_para(int val);
    void signal_core_fpga_get_svrd();
    void signal_core_fpga_get_adgain();
    void signal_core_fpga_get_intcp();
    void signal_core_fpga_get_fos();
    void signal_pc_image_set_vertical_handle(int val);
    void signal_pc_image_set_suppression_handle(int val);
public  slots:
    void slot_biaoding_ceshi();
    void slot_hphide_biaoding_zn(int zn_value);
    void slot_core_biaoding_canshu(FPGAMenuPara data);
    void slot_core_biaoding_gray(FPGAMenuGray data);
    void slot_pc_focus_offset(unsigned char return_value );
    void slot_biaoding_focus_offset(bool focusSaveMth, int laserfocus,int generalfocus,int fastFocus);

    void handleTimeout( );
    void slot_image_set_gas(GasPara para);

    void slot_set_core_fpgamenu_badline_x(unsigned char return_value);
    void slot_set_core_fpgamenu_badline_y(unsigned char return_value);
    void slot_biaoding_DDE(unsigned char return_value);
    void slot_setbiaoding_CheckBox_DDE(bool val);

    void slot_pc_checkbox_rotate(unsigned char return_value);
    void slot_core_fpgamenu_oritoggle(unsigned char return_value);
    void slot_core_fpgamenu_auto_badixel(unsigned char return_value);
    void slot_core_fpgamenu_badpixel_recover(unsigned char return_value);
    void hp_saveFocus();
    void hp_setautofocusmode(int mode);
    void slot_spinBox_Para_valueChanged(int val);
    void slot_spinBox_Zoom_valueChanged(int val);
    void slot_pc_spinbox_para(unsigned char return_value);
    void slot_pc_spinbox_zoom(unsigned char return_value);
    void slot_setbiaoding_Para(int val);
    void slot_setbiaoding_Zoom(int val);
    void slot_setbiaoding_3DSD(int val);
    void slot_setbiaoding_3DHDFF(int val);
    void slot_core_fpga_get_svrd(unsigned char return_value, int val);
    void slot_core_fpga_get_intcp(unsigned char return_value, int val);
    void slot_core_fpga_get_fos(unsigned char return_value, int val);
    void slot_core_fpga_get_adgain(unsigned char return_value, int val);
private slots:

    void on_Button_cancel_released();

    void on_Button_set_released();

  //  void on_comboBox_ZN_currentIndexChanged(int index);

  //  void on_comboBox_ZN_currentIndexChanged(const QString &arg1);

    void on_spinBox_vs_valueChanged(int arg1);

    void on_spinBox_vf_valueChanged(int arg1);

    void on_spinBox_gain_valueChanged(int arg1);

    void on_spinBox_tnt_valueChanged(int arg1);

    void on_Button_HI_released();

    void on_Button_LO_released();

    void on_Button_save_released();

//    void on_spinBox_facus_valueChanged(int arg1);

    void on_Button_X_released();

    void on_Button_Y_released();
    void hp_slot_DDE_checked(bool checked);
    void on_checkBox_Sensibility_click(bool checked);
    void on_spinBox_SensibilityGain_value_change(int value);
    void on_spinBox_SensibilityRange_value_change(int value);
    void on_checkBox_rotate_clicked(bool checked);

    void on_Button_oritoggle_0_clicked();

    void on_Button_oritoggle_1_clicked();

    void on_checkBox_auto_badpixel_clicked(bool checked);

    void on_Button_recover_clicked();

    void on_spinBox_facus_3_valueChanged(int arg1);

    void on_spinBox_fos_valueChanged(int arg1);

    void on_spinBox_svrd_valueChanged(int arg1);

    void on_spinBox_adgain_valueChanged(int arg1);

    void on_spinBox_intcp_valueChanged(int arg1);

    void on_checkBox_OCC_clicked(bool checked);

    void on_spinBox_3DHDFF_valueChanged(int arg1);

    void on_spinBox_3DSD_valueChanged(int arg1);

    void on_checkBox_VERTICAL_clicked(bool checked);

    void on_checkBox_SUPPRESSION_clicked(bool checked);

private:
    Ui::HpHide_Biaoding *ui;
    HpXmlReader hpxmlreader;
    bool isStructSave;
    int focusmode;
protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
    QTimer *timer;
};

#endif // HPHIDE_BIAODING_H
