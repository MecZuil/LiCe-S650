#ifndef HPDOMAINTHREAD_H
#define HPDOMAINTHREAD_H

#include  <QThread>
#include  <QDebug>
#include  <QTextCodec>
#include  "hi384_protocol.h"
#include  "hpdomainapi.h"
#include  "hpprotocolpkg.h"


class HpDomainThread : public QThread
{
    Q_OBJECT
public:
    explicit HpDomainThread(QObject *parent = 0);

    QString domainName;
    bool isGetBiaoDingPara;
    void setDomainName(const QString& str);
    void startDomain();
    void stopDomain();


protected:
    void run();

signals:
    void signal_core_get_upload_status(unsigned char return_value,int upload_status);
    void signal_pc_set_upload_break(unsigned char return_value);
    void signal_pc_sys_set_upload_target(unsigned char return_value);
    void signal_pc_cmd_set_pc_pic(unsigned char return_value);
    void signal_pc_cmd_set_pc_pic_srv(unsigned char return_value);
    void signal_pc_cfg_get_deviceinfo(unsigned char return_value,ComDeviceInfo msg);
    void signal_pc_cfg_get_sysconfig(unsigned char return_value,ComDeviceInfo msg);//reserve

    void signal_PC_SYS_GET_ESSID(unsigned char return_value,QString name);
    void signal_PC_SYS_SET_WIFI_STA(unsigned char return_value);
    void signal_CORE_GET_WIFI_STA_STATUS(unsigned char return_value,int wifi_sta_status);
    void signal_pc_sys_set_dev_active_search(unsigned char return_value, QStringList info);
    void signal_pc_sys_set_dev_client(unsigned char return_value);

    void singal_pc_cfg_get_pointconfig(unsigned char return_value,int  apppoint);
    void singal_pc_cfg_get_lineconfig(unsigned char return_value,int appline);
    void singal_pc_cfg_get_rectconfig(unsigned char return_value,int apprect);
    void singal_pc_cfg_get_circleconfig(unsigned char return_value,int appcircle);
    void signal_pc_sys_get_standard(unsigned char return_value,StandardInfo msg);
    void signal_pc_sys_get_hidemenu(unsigned char return_value,ComHideMenuPara para);

    void signal_pc_sys_get_bn(unsigned char return_value,int bn);
    void signal_pc_sys_get_focus(unsigned char return_value,int bn);

    void signal_pc_sys_set_language(unsigned char return_value);
    void signal_pc_sys_set_default(unsigned char return_value);
    void signal_pc_sys_set_hidemenu(unsigned char return_value);
    void signal_pc_sys_set_capturetime(unsigned char return_value);
    void signal_pc_sys_set_autorectify(unsigned char return_value);
    void signal_pc_sys_set_time_sec(unsigned char return_value);
    void signal_pc_sys_set_format(unsigned char return_value);
    void signal_pc_sys_set_usbmode(unsigned char return_value);
    void signal_pc_sys_set_wifi_switch(unsigned char return_value);
    void signal_pc_sys_set_ETH_switch(unsigned char return_value);
    void signal_pc_sys_set_lcd_bright(unsigned char return_value);
    void signal_pc_sys_set_handfusion(unsigned char return_value);

    void signal_pc_sys_fusion_adjust(unsigned char return_value);
    void signal_pc_sys_set_panorama_stop(unsigned char return_value, QString name);
    void signal_pc_cfg_set_temp_userpara(unsigned char return_value);

    void signal_pc_measure_active(unsigned char return_value);
    void signal_pc_measure_clear(unsigned char return_value);

    void signal_pc_key_auto_focus(unsigned char return_value);

    void signal_pc_measure_set_reference(unsigned char return_value);
    void signal_pc_measure_set_tempunit(unsigned char return_value);
    void signal_pc_measure_set_temprange(unsigned char return_value);

    void signal_pc_measure_set_point_add(unsigned char return_value);
    void signal_pc_measure_set_point_update(unsigned char return_value);
    void signal_pc_measure_set_point_del(unsigned char return_value);

    void signal_pc_measure_set_line_add(unsigned char return_value);
    void signal_pc_measure_set_line_update(unsigned char return_value);
    void signal_pc_measure_set_line_del(unsigned char return_value);

    void signal_pc_measure_set_rect_add(unsigned char return_value);
    void signal_pc_measure_set_rect_update(unsigned char return_value);
    void signal_pc_measure_set_rect_del(unsigned char return_value);

