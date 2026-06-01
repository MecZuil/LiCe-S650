#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include  <QWidget>
#include  <QKeyEvent>
#include  <QLabel>
#include  <QAbstractButton>

#include  <QMetaType>
//#include  <stdio.h>
#include  "hppreview.h"
#include  "hpsetting.h"
#include  "hpmode.h"
#include  "hpsebiao.h"
#include  "hpresize.h"
#include  "hpcpumem.h"
#include  "hpdomainthread.h"
#include  "hp_button.h"
//#include  "hphidemenu.h"
#include  "hp_camera_cap.h"
#include  "hp_camera_video.h"
#include  "hppreview.h"
#include  "hp_adjust_cmd.h"
#include  "hp_mode_hzh_adjust.h"
#include  "hp_mode_rdj_adjust.h"
#include  "hp_sd_space_warning.h"

#include  "hp_twice_analysis.h"
#include  "hp_poweroff_dialog.h"
#include  "hp_poweroff_warn.h"
#include  "hp_createpdf.h"
#include  "frminput.h"
#include  "hphide_biaoding.h"
#include  "hphide_dialog.h"
#include  "hphide_laser.h"
#include  "hp_panorama_tips_dialog.h"
#include  "hp_usb_insert.h"
#include  "hp_avi_mode.h"
#include  "hp_isotherm.h"
#include  "hp_twice_pic.h"
#include  "hp_twice_kjg.h"
#include  "hp_wifi_search_dialog.h"
#include  "hp_sis_content.h"
#include  "hp_picture_mode.h"
#include  "hp_wait_warn.h"
#include  "hp_pms.h"
#include  "hp_sort.h"

extern "C"
{
    #include "cJSON.h"
}

#include  "../TaskPkg/hp_statement.h"
#include  "../TaskPkg/hp_taskpkg.h"


#define ToolButtonUP "QToolButton {border-image:url(:/res/res/m_up_arrow_n.png);  color:#7CA6C9;}\
                            QToolButton:pressed{border-image:url(:/res/res/m_up_arrow_s.png);}"
#define ToolButtonUP_2 "QToolButton {border-image:url(:/res/res/m_up_arrow_n_2.png);  color:#7CA6C9;}\
                            QToolButton:pressed{border-image:url(:/res/res/m_up_arrow_s_2.png);}"
#define ToolButtonUP_3 "QToolButton {border-image:url(:/res/res/m_up_arrow_n_3.png);  color:#7CA6C9;}\
                            QToolButton:pressed{border-image:url(:/res/res/m_up_arrow_s_3.png);}"
#define ToolButtonUP_4 "QToolButton {border-image:url(:/res/res/m_up_arrow_n_1.png);  color:#7CA6C9;}\
                            QToolButton:pressed{border-image:url(:/res/res/m_up_arrow_s_1.png);}"
#define ToolButtonDown "QToolButton {border-image:url(:/res/res/m_down_arrow_n.png);  color:#7CA6C9;}\
                            QToolButton:pressed{border-image:url(:/res/res/m_down_arrow_s.png);}"
#define ToolButtonDown_2 "QToolButton {border-image:url(:/res/res/m_down_arrow_n_2.png);  color:#7CA6C9;}\
                            QToolButton:pressed{border-image:url(:/res/res/m_down_arrow_s_2.png);}"
#define ToolButtonDown_3 "QToolButton {border-image:url(:/res/res/m_down_arrow_n_3.png);  color:#7CA6C9;}\
                            QToolButton:pressed{border-image:url(:/res/res/m_down_arrow_s_3.png);}"
#define ToolButtonDown_4 "QToolButton {border-image:url(:/res/res/m_down_arrow_n_1.png);  color:#7CA6C9;}\
                            QToolButton:pressed{border-image:url(:/res/res/m_down_arrow_s_1.png);}"
#define ToolButtonAM  "QToolButton {border-image:url(:/res/res/auto.png);color:#7CA6C9;}\
                            QToolButton:checked{border-image:url(:/res/res/manual.png);}"
#define ToolButtonAM_2  "QToolButton {border-image:url(:/res/res/auto_task_2.png);color:#7CA6C9;}\
                            QToolButton:checked{border-image:url(:/res/res/manual_task_2.png);}"
