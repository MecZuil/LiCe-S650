#ifndef HPSETTING_H
#define HPSETTING_H

#include  <QWidget>
#include  <QKeyEvent>
#include  "hptabwidgetstyle.h"
#include  "hi384_protocol.h"
#include  "hpcpumem.h"
#include  "hp_hotkey.h"
#include  "hphidemenu.h"
#include  "hpxmlreader.h"
#include  "hptempunitconvert.h"
#include  "hp_defaultdialog.h"
#include  "hp_formatdialog.h"
#include  "hp_dialog.h"
#include  "hp_calbration.h"

#include  "hp_ble_search.h"
#include  "hphide_biaoding.h"
#include  "hphide_dialog.h"
#include  "hpsetting_adjust.h"
#include  "hp_isotherm.h"
#include  "hp_wifi_search.h"
#include  "hp_autoupload.h"
#include  "hp_autoupload_dialog.h"
#include  "hp_download.h"
#include  "hp_common_dialog_select.h"
#include  "hp_mulhom_edit.h"
#include  "hp_panorama.h"
#include  "hphide_laser.h"
#include  "hp_bel_search_old.h"
#include  "hp_transmission.h"
#include  "hp_transmissionsearch.h";

#define LISTWIDGETS3X0 "QListWidget { border: 1px solid #7CA6C9; color:#7CA6C9; background-image: url(:/res/res/list_background.png); border-right-color: 0px; } \
    QScrollBar:vertical { border:0px solid #7CA6C9; background-color:#32CC99; width:25px; margin:25 0 25 0px; } \
    QScrollBar::handle:vertical { background-color: rgb(83, 166, 249); border:1px solid #7CA6C9; } \
    QScrollBar::add-line:vertical { border:0px solid #7CA6C9; background-color:transparent; width:25px; height:25px; subcontrol-position:bottom; subcontrol-origin:margin; border-image: url(:/res/res/m_down_arrow_s.png); } \
    QScrollBar::sub-line:vertical { border:0px solid #7CA6C9; background-color:transparent; width:25px; height:25px; subcontrol-position:top; subcontrol-origin:margin; border-image: url(:/res/res/m_up_arrow_s.png); }\
    QScrollBar::up-arrow:vertical,QScrollBar::down-arrow:vertical { border:0px; width:25px; height:25px; } \
    QScrollBar::add-page:vertical { background-color:transparent; } \
    QScrollBar::sub-page:vertical { background-color:transparent; }"

namespace Ui {
class HpSetting;
}

enum SETING_4G      //用于标识4G状态
{
    IS_ON_NONE,         //空闲状态
    IS_ON_CONNECT,      //处于连接中
    IS_ON_CONNECT_WAIT, //处于等待连接状态
    IS_ON_CONNECT_OK,   //处于连接成功
};


class HpSetting : public QWidget
{
    Q_OBJECT

public:
    explicit HpSetting(QWidget *parent = 0);
    ~HpSetting();
    Ui::HpSetting *ui;
    bool isBleOpen;
    bool isNewBle;
    bool lcd_offed;
    bool onlcdonce;//揭示是否是在息屏刚唤醒时，因为每次事件都会被触发两次，所以要有这个变量来限制
    HpHideMenu hphidemenu;
    hphide_laser hpdidelaser;
//2018.4.2 生产标定界面
    HpHide_Biaoding hphide_biaoding;
    hp_DefaultDialog *hpdefault;
    Hp_FormatDialog *hpformat;
    HpSetting_adjust *hpsetadjust;
    hp_Isotherm  hpisotherm;
    Hp_Ble_Search hpblesearch;
    Hp_Bel_Search_Old hpblesearchold;
    QList<DANGWEI> dangwei_list;
    Hp_Wifi_Search *hp_wifi_Search;//为什么这个界面点击返回无效呢？原因：hp_wifi_Search是指定父窗口的界面，而hpblesearch未指定父窗口

    hp_transmission *m_Transmission;
    Hp_hotkey m_hotkeyWidget;
    hp_calbration hpcalbration;
    hp_AutoUpLoad *hp_autoupload;//这个按下返回键被父窗口接收和hp_wifi_Search一样的原因
    hp_download *hp_downLoad;
    hp_common_dialog_select *hp_Common_dialog_select;
    hp_common_dialog_cancel *hp_Common_dialog_cancel;
    hp_mulhom_edit *hp_Mulhom_edit;
    Hp_Autoupload_Dialog *hp_autoupload_dialog;
    SETING_4G state4G;
    bool canbercv;//连接超时

    bool m_isOpenCircle;
    bool m_isOpenPolygon;
    QTimer m_timer_4G;
    QTimer *state_4G;//打开4G时，获取4G状态
    QTimer *state_Wait_4G;//4G连接时查看4G是否处于连接状态
    int state_wait_4G_open;//等待时发送打开4G信号
    QTimer tempSetTm;//当切换挡位时启动，不断查询挡位是否切换成功
    bool isWifiInsert;
    bool isOtherm;//就代表宏定义ISOTHERM
    bool isWIFISearch;//代表wifi是否打开
    bool isWIFIServer;
    bool onceUpload;//代表一键上传是否打开
    bool download;//代表一键下载是否打开
    bool fidpid;//代表FIDPID是否打开
    bool define_S6X0_S3X0;//标识S3X0是否打开
    bool isTaskMode;//标识是否为台账模式

    bool fastfocusmode;//标志着是否为快速自动聚焦
    bool guowangFlag;   //false 表示国网模式开启    true 表示国网模式关闭
    bool panoramaFlag;

    QWidget *parentP;//主界面指针

    void setCurrentTabToWenDuXiuZheng();
    int gettempunit();
    bool getCheckedAutoUpdata();
    void disableSignalSlot(bool flag);
    void ResetPreviewParameters();
    void StoragePreviewParameters();
    int get_temp_unit_state();                          //获取温度单位

    void LimitAutoSave_SR_AutoUpload();//自动上传和SR互斥、自动存储和SR互斥,关闭SR功能
    void RelieveLimitAutoSave_SR_AutoUpload();

    void LimitAutoUpload();//自动存储和自动上传互斥，关闭自动存储功能
    void RelieveLimitAutoUpload();

    int get_environ_temp() { return TempUserPara.AmbientTempManu100; }   //获取环境温度
    void autoupdate_once(int page,int zon,QString content);
    bool winInit();//通过配置文件设置图标位置
    void initStyleSheet();
    void hp_setS3X0(bool isS3X0);
    void dangweiAutoaddone();
    void jintouAutoaddone();
    bool getPanoramaFlag();
    void slot_setCameracapChecked(bool checked);
    void slot_srvupload_failed();
    void delaymsec(int msec);
    int getAlarmTemp();
    OsdSetting getOsdSetting();
    int getAlarmSwitch();
    bool isGpsOpen;
    bool tempWengdangchange;//是否处于温档改变状态
    int  jingtouhide;//目前的选中的镜头，相较于显示的镜头数加上隐藏的镜头数，用于长按激光自动切换镜头
    int m_colorrulemaxid;
    int m_colorruleminid;
    int m_reflectType;
    int swiftingCounter;
protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
    virtual bool eventFilter(QObject *w, QEvent *e);
    virtual void MousePressEvent(QMouseEvent *ev);

signals:
    void SignalClearMaxRectPara();//恢复出厂设置时
    void SignalCheckAndCreateDateFolder();
    void signal_noncool_unenable_plr(bool isAimTemp);
    void signal_core_fpgamunu_noncool_correct(int para);
    void signal_pc_sys_set_wifi_eth_close(int para);
    void signal_show_4G_pixel(int gps);
    void signal_show_gps_pixel(int gps);
    void signal_set_show_avgTemp(bool isShow);
    void signal_set_auto_reflect(bool isShow);
    void signal_pc_image_set_gps(int gps);
    void signal_core_get_usbwifiinsert();
    void signal_start_panorama(bool isOpen);
    void signal_stop_AviMode(bool checked);
    void signal_stop_TextVoice(bool checked);
    void signal_pc_key_auto_rectify();
    void signal_set_IsInlcdoff(bool value);
    void signal_SetAutoUpdateIsChecked(bool checked);
    void signal_pc_sys_set_autorectify(int time_s);
    void signal_update_radiance_to_display(int value);
    void signal_update_radTable_to_display(int id, int value);
    void signal_set_radTable_state(int mode);
    void signal_update_distance_to_display(int value);
    void signal_update_reflect_temp_to_display(int value);
    void signal_core_fpgamenu_oritoggle(int value);
    void signal_pc_sys_set_hidemenu(bool para);
    void signal_pc_sys_set_step_zero(int value);
    void signal_pc_cfg_set_temp_userpara(ComTempUserPara para);
    void signal_pc_measure_set_reference(ComTempReference para);
    void signal_pc_measure_set_tempunit(int unit);
    void signal_pc_measure_set_temprange(ComTempRange para);
    void signal_pc_measure_temprange_query(ComTempRange para);
    void signal_pc_image_set_alarm(ComAlarmTemp para);
    void signal_pc_sys_time_sec(char *str);
    void signal_pc_sys_set_capturetime(int time);
    void signal_pc_sys_set_usbmode(int usbtype);
    void signal_pc_sys_set_wifi_switch(int power);
    void signal_pc_sys_set_local_servrer(int isOpen);
    void signal_language_changed(int index);
    void signal_set_usbmode(int index);
    void signal_set_para_2123();
    void signal_setting_close();
    void signal_set_globresize_nZoomRate10_value(int nZoomRate10);      //设置resize放大倍数
    void signal_set_globnProcessType_value(int nProcessType, int nMaxTempHand100,int nMinTempHand100);
    void signal_set_part_ReferTemp(bool checked);
    void signal_ScrollBar_TempUnit_change(int value);                           //二次分析返回时调用，用来设置温度单位
    void signal_language_changed_end();
    void signal_pc_measure_tempcapture(int TempCapture);
    void signal_tempunit_value_changed(int temp_unit);
    void signal_pc_measure_set_compensate(int compensate);

    void signal_checkBox_volumn_checked(bool checked);//体积测算
    void signal_checkBox_angel_checked(bool checked);//角度辅助
    void signal_set_picture_zoom_save(bool isChecked);//原图存储
    void signal_set_temp_hum_enable(int enable);//干湿度使能
    void signal_pc_osd_set_osdstat(OsdSetting para);
    void SignalAutoSave(int SaveValue);
    void signal_pc_image_set_abnormal(int isSet);
    void SignalSetImageSR(bool isSelect);
    void signal_avi_hir_mode(int mode);
    void signal_TaskStart();
    void siganl_image_set_gas_para(GasPara para);
    void signal_StartAutoUpload_once(bool isTask);//一键上传,参数：是台账图片还是普通图片
    void signal_autoupdate_return();//一键上传返回
    void signal_set_HDMI(int index);
    void signal_hidemenu_ImageChange(ComTempRange para);
    void signal_pc_sys_set_autofocusmode(int num);
    void signal_pc_sys_set_wifi_power(int val);
    void signal_update_lcdoff_time(bool iskey);
    void SignalSetImageSIS(bool isSelect);
    void signal_set_qrcode_state(bool  checked);
    void signal_pc_measure_mulhomogeneity(int num);
    void signal_pc_sys_set_ble_power(int on);
    void signal_pc_sys_set_ble_module(int mode);
    void signal_pc_sys_set_ble_switch(int on);
    void signal_pc_image_set_imagetype(int num);
    void signal_pc_sys_set_light_power(int power);
    void signal_pc_sys_set_powerdown(int power);
    void signal_pc_sys_set_screen_sleep(int power);
    void signal_set_4G_power(int num);
    void signal_set_4G_state(int num);
    void signal_set_4G_stop(int num);
    void signal_get_4G_state();
    void signal_set_4G_icon(bool checked);
    void signal_timer_get_positiion_switch(int para);
    void signal_sketch_switch(int para);
    void signal_set_ETH_switch(int para);
    void signal_pc_image_set_sketch_clear();
    void signal_pc_image_set_flip(int iamgettype);
    void signal_timer_get_rotation_switch(int index);
    void signal_start_transmission();
    void signal_stop_transmission();
    void signal_set_image_format(int imageFormat);
    void signal_set_preset_mode(int presetMode);
    void signal_pc_key_focus_select(int flag);
    void signal_pc_key_focus_stop_aut(bool checked);
public slots:
    void set_gps();
    void slot_lcd_ReOpen();
    void yqsz_GPS_setchecked(bool checked);
    void yqsz_avgTemp_setchecked(bool checked);
    void yqsz_nonCool_setchecked(bool checked);
    void slot_set_dialog_close(bool isClose);
    void slot_pc_image_set_gps(unsigned char return_value);
    void set_ScrollBar_Distance(double distance);
    void slot_pc_sys_set_ETH_switch(unsigned char return_value);
    void slot_core_get_usbwifiinsert(unsigned char return_value, int uwi);
    void slot_pc_sys_set_ble_power(unsigned char return_value);
    void slot_pc_sys_set_ble_module(unsigned char return_value);
    void slot_pc_sys_set_ble_switch(unsigned char return_value);
    void slot_core_fpga_get_ver(unsigned char return_value,int val);
    void slot_update_lcdoff_Time();//自动关屏，按下按键时执行，重新输入时间
    void slot_cpuMemu(bool checked);
    void slot_hidemenu(bool checked);
    void wdxz_radiance_value_changed(int value);
    void wdxz_distance_double_value_changed(double value);
    void wdxz_humidity_value_changed(int value);
    void wdxz_reflecttemp_double_value_changed(double value);
    void wdxz_transmission_value_changed(int value);
    void wdxz_ambienttempmenu_double_value_changed(double value);
    void wdxz_refertemp_enable(bool checked);
    void wdxz_reflectTemp_enable(bool checked);
    void wdxz_refertemp_double_value_changed(double value);
    void wdxz_tempunit_value_changed(int value);
    void cwfw_autorectify_value_change(int value);
    void cwfw_dangwei_current_index_changed(int value);
    void cwfw_jingtou_current_index_changed(int value);
    void cwfw_baojingshezhi_current_index_changed(int value);
    void cwfw_baojingwendu_double_value_changed(double value);
    void cwfw_baojingjuli_double_value_changed(double value);
    void cwfw_baojingse_current_index_changed(int value);

//    void yqsz_checkBox_zoomSave_checked(bool ischeked);
//    void yqsz_checkBox_tempHum_checked(bool ischecked);
    void yqsz_zidongcunchu_value_changed(int value);
    void yqsz_autoUpdate_setchecked(bool checked);
    void checkBox_hdmi_Clicked(bool checked);
    void yqsz_autoUpdate_Edit_setchecked();
    void yqsz_btautoUpdate_once_clicked();
    void yqsz_btdownload_clicked();
    void yqsz_mulhom_setchecked(bool checked);
    void slot_Set_Unchecked();
    void slot_pc_sys_set_autorectify(unsigned char return_value);
    void slot_pc_cfg_set_userpara(unsigned char return_value);
    void slot_pc_measure_set_reference(unsigned char return_value);
    void slot_pc_measure_set_tempunit(unsigned char return_value);
    void slot_pc_measure_set_temprange(unsigned char return_value);
    void slot_pc_measure_temprange_query(unsigned char return_value);
    void slot_pc_image_set_alarm(unsigned char return_value);
    void slot_pc_sys_set_default(unsigned char return_value);
    void slot_pc_sys_set_format(unsigned char return_value);
    void slot_pc_sys_set_capturetime(unsigned char return_value);
    void slot_pc_sys_time_sec(unsigned char return_value);
    void slot_pc_sys_set_usbmode(unsigned char return_value);
    void slot_pc_sys_set_wifi_switch(unsigned char return_value);
    void slot_pc_measure_mulhomogeneity(unsigned char return_value);
    void slot_set_current_lens(int len);
    void finish_button_pressed();
    void wifi_clicked(bool checked);
    void buguangdeng_clicked(bool checked);
    void ble_clicked(bool checked);

    void slot_ble_set_close();
    void auto_poweroff_value_changed(int index);
    void auto_lcdoff_value_changed(int index);
    void ble_edit_release();
    void wifi_edit_release();
//    void slot_dangwei_jingtou_adjust(bool state);
    void slot_dev_get_parameter(unsigned char *data,unsigned char return_value);                    //设备获取一些全局参数
    void slot_set_globle_ReferTemp(bool checked);
    void slot_set_lcd_offed_state();
    void slot_pc_measure_tempcapture(unsigned char return_value);
    void slot_JPGTemCaptrue_Switch(int isOpen);
    void slot_pc_measure_set_compensate(unsigned char return_value);
    void slot_pc_image_set_abnormal(unsigned char return_value);
    void slot_setWifiIsSelect(bool checked);
    void save_start_error_about_temp();
    void slot_close_task();//关闭时触发
    void slot_StartAutoUpload_once(bool isTask);
    void slot_closeAutoUpload_once();
    void slot_selectAutoUpload_once(int select);
    void slot_scroll_page_changed(int page);
    void slot_pc_sys_set_HDMI(unsigned char return_value);
    void slot_client_isOn(bool ischecked);
    void slot_hidemenu_ImageChange(bool isChecked);
    void hp_emitsignal_hidemenu_ImageChange();
    void yqsz_focusmode_current_index_changed(int currentRow);
    void slot_pc_sys_set_wifi_power(unsigned char return_value);
    void slot_get_wifi_inert();
    void clot_close_sis_switch();
    void on_checkBox_sis_clicked(bool checked);
    void yqsz_mulhom_edit_checked();
    void hp_slot_mulhom_edit_value_changed(int val);
    void slot_tempSetTm_out();
    void set_ScrollBar_TemperInfo(temper_info_t temperInfo);
    void slot_set_4G_state(unsigned char return_value);
    void slot_get_4G_state(unsigned char return_value,int status);
    void slot_timeout_4G_wait_state();
    void slot_measure_reflect_temp(int value);
    int getLensCount();
    void setInitAlarmMsg();
private slots:
    void on_calbration_edit_clicked();

    void on_checkBox_bmp_clicked(bool checked);

    void yqsz_compass_setchecked(bool checked);

    void yqsz_contrustFocus_setchecked(bool checked);

    void yqsz_4G_setchecked(bool checked);

    void on_pushButton_default_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_pushButton_3_clicked();

    void on_pushButton_hotkey_clicked();

    void timer_func();

    void on_comboBox_usbmode_currentIndexChanged(int index);

    void on_comboBox_language_currentIndexChanged(int index);

    void on_pushButton_qiehuan_released();

    void slot_tabbar_current_changed(int index);

    void on_listWidget_jingtou_clicked(const QModelIndex &index);

    void on_listWidget_wendang_clicked(const QModelIndex &index);

    void on_listWidget_baojingshezhi_clicked(const QModelIndex &index);

    void on_listWidget_baojingse_clicked(const QModelIndex &index);

    void on_listWidget_jingtou_currentRowChanged(int currentRow);

    void on_listWidget_wendang_currentRowChanged(int currentRow);

    void on_listWidget_baojingshezhi_currentRowChanged(int currentRow);

    void on_listWidget_baojingse_currentRowChanged(int currentRow);

    void on_listWidget_usbmode_currentRowChanged(int currentRow);

    void on_listWidget_language_currentRowChanged(int currentRow);

    void on_listWidget_poweroff_currentRowChanged(int currentRow);

    void on_listWidget_lcdoff_currentRowChanged(int currentRow);

    void on_checkBox_Radiance_clicked(bool checked);

    void on_checkBox_ReferTemp_enable_clicked(bool checked);

    void on_listWidget_Radiance_currentRowChanged(int currentRow);

    void on_checkBox_Catch_clicked(bool checked);

    void on_comboBox_buchangwendu_valueChanged(double value);

    void on_checkBox_area_clicked(bool checked);

    void on_checkBox_sr_clicked(bool checked);

    void on_checkBox_fid_clicked(bool checked);

    void on_checkBox_pid_clicked(bool checked);

    void on_checkBox_panorama_clicked(bool checked);

    void on_listWidget_imageType_currentRowChanged(int currentRow);

    void on_checkBox_zoomSave_clicked(bool checked);

    void on_listWidget_recordmode_currentRowChanged(int currentRow);

    void on_checkBox_homogeneity_clicked(bool checked);

    void on_checkBox_sketch_clicked(bool checked);

    void on_checkBox_stepZero_clicked(bool checked);

    void slot_cancel4GConnect();

    void slot_timeout_4G_state();

    void on_dengwengse_edit_released();

    void on_ScrollBar_AmbientTempManu_valueChanged(double arg1);

    void on_listWidget_modeSelect_currentRowChanged(int currentRow);

    void on_checkBox_gw_clicked(bool checked);

    void on_checkBox_oritoggle_clicked(bool checked);

    void on_listWidget_ReflectTemp_currentRowChanged(int currentRow);

    void on_checkBox_eth_clicked(bool checked);

    void on_sketch_edit_clicked();

    void on_checkBox_transmission_clicked(bool checked);

    void on_checkBox_flip_clicked(bool checked);

    void slot_link_transmission(QString addr);

    void slot_start_get_bleInfo();

    void slot_stop_get_bleInfo(QString bleInfo);

    void slot_transmission_start();

    void slot_transmission_stop();

    void slot_set_dialog_close();

    void slot_transmission_allow_upload();

    void slot_transmission_send_heartbeat();

    void slot_transmission_get_download();
    void on_trmission_edit_clicked();
    void slot_reset_ble_power();
    void on_checkBox_preset1_clicked(bool checked);
    void on_checkBox_preset2_clicked(bool checked);
private:
    Hp_Dialog *hpdialog;
    HpTabWidgetStyle *p_tws;
    HpCpuMem *hpcpumem;
    HpXmlReader hpxmlreader;
    HpTempUnitConvert hptempunitconvert;
    ComTempUserPara TempUserPara,TempUserPara_old;
    ComTempReference TempReference,TempReference_old;
    ComTempRange  TempRange;
    ComAlarmTemp AlarmTemp;
    OsdSetting osdsetting;
    Hp_TransmissionSearch *m_transmissionSearch;
    bool m_transmissionInit;
    bool m_transmissionStart;
    bool m_transmissionIsSearch;
    QTimer timer;
    int m_isS3X0;
    ComSysConfig MainInterUserPara;
    bool eth_change;
    int eth_num;
    bool IsInEth;//当点击WIFI、ETH时调用
    bool isManualCall;
    bool alreadyClosed;
    bool isHotkey;
    QString hp_datetime,hp_datetime_old;
    int fastimageType;
    int getWifiWait;
    bool blePower;
    bool bleSwitch;
    int dangweiMaxTemp;//最大挡位值
    int dangweiMinTemp;//最小挡位值
    int lensnum,rangenum;
    int autorectify_time,autorectify_time_old,autorectify_time_back;
    int screensave_time,screensave_time_old;
    int tempunit;
    int tempjingdu;
    int lcdoff_clock;//关屏时间
    int lcdoff_clock_ret;//关屏临时时间
    int poweroff_clock;
    int dangwei_exit[3];                    //0:表示该测温范围存在。 1表示不存在
    int jingtou_state[4];                    //四个镜头的使能状态 1 表示镜头使能
    int  jingtou_enable[4];                //依次表示那个镜头使能了。比如  jingtou_enable[0]=2; 表示第一个使能的镜头是镜头三。存放镜头号
    int jingtou_enable_num;            //镜头使能数量
    int ui_jingtou_id, ui_dangwei_id;   //设置后，镜头和挡位ID号
    int ui_dangwei_changeid, ui_jingtou_changeid;
    int  radTable_value[24] = {96, 80, 90, 93, 20, 55, 22, 61, 78, 74, 65, 64, 21, 37, 79, 85, 95, 98, 92, 97, 94, 93, 90, 92};
    int jingtou_num;                            //获取镜头的总数量
    int dangwei_num;                        //获取挡位总数量
    int jingtouRow;
    int dangweiRow;
    int  listwidget_type;                       //下拉框的状态，0--->没有下拉框打开。 1--->第一个下拉框打开。以此类推
    int wendang_i;                              //获取界面当前文档的位置
    int compensateValue;


    bool isTempCaptureSwitch;
    bool auto_lcdoff;
    bool auto_poweroff;
    bool unitconverting;
    bool language_changing;
    bool ReferTemp_enable_first;        //第一次进入设置hou ，退出时。发送参考温度
    bool jingtou_dangwei_change;        //镜头和挡位同时发生改变
    bool temp_tab_change;                  //温度单位或者tab发生改变
    bool baojingshezhi_init;
    bool baojingse_init;
    bool usbmode_init;                        // true 表示第一次初始化
    bool recordmode_init;//标志着是不是第一次执行，初始化时执行
    bool jingtou_init;
    bool wendang_init;
    bool jingtou_changing;
    bool autoUpdateIsChecked;       //标识自动上传是否被选中
    bool wifiIsSelect;//标识wifi是否被选中

    /***************************以下为新功能******************************/
    void para_init();
    void changeEvent(QEvent *e);
    void range_lens_copy();             //用来保存上个状态的镜头号和挡位号
    void listwidget_drop_manage_jingtou(bool type);        // 第一个下拉框处理。主要是处理其它图标的使能状态。  true--->表示打开。false--->表示关闭
    void listwidget_drop_manage_wendang(bool type);
    void listwidget_drop_manage_bangjingshehzi(bool type);
    void listwidget_drop_manage_baojingse(bool type);
    void listwidget_drop_manage_usbmode(bool type);
    void listwidget_drop_manage_recordmode(bool type);
    void listwidget_drop_manage_modeSelect(bool type);
    void listwidget_drop_manage_language(bool type);
    void listwidget_drop_manage_poweroff(bool type);
    void listwidget_drop_manage_lcdoff(bool type);
    void listwidget_drop_manage_Radiance(bool type);
    void listwidget_type_manage();                                  //用于切换界面。和一些按钮，根据是否打开listwidget列表进行处理
    void listwidget_drop_manage_focusmode(bool type);
    void listwidget_drop_manage_imageType(bool type);
    void listwidget_drop_manage_reflectTemp(bool type);
};

#endif // HPSETTING_H
