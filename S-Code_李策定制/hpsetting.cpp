
#include  "ui_hpsetting.h"
#include  "hpsetting.h"
#include  "mainwidget.h"

HpSetting::HpSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HpSetting)
{
    m_isS3X0 = 0;
    swiftingCounter = 0;
    usbmode_init =true;
    isGpsOpen = false;
    recordmode_init = true;
    baojingshezhi_init = true;
    baojingse_init = true;
    jingtou_init = true;
    wendang_init = true;
    jingtou_dangwei_change = false;
    temp_tab_change = false;
    ReferTemp_enable_first =true;
    isTempCaptureSwitch=false;
    onlcdonce = false;
    isTaskMode = false;
    jingtou_num=0;
    dangwei_num=0;
    getWifiWait = 0;
    compensateValue=0;
    jingtouhide = 0;
    m_reflectType = -1;
    eth_num = 0;
    IsInEth = false;
    eth_change = false;

    jingtouRow = 0;
    dangweiRow = 0;
    blePower = false;
    bleSwitch = false;
    isOtherm = false;
    isWIFISearch = false;
    isWIFIServer = false;
    onceUpload = false;
    download = false;
    isManualCall = false;
    fidpid = false;
    isNewBle = false;
    canbercv = false;
    tempWengdangchange = false;
    fastfocusmode = false;
    guowangFlag = false;
    isWifiInsert = false;
    panoramaFlag = false;
    isBleOpen = false;

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    screensave_time = screensave_time_old = 7;
    autoUpdateIsChecked = false;
    wifiIsSelect = false;
    ui->setupUi(this);
     ui->cwfw_autorectify->setSpecialValueText(tr("自动校正间隔：关闭"));
    if(HP_ReflectTemp == 0)
    {
        ui->ScrollBar_ReflectTemp->hide();
        ui->checkBox_ReferTemp_enable->setGeometry(41,292,70,40);
        ui->ScrollBar_transmission->setGeometry(116,236,366,44);
        ui->ScrollBar_ReferTemp->setGeometry(116,292,366,44);
        ui->ScrollBar_TempUnit->setGeometry(116,348,366,44);
        ui->ScrollBar_ReflectTemp->setGeometry(116,404,366,44);
    }
    if(HP_Time !=1)
    {
        ui->dateTimeEdit->setEnabled(false);
    }
    m_isOpenCircle = false;
    m_isOpenPolygon = false;
    language_changing = false;
    ui->ble_edit->close();
    ui->label_11->setVisible(false);
    unitconverting = false;

    ui->wifi_edit->close();
    ui->autoUpload_edit->close();

    ui->ScrollBar_Radiance->setSuffix("%");
    ui->ScrollBar_Distance->setSuffix("m");
    ui->ScrollBar_Humidity->setSuffix("%");
    ui->ScrollBar_transmission->setSuffix("%");

    ui->hp_logo->set_hp_button_status_image_select("res/zh/hp_logo.png");
    ui->hp_logo->set_hp_button_status_image_normal("res/zh/hp_logo.png");
    ui->hp_logo->set_hp_button_status_image_disable("res/zh/hp_logo.png");
    ui->hp_logo->set_hp_button_checked_enable(true);
    ui->hp_logo->setDisabled(true);

    //隐藏等温色和等温色设置
    ui->label_30->setEnabled(false);
    ui->dengwengse_edit->setEnabled(false);
    ui->dengwengse_edit->close();
    ui->label_30->close();


    QTabBar *tabBar=ui->tabWidget->findChildren<QTabBar*>().at(0);
    p_tws = new HpTabWidgetStyle;

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hpdefault = new hp_DefaultDialog(this);

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hpformat = new Hp_FormatDialog(this);

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hpdialog = new Hp_Dialog(this);
//    hpsetadjust = new HpSetting_adjust(this);//无作用

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hp_wifi_Search = new Hp_Wifi_Search(this);
    hp_wifi_Search->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hp_autoupload = new hp_AutoUpLoad(this);
    hp_autoupload->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hp_Common_dialog_select = new hp_common_dialog_select(this);
    hp_Common_dialog_select->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hp_downLoad = new hp_download(this);
    hp_downLoad->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hp_autoupload_dialog = new Hp_Autoupload_Dialog(this);
    hp_autoupload_dialog->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    m_transmissionSearch  = new Hp_TransmissionSearch(this);
    m_transmissionSearch->close();
    m_Transmission = new hp_transmission;

    m_transmissionStart = false;
    m_transmissionIsSearch = false;
    hp_Mulhom_edit = new hp_mulhom_edit(this);
    hp_Mulhom_edit->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

//    hpsetadjust->close();
    hpdialog->close();
    tempjingdu = 1;
    autorectify_time_back = 150;
    hpcpumem = new HpCpuMem(this);
    hpcpumem->hide();
    ui->checkBox_angel->setVisible(false);
    ui->checkBox_volume->setVisible(false);
    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    ui->listWidget_recordmode->close();
    ui->dengwengse_edit->close();
    ui->label_30->close();
    ui->listWidget_modeSelect->close();
#if TaiZhang_Mode
    ui->label_32->setGeometry(20,225,168,50);   //台账模式
    ui->frame_modeSelect->setGeometry(210,228,243,44);
    ui->listWidget_modeSelect->setGeometry(210,272,243,70);

    ui->label_19->setGeometry(20,275,168,50);   //usb模式
    ui->frame_usbmode->setGeometry(210,278,243,44);
    ui->listWidget_usbmode->setGeometry(210,322,243,70);

    ui->label_29->setGeometry(20,325,168,50);  //录制模式
    ui->frame_recordmode->setGeometry(210,328,243,44);
    ui->listWidget_recordmode->setGeometry(210,372,243,70);

    ui->label_24->setGeometry(20,375,168,50);  //自动存储
    ui->spinBox_autosave->setGeometry(210,378,243,44);
#endif

    if(!isOtherm)     //1表示等温线关闭  0 表示等温线开启
    {
        ui->dengwengse_edit->show();
        ui->label_30->show();
        ui->dengwengse_edit->setGeometry(330,430,100,44);
        ui->label_30->setGeometry(124,430,150,44);
        ui->label_30->setEnabled(true);
        ui->dengwengse_edit->setEnabled(true);
        ui->comboBox_buchangwendu->close();
    }

    //将所有相关控件关闭
    alreadyClosed = true;
    ui->autoUpload_edit->close();
    ui->btautoUpload_once->close();
    ui->ble_edit->close();
    ui->buguangdeng->close();
    ui->checkBox_ble->close();
    ui->checkBox_area->close();
    ui->checkBox_fid->close();
    ui->checkBox_pid->close();
    ui->checkBox_wifi->close();
    ui->comboBox_usbmode->close();
    ui->wifi_edit->close();
    ui->checkBox_autoUpload->close();
    ui->btdownload->close();
    ui->label_31->close();//自动上传
    ui->label_16->close();//wifi
    ui->label_17->close();//补光灯
    ui->label_18->close();//蓝牙
    ui->label_21->close();//area
    ui->label_27->close();//fid
    ui->label_28->close();//pid
    ui->label_51->close();//草图
    ui->checkBox_sketch->close();
    ui->sketch_edit->close();
    ui->label_50->close();//ETH
    ui->checkBox_eth->close();
    //以下为控件全部失能
    ui->autoUpload_edit->setEnabled(false);;
    ui->ble_edit->setEnabled(false);
    ui->buguangdeng->setEnabled(false);
    ui->checkBox_ble->setEnabled(false);
    ui->checkBox_area->setEnabled(false);
    ui->checkBox_fid->setEnabled(false);
    ui->checkBox_pid->setEnabled(false);
    ui->checkBox_wifi->setEnabled(false);
    ui->comboBox_usbmode->setEnabled(false);
    ui->wifi_edit->setEnabled(false);
    ui->checkBox_autoUpload->setEnabled(false);
    ui->btautoUpload_once->setEnabled(false);
    ui->btdownload->setEnabled(false);
    if(!SR_Mode)//后续若有需要则要重新设置位置
    {
        ui->checkBox_sr->close();//因为这几个是常开的，所以直接屏蔽
        ui->label_26->close();//因为这几个是常开的，所以直接屏蔽
    }else{
        ui->label_26->setGeometry(20,175,168,50);
        ui->checkBox_sr->setGeometry(210,175,70,50);
    }
    //以下是设置wifi、补光灯、蓝牙的默认位置
    ui->label_16->show();//wifi
    ui->label_17->show();//补光灯

    ui->label_18->show();//蓝牙
    ui->checkBox_wifi->show();
    ui->buguangdeng->show();
    ui->checkBox_ble->show();
    ui->label_16->setGeometry(20,10,168,50);//wifi
    ui->label_17->setGeometry(20,65,168,50);//补光灯
    ui->label_18->setGeometry(20,120,168,50);//蓝牙
    ui->checkBox_wifi->setGeometry(210,10,70,50);
    ui->buguangdeng->setGeometry(210,65,70,50);
    ui->checkBox_ble->setGeometry(210,120,70,50);
    ui->ble_edit->setGeometry(326,120,100,30);
    ui->checkBox_wifi->setEnabled(true);
    ui->buguangdeng->setEnabled(true);
    ui->checkBox_ble->setEnabled(true);

    if(!Area_Mode && !FID_PID_MODE && isWIFISearch) //S650华西  自动上传的还存在问题，先不管
    {
        ui->label_31->show();//自动上传
        ui->checkBox_autoUpload->show();
    //    ui->btdownload->show();
        ui->buguangdeng->show();
        ui->label_17->setGeometry(305,175,70,50);//补光灯
        ui->label_31->setGeometry(20,65,168,50);
        ui->checkBox_autoUpload->setGeometry(210,65,70,50);
        ui->autoUpload_edit->setGeometry(290,74,100,30);
        ui->btautoUpload_once->setGeometry(400,74,110,30);
        ui->wifi_edit->setGeometry(290,19,100,30);
        ui->buguangdeng->setGeometry(390,175,70,50);
        ui->btdownload->setGeometry(520,74,110,30);
        ui->ble_edit->setGeometry(290,120,100,30);
        ui->checkBox_autoUpload->setEnabled(true);
        ui->autoUpload_edit->setEnabled(true);
        ui->btautoUpload_once->setEnabled(true);
        ui->buguangdeng->setEnabled(true);
        ui->wifi_edit->setEnabled(true);
        ui->btdownload->setEnabled(true);
    }

    para_init();
    connect(hpdialog, SIGNAL(signal_set_dialog_close(bool)), this, SLOT(slot_set_dialog_close(bool)));
    connect(this, SIGNAL(signal_pc_sys_set_hidemenu(bool)), &hphidemenu, SLOT(slot_homogeneity_enable(bool)));
    connect(ui->ScrollBar_AmbientTempManu,SIGNAL(valueChanged(double)),this,SLOT(wdxz_ambienttempmenu_double_value_changed(double)));
    connect(ui->ScrollBar_Distance,SIGNAL(valueChanged(double)),this,SLOT(wdxz_distance_double_value_changed(double)));
    connect(ui->ScrollBar_Humidity,SIGNAL(valueChanged(int)),this,SLOT(wdxz_humidity_value_changed(int)));
    connect(ui->ScrollBar_Radiance,SIGNAL(valueChanged(int)),this,SLOT(wdxz_radiance_value_changed(int)));
    connect(ui->ScrollBar_ReferTemp,SIGNAL(valueChanged(double)),this,SLOT(wdxz_refertemp_double_value_changed(double)));
    connect(ui->checkBox_ReferTemp_enable,SIGNAL(clicked(bool)),this,SLOT(wdxz_refertemp_enable(bool)));
    connect(ui->checkBox_ReflectTemp_enable,SIGNAL(clicked(bool)),this,SLOT(wdxz_reflectTemp_enable(bool)));
    connect(ui->ScrollBar_ReflectTemp,SIGNAL(valueChanged(double)),this,SLOT(wdxz_reflecttemp_double_value_changed(double)));
    connect(ui->ScrollBar_TempUnit,SIGNAL(valueChanged(int)),this,SLOT(wdxz_tempunit_value_changed(int)));
    connect(ui->ScrollBar_transmission,SIGNAL(valueChanged(int)),this,SLOT(wdxz_transmission_value_changed(int)));
    connect(ui->cwfw_autorectify,SIGNAL(valueChanged(int)),this,SLOT(cwfw_autorectify_value_change(int)));
    connect(ui->comboBox_dangwei,SIGNAL(currentIndexChanged(int)),this,SLOT(cwfw_dangwei_current_index_changed(int)));
    connect(ui->comboBox_jingtou,SIGNAL(currentIndexChanged(int)),this,SLOT(cwfw_jingtou_current_index_changed(int)));
    connect(ui->comboBox_baojingshezhi,SIGNAL(currentIndexChanged(int)),this,SLOT(cwfw_baojingshezhi_current_index_changed(int)));
    connect(ui->comboBox_baojingwendu,SIGNAL(valueChanged(double)),this,SLOT(cwfw_baojingwendu_double_value_changed(double)));
    connect(ui->comboBox_baojingjuli,SIGNAL(valueChanged(double)),this,SLOT(cwfw_baojingjuli_double_value_changed(double)));
    connect(ui->comboBox_baojingse,SIGNAL(currentIndexChanged(int)),this,SLOT(cwfw_baojingse_current_index_changed(int)));
    connect(ui->spinBox_autosave,SIGNAL(valueChanged(int)),this,SLOT(yqsz_zidongcunchu_value_changed(int)));
    connect(ui->checkBox_autoUpload,SIGNAL(clicked(bool)),this,SLOT(yqsz_autoUpdate_setchecked(bool)));
    connect(hp_autoupload,SIGNAL(signal_Set_Unchecked()),this,SLOT(slot_Set_Unchecked()));
    connect(ui->autoUpload_edit,SIGNAL(pressed()),this,SLOT(yqsz_autoUpdate_Edit_setchecked()));
    connect(ui->btautoUpload_once,SIGNAL(released()),this,SLOT(yqsz_btautoUpdate_once_clicked()));
    connect(hp_wifi_Search,SIGNAL(signal_SetIsWifiSearch(bool)),this,SLOT(slot_setWifiIsSelect(bool)));
    connect(ui->btdownload,SIGNAL(released()),this,SLOT(yqsz_btdownload_clicked()));

    //connect(ui->auto_lcdoff,SIGNAL(currentIndexChanged(int)),this,SLOT(auto_lcdoff_value_changed(int)));
    connect(ui->auto_poweroff,SIGNAL(currentIndexChanged(int)),this,SLOT(auto_poweroff_value_changed(int)));
    connect(ui->buguangdeng,SIGNAL(clicked(bool)),this,SLOT(buguangdeng_clicked(bool)));
    connect(ui->checkBox_ble,SIGNAL(clicked(bool)),this,SLOT(ble_clicked(bool)));
    connect(ui->checkBox_wifi,SIGNAL(toggled(bool)),this,SLOT(wifi_clicked(bool)));
    connect(ui->ble_edit,SIGNAL(released()),this,SLOT(ble_edit_release()));
    connect(ui->wifi_edit,SIGNAL(released()),this,SLOT(wifi_edit_release()));
    connect(ui->checkBox_hdmi,SIGNAL(clicked(bool)),this,SLOT(checkBox_hdmi_Clicked(bool)));
    connect(ui->checkBox_zoomSave, SIGNAL(clicked(bool)), this, SLOT(on_checkBox_zoomSave_clicked(bool)));
    connect(ui->checkBox_bmp, SIGNAL(clicked(bool)), this, SLOT(on_checkBox_bmp_clicked(bool)));
    connect(ui->checkBox_mulhom,SIGNAL(clicked(bool)),this,SLOT(yqsz_mulhom_setchecked(bool)));
    connect(ui->checkBox_4G,SIGNAL(clicked(bool)),this,SLOT(yqsz_4G_setchecked(bool)));
    connect(ui->checkBox_GPS,SIGNAL(clicked(bool)),this,SLOT(yqsz_GPS_setchecked(bool)));
    connect(ui->checkBox_avgTemp,SIGNAL(clicked(bool)),this,SLOT(yqsz_avgTemp_setchecked(bool)));
    connect(ui->checkBox_compass,SIGNAL(clicked(bool)),this,SLOT(yqsz_compass_setchecked(bool)));
    connect(ui->checkBox_contrustFocus,SIGNAL(clicked(bool)),this,SLOT(yqsz_contrustFocus_setchecked(bool)));
    connect(ui->calbration_edit,SIGNAL(clicked(bool)),this,SLOT(on_calbration_edit_clicked(bool)));
    connect(ui->mulhom_edit,SIGNAL(released()),this,SLOT(yqsz_mulhom_edit_checked()));
    connect(hp_Mulhom_edit,SIGNAL(hp_mulhom_edit_value_changed(int)),this,SLOT(hp_slot_mulhom_edit_value_changed(int)));
    connect(ui->checkBox_nonCool,SIGNAL(clicked(bool)),this,SLOT(yqsz_nonCool_setchecked(bool)));

    connect(&hpblesearch, SIGNAL(signal_ble_set_close()), this, SLOT(slot_ble_set_close()));
    connect(&hpblesearch, SIGNAL(signal_reset_ble_power()), this, SLOT(slot_reset_ble_power()));
    connect(tabBar,SIGNAL(currentChanged(int)),this,SLOT(slot_tabbar_current_changed(int)));
//    connect(hpsetadjust,SIGNAL(signal_dangwei_jingtou_adjust(bool)),this,SLOT(slot_dangwei_jingtou_adjust(bool)));

    connect(hpdefault,SIGNAL(signal_defaultdialog_set_lcd_offed_state()),this,SLOT(slot_set_lcd_offed_state()));
    connect(hpformat,SIGNAL(signal_formatdialog_set_lcd_offed_state()),this,SLOT(slot_set_lcd_offed_state()));

    connect(hpdefault,SIGNAL(signal_close_ble_lie()),&hpblesearchold,SLOT(ble_off_close()));

    connect(hp_autoupload_dialog,SIGNAL(signal_StartAutoUpload_once(bool)),this,SLOT(slot_StartAutoUpload_once(bool)));
    connect(hp_autoupload_dialog,SIGNAL(signal_close()),this,SLOT(slot_closeAutoUpload_once()));

    connect(ui->scrollArea,SIGNAL(signal_page_changed(int)),this,SLOT(slot_scroll_page_changed(int)));
    connect(hp_autoupload,SIGNAL(siganl_client_isOn(bool)),this,SLOT(slot_client_isOn(bool)));

    connect(hp_Common_dialog_select,SIGNAL(hp_signal_bt_click(int)),this,SLOT(slot_selectAutoUpload_once(int)));

    connect(&hphide_biaoding,SIGNAL(signal_pc_checkbox_rotate(bool)),this,SLOT(slot_hidemenu_ImageChange(bool)));

    connect(ui->listWidget_focusmode,SIGNAL(currentRowChanged(int)),this,SLOT(yqsz_focusmode_current_index_changed(int)));

    connect(&tempSetTm,SIGNAL(timeout()),this,SLOT(slot_tempSetTm_out()));

    connect(ui->checkBox_angel, SIGNAL(clicked(bool)),this,SLOT(hp_slot_checkBox_angle_clicked(bool)));
    connect(ui->checkBox_volume, SIGNAL(clicked(bool)),this,SLOT(hp_slot_checkBox_volcal_clicked(bool)));
    connect(ui->pushButton_hotkey, SIGNAL(click()), this, SLOT(on_pushButton_hotkey_clicked()));
    connect(this, SIGNAL(signal_start_transmission()), m_Transmission, SLOT(hp_start_transmission()));
    connect(this, SIGNAL(signal_stop_transmission()), m_Transmission, SLOT(hp_stop_transmission()));
    connect(m_Transmission, SIGNAL(signal_transmission_init_over()), this, SLOT(slot_set_dialog_close()));
    connect(m_Transmission, SIGNAL(signal_transmission_allow_upload()), this, SLOT(slot_transmission_allow_upload()));
    connect(m_Transmission, SIGNAL(signal_transmission_send_heartbeat()), this, SLOT(slot_transmission_send_heartbeat()));
    connect(m_Transmission, SIGNAL(signal_transmission_get_download()), this, SLOT(slot_transmission_get_download()));
    connect(m_Transmission, SIGNAL(signal_set_transmission_addr(QString)), m_transmissionSearch, SLOT(slot_set_transmission_addr(QString)));
    connect(m_transmissionSearch, SIGNAL(signal_link_transmission(QString)), this, SLOT(slot_link_transmission(QString)));
    connect(m_transmissionSearch, SIGNAL(signal_start_get_xml()), m_Transmission, SLOT(slot_start_get_xml()));
    connect(m_transmissionSearch, SIGNAL(signal_get_ble_msg()), this, SLOT(slot_start_get_bleInfo()));
    connect(m_Transmission, SIGNAL(signal_stop_get_bleInfo(QString)), m_transmissionSearch, SLOT(slot_get_ble_msg(QString)));
    connect(m_Transmission, SIGNAL(signal_stop_get_bleInfo(QString)), this, SLOT(slot_stop_get_bleInfo(QString)));
    auto_poweroff = false;
    lcd_offed = false;


    state4G = IS_ON_NONE;
    state_4G = new QTimer();
    state_4G->setInterval(3000);
    connect(state_4G,SIGNAL(timeout()),this,SLOT(slot_timeout_4G_state()));
    connect(&m_timer_4G, SIGNAL(timeout()), this, SLOT(slot_cancel4GConnect()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(timer_func()));

    state_Wait_4G = new QTimer();
    state_Wait_4G->setInterval(20000);
    connect(state_Wait_4G,SIGNAL(timeout()),this,SLOT(slot_timeout_4G_wait_state()));
    timer.start(1000);//1min
    hp_Common_dialog_cancel = new hp_common_dialog_cancel();
    hp_Common_dialog_cancel->close();

    connect(hp_Common_dialog_cancel,SIGNAL(hp_signal_on_cancel_clicked()),this,SLOT(slot_cancel4GConnect()));
    //初始化改变的值
    ui_jingtou_changeid = ui->comboBox_jingtou->currentIndex();
    ui_dangwei_changeid = ui->comboBox_dangwei->currentIndex();

    range_lens_copy();     //保存此时镜头和挡位号的状态

    ui->comboBox_jingtou->close();
    ui->comboBox_dangwei->close();
    ui->comboBox_baojingshezhi->close();
    ui->comboBox_baojingse->close();
    ui->comboBox_usbmode->close();
    ui->comboBox_language->close();
    ui->auto_poweroff->close();
    ui->auto_lcdoff->close();


    listwidget_type = 0;
    ui->frame->installEventFilter(this);
    ui->frame_jingtou->installEventFilter(this);
    ui->frame_wendang->installEventFilter(this);
    ui->frame_bangjingshehzi->installEventFilter(this);
    ui->frame_baojingse->installEventFilter(this);

    ui->frame_imageType->installEventFilter(this);
    ui->frame_modeSelect->installEventFilter(this);
    ui->frame_usbmode->installEventFilter(this);
    ui->frame_recordmode->installEventFilter(this);
    ui->frame_language->installEventFilter(this);
    ui->frame_poweroff->installEventFilter(this);
    ui->frame_lcdoff->installEventFilter(this);
    ui->frame_Radiance->installEventFilter(this);
    ui->frame_ReflectTemp->installEventFilter(this);
    ui->frame_focusmode->installEventFilter(this);

    ui->listWidget_jingtou->close();
    ui->listWidget_wendang->close();
    ui->listWidget_baojingshezhi->close();
    ui->listWidget_baojingse->close();

    ui->listWidget_usbmode->close();
    ui->listWidget_language->close();
    ui->listWidget_poweroff->close();
    ui->listWidget_lcdoff->close();
    ui->listWidget_Radiance->close();

    ui->listWidget_Radiance->setGeometry(116,56,30*12+4,390);
    ui->frame_Radiance->setGeometry(116,12,366,44);
    ui->frame_Radiance->hide();
    ui->frame_ReflectTemp->close();
    ui->listWidget_ReflectTemp->close();
    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    if(TempUserPara.RadTable_switch == 0)
    {
        ui->checkBox_Radiance->setChecked(false);                   //辐射率表开关 关为0，开为1
        isManualCall = true;
        on_checkBox_Radiance_clicked(false);
        isManualCall = false;
    }else{
        ui->checkBox_Radiance->setChecked(true);
        isManualCall = true;
        on_checkBox_Radiance_clicked(true);
        isManualCall = false;
    }


    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    slot_setWifiIsSelect(false);
    signal_core_fpgamenu_oritoggle(0);

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }
    qDebug() << __LINE__ << "dangweiMaxTemp" << dangweiMaxTemp << "dangweiMinTemp" << dangweiMinTemp;
    ui->label_scroll->setMyname(MYLABEL_WHO_SCROLL);
}
bool HpSetting::winInit()//通过配置文件设置图标位置
{
    qDebug() << "HpSetting::winInit";

    //关闭组件
    ui->label_16->close();
    ui->checkBox_wifi->close();
    ui->label_18->close();
    ui->checkBox_ble->close();
    ui->label_21->close();
    ui->checkBox_area->close();
    ui->label_26->close();
    ui->checkBox_sr->close();
    ui->label_17->close();
    ui->buguangdeng->close();
    ui->label_27->close();
    ui->checkBox_fid->close();
    ui->label_28->close();
    ui->checkBox_pid->close();
    ui->label_31->close();
    ui->checkBox_autoUpload->close();
    ui->label_32->close();
    ui->frame_modeSelect->close();
    ui->label_33->close();
    ui->checkBox_hdmi->close();
    ui->label_34->close();
    ui->checkBox_sis->close();
    ui->label_35->close();
    ui->checkBox_mulhom->close();
    ui->mulhom_edit->close();
    ui->label_45->close();
    ui->frame_focusmode->close();
    ui->listWidget_focusmode->close();
    ui->label_36->close();
    ui->checkBox_gw->close();
    ui->label_37->close();
    ui->label_38->close();
    ui->label_39->close();
    ui->label_40->close();
    ui->label_41->close();
    ui->label_42->close();
    ui->label_43->close();
    ui->label_44->close();
    ui->label_55->close();
    ui->label_56->close();
    ui->label_57->close();

    ui->label_46->close();
    ui->checkBox_GPS->close();
    ui->checkBox_brightness->close();
    ui->checkBox_autoReg->close();
    ui->checkBox_contrustFocus->close();
    ui->label_47->close();
    ui->label_48->close();
    ui->checkBox_avgTemp->close();
    ui->checkBox_4G->close();
    ui->checkBox_compass->close();
    ui->calbration_edit->close();
    ui->frame_imageType->close();
    ui->listWidget_imageType->close();
    ui->listWidget_ReflectTemp->close();
    ui->checkBox_panorama->close();
    ui->checkBox_zoomSave->close();
    ui->checkBox_oritoggle->close();
    ui->checkBox_nonCool->close();
    ui->checkBox_homogeneity->close();
    ui->checkBox_stepZero->close();
    ui->checkBox_ReflectTemp_enable->close();
    int isS3X0 = 0;//标识S3X0是否
    QString para;

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","S3X0");
        qDebug() << "S3X0 == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            isS3X0 = para.toInt();
            m_isS3X0 = isS3X0;
            break;
        }
    }
    if(1)
    {
        bool isSuccess = false;
        int fileCount = 0;
        while(!isSuccess || fileCount < 10)
        {
            QString fileName = "/usr/share/imx_6q_display_config";
            QFile file(fileName);
            // 打开文件，如果无法打开则报错
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                qDebug() << "Error: Cannot open file for writing";
                fileCount++;
                continue;
            }
            else
            {
                // 创建文本流
                QTextStream out(&file);
                if(isS3X0 == 2)
                {
                    // 写入文件内容
                    out << "[master]" << endl;
                    out << "device = /dev/video19" << endl;
                    out << "width = 384" << endl;
                    out << "height = 272" << endl;
                    out << "#alpha = 255" << endl;
                    out << "#color_key = 0" << endl;
                    out << "[slave]" << endl;
                    out << "device = /dev/video17" << endl;
                    out << "width = 384" << endl;
                    out << "height = 272" << endl;
                }
                else
                {
                    // 写入文件内容
                    out << "[master]" << endl;
                    out << "device = /dev/video19" << endl;
                    if(isS3X0 == 3)
                        out << "width = 600" << endl;
                    else
                        out << "width = 640" << endl;
                    out << "height = 480" << endl;
                    out << "#alpha = 255" << endl;
                    out << "#color_key = 0" << endl;
                    out << "[slave]" << endl;
                    out << "device = /dev/video17" << endl;
                    if(isS3X0 == 3)
                        out << "width = 600" << endl;
                    else
                        out << "width = 640" << endl;
                    out << "height = 480" << endl;
                }

                // 关闭文件
                file.close();
                qDebug() << "File generated successfully.";
            }
            if (file.error() == QFile::NoError) {
                isSuccess = true;
                qDebug() << "File generated successfully.";
                break;
            } else {
                qDebug() << "Error occurred during file generation. Retrying...";
                fileCount++;
            }
        }
    }
    //下拉列表布局
    int list_row1,list_row2,list_row3,list_row4,list_row5;//下拉列表y坐标
    //若有4行
    if(isS3X0 == 2)
    {
        list_row1 = 145;
        list_row2 = 178;
        list_row3 = 211;
        list_row4 = 244;

        ui->label_19->setGeometry(30,list_row1,100,31);//USB模式
        ui->label_29->setGeometry(30,list_row2,100,31);//录制模式
        ui->label_24->setGeometry(30,list_row3,100,31);//自动存储
        ui->label_25->setGeometry(1130,list_row4,100,31);//格式化
        ui->frame_usbmode->setGeometry(140,list_row1,146,25);
        ui->listWidget_usbmode->setGeometry(140,ui->frame_usbmode->y() + ui->frame_usbmode->height(),146,42);
        ui->frame_recordmode->setGeometry(140,list_row2,146,25);
        ui->listWidget_recordmode->setGeometry(140,ui->frame_recordmode->y() + ui->frame_recordmode->height(),146,42);
        ui->spinBox_autosave->setGeometry(140,list_row3,146,25);
//        ui->pushButton_3->setGeometry(140,list_row4,146,25);
    }else{
        list_row1 = 222;
        list_row2 = 275;
        list_row3 = 328;
        list_row4 = 381;
        ui->label_19->setGeometry(15,list_row1,173,50);//USB模式
        ui->label_29->setGeometry(15,list_row2,173,55);//录制模式
        ui->label_24->setGeometry(15,list_row3,173,50);//自动存储
        ui->label_25->setGeometry(1115,list_row4,173,50);//格式化
        ui->frame_usbmode->setGeometry(210,list_row1,243,44);
        ui->listWidget_usbmode->setGeometry(210,ui->frame_usbmode->y() + ui->frame_usbmode->height(),243,70);
        ui->frame_recordmode->setGeometry(210,list_row2,243,44);
        ui->listWidget_recordmode->setGeometry(210,ui->frame_recordmode->y() + ui->frame_recordmode->height(),243,70);
        ui->spinBox_autosave->setGeometry(210,list_row3,243,44);
//        ui->pushButton_3->setGeometry(210,list_row4,243,44);
    }


    int setArray[50] = {0};//用于存放有哪些被选中
    int index = 0;//数组下标
    MainWidget *p = (MainWidget *)parentP;
//    fp.write("HpSetting::winInit  == read\n");
    //读取XML
    //默认有wifi 存在
    ui->label_16->setEnabled(true);
    ui->checkBox_wifi->setEnabled(true);

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","wifi_sta");
        qDebug() << "wifi_sta == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            hp_wifi_Search->hp_setUiInit(false);
            if(para.toInt() == 0)
            {
                //功能定义
                isWIFISearch = false;
                isWIFIServer = false;
            }else if(para.toInt() == 1){
                isWIFISearch = false;
                setArray[index] = XML_WIFI;
                index++;
            }else if(para.toInt() == 2)
            {
                isWIFISearch = true;
                setArray[index] = XML_WIFI;
                index++;
            }else if(para.toInt() == 3)
            {
                isWIFISearch = true;
                isWIFIServer = true;
                setArray[index] = XML_WIFI;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","buguang_sw");
//        qDebug() << "buguang_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_BUGUANGDENG;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","ble_sw");
//        qDebug() << "ble_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_BLE;
                index++;
            }
            break;
        }
    }


    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","sr_sw");