#define ToolButtonAM_3  "QToolButton {border-image:url(:/res/res/auto_task_3.png);color:#7CA6C9;}\
                            QToolButton:checked{border-image:url(:/res/res/manual_task_3.png);}"
#define ToolButtonAM_4  "QToolButton {border-image:url(:/res/res/auto_task_4.png);color:#7CA6C9;}\
                            QToolButton:checked{border-image:url(:/res/res/manual_task_4.png);}"
namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

    Ui::MainWidget *ui;
    HpDomainThread *hpdomainthread;
    HpDomainThread *sd_hpdomain;

    Hp_Twice_Analysis *hta;
    HpPreview *hppreview;
    HpSebiao hpsebiao;

    Hp_Camera_Cap *hpcameracap;
    hp_picture_mode *pictureModeObject;
    Hp_Dialog * hp_dialog;
    Hp_Wifi_search_Dialog *hp_Wifi_search_Dialog;
    Hp_Panorama * hp_panorama;
    HP_USB_insert hp_usb_insert;
    Hp_Sd_Space_Warning *hssw;
    HpResize hpresize;
    Hp_wait_warn hp_wait_w;
    hp_pms *hp_Pms;

    int Task_win;//表述处于Task(台账)的状态的什么界面  0表示不处于Task状态,1:处于任务界面 2：处于设备树界面 3：处于是否还原上一次设置界面 4：显示SD卡提示界面 5:显示统计界面
    HpSetting hpsetting;
    int autocretify_time;
    int autocretify_settime;//设置按键下的自动调焦计时
    int autocretify_pretime;//预览按键下的自动调焦计时
    Hp_Panorama_Tips_Dialog panorama_dialog;
    bool m_panorama_cap;
    bool panorama_quit;
    QStringList main_task_name;
    QStringList main_task_id;
    QStringList sub_task_name;
    QStringList sub_task_id;
    QStringList clearance_name;
    QStringList clearance_id;
    QStringList clearance_sn;
    QStringList test_point_name;
    QStringList test_point_id;
    bool isBlePowerOn;
    bool m_hirRecordStarted;
    bool m_isAutoReflect;
    bool consercutiveLaser;
    bool laserAdjust;
    bool get_headset_status();
    bool preview_open;    //预览界面是否打开
    bool twice_analysis_cut_pic;            //是否是二次分析切换图片
    bool isTwiceChangeOver;
    bool pic_swich_save;                    //左右切换图片是否保存的标志

    bool onlcdonce;//揭示是否是在息屏刚唤醒时，因为每次事件都会被触发两次，所以要有这个变量来限制

    bool twice_analysis_start;          //标准着开始二次分析
    bool Twice_analysis;
    bool main_auto_focus;              //主界面自动调焦的状态
    bool isHotKeyBle;
    KEYSETTING m_hotKey1;
    KEYSETTING m_hotKey0;
    bool isHcf;
    bool IsInlcdoff;                    //是否处于自动关屏状态
    bool autoupload_once;               //是否处于一键上传状态
    bool hir_analyse;              //用于标识是否开始HIR灰度视频开始二次分析模式
    bool fidpid;                    //用于标识是否开启fidpid
    bool define_S6X0_S3X0;//相当于宏定义HP_640_pro
//    bool define_laser;//相当于宏定义LASER_RANGING
    bool define_brightmode;//相当于宏定义FOCUS_MODE
    bool isLasertype;//标志着sys.xml文件中laserdev_type字段的值是否大于1，若大于1，则激光测距时不需要 devtest 3 0
    bool getRangeOnce;
    bool define_sis;//就代表宏定义中的SIS_MODE
    bool qrcode;     //扫一扫开关的状态 默认false  true的时候 禁用视频按钮 和视频切换键
    int  temp_mode;   //临时保存当前模式的变量
    bool OutsisToTask;//外部扫一扫指令进入台账
    HpSort * hp_sorts;
    int m_laserType;
    QString StrOutsisToTask;//文本
    Hp_FormatDialog formatDialog;//检测视频是否错误，需要删除
    QString m_latestVideoName;

    QFileInfoList file_list;
    int autoupload_num;
    ftp_para autoupload_para;
    enum_AutoUpload_mode upload_mode;//自动上传模式
    void slot_set_define_Init(bool val);//初始化从配置文件读取内容
    void hp_setDefine_S3x0(bool isSelect);
    void hp_setDefine_Szoom(bool souldzoom);
    void hp_setDefine_brightmode(bool isSelect);
    QString all_replace_delete_Tab(QString str);//删除tab
    QString all_replace_covert_char(QString s_text);

