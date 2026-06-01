#include  "hpdomainthread.h"

HpDomainThread::HpDomainThread(QObject *parent) : QThread(parent)
{
    isGetBiaoDingPara = false;
    stopped = false;
    domainName = "/tmp/sock";
    p_hpdomainapi = new HpDomainApi();
    p_hpprotocolpkg = new HpProtocolPkg();
}

void HpDomainThread::setDomainName(const QString &str)
{
    if(domainName != str)
    {
        domainName = str;
        qDebug()<<"set domainName:"<<domainName;
    }
}

void HpDomainThread::startDomain()
{
    start();
}

void HpDomainThread::stopDomain()
{
    stopped = true;
}

void HpDomainThread::slot_pc_image_set_gps(int flip)
{
    int ret ,totallen;
    unsigned char buf[1024];
    qDebug() << "HpDomainThread::slot_pc_image_set_gps" << flip;
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_GPS,0,(unsigned char *)&flip,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}


void HpDomainThread::slot_pc_image_set_flip(int flip)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_FLIP,0,(unsigned char *)&flip,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_cmd_set_pc_pic(ftp_para para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_PIC,PC_PIC_SET_UPLOAD,0,(unsigned char *)&para,sizeof(ftp_para),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_analog_video(int on)
{
    qDebug() << "111111111111111111111111111HpDomainThread::slot_pc_sys_set_analog_video(int on)";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_ANALOG_AUDIO,0,(unsigned char *)&on,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_ble_power(int on)
{
    qDebug() << "111111111111111111111111111HpDomainThread::slot_pc_sys_set_ble_power(int on)";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_BLE_POWER,0,(unsigned char *)&on,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_ble_switch(int on)
{
    qDebug() << "22222222222222222222222222222222HpDomainThread::slot_pc_sys_set_ble_switch(int on)";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_BLE_SWITCH,0,(unsigned char *)&on,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_ble_module(int on)
{
    int ret ,totallen;
    qDebug() << " HpDomainThread::slot_pc_sys_set_ble_module" << on ;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_BLE_MODULE,0,(unsigned char *)&on,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_ble_function(BleInfo bleInfo)
{
    qDebug("HpDomainThread::slot_pc_sys_set_ble_function functionmode = %d, %s", bleInfo.function_mode, bleInfo.mac_addr);
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_BLE_FUNCTION,0,(unsigned char *)&bleInfo,sizeof(BleInfo),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_get_ble_info(int msgType)
{
    qDebug() << "444444444444444444HpDomainThread::slot_pc_sys_get_ble_info(int on)";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_BLE_INFO,0,(unsigned char *)&msgType,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_get_ble_status()
{
//    qDebug() << "555555555555555555555HpDomainThread::slot_core_get_ble_status(int on)";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_BLE_STATUS,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_upload_target(ftp_para para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_UPLOAD_TARGET,0,(unsigned char *)&para,sizeof(ftp_para),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_get_standard()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_STANDARD,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
//        qDebug()<<"Domain_send error";
    return;
}
//get  hidemenu
void HpDomainThread::slot_pc_sys_get_hidemenu()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_HIDEMENU,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_get_bn()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_BN,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_PC_SYS_GET_ESSID()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_ESSID,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_PC_SYS_SET_WIFI_STA(ap_para ret2)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_WIFI_STA,0,(unsigned char *)&ret2,sizeof(ap_para),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_CORE_GET_WIFI_STA_STATUS()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_WIFI_STA_STATUS,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_local_servrer(int isOPen)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_pc_sys_set_local_servrer power == > " << isOPen;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_LOCAL_SERVICE,0,(unsigned char *)&isOPen,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_dev_active_search()
{
    qDebug() << __func__ << __LINE__;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS, PC_SYS_SET_DEV_ACTIVE_SEARCH,0,(unsigned char *)0,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_key_dev_client_encode_start()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf, 1024, PC_SYS, CORE_KEY_DEV_CLIENT_ENCODE_START, 0, (unsigned char *)0, 0, 0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_key_dev_client_encode_stop()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf, 1024, PC_SYS, CORE_KEY_DEV_CLIENT_ENCODE_STOP, 0, (unsigned char *)0, 0, 0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_dev_client(ComDevClientInfo info)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_pc_sys_set_wifi_switch power == > " << info.ip_addr << info.client_switch;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_DEV_CLIENT,0,(unsigned char *)&info,sizeof(ComDevClientInfo),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

//slot_pc_sys_get_focus
void HpDomainThread::slot_pc_sys_get_focus()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_FOCUS_STEP,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_language(int lang)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_LANGUAGE,0,(unsigned char *)&lang,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_default()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_DEFAULT,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}


//set hidemenu
void HpDomainThread::slot_pc_sys_set_hidemenu(ComHideMenuPara para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_HIDEMENU,0,(unsigned char *)&para,sizeof(ComHideMenuPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_mag_calsw_start()
{
    qDebug()<<"HpDomainThread::slot_pc_sys_mag_calsw_start";
    int ret ,totallen;
    unsigned char buf[1024];
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_MAG_CALSW_START,0,(unsigned char *)0,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_mag_calsw_stop()
{
    qDebug()<<"HpDomainThread::slot_pc_sys_mag_calsw_stop";
    int ret ,totallen;
    unsigned char buf[1024];
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_MAG_CALSW_STOP,0,(unsigned char *)0,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_mag_affset(int para)
{
    qDebug()<<"HpDomainThread::slot_pc_sys_set_mag_affse"<<para;
    int ret ,totallen;
    unsigned char buf[1024];
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_MAG_OFFSET,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}


void HpDomainThread::slot_pc_sys_set_capturetime(int time_s)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_CAPTURETIME,0,(unsigned char *)&time_s,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_autorectify(int time_s)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_AUTORECTIFY,0,(unsigned char *)&time_s,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_time_sec(char *str)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_TIME_SEC,0,(unsigned char *)str,strlen(str),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_format()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_FORMAT,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_usbmode(int usbtype)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_USBMODE,0,(unsigned char *)&usbtype,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_wifi_switch(int power)
{
    qDebug() << "HpDomainThread::slot_pc_sys_set_wifi_switch" ;
    int ret ,totallen;
    unsigned char buf[1024];
//
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_WIFI_SWITCH,0,(unsigned char *)&power,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_ETH_switch(int index)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << __func__ << index;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_ETH_SWITCH,0,(unsigned char *)&index,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);
    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_image_set_sketch_clear()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_SKETCH_CLEAR,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_lcd_bright(int bright)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_LCD_BRIGHT,0,(unsigned char *)&bright,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_handfusion(int hs)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_HAND_FUSION,0,(unsigned char *)&hs,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_panorama_start(int para)
{
    qDebug()<<"slot_pc_sys_set_panorama_start " << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_PANORAMA_START,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_get_matching_degree(int para)
{
//    qDebug()<<"slot_pc_sys_get_matching_degree " << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_MATCHING_DEGREE,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_panorama_stop(int para)
{
    qDebug()<<"slot_pc_sys_set_panorama_stop " << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_PANORAMA_STOP,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_color_brightness(int para)
{
    qDebug()<<"slot_pc_sys_set_color_brightness " << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_COLOR_BRIGHTNESS,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_image_contrast(int para)
{
    qDebug()<<"slot_pc_sys_set_image_contrast " << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_IMAGE_CONTRAST,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_fusion_adjust(FusionAdjust fa)
{
//    qDebug( )<<"@@@@@@ slot_pc_sys_fusion_adjust";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_FUSION_ADJUST,0,(unsigned char *)&fa,sizeof(FusionAdjust),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}


void HpDomainThread::slot_pc_cfg_set_temp_userpara(ComTempUserPara para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_CFG,PC_CFG_SET_TEMP_USERPARA,0,(unsigned char *)&para,sizeof(ComTempUserPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_active(OP_DATA op_data)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_ACTIVE,0,(unsigned char *)&op_data,sizeof(OP_DATA),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_tempcapture(int temp_capture)
{
    int ret ,totallen;
    unsigned char buf[1024];
//
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_TEMPCAPTURE,0,(unsigned char *)&temp_capture,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_clear()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_CLEAR,0,(unsigned char *)0,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_reference(ComTempReference para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_REFERENCE,0,(unsigned char *)&para,sizeof(ComTempReference),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_image_set_sketch_draw(sketch_point para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug()<<"slot_pc_image_set_sketch_draw"<<para.point_x<<"ffff"<<para.point_y;
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_SKETCH_DRAW,0,(unsigned char *)&para,sizeof(sketch_point),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_image_set_sketch_start(sketch_point para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug()<<"slot_pc_image_set_sketch_start"<<para.point_x<<"ffff"<<para.point_y;
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SKETCH_DRAW_START,0,(unsigned char *)&para,sizeof(sketch_point),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_image_set_Isotherm(ComIsothermTemp para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_ISOTHERM,0,(unsigned char *)&para,sizeof(ComAlarmTemp),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_image_set_gas(GasPara para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_GAS,0,(unsigned char *)&para,sizeof(GasPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_tempunit(int temp_unit)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_TEMPUNIT,0,(unsigned char *)&temp_unit,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_temprange(ComTempRange para)           //切换，仪器镜头和测温范围时发送的命令
{
    int ret ,totallen;
    unsigned char buf[1024];
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_TEMPRANGE,0,(unsigned char *)&para,sizeof(ComTempRange),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}


/********************************************************************************************************
 * @ description    : 参函数，移动播放窗口
 * @ param - offset : 窗口偏移量
 * @ return         : null
 ********************************************************************************************************/
void HpDomainThread::slot_pc_measure_move_display(ti_pos offset)
{
    qDebug() << "HpDomainThread::slot_pc_measure_move_display" << offset.lcd_pos_x;
    int ret, totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf, 1024, PC_OSD, PC_OSD_SET_VIDEOOFFSET, 0, (unsigned char *)&offset,sizeof(ti_pos),0);
    ret = p_hpdomainapi->Domain_send(sock_fd, buf, totallen);
}

void HpDomainThread::slot_pc_measure_set_point_add(ComPointPara point)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_POINT_ADD,0,(unsigned char *)&point,sizeof(ComPointPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);


    if(ret <0)
        qDebug()<<"Domain_send error";

//    qDebug("######## totallen === %d",totallen);
//    qDebug("######$$ point temp100 === %d",point.temp100);
//    qDebug("$######$ sizeof(point) === %d",sizeof(point));
    return;
}

void HpDomainThread::slot_pc_measure_set_point_update(ComPointPara point)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_POINT_UPDATE,0,(unsigned char *)&point,sizeof(ComPointPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);


    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_measure_get_point(int index)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_GET_POINT,0,(unsigned char *)&index,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

//    qDebug()<<"fffffffffffffffffffffffffff1";
    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_measure_get_line(int index)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_GET_LINE,0,(unsigned char *)&index,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);
//    qDebug()<<" ====Send CMD : PC_MEASURE_GET_LINE====";

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_measure_get_rect(int index)
{
//    qDebug() << __func__ << index;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_GET_RECT,0,(unsigned char *)&index,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_measure_get_circle(int index)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_GET_CIRCLE,0,(unsigned char *)&index,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

//    qDebug()<<"fffffffffffffffffffffffffff3";
    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_point_del(ComPointPara point)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_POINT_DEL,0,(unsigned char *)&point,sizeof(ComPointPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);


    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_line_add(ComLinePara line)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_LINE_ADD,0,(unsigned char *)&line,sizeof(ComLinePara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_line_update(ComLinePara line)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_LINE_UPDATE,0,(unsigned char *)&line,sizeof(ComLinePara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}


void HpDomainThread::slot_pc_measure_set_line_del(ComLinePara line)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_LINE_DEL,0,(unsigned char *)&line,sizeof(ComLinePara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_rect_add(ComRectPara rect)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_RECT_ADD,0,(unsigned char *)&rect,sizeof(ComRectPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);


    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_rect_update(ComRectPara rect)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_RECT_UPDATE,0,(unsigned char *)&rect,sizeof(ComRectPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);


    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_rect_del(ComRectPara rect)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_RECT_DEL,0,(unsigned char *)&rect,sizeof(ComRectPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    qDebug("rect del:");
    qDebug("\trect_id:%d (%d,%d)-(%d,%d)",rect.rect_id,rect.origin_xcoord,rect.origin_ycoord,rect.rect_wide,rect.rect_high);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_circle_add(ComCirclePara circle)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_CIRCLE_ADD,0,(unsigned char *)&circle,sizeof(ComCirclePara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);


    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_circle_update(ComCirclePara circle)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_CIRCLE_UPDATE,0,(unsigned char *)&circle,sizeof(ComCirclePara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);


    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_circle_del(ComCirclePara circle)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_CIRCLE_DEL,0,(unsigned char *)&circle,sizeof(ComCirclePara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_polygon_add(ComPolygonPara polygon)
{
//    int ret ,totallen;
//    unsigned char buf[1024];

//    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_POLYGON_ADD,0,(unsigned char *)&polygon,sizeof(ComPolygonPara),0);
//    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);


//    if(ret <0)
//        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_polygon_update(ComPolygonPara polygon)
{
//    int ret ,totallen;
//    unsigned char buf[1024];
//    qDebug() << "polygon.refer_flag" << polygon.refer_flag;
//    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_POLYGON_UPDATE,0,(unsigned char *)&polygon,sizeof(ComPolygonPara),0);
//    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);


//    if(ret <0)
//        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_polygon_del(ComPolygonPara polygon)
{
//    int ret ,totallen;
//    unsigned char buf[1024];

//    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_SET_POLYGON_DEL,0,(unsigned char *)&polygon,sizeof(ComPolygonPara),0);
//    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

//    if(ret <0)
//        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_tempcenter(int index)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_pc_measure_tempcenter PC_MEASURE_TEMPCENTER == > " << index;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_TEMPCENTER,0,(unsigned char *)&index,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}


void HpDomainThread::slot_pc_image_set_abnormalexitend(ComAbnormalExtendPara para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_pc_image_set_abnormalexitend Send PC_IMAGE_SET_ABNORMALEXTEND" << para.bvolume_enable << para.belevation_enable << para.blinedepth_enable;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_ABNORMALEXTEND,0,(unsigned char *)&para,sizeof(ComAbnormalExtendPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_image_set_mode(int nVideoMode)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_MODE,0,(unsigned char *)&nVideoMode,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_image_set_colorruler(int colorid)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_COLORRULER,0,(unsigned char *)&colorid,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_image_set_alarm(ComAlarmTemp para)
{
    int ret ,totallen;
    unsigned char buf[1024];
    qDebug() << __func__ << para.AlarmSwitch << para.AlarmTemp100;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_ALARM,0,(unsigned char *)&para,sizeof(ComAlarmTemp),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_image_set_manual(ComManualPara para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_MANUAL,0,(unsigned char *)&para,sizeof(ComManualPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_image_set_fusion(FusionPara para)
{
    int ret ,totallen;
    unsigned char buf[1024];
//    qDebug("FusionPara size:%d",sizeof(FusionPara));

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_FUSION,0,(unsigned char *)&para,sizeof(FusionPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_image_set_pip(PipPara para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_PIP,0,(unsigned char *)&para,sizeof(PipPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_image_get_manual()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_GET_MANUAL,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_key_zoom(int zoom_rate)
{
    qDebug() << "HpDomainThread::slot_pc_key_zoom" << zoom_rate;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_KEY,PC_KEY_ZOOM,0,(unsigned char *)&zoom_rate,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}


void HpDomainThread::slot_pc_key_auto_rectify()
{
    qDebug() << "HpDomainThread::slot_pc_key_auto_rectify";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_KEY,PC_KEY_AUTO_RECTIFY,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);
    signal_key_auto_start();
    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_key_set_freeze(int freeze)
{
    int ret ,totallen;
    unsigned char buf[1024];

  //  qDebug("slot_pc_key_set_freeze:%d",freeze);

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_KEY,PC_KEY_SET_FREEZE,0,(unsigned char *)&freeze,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}


void HpDomainThread::slot_core_key_record_avi_start()
{
    qDebug( )<<"*********************************************** avi  start";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_KEY,CORE_KEY_RECORD_AVI_START,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_key_record_avi_stop()
{
    qDebug( )<<"*********************************************** avi  stop";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_KEY,CORE_KEY_RECORD_AVI_STOP,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_key_record_hir_start()
{
   qDebug( )<<"*********************************************** hir  start";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_KEY,CORE_KEY_RECORD_IR_START,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}


void HpDomainThread::slot_core_key_record_hir_stop()
{
     qDebug( )<<"*********************************************** hir  stop";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_KEY,CORE_KEY_RECORD_IR_STOP,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}


void HpDomainThread::slot_core_key_capture_start(int flag)
{
    qDebug() << "HpDomainThread::slot_core_key_capture_start";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_KEY,CORE_KEY_CAPTURE_START,0,(unsigned char *)&flag,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_key_capture_stop(int type)
{
    qDebug() << "HpDomainThread::slot_core_key_capture_stop";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_KEY,CORE_KEY_CAPTURE_STOP,0,(unsigned char *)&type,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_key_add_audio_start()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_KEY,CORE_KEY_ADD_AUDIO_START,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_key_add_audio_stop()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_KEY,CORE_KEY_ADD_AUDIO_STOP,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_key_add_text(char *text)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug("slot_core_key_add_text:%s",text);

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_KEY,CORE_KEY_ADD_TEXT,0,(unsigned char *)text,strlen(text),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_annlysis_pic_twice_start(char *name)
{
    int ret ,totallen;
    unsigned char buf[1024];


//    qDebug() << " ((((( Twice ))))) 1.1.1";
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_PIC_TWICE_START,0,(unsigned char *)name,strlen(name),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_core_annlysis_hir_twice_start(char *name)
{
    int ret ,totallen;
    unsigned char buf[1024];

//    qDebug() << "HIR Play Start test";

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_HIR_TWICE_START,0,(unsigned char *)name,strlen(name),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_annlysis_pic_twice_stop()
{
    qDebug() << " HpDomainThread::slot_core_annlysis_pic_twice_stop()";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_PIC_TWICE_STOP,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_core_annlysis_hir_twice_stop()
{
    int ret ,totallen;
    unsigned char buf[1024];

//    qDebug() << "Stop HIR Video";
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_HIR_TWICE_STOP,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_annlysis_hir_twice_suspend(int type)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_HIR_TWICE_SUSPEND,0,(unsigned char *)&type,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_ctrlcore_start_encode()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_CTRLCORE,CORE_CTRLCORE_START_ENCODE,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_ctrlcore_stop_encode()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_CTRLCORE,CORE_CTRLCORE_STOP_ENCODE,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_get_sd_info()   //索要SD卡容量信息   sd_info
{
    int ret ,totallen;
    unsigned char buf[1024];

//    qDebug("HpDomainThread::slot_core_get_sd_info");

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_SD_INFO,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_fpga_get_ver()
{
    int ret, totallen;
    unsigned char buf[1024];

    qDebug() << " HpDomainThread::slot_core_fpga_get_ver~~~~~";

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_GET_VER,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}

void HpDomainThread::slot_core_get_upload_status()
{
    int ret ,totallen;
    unsigned char buf[1024];

//    qDebug("HpDomainThread::slot_core_get_sd_info");

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_UPLOAD_STATUS,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_get_battery()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_BATTERY,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_image_set_vertical_handle(int type)
{
    qDebug()<<"HpDomainThread::slot_pc_image_set_vertical_handle" << type;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_VERTICAL_HANDLE,0,(unsigned char *)&type,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_image_set_imagetype  error";
    return;
}

void HpDomainThread::slot_pc_image_set_suppression_handle(int type)
{
    qDebug()<<"HpDomainThread::slot_pc_image_set_vertical_handle" << type;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_SUPPRESSION_HANDLE,0,(unsigned char *)&type,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_image_set_imagetype  error";
    return;
}

void HpDomainThread::slot_pc_image_set_imagetype(int para)
{
    qDebug()<<"HpDomainThread::slot_pc_image_set_imagetype" << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_IMAGETYPE,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_image_set_imagetype  error";
    return;
}

void HpDomainThread::slot_pc_set_upload_break(int status)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_UPLOAD_BREAK,0,(unsigned char *)&status,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_get_usbwifiinsert()
{
    qDebug() << "HpDomainThread::slot_core_get_usbwifiinsert()";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_USBWIFIINSERT,0,NULL,0,0);

    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);


    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_get_charge()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_CHARGE,0,NULL,0,0);

    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_get_usbinsert()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_USBINSERT,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_get_rodation_type()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_ROTATION_TYPE,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_get_twice_audio_status()
{
    qDebug() << "HpDomainThread::slot_core_get_twice_audio_status";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_TWICE_AUDIO_STATUS,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_analysis_pic_twice_audioplay_start()
{
    qDebug() << "HpDomainThread::slot_core_analysis_pic_twice_audioplay_start";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_PIC_TWICE_AUDIOPLAY_START,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_analysis_pic_twice_audioplay_stop()
{
    qDebug() << "HpDomainThread::slot_core_analysis_pic_twice_audioplay_stop";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_PIC_TWICE_AUDIOPLAY_STOP,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_analysis_pic_twice_audiocap_start()
{
    qDebug() << "HpDomainThread::slot_core_analysis_pic_twice_audiocap_start";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_PIC_TWICE_AUDIOCAP_START,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_analysis_pic_twice_addtext(char* text)
{
    qDebug() << " HpDomainThread::slot_core_analysis_pic_twice_addtext" << text;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_PIC_TWICE_ADDTEXT,0,(unsigned char *)text,strlen(text),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_analysis_pic_twice_addaudio()
{
    qDebug() << " HpDomainThread::slot_core_analysis_pic_twice_addaudio";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_PIC_TWICE_ADDAUDIO,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_analysis_pic_twice_cancelaudio()
{
    qDebug() << " HpDomainThread::slot_core_analysis_pic_twice_cancelaudio";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_PIC_TWICE_CANCELAUDIO,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_analysis_pic_twice_audiocap_stop()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_PIC_TWICE_AUDIOCAP_STOP,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_get_appcontrolstatus()
{
//    qDebug() << "HpDomainThread::slot_pc_sys_get_appcontrolstatus()" ;
    int ret ,totallen;
    unsigned char buf[1024];
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_APPCONTROLSTATUS,0,(unsigned char *)0,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_get_sdinsert()        //索取SD卡插入信息  sd_info
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_SDINSERT,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::run()
{
    int ret;
    unsigned char r_buf[1024];


    unsigned char  recv_cmd= ERRORCMD;
    unsigned char recv_subcmd = 0xff;
    unsigned char return_value;
    unsigned char recv_data[1024] =
    { 0 };
    unsigned char *moredata;
    int recv_datalen = 0;

    int testlen = 0;

    int reread_datalen = 0;

    QByteArray ba = domainName.toLatin1();

    while(!stopped)
    {
        while(!stopped)
        {
            //sock_fd = p_hpdomainapi->Domain_client_init("domain_socket_sync");
            sock_fd = p_hpdomainapi->Domain_client_init(ba.data());

            if(sock_fd > 0)
            {
//                qDebug()<<"sock_fd:"<< sock_fd;
                break;
            }
            sleep(3);
        }
        while(!stopped)
        {
            if(reread_datalen <= 0 )
            {
                ret = p_hpdomainapi->Domain_recv(sock_fd,r_buf,1024);
                if(ret <= 0)
                {
                    qDebug()<<"recv error..PLEASE check server connect ok";
                    p_hpdomainapi->Domain_client_uinit(&sock_fd);
                    reread_datalen = 0;
                    break;
                }

//                qDebug() << "[Source] recv len =" << ret;
//                QString hexStr;
//                for(int i = 0; i < ret; i++)
//                    hexStr += QString("%1 ").arg(r_buf[i], 2, 16, QChar('0'));
//                qDebug().noquote() << "[Source] hex =" << hexStr;

                reread_datalen = ret;
            }
            ret = p_hpprotocolpkg->protocol_pkg_hp_analysis(r_buf,reread_datalen,&recv_cmd,&recv_subcmd,&return_value,recv_data,&recv_datalen);

//            if(recv_cmd != CORE_GET)
//            {
//                if(r_buf[1] == CORE_KEY && r_buf[2] == CORE_KEY)
//                {
//                    qDebug() << "========================== HpDomainThread ret == " << ret <<  " ==========================";
//                    qDebug() << recv_cmd << recv_subcmd;
//                    for(int i = 0;i < testlen;i++)
//                    {
//                        printf("%x - ", r_buf[i]);
//                    }
//                }
//            }

            if(ret == -3)
            {
                qDebug() << "========================== HpDomainThread ret == -3 ==========================";
                reread_datalen = 0;
                continue;
            }
            if(ret == -4)
            {
                qDebug() << "========================== HpDomainThread ret == -4 ==========================";
                p_hpprotocolpkg->protocol_pkg_hp_moregetdate(&recv_cmd,&recv_subcmd,&return_value,&moredata,&recv_datalen);
                process(recv_cmd,recv_subcmd,return_value,moredata,recv_datalen);//(主命令,子命令,返回值,返回的数据,返回数据的长度)
                reread_datalen = 0;
                continue;
            }
            if(ret < 0)
            {
                reread_datalen = 0;    // ★ 无效数据，丢弃
                continue;
            }
            reread_datalen = ret; 

                // qDebug() << "[RAW_RECV] recv_cmd=0x" << hex << (int)recv_cmd
                //      << "recv_subcmd=0x" << (int)recv_subcmd
                //      << "return_value=0x" << (int)return_value
                //      << "datalen=" << dec << recv_datalen;

            process(recv_cmd,recv_subcmd,return_value,recv_data,recv_datalen);//(主命令,子命令,返回值,返回的数据,返回数据的长度)
        }
    }

    if(sock_fd > 0)
        p_hpdomainapi->Domain_client_uinit(&sock_fd);

    qDebug("run  int ret == %d",ret);
}

//主线程
//第一个参数为主类。
void HpDomainThread::process(unsigned char recv_cmd, unsigned char recv_subcmd, unsigned char return_value,unsigned char *data, int recv_datalen)
{

//    qDebug("recv_cmd == 0x%02x  #########  recv_sucmd == 0x%02x",recv_cmd,recv_subcmd);
    switch(recv_cmd)
    {
    case PC_CFG:    //配置类
//        qDebug("PC_CFG");
        pc_cfg_process(recv_subcmd,return_value,data,recv_datalen);
        break;
    case PC_MEASURE:    //测温类
//        qDebug("PC_MEASURE");
        pc_measure_process(recv_subcmd,return_value,data,recv_datalen);
        break;
    case PC_IMAGE:     //图像类
//        qDebug("PC_IMAGE");
        pc_image_process(recv_subcmd,return_value,data,recv_datalen);
        break;
    case PC_SYS:       //系统类
//        qDebug("PC_SYS");
        pc_sys_process(recv_subcmd,return_value,data,recv_datalen);
        break;
    case PC_KEY:    //按键类
//        qDebug("PC_KEY");
        pc_key_process(recv_subcmd,return_value,data,recv_datalen);
        break;
    case PC_PIC:    //按键类
        qDebug("PC_PIC");
        pc_pic_process(recv_subcmd,return_value,data,recv_datalen);
        break;
    case CORE_KEY:     //按键类
//        qDebug("CORE_KEY");
        core_key_process(recv_subcmd,return_value,data,recv_datalen);
        break;
    case CORE_GET:     //获取类
//        qDebug("CORE_GET");
        core_get_process(recv_subcmd,return_value,data,recv_datalen);
        break;
    case CORE_CTRLCORE:    //控制类
//        qDebug("CORE_CTRLCORE");
        core_ctrlcore_process(recv_subcmd,return_value,data,recv_datalen);
        break;
    case CORE_ANALYSIS:     //分析类
//        qDebug("CORE_ANALYSIS");
        core_analysis_process(recv_subcmd,return_value,data,recv_datalen);
        break;
//biaoding
    case CORE_FPGAMENU:    //标定FPGA前端
//        qDebug("CORE_FEGAMENU");
        core_biaoding_process(recv_subcmd,return_value,data,recv_datalen);
        break;
    default:
        break;
    }

}


void HpDomainThread::pc_cfg_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen)
{
    int pointCount = 0;
    switch(recv_subcmd)
    {
    case PC_CFG_GET_DEVICEINFO:    //获取设备信息
        ComDeviceInfo msg;
        if(return_value == RE_OK)
            memcpy(&msg,data,recv_datalen);
        else
            memset(&msg,0,sizeof(ComDeviceInfo));
        signal_pc_cfg_get_deviceinfo(return_value,msg);

        break;
    case PC_CFG_GET_SYSCONFIG:     //获取系统配置
        qDebug("not defined...\n");
        signal_dev_get_parameter(data,return_value);
        break;
    case PC_CFG_SET_TEMP_USERPARA:    //设置测温参数(对用户开放)
        signal_pc_cfg_set_temp_userpara(return_value);
        break;
    case PC_CFG_GET_POINTCONFIG:        //获取仪器的点的具体信息
        memcpy(&pointCount,data,sizeof(int));
        qDebug() << "PC_CFG_GET_POINTCONFIG" << recv_datalen << "point Count " << pointCount;
        singal_pc_cfg_get_pointconfig(return_value,pointCount);
        break;
    case PC_CFG_GET_LINECONFIG:        //获取仪器的线的具体信息
        memcpy(&pointCount,data,sizeof(int));
        qDebug() << "PC_CFG_GET_LINECONFIG" << recv_datalen << "line Count " << pointCount;
        singal_pc_cfg_get_lineconfig(return_value,pointCount);
        break;
    case PC_CFG_GET_RECTCONFIG:      //获取仪器的框的具体信息
        memcpy(&pointCount,data,sizeof(int));
        qDebug() << "PC_CFG_GET_RECTCONFIG" << recv_datalen << "rect Count " << pointCount;
        singal_pc_cfg_get_rectconfig(return_value,pointCount);
        break;
    case PC_CFG_GET_CIRCLECONFIG:
       memcpy(&pointCount,data,sizeof(int));
       qDebug() << "PC_CFG_GET_CIRCLECONFIG" << recv_datalen << "circle Count " << pointCount;
       singal_pc_cfg_get_circleconfig(return_value,pointCount);
       break;
    default:
        break;
    }
}

void HpDomainThread::pc_measure_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen)
{
    switch(recv_subcmd)
    {
    case PC_MEASURE_ACTIVE:
        signal_pc_measure_active(return_value);
        break;
    case PC_MEASURE_CLEAR:             //+所有测温点，线，框都清除
        signal_pc_measure_clear(return_value);
        break;
    case PC_MEASURE_TEMPCAPTURE:
        signal_pc_measure_tempcapture(return_value);
        break;
    case PC_MEASURE_TEMPADJUST:
        signal_pc_measure_set_compensate(return_value);
        break;
    case PC_MEASURE_TEMPCENTER:
        signal_pc_measure_tempcenter(return_value);
        break;
    case PC_MEASURE_SET_REFERENCE:	//设置参考温度
        signal_pc_measure_set_reference(return_value);
        break;
    case PC_MEASURE_SET_TEMPUNIT:		//设置测温单位
        signal_pc_measure_set_tempunit(return_value);
        break;
    case PC_MEASURE_SET_TEMPRANGE:               //设置镜头成功后        切换测温档
        signal_pc_measure_set_temprange(return_value);
        break;

    case PC_MEASURE_SET_POINT_ADD:    //增加点
        ComPointPara point_test;
        memcpy(&point_test,data,sizeof(ComPointPara));
//        qDebug("############# temp100  ==== %d",point_test.temp100);
//        qDebug("############# sizeof(point) ====%d",sizeof(point_test));
        signal_pc_measure_set_point_add(return_value);
        break;
    case PC_MEASURE_SET_POINT_UPDATE:   //更新点测温
        signal_pc_measure_set_point_update(return_value);
        break;
    case PC_MEASURE_SET_POINT_DEL:     //删除点
        signal_pc_measure_set_point_del(return_value);
        break;

    case PC_MEASURE_SET_RECT_ADD:	         //增加区域测温
        signal_pc_measure_set_rect_add(return_value);
        break;
    case PC_MEASURE_SET_RECT_UPDATE:
        signal_pc_measure_set_rect_update(return_value);
        break;
    case PC_MEASURE_SET_RECT_DEL:
        signal_pc_measure_set_rect_del(return_value);
        break;

    case PC_MEASURE_SET_CIRCLE_ADD:	         //增加区域测温
        qDebug() << "PC_MEASURE_SET_CIRCLE_ADD" << return_value;
//        signal_pc_measure_set_circle_add(return_value);
        break;
    case PC_MEASURE_SET_CIRCLE_UPDATE:
        qDebug() << "PC_MEASURE_SET_CIRCLE_UPDATE" << return_value;
//        signal_pc_measure_set_circle_update(return_value);
        break;
    case PC_MEASURE_SET_CIRCLE_DEL:
        qDebug() << "PC_MEASURE_SET_CIRCLE_DEL" << return_value;
//        signal_pc_measure_set_circle_del(return_value);
        break;

    case PC_MEASURE_SET_LINE_ADD:     //增加线
        signal_pc_measure_set_line_add(return_value);
        break;
    case PC_MEASURE_SET_LINE_UPDATE:
        signal_pc_measure_set_line_update(return_value);
        break;
    case PC_MEASURE_SET_LINE_DEL:
        signal_pc_measure_set_line_del(return_value);
        break;
    case PC_MEASURE_GET_POINT:    //获取点温度
        ComPointPara point;
        memcpy(&point,data,sizeof(ComPointPara));
        signal_pc_measure_get_point(return_value,point);
        break;
    case PC_MEASURE_GET_LINE:    //获取线测温
        ComLinePara line;
        memcpy(&line,data,sizeof(ComLinePara));
        signal_pc_measure_get_line(return_value,line);
        break;
    case PC_MEASURE_GET_RECT:   //获取区域测温
        ComRectPara rect;
        memcpy(&rect,data,sizeof(ComRectPara));
        signal_pc_measure_get_rect(return_value,rect);
        break;
    case PC_MEASURE_GET_CIRCLE:   //获取区域测温
        ComCirclePara circle;
        memcpy(&circle,data,sizeof(ComCirclePara));
        signal_pc_measure_get_circle(return_value,circle);
        break;
    case PC_MEASURE_GET_TEMP:
        RectTemp Temp;
        memcpy(&Temp,data,sizeof(RectTemp));
        signal_pc_get_measure_get_temp(return_value,Temp);
        break;
    case PC_MEASURE_MULHOMOGENEITY:
        signal_pc_measure_mulhomogeneity(return_value);
        break;
    case PC_MEASURE_TEMPRANGE_QUERY:
        int query;
        memcpy(&query,data,sizeof(int));
        signal_pc_measure_temprange_query(return_value, query);
        break;
    default:
        break;
    }
}


void HpDomainThread::pc_image_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen)
{
    switch(recv_subcmd)
    {
    case PC_IMAGE_SET_MODE:
        signal_pc_image_set_mode(return_value);
        break;
    case PC_IMAGE_SET_COLORRULER:
        signal_pc_image_set_colorruler(return_value);
        break;
    case PC_IMAGE_SET_ALARM:
        signal_pc_image_set_alarm(return_value);
        break;
    case PC_IMAGE_SET_MANUAL:
        signal_pc_image_set_manual(return_value);
        break;
    case PC_IMAGE_GET_MANUAL:
        ComManualPara cmp;
        if(return_value == RE_OK)
        {
            memcpy((unsigned char *)&cmp,data,sizeof(ComManualPara));
        }
        else
            memset((unsigned char *)&cmp,0,sizeof(ComManualPara));
        signal_pc_image_get_manual(return_value,cmp);
        break;
    case PC_IMAGE_SET_GPS:
        signal_pc_image_set_gps(return_value);
        break;
    case PC_IMAGE_SET_FUSION:
        signal_pc_image_set_fusion(return_value);
        break;
    case PC_IMAGE_SET_PIP:
        signal_pc_image_set_pip(return_value);
        break;
    case PC_IMAGE_SET_ABNORMALEXTEND:
        signal_pc_image_set_abnormalexitend(return_value);
        break;
    case PC_IMAGE_SET_ABNORMAL:
            signal_pc_image_set_abnormal(return_value);
            break;
    case PC_IMAGE_SET_ISOTHERM:
         signal_pc_image_set_Isotemp(return_value);
        break;
    case PC_IMAGE_HIR_COMPOSITE:
         signal_pc_image_hir_composite(return_value);
        break;
    case PC_IMAGE_SET_IMAGETYPE:
        signal_pc_image_set_imagetype(return_value);
        break;
    case PC_IMAGE_SET_SUPPRESSION_HANDLE:
        qDebug() << "PC_IMAGE_SET_SUPPRESSION_HANDLE" << return_value;
        break;
    default:
        break;
    }
}


void HpDomainThread::pc_sys_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen)
{

    QString strname;
    if(recv_subcmd == PC_SYS_SET_PANORAMA_STOP)
    {
        qDebug() << "Name change!!!";
        char *str1 = (char *)data;
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        strname = codec->toUnicode(str1);
    }
    switch(recv_subcmd)
    {
    case PC_SYS_GET_STANDARD:          //获取定标数据
        if(return_value == RE_OK)
        {
//            StandardInfo msg;
//            memcpy(&msg,data,sizeof(StandardInfo));

//            signal_pc_sys_get_standard(return_value,msg);
            qDebug("\terr:\t PC_SYS_GET_STANDARD return_value=0x%02x",return_value);
        }
        else
        {
            qDebug("\terr:\treturn_value=0x%02x",return_value);
        }
        break;
    case PC_SYS_GET_HIDEMENU:               //获取隐藏菜单信息   HIDEMENU
        if(return_value == RE_OK)
        {
            ComHideMenuPara msg;
            memcpy(&msg,data,sizeof(ComHideMenuPara));
            signal_core_hidemenu_get_para(msg);
        }
        else
        {
            qDebug("\terr:\treturn_value=0x%02x",return_value);
        }
        break;
    case PC_SYS_SET_LCD_BRIGHT:
        signal_pc_sys_set_lcd_bright(return_value);
        break;
    case PC_SYS_GET_BN:
        if(return_value == RE_OK)
        {
            int a;
            memcpy(&a,data,sizeof(int));
            signal_pc_sys_get_bn(return_value,a);
        }
        else
        {
            signal_pc_sys_get_bn(return_value,-1);
        }
        break;
    case PC_SYS_GET_FOCUS_STEP:
        if(return_value == RE_OK)
        {
            int a;
            memcpy(&a,data,sizeof(int));
            signal_pc_sys_get_focus(return_value,a);
        }
        else
        {
            signal_pc_sys_get_focus(return_value,-1);
        }
        break;
    case PC_SYS_SET_LANGUAGE:
        signal_pc_sys_set_language(return_value);
        break;
    case PC_SYS_SET_DEFAULT:
        signal_pc_sys_set_default(return_value);
        break;
    case PC_SYS_SET_HIDEMENU:                                           //设置隐藏菜单
        signal_pc_sys_set_hidemenu(return_value);
        break;
    case PC_SYS_SET_CAPTURETIME:
        signal_pc_sys_set_capturetime(return_value);
        break;
    case PC_SYS_SET_UPLOAD_BREAK:
        signal_pc_set_upload_break(return_value);
        break;
    case PC_SYS_SET_AUTORECTIFY:
        signal_pc_sys_set_autorectify(return_value);
        break;
    case PC_SYS_SET_TIME_SEC:
        signal_pc_sys_set_time_sec(return_value);
        break;
    case PC_SYS_SET_FORMAT:
        signal_pc_sys_set_format(return_value);
        break;
    case PC_SYS_SET_USBMODE:
        signal_pc_sys_set_usbmode(return_value);
        break;
//wifi switch
    case PC_SYS_SET_WIFI_SWITCH:
        signal_pc_sys_set_wifi_switch(return_value);
        break;
    case PC_SYS_SET_ETH_SWITCH:
        signal_pc_sys_set_ETH_switch(return_value);
        break;
    case PC_SYS_FUSION_ADJUST:
        signal_pc_sys_fusion_adjust(return_value);
        break;
    case PC_SYS_SET_PANORAMA_STOP:
        signal_pc_sys_set_panorama_stop(return_value, strname);
        break;
    case PC_SYS_SET_HAND_FUSION:
        signal_pc_sys_set_handfusion(return_value);
        break;
    case PC_SYS_SET_LASER_POWER:
        qDebug() << __func__ << "PC_SYS_SET_LASER_POWER" << return_value;
        break;
    case PC_SYS_SET_LASERCMD:
        signal_pc_key_laser(return_value);
        break;
    case PC_SYS_SET_HDMI:
        signal_pc_sys_set_HDMI(return_value);
        break;
    case PC_SYS_GET_ESSID:
        signal_PC_SYS_GET_ESSID(return_value,QString(QLatin1String((char *)data)));
        break;
    case PC_SYS_SET_WIFI_STA:
        signal_PC_SYS_SET_WIFI_STA(return_value);
        break;
    case PC_SYS_SET_DEV_ACTIVE_SEARCH:
        if(return_value == RE_OK)
        {
            dev_client_dev_search_info dev_info;
            memcpy(&dev_info, data, sizeof(dev_client_dev_search_info));
            qDebug() << __func__ << "PC_SYS_SET_DEV_ACTIVE_SEARCH" << dev_info.search_num;
            deviceIpList.clear();
            for(int i = 0; i < dev_info.search_num; i++)
            {
                deviceIp = dev_info.ip_info[i].ip_addr;
                qDebug() << i << dev_info.ip_info[i].ip_addr << deviceIp;
                deviceIpList.append(deviceIp);
            }
            qDebug() << deviceIpList.count();
            signal_pc_sys_set_dev_active_search(return_value, deviceIpList);
        }
        else
        {
            qDebug() << __func__ << "PC_SYS_SET_DEV_ACTIVE_SEARCH" << return_value;
        }
        break;
    case PC_SYS_SET_DEV_CLIENT:
        qDebug() << __func__ << "PC_SYS_SET_DEV_CLIENT" << return_value << __LINE__;
        signal_pc_sys_set_dev_client(return_value);
        break;
    case PC_SYS_SET_QRCODE_SWITCH:
        signal_pc_sys_set_qrcode_switch(return_value);
        break;
    case PC_SYS_GET_QRCODE_INFO:
        unsigned char *buf;
        buf = data;
        buf[recv_datalen]='\0';
        signal_pc_sys_get_qrcode_info(return_value,buf);
        break;
    case PC_SYS_GET_LASERRANGE:
        int a;
        memcpy(&a,data,sizeof(int));

        qDebug() << "data" << data << a;
        signal_pc_sys_get_laserrange(return_value, a);
        break;
    case  PC_SYS_GET_APPCONTROLSTATUS:
        int c;
        memcpy(&c,data,sizeof(int));
        signal_pc_sys_get_appcontrolstatus(return_value, c);
        break;
    case  PC_SYS_SET_UPLOAD_TARGET:
        signal_pc_sys_set_upload_target(return_value);
        break;
    case PC_SYS_SET_WIFI_POWER:
        signal_pc_sys_set_wifi_power(return_value);
        break;
    case  PC_SYS_SET_LASERPOS:
        singal_pc_sys_set_laserpos(return_value);
        break;
    case  PC_SYS_GET_ZOOM:
        int d;
        memcpy(&d,data,sizeof(int));
        signal_hir_twice_get_zoom(return_value, d);
        break;
    case  PC_SYS_GET_COLORRULE:
        int e;
        memcpy(&e,data,sizeof(int));
        signal_hir_twice_get_colorrule(return_value, e);
        break;
    case PC_SYS_SET_FILEQUERY:
//        qDebug() << "printf =========== 3";
//        qDebug() << "return Size : " << recv_datalen;
//        for(int i = 0;i < recv_datalen;i++)
//        {
//            printf("%c",data[i]);
//        }
//        qDebug("PC_SYS_SET_FILEQUERY address = %x",data);
//        qDebug() << "printf =========== 4";
        signal_pc_sys_set_filequery(return_value,QString::fromUtf8((char *)data),(char *)data,recv_datalen);
        break;
    case PC_SYS_SET_LTE_POWER:
        qDebug() << "PC_SYS_SET_LTE_POWER" <<return_value;
        break;
    case PC_SYS_SET_LTE:
        qDebug() << "HpdomainPC_SYS_SET_LTE";
        signal_set_4G_state(return_value);
        break;

    case  PC_SYS_SET_DOWNLOAD:
        signal_pc_sys_set_download(return_value);
        break;
    case PC_SYS_SET_SERVICE:
        siganl_pc_sys_set_serve_con(return_value);
        break;
    case PC_SYS_SET_SEVSEND_BREAK:
        signal_pc_sys_set_sevsend_break(return_value);
        break;
    case PC_SYS_SET_BLE_POWER:
        signal_pc_sys_set_ble_power(return_value);
        break;
    case PC_SYS_SET_ANALOG_AUDIO:
        signal_pc_sys_set_analog_video(return_value);
        break;
    case PC_SYS_SET_BLE_SWITCH:
        qDebug() << "HpDomainThread::signal_pc_sys_set_ble_switch" << return_value;
        signal_pc_sys_set_ble_switch(return_value);
        break;
    case PC_SYS_SET_BLE_MODULE:
        qDebug() << "HpDomainThread::signal_pc_sys_set_ble_module" << return_value;
        signal_pc_sys_set_ble_module(return_value);
        break;
    case PC_SYS_SET_BLE_FUNCTION:
        signal_pc_sys_set_ble_function(return_value);
        break;
    case PC_SYS_GET_BLE_INFO:
    {
        char* str = (char*) data;
        qDebug() << "signal_pc_sys_get_ble_info" << str << strlen(str) << data;
        signal_pc_sys_get_ble_info(return_value, str);
    }
        break;
    case PC_SYS_GET_MATCHING_DEGREE:
        int degree;
        memcpy(&degree,data,sizeof(int));
        signal_pc_sys_get_match_degree(return_value, degree);
        break;
    case PC_SYS_GET_POSITIION_DATA:
        int b;
        memcpy(&b,data,sizeof(int));
        qDebug() << "signal_pc_sys_get_positiion_data" << return_value << b;
        signal_pc_sys_get_positiion_data(return_value, b);
        break;
    case PC_SYS_SET_IMAGE_CONTRAST:
        qDebug()<< "PC_SYS_SET_IMAGE_CONTRAST  : "<<return_value;
    default:
        break;
    }
}


void HpDomainThread::pc_key_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen)
{
    switch(recv_subcmd)
    {
    case PC_KEY_ZOOM:
        signal_pc_key_zoom(return_value);
        break;
    case PC_KEY_AUTO_RECTIFY:                           //tiaoling  //按键调零
        signal_pc_key_auto_rectify(return_value);
       pc_get_biaoding_gray( );                            //调零后，获取标定界面灰度
        break;
    case PC_KEY_SET_FREEZE:
        signal_pc_key_set_freeze(return_value);
        break;
    case PC_KEY_FOCUS_ADJUST:
        qDebug() << "PC_KEY_FOCUS_ADJUST" << return_value;
        break;
    case PC_KEY_AUTO_FOCUS:
        signal_pc_key_auto_focus(return_value);         //按下自动聚焦按钮后
        break;
    default:
        break;
    }
}
void HpDomainThread::pc_pic_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen)
{
    switch(recv_subcmd)
    {
    case PC_PIC_SET_UPLOAD:
        signal_pc_cmd_set_pc_pic(return_value);
        break;
    case PC_PIC_SET_PIC:
        signal_pc_cmd_set_pc_pic_srv(return_value);
        break;
    default:
        break;
    }
}

void HpDomainThread::core_key_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen)
{
//    qDebug() << __func__ << "=================================================" << recv_subcmd;
    QString strname;
    if(recv_subcmd == CORE_KEY_CAPTURE_STOP)
    {
        qDebug() << "Name change!!!";
        char *str1 = (char *)data;
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        strname = codec->toUnicode(str1);
    }
    switch(recv_subcmd)
    {
    case CORE_KEY_RECORD_AVI_STOP:
        signal_core_key_record_avi_stop(return_value);              //停止录像avi
        break;
    case CORE_KEY_RECORD_IR_STOP:
        signal_core_key_record_avi_stop(return_value);              //停止录像hir
        break;
    case CORE_KEY_RECORD_AVI_START:                                         //开始录像avi
        signal_core_key_record_avi_start(return_value);
        break;
    case CORE_KEY_RECORD_IR_START:                                          //开始录像hir
        qDebug() << "CORE_KEY_RECORD_IR_START" << return_value;
        signal_core_key_record_avi_start(return_value);
        break;
    case CORE_KEY_CAPTURE_START:                                        //开始拍照

        signal_core_key_capture_start(return_value);
        break;
    case CORE_KEY_CAPTURE_STOP:                                             //结束拍照
        signal_core_key_capture_stop(return_value, strname);
        break;
    case CORE_KEY_ADD_AUDIO_START:                                  //音频
        signal_core_key_add_audio_start(return_value);
        break;
    case CORE_KEY_ADD_AUDIO_STOP:
        int audioLength;
        memcpy(&audioLength,data,sizeof(int));
        qDebug() << "CORE_KEY_ADD_AUDIO_STOP" << audioLength;
        signal_core_key_add_audio_stop(return_value, audioLength);
        signal_core_key_add_audio_stop(return_value);
        break;
    case CORE_KEY_ADD_TEXT:                                             //文本
        signal_core_key_add_text(return_value);
        break;
    default:
        break;
    }
}

void HpDomainThread::core_get_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen)
{
    switch(recv_subcmd)
    {
    case CORE_GET_SD_INFO:                                      //获取SD卡容量信息
        sdinfo_t sdinfo;
        if(return_value == RE_OK)
        {
            memcpy(&sdinfo,data,sizeof(sdinfo_t));
        }
        else
        {
            memset(&sdinfo,0,sizeof(sdinfo_t));
        }
        signal_core_get_sd_info(return_value,sdinfo);
        break;
    case CORE_GET_LTE_STATUS:
        int value_4G;
        if(return_value == RE_OK)
        {
            memcpy(&value_4G,data,sizeof(int));
        }
        else
        {
            value_4G = -100;
        }
        signal_get_4G_state(return_value,value_4G);
        break;
    case CORE_GET_BATTERY:
        int battery_value;
        if(return_value == RE_OK)
        {
            memcpy(&battery_value,data,sizeof(int));
        }
        else
        {
            battery_value = 0;
        }
        signal_core_get_battery(return_value,battery_value);
        break;
    case CORE_GET_UPLOAD_STATUS:
        int upload_value;
        if(return_value == RE_OK)
        {
            memcpy(&upload_value,data,sizeof(int));
        }
        else
        {
            upload_value = -100;
        }
        signal_core_get_upload_status(return_value,upload_value);
        break;
    case CORE_GET_HIR_PLAY_STATUS:
        int hirstatue;
        if(return_value == RE_OK)
        {
            memcpy(&hirstatue,data,sizeof(int));
        }
        else
        {
            hirstatue = -100;
        }
        signal_core_get_hir_play_status(return_value,hirstatue);
        break;
    case CORE_GET_USBWIFIINSERT:
        int uwi;
        if(return_value == RE_OK)
        {
            memcpy(&uwi,data,sizeof(int));
        }
        else
        {
            uwi = -1;
        }
        signal_core_get_usbwifiinsert(return_value,uwi);
        break;
    case CORE_GET_WIFI_STA_STATUS:
        int stats;
        if(return_value == RE_OK)
        {
            memcpy(&stats,data,sizeof(int));
        }
        else
        {
            stats = -100;
        }
        signal_CORE_GET_WIFI_STA_STATUS(return_value,stats);
        break;
    case CORE_GET_CHARGE:
        int charge;
        if(return_value == RE_OK)
        {
            memcpy(&charge,data,sizeof(int));
        }
        else
        {
            charge = -1;
        }
        signal_core_get_charge(return_value,charge);
        break;
    case CORE_GET_USBINSERT:                                    //usb
        int ui;
        if(return_value == RE_OK)
        {
            memcpy(&ui,data,sizeof(int));
        }
        else
        {
            ui = -1;
        }

        signal_core_get_usbinsert(return_value,ui);
        break;
    case CORE_GET_ROTATION_TYPE:
        int ti;
        if(return_value == RE_OK)
        {
            memcpy(&ti,data,sizeof(int));
        }
        else
        {
            ti = -1;
        }
        signal_core_get_rotation_type(return_value,ti);
        break;
    case CORE_GET_SDINSERT:                                             //获取SD卡插入信息  sd_info
        int si;
        if(return_value == RE_OK)
        {
            memcpy(&si,data,sizeof(int));
        }
        else
        {
            si = -1;
        }
        signal_core_get_sdinsert(return_value,si);
        break;
    case CORE_GET_BLE_STATUS:                                             //获取SD卡插入信息  sd_info
        BleState bleState;
        if(return_value == RE_OK)
        {
            memcpy(&bleState,data,sizeof(BleState));
//            qDebug() << bleState.scan_state << bleState.pair_state << bleState.conn_state << return_value;
        }
        else
        {
            bleState.conn_state = -2;
            bleState.pair_state = -2;
            bleState.scan_state = -2;
        }
        signal_get_ble_state(return_value,bleState);
        break;
    case CORE_GET_TWICE_AUDIO_STATUS:
        int st;
        if(return_value == RE_OK)
        {
            memcpy(&st,data,sizeof(int));
        }
        else
        {
            st = 0;
        }
        signal_core_get_twice_audio_status(return_value, st);
        break;
    default:
        break;
    }
}
void HpDomainThread::core_ctrlcore_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen)
{
    switch(recv_subcmd)
    {
    case CORE_CTRLCORE_START_ENCODE:
        signal_core_ctrlcore_start_encode(return_value);
        break;
    case CORE_CTRLCORE_STOP_ENCODE:
        signal_core_ctrlcore_stop_encode(return_value);
        break;
    default:
        break;
    }
}

void HpDomainThread::core_analysis_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen)
{
    switch(recv_subcmd)
    {
    case CORE_ANALYSIS_PIC_TWICE_START:
        signal_core_annlysis_pic_twice_start(return_value);
        break;
    case CORE_ANALYSIS_PIC_TWICE_STOP:
        signal_core_annlysis_pic_twice_stop(return_value);
        break;
    case CORE_ANALYSIS_HIR_TWICE_START:
        signal_core_analysis_hir_twice_start(return_value);
        break;
    case CORE_ANALYSIS_HIR_TWICE_STOP:
        signal_core_analysis_hir_twice_stop_cut(return_value);
        break;
    case CORE_ANALYSIS_HIR_TWICE_SUSPEND:
        signal_core_annlysis_hir_twice_suspend(return_value);
        break;
    case CORE_ANALYSIS_PIC_TWICE_AUDIOPLAY_START:
        signal_core_analysis_pic_twice_audioplay_start(return_value);
        break;
    case CORE_ANALYSIS_PIC_TWICE_AUDIOPLAY_STOP:
        signal_core_analysis_pic_twice_audioplay_stop(return_value);
        break;
    case CORE_ANALYSIS_PIC_TWICE_AUDIOCAP_START:
        signal_core_analysis_pic_twice_audiocap_start(return_value);
        break;
    case CORE_ANALYSIS_PIC_TWICE_ADDAUDIO:
        qDebug() << "CORE_ANALYSIS_PIC_TWICE_ADDAUDIO" << return_value;
        break;
    case CORE_ANALYSIS_PIC_TWICE_AUDIOCAP_STOP:
        signal_core_analysis_pic_twice_audiocap_stop(return_value);
        break;
    case CORE_ANALYSIS_HIR_TWICE_LOCKSTATUS:
        signal_hir_twice_lockstatus(return_value);
        break;
    default:
        break;
    }
}

//biaoding
/**********************************************************************
 *主类为标定类。根据子类的值来判断我们要进行的操作和相关数据的处理
 *  第一个为子类。第二个为值.
***********************************************************************/
void HpDomainThread::core_biaoding_process(unsigned char recv_subcmd, unsigned char return_value, unsigned char *data, int recv_datalen)
{
    qDebug() << "core_biaoding_process recv_subcmd = 0x" << hex << recv_subcmd << "return_value =" << return_value << "datalen =" << recv_datalen;

    switch(recv_subcmd)
    {
    case CORE_FPGAMENU_ZN:
        isGetBiaoDingPara = true;
        int zn_value;
        zn_value = *data;
        qDebug() << " HpDomainThread::core_biaoding_process" << zn_value;
        signal_core_biaoding_zn(zn_value);                                              //信号，传递标定区号给界面 core 表示内核传递过来
        pc_get_biaoding_canshu( );                                                 //信号， 向内核索取 标定界面参数值。 pc表示界面传递过去
        break;
     case CORE_FPGAMENU_GET_PARA:
        FPGAMenuPara fpgaPara;
        memcpy(&fpgaPara,data,sizeof(FPGAMenuPara));
        signal_core_biaoding_canshu(fpgaPara);                                  //信号，传递标定参数   给界面 core 表示内核传递过来
        break;
    case CORE_FPGAMENU_FOCUS_OFFSET:
        signal_pc_focus_offset(return_value);                                  //信号，传递标定参数   给界面 core 表示内核传递过来
        break;
    case CORE_FPGAMENU_GET_GRAY:
//        unsigned char buf1[128];
        {
            FPGAMenuGray grayData;
            memcpy(&grayData, data, sizeof(FPGAMenuGray));
//            qDebug() << "[GET_GRAY] send: MaxGray=" << grayData.MaxGray
//                     << "MinGray=" << grayData.MinGray
//                     << "ZeroGray=" << grayData.ZeroGray;
            signal_core_biaoding_gray(grayData);
        }
    case CORE_FPGAMENU_ZERO:      //收到调零信号成功.(标定界面的)（主界面不相应这个槽）
        {

        }
        break;
    case CORE_FPGAMENU_BADLINE_X :
        signal_set_core_fpgamenu_badline_x(return_value);
        break;
    case CORE_FPGAMENU_BADLINE_Y:
        signal_set_core_fpgamenu_badline_y(return_value);
        break;
    case CORE_FPGAMENU_IAMGE_ENHANCE:
        signal_biaoding_DDE(return_value);                                  //信号，传递标定参数   给界面 core 表示内核传递过来
        break;
    case CORE_FPGAMENU_SEPARA:
        signal_pc_spinbox_para(return_value);                                  //信号，传递标定参数   给界面 core 表示内核传递过来
        break;
    case CORE_FPGAMENU_SEZOOM:
        signal_pc_spinbox_zoom(return_value);                                  //信号，传递标定参数   给界面 core 表示内核传递过来
        break;
    case CORE_FPGAMENU_IMAGE_ROTATE:
        signal_pc_checkbox_rotate(return_value);                                  //信号，传递标定参数   给界面 core 表示内核传递过来
        break;
    case CORE_FPGAMENU_NONCOOL_CORRECT:
        qDebug() << " CORE_FPGAMENU_NONCOOL_CORRECT " << return_value;
        break;
    case CORE_FPGAMENU_SET_INTCP:
        qDebug() << " CORE_FPGAMENU_SET_INTCP " << return_value;
        break;
    case CORE_FPGAMENU_SET_ADGAIN:
        qDebug() << " CORE_FPGAMENU_SET_ADGAIN " << return_value;
        break;
    case CORE_FPGAMENU_SET_SVRD:
        qDebug() << " CORE_FPGAMENU_SET_SVRD " << return_value;
        break;
    case CORE_FPGAMENU_SET_FOS:
        qDebug() << " CORE_FPGAMENU_SET_FOS " << return_value;
        break;
    case CORE_FPGAMENU_SET_OCC_ENABLE:
        qDebug() << " CORE_FPGAMENU_SET_OCC_ENABLE " << return_value;
        break;
    case CORE_FPGAMENU_ORITOGGLE:
        signal_core_fpgamenu_oritoggle(return_value);                                  //信号，传递标定参数   给界面 core 表示内核传递过来
        break;
    case CORE_FPGAMENU_AUTO_BADPIXEL:
        signal_core_fpgamenu_auto_badixel(return_value);                                  //信号，传递标定参数   给界面 core 表示内核传递过来
        break;
    case CORE_FPGAMENU_BADPIXEL_RECOVER:
        signal_core_fpgamenu_badpixel_recover(return_value);                                  //信号，传递标定参数   给界面 core 表示内核传递过来
        break;
    case CORE_FPGAMENU_GET_VER:
    {
        qDebug() << "signal_core_fpga_get_ver(return_value,ver_value) == > " << *data;
        int ver_value;
        ver_value = *(int *)data;
        signal_core_fpga_get_ver(return_value,ver_value);                                             //信号， 向内核索取 标定界面参数值。 pc表示界面传递过去
    }
        break;
    case CORE_FPGAMENU_NOISE_TIME_PARA:
        qDebug() << __func__ << "CORE_FPGAMENU_NOISE_TIME_PARA" << return_value;
        break;
    case CORE_FPGAMENU_NOISE_AIRSPACE_PARA:
        qDebug() << __func__ << "CORE_FPGAMENU_NOISE_AIRSPACE_PARA" << return_value;
        break;
    case CORE_FPGAMENU_GET_INTCP:
    {
        qDebug() << __func__ << "CORE_FPGAMENU_GET_INTCP" << return_value;
        int intcp_value;
        intcp_value = *(int *)data;
        signal_core_fpga_get_intcp(return_value,intcp_value);
    }
    break;
    case CORE_FPGAMENU_GET_ADGAIN:
    {
        qDebug() << __func__ << "CORE_FPGAMENU_GET_ADGAIN" << return_value;
        int adgain_value;
        adgain_value = *(int *)data;
        signal_core_fpga_get_adgain(return_value,adgain_value);
    }
    break;
    case CORE_FPGAMENU_GET_SVRD:
    {
        qDebug() << __func__ << "CORE_FPGAMENU_GET_SVRD" << return_value;
        int svrd_value;
        svrd_value = *(int *)data;
        signal_core_fpga_get_svrd(return_value,svrd_value);
    }
    break;
    case CORE_FPGAMENU_GET_FOS:
    {
        qDebug() << __func__ << "CORE_FPGAMENU_GET_FOS" << return_value;
        int fos_value;
        fos_value = *(int *)data;
        signal_core_fpga_get_fos(return_value,fos_value);
    }
    break;
     default:
         break;
    }
}
//*********************************************************标定
//pc发送给内核消息--->启动界面时调用。生产标定界面获取区号
void HpDomainThread::slot_pc_send_biaoding()
{
    qDebug() << "HpDomainThread::slot_pc_send_biaoding()";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_ZN,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_send_biaoding  error";
    return;
}
//pc发送给内核消息--->获取区号后调用。生产标定界面获取参数值
void HpDomainThread::pc_get_biaoding_canshu()
{

    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_GET_PARA,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"pc_get_biaoding_canshu  error";


    return;

}
//pc发送给内核消息--->获取区号后调用。生产标定界面获取参数值  gray
//第二种调用方式：标定界面按Q
void HpDomainThread::pc_get_biaoding_gray( )
{

    int ret ,totallen;
    unsigned char buf[1024];
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_GET_GRAY,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
        qDebug()<<"pc_get_biaoding_gray  error";
    return;

}

//pc发送给内核消息--->界面设置后  将参数结构体发送到内核
void HpDomainThread::slot_pc_biaoding_canshu(FPGAMenuPara para)
{

    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_SET_PARA,0,(unsigned char *)&para,sizeof(FPGAMenuPara),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_biaoding_canshu  error";
    return;

}
void HpDomainThread::slot_pc_save_focus_offset(int para)
{

    int ret ,totallen;
    unsigned char buf[1024];

   qDebug() << "HpDomainThread::slot_pc_focus_offset para == > " << para;
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_FOCUS_OFFSET,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_focus_offset  error";
    return;

}

void HpDomainThread::slot_pc_focus_offset(ComFocusOffset para)
{
    qDebug() << "HpDomainThread::slot_pc_focus_offset";
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_FOCUS_OFFSET,0,(unsigned char *)&para,sizeof(ComFocusOffset),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_focus_offset  error";
    return;
}

//1：获取参数para 后。 再获取gray : 避免数据覆盖
//2：标定界面按Q

  void HpDomainThread::slot_biaoding_para_ok( )
  {
           pc_get_biaoding_gray( );                                                    //信号，向内核索取   标定界面的 gray。
  }

//界面按HI.发送给内核
  void HpDomainThread::slot_biaoding_HI( )
  {
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_HI,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_biaoding_HI  error";
    return;

  }
//界面按LO.发送给内核
  void HpDomainThread::slot_biaoding_LO( )
  {
    int ret ,totallen;
    unsigned char buf[1024];

   totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_LO,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_biaoding_LO  error";
    return;

  }
//界面按SAVE.发送给内核
  void HpDomainThread::slot_biaoding_SAVE( )
  {
    int ret ,totallen;
    unsigned char buf[1024];

  totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_SAVE,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_biaoding_SAVE  error";
    return;

  }
//界面 biaoding ' mainwidget  上相应Q实现 调零信号的发送
  //tiaoling
  void HpDomainThread::slot_all_tiaoling( )
  {
        slot_pc_key_auto_rectify( );
         /*
        qDebug()<<" tiaoling : :CORE_FPGAMENU_ZERO";
        int ret ,totallen;
        unsigned char buf[1024];

      totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_ZERO,0,NULL,0,0);
        ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

        if(ret <0)
            qDebug()<<"slot_all_tiaoling  error";
        return;
        */
  }
//



//************************隐藏菜单hidemenu。画框display. 打死点
// hidemenu  point rect
void HpDomainThread::slot_hidemenu_point_enable(bool checked )
{
    if(true == checked)
    {
        ComPointBadPixel para;
        para.xcoord = 192;
        para.ycoord = 136;

        int ret ,totallen;
        unsigned char buf[1024];

        totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_POINT_BADPIXEL,0,(unsigned char *)&para,sizeof(ComPointBadPixel),0);
        ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

        if(ret <0)
            qDebug()<<"slot_hidemenu_point_enable  error";
        return;
    }
    else{
        return;
    }
}


void HpDomainThread::slot_hidemenu_rect_enable(bool checked )
{
    if(true == checked)
    {
        ComRectBadPixel para;
        para.start_x = 144;
        para.start_y = 102;
        para.width = 96;
        para.high = 68;

        int ret ,totallen;
        unsigned char buf[1024];

        totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_RECT_BADPIXEL,0,(unsigned char *)&para,sizeof(ComRectBadPixel),0);
        ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

        if(ret <0)
            qDebug()<<"slot_hidemenu_rect_enable  error";
        return;
    }else{
        return;
    }
}
//display松开手后发送坐编标
void HpDomainThread::slot_display_rect(unsigned char *data,int recv_datalen)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_RECT_BADPIXEL,0,data,recv_datalen,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_display_rect  error";
    return;
}
//display松开手后发送坐编标  界面图片
void HpDomainThread::slot_display_point(unsigned char *data,int recv_datalen)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_POINT_BADPIXEL,0,data,recv_datalen,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_display_point  error";
    return;
}

//快捷键，ctrl+a  (坏点)
void HpDomainThread::slot_dandian_sidian()
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_dandian_sidian Send CORE_FPGAMENU_DEL_BADPIXEL";

    int data = 1;
   totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_DEL_BADPIXEL,0,(unsigned char *)&data,4,0);
   ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_dandian_sidian  error";
    return;
}


//ctrl + s   (高温)
void HpDomainThread::slot_gaowen_sidian()
{

    int ret ,totallen;
    unsigned char buf[1024];

    int data =2;
    qDebug() << "HpDomainThread::slot_dandian_sidian Send CORE_FPGAMENU_DEL_BADPIXEL";

   totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_DEL_BADPIXEL,0,(unsigned char *)&data,4,0);
   ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_gaowen_sidian  error";
    return;

}

//ctrl + d   (低温)
void HpDomainThread::slot_diwen_sidian()
{
    int ret ,totallen;
    unsigned char buf[1024];
    qDebug() << "HpDomainThread::slot_dandian_sidian Send CORE_FPGAMENU_DEL_BADPIXEL";

    int data =3;
   totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_DEL_BADPIXEL,0,(unsigned char *)&data,4,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_diwen_sidian  error";
    return;

}
void HpDomainThread::slot_pc_cfg_get_pointconfig()
{
        int ret ,totallen;
        unsigned char buf[1024];

//            qDebug()<<"gggggggggg111";
       totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_CFG,PC_CFG_GET_POINTCONFIG,0,NULL,0,0);
        ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

        if(ret <0)
            qDebug()<<"slot_pc_cfg_get_pointconfig  error";
        return;
}
void HpDomainThread::slot_pc_cfg_get_lineconfig()
{
        int ret ,totallen;
        unsigned char buf[1024];

//            qDebug()<<"gggggggggg222";
       totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf, 1024, PC_CFG, PC_CFG_GET_LINECONFIG, 0, NULL, 0, 0);
        ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

        if(ret <0)
            qDebug()<<"slot_pc_cfg_get_lineconfig  error";
        return;
}
void HpDomainThread::slot_pc_cfg_get_rectconfig()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf, 1024, PC_CFG, PC_CFG_GET_RECTCONFIG, 0, NULL, 0, 0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_cfg_get_rectconfig  error";
    return;
}

void HpDomainThread::slot_pc_cfg_get_circleconfig()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf, 1024, PC_CFG, PC_CFG_GET_CIRCLECONFIG, 0, NULL, 0, 0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"PC_CFG_GET_CIRCLECONFIG  error";
    return;
}

void HpDomainThread::slot_dev_get_parameter()
{
    int ret ,totallen;
    unsigned char buf[1024];

   totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_CFG,PC_CFG_GET_SYSCONFIG,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_diwen_sidian  error";
    return;

}

void HpDomainThread::slot_pc_key_auto_focus()
{
//        qDebug( )<<"slot_pc_key_auto_focus";
    int ret ,totallen;
    unsigned char buf[1024];

   totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_KEY,PC_KEY_AUTO_FOCUS,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_key_auto_focus  error";
    return;
}

void HpDomainThread::slot_pc_key_focus_near()
{
    int ret ,totallen;
    unsigned char buf[1024];

   totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_KEY,PC_KEY_FOCUS_NEAR,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_key_focus_near  error";
    return;

}

void HpDomainThread::slot_pc_key_focus_far()
{
    int ret ,totallen;
    unsigned char buf[1024];

   totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_KEY,PC_KEY_FOCUS_FAR,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_key_focus_far  error";
    return;
}

void HpDomainThread::slot_pc_key_focus_stop()
{
    int ret ,totallen;
    unsigned char buf[1024];

   totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_KEY,PC_KEY_FOCUS_STOP,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_key_focus_stop  error";
    return;
}

void HpDomainThread::slot_pc_key_focus_adjust(int flag)
{
       qDebug() << "slot_pc_key_focus_adjust" << flag;
    int ret ,totallen;
    unsigned char buf[1024];

   totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_KEY,PC_KEY_FOCUS_ADJUST,0,(unsigned char *)&flag,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_key_focus_adjust  error";
    return;
}

void HpDomainThread::slot_pc_key_focus_select(int flag)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen =p_hpprotocolpkg-> protocol_pkg_hp_create(buf,1024,PC_KEY,PC_KEY_FOCUS_SELECT,0,(unsigned char *)&flag,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
    qDebug()<<"slot_pc_key_focus_adjust  error";
    return;
}

void HpDomainThread::slot_pc_osd_set_osdstat(OsdSetting para)
{
//       qDebug( )<<"slot_pc_osd_set_osdstat";
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug()<<"yyyyyyyyyyyyyyyyyyyyy para.color_ruler "<<para.color_ruler;
    qDebug()<<"yyyyyyyyyyyyyyyyyyyy0"<<QString(para.pid3100);
   totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_OSD,PC_OSD_SET_OSDSTAT,0,(unsigned char *)&para,sizeof(OsdSetting),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_osd_set_osdstat  error";
    return;
}

void HpDomainThread::ceshi(unsigned char *data,int recv_datalen)
{
/*  FPGAMenuPara    *fpgamenu_para = (FPGAMenuPara*)data;           //强制转换
    qDebug()<<fpgamenu_para->VS;
    qDebug()<<fpgamenu_para->VF;
    qDebug()<<fpgamenu_para->Gain;
    qDebug()<<fpgamenu_para->INT;
    qDebug()<<recv_datalen;
*/
}
void HpDomainThread::slot_pc_get_measure_get_temp()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_GET_TEMP,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_get_measure_get_collect(int value)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg-> protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_GET_COLLECT,0,(unsigned char *)&value,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_measure_set_compensate(int compensate)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug()<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<compensate;
    //totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_KEY,CORE_KEY_CAPTURE_STOP,0,(unsigned char *)&type,sizeof(int),0);
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_TEMPADJUST,0,(unsigned char *)&compensate,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slt_pc_sys_get_laserrange()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_LASERRANGE,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_light_power(int power)
{
    int ret ,totallen;
    unsigned char buf[1024];
//
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_LIGHT,0,(unsigned char *)&power,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_powerdown(int power)
{
    int ret ,totallen;
    unsigned char buf[1024];
//
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_POWERDOWN,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_screensleep(int power)
{
    int ret ,totallen;
    unsigned char buf[1024];
//
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_SCREENSLEEP,0,(unsigned char *)&power,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_laser_power(int power)
{
    int ret ,totallen;
    unsigned char buf[1024];
//
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_LASER_POWER,0,(unsigned char *)&power,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_key_laser(int index)
{
    int ret ,totallen;
    unsigned char buf[1024];
//
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_LASERCMD,0,(unsigned char *)&index,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_image_set_abnormal(int isSet)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_SET_ABNORMAL,0,(unsigned char *)&isSet,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_set_core_fpgamenu_badline_x(int x)
{
    int ret, totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_BADLINE_X,0,(unsigned char *)&x,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}

void HpDomainThread::slot_set_core_fpgamenu_badline_y(int y)
{
    int ret, totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_BADLINE_Y,0,(unsigned char *)&y,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}

void HpDomainThread::slot_set_4G_power(int value)
{
    int ret, totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_set_4G_state Send PC_SYS_SET_LTE == > " << value;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_LTE_POWER,0,(unsigned char *)&value,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);
    qDebug() << "<=============================================slot_set_4G_state buf" << buf;
    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}

void HpDomainThread::slot_set_4G_state(int num)
{
    int ret, totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_set_4G_state Send PC_SYS_SET_LTE == > " << num;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_LTE,0,(unsigned char *)&num,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);
    qDebug() << "<=============================================slot_set_4G_state buf" << buf;
    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}

void HpDomainThread::slot_get_4G_state()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_LTE_STATUS,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);
//    qDebug() << "slot_get_4G_state" << buf;
    if(ret < 0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_get_positiion_data()
{
    qDebug() << "slot_pc_sys_get_positiion_data";
    int ret ,totallen;
    unsigned char buf[1024];
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_POSITIION_DATA,0,(unsigned char *)0,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_laserpos(int index)
{
    int ret, totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_LASERPOS,0,(unsigned char *)&index,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}
void HpDomainThread::slot_hir_twice_get_zoom()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_ZOOM,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_hir_twice_get_colorrule()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_COLORRULE,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_hir_twice_lockstatus(int v)
{
    int ret, totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_ANALYSIS,CORE_ANALYSIS_HIR_TWICE_LOCKSTATUS,0,(unsigned char *)&v,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}
void HpDomainThread::slot_pc_sys_set_filequery(ftp_para para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_FILEQUERY,0,(unsigned char *)&para,sizeof(ftp_para),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_download(ftp_para para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_DOWNLOAD,0,(unsigned char *)&para,sizeof(ftp_para),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_image_hir_composite(char *name)
{
    int ret ,totallen;
    unsigned char buf[1024];

//    qDebug() << "HIR Play Start test";

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_IMAGE,PC_IMAGE_HIR_COMPOSITE,0,(unsigned char *)name,strlen(name),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_core_get_hir_play_status()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_GET,CORE_GET_HIR_PLAY_STATUS,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_HDMI_switch(int index)
{
    int ret ,totallen;
    unsigned char buf[1024];
//
    qDebug() << ">> HpDomainThread::slot_pc_sys_set_HDMI_switch PC_SYS ; PC_SYS_SET_HDMI value  == > " << index;
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_HDMI,0,(unsigned char *)&index,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_serve_con(client_para para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_SERVICE,0,(unsigned char *)&para,sizeof(client_para),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_newserve_con(server_para para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_SERVICE,0,(unsigned char *)&para,sizeof(server_para),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_cmd_set_pc_pic_srv(char *photoname)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_pc_cmd_set_pc_pic_srv";

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_PIC,PC_PIC_SET_PIC,0,(unsigned char *)photoname,strlen(photoname),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_sevsend_break()
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_pc_sys_set_sevsend_break Send PC_SYS_SET_SEVSEND_BREAK";

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_SEVSEND_BREAK,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_biaoding_DDE(int val)
{
    int ret, totallen;
    unsigned char buf[1024];

    qDebug() << " HpDomainThread::slot_biaoding_DDE == > " << val;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_IAMGE_ENHANCE,0,(unsigned char *)&val,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}
void HpDomainThread::slot_pc_checkbox_rotate(ComTempRange val)
{
    int ret, totallen;
    unsigned char buf[1024];

    qDebug() << " HpDomainThread::slot_pc_checkbox_rotate  CORE_FPGAMENU_IMAGE_ROTATE";

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_IMAGE_ROTATE,0,(unsigned char *)&val,sizeof(ComTempRange),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}

void HpDomainThread::slot_core_fpgamunu_noncool_correct(int para)
{
    qDebug()<<"HpDomainThread::slot_core_fpgamunu_noncool_correct" << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_NONCOOL_CORRECT,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_pc_image_set_imagetype  error";
    return;
}


void HpDomainThread::slot_core_fpga_get_svrd()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_GET_SVRD,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_fpga_get_adgain()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_GET_ADGAIN,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_fpga_get_intcp()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_GET_INTCP,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_fpga_get_fos()
{
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_GET_FOS,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_core_fpgamunu_set_intcp(int para)
{
    qDebug()<<"HpDomainThread::slot_core_fpgamunu_set_intcp" << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_SET_INTCP,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_core_fpgamunu_set_intcp  error";
    return;
}

void HpDomainThread::slot_core_fpgamunu_set_adgain(int para)
{
    qDebug()<<"HpDomainThread::slot_core_fpgamunu_set_adgain" << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_SET_ADGAIN,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_core_fpgamunu_set_adgain  error";
    return;
}

void HpDomainThread::slot_core_fpgamunu_set_svrd(int para)
{
    qDebug()<<"HpDomainThread::slot_core_fpgamunu_set_svrd" << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_SET_SVRD,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_core_fpgamunu_set_svrd  error";
    return;
}

void HpDomainThread::slot_core_fpgamunu_set_fos(int para)
{
    qDebug()<<"HpDomainThread::slot_core_fpgamunu_noncool_correct" << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_SET_FOS,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_core_fpgamunu_set_fos  error";
    return;
}

void HpDomainThread::slot_core_fpgamunu_set_occ_enable(int para)
{
    qDebug()<<"HpDomainThread::slot_core_fpgamunu_set_occ_enable" << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_SET_OCC_ENABLE,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_core_fpgamunu_set_occ_enable  error";
    return;
}

void HpDomainThread::slot_core_fpgamenu_noise_time_para(int para)
{
    qDebug()<<"HpDomainThread:" << __func__ << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_NOISE_TIME_PARA,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_core_fpgamunu_set_fos  error";
    return;
}

void HpDomainThread::slot_core_fpgamenu_noise_airspace_para(int para)
{
    qDebug()<<"HpDomainThread:" << __func__ << para;
    int ret ,totallen;
    unsigned char buf[1024];

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_NOISE_AIRSPACE_PARA,0,(unsigned char *)&para,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"slot_core_fpgamunu_set_fos  error";
    return;
}

void HpDomainThread::slot_core_fpgamenu_oritoggle(int val)
{
    int ret, totallen;
    unsigned char buf[1024];

    qDebug() << " HpDomainThread::slot_core_fpgamenu_oritoggle == > " << val;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_ORITOGGLE,0,(unsigned char *)&val,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}
void HpDomainThread::slot_core_fpgamenu_auto_badixel(int val)
{
    int ret, totallen;
    unsigned char buf[1024];

    qDebug() << " HpDomainThread::slot_core_fpgamenu_auto_badixel == > " << val;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_AUTO_BADPIXEL,0,(unsigned char *)&val,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}


void HpDomainThread::slot_core_fpgamenu_value_badixel(int val)
{
    int ret, totallen;
    unsigned char buf[1024];

    qDebug() << " HpDomainThread::slot_core_fpgamenu_value_badixel == > " << val;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_BADPIXEL_PARA,0,(unsigned char *)&val,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}
void HpDomainThread::slot_core_fpgamenu_badpixel_recover()
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_core_fpgamenu_badpixel_recover Send CORE_FPGAMENU_BADPIXEL_RECOVER";

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_BADPIXEL_RECOVER,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_spinbox_para(int val)
{
    int ret, totallen;
    unsigned char buf[1024];

    qDebug() << " HpDomainThread::slot_pc_spinbox_para  CORE_FPGAMENU_SEPARA == > " << val;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_SEPARA,0,(unsigned char *)&val,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}
void HpDomainThread::slot_pc_spinbox_zoom(int val)
{
    int ret, totallen;
    unsigned char buf[1024];

    qDebug() << " HpDomainThread::slot_pc_spinbox_zoom  CORE_FPGAMENU_SEZOOM == > " << val;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,CORE_FPGAMENU,CORE_FPGAMENU_SEZOOM,0,(unsigned char *)&val,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret < 0)
    {
        qDebug("Domain_send_error");
    }
    return;
}
void HpDomainThread::slot_pc_sys_wifi_power(int val)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_pc_sys_wifi_power Send PC_SYS_SET_WIFI_POWER ==> " << val;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_WIFI_POWER,0,(unsigned char *)&val,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_qrcode_switch(int index)
{
    int ret ,totallen;
    unsigned char buf[1024];
//
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_QRCODE_SWITCH,0,(unsigned char *)&index,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_set_step_zero(int index)
{
    int ret ,totallen;
    unsigned char buf[1024];
//
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_STEP_ZERO,0,(unsigned char *)&index,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);
    qDebug()<<"Domain_send slot_pc_sys_set_step_zero" << index << ret;

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}

void HpDomainThread::slot_pc_sys_get_qrcode_info()
{
    int ret ,totallen;
    unsigned char buf[1024];
    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_GET_QRCODE_INFO,0,(unsigned char *)0,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_measure_mulhomogeneity(int val)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug("HpDomainThread::slot_pc_measure_mulhomogeneity PC_MEASURE_MULHOMOGENEITY %x",val);
//    qDebug() << "HpDomainThread::slot_pc_measure_mulhomogeneity Send PC_MEASURE_MULHOMOGENEITY ==> " << (unsigned int)val;

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_MULHOMOGENEITY,0,(unsigned char *)&val,sizeof(int),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_sys_set_laserrange()
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_pc_sys_set_laserrange Send PC_SYS_SET_LASERRANGE";

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_SYS,PC_SYS_SET_LASERRANGE,0,NULL,0,0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
void HpDomainThread::slot_pc_measure_temprange_query(ComTempRange para)
{
    int ret ,totallen;
    unsigned char buf[1024];

    qDebug() << "HpDomainThread::slot_pc_measure_temprange_query Send PC_MEASURE_TEMPRANGE_QUERY";

    totallen = p_hpprotocolpkg->protocol_pkg_hp_create(buf,1024,PC_MEASURE,PC_MEASURE_TEMPRANGE_QUERY,0,(unsigned char *)&para,sizeof(ComTempRange),0);
    ret = p_hpdomainapi->Domain_send(sock_fd,buf,totallen);

    if(ret <0)
        qDebug()<<"Domain_send error";
    return;
}