//        qDebug() << "sr_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_SR;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","bmp_sw");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_BMP;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","area_sw");
//        qDebug() << "area_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_AREA;
                index++;
                signal_pc_image_set_abnormal(0);//根据mainwidget.cpp文件中描述，当开启Area_mode时，需要发送这个信号
//                ui->checkBox_angel->show();
//                ui->checkBox_volume->show();
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","hdmi_sw");
//        qDebug() << "hdmi_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_HDMI;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","sis_sw");
//        qDebug() << "sis_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_SIS;
                index++;

                //功能参数
                p->define_sis = true;
            }else if(para.toInt() == 2)
            {
                setArray[index] = XML_SIS;
                index++;

                //功能参数
                p->define_sis = true;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        QString para = hpxmlreader.XmlInit_read("sys.xml","MODULE","once_range");
//        qDebug() << "once_range == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                p->getRangeOnce = true;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        QString para = hpxmlreader.XmlInit_read("sys.xml","MODULE","consercutive_laser");
//        qDebug() << "consercutive_laser == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                p->consercutiveLaser = true;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        QString para = hpxmlreader.XmlInit_read("sys.xml","MODULE","laser_adjust");
        qDebug() << "laser_adjust == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                p->laserAdjust = true;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","sw_4G");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_4G;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","sw_GPS");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_GPS;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","sketch_sw");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_SKETCH;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","eth_sw");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_ETH;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","sw_avgtemp");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_SHOWAVGTEMP;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.readXml("config.xml","NONCOOLCORRECTTYPE","content");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_NONCOOL;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","compass_sw");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_COMPASS;
                index++;
                hphidemenu.setDefineCompass(true);
            }else if(para.toInt() == 0){
                hphidemenu.setDefineCompass(false);
                ui->calbration_edit->close();
            }
            break;
        }
    }


    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","fidpid_sw");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                fidpid = true;
                if(dangweiMaxTemp == 80 && dangweiMinTemp == -20)
                {
                    signal_noncool_unenable_plr(true);
                    yqsz_nonCool_setchecked(true);
                    ui->checkBox_nonCool->setChecked(true);
                }else
                {
                    signal_noncool_unenable_plr(false);
                    yqsz_nonCool_setchecked(false);
                    ui->checkBox_nonCool->setChecked(false);
                }
                p->slot_set_define_Init(true);
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","autoupload_sw");
//        qDebug() << "autoupload_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_AUTOUPLOAD;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","mulhom_sw");
//        qDebug() << "mulhom_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_MULHOM;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","gw_sw");
//        qDebug() << "gw_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_GW;
                index++;
            }
            break;
        }
    }
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","panorama_sw");
//        qDebug() << "panorama_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_PANORAMA;
                index++;
            }
            break;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","zoomsave_sw");
//        qDebug() << "zoomsave_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_ZOOMSAVE;
                index++;
            }
            break;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","filp_sw");
//        qDebug() << "zoomsave_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_FLIP;
                index++;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","DEV","bledev_type");
//        qDebug() << "S3X0 == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 2)
            {
                isNewBle = true;
            }
            break;
        }
    }
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","ble_trans");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_TRANS;
                index++;
            }
            break;
        }
    }
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","autorec_sw");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_AUTOREG;
                index++;
            }
            break;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","contrast_sw");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                setArray[index] = XML_CONTRAST;
                index++;
            }
            break;
        }
    }
//    setArray[index++] = XML_PRESET1;
//    setArray[index++] = XML_PRESET2;
//    setArray[index++] = XML_ORITOGGLE;
//    setArray[index++] = XML_HOMOGENEITY;
//    setArray[index++] = XML_STEPZERO;
//    setArray[index++] = XML_NONCOOL;


    //初始化坐标
    int colum1_x,colum2_x,colum3_x,colum4_x,colum5_x,colum6_x;//列x坐标
    int row1_y,row2_y,row3_y,row4_y;//行x坐标
    int label_w;
    int label_h;
    int checkbox_w;
    int checkbox_h;

    if(isS3X0 == 2)
    {
        row1_y = 0;
        row2_y = 30;
        row3_y = 60;
        row4_y = 90;

        colum1_x = 0 + 30;
        colum2_x = 580 + 30;
        colum3_x = 1160 + 30;
        colum4_x = 1740 + 30;
        colum5_x = 2320 + 30;
        colum6_x = 2900 + 30;

        label_w = 101;
        label_h = 45;
        checkbox_w = 42;
        checkbox_h = 35;

        ui->scrollArea->pagesize = 580;
        ui->scrollArea->setGeometry(0,5,374,143);
        ui->label_scroll->setGeometry(ui->scrollArea->x() + ui->scrollArea->width(),5,10,143);
    }else{
        row1_y = 0;
        row2_y = 53;
        row3_y = 106;
        row4_y = 159;

        colum1_x = 0;
        colum2_x = 580;
        colum3_x = 1160;
        colum4_x = 1740;
        colum5_x = 2320;
        colum6_x = 2900;

        label_w = 178;
        label_h = 50;
        checkbox_w = 70;
        checkbox_h = 40;

        ui->scrollArea->pagesize = 580;
    }


    ui->scrollArea->hp_setMaxPage((index - 1) / 4);
    ui->label_scroll->hp_scroll_setzon((index - 1) / 4);

    //遍历数组
    int nowX;
    int nowY;
    char *mm;
    QByteArray ba;
    for(int i = 0;i < index + 1;i++)
    {
        if(i <= 3)
        {
            nowX = colum1_x;
        }else if(i <= 7)
        {
            nowX = colum2_x;
        }else if(i <= 11)
        {
            nowX = colum3_x;
        }else if(i <= 15)
        {
            nowX = colum4_x;
        }else if(i <= 19)
        {
            nowX = colum5_x;
        }else if(i <= 23)
        {
            nowX = colum6_x;
        }
        if(i % 4 == 3)
        {
            nowY = row4_y;
        }else if(i % 4 == 2)
        {
            nowY = row3_y;
        }else if(i % 4 == 1)
        {
            nowY = row2_y;
        }else if(i % 4 == 0)
        {
            nowY = row1_y;
        }
        ba = QString::number(i).toUtf8();
        mm = ba.data();
        ba = QString(QString(" ---- ") + QString::number((int)setArray[i]) + QString("\n")).toUtf8();
        mm = ba.data();
        if(setArray[i] == (int)XML_WIFI){
            ui->label_16->setEnabled(true);
            ui->checkBox_wifi->setEnabled(true);
            ui->checkBox_wifi->setCheckable(true);
            ui->wifi_edit->setEnabled(true);
            ui->label_16->show();
            ui->checkBox_wifi->show();
            ui->label_16->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_wifi->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
            //MainWidget::slot_core_get_usbwifiinsert函数将其失能，不知为啥，现已将其屏蔽
            if(isS3X0 == 2)
            {
                ui->wifi_edit->setGeometry(ui->checkBox_wifi->x() + checkbox_w + 10,nowY + 9,40,25);
            }else{
                ui->wifi_edit->setGeometry(ui->checkBox_wifi->x() + checkbox_w + 10,nowY + 9,71,30);
            }
        }else if(setArray[i] == (int)XML_SR){
            ui->label_26->setEnabled(true);
            ui->checkBox_sr->setEnabled(true);
            ui->label_26->show();
            ui->checkBox_sr->show();
            ui->label_26->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_sr->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_HDMI){
            ui->label_33->show();
            ui->checkBox_hdmi->show();
            ui->label_33->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_hdmi->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_BLE){
            ui->label_18->setEnabled(true);
            ui->checkBox_ble->setEnabled(true);
            ui->ble_edit->hide();
            ui->label_18->show();
            ui->checkBox_ble->show();
            ui->label_18->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_ble->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
            if(isS3X0 == 2)
            {
                ui->ble_edit->setGeometry(ui->checkBox_ble->x() + checkbox_w + 10,nowY + 9,40,25);
            }else{
                ui->ble_edit->setGeometry(ui->checkBox_ble->x() + checkbox_w + 10,nowY + 9,71,30);
            }
        }else if(setArray[i] == (int)XML_AREA){
            ui->label_21->setEnabled(true);
            ui->checkBox_area->setEnabled(true);
            ui->label_21->show();
            ui->checkBox_area->show();
            ui->label_21->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_area->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_BUGUANGDENG){
            ui->label_17->setEnabled(true);
            ui->buguangdeng->setEnabled(true);
            ui->label_17->show();
            ui->buguangdeng->show();
            ui->label_17->setGeometry(nowX,nowY,label_w,label_h);
            ui->buguangdeng->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_FOCUS){
//            ui->label_29->show();
//            ui->checkBox_con->show();
//            ui->label_29->setGeometry(nowX,nowY,label_w,label_h);
//            ui->checkBox_con->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_SIS){
            ui->label_34->show();
            ui->checkBox_sis->show();
            ui->label_34->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_sis->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_ETH){
            ui->label_50->show();
            ui->checkBox_eth->show();
            ui->label_50->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_eth->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
            ui->checkBox_eth->setEnabled(false);
        }else if(setArray[i] == (int)XML_4G){
            ui->label_43->show();
            ui->checkBox_4G->show();
            ui->label_43->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_4G->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_GPS){
            ui->label_46->show();
            ui->checkBox_GPS->show();
            ui->label_46->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_GPS->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_SHOWAVGTEMP){
            ui->label_47->show();
            ui->checkBox_avgTemp->show();
            ui->label_47->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_avgTemp->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_NONCOOL){
            ui->label_48->show();
            ui->checkBox_nonCool->show();
            ui->label_48->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_nonCool->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_FLIP){
            ui->label_52->show();
            ui->checkBox_flip->show();
            ui->label_52->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_flip->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_SKETCH){
            ui->label_51->show();
            ui->checkBox_sketch->show();
            ui->label_51->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_sketch->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
            ui->sketch_edit->setGeometry(ui->checkBox_sketch->x() + checkbox_w + 10,nowY + 9,71,30);
        }else if(setArray[i] == (int)XML_COMPASS){
            ui->label_44->show();
            ui->checkBox_compass->show();
            ui->label_44->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_compass->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
            ui->calbration_edit->setGeometry(ui->checkBox_compass->x() + checkbox_w + 10,nowY + 9,71,30);
        }else if(setArray[i] == (int)XML_AUTOUPLOAD){
            ui->label_31->setEnabled(true);
            ui->checkBox_autoUpload->setEnabled(true);
            ui->autoUpload_edit->setEnabled(true);
            ui->btautoUpload_once->setEnabled(true);
            ui->btdownload->setEnabled(true);
            ui->label_31->show();
            ui->checkBox_autoUpload->show();
            ui->label_31->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_autoUpload->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
            if(isS3X0 == 2)
            {
                ui->autoUpload_edit->setGeometry(ui->checkBox_autoUpload->x() + checkbox_w + 5,nowY + 9,35,25);
                ui->btautoUpload_once->setGeometry(ui->autoUpload_edit->x() + 35 + 5,nowY + 9,60,25);
                ui->btdownload->setGeometry(ui->btautoUpload_once->x() + ui->btautoUpload_once->width() + 5,nowY + 9,60,25);
            }else{
                ui->autoUpload_edit->setGeometry(ui->checkBox_autoUpload->x() + checkbox_w + 10,nowY + 9,71,30);
                ui->btautoUpload_once->setGeometry(ui->autoUpload_edit->x() + checkbox_w + 10,nowY + 9,110,30);
                ui->btdownload->setGeometry(ui->btautoUpload_once->x() + ui->btautoUpload_once->width() + 10,nowY + 9,110,30);
            }
        }else if(setArray[i] == (int)XML_FID){//非制冷气体作用暂时屏蔽
//            ui->label_27->setEnabled(true);
//            ui->checkBox_fid->setEnabled(true);
//            ui->label_27->show();
//            ui->checkBox_fid->show();
//            ui->label_27->setGeometry(nowX,nowY,label_w,label_h);
//            ui->checkBox_fid->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_PID){
            ui->label_28->setEnabled(true);
            ui->checkBox_pid->setEnabled(true);
            ui->label_28->show();
            ui->checkBox_pid->show();
            ui->label_28->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_pid->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_MULHOM){
            ui->label_35->setEnabled(true);
            ui->checkBox_mulhom->setEnabled(true);
            ui->mulhom_edit->setEnabled(true);
            ui->label_35->show();
            ui->checkBox_mulhom->show();
            ui->label_35->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_mulhom->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
            if(isS3X0 == 2)
            {
                ui->mulhom_edit->setGeometry(ui->checkBox_mulhom->x() + checkbox_w + 10,nowY + 9,40,25);
            }else{
                ui->mulhom_edit->setGeometry(ui->checkBox_mulhom->x() + checkbox_w + 10,nowY + 9,71,30);
            }

//            ui->checkBox_mulhom->setChecked(true);//开机自启动
            yqsz_mulhom_setchecked(false);
        }else if(setArray[i] == (int)XML_GW){
            ui->label_36->setEnabled(true);
            ui->checkBox_gw->setEnabled(true);
            ui->label_36->show();
            ui->checkBox_gw->show();
            ui->label_36->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_gw->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_PANORAMA){
            ui->label_37->setEnabled(true);
            ui->checkBox_panorama->setEnabled(true);
            ui->label_37->show();
            ui->checkBox_panorama->show();
            ui->label_37->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_panorama->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_ZOOMSAVE){
            ui->label_39->setEnabled(true);
            ui->checkBox_zoomSave->setEnabled(true);
            ui->label_39->show();
            ui->checkBox_zoomSave->show();
            ui->label_39->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_zoomSave->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_BMP){
            ui->label_54->setEnabled(true);
            ui->checkBox_bmp->setEnabled(true);
            ui->label_54->show();
            ui->checkBox_bmp->show();
            ui->label_54->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_bmp->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_TRANS){
            ui->label_53->setEnabled(true);
            ui->checkBox_transmission->setEnabled(true);
            ui->label_53->show();
            ui->checkBox_transmission->show();
            ui->label_53->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_transmission->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
            if(isS3X0 == 2)
            {
                ui->trmission_edit->setGeometry(ui->checkBox_transmission->x() + checkbox_w + 10,nowY + 9,40,25);
            }else{
                ui->trmission_edit->setGeometry(ui->checkBox_transmission->x() + checkbox_w + 10,nowY + 9,71,30);
            }
            ui->trmission_edit->close();
        }else if(setArray[i] == (int)XML_AUTOREG){
            ui->label_57->setEnabled(true);
            ui->checkBox_autoReg->setEnabled(true);
            ui->label_57->show();
            ui->checkBox_autoReg->show();
            ui->label_57->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_autoReg->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_PRESET1){
            ui->label_58->setEnabled(true);
            ui->checkBox_preset1->setEnabled(true);
            ui->label_58->show();
            ui->checkBox_preset1->show();
            ui->label_58->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_preset1->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_PRESET2){
            ui->label_59->setEnabled(true);
            ui->checkBox_preset2->setEnabled(true);
            ui->label_59->show();
            ui->checkBox_preset2->show();
            ui->label_59->setGeometry(nowX,nowY,label_w,label_h);
            ui->checkBox_preset2->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
        }else if(setArray[i] == (int)XML_CONTRAST){
            ui->label_55->setEnabled(true);
            ui->checkBox_contrustFocus->setEnabled(true);
            ui->label_55->show();
            ui->checkBox_contrustFocus->show();
            ui->label_55->setGeometry(nowX, nowY, label_w, label_h);
            ui->checkBox_contrustFocus->setGeometry(nowX + label_w + 10, nowY + 5, checkbox_w, checkbox_h);
        }
//        else if(setArray[i] == (int)XML_ORITOGGLE){
//            ui->label_40->setEnabled(true);
//            ui->checkBox_oritoggle->setEnabled(true);
//            ui->label_40->show();
//            ui->checkBox_oritoggle->show();
//            ui->label_40->setGeometry(nowX,nowY,label_w,label_h);
//            ui->checkBox_oritoggle->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
//        }
//        else if(setArray[i] == (int)XML_HOMOGENEITY){
//            ui->label_41->setEnabled(true);
//            ui->checkBox_homogeneity->setEnabled(true);
//            ui->label_41->show();
//            ui->checkBox_homogeneity->show();
//            ui->label_41->setGeometry(nowX,nowY,label_w,label_h);
//            ui->checkBox_homogeneity->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
//        }
//        else if(setArray[i] == (int)XML_STEPZERO){
//            ui->label_42->setEnabled(true);
//            ui->checkBox_stepZero->setEnabled(true);
//            ui->label_42->show();
//            ui->checkBox_stepZero->show();
//            ui->label_42->setGeometry(nowX,nowY,label_w,label_h);
//            ui->checkBox_stepZero->setGeometry(nowX + label_w + 10,nowY + 5,checkbox_w,checkbox_h);
//        }
    }
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","oneupload_sw");
//        qDebug() << "oneupload_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                //功能定义
                onceUpload = true;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","autodownload_sw");
//        qDebug() << "autodownload_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                //功能定义
                download = true;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","isotherm_sw");
//        qDebug() << "isotherm_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 0)
            {
                ui->dengwengse_edit->close();
                ui->label_30->close();

                ui->comboBox_buchangwendu->show();

                isOtherm = false;
            }else{
                //这里直接把ISOTHERM设置的内容搬过来
                ui->dengwengse_edit->show();
                ui->label_30->show();
                ui->label_30->setGeometry(124,430,200,44);
                ui->label_30->setEnabled(true);
                ui->dengwengse_edit->setEnabled(true);
                ui->comboBox_buchangwendu->close();

                isOtherm = true;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","hirplay");
//        qDebug() << "hirplay == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                p->hppreview->define_hirplay = true;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","prefix");
//        qDebug() << "prefix == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                hp_wifi_Search->hti.setShowPrefix(false);
                p->hppreview->hp_text_input.setShowPrefix(false);
                p->hpcameracap->hti.setShowPrefix(true);
                p->hta->hti.setShowPrefix(true);
                hp_autoupload->hti.setShowPrefix(false);
            }else{
                hp_wifi_Search->hti.setShowPrefix(false);
                p->hppreview->hp_text_input.setShowPrefix(false);
                p->hpcameracap->hti.setShowPrefix(false);
                p->hta->hti.setShowPrefix(false);
                hp_autoupload->hti.setShowPrefix(false);
            }
            break;
        }
    }
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","circle");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                m_isOpenCircle = true;
            }
            break;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","polygon");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                m_isOpenPolygon = true;
            }
            break;
        }
    }
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","audiotime");
//        qDebug() << "audiotime == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            p->hpcameracap->hp_setMaxAudioTime(para.toInt());
            p->hta->hp_setMaxAudioTime(para.toInt());
            break;
        }else{
            p->hpcameracap->hp_setMaxAudioTime(60);
            p->hta->hp_setMaxAudioTime(60);
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","ftp_upload");
//        qDebug() << "ftp_upload == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 0)
            {
                p->hpsetting.hp_autoupload->changeMode(0);
                p->hpcameracap->mymode = enum_AUP_ftp;
                p->upload_mode = enum_AUP_ftp;
            }else if(para.toInt() == 1){
                p->hpsetting.hp_autoupload->changeMode(1);
                p->hpcameracap->mymode = enum_AUP_SERVER;
                p->upload_mode = enum_AUP_SERVER;
            }else if(para.toInt() == 2){
                p->hpsetting.hp_autoupload->changeMode(2);
                p->hpcameracap->mymode = enum_AUP_SERVER_PLUS;
                p->upload_mode = enum_AUP_SERVER_PLUS;
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","brightmode");
//        qDebug() << "brightmode == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                p->hp_setDefine_brightmode(true);
            }else if(para.toInt() == 0){
                p->hp_setDefine_brightmode(false);
            }
            break;
        }
    }
    isHotkey = false;
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","hotkey_sw");
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                isHotkey = true;
            }
            else
            {
                ui->label_49->close();
                ui->pushButton_hotkey->close();
                ui->pushButton_3->move(131,282);
                ui->pushButton_default->move(131,343);
            }
            break;
        }
    }