signals:
    void signal_set_twice_change_over();
    void signal_core_fpga_get_ver();
    void signal_Set_autoUpload_close();//WIFI查找返回时触发
    void signal_Set_WIFIsearch_Dialog_close();
    void signal_close_poweroff_warn(); //充电的时候 如果这个电量过低的窗口是开的 就发送信号把他关了
    void signal_pc_image_set_mode(int nVideoMode);
    void signal_pc_image_set_colorruler(int colorid);
    void signal_pc_image_set_fusion(FusionPara para);
    void signal_pc_image_set_pip(PipPara para);
    void signal_pc_image_get_manual();
    void signal_pc_image_set_manual(ComManualPara para);
    void signal_pc_osd_set_osdstat(OsdSetting para);
    void signal_pc_key_auto_rectify();
    void signal_pc_key_set_freeze(int freeze);
    void signal_core_key_capture_start(int flag);
    void signal_core_key_panorama_stop(int flag);
    void signal_core_key_panorama_cap(int flag);//用于保存普通照片；
    void signal_core_get_sd_info();//向SD卡获取容量信息
    void signal_core_key_record_avi_mode_start();
    void signal_core_key_record_hir_mode_start();
    void signal_core_key_record_avi_start();    //之前用到了，现在没用。开始信号在hp_avi_mode界面进行发送
    void signal_core_key_record_avi_stop();
    void signal_core_key_record_hir_start();    //先定义好，没用到
    void signal_core_key_record_hir_stop();

    void signal_core_analysis_pic_twice_stop();

    void signal_core_corectrl_start_encode();
    void signal_core_corectrl_stop_encode();
    void signal_pc_measure_move_display(ti_pos pos);

    void signal_core_get_sdinsert();
    void signal_core_get_battery();
    void signal_core_get_battery_charge();
    void signal_core_get_usbwifiinsert();
    void signal_core_get_usbinsert();

    void signal_pc_sys_set_lcd_bright(int bright);

    void signal_twice_voiceStop();
    void signal_twice_voicep_Stop();
    void signal_show_auto_save(int);
    //biaoding
    void signal_biaoding_ceshi( );
    void signal_pc_send_biaoding();         //信号发送给内核。 槽中实现信号的传送

    void siganl_image_set_gas_para(GasPara gasPara);
    void signal_hphide_biaoding_zn(int zn_value);   //发送信号给标定界面显示zn的值
    void signal_mainwidget_tiaoling( );
                                                                                                //快捷键,发送 坏点
    void signal_dandian_sidian();
    void signal_gaowen_sidian();
    void signal_diwen_sidian();

    void signal_del_badpixel_up(int timers);                              //向上面移动
    void signal_del_badpixel_point(int direction );                                      //点的移动 1234  上下左右
    void signal_del_badpixel_rect(int direction );
//hidemenu
     void signal_pc_hidemenu_get_para();       //开机向内核索要信息