    void signal_pc_measure_get_point(unsigned char return_value,ComPointPara point);
    void signal_pc_measure_get_line(unsigned char return_value,ComLinePara line);
    void signal_pc_measure_get_rect(unsigned char return_value,ComRectPara rect);
    void signal_pc_measure_get_circle(unsigned char return_value,ComCirclePara circle);
    void signal_pc_get_measure_get_temp(unsigned char return_value,RectTemp temp);
    void signal_pc_image_set_mode(unsigned char return_value);
    void signal_pc_image_set_colorruler(unsigned char return_value);
    void signal_pc_image_set_alarm(unsigned char return_value);
    void signal_pc_image_set_manual(unsigned char return_value);
    void signal_pc_image_set_fusion(unsigned char return_value);
    void signal_pc_image_set_pip(unsigned char return_value);
    void signal_pc_image_set_gps(unsigned char return_value);
    void signal_pc_image_get_manual(unsigned char return_value,ComManualPara para);


    void signal_pc_key_zoom(unsigned char return_value);
    void signal_pc_key_auto_rectify(unsigned char return_value);

    void signal_pc_key_set_freeze(unsigned char return_value);


    void signal_core_key_record_avi_start(unsigned char return_value);
    void signal_core_key_record_avi_stop(unsigned char return_value);

    void signal_core_key_capture_start(unsigned char return_value);
    void signal_core_key_add_audio_start(unsigned char return_value);
    void signal_core_key_add_audio_stop(unsigned char return_value);
    void signal_core_key_add_audio_stop(unsigned char return_value, int length);
    void signal_core_key_add_text(unsigned char return_value);
    void signal_core_key_capture_stop(unsigned char return_value,QString name);

    void signal_core_annlysis_pic_twice_start(unsigned char return_value);
    void signal_core_annlysis_pic_twice_stop(unsigned char return_value);

    void signal_core_analysis_hir_twice_start(unsigned char return_value);
    void signal_core_annlysis_hir_twice_suspend(unsigned char return_value);
    void signal_core_analysis_hir_twice_stop_cut(unsigned char return_value);
    void signal_core_get_twice_audio_status(unsigned char return_value, int status);
    void signal_core_analysis_pic_twice_audioplay_start(unsigned char return_value);
    void signal_core_analysis_pic_twice_audioplay_stop(unsigned char return_value);
    void signal_core_analysis_pic_twice_audiocap_start(unsigned char return_value);
    void signal_core_analysis_pic_twice_audiocap_stop(unsigned char return_value);
    void signal_core_ctrlcore_start_encode(unsigned char return_value);
    void signal_core_ctrlcore_stop_encode(unsigned char return_value);

    void signal_core_get_sd_info(unsigned char return_value,sdinfo_t sdinfo);
    void signal_core_get_battery(unsigned char return_value,int battery_value);
    void signal_core_get_charge(unsigned char return_value,int charge);
    void signal_core_get_usbwifiinsert(unsigned char return_value,int uwi);
    void signal_core_get_usbinsert(unsigned char return_value,int ui);
    void signal_core_get_sdinsert(unsigned char return_value,int si);
    void signal_core_get_rotation_type(unsigned char return_value,int ti);

    //biaoding
    void signal_core_biaoding_zn(int  zn_value);
    void signal_core_biaoding_canshu(FPGAMenuPara data);                                  //信号，传递标定参数   给界面 core 表示内核传递过来
    void signal_core_biaoding_gray(FPGAMenuGray data);
        void signal_pc_focus_offset(unsigned char return_value);
    //hidemenu   para_21  para_23
//    void signal_core_hidemenu_get_para(unsigned char *data);
    void signal_core_hidemenu_get_para(ComHideMenuPara data);

    void signal_key_auto_start( );
    void signal_dev_get_parameter(unsigned char *data,unsigned char return_value);
    void signal_pc_measure_tempcapture(unsigned char return_value);
    void signal_pc_measure_set_compensate(unsigned char return_value);
    void signal_pc_measure_tempcenter(unsigned char return_value);

    void signal_pc_sys_get_laserrange(unsigned char return_value, int value);
    void signal_pc_key_laser(unsigned char return_value);
    void signal_pc_image_set_abnormal(unsigned char return_value);
    void signal_pc_image_set_Isotemp(unsigned char return_value);
    void signal_pc_sys_get_appcontrolstatus(unsigned char return_value, int value);