//    for(int i = 0;i < 10;i++)
//    {
//        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","sebiao15");
//        qDebug() << "sebiao15 == > " << para.toInt();
//        if(!hpxmlreader.errorRead)
//        {
//            bool isS300 = false;
//            if(isS3X0 == 2)
//            {
//                isS300 = true;
//            }else{
//                isS300 = false;
//            }
//            if(para.toInt() == 1)
//            {
//                p->hpsebiao.set_sebiao(false,isS300);
//            }else if(para.toInt() == 0){
//                p->hpsebiao.set_sebiao(true,isS300);
//            }
//            break;
//        }
//    }
    bool xmlImageType = false;
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","imagetype");
//        qDebug() << "xmlImageType == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                xmlImageType = true;
            }
            break;
        }
    }
    bool xmlTaskmode = false;
    for(int i = 0;i < 10;i++)
    {
        if(xmlImageType)
            break;
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","taskmode");
//        qDebug() << "taskmode == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                p->hppreview->Taskmode = true;
                p->hppreview->hp_text_input.setbtnTaskVisble(true);
                xmlTaskmode = true;
            }else{
                p->hppreview->Taskmode = false;
                p->hppreview->hp_text_input.setbtnTaskVisble(false);
                xmlTaskmode = false;
            }
            break;
        }
    }

    int colorrulemaxid = 7;
    int colorruleminid = 0;
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","COLORRULE","maxid");
//        qDebug() << "COLORRULE maxid == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            colorrulemaxid = para.toInt();
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","COLORRULE","minid");
//        qDebug() << "COLORRULE minid == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            colorruleminid = para.toInt();
            break;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","turn_sebiao");
        qDebug() << "-----------------------------------------auto_reflect == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                p->hpsebiao.turnSebiao = true;
            }
            break;
        }
    }
    if(isS3X0 == 2)
    {
        p->hpsebiao.set_sebiao(colorruleminid,colorrulemaxid,true);
    }else{
        p->hpsebiao.set_sebiao(colorruleminid,colorrulemaxid,false);
    }

    m_colorrulemaxid = colorrulemaxid;
    m_colorruleminid = colorruleminid;
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","ZOOMRANGE","content");
//        qDebug() << "ZOOMRANGE == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() > 2)
            {
                p->hpresize.set_resize35(para.toInt());
            }else{
                p->hpresize.set_resize35(8);
            }
            break;
        }
    }
    bool xmlFocusmode = false;
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","focusmode");
//        qDebug() << "focusmode == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() != 0)
            {
                int modeSelect = para.toInt();
                if(modeSelect == 1)
                {
                    ui->listWidget_focusmode->setItemHidden(ui->listWidget_focusmode->item(1), true);
                    ui->listWidget_focusmode->setItemHidden(ui->listWidget_focusmode->item(2), true);
                    ui->listWidget_focusmode->setCurrentRow(0);
                }
                else if(modeSelect == 2)
                {
                    ui->listWidget_focusmode->setItemHidden(ui->listWidget_focusmode->item(0), true);
                    ui->listWidget_focusmode->setItemHidden(ui->listWidget_focusmode->item(2), true);
                    ui->listWidget_focusmode->setCurrentRow(1);
                }
                else if(modeSelect == 3)
                {
                    ui->listWidget_focusmode->setItemHidden(ui->listWidget_focusmode->item(0), true);
                    ui->listWidget_focusmode->setItemHidden(ui->listWidget_focusmode->item(1), true);
                    ui->listWidget_focusmode->setCurrentRow(2);
                }
                else if(modeSelect == 12)
                {
                    ui->listWidget_focusmode->setCurrentRow(0);
                    ui->listWidget_focusmode->setItemHidden(ui->listWidget_focusmode->item(2), true);
                }
                else if(modeSelect == 13)
                {
                    ui->listWidget_focusmode->setCurrentRow(0);
                    ui->listWidget_focusmode->setItemHidden(ui->listWidget_focusmode->item(1), true);
                }
                else if(modeSelect == 23)
                {
                    ui->listWidget_focusmode->setCurrentRow(1);
                    ui->listWidget_focusmode->setItemHidden(ui->listWidget_focusmode->item(0), true);
                }
                else
                {
                    ui->listWidget_focusmode->setCurrentRow(0);//设置为普通模式
                }
                xmlFocusmode = true;
            }
            break;
        }
    }

    if(!xmlFocusmode)
    {
        for(int i = 0;i < 10;i++)
        {
            para = hpxmlreader.XmlInit_read("sys.xml","MODULE","laser");
            qDebug() << "laser == > " << para.toInt();
            if(!hpxmlreader.errorRead)
            {
                if(para.toInt() == 1)
                {
 //                    p->define_laser = true;
                    fastfocusmode = true;//若focusmode未打开，则使用这个
//                    yqsz_focusmode_current_index_changed(1);
                    signal_pc_sys_set_autofocusmode(1);//相当于开启快速自动聚焦
                }else{
 //                    p->define_laser = false;
                    fastfocusmode = false;//若focusmode未打开，则使用这个
                    ui->frame_focusmode->setEnabled(false);
                    signal_pc_sys_set_autofocusmode(0);//相当于开启快速自动聚焦
                }
                break;
            }
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","focus_save");
        qDebug() << "-----------------------------------------focus_save == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                hphide_biaoding.setStructSave(true);
            }
            break;
        }
    }
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","DEV","laserdev_type");
        qDebug() << "-----------------------------------------focus_save == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 2)
            {
                p->m_laserType = 2;
            }
            break;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","auto_reflect");
        qDebug() << "-----------------------------------------auto_reflect == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                ui->checkBox_ReflectTemp_enable->show();
                p->m_isAutoReflect = true;
            }
            break;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","insulation_sw");
        qDebug() << "-----------------------------------------insulation_sw == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                p->setInsulation(true);
            }
            break;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.XmlInit_read("sys.xml","MODULE","range_warn");
        qDebug() << "-----------------------------------------range_warn == > " << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() != 1)
            {
                int row1 = 15;
                int row2 = row1 + 60;
                int row3 = row2 + 60;
                int row4 = row3 + 60;
                int row5 = row4 + 60;
                int row6 = row5 + 60;
                int row7 = row6 + 60;
                int row8 = row7 + 60;

                ui->label_9->move(ui->label_9->x(), row1);
                ui->frame_jingtou->move(ui->frame_jingtou->x(), row1);
                ui->label_10->move(ui->label_10->x(), row2);
                ui->frame_wendang->move(ui->frame_wendang->x(), row2);
                ui->cwfw_autorectify->move(ui->cwfw_autorectify->x(), row3);
                ui->comboBox_baojingwendu->move(ui->comboBox_baojingwendu->x(), row4);
                ui->label_13->move(ui->label_13->x(), row5);
                ui->frame_bangjingshehzi->move(ui->frame_bangjingshehzi->x(), row5);
                ui->label_15->move(ui->label_15->x(), row6);
                ui->frame_baojingse->move(ui->frame_baojingse->x(), row6);
                ui->label_20->move(ui->label_20->x(), row7);
                ui->checkBox_Catch->move(ui->checkBox_Catch->x(), row7);
                ui->label_30->move(ui->label_30->x(), row8);
                ui->dengwengse_edit->move(ui->dengwengse_edit->x(), row8);
                ui->comboBox_baojingjuli->close();
            }
            break;
        }
    }

    if(isS3X0 == 2)//若是 S300
    {
        define_S6X0_S3X0 = true;
        p->hp_setDefine_S3x0(true);
        hp_setS3X0(true);
    }else
    {
        if(isS3X0 == 3)
        {
            p->isHcf = true;
        }
        define_S6X0_S3X0 = false;
        p->hp_setDefine_S3x0(false);
        hp_setS3X0(false);
    }
    p->hppreview->define_s3X0 = isS3X0;
    if(isS3X0 == 0)
    {
        p->hp_setDefine_Szoom(true);
    }else{
        p->hp_setDefine_Szoom(false);
    }
    if(isS3X0 == 2)
    {
        QList<int> yset;
        yset.append(140);
        yset.append(170);
        yset.append(200);
        yset.append(230);
        int currFrameIndex = 0;
        if(xmlTaskmode)
        {
            ui->label_32->setGeometry(50, yset.at(currFrameIndex), 80, 25);
            ui->frame_modeSelect->setGeometry(150, yset.at(currFrameIndex), 150, 24);
            ui->listWidget_modeSelect->setGeometry(ui->frame_modeSelect->x(),ui->frame_modeSelect->y() + ui->frame_modeSelect->height(),ui->frame_modeSelect->width(),ui->frame_modeSelect->height() * 2 - 5);
            ui->label_32->show();
            ui->frame_modeSelect->show();
            currFrameIndex++;
        }
        else if(xmlFocusmode)
        {
            fastfocusmode = false;
            signal_pc_sys_set_autofocusmode(0);
            ui->label_45->setGeometry(50, yset.at(currFrameIndex), 80, 25);
            ui->frame_focusmode->setGeometry(150, yset.at(currFrameIndex), 150, 24);
            ui->listWidget_focusmode->move(ui->frame_focusmode->x(),ui->frame_focusmode->y() + ui->frame_focusmode->height());
            ui->label_45->show();
            ui->frame_focusmode->show();
            currFrameIndex++;
        }
        else if(xmlImageType)
        {
            ui->label_38->setGeometry(50, yset.at(currFrameIndex), 80, 25);
            ui->frame_imageType->setGeometry(150, yset.at(currFrameIndex), 150, 24);
            ui->listWidget_imageType->setGeometry(ui->frame_modeSelect->x(),ui->frame_modeSelect->y() + ui->frame_modeSelect->height(),ui->frame_modeSelect->width(),ui->frame_modeSelect->height());
            ui->label_38->show();
            ui->frame_imageType->show();
            currFrameIndex++;
        }
        ui->label_19->setGeometry(50, yset.at(currFrameIndex), 80, 25);   //usb模式
        ui->frame_usbmode->setGeometry(150, yset.at(currFrameIndex), 150, 24);
        ui->listWidget_usbmode->move(ui->frame_usbmode->x(),ui->frame_usbmode->y() + ui->frame_usbmode->height());

        currFrameIndex++;
        ui->label_29->setGeometry(50, yset.at(currFrameIndex), 80, 25);  //录制模式
        ui->frame_recordmode->setGeometry(150, yset.at(currFrameIndex), 150, 24);
        ui->listWidget_recordmode->move(ui->frame_recordmode->x(),ui->frame_recordmode->y() + ui->frame_recordmode->height());

        currFrameIndex++;
        ui->label_24->setGeometry(50, yset.at(currFrameIndex), 80, 25);  //自动存储
        ui->spinBox_autosave->setGeometry(150, yset.at(currFrameIndex), 150, 24);
    }else{
        QList<int> yset;
        yset.append(240);
        yset.append(300);
        yset.append(360);
        yset.append(420);
        int currFrameIndex = 0;
        int labelWidth = 173;
        int frameWidth = 243;
        int labelHeight = 50;
        int frameHeight = 48;

        int labelSetX = 30;
        int frameSetX = 225;
        if(xmlTaskmode)
        {
            ui->label_32->setGeometry(labelSetX, yset.at(currFrameIndex), labelWidth, labelHeight);
            ui->frame_modeSelect->setGeometry(frameSetX, yset.at(currFrameIndex), frameWidth, frameHeight);
            ui->listWidget_modeSelect->setGeometry(ui->frame_modeSelect->x(),ui->frame_modeSelect->y() + ui->frame_modeSelect->height(),ui->frame_modeSelect->width(), 70);
            ui->label_32->show();
            ui->frame_modeSelect->show();
            currFrameIndex++;
        }
        else if(xmlFocusmode)
        {
            fastfocusmode = false;
            signal_pc_sys_set_autofocusmode(0);
            ui->label_45->setGeometry(labelSetX, yset.at(currFrameIndex), labelWidth, labelHeight);
            ui->frame_focusmode->setGeometry(frameSetX, yset.at(currFrameIndex), frameWidth, frameHeight);
            ui->listWidget_focusmode->move(ui->frame_focusmode->x(),ui->frame_focusmode->y() + ui->frame_focusmode->height());
            ui->label_45->show();
            ui->frame_focusmode->show();
            currFrameIndex++;
        }
        else if(xmlImageType)
        {
            ui->label_38->setGeometry(labelSetX, yset.at(currFrameIndex), labelWidth, labelHeight);
            ui->frame_imageType->setGeometry(frameSetX, yset.at(currFrameIndex), frameWidth, frameHeight);
            ui->listWidget_imageType->setGeometry(ui->frame_imageType->x(),ui->frame_imageType->y() + ui->frame_imageType->height(),ui->frame_imageType->width(),ui->frame_imageType->height() * 3);
            ui->label_38->show();
            ui->frame_imageType->show();
            currFrameIndex++;
        }
        ui->label_19->setGeometry(labelSetX, yset.at(currFrameIndex), labelWidth, labelHeight);   //usb模式
        ui->frame_usbmode->setGeometry(frameSetX, yset.at(currFrameIndex), frameWidth, frameHeight);
        ui->listWidget_usbmode->move(ui->frame_usbmode->x(),ui->frame_usbmode->y() + ui->frame_usbmode->height());

        currFrameIndex++;
        ui->label_29->setGeometry(labelSetX, yset.at(currFrameIndex), labelWidth, labelHeight);  //录制模式
        ui->frame_recordmode->setGeometry(frameSetX, yset.at(currFrameIndex), frameWidth, frameHeight);
        ui->listWidget_recordmode->move(ui->frame_recordmode->x(),ui->frame_recordmode->y() + ui->frame_recordmode->height());

        currFrameIndex++;
        ui->label_24->setGeometry(labelSetX, yset.at(currFrameIndex), labelWidth, labelHeight);  //自动存储
        ui->spinBox_autosave->setGeometry(frameSetX, yset.at(currFrameIndex), frameWidth, frameHeight);
    }

    return false;
}
void HpSetting::hp_setS3X0(bool isS3X0)
{
    qDebug() << ">> HpSetting::hp_setS3X0 <<";
    if(isS3X0)
    {
        QFont font10;
        font10.setPointSize(10);
        QFont font11;
        font11.setPointSize(11);

        QTabBar *tabBar=ui->tabWidget->findChildren<QTabBar*>().at(0);
        p_tws->m_width = 96;
        p_tws->m_height = 40;
        tabBar->setStyle(p_tws);
        ui->frame_other->raise();
        ui->frame->setGeometry(0,0,581,272);
        ui->tabWidget->setGeometry(0,0,480,272);
        ui->ScrollBar_AmbientTempManu->setGeometry(70,103,220,25);
        ui->ScrollBar_Distance->setGeometry(70,39,220,25);
        ui->ScrollBar_Humidity->setGeometry(70,71,220,25);
        ui->ScrollBar_Radiance->setGeometry(70,7,220,25);
        ui->ScrollBar_ReferTemp->setGeometry(70,199,220,25);
        ui->ScrollBar_ReflectTemp->setGeometry(70,135,220,25);
        ui->frame_ReflectTemp->setGeometry(70,135,220,25);
        ui->label_ReflectTemp->setGeometry(0,0,195,25);
        ui->label_ReflectTemp_2->setGeometry(195,1,25,25);
        ui->listWidget_ReflectTemp->setGeometry(ui->frame_ReflectTemp->x(), ui->frame_ReflectTemp->y() + ui->frame_ReflectTemp->height(), ui->frame_ReflectTemp->width(), 50);
        ui->ScrollBar_TempUnit->setGeometry(70,231,220,25);
        ui->ScrollBar_transmission->setGeometry(70,167,220,25);
        ui->checkBox_Radiance->setGeometry(25,7,42,23);
        ui->checkBox_ReferTemp_enable->setGeometry(25,199,42,23);
        ui->frame_Radiance->setGeometry(70,7,220,25);
        ui->label_Radiance->setGeometry(0,0,195,25);
        ui->label_Radiance_2->setGeometry(195,1,25,25);
        ui->listWidget_Radiance->setGeometry(ui->frame_Radiance->x(),ui->frame_Radiance->y() + ui->frame_Radiance->height(),ui->frame_Radiance->width(),131);
        ui->checkBox_ReflectTemp_enable->setGeometry(25,ui->ScrollBar_ReflectTemp->y(),42,23);
        ui->checkBox_Catch->setGeometry(250,200,42,23);
        ui->comboBox_baojingse->setGeometry(100,0,21,20);
        ui->comboBox_baojingshezhi->setGeometry(60,0,21,25);
        ui->comboBox_baojingwendu->setGeometry(70,103,220,25);
        ui->comboBox_buchangwendu->setGeometry(70,240,220,25);
        ui->comboBox_dangwei->setGeometry(40,0,21,25);
        ui->comboBox_jingtou->setGeometry(10,0,21,25);
        ui->cwfw_autorectify->setGeometry(70,71,220,25);
        ui->dengwengse_edit->setGeometry(250,231,52,23);
        ui->frame_bangjingshehzi->setGeometry(140,135,151,25);
        ui->label_bangjingshehzi->setGeometry(0,0,126,25);
        ui->label_bangjingshehzi_2->setGeometry(126,1,23,23);
        ui->frame_baojingse->setGeometry(140,167,151,25);
        ui->label_baojingse->setGeometry(0,0,121,25);
        ui->label_baojingse_2->setGeometry(126,1,23,23);
        ui->frame_jingtou->setGeometry(140,7,151,25);
        ui->label_jingtou->setGeometry(0,0,125,25);
        ui->label_jingtou_2->setGeometry(127,1,23,23);
        ui->frame_wendang->setGeometry(140,39,151,25);
        ui->label_wendang->setGeometry(0,0,126,25);
        ui->label_wendang_2->setGeometry(127,1,23,23);
        ui->label_10->setGeometry(20,39,111,25);
        ui->label_30->setGeometry(70,231,171,35);//等温色
        ui->label_13->setGeometry(20,135,111,25);
        ui->label_15->setGeometry(20,167,111,25);
        ui->label_20->setGeometry(70,199,171,25);//高低温捕捉
        ui->label_9->setGeometry(20,7,111,25);
//        ui->listWidget_baojingse->setGeometry(360,210,71,21);
//        ui->listWidget_baojingshezhi->setGeometry(360,180,71,21);
//        ui->listWidget_jingtou->setGeometry(360,30,71,21);
//        ui->listWidget_wendang->setGeometry(360,70,71,21);
        ui->pushButton_qiehuan->setGeometry(300,43,55,30);

        ui->label_modeSelect->setGeometry(0,0,121,25);
        ui->label_modeSelect_2->setGeometry(121,1,23,23);
        ui->label_focusmode->setGeometry(0,0,121,25);
        ui->label_focusmode_2->setGeometry(121,1,23,23);
        ui->label__imageType->setGeometry(0,0,121,25);
        ui->label__imageType_2->setGeometry(121,1,23,23);
        ui->label_recordmode->setGeometry(0,0,121,25);
        ui->label_recordmode_2->setGeometry(121,1,23,23);
        ui->label_usbmode->setGeometry(0,0,121,25);
        ui->label_usbmode_2->setGeometry(121,1,23,23);

        ui->auto_lcdoff->setGeometry(50,0,21,25);
        ui->auto_poweroff->setGeometry(30,0,21,25);
        ui->frame_language->setGeometry(70,15,220,25);
        ui->label_language->setGeometry(0,0,195,25);
        ui->label_language2->setGeometry(196,1,23,23);
        ui->comboBox_language->setGeometry(10,10,21,25);
        ui->dateTimeEdit->setGeometry(70,50,220,25);
        ui->frame_poweroff->setGeometry(140,85,151,25);
        ui->label_poweroff->setGeometry(0,0,126,25);
        ui->label_poweroff_2->setGeometry(127,2,23,23);
        ui->frame_lcdoff->setGeometry(140,120,151,25);
        ui->label_lcdoff->setGeometry(0,0,126,25);
        ui->label_lcdoff_2->setGeometry(127,2,23,23);
        ui->label_22->setGeometry(50,80,80,25);
        ui->label_23->setGeometry(50,115,80,25);
        if(isHotkey)
        {
            ui->label_49->setGeometry(50,150,80,25);
            ui->pushButton_hotkey->setGeometry(140,150,151,25);
            ui->pushButton_3->setGeometry(70,185,220,25);
            ui->pushButton_default->setGeometry(70,220,220,25);
        }
        else
        {
            ui->label_49->close();
            ui->pushButton_hotkey->close();
            ui->pushButton_3->setGeometry(70,150,220,25);
            ui->pushButton_default->setGeometry(70,185,220,25);
        }
        ui->hp_logo->setGeometry(60,62,191,34);
        ui->hp_logo->setFixedSize(191,34);

        ui->label_yiqixinghao->setGeometry      (41, 103,101,17);
        ui->label_xinghao_text->setGeometry     (141,103,131,18);
        ui->label_yiqibianhao->setGeometry      (41, 127,101,17);
        ui->label_bianhao_text->setGeometry     (141,127,131,18);
        ui->label_ruanjianbanben->setGeometry   (41, 151,101,17);
        ui->label_banben_text->setGeometry      (141,151,131,18);
        ui->label_gujianbanben->setGeometry     (41, 175,101,17);
        ui->label_gujianbanben_text->setGeometry(141,175,131,18);
        ui->label_shengchanriqi->setGeometry    (41, 199,101,17);
        ui->label_riqi_text->setGeometry        (141,199,151,18);
        ui->frame->setFont(font10);
        ui->tabWidget->setFont(font11);
        ui->ScrollBar_AmbientTempManu->setFont(font10);
        ui->ScrollBar_Distance->setFont(font10);
        ui->ScrollBar_Humidity->setFont(font10);
        ui->ScrollBar_Radiance->setFont(font10);
        ui->ScrollBar_ReferTemp->setFont(font10);
        ui->ScrollBar_ReflectTemp->setFont(font10);
        ui->ScrollBar_TempUnit->setFont(font10);
        ui->ScrollBar_transmission->setFont(font10);
        ui->ScrollBar_Radiance->setFont(font10);
        ui->ScrollBar_ReflectTemp->setFont(font10);
        ui->frame_Radiance->setFont(font10);
        ui->label_Radiance->setFont(font10);
        ui->label_Radiance_2->setFont(font10);
        ui->listWidget_Radiance->setFont(font10);
        ui->checkBox_Catch->setFont(font10);
        ui->comboBox_baojingse->setFont(font10);
        ui->comboBox_baojingshezhi->setFont(font10);
        ui->comboBox_baojingwendu->setFont(font10);
        ui->comboBox_buchangwendu->setFont(font10);
        ui->comboBox_dangwei->setFont(font10);
        ui->comboBox_jingtou->setFont(font10);
        ui->cwfw_autorectify->setFont(font10);
        ui->dengwengse_edit->setFont(font10);
        ui->frame_bangjingshehzi->setFont(font10);
        ui->label_bangjingshehzi->setFont(font10);
        ui->label_bangjingshehzi_2->setFont(font10);
        ui->frame_baojingse->setFont(font10);
        ui->label_baojingse->setFont(font10);
        ui->label_baojingse_2->setFont(font10);
        ui->frame_jingtou->setFont(font10);
        ui->label_jingtou->setFont(font10);
        ui->label_jingtou_2->setFont(font10);
        ui->frame_wendang->setFont(font10);
        ui->label_wendang->setFont(font10);
        ui->label_wendang_2->setFont(font10);
        ui->label_10->setFont(font10);
        ui->label_30->setFont(font10);
        ui->label_13->setFont(font10);
        ui->label_15->setFont(font10);
        ui->label_20->setFont(font10);
        ui->label_9->setFont(font10);
        ui->label_31->setFont(font10);
        ui->label_gujianbanben_text->setFont(font10);
        ui->label_gujianbanben->setFont(font10);
        ui->listWidget_baojingse->setFont(font10);
        ui->listWidget_baojingshezhi->setFont(font10);
        ui->listWidget_jingtou->setFont(font10);
        ui->listWidget_wendang->setFont(font10);
        ui->pushButton_qiehuan->setFont(font10);

        ui->ble_edit->setFont(font10);
        ui->mulhom_edit->setFont(font10);
        ui->wifi_edit->setFont(font10);
        ui->autoUpload_edit->setFont(font10);
        ui->btautoUpload_once->setFont(font10);
        ui->btdownload->setFont(font10);

        ui->auto_lcdoff->setFont(font10);
        ui->auto_poweroff->setFont(font10);
        ui->dateTimeEdit->setFont(font10);
        ui->comboBox_language->setFont(font10);
        ui->frame_language->setFont(font10);
        ui->label_language->setFont(font10);
        ui->label_language2->setFont(font10);
        ui->frame_lcdoff->setFont(font10);
        ui->label_lcdoff->setFont(font10);
        ui->label_lcdoff_2->setFont(font10);
        ui->frame_poweroff->setFont(font10);
        ui->label_poweroff->setFont(font10);
        ui->label_poweroff_2->setFont(font10);
        ui->label_22->setFont(font10);
        ui->label_23->setFont(font10);
        ui->label_49->setFont(font10);
        ui->pushButton_hotkey->setFont(font10);
        ui->listWidget_language->setFont(font10);
        ui->listWidget_lcdoff->setFont(font10);
        ui->listWidget_poweroff->setFont(font10);
        ui->pushButton_default->setFont(font10);

        ui->label_banben_text->setFont(font10);
        ui->label_bianhao_text->setFont(font10);
        ui->label_riqi_text->setFont(font10);
        ui->label_ruanjianbanben->setFont(font10);
        ui->label_shengchanriqi->setFont(font10);
        ui->label_xinghao_text->setFont(font10);
        ui->label_yiqibianhao->setFont(font10);
        ui->label_yiqixinghao->setFont(font10);
        ui->label_32->setFont(font10);
        ui->label_modeSelect->setFont(font10);
        ui->frame_modeSelect->setFont(font10);
        ui->listWidget_modeSelect->setFont(font10);

        ui->label_16->setFont(font10);
        ui->label_17->setFont(font10);
        ui->label_27->setFont(font10);
        ui->label_18->setFont(font10);
        ui->label_21->setFont(font10);
        ui->label_26->setFont(font10);
        ui->label_19->setFont(font10);
        ui->label_28->setFont(font10);
        ui->label_24->setFont(font10);
        ui->label_25->setFont(font10);
        ui->label_29->setFont(font10);
        ui->label_33->setFont(font10);
        ui->label_35->setFont(font10);
        ui->label_36->setFont(font10);
        ui->label_37->setFont(font10);
        ui->label_39->setFont(font10);
        ui->label_48->setFont(font10);
        ui->label_usbmode->setFont(font10);
        ui->label_recordmode->setFont(font10);
        ui->spinBox_autosave->setFont(font10);
        ui->pushButton_3->setFont(font10);
        ui->listWidget_recordmode->setFont(font10);
        ui->listWidget_usbmode->setFont(font10);

        ui->label_45->setFont(font10);
        ui->frame_focusmode->setFont(font10);
        ui->label_focusmode->setFont(font10);
        ui->listWidget_focusmode->setFont(font10);
        ui->label_38->setFont(font10);
        ui->label__imageType->setFont(font10);
        ui->label__imageType_2->setFont(font10);
        ui->listWidget_imageType->setFont(font10);
        ui->label_ReflectTemp->setFont(font10);
        ui->listWidget_ReflectTemp->setFont(font10);

        ui->label_34->setFont(font10);
        ui->checkBox_sis->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");

        ui->checkBox_area->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_autoUpload->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_ble->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_Catch->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_fid->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_pid->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_Radiance->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_ReferTemp_enable->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_ReflectTemp_enable->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_sr->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_wifi->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->buguangdeng->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_hdmi->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_mulhom->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_gw->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_panorama->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_zoomSave->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_oritoggle->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_homogeneity->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_stepZero->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_4G->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_compass->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_nonCool->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");

ui->ScrollBar_Radiance->setStyleSheet("QSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QSpinBox::up-button:pressed{ \
subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
height: 24;}");
ui->ScrollBar_Distance->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                      image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                      subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                      QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                      height: 24;}");
ui->ScrollBar_Humidity->setStyleSheet("QSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                      image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QSpinBox::up-button:pressed{ \
                                      subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                      QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                      height: 24;}");
ui->ScrollBar_AmbientTempManu->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                             image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                             subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                             QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                             height: 24;}");
ui->ScrollBar_ReflectTemp->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                         image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                         subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                         QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                         height: 24;}");
ui->ScrollBar_transmission->setStyleSheet("QSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                          image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QSpinBox::up-button:pressed{ \
                                          subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                          QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                          height: 24;}");
ui->ScrollBar_ReferTemp->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                       image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                       subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                       QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                       height: 24;}");
ui->ScrollBar_TempUnit->setStyleSheet("QSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                      image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QSpinBox::up-button:pressed{ \
                                      subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                      QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                      height: 24;}");
ui->cwfw_autorectify->setStyleSheet("QSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                    image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QSpinBox::up-button:pressed{ \
                                    subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                    QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                    height: 24;}");
ui->comboBox_baojingwendu->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                    image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                    subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                    QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                    height: 24;}");
ui->comboBox_buchangwendu->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                    image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                    subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                    QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                    height: 24;}");
ui->spinBox_autosave->setStyleSheet("QSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                    image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QSpinBox::up-button:pressed{ \
                                    subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                    QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                    height: 24;}");
ui->dateTimeEdit->setStyleSheet("QDateTimeEdit{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDateTimeEdit::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                    image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDateTimeEdit::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDateTimeEdit::up-button:pressed{ \
                                    subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDateTimeEdit::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                    QDateTimeEdit::down-arrow:disabled,QDateTimeEdit::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDateTimeEdit::up-arrow:disabled,QDateTimeEdit::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                    height: 24;}");

//                                    ui->listWidget_Radiance->setStyleSheet("");
      ui->listWidget_Radiance->setStyleSheet(LISTWIDGETS3X0);
      ui->listWidget_ReflectTemp->setStyleSheet(LISTWIDGETS3X0);

        ui->frame_other->show();
        ui->frame_other->raise();

        ui->scrollArea->horizontalScrollBar()->hide();
        ui->scrollArea->horizontalScrollBar()->setStyleSheet("height:0px;");
        ui->scrollArea->verticalScrollBar()->hide();
        ui->scrollArea->verticalScrollBar()->setStyleSheet("width:0px;");
    }else{
        QTabBar *tabBar=ui->tabWidget->findChildren<QTabBar*>().at(0);
        p_tws->m_width = 160;
        p_tws->m_height = 80;
        tabBar->setStyle(p_tws);

        ui->frame_other->close();
        QFont font17;
        font17.setPointSize(17);

        ui->frame_ReflectTemp->setGeometry(ui->ScrollBar_ReflectTemp->x(), ui->ScrollBar_ReflectTemp->y(), ui->ScrollBar_ReflectTemp->width(), ui->ScrollBar_ReflectTemp->height());
        ui->listWidget_ReflectTemp->setGeometry(ui->frame_ReflectTemp->x(), ui->frame_ReflectTemp->y() + ui->frame_ReflectTemp->height(), ui->frame_ReflectTemp->width(), 105);
        ui->label_ReflectTemp->setFont(font17);
        ui->listWidget_ReflectTemp->setFont(font17);

        ui->ScrollBar_Radiance->hp_setFont(font17);
        ui->ScrollBar_Distance->hp_setFont(font17);
        ui->ScrollBar_Humidity->hp_setFont(font17);
        ui->ScrollBar_AmbientTempManu->hp_setFont(font17);
        ui->ScrollBar_ReflectTemp->hp_setFont(font17);
        ui->ScrollBar_transmission->hp_setFont(font17);
        ui->ScrollBar_ReferTemp->hp_setFont(font17);
        ui->ScrollBar_TempUnit->hp_setFont(font17);

        ui->scrollArea->horizontalScrollBar()->hide();
        ui->scrollArea->horizontalScrollBar()->setStyleSheet("height:0px;");
    }
    m_transmissionSearch->hp_setDefine_S3x0(isS3X0);
    hp_downLoad->hp_setDefine_S3x0(isS3X0);
    m_hotkeyWidget.hp_setDefine_S3x0(isS3X0);
    hpblesearchold.hp_setDefine_S3x0(isS3X0);
    hpblesearch.hp_setDefine_S3x0(isS3X0);
    hpdefault->hp_setDefine_S3x0(isS3X0);
    hpdialog->hp_setDefine_S3x0(isS3X0);
    hpformat->hp_setDefine_S3x0(isS3X0);
    hpisotherm.hp_setDefine_S3x0(isS3X0);
    hpcpumem->hp_setDefine_S3x0(isS3X0);
    hphide_biaoding.hp_setDefine_S3x0(isS3X0);
    hphide_biaoding.hp_hide_dialog->hp_setDefine_S3x0(isS3X0);
    hphide_biaoding.hp_hide_dialog_lo->hp_setDefine_S3x0(isS3X0);
    hphide_biaoding.hp_hide_dialog_save->hp_setDefine_S3x0(isS3X0);
    hphidemenu.hp_setDefine_S3x0(isS3X0);
    hp_wifi_Search->hp_setDefine_S3x0(isS3X0);
    hp_autoupload->hp_setDefine_S3x0(isS3X0);
    hp_autoupload_dialog->hp_setDefine_S3x0(isS3X0);
    hp_Common_dialog_select->hp_setDefine_S3x0(isS3X0);
    hp_Mulhom_edit->hp_setDefine_S3x0(isS3X0);
}

void HpSetting::initStyleSheet()
{

}