//preview
    void signal_twice_lastpage();
    void signal_twice_nextpage();
    void signal_twice_pic_start();

    void signal_pc_key_auto_focus();
    void signal_pc_key_focus_near();
    void signal_pc_key_focus_far();
    void signal_pc_key_focus_stop();
    void signal_pc_key_focus_adjust(int flag);

    void signal_sd_put_out_cap(); //send to cannal sinnal;
    void signal_pc_sys_get_laserrange();
    void signal_pc_sys_set_laserrange();
    void signal_pc_sys_set_screen_sleep(int power);
    void signal_pc_sys_set_laser_power(int power);
    void signal_pc_key_laser(int index);
    void signal_pc_image_set_abnormal(int isSet);
    void signal_pc_sys_get_appcontrolstatus(); //app控制界面状态
    void signal_pc_measure_get_point(int index);
    void signal_pc_measure_get_line(int index);
    void signal_pc_measure_get_rect(int index);
    void signal_pc_measure_get_circle(int index);
    void signal_pc_focus_offset(int index);
     void signal_biaoding_focus_offset(int index);

    void singal_pc_cfg_get_pointconfig();
    void singal_pc_cfg_get_lineconfig();
    void singal_pc_cfg_get_rectconfig();
    void singal_pc_cfg_get_circleconfig();

    /* 停止任务包相关重绘事件 */
    //void siganl_stop_task();

    void singal_pc_sys_set_laserpos(int value);
    void signal_core_key_capture_stop(int para);
    void signal_pc_cmd_set_pc_pic(ftp_para para);
    void signal_pc_cmd_set_pc_pic_srv(char *photoname);//server模式
    void signal_pc_set_upload_break(int status);//取消上传
    void signal_core_annlysis_hir_twice_suspend(int type);
    void signal_hir_twice_get_zoom();
    void signal_hir_twice_get_colorrule();
    void signal_hir_twice_lockstatus(int value);//1解锁 0加锁
    void signal_set_HDMI(int index);
    void signal_pc_sys_set_ble_power(int value);
    void signal_pc_sys_set_ble_module(int value);
    void signal_pc_sys_set_analog_video(int value);
    void signal_pc_measure_tempcenter(int index);
    void signal_set_qrcode_switch(int index);
    void signal_get_qrcode_info();
    void signal_set_sis_label(unsigned char *data);
    void signal_pc_sys_set_panorama_stop(int para);
    void signal_sort_add_new_file(QString name);
    void signal_pc_sys_set_panorama_start(int flag);
    void signal_pc_sys_get_matching_degree(int flag);
    void signal_pc_sys_get_positiion_data();
    void signal_pc_get_measure_get_temp();
    void signal_measure_reflect_temp(int value);
    void signal_core_get_rotation_type();
    void signal_set_current_lens(int len);