    void signal_set_core_fpgamenu_badline_x(unsigned char return_value);
    void signal_set_core_fpgamenu_badline_y(unsigned char return_value);

    void singal_pc_sys_set_laserpos(unsigned char return_value);
    void signal_hir_twice_get_zoom(unsigned char return_value, int value);
    void signal_hir_twice_get_colorrule(unsigned char return_value, int value);
    void signal_hir_twice_lockstatus(unsigned char return_value);

    void signal_pc_sys_set_filequery(unsigned char return_value,QString name,char *data,int returnlen);
    void signal_set_4G_state(unsigned char return_value);
    void signal_get_4G_state(unsigned char return_value,int status);
    //为什么这里既要传输地址又要传输字符串呢？，传输地址(data)是因为当内容大于1024时可以让接收的地方释放内存，传输字符串(name)是因为可能是接收的内容太快，
    //导致buf内的内容未读取完毕，就已经被下一条内容覆盖了，导致内容转化失败，所有这里就两个都要传,通过观察，在这个函数执行之前数据是完整的，因为线程
    void signal_pc_sys_set_download(unsigned char return_value);
    void signal_pc_image_hir_composite(unsigned char return_value);
    void signal_pc_image_set_imagetype(unsigned char return_value);
    void signal_pc_image_set_abnormalexitend(unsigned char return_value);
    void signal_core_get_hir_play_status(unsigned char return_value, int value);
    void signal_pc_sys_set_HDMI(unsigned char return_value);
    void siganl_pc_sys_set_serve_con(unsigned char return_value);
    void signal_pc_sys_set_sevsend_break(unsigned char return_value);
    void signal_pc_sys_set_ble_power(unsigned char return_value);
    void signal_pc_sys_set_analog_video(unsigned char return_value);
    void signal_pc_sys_set_ble_switch(unsigned char return_value);
    void signal_pc_sys_set_ble_module(unsigned char return_value);

    void signal_pc_sys_set_ble_function(unsigned char return_value);
    void signal_pc_sys_get_ble_info(unsigned char return_value, QString data);
    void signal_get_ble_state(unsigned char return_value, BleState bleState);
    void signal_pc_sys_get_match_degree(unsigned char return_value, int data);
    void signal_pc_sys_get_positiion_data(unsigned char return_value, int data);
//    void signal_pc_sys_get_matching_degree(unsigned char return_value, int data);
    void signal_biaoding_DDE(unsigned char return_value);
    void signal_pc_checkbox_rotate(unsigned char return_value);
    void signal_core_fpgamenu_oritoggle(unsigned char return_value);
    void signal_core_fpgamenu_auto_badixel(unsigned char return_value);
    void signal_core_fpgamenu_badpixel_recover(unsigned char return_value);
    void signal_core_fpga_get_ver(unsigned char return_value,int val);
    void signal_core_fpga_get_intcp(unsigned char return_value,int val);
    void signal_core_fpga_get_adgain(unsigned char return_value,int val);
    void signal_core_fpga_get_svrd(unsigned char return_value,int val);
    void signal_core_fpga_get_fos(unsigned char return_value,int val);

    void signal_pc_spinbox_para(unsigned char return_value);
    void signal_pc_spinbox_zoom(unsigned char return_value);
    void signal_pc_sys_set_wifi_power(unsigned char return_value);
    void signal_pc_sys_set_qrcode_switch(unsigned char return_value);
    void signal_pc_sys_get_qrcode_info(unsigned char return_value ,unsigned char *data);
    void signal_pc_measure_mulhomogeneity(unsigned char return_value);
    void signal_pc_measure_temprange_query(unsigned char return_value,int data);
public slots:
    void slot_core_fpga_get_ver();
    void slot_core_get_upload_status();
    void slot_pc_sys_set_upload_target(ftp_para para);
    void slot_pc_cmd_set_pc_pic(ftp_para para);
    void slot_pc_image_set_gps(int flip);
    void slot_pc_image_set_flip(int flip);
    void slot_pc_sys_get_standard();
    void slot_pc_sys_get_hidemenu();

    void slot_pc_sys_get_bn();
    void slot_pc_sys_get_focus();

    void slot_pc_sys_set_language(int lang);
    void slot_pc_sys_set_default();
    void slot_pc_sys_set_hidemenu(ComHideMenuPara para);