void HpSetting::para_init()//开机时，设置内一些值的读取
{
    jingtou_init = true;
    wendang_init = true;
    QString str,para;
    qDebug("start para......");
    jingtou_changing = false;

    dangwei_exit[0]=0;
    dangwei_exit[1]=0;
    dangwei_exit[2]=0;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    qDebug("read language index:%d",para.toInt());

    ui->listWidget_language->setCurrentRow(para.toInt());

    if( para!= NULL)
    {
        if(para.toInt()>=0&&para.toInt()<ui->comboBox_language->count())
        {
            ui->comboBox_language->setCurrentIndex(para.toInt());
        }
        else
        {
            ui->comboBox_language->setCurrentIndex(0);
        }
    }
    else
    {
        ui->comboBox_language->setCurrentIndex(0);
    }


    if(QFile::exists("/home/root/qtconfig.xml"))
    {
        para = hpxmlreader.readXml("/home/root/qtconfig.xml","FPGA_UPDATE","filename");
        if( para!= NULL)
        {
            ui->label_gujianbanben_text->setText(para.split(".b").at(0));
        }
    }




//四个镜头： 标准、长焦、广角、预留一个
//三个挡位： 低温、中温、高温、       挡位选择 i*3(镜头号)+1（挡位号）

    //lensnum   4个镜头
    para = hpxmlreader.readXml("config.xml","LENSSET","lensnum");
    if(para != NULL)
        lensnum = para.toInt();
    else
        lensnum = 4;

    //rangenum  3个挡位
    para = hpxmlreader.readXml("config.xml","LENSSET","rangenum");
    if(para != NULL)
        rangenum = para.toInt();
    else
        rangenum = 2;

    //当前档位号
    para = hpxmlreader.readXml("config.xml","LENSSET","rangeid");
    if(para != NULL)
        TempRange.TempRangeID = para.toInt();
    else
        TempRange.TempRangeID = 0;
    //当前镜头号
    para = hpxmlreader.readXml("config.xml","LENSSET","lensid");
    if(para != NULL)
        TempRange.LensId = para.toInt();
    else
        TempRange.LensId = 0;

    //镜头变化时同时变化图像旋转
    QString pararotate;
    pararotate = hpxmlreader.readXml("config.xml","IMAGEROTATE","diameter" + QString::number(TempRange.LensId));
    qDebug() << " >>> config.xml IMAGEROTATE diameter" + QString::number(TempRange.LensId) + " == > " << pararotate;
    if(pararotate != NULL)
    {
        TempRange.ImageRotate = pararotate.toInt();
        hphide_biaoding.setCheckboxrotate(pararotate.toInt());
    }
    int readnumEr = 0;
    while(hpxmlreader.errorRead)
    {
        delaymsec(100);
        readnumEr++;
        pararotate = hpxmlreader.readXml("config.xml","IMAGEROTATE","diameter" + QString::number(TempRange.LensId));
        qDebug() << " >>> config.xml IMAGEROTATE diameter" + QString::number(TempRange.LensId) + " == > " << pararotate;
        if(pararotate != NULL)
        {
            TempRange.ImageRotate = pararotate.toInt();
            hphide_biaoding.setCheckboxrotate(pararotate.toInt());
        }
        if(readnumEr > 10)
        {
            break;
        }
    }
    //镜头变化时同时变化图像旋转

    int now_lensld = TempRange.LensId + 1;                                                  //获取当前镜头号 从1开始

    DANGWEI l_dangwei;                                                  // 挡位结构体

    if(!dangwei_list.isEmpty())
        dangwei_list.clear();

    jingtou_enable_num=0;
    int jingtou = 0;
    for(int i=1;i<lensnum+1;i++)                //镜头数量4
    {
        para = hpxmlreader.readXml("config.xml","LENSSET","valid"+QString::number(i));
        jingtou_state[i-1]=0;                           //初始化为0
        jingtou_enable[i-1]=0;
        if(para.contains('1'))                  //如果包含字符1
        {
            jingtou_state[i-1]=1;
            jingtou_enable[jingtou] = i-1;//之后可以循环打印一下这个值
            jingtou++;
            jingtou_enable_num++;
        }


        if(para != NULL)
        {

            QIcon icon (":/res/res/combobox_icon.png");
            if(para.toInt() == 1)//若当前镜头使能
            {
                QString jingtou;
                jingtou = hpxmlreader.readXml("config.xml","LENSSET","diameter"+QString::number(i));//读取镜头文本
                if(jingtou != NULL)
                {
                    ui->comboBox_jingtou->addItem(icon,jingtou);

                    QListWidgetItem *listWidgetItem = new QListWidgetItem;
                    listWidgetItem->setText(jingtou);
                    ui->listWidget_jingtou->addItem(listWidgetItem);//添加镜头文本
                }

 //第一个挡位LENS1
                QString MinTemp,MaxTemp;
                MinTemp = hpxmlreader.readXml("config.xml","LENS"+QString::number((i-1)*3+1),"MinTemp");//读取镜头最大值最小值
                MaxTemp = hpxmlreader.readXml("config.xml","LENS"+QString::number((i-1)*3+1),"MaxTemp");


                if(MinTemp != NULL && MaxTemp != NULL)
                {
                    l_dangwei.minTemp = MinTemp.toInt()*100;
                    l_dangwei.maxTemp = MaxTemp.toInt()*100;

                    //最大值、最小值默认参数，用于防止报警温度超过挡位值
                    dangweiMinTemp = hptempunitconvert.getTempValue(tempunit,l_dangwei.minTemp)/100;
                    dangweiMaxTemp = hptempunitconvert.getTempValue(tempunit,l_dangwei.maxTemp)/100;
//                    if(dangweiMaxTemp == 80 && dangweiMinTemp == -20)
//                    {
//                        signal_noncool_unenable_plr(true);
//                        yqsz_nonCool_setchecked(true);
//                        ui->checkBox_nonCool->setChecked(true);
//                    }
//                    else
//                    {
//                        signal_noncool_unenable_plr(false);
//                        yqsz_nonCool_setchecked(false);
//                        ui->checkBox_nonCool->setChecked(false);
//                    }
                    dangwei_list.append(l_dangwei);
                    QString tmp = QString::number(hptempunitconvert.getTempValue(tempunit,l_dangwei.minTemp)/100)+"~"+QString::number(hptempunitconvert.getTempValue(tempunit,l_dangwei.maxTemp)/100)+hptempunitconvert.getTempUnitString(tempunit);
                   if( now_lensld== i)   //now_lensld  根据当前选中的镜头编号选择显示对应的温度挡位
                   {
                       if( 0 != l_dangwei.minTemp || 0!=l_dangwei.maxTemp )
                       {
                            ui->comboBox_dangwei->addItem(icon,tmp);
                            QListWidgetItem *listWidgetItem = new QListWidgetItem;
                            listWidgetItem->setText(tmp);
                            ui->listWidget_wendang->addItem(listWidgetItem);//根据当前选中的镜头编号选择显示对应的温度挡位

                            dangwei_exit[0]=0;
                       }else{
                             dangwei_exit[0]=1;                                                                                    // =1表示 第一个测温挡位范围为 0-0
                       }


                   }
                }

//第二个挡位LENS2
                MinTemp = hpxmlreader.readXml("config.xml","LENS"+QString::number((i-1)*3+2),"MinTemp");
                MaxTemp = hpxmlreader.readXml("config.xml","LENS"+QString::number((i-1)*3+2),"MaxTemp");
                if(MinTemp != NULL && MaxTemp != NULL)
                {

                    l_dangwei.minTemp = MinTemp.toInt()*100;
                    l_dangwei.maxTemp = MaxTemp.toInt()*100;
                    dangwei_list.append(l_dangwei);
                    QString tmp = QString::number(hptempunitconvert.getTempValue(tempunit,l_dangwei.minTemp)/100)+"~"+QString::number(hptempunitconvert.getTempValue(tempunit,l_dangwei.maxTemp)/100)+hptempunitconvert.getTempUnitString(tempunit);
                    if( now_lensld== i)
                    {
                        if( 0!= l_dangwei.minTemp || 0!=l_dangwei.maxTemp )
                        {
                             ui->comboBox_dangwei->addItem(icon,tmp);
                             QListWidgetItem *listWidgetItem = new QListWidgetItem;
                             listWidgetItem->setText(tmp);
                             ui->listWidget_wendang->addItem(listWidgetItem);
                             dangwei_exit[1]=0;
                        }else{
                            dangwei_exit[1]=1;
                        }
                    }
                }

//第三个挡位
                MinTemp = hpxmlreader.readXml("config.xml","LENS"+QString::number((i-1)*3+3),"MinTemp");
                MaxTemp = hpxmlreader.readXml("config.xml","LENS"+QString::number((i-1)*3+3),"MaxTemp");
                if(MinTemp != NULL && MaxTemp != NULL)
                {
                    l_dangwei.minTemp = MinTemp.toInt()*100;
                    l_dangwei.maxTemp = MaxTemp.toInt()*100;
                    dangwei_list.append(l_dangwei);
                    QString tmp = QString::number(hptempunitconvert.getTempValue(tempunit,l_dangwei.minTemp)/100)+"~"+QString::number(hptempunitconvert.getTempValue(tempunit,l_dangwei.maxTemp)/100)+hptempunitconvert.getTempUnitString(tempunit);
                    if( now_lensld== i)
                    {
                        if( 0!= l_dangwei.minTemp || 0!=l_dangwei.maxTemp )
                        {
                             ui->comboBox_dangwei->addItem(icon,tmp);
                             QListWidgetItem *listWidgetItem = new QListWidgetItem;
                             listWidgetItem->setText(tmp);
                             ui->listWidget_wendang->addItem(listWidgetItem);
                            dangwei_exit[2]=0;
                        }else{
                            dangwei_exit[2]=1;
                        }
                    }
                }
            }
        }
    }
    //如果挡位范围有0的情况，挡位是三个0        1      2， 但实际界面的会小于三个
    int ui_dangwei_id = 0;

    //xml中挡位号是0             .说明ui挡位0肯定存在，
    if(0 ==TempRange.TempRangeID){
          ui_dangwei_id = TempRange.TempRangeID;
    };
    //xml中挡位号是1             考虑ui挡位号0是否存在
    if(1 ==TempRange.TempRangeID){
        if(1 == dangwei_exit[0] )                                       //ui挡位号0不存在。1--->不存在
        {
            ui_dangwei_id =0;
        }else{                                                                          //存在
            ui_dangwei_id = TempRange.TempRangeID;
        }
    };
    //xml中挡位号是2             考虑挡位0 或挡位1 是否存在。或者同时存在同时不存在
    if(2 ==TempRange.TempRangeID){
        if( 1==dangwei_exit[0] && 1 ==dangwei_exit[1]){                             //ui挡位 0 和1 同时不存在（即温度范围是0-0）
            ui_dangwei_id=0;
        }else if(0==dangwei_exit[0] && 0 ==dangwei_exit[1]){                    //ui挡位0和1  同时存在
            ui_dangwei_id=2;
        }else{                                                                                                       //一个存在或者一个不存在
            ui_dangwei_id=1;
        }
    };
     int ui_jingtou_id = 0;
     for(int i=0; i<jingtou_enable_num;i++)                     //循环遍历，根据镜头号的值，得出镜头实际在界面id的值
     {
         if( jingtou_enable[i] == TempRange.LensId)
         {
               ui_jingtou_id = i;
         }
     }
    ui->comboBox_dangwei->setCurrentIndex(ui_dangwei_id);       //挡位号 0 1 2
    ui->comboBox_jingtou->setCurrentIndex(ui_jingtou_id);                        //镜头号0 1 2 3
    jingtou_num=ui->listWidget_jingtou->count();
    dangwei_num=ui->listWidget_wendang->count();
    qDebug()  << __func__ <<" ; " << __LINE__ << " ; " << jingtou_num << " ; " << dangwei_num;
    ui->listWidget_jingtou->setCurrentRow(ui_jingtou_id);
    ui->listWidget_wendang->setCurrentRow(ui_dangwei_id);
    jingtouRow = ui_jingtou_id;
    dangweiRow = ui_dangwei_id;
    qDebug()  << __func__ <<" ; " << __LINE__ << " ; " << ui->listWidget_jingtou->currentRow() << " ; " << ui->listWidget_wendang->currentRow();
    ui->label_jingtou->setText(ui->listWidget_jingtou->currentItem()->text());
    ui->label_wendang->setText(ui->listWidget_wendang->currentItem()->text());

    l_dangwei = dangwei_list.at(TempRange.TempRangeID);

    para = hpxmlreader.readXml("sys.xml","ALARM","on");
    if(para != NULL)
        AlarmTemp.AlarmSwitch = para.toInt();
    else
        AlarmTemp.AlarmSwitch = 0;

    para = hpxmlreader.readXml("sys.xml","ALARM","temp100");
    if(para != NULL)
        AlarmTemp.AlarmTemp100 = para.toInt();
    else
        AlarmTemp.AlarmTemp100 = 3700;

    para = hpxmlreader.readXml("sys.xml","ALARM","color");
    if(para != NULL)
        AlarmTemp.AlarmColorId = para.toInt();
    else
        AlarmTemp.AlarmColorId = 0;
    para = hpxmlreader.readXml("sys.xml", "ALARM", "range100");
        ui->comboBox_baojingjuli->setValue((double)(para.toInt() * 1.0 / 100.0));
    ui->listWidget_baojingshezhi->setCurrentRow(AlarmTemp.AlarmSwitch);
    ui->label_bangjingshehzi->setText(ui->listWidget_baojingshezhi->currentItem()->text());
    ui->listWidget_baojingse->setCurrentRow(AlarmTemp.AlarmColorId);
    ui->label_baojingse->setText(ui->listWidget_baojingse->currentItem()->text());


    ui->comboBox_baojingwendu->setSuffix(hptempunitconvert.getTempUnitString(tempunit));
    ui->comboBox_baojingwendu->setValue(hptempunitconvert.getTempValue(tempunit,AlarmTemp.AlarmTemp100)/100.0);
    //补偿温度
    para = hpxmlreader.readXml("sys.xml","TEMPADJUST100","content");
    if(para != NULL)
        compensateValue = para.toInt();
    else
        compensateValue = 0;

    ui->comboBox_buchangwendu->setSuffix(hptempunitconvert.getTempUnitString(tempunit));
    ui->comboBox_buchangwendu->setValue(hptempunitconvert.getTempValue(tempunit,compensateValue)/100.0);

    //关屏时间
    para = hpxmlreader.readXml("sys.xml","SCREENSAVE","time");
    if(para != NULL)
        lcdoff_clock = para.toInt();
    else
        lcdoff_clock = 0;
    if( lcdoff_clock == 0 )
        ui->listWidget_lcdoff->setCurrentRow(0);
    else if( lcdoff_clock <= 15 && lcdoff_clock > 0 )
        ui->listWidget_lcdoff->setCurrentRow(1);
    else if( lcdoff_clock <= 60 && lcdoff_clock > 15 )
        ui->listWidget_lcdoff->setCurrentRow(2);
    else if( lcdoff_clock <= 300 && lcdoff_clock > 60 )
        ui->listWidget_lcdoff->setCurrentRow(3);
    else if( lcdoff_clock <= 1800 && lcdoff_clock > 300 )
        ui->listWidget_lcdoff->setCurrentRow(4);
    else if( lcdoff_clock <= 3200 && lcdoff_clock > 1800 )
        ui->listWidget_lcdoff->setCurrentRow(5);
    else if( lcdoff_clock <= 9600 && lcdoff_clock > 3200 )
        ui->listWidget_lcdoff->setCurrentRow(6);
    else if( lcdoff_clock <= 19200)
        ui->listWidget_lcdoff->setCurrentRow(7);
//    ui->listWidget_lcdoff->setCurrentRow(0);
    ui->listWidget_poweroff->setCurrentRow(0);

    //高低温捕捉
    int tempCatch=0;
    para = hpxmlreader.readXml("sys.xml","TEMPCAPTURE","on");
    if(para != NULL)
        tempCatch = para.toInt();
    else
        tempCatch = 0;
    if(tempCatch == 0)
    {
        ui->checkBox_Catch->setChecked(false);
        on_checkBox_Catch_clicked(false);
    }else{
        ui->checkBox_Catch->setChecked(true);
        on_checkBox_Catch_clicked(true);
    }
    //wdxz-1
    para = hpxmlreader.readXml("sys.xml","EMISSIVITY100","content");
    if(para != NULL)
        TempUserPara.Radiance100 = para.toInt();
    else
        TempUserPara.Radiance100 = 96;

    ui->ScrollBar_Radiance->setValue(TempUserPara.Radiance100);
    signal_update_radiance_to_display(TempUserPara.Radiance100);

    //辐射率表相关初始化
    para = hpxmlreader.readXml("sys.xml","RADTABLE_SWITCH","content");
    if(para != NULL)
        TempUserPara.RadTable_switch = para.toInt();
    else
        TempUserPara.RadTable_switch = 0;

    para = hpxmlreader.readXml("sys.xml","RADTABLE_ID","content");
    if(para != NULL)
        TempUserPara.RadTable_id = para.toInt();
    else
        TempUserPara.RadTable_id = 0;

    para = hpxmlreader.readXml("sys.xml","RADTABLE_VALUE100","content");
    if(para != NULL)
        TempUserPara.RadTable_value100 = para.toInt();
    else
        TempUserPara.RadTable_value100 = 96;

    ui->listWidget_Radiance->setCurrentRow(TempUserPara.RadTable_id);
    ui->label_Radiance->setText(ui->listWidget_Radiance->currentItem()->text());
    signal_update_radTable_to_display( TempUserPara.RadTable_id  , TempUserPara.RadTable_value100);
    signal_set_radTable_state(TempUserPara.RadTable_switch);

    //wdxz-2
    para = hpxmlreader.readXml("sys.xml","DISTANCE100","content");
    if(para != NULL)
        TempUserPara.Distance100 = para.toInt();
    else
        TempUserPara.Distance100 = 150;

    ui->ScrollBar_Distance->setValue(TempUserPara.Distance100/100.0);
    signal_update_distance_to_display(TempUserPara.Distance100);

    //wdxz-3
    para = hpxmlreader.readXml("sys.xml","HUMIDITY100","content");
    if(para != NULL)
        TempUserPara.Humidity100 = para.toInt();
    else
        TempUserPara.Humidity100 = 60;

    ui->ScrollBar_Humidity->setValue(TempUserPara.Humidity100);
    //wdxz-4
    para = hpxmlreader.readXml("sys.xml","AMBIENTTEMP100","content");
    if(para != NULL)
        TempUserPara.AmbientTempManu100 = para.toInt();
    else
        TempUserPara.AmbientTempManu100 = 2100;

    ui->ScrollBar_AmbientTempManu->setValue(TempUserPara.AmbientTempManu100/100.0);

    //wdxz-5
    para = hpxmlreader.readXml("sys.xml","REFLECTTEMP100","content");
    if(para != NULL)
        TempUserPara.ReflectTemp100 = para.toInt();
    else
        TempUserPara.ReflectTemp100 = 3000;

    ui->ScrollBar_ReflectTemp->setValue(TempUserPara.ReflectTemp100/100.0);
    signal_update_reflect_temp_to_display(TempUserPara.ReflectTemp100);
    //wdxz-6
    para = hpxmlreader.readXml("sys.xml","TRANSMISSION100","content");
    if(para != NULL)
        TempUserPara.transmission100 = para.toInt();
    else
        TempUserPara.transmission100 = 100;

    ui->ScrollBar_transmission->setValue(TempUserPara.transmission100);

    //wdxz-7
    para = hpxmlreader.readXml("sys.xml","TEMPPARA","refetype");
    if(para != NULL)
        TempReference.enable = para.toInt();
    else
        TempReference.enable = 0;

    para = hpxmlreader.readXml("sys.xml","TEMPPARA","refetemp100");
    if(para != NULL)
        TempReference.ReferTemp100 = para.toInt();
    else
        TempReference.ReferTemp100 = 3000;

    ui->checkBox_ReferTemp_enable->setChecked(TempReference.enable);

    ui->ScrollBar_ReferTemp->setMinimum(l_dangwei.minTemp/100.0);
    ui->ScrollBar_ReferTemp->setMaximum(l_dangwei.maxTemp/100.0);
    ui->ScrollBar_ReferTemp->setValue(TempReference.ReferTemp100/100.0);
    ui->ScrollBar_ReferTemp->setEnabled(TempReference.enable);
    para = hpxmlreader.readXml("config.xml","SOFTWAREVER","content");
    if(para != NULL)
        ui->label_banben_text->setText(para);

    para = hpxmlreader.readXml("config.xml","PRODUCEDTIME","content");
    if(para != NULL)
        ui->label_riqi_text->setText(para);

    para = hpxmlreader.readXml("config.xml","DEVICESN","content");
    if(para != NULL)
        ui->label_bianhao_text->setText(para);

    para = hpxmlreader.readXml("config.xml","DEVICEOEMNAME","content");
    if(para != NULL)
        ui->label_xinghao_text->setText(para);
    m_Transmission->hp_setEquipID(ui->label_xinghao_text->text(), ui->label_bianhao_text->text());
    memcpy(&TempReference_old,&TempReference,sizeof(ComTempReference));
    memcpy(&TempUserPara_old,&TempUserPara,sizeof(ComTempUserPara));

    ui->listWidget_modeSelect->setCurrentRow(0);
    para = hpxmlreader.readXml("sys.xml","USBTYPE","type");
    if(para != NULL)        //界面USB模式初始化
    {
        ui->listWidget_usbmode->setCurrentRow(para.toInt());
    }
    else
    {
        ui->listWidget_usbmode->setCurrentRow(1);
    }
    ui->listWidget_recordmode->setCurrentRow(0);

    if(para.toInt() >=0 && para.toInt()<2 )
    {
        ui->label_usbmode->setText(ui->listWidget_usbmode->currentItem()->text());
        if(ui->listWidget_usbmode->currentRow() == 0)
        {
            if(ui->checkBox_eth->isChecked())
            {
                ui->checkBox_eth->setChecked(false);
            }
            ui->checkBox_eth->setCheckable(false);
        }else
        {
            ui->checkBox_eth->setCheckable(true);
        }
    }


    para = hpxmlreader.readXml("sys.xml","TEMPPARA","tempunit");
    if(para != NULL)
    {
        tempunit = para.toInt();
        ui->ScrollBar_TempUnit->setValue(tempunit);
        wdxz_tempunit_value_changed(tempunit);
        ui->ScrollBar_AmbientTempManu->setSuffix(hptempunitconvert.getTempUnitString(tempunit));
        ui->ScrollBar_ReferTemp->setSuffix(hptempunitconvert.getTempUnitString(tempunit));
        ui->ScrollBar_ReflectTemp->setSuffix(hptempunitconvert.getTempUnitString(tempunit));
        ui->comboBox_baojingwendu->setSuffix(hptempunitconvert.getTempUnitString(tempunit));
    }
    para =hpxmlreader.readXml("sys.xml","OSD","color_sw");
    if(para != NULL)
    {
        osdsetting.color_ruler=para.toInt();
    }
    else
    {
        osdsetting.color_ruler=0;
    }
    para =hpxmlreader.readXml("sys.xml","OSD","maxtemp_sw");
    if(para != NULL)
    {
        osdsetting.max_temp_obj=para.toInt();
    }
    else
    {
        osdsetting.max_temp_obj=0;
    }

    para =hpxmlreader.readXml("sys.xml","OSD","obj_sw");
    if(para != NULL)
    {
        osdsetting.measure_obj=para.toInt();
    }
    else
    {
        osdsetting.measure_obj=0;
    }
    para =hpxmlreader.readXml("sys.xml","OSD","time_sw");
    if(para != NULL)
    {
        osdsetting.time=para.toInt();
    }
    else
    {
        osdsetting.time=0;
    }
    para =hpxmlreader.readXml("sys.xml","OSD","mintemp_sw");
    if(para != NULL)
    {
        osdsetting.min_temp_obj=para.toInt();
    }
    else
    {
        osdsetting.min_temp_obj=0;
    }
    para =hpxmlreader.readXml("sys.xml","OSD","avgtemp_sw");
    if(para != NULL)
    {
        osdsetting.avg_temp_obj=para.toInt();
    }
    else
    {
        osdsetting.avg_temp_obj=0;
    }
    para =hpxmlreader.readXml("sys.xml","OSD","gps_sw");
    if(para != NULL)
    {
        osdsetting.gps=para.toInt();
    }
    else
    {
        osdsetting.gps=0;
    }
    para =hpxmlreader.readXml("sys.xml","OSD","videomode_sw");
    if(para != NULL)
    {
        osdsetting.video_mode=para.toInt();
    }
    else
    {
        osdsetting.video_mode=0;
    }
    para =hpxmlreader.readXml("sys.xml","OSD","emissivity_sw");
    if(para != NULL)
    {
        osdsetting.emissivity=para.toInt();
    }
    else
    {
        osdsetting.emissivity=0;
    }
//用户IP、用户名、密码
    para =hpxmlreader.readXml("sys.xml","UPLOADPARA","ip");
    if(para != NULL)
    {
        hp_autoupload->SetSettingInit(para,1);//设置IP
    }
    para =hpxmlreader.readXml("sys.xml","UPLOADPARA","username");
    if(para != NULL)
    {
        hp_autoupload->SetSettingInit(para,2);//设置用户名
    }
    para =hpxmlreader.readXml("sys.xml","UPLOADPARA","password");
    if(para != NULL)
    {
        hp_autoupload->SetSettingInit(para,3);//设置密码
    }
//    2022.3.18  ->  //初始化fidpid
    para =hpxmlreader.readXml("sys.xml","OSD","fid_sw");
    if(para != NULL)
    {
        osdsetting.fid3100=para.toInt();
        if(osdsetting.fid3100!=0)
           ui->checkBox_fid->setChecked(true);
    }
    else
    {
        osdsetting.fid3100=0;
    }
    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.readXml("sys.xml","AUTORECTIFY","time");
        if(para != NULL)
        {
            int currAutoRectifyTime = para.toInt();
            if(currAutoRectifyTime < ui->cwfw_autorectify->minimum())
            {
                ui->cwfw_autorectify->setValue(ui->cwfw_autorectify->minimum());
                autorectify_time_back = 150;
                autorectify_time = autorectify_time_old = ui->cwfw_autorectify->minimum();
            }
            else
            {
                autorectify_time_back = currAutoRectifyTime;
                autorectify_time_old = currAutoRectifyTime;
                if(!ui->checkBox_nonCool->isChecked())
                {
                    ui->cwfw_autorectify->setValue(currAutoRectifyTime);
                    autorectify_time = autorectify_time_old = currAutoRectifyTime;
                }
                else
                {
                        ui->cwfw_autorectify->setValue(ui->cwfw_autorectify->minimum());
                        autorectify_time_back = 150;
                        autorectify_time = autorectify_time_old = ui->cwfw_autorectify->minimum();
                }
            }
            break;
        }
    }

    para =hpxmlreader.readXml("sys.xml","OSD","pid_sw");
    if(para != NULL)
    {
        osdsetting.pid3100=para.toInt();
        if(osdsetting.pid3100!=0)
            ui->checkBox_pid->setChecked(true);
    }
    else
    {
        osdsetting.pid3100=0;
    }
    osdsetting.fid3100=0;
    osdsetting.pid3100=0;
    QStringList wendangret = ui->label_wendang->text().split('~');
    if(wendangret[0] != NULL && wendangret[1] != NULL)
    {
        QString Min_ret1 = wendangret[0];
        qDebug() << "dangweiMinTemp -- 0 > " << Min_ret1;
        QString Max_ret2 = wendangret[1];
        Max_ret2.chop(1);
        qDebug() << "dangweiMaxTemp -- 2 > " << Max_ret2;
        //最大值最小值设置地方，用于防止报警温度超过挡位值
        dangweiMinTemp = Min_ret1.toInt();
        dangweiMaxTemp = Max_ret2.toInt();
    }

    if(fidpid)
    {
        if(dangweiMaxTemp == 80 && dangweiMinTemp == -20)
        {
            signal_noncool_unenable_plr(true);
            yqsz_nonCool_setchecked(true);
            ui->checkBox_nonCool->setChecked(true);
        }else
        {
            signal_noncool_unenable_plr(false);
            yqsz_nonCool_setchecked(false);
            ui->checkBox_nonCool->setChecked(false);
        }
    }
    if(ui->comboBox_baojingwendu->value() > dangweiMaxTemp)
    {
        AlarmTemp.AlarmTemp100 = hptempunitconvert.getCTempValue(tempunit,dangweiMaxTemp*100);
        ui->comboBox_baojingwendu->setValue(dangweiMaxTemp);
    }else if(ui->comboBox_baojingwendu->value() < dangweiMinTemp)
    {
        AlarmTemp.AlarmTemp100 = hptempunitconvert.getCTempValue(tempunit,dangweiMinTemp*100);
        ui->comboBox_baojingwendu->setValue(dangweiMinTemp);
    }

    qDebug("end para_init....");
}

HpSetting::~HpSetting()
{
    delete ui;
}

void HpSetting::changeEvent(QEvent *e)                                                                                          //lcy
{
    //38、就只对这个函数进行了修改，添加了l_recordmode和其有关项
    QWidget::changeEvent(e);
    int c_lang,c_baojingse,c_baojingshezhi,c_dangwei,c_jingtou,c_usbmode,c_lcdoff,c_poweroff;

    int l_lcdoff,l_poweroff,l_usbmode,l_baojingse,l_baojingshezhi,I_jingtou,l_dangwei,l_recordmode;
    int I_radTable_switch, I_radTable_id, I_radTable_value100;
    QString para;
    switch (e->type())
    {
    case QEvent::LanguageChange:

        language_changing = true;
        c_lang = ui->comboBox_language->currentIndex();
        c_baojingse = ui->comboBox_baojingse->currentIndex();
        c_baojingshezhi=ui->comboBox_baojingshezhi->currentIndex();
        c_dangwei = ui->comboBox_dangwei->currentIndex();
        c_jingtou = ui->comboBox_jingtou->currentIndex();
        c_usbmode = ui->comboBox_usbmode->currentIndex();
        c_lcdoff = ui->auto_lcdoff->currentIndex();
        c_poweroff = ui->auto_poweroff->currentIndex();

        l_lcdoff =ui->listWidget_lcdoff->currentRow();
        l_poweroff = ui->listWidget_poweroff->currentRow();
        l_usbmode = ui->listWidget_usbmode->currentRow();
        l_baojingse = ui->listWidget_baojingse->currentRow();
        l_baojingshezhi = ui->listWidget_baojingshezhi->currentRow();
        I_jingtou = ui->listWidget_jingtou->currentRow();
        l_dangwei = ui->listWidget_wendang->currentRow();

         I_radTable_id = ui->listWidget_Radiance->currentRow();

         l_recordmode = ui->listWidget_recordmode->currentRow();

        ui->retranslateUi(this);

        ui->comboBox_language->setCurrentIndex(c_lang);
        ui->comboBox_baojingse->setCurrentIndex(c_baojingse);
        ui->comboBox_baojingshezhi->setCurrentIndex(c_baojingshezhi);
        ui->comboBox_dangwei->setCurrentIndex(c_dangwei);
        ui->comboBox_jingtou->setCurrentIndex(c_jingtou);
        ui->comboBox_usbmode->setCurrentIndex(c_usbmode);
        ui->auto_lcdoff->setCurrentIndex(c_lcdoff);
        ui->auto_poweroff->setCurrentIndex(c_poweroff);



        para = hpxmlreader.readXml("config.xml","SOFTWAREVER","content");
        if(para != NULL)
            ui->label_banben_text->setText(para);

        para = hpxmlreader.readXml("config.xml","PRODUCEDTIME","content");
        if(para != NULL)
            ui->label_riqi_text->setText(para);

        para = hpxmlreader.readXml("config.xml","DEVICESN","content");
        if(para != NULL)
            ui->label_bianhao_text->setText(para);

        para = hpxmlreader.readXml("config.xml","DEVICEOEMNAME","content");
        if(para != NULL)
            ui->label_xinghao_text->setText(para);
        m_Transmission->hp_setEquipID(ui->label_xinghao_text->text(), ui->label_bianhao_text->text());

        //读取语言
        para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        qDebug("read language index:%d",para.toInt());

        //para.toInt()
        if(para !=NULL)
        {
            if(ui->listWidget_language->currentRow()<ui->listWidget_language->count() && ui->listWidget_language->currentRow()>=0 )
            ui->label_language->setText(ui->listWidget_language->currentItem()->text());
        }

        if( l_lcdoff >=0 && l_lcdoff <ui->listWidget_lcdoff->count())
        {
            ui->label_lcdoff->setText(ui->listWidget_lcdoff->currentItem()->text());
        }

        if( l_poweroff >=0 && l_poweroff <ui->listWidget_poweroff->count())
        {
            ui->label_poweroff->setText(ui->listWidget_poweroff->currentItem()->text());
        };
        if( l_usbmode >=0 && l_usbmode <ui->listWidget_usbmode->count())
        {
            ui->label_usbmode->setText(ui->listWidget_usbmode->currentItem()->text());
        };

        if(l_baojingshezhi >=0 && l_baojingshezhi <ui->listWidget_baojingshezhi->count())
        {
            ui->label_bangjingshehzi->setText(ui->listWidget_baojingshezhi->currentItem()->text());
        }
        if(l_recordmode >=0 && l_recordmode <ui->listWidget_recordmode->count())
        {
            ui->label_recordmode->setText(ui->listWidget_recordmode->currentItem()->text());
        }

        if(l_baojingse >=0 && l_baojingse <ui->listWidget_baojingse->count())
        {
            ui->label_baojingse->setText(ui->listWidget_baojingse->currentItem()->text());
        }

        if(I_jingtou >=0 && I_jingtou <ui->listWidget_jingtou->count())
        {
            ui->label_jingtou->setText(ui->listWidget_jingtou->currentItem()->text());
        }

        if(l_dangwei >=0 &&l_dangwei<ui->listWidget_wendang->count())
        {
            ui->label_wendang->setText(ui->listWidget_wendang->currentItem()->text());
        }

        if(I_radTable_id >=0 && I_radTable_id<ui->listWidget_Radiance->count())
        {
            ui->label_Radiance->setText(ui->listWidget_Radiance->currentItem()->text());
        }

        ui->ScrollBar_AmbientTempManu->setSuffix(hptempunitconvert.getTempUnitString(tempunit));

//       signal_language_changed_end();
        language_changing = false;
        break;
    default:
        break;
    }
//     signal_language_changed_end();
    signal_tempunit_value_changed(tempunit);
}

void HpSetting::slot_cpuMemu(bool checked)
{
    if(checked)
    {
        hpcpumem->show();
        hpcpumem->timer0->start(1000);
    }
    else
    {
        hpcpumem->timer0->stop();
        hpcpumem->close();
    }
}

void HpSetting::slot_hidemenu(bool checked)
{
    if(checked)
        hphidemenu.show();
    else
        hphidemenu.close();
}

void HpSetting::wdxz_ambienttempmenu_double_value_changed(double value)
{
    signal_update_lcdoff_time(false);
    qDebug("wdxz_ambienttempmenu_double_value_changed:unit:%d value:%f cvalue:%d",tempunit,value,hptempunitconvert.getCTempValue(tempunit,value*100));
    if(!unitconverting)
        TempUserPara.AmbientTempManu100 = hptempunitconvert.getCTempValue(tempunit,value*100);
}

void HpSetting::wdxz_distance_double_value_changed(double value)
{
    signal_update_lcdoff_time(false);
    if(!unitconverting)
    {
        TempUserPara.Distance100 = value*100;
        signal_update_distance_to_display(TempUserPara.Distance100);
    }
}

void HpSetting::wdxz_refertemp_double_value_changed(double value)
{
    signal_update_lcdoff_time(false);
    qDebug("wdxz_refertemp_double_value_changed:unit:%d value:%f cvalue:%d",tempunit,value,hptempunitconvert.getCTempValue(tempunit,value*100));
    if(!unitconverting)
        TempReference.ReferTemp100 = hptempunitconvert.getCTempValue(tempunit,value*100);
}

void HpSetting::wdxz_reflecttemp_double_value_changed(double value)
{
    signal_update_lcdoff_time(false);
    qDebug("wdxz_reflecttemp_double_value_changed:unit:%d value:%f cvalue:%d",tempunit,value,hptempunitconvert.getCTempValue(tempunit,value*100));
    if(!unitconverting)
    {
        TempUserPara.ReflectTemp100 = hptempunitconvert.getCTempValue(tempunit,value*100);
        signal_update_reflect_temp_to_display(TempUserPara.ReflectTemp100);
    }
}

void HpSetting::wdxz_humidity_value_changed(int value)
{
    signal_update_lcdoff_time(false);
    TempUserPara.Humidity100 = value;
}

//fushelv
void HpSetting::wdxz_radiance_value_changed(int value)
{
    signal_update_lcdoff_time(false);
    TempUserPara.Radiance100 = value;
    signal_update_radiance_to_display(value);
}

void HpSetting::wdxz_refertemp_enable(bool checked)
{
    signal_update_lcdoff_time(false);
    if(checked){
        TempReference.enable = 1;
        signal_set_part_ReferTemp(false);
    }else{
        TempReference.enable = 0;
    }
    ui->ScrollBar_ReferTemp->setEnabled(checked);
}

void HpSetting::wdxz_reflectTemp_enable(bool checked)
{
    ui->ScrollBar_ReflectTemp->setEnabled(!checked);
    qDebug() << __func__ << checked << __LINE__;
    if(checked)
    {
        ui->frame_ReflectTemp->show();
        ui->frame_ReflectTemp->raise();
        m_reflectType = 0;
        signal_set_auto_reflect(true);
    }else
    {
        m_reflectType = -1;
        ui->frame_ReflectTemp->close();
        ui->listWidget_ReflectTemp->close();
        signal_set_auto_reflect(false);
    }
}

void HpSetting::wdxz_tempunit_value_changed(int value)                  //改变温度单位
{
    signal_update_lcdoff_time(false);
    signal_tempunit_value_changed(value);
    temp_tab_change = true;
    tempunit = value;

    disconnect(ui->comboBox_dangwei,SIGNAL(currentIndexChanged(int)),this,SLOT(cwfw_dangwei_current_index_changed(int)));

    wendang_i = ui->listWidget_wendang->currentRow();
    if(wendang_i <0){
        wendang_i = 0;
    }

    ui->comboBox_dangwei->clear();
    ui->listWidget_wendang->clear();
//    QListIterator<DANGWEI> i_dangwei(dangwei_list);
    //当前镜头号
    QString para;
    para = hpxmlreader.readXml("config.xml","LENSSET","lensid");
    if(para != NULL)
        TempRange.LensId = para.toInt();
    else
        TempRange.LensId = 0;

    //镜头变化时同时变化图像旋转
    QString pararotate;
    pararotate = hpxmlreader.readXml("config.xml","IMAGEROTATE","diameter" + QString::number(TempRange.LensId));
    qDebug() << " >>> config.xml IMAGEROTATE diameter" + QString::number(TempRange.LensId) + " == > " << pararotate;
    if(pararotate != NULL)
    {
        TempRange.ImageRotate = pararotate.toInt();
        hphide_biaoding.setCheckboxrotate(pararotate.toInt());
    }
    int readnumEr = 0;
    while(hpxmlreader.errorRead)
    {
        readnumEr++;
        if(readnumEr > 1)
        {
            break;
        }
        pararotate = hpxmlreader.readXml("config.xml","IMAGEROTATE","diameter" + QString::number(TempRange.LensId));
        qDebug() << " >>> config.xml IMAGEROTATE diameter" + QString::number(TempRange.LensId) + " == > " << pararotate;
        if(pararotate != NULL)
        {
            TempRange.ImageRotate = pararotate.toInt();
            hphide_biaoding.setCheckboxrotate(pararotate.toInt());
        }
    }
    //镜头变化时同时变化图像旋转

    int now_lensld = TempRange.LensId;                                                  //获取当前镜头号
     DANGWEI l_dangwei;                                                  // 挡位结构体


    //一共四个镜头，三个挡位
    for( int i =1; i<4; i++)                        //加载挡位
    {
        QString MinTemp,MaxTemp;
        DANGWEI l_dangwei;
        MinTemp = hpxmlreader.readXml("config.xml","LENS"+QString::number(now_lensld*3+ i),"MinTemp");
        MaxTemp = hpxmlreader.readXml("config.xml","LENS"+QString::number(now_lensld*3+ i),"MaxTemp");

        l_dangwei.minTemp = MinTemp.toInt()*100;
        l_dangwei.maxTemp = MaxTemp.toInt()*100;

         QString tmp = QString::number(hptempunitconvert.getTempValue(tempunit,l_dangwei.minTemp)/100)+"~"+QString::number(hptempunitconvert.getTempValue(tempunit,l_dangwei.maxTemp)/100)+hptempunitconvert.getTempUnitString(tempunit);
         if( l_dangwei.minTemp/100 != 0 || l_dangwei.maxTemp/100 !=0)
         {
                   ui->comboBox_dangwei->addItem(tmp);
                   if(temp_tab_change == true)
                   {
                       QListWidgetItem *listWidgetItem = new QListWidgetItem;
                       listWidgetItem->setText(tmp);
                       ui->listWidget_wendang->addItem(listWidgetItem);
                   }
         }
    }

    l_dangwei = dangwei_list.at(ui->comboBox_dangwei->currentIndex());

    connect(ui->comboBox_dangwei,SIGNAL(currentIndexChanged(int)),this,SLOT(cwfw_dangwei_current_index_changed(int)));

    unitconverting = true;
    int minctemp100 = -20000;
    int maxctemp100 = 200000;

    //can kao wen du
    ui->ScrollBar_ReferTemp->setMinimum(hptempunitconvert.getTempValue(tempunit,minctemp100)/100.0);
    ui->ScrollBar_ReferTemp->setMaximum(hptempunitconvert.getTempValue(tempunit,maxctemp100)/100.0);
    ui->ScrollBar_ReferTemp->setSuffix(hptempunitconvert.getTempUnitString(tempunit));
    ui->ScrollBar_ReferTemp->setValue(hptempunitconvert.getTempValue(tempunit,TempReference.ReferTemp100)/100.0);

    //fan she wen du

    ui->ScrollBar_ReflectTemp->setMinimum(hptempunitconvert.getTempValue(tempunit,minctemp100)/100.0);
    ui->ScrollBar_ReflectTemp->setMaximum(hptempunitconvert.getTempValue(tempunit,maxctemp100)/100.0);
    ui->ScrollBar_ReflectTemp->setSuffix(hptempunitconvert.getTempUnitString(tempunit));
    ui->ScrollBar_ReflectTemp->setValue(hptempunitconvert.getTempValue(tempunit,TempUserPara.ReflectTemp100)/100.0);

    //huan jing wendu
    ui->ScrollBar_AmbientTempManu->setMinimum(hptempunitconvert.getTempValue(tempunit,minctemp100)/100.0);
    ui->ScrollBar_AmbientTempManu->setMaximum(hptempunitconvert.getTempValue(tempunit,maxctemp100)/100.0);
    ui->ScrollBar_AmbientTempManu->setSuffix(hptempunitconvert.getTempUnitString(tempunit));
    ui->ScrollBar_AmbientTempManu->setValue(hptempunitconvert.getTempValue(tempunit,TempUserPara.AmbientTempManu100)/100.0);

    //buchangwendu
    ui->comboBox_buchangwendu->setSuffix(hptempunitconvert.getTempUnitString(tempunit));
    ui->comboBox_buchangwendu->setValue(hptempunitconvert.getTempValue(tempunit,compensateValue)/100.0);

    //bao jing wen du
    //ui->comboBox_baojingwendu->setMinimum(hptempunitconvert.getTempValue(tempunit,l_dangwei.minTemp)/100.0);
    //ui->comboBox_baojingwendu->setMaximum(hptempunitconvert.getTempValue(tempunit,l_dangwei.maxTemp)/100.0);
    ui->comboBox_baojingwendu->setSuffix(hptempunitconvert.getTempUnitString(tempunit));
    ui->comboBox_baojingwendu->setValue(hptempunitconvert.getTempValue(tempunit,AlarmTemp.AlarmTemp100)/100.0);

    unitconverting = false;

    ui->listWidget_wendang->setCurrentRow(wendang_i);
//    ui->label_wendang->setText(ui->listWidget_wendang->currentItem()->text());
    temp_tab_change =false;


}