public slots:
    void slot_set_twice_change_over();
    void slot_noncool_unenable_plr(bool isAimTemp);
    void slot_tagTempAlarm_timeout();
    void slot_get_tagRectTemp_timeout();
    void slot_set_show_avgTemp(bool isShow);
    void slot_set_auto_reflect(bool isShow);
    void slot_pc_get_measure_get_temp(unsigned char return_value,RectTemp temp);
    void slot_show_4G_pixel(int para);
    void slot_show_gps_pixel(int para);
    void slot_timer_get_compass_data();
    void slot_pc_sys_get_positiion_data(unsigned char return_value, int value);
    void slot_timer_get_rotation_switch(int index);
    void slot_set_compass_trans(int index);
    void slot_timer_get_rotation_type();
    void slot_core_get_rodation_type(unsigned char return_value, int ti);
    void slot_timer_get_positiion_switch(int para);
    void SlotSetImageSR(bool state);
    void on_point_clicked(HP_BUTTON_STATUS status);
    void on_line_clicked(HP_BUTTON_STATUS status);
    void on_rect_clicked(HP_BUTTON_STATUS status);
    void on_circle_clicked(HP_BUTTON_STATUS status);
    void on_polygon_clicked(HP_BUTTON_STATUS status);
    void on_preview_clicked(HP_BUTTON_STATUS status);
    void on_clean_clicked(HP_BUTTON_STATUS status);
    void on_sebiao_clicked(HP_BUTTON_STATUS status);
    void on_bright_mode_clicked(HP_BUTTON_STATUS status);
    void on_mode_clicked(HP_BUTTON_STATUS status);
    void on_resize_clicked(HP_BUTTON_STATUS status);
    void on_setting_clicked(HP_BUTTON_STATUS status);
    void slot_sebiao_set_reverse(bool isReverse);
    void sebiao_groupbutton(QAbstractButton* bt,bool checked);//原on_sebiao_groupbutton(QAbstractButton*,bool)
    void mode_groupButton(QAbstractButton* bt,bool checked);//原on_mode_groupButton(QAbstractButton*,bool)
    void pip_groupButton(QAbstractButton* bt,bool checked);//原on_pip_groupButton(QAbstractButton*,bool)

    void mode_hzh_adjust_release();//原on_mode_hzh_adjust_release()
    void mode_rdj_adjust_release();//原on_mode_rdj_adjust_release()
    void slot_task_start();
    void set_audio(bool flag, int type);
    void slot_cap_camera_panorama();
    void slot_cap_camera_stop();
    void slot_check_panorama_photo(bool isShot);
    void slot_open_panorama(bool isOpen);
    void slot_start_panorama();
    void slot_pc_sys_set_panorama_stop(unsigned char isSave, QString name);
    void slot_panorama_set_unsave(QString name);
    void slot_close_panorama(bool setPanoramaStop);
    void mode_handfution_clicked(bool checked);//原on_mode_handfution_clicked(bool)

    void avi_record_get_SDInfoTimeOut();
    void kjgToAutoRecirftTimeOut();
    void settingToAutoRecirftTimeOut();
    void previewToAutoRecirftTimeOut();
    void autoUpdateGetStatusTimeOut();
    void autoUpdateClose();
    void previewShow();
    void setDisplayMove(bool isMove);
    void slot_pc_cfg_get_pointconfig(unsigned char return_value, int apppoint);
    void slot_pc_cfg_get_lineconfig(unsigned char return_value,int appline);
    void slot_pc_cfg_get_rectconfig(unsigned char return_value,int apprect);
    void slot_pc_cfg_get_circleconfig(unsigned char return_value,  int  appcircle);
    void slot_update_lcdoff_time(bool iskey);
    void slot_set_IsInlcdoff(bool value);
    void slot_pc_sys_get_appcontrolstatus(unsigned char return_value, int value);
    void slot_pc_image_set_mode(unsigned char return_value);
    void slot_pc_image_set_colorruler(unsigned char return_value);

    void slot_pc_image_set_fusion(unsigned char return_value);
    void slot_pc_image_set_pip(unsigned char return_value);

    void slot_pc_image_get_manual(unsigned char return_value,ComManualPara para);
    void slot_pc_image_set_manual(unsigned char return_value);

    void slot_pc_key_zoom(unsigned char return_value);
    void slot_pc_key_auto_rectify(unsigned char return_value);

    void slot_pc_key_set_freeze(unsigned char return_value);

    void slot_core_key_record_avi_start(unsigned char return_value);
    void slot_core_key_record_avi_stop(unsigned char return_value);

    void slot_core_analysis_pic_twice_start(unsigned char return_value);
    void slot_core_analysis_pic_twice_stop(unsigned char return_value);

    void slot_core_corectrl_start_encode(unsigned char return_value);
    void slot_core_corectrl_stop_encode(unsigned char return_value);

    void slot_core_get_usbinsert(unsigned char return_value,int ui);
    void slot_core_get_sdinsert(unsigned char return_value,int si);
    void slot_core_get_sd_info(unsigned char return_value,sdinfo_t sdinfo);
    void slot_core_get_battery(unsigned char return_value,int battery_value);

    void slot_core_get_battery_charge(unsigned char return_value,int charge);
    void slot_core_get_usbwifiinsert(unsigned char return_value,int uwi);

    void slot_pc_sys_set_lcd_bright(unsigned char return_value);

    void timer_3s_func(void);

    void preview_finish(void);
    void slot_set_main_analog_audio();
    void mode_hzh_adjust_finish();
    void mode_rdj_adjust_finish();

    void slot_hpsetting_wifi(bool checked);
    void slot_hpsetting_eth(bool checked);
    void slot_hpsetting_ble(bool checked);
    void slot_wifi_eth_close(int power);
    void slot_hpblesearch_headset(bool f);
    void slot_hphidemenu_printscreen(bool checked);

    void slot_pic_twice_begin();                                              //图片二次分析开始信号。传给主界面左右移动按钮。
    void slot_pic_twice_type(int last_state, int next_state);
    void  slot_biaoding_ceshi_2();

    //槽获取内核传来的标定 的 ZN的状态
    void slot_pc_send_biaoding();
    void slot_core_biaoding_zn(int para);
    void slot_get_biaoding();
    void slot_all_tiaoling_2();     //主线程那个。槽。暂时在这里实现

    void slot_set_usbmode(int index);         //USB插入模式。用来判断 USB选择哪种模式
    void slot_setting_close();
    void slot_avi_hir_mode(int mode);

    void slot_pc_key_auto_focus(unsigned char return_value);
    void slot_timeout_close_laserRange();
    void slot_timeout_pc_key_auto_focus();
    void slot_sd_format_start();
    void slot_sd_format_end(unsigned char return_value);
    void slot_key_auto_start();
    void slot_key_auto_end(unsigned char return_value);

    void slot_set_resize_nZoomRate10_value(int nZoomRate10);      //设置resize放大倍数
    void slot_set_nProcessType_value(int nProcessType, int nMaxTempHand100,int nMinTempHand100);

    void slot_mainset_lcd_offed_state();
    void slot_set_twice_hzh_adjust(int x, int y,  int w,  int h);
    void slot_language_changed_end();
    void slot_tempunit_value_changed(int temp_unit);

    void slot_lable_focus_state(bool state);
    void SlotUsbPreview();
    void slt_pc_sys_get_laserrange(unsigned char return_value, int value);
    void slot_pc_key_laser(unsigned char value);
    void slot_close_laser_widget();
    void slot_close_auto_save();
    void slot_set_twice_text(bool state,QString text);
    void set_twice_text_about_preview();
    void slot_to_set_twice_text(QString text);
    void slot_twice_text_show_or_not(int pic_video);
    void slot_SetMainWifiDisconnect();
    void slot_SetMainCameraCapDialog(QString str,int ret);//1表示成功，-1表示失败
    /*  台账  */
    /* 8. 信号 通知作业包已关闭 */
    void slot_CloseDlg();
    /* 9. 信号 通知轮廓文件及分析底线框 */
    void slot_ChangeAnaInfo(QString bmp, QVector<ANA_OUTLINE> ana_infos);
    /* 10. 信号 显示作业包选择界面 */
    void slot_Show_TaskSelect();
    /* 11. 信号 显示设备拍摄界面 */
    void slot_Show_TreeView();
    /* 12. 信号 显示拍摄恢复提示界面 */
    void slot_Show_MessageBox();
    /* 13. 信号 显示SD卡提示界面 */
    void slot_Show_MessageDialog();
    /* 14. 信号 显示统计折线界面 */
    void slot_Show_AnalysisChart();
    /* 获取节点信息*/
    void slot_read_img_process(int index);
    void slot_get_select_xml(QString str);
    void slot_close_pms();
    void slot_take_picture();
    void slot_open_mode();

    void slot_core_annlysis_hir_twice_start(unsigned char return_value);
    void slot_core_annlysis_hir_twice_suspend(unsigned char return_value);
    void slot_core_annlysis_hir_twice_stop(unsigned char return_value);

    void slot_hidemenu_laser(bool checked);

    void slot_pc_sys_set_laserpos(unsigned char return_value);

    void slot_cameracap_panorama_errmsg(unsigned char return_value);
    void slot_StartAutoUpload_once(bool isTask);
    void slot_pc_cmd_set_pc_pic(unsigned char return_value);
    void slot_OnAutoUpload_once();
    void slot_pc_set_upload_break(unsigned char return_value);
    void slot_start_hir_analyse(QString filename,bool checked);
    void slot_stop_hir_analyse();
    void slot_hir_twice_get_zoom(unsigned char return_value, int value);
    void slot_hir_twice_get_colorrule(unsigned char return_value, int value);
    void slot_hir_twice_lockstatus(unsigned char return_value);
    void slot_hir_analyse_get_measure();
    void slot_hir_analyse_clear_measure();
    void slot_hphide_biaoding_zn(int para);
    void slot_hir_analyse_point_stop(int index,bool stop);
    void slot_hir_analyse_line_stop(int index,bool stop);
    void slot_hir_analyse_rect_stop(int index,bool stop);
    void slot_pc_measure_tempcenter(unsigned char return_value);
    void slot_pc_sys_set_analog_video(unsigned char return_value);
    void slot_show_auto_save();
    void slot_pc_sys_set_capturetime(int para);
    void slot_core_key_capture_start(unsigned char return_value);
    void slot_core_key_panorama_cap(unsigned char return_value);
    void slot_set_qrcode_state(bool checked);
    void slot_pc_sys_set_qrcode_switch(unsigned char return_value);
    void slot_pc_sys_get_qrcode_info(unsigned char return_value ,unsigned char *data);
    void slot_ok_or_cannal_sis_swicth(int num,QString text);
    void slot_close_sis_mode(bool checkd);
    void slot_timer_500ms(void);
    void slot_stop_AviMode(bool checked);
    void slot_should_make_pms_json(QString real_file);
    void slot_event_start_get_capture();
    void slot_pms_select_changed(int index);
    void slot_pms_key_release(QKeyEvent *ev);
    void slot_pc_measure_temprange_query(unsigned char return_value,int data);
    void slot_delete_new_video();
    void modifyXmlFilename(const QString& filePath, const QString& newFilename, QString pmsFilePath);
    void slot_upload_pms_dat();
    void removeTestPointByFilename(QDomElement &parent, const QString &targetFilename);
    int removeEmptyClearance(QDomElement &parent);
    void slot_set_image_format(int imageFormat);
    void setInsulation(bool isInsulation);
    void slot_show_insulation_warning(bool isShow, int id, int x, int y);
    void show_lens_info();
    void slot_timerout_jingtou_change();
    void slot_double_clicked_focus();
    void slot_transmission_send_upload_success();
    void slot_set_focus();
    void slot_set_preset_mode(int presetMode);
    void slot_stop_focus_aut(bool checked);