    void slot_pc_measure_move_display(ti_pos offset);
    void slot_pc_sys_mag_calsw_start();
    void slot_pc_sys_mag_calsw_stop();
    void slot_pc_sys_set_mag_affset(int para);
    void slot_pc_sys_set_capturetime(int time_s);
    void slot_pc_sys_set_autorectify(int time_s);
    void slot_pc_sys_set_time_sec(char *str);
    void slot_pc_sys_set_format();
    void slot_pc_sys_set_usbmode(int usbtype);
    void slot_pc_sys_set_wifi_switch(int power);
    void slot_pc_sys_set_lcd_bright(int bright);
    void slot_pc_sys_set_ETH_switch(int index);
    void slot_pc_image_set_sketch_clear();
    void slot_pc_sys_set_handfusion(int hs);
    void slot_pc_sys_set_ble_power(int on);
    void slot_pc_sys_set_ble_module(int on);
    void slot_pc_sys_set_ble_switch(int on);
    void slot_pc_sys_set_analog_video(int on);
    void slot_pc_sys_set_ble_function(BleInfo bleInfo);
    void slot_pc_sys_set_panorama_start(int para);
    void slot_pc_sys_get_matching_degree(int para);
    void slot_pc_sys_set_panorama_stop(int para);
    void slot_pc_sys_set_color_brightness(int para);
    void slot_pc_sys_set_image_contrast(int para);
    void slot_pc_sys_get_ble_info(int msgType);
    void slot_core_get_ble_status();
    void slot_pc_sys_fusion_adjust(FusionAdjust fa);

    void slot_pc_cfg_set_temp_userpara(ComTempUserPara para);

    void slot_pc_measure_active(OP_DATA op_data);
    void slot_pc_measure_clear();
    void slot_pc_measure_tempcapture(int temp_capture);

    void slot_pc_measure_set_reference(ComTempReference para);
    void slot_pc_measure_set_tempunit(int temp_unit);//0:c 1:f 2:k
    void slot_pc_measure_set_temprange(ComTempRange para);
    void slot_pc_image_set_Isotherm(ComIsothermTemp para);
    void slot_pc_image_set_sketch_start(sketch_point para);
    void slot_pc_image_set_sketch_draw(sketch_point para);
    void slot_image_set_gas(GasPara para);
    void slot_pc_measure_set_point_add(ComPointPara point);
    void slot_pc_measure_set_point_update(ComPointPara point);
    void slot_pc_measure_set_point_del(ComPointPara point);
    void slot_pc_measure_get_point(int index);
    void slot_pc_measure_get_line(int index);
    void slot_pc_measure_get_rect(int index);
    void slot_pc_measure_get_circle(int index);

    void slot_pc_measure_set_line_add(ComLinePara line);
    void slot_pc_measure_set_line_update(ComLinePara line);
    void slot_pc_measure_set_line_del(ComLinePara line);

    void slot_pc_measure_set_rect_add(ComRectPara rect);
    void slot_pc_measure_set_rect_update(ComRectPara rect);
    void slot_pc_measure_set_rect_del(ComRectPara rect);

    void slot_pc_measure_set_circle_add(ComCirclePara circle);
    void slot_pc_measure_set_circle_update(ComCirclePara circle);
    void slot_pc_measure_set_circle_del(ComCirclePara circle);

    void slot_pc_measure_set_polygon_add(ComPolygonPara polygon);
    void slot_pc_measure_set_polygon_update(ComPolygonPara polygon);
    void slot_pc_measure_set_polygon_del(ComPolygonPara polygon);

    void slot_pc_measure_tempcenter(int index);