void HpSetting::wdxz_transmission_value_changed(int value)
{
    signal_update_lcdoff_time(false);
    TempUserPara.transmission100 = value;
}

void HpSetting::cwfw_autorectify_value_change(int value)
{
    if(!ui->checkBox_nonCool->isChecked() && (value >= 9))
    {
        autorectify_time_back = value;
    }
    signal_update_lcdoff_time(false);
    autorectify_time = value;
}

void HpSetting::cwfw_dangwei_current_index_changed(int value)               //挡位发生改变
{
    signal_update_lcdoff_time(false);
    ui_dangwei_changeid = value;     //记录当前改变的挡位

    if(language_changing)
        return;
    int ui_count;                   //获取ui界面总数量
    ui_count = ui->comboBox_dangwei->count();

    if(2 == value ){                                                //发生改变的 Ui 挡位是 2.  则挡位都在 没有 0-0
        TempRange.TempRangeID=2;
    }else if(1 == value){                                          //发生改变的UI挡位是  1，则至少有两个挡位。 考虑 前两个挡位是否有一个是 0-0
                                                                                //两种情况。 一种是 0和1档中有一个空挡。 或者没有空挡
        if(1 == dangwei_exit[0]  ||  1 == dangwei_exit[1])                              //值为一表示空挡
        {
            TempRange.TempRangeID=2;
        }else{
            TempRange.TempRangeID=1;
        }
    }else if(0 == value){                                           //发生改变的UI挡位是 0。 挡位有 一个，两个，或者3个.方法：挡位0若存在则为0.依次
                                                                                //往后判断从前
        if(0 == dangwei_exit[0]){
            TempRange.TempRangeID=0;
        }else if( 0== dangwei_exit[1]){
            TempRange.TempRangeID=1;
        }else {
            TempRange.TempRangeID=2;
        }
    }else{

    }

    if(jingtou_changing == false)                                                                   //镜头发生  未改变， 挡位改变的时候使能
    {

  //      signal_pc_measure_set_temprange(TempRange);       //5.17
    }

    //TempRange.TempRangeID=value ：挡位界面当前界面的序号。其实是xml文件真实的序列号？
    //修改后：
    DANGWEI l_dangwei;
    l_dangwei = dangwei_list.at(TempRange.TempRangeID);

    update();
}

void HpSetting::cwfw_jingtou_current_index_changed(int value)           //界面镜头切换，槽
{
    qDebug() << __func__ << __LINE__;
    signal_update_lcdoff_time(false);
    ui_jingtou_changeid = value;   //记录当前切换的界面
    if(language_changing)//若是语言切换则忽略
        return;
//2018.3.6
    jingtou_changing = true;


    int ui_count;
    ui_count = ui->comboBox_dangwei->count();                               //获取ui界面总数量

    ui->comboBox_dangwei->clear();
 //   int ui_jingtou_value;
 //   ui_jingtou_value = value;
    DANGWEI l_dangwei;

    if(!dangwei_list.isEmpty())
        dangwei_list.clear();

    //显示镜头对应的挡位
    QIcon icon (":/res/res/combobox_icon.png");
    for(int j = 1; j <= 3; j++)
    {
        QString MinTemp,MaxTemp;
        MinTemp = hpxmlreader.readXml("config.xml","LENS"+QString::number((jingtou_enable[value])*3+ j),"MinTemp");
        MaxTemp = hpxmlreader.readXml("config.xml","LENS"+QString::number((jingtou_enable[value])*3+ j),"MaxTemp");
        if(MinTemp != NULL && MaxTemp != NULL)
        {
            l_dangwei.minTemp = MinTemp.toInt()*100;
            l_dangwei.maxTemp = MaxTemp.toInt()*100;
            dangwei_list.append(l_dangwei);

             QString tmp = QString::number(hptempunitconvert.getTempValue(tempunit,l_dangwei.minTemp)/100)+"~"+QString::number(hptempunitconvert.getTempValue(tempunit,l_dangwei.maxTemp)/100)+hptempunitconvert.getTempUnitString(tempunit);
            if( 0!= l_dangwei.minTemp || 0!=l_dangwei.maxTemp )
            {
                qDebug()  << __func__ << "ui->comboBox_dangwei->addItem(icon,tmp)" << jingtou_dangwei_change;
                 ui->comboBox_dangwei->addItem(icon,tmp);
                 if(jingtou_dangwei_change == true)
                 {
                     QListWidgetItem *listWidgetItem = new QListWidgetItem;
                     listWidgetItem->setText(tmp);
                     qDebug()  << __func__ << "ui->listWidget_wendang->addItem(listWidgetItem)";
                     ui->listWidget_wendang->addItem(listWidgetItem);
                 }

                dangwei_exit[j-1]=0;
            }else{
                dangwei_exit[j-1]=1;
            }
        }
    }


    TempRange.LensId = jingtou_enable[value];                           //当前镜头号
    TempRange.TempRangeID = 0;              //当前挡位号.设置为0表示   切换镜头后从第一个挡位开始

    if(0 ==dangwei_exit[0]){                                           //挡位1存在
        TempRange.TempRangeID = 0;
    }else{
        if(0 ==dangwei_exit[1]){
            TempRange.TempRangeID = 1;
        }else{
            if(0 == dangwei_exit[2]){
                TempRange.TempRangeID = 2;
            }else{
                TempRange.TempRangeID = 0;
            }
        }
    }

    if( 1==dangwei_exit[0] && 1==dangwei_exit[1] && 1==dangwei_exit[2])
    {
          ui->comboBox_dangwei->addItem("");
    }else
    {
    }

    ui->comboBox_dangwei->setCurrentIndex(wendang_i);
    ui->listWidget_wendang->setCurrentRow(wendang_i);

    ui->label_wendang->setText(ui->listWidget_wendang->currentItem()->text());
    jingtou_changing = false;
    jingtou_dangwei_change=false;

    //镜头变化时同时变化图像旋转
    QString pararotate;
    pararotate = hpxmlreader.readXml("config.xml","IMAGEROTATE","diameter" + QString::number(TempRange.LensId));
    qDebug() << " >>> config.xml IMAGEROTATE diameter" + QString::number(TempRange.LensId) + " == > " << pararotate;
    if(pararotate != NULL)
    {
        TempRange.ImageRotate = pararotate.toInt();
        hphide_biaoding.setCheckboxrotate(pararotate.toInt());
    }
    int readnumEr = 0;
    while(hpxmlreader.errorRead)
    {
        delaymsec(100);
        readnumEr++;
        pararotate = hpxmlreader.readXml("config.xml","IMAGEROTATE","diameter" + QString::number(TempRange.LensId));
        qDebug() << " >>> config.xml IMAGEROTATE diameter" + QString::number(TempRange.LensId) + " == > " << pararotate;
        if(pararotate != NULL)
        {
            TempRange.ImageRotate = pararotate.toInt();
            hphide_biaoding.setCheckboxrotate(pararotate.toInt());
        }
        if(readnumEr > 10)
        {
            break;
        }
    }
    //镜头变化时同时变化图像旋转

    update();

}

void HpSetting::cwfw_baojingshezhi_current_index_changed(int value)                         //报警温度相关
{
    signal_update_lcdoff_time(false);
    if(language_changing)
        return;
    AlarmTemp.AlarmSwitch = value;

    signal_pc_image_set_alarm(AlarmTemp);
    update();
}

void HpSetting::cwfw_baojingwendu_double_value_changed(double value)                    //发送报警温度，设置报警温度
{
    signal_update_lcdoff_time(false);
    qDebug("cwfw_baojingwendu_value_changed:unit:%d value:%f cvalue:%d",tempunit,value,hptempunitconvert.getCTempValue(tempunit,value*100));
    if(!unitconverting)
    {
        qDebug() << "dangweiMaxTemp == " << dangweiMaxTemp;
        qDebug() << "dangweiMinTemp == " << dangweiMinTemp;
        qDebug() << "value == " << value;
        if(value > dangweiMaxTemp)
        {
            AlarmTemp.AlarmTemp100 = hptempunitconvert.getCTempValue(tempunit,dangweiMaxTemp*100);
            ui->comboBox_baojingwendu->setValue(dangweiMaxTemp);
        }else if(value < dangweiMinTemp)
        {
            AlarmTemp.AlarmTemp100 = hptempunitconvert.getCTempValue(tempunit,dangweiMinTemp*100);
            ui->comboBox_baojingwendu->setValue(dangweiMinTemp);
        }else
        {
            AlarmTemp.AlarmTemp100 = hptempunitconvert.getCTempValue(tempunit,value*100);
        }

        signal_pc_image_set_alarm(AlarmTemp);
        update();
    }
}

void HpSetting::cwfw_baojingjuli_double_value_changed(double value)
{
    signal_update_lcdoff_time(false);
    hpxmlreader.writeXml("sys.xml", "ALARM", "range100", QString::number(value * 100));
    qDebug() << __func__ << __LINE__ << value;
}

void HpSetting::cwfw_baojingse_current_index_changed(int value)                                 //报警色
{
    signal_update_lcdoff_time(false);
    if(language_changing)
        return;
    AlarmTemp.AlarmColorId = value;

    signal_pc_image_set_alarm(AlarmTemp);
    update();
}

void HpSetting::ResetPreviewParameters()
{
    if(MainInterUserPara.nradTable_switch == 0)
    {
        ui->checkBox_Radiance->setChecked(false);                   //辐射率表开关 关为0，开为1
        isManualCall = true;
        on_checkBox_Radiance_clicked(false);
        isManualCall = false;
    }else{
        ui->checkBox_Radiance->setChecked(true);
        isManualCall = true;
        on_checkBox_Radiance_clicked(true);
        isManualCall = false;
    }
    ui->listWidget_Radiance->setCurrentRow(MainInterUserPara.nradTable_id);                                       //辐射率表下拉框
    ui->label_Radiance->setText(ui->listWidget_Radiance->currentItem()->text());             //辐射率表文本
    ui->ScrollBar_Radiance->setValue(MainInterUserPara.nradTable100);                                                 //设置辐射率
    qDebug()  << "msg.Distance100/100.0" << MainInterUserPara.Distance100 << MainInterUserPara.Distance100/100.0;
    ui->ScrollBar_Distance->setValue(MainInterUserPara.Distance100/100.0);                                          //设置距离
//    qDebug() << "==========================lzj --- > 3";
    ui->ScrollBar_Humidity->setValue(MainInterUserPara.Humidity100);                                                 //相对湿度

    ui->ScrollBar_transmission->setValue(MainInterUserPara.Transmission100);                                         //窗口透过率

    if(MainInterUserPara.RefeTempType == 0)                   //0关闭1 打开 2点测温3:区域4:线
    {
        TempReference.enable = 0;
        TempReference_old.enable = 0;
        ui->checkBox_ReferTemp_enable->setChecked(false);                   //参考温度开关。 关为0，开为1
        isManualCall = true;
        on_checkBox_ReferTemp_enable_clicked(false);
        isManualCall = false;
    }else if(MainInterUserPara.RefeTempType == 1){
        TempReference.enable = 1;
        TempReference_old.enable =1;
        ui->checkBox_ReferTemp_enable->setChecked(true);
        isManualCall = true;
        on_checkBox_ReferTemp_enable_clicked(true);
        isManualCall = false;
    }

    ui->ScrollBar_TempUnit->setValue(MainInterUserPara.TempUnit);
    ui->ScrollBar_ReferTemp->setValue(MainInterUserPara.RefeTemp100/100.0);
    ui->ScrollBar_ReflectTemp->setValue(MainInterUserPara.ReflectTemp100/100.0);
    ui->ScrollBar_AmbientTempManu->setValue(MainInterUserPara.AmbientTempManu100/100.0);

    ui->checkBox_Catch->setChecked(isTempCaptureSwitch);
}

void HpSetting::StoragePreviewParameters()
{
    if(ui->checkBox_Radiance->isChecked())
    {
        MainInterUserPara.nradTable_switch = 1;
    }
    else
    {
        MainInterUserPara.nradTable_switch = 0;
    }

    MainInterUserPara.nradTable_id = ui->listWidget_Radiance->currentRow();
    MainInterUserPara.nradTable100 = ui->ScrollBar_Radiance->value();

    MainInterUserPara.Distance100 = ui->ScrollBar_Distance->value()*100;
    MainInterUserPara.Humidity100 = ui->ScrollBar_Humidity->value();
    MainInterUserPara.Transmission100 =  ui->ScrollBar_transmission->value();

    if( ui->checkBox_ReferTemp_enable->isChecked() )
    {
        MainInterUserPara.RefeTempType = 1;
    }
    else
    {
        MainInterUserPara.RefeTempType = 0;
    }

    MainInterUserPara.RefeTemp100 = ui->ScrollBar_ReferTemp->value()*100;
    MainInterUserPara.ReflectTemp100 = ui->ScrollBar_ReflectTemp->value()*100;
    MainInterUserPara.AmbientTempManu100 = ui->ScrollBar_AmbientTempManu->value()*100;
    MainInterUserPara.TempUnit = ui->ScrollBar_TempUnit->value();
    //qDebug()<<"HpSetting::StoragePreviewParameters-----------------------*******************TempReference.ReferTemp100 is "<<TempReference.ReferTemp100;
    isTempCaptureSwitch = ui->checkBox_Catch->isChecked();
}

void HpSetting::slot_JPGTemCaptrue_Switch(int isOpen)
{
    qDebug()<<"HpSetting::slot_JPGTemCaptrue_Switch(int isOpen)-----------------------"<<isOpen;
    ui->checkBox_Catch->setChecked(isOpen);
}

void HpSetting::on_checkBox_Catch_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
    if(checked)
    {
        signal_pc_measure_tempcapture(1);
    }
    else
    {
        signal_pc_measure_tempcapture(0);
    }
}

void HpSetting::yqsz_zidongcunchu_value_changed(int value)
{
    signal_update_lcdoff_time(false);
    screensave_time = value;
    SignalAutoSave(screensave_time);

    if(ui->spinBox_autosave->value() <= ui->spinBox_autosave->minimum())
    {
        RelieveLimitAutoSave_SR_AutoUpload();
        RelieveLimitAutoUpload();
    }
    else if(ui->spinBox_autosave->value() > ui->spinBox_autosave->minimum())
    {
        LimitAutoSave_SR_AutoUpload();
        LimitAutoUpload();
    }
}

void HpSetting::yqsz_autoUpdate_setchecked(bool checked)
{
    qDebug() << "HpSetting::yqsz_autoUpdate_setchecked" << checked << ui->checkBox_autoUpload->isEnabled();
    signal_update_lcdoff_time(false);
    if(hp_autoupload->mymode == enum_AUP_ftp)
    {
        slot_setCameracapChecked(checked);
    }
    qDebug() << "HpSetting::yqsz_autoUpdate_setchecked" << checked << enum_AUP_ftp;
    if(checked)
    {
        hp_autoupload->show();
        ui->autoUpload_edit->show();
        qDebug() << "onceUpload -- download == > " << onceUpload << " ; " << download;
        if(onceUpload)
        {
            ui->btautoUpload_once->show();
        }
        if(download){
            ui->btdownload->show();
        }
        autoUpdateIsChecked = true;
        LimitAutoSave_SR_AutoUpload();
    }else{
        ui->autoUpload_edit->close();
        ui->btdownload->close();
        ui->btautoUpload_once->close();
        autoUpdateIsChecked = false;
        hp_autoupload->setCloseClient();
        RelieveLimitAutoSave_SR_AutoUpload();
    }

}
void HpSetting::slot_setCameracapChecked(bool checked)
{
    signal_SetAutoUpdateIsChecked(checked);//发送给hp_camera_cap
}
void HpSetting::slot_srvupload_failed()
{
    hp_autoupload->setCloseClient();
}
void HpSetting::checkBox_hdmi_Clicked(bool checked)
{
    MainWidget *p = (MainWidget *)parentP;
    if(checked)
    {
        p->hppreview->gstPlayer.display_HDMI = true;
        setenv("QT_FB2_ENABLE","true",1);
        signal_set_HDMI(1);
        update();//打开HDMI时调用界面刷新
    }else{
        p->hppreview->gstPlayer.display_HDMI = false;
        setenv("QT_FB2_ENABLE","false",1);
        signal_set_HDMI(0);
    }
}

void HpSetting::on_calbration_edit_clicked()
{
      hpcalbration.show();
}


void HpSetting::yqsz_compass_setchecked(bool checked)
{
    if(checked)
    {
        signal_timer_get_positiion_switch(1);
        ui->calbration_edit->show();
    }
    else
    {
        signal_timer_get_positiion_switch(0);
        ui->calbration_edit->close();
    }
}

void HpSetting::yqsz_contrustFocus_setchecked(bool checked)
{
    if(checked)
    {
        signal_pc_key_focus_select(1);
        signal_pc_key_focus_stop_aut(true);
    }
    else
    {
        signal_pc_key_focus_select(0);
        signal_pc_key_focus_stop_aut(false);
    }
}

void HpSetting::yqsz_4G_setchecked(bool checked)
{
    if(checked)
    {
        signal_show_4G_pixel(1);
        m_timer_4G.start(240000);
        if(ui->checkBox_eth->isChecked())
        {
            ui->checkBox_eth->setChecked(false);
            signal_pc_sys_set_wifi_eth_close(0);
            eth_num = -1;
            signal_set_ETH_switch(0);
        }
        if(ui->checkBox_wifi->isChecked())
        {
            ui->checkBox_wifi->setChecked(false);
            signal_pc_sys_set_wifi_eth_close(1);
            ui->wifi_edit->close();
            hp_wifi_Search->slot_SetDisConnect();
//            wifi_num = -10;
            signal_pc_sys_set_wifi_switch(0);
            signal_pc_sys_set_wifi_power(0);
        }
        state4G = IS_ON_CONNECT;
//        hpdialog->move((this->width() - hpdialog->width()) / 2,(this->height() - hpdialog->height()) / 2 - 5);
        hpdialog->setText("4G " + hpblesearchold.fIsInConnnect);
        hpdialog->show();
        canbercv = false;//连接超时标志
        signal_set_4G_power(1);
        signal_set_4G_state(1);//设置4G状态，为打开
        state_4G->start();//开始获取4G状态
        RelieveLimitAutoUpload();
    }
    else
    {
        signal_show_4G_pixel(0);
        hpdialog->close();
        hp_Common_dialog_cancel->Set_label_text("4G " + hpblesearchold.fConnnectfailed);
        state4G = IS_ON_NONE;
        m_timer_4G.stop();
        state_4G->stop();
        hp_autoupload->set4Gstatu(false);
        signal_set_4G_icon(false);
        if(canbercv)
        {
            signal_set_4G_state(0);
            signal_set_4G_power(0);
        }

        LimitAutoUpload();
    }
}

void HpSetting::yqsz_avgTemp_setchecked(bool checked)
{
    qDebug() << " HpSetting::yqsz_GPS_setchecked" << checked;
    signal_set_show_avgTemp(checked);
}

void HpSetting::yqsz_nonCool_setchecked(bool checked)
{
    if(checked)
    {
        if(ui->cwfw_autorectify->value() >= 9)
        {
            autorectify_time_back = ui->cwfw_autorectify->value();
        }
        ui->cwfw_autorectify->setValue(0);
        ui->cwfw_autorectify->setEnabled(false);
        signal_core_fpgamunu_noncool_correct(1);
    }
    else
    {
        ui->cwfw_autorectify->setValue(autorectify_time_back);
        ui->cwfw_autorectify->setEnabled(true);
        signal_core_fpgamunu_noncool_correct(0);
    }
}

void HpSetting::yqsz_GPS_setchecked(bool checked)
{
    qDebug() << " HpSetting::yqsz_GPS_setchecked" << checked;
    isGpsOpen = false;
    if(checked)
    {
        signal_show_gps_pixel(1);
        osdsetting.gps = 1;
        signal_pc_osd_set_osdstat(osdsetting);
        signal_pc_image_set_gps(1);
    }
    else
    {
        signal_show_gps_pixel(0);
        osdsetting.gps = 0;
        signal_pc_osd_set_osdstat(osdsetting);
        signal_pc_image_set_gps(0);
    }
}

void HpSetting::slot_pc_image_set_gps(unsigned char return_value)
{
     qDebug("slot_pc_image_set_gps return_value:0x%02x",return_value);
     if(ui->checkBox_GPS->isChecked() && RE_OK != return_value)
     {
         QTimer::singleShot(1000, this, SLOT(set_gps()));
     }
     else
     {
         qDebug("HpSetting::slot_pc_image_set_gps %d",ui->checkBox_GPS->isChecked());
         isGpsOpen = true;
     }
}

void HpSetting::set_gps()
{
    if(!isGpsOpen)
    {
        signal_pc_image_set_gps(1);
    }
}

void HpSetting::slot_set_dialog_close(bool isClose)
{
    qDebug() << " HpSetting::slot_set_dialog_close" << isClose;
    hpdialog->close();
}

void HpSetting::yqsz_mulhom_setchecked(bool checked)
{
    int ret = 0;
    double val = hp_Mulhom_edit->max_temp * 100;
    ret = (int)val;
    if(checked)
    {
        ui->mulhom_edit->show();
        ret = ret | 0x80000000;//最高位赋值1
        signal_pc_measure_mulhomogeneity(ret);
    }else{
        ui->mulhom_edit->close();
        signal_pc_measure_mulhomogeneity(ret);
    }
}
void HpSetting::hp_slot_mulhom_edit_value_changed(int val)
{
    if(ui->checkBox_mulhom->isChecked())
    {
        int ret = 0;
        double val = hp_Mulhom_edit->max_temp * 100;
        ret = (int)val;
        ret = ret | 0x80000000;//最高位赋值1
        signal_pc_measure_mulhomogeneity(ret);
    }
}
void HpSetting::yqsz_mulhom_edit_checked()
{
    hp_Mulhom_edit->show();
}
void HpSetting::slot_pc_measure_mulhomogeneity(unsigned char return_value)
{
    qDebug("slot_pc_measure_mulhomogeneity return_value:0x%02x",return_value);
}
void HpSetting::yqsz_autoUpdate_Edit_setchecked()
{
    signal_update_lcdoff_time(false);
    hp_autoupload->show();
}
void HpSetting::yqsz_btautoUpdate_once_clicked()
{
    MainWidget *p = (MainWidget *)parentP;
    if(p->hpcameracap->mymode == enum_AUP_ftp)
    {
        hp_autoupload_dialog->setFrame(false);
        hp_autoupload_dialog->show();
    }else if(p->hpcameracap->mymode == enum_AUP_SERVER || p->hpcameracap->mymode == enum_AUP_SERVER_PLUS)
    {
        hp_Common_dialog_select->hp_setLabelText(hp_downLoad->fselectupload);
        hp_Common_dialog_select->hp_setBt1Text(hp_downLoad->ftask);
        hp_Common_dialog_select->hp_setBt2Text(hp_downLoad->fnormal);
        hp_Common_dialog_select->hp_setBt3Text(hp_autoupload->fcancel);
        hp_Common_dialog_select->show();
    }
}
void HpSetting::slot_StartAutoUpload_once(bool isTask)
{
    hp_autoupload_dialog->setFrame(true);
    signal_StartAutoUpload_once(isTask);
}
void HpSetting::slot_closeAutoUpload_once()
{
    signal_autoupdate_return();
}
void HpSetting::slot_selectAutoUpload_once(int select)
{
    hp_Common_dialog_select->close();
    if(select == 1)
    {
        hp_autoupload_dialog->setFrame(true);
        hp_autoupload_dialog->show();
        signal_StartAutoUpload_once(true);
    }else if(select == 2)
    {
        hp_autoupload_dialog->setFrame(true);
        hp_autoupload_dialog->show();
        signal_StartAutoUpload_once(false);
    }else if(select == 3)
    {
    }
}
void HpSetting::slot_client_isOn(bool ischecked)
{
    if(ischecked)
    {
        if(onceUpload)
        {
            ui->btautoUpload_once->show();
        }
        if(download)
        {
            ui->btdownload->show();
        }
    }else{
        ui->btautoUpload_once->close();
        ui->btdownload->close();
    }
    slot_setCameracapChecked(ischecked);
}

void HpSetting::slot_Set_Unchecked()
{
    ui->autoUpload_edit->close();
    ui->btdownload->close();
    ui->btautoUpload_once->close();
    ui->checkBox_autoUpload->setChecked(false);
    signal_SetAutoUpdateIsChecked(false);//发送给hp_camera_cap
    autoUpdateIsChecked = false;
}

void HpSetting::slot_pc_sys_set_autorectify(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_autorectify return_value:0x%02x",return_value);
}

void HpSetting::yqsz_btdownload_clicked()
{
    hp_downLoad->show();
    hp_downLoad->Start_download();
}

void HpSetting::slot_scroll_page_changed(int page)
{
    ui->label_scroll->hp_updateScroll(page);
}

void HpSetting::slot_pc_cfg_set_userpara(unsigned char return_value)
{
    qDebug("slot_pc_cfg_set_userpara return_value:0x%02x",return_value);
}

void HpSetting::slot_pc_measure_set_reference(unsigned char return_value)
{
    qDebug("slot_pc_measure_set_reference return_value:0x%02x",return_value);
}

void HpSetting::slot_pc_measure_set_tempunit(unsigned char return_value)
{
    qDebug("slot_pc_measure_set_tempunit return_value:0x%02x",return_value);
}
void HpSetting::slot_tempSetTm_out()
{
//    tempSetTm.stop();//只有接收到返回后才发送
    signal_pc_measure_temprange_query(TempRange);
//    swiftingCounter = 5;
//    ui->listWidget_jingtou->setCurrentRow(ui_jingtou_id);
//    ui->listWidget_wendang->setCurrentRow(ui_dangwei_id);
//    ui_dangwei_changeid = ui_dangwei_id;
//    ui_jingtou_changeid = ui_jingtou_id;

//    hpdialog->setText(hpblesearchold.fSwitchingFailure);
//    hpdialog->setDelayClose(2000);
//    tempWengdangchange = false;
}
void HpSetting::slot_pc_measure_set_temprange(unsigned char return_value)   //设置xml文件成功后
{
    qDebug() << __func__ << __LINE__;
    if(return_value == RE_OK)
    {
        signal_pc_measure_temprange_query(TempRange);
//        tempSetTm.stop();
    }
    else
    {
        swiftingCounter++;
        if(swiftingCounter > 4)
        {
            ui->listWidget_jingtou->setCurrentRow(ui_jingtou_id);
            ui->listWidget_wendang->setCurrentRow(ui_dangwei_id);
            ui_dangwei_changeid = ui_dangwei_id;
            ui_jingtou_changeid = ui_jingtou_id;

            hpdialog->setText(hpblesearchold.fSwitchingFailure);
            hpdialog->setDelayClose(2000);
            tempWengdangchange = false;
        }
        else
        {
            signal_pc_measure_set_temprange(TempRange);
        }
        return;
    }
    qDebug("slot_pc_measure_set_temprange return_value:0x%02x",return_value);
    range_lens_copy();      //保存新的数据待用

    tempWengdangchange = false;
}

void HpSetting::slot_pc_measure_temprange_query(unsigned char return_value)
{
    if(return_value == RE_OK)
    {
        tempWengdangchange = false;
        hpdialog->close();
        signal_set_para_2123();     //信号设置隐藏菜单中para_21和para_23的值
    }
}

void HpSetting::slot_pc_image_set_alarm(unsigned char return_value)
{
    qDebug("slot_pc_image_set_alarm return_value:0x%02x",return_value);
}
//恢复出厂设置
void HpSetting::slot_pc_sys_set_default(unsigned char return_value)                 //不理解为什要断开后再连接槽，直接清空不行吗？？？
{
    qDebug("slot_pc_sys_set_default return_value:0x%02x",return_value);         //断开槽
    //清空保存的最大框文件
    SignalClearMaxRectPara();

    disconnect(ui->comboBox_dangwei,SIGNAL(currentIndexChanged(int)),this,SLOT(cwfw_dangwei_current_index_changed(int)));
    disconnect(ui->comboBox_jingtou,SIGNAL(currentIndexChanged(int)),this,SLOT(cwfw_jingtou_current_index_changed(int)));
    ui->comboBox_jingtou->clear();                                                                      //清空槽
    ui->comboBox_dangwei->clear();

    jingtou_init = true;
    wendang_init = true;
    ui->listWidget_jingtou->clear();
    ui->listWidget_wendang->clear();                             //界面相关函数



    //新建槽
    connect(ui->comboBox_dangwei,SIGNAL(currentIndexChanged(int)),this,SLOT(cwfw_dangwei_current_index_changed(int)));
    connect(ui->comboBox_jingtou,SIGNAL(currentIndexChanged(int)),this,SLOT(cwfw_jingtou_current_index_changed(int)));
}

void HpSetting::slot_pc_sys_set_format(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_format return_value:0x%02x",return_value);
    SignalCheckAndCreateDateFolder();
}

void HpSetting::slot_pc_sys_set_capturetime(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_capturetime return_value:0x%02x",return_value);
}

void HpSetting::slot_pc_sys_time_sec(unsigned char return_value)
{
    qDebug("slot_pc_sys_time_sec return_value:0x%02x",return_value);
    SignalCheckAndCreateDateFolder();

}