private slots:
    void on_toolButton_AM_clicked(bool checked);
    void on_toolButton_min_clicked(bool checked);
    void on_toolButton_max_clicked(bool checked);
    void on_toolButton_up_released();
    void on_toolButton_down_released();
    void slot_timer_task();
    void on_pushButton_confirm_clicked();
    void slot_signal_sketch_switch(int index);
    void slot_language_changed(int index);
    void on_last_page_released();
    void on_next_page_released();
    void on_focus_near_pressed();
    void on_focus_near_released();
    void on_focus_far_pressed();
    void on_focus_far_released();
    void SlotContinuedFreezeTimer();
    void SlotAutoSave(int SaveValue);
    void sltPCKeyLaser();
    void getLaserRangeOnce();
    void toolButton_pause_Clicked(bool click);//原on_toolButton_pause_Clicked(bool)
    void slot_wait_warn_save();
    void slot_wait_warn();
    void slot_temp_row_mode(int mode);
    void slot_un_freeze();
    void slot_hotkey_set_key_focus(KEYSETTING hotkey);
    void slot_hotkey_set_key_camera(KEYSETTING hotkey);
    void on_checkBox_polygon_clicked(bool checked);

private:
    void KJGModeLimit();
    void KJGModeRelieveLimit();
    void ModeAMLimit(bool checked);
    void ColorAMLimit(bool checked);
    void ReciseAMLimit(bool checked);
    void PreviewIconLimit(HP_BUTTON_STATUS status);
    void delaymsec(int msec);
    void initLaser();