    void slot_pc_image_set_imagetype(int type);
    void slot_pc_image_set_mode(int nVideoMode);
    void slot_pc_image_set_abnormalexitend(ComAbnormalExtendPara para);
    void slot_pc_image_set_colorruler(int colorid);
    void slot_pc_image_set_alarm(ComAlarmTemp para);
    void slot_pc_image_set_manual(ComManualPara para);
    void slot_pc_image_set_fusion(FusionPara para);
    void slot_pc_image_set_pip(PipPara para);
    void slot_pc_image_get_manual();
    void slot_pc_image_set_vertical_handle(int type);
    void slot_pc_image_set_suppression_handle(int type);
    void slot_pc_key_zoom(int zoom_rate);
    void slot_pc_key_auto_rectify();
    void slot_pc_key_set_freeze(int freeze);
    void slot_core_key_record_avi_start();
    void slot_core_key_record_avi_stop();
    void slot_core_key_record_hir_start();
    void slot_core_key_record_hir_stop();
    void slot_core_key_capture_start(int flag);
    void slot_core_key_add_audio_start();
    void slot_core_key_add_audio_stop();
    void slot_core_key_add_text(char *text);
//    void slot_core_key_capture_stop();
    void slot_core_key_capture_stop(int type);
    void slot_core_annlysis_pic_twice_start(char *name);
    void slot_core_annlysis_hir_twice_start(char *name);
    void slot_core_annlysis_pic_twice_stop();
    void slot_core_annlysis_hir_twice_stop();
    void slot_core_annlysis_hir_twice_suspend(int type);
    void slot_core_ctrlcore_start_encode();
    void slot_core_ctrlcore_stop_encode();
    void slot_core_get_sd_info();
    void slot_core_get_battery();
    void slot_pc_set_upload_break(int status);
    void slot_core_get_usbwifiinsert();
    void slot_core_get_charge();
    void slot_core_get_sdinsert();
    void slot_core_get_usbinsert();
    void slot_core_get_rodation_type();
    void slot_core_get_twice_audio_status();
    void slot_core_analysis_pic_twice_audioplay_start();
    void slot_core_analysis_pic_twice_audioplay_stop();
    void slot_core_analysis_pic_twice_audiocap_start();
    void slot_core_analysis_pic_twice_audiocap_stop();
    void slot_core_analysis_pic_twice_addtext(char* text) ;
    void slot_core_analysis_pic_twice_addaudio();
    void slot_core_analysis_pic_twice_cancelaudio();
    void slot_pc_sys_get_appcontrolstatus();
    //biaoding
    void slot_pc_send_biaoding( );
    void slot_pc_biaoding_canshu(FPGAMenuPara para);
    void slot_pc_save_focus_offset(int para);
    void slot_pc_focus_offset(ComFocusOffset para);
    void slot_biaoding_para_ok( );
    void slot_biaoding_HI( );
    void slot_biaoding_LO( );
    void slot_biaoding_SAVE( );
    void slot_all_tiaoling( );
    //hidemenu point rect
    void slot_hidemenu_point_enable(bool checked);
    void slot_hidemenu_rect_enable(bool checked);
    void slot_display_rect(unsigned char *data,int recv_datalen);
    void slot_display_point(unsigned char *data,int recv_datalen);
    //单点，高低温，坏点
    void slot_dandian_sidian();
    void slot_gaowen_sidian();
    void slot_diwen_sidian();
    //       void slot_core_hidemenu_get_para();

    void slot_dev_get_parameter();                    //设备获取一些全局参数

    void slot_pc_cfg_get_pointconfig();
    void slot_pc_cfg_get_lineconfig();
    void slot_pc_cfg_get_rectconfig();
    void slot_pc_cfg_get_circleconfig();
    void slot_pc_key_auto_focus();
    void slot_pc_key_focus_near();
    void slot_pc_key_focus_far();
    void slot_pc_key_focus_stop();
    void slot_pc_key_focus_adjust(int flag);
    void slot_pc_key_focus_select(int flag);
    void slot_pc_osd_set_osdstat(OsdSetting para);
    void slot_pc_measure_set_compensate(int compensate);
    void slot_pc_get_measure_get_temp();
    void slot_pc_get_measure_get_collect(int value);
    void slt_pc_sys_get_laserrange();
    void slot_pc_key_laser(int index);
    void slot_pc_sys_set_screensleep(int power);
    void slot_pc_sys_set_powerdown(int power);
    void slot_pc_sys_set_light_power(int power);
    void slot_pc_sys_set_laser_power(int power);
    void slot_pc_image_set_abnormal(int isSet);

    void slot_PC_SYS_GET_ESSID();
    void slot_PC_SYS_SET_WIFI_STA(ap_para ret2);
    void slot_CORE_GET_WIFI_STA_STATUS();

    void slot_set_core_fpgamenu_badline_x(int x);
    void slot_set_core_fpgamenu_badline_y(int y);
    void slot_set_4G_state(int num);
    void slot_set_4G_power(int value);
    void slot_get_4G_state();
    void slot_pc_sys_set_laserpos(int index);
    void slot_pc_sys_get_positiion_data();
    void slot_hir_twice_get_zoom();
    void slot_hir_twice_get_colorrule();
    void slot_hir_twice_lockstatus(int v);
    void slot_pc_sys_set_filequery(ftp_para para);
    void slot_pc_sys_set_download(ftp_para para);
    void slot_pc_image_hir_composite(char *name);
    void slot_core_get_hir_play_status();
    void slot_pc_sys_set_HDMI_switch(int index);