void HpSetting::slot_pc_sys_set_usbmode(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_usbmode return_value:0x%02x",return_value);
}
//wifi_switch
void HpSetting::slot_pc_sys_set_wifi_switch(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_wifi_switch return_value:0x%02x",return_value);
}

void HpSetting::slot_pc_measure_tempcapture(unsigned char return_value)
{
    qDebug("slot_pc_image_set_alarm return_value:0x%02x",return_value);
}

void HpSetting::finish_button_pressed()
{
    signal_update_lcdoff_time(false);
    signal_update_distance_to_display(TempUserPara.Distance100);
    signal_update_radiance_to_display(TempUserPara.Radiance100);
    signal_update_radTable_to_display(TempUserPara.RadTable_id, TempUserPara.RadTable_value100);
    signal_set_radTable_state(TempUserPara.RadTable_switch);

    signal_update_reflect_temp_to_display(TempUserPara.ReflectTemp100);

    ui->listWidget_ReflectTemp->close();
    if(TempUserPara.AmbientTempManu100 != TempUserPara_old.AmbientTempManu100
            ||TempUserPara.Distance100 != TempUserPara_old.Distance100
            ||TempUserPara.Humidity100 != TempUserPara_old.Humidity100
            ||TempUserPara.Radiance100 != TempUserPara_old.Radiance100
            ||TempUserPara.ReflectTemp100 != TempUserPara.ReflectTemp100
            ||TempUserPara.transmission100 != TempUserPara_old.transmission100
            ||TempUserPara.RadTable_switch != TempUserPara_old.RadTable_switch
            ||TempUserPara.RadTable_id != TempUserPara.RadTable_id
            ||TempUserPara.RadTable_value100 != TempUserPara_old.RadTable_value100
            )
    {
        qDebug() << "TempUserPara.AmbientTempManu100; " << TempUserPara.AmbientTempManu100;
        qDebug() << "TempUserPara.Distance100;        " << TempUserPara.Distance100;
        qDebug() << "TempUserPara.Humidity100;        " << TempUserPara.Humidity100;
        qDebug() << "TempUserPara.Radiance100;        " << TempUserPara.Radiance100;
        qDebug() << "TempUserPara.ReflectTemp100;     " << TempUserPara.ReflectTemp100;
        qDebug() << "TempUserPara.transmission100;    " << TempUserPara.transmission100;
        qDebug() << "TempUserPara.RadTable_switch;    " << TempUserPara.RadTable_switch;
        qDebug() << "TempUserPara.RadTable_id;        " << TempUserPara.RadTable_id;
        qDebug() << "TempUserPara.RadTable_value100;  " << TempUserPara.RadTable_value100;

        qDebug() << "HpSetting signal_pc_cfg_set_temp_userpara";
        signal_pc_cfg_set_temp_userpara(TempUserPara);
        memcpy(&TempUserPara_old,&TempUserPara,sizeof(TempUserPara));
    }

    if(ReferTemp_enable_first == true){
        ReferTemp_enable_first =false;
        signal_pc_measure_set_reference(TempReference);
        memcpy(&TempReference_old,&TempReference,sizeof(ComTempReference));
    }else if(TempReference.enable != TempReference_old.enable
             ||TempReference.ReferTemp100 != TempReference_old.ReferTemp100 )
    {
        signal_pc_measure_set_reference(TempReference);
        memcpy(&TempReference_old,&TempReference,sizeof(ComTempReference));
    };
//    if(TempReference.enable != TempReference_old.enable
//            ||TempReference.ReferTemp100 != TempReference_old.ReferTemp100
//            )
//    {
//        signal_pc_measure_set_reference(TempReference);
//        memcpy(&TempReference_old,&TempReference,sizeof(ComTempReference));
//    }

    if(autorectify_time != autorectify_time_old)
    {
        if(autorectify_time == ui->cwfw_autorectify->minimum())
        {
            signal_pc_sys_set_autorectify(0);
        }
        else
        {
            signal_pc_sys_set_autorectify(autorectify_time);
        }

        autorectify_time_old = autorectify_time;
    }

    if(screensave_time != screensave_time_old)
    {
        if(screensave_time == ui->spinBox_autosave->minimum())
        {
            signal_pc_sys_set_capturetime(0);
        }
        else
        {
            signal_pc_sys_set_capturetime(screensave_time);
        }
        screensave_time_old = screensave_time;
    }

    if(hp_datetime != hp_datetime_old)
    {
        QByteArray ba = hp_datetime.toLatin1();
        char *mm = ba.data();
        hp_datetime_old = hp_datetime;
        signal_pc_sys_time_sec(mm);
    }
    ui->listWidget_jingtou->setCurrentRow(ui_jingtou_id);

    cwfw_jingtou_current_index_changed(ui_jingtou_id);
    ui->listWidget_wendang->setCurrentRow(ui_dangwei_id);
    signal_setting_close();
//    signal_pc_key_auto_rectify();
    /* 如果当前选择的模式为任务模式，则发送信号开启任务模式 */
    if(isTaskMode) {
        signal_TaskStart();
    }
    close();            //关闭设置界面
}

void HpSetting::buguangdeng_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
    if(checked)
    {
        qDebug()<<"bu guang deng on";
        signal_pc_sys_set_light_power(1);
    }
    else
    {
        qDebug()<<"bu guang deng off";
        signal_pc_sys_set_light_power(0);
    }
}

void HpSetting::slot_ble_set_close()
{
    qDebug() <<" -------------------------" << "HpSetting::slot_ble_set_close()1";

    if(ui->checkBox_ble->isChecked())
    {
        alreadyClosed = true;
        signal_pc_sys_set_ble_switch(0);
        if(isNewBle)
            signal_pc_sys_set_ble_module(0);
        signal_pc_sys_set_ble_power(0);

        ui->ble_edit->close();
        ui->ble_edit->setEnabled(false);
        ui->checkBox_ble->setChecked(false);
        ui->checkBox_ble->clicked(false);
    }
    else
    {
        if(isNewBle && !hpblesearch.m_isCloseBle)
        {
            signal_pc_sys_set_ble_switch(0);
            if(isNewBle)
                signal_pc_sys_set_ble_module(0);
            signal_pc_sys_set_ble_power(0);
        }
    }
    qDebug() <<" -------------------------" << "HpSetting::slot_ble_set_close()2";
}


void HpSetting::ble_clicked(bool checked)           //蓝牙开关
{
    signal_update_lcdoff_time(false);
    if(checked && ui->checkBox_transmission->isChecked())
    {
        ui->checkBox_ble->setChecked(false);
        return;
    }
    isBleOpen = checked;
    qDebug() << " HpSetting::ble_clicked" << " isBleOpen" << isBleOpen << " isLinekd" << hpblesearch.isLinked << ui->ble_edit->isVisible();
    if(checked)
    {
        alreadyClosed = false;
        ui->checkBox_transmission->setEnabled(false);
        if(ui->checkBox_ble->isChecked())
        {
            if(m_isS3X0 == 2)
            {
                ui->ble_edit->setGeometry(ui->checkBox_ble->x() + 60, ui->checkBox_ble->y(),40,25);
            }else{
                ui->ble_edit->setGeometry(ui->checkBox_ble->x() + ui->checkBox_ble->width() + 5, ui->checkBox_ble->y(),71,30);
            }
            ui->ble_edit->show();
            ui->ble_edit->setEnabled(true);
            hpdialog->setText(hpblesearch.fBleStart);
            hpdialog->show();
            update();
            signal_pc_sys_set_ble_power(1);
        }
    }
    else
    {
        MainWidget* p = (MainWidget*)parentP;
        if((this->isVisible() || p->m_hotKey0 == HOTKEY_BLUETOOTH || p->m_hotKey1 == HOTKEY_BLUETOOTH))
        {
            hpdialog->setText(tr("模块关闭中"));
            hpdialog->show();
        }

        ui->checkBox_transmission->setEnabled(true);
        if(isNewBle && hpblesearch.isLinked && !alreadyClosed)
        {
            alreadyClosed = true;
            qDebug() << 1;
            hpblesearch.ble_off();
        }
        else if(isNewBle && !hpblesearch.isLinked && !alreadyClosed)
        {
            alreadyClosed = true;
            signal_pc_sys_set_ble_switch(0);
            if(isNewBle)
                signal_pc_sys_set_ble_module(0);
            signal_pc_sys_set_ble_power(0);
        }
        if(!isNewBle)
        {
            signal_pc_sys_set_ble_switch(0);
            signal_pc_sys_set_ble_power(0);
        }
    }
}

void HpSetting::slot_pc_sys_set_ble_power(unsigned char return_value)
{
    qDebug("HpSetting::slot_pc_sys_set_ble_power 0x0%x %d", return_value, this->isVisible());
    if(ui->checkBox_transmission->isChecked())
    {
        if(!m_transmissionInit)
        {
            m_transmissionInit = true;
            return;
        }
        if(m_transmissionIsSearch)
        {
            m_Transmission->slot_start_get_bleInfo();
            return;
        }
        m_Transmission->setBleMode(171);
        signal_start_transmission();
        return;
    }
    MainWidget* p = (MainWidget*)parentP;
    if(return_value == RE_OK && (this->isVisible() || p->m_hotKey0 == HOTKEY_BLUETOOTH || p->m_hotKey1 == HOTKEY_BLUETOOTH))
    {
        qDebug() << "ui->ble_edit->isVisible()" << ui->ble_edit->isVisible();

        if(ui->checkBox_ble->isChecked() && (this->isVisible() || p->m_hotKey0 == HOTKEY_BLUETOOTH || p->m_hotKey1 == HOTKEY_BLUETOOTH))
        {
            if(isNewBle)
                signal_pc_sys_set_ble_module(1);//（0-关闭 1-指令模式 2-传输模式）
            signal_pc_sys_set_ble_switch(1);
        }
        else
        {
            if(!isNewBle)
                hpblesearchold.ble_off();
        }
        if(!isBleOpen)
        {
            ui->ble_edit->move(-100, -20);
            ui->ble_edit->close();
            ui->ble_edit->setEnabled(false);
            hpdialog->close();
        }
    }
    else
    {
        if((this->isVisible() || p->m_hotKey0 == HOTKEY_BLUETOOTH || p->m_hotKey1 == HOTKEY_BLUETOOTH))
        {
            hpdialog->close();
            ui->checkBox_ble->setChecked(false);
            ui->checkBox_ble->clicked(false);
        }
    }
}

void HpSetting::slot_pc_sys_set_ble_module(unsigned char return_value)
{
    qDebug() << "HpSetting::slot_pc_sys_set_ble_module" << return_value << this->isVisible();

    MainWidget* p = (MainWidget*)parentP;
    if(return_value != RE_OK && (this->isVisible() || p->m_hotKey0 == HOTKEY_BLUETOOTH || p->m_hotKey1 == HOTKEY_BLUETOOTH))
    {
        hpdialog->close();
        ui->checkBox_ble->setChecked(false);
        ui->checkBox_ble->clicked(false);
    }
}

void HpSetting::slot_pc_sys_set_ble_switch(unsigned char return_value)
{
    qDebug() << "HpSetting::slot_pc_sys_set_ble_switch" << return_value;

    MainWidget* p = (MainWidget*)parentP;
    hpdialog->close();
    if(return_value == RE_OK && (this->isVisible() || p->m_hotKey0 == HOTKEY_BLUETOOTH || p->m_hotKey1 == HOTKEY_BLUETOOTH))
    {
        if(isBleOpen)
        {
            if(!isNewBle)
            {
                if(hpblesearchold.flush_ui_device())
                {
                    hpblesearchold.ble_on();
                    hpblesearchold.show();
                }else
                {
                    qDebug( )<<" ERROR: ble init error";
                }
                return;
            }
            else
            {
                hpblesearch.ble_on();
                hpblesearch.show();

            }
        }
    }
}
//2018.1.15
void HpSetting::wifi_clicked(bool checked)
{
    signal_update_lcdoff_time(false);

    qDebug() << "HpSetting::wifi_clicked == > " << checked;
    if(checked)
    {
        ui->listWidget_usbmode->setEnabled(false);
        ui->listWidget_usbmode->setCurrentRow(1);
        signal_pc_sys_set_usbmode(1);
    }
    else
    {
        ui->listWidget_usbmode->setEnabled(true);
    }
    if(isWIFISearch)
    {
        if(checked)
        {
            if(ui->checkBox_eth->isChecked())
            {
                ui->checkBox_eth->setChecked(false);
                signal_pc_sys_set_wifi_eth_close(0);
                eth_num = -1;
                signal_set_ETH_switch(0);
            }
            if(ui->checkBox_4G->isChecked())
            {
                ui->checkBox_4G->setChecked(false);
                state4G = IS_ON_NONE;
                state_4G->stop();
                signal_set_4G_state(0);
                signal_set_4G_power(0);
            }
            if(listwidget_type !=0)      //表示有下拉框打开
            {
                listwidget_type_manage();
                return;
            }
            getWifiWait = 0;
            signal_pc_sys_set_wifi_power(1);
            ui->wifi_edit->show();
            hp_wifi_Search->On_set_click_Init();
//            emit hp_wifi_Search->signal_PC_SYS_GET_ESSID();
            hp_wifi_Search->show();
        }
        else
        {
            ui->wifi_edit->close();
            hp_wifi_Search->slot_SetDisConnect();
            hp_wifi_Search->close();
            signal_pc_sys_set_wifi_power(0);
            //让hp_wifi_search断开连接
        }
    }
    else
    {
        if(checked)
        {
            if(ui->checkBox_eth->isChecked())
            {
                ui->checkBox_eth->setChecked(false);
                signal_pc_sys_set_wifi_eth_close(0);
                eth_num = -1;
                signal_set_ETH_switch(0);
            }
            if(ui->checkBox_4G->isChecked())
            {
                ui->checkBox_4G->setChecked(false);
                state4G = IS_ON_NONE;
                state_4G->stop();
                signal_set_4G_state(0);
                signal_set_4G_power(0);
            }
            isWifiInsert = false;
            signal_pc_sys_set_wifi_power(1);
//            signal_pc_sys_set_wifi_switch(1);
        }
        else
        {
            isWifiInsert = false;
            signal_pc_sys_set_local_servrer(0);
            signal_pc_sys_set_wifi_switch(0);
            signal_pc_sys_set_wifi_power(0);
        }
    }
}
void HpSetting::slot_close_task()
{
//    isTaskMode = false;
//    ui->listWidget_modeSelect->setCurrentRow(0);
//    ui->checkBox_transmission->setChecked(false);
//    ui->checkBox_transmission->clicked(false);
}

void HpSetting::auto_lcdoff_value_changed(int index)
{
    signal_update_lcdoff_time(false);
    if(language_changing)
        return;
    switch(index)
    {
    case 1:
        auto_lcdoff = true;
        lcdoff_clock = 15;//15秒
        lcdoff_clock_ret = 15;
        signal_set_IsInlcdoff(true);
        break;
    case 2:
        auto_lcdoff = true;
        lcdoff_clock = 60;//1分钟
        lcdoff_clock_ret = 60;
        signal_set_IsInlcdoff(true);
        break;
    case 3:
        auto_lcdoff = true;
        lcdoff_clock = 300;//5分钟
        lcdoff_clock_ret = 300;
        signal_set_IsInlcdoff(true);
        break;
    case 4:
        auto_lcdoff = true;
        lcdoff_clock = 1800;//30分钟
        lcdoff_clock_ret = 1800;
        signal_set_IsInlcdoff(true);
        break;
    case 5:
        auto_lcdoff = true;
        lcdoff_clock = 3200;//1小时
        lcdoff_clock_ret = 3200;
        signal_set_IsInlcdoff(true);
        break;
    case 6:
        auto_lcdoff = true;
        lcdoff_clock = 9600;//3小时
        lcdoff_clock_ret = 9600;
        signal_set_IsInlcdoff(true);
        break;
    case 7:
        auto_lcdoff = true;
        lcdoff_clock = 19200;//6小时
        lcdoff_clock_ret = 19200;
        signal_set_IsInlcdoff(true);
        break;
    default:
        auto_lcdoff = false;
        break;
    }
}

void HpSetting::slot_core_fpga_get_ver(unsigned char return_value,int val)
{
      qDebug("slot_core_fpga_get_ver return_value:0x%02x val = %d",return_value, val);
//    if(return_value == RE_OK && !val.isEmpty())
//    {
//        ui->label_gujianbanben_text->setText(val);
//        return;
//    }
      if(QFile::exists("/home/root/qtconfig.xml"))
      {
          QString para = hpxmlreader.readXml("/home/root/qtconfig.xml","FPGA_UPDATE","filename");
          if(!para.isEmpty())
          {
              ui->label_gujianbanben_text->setText(para.split(".b").at(0));
          }
      }
}

void HpSetting::slot_update_lcdoff_Time()
{
    if(auto_lcdoff)
    {
        lcdoff_clock = lcdoff_clock_ret;
    }
}
void HpSetting::ble_edit_release()
{
    signal_update_lcdoff_time(false);
    if(listwidget_type !=0)      //表示有下拉框打开
    {
        listwidget_type_manage();
        return;
    }
    if(isNewBle)
        hpblesearch.show();
    else
        hpblesearchold.show();
}
void HpSetting::wifi_edit_release()
{
    signal_update_lcdoff_time(false);
    if(listwidget_type !=0)      //表示有下拉框打开
    {
        listwidget_type_manage();
        return;
    }
    hp_wifi_Search->On_set_click_Init();
    hp_wifi_Search->show();
}

//void HpSetting::slot_dangwei_jingtou_adjust(bool state)//无作用
//{
//    if(true == state)
//    {
//        ui_jingtou_changeid = ui->comboBox_jingtou->currentIndex();
//        ui_dangwei_changeid = ui->comboBox_dangwei->currentIndex();
//        if((ui_jingtou_changeid == ui_jingtou_id)  && (ui_dangwei_changeid == ui_dangwei_id))
//        {
//            return;
//        }else{
//            hpdialog->show();
//            signal_pc_measure_set_temprange(TempRange);
//        }
//    }else
//    {
//        temp_tab_change =true;
//        ui->comboBox_dangwei->setCurrentIndex(ui_dangwei_id);
//        ui->comboBox_jingtou->setCurrentIndex(ui_jingtou_id);

//        ui->listWidget_wendang->setCurrentRow(ui_dangwei_id);
//        ui->listWidget_jingtou->setCurrentRow(ui_jingtou_id);
//        ui->label_jingtou->setText(ui->listWidget_jingtou->currentItem()->text());
//        ui->label_wendang->setText(ui->listWidget_wendang->currentItem()->text());
//        temp_tab_change =false;
//    }
//}

void HpSetting::auto_poweroff_value_changed(int index)
{
    signal_update_lcdoff_time(false);
    if(language_changing)
        return;
    switch(index)
    {
    case 1:
        auto_poweroff = true;
        poweroff_clock = 15;//15秒
        break;
    case 2:
        auto_poweroff = true;
        poweroff_clock = 60;//1分钟
        break;
    case 3:
        auto_poweroff = true;
        poweroff_clock = 300;//5分钟
        break;
    case 4:
        auto_poweroff = true;
        poweroff_clock = 1800;//30分钟
        break;
    case 5:
        auto_poweroff = true;
        poweroff_clock = 3200;//1小时
        break;
    case 6:
        auto_poweroff = true;
        poweroff_clock = 9600;//3小时
        break;
    case 7:
        auto_poweroff = true;
        poweroff_clock = 19200;//6小时
        break;
    default:
        auto_poweroff = false;
        break;
    }
}

void HpSetting::on_pushButton_default_clicked()
{
    signal_update_lcdoff_time(false);
    if(listwidget_type !=0)      //表示有下拉框打开
    {
        listwidget_type_manage();
        return;
    }
    hpdefault->default_button_state();
    hpdefault->exec();
}

void HpSetting::on_tabWidget_currentChanged(int index)                      //切换条目
{
    signal_update_lcdoff_time(false);
    if( 6 == index)
    {
        return;
    }

    if(listwidget_type != 0)
    {
         listwidget_type_manage();
    }

    if(language_changing)
        return;
    if(index == 4)
    {
        system("hwclock -s");
        QDateTime time = QDateTime::currentDateTime();
        hp_datetime = time.toString("yyyyMMddhhmmss");
        hp_datetime_old = time.toString("yyyyMMddhhmmss");
        ui->dateTimeEdit->setDateTime(time);
    }
    else
    {
        slot_tabbar_current_changed(index);
        if(hp_datetime != hp_datetime_old)
        {
            QByteArray ba = hp_datetime.toLatin1();
            char *mm = ba.data();
            hp_datetime_old = hp_datetime;
            signal_pc_sys_time_sec(mm);
        }
        if(index == 0)
        {
            finish_button_pressed();
        }

    }
}

void HpSetting::slot_tabbar_current_changed(int index)              //当前tab发生改变
{
    if(2 == index)         //2->温度范围
    {
        qDebug() << __func__ << __LINE__;
        qDebug() << __func__ << __LINE__ << "ui_jingtou_id" << ui_jingtou_id;
        qDebug() << __func__ << __LINE__ << "ui_dangwei_id" << ui_dangwei_id;
        ui->listWidget_jingtou->setCurrentRow(ui_jingtou_id);
        temp_tab_change = true;
        qDebug() << __func__ << __LINE__ << "ui->listWidget_wendang->count" << ui->listWidget_wendang->count();
        qDebug() << __func__ << __LINE__ << "ui->comboBox_dangwei->count" << ui->comboBox_dangwei->count();
        ui->listWidget_wendang->setCurrentRow(ui_dangwei_id);
        ui->comboBox_dangwei->setCurrentIndex(ui_dangwei_id);
        ui->label_jingtou->setText(ui->listWidget_jingtou->currentItem()->text());
        ui->label_wendang->setText(ui->listWidget_wendang->currentItem()->text());
        temp_tab_change = false;
    }
}

void HpSetting::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    hp_datetime = dateTime.toString("yyyyMMddhhmmss");
}

void HpSetting::on_pushButton_3_clicked()
{
    signal_update_lcdoff_time(false);
    if(listwidget_type !=0)      //表示有下拉框打开
    {
        listwidget_type_manage();
        return;
    }
    hpformat->format_button_state();
    hpformat->exec();
}

void HpSetting::timer_func()
{
    if(auto_lcdoff)
    {
        if(lcdoff_clock > 0)
        {
            lcdoff_clock--;
//            qDebug("lcdoff_clock = %d",lcdoff_clock);
        }
        else
        {
            qDebug("lcd off");
            signal_pc_sys_set_screen_sleep(1);
            lcd_offed = true;
//            lcdoff_clock_ret = 0;//这里要加！！！ X系列
            signal_set_IsInlcdoff(false);
        }
    }

    if(auto_poweroff)
    {
        if(poweroff_clock > 0)
        {
            poweroff_clock--;
            qDebug("poweroff_clock = %d",poweroff_clock);
        }
        else
        {
            qDebug("power off");
            signal_pc_sys_set_powerdown(1);
        }
    }
}

void HpSetting::on_comboBox_usbmode_currentIndexChanged(int index)
{
    signal_update_lcdoff_time(false);
    if(language_changing)
        return;
    signal_pc_sys_set_usbmode(index);
    signal_set_usbmode(index);
}

void HpSetting::setCurrentTabToWenDuXiuZheng()
{
    ui->tabWidget->setCurrentIndex(1);
}

int HpSetting::gettempunit()
{
    return tempunit;
}
bool HpSetting::getCheckedAutoUpdata()
{
    return autoUpdateIsChecked;
}
void HpSetting::on_comboBox_language_currentIndexChanged(int index)
{
    signal_update_lcdoff_time(false);
    if(language_changing)
        return;
    signal_language_changed(index);
   // signal_set_language(index);
}
void HpSetting::dangweiAutoaddone()
{
    tempWengdangchange = true;//是否处于温档改变状态
    int row = ui->listWidget_wendang->currentRow() + 1;
    if(row >= ui->listWidget_wendang->count())
    {
        row = 0;
    }
    ui->listWidget_wendang->setCurrentRow(row);
    on_listWidget_wendang_currentRowChanged(row);
    on_pushButton_qiehuan_released();
}
void HpSetting::jintouAutoaddone()
{
    //此函数未被调用
    jingtouhide = jingtouhide + 1;
    if(jingtouhide == 2)
    {
        jingtouhide = 0;
    }
    qDebug() << "HpSetting::jintouAutoaddone == > " << jingtouhide;
    TempRange.LensId = jingtouhide;//当前镜头号
//    这里不改变挡位，因为这个功能是零时需求，切换的第二镜头的挡位和第一个镜头的挡位完全一样，所以不用切档
    TempRange.TempRangeID = ui->comboBox_dangwei->currentIndex();//当前挡位号.设置为0表示   切换镜头后从第一个挡位开始
    swiftingCounter = 0;
    signal_pc_measure_set_temprange(TempRange);
}

void HpSetting::on_pushButton_hotkey_clicked()
{
    m_hotkeyWidget.showText();
    MainWidget* p = (MainWidget*)parentP;
    m_hotkeyWidget.setFocusType(p->m_hotKey1);
    m_hotkeyWidget.setCameraType(p->m_hotKey0);
    m_hotkeyWidget.showText();

    m_hotkeyWidget.show();
}

//选好挡位和镜头后发送信号。镜头和挡位的ID都是从0开始
void HpSetting::on_pushButton_qiehuan_released()
{
    signal_update_lcdoff_time(false);

    if(listwidget_type !=0)      //表示有下拉框打开
    {
        listwidget_type_manage();
        return;
    }


    //以下是获取当前挡位,并检测温度是否超出范围
    QStringList wendangret = ui->label_wendang->text().split('~');
    if(wendangret[0] != NULL && wendangret[1] != NULL)
    {
        QString Min_ret1 = wendangret[0];
        qDebug() << "dangweiMinTemp -- 0 > " << Min_ret1;
        QString Max_ret2 = wendangret[1];
        Max_ret2.chop(1);
        qDebug() << "dangweiMaxTemp -- 2 > " << Max_ret2;
        //最大值最小值设置地方，用于防止报警温度超过挡位值
        dangweiMinTemp = Min_ret1.toInt();
        dangweiMaxTemp = Max_ret2.toInt();
        if(dangweiMaxTemp == 80 && dangweiMinTemp == -20)
        {
            if(ui->cwfw_autorectify->value() >= 9)
            {
                autorectify_time_back = ui->cwfw_autorectify->value();
            }
            signal_noncool_unenable_plr(true);
            ui->checkBox_nonCool->setChecked(true);
            yqsz_nonCool_setchecked(true);
        }
        else
        {
            signal_noncool_unenable_plr(false);
            ui->checkBox_nonCool->setChecked(false);
            yqsz_nonCool_setchecked(false);
        }
        if(ui->comboBox_baojingwendu->value() > dangweiMaxTemp)
        {
            AlarmTemp.AlarmTemp100 = hptempunitconvert.getCTempValue(tempunit,dangweiMaxTemp*100);
            ui->comboBox_baojingwendu->setValue(dangweiMaxTemp);
        }else if(ui->comboBox_baojingwendu->value() < dangweiMinTemp)
        {
            AlarmTemp.AlarmTemp100 = hptempunitconvert.getCTempValue(tempunit,dangweiMinTemp*100);
            ui->comboBox_baojingwendu->setValue(dangweiMinTemp);
        }
    }

    ui_jingtou_changeid = ui->comboBox_jingtou->currentIndex();
    ui_dangwei_changeid = ui->comboBox_dangwei->currentIndex();
    if((ui_jingtou_changeid == ui_jingtou_id)  && (ui_dangwei_changeid == ui_dangwei_id))
    {
        return;
    }else{
        hpdialog->setText(hpblesearchold.fSwitching);
        hpdialog->show();
        swiftingCounter = 0;
        signal_pc_measure_set_temprange(TempRange);
//        tempSetTm.start(40000);
    }
}
void HpSetting::autoupdate_once(int page,int zon,QString content)
{
    hp_autoupload_dialog->setText(page,zon,content);
}
void HpSetting::range_lens_copy()        //用来保存上个状态的镜头号和挡位号
{
    ui_jingtou_id = ui->listWidget_jingtou->currentRow();
    ui_dangwei_id = ui->listWidget_wendang->currentRow();
}

int HpSetting::get_temp_unit_state()
{
    return tempunit;
}
void HpSetting::LimitAutoSave_SR_AutoUpload()
{
    if(ui->checkBox_sr->isChecked())
    {
        ui->checkBox_sr->setChecked(false);
        emit ui->checkBox_sr->clicked(false);
    }
    if(ui->checkBox_sr->isEnabled())
        ui->checkBox_sr->setEnabled(false);
}
void HpSetting::RelieveLimitAutoSave_SR_AutoUpload()
{
    if(!ui->checkBox_sr->isEnabled())
        ui->checkBox_sr->setEnabled(true);
}
void HpSetting::LimitAutoUpload()//自动存储和自动上传互斥
{
    if(ui->checkBox_autoUpload->isCheckable())
    {
        if(ui->checkBox_autoUpload->isChecked())
        {
            ui->checkBox_autoUpload->setChecked(false);
            emit ui->checkBox_autoUpload->clicked(false);
        }
        if(ui->checkBox_autoUpload->isEnabled())
            ui->checkBox_autoUpload->setEnabled(false);
    }
}
void HpSetting::RelieveLimitAutoUpload()
{
    qDebug() <<" ---------------------------------HpSetting::RelieveLimitAutoUpload" << ui->checkBox_autoUpload->isEnabled();
    if(!ui->checkBox_autoUpload->isEnabled())
        ui->checkBox_autoUpload->setEnabled(true);
}
/*************************************************下面是新增功能***********************************************/
bool HpSetting::eventFilter(QObject *w, QEvent *e)
{
        if(QEvent::MouseButtonPress == e->type())               //先判断是鼠标点击事件
        {
            qDebug() << "HpSetting::eventFilter -- > " << listwidget_type << " ; " << w->objectName();
            signal_update_lcdoff_time(false);
            switch(listwidget_type)
            {
            case 0:                                                                      //表示还没有下拉框点开
            {
                if(w->objectName() == "frame_jingtou")          //判断想要打开的是哪个下拉框
                {
                    listwidget_drop_manage_jingtou(true);
                }else if( w->objectName() == "frame_wendang" )
                {
                    listwidget_drop_manage_wendang(true);
                }else if(w->objectName() == "frame_bangjingshehzi")
                {
                    listwidget_drop_manage_bangjingshehzi(true);
                }else if(w->objectName() == "frame_baojingse")
                {
                    listwidget_drop_manage_baojingse(true);
                }else if(w->objectName() == "frame_usbmode")
                {
                    listwidget_drop_manage_usbmode(true);
                }
                else if(w->objectName() == "frame_language")
                {
                    listwidget_drop_manage_language(true);
                }else if(w->objectName() == "frame_poweroff")
                {
                    listwidget_drop_manage_poweroff(true);
                }else if(w->objectName() == "frame_lcdoff")
                {
                    listwidget_drop_manage_lcdoff(true);
                }else if(w->objectName() == "frame_Radiance")
                {
                    listwidget_drop_manage_Radiance(true);
                }else if(w->objectName() == "frame_recordmode")
                {
                    listwidget_drop_manage_recordmode(true);
                }else if(w->objectName() == "frame_modeSelect")
                {
                    listwidget_drop_manage_modeSelect(true);
                }else if(w->objectName() == "frame_focusmode")
                {
                    if(ui->frame_focusmode->isEnabled())
                        listwidget_drop_manage_focusmode(true);
                    qDebug() << "ui->listWidget_focusmode->isEnabled()" << ui->listWidget_focusmode->isEnabled();
                }else if(w->objectName() == "frame_imageType")
                {
                    listwidget_drop_manage_imageType(true);
                }else if(w->objectName() == "frame_ReflectTemp")
                {
                    listwidget_drop_manage_reflectTemp(true);
                }else
                {
                    listwidget_type_manage();
                }
                break;
            }
            case 1:                                                                     //表示第一个下拉框已经点开，进行处理
                listwidget_drop_manage_jingtou(false);
                break;
            case 2:
                listwidget_drop_manage_wendang(false);
                break;
            case 3:
                listwidget_drop_manage_bangjingshehzi(false);
                break;
            case 4:
                listwidget_drop_manage_baojingse(false);
                break;
            case 5:
                listwidget_drop_manage_usbmode(false);
                break;
            case 6:
                listwidget_drop_manage_language(false);
                break;
            case 7:
               listwidget_drop_manage_poweroff(false);
                break;
            case 8:
                listwidget_drop_manage_lcdoff(false);
                break;
            case 9:
                if(w->objectName() == "frame_Radiance")          //判断想要打开的是哪个下拉框
                {
                    listwidget_drop_manage_Radiance(false);
                }else{

                }
                break;
            case 10:
                listwidget_drop_manage_recordmode(false);
                break;
            case 11:
                listwidget_drop_manage_modeSelect(false);
                break;
            case 12:
                listwidget_drop_manage_focusmode(false);
                break;
            case 13:
                listwidget_drop_manage_imageType(false);
                break;
            case 14:
                listwidget_drop_manage_reflectTemp(false);
                break;
            default:
                break;
            }
        }else if( e->type() == QKeyEvent::KeyRelease)               //按键松开事件
        {
            qDebug( )<<" w->objectName()"<<w->objectName();
            QKeyEvent *key_event = (QKeyEvent *)e;
             keyReleaseEvent(key_event);
        }else{};

    return true;
}