private:
    hphide_laser hphidelaser;
    HpXmlReader hpxmlreader;

    QTimer *get_tagRectTemp;//定时获取全图的温度，根据当前挡位进行自动换挡
    QTimer *tagTempAlarm;
    QTimer *timer_jingtou;
    HpMode hpmode;
    HpCpuMem hpcpumem;
    Hp_Camera_Video hpcameravideo;
    Hp_Adjust_Cmd hpadjustcmd;

    Hp_Mode_Hzh_Adjust hpmodehzhadjust;
    Hp_Mode_Rdj_Adjust hpmoderdjadjust;

    Hp_Media_Player hmp;

    Hp_PowerOff_Dialog hpd;
    HP_Poweroff_Warn hp_power_w;

    HP_Avi_mode hp_avimode;
    HP_Twice_Pic hp_twice_pic;
    Hp_Twice_kjg hp_twice_kjg;
    Hp_Dialog *SDFormatDialog;
    hp_sis_content *hpsis_content;
    Hp_CreatePDF *hp_createPdf;

    void update_main_show(MAIN_SHOW main_show);
    int m_lensCount;
    int m_currLens;
    int video_mode,bak_video_mode;
    int video_sebiao,bak_video_sebiao;
    bool sebiaoReverse;
    int video_mode_hp;

    bool rot_type_state; //获取当前仪器选转方向状态
    bool m_pmsWidgetOpenFlag;
    bool m_pmsUploadFlag;
    bool m_isInitBiaoding;
    bool m_isAimTemp;
    bool main_task_open;            //为真表示打开了sebiao mode 等图标
    bool m_isPanorama;
    bool m_isShowAvg;
    bool compass_state; //获取指南针方位状态