    void slot_pc_sys_set_local_servrer(int isOPen);
    void slot_pc_sys_set_dev_active_search();
    void slot_pc_sys_set_dev_client(ComDevClientInfo info);

    void slot_key_dev_client_encode_start();
    void slot_key_dev_client_encode_stop();
    void slot_pc_sys_set_newserve_con(server_para para);
    void slot_pc_sys_set_serve_con(client_para para);
    void slot_pc_cmd_set_pc_pic_srv(char *photoname);
    void slot_pc_sys_set_sevsend_break();
    void slot_biaoding_DDE(int val);
    void slot_pc_checkbox_rotate(ComTempRange val);
    void slot_core_fpgamenu_oritoggle(int val);
    void slot_core_fpgamenu_noise_time_para(int para);
    void slot_core_fpgamenu_noise_airspace_para(int para);
    void slot_core_fpgamunu_noncool_correct(int para);
    void slot_core_fpga_get_fos();
    void slot_core_fpga_get_intcp();
    void slot_core_fpga_get_adgain();
    void slot_core_fpga_get_svrd();
    void slot_core_fpgamunu_set_intcp(int para);
    void slot_core_fpgamunu_set_adgain(int para);
    void slot_core_fpgamunu_set_svrd(int para);
    void slot_core_fpgamunu_set_fos(int para);
    void slot_core_fpgamunu_set_occ_enable(int para);
    void slot_core_fpgamenu_auto_badixel(int val);
    void slot_core_fpgamenu_value_badixel(int val);
    void slot_core_fpgamenu_badpixel_recover();
    void slot_pc_spinbox_para(int val);
    void slot_pc_spinbox_zoom(int val);
    void slot_pc_sys_wifi_power(int val);
    void slot_pc_sys_set_qrcode_switch(int index);
    void slot_pc_sys_set_step_zero(int index);
    void slot_pc_sys_get_qrcode_info();
    void slot_pc_measure_mulhomogeneity(int val);
    void slot_pc_sys_set_laserrange();
    void slot_pc_measure_temprange_query(ComTempRange para);
private:
    volatile bool stopped;

    int sock_fd;

    QString deviceIp;
    QStringList deviceIpList;
    HpDomainApi *p_hpdomainapi;
    HpProtocolPkg *p_hpprotocolpkg;

    void process(unsigned char recv_cmd,unsigned char recv_subcmd,unsigned char return_value,unsigned char *data,int recv_datalen);    //主线程

    void pc_cfg_process(unsigned char recv_subcmd,unsigned char return_value,unsigned char *data,int recv_datalen);
    void pc_measure_process(unsigned char recv_subcmd,unsigned char return_value,unsigned char *data,int recv_datalen);
    void pc_image_process(unsigned char recv_subcmd,unsigned char return_value,unsigned char *data,int recv_datalen);
    void pc_sys_process(unsigned char recv_subcmd,unsigned char return_value,unsigned char *data,int recv_datalen);
    void pc_key_process(unsigned char recv_subcmd,unsigned char return_value,unsigned char *data,int recv_datalen);
    void pc_pic_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen);
    void core_key_process(unsigned char recv_subcmd,unsigned char return_value,unsigned char *data,int recv_datalen);
    void core_get_process(unsigned char recv_subcmd,unsigned char return_value,unsigned char *data,int recv_datalen);
    void core_ctrlcore_process(unsigned char recv_subcmd,unsigned char return_value,unsigned char *data,int recv_datalen);
    void core_analysis_process(unsigned char recv_subcmd,unsigned char return_value,unsigned char *data,int recv_datalen);

//biaoding   判断主类之后调用。 用来根据子类的类型进行相应的操作
    void core_biaoding_process(unsigned char recv_subcmd,unsigned char return_value,unsigned char *data,int recv_datalen);

    void pc_get_biaoding_canshu( );                                                 //信号， 向内核索取 标定界面参数值。 pc表示界面传递过去
    void pc_get_biaoding_gray( );
    void ceshi(unsigned char *data,int recv_datalen);


};

#endif // HPDOMAINTHREAD_H