void HpSetting::MousePressEvent(QMouseEvent *ev)
{
//    signal_pc_sys_set_screen_sleep(0);
}

void HpSetting::keyReleaseEvent(QKeyEvent *ev)
{
    signal_update_lcdoff_time(true);
    qDebug() << "HpSetting::keyReleaseEvent >> " << ev->key();
    if(onlcdonce)
    {
        onlcdonce = false;
        return;
    }
    if(lcd_offed)
    {
        qDebug("lcd on....1");

        slot_lcd_ReOpen();
        return;
    }
    if(ev->key() == KEY_RETURN)
    {
        if(m_transmissionSearch->isVisible())
        {
            m_transmissionSearch->close();
            update();
            return;
        }
        if(hp_wifi_Search->isVisible())//不知道为什么   wifi搜索窗口的返回事件，被这里接收到了
        {
            hp_wifi_Search->GoBack();
        }else if(hp_autoupload->isVisible())//不知道为什么   wifi搜索窗口的返回事件，被这里接收到了
        {
            hp_autoupload->GoBack();
        }else if(hp_autoupload_dialog->isVisible())
        {
            signal_autoupdate_return();
        }else if(hp_downLoad->isVisible())
        {
            if(hp_downLoad->hp_autoupload_dialog->isVisible())
            {
                qDebug() << " ---- hp_autoupload_dialog key close ---- ";
                hp_downLoad->hp_autoupload_dialog->close();
            }else{
                hp_downLoad->close();
            }
        }else if(hp_Mulhom_edit->isVisible())
        {
            hp_Mulhom_edit->on_toolButton_back_clicked();
        }else{
            finish_button_pressed();
            if(listwidget_type != 0)
            {
                 listwidget_type_manage();
            }
            signal_setting_close();
            close();
        }
    }
}

void HpSetting::on_listWidget_jingtou_currentRowChanged(int currentRow)                             //jingtou
{
    qDebug() << __func__ << __LINE__;
    signal_update_lcdoff_time(false);
    if( currentRow < 0)
    {
        return;
    }
    QString str;
    str = ui->listWidget_jingtou->currentItem()->text();
    ui->label_jingtou->setText(str);
    listwidget_drop_manage_jingtou(false);

    if(jingtou_init == true)//只在初始化的时候触发
    {
        jingtou_init =false;
        return;
    }

    if(temp_tab_change == true)//当tab改变的时候，还原原值，或者温度单位改变的时候触发
    {
        return;
    }

    jingtou_dangwei_change = true;


    wendang_i = 0;
    ui->listWidget_wendang->clear();
    ui->comboBox_jingtou->setCurrentIndex(currentRow);

}

void HpSetting::on_listWidget_wendang_currentRowChanged(int currentRow)
{
    qDebug() << __func__ << __LINE__;
    signal_update_lcdoff_time(false);
    if( currentRow < 0)
    {
        return;
    }
    QString str;
    str = ui->listWidget_wendang->currentItem()->text();
    ui->label_wendang->setText(str);
    listwidget_drop_manage_wendang(false);

    if(wendang_init ==true)
    {
        wendang_init =false;
        return;
    }


//改变镜头导致挡位发生改变。那么不进行下面操作
    if(jingtou_dangwei_change ==true || temp_tab_change == true)
    {
        return;
    }

    //同步改变 comboBox_dangwei
    ui->comboBox_dangwei->setCurrentIndex(currentRow);
}

void HpSetting::on_listWidget_baojingshezhi_currentRowChanged(int currentRow)
{
    signal_update_lcdoff_time(false);
    if( currentRow < 0)
    {
        return;
    }
    QString str;
    str = ui->listWidget_baojingshezhi->currentItem()->text();
    ui->label_bangjingshehzi->setText(str);
    listwidget_drop_manage_bangjingshehzi(false);

    if( baojingshezhi_init == true)
    {
        baojingshezhi_init =false;
        return;
    }

    if(language_changing)
        return;
    AlarmTemp.AlarmSwitch = currentRow;

    signal_pc_image_set_alarm(AlarmTemp);
    update();
}

void HpSetting::on_listWidget_baojingse_currentRowChanged(int currentRow)
{
    signal_update_lcdoff_time(false);
    if( currentRow<0)
    {
        return;
    }
    QString str;
    str = ui->listWidget_baojingse->currentItem()->text();
    ui->label_baojingse->setText(str);
    listwidget_drop_manage_baojingse(false);

    if( baojingse_init == true)
    {
        baojingse_init = false;
        return;
    }

    if(language_changing)
        return;
    AlarmTemp.AlarmColorId = currentRow;

    signal_pc_image_set_alarm(AlarmTemp);
    update();
}

void HpSetting::on_listWidget_usbmode_currentRowChanged(int currentRow)
{
    signal_update_lcdoff_time(false);
    if(ui->listWidget_usbmode->currentRow() == 0)
    {
        if(ui->checkBox_eth->isChecked())
        {
            ui->checkBox_eth->setChecked(false);
        }
        ui->checkBox_eth->setCheckable(false);
        if(ui->checkBox_wifi->isChecked())
        {
            ui->checkBox_wifi->setChecked(false);
        }
        ui->checkBox_wifi->setCheckable(false);
    }else
    {
        ui->checkBox_eth->setCheckable(true);

        ui->checkBox_wifi->setCheckable(true);
    }
    if( currentRow<0 || (ui->label_usbmode->text() == ui->listWidget_usbmode->currentItem()->text()))
    {
        return;
    }
    QString str;
    str = ui->listWidget_usbmode->currentItem()->text();
    ui->label_usbmode->setText(str);
    listwidget_drop_manage_usbmode(false);

    if(usbmode_init == true)
    {
        usbmode_init =false;
        return;
    }
    if(language_changing)
        return;
    signal_pc_sys_set_usbmode(currentRow);
    signal_set_usbmode(currentRow);
}

void HpSetting::on_listWidget_language_currentRowChanged(int currentRow)
{
    signal_update_lcdoff_time(false);
    if( currentRow<0)
    {
        return;
    }
    QString str;
    str = ui->listWidget_language->currentItem()->text();
    ui->label_language->setText(str);
    listwidget_drop_manage_language(false);

    if(language_changing)
        return;
    signal_language_changed(currentRow);
}

void HpSetting::on_listWidget_poweroff_currentRowChanged(int currentRow)
{
    signal_update_lcdoff_time(false);
    if( currentRow<0)
    {
        return;
    }
    QString str;
    str = ui->listWidget_poweroff->currentItem()->text();
    ui->label_poweroff->setText(str);
    listwidget_drop_manage_poweroff(false);

    auto_poweroff_value_changed(currentRow);
}

void HpSetting::on_listWidget_lcdoff_currentRowChanged(int currentRow)
{
    signal_update_lcdoff_time(false);
    if( currentRow<0)
    {
        return;
    }
    QString str;
    str = ui->listWidget_lcdoff->currentItem()->text();
    ui->label_lcdoff->setText(str);
    listwidget_drop_manage_lcdoff(false);

    auto_lcdoff_value_changed(currentRow);
}

void HpSetting::on_listWidget_Radiance_currentRowChanged(int currentRow)
{
    signal_update_lcdoff_time(false);
    if( currentRow<0)
    {
        return;
    }
    ui->label_Radiance->setText(ui->listWidget_Radiance->currentItem()->text());
    listwidget_drop_manage_Radiance(false);

    if(language_changing)
        return;
    //@ 添加 信号处理事件  lcy
    TempUserPara.RadTable_id = currentRow;
    TempUserPara.RadTable_value100 = radTable_value[currentRow];
    signal_update_radTable_to_display( TempUserPara.RadTable_id , TempUserPara.RadTable_value100);
//    qDebug( )<<" ******** on_listWidget_Radiance_currentRowChanged "<<TempUserPara.RadTable_id<<TempUserPara.RadTable_value100<<TempUserPara.RadTable_switch ;
}

void HpSetting::listwidget_drop_manage_jingtou(bool type)       //镜头下拉框打开关闭处理
{
    if(type == true)
    {
        listwidget_type = 1;
        if(define_S6X0_S3X0)
        {
            ui->listWidget_jingtou->setGeometry(ui->frame_jingtou->x(),ui->frame_jingtou->y() + ui->frame_jingtou->height(),ui->frame_jingtou->width(),21*jingtou_num);
        }else{
            ui->listWidget_jingtou->setGeometry(233,56,243,33*jingtou_num);
        }
        ui->listWidget_jingtou->show();
        ui->frame_wendang->setEnabled(false);
        ui->frame_bangjingshehzi->setEnabled(false);
        ui->frame_baojingse->setEnabled(false);
        ui->cwfw_autorectify->setEnabled(false);
        ui->comboBox_baojingwendu->setEnabled(false);
        ui->comboBox_buchangwendu->setEnabled(false);
    }else
    {
        listwidget_type = 0;
        ui->listWidget_jingtou->close();
        ui->frame_jingtou->setEnabled(true);
        ui->frame_wendang->setEnabled(true);
        ui->frame_bangjingshehzi->setEnabled(true);
        ui->frame_baojingse->setEnabled(true);
        ui->cwfw_autorectify->setEnabled(true);
        ui->comboBox_baojingwendu->setEnabled(true);
        ui->comboBox_buchangwendu->setEnabled(true);
    }

}

void HpSetting::listwidget_drop_manage_wendang(bool type)       //温档
{
    if(type == true)
    {
        listwidget_type = 2;
        int num= ui->listWidget_wendang->count();
        if(define_S6X0_S3X0)
        {
            ui->listWidget_wendang->setGeometry(ui->frame_wendang->x(),ui->frame_wendang->y() + ui->frame_wendang->height(),ui->frame_wendang->width(),21*num);
        }else{
            ui->listWidget_wendang->setGeometry(233,120,243,33*num);
        }
        ui->listWidget_wendang->show();
        ui->frame_jingtou->setEnabled(false);
        ui->frame_bangjingshehzi->setEnabled(false);
        ui->frame_baojingse->setEnabled(false);
        ui->cwfw_autorectify->setEnabled(false);
        ui->comboBox_baojingwendu->setEnabled(false);
        ui->comboBox_buchangwendu->setEnabled(false);
    }else
    {
        listwidget_type =0;
        ui->listWidget_wendang->close();
        ui->frame_jingtou->setEnabled(true);
        ui->frame_wendang->setEnabled(true);
        ui->frame_bangjingshehzi->setEnabled(true);
        ui->frame_baojingse->setEnabled(true);
        ui->cwfw_autorectify->setEnabled(true);
        ui->comboBox_baojingwendu->setEnabled(true);
        ui->comboBox_buchangwendu->setEnabled(true);
    }
}

void HpSetting::listwidget_drop_manage_bangjingshehzi(bool type)        //报警设置
{
    if(type == true)
    {
        listwidget_type =3;
        if(define_S6X0_S3X0)
        {
            ui->listWidget_baojingshezhi->setGeometry(ui->frame_bangjingshehzi->x(),ui->frame_bangjingshehzi->y() + ui->frame_bangjingshehzi->height(),ui->frame_bangjingshehzi->width(),21*3);
        }else{
            ui->listWidget_baojingshezhi->setGeometry(233,302,243,100);
        }
        ui->listWidget_baojingshezhi->show();
        ui->frame_jingtou->setEnabled(false);
        ui->frame_wendang->setEnabled(false);
        ui->frame_baojingse->setEnabled(false);
        ui->cwfw_autorectify->setEnabled(false);
        ui->comboBox_baojingwendu->setEnabled(false);
        ui->comboBox_buchangwendu->setEnabled(false);

    }else
    {
        listwidget_type =0;
        ui->listWidget_baojingshezhi->close();
        ui->frame_jingtou->setEnabled(true);
        ui->frame_wendang->setEnabled(true);
        ui->frame_bangjingshehzi->setEnabled(true);
        ui->frame_baojingse->setEnabled(true);
        ui->cwfw_autorectify->setEnabled(true);
        ui->comboBox_baojingwendu->setEnabled(true);
        ui->comboBox_buchangwendu->setEnabled(true);
    }
}

void HpSetting::listwidget_drop_manage_baojingse(bool type)
{
    if(type == true)
    {
        listwidget_type =4;
        if(define_S6X0_S3X0)
        {
            ui->listWidget_baojingse->setGeometry(140,0,151,19*10-3);
        }else{
            ui->listWidget_baojingse->setGeometry(233,17,243,303);
        }
        ui->listWidget_baojingse->show();
        ui->frame_jingtou->setEnabled(false);
        ui->frame_wendang->setEnabled(false);
        ui->frame_bangjingshehzi->setEnabled(false);
        ui->cwfw_autorectify->setEnabled(false);
        ui->comboBox_baojingwendu->setEnabled(false);
        ui->comboBox_buchangwendu->setEnabled(false);
    }else
    {
        listwidget_type =0;
        ui->listWidget_baojingse->close();
        ui->frame_jingtou->setEnabled(true);
        ui->frame_wendang->setEnabled(true);
        ui->frame_bangjingshehzi->setEnabled(true);
        ui->frame_baojingse->setEnabled(true);
        ui->cwfw_autorectify->setEnabled(true);
        ui->comboBox_baojingwendu->setEnabled(true);
        ui->comboBox_buchangwendu->setEnabled(true);
    }

}

void HpSetting::listwidget_drop_manage_usbmode(bool type)
{
    if(type == true)
    {
        listwidget_type =5;
        if(define_S6X0_S3X0)
        {
            ui->listWidget_usbmode->setGeometry(ui->frame_usbmode->x(),ui->frame_usbmode->y() + ui->frame_usbmode->height(),ui->frame_usbmode->width(),21*2);
        }else{
            ui->listWidget_usbmode->setGeometry(ui->frame_usbmode->x(),ui->frame_usbmode->y() + ui->frame_usbmode->height(),243,70);
        }
        if(ui->listWidget_usbmode->y() + ui->listWidget_usbmode->height() > 460)
        {
            ui->listWidget_usbmode->setGeometry(ui->frame_usbmode->x(),ui->frame_usbmode->y() - ui->frame_usbmode->height(),ui->frame_usbmode->width(),ui->frame_usbmode->height());
        }
        ui->listWidget_usbmode->show();

        ui->checkBox_wifi->setEnabled(false);
        ui->buguangdeng->setEnabled(false);
        ui->checkBox_ble->setEnabled(false);
        ui->spinBox_autosave->setEnabled(false);
    }else
    {
        listwidget_type =0;
        ui->listWidget_usbmode->close();
        ui->buguangdeng->setEnabled(true);
        ui->checkBox_wifi->setEnabled(true);
        ui->checkBox_ble->setEnabled(true);
        ui->spinBox_autosave->setEnabled(true);
    }
}

void HpSetting::listwidget_drop_manage_language(bool type)
{
    if(type == true)
    {
        listwidget_type =6;
        if(define_S6X0_S3X0)
        {
            ui->listWidget_language->setGeometry(ui->frame_language->x(),ui->frame_language->y() + ui->frame_language->height(),ui->frame_language->width(),21*6);
        }else{
            ui->listWidget_language->setGeometry(ui->frame_language->x(),ui->frame_language->y() + ui->frame_language->height(),ui->frame_language->width(),200);
        }
        ui->listWidget_language->show();
        ui->listWidget_language->raise();
        ui->dateTimeEdit->setEnabled(false);
        ui->frame_poweroff->setEnabled(false);
        ui->frame_lcdoff->setEnabled(false);

    }else
    {
        listwidget_type =0;
        ui->listWidget_language->close();

        ui->frame_language->setEnabled(true);
         if(HP_Time == 1)
         {
              ui->dateTimeEdit->setEnabled(true);
         }

        ui->frame_poweroff->setEnabled(true);
        ui->frame_lcdoff->setEnabled(true);

    }
}

void HpSetting::listwidget_drop_manage_poweroff(bool type)
{
    if(type == true)
    {
        listwidget_type =7;
        if(define_S6X0_S3X0)
        {
            ui->listWidget_poweroff->setGeometry(ui->frame_poweroff->x(),ui->frame_poweroff->y() + ui->frame_poweroff->height(),ui->frame_poweroff->width(),21*4);
        }else{
            ui->listWidget_poweroff->setGeometry(ui->frame_poweroff->x(),ui->frame_poweroff->y() + ui->frame_poweroff->height(),ui->frame_poweroff->width(),130);
        }
        ui->listWidget_poweroff->show();
        ui->listWidget_poweroff->raise();

        ui->frame_language->setEnabled(false);
        ui->dateTimeEdit->setEnabled(false);
        ui->frame_lcdoff->setEnabled(false);

    }else
    {
        listwidget_type =0;
        ui->listWidget_poweroff->close();

        ui->frame_language->setEnabled(true);
        if(HP_Time == 1)
        {
             ui->dateTimeEdit->setEnabled(true);
        }
        ui->frame_poweroff->setEnabled(true);
        ui->frame_lcdoff->setEnabled(true);
    }

}

void HpSetting::listwidget_drop_manage_lcdoff(bool type)
{
    if(type == true)
    {
        listwidget_type =8;
        if(define_S6X0_S3X0)
        {
            ui->listWidget_lcdoff->setGeometry(ui->frame_lcdoff->x(),ui->frame_lcdoff->y() + ui->frame_lcdoff->height(),ui->frame_lcdoff->width(),21*4);
        }else{
            ui->listWidget_lcdoff->setGeometry(ui->frame_lcdoff->x(),ui->frame_lcdoff->y() + ui->frame_lcdoff->height(),ui->frame_lcdoff->width(),130);
        }
        ui->listWidget_lcdoff->raise();
        ui->listWidget_lcdoff->show();

        ui->frame_language->setEnabled(false);
        ui->dateTimeEdit->setEnabled(false);
        ui->frame_poweroff->setEnabled(false);

    }else
    {
        listwidget_type =0;
        ui->listWidget_lcdoff->close();

        ui->frame_language->setEnabled(true);
        if(HP_Time == 1)
        {
             ui->dateTimeEdit->setEnabled(true);
        }
        ui->frame_poweroff->setEnabled(true);
        ui->frame_lcdoff->setEnabled(true);
    }

}

void HpSetting::listwidget_drop_manage_Radiance(bool type)
{
    if(type == true)
    {
        listwidget_type =9;
        ui->listWidget_Radiance->show();
        ui->listWidget_Radiance->raise();
        ui->checkBox_ReferTemp_enable->setEnabled(false);
        //ScrollBar
        ui->ScrollBar_AmbientTempManu->setEnabled(false);
        ui->ScrollBar_Distance->setEnabled(false);
        ui->ScrollBar_Humidity->setEnabled(false);
        ui->ScrollBar_Radiance->setEnabled(false);
        //ui->ScrollBar_ReferTemp->setEnabled(false);
        ui->ScrollBar_ReflectTemp->setEnabled(false);
        ui->ScrollBar_TempUnit->setEnabled(false);
        ui->ScrollBar_transmission->setEnabled(false);

    }else
    {
        listwidget_type =0;
        ui->listWidget_Radiance->hide();
        ui->checkBox_ReferTemp_enable->setEnabled(true);

        ui->ScrollBar_AmbientTempManu->setEnabled(true);
        ui->ScrollBar_Distance->setEnabled(true);
        ui->ScrollBar_Humidity->setEnabled(true);
        ui->ScrollBar_Radiance->setEnabled(true);
        //ui->ScrollBar_ReferTemp->setEnabled(true);
        ui->ScrollBar_ReflectTemp->setEnabled(true);
        ui->ScrollBar_TempUnit->setEnabled(true);
        ui->ScrollBar_transmission->setEnabled(true);
    }
}
void HpSetting::listwidget_drop_manage_recordmode(bool type)
{
    if(type == true)
    {
        listwidget_type =10;
        ui->listWidget_recordmode->raise();
        ui->listWidget_recordmode->show();
        ui->checkBox_wifi->setEnabled(false);
        ui->buguangdeng->setEnabled(false);
        ui->checkBox_ble->setEnabled(false);
        ui->spinBox_autosave->setEnabled(false);
    }else
    {
        listwidget_type =0;
        ui->listWidget_recordmode->close();
        ui->buguangdeng->setEnabled(true);
        ui->checkBox_wifi->setEnabled(true);
        ui->checkBox_ble->setEnabled(true);
        ui->spinBox_autosave->setEnabled(true);
    }
}
void HpSetting::listwidget_drop_manage_modeSelect(bool type)
{
    if(type == true)
    {
        if(!ui->checkBox_transmission->isChecked())
        {
            return;
        }
        listwidget_type = 11;
        ui->listWidget_modeSelect->setGeometry(ui->frame_modeSelect->x(),ui->frame_modeSelect->y() + ui->frame_modeSelect->height(),ui->listWidget_modeSelect->width(),ui->listWidget_modeSelect->height());

        ui->listWidget_modeSelect->show();
        ui->checkBox_wifi->setEnabled(false);
        ui->buguangdeng->setEnabled(false);
        ui->checkBox_ble->setEnabled(false);
        ui->spinBox_autosave->setEnabled(false);
    }else
    {
        listwidget_type =0;
        ui->listWidget_modeSelect->close();
        ui->buguangdeng->setEnabled(true);
        ui->checkBox_wifi->setEnabled(true);
        ui->checkBox_ble->setEnabled(true);
        ui->spinBox_autosave->setEnabled(true);
    }
}

void HpSetting::listwidget_type_manage()
{
    switch(listwidget_type)
    {
    case 1:                                                                     //表示第一个下拉框已经点开，进行处理
        listwidget_drop_manage_jingtou(false);
        break;
    case 2:
        listwidget_drop_manage_wendang(false);
        break;
    case 3:
        listwidget_drop_manage_bangjingshehzi(false);
        break;
    case 4:
        listwidget_drop_manage_baojingse(false);
        break;
    case 5:
        listwidget_drop_manage_usbmode(false);
        break;
    case 6:
        listwidget_drop_manage_language(false);
        break;
    case 7:
       listwidget_drop_manage_poweroff(false);
        break;
    case 8:
        listwidget_drop_manage_lcdoff(false);
        break;
    case 9:
        listwidget_drop_manage_Radiance(false);
        break;
    case 10:
        listwidget_drop_manage_recordmode(false);
        break;
    case 11:
        listwidget_drop_manage_modeSelect(false);
    case 12:
        listwidget_drop_manage_focusmode(false);
        break;
    case 13:
        listwidget_drop_manage_imageType(false);
        break;
    case 14:
        listwidget_drop_manage_reflectTemp(false);
        break;
    default:
        break;
        }
}

void HpSetting::on_listWidget_jingtou_clicked(const QModelIndex &index)         //镜头下拉框选中点击
{

}

void HpSetting::on_listWidget_wendang_clicked(const QModelIndex &index)
{

}

void HpSetting::on_listWidget_baojingshezhi_clicked(const QModelIndex &index)
{

}

void HpSetting::on_listWidget_baojingse_clicked(const QModelIndex &index)
{

}

void HpSetting::on_checkBox_Radiance_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
    listwidget_type_manage();
    ui->label_Radiance->setText(ui->listWidget_Radiance->currentItem()->text());
    if(checked)
    {
        ui->frame_Radiance->show();
        ui->ScrollBar_Radiance->hide();
        TempUserPara.RadTable_switch = 1;
        signal_set_radTable_state(TempUserPara.RadTable_switch);
    }else{
        ui->frame_Radiance->hide();
        ui->ScrollBar_Radiance->show();
        TempUserPara.RadTable_switch = 0;
        signal_set_radTable_state(TempUserPara.RadTable_switch);
    }
}

void HpSetting::on_checkBox_ReferTemp_enable_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
    listwidget_type_manage();
}

void HpSetting::set_ScrollBar_TemperInfo(temper_info_t temperInfo)
{
//    qDebug() << "HpSetting::set_ScrollBar_Distance nEmissivity100" << temperInfo.nEmissivity100;
//    qDebug() << "temperInfo.temp_para.nDistance100;       " << temperInfo.temp_para.nDistance100;
//    qDebug() << "temperInfo.temp_para.nHumidity100;       " << temperInfo.temp_para.nHumidity100;
//    qDebug() << "temperInfo.temp_para.nAmbientTempManu100;" << temperInfo.temp_para.nAmbientTempManu100;
//    qDebug() << "temperInfo.temp_para.nReflectTemp100;    " << temperInfo.temp_para.nReflectTemp100;
//    qDebug() << "temperInfo.temp_para.nTransmission100;   " << temperInfo.temp_para.nTransmission100;
//    qDebug() << "temperInfo.draw_layer.nRefeTemp100;      " << temperInfo.draw_layer.nRefeTemp100;
//    qDebug() << "temperInfo.nTempUnit;                    " << temperInfo.nTempUnit;
    ui->ScrollBar_Radiance->setValue(temperInfo.temp_para.nEmissivity100);
    ui->ScrollBar_Distance->setValue(double(temperInfo.temp_para.nDistance100) / 100.0);
    ui->ScrollBar_Humidity->setValue(temperInfo.temp_para.nHumidity100 * 1.0);
    ui->ScrollBar_transmission->setValue(temperInfo.temp_para.nTransmission100);
    ui->ScrollBar_TempUnit->setValue(temperInfo.nTempUnit);
    double refeTemp        = double(temperInfo.reference_para.nRefeTemp100 * 1.0) / 100.0;
    double reflectTemp     = double(temperInfo.temp_para.nReflectTemp100 * 1.0) / 100.0;
    double ambientTempManu = double(temperInfo.temp_para.nAmbientTempManu100 * 1.0) / 100.0;
    if(temperInfo.nTempUnit == 0)
    {
    }
    else if(temperInfo.nTempUnit == 1)
    {
        refeTemp        = 9 * refeTemp / 5 + 32;
        reflectTemp     = 9 * reflectTemp / 5 + 32;
        ambientTempManu = 9 * ambientTempManu / 5 + 32;
    }
    else if(temperInfo.nTempUnit == 2)
    {
        refeTemp        += 273.15;
        reflectTemp     += 273.15;
        ambientTempManu += 273.15;
    }

    ui->ScrollBar_ReferTemp->setValue(refeTemp);
    ui->ScrollBar_ReflectTemp->setValue(reflectTemp);
    ui->ScrollBar_AmbientTempManu->setValue(ambientTempManu);
}

/***************************************************************************************/
void HpSetting::slot_dev_get_parameter(unsigned char *data, unsigned char return_value)
{
//    qDebug()<<"&& slot_dev_get_parameter  :  "<<return_value;
    ComSysConfig msg;
    if(return_value == RE_OK){
        memcpy(&msg,data,sizeof(ComSysConfig));
    }else{
        qDebug()<<"lot_dev_get_parameter  :  error ";
        return;
    }
//    qDebug( )<<"@@ "<<msg.Emissivity100<<msg.Repair100<<msg.RepairTemp100<<msg.Distance100<<msg.Humidity100<<msg.ReflectTemp100;
//    qDebug( )<<"@@ "<<msg.TempRangeID<<msg.OtherLensID<<msg.TempClass<<msg.TempUnit<<msg.RefeTempType<<msg.RefeTemp100;

//    qDebug( )<<"@@ "<<msg.AlarmColorID<<msg.AlarmSwitch<<msg.AlarmTemp100;
//    qDebug( )<<"@@ "<<msg.IsothermColorID<<msg.IsothermTemp100<<msg.IsothermHight100;
//    qDebug( )<<"@@ "<<msg.ColorRulerID<<msg.ReverseImage<<msg.ManualType<<msg.TempHigh100<<msg.TempLow100;

//    qDebug( )<<"@@ "<<msg.LanguageID<<msg.AutoZeroTime<<msg.AutoCapTime<<msg.BlackBodyTemp100<<msg.ZoomRate;
//    qDebug( )<<"@@ "<<msg.MonitorMode<<msg.ShowGrayEnable<<msg.CollectEnable;
//    qDebug( )<<"@@ "<<msg.InterCorrectTemp100<<msg.InterCorrectFact100<<msg.AlarmLevel<<msg.AlarmLevelNum;
//    qDebug( )<<"@@ "<<msg.Transmission100<<msg.AmbientTempManu100;
//    qDebug( )<<"@@ "<<msg.nradTable_switch<<msg.nradTable_id<<msg.nradTable_value100<<msg.nradTable100;

    if(msg.nradTable_switch == 0)
    {
        ui->checkBox_Radiance->setChecked(false);                   //辐射率表开关 关为0，开为1
        on_checkBox_Radiance_clicked(false);
    }else{
        ui->checkBox_Radiance->setChecked(true);
        on_checkBox_Radiance_clicked(true);
    }
    ui->listWidget_Radiance->setCurrentRow(msg.nradTable_id);                                       //辐射率表下拉框
    ui->label_Radiance->setText(ui->listWidget_Radiance->currentItem()->text());             //辐射率表文本
    ui->ScrollBar_Radiance->setValue(msg.nradTable100);                                                 //设置辐射率

    ui->ScrollBar_Distance->setValue(msg.Distance100/100.0);                                          //设置距离
    ui->ScrollBar_Humidity->setValue(msg.Humidity100);                                                 //相对湿度

    ui->ScrollBar_transmission->setValue(msg.Transmission100);                                         //窗口透过率

    if(msg.RefeTempType == 0)                   //0关闭1 打开 2点测温3:区域4:线
    {
        TempReference.enable = 0;
        TempReference_old.enable = 0;
        ui->checkBox_ReferTemp_enable->setChecked(false);                   //参考温度开关。 关为0，开为1
    }else if(msg.RefeTempType == 1){
        TempReference.enable = 1;
        TempReference_old.enable =1;
        ui->checkBox_ReferTemp_enable->setChecked(true);
    }else{;};

    TempReference.ReferTemp100 = msg.RefeTemp100;                                                           //参考温度
    TempUserPara.ReflectTemp100 = msg.ReflectTemp100;                                                       //反射温度
//     qDebug( )<<"@@ "<<msg.ReflectTemp100;

    TempUserPara.AmbientTempManu100 = msg.AmbientTempManu100;                               //环境温度
    tempunit = msg.TempUnit;                                                                                                //温度单位

    ui->ScrollBar_TempUnit->setValue(tempunit);
//    qDebug( )<<"@@@@ "<<msg.TempUnit;
    signal_ScrollBar_TempUnit_change(msg.TempUnit);

    signal_set_globresize_nZoomRate10_value(msg.ZoomRate);      //设置resize放大倍数
//    signal_set_globnProcessType_value(msg.ManualType, msg.TempHigh100,msg.TempLow100);llBar_ReferTemp->setValue(msg.RefeTemp100/100.0);                                    //参考温度

}