//lcy--2018.1.17
    int twice_analysis_state;   //  1->star. 0->end.
    int usb_mode;                   //0->视频传输。1->大容量存储
    int m_laserRange;
    int wifi_insert_first;              //第一次插入wifi模块。 0--->初始状态。 1--->非初始状态
    double ReferTemp;  // temporarily save the compensation temperature

    int trans_num;
    int m_laserRangeTimer;
    int m_imageFormat;
    QTimer *timer_10s;
    QTimer *timer_5min;
    QTimer timer_3s;
    QTimer timer_task;
    QTimer timer_compass;
    QTimer* ContinuedFreezeTimer;
    QTimer *avi_record_get_SDInfo;//录像时，实时检测容量
    QTimer *kjgToAutoRecirft;//可见光定时器，处于可见光模式下，若久了，就自动打挡片
    QTimer *settingToAutoRecirft;//设置定时器，处于设置模式下，若久了，就自动打挡片
    QTimer *previewToAutoRecirft;//预览定时器，处于预览模式下，若久了，就自动打挡片
    QTimer *AutoUpdateGetStatus;//一键上传定时器
    QTimer *timerConsercutiveLaser;//一键上传定时器
    QTimer timer_500ms;
    QTimer timer_get_rotation_type;
    QTimer timerGetBiaodingPara;;

    QString fError;//翻译 “错误”；
    QString fErrReInsert;
    QString fSDHasNoSpace;
    QString fNoSD;
    QString fkjgNotQuit;
    QString fHSENotQuit;
    QString fautoStopVideo;
    QString fNoTaskpic;
    QString fSisIsNotOpen;
    QString fvideoError;

    QList<double> laserParaX;
    QList<double> laserParaY;
    QList<double> laserParaX_IR;
    QList<double> laserParaY_IR;
    bool start_capture;
    bool start_record;   //视频模块运行
    bool headset_status;
    bool con_flag;

    bool hidemenu_laser;
    QLabel *text_pic;
    QLabel *text_video;

   // HP_BUTTON_STATUS preview_tmp_s;

    bool laser_on;
    bool adjust_cmd_show_flag;

    bool ble_status;
    bool wifi_status;

    PipPara pippara;
    PipPara pippara_bak;                    //画中画参数.退出预览的时候的参数
    FusionPara fusionpara;          //热叠加参数

    ComManualPara manualpara;
      OsdSetting osdsetting1;
      hp_Isotherm  hpisotherm;

    bool auto_manual_flag;
    bool min_handle_flag;
    int min_value100;
    bool max_handle_flag;
    int max_value100;

    void auto_manual_init();
    void auto_manual_update();
    bool main_task_ble;
    bool main_task_sd;
    bool main_task_wifi;
    bool main_task_headset;
    bool main_task_usb;
    bool usb_uart_insert;
    bool main_task_eth;
    bool main_task_battery_charge;
    bool main_task_wifi_insert;

    bool sd_space_enough;


    QTranslator translator;
    void changeEvent(QEvent *e);

    int get_sd_count;
    int autoSaveShowTimer;

    bool printscreen_checked;
    int avi_hir_mode;       //1表示avi模式已经开启。 2表示hir 模式已经开启。 0表示没有任何模式
//快捷键;
    bool ctrl_ok;
    bool alt_ok;
    int isShowAlarm;
    bool mode_kjg;      //记录mode是否是可见光模式
    bool last_botton_state;          //mode是可见光模式时， 记录二次分析左右移动按钮的状态
    bool next_botton_state;
    bool setting_open_state;        //进入设置界面状态
    bool battery_warn;                  //电池电量提醒
    bool laser_init;

    HP_BUTTON_STATUS resize_state;                  //记录放大按钮图标的状态
    HP_BUTTON_STATUS focus_state;                  //记录电机按钮图标状态
    bool sd_format;
    bool auto_state;                                            //记录调零状态。为真表示正在调零
    bool isAutoSave;
    bool isUSBPreviewLimit;
    bool appcon_state;

    bool preview_state;
    bool twice_text_state;
    bool text_label_show;//标识注释是否被显示

    bool m_keyORelease;
    bool wait_warn;//非国网模式
    bool wait_warn_state;//非国网模式
    QElapsedTimer m_testHirTime;
    QMap<QString, QMap<QString, QList<QString>>> m_clearancePointFilenameMap;
    QMap<QString, QMap<QString, QList<QString>>> m_errClearancePointFilenameMap;
protected:
    bool eventFilter(QObject *o, QEvent *e);

    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void keyReleaseEvent(QKeyEvent *ev);

    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void mouseMoveEvent(QMouseEvent *ev);

};

#endif // MAINWIDGET_H