void HpSetting::slot_set_globle_ReferTemp(bool checked)
{
    if(checked == false)
    {
        ui->checkBox_ReferTemp_enable->setChecked(checked);
        TempReference.enable = 0;
        if(TempReference.enable != TempReference_old.enable
                ||TempReference.ReferTemp100 != TempReference_old.ReferTemp100
                )
        {
//            signal_pc_measure_set_reference(TempReference);
            memcpy(&TempReference_old,&TempReference,sizeof(ComTempReference));
        }
    }
}

void HpSetting::slot_lcd_ReOpen()
{
    if(lcd_offed)
    {
        qDebug("HpSetting::slot_lcd_ReOpen ....");
        signal_pc_sys_set_screen_sleep(0);
//        connect(&timer,SIGNAL(timeout()),this,SLOT(timer_func()));
        auto_lcdoff_value_changed(ui->listWidget_lcdoff->currentRow());
        ui->label_lcdoff->setText(ui->listWidget_lcdoff->currentItem()->text());
        lcd_offed = false;
        onlcdonce = true;
    }
}

void HpSetting::slot_set_lcd_offed_state()
{
    if(onlcdonce)
    {
        onlcdonce = false;
        return;
    }
    if(lcd_offed)
    {
        qDebug("lcd on....2");
        slot_lcd_ReOpen();
        return;
    }
}

//void HpSetting::on_checkBox_area_clicked(bool checked)    //area侧面积开关
//{
//    signal_update_lcdoff_time(false);
//    qDebug()<<"on_checkBox_area_clicked--------------------------------------------"<<checked;

//    if(checked)
//    {
//        signal_pc_image_set_abnormal(1);

// //        ui->checkBox_volcal->show();
// //        ui->checkBox_angel->show();
//    }
//    else
//    {
//        ui->checkBox_volume->setChecked(false);
//        hp_slot_checkBox_volcal_clicked(false);
//        signal_pc_image_set_abnormal(0);
//        ui->checkBox_angel->setChecked(false);
//        hp_slot_checkBox_angle_clicked(false);
//        ui->checkBox_volume->close();
//        ui->checkBox_angel->close();
//    }
//}
//void HpSetting::hp_slot_checkBox_volcal_clicked(bool checked)
//{
//    signal_checkBox_volcal_checked(checked);
//}
//void HpSetting::hp_slot_checkBox_angle_clicked(bool checked)
//{
//    signal_checkBox_angle_checked(checked);
//}
void HpSetting::on_comboBox_buchangwendu_valueChanged(double value)
{
    if(!unitconverting)
    {
        qDebug()<<"on_comboBox_buchangwendu_valueChanged-------------------------"<<value;

        if(value > -0.1 && value < 0.1)
        {
            value = 0;
            ui->comboBox_buchangwendu->setValue(0);
        }

        compensateValue = hptempunitconvert.getCTempValue(tempunit,value*100);

        signal_pc_measure_set_compensate(compensateValue);//PC_MEASURE_TEMPADJUST
        update();
    }
}

void HpSetting::slot_pc_measure_set_compensate(unsigned char return_value)
{
    qDebug("slot_pc_measure_set_compensate return_value:0x%02x",return_value);
}


void HpSetting::slot_pc_image_set_abnormal(unsigned char return_value)
{
//    qDebug("slot_pc_image_set_abnormal return_value:0x%02x",return_value);
}

void HpSetting::save_start_error_about_temp()
{
    signal_update_radTable_to_display(TempUserPara.RadTable_id, TempUserPara.RadTable_value100);
    signal_set_radTable_state(TempUserPara.RadTable_switch);
}
void HpSetting::slot_setWifiIsSelect(bool checked)
{
    wifiIsSelect = checked;
    if(checked)
    {
        ui->checkBox_autoUpload->setEnabled(true);
        if(!ui->checkBox_autoUpload->isCheckable())
            ui->checkBox_autoUpload->setCheckable(true);
    }else{
        if(ui->checkBox_autoUpload->isChecked())
        {
            emit ui->checkBox_autoUpload->clicked(false);
            ui->checkBox_autoUpload->setChecked(false);
        }
        if(ui->checkBox_autoUpload->isCheckable())
            ui->checkBox_autoUpload->setCheckable(false);
    }
}
void HpSetting::on_checkBox_area_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
//     qDebug()<<"on_checkBox_area_clicked--------------------------------------------"<<checked;
    if(checked)
    {
        signal_pc_image_set_abnormal(1);
    }
    else
    {
        signal_pc_image_set_abnormal(0);
    }
}

void HpSetting::on_checkBox_sr_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
    qDebug()<<"on_checkBox_sr_clicked--------------------------------------------"<<checked;
    if(checked)
    {
        if(ui->checkBox_panorama->isChecked())
        {

            ui->checkBox_panorama->setChecked(false);
            ui->checkBox_panorama->clicked(false);
        }

    }
    SignalSetImageSR(checked);
}

void HpSetting::on_checkBox_fid_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
    if(checked)
    {
        osdsetting.fid3100 =1;
    }
    else
    {
         osdsetting.fid3100 =0;
    }
    if(ui->checkBox_pid->isChecked())
    {
        osdsetting.pid3100 = 1;
    }else{
        osdsetting.pid3100 = 0;
    }
    signal_pc_osd_set_osdstat(osdsetting);
}

void HpSetting::on_checkBox_pid_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
    if(checked)
    {
        osdsetting.pid3100 =1;
    }
    else
    {
         osdsetting.pid3100 =0;
    }
    if(ui->checkBox_fid->isChecked())
    {
        osdsetting.fid3100 = 1;
    }else{
        osdsetting.fid3100 = 0;
    }
    signal_pc_osd_set_osdstat(osdsetting);
}

void HpSetting::on_listWidget_recordmode_currentRowChanged(int currentRow)
{
    signal_update_lcdoff_time(false);
    if( currentRow<0)
        return;
    ui->label_recordmode->setText( ui->listWidget_recordmode->currentItem()->text() );
//    QString str;
//    str = ui->label_recordmode->currentItem()->text();
//    ui->label_recordmode->setText(str);
    listwidget_drop_manage_recordmode(false);
    if(recordmode_init == true)
    {
        recordmode_init =false;
        return;
    }
    if(language_changing)
        return;
    qDebug()<<"xxxxxxxxxxxxxxxxxxxxxxxx" <<currentRow;
    if(currentRow==0)
    {
//        qDebug() << "XXXXXXX HpSetting::on_listWidget_recordmode_currentRowChanged";
        signal_avi_hir_mode(1);
    }
    else if(currentRow ==1)
    {
//        qDebug() << "XXXXXXX HpSetting::on_listWidget_recordmode_currentRowChanged";
        signal_avi_hir_mode(2);
    }else{};
}
void HpSetting::on_dengwengse_edit_released()
{
    signal_update_lcdoff_time(false);
    hpisotherm.show();
}

void HpSetting::on_ScrollBar_AmbientTempManu_valueChanged(double arg1)
{

}

void HpSetting::on_listWidget_modeSelect_currentRowChanged(int currentRow)
{
    if(currentRow < 0)
        return;

    ui->label_modeSelect->setText(ui->listWidget_modeSelect->currentItem()->text());
    listwidget_drop_manage_modeSelect(false);

    if(language_changing)
        return;
    if(currentRow == 0){            //常规模式
        isTaskMode = false;
        ui->checkBox_gw->setCheckable(true);
        ui->spinBox_autosave->setEnabled(true);
    } else if(currentRow == 1) {    //任务包模式
        if(guowangFlag || ui->checkBox_gw->isChecked())
        {
            guowangFlag = false;
            ui->checkBox_gw->setChecked(false);
            ui->checkBox_gw->clicked(false);
        }
        isTaskMode = true;
        ui->checkBox_gw->setCheckable(false);
        screensave_time = 7;
        SignalAutoSave(screensave_time);
        ui->spinBox_autosave->setEnabled(false);
        ui->spinBox_autosave->setValue(0);
    }
}

void HpSetting::slot_pc_sys_set_HDMI(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_HDMI return_value:0x%02x",return_value);
    update();//打开HDMI时调用界面刷新
}
void HpSetting::slot_hidemenu_ImageChange(bool isChecked)
{
//    QString para;
//    para = hpxmlreader.readXml("config.xml","LENSSET","lensid");//获取当前镜头号
//    if(para != NULL)
//        TempRange.LensId = para.toInt();

    if(isChecked)
    {
        TempRange.ImageRotate = 1;
    }else{
        TempRange.ImageRotate = 0;
    }

    signal_hidemenu_ImageChange(TempRange);
}
void HpSetting::hp_emitsignal_hidemenu_ImageChange()
{
//    signal_hidemenu_ImageChange(TempRange);
}

void HpSetting::yqsz_focusmode_current_index_changed(int currentRow)
{
    if( currentRow<0)
        return;
    qDebug() << ui->listWidget_focusmode->currentItem()->text();
    ui->label_focusmode->setText( ui->listWidget_focusmode->currentItem()->text() );
    listwidget_drop_manage_focusmode(false);
    if(language_changing)
        return;
    if(currentRow == 0)
    {
        fastfocusmode = false;
        signal_pc_sys_set_autofocusmode(0);
    }else if(currentRow == 1){
        fastfocusmode = true;
        signal_pc_sys_set_autofocusmode(1);
    }else if(currentRow == 2){
        fastfocusmode = false;
        signal_pc_sys_set_autofocusmode(2);
    }
}
void HpSetting::listwidget_drop_manage_focusmode(bool type)
{
    if(type == true)
    {
        listwidget_type = 12;
        ui->listWidget_focusmode->show();
    }else
    {
        listwidget_type =0;
        ui->listWidget_focusmode->close();
    }
}
void HpSetting::slot_get_wifi_inert()
{
    qDebug() << " HpSetting::slot_get_wifi_inert()";

    if(!isWifiInsert)
    {
        getWifiWait++;
        signal_core_get_usbwifiinsert();
        if(getWifiWait < 30)
            QTimer::singleShot(500, this, SLOT(slot_get_wifi_inert()));
    }
    if(!isWIFISearch)
    {
        signal_pc_sys_set_wifi_switch(1);
        signal_pc_sys_set_local_servrer(1);
    }
}

void HpSetting::slot_core_get_usbwifiinsert(unsigned char return_value, int uwi)
{
    qDebug() << "HpSetting::slot_core_get_usbwifiinsert" << return_value<<  "uwi" << uwi;
    if(return_value == RE_OK && uwi == 1)
    {
        isWifiInsert = true;
    }
}

void HpSetting::slot_pc_sys_set_wifi_power(unsigned char return_value)
{
    qDebug("slot_pc_sys_wifi_power return_value:0x%02x",return_value);
    if(ui->checkBox_wifi->isChecked())
    {
        getWifiWait = 0;
        slot_get_wifi_inert();
    }
}
void HpSetting::clot_close_sis_switch()
{
    qDebug()<<"clot_close_sis_switch";
    on_checkBox_sis_clicked(false);
    ui->checkBox_sis->setChecked(false);
}
void HpSetting::on_checkBox_sis_clicked(bool checked)//扫一扫开关
{
    SignalSetImageSIS(checked);
      //默认开启扫一扫，直接将hp_camera_cap.cpp的标志改变
}
void HpSetting::delaymsec(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < dieTime )

    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

int HpSetting::getAlarmTemp()
{
    return AlarmTemp.AlarmTemp100;
}

OsdSetting HpSetting::getOsdSetting()
{
    return osdsetting;
}

int HpSetting::getAlarmSwitch()
{
    return AlarmTemp.AlarmSwitch;
}

void HpSetting::on_checkBox_gw_clicked(bool checked)
{
    if(isTaskMode)
    {
        ui->checkBox_gw->setChecked(false);
        return;
    }
    if(checked)
    {
//        ui->listWidget_modeSelect->setEnabled(false);
        if(ui->checkBox_panorama->isChecked())
        {
            ui->checkBox_panorama->setChecked(false);
            ui->checkBox_panorama->clicked(false);
        }
        LimitAutoSave_SR_AutoUpload();
    }else{
        RelieveLimitAutoSave_SR_AutoUpload();
    }
    guowangFlag = checked;
    MainWidget *p = (MainWidget *)parentP;
    p->hpcameracap->isGuoWangFlag = guowangFlag;
    signal_stop_TextVoice(checked);
    signal_stop_AviMode(checked);
}

void HpSetting::on_checkBox_panorama_clicked(bool checked)
{
    if(checked)
    {
        panoramaFlag = true;
        if(guowangFlag || ui->checkBox_gw->isChecked())
        {
            guowangFlag = false;
            ui->checkBox_gw->setChecked(false);
            ui->checkBox_gw->clicked(false);
        }
        if(ui->checkBox_sr->isChecked())
        {
            LimitAutoSave_SR_AutoUpload();
        }
        if(ui->checkBox_Catch->isChecked())
        {
            ui->checkBox_Catch->setChecked(false);
            ui->checkBox_Catch->clicked(false);
        }
        if(ui->checkBox_ReferTemp_enable->isChecked())
        {
            ui->checkBox_ReferTemp_enable->setChecked(false);
            ui->checkBox_ReferTemp_enable->clicked(false);
        }
        signal_start_panorama(checked);
    }
    else
    {
        panoramaFlag = false;
        RelieveLimitAutoSave_SR_AutoUpload();
    }

}

void HpSetting::on_checkBox_zoomSave_clicked(bool checked)
{
    if(checked)
    {
        guowangFlag = false;
        if(ui->checkBox_gw->isChecked())
        {
            ui->checkBox_gw->click();
        }
        signal_set_picture_zoom_save(checked);
    }
    else
    {
        signal_set_picture_zoom_save(checked);
    }
}

void HpSetting::on_checkBox_bmp_clicked(bool checked)
{
    if(checked)
    {
        signal_set_image_format(1);
    }
    else
    {
        signal_set_image_format(0);
    }
}

void HpSetting::listwidget_drop_manage_imageType(bool type)
{
    qDebug() << "HpSetting::listwidget_drop_manage_imageType" << type;
    if(type == true)
    {

        listwidget_type = 13;
        ui->listWidget_imageType->show();
    }else
    {
        listwidget_type =0;
        ui->listWidget_imageType->close();
    }
}

void HpSetting::listwidget_drop_manage_reflectTemp(bool type)
{
    qDebug() << "HpSetting::listwidget_drop_manage_reflectTemp" << type;
    if(type == true)
    {

        listwidget_type = 14;
        ui->listWidget_ReflectTemp->show();
    }else
    {
        listwidget_type =0;
        ui->listWidget_ReflectTemp->close();
    }
}

void HpSetting::on_listWidget_imageType_currentRowChanged(int currentRow)
{
    qDebug() << "HpSetting::yqsz_imageType_current_index_changed" << currentRow;
    if( currentRow<0)
        return;
    qDebug() << "HpSetting::yqsz_imageType_current_index_changed" << currentRow;
    ui->label__imageType->setText( ui->listWidget_imageType->currentItem()->text() );
    listwidget_drop_manage_imageType(false);
    if(language_changing)
        return;
    signal_pc_image_set_imagetype(currentRow);
}
bool HpSetting::getPanoramaFlag()
{
    return panoramaFlag;
}

void HpSetting::set_ScrollBar_Distance(double distance)
{
    ui->ScrollBar_Distance->setValue(double(distance * 1.0));
    TempUserPara.Distance100 = (double(distance * 1.0) * 100);
    signal_pc_cfg_set_temp_userpara(TempUserPara);
}

void HpSetting::on_checkBox_oritoggle_clicked(bool checked)
{
    signal_core_fpgamenu_oritoggle(checked);
}

void HpSetting::on_checkBox_homogeneity_clicked(bool checked)
{
    signal_pc_sys_set_hidemenu(checked);
}


void HpSetting::on_checkBox_stepZero_clicked(bool checked)
{
    signal_pc_sys_set_step_zero(checked);
}

void HpSetting::slot_timeout_4G_state()
{
    qDebug() << "o0o0o0o0o0o0o -- > HpSetting::signal_get_4G_state";
    signal_get_4G_state();//获取4G状态
}

void HpSetting::slot_cancel4GConnect()//取消4G连接
{
    qDebug() << "HpSetting::slot_cancel4GConnect";
    if(m_timer_4G.remainingTime() < 10)
        qDebug() <<"4G timeout===========================>";
    state_Wait_4G->stop();
    m_timer_4G.stop();
    emit ui->checkBox_4G->clicked(false);
    state_4G->stop();
    ui->checkBox_4G->setChecked(false);
    hp_autoupload->set4Gstatu(false);
}

void HpSetting::slot_set_4G_state(unsigned char return_value)
{
    qDebug("o0o0o0o0o0o0o -- > HpSetting::slot_set_4G_state:%02x",return_value);
    if(return_value == 0)
        m_timer_4G.start(60000);
    canbercv = true;//只有接收到这个信号的时候，定时器的返回值才有效
}

void HpSetting::slot_get_4G_state(unsigned char return_value,int status)
{
    qDebug() << m_timer_4G.remainingTime();
    qDebug("o0o0o0o0o0o0o -- > HpSetting::slot_get_4G_state:%02x value == > %d",return_value,status);
    qDebug() << "o0o0o0o0o0o0o -- > HpSetting::slot_get_4G_state -- > " << canbercv << " state4G == > " << state4G;
    if(canbercv == false)
    {
        return;
    }
//    hpdialog->move((this->width() - hpdialog->width()) / 2,(this->height() - hpdialog->height()) / 2 - 5);
    if(status > 0)
    {   if(state4G == IS_ON_CONNECT || state4G == IS_ON_CONNECT_WAIT)//若处于正在连接状态
        {
            disconnect(&m_timer_4G, SIGNAL(timeout()), this, SLOT(slot_cancel4GConnect()));
            qDebug() << "HpSetting::slot_get_4G_state - (1) - > 4G connect success";
            state4G = IS_ON_CONNECT_OK;
            state_Wait_4G->stop();
            hp_Common_dialog_cancel->close();
            update();
            QApplication::processEvents();
            signal_set_4G_icon(true);//设置4G图标
            hpdialog->setText("4G " + hpblesearchold.fConnnectOK);
            hpdialog->setDelayClose(3000);
            hpdialog->show();

            if(!ui->checkBox_autoUpload->isCheckable())
                ui->checkBox_autoUpload->setCheckable(true);
            update();
            QApplication::processEvents();
            hp_autoupload->set4Gstatu(true);
        }
    }else{
        qDebug() << "slot_get_4G_state" << status << state4G;
        if(state4G == IS_ON_CONNECT_OK)
        {
//            if(hp_autoupload->isVisible())
//            {
//                if(hp_autoupload->hti.isVisible())
//                {
//                    hp_autoupload->hti.close();
//                }
//                if(hp_autoupload->hpdialog->isVisible())
//                {
//                    hp_autoupload->hpdialog->close();
//                }
//                hp_autoupload->close();
//            }
            if(this->isVisible())
            {
                hpdialog->setText("4G " + hpblesearchold.fDisConnnect);
                hpdialog->show();
            }else{
//                signal_set_Dialog("4G " + hpblesearchold.fDisConnnect,0);
            }
            slot_cancel4GConnect();
        }else if(state4G == IS_ON_CONNECT)
        {
            if(status == -1)
            {
//                qDebug() << "slot_get_4G_state==========2";
                if(!state_Wait_4G->isActive())
                {
//                    qDebug() << "/*slot_get_4G_state*/==========3";
                    state4G = IS_ON_CONNECT_WAIT;//当处于等待阶段时，不会对连接失败做判断
                    state_wait_4G_open = 0;
//                    hpdialog->Set_label_text("4G " + hpblesearchold.fNoModul);
                    hp_Common_dialog_cancel->Set_label_text("4G " + hpblesearchold.fModulInit);
                    hp_Common_dialog_cancel->Set_button_text(hpblesearchold.fcancel);
                    hp_Common_dialog_cancel->move((this->width() - hp_Common_dialog_cancel->width()) / 2,(this->height() - hp_Common_dialog_cancel->height()) / 2 - 5);
                    hp_Common_dialog_cancel->show();
                    hpdialog->close();
                    state_Wait_4G->start();
                }
            }else{
                if(status == -3)
                {
//                    hpdialog->Set_label_text("SIM " + hpblesearchold.fNoCard);
                    if(!state_Wait_4G->isActive())
                    {
                        state4G = IS_ON_CONNECT_WAIT;
                        state_wait_4G_open = 0;
                        hp_Common_dialog_cancel->Set_label_text("4G " + hpblesearchold.fModulInit);
                        hp_Common_dialog_cancel->Set_button_text(hpblesearchold.fcancel);
                        hp_Common_dialog_cancel->move((this->width() - hp_Common_dialog_cancel->width()) / 2,(this->height() - hp_Common_dialog_cancel->height()) / 2);
                        hp_Common_dialog_cancel->show();
                        hpdialog->close();

                        update();
                        QApplication::processEvents();
                        state_Wait_4G->start();
                    }
                }else{
//                    qDebug() << "slot_get_4G_state==========4";
                    hpdialog->setText("4G " + hpblesearchold.fConnnectfailed);
                    hpdialog->show();
                    update();
                    QApplication::processEvents();
                    slot_cancel4GConnect();
                }
            }
        }
    }
    //打印
    if(status == 1)
    {

    }else if(status == 0)
    {
        qDebug() << "HpSetting::slot_get_4G_state - (0) - > 4G is disconnect";
    }else if(status == -1)
    {
        qDebug() << "HpSetting::slot_get_4G_state - (-1) - > SIM modul is not find" << state_Wait_4G->isActive();
    }else if(status == -2)
    {
        qDebug() << "HpSetting::slot_get_4G_state - (-2) - > SIM modul is not work";
    }else if(status == -3)
    {
        qDebug() << "HpSetting::slot_get_4G_state - (-3) - > SIM card is not find";
    }else if(status == -4)
    {
        qDebug() << "HpSetting::slot_get_4G_state - (-4) - > SIM card data is not work";
    }else if(status == -5)
    {
        qDebug() << "HpSetting::slot_get_4G_state - (-5) - > SIM card 4G is not work";
    }else if(status == -6)
    {
        qDebug() << "HpSetting::slot_get_4G_state - (-6) - > SIM card can't get IP";
    }
}

void HpSetting::slot_timeout_4G_wait_state()
{
    qDebug() << "HpSetting::slot_timeout_4G_wait_state  == > " << state_wait_4G_open;
    state_wait_4G_open++;
    if(state_wait_4G_open < 12)//3分钟
    {
        signal_set_4G_state(1);
    }else{
        state4G = IS_ON_NONE;
        hpdialog->setText("4G " + hpblesearchold.fNoCard);
        hpdialog->show();
        hp_Common_dialog_cancel->close();
        update();
        QApplication::processEvents();
        state_Wait_4G->stop();
        slot_cancel4GConnect();
    }

}

void HpSetting::slot_measure_reflect_temp(int value)
{
    TempUserPara.ReflectTemp100 = value;
    signal_pc_cfg_set_temp_userpara(TempUserPara);
}

void HpSetting::on_listWidget_ReflectTemp_currentRowChanged(int currentRow)
{
    m_reflectType = currentRow;
    ui->listWidget_ReflectTemp->close();
    ui->label_ReflectTemp->setText(tr("反射类型：") + ui->listWidget_ReflectTemp->currentItem()->text());
}

void HpSetting::on_checkBox_sketch_clicked(bool checked)
{
    if(checked)
    {
        signal_sketch_switch(1);
        ui->sketch_edit->show();
    }
    else
    {
        signal_sketch_switch(0);
        ui->sketch_edit->close();
    }
}

void HpSetting::on_checkBox_eth_clicked(bool checked)
{
    if(checked)
    {
        if(ui->checkBox_wifi->isChecked())
        {
            ui->checkBox_wifi->setChecked(false);
            ui->wifi_edit->close();
            if(isWIFISearch)
            {
                hp_wifi_Search->slot_SetDisConnect();
            }else{
                signal_pc_sys_set_local_servrer(0);
                signal_pc_sys_set_wifi_switch(0);
                signal_pc_sys_set_wifi_power(0);
            }
        }
        if(ui->checkBox_4G->isChecked())
        {
            ui->checkBox_4G->setChecked(false);
            state4G = IS_ON_NONE;
            state_4G->stop();
            signal_set_4G_state(0);
            signal_set_4G_power(0);
        }
    }
    qDebug() << __func__ << "isInEth" << IsInEth;
    if(IsInEth == false)
    {
        IsInEth = true;
        if(checked)
        {
            eth_num = 1;
            signal_set_ETH_switch(1);
            delaymsec(1000);
            signal_pc_sys_set_local_servrer(1);
        }
        else
        {
            eth_num = -1;
            signal_pc_sys_set_local_servrer(0);
            signal_set_ETH_switch(0);
        }
    }
    else
    {
        if(checked == true)
        {
            if(eth_num == -1)
            {
                eth_change = true;
            }else
            {
                eth_change = false;
            }
        }else
        {
            if(eth_num == 1)
            {
                eth_change = true;
            }else
            {
                eth_change = false;
            }
        }
    }
}

void HpSetting::slot_pc_sys_set_ETH_switch(unsigned char return_value)
{
    IsInEth = false;
    if(eth_change == true)
    {
        eth_change = false;
        if(eth_num == 1)
        {
            eth_num = 0;
            emit ui->checkBox_eth->clicked(false);
        }else if(eth_num == -1)
        {
            eth_num = 0;
            emit ui->checkBox_eth->clicked(true);
        }
    }
    qDebug("slot_pc_sys_set_ETH_switch return_value:0x%02x",return_value);
}

void HpSetting::on_sketch_edit_clicked()
{
    if(listwidget_type !=0)      //表示有下拉框打开
    {
        listwidget_type_manage();
        return;
    }
    signal_pc_image_set_sketch_clear();
}

void HpSetting::on_checkBox_flip_clicked(bool checked)
{
    if(checked)
    {
        signal_pc_image_set_flip(1);
        signal_timer_get_rotation_switch(1);
    }
    else
    {
        signal_pc_image_set_flip(0);
        signal_timer_get_rotation_switch(0);
    }
}

void HpSetting::on_checkBox_transmission_clicked(bool checked)
{
    if(checked && ui->checkBox_ble->isChecked())
    {
        ui->checkBox_transmission->setChecked(false);
        return;
    }
    if(checked && ui->checkBox_ble->isChecked())
    {
        ui->checkBox_transmission->setChecked(false);
        return;
    }

    if(checked)
    {
        m_transmissionInit = false;
        ui->checkBox_ble->setEnabled(false);
        if(ui->checkBox_ble->isChecked())
        {
            ui->checkBox_ble->setChecked(false);
            ble_clicked(false);
            delaymsec(1000);
        }
        signal_pc_sys_set_ble_power(0);
        isTaskMode = true;
        ui->trmission_edit->show();
        m_transmissionSearch->show();
    }
    else
    {
        isTaskMode = false;
        ui->trmission_edit->close();
        m_transmissionInit = false;
        slot_transmission_stop();
    }
}

void HpSetting::on_checkBox_preset1_clicked(bool checked)
{
    if(ui->checkBox_preset2->isChecked())
    {
        ui->checkBox_preset2->setChecked(false);
    }
    if(checked)
    {
        signal_set_preset_mode(1);
    }
    else
    {
        signal_set_preset_mode(0);
    }
}

void HpSetting::on_checkBox_preset2_clicked(bool checked)
{
    if(ui->checkBox_preset1->isChecked())
    {
        ui->checkBox_preset1->setChecked(false);
    }
    if(checked)
    {
        signal_set_preset_mode(2);
    }
    else
    {
        signal_set_preset_mode(0);
    }
}

void HpSetting::slot_link_transmission(QString addr)
{
    m_transmissionIsSearch = false;
    signal_pc_sys_set_ble_power(0);
    slot_transmission_start();
}

void HpSetting::slot_start_get_bleInfo()
{
    m_transmissionIsSearch = true;
    hpdialog->setText(tr("蓝牙搜索中"));
    hpdialog->show();
    signal_pc_sys_set_ble_power(1);
//    delaymsec(3000);ble
//    m_transmissionSearch->slot_get_ble_msg(QString("io"));
}

void HpSetting::slot_stop_get_bleInfo(QString bleInfo)
{
    hpdialog->close();
}

void HpSetting::slot_transmission_start()
{
    hpdialog->setText(tr("蓝牙启动中"));
    hpdialog->show();
    QApplication::processEvents();
    delaymsec(50);
    if(!m_transmissionIsSearch)
    {
//        signal_pc_sys_set_ble_power(1);
        m_transmissionStart = true;
    }
    else
    {
        if(m_transmissionStart)
            return;
        m_transmissionIsSearch = false;
        m_Transmission->setBleMode(171);
        signal_start_transmission();
        m_transmissionStart = true;
    }
}

void HpSetting::slot_transmission_stop()
{
    signal_pc_sys_set_ble_power(0);
    ui->checkBox_ble->setEnabled(true);
    if(!m_transmissionStart  )
        return;

    m_transmissionStart = false;
    hpdialog->setText(tr("传输模式关闭中"));
    hpdialog->setDelayClose(10000);
    hpdialog->show();
    QApplication::processEvents();
    ui->trmission_edit->close();
    signal_stop_transmission();
    delaymsec(500);
}

void HpSetting::slot_set_dialog_close()
{
    qDebug() << " HpSetting::slot_set_dialog_close" << m_transmissionSearch->m_currMacAddr;
    if(m_transmissionSearch->m_currMacAddr.count() < 5)
    {
        return;
    }
    m_Transmission->slot_link_transmission(m_transmissionSearch->m_currMacAddr);
    hpdialog->setText(tr("连接成功"));
    hpdialog->setDelayClose(2000);
}

void HpSetting::slot_transmission_allow_upload()
{
    if(m_transmissionSearch->isVisible())
    {
        delaymsec(300);
        hpdialog->setText(hpblesearchold.fConnnectOK);
        hpdialog->show();
        hpdialog->setDelayClose(1000);

        update();
    }
}

void HpSetting::slot_transmission_send_heartbeat()
{
    if(m_transmissionSearch->isVisible())
    {
        hpdialog->setText(tr("发送连接"));
        hpdialog->show();
        hpdialog->setDelayClose(1000);

        update();
    }
}

void HpSetting::slot_transmission_get_download()
{
    hpdialog->setText(tr("接收完毕"));
    hpdialog->show();
    hpdialog->setDelayClose(1000);
    update();
}

void HpSetting::on_trmission_edit_clicked()
{
    m_transmissionSearch->show();
}

int HpSetting::getLensCount()
{
    return jingtou_num;
}

void HpSetting::slot_set_current_lens(int len)
{
    qDebug() << "ui->comboBox_jingtou->currentIndex()" << ui->comboBox_jingtou->currentIndex() << len;
    qDebug() << "ui->listWidget_jingtou->currentIndex()" << ui->listWidget_jingtou->currentRow() << len;
    if((len + 1 > ui->listWidget_jingtou->count()))
    {
        return;
    }
    if(len != ui->comboBox_jingtou->currentIndex())
    {
        ui->listWidget_jingtou->setCurrentRow(len);
//        on_listWidget_jingtou_currentRowChanged(len);
        on_pushButton_qiehuan_released();
    }
}

void HpSetting::setInitAlarmMsg()
{
    qDebug() << __func__ << AlarmTemp.AlarmSwitch << AlarmTemp.AlarmTemp100;
    signal_pc_image_set_alarm(AlarmTemp);
}

void HpSetting::slot_reset_ble_power()
{
//    hpblesearch.ble_off();
    delaymsec(500);
    signal_pc_sys_set_ble_switch(0);
    delaymsec(200);
    signal_pc_sys_set_ble_module(0);
    delaymsec(800);
    signal_pc_sys_set_ble_module(1);//（0-关闭 1-指令模式 2-传输模式）
    delaymsec(30);
    signal_pc_sys_set_ble_switch(1);
}
