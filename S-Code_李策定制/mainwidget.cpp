#include  "mainwidget.h"
#include  "hp_button.h"

#include  "ui_mainwidget.h"
#include  "ui_hpsetting.h"
#include  "ui_hpmode.h"
#include  "ui_hpsebiao.h"
#include  "ui_hpresize.h"
#include  "ui_hpcpumem.h"
#include  "ui_hphidemenu.h"
#include  "frminput.h"

#include  "hi384_protocol.h"
#include  <QFile>
#include  <QDir>
#include  <QDebug>
#include  <QList>
#include  <sys/stat.h>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    ui->widget_laser->setVisible(false);
    hpmode.ui->frame_handfution->setVisible(hpmode.ui->toolButton_handfusion->isChecked());

    Task_win = 0;
    m_isInitBiaoding = false;
    m_keyORelease = false;
    laserAdjust = false;
    get_sd_count = 0;
    wifi_insert_first = 1;
    avi_hir_mode = 1;
    autocretify_time = 0;
    panorama_quit = true;
    main_task_open = false;
    onlcdonce = false;
    m_isPanorama = false;
    con_flag = false;
    m_pmsUploadFlag = true;
    autocretify_time = 0;
    m_currLens = 0;
    autocretify_settime = 0;
    autocretify_pretime = 0;
    m_lensCount = 0;
    rot_type_state = false;
    trans_num=0;
    autoSaveShowTimer = -1;
    hidemenu_laser = false;
    m_isShowAvg = false;
    m_isAimTemp = false;
    hpsetting.parentP = this;//赋值父类指针
    consercutiveLaser = false;
    get_tagRectTemp = new QTimer();
    get_tagRectTemp->setInterval(1000);
    connect(get_tagRectTemp,SIGNAL(timeout()),this,SLOT(slot_get_tagRectTemp_timeout()));

    get_tagRectTemp->stop();
    tagTempAlarm = new QTimer();
    tagTempAlarm->setInterval(1000);
    connect(tagTempAlarm,SIGNAL(timeout()),this,SLOT(slot_tagTempAlarm_timeout()));
    tagTempAlarm->stop();
    battery_warn =true;             //电池电量提醒
    pic_swich_save = false;
    main_auto_focus = true;
    isAutoSave = false;
    isUSBPreviewLimit= false;
    appcon_state =false; //app连接状态
    m_pmsWidgetOpenFlag = false;

    m_hirRecordStarted = false;
    wait_warn = false;
    wait_warn_state = false;

    //预览模式下文字注释显示状态
    twice_text_state = false;
    text_label_show = false;
    OutsisToTask = false;
    sebiaoReverse = false;
//    sisToTask = false;
    //快捷键
    ctrl_ok =false;
    //预览界面是否打开
    preview_open =false;
    preview_state = false;
    usb_uart_insert =true;
    twice_analysis_cut_pic =false;
    isTwiceChangeOver = false;
    Twice_analysis=false;
    hir_analyse = false;
    fidpid = false;
    define_brightmode = false;
    define_sis = false;
    getRangeOnce = false;
    temp_mode = -1;

    isHcf = false;
    IsInlcdoff = false;
    qrcode =false;
    twice_analysis_start = false;

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hpcameracap = new Hp_Camera_Cap(this);
    hpcameracap->VoiceStatus =false;
    hpcameracap->cancelflag = false;
    hpcameracap->cap_state = false;
    hpcameracap->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hta = new Hp_Twice_Analysis(this);
    hta->close();

    hp_createPdf = new Hp_CreatePDF(this);
    hp_createPdf->close();
    m_laserType == 1;

    ui->compass->close();
    ui->checkBox_polygon->close();
    ui->compass->setPixmap(":/res/res/N-1.png");
    ui->compass->index1=0;
    ui->compass->index2=0;
    ui->compass->angle=0;
    compass_state = false;
    m_isAutoReflect = false;
    connect(&timer_compass,SIGNAL(timeout()),this,SLOT(slot_timer_get_compass_data()));
    formatDialog.close();
    m_latestVideoName.clear();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hppreview = new HpPreview(this);
    hppreview->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    SDFormatDialog = new Hp_Dialog(this);
    SDFormatDialog->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hssw = new Hp_Sd_Space_Warning(this);
    hssw->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hp_Wifi_search_Dialog = new Hp_Wifi_search_Dialog(this);
    hp_Wifi_search_Dialog->close();

    hp_dialog = new Hp_Dialog(this);
    hp_dialog->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    pictureModeObject = new hp_picture_mode(this);
    pictureModeObject->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hp_panorama = new Hp_Panorama(this);
    hp_panorama->setGeometry(160, 0, 640, 480);
    hp_panorama->close();
    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    avi_record_get_SDInfo = new QTimer();
    avi_record_get_SDInfo->setInterval(500);

    ContinuedFreezeTimer = new QTimer();
    ContinuedFreezeTimer->setInterval(20);
    timer_10s = new QTimer();
//    timer_10s->setInterval(10000);
    timer_10s->stop();
    timerConsercutiveLaser = new QTimer();
    timerConsercutiveLaser->stop();
    timer_5min = new QTimer();
    timer_5min->stop();
    kjgToAutoRecirft = new QTimer();
    kjgToAutoRecirft->setInterval(1000);//每三分钟触发一次

    settingToAutoRecirft = new QTimer();
    settingToAutoRecirft->setInterval(1000);

    previewToAutoRecirft = new QTimer();
    previewToAutoRecirft->setInterval(1000);

    AutoUpdateGetStatus = new QTimer();
    AutoUpdateGetStatus->setInterval(20000);

    timer_jingtou = new QTimer();
    timer_jingtou->setInterval(3000);
    timer_jingtou->stop();
    connect(timer_jingtou, SIGNAL(timeout()), this, SLOT(slot_timerout_jingtou_change()));
    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hpsis_content = new hp_sis_content(this);
    hpsis_content->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hp_Pms = new hp_pms();
    hp_Pms->close();
    hpcameracap->setIsPmsMode(false);

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    ui->frame_task_2->close();
    ui->frame_task_3->close();
    ui->frame_task_4->close();
    ui->label_tempAvg->close();
    ui->last_page->close();
    ui->next_page->close();
    ui->label_alarm->close();
    ui->focus_near->close();
    ui->focus_far->close();
    ui->label_focus->close();
    ui->checkBox_polygon->close();
    ui->pushButton_confirm->close();
    ui->label_laserRange->close();
    ui->label_focusWarning->close();
    ui->listWidget_jingtou->close();
    ui->label_focus->setGeometry(288,220,65,40);

    ui->toolButton_pause->setGeometry(1,401,158,79);
    ui->toolButton_pause->close();

    ui->label->setGeometry(65,361,375,60);
    ui->label->close();
    ui->label_2->setGeometry(65,391,375,60);
    ui->label_2->close();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    Hp_TaskPkg::getInstance()->Move_MessageBox(100,0);

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hpmode.installEventFilter(this);
    hpsebiao.installEventFilter(this);
    hpresize.installEventFilter(this);
    hppreview->installEventFilter(this);
    hppreview->hmp.installEventFilter(this);
    hppreview->hmp2.installEventFilter(this);
    ui->toolButton_max->installEventFilter(this);
    ui->toolButton_min->installEventFilter(this);

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hppreview->hhp.installEventFilter(this);
    hpcameravideo.installEventFilter(this);
    hpadjustcmd.installEventFilter(this);
    hpsetting.installEventFilter(this);
    hpsetting.hpblesearch.installEventFilter(this);
    hpsetting.hpblesearchold.installEventFilter(this);
//    hpsetting.hp_autoupload_dialog->installEventFilter(this);

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }
    for(int i = 0;i < 10;i++)
    {
        QString para = hpxmlreader.XmlInit_read("sys.xml","MODULE","S3X0");
        if(para != NULL)
        {
            if(para.toInt() == 2)
                Hp_TaskPkg::getInstance()->taskPkg_init(SCREEN_480_272);
            else
                Hp_TaskPkg::getInstance()->taskPkg_init(SCREEN_800_480);
        }

    }

    Hp_TaskPkg::getInstance()->hp_InstallEventFilter(this);

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hpmodehzhadjust.installEventFilter(this);
    hpmoderdjadjust.installEventFilter(this);

    hmp.installEventFilter(this);
    hta->installEventFilter(this);

    ui->display->hpdeledit.installEventFilter(this);
    ui->display->hpplredit->installEventFilter(this);

    start_capture = false;
    start_record = false;
    laser_on = false;
    laser_init= false;
    main_task_ble = false;
    main_task_headset = false;
    main_task_sd = false;
    main_task_usb = false;
    main_task_wifi = false;

    main_task_eth = false;
    main_task_battery_charge = false;
    main_task_wifi_insert = false;
    autoupload_once = false;

    hp_power_w.battery_warn_state = false;
    mode_kjg=false;
    last_botton_state=false;
    next_botton_state=false;
    setting_open_state=false;

    sd_space_enough = false;
    m_imageFormat = 0;

    adjust_cmd_show_flag = false;
    printscreen_checked = false;

    sd_format = false;
    auto_state = false;

    isLasertype = false;

    m_laserRange = 0;
    m_laserRangeTimer = 0;

    hppreview->avi_bad_name=" ";
    hppreview->hir_bad_name=" ";

    //这些都是声明，信号槽函数链接时，传输的不是系统定义的数据类型，而是自己定义的类型时，就需要声明
    qRegisterMetaType<FPGAMenuPara>("FPGAMenuPara");
    qRegisterMetaType<StandardInfo>("StandardInfo");
    qRegisterMetaType<sdinfo_t>("sdinfo_t");
    qRegisterMetaType<ComManualPara>("ComManualPara");
    qRegisterMetaType<OsdSetting>("OsdSetting");
    qRegisterMetaType<MeasureArrayState *>("MeasureArrayState *");
    qRegisterMetaType<ComPointPara>("ComPointPara");
    qRegisterMetaType<ComLinePara>("ComLinePara");
    qRegisterMetaType<ComRectPara>("ComRectPara");
    qRegisterMetaType<ComCirclePara>("ComCirclePara");
    qRegisterMetaType<ComPolygonPara>("ComPolygonPara");
    qRegisterMetaType<MeasureArray>("MeasureArray");
    qRegisterMetaType<ComIsothermTemp>("ComIsothermTemp");
    qRegisterMetaType<BleState>("BleState");
    qRegisterMetaType<RectTemp>("RectTemp");
    qRegisterMetaType<ComHideMenuPara>("ComHideMenuPara");
    qRegisterMetaType<FPGAMenuGray>("FPGAMenuGray");

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }


    hp_sorts = new HpSort();
    hp_sorts->startSort();

    hpdomainthread = new HpDomainThread(this);
    hpdomainthread->setDomainName("/tmp/sock");
    hpdomainthread->startDomain();

    sd_hpdomain = new HpDomainThread(this);
    sd_hpdomain->setDomainName("/tmp/sock_msg");
    sd_hpdomain->startDomain();
    isBlePowerOn = false;
    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    connect(&timer_3s,SIGNAL(timeout()),this,SLOT(timer_3s_func()));
    connect(&timerGetBiaodingPara,SIGNAL(timeout()),this,SLOT(slot_get_biaoding()));
    connect(&timer_500ms,SIGNAL(timeout()),this,SLOT(slot_timer_500ms()));
    connect(&timer_get_rotation_type,SIGNAL(timeout()),this,SLOT(slot_timer_get_rotation_type()));
    ui->label_autosave->close();

    connect(hpsetting.ui->checkBox_wifi,SIGNAL(clicked(bool)),this,SLOT(slot_hpsetting_wifi(bool)));
    connect(hpsetting.ui->checkBox_eth,SIGNAL(clicked(bool)),this,SLOT(slot_hpsetting_eth(bool)));
    connect(hpsetting.ui->checkBox_ble,SIGNAL(clicked(bool)),this,SLOT(slot_hpsetting_ble(bool)));
    connect(&hpsetting,SIGNAL(signal_pc_image_set_imagetype(int)),hpdomainthread,SLOT(slot_pc_image_set_imagetype(int)));
    connect(&hpsetting,SIGNAL(signal_core_fpgamunu_noncool_correct(int)),hpdomainthread,SLOT(slot_core_fpgamunu_noncool_correct(int)));
    connect(&hpsetting,SIGNAL(signal_noncool_unenable_plr(bool)),this,SLOT(slot_noncool_unenable_plr(bool)));
    connect(hpdomainthread,SIGNAL(signal_pc_image_set_imagetype(unsigned char)),&hpsetting,SLOT(slot_pc_image_set_imacgetype(unsigned char)));
    ui->point->set_hp_button_status_image_select(":/res/res/point_s.png");
    ui->point->set_hp_button_status_image_normal(":/res/res/point_n.png");
    ui->point->set_hp_button_status_image_disable(":/res/res/point_d.png");
    ui->point->set_hp_button_checked_enable(true);

    ui->line->set_hp_button_status_image_select(":/res/res/line_s.png");
    ui->line->set_hp_button_status_image_normal(":/res/res/line_n.png");
    ui->line->set_hp_button_status_image_disable(":/res/res/line_d.png");
    ui->line->set_hp_button_checked_enable(true);

    ui->rect->set_hp_button_status_image_select(":/res/res/rect_s.png");
    ui->rect->set_hp_button_status_image_normal(":/res/res/rect_n.png");
    ui->rect->set_hp_button_status_image_disable(":/res/res/rect_d.png");
    ui->rect->set_hp_button_checked_enable(true);

    ui->circle->set_hp_button_status_image_select(":/res/res/circle_s.png");
    ui->circle->set_hp_button_status_image_normal(":/res/res/circle_n.png");
    ui->circle->set_hp_button_status_image_disable(":/res/res/circle_d.png");
    ui->circle->set_hp_button_checked_enable(true);
    ui->circle->close();

    ui->polygon->set_hp_button_status_image_select(":/res/res/polygon_s.png");
    ui->polygon->set_hp_button_status_image_normal(":/res/res/polygon_n.png");
    ui->polygon->set_hp_button_status_image_disable(":/res/res/polygon_d.png");
    ui->polygon->set_hp_button_checked_enable(true);
    ui->polygon->close();

    ui->preview->set_hp_button_status_image_select(":/res/res/preview_s.png");
    ui->preview->set_hp_button_status_image_normal(":/res/res/preview_n.png");
    ui->preview->set_hp_button_status_image_disable(":/res/res/preview_d.png");
    ui->preview->set_hp_button_checked_enable(true);

    ui->setting->set_hp_button_status_image_select(":/res/res/shezhi_s.png");
    ui->setting->set_hp_button_status_image_normal(":/res/res/shezhi_n.png");
    ui->setting->set_hp_button_status_image_disable(":/res/res/shezhi_d.png");
    ui->setting->set_hp_button_checked_enable(false);

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    //改变灯光功能为点击功能   b
    if(define_brightmode){      //如果存在点击功能，记得把图标放到相应位置
        ui->bright_mode->set_hp_button_status_image_select(":/res/res/focus_s.png");
        ui->bright_mode->set_hp_button_status_image_normal(":/res/res/focus_n.png");
        ui->bright_mode->set_hp_button_status_image_disable(":/res/res/focus_d.png");       //mf图标
        ui->bright_mode->set_hp_button_checked_enable(true);
    }else{
        ui->bright_mode->set_hp_button_status_image_select(":/res/res/bright_night.png");
        ui->bright_mode->set_hp_button_status_image_normal(":/res/res/bright_day.png");
        ui->bright_mode->set_hp_button_status_image_disable(":/res/res/bright_day.png");       //mf图标
        ui->bright_mode->set_hp_button_checked_enable(true);
    }


    focus_state = S_NORMAL;
    ui->clean->set_hp_button_status_image_select(":/res/res/clean_s.png");
    ui->clean->set_hp_button_status_image_normal(":/res/res/clean_n.png");
    ui->clean->set_hp_button_status_image_disable(":/res/res/clean_d.png");
    ui->clean->set_hp_button_checked_enable(false);

    ui->mode->set_hp_button_status_image_select(":/res/res/mode_s.png");
    ui->mode->set_hp_button_status_image_normal(":/res/res/mode_n.png");
    ui->mode->set_hp_button_status_image_disable(":/res/res/mode_d.png");
    ui->mode->set_hp_button_checked_enable(true);

    ui->resize->set_hp_button_status_image_select(":/res/res/resize_s.png");
    ui->resize->set_hp_button_status_image_normal(":/res/res/resize_n.png");
    ui->resize->set_hp_button_status_image_disable(":/res/res/resize_d.png");
    ui->resize->set_hp_button_checked_enable(true);

    ui->sebiao->set_hp_button_status_image_select(":/res/res/sebiao_s.png");
    ui->sebiao->set_hp_button_status_image_normal(":/res/res/sebiao_n.png");
    ui->sebiao->set_hp_button_status_image_disable(":/res/res/sebiao_d.png");
    ui->sebiao->set_hp_button_checked_enable(true);

//    connect(ui->sebiao,SIGNAL(clicked(HP_BUTTON_STATUS)),this,SLOT(on_sebiao_click(HP_BUTTON_STATUS)));//这里是不是少加了ed？？？
//    connect(ui->resize,SIGNAL(clicked(HP_BUTTON_STATUS)),this,SLOT(on_resize_click(HP_BUTTON_STATUS)));
//    connect(ui->mode,SIGNAL(clicked(HP_BUTTON_STATUS)),this,SLOT(on_mode_click(HP_BUTTON_STATUS)));
//    connect(ui->clean,SIGNAL(clicked(HP_BUTTON_STATUS)),this,SLOT(on_clean_click(HP_BUTTON_STATUS)));
//    connect(ui->bright_mode,SIGNAL(clicked(HP_BUTTON_STATUS)),this,SLOT(on_bright_mode_click(HP_BUTTON_STATUS)));
//    connect(ui->setting,SIGNAL(clicked(HP_BUTTON_STATUS)),this,SLOT(on_setting_click(HP_BUTTON_STATUS)));
//    connect(ui->preview,SIGNAL(clicked(HP_BUTTON_STATUS)),this,SLOT(on_preview_click(HP_BUTTON_STATUS)));
//    connect(ui->rect,SIGNAL(clicked(HP_BUTTON_STATUS)),this,SLOT(on_rect_click(HP_BUTTON_STATUS)));
//    connect(ui->line,SIGNAL(clicked(HP_BUTTON_STATUS)),this,SLOT(on_line_click(HP_BUTTON_STATUS)));
//    connect(ui->point,SIGNAL(clicked(HP_BUTTON_STATUS)),this,SLOT(on_point_click(HP_BUTTON_STATUS)));

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    connect(this,SIGNAL(signal_pc_image_get_manual()),hpdomainthread,SLOT(slot_pc_image_get_manual()));
    connect(hpdomainthread,SIGNAL(signal_pc_image_get_manual(unsigned char,ComManualPara)),this,SLOT(slot_pc_image_get_manual(unsigned char,ComManualPara)));

    connect(this,SIGNAL(signal_pc_image_set_manual(ComManualPara)),hpdomainthread,SLOT(slot_pc_image_set_manual(ComManualPara)));
    connect(hpdomainthread,SIGNAL(signal_pc_image_set_manual(unsigned char)),this,SLOT(slot_pc_image_set_manual(unsigned char)));

    connect(this,SIGNAL(signal_sd_put_out_cap()),hpcameracap,SLOT(slot_camera_cap_cannal())); //send to camera_cap_cannal

    connect(&hppreview->hp_text_input,SIGNAL(signalTask()),hppreview,SLOT(slot_Show_TaskPic()));

    connect(&formatDialog,SIGNAL(signal_sd_formatting()),this,SLOT(slot_delete_new_video()));

    QString mode;
    mode = hpxmlreader.readXml("sys.xml","IMAGEMODE","content");

    video_mode = mode.toInt();

    if(video_mode <0 || video_mode >4)
        video_mode = 0;

    if(video_mode == 0)
    {
        ui->resize->set_hp_button_status(S_NORMAL);
    }
    else
    {
        ui->resize->set_hp_button_status(S_DISABLE);
    }
    if(define_brightmode)
    {
        if( video_mode == 1 )
        {
            ui->bright_mode->set_hp_button_status(S_DISABLE);
        }
        else
        {
            ui->bright_mode->set_hp_button_status(S_NORMAL);
        }
    }

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    video_mode_hp = video_mode;
    hpmode.set_mode(video_mode);

    //PIP  画中画模式参数
    QString pp;
    pp = hpxmlreader.readXml("sys.xml","PIPPARA","start_x");
    pippara.nPIP_X = pp.toInt();

    pp = hpxmlreader.readXml("sys.xml","PIPPARA","start_y");
    pippara.nPIP_Y = pp.toInt();

    pp = hpxmlreader.readXml("sys.xml","PIPPARA","width");
    pippara.nPIP_W = pp.toInt();

    pp = hpxmlreader.readXml("sys.xml","PIPPARA","height");
    pippara.nPIP_H = pp.toInt();

    pp = hpxmlreader.readXml("sys.xml","PIPPARA","rate100");
    pippara.nPIP_RATE100 = pp.toInt();
    switch(pippara.nPIP_RATE100)
    {
    case 25:
        hpmode.ui->toolButton_1_4->setChecked(true);
        break;
    case 50:
        hpmode.ui->toolButton_1_2->setChecked(true);
        break;
    case 75:
        hpmode.ui->toolButton_3_4->setChecked(true);
        break;
    case 100:
        hpmode.ui->toolButton_auto->setChecked(true);
        break;
    default:
        hpmode.ui->toolButton_auto->setChecked(true);
        break;
    }

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    QString fp;
    fp = hpxmlreader.readXml("sys.xml","FUSIONPARA","type");
    fusionpara.nFusionType = fp.toInt();

    fp = hpxmlreader.readXml("sys.xml","FUSIONPARA","high100");
    fusionpara.nFusionAmongHighTemp100 = fp.toInt();

    fp = hpxmlreader.readXml("sys.xml","FUSIONPARA","low100");
    fusionpara.nFusionAmongLowTemp100 = fp.toInt();

    fp = hpxmlreader.readXml("sys.xml","FUSIONPARA","above100");
    fusionpara.nFusionAboveTemp100 = fp.toInt();

    fp = hpxmlreader.readXml("sys.xml","FUSIONPARA","below100");
    fusionpara.nFusionBelowTemp100 = fp.toInt();
//    qDebug("fusionpara %d",fusionpara.nFusionType);

    QString para_2;
    para_2 = hpxmlreader.readXml("sys.xml","USBTYPE","type");
    if(para_2 != NULL)        //界面USB模式初始化
    {
         usb_mode = para_2.toInt();
    }
    else
    {
         usb_mode = 1;
    }
    //激光位置初始化
    QString para_3;
    para_3 = hpxmlreader.readXml("sys.xml","LASERPOS","x");
    qDebug() << ">>>>>>> LASERPOS = X = > " << para_3.toInt();
    if(para_3 != NULL)        //界面USB模式初始化
    {
         ui->widget_laser->move(para_3.toInt(),218);
    }
    else
    {
        ui->widget_laser->move(300,218);
    }
    para_3 = hpxmlreader.readXml("sys.xml","LASERPOS","y");
    qDebug() << ">>>>>>> LASERPOS = Y = > " << para_3.toInt();
    if(para_3 != NULL)        //界面USB模式初始化
    {
        ui->widget_laser->move(ui->widget_laser->x(),para_3.toInt());
    }
    else
    {
        ui->widget_laser->move(ui->widget_laser->x(),218);
    }
    for(int i = 1; i < 5; i++)
    {
        QString f_namex = "X" + QString::number(i);
        QString f_namey = "Y" + QString::number(i);
        QString para;
        qDebug() << "QString f_namex = + QString::number(i);";
        para = hpxmlreader.readXml("qtconfig.xml","LASER_OFFSET",f_namex);
        if(!para.isNull())
        {
            laserParaX.append(para.toDouble());
            qDebug() << f_namex << para;
        }
        else
            laserParaX.append(0);
        para = hpxmlreader.readXml("qtconfig.xml","LASER_OFFSET",f_namey);
        if(!para.isNull())
        {
            laserParaY.append(para.toDouble());
            qDebug() << f_namey << para;
        }
        else
            laserParaY.append(0);
    }

    for(int i = 1; i < 5; i++)
    {
        QString f_namex = "X" + QString::number(i);
        QString f_namey = "Y" + QString::number(i);
        QString para;
        qDebug() << "QString f_namex = + QString::number(i);";
        para = hpxmlreader.readXml("qtconfig.xml","LASER_OFFSET_IR",f_namex);
        if(!para.isNull())
        {
            laserParaX_IR.append(para.toDouble());
        }
        else
            laserParaX_IR.append(0);
        para = hpxmlreader.readXml("qtconfig.xml","LASER_OFFSET_IR",f_namey);
        if(!para.isNull())
        {
            laserParaY_IR.append(para.toDouble());
        }
        else
            laserParaY_IR.append(0);
    }

    qDebug() << ">>>>>>> LASERPOS = (X,Y) = > " << ui->widget_laser->pos();

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    QString fstr;
    fstr = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    hp_panorama->set_language(fstr.toInt());
    if(fstr !=NULL)
    {
        if(fstr.toInt() == 0)
        {
            fSDHasNoSpace = "存储空间不够";
            fErrReInsert = "SD卡错误，请重新插入";
            fkjgNotQuit = "可见光模式不可退出二次分析";
            fHSENotQuit = "HSE模式不可退出二次分析";
            fNoSD = "SD卡没有插入";
            fError = "出错了";
            fautoStopVideo="空间已满，录像已自动保存";
            fNoTaskpic="未找到图片";
            fSisIsNotOpen = "扫一扫功能未打开";
            fvideoError = "视频错误是否删除";
        }
        else if(fstr.toInt() == 1)
        {
            fSDHasNoSpace = "存儲空間不夠";
            fErrReInsert = "SD卡错误，请重新插入";
            fkjgNotQuit = "可見光模式不可退出二次分析";
            fHSENotQuit = "HSE模式不可退出二次分析";
            fNoSD = "SD卡沒有插入";
            fError = "出錯了";
            fautoStopVideo="空間已滿，錄影已自動保存";
            fNoTaskpic="未找到影像";
            fSisIsNotOpen = "掃一掃功能未打開";
            fvideoError = "視頻錯誤是否删除";
        }
        else if(fstr.toInt() == 2)//english
        {
            fSDHasNoSpace = "No enough memory";
            fErrReInsert = "SD card error, please reinsert";
            fkjgNotQuit = "Visible mode can't exit analysis";
            fHSENotQuit = "HSE mode can't exit analysis";
            fNoSD = "SD not insert";
            fError = "Error";
            fautoStopVideo="Space is full,video has been saved";
            fNoTaskpic="Image not found";
            fSisIsNotOpen = "Scan is not opened";
            fvideoError = "Are video errors deleted";
        }
        else if(fstr.toInt() == 3)//俄语
        {
            fSDHasNoSpace = "Мало памяти!";
            fErrReInsert = "Ошибка SD-карты, пожалуйста, вставьте заново";
            fkjgNotQuit = "Невозм. выполнить в этом режиме!";
            fHSENotQuit = "Невозм запустить видимый режим HSE";
            fNoSD = "нет карты SD";
            fError = "Ошибка";
            fautoStopVideo="пространство заполнено,видео сохранено";
            fNoTaskpic="Изображения не найдены";
            fSisIsNotOpen = "подметать не открывая";
            fvideoError = "Удалены ли видеоошибки";
        }
        else if(fstr.toInt() == 4)//匈牙利语
        {
            fSDHasNoSpace = "nincs elég memóriakapacitás";
            fErrReInsert = "SD kártya hiba, kérlek, tess be újra";
            fkjgNotQuit = "Másodlagos elemzés fényképmódban nincs";
            fHSENotQuit = "A látható fény nem érhető el HSE üzemmódban";
            fNoSD = "nincs SD";
            fError = "Hiba";
            fautoStopVideo="A hely tele van, és a videó mentésre került";
            fNoTaskpic="A kép nem található";
            fSisIsNotOpen = "A beolvasás nincs megnyitva";
            fvideoError = "A videohibák törlése";
        }
        else if(fstr.toInt() == 5)//西班牙语
        {
            fSDHasNoSpace = "Tarjeta SD Llena";
            fErrReInsert = "Error de la tarjeta SD, por favor vuelve a insertar";
            fkjgNotQuit = "Luz Visible Fuera del Análisis Secundario";
            fHSENotQuit = "El modo HSE no puede emitir luz visible";
            fNoSD = "Isertar SD";
            fError = "Error";
            fautoStopVideo="Espacio completo,grabación de vídeo guardada";
            fNoTaskpic="Imagen no encontrada";
            fSisIsNotOpen = "Barrido sin abrir";
            fvideoError = "Si se elimina el error de vídeo";
        }
    }

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    connect(&hpsetting, SIGNAL(signal_TaskStart()), this, SLOT(slot_task_start()));//开始分析
    connect(this, SIGNAL(signal_sort_add_new_file(QString)), hp_sorts, SLOT(addNewFile(QString)));
    connect(hpcameracap, SIGNAL(signal_sort_add_new_file(QString)), hp_sorts, SLOT(addNewFile(QString)));

    connect(hp_panorama, SIGNAL(signal_sent_press_pos_to_display(QMouseEvent*)), ui->display,   SLOT(slot_sent_press_pos_to_display(QMouseEvent*)));
    connect(hp_panorama, SIGNAL(signal_sent_release_pos_to_display(QMouseEvent*)), ui->display, SLOT(slot_sent_release_pos_to_display(QMouseEvent*)));
    connect(&panorama_dialog, SIGNAL(signal_panorama_start()), this, SLOT(slot_cap_camera_panorama()));
    connect(&panorama_dialog, SIGNAL(signal_panorama_stop()), this, SLOT(slot_cap_camera_stop()));
    connect(&hpsetting, SIGNAL(signal_start_panorama()), this, SLOT(slot_start_panorama()));
    connect(hp_panorama, SIGNAL(signal_close_panorama(bool)), this, SLOT(slot_close_panorama(bool)));
    connect(hpcameracap,SIGNAL(signal_cam_key_capture_stop(unsigned char,QString)),hp_panorama,SLOT(slot_core_key_capture_stop(unsigned char,QString)));

    connect(this, SIGNAL(signal_pc_sys_set_panorama_start(int)), hpdomainthread, SLOT(slot_pc_sys_set_panorama_start(int)));
    connect(hp_panorama, SIGNAL(signal_pc_sys_get_matching_degree(int)), hpdomainthread, SLOT(slot_pc_sys_get_matching_degree(int)));
    connect(hpdomainthread, SIGNAL(signal_pc_sys_get_match_degree(unsigned char, int)), hp_panorama, SLOT(slot_pc_sys_get_matching_degree(unsigned char, int)));
    connect(this, SIGNAL(signal_pc_sys_get_matching_degree(int)), hpdomainthread, SLOT(slot_pc_sys_get_matching_degree(int)));
    connect(this, SIGNAL(signal_pc_sys_set_panorama_stop(int)), hpdomainthread, SLOT(slot_pc_sys_set_panorama_stop(int)));
    connect(hp_panorama, SIGNAL(signal_pc_sys_set_panorama_stop(int)), hpdomainthread, SLOT(slot_pc_sys_set_panorama_stop(int)));
    connect(hpdomainthread, SIGNAL(signal_pc_sys_set_panorama_stop(unsigned char, QString)), this, SLOT(slot_pc_sys_set_panorama_stop(unsigned char, QString)));
    connect(hp_panorama, SIGNAL(signal_panorama_set_unsave(QString)), this, SLOT(slot_panorama_set_unsave(QString)));
    connect(hp_panorama, SIGNAL(signal_check_panorama_photo(bool)), this, SLOT(slot_check_panorama_photo(bool)));
    connect(hp_panorama,SIGNAL(signal_pc_key_set_freeze(int)),hpdomainthread,SLOT(slot_pc_key_set_freeze(int)));
    connect(hpcameracap,SIGNAL(signal_cameracap_panorama_errmsg(unsigned char)),hp_panorama,SLOT(slot_cameracap_panorama_errmsg(unsigned char)));
    connect(hpcameracap,SIGNAL(signal_cameracap_panorama_errmsg(unsigned char)),this,SLOT(slot_cameracap_panorama_errmsg(unsigned char)));

    connect(ui->display,SIGNAL(signal_pc_image_set_sketch_draw(sketch_point)),hpdomainthread,SLOT(slot_pc_image_set_sketch_draw(sketch_point)));
    connect(ui->display,SIGNAL(signal_pc_image_set_sketch_start(sketch_point)),hpdomainthread,SLOT(slot_pc_image_set_sketch_start(sketch_point)));

    connect(ui->display, SIGNAL(signal_read_img_process(int)), this, SLOT(slot_read_img_process(int)));
    connect(ui->display, SIGNAL(signal_setTaskTest(QString,QString,QString)),hpcameracap,SLOT(slot_setTaskTest(QString,QString,QString)));

    connect(ui->display, SIGNAL(signal_double_clicked_focus()), this, SLOT(slot_double_clicked_focus()));
    connect(Hp_TaskPkg::getInstance(),SIGNAL(Signal_ChangeAnaInfo(QString,QVector<ANA_OUTLINE>)),this,SLOT(slot_ChangeAnaInfo(QString,QVector<ANA_OUTLINE>)));
    connect(Hp_TaskPkg::getInstance(),SIGNAL(Signal_CloseDlg()),this,SLOT(slot_CloseDlg()));
    connect(Hp_TaskPkg::getInstance(),SIGNAL(Signal_Show_MessageBox()),this,SLOT(slot_Show_MessageBox()));
    connect(Hp_TaskPkg::getInstance(),SIGNAL(Signal_Show_MessageDialog()),this,SLOT(slot_Show_MessageDialog()));
    connect(Hp_TaskPkg::getInstance(),SIGNAL(Signal_Show_TaskSelect()),this,SLOT(slot_Show_TaskSelect()));
    connect(Hp_TaskPkg::getInstance(),SIGNAL(Signal_Show_TreeView()),this,SLOT(slot_Show_TreeView()));
    connect(Hp_TaskPkg::getInstance(),SIGNAL(Signal_Show_AnalysisChart()),this,SLOT(slot_Show_AnalysisChart()));
    connect(Hp_TaskPkg::getInstance(),SIGNAL(Signal_get_select_xml(QString)),this,SLOT(slot_get_select_xml(QString)));
    connect(this, SIGNAL(signal_pc_sys_set_laser_power(int)),hpdomainthread,SLOT(slot_pc_sys_set_laser_power(int)));
    connect(&hpsetting,SIGNAL(signal_pc_sys_set_powerdown(int)),hpdomainthread,SLOT(slot_pc_sys_set_powerdown(int)));
    connect(&hpd,SIGNAL(signal_pc_sys_set_powerdown(int)),hpdomainthread,SLOT(slot_pc_sys_set_powerdown(int)));
    connect(this, SIGNAL(signal_pc_sys_set_screen_sleep(int)), hpdomainthread, SLOT(slot_pc_sys_set_screensleep(int)));
    connect(&hpsetting, SIGNAL(signal_pc_sys_set_screen_sleep(int)), hpdomainthread, SLOT(slot_pc_sys_set_screensleep(int)));
    connect(&hpsetting, SIGNAL(signal_pc_sys_set_light_power(int)),hpdomainthread,SLOT(slot_pc_sys_set_light_power(int)));
    connect(hpmode.ui->buttonGroup_mode,SIGNAL(buttonToggled(QAbstractButton*,bool)),this,SLOT(mode_groupButton(QAbstractButton*,bool)));
    connect(hpmode.ui->buttonGroup_pip,SIGNAL(buttonToggled(QAbstractButton*,bool)),this,SLOT(pip_groupButton(QAbstractButton*,bool)));

    connect(hpmode.ui->toolButton_rect_adjust,SIGNAL(released()),this,SLOT(mode_hzh_adjust_release()));
    connect(&hpmodehzhadjust,SIGNAL(sync_pippara_rect()),this,SLOT(mode_hzh_adjust_finish()));

   connect(hpmode.ui->toolButton_rdj_adjust,SIGNAL(released()),this,SLOT(mode_rdj_adjust_release()));
   connect(&hpmode, SIGNAL(signal_rdj_set_adjust()), this, SLOT(mode_rdj_adjust_release()));
    connect(&hpmoderdjadjust,SIGNAL(sync_fusion_para()),this,SLOT(mode_rdj_adjust_finish()));

    connect(hpmode.ui->toolButton_handfusion,SIGNAL(clicked(bool)),this,SLOT(mode_handfution_clicked(bool)));

    QString sebiao;
    sebiao = hpxmlreader.readXml("sys.xml","COLORRULE","content");
    video_sebiao = sebiao.toInt();
    hpsebiao.set_sebiao(video_sebiao);
    ui->display->m_currSebiao = video_sebiao;

    connect(hpsebiao.ui->buttonGroup,SIGNAL(buttonToggled(QAbstractButton*,bool)),this,SLOT(sebiao_groupbutton(QAbstractButton*,bool)));

    connect(&hpsebiao, SIGNAL(signal_sebiao_set_reverse(bool)), this, SLOT(slot_sebiao_set_reverse(bool)));
    //======================================
    //diplay -> domain

    connect(ui->display,SIGNAL(signal_pc_sys_get_standard()),hpdomainthread,SLOT(slot_pc_sys_get_standard()));
    connect(ui->display,SIGNAL(signal_pc_measure_active(OP_DATA)),hpdomainthread,SLOT(slot_pc_measure_active(OP_DATA)));

    connect(ui->display,SIGNAL(signal_pc_measure_set_point_add(ComPointPara)),hpdomainthread,SLOT(slot_pc_measure_set_point_add(ComPointPara)));   //增加点
    connect(ui->display,SIGNAL(signal_pc_measure_set_point_update(ComPointPara)),hpdomainthread,SLOT(slot_pc_measure_set_point_update(ComPointPara)));
    connect(ui->display,SIGNAL(signal_pc_measure_set_point_del(ComPointPara)),hpdomainthread,SLOT(slot_pc_measure_set_point_del(ComPointPara)));

    connect(ui->display,SIGNAL(signal_pc_measure_set_line_add(ComLinePara)),hpdomainthread,SLOT(slot_pc_measure_set_line_add(ComLinePara)));
    connect(ui->display,SIGNAL(signal_pc_measure_set_line_update(ComLinePara)),hpdomainthread,SLOT(slot_pc_measure_set_line_update(ComLinePara)));
    connect(ui->display,SIGNAL(signal_pc_measure_set_line_del(ComLinePara)),hpdomainthread,SLOT(slot_pc_measure_set_line_del(ComLinePara)));

    connect(ui->display,SIGNAL(signal_pc_measure_set_rect_add(ComRectPara)),hpdomainthread,SLOT(slot_pc_measure_set_rect_add(ComRectPara)));
    connect(ui->display,SIGNAL(signal_pc_measure_set_rect_update(ComRectPara)),hpdomainthread,SLOT(slot_pc_measure_set_rect_update(ComRectPara)));
    connect(ui->display,SIGNAL(signal_pc_measure_set_rect_del(ComRectPara)),hpdomainthread,SLOT(slot_pc_measure_set_rect_del(ComRectPara)));

    connect(ui->display,SIGNAL(signal_pc_measure_set_circle_add(ComCirclePara)),hpdomainthread,SLOT(slot_pc_measure_set_circle_add(ComCirclePara)));
    connect(ui->display,SIGNAL(signal_pc_measure_set_circle_update(ComCirclePara)),hpdomainthread,SLOT(slot_pc_measure_set_circle_update(ComCirclePara)));
    connect(ui->display,SIGNAL(signal_pc_measure_set_circle_del(ComCirclePara)),hpdomainthread,SLOT(slot_pc_measure_set_circle_del(ComCirclePara)));

    connect(ui->display,SIGNAL(signal_pc_measure_set_polygon_add(ComPolygonPara)),hpdomainthread,SLOT(slot_pc_measure_set_polygon_add(ComPolygonPara)));
    connect(ui->display,SIGNAL(signal_pc_measure_set_polygon_update(ComPolygonPara)),hpdomainthread,SLOT(slot_pc_measure_set_polygon_update(ComPolygonPara)));
    connect(ui->display,SIGNAL(signal_pc_measure_set_polygon_del(ComPolygonPara)),hpdomainthread,SLOT(slot_pc_measure_set_polygon_del(ComPolygonPara)));

    connect(ui->display,SIGNAL(signal_pc_measure_clear()),hpdomainthread,SLOT(slot_pc_measure_clear()));
    connect(ui->display,SIGNAL(signal_lable_focus_state(bool)),this,SLOT(slot_lable_focus_state(bool)));

    connect(this,SIGNAL(signal_pc_measure_get_point(int)),hpdomainthread,SLOT(slot_pc_measure_get_point(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_get_point(unsigned char,ComPointPara)),ui->display,SLOT(slot_pc_measure_get_point(unsigned char,ComPointPara)));
    connect(this,SIGNAL(signal_pc_measure_get_line(int)),hpdomainthread,SLOT(slot_pc_measure_get_line(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_get_line(unsigned char,ComLinePara)),ui->display,SLOT(slot_pc_measure_get_line(unsigned char,ComLinePara)));
    connect(this,SIGNAL(signal_pc_measure_get_rect(int)),hpdomainthread,SLOT(slot_pc_measure_get_rect(int)));
    connect(ui->display,SIGNAL(signal_pc_measure_get_rect(int)),hpdomainthread,SLOT(slot_pc_measure_get_rect(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_get_rect(unsigned char,ComRectPara)),ui->display,SLOT(slot_pc_measure_get_rect(unsigned char,ComRectPara)));
    connect(this,SIGNAL(signal_pc_measure_get_circle(int)),hpdomainthread,SLOT(slot_pc_measure_get_circle(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_get_circle(unsigned char,ComCirclePara)),ui->display,SLOT(slot_pc_measure_get_circle(unsigned char,ComCirclePara)));

    connect(ui->display,SIGNAL(signal_hir_analyse_point_stop(int,bool)),this,SLOT(slot_hir_analyse_point_stop(int,bool)));
    connect(ui->display,SIGNAL(signal_hir_analyse_line_stop(int,bool)),this,SLOT(slot_hir_analyse_line_stop(int,bool)));
    connect(ui->display,SIGNAL(signal_hir_analyse_rect_stop(int,bool)),this,SLOT(slot_hir_analyse_rect_stop(int,bool)));

    connect(ui->display, SIGNAL(signal_show_insulation_warning(bool, int, int, int)), this, SLOT(slot_show_insulation_warning(bool, int, int, int)));

    connect(this,SIGNAL(signal_pc_image_set_mode(int)),hpdomainthread,SLOT(slot_pc_image_set_mode(int)));
    connect(this,SIGNAL(signal_pc_image_set_colorruler(int)),hpdomainthread,SLOT(slot_pc_image_set_colorruler(int)));

    connect(hpresize.ui->slider_resize, SIGNAL(valueChanged(int)), hpdomainthread,SLOT(slot_pc_key_zoom(int)));
    connect(hpresize.ui->slider_contrast, SIGNAL(valueChanged(int)), hpdomainthread, SLOT(slot_pc_sys_set_image_contrast(int)));
    connect(hpresize.ui->slider_brightness, SIGNAL(valueChanged(int)), hpdomainthread, SLOT(slot_pc_sys_set_color_brightness(int)));

    //=====================================
    //domain->display
    connect(hpdomainthread,SIGNAL(signal_pc_sys_get_standard(unsigned char,StandardInfo)),ui->display,SLOT(slot_pc_sys_get_standard(unsigned char,StandardInfo)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_active(unsigned char)), ui->display,SLOT(slot_pc_measure_active(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_point_add(unsigned char)),ui->display,SLOT(slot_pc_measure_set_point_add(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_point_update(unsigned char)),ui->display,SLOT(slot_pc_measure_set_point_update(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_point_del(unsigned char)),ui->display,SLOT(slot_pc_measure_set_point_del(unsigned char)));

    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_line_add(unsigned char)),ui->display,SLOT(slot_pc_measure_set_line_add(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_line_update(unsigned char)),ui->display,SLOT(slot_pc_measure_set_line_update(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_line_del(unsigned char)),ui->display,SLOT(slot_pc_measure_set_line_del(unsigned char)));

    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_rect_add(unsigned char)),ui->display,SLOT(slot_pc_measure_set_rect_add(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_rect_update(unsigned char)),ui->display,SLOT(slot_pc_measure_set_rect_update(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_rect_del(unsigned char)),ui->display,SLOT(slot_pc_measure_set_rect_del(unsigned char)));

    connect(hpdomainthread,SIGNAL(signal_pc_measure_clear(unsigned char)),ui->display,SLOT(slot_pc_measure_clear(unsigned char)));

    connect(hpdomainthread,SIGNAL(signal_pc_image_set_mode(unsigned char)),this,SLOT(slot_pc_image_set_mode(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_pc_image_set_colorruler(unsigned char)),this,SLOT(slot_pc_image_set_colorruler(unsigned char)));

    connect(hpdomainthread,SIGNAL(signal_pc_key_zoom(unsigned char)),this,SLOT(slot_pc_key_zoom(unsigned char)));

    connect(&hpsetting.hpcalbration,SIGNAL(signal_pc_sys_mag_calsw_start()),hpdomainthread,SLOT(slot_pc_sys_mag_calsw_start()));
    connect(&hpsetting.hpcalbration,SIGNAL(signal_pc_sys_mag_calsw_stop()),hpdomainthread,SLOT(slot_pc_sys_mag_calsw_stop()));
    //=============================
    //hpseeting -> domain
    connect(&hpsetting.hphidemenu,SIGNAL(signal_pc_sys_set_hidemenu(ComHideMenuPara)),hpdomainthread,SLOT(slot_pc_sys_set_hidemenu(ComHideMenuPara)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_hidemenu(unsigned char)),&hpsetting.hphidemenu,SLOT(slot_pc_sys_set_hidemenu(unsigned char)));
    connect(&hpsetting.hphidemenu, SIGNAL(signal_pc_sys_mag_calsw_start()),   hpdomainthread, SLOT(slot_pc_sys_mag_calsw_start()));
    connect(&hpsetting.hphidemenu,SIGNAL(signal_pc_sys_mag_calsw_stop()),     hpdomainthread, SLOT(slot_pc_sys_mag_calsw_stop()));
    connect(&hpsetting.hphidemenu, SIGNAL(signal_pc_sys_set_mag_affset(int)), hpdomainthread, SLOT(slot_pc_sys_set_mag_affset(int)));
    connect(&hpsetting.hphidemenu, SIGNAL(signal_set_compass_trans(int)),     this, SLOT(slot_set_compass_trans(int)));

    connect(this,SIGNAL(singal_pc_sys_set_laserpos(int)), hpdomainthread,SLOT(slot_pc_sys_set_laserpos(int)));
    connect(hpdomainthread,SIGNAL(singal_pc_sys_set_laserpos(unsigned char)),this,SLOT(slot_pc_sys_set_laserpos(unsigned char)));

    connect(&hpsetting,SIGNAL(signal_pc_osd_set_osdstat(OsdSetting)),hpdomainthread,SLOT(slot_pc_osd_set_osdstat(OsdSetting)));
    connect(this,SIGNAL(signal_pc_osd_set_osdstat(OsdSetting)),hpdomainthread,SLOT(slot_pc_osd_set_osdstat(OsdSetting)));
    connect(&hpsetting,SIGNAL(signal_pc_sys_set_autorectify(int)),hpdomainthread,SLOT(slot_pc_sys_set_autorectify(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_autorectify(unsigned char)),&hpsetting,SLOT(slot_pc_sys_set_autorectify(unsigned char)));

    connect(&hpsetting.hphidemenu,SIGNAL(signal_gray_enable(bool)),ui->display,SLOT(slot_hidemenu_gray(bool)));
    connect(&hpsetting.hphidemenu,SIGNAL(signal_laser_enable(bool)),this,SLOT(slot_hidemenu_laser(bool)));

    connect(this,SIGNAL(signal_pc_key_auto_rectify()),hpdomainthread,SLOT(slot_pc_key_auto_rectify()));
    connect(&hpsetting,SIGNAL(signal_pc_key_auto_rectify()),hpdomainthread,SLOT(slot_pc_key_auto_rectify()));
    connect(hpdomainthread,SIGNAL(signal_pc_key_auto_rectify(unsigned char)),this,SLOT(slot_pc_key_auto_rectify(unsigned char)));

    connect(hpdomainthread,SIGNAL(signal_key_auto_start()),this,SLOT(slot_key_auto_start()));
    connect(hpdomainthread,SIGNAL(signal_pc_key_auto_rectify(unsigned char)),this,SLOT(slot_key_auto_end(unsigned char)));
    //====================================
    connect(&hpsetting,SIGNAL(signal_tempunit_value_changed(int)),this,SLOT(slot_tempunit_value_changed(int)));

    connect(&hpsetting,SIGNAL(signal_set_part_ReferTemp(bool)),ui->display,SLOT(slot_set_part_ReferTemp(bool)));
    connect(ui->display,SIGNAL(signal_set_globle_ReferTemp(bool)),&hpsetting,SLOT(slot_set_globle_ReferTemp(bool)));

    connect(hpsetting.ui->ScrollBar_TempUnit,SIGNAL(valueChanged(int)),ui->display,SLOT(slot_tempunit_changed(int)));
    connect(&hpsetting,SIGNAL(signal_update_radiance_to_display(int)),ui->display,SLOT(slot_global_radiance_value_changed(int)));
    connect(&hpsetting,SIGNAL(signal_update_radTable_to_display(int,int)),ui->display,SLOT(slot_global_radTable_value_changed(int,int)));
    connect(&hpsetting,SIGNAL(signal_set_radTable_state(int)),ui->display,SLOT(slot_global_radTable_mode_changed(int)));

    //4G
    connect(&hpsetting,SIGNAL(signal_set_4G_state(int)),hpdomainthread,SLOT(slot_set_4G_state(int)));
    connect(&hpsetting,SIGNAL(signal_set_4G_power(int)),hpdomainthread,SLOT(slot_set_4G_power(int)));
    connect(hpdomainthread,SIGNAL(signal_set_4G_state(unsigned char)),&hpsetting,SLOT(slot_set_4G_state(unsigned char)));

    connect(&hpsetting,SIGNAL(signal_get_4G_state()),sd_hpdomain,SLOT(slot_get_4G_state()));
    connect(sd_hpdomain,SIGNAL(signal_get_4G_state(unsigned char ,int)),&hpsetting,SLOT(slot_get_4G_state(unsigned char ,int)));
    connect(sd_hpdomain,SIGNAL(signal_set_4G_state(unsigned char)),&hpsetting,SLOT(slot_get_4G_state(unsigned char,int)));
    connect(this,SIGNAL(signal_pc_get_measure_get_temp()),sd_hpdomain,SLOT(slot_pc_get_measure_get_temp()));
    connect(sd_hpdomain,SIGNAL(signal_pc_get_measure_get_temp(unsigned char,RectTemp)),this,SLOT(slot_pc_get_measure_get_temp(unsigned char,RectTemp)));

    connect(&hpsetting,SIGNAL(signal_timer_get_positiion_switch(int)),this,SLOT(slot_timer_get_positiion_switch(int)));

    connect(this, SIGNAL(signal_pc_sys_get_positiion_data()), hpdomainthread, SLOT(slot_pc_sys_get_positiion_data()));
    connect(hpdomainthread, SIGNAL(signal_pc_sys_get_positiion_data(unsigned char, int)), this, SLOT(slot_pc_sys_get_positiion_data(unsigned char, int)));

    connect(&hpsetting,SIGNAL(signal_update_distance_to_display(int)),ui->display,SLOT(slot_global_distance_value_changed(int)));
    connect(&hpsetting,SIGNAL(signal_update_reflect_temp_to_display(int)),ui->display,SLOT(slot_global_reflect_value_changed(int)));

    connect(&hpsetting,SIGNAL(signal_pc_cfg_set_temp_userpara(ComTempUserPara)),hpdomainthread,SLOT(slot_pc_cfg_set_temp_userpara(ComTempUserPara)));
    connect(hpdomainthread,SIGNAL(signal_pc_cfg_set_temp_userpara(unsigned char)),&hpsetting,SLOT(slot_pc_cfg_set_userpara(unsigned char)));

    connect(&hpsetting,SIGNAL(signal_pc_measure_set_reference(ComTempReference)),hpdomainthread,SLOT(slot_pc_measure_set_reference(ComTempReference)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_reference(unsigned char)),&hpsetting,SLOT(slot_pc_measure_set_reference(unsigned char)));

    connect(hpsetting.ui->ScrollBar_TempUnit,SIGNAL(valueChanged(int)),hpdomainthread,SLOT(slot_pc_measure_set_tempunit(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_tempunit(unsigned char)),&hpsetting,SLOT(slot_pc_measure_set_tempunit(unsigned char)));

    connect(&hpsetting.hpisotherm,SIGNAL(signal_pc_image_set_Isotemp(ComIsothermTemp)),hpdomainthread,SLOT(slot_pc_image_set_Isotherm(ComIsothermTemp)));
    connect(hpdomainthread,SIGNAL(signal_pc_image_set_Isotemp(unsigned char)),&hpsetting.hpisotherm,SLOT(slot_pc_image_set_Isotherm(unsigned char)));
    connect(&hpsetting, SIGNAL(signal_set_picture_zoom_save(bool)), hpcameracap, SLOT(slot_set_picture_zoom_save(bool)));

    connect(&hpsetting,SIGNAL(signal_pc_measure_set_temprange(ComTempRange)),hpdomainthread,SLOT(slot_pc_measure_set_temprange(ComTempRange)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_temprange(unsigned char)),&hpsetting,SLOT(slot_pc_measure_set_temprange(unsigned char)));

    connect(&hpsetting,SIGNAL(signal_pc_image_set_alarm(ComAlarmTemp)),hpdomainthread,SLOT(slot_pc_image_set_alarm(ComAlarmTemp)));
    connect(hpdomainthread,SIGNAL(signal_pc_image_set_alarm(unsigned char)),&hpsetting,SLOT(slot_pc_image_set_alarm(unsigned char)));

    connect(hpsetting.hpdefault,SIGNAL(signal_set_default()),hpdomainthread,SLOT(slot_pc_sys_set_default()));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_default(unsigned char)),&hpsetting,SLOT(slot_pc_sys_set_default(unsigned char)));

    connect(hpsetting.hpformat,SIGNAL(signal_set_format()),hpdomainthread,SLOT(slot_pc_sys_set_format()));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_format(unsigned char)),&hpsetting,SLOT(slot_pc_sys_set_format(unsigned char)));

    connect(hpsetting.hpformat,SIGNAL(signal_set_format()),this,SLOT(slot_sd_format_start()));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_format(unsigned char)),this,SLOT(slot_sd_format_end(unsigned char)));

    connect(hpsetting.hp_wifi_Search,SIGNAL(signal_PC_SYS_GET_ESSID()),hpdomainthread,SLOT(slot_PC_SYS_GET_ESSID()));
    connect(hpdomainthread,SIGNAL(signal_PC_SYS_GET_ESSID(unsigned char,QString)),hpsetting.hp_wifi_Search,SLOT(slot_PC_SYS_GET_ESSID(unsigned char,QString)));

    connect(hpsetting.hp_wifi_Search,SIGNAL(signal_PC_SYS_SET_WIFI_STA(ap_para)),hpdomainthread,SLOT(slot_PC_SYS_SET_WIFI_STA(ap_para)));
    connect(hpdomainthread,SIGNAL(signal_PC_SYS_SET_WIFI_STA(unsigned char)),hpsetting.hp_wifi_Search,SLOT(slot_PC_SYS_SET_WIFI_STA(unsigned char)));

    connect(hpsetting.hp_wifi_Search,SIGNAL(signal_CORE_GET_WIFI_STA_STATUS()),hpdomainthread,SLOT(slot_CORE_GET_WIFI_STA_STATUS()));
    connect(hpdomainthread,SIGNAL(signal_CORE_GET_WIFI_STA_STATUS(unsigned char,int)),hpsetting.hp_wifi_Search,SLOT(slot_CORE_GET_WIFI_STA_STATUS(unsigned char,int)));

    connect(hpsetting.hp_wifi_Search,SIGNAL(signal_pc_sys_set_local_servrer(int)),hpdomainthread,SLOT(slot_pc_sys_set_local_servrer(int)));
    connect(&hpsetting,SIGNAL(signal_pc_sys_set_local_servrer(int)),hpdomainthread,SLOT(slot_pc_sys_set_local_servrer(int)));
    connect(this,SIGNAL(signal_pc_sys_set_local_servrer(int)),hpdomainthread,SLOT(slot_pc_sys_set_local_servrer(int)));

    connect(hpsetting.hp_wifi_Search, SIGNAL(signal_pc_sys_set_dev_active_search()), hpdomainthread, SLOT(slot_pc_sys_set_dev_active_search()));
    connect(hpdomainthread, SIGNAL(signal_pc_sys_set_dev_active_search(unsigned char, QStringList)), hpsetting.hp_wifi_Search, SLOT(slot_pc_sys_set_dev_active_search(unsigned char, QStringList)));

    connect(hpsetting.hp_wifi_Search, SIGNAL(signal_pc_sys_set_dev_client(ComDevClientInfo)), hpdomainthread, SLOT(slot_pc_sys_set_dev_client(ComDevClientInfo)));
    connect(hpdomainthread, SIGNAL(signal_pc_sys_set_dev_client(unsigned char)), hpsetting.hp_wifi_Search, SLOT(slot_pc_sys_set_dev_client(unsigned char)));

    connect(hpsetting.hp_wifi_Search, SIGNAL(signal_key_dev_client_encode_start()), hpdomainthread, SLOT(slot_key_dev_client_encode_start()));
    connect(hpsetting.hp_wifi_Search, SIGNAL(signal_key_dev_client_encode_stop()), hpdomainthread,  SLOT(slot_key_dev_client_encode_stop()));


    connect(hpsetting.hp_autoupload,SIGNAL(signal_set_IP_Account_Password(QString,QString,QString,int)),hpcameracap,SLOT(slot_set_IP_Account_Password(QString,QString,QString,int)));
    connect(hpsetting.hp_autoupload,SIGNAL(signal_set_IP_Account_Password(QString,QString,QString,int)),hpsetting.hp_downLoad,SLOT(slot_set_IP_Account_Password(QString,QString,QString,int)));

    connect(&hpsetting,SIGNAL(signal_pc_sys_time_sec(char*)),hpdomainthread,SLOT(slot_pc_sys_set_time_sec(char*)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_time_sec(unsigned char)),&hpsetting,SLOT(slot_pc_sys_time_sec(unsigned char)));

    connect(&hpsetting,SIGNAL(signal_pc_sys_set_capturetime(int)),this,SLOT(slot_pc_sys_set_capturetime(int)));

    connect(&hpsetting,SIGNAL(signal_pc_sys_set_usbmode(int)),hpdomainthread,SLOT(slot_pc_sys_set_usbmode(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_usbmode(unsigned char)),&hpsetting,SLOT(slot_pc_sys_set_usbmode(unsigned char)));

    connect(hpsetting.hp_wifi_Search,SIGNAL(signal_pc_sys_set_wifi_switch(int)),hpdomainthread,SLOT(slot_pc_sys_set_wifi_switch(int)));
    connect(&hpsetting,SIGNAL(signal_pc_sys_set_wifi_switch(int)),hpdomainthread,SLOT(slot_pc_sys_set_wifi_switch(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_wifi_switch(unsigned char)),&hpsetting,SLOT(slot_pc_sys_set_wifi_switch(unsigned char)));

    connect(this,SIGNAL(signal_pc_key_set_freeze(int)),hpdomainthread,SLOT(slot_pc_key_set_freeze(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_key_set_freeze(unsigned char)),this,SLOT(slot_pc_key_set_freeze(unsigned char)));

    connect(this,SIGNAL(signal_core_key_record_avi_start()),hpdomainthread,SLOT(slot_core_key_record_avi_start()));
    connect(hpdomainthread,SIGNAL(signal_core_key_record_avi_start(unsigned char)),this,SLOT(slot_core_key_record_avi_start(unsigned char)));

    connect(this, SIGNAL(signal_set_current_lens(int)), &hpsetting, SLOT(slot_set_current_lens(int)));
    //powerpff_warn
    connect(this,SIGNAL(signal_close_poweroff_warn()),&hp_power_w,SLOT(chongdian_on_toolButton_clicked()));
    //avi hir start stop
    connect(&hp_avimode,SIGNAL(signal_avi_hir_mode(int)),this,SLOT(slot_avi_hir_mode(int)));
    connect(&hpsetting,SIGNAL(signal_avi_hir_mode(int)),this,SLOT(slot_avi_hir_mode(int)));
    connect(&hp_avimode,SIGNAL(signal_core_key_record_avi_mode_start()),hpdomainthread,SLOT(slot_core_key_record_avi_start()));
    connect(&hp_avimode,SIGNAL(signal_core_key_record_hir_mode_start()),hpdomainthread,SLOT(slot_core_key_record_hir_start()));
    connect(this,SIGNAL(signal_core_key_record_avi_mode_start()),hpdomainthread,SLOT(slot_core_key_record_avi_start()));
    connect(this,SIGNAL(signal_core_key_record_hir_mode_start()),hpdomainthread,SLOT(slot_core_key_record_hir_start()));

    connect( avi_record_get_SDInfo,SIGNAL( timeout() ) ,this,SLOT( avi_record_get_SDInfoTimeOut() ) );
    connect( kjgToAutoRecirft,SIGNAL( timeout() ) ,this,SLOT( kjgToAutoRecirftTimeOut() ) );
    connect( settingToAutoRecirft,SIGNAL( timeout() ) ,this,SLOT( settingToAutoRecirftTimeOut() ) );
    connect( previewToAutoRecirft,SIGNAL( timeout() ) ,this,SLOT( previewToAutoRecirftTimeOut() ) );
    connect( AutoUpdateGetStatus,SIGNAL( timeout() ) ,this,SLOT( autoUpdateGetStatusTimeOut() ) );

    connect(this,SIGNAL(signal_core_key_record_hir_stop()),hpdomainthread,SLOT(slot_core_key_record_hir_stop()));
    connect(this,SIGNAL(signal_core_key_record_avi_stop()),hpdomainthread,SLOT(slot_core_key_record_avi_stop()));
    connect(hpdomainthread,SIGNAL(signal_core_key_record_avi_stop(unsigned char)),this,SLOT(slot_core_key_record_avi_stop(unsigned char)));

    connect(this,SIGNAL(signal_pc_measure_move_display(ti_pos)), hpdomainthread, SLOT(slot_pc_measure_move_display(ti_pos)));//移动屏幕显示区域专用
    connect(hppreview,SIGNAL(signal_core_analysis_pic_twice_start(char*)),hpdomainthread,SLOT(slot_core_annlysis_pic_twice_start(char*)));
    connect(hpdomainthread,SIGNAL(signal_core_annlysis_pic_twice_start(unsigned char)),this,SLOT(slot_core_analysis_pic_twice_start(unsigned char)));

    connect(&hppreview->hhp,SIGNAL(signal_core_analysis_hir_twice_start(char*)),hpdomainthread,SLOT(slot_core_annlysis_hir_twice_start(char*)));
    connect(hpdomainthread,SIGNAL(signal_core_analysis_hir_twice_start(unsigned char)),this,SLOT(slot_core_annlysis_hir_twice_start(unsigned char)));

    connect(this,SIGNAL(signal_core_analysis_pic_twice_stop()),hpdomainthread,SLOT(slot_core_annlysis_pic_twice_stop()));
    connect(hpdomainthread,SIGNAL(signal_core_annlysis_pic_twice_stop(unsigned char)),this,SLOT(slot_core_analysis_pic_twice_stop(unsigned char)));

    connect(this,SIGNAL(signal_core_corectrl_start_encode()),hpdomainthread,SLOT(slot_core_ctrlcore_start_encode()));
    connect(hpdomainthread,SIGNAL(signal_core_ctrlcore_start_encode(unsigned char)),this,SLOT(slot_core_corectrl_start_encode(unsigned char)));

    connect(this,SIGNAL(signal_core_corectrl_stop_encode()),hpdomainthread,SLOT(slot_core_ctrlcore_stop_encode()));
    connect(hpdomainthread,SIGNAL(signal_core_ctrlcore_stop_encode(unsigned char)),this,SLOT(slot_core_corectrl_stop_encode(unsigned char)));

    connect(hppreview,SIGNAL(signal_preview_close()),this,SLOT(preview_finish()));
    connect(hppreview, SIGNAL(signal_set_main_analog_audio()), this, SLOT(slot_set_main_analog_audio()));
    connect(hppreview,SIGNAL(signal_core_get_sd_info()),sd_hpdomain,SLOT(slot_core_get_sd_info()));
    connect(sd_hpdomain,SIGNAL(signal_core_get_sd_info(unsigned char,sdinfo_t)),hppreview,SLOT(slot_core_get_sd_info(unsigned char,sdinfo_t)));
    connect(sd_hpdomain,SIGNAL(signal_core_get_sd_info(unsigned char,sdinfo_t)),this,SLOT(slot_core_get_sd_info(unsigned char,sdinfo_t)));
    connect(this,SIGNAL(signal_core_get_sd_info()),sd_hpdomain,SLOT(slot_core_get_sd_info()));

    connect(this,SIGNAL(signal_core_get_battery()),sd_hpdomain,SLOT(slot_core_get_battery()));
    connect(sd_hpdomain,SIGNAL(signal_core_get_battery(unsigned char,int)),this,SLOT(slot_core_get_battery(unsigned char,int)));

    connect(this,SIGNAL(signal_pc_set_upload_break(int)),sd_hpdomain,SLOT(slot_pc_set_upload_break(int)));
    connect(hpcameracap,SIGNAL(signal_pc_set_upload_break(int)),sd_hpdomain,SLOT(slot_pc_set_upload_break(int)));

    connect(sd_hpdomain,SIGNAL(signal_pc_set_upload_break(unsigned char)),hpcameracap,SLOT(slot_pc_set_upload_break(unsigned char)));
    connect(sd_hpdomain,SIGNAL(signal_pc_set_upload_break(unsigned char)),this,SLOT(slot_pc_set_upload_break(unsigned char)));

    connect(hpcameracap,SIGNAL(signal_core_get_upload_status()),sd_hpdomain,SLOT(slot_core_get_upload_status()));
    connect(sd_hpdomain,SIGNAL(signal_core_get_upload_status(unsigned char,int)),hpcameracap,SLOT(slot_core_get_upload_status(unsigned char,int)));

    connect(&hpadjustcmd,SIGNAL(signal_FusionAdjust(FusionAdjust)),hpdomainthread,SLOT(slot_pc_sys_fusion_adjust(FusionAdjust)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_fusion_adjust(unsigned char)),&hpadjustcmd,SLOT(slot_FusionAdjust(unsigned char)));

    //    connect(&hpsetting,SIGNAL(signal_tempunit_changed()),this,SLOT(slot_tempunit_chaned()));

    connect(this,SIGNAL(signal_pc_image_set_pip(PipPara)),hpdomainthread,SLOT(slot_pc_image_set_pip(PipPara)));
    connect(hpdomainthread,SIGNAL(signal_pc_image_set_pip(unsigned char)),this,SLOT(slot_pc_image_set_pip(unsigned char)));

    connect(ui->display, SIGNAL(signal_set_twice_hzh_adjust(int,int,int,int)),this,SLOT(slot_set_twice_hzh_adjust(int,int,int,int)));

    connect(this,SIGNAL(signal_pc_image_set_fusion(FusionPara)),hpdomainthread,SLOT(slot_pc_image_set_fusion(FusionPara)));
    connect(hpdomainthread,SIGNAL(signal_pc_image_set_fusion(unsigned char)),this,SLOT(slot_pc_image_set_fusion(unsigned char)));

    connect(&hpadjustcmd,SIGNAL(signal_pc_sys_get_bn()),hpdomainthread,SLOT(slot_pc_sys_get_bn()));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_get_bn(unsigned char,int)),&hpadjustcmd,SLOT(slot_pc_sys_get_bn(unsigned char,int)));
    auto_manual_init();

    connect(&hpadjustcmd,SIGNAL(signal_pc_sys_get_focus()),hpdomainthread,SLOT(slot_pc_sys_get_focus()));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_get_focus(unsigned char,int)),&hpadjustcmd,SLOT(slot_pc_sys_get_focus(unsigned char,int)));
    auto_manual_init();
    //slot_pc_measure_set_temprange_ok
//    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_temprange(unsigned char)),&hpadjustcmd,SLOT(slot_pc_measure_set_temprange_ok(unsigned char)));

    connect(hpcameracap,SIGNAL(signal_core_key_add_audio_start()),hpdomainthread,SLOT(slot_core_key_add_audio_start()));
    connect(hpdomainthread,SIGNAL(signal_core_key_add_audio_start(unsigned char)),hpcameracap,SLOT(slot_core_key_add_audio_start(unsigned char)));

    connect(hpcameracap,SIGNAL(signal_core_key_add_audio_stop()),hpdomainthread,SLOT(slot_core_key_add_audio_stop()));
    connect(hpdomainthread,SIGNAL(signal_core_key_add_audio_stop(unsigned char)),hpcameracap,SLOT(slot_core_key_add_audio_stop(unsigned char)));

    connect(hpcameracap,SIGNAL(signal_core_key_add_text(char*)),hpdomainthread,SLOT(slot_core_key_add_text(char*)));
    connect(hpdomainthread,SIGNAL(signal_core_key_add_text(unsigned char)),hpcameracap,SLOT(slot_core_key_add_text(unsigned char)));
    connect(hpcameracap,SIGNAL(signal_core_key_capture_start(int)),hpdomainthread,SLOT(slot_core_key_capture_start(int)));
    connect(this,SIGNAL(signal_core_key_capture_start(int)),hpdomainthread,SLOT(slot_core_key_capture_start(int)));
    connect(hpcameracap,SIGNAL(signal_core_key_capture_start(int)),this,SLOT(slot_core_key_capture_start(int)));

    connect(hpdomainthread,SIGNAL(signal_core_key_capture_start(unsigned char)),hpcameracap,SLOT(slot_core_key_capture_start(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_core_key_capture_start(unsigned char)),this,SLOT(slot_core_key_capture_start(unsigned char)));

    connect(this,SIGNAL(signal_core_key_capture_stop(int)),hpdomainthread,SLOT(slot_core_key_capture_stop(int)));
    connect(hpcameracap,SIGNAL(signal_core_key_capture_stop(int)),hpdomainthread,SLOT(slot_core_key_capture_stop(int)));
    connect(hpdomainthread,SIGNAL(signal_core_key_capture_stop(unsigned char,QString)),hpcameracap,SLOT(slot_core_key_capture_stop(unsigned char,QString)));


    connect(hpsetting.hp_autoupload,SIGNAL(signal_pc_sys_set_upload_target(ftp_para)),hpdomainthread,SLOT(slot_pc_sys_set_upload_target(ftp_para)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_upload_target(unsigned char)),hpsetting.hp_autoupload,SLOT(slot_pc_sys_set_upload_target(unsigned char)));

    connect(hpcameracap,SIGNAL(signal_pc_key_set_freeze(int)),hpdomainthread,SLOT(slot_pc_key_set_freeze(int)));

    connect(&hpsetting,SIGNAL(signal_language_changed(int)),this,SLOT(slot_language_changed(int)));
    connect(&hpsetting,SIGNAL(signal_language_changed(int)),hpdomainthread,SLOT(slot_pc_sys_set_language(int)));
    connect(&hpsetting,SIGNAL(signal_language_changed_end()),this,SLOT(slot_language_changed_end()));
    connect(this,SIGNAL(signal_pc_sys_set_lcd_bright(int)),hpdomainthread,SLOT(slot_pc_sys_set_lcd_bright(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_lcd_bright(unsigned char)),this,SLOT(slot_pc_sys_set_lcd_bright(unsigned char)));

    connect( &hpsetting,SIGNAL(signal_pc_measure_tempcapture(int)),hpdomainthread,SLOT(slot_pc_measure_tempcapture(int)) );
    connect( hpdomainthread,SIGNAL(signal_pc_measure_tempcapture(unsigned char)),&hpsetting,SLOT(slot_pc_measure_tempcapture(unsigned char)) );

    connect(this,SIGNAL(signal_pc_cmd_set_pc_pic(ftp_para)),hpdomainthread,SLOT(slot_pc_cmd_set_pc_pic(ftp_para)));
    connect(hpcameracap,SIGNAL(signal_pc_cmd_set_pc_pic(ftp_para)),hpdomainthread,SLOT(slot_pc_cmd_set_pc_pic(ftp_para)));
    connect(hpdomainthread,SIGNAL(signal_pc_cmd_set_pc_pic(unsigned char)),hpcameracap,SLOT(slot_pc_cmd_set_pc_pic(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_pc_cmd_set_pc_pic(unsigned char)),this,SLOT(slot_pc_cmd_set_pc_pic(unsigned char)));
    connect(&hpsetting,SIGNAL(signal_SetAutoUpdateIsChecked(bool)),hpcameracap,SLOT(slot_autoUpdate_setchecked(bool)));
    connect(&hpsetting,SIGNAL(signal_set_show_avgTemp(bool)), this, SLOT(slot_set_show_avgTemp(bool)));
    connect(&hpsetting,SIGNAL(signal_set_auto_reflect(bool)), this, SLOT(slot_set_auto_reflect(bool)));

    connect(&hpsetting,SIGNAL(signal_pc_image_set_gps(int)),hpdomainthread,SLOT(slot_pc_image_set_gps(int)));
    connect(this,SIGNAL(signal_pc_image_set_gps(int)),hpdomainthread,SLOT(slot_pc_image_set_gps(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_image_set_gps(unsigned char)),&hpsetting,SLOT(slot_pc_image_set_gps(unsigned char)));
    connect(&hpsetting, SIGNAL(signal_show_gps_pixel(int)), this, SLOT(slot_show_gps_pixel(int)));
    connect(&hpsetting, SIGNAL(signal_show_4G_pixel(int)), this, SLOT(slot_show_4G_pixel(int)));
    connect(&hpsetting,SIGNAL(signal_timer_get_rotation_switch(int)),this,SLOT(slot_timer_get_rotation_switch(int)));
    connect(&hpsetting,SIGNAL(signal_pc_image_set_flip(int)),hpdomainthread,SLOT(slot_pc_image_set_flip(int)));

    connect(this,SIGNAL(signal_core_get_battery_charge()),sd_hpdomain,SLOT(slot_core_get_charge()));
    connect(sd_hpdomain,SIGNAL(signal_core_get_charge(unsigned char,int)),this,SLOT(slot_core_get_battery_charge(unsigned char,int)));
    connect(&hpsetting,SIGNAL(signal_core_get_usbwifiinsert()),sd_hpdomain,SLOT(slot_core_get_usbwifiinsert()));
    connect(&hpsetting, SIGNAL(signal_set_preset_mode(int)), this, SLOT(slot_set_preset_mode(int)));
    connect(sd_hpdomain,SIGNAL(signal_core_get_usbwifiinsert(unsigned char,int)),&hpsetting,SLOT(slot_core_get_usbwifiinsert(unsigned char,int)));
    connect(this,SIGNAL(signal_core_get_usbwifiinsert()),sd_hpdomain,SLOT(slot_core_get_usbwifiinsert()));
    connect(sd_hpdomain,SIGNAL(signal_core_get_usbwifiinsert(unsigned char,int)),this,SLOT(slot_core_get_usbwifiinsert(unsigned char,int)));
    connect(this,SIGNAL(signal_core_get_sdinsert()),sd_hpdomain,SLOT(slot_core_get_sdinsert()));
    connect(sd_hpdomain,SIGNAL(signal_core_get_sdinsert(unsigned char,int)),this,SLOT(slot_core_get_sdinsert(unsigned char,int)));

    connect(this,SIGNAL(signal_core_get_usbinsert()),sd_hpdomain,SLOT(slot_core_get_usbinsert()));
    connect(sd_hpdomain,SIGNAL(signal_core_get_usbinsert(unsigned char,int)),this,SLOT(slot_core_get_usbinsert(unsigned char,int)));

    connect(this,SIGNAL(signal_core_get_rotation_type()),sd_hpdomain,SLOT(slot_core_get_rodation_type()));
    connect(sd_hpdomain,SIGNAL(signal_core_get_rotation_type(unsigned char,int)),this,SLOT(slot_core_get_rodation_type(unsigned char,int)));
    QString para;
    para = hpxmlreader.readXml("sys.xml","HANDFUSION","content");
    if(!hpmode.ui->widget_handfution->set_current_index(para.toInt()))
    {
        hpmode.ui->widget_handfution->set_current_index(0);
    }

    connect(hpmode.ui->widget_handfution,SIGNAL(current_index_changed(int)),hpdomainthread,SLOT(slot_pc_sys_set_handfusion(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_handfusion(unsigned char)),hpmode.ui->widget_handfution,SLOT(slot_pc_sys_set_handfusion(unsigned char)));

    connect(&hpsetting.hphidemenu,SIGNAL(signal_printscreen_checked(bool)),this,SLOT(slot_hphidemenu_printscreen(bool)));

    //更改为上次关机时的语言设置
    slot_language_changed(hpsetting.ui->comboBox_language->currentIndex());


    //connect(&hpsetting.hpblesearch,SIGNAL(signal_sendLinkToCameracap(bool)),hpcameracap,SLOT(slot_sendLinkToCameracap(bool)));
    //==============================================================
    //hidemenu point rect
    connect(&hpsetting.hphidemenu,SIGNAL(signal_point_enable(bool)),hpdomainthread,SLOT(slot_hidemenu_point_enable(bool)));
    connect(&hpsetting.hphidemenu,SIGNAL(signal_rect_enable(bool)),hpdomainthread,SLOT(slot_hidemenu_rect_enable(bool)));

    connect(hppreview,SIGNAL(signal_pc_image_hir_composite(char*)),hpdomainthread,SLOT(slot_pc_image_hir_composite(char*)));
    connect(hpdomainthread,SIGNAL(signal_pc_image_hir_composite(unsigned char)),hppreview,SLOT(slot_pc_image_hir_composite(unsigned char)));

    //隐藏界面， 画框，点
    connect(&hpsetting.hphidemenu,SIGNAL(signal_painter_rect(bool)), ui->display,SLOT(slot_painter_rect(bool)));
    connect(&hpsetting.hphidemenu,SIGNAL(signal_painter_point(bool)),ui->display,SLOT(slot_painter_point(bool)));
    connect(&hpsetting.hphidemenu,SIGNAL(signal_pc_get_measure_get_collect(int)),hpdomainthread,SLOT(slot_pc_get_measure_get_collect(int)));
    connect(ui->display,SIGNAL(signal_display_point(unsigned char*,int)),hpdomainthread,SLOT(slot_display_point(unsigned char*,int)));
    connect(ui->display,SIGNAL(signal_display_rect(unsigned char*,int)),hpdomainthread,SLOT(slot_display_rect(unsigned char*,int)));
    //displau
    connect(this,SIGNAL(signal_dandian_sidian()),hpdomainthread,SLOT(slot_dandian_sidian()));
    connect(this,SIGNAL(signal_gaowen_sidian()),hpdomainthread,SLOT(slot_gaowen_sidian()));
     connect(this,SIGNAL(signal_diwen_sidian()),hpdomainthread,SLOT(slot_diwen_sidian()));
    //移动死点
    connect(this,SIGNAL(signal_del_badpixel_point(int)),ui->display,SLOT(slot_del_badpixel_point(int)));
    connect(this,SIGNAL(signal_del_badpixel_rect(int)),ui->display,SLOT(slot_del_badpixel_rect(int)));
    //获取高i低温补偿系数
    connect(hpdomainthread,SIGNAL(signal_core_hidemenu_get_para(ComHideMenuPara)),&hpsetting.hphidemenu,SLOT(slot_core_hidemenu_get_para(ComHideMenuPara)));

    connect(this,SIGNAL(signal_pc_hidemenu_get_para()),hpdomainthread,SLOT(slot_pc_sys_get_hidemenu()));

    connect(ui->display,SIGNAL( signal_JPGTemCaptrue_Switch(int) ),&hpsetting,SLOT( slot_JPGTemCaptrue_Switch(int) ));

    //改变镜头或者挡位后，重新设置 para_ 的值
    connect(&hpsetting,SIGNAL(signal_set_para_2123()),&hpsetting.hphidemenu,SLOT(slot_set_para_2123()));
    connect(ui->display,SIGNAL(signal_dev_get_parameter()),hpdomainthread,SLOT(slot_dev_get_parameter()));
     connect(hpdomainthread,SIGNAL(signal_dev_get_parameter(unsigned char*,unsigned char)),&hpsetting,SLOT(slot_dev_get_parameter(unsigned char*,unsigned char)));

    connect(ui->display,SIGNAL(signal_set_resize_nZoomRate10_value(int)),this,SLOT(slot_set_resize_nZoomRate10_value(int)));
    connect(ui->display,SIGNAL(signal_set_nProcessType_value(int,int,int)),this,SLOT(slot_set_nProcessType_value(int,int,int)));

    connect(&hpsetting,SIGNAL(signal_set_globresize_nZoomRate10_value(int)),this,SLOT(slot_set_resize_nZoomRate10_value(int)));

    connect(hpdomainthread,SIGNAL(singal_pc_cfg_get_pointconfig(unsigned char,int)),this,SLOT(slot_pc_cfg_get_pointconfig(unsigned char,int )));
    connect(this, SIGNAL(singal_pc_cfg_get_pointconfig()), hpdomainthread,SLOT(slot_pc_cfg_get_pointconfig()));

    connect(hpdomainthread,SIGNAL(singal_pc_cfg_get_lineconfig(unsigned char,int)),this,SLOT(slot_pc_cfg_get_lineconfig(unsigned char, int)));
    connect(this, SIGNAL(singal_pc_cfg_get_lineconfig()), hpdomainthread,SLOT(slot_pc_cfg_get_lineconfig()));

    connect(hpdomainthread,SIGNAL(singal_pc_cfg_get_rectconfig(unsigned char,int)),this,SLOT(slot_pc_cfg_get_rectconfig(unsigned char, int)));
    connect(this, SIGNAL(singal_pc_cfg_get_rectconfig()), hpdomainthread,SLOT(slot_pc_cfg_get_rectconfig()));

    connect(hpdomainthread,SIGNAL(singal_pc_cfg_get_circleconfig(unsigned char,int)),this,SLOT(slot_pc_cfg_get_circleconfig(unsigned char, int)));
    connect(this, SIGNAL(singal_pc_cfg_get_circleconfig()), hpdomainthread,SLOT(slot_pc_cfg_get_circleconfig()));
    //===============================================================
    //biaoding
    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_pc_image_set_vertical_handle(int)),hpdomainthread,SLOT(slot_pc_image_set_vertical_handle(int)));
    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_pc_image_set_suppression_handle(int)),hpdomainthread,SLOT(slot_pc_image_set_suppression_handle(int)));
    connect(this, SIGNAL(siganl_image_set_gas_para(GasPara)), &hpsetting.hphide_biaoding,SLOT(slot_image_set_gas(GasPara)));
    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_image_set_gas(GasPara)), hpdomainthread, SLOT(slot_image_set_gas(GasPara)));

    connect(hpdomainthread, SIGNAL(signal_pc_spinbox_para(unsigned char)), &hpsetting.hphide_biaoding,SLOT(slot_pc_spinbox_para(unsigned char)));
    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_pc_spinbox_para(int)), hpdomainthread, SLOT(slot_pc_spinbox_para(int)));

    connect(hpdomainthread, SIGNAL(signal_pc_spinbox_zoom(unsigned char)), &hpsetting.hphide_biaoding,SLOT(slot_pc_spinbox_zoom(unsigned char)));
    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_pc_spinbox_zoom(int)), hpdomainthread, SLOT(slot_pc_spinbox_zoom(int)));

    connect(this, SIGNAL(signal_biaoding_ceshi()), &hpsetting.hphide_biaoding, SLOT(slot_biaoding_ceshi()));
    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_biaoding_ceshi_2()), this,SLOT(slot_biaoding_ceshi_2()));

    connect(hpdomainthread,SIGNAL(signal_core_biaoding_zn(int)), this, SLOT(slot_core_biaoding_zn(int)));
    connect(this, SIGNAL(signal_pc_send_biaoding()), hpdomainthread,SLOT(slot_pc_send_biaoding()));

    connect(this, SIGNAL(signal_hphide_biaoding_zn(int)), &hpsetting.hphide_biaoding,   SLOT(slot_hphide_biaoding_zn(int)));

//    connect(hpdomainthread, SIGNAL(signal_core_biaoding_zn(int)), this, SLOT(slot_core_biaoding_zn(int)));
    connect(this, SIGNAL(signal_pc_sys_get_appcontrolstatus()), hpdomainthread, SLOT(slot_pc_sys_get_appcontrolstatus()));
       connect(hpdomainthread, SIGNAL(signal_pc_sys_get_appcontrolstatus(unsigned char, int)), this, SLOT(slot_pc_sys_get_appcontrolstatus(unsigned char, int)));

    connect(hpdomainthread, SIGNAL(signal_core_biaoding_canshu(FPGAMenuPara)), &hpsetting.hphide_biaoding,SLOT(slot_core_biaoding_canshu(FPGAMenuPara)));
    connect(&hpsetting.hphide_biaoding, SIGNAL(single_pc_biaoding_canshu(FPGAMenuPara)), hpdomainthread, SLOT(slot_pc_biaoding_canshu(FPGAMenuPara)));

    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_pc_save_focus_offset(int)), hpdomainthread, SLOT(slot_pc_save_focus_offset(int)));
    connect(hpdomainthread, SIGNAL(signal_pc_focus_offset(unsigned char)), &hpsetting.hphide_biaoding,SLOT(slot_pc_focus_offset(unsigned char)));
    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_pc_focus_offset(ComFocusOffset)), hpdomainthread, SLOT(slot_pc_focus_offset(ComFocusOffset)));
//    connect(this, SIGNAL(signal_pc_focus_offset(int)), hpdomainthread, SLOT(slot_pc_focus_offset(int)));
//    connect(this, SIGNAL(signal_biaoding_focus_offset(int)), &hpsetting.hphide_biaoding,SLOT(slot_biaoding_focus_offset(int)));

    connect(hpdomainthread,SIGNAL(signal_core_biaoding_gray(FPGAMenuGray)),&hpsetting.hphide_biaoding,SLOT(slot_core_biaoding_gray(FPGAMenuGray)));

    connect(&hpsetting.hphide_biaoding,SIGNAL(single_biaoding_HI()),hpdomainthread,SLOT(slot_biaoding_HI()));
    connect(&hpsetting.hphide_biaoding,SIGNAL(single_biaoding_LO()),hpdomainthread,SLOT(slot_biaoding_LO()));
    connect(&hpsetting.hphide_biaoding,SIGNAL(single_biaoding_SAVE()),hpdomainthread,SLOT(slot_biaoding_SAVE()));

    connect(hpdomainthread, SIGNAL(signal_core_fpga_get_svrd(unsigned char, int)), &hpsetting.hphide_biaoding, SLOT(slot_core_fpga_get_svrd(unsigned char, int)));
    connect(hpdomainthread, SIGNAL(signal_core_fpga_get_adgain(unsigned char, int)), &hpsetting.hphide_biaoding, SLOT(slot_core_fpga_get_adgain(unsigned char, int)));
    connect(hpdomainthread, SIGNAL(signal_core_fpga_get_intcp(unsigned char, int)), &hpsetting.hphide_biaoding, SLOT(slot_core_fpga_get_intcp(unsigned char, int)));
    connect(hpdomainthread, SIGNAL(signal_core_fpga_get_fos(unsigned char, int)), &hpsetting.hphide_biaoding, SLOT(slot_core_fpga_get_fos(unsigned char, int)));

    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_core_fpga_get_svrd()), hpdomainthread, SLOT(slot_core_fpga_get_svrd()));
    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_core_fpga_get_adgain()), hpdomainthread, SLOT(slot_core_fpga_get_adgain()));
    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_core_fpga_get_intcp()), hpdomainthread, SLOT(slot_core_fpga_get_intcp()));
    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_core_fpga_get_fos()), hpdomainthread, SLOT(slot_core_fpga_get_fos()));

    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_core_fpgamenu_set_svrd(int)),hpdomainthread,SLOT(slot_core_fpgamunu_set_svrd(int)));
    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_core_fpgamenu_set_adgain(int)),hpdomainthread,SLOT(slot_core_fpgamunu_set_adgain(int)));
    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_core_fpgamenu_set_intcp(int)),hpdomainthread,SLOT(slot_core_fpgamunu_set_intcp(int)));
    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_core_fpgamenu_set_fos(int)),hpdomainthread,SLOT(slot_core_fpgamunu_set_fos(int)));
    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_core_fpgamenu_occ_enable(int)),hpdomainthread,SLOT(slot_core_fpgamunu_set_occ_enable(int)));

    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_core_fpgamenu_noise_time_para(int)),hpdomainthread,SLOT(slot_core_fpgamenu_noise_time_para(int)));
    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_core_fpgamenu_noise_airspace_para(int)),hpdomainthread,SLOT(slot_core_fpgamenu_noise_airspace_para(int)));

    //设置死线 X、Y轴
    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_set_core_fpgamenu_badline_x(int)),hpdomainthread,SLOT(slot_set_core_fpgamenu_badline_x(int)));
    connect(hpdomainthread,SIGNAL(signal_set_core_fpgamenu_badline_x(unsigned char)),&hpsetting.hphide_biaoding,SLOT(slot_set_core_fpgamenu_badline_x(unsigned char)));
    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_set_core_fpgamenu_badline_y(int)),hpdomainthread,SLOT(slot_set_core_fpgamenu_badline_y(int)));
    connect(hpdomainthread,SIGNAL(signal_set_core_fpgamenu_badline_y(unsigned char)),&hpsetting.hphide_biaoding,SLOT(slot_set_core_fpgamenu_badline_y(unsigned char)));
    //两个不同的调用灰度的方式

    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_biaoding_para_ok()), hpdomainthread,SLOT(slot_biaoding_para_ok()));       //标定界面初始化  灰度
    connect(&hpsetting,SIGNAL(signal_setting_close()),this,SLOT(slot_setting_close()));

    connect(&hpsetting.hphide_biaoding,SIGNAL(single_biaoding_tiaoling()),this,SLOT(slot_all_tiaoling_2()));          //标定界面的Q
    connect(this,SIGNAL(signal_mainwidget_tiaoling()),this,SLOT(slot_all_tiaoling_2()));                                              //主界面的Q +板子按键（a）

    connect(&hpsetting,SIGNAL(signal_autoupdate_return()),this,SLOT(autoUpdateClose()));
    //===========================hppreview
    connect(hpsetting.hpformat,SIGNAL(signal_sd_formatting()),hppreview,SLOT(slot_sd_formatting()));
    connect(&hpsetting,SIGNAL(signal_set_usbmode(int)),this,SLOT(slot_set_usbmode(int)));

    connect(hppreview,SIGNAL(signal_pic_twice_begin()),this,SLOT(slot_pic_twice_begin()));                                    //预览界面传递信息，点击二次分析按钮时
    connect(this,SIGNAL(signal_twice_lastpage()),hppreview,SLOT(slot_twice_lastpage()));
    connect(this,SIGNAL(signal_twice_nextpage()),hppreview,SLOT(slot_twice_nextpage()));

    connect(hppreview,SIGNAL(signal_core_analysis_pic_twice_stop_cut()),hpdomainthread,SLOT(slot_core_annlysis_pic_twice_stop()));
    connect(hppreview,SIGNAL(signal_pic_twice_type(int,int)),this,SLOT(slot_pic_twice_type(int,int)));

    connect(&hppreview->hhp,SIGNAL(signal_core_analysis_hir_twice_stop_cut()),hpdomainthread,SLOT(slot_core_annlysis_hir_twice_stop()));
    connect(hpdomainthread,SIGNAL(signal_core_analysis_hir_twice_stop_cut(unsigned char)),this,SLOT(slot_core_annlysis_hir_twice_stop(unsigned char)));

    connect(&hppreview->hhp,SIGNAL(signal_core_get_hir_play_status()),hpdomainthread,SLOT(slot_core_get_hir_play_status()));
    connect(hpdomainthread,SIGNAL(signal_core_get_hir_play_status(unsigned char,int)),&hppreview->hhp,SLOT(slot_core_get_hir_play_status(unsigned char,int)));


    connect(&hppreview->hhp,SIGNAL(signal_core_annlysis_hir_twice_suspend(int)),hpdomainthread,SLOT(slot_core_annlysis_hir_twice_suspend(int)));
    connect(this,SIGNAL(signal_core_annlysis_hir_twice_suspend(int)),hpdomainthread,SLOT(slot_core_annlysis_hir_twice_suspend(int)));
    connect(hpdomainthread,SIGNAL(signal_core_annlysis_hir_twice_suspend(unsigned char)),this,SLOT(slot_core_annlysis_hir_twice_suspend(unsigned char)));

    connect(this,SIGNAL(signal_twice_pic_start()),hppreview,SLOT(slot_twice_pic_start()));

    connect(hppreview,SIGNAL(signal_pic_kjg_open(QString)),&hp_twice_pic,SLOT(slot_pic_kjg_open(QString)));
    connect(hppreview,SIGNAL(signal_pic_kjg_on(QString)),&hp_twice_kjg,SLOT(slot_pic_kjg_on(QString)));

    //Hp_Camera_Cap *hpcameracap;
    connect(hpcameracap,SIGNAL(signal_cameracap_set_lcd_offed_state()),this,SLOT(slot_mainset_lcd_offed_state()));
    connect(&hp_twice_kjg,SIGNAL(signal_twicekjg_set_lcd_offed_state()),this,SLOT(slot_mainset_lcd_offed_state()));

    connect(hta,SIGNAL(signal_twiceanalysis_set_lcd_offed_state()),this,SLOT(slot_mainset_lcd_offed_state()));

    connect(hta,SIGNAL(signal_core_get_twice_audio_status()),sd_hpdomain,SLOT(slot_core_get_twice_audio_status()));
    connect(sd_hpdomain,SIGNAL(signal_core_get_twice_audio_status(unsigned char, int)),hta,SLOT(slot_core_get_twice_audio_status(unsigned char, int)));
    connect(hta,SIGNAL(signal_core_analysis_pic_twice_audioplay_start()),hpdomainthread,SLOT(slot_core_analysis_pic_twice_audioplay_start()));
    connect(hpdomainthread,SIGNAL(signal_core_analysis_pic_twice_audioplay_start(unsigned char)),hta,SLOT(slot_core_analysis_pic_twice_audioplay_start(unsigned char)));
    connect(hta,SIGNAL(signal_core_analysis_pic_twice_audioplay_stop()),hpdomainthread,SLOT(slot_core_analysis_pic_twice_audioplay_stop()));
    connect(hpdomainthread,SIGNAL(signal_core_analysis_pic_twice_audioplay_stop(unsigned char)),hta,SLOT(slot_core_analysis_pic_twice_audioplay_stop(unsigned char)));
    connect(hta,SIGNAL(signal_core_analysis_pic_twice_audiocap_start()),hpdomainthread,SLOT(slot_core_analysis_pic_twice_audiocap_start()));
    connect(hpdomainthread,SIGNAL(signal_core_analysis_pic_twice_audiocap_start(unsigned char)),hta,SLOT(slot_core_analysis_pic_twice_audiocap_start(unsigned char)));
    connect(hta,SIGNAL(signal_core_analysis_pic_twice_audiocap_stop()),hpdomainthread,SLOT(slot_core_analysis_pic_twice_audiocap_stop()));
    connect(hpdomainthread,SIGNAL(signal_core_analysis_pic_twice_audiocap_stop(unsigned char)),hta,SLOT(slot_core_analysis_pic_twice_audiocap_stop(unsigned char)));
    connect(hta,SIGNAL(signal_core_analysis_pic_twice_addaudio()),hpdomainthread,SLOT(slot_core_analysis_pic_twice_addaudio()));
    connect(hta,SIGNAL(signal_core_analysis_pic_twice_cancelaudio()),hpdomainthread,SLOT(slot_core_analysis_pic_twice_cancelaudio()));
    connect(hta,SIGNAL(signal_core_analysis_pic_twice_addtext(char* )),hpdomainthread,SLOT(slot_core_analysis_pic_twice_addtext(char*)));

    connect(this,SIGNAL(signal_pc_key_auto_focus()),hpdomainthread,SLOT(slot_pc_key_auto_focus()));
    connect(hpdomainthread,SIGNAL(signal_pc_key_auto_focus(unsigned char)),this,SLOT(slot_pc_key_auto_focus(unsigned char)));

    connect(this,SIGNAL(signal_pc_key_focus_near()),hpdomainthread,SLOT(slot_pc_key_focus_near()));
    connect(this,SIGNAL(signal_pc_key_focus_far()),hpdomainthread,SLOT(slot_pc_key_focus_far()));
    connect(this,SIGNAL(signal_pc_key_focus_stop()),hpdomainthread,SLOT(slot_pc_key_focus_stop()));
    connect(this,SIGNAL(signal_pc_key_focus_adjust(int)),hpdomainthread,SLOT(slot_pc_key_focus_adjust(int)));


    connect(&hpsetting,SIGNAL(signal_pc_measure_set_compensate(int)),hpdomainthread,SLOT(slot_pc_measure_set_compensate(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_set_compensate(unsigned char)),&hpsetting,SLOT(slot_pc_measure_set_compensate(unsigned char)));

    connect( ContinuedFreezeTimer,SIGNAL( timeout() ) ,this,SLOT( SlotContinuedFreezeTimer() ) );
    connect(timer_10s, SIGNAL(timeout()), this, SLOT(slot_timeout_pc_key_auto_focus()));
//    connect(timerConsercutiveLaser, SIGNAL(timeout()), this, SLOT(getLaserRangeOnce()));
    connect(timer_5min, SIGNAL(timeout()), this, SLOT(slot_timeout_close_laserRange()));
    connect( &hpsetting,SIGNAL(SignalAutoSave(int)),this,SLOT(SlotAutoSave(int)) );
    connect(hpsetting.hp_wifi_Search,SIGNAL(signal_SetMainWifiDisconnect()),this,SLOT(slot_SetMainWifiDisconnect()));
    connect(hpcameracap,SIGNAL(signal_set_Dialog(QString,int)),this,SLOT(slot_SetMainCameraCapDialog(QString,int)));

    connect(this,SIGNAL(signal_twice_voiceStop()),hta,SLOT(slot_return_close_voice_r()));
    connect(this,SIGNAL(signal_twice_voicep_Stop()),hta,SLOT(slot_return_close_voice_p()));

    //获取激光测距的值
    connect(this, SIGNAL(signal_pc_sys_get_laserrange()), hpdomainthread, SLOT(slt_pc_sys_get_laserrange()));
    connect(hpdomainthread, SIGNAL(signal_pc_sys_get_laserrange(unsigned char, int)), this, SLOT(slt_pc_sys_get_laserrange(unsigned char, int)));
    connect(&hphidelaser, SIGNAL(signal_hide_laser_get_lasserRange()), this, SLOT(getLaserRangeOnce()));
    connect(this,SIGNAL(signal_pc_sys_set_laserrange()),hpdomainthread,SLOT(slot_pc_sys_set_laserrange()));

    //控制激光测距的开关
    connect(this, SIGNAL(signal_pc_key_laser(int)), hpdomainthread, SLOT(slot_pc_key_laser(int)));
    connect(hpdomainthread, SIGNAL(signal_pc_key_laser(unsigned char)), this, SLOT(slot_pc_key_laser(unsigned char)));

    connect( &hpsetting,SIGNAL(SignalSetImageSR(bool) ),hpcameracap,SLOT( SlotSetImageSR(bool) ) );
    connect( &hpsetting,SIGNAL(SignalSetImageSR(bool) ),this,SLOT( SlotSetImageSR(bool) ) );
    //设置异常区域
    connect(this,SIGNAL(signal_pc_image_set_abnormal(int)),hpdomainthread,SLOT(slot_pc_image_set_abnormal(int)) );
    connect( &hpsetting,SIGNAL(signal_pc_image_set_abnormal(int)),hpdomainthread,SLOT(slot_pc_image_set_abnormal(int)) );
    connect( hpdomainthread,SIGNAL(signal_pc_image_set_abnormal(unsigned char)),&hpsetting,SLOT(slot_pc_image_set_abnormal(unsigned char)) );

    //设置二次分析下的文字注释显示与否
    connect(hta,SIGNAL(signal_set_twice_text(bool,QString)),this,SLOT(slot_set_twice_text(bool,QString)));
    connect(hppreview,SIGNAL(signal_send_twice_text()),hta,SLOT(slot_send_twice_text()));
    connect(hta,SIGNAL(signal_to_send_twice_text(QString)),this,SLOT(slot_to_set_twice_text(QString)));
    connect(hppreview,SIGNAL(signal_twice_text_show_or_not(int)),this,SLOT(slot_twice_text_show_or_not(int)));

    connect(&hpsetting,SIGNAL(signal_set_IsInlcdoff(bool)),this,SLOT(slot_set_IsInlcdoff(bool)));
    connect(&hpsetting,SIGNAL(signal_StartAutoUpload_once(bool)),this,SLOT(slot_StartAutoUpload_once(bool)));

    connect(&hppreview->hhp,SIGNAL(signal_start_hir_analyse(QString,bool)),this,SLOT(slot_start_hir_analyse(QString,bool)));
    connect(&hppreview->hhp,SIGNAL(signal_playstatusTimeout()),this,SLOT(slot_stop_hir_analyse()));

//    connect(&hppreview->hhp,SIGNAL(signal_hir_analyse_get_measure()),this,SLOT(slot_hir_analyse_get_measure()));
    connect(&hppreview->hhp,SIGNAL(signal_clear_measure()),this,SLOT(slot_hir_analyse_clear_measure()));

    connect(ui->toolButton_pause,SIGNAL(clicked(bool)),this,SLOT(toolButton_pause_Clicked(bool)));

    connect(this,SIGNAL(signal_hir_twice_get_zoom()),hpdomainthread,SLOT(slot_hir_twice_get_zoom()));
    connect(hpdomainthread,SIGNAL(signal_hir_twice_get_zoom(unsigned char,int)),this,SLOT(slot_hir_twice_get_zoom(unsigned char,int)));

    connect(this,SIGNAL(signal_hir_twice_get_colorrule()),hpdomainthread,SLOT(slot_hir_twice_get_colorrule()));
    connect(hpdomainthread,SIGNAL(signal_hir_twice_get_colorrule(unsigned char,int)),this,SLOT(slot_hir_twice_get_colorrule(unsigned char,int)));

    connect(this,SIGNAL(signal_hir_twice_lockstatus(int)),hpdomainthread,SLOT(slot_hir_twice_lockstatus(int)));
    connect(hpdomainthread,SIGNAL(signal_hir_twice_lockstatus(unsigned char)),this,SLOT(slot_hir_twice_lockstatus(unsigned char)));

    connect(hpsetting.hp_downLoad,SIGNAL(signal_pc_sys_set_filequery(ftp_para)),hpdomainthread,SLOT(slot_pc_sys_set_filequery(ftp_para)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_filequery(unsigned char,QString,char*,int)),hpsetting.hp_downLoad,SLOT(slot_pc_sys_set_filequery(unsigned char,QString,char*,int)));

    connect(hpsetting.hp_downLoad,SIGNAL(signal_pc_sys_set_download(ftp_para)),hpdomainthread,SLOT(slot_pc_sys_set_download(ftp_para)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_download(unsigned char)),hpsetting.hp_downLoad,SLOT(slot_pc_sys_set_download(unsigned char)));

    connect(&hpsetting,SIGNAL(signal_set_HDMI(int)),hpdomainthread, SLOT(slot_pc_sys_set_HDMI_switch(int)));
    connect(this,SIGNAL(signal_set_HDMI(int)),hpdomainthread, SLOT(slot_pc_sys_set_HDMI_switch(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_HDMI(unsigned char)),&hpsetting,SLOT(slot_pc_sys_set_HDMI(unsigned char)));
    connect(this, SIGNAL(signal_pc_sys_set_analog_video(int)), hpdomainthread, SLOT(slot_pc_sys_set_analog_video(int)));
    connect(hpcameracap,SIGNAL(signal_set_audio(bool, int)),this, SLOT(set_audio(bool, int)));
    connect(&hppreview->hmp,SIGNAL(signal_set_audio(bool, int)),this, SLOT(set_audio(bool, int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_analog_video(unsigned char)),this, SLOT(slot_pc_sys_set_analog_video(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_analog_video(unsigned char)),hpcameracap, SLOT(slot_pc_sys_set_analog_video(unsigned char)));
    connect(this,SIGNAL(signal_pc_measure_tempcenter(int)),hpdomainthread,SLOT(slot_pc_measure_tempcenter(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_tempcenter(unsigned char)),this,SLOT(slot_pc_measure_tempcenter(unsigned char)));

    //关联lcd刷新时间
    connect(&hpsetting.hpblesearchold,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hpsebiao,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(ui->display,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(hppreview,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hpresize,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hpmode,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&ui->display->hpdeledit,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(hpcameracap,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hpcameracap->hti,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hpmodehzhadjust,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hpmoderdjadjust,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(hta,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hta->hti,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hp_twice_kjg,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hp_twice_pic,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hmp,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hppreview->hmp,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hppreview->hp_text_input,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hpsetting.hpblesearch,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(this,SIGNAL(signal_pc_sys_set_ble_power(int)),hpdomainthread,SLOT( slot_pc_sys_set_ble_power(int)));
    connect(&hpsetting,SIGNAL(signal_pc_sys_set_ble_power(int)),hpdomainthread,SLOT( slot_pc_sys_set_ble_power(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_ble_power(unsigned char)), &hpsetting,SLOT(slot_pc_sys_set_ble_power(unsigned char)));
    connect(&hpsetting,SIGNAL(signal_pc_sys_set_ble_switch(int)),hpdomainthread,SLOT(slot_pc_sys_set_ble_switch(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_ble_switch(unsigned char)),&hpsetting,SLOT(slot_pc_sys_set_ble_switch(unsigned char)));
    connect(&hpsetting,SIGNAL(signal_pc_sys_set_ble_module(int)),hpdomainthread,SLOT(slot_pc_sys_set_ble_module(int)));
    connect(this,SIGNAL(signal_pc_sys_set_ble_module(int)),hpdomainthread,SLOT(slot_pc_sys_set_ble_module(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_ble_module(unsigned char)),&hpsetting,SLOT(slot_pc_sys_set_ble_module(unsigned char)));

    connect(&hpsetting.hpblesearch,SIGNAL(signal_pc_sys_set_ble_function(BleInfo)),hpdomainthread,SLOT(slot_pc_sys_set_ble_function(BleInfo)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_ble_function(unsigned char)),&hpsetting.hpblesearch,SLOT(slot_pc_sys_set_ble_function(unsigned char)));
    connect(&hpsetting.hpblesearch,SIGNAL(signal_pc_sys_get_ble_info(int)),hpdomainthread,SLOT(slot_pc_sys_get_ble_info(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_get_ble_info(unsigned char, QString)),&hpsetting.hpblesearch,SLOT(slot_pc_sys_get_ble_info(unsigned char, QString)));
    connect(&hpsetting.hpblesearch,SIGNAL(signal_core_get_ble_status()),sd_hpdomain,SLOT(slot_core_get_ble_status()));
    connect(sd_hpdomain,SIGNAL(signal_get_ble_state(unsigned char, BleState)),&hpsetting.hpblesearch,SLOT(slot_get_ble_state(unsigned char, BleState)));
//    connect(hpdomainthread,SIGNAL(signal_get_ble_state(unsigned char, BleState)),&hpsetting.hpblesearch,SLOT(slot_get_ble_state(unsigned char, BleState)));


    connect(hpsetting.hp_wifi_Search,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hpsetting.hp_wifi_Search->hti,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(hpsetting.hp_autoupload,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hpsetting.hp_autoupload->hti,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&hpsetting,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(this,SIGNAL(signal_measure_reflect_temp(int)), &hpsetting, SLOT(slot_measure_reflect_temp(int)));
    connect(hpsetting.hp_Mulhom_edit,SIGNAL(signal_update_lcdoff_time(bool)),this,SLOT(slot_update_lcdoff_time(bool)));
    connect(&panorama_dialog, SIGNAL(signal_update_lcdoff_time(bool)), this, SLOT(slot_update_lcdoff_time(bool)));
    connect(hp_panorama, SIGNAL(signal_update_lcdoff_time(bool)), this, SLOT(slot_update_lcdoff_time(bool)));
    //自动上传连接服务器
    connect(hpsetting.hp_autoupload,SIGNAL(siganl_pc_sys_set_newserve_con(server_para)),hpdomainthread,SLOT(slot_pc_sys_set_newserve_con(server_para)));
    connect(hpsetting.hp_autoupload,SIGNAL(siganl_pc_sys_set_serve_con(client_para)),hpdomainthread,SLOT(slot_pc_sys_set_serve_con(client_para)));
    connect(hpdomainthread,SIGNAL(siganl_pc_sys_set_serve_con(unsigned char)),hpsetting.hp_autoupload,SLOT(slot_pc_sys_set_serve_con(unsigned char)));

    //自动上传取消连接服务器
    connect(hpsetting.hp_autoupload,SIGNAL(signal_pc_sys_newcancel_autoupload(server_para)),sd_hpdomain,SLOT(slot_pc_sys_set_newserve_con(server_para)));
    connect(hpsetting.hp_autoupload,SIGNAL(signal_pc_sys_cancel_autoupload(client_para)),sd_hpdomain,SLOT(slot_pc_sys_set_serve_con(client_para)));
    connect(sd_hpdomain,SIGNAL(siganl_pc_sys_set_serve_con(unsigned char)),hpsetting.hp_autoupload,SLOT(slot_pc_sys_cancel_autoupload(unsigned char)));

    //中断上传
    connect(hpsetting.hp_autoupload,SIGNAL(signal_pc_sys_set_sevsend_break()),sd_hpdomain,SLOT(slot_pc_sys_set_sevsend_break()));
    connect(sd_hpdomain,SIGNAL(signal_pc_sys_set_sevsend_break(unsigned char)),hpsetting.hp_autoupload,SLOT(slot_pc_sys_set_sevsend_break(unsigned char)));

    connect(hpcameracap,SIGNAL(signal_pc_cmd_set_pc_pic_srv(char*)),hpdomainthread,SLOT(slot_pc_cmd_set_pc_pic_srv(char*)));
    connect(this,SIGNAL(signal_pc_cmd_set_pc_pic_srv(char*)),hpdomainthread,SLOT(slot_pc_cmd_set_pc_pic_srv(char*)));
    connect(hpdomainthread,SIGNAL(signal_pc_cmd_set_pc_pic_srv(unsigned char)),hpcameracap,SLOT(slot_pc_cmd_set_pc_pic_srv(unsigned char)));
    connect(hpdomainthread,SIGNAL(signal_pc_cmd_set_pc_pic_srv(unsigned char)),this,SLOT(slot_pc_cmd_set_pc_pic(unsigned char)));

    connect(hpcameracap,SIGNAL(signal_srvupload_cancel()),hpsetting.hp_autoupload,SLOT(slot_srvupload_cancel()));

    connect(hpdomainthread, SIGNAL(signal_biaoding_DDE(unsigned char)), &hpsetting.hphide_biaoding,SLOT(slot_biaoding_DDE(unsigned char)));
    connect(&hpsetting.hphide_biaoding, SIGNAL(signal_biaoding_DDE(int)), hpdomainthread, SLOT(slot_biaoding_DDE(int)));

    connect(hpdomainthread, SIGNAL(signal_pc_checkbox_rotate(unsigned char)), &hpsetting.hphide_biaoding,SLOT(slot_pc_checkbox_rotate(unsigned char)));
    connect(&hpsetting, SIGNAL(signal_hidemenu_ImageChange(ComTempRange)), hpdomainthread, SLOT(slot_pc_checkbox_rotate(ComTempRange)));

    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_core_fpgamenu_auto_badixel(int)),hpdomainthread,SLOT(slot_core_fpgamenu_auto_badixel(int)));
    connect(hpdomainthread,SIGNAL(signal_core_fpgamenu_auto_badixel(unsigned char)),&hpsetting.hphide_biaoding,SLOT(slot_core_fpgamenu_auto_badixel(unsigned char)));
    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_core_fpgamenu_value_badixel(int)),hpdomainthread,SLOT(slot_core_fpgamenu_value_badixel(int)));

    connect(&hpsetting,SIGNAL(signal_pc_sys_set_step_zero(int)),hpdomainthread,SLOT(slot_pc_sys_set_step_zero(int)));
    connect(&hpsetting,SIGNAL(signal_core_fpgamenu_oritoggle(int)),hpdomainthread,SLOT(slot_core_fpgamenu_oritoggle(int)));
    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_core_fpgamenu_oritoggle(int)),hpdomainthread,SLOT(slot_core_fpgamenu_oritoggle(int)));
    connect(hpdomainthread,SIGNAL(signal_core_fpgamenu_oritoggle(unsigned char)),&hpsetting.hphide_biaoding,SLOT(slot_core_fpgamenu_oritoggle(unsigned char)));

    connect(&hpsetting.hphide_biaoding,SIGNAL(signal_core_fpgamenu_badpixel_recover()),hpdomainthread,SLOT(slot_core_fpgamenu_badpixel_recover()));
    connect(hpdomainthread,SIGNAL(signal_core_fpgamenu_badpixel_recover(unsigned char)),&hpsetting.hphide_biaoding,SLOT(slot_core_fpgamenu_badpixel_recover(unsigned char)));

    connect(&hpsetting,SIGNAL(signal_pc_sys_set_autofocusmode(int)),&hpsetting.hphide_biaoding,SLOT(hp_setautofocusmode(int)));

    connect(&hpsetting,SIGNAL(signal_pc_sys_set_wifi_power(int)),hpdomainthread,SLOT(slot_pc_sys_wifi_power(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_wifi_power(unsigned char)),&hpsetting,SLOT(slot_pc_sys_set_wifi_power(unsigned char)));

//    connect(&hpsetting,SIGNAL(signal_set_qrcode_switch(int)),hpdomainthread, SLOT(slot_pc_sys_set_qrcode_switch(int)));
    connect(this,SIGNAL(signal_set_qrcode_switch(int)),hpdomainthread, SLOT(slot_pc_sys_set_qrcode_switch(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_qrcode_switch(unsigned char)),this,SLOT(slot_pc_sys_set_qrcode_switch(unsigned char)));
//    connect(&hpsetting,SIGNAL(signal_set_qrcode_state(bool)),this, SLOT(slot_set_qrcode_state(bool)));

    connect(hpsis_content,SIGNAL(signal_on_pushButton_ok_or_cannal(int,QString)),this,SLOT(slot_ok_or_cannal_sis_swicth(int,QString)));
//    connect(this,SIGNAL(signal_close_sis_switch()),&hpsetting,SLOT(clot_close_sis_switch()));
    connect(this,SIGNAL(signal_set_sis_label(unsigned char*)),hpsis_content,SLOT(slot_set_label_text(unsigned char*)));

    connect(this,SIGNAL(signal_get_qrcode_info()),hpdomainthread, SLOT(slot_pc_sys_get_qrcode_info()));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_get_qrcode_info(unsigned char ,unsigned char *)),this,SLOT(slot_pc_sys_get_qrcode_info(unsigned char ,unsigned char *)));

    connect(&hpsetting,SIGNAL(SignalSetImageSIS(bool)),this,SLOT(slot_close_sis_mode(bool)));
    connect( &hpsetting,SIGNAL( SignalSetImageSIS(bool) ),hpcameracap,SLOT( SlotSetImageSis(bool) ) );

    connect(&hpsetting,SIGNAL(signal_pc_measure_mulhomogeneity(int)),hpdomainthread,SLOT(slot_pc_measure_mulhomogeneity(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_mulhomogeneity(unsigned char)),&hpsetting,SLOT(slot_pc_measure_mulhomogeneity(unsigned char)));

    connect(pictureModeObject,SIGNAL(signal_un_freeze()),this,SLOT(slot_un_freeze()));
    connect(pictureModeObject,SIGNAL(signal_wait_warn()),this,SLOT(slot_wait_warn()));
    connect( pictureModeObject,SIGNAL(signal_temp_row_mode(int)),this,SLOT(slot_temp_row_mode(int)) );
    connect(&hpsetting,SIGNAL(signal_stop_AviMode(bool)),this,SLOT(slot_stop_AviMode(bool)));
    connect(&hpsetting,SIGNAL(signal_stop_TextVoice(bool)),hpcameracap,SLOT(slot_stop_TextVoice(bool)));  //国网模式关闭录音 和文本
    connect(hpcameracap,SIGNAL(signal_wait_warn_save()),this,SLOT(slot_wait_warn_save()));

    connect(hpcameracap,SIGNAL(signal_should_make_pms_json(QString)),this,SLOT(slot_should_make_pms_json(QString)));
    connect(hp_Pms,SIGNAL(signal_selectChanged(int)),this,SLOT(slot_pms_select_changed(int)));
    connect(hp_Pms,SIGNAL(signal_upload_pms_dat()),this,SLOT(slot_upload_pms_dat()));
    connect(hp_Pms,SIGNAL(signal_close_pms()),this,SLOT(slot_close_pms()));
    connect(hp_Pms, SIGNAL(signal_open_mode()), this, SLOT(slot_open_mode()));
    connect(hp_Pms,SIGNAL(signal_sould_showDialog(QString,int)),this,SLOT(slot_SetMainCameraCapDialog(QString,int)));//设置弹窗
    connect(hp_Pms,SIGNAL(signal_take_picture()),this,SLOT(slot_take_picture()));
    connect(hp_Pms,SIGNAL(signal_set_focus()),this,SLOT(slot_set_focus()));
    connect(hp_Pms, SIGNAL(signal_update_lcdoff_time(bool)), this, SLOT(slot_update_lcdoff_time(bool)));

    connect(&hpsetting,SIGNAL(signal_pc_measure_temprange_query(ComTempRange)),hpdomainthread,SLOT(slot_pc_measure_temprange_query(ComTempRange)));
    connect(hpdomainthread,SIGNAL(signal_pc_measure_temprange_query(unsigned char,int)),this,SLOT(slot_pc_measure_temprange_query(unsigned char,int)));
    //FPGA固件版本号显示
    connect(this,SIGNAL(signal_core_fpga_get_ver()),hpdomainthread,SLOT(slot_core_fpga_get_ver()));
    connect(hpdomainthread,SIGNAL(signal_core_fpga_get_ver(unsigned char, int)),&hpsetting,SLOT(slot_core_fpga_get_ver(unsigned char, int)));

    connect(&hpsetting.m_hotkeyWidget, SIGNAL(signal_hotkey_set_key_focus(KEYSETTING)), this, SLOT(slot_hotkey_set_key_focus(KEYSETTING)));
    connect(&hpsetting.m_hotkeyWidget, SIGNAL(signal_hotkey_set_key_camera(KEYSETTING)), this, SLOT(slot_hotkey_set_key_camera(KEYSETTING)));
    connect(&hpsetting.hpblesearch,SIGNAL(signal_core_key_add_audio_start()),hpdomainthread,SLOT(slot_core_key_add_audio_start()));
    connect(hpdomainthread,SIGNAL(signal_core_key_add_audio_start(unsigned char)),&hpsetting.hpblesearch,SLOT(slot_core_key_add_audio_start(unsigned char)));

    connect(&hpsetting.hpblesearch,SIGNAL(signal_core_key_add_audio_stop()),hpdomainthread,SLOT(slot_core_key_add_audio_stop()));
    connect(hpdomainthread,SIGNAL(signal_core_key_add_audio_stop(unsigned char, int)),&hpsetting.hpblesearch,SLOT(slot_core_key_add_audio_stop(unsigned char, int)));

    connect(&hpsetting,SIGNAL(signal_set_ETH_switch(int)),hpdomainthread, SLOT(slot_pc_sys_set_ETH_switch(int)));
    connect(hpdomainthread,SIGNAL(signal_pc_sys_set_ETH_switch(unsigned char)),&hpsetting,SLOT(slot_pc_sys_set_ETH_switch(unsigned char)));
    connect(&hpsetting,SIGNAL(signal_pc_sys_set_wifi_eth_close(int)),this,SLOT(slot_wifi_eth_close(int)));
    connect(&hpsetting,SIGNAL(signal_sketch_switch(int)),this,SLOT(slot_signal_sketch_switch(int)));
    connect(&hpsetting,SIGNAL(signal_set_image_format(int)),this,SLOT(slot_set_image_format(int)));
    connect(&hpsetting,SIGNAL(signal_pc_image_set_sketch_clear()),hpdomainthread,SLOT(slot_pc_image_set_sketch_clear()));
    connect(&hpsetting,SIGNAL(signal_pc_key_focus_select(int)),hpdomainthread,SLOT(slot_pc_key_focus_select(int)));
    connect(&hpsetting,SIGNAL(signal_pc_key_focus_stop_aut(bool)),this,SLOT(slot_stop_focus_aut(bool)));
    connect(hpsetting.m_Transmission, SIGNAL(signal_transmission_send_upload_success()), this, SLOT(slot_transmission_send_upload_success()));
    connect(&timer_task,SIGNAL(timeout()),this,SLOT(slot_timer_task()));
    connect(hpcameracap,SIGNAL(SingalSendDateFolderPath(QString)),hppreview,SLOT(SlotSendDateFolderPath(QString)));
    connect(hpcameracap,SIGNAL(SingalSendDateFolderPath(QString)),&hp_twice_pic,SLOT(SlotSendDateFolderPath(QString)));
    connect(hpcameracap,SIGNAL(SingalSendDateFolderPath(QString)),&hp_twice_kjg,SLOT(SlotSendDateFolderPath(QString)));
    connect(&hpsetting,SIGNAL(SignalCheckAndCreateDateFolder()),hpcameracap,SLOT(SlotCheckAndCreateDateFolder()));
    connect(&hpsetting,SIGNAL(SignalClearMaxRectPara()),ui->display,SLOT(SlotClearMaxRectPara()));

    timer_task.start(300);
    if(Area_Mode)//当测面积打开时，开机发送一个 信号给主程序，使侧面积初始状态是关闭的
    {
        signal_pc_image_set_abnormal(0);
    }

    if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
        qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
    }

    hpsetting.save_start_error_about_temp();

    QString hotkeyType;
    hotkeyType = hpxmlreader.readXml("sys.xml","HOTKEY","focus");
    if(!hpxmlreader.errorRead)
    {
        m_hotKey1 = (KEYSETTING)hotkeyType.toInt();
        hpsetting.m_hotkeyWidget.setFocusType(m_hotKey1);
    }
    else
    {
        m_hotKey1 = HOTKEY_FOCUS;
        hpsetting.m_hotkeyWidget.setFocusType(m_hotKey1);
    }

    hotkeyType = hpxmlreader.readXml("sys.xml","HOTKEY","camera");
    if(!hpxmlreader.errorRead)
    {
        m_hotKey0 = (KEYSETTING)hotkeyType.toInt();
        hpsetting.m_hotkeyWidget.setCameraType(m_hotKey0);
    }
    else
    {
        m_hotKey0 = HOTKEY_CAMERA;
        hpsetting.m_hotkeyWidget.setCameraType(m_hotKey0);
    }
    QString numPara;
    int point_count = 20;
    int line_count = 20;
    int rect_count = 20;
    int circle_count = 20;
    int polygon_count = 20;
    for(int i = 0;i <= 10;i++)
    {
        numPara = hpxmlreader.readXml("sys.xml","ZONE","point_num");
        if(!hpxmlreader.errorRead)
        {
            point_count = numPara.toInt();
            break;
        }
    }
    for(int i = 0;i <= 10;i++)
    {
        numPara = hpxmlreader.readXml("sys.xml","ZONE","line_num");
        if(!hpxmlreader.errorRead)
        {
            line_count = numPara.toInt();
            break;
        }
    }
    for(int i = 0;i <= 10;i++)
    {
        numPara = hpxmlreader.readXml("sys.xml","ZONE","rect_num");
        if(!hpxmlreader.errorRead)
        {
            rect_count = numPara.toInt();
            break;
        }
    }
    for(int i = 0;i <= 10;i++)
    {
        numPara = hpxmlreader.readXml("sys.xml","ZONE","circle_num");
        if(!hpxmlreader.errorRead)
        {
            circle_count = numPara.toInt();
            break;
        }
    }
    for(int i = 0;i <= 10;i++)
    {
        numPara = hpxmlreader.readXml("sys.xml","ZONE","polygon_num");
        if(!hpxmlreader.errorRead)
        {
            polygon_count = numPara.toInt();
            break;
        }
    }
    ui->display->display_set_max_num(point_count, line_count, rect_count, circle_count, polygon_count);
    QString paras2;//读取标定界面侧面积的值，设置标定界面对应对话框的值为读取的值，并发送信号给主程序告知读取的值
    int facus = 75;
    for(int i = 0;i <= 10;i++)
    {
        paras2 = hpxmlreader.readXml("config.xml","FOCUSOFFSET","laser"); //查询sys.xml文件中的FOCUSOFFSET字段下的laser的内容
        if(!hpxmlreader.errorRead)
        {
            qDebug() << "FOCUSOFFSET laser" << paras2.toInt();
            facus = paras2.toInt();
            break;
        }
        delaymsec(100);
        qDebug() << " >>>>>>  laser  Focus  read == Error read  !!!!!!  ";
    }

    QString paras3;
    int facus_2 = 75;
    for(int i = 0;i <= 10;i++)
    {
        paras3 = hpxmlreader.readXml("config.xml","FOCUSOFFSET","general"); //查询sys.xml文件中的FOCUSOFFSET字段下的general的内容
        if(!hpxmlreader.errorRead)
        {
            qDebug() << "FOCUSOFFSET general" << paras3.toInt();
            facus_2= paras3.toInt();
            break;
        }
        delaymsec(100);
        qDebug() << " >>>>>>  general  Focus  read == Error read  !!!!!!  ";
    }
    QString paras4;
    int facus_3 = 75;
    for(int i = 0;i <= 10;i++)
    {
        paras4 = hpxmlreader.readXml("config.xml","FOCUSOFFSET","fast"); //查询sys.xml文件中的FOCUSOFFSET字段下的general的内容
        if(!hpxmlreader.errorRead)
        {
            qDebug() << "FOCUSOFFSET general" << paras4.toInt();
            facus_3= paras4.toInt();
            break;
        }
        delaymsec(100);
        qDebug() << " >>>>>>  general  Focus  read == Error read  !!!!!!  ";
    }
    bool focusWay = false;
    for(int i = 0;i <= 10;i++)
    {
        paras3 = hpxmlreader.XmlInit_read("sys.xml","MODULE","focus_save"); //查询sys.xml文件中的FOCUSOFFSET字段下的general的内容
        if(!hpxmlreader.errorRead)
        {
            if(paras3.toInt() == 1)
            {
                focusWay = true;
            }
            break;
        }
        delaymsec(100);
        qDebug() << " >>>>>>  focus_save  Focus  read == Error read  !!!!!!  ";
    }

    qDebug() << " >>>>>>  laser  Focus  read == > " << facus;
    qDebug() << " >>>>>>  general  Focus  read == > " << facus_2;
    hpsetting.hphide_biaoding.slot_biaoding_focus_offset(focusWay, facus,facus_2, facus_3);//设置标定界面FOCUS的值
//    signal_pc_focus_offset(facus);
//    signal_biaoding_focus_offset(facus);    //设置hphide_biaoding界面的spinBox_facus的值与之对应

    for(int i = 0;i <= 10;i++)
    {
        paras2 = hpxmlreader.XmlInit_read("sys.xml","DEV","laserdev_type");
        if(!hpxmlreader.errorRead)
        {
            if(paras2.toInt() > 1)
            {
                isLasertype = true;
            }else{
                isLasertype = false;
            }
            break;
        }
        delaymsec(100);
        qDebug() << " >>>>>>  DEV  laserdev_type  read == Error read  !!!!!!  ";
    }

    if(hpadjustcmd.get_focus_mode() == 0)//若开启自动调焦模式
    {
        signal_pc_key_focus_adjust(0);
    }else{
        signal_pc_key_focus_adjust(1);
    }

    signal_pc_hidemenu_get_para();
    paras2 = hpxmlreader.readXml("config.xml","ENHANCE","on");
    qDebug() << "config.xml ---- > ENHANCE ----- > on ---- > " << paras2;
    if(paras2.toInt() != 0)
    {
        hpsetting.hphide_biaoding.slot_setbiaoding_CheckBox_DDE(true);
    }else{
        hpsetting.hphide_biaoding.slot_setbiaoding_CheckBox_DDE(false);
    }
    para = hpxmlreader.readXml("sys.xml","MULHOMOGENITY","content");
    if(para != NULL)
    {
        hpsetting.hp_Mulhom_edit->mulhom_value_init(para.toInt());
    }

    if(isLasertype)
    {
        signal_pc_sys_set_laser_power(1);
    }
    signal_set_qrcode_switch(0);
//    timer_10s->start(10000);
    setenv("QT_FB2_ENABLE","false",1);//这一句会导致底层死掉
    signal_set_HDMI(0);
    signal_core_fpga_get_ver();
    qDebug() << __LINE__ << "signal_core_fpga_get_ver() Begin";
    hpsetting.setInitAlarmMsg();
    QTimer::singleShot(10, this, SLOT(slot_get_biaoding()));
    timerGetBiaodingPara.start(2000);
    ui->display->initMaxRectPara();
}

MainWidget::~MainWidget()
{
    delete ui;
}
void MainWidget::changeEvent(QEvent *e)
{
    QString para;
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        hp_panorama->set_language(para.toInt());
        if(para !=NULL)
        {
            if(para.toInt() == 0)
            {
                fSDHasNoSpace = "存储空间不够";
                fErrReInsert = "SD卡错误，请重新插入";
                fkjgNotQuit = "可见光模式不可退出二次分析";
                fHSENotQuit = "HSE模式不可退出二次分析";
                fNoSD = "SD卡没有插入";
                fError = "出错了";
                fautoStopVideo="空间已满，录像已自动保存";
                fNoTaskpic="未找到图片";
                fSisIsNotOpen = "扫一扫功能未打开";
                fvideoError = "视频错误是否删除";
            }
            else if(para.toInt() == 1)
            {
                fSDHasNoSpace = "存儲空間不夠";
                fErrReInsert = "SD卡错误，请重新插入";
                fkjgNotQuit = "可見光模式不可退出二次分析";
                fHSENotQuit = "HSE模式不可退出二次分析";
                fNoSD = "SD卡沒有插入";
                fError = "出錯了";
                fautoStopVideo="空間已滿，錄影已自動保存";
                fNoTaskpic="未找到影像";
                fSisIsNotOpen = "掃一掃功能未打開";
                fvideoError = "視頻錯誤是否删除";
            }
            else if(para.toInt() == 2)//english
            {
                fSDHasNoSpace = "No enough memory";
                fErrReInsert = "SD card error, please reinsert";
                fkjgNotQuit = "Visible mode can't exit analysis";
                fHSENotQuit = "HSE mode can't exit analysis";
                fNoSD = "SD not insert";
                fError = "Error";
                fautoStopVideo="Space is full,video has been saved";
                fNoTaskpic="Image not found";
                fSisIsNotOpen = "Scan is not opened";
                fvideoError = "Are video errors deleted";
            }
            else if(para.toInt() == 3)//俄语
            {
                fSDHasNoSpace = "Мало памяти!";
                fErrReInsert = "Ошибка SD-карты, пожалуйста, вставьте заново";
                fkjgNotQuit = "Невозм. выполнить в этом режиме!";
                fHSENotQuit = "Невозм запустить видимый режим HSE";
                fNoSD = "нет карты SD";
                fError = "Ошибка";
                fautoStopVideo="пространство заполнено,видео сохранено";
                fNoTaskpic="Изображения не найдены";
                fSisIsNotOpen = "подметать не открывая";
                fvideoError = "Удалены ли видеоошибки";
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                fSDHasNoSpace = "nincs elég memóriakapacitás";
                fErrReInsert = "SD kártya hiba, kérlek, tess be újra";
                fkjgNotQuit = "Másodlagos elemzés fényképmódban nincs";
                fHSENotQuit = "A látható fény nem érhető el HSE üzemmódban";
                fNoSD = "nincs SD";
                fError = "Hiba";
                fautoStopVideo="A hely tele van, és a videó mentésre került";
                fNoTaskpic="A kép nem található";
                fSisIsNotOpen = "A beolvasás nincs megnyitva";
                fvideoError = "A videohibák törlése";
            }
            else if(para.toInt() == 5)//西班牙语
            {
                fSDHasNoSpace = "Tarjeta SD Llena";
                fErrReInsert = "Error de la tarjeta SD, por favor vuelve a insertar";
                fkjgNotQuit = "Luz Visible Fuera del Análisis Secundario";
                fHSENotQuit = "El modo HSE no puede emitir luz visible";
                fNoSD = "Isertar SD";
                fError = "Error";
                fautoStopVideo="Espacio completo,grabación de vídeo guardada";
                fNoTaskpic="Imagen no encontrada";
                fSisIsNotOpen = "Barrido sin abrir";
                fvideoError = "Si se elimina el error de vídeo";
            }
        }
        break;
    default:
        break;
    }
}
void MainWidget::slot_set_qrcode_state(bool checked)
{
    if(checked)
    {
        signal_set_qrcode_switch(0);//先结束
        signal_set_qrcode_switch(1);//后重新启动，表示新的扫码开始
        qrcode = true;
        timer_500ms.start(1000);
    }
    else
    {
        if(temp_mode != -1)
        {
             signal_set_qrcode_switch(0);
            video_mode=0;
            temp_mode =-1 ;
            hpmode.set_mode(video_mode);
            ui->mode->set_hp_button_status(S_NORMAL);

            ui->point->set_hp_button_status(S_NORMAL);
            ui->line->set_hp_button_status(S_NORMAL);
            ui->rect->set_hp_button_status(S_NORMAL);
            ui->circle->set_hp_button_status(S_NORMAL);
            ui->polygon->set_hp_button_status(S_NORMAL);
            ui->clean->set_hp_button_status(S_NORMAL);
            ui->sebiao->set_hp_button_status(S_NORMAL);
            ui->bright_mode->set_hp_button_status(S_NORMAL);

            if(video_mode==0)
                ui->resize->set_hp_button_status(S_NORMAL);
            qrcode = false;
        }
    }
}
void MainWidget::slot_pc_measure_temprange_query(unsigned char return_value,int data)
{
    qDebug() << "MainWidget::slot_pc_measure_temprange_query == > " << return_value << " ; " << data;
    if(return_value == RE_OK)
    {
        if(data == 1)
        {
            hpsetting.tempSetTm.stop();
            hpsetting.slot_pc_measure_temprange_query(RE_OK);
            hpadjustcmd.slot_pc_measure_set_temprange_ok(RE_OK);
        }else{
            hpsetting.slot_tempSetTm_out();
        }
    }else{
        hpsetting.slot_tempSetTm_out();
    }
}

void MainWidget::slot_pc_sys_set_qrcode_switch(unsigned char return_value)
{
//    qDebug("slot_pc_sys_set_qrcode_switch  0x%02x",return_value);
}

void MainWidget::slot_pc_sys_get_qrcode_info(unsigned char return_value, unsigned char *data)
{
    if(return_value== RE_OK)
    {
        char *str1 = (char *)data;

        if(strlen(str1)>0)
        {
            signal_set_sis_label(data);
            timer_500ms.stop();
            hpsis_content->show();
        }
        else
        {
            qDebug()<<"slot_pc_sys_get_qrcode_info data is NUll";
        }
    }
    else
    {
        qDebug("slot_pc_sys_get_qrcode_info return_value0x%02x",return_value);
    }
}

void MainWidget::slot_ok_or_cannal_sis_swicth(int num,QString text)
{
    qDebug() << "MainWidget::slot_ok_or_cannal_sis_swicth == > " << num << " ; " << text;
    if(num)    //0取消 1继续
    {
       slot_set_qrcode_state(false);

#if TaiZhang_Mode

    //武船站-220kV-2023-07-13;-武船站;-220kV;-1
    if(hppreview->Taskmode)//若有台账功能则进行
    {
        if(hpcameracap->Taskmode)//若在台账内
        {
            //武船站;-220kV;-1
            qDebug() << " Hp_TaskPkg::getInstance()->Dump_to_index_by_name == > " << text;
            Hp_TaskPkg::getInstance()->Dump_to_index_by_name(text);//点击确定时跳转到对应的地方
        }else{
            int ind = text.indexOf(";-");

            QString by_name_extend = text.mid(0,ind);
            if(by_name_extend.isEmpty())
            {
                qDebug() << " Hp_TaskPkg::getInstance()->Dump_to_task_by_name_extend by_name_extend.isEmpty <<<";
                return;
            }
            QString by_name = text.mid(ind + 2);

            OutsisToTask = true;
            StrOutsisToTask = by_name;

            //MainWidget::slot_task_start执行的内容
            //ui->display->hp_list_save();
            hpcameracap->Taskmode = true;
            //MainWidget::slot_task_start执行的内容

            //武船站-220kV-2023-07-13
            qDebug() << " Hp_TaskPkg::getInstance()->Dump_to_task_by_name_extend == > " << by_name_extend;
            int ret = Hp_TaskPkg::getInstance()->Dump_to_task_by_name_extend(by_name_extend);//从台账外跳转到台账内
            if(ret != 0)
            {
                OutsisToTask = false;
                hpcameracap->Taskmode = false;
            }else{
                ui->display->sltStartTask();
            }
        }
    }
#endif

//       if(sisToTask)
//       {
//#if TaiZhang_Mode
//           qDebug() << " Hp_TaskPkg::getInstance()->Dump_to_index_by_name == > " << text;
//           if(hpcameracap->Taskmode)//若在台账内
//           {
//               Hp_TaskPkg::getInstance()->Dump_to_index_by_name(text);//点击确定时跳转到对应的地方
//           }else{
//               Hp_TaskPkg::getInstance()->Dump_to_task_by_name_extend(text);//点击确定时跳转到对应的地方
//           }
//#endif
//       }

       hpcameracap->isSisOK = true;
       ui->display->TaskSouldBepaint = true;//重新绘图
       ui->display->update();
//        signal_add_center_rect();
    }
    else
    {
        slot_set_qrcode_state(true);
    }
}
void MainWidget::slot_close_sis_mode(bool checkd)
{
    if(checkd)
    {
        return;
    }
    if((qrcode == true) && define_sis)//是否处于扫一扫模式
    {
        slot_set_qrcode_state(false);
    }
}
void MainWidget::slot_timer_500ms()
{
    if(qrcode == true)
    {
        signal_get_qrcode_info();
    }
    else
    {
        timer_500ms.stop();
    }
}

void MainWidget::hp_setDefine_Szoom(bool souldzoom)
{
    ui->display->define_zoom = souldzoom;
}
void MainWidget::hp_setDefine_S3x0(bool isSelect)
{
    qDebug() << ">> MainWidget::hp_setDefine_S3x0 << " << isSelect;
//    ui->display->define_S6X0_S3X0 = isSelect;//有问题  那天的硬件  散装的
    hpsetting.hphide_biaoding.define_S6X0_S3X0 = isSelect;//有问题  那天的硬件  散装的
    hppreview->hp_setDefine_S3x0(isSelect);
    define_S6X0_S3X0 = isSelect;//有问题  那天的硬件  散装的
    if(isHcf)
    {
        ui->display->define_640_512 = true;
        this->resize(800,512);
        this->setGeometry(0, 0, 800, 512);
        ui->display->bottom_edge = 512;
        hp_twice_kjg.define_640_512 = true;
        hppreview->define_640_512 = true;
//        hppreview->hmp.define_640_512 = true;
    }
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);
        QFont font10;
        font10.setPointSize(10);

        this->resize(480,272);
        ui->label_alarm->setGeometry(200, 16, 150, 20);
        ui->label_tempAvg->setGeometry(200, 40, 60, 20);
        ui->label_laserRange->setGeometry(0, 20, 90, 20);
        ui->display->setGeometry(96,0,384,272);
        ui->focus_far->setGeometry(190,220,39,39);
        ui->focus_near->setGeometry(140,220,39,39);
        ui->frame_tool->setGeometry(300,16,84,254);
        ui->toolButton_AM->setGeometry(40,0,32,32);
        ui->toolButton_down->setGeometry(0,140,40,40);
        ui->toolButton_max->setGeometry(35,25,40,20);
        ui->toolButton_min->setGeometry(35,215,40,20);
        ui->toolButton_up->setGeometry(0,90,40,40);

        ui->frame_task->setGeometry(234,0,150,16);
        ui->widget_task->setGeometry(0,0,150,16);
        ui->label_autosave->setGeometry(150,110,80,20);
        ui->label->setGeometry(45,205,236,34);
        ui->label_2->setGeometry(45,222,236,34);
        ui->label_focus->setGeometry(180,130,60,20);
        ui->last_page->setGeometry(290,180,35,33);
        ui->next_page->setGeometry(290,220,35,33);
        ui->widget_laser->resize(24,24);//这个x,y不用自己设置，通过配置文件设置《《《
        ui->frame->setGeometry(0,0,96,272);
        ui->bright_mode->setGeometry(2,181,46,44);
        ui->clean->setGeometry(49,136,46,44);
        ui->line->setGeometry(49,46,46,44);
        ui->mode->setGeometry(2,136,46,44);
        ui->point->setGeometry(49,1,46,44);
        ui->preview->setGeometry(2,1,46,89);
        ui->rect->setGeometry(49,91,46,44);
        ui->circle->setGeometry(0,91,46,44);
        ui->polygon->setGeometry(0,91,46,44);
        ui->resize->setGeometry(49,181,46,44);
        ui->sebiao->setGeometry(2,91,46,44);
        ui->setting->setGeometry(2,226,93,44);
        ui->display->gray_disp->setGeometry(0,200,384,30);
        ui->label_alarm->setFont(font9);
        ui->toolButton_pause->setGeometry(2,226,93,44);
        ui->label_focus->setFont(font10);
        ui->label->setFont(font10);
        ui->label_2->setFont(font10);
        ui->toolButton_max->setFont(font9);
        ui->toolButton_min->setFont(font9);
        ui->display->gray_disp->setFont(font9);
        ui->label_laserRange->setFont(font10);
        ui->label_tempAvg->setFont(font10);
        ui->label_autosave->setFont(font10);
        ui->toolButton_AM->setStyleSheet("QToolButton {border-image:url(:/res/res/auto_s3x0.png);color:#7CA6C9;}QToolButton:checked{border-image:url(:/res/res/manual_s3x0.png);}");
        ui->point->set_hp_button_status_image_select(":/res/res/point_s_s.png");
        ui->point->set_hp_button_status_image_normal(":/res/res/point_s_n.png");
        ui->point->set_hp_button_status_image_disable(":/res/res/point_s_d.png");
        ui->point->set_hp_button_checked_enable(true);

        ui->line->set_hp_button_status_image_select(":/res/res/line_s_s.png");
        ui->line->set_hp_button_status_image_normal(":/res/res/line_s_n.png");
        ui->line->set_hp_button_status_image_disable(":/res/res/line_s_d.png");
        ui->line->set_hp_button_checked_enable(true);

        ui->rect->set_hp_button_status_image_select(":/res/res/rect_s_s.png");
        ui->rect->set_hp_button_status_image_normal(":/res/res/rect_s_n.png");
        ui->rect->set_hp_button_status_image_disable(":/res/res/rect_s_d.png");
        ui->rect->set_hp_button_checked_enable(true);

        ui->circle->set_hp_button_status_image_select(":/res/res/circle_s_s.png");
        ui->circle->set_hp_button_status_image_normal(":/res/res/circle_s_n.png");
        ui->circle->set_hp_button_status_image_disable(":/res/res/circle_s_d.png");
        ui->circle->set_hp_button_checked_enable(true);

        ui->polygon->set_hp_button_status_image_select(":/res/res/polygon_s_s.png");
        ui->polygon->set_hp_button_status_image_normal(":/res/res/polygon_s_n.png");
        ui->polygon->set_hp_button_status_image_disable(":/res/res/polygon_s_d.png");
        ui->polygon->set_hp_button_checked_enable(true);

        ui->preview->set_hp_button_status_image_select(":/res/res/preview_s_s.png");
        ui->preview->set_hp_button_status_image_normal(":/res/res/preview_s_n.png");
        ui->preview->set_hp_button_status_image_disable(":/res/res/preview_s_d.png");
        ui->preview->set_hp_button_checked_enable(true);

        ui->setting->set_hp_button_status_image_select(":/res/res/shezhi_s_s.png");
        ui->setting->set_hp_button_status_image_normal(":/res/res/shezhi_s_n.png");
        ui->setting->set_hp_button_status_image_disable(":/res/res/shezhi_s_d.png");
        ui->setting->set_hp_button_checked_enable(false);

        //改变灯光功能为点击功能   b
        if(define_brightmode){      //如果存在点击功能，记得把图标放到相应位置
            ui->bright_mode->set_hp_button_status_image_select(":/res/res/focus_s_s.png");
            ui->bright_mode->set_hp_button_status_image_normal(":/res/res/focus_s_n.png");
            ui->bright_mode->set_hp_button_status_image_disable(":/res/res/focus_s_d.png");       //mf图标
            ui->bright_mode->set_hp_button_checked_enable(true);
        }else{
            ui->bright_mode->set_hp_button_status_image_select(":/res/res/bright_s_night.png");
            ui->bright_mode->set_hp_button_status_image_normal(":/res/res/bright_s_day.png");
            ui->bright_mode->set_hp_button_status_image_disable(":/res/res/bright_s_day.png");       //mf图标
            ui->bright_mode->set_hp_button_checked_enable(true);
        }


        focus_state = S_NORMAL;
        ui->clean->set_hp_button_status_image_select(":/res/res/clean_s_s.png");
        ui->clean->set_hp_button_status_image_normal(":/res/res/clean_s_n.png");
        ui->clean->set_hp_button_status_image_disable(":/res/res/clean_s_d.png");
        ui->clean->set_hp_button_checked_enable(false);

        ui->mode->set_hp_button_status_image_select(":/res/res/mode_s_s.png");
        ui->mode->set_hp_button_status_image_normal(":/res/res/mode_s_n.png");
        ui->mode->set_hp_button_status_image_disable(":/res/res/mode_s_d.png");
        ui->mode->set_hp_button_checked_enable(true);

        ui->resize->set_hp_button_status_image_select(":/res/res/resize_s_s.png");
        ui->resize->set_hp_button_status_image_normal(":/res/res/resize_s_n.png");
        ui->resize->set_hp_button_status_image_disable(":/res/res/resize_s_d.png");
        ui->resize->set_hp_button_checked_enable(true);

        ui->sebiao->set_hp_button_status_image_select(":/res/res/sebiao_s_s.png");
        ui->sebiao->set_hp_button_status_image_normal(":/res/res/sebiao_s_n.png");
        ui->sebiao->set_hp_button_status_image_disable(":/res/res/sebiao_s_d.png");
        ui->sebiao->set_hp_button_checked_enable(true);
    }else{
        ui->toolButton_AM->setGeometry(80,8,30,30);
        ui->toolButton_max->setGeometry(60,38,66,35);
        ui->toolButton_min->setGeometry(60,388,66,35);
    }
    hp_dialog->hp_setDefine_S3x0(isSelect);
    hphidelaser.hp_setDefineS3X0(isSelect);
    panorama_dialog.hp_setDefine5_5(isSelect);
    hp_panorama->hp_setDefineS3X0(isSelect);
    hpadjustcmd.hp_setDefine_S3x0(isSelect);
    hp_avimode.hp_setDefine_S3x0(isSelect);
    hpcameracap->hp_setDefine_S3x0(isSelect);
    hpcameravideo.hp_setDefine_S3x0(isSelect);
    SDFormatDialog->hp_setDefine_S3x0(isSelect);
    formatDialog.hp_setDefine_S3x0(isSelect);
    hpisotherm.hp_setDefine_S3x0(isSelect);
    ui->widget_task->hp_setDefine_S3x0(isSelect);
    hmp.hp_setDefine_S3x0(isSelect);
    hpmodehzhadjust.hp_setDefine_S3x0(isSelect);
    hpmoderdjadjust.hp_setDefine_S3x0(isSelect);
    hpd.hp_setDefine_S3x0(isSelect);
    hp_power_w.hp_setDefine_S3x0(isSelect);
    hta->hp_setDefine_S3x0(isSelect);
    hp_twice_kjg.hp_setDefine_S3x0(isSelect);
    hp_twice_pic.hp_setDefine_S3x0(isSelect);
    hp_usb_insert.hp_setDefine_S3x0(isSelect);
    hpcpumem.hp_setDefine_S3x0(isSelect);
    ui->display->hpdeledit.hp_setDefine_S3x0(isSelect);
    hpmode.hp_setDefine_S3x0(isSelect);
    ui->display->hpplredit->hp_setDefine_S3x0(isSelect);
    hpresize.hp_setDefine_S3x0(isSelect);
    hpsebiao.hp_setDefine_S3x0(isSelect);
    hssw->hp_setDefine_S3x0(isSelect);
    hp_Wifi_search_Dialog->hp_setDefine_S3x0(isSelect);
    hpsis_content->hp_setDefine_S3x0(isSelect);
    hp_wait_w.hp_setS3X0(isSelect);
    hp_Pms->hp_setS3X0(isSelect);
}
void MainWidget::hp_setDefine_brightmode(bool isSelect)
{
    this->define_brightmode = (!isSelect);

    ui->display->define_brightmode = (!isSelect);
    if(fidpid)
    {
        ui->display->define_brightmode = true;
    }

    if(define_brightmode){      //如果存在点击功能，记得把图标放到相应位置
        ui->bright_mode->set_hp_button_status_image_select(":/res/res/focus_s.png");
        ui->bright_mode->set_hp_button_status_image_normal(":/res/res/focus_n.png");
        ui->bright_mode->set_hp_button_status_image_disable(":/res/res/focus_d.png");       //mf图标
        ui->bright_mode->set_hp_button_checked_enable(true);
    }else{
        ui->bright_mode->set_hp_button_status_image_select(":/res/res/bright_night.png");
        ui->bright_mode->set_hp_button_status_image_normal(":/res/res/bright_day.png");
        ui->bright_mode->set_hp_button_status_image_disable(":/res/res/bright_day.png");       //mf图标
        ui->bright_mode->set_hp_button_checked_enable(true);
    }
}
void MainWidget::slot_set_IsInlcdoff(bool value)
{
    IsInlcdoff = value;
}
void MainWidget::slot_update_lcdoff_time(bool iskey)
{
//    qDebug() << iskey << printscreen_checked;
    if(IsInlcdoff)
    {
        hpsetting.slot_update_lcdoff_Time();
    }

    if(printscreen_checked && iskey)//若开启截图
    {
        signal_core_key_capture_start(0);
    }
}
void MainWidget::slot_core_key_capture_start(unsigned char return_value)
{
    if(printscreen_checked)
    {
        if(return_value == RE_OK)
        {
            hssw->warning("提示","截图成功");
        }else{
            hssw->warning("提示","截图失败");
        }
        hssw->show();
    }
    else
    {
//        signal_core_key_capture_stop(1);
    }
}

void MainWidget::slot_core_key_panorama_cap(unsigned char return_value)
{
    signal_core_key_panorama_stop(1);
}

void MainWidget::auto_manual_init()
{
    auto_manual_flag = false;
    min_handle_flag = false;
    max_handle_flag = false;
    auto_manual_update();

}

void MainWidget::auto_manual_update()//
{
    ui->toolButton_AM->setChecked(auto_manual_flag);
    ui->toolButton_max->setVisible(auto_manual_flag);
    ui->toolButton_min->setVisible(auto_manual_flag);
    if(auto_manual_flag)
    {
        ui->toolButton_max->raise();
        ui->toolButton_min->raise();
    }

    int temp_unit;
    temp_unit = hpsetting.get_temp_unit_state();

    if(min_handle_flag || max_handle_flag)
    {
        ui->toolButton_down->setVisible(true && auto_manual_flag);
        ui->toolButton_up->setVisible(true && auto_manual_flag);

        slot_tempunit_value_changed(temp_unit);
//        ui->toolButton_max->setText(QString::number(max_value100/100.0,'f',1));
//        ui->toolButton_min->setText(QString::number(min_value100/100.0,'f',1));
    }
    else
    {
        ui->toolButton_down->setVisible(false);
        ui->toolButton_up->setVisible(false);

        slot_tempunit_value_changed(temp_unit);
//        ui->toolButton_max->setText(QString::number(max_value100/100.0,'f',1));
//        ui->toolButton_min->setText(QString::number(min_value100/100.0,'f',1));
    }

}

void MainWidget::on_point_clicked(HP_BUTTON_STATUS status)
{
//    hpd.show();
//    hpsetting.hphide_biaoding.show();
//    hpsetting.hphidemenu.show();
//    return;

    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->point->set_hp_button_status(S_NORMAL);
        return;
    }
    if(status == S_SELECT)
    {
        ui->display->drawStatus = DS_POINT;   //增加点操作
        update_main_show(MAIN_POINT);
        if(mode_kjg == false){
           if(pic_swich_save == false)
           {
               last_botton_state = ui->last_page->isEnabled();
               next_botton_state = ui->next_page->isEnabled();
           }
             pic_swich_save = true;
             ui->last_page->setEnabled(false);
             ui->next_page->setEnabled(false);
           }
    }
    else if(status == S_NORMAL)
    {
        ui->display->drawStatus = DS_NON;
        if(mode_kjg == false){
            pic_swich_save = false;
           ui->last_page->setEnabled(last_botton_state);
           ui->next_page->setEnabled(next_botton_state);
            }
    }
}

void MainWidget::on_line_clicked(HP_BUTTON_STATUS status)
{
//    hp_power_w.show();

    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->line->set_hp_button_status(S_NORMAL);
        return;
    }
    if(status == S_SELECT)
    {
        ui->display->drawStatus = DS_LINE;
        update_main_show(MAIN_LINE);
        if(mode_kjg == false){
           if(pic_swich_save == false)
           {
               last_botton_state = ui->last_page->isEnabled();
               next_botton_state = ui->next_page->isEnabled();
           }
             pic_swich_save = true;
             ui->last_page->setEnabled(false);
             ui->next_page->setEnabled(false);
           }
    }
    else if(status == S_NORMAL)
    {
        ui->display->drawStatus = DS_NON;
        if(mode_kjg == false){
            pic_swich_save = false;
           ui->last_page->setEnabled(last_botton_state);
           ui->next_page->setEnabled(next_botton_state);
           }
    }
}

void MainWidget::on_rect_clicked(HP_BUTTON_STATUS status)
{
    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->rect->set_hp_button_status(S_NORMAL);
        return;
    }
    if(hpsetting.m_isOpenPolygon || hpsetting.m_isOpenCircle)
    {
        ui->rect->set_hp_button_status_image_select(":/res/res/rect_s.png");
        ui->rect->set_hp_button_status_image_normal(":/res/res/rect_n.png");
        ui->rect->set_hp_button_status_image_disable(":/res/res/rect_d.png");
        update();
    }
    if(!ui->circle->isVisible() && hpsetting.m_isOpenCircle)
    {
        ui->display->drawStatus = DS_NON;
        ui->circle->show();
        ui->circle->set_hp_button_status(S_NORMAL);
        ui->rect->set_hp_button_status(S_NORMAL);
        return;
    }
    if(!ui->polygon->isVisible() && hpsetting.m_isOpenPolygon)
    {
        ui->display->drawStatus = DS_NON;
        ui->polygon->show();
        ui->polygon->set_hp_button_status(S_NORMAL);
        ui->rect->set_hp_button_status(S_NORMAL);
        return;
    }
    ui->circle->close();
    ui->polygon->close();
    if(status == S_SELECT)
    {
        ui->display->drawStatus = DS_RECT;
        update_main_show(MAIN_RECT);
        if(mode_kjg == false){
           if(pic_swich_save == false)
           {
               last_botton_state = ui->last_page->isEnabled();
               next_botton_state = ui->next_page->isEnabled();
           }
             pic_swich_save = true;
             ui->last_page->setEnabled(false);
             ui->next_page->setEnabled(false);
           }
    }
    else if(status == S_NORMAL)
    {
        ui->display->drawStatus = DS_NON;
        if(mode_kjg == false){
            pic_swich_save = false;
           ui->last_page->setEnabled(last_botton_state);
           ui->next_page->setEnabled(next_botton_state);
           }
    }
}

void MainWidget::on_circle_clicked(HP_BUTTON_STATUS status)
{
    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->circle->set_hp_button_status(S_NORMAL);
        return;
    }
    ui->display->drawStatus = DS_CIRCLE;
    if(status == S_SELECT)
    {
        ui->display->clear_selecte_status();
        ui->display->drawStatus = DS_CIRCLE;
        ui->circle->close();
        ui->point->set_hp_button_status(S_NORMAL);
        ui->line->set_hp_button_status(S_NORMAL);
        if(mode_kjg == false)
        {
           if(pic_swich_save == false)
           {
               last_botton_state = ui->last_page->isEnabled();
               next_botton_state = ui->next_page->isEnabled();
           }
             pic_swich_save = true;
             ui->last_page->setEnabled(false);
             ui->next_page->setEnabled(false);
        }
        ui->rect->set_hp_button_status_image_select(":/res/res/circle_s.png");
        ui->rect->set_hp_button_status_image_normal(":/res/res/circle_n.png");
        ui->rect->set_hp_button_status_image_disable(":/res/res/circle_d.png");
        ui->rect->set_hp_button_status(S_SELECT);
    }
}

void MainWidget::on_polygon_clicked(HP_BUTTON_STATUS status)
{
    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->polygon->set_hp_button_status(S_NORMAL);
        return;
    }
    qDebug() << __func__ << "DS_POLYGON";
    ui->display->drawStatus = DS_POLYGON;
    if(status == S_SELECT)
    {
        ui->checkBox_polygon->setChecked(false);
        ui->display->m_isPolygonDraw = true;
        ui->display->clear_selecte_status();
        ui->display->drawStatus = DS_POLYGON;
        ui->point->set_hp_button_status(S_NORMAL);
        ui->line->set_hp_button_status(S_NORMAL);
        ui->polygon->close();
        if(mode_kjg == false)
        {
           if(pic_swich_save == false)
           {
               last_botton_state = ui->last_page->isEnabled();
               next_botton_state = ui->next_page->isEnabled();
           }
             pic_swich_save = true;
             ui->last_page->setEnabled(false);
             ui->next_page->setEnabled(false);
        }
        ui->rect->set_hp_button_status_image_select(":/res/res/polygon_s.png");
        ui->rect->set_hp_button_status_image_normal(":/res/res/polygon_n.png");
        ui->rect->set_hp_button_status_image_disable(":/res/res/polygon_d.png");
        ui->rect->set_hp_button_status(S_SELECT);
    }
    else
    {
        ui->checkBox_polygon->setChecked(false);
        ui->checkBox_polygon->close();
        ui->pushButton_confirm->close();
    }
}

void MainWidget::setDisplayMove(bool isMove)
{
    ti_pos pos;
    if(isMove)
    {
        pos.hdmi_pos_x = 80;
        pos.hdmi_pos_y = 60;
        pos.lcd_pos_x = 80;
        pos.lcd_pos_y = 0;
        signal_pc_measure_move_display(pos);
    }
    else
    {
        pos.hdmi_pos_x = 160;
        pos.hdmi_pos_y = 60;
        pos.lcd_pos_x = 160;
        pos.lcd_pos_y = 0;
        signal_pc_measure_move_display(pos);
    }
}

void MainWidget::previewShow()
{
    if(hssw->isVisible() || video_mode == 1)
    {
        if(hta->isVisible())
            return;
    }
    hp_dialog->setText(hpcameracap->WaitShow);//借用
    hp_Wifi_search_Dialog->SetHideButton(true);
    hp_dialog->show();
    QApplication::processEvents();
}



void MainWidget::on_preview_clicked(HP_BUTTON_STATUS status)
{
    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->preview->set_hp_button_status(S_NORMAL);
        return;
    }
    if(hir_analyse)
    {
        slot_stop_hir_analyse();
        return;
    }
    ui->display->drawStatus = DS_NON;
    if(Twice_analysis == true)
        status = S_NORMAL;
    if(status == S_SELECT)
    {
        qDebug() << "hpsetting.hpblesearchold.get_conn_status() " << hpsetting.hpblesearchold.get_conn_status() << "status" << status;
        previewShow();
        signal_core_corectrl_stop_encode();   //视频模块停止运行
        hta->slot_core_get_twice_audio_status(RE_OK, 0);
        if(!hpsetting.hpblesearchold.get_conn_status() && !hpsetting.hpblesearch.isLinked && !isBlePowerOn)
        {
            if(hpsetting.isNewBle &&  !hpsetting.isBleOpen && !hpsetting.ui->checkBox_ble->isChecked())
            {
                signal_pc_sys_set_ble_power(1);
                signal_pc_sys_set_ble_module(1);
                hppreview->isFirstVideo = true;
            }
            isBlePowerOn = true;
        }
        preview_state = true;
        if(define_brightmode && ui->focus_near->isVisible() && ui->focus_far->isVisible())
        {
            ui->focus_near->hide();
            ui->focus_far->hide();
        }
    }
    else if(status == S_NORMAL)
    {
        if(video_mode == 1)
        {
            hssw->warning(fError,fkjgNotQuit);
            hssw->setDelayClose(3000);
            hssw->show();
            return;
        }
        else if(((video_mode == 4)&&fidpid))//如果为HSE模式
        {
            hssw->warning(fError,fHSENotQuit);
            hssw->setDelayClose(3000);
            hssw->show();
            return;
        }
        else
        {
            previewShow();
            qDebug() << "isTwiceChangeOver" << isTwiceChangeOver << __LINE__;
            if(twice_analysis_cut_pic || isTwiceChangeOver)
            {
                return;
            }
            hta->stop_twice_preview =true;
            if(hta->play_state)
           {
              signal_twice_voicep_Stop();
           }
            if(hta->voice_state)
            {
                signal_twice_voiceStop();
            }
            signal_core_analysis_pic_twice_stop();
            set_twice_text_about_preview();
        }
    }
    else
    {
    }
    update_main_show(MAIN_PREVIEW);
}

void MainWidget::on_clean_clicked(HP_BUTTON_STATUS status)
{
    Q_UNUSED(status);
    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->clean->set_hp_button_status(S_NORMAL);
        return;
    }
    if(status == S_NORMAL)
    {
        ui->display->clear_measure();
    }

    if(pic_swich_save == true)
    {
        pic_swich_save = false;
       ui->last_page->setEnabled(last_botton_state);
       ui->next_page->setEnabled(next_botton_state);
       if( (video_mode== 1) ||  ((video_mode == 4) && fidpid))
       {
          ui->last_page->setEnabled(false);
          ui->next_page->setEnabled(false);
       }
    }
    ui->display->drawStatus = DS_NON;
    update_main_show(MAIN_CLEAN);
}

void MainWidget::on_setting_clicked(HP_BUTTON_STATUS status)
{
    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->setting->set_hp_button_status(S_NORMAL);
        return;
    }
    if( (!hpmode.isHidden()) || (!hpsebiao.isHidden()) || (!hpresize.isHidden()))
    {
        return ;
    }
    Q_UNUSED(status);
    setting_open_state = true;
    ui->display->drawStatus = DS_NON;
    update_main_show(MAIN_SETTING);
    hpsetting.setCurrentTabToWenDuXiuZheng();
    hpsetting.show();
    if(!settingToAutoRecirft->isActive())
    {
        settingToAutoRecirft->start();
    }
}

void MainWidget::on_sebiao_clicked(HP_BUTTON_STATUS status)
{
    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->sebiao->set_hp_button_status(S_NORMAL);
        return;
    }
    if( (!hpmode.isHidden()) || (!hpresize.isHidden()) )
    {
        return ;
    }
    ui->display->drawStatus = DS_NON;

    if(status == S_SELECT){
        if(text_label_show == true)
        {
            ui->label->close();
            ui->label_2->close();
        }
        if(twice_analysis_start == true)
        {
            hta->close();
        }
        ColorAMLimit(true);
        hpsebiao.show();
        if(mode_kjg == false){
           if(pic_swich_save == false)
           {
               last_botton_state = ui->last_page->isEnabled();
               next_botton_state = ui->next_page->isEnabled();
           }
             pic_swich_save = true;
             ui->last_page->setEnabled(false);
             ui->next_page->setEnabled(false);
           }
        if(define_brightmode && ui->focus_near->isVisible() && ui->focus_far->isVisible())
        {
            ui->focus_near->hide();
            ui->focus_far->hide();
            if(define_brightmode)
            {
                if( video_mode == 1 )
                {
                    ui->bright_mode->set_hp_button_status(S_DISABLE);
                }
                else
                {
                    ui->bright_mode->set_hp_button_status(S_NORMAL);
                }
            }
        }
        if(twice_analysis_start)//二次分析时将控件隐藏
        {
            if(ui->next_page->isVisible() && ui->last_page->isVisible())
            {
                ui->next_page->hide();
                ui->last_page->hide();
            }
        }
    }
    else if(status == S_NORMAL){
        if(text_label_show == true)
        {
            ui->label->show();
            ui->label_2->show();
        }
        if(twice_analysis_start == true)
        {
            hta->show();
        }
        ColorAMLimit(false);
        hpsebiao.close();
        if(mode_kjg == false)
        {
            pic_swich_save = false;
           ui->last_page->setEnabled(last_botton_state);
           ui->next_page->setEnabled(next_botton_state);
           if( (video_mode== 1) ||  ((video_mode == 4) && fidpid))
           {
                pic_swich_save = true;
              ui->last_page->setEnabled(false);
              ui->next_page->setEnabled(false);
           }
        }
        if(twice_analysis_start)//二次分析时将控件隐藏
        {
            if((!ui->next_page->isVisible()) && (!ui->last_page->isVisible()))
            {
                ui->next_page->show();
                ui->last_page->show();
            }
        }
    }
    else
    {

    }

    update_main_show(MAIN_SEBIAO);
}

void MainWidget::on_resize_clicked(HP_BUTTON_STATUS status)
{
    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->resize->set_hp_button_status(S_NORMAL);
        return;
    }
    if( (!hpmode.isHidden()) || (!hpsebiao.isHidden()) )
    {
        return ;
    }
    Q_UNUSED(status);
    qDebug()<<"on_resize_clicked ";
    ui->display->drawStatus = DS_NON;

    if(status == S_SELECT)
    {
        if(text_label_show == true)
        {
            ui->label->close();
            ui->label_2->close();
        }
        ReciseAMLimit(true);
        hpresize.show();
        hpresize.raise();
        if(mode_kjg == false){
           if(pic_swich_save == false)
           {
               last_botton_state = ui->last_page->isEnabled();
               next_botton_state = ui->next_page->isEnabled();
           }
             pic_swich_save = true;
             ui->last_page->setEnabled(false);
             ui->next_page->setEnabled(false);
           }
        if(define_brightmode && ui->focus_near->isVisible() && ui->focus_far->isVisible())
        {
            ui->focus_near->hide();
            ui->focus_far->hide();
        }
        if(twice_analysis_start)//二次分析时将控件隐藏
        {
            if(ui->next_page->isVisible() && ui->last_page->isVisible())
            {
                ui->next_page->hide();
                ui->last_page->hide();
            }
        }
     }
    else if(status == S_NORMAL)
    {
        if(text_label_show == true)
        {
            ui->label->show();
            ui->label_2->show();
        }
        ReciseAMLimit(false);
        hpresize.close();
         if(mode_kjg == false){
             pic_swich_save = false;
            ui->last_page->setEnabled(last_botton_state);
            ui->next_page->setEnabled(next_botton_state);
            }
         if(twice_analysis_start)//二次分析时将控件隐藏
         {
             if((!ui->next_page->isVisible()) && (!ui->last_page->isVisible()))
             {
                 ui->next_page->show();
                 ui->last_page->show();
             }
         }
    }
    else
    {

    }

    update_main_show(MAIN_RESIZE);
}

void MainWidget::on_mode_clicked(HP_BUTTON_STATUS status)
{
    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->mode->set_hp_button_status(S_NORMAL);
        return;
    }
    if( (!hpsebiao.isHidden()) || (!hpresize.isHidden()))
    {
        return ;
    }
    if(qrcode == true)
    {
        return ;
    }
    if(hpsetting.guowangFlag)//国网模式不允许切
    {
        qDebug() << "hpsetting.guowangFlag can't change mode == > " << hpsetting.guowangFlag;
        return ;
    }
    ui->display->drawStatus = DS_NON;
    if(status == S_SELECT){
        if(text_label_show == true)
        {
            ui->label->close();
            ui->label_2->close();
        }
        ModeAMLimit(true);
        hpmode.show();
        if(fidpid && hta->isVisible())
        {
            hpmode.ui->toolButton_rdj->setEnabled(false);

            if(define_S6X0_S3X0)
            {
                hpmode.ui->frame->setGeometry(86, 190, 170, 44);
            }
            else
            {
                hpmode.ui->frame->setGeometry(143, 325, 288, 69);
            }

        }

        if(!hta->isVisible())
        {
            hpmode.ui->toolButton_rdj->setEnabled(true);
            if(define_S6X0_S3X0)
            {
                hpmode.ui->frame->setGeometry(86, 190, 212, 44);
            }
            else
            {
                hpmode.ui->frame->setGeometry(143, 325, 360, 69);
            }
        }
        if(mode_kjg == false){
           if(pic_swich_save == false)
           {
               last_botton_state = ui->last_page->isEnabled();
               next_botton_state = ui->next_page->isEnabled();
           }
             pic_swich_save = true;
             ui->last_page->setEnabled(false);
             ui->next_page->setEnabled(false);
           }
        if(define_brightmode && ui->focus_near->isVisible() && ui->focus_far->isVisible())
        {
            ui->focus_near->hide();
            ui->focus_far->hide();
        }
    }
    else if(status == S_NORMAL){
        if(text_label_show == true)
        {
            ui->label->show();
            ui->label_2->show();
        }
        hpmode.close();
        ModeAMLimit(false);
        if(mode_kjg == false){               //当前模式是    非可见光模式
            pic_swich_save = false;
            ui->last_page->setEnabled(last_botton_state);
            ui->next_page->setEnabled(next_botton_state);
            if(ui->toolButton_AM->isHidden() && !m_isAimTemp && video_mode != 5)
            {
                qDebug() << "ui->toolButton_AM->show()" << __LINE__;
                ui->toolButton_AM->show();
            }
        }else{
            if(!ui->toolButton_AM->isHidden() && !m_isAimTemp)
            {
                qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
                ui->toolButton_AM->hide();
            }
        }
        if(video_mode == 4 && fidpid)
        {
            if(!ui->toolButton_AM->isHidden() && !m_isAimTemp)
            {
                qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
                ui->toolButton_AM->hide();
            }
        }
        if(twice_analysis_start)
        {
            if(define_S6X0_S3X0)//判断是否为S300
            {
                if(fidpid)
                {
                    if(video_mode==4)
                    {
                        pic_swich_save = true;
                        ui->last_page->setEnabled(false);
                        ui->next_page->setEnabled(false);
                    }
                }
            }
        }
    }
    else
    {

    }
    update_main_show(MAIN_MODE);
}

void MainWidget::on_bright_mode_clicked(HP_BUTTON_STATUS status)
{
    Q_UNUSED(status);
    if(hpsetting.tempWengdangchange)//若处于自动调整温档状态
    {
        ui->bright_mode->set_hp_button_status(S_NORMAL);
        return;
    }
    ui->display->drawStatus = DS_NON;
    update_main_show(MAIN_BRIGHT_MODE);
  if(define_brightmode)                           //电机模式-->调整近焦和远焦
  {
      if(status == S_SELECT)
      {
          if( video_mode != 1 )
          {
              ui->focus_near->show();
              ui->focus_far->show();
          }
      }else if(status == S_DISABLE)
      {
          ;
      }
      else
      {
          ui->focus_near->close();
          ui->focus_far->close();
      }
  }else{
      if(status == S_SELECT)
      {
          signal_pc_sys_set_lcd_bright(1);
      }
      else
      {
          signal_pc_sys_set_lcd_bright(0);
      }
  }

}

void MainWidget::sebiao_groupbutton(QAbstractButton *bt, bool checked)
{
    qDebug() << "MainWidget::sebiao_groupbutton " << checked;
    slot_update_lcdoff_time(true);
    if(bt->objectName() == "toolButton_sb01")
    {
        if(checked)
        {
            video_sebiao = 0;
        }
    }
    if(bt->objectName() == "toolButton_sb02")
    {
        if(checked)
        {
            video_sebiao = 1;
        }
    }
    if(bt->objectName() == "toolButton_sb03")
    {
        if(checked)
        {
            video_sebiao = 2;
        }
    }
    if(bt->objectName() == "toolButton_sb04")
    {
        if(checked)
        {
            video_sebiao = 3;
        }
    }
    if(bt->objectName() == "toolButton_sb05")
    {
        if(checked)
        {
            video_sebiao = 4;
        }
    }
    if(bt->objectName() == "toolButton_sb06")
    {
        if(checked)
        {
            video_sebiao = 5;
        }
    }
    if(bt->objectName() == "toolButton_sb07")
    {
        if(checked)
        {
            video_sebiao = 6;
        }
    }
    if(bt->objectName() == "toolButton_sb08")
    {
        if(checked)
        {
            video_sebiao = 7;
        }
    }
    if(bt->objectName() == "toolButton_sb09")
    {
        if(checked)
        {
            video_sebiao = 8;
        }
    }
    if(bt->objectName() == "toolButton_sb10")
    {
        if(checked)
        {
            video_sebiao = 9;
        }
    }
    if(bt->objectName() == "toolButton_sb11")
    {
        if(checked)
        {
            video_sebiao = 10;
        }
    }
    if(bt->objectName() == "toolButton_sb12")
    {
        if(checked)
        {
            video_sebiao = 11;
        }
    }
    if(bt->objectName() == "toolButton_sb13")
    {
        if(checked)
        {
            video_sebiao = 12;
        }
    }
    if(bt->objectName() == "toolButton_sb14")
    {
        if(checked)
        {
            video_sebiao = 13;
        }
    }
    if(bt->objectName() == "toolButton_sb15")
    {
        if(checked)
        {
            video_sebiao = 14;
        }
    }
    if(bt->objectName() == "toolButton_sb16")
    {
        if(checked)
        {
            video_sebiao = 15;
        }
    }
    if(bt->objectName() == "toolButton_sb17")
    {
        if(checked)
        {
            video_sebiao = 16;
        }
    }
    if(sebiaoReverse)
    {
        int sendSebiao = video_sebiao | 0x80000000;
        if(checked)
        {
            signal_pc_image_set_colorruler(sendSebiao);
        }
    }
    else
    {
        if(checked)
        {
            signal_pc_image_set_colorruler(video_sebiao);
        }
    }
    ui->display->m_currSebiao = video_sebiao;
    slot_update_lcdoff_time(false);
}

void MainWidget::slot_sebiao_set_reverse(bool isReverse)
{
    sebiaoReverse = isReverse;
    if(sebiaoReverse)
    {
        int sendSebiao = video_sebiao | 0x80000000;
        signal_pc_image_set_colorruler(sendSebiao);
    }
    else
    {
        signal_pc_image_set_colorruler(video_sebiao);
    }
}

void MainWidget::mode_groupButton(QAbstractButton *bt, bool checked)
{
    qDebug() << "MainWidget::mode_groupButton" << bt->objectName();
    hpcameracap->m_isKjg = false;
    if(video_mode == 5)
    {
        qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
        ui->toolButton_AM->hide();
    }
    if(bt->objectName() == "toolButton_hongwai")
    {
        if(checked)
        {
            signal_pc_image_set_mode(0);
            hpresize.ui->slider_resize->setValue(10);
            video_mode = 0;
            KJGModeRelieveLimit();
        }
    }
    if(bt->objectName() == "toolButton_kejian")
    {
        if(checked)
        {
            signal_pc_image_set_mode(1);
            video_mode = 1;
            hpcameracap->m_isKjg = true;
            KJGModeLimit();
        }
    }

    if(bt->objectName() == "toolButton_msx")
    {
        if(checked)
        {
            signal_pc_image_set_mode(2);
            video_mode = 2;
            KJGModeRelieveLimit();
        }
    }
    if(bt->objectName() == "toolButton_hzh")
    {
        hpmode.ui->frame_pip->setVisible(checked);
        if(checked)
        {
            signal_pc_image_set_mode(3);
            video_mode = 3;
            KJGModeRelieveLimit();
        }
    }
    if(bt->objectName() == "toolButton_rdj")
    {
        if(checked)
        {
            if(fidpid)
            {
                hpmode.ui->frame_rdj->setVisible(false);
                signal_pc_image_set_mode(5);
                video_mode = 5;
                {
                    qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
                    ui->toolButton_AM->hide();
                }
            }
            else
            {
                get_tagRectTemp->start();
                signal_pc_image_set_mode(4);
                video_mode = 4;
            }
            KJGModeRelieveLimit();
        }
//        if(fidpid)
//        {
//            hpmode.ui->frame_rdj->setVisible(false);
//            ui->display->isVisibleLight=true;
//        }
    }
    if(ui->mode->get_hp_button_status() == S_SELECT)
    {
        ui->sebiao->set_hp_button_status(S_DISABLE);
        if(!ui->toolButton_AM->isHidden() && !m_isAimTemp)
        {
            qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
            ui->toolButton_AM->hide();
        }
    }else{
        if(video_mode != 1 && (!(video_mode == 5)))
        {
            ui->sebiao->set_hp_button_status(S_NORMAL);
            if(ui->toolButton_AM->isHidden() && !m_isAimTemp)
            {
                qDebug() << "ui->toolButton_AM->show()" << __LINE__;
                ui->toolButton_AM->show();
            }
        }
    }
    hpcameracap->ModeEnable(video_mode);
//    qDebug() << "----------------------------------------------------------hpmode.set_mode(video_mode)" << __LINE__;
    hpmode.set_mode(video_mode);
    if(video_mode == 5)
    {
        qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
        ui->toolButton_AM->hide();
    }
}

void MainWidget::pip_groupButton(QAbstractButton *bt, bool checked)
{
    if(bt->objectName() == "toolButton_other")
    {
        if(checked)
        {
            pippara.nPIP_RATE100 = 100;
            signal_pc_image_set_pip(pippara);
        }
    }

    if(bt->objectName() == "toolButton_auto")
    {

        if(checked)
        {
            pippara.nPIP_RATE100 = 100;
            signal_pc_image_set_pip(pippara);
        }
    }
    if(bt->objectName() == "toolButton_3_4")
    {
        if(checked)
        {
            pippara.nPIP_RATE100 = 75;
            signal_pc_image_set_pip(pippara);
        }
    }
    if(bt->objectName() == "toolButton_1_2")
    {
        if(checked)
        {
            pippara.nPIP_RATE100 = 50;
            signal_pc_image_set_pip(pippara);
        }
    }
    if(bt->objectName() == "toolButton_1_4")
    {
        if(checked)
        {
            pippara.nPIP_RATE100 = 25;
            signal_pc_image_set_pip(pippara);
        }
    }
}

void MainWidget::mode_hzh_adjust_release()
{
    if(ui->display->define_zoom)//这里S300是正确的
    {
        qDebug() << "HP_S350_or_S300" << HP_S350_or_S300;
        if(HP_S350_or_S300)
        {
//            hpmodehzhadjust.setRect(QRect(pippara.nPIP_X*168/100,pippara.nPIP_Y*167/100,pippara.nPIP_W*167/100,pippara.nPIP_H*167/100));//注意此为大部分版本都正确的数据，请不要删除，测试要求修改请在下面新增
            hpmodehzhadjust.setRect(QRect(pippara.nPIP_X*168/100,pippara.nPIP_Y*167/100 + 2,pippara.nPIP_W*167/100,pippara.nPIP_H*167/100));
        }
        else{
            hpmodehzhadjust.setRect(QRect(pippara.nPIP_X*167/100,pippara.nPIP_Y*176/100,pippara.nPIP_W*167/100,pippara.nPIP_H*176/100));
        }
    }else
    {
        qDebug() << "ui->display->define_zoom" << HP_S350_or_S300;
        hpmodehzhadjust.setRect(QRect(pippara.nPIP_X,pippara.nPIP_Y,pippara.nPIP_W,pippara.nPIP_H));
        if(isHcf)
        {
            hpmodehzhadjust.setRect(QRect(pippara.nPIP_X, pippara.nPIP_Y/(512.0 / 480),pippara.nPIP_W + 3,pippara.nPIP_H/(512.0 / 480)));
        }
    }
    hpmodehzhadjust.show();
}

void MainWidget::mode_rdj_adjust_release()
{
    hpmoderdjadjust.setTempUnit(hpsetting.gettempunit());
    hpmoderdjadjust.setTempRang(hpsetting.dangwei_list.at(hpsetting.ui->comboBox_dangwei->currentIndex()).minTemp/100,hpsetting.dangwei_list.at(hpsetting.ui->comboBox_dangwei->currentIndex()).maxTemp/100);
    hpmoderdjadjust.setFusion(fusionpara);
    hpmoderdjadjust.show();
}

void MainWidget::mode_handfution_clicked(bool checked)
{
    hpmode.ui->frame_handfution->setVisible(checked);
}

void MainWidget::slot_pc_cfg_get_pointconfig(unsigned char return_value,int apppoint )
{
    //app连接时，接收到的点信息，判断哪些点是有的
    qDebug() << "slot_pc_cfg_get_pointconfig" << apppoint;
    if(return_value == RE_OK)
    {
        int i;
        for(i=0;i<apppoint;i++)
        {
            if(ui->display->hir_analyse)//若为hir分析模式
            {
                signal_pc_measure_get_point(i);
                delaymsec(2);
            }else{
                signal_pc_measure_get_point(i);
                delaymsec(1);
            }
        }
    }

}


void MainWidget::slot_pc_cfg_get_lineconfig(unsigned char return_value, int   appline)
{
    if(return_value == RE_OK)
    {
        int i;
        for(i=0;i<appline;i++)
        {
            if(ui->display->hir_analyse)//若为hir分析模式
            {
                signal_pc_measure_get_line(i);
                delaymsec(1);
            }else{
                signal_pc_measure_get_line(i);
                delaymsec(1);
            }
        }
    }

}

void MainWidget::slot_pc_cfg_get_rectconfig(unsigned char return_value,  int  apprect)
{
    if(return_value == RE_OK)
    {
        int i;
        for(i=0;i<apprect;i++)
        {
            if(ui->display->hir_analyse)//若为hir分析模式
            {
                signal_pc_measure_get_rect(i);
                delaymsec(1);
            }else{
                signal_pc_measure_get_rect(i);
                delaymsec(1);
            }

        }
    }

}

void MainWidget::slot_pc_cfg_get_circleconfig(unsigned char return_value,  int  appcircle)
{
    if(return_value == RE_OK)
    {
        int i;
        for(i = 0 ; i < appcircle; i++)
        {
            if(ui->display->hir_analyse)//若为hir分析模式
            {
                signal_pc_measure_get_circle(i);
                delaymsec(1);
            }else{
                signal_pc_measure_get_circle(i);
                delaymsec(1);
            }

        }
    }

}

void MainWidget::slot_pc_sys_get_appcontrolstatus(unsigned char return_value, int value)
{
//    qDebug()<<"slot_pc_sys_get_appcontrolstatus:0x%02x" << return_value << value;
    if(return_value == RE_OK)
        {
            if(1 == value)
            {
//                qDebug()<<"rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr2";
                appcon_state= true;
                if (!hpmode.isHidden())
                {
                    on_mode_clicked(S_NORMAL);
                }
                 if (!hpsebiao.isHidden())
                 {
                     on_sebiao_clicked(S_NORMAL);
                 }
                 if(!hpresize.isHidden())
                {
                    on_resize_clicked(S_NORMAL);
                }
                ui->point->set_hp_button_status(S_DISABLE);
                ui->line->set_hp_button_status(S_DISABLE);
                ui->rect->set_hp_button_status(S_DISABLE);
                ui->circle->set_hp_button_status(S_DISABLE);
                ui->clean->set_hp_button_status(S_DISABLE);
                ui->polygon->set_hp_button_status(S_DISABLE);
                ui->mode->set_hp_button_status(S_DISABLE);
                if(define_brightmode)
                {
                    ui->bright_mode->set_hp_button_status(S_DISABLE);
                }
                ui->sebiao->set_hp_button_status(S_DISABLE);
                ui->resize->set_hp_button_status(S_DISABLE);
                ui->setting->set_hp_button_status(S_DISABLE);
                ui->preview->set_hp_button_status(S_DISABLE);
            }else if(0==value)
            {
                if (appcon_state== true)
                {
                    appcon_state=false;
//                    qDebug()<<"rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr0";
                    ui->display->clear_measure2();
                    ui->display->drawStatus = DS_NON;
                    singal_pc_cfg_get_pointconfig();
                    delaymsec(10);
                    singal_pc_cfg_get_lineconfig();
                    delaymsec(10);
                    singal_pc_cfg_get_rectconfig();
                    delaymsec(10);
                    singal_pc_cfg_get_circleconfig();
                    if(video_mode != 1)
                    {
                        if(!m_isAimTemp)
                        {
                            ui->point->set_hp_button_status(S_NORMAL);
                            ui->line->set_hp_button_status(S_NORMAL);
                            ui->rect->set_hp_button_status(S_NORMAL);
                            ui->circle->set_hp_button_status(S_NORMAL);
                            ui->polygon->set_hp_button_status(S_NORMAL);
                            ui->clean->set_hp_button_status(S_NORMAL);
                        }
                        ui->sebiao->set_hp_button_status(S_NORMAL);
                        ui->resize->set_hp_button_status(S_NORMAL);
                        if(define_brightmode)
                        {
                            if( video_mode == 1 )
                            {
                                ui->bright_mode->set_hp_button_status(S_DISABLE);
                            }
                            else
                            {
                                ui->bright_mode->set_hp_button_status(S_NORMAL);
                            }
                        }
                    }else{
                        ui->point->set_hp_button_status(S_DISABLE);
                        ui->line->set_hp_button_status(S_DISABLE);
                        ui->rect->set_hp_button_status(S_DISABLE);
                        ui->circle->set_hp_button_status(S_DISABLE);
                        ui->polygon->set_hp_button_status(S_DISABLE);
                        ui->clean->set_hp_button_status(S_DISABLE);
                        ui->sebiao->set_hp_button_status(S_DISABLE);
                        ui->resize->set_hp_button_status(S_NORMAL);
                        if(define_brightmode)
                        {
                            ui->bright_mode->set_hp_button_status(S_DISABLE);
                        }
                    }
                    if(video_mode == 1)
                    {
                        ui->resize->set_hp_button_status(S_NORMAL);
                    }else{
                        ui->resize->set_hp_button_status(S_NORMAL);
                    }
                    if((video_mode == 4 && fidpid) || video_mode == 5)
                    {
                        ui->point->set_hp_button_status(S_DISABLE);
                        ui->line->set_hp_button_status(S_DISABLE);
                        ui->rect->set_hp_button_status(S_DISABLE);
                        ui->circle->set_hp_button_status(S_DISABLE);
                        ui->polygon->set_hp_button_status(S_DISABLE);
                        ui->clean->set_hp_button_status(S_DISABLE);
                    }
                    ui->mode->set_hp_button_status(S_NORMAL);
                    ui->setting->set_hp_button_status(S_NORMAL);
                    ui->preview->set_hp_button_status(S_NORMAL);
                    signal_pc_image_set_mode(0);
                    hpresize.ui->slider_resize->setValue(10);
                    video_mode = 0;
                    KJGModeRelieveLimit();
//                    qDebug() << "----------------------------------------------------------hpmode.set_mode(video_mode)" << __LINE__;
                    hpmode.set_mode(video_mode);

                }else
                {
                    appcon_state=false;
                }
            }
            else{}
        }
    else
    {
//        qDebug()<<"slot_pc_sys_get_appcontrolstatus:0x%02x"<<return_value;
    }
}
//-----------------------------------------
void MainWidget::slot_pc_image_set_mode(unsigned char return_value)
{
    qDebug("slot_pc_image_set_mode:return_value:0x%02x",return_value);
    if(video_mode == 1)
    {
        if(!kjgToAutoRecirft->isActive())
        {
            kjgToAutoRecirft->start();
        }
    }
    else
    {
        if(autocretify_time >= 60)
        {
            if(!twice_analysis_start)
            {
                qDebug() << "QT signal_pc_key_auto_rectify" << __func__ <<__LINE__;
                signal_pc_key_auto_rectify();
                autocretify_time = 0;
            }
        }
        if(kjgToAutoRecirft->isActive())
        {
            kjgToAutoRecirft->stop();
            autocretify_time = 0;
        }
    }
}

void MainWidget::slot_pc_image_set_colorruler(unsigned char return_value)
{
    qDebug("slot_pc_image_set_colorruler:return_value:0x%02x",return_value);
}

void MainWidget::slot_pc_image_set_pip(unsigned char return_value)
{
    qDebug("slot_pc_image_set_pip:return_value:0x%02x",return_value);
}
void MainWidget::slot_core_annlysis_hir_twice_start(unsigned char return_value)
{
    qDebug("slot_core_annlysis_hir_twice_start:return_value:0x%02x",return_value);
    if(return_value == RE_OK)
    {
        ui->display->hir_analyse = true;
        hppreview->hhp.show();
        hppreview->hp_dialog->close();
    }
    else
    {
        hppreview->hp_dialog->setText(hpcameracap->analysisError);
        hppreview->hp_dialog->setDelayClose(3000);
    }
}
void MainWidget::slot_core_annlysis_hir_twice_suspend(unsigned char return_value)
{
    qDebug("slot_core_annlysis_hir_twice_suspend:return_value:0x%02x",return_value);
}
void MainWidget::slot_core_annlysis_hir_twice_stop(unsigned char return_value)
{
    qDebug("slot_core_annlysis_hir_twice_stop:return_value:0x%02x",return_value);
    if(return_value == RE_OK)
    {
        ui->display->hir_analyse = false;
        ui->display->hir_stop = true;
    }
}
void MainWidget::slot_pc_image_get_manual(unsigned char return_value, ComManualPara para)
{
    qDebug("slot_pc_image_get_manual:return_value:0x%02x",return_value);
    manualpara = para;
    if(manualpara.ManualType == 1)
    {
        auto_manual_flag = true;
        manualpara.ManualType = 0;
        signal_pc_image_set_manual(manualpara);
    }

    min_value100 = manualpara.TempLowest;
    max_value100 = manualpara.TempHighest;
    auto_manual_update();
}

void MainWidget::slot_pc_image_set_manual(unsigned char return_value)
{
    qDebug("slot_pc_image_set_manual:return_value:0x%02x",return_value);
}

void MainWidget::slot_pc_image_set_fusion(unsigned char return_value)
{
    qDebug("slot_pc_image_set_fusion:return_value:0x%02x",return_value);
}

void MainWidget::slot_pc_key_zoom(unsigned char return_value)
{
    qDebug("slot_pc_key_zoom:return_value:0x%02x",return_value);
}

void MainWidget::slot_pc_key_auto_rectify(unsigned char return_value)
{
    qDebug("slot_pc_key_aotu_rectify:return_value:0x%02x",return_value);
}

void MainWidget::slot_pc_key_set_freeze(unsigned char return_value)
{
    if(return_value == RE_OK)
    {
        if(m_panorama_cap && hp_panorama->isVisible())
        {
            qDebug() << "MainWidget::slot_pc_key_set_freeze" << hp_panorama->currPicNo;
            if(hp_panorama->currPicNo == 0)
            {
                slot_cap_camera_panorama();
                m_panorama_cap = false;
                return;
            }
            qDebug() << "MainWidget::slot_pc_key_set_freeze hp_panorama->getMatchDegree()" << hp_panorama->getMatchDegree();
            if(hp_panorama->getMatchDegree() > 30)
            {
                hp_panorama->setDialogVisiable(false);
                panorama_dialog.setDialogText(hp_panorama->m_confirmFusionMsg);
            }
            else
            {
                hp_panorama->setDialogVisiable(false);
                panorama_dialog.setDialogText(hp_panorama->m_fusionDegreeMsg);
            }
            panorama_dialog.move((ui->display->width() - hp_Wifi_search_Dialog->width()) / 2 + ui->frame->width(),(ui->display->height() - hp_Wifi_search_Dialog->height()) / 2);
            panorama_dialog.show();
            m_panorama_cap = false;
            start_capture = false;
            return;
        }
        if(hp_panorama->isVisible())
        {
            return;
        }

        if( start_capture && hpcameracap->isContinuedFreeze &&hpcameracap->isHidden() )
        {
            hpcameracap->isContinuedFreeze=false;
        }
        if( start_capture && !hpcameracap->isContinuedFreeze )
        {
            if(hpsetting.guowangFlag )
            {
                slot_temp_row_mode(0);
                slot_wait_warn();
            }else{
                slot_temp_row_mode(1);
                hpcameracap->init_cap();
                hpcameracap->ModeEnable(video_mode);
                QString para;
                para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
                if(para !=NULL)
                {
                    if(para.toInt() == 0)
                    {
                        hpcameracap->setText("冻结成功");
                    }
                    else if(para.toInt() == 1)
                    {
                        hpcameracap->setText("凍結成功");
                    }
                    else if(para.toInt() == 2)//english
                    {
                        hpcameracap->setText("Freeze Sucess");
                    }
                    else if(para.toInt() == 3)//俄语
                    {
                        hpcameracap->setText("Успешно");
                    }
                    else if(para.toInt() == 4)//匈牙利语
                    {
                        hpcameracap->setText("Leállítva");
                    }
                    else if(para.toInt() == 5)//西班牙语
                    {
                        hpcameracap->setText("Congelado logrado");
                    }
                }

                hpcameracap->show();
                start_capture = false;
                hpcameracap->isContinuedFreeze = true;
                ContinuedFreezeTimer->start();

                if(hpcameracap->Taskmode)
                {
                    qDebug() << "ui->display->m_filePathState == > " << ui->display->m_filePathState;
                    /* 作业模式下，冻结成功后查询框选信息 */
                    if(ui->display->m_filePathState) {//这里是判断是否为设备树界面，借用display中的m_filePathState变量，节省内存
                        qDebug() << "MainWidget::slot_pc_key_set_freeze : Get temp";
                        ui->display->reset_taskIndex();//重置display_aya_infos的节点指针
                        slot_read_img_process(0);//获取第一个节点信息,会在接收函数中反复读取，最终把所有的值都读取完毕
                    }
                    /* 禁用拍摄树控件 */
                    Hp_TaskPkg::getInstance()->Enable_TreeView(false);
                }
            }
        }
        else if( !start_capture && !hpcameracap->isContinuedFreeze )
        {
            if(wait_warn_state == true )
            {
                hp_wait_w.close();
                wait_warn = false;
                wait_warn_state =false;
            }

            QString para;
            para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
            if(para !=NULL)
            {
                if(para.toInt() == 0)
                {
                    hpcameracap->setText("解冻成功");
                }
                else if(para.toInt() == 1)
                {
                    hpcameracap->setText("解凍成功");
                }
                else if(para.toInt() == 2)//english
                {
                    hpcameracap->setText("Unfreeze Sucess");
                }
                else if(para.toInt() == 3)//俄语
                {
                    hpcameracap->setText("разморозить удалось");
                }
                else if(para.toInt() == 4)//匈牙利语
                {
                    hpcameracap->setText("Sikeres indítás");
                }
                else if(para.toInt() == 5)//西班牙语
                {
                    hpcameracap->setText("Descongelado exitoso");
                }
            }
        }
    }else{//若调零的时候拍照，则会返回错误
        qDebug("slot_pc_key_set_freeze:return_value:0x%02x",return_value);
        start_capture = false;
    }
}
/**********************************************************************
 * @ description   : 任务包模式下，读取分析框图温度信息
 * @ param - index : 框图索引
 * @ return        : null
 **********************************************************************/
void MainWidget::slot_read_img_process(int index)
{
    QVector<ANA_OUTLINE> points = ui->display->get_taskAnalys();
    ANA_OUTLINE point = points.at(index);
    if(point.ana_type[0] == 'P')
        emit signal_pc_measure_get_point(point.id);
    else if (point.ana_type[0] == 'L')
        emit signal_pc_measure_get_line(point.id);
    else if (point.ana_type[0] == 'R')
        emit signal_pc_measure_get_rect(point.id);
}
void MainWidget::slot_core_key_record_avi_start(unsigned char return_value)//hir和avi用的是同样的信号
{
    qDebug() << __func__ << "m_testHirTime.elapsed()" << m_testHirTime.elapsed() << __LINE__;
    if(return_value == 0x00)
    {
        start_record = true;

        hpcameravideo.show();               //显示该类 的界面

        hpcameravideo.timer_start();    //计时
        if( ui->mode->get_hp_button_status() == S_SELECT )
        {
            ui->mode->set_hp_button_status(S_NORMAL);
            on_mode_clicked(S_NORMAL);
        }
        if( ui->sebiao->get_hp_button_status() == S_SELECT )
        {
            ui->sebiao->set_hp_button_status(S_NORMAL);
            on_sebiao_clicked(S_NORMAL);
        }
        if( ui->resize->get_hp_button_status() == S_SELECT )
        {
            ui->resize->set_hp_button_status(S_NORMAL);
            on_resize_clicked(S_NORMAL);
        }
        PreviewIconLimit(S_DISABLE);
        ui->point->set_hp_button_status(S_DISABLE);
        ui->line->set_hp_button_status(S_DISABLE);
        ui->rect->set_hp_button_status(S_DISABLE);
        ui->circle->set_hp_button_status(S_DISABLE);
        ui->polygon->set_hp_button_status(S_DISABLE);
        ui->clean->set_hp_button_status(S_DISABLE);
        ui->setting->set_hp_button_status(S_DISABLE);
        ui->sebiao->set_hp_button_status(S_DISABLE);
        ui->resize->set_hp_button_status(S_DISABLE);
        ui->clean->set_hp_button_status(S_DISABLE);
        if(define_brightmode)
        {
            ui->bright_mode->set_hp_button_status(S_DISABLE);
        }
        if(define_brightmode && ui->focus_near->isVisible() && ui->focus_far->isVisible())
        {
            ui->focus_near->hide();
            ui->focus_far->hide();
        }
    }
}

void MainWidget::slot_core_key_record_avi_stop(unsigned char return_value)
{
    qDebug("slot_core_key_record_avi_stop:return_value:0x%02x",return_value);
    if(!hpsetting.hpblesearch.isLinked && !hpsetting.isBleOpen)
    {
        return_value = 0;
    }
    if(return_value == RE_ERR_DEV_AUDIO)
    {
        hp_Wifi_search_Dialog->move((ui->display->width() - hp_Wifi_search_Dialog->width()) / 2 + ui->frame->width(),(ui->display->height() - hp_Wifi_search_Dialog->height()) / 2);
        hp_Wifi_search_Dialog->Set_label_text(hpcameracap->RecordError);//借用
        hp_Wifi_search_Dialog->Set_button_text(hpsetting.hp_wifi_Search->fOK);//借用
        if(!hp_Wifi_search_Dialog->isVisible())
        {
            hp_Wifi_search_Dialog->show();
        }

        start_record = false;
//        hpcameravideo.timer_stop();

        hpcameravideo.close();
        PreviewIconLimit(S_NORMAL);
        if( hpmode.isVisible())
        {
            if( main_task_open == true )
                main_task_open = false;
            hpmode.close();
            if(mode_kjg == false){               //当前模式是    非可见光模式
                pic_swich_save = false;
                ui->last_page->setEnabled(last_botton_state);
                ui->next_page->setEnabled(next_botton_state);
                update_main_show(MAIN_MODE);
            }
        }
        if(video_mode != 1)
        {
            if(!m_isAimTemp)
            {
                ui->point->set_hp_button_status(S_NORMAL);
                ui->line->set_hp_button_status(S_NORMAL);
                ui->rect->set_hp_button_status(S_NORMAL);
                ui->circle->set_hp_button_status(S_NORMAL);
                ui->polygon->set_hp_button_status(S_NORMAL);
                ui->clean->set_hp_button_status(S_NORMAL);
            }
            ui->sebiao->set_hp_button_status(S_NORMAL);
        }else{
            ui->point->set_hp_button_status(S_DISABLE);
            ui->line->set_hp_button_status(S_DISABLE);
            ui->rect->set_hp_button_status(S_DISABLE);
            ui->circle->set_hp_button_status(S_DISABLE);
            ui->polygon->set_hp_button_status(S_DISABLE);
            ui->clean->set_hp_button_status(S_DISABLE);
            ui->sebiao->set_hp_button_status(S_DISABLE);
        }

        ui->setting->set_hp_button_status(S_NORMAL);
        ui->mode->set_hp_button_status(S_NORMAL);
        ui->preview->set_hp_button_status(S_NORMAL);
        if( video_mode == 0 )
            ui->resize->set_hp_button_status(S_NORMAL);
        else
            ui->resize->set_hp_button_status(S_DISABLE);
        if(define_brightmode)
        {
            if( video_mode == 1 )
            {
                ui->bright_mode->set_hp_button_status(S_DISABLE);
            }
            else
            {
                ui->bright_mode->set_hp_button_status(S_NORMAL);
            }
        }
        if( (video_mode == 4) && fidpid)//若为HSE模式
        {
            ui->point->set_hp_button_status(S_DISABLE);
            ui->line->set_hp_button_status(S_DISABLE);
            ui->rect->set_hp_button_status(S_DISABLE);
            ui->circle->set_hp_button_status(S_DISABLE);
            ui->polygon->set_hp_button_status(S_DISABLE);
            ui->clean->set_hp_button_status(S_DISABLE);
        }
    }
    if(return_value == 0x00)
    {
        start_record = false;
//        hpcameravideo.timer_stop();
        if(avi_hir_mode == 1)
        {
            QDir dir;
            QStringList filters;
            filters.clear();
            filters.append(QString("*.avi"));
            dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
            dir.setNameFilters(filters);
            dir.setSorting(QDir::Name | QDir::Reversed);
            dir.cd("/run/media/mmcblk2p1/DCIM");
            file_list.clear();
            file_list = dir.entryInfoList();//生成的时间越晚,下标越小
            hppreview->VideoForPNG(file_list.at(0).filePath(),file_list.at(0).fileName().section('.',0,0));//获取返回值 （20230725xyn)

            QImage test_img("./res/TempStoragePng/"+file_list.at(0).fileName().section('.',0,0)+".jpg");
            if(test_img.isNull())//若视频错误,则停止
            {
                qDebug() << ">>> test audio Error";
                formatDialog.setTextForVideo(fvideoError);
                formatDialog.show();
            }
            else{
                m_latestVideoName = file_list.at(0).fileName();
                QString m_newFileName = m_latestVideoName;
                m_newFileName = hpcameracap->getNewFileName(m_latestVideoName);
                QString newCmd = QString("mv ") + "/run/media/mmcblk2p1/DCIM/" + m_latestVideoName + " " + hpcameracap->dateFolderPath + m_newFileName;
                m_latestVideoName = m_newFileName;
                qDebug() << "RENAME !!! == > " << newCmd;
                system(newCmd.toUtf8().data());
                system("sync");
            }
        }

//        if(!hpsetting.hpblesearchold.get_conn_status() && !hpsetting.hpblesearch.isLinked)
//        {
//            if(hpsetting.isNewBle && !hpsetting.isBleOpen && !hpsetting.ui->checkBox_ble->isChecked())
//            {
//                signal_pc_sys_set_ble_module(0);
//                signal_pc_sys_set_ble_power(0);
//                isBlePowerOn = false;
//            }
//        }
        hpcameravideo.close();
        PreviewIconLimit(S_NORMAL);
        if( hpmode.isVisible())
        {
            if( main_task_open == true )
                main_task_open = false;
            hpmode.close();
            if(mode_kjg == false){               //当前模式是    非可见光模式
                pic_swich_save = false;
                ui->last_page->setEnabled(last_botton_state);
                ui->next_page->setEnabled(next_botton_state);
                update_main_show(MAIN_MODE);
            }
        }
        if(video_mode != 1)
        {
            if(!m_isAimTemp)
            {
                ui->point->set_hp_button_status(S_NORMAL);
                ui->line->set_hp_button_status(S_NORMAL);
                ui->rect->set_hp_button_status(S_NORMAL);
                ui->circle->set_hp_button_status(S_NORMAL);
                ui->polygon->set_hp_button_status(S_NORMAL);
                ui->clean->set_hp_button_status(S_NORMAL);
            }
            ui->sebiao->set_hp_button_status(S_NORMAL);
        }else{
            ui->point->set_hp_button_status(S_DISABLE);
            ui->line->set_hp_button_status(S_DISABLE);
            ui->rect->set_hp_button_status(S_DISABLE);
            ui->circle->set_hp_button_status(S_DISABLE);
            ui->polygon->set_hp_button_status(S_DISABLE);
            ui->clean->set_hp_button_status(S_DISABLE);
            ui->sebiao->set_hp_button_status(S_DISABLE);
        }

        ui->setting->set_hp_button_status(S_NORMAL);
        ui->mode->set_hp_button_status(S_NORMAL);
        ui->preview->set_hp_button_status(S_NORMAL);
        if( video_mode == 0 )
            ui->resize->set_hp_button_status(S_NORMAL);
        else
            ui->resize->set_hp_button_status(S_DISABLE);
        if(define_brightmode)
        {
            if( video_mode == 1 )
            {
                ui->bright_mode->set_hp_button_status(S_DISABLE);
            }
            else
            {
                ui->bright_mode->set_hp_button_status(S_NORMAL);
            }
        }
        if( (video_mode == 4) && fidpid)//若为HSE模式
        {
            ui->point->set_hp_button_status(S_DISABLE);
            ui->line->set_hp_button_status(S_DISABLE);
            ui->rect->set_hp_button_status(S_DISABLE);
            ui->circle->set_hp_button_status(S_DISABLE);
            ui->polygon->set_hp_button_status(S_DISABLE);
            ui->clean->set_hp_button_status(S_DISABLE);
        }
    }
}

void MainWidget::slot_delete_new_video()
{
    if(!m_latestVideoName.isEmpty())
    {
        QString cmd;
        cmd = "rm -f "+ hpcameracap->dateFolderPath + m_latestVideoName;
        QByteArray ba=cmd.toUtf8();
        system(ba);
        system("sync");
        m_latestVideoName.clear();
    }
}
void MainWidget::slot_core_analysis_pic_twice_start(unsigned char return_value)             //图片开始二次分析
{
    qDebug("slot_core_analysis_pic_twice_start :0x%02x",return_value);
    if(return_value == 0)
    {
        Twice_analysis = true;
        twice_analysis_start = true;
        hpsetting.ui->tabWidget->setTabEnabled(2,false);
        hpsetting.ui->tabWidget->setTabEnabled(3,false);
        hpsetting.ui->tabWidget->setTabEnabled(4,false);
        hpsetting.ui->tabWidget->setTabEnabled(5,false);
        ReferTemp=hpsetting.ui->ScrollBar_ReferTemp->value();
        qDebug() << "twice_analysis_cut_pic" << twice_analysis_cut_pic;
        if(true == twice_analysis_cut_pic)  //没用到
        {
            twice_analysis_cut_pic = false;
        }else{                  //开始二次分析时，打开一张图片
            twice_analysis_state=1;
            ui->display->hp_jpg_read(hppreview->direct,hppreview->file_name);
            qDebug() << __LINE__ << __func__;
            bak_video_mode = video_mode;
            qDebug() << __LINE__ << __func__;
            video_mode = ui->display->get_jpg_mode();
            qDebug() << __LINE__ << __func__;
            hpmode.set_mode(video_mode);
            qDebug() << __LINE__ << __func__;
            hpsetting.set_ScrollBar_TemperInfo(ui->display->get_jpg_wdxz());
            qDebug() << __LINE__ << __func__;
            if( video_mode == 0)
            {
                ui->resize->set_hp_button_status(S_NORMAL);
                qDebug() << __LINE__ << __func__;
            }else{
                ui->resize->set_hp_button_status(S_DISABLE);
                qDebug() << __LINE__ << __func__;
            }
            qDebug() << __LINE__ << __func__;
            if(video_mode == 1 || (video_mode == 4 && fidpid))//HSE模式和可见光模式一样
            {
                ui->point->set_hp_button_status(S_DISABLE);
                ui->line->set_hp_button_status(S_DISABLE);
                ui->rect->set_hp_button_status(S_DISABLE);
                ui->sebiao->set_hp_button_status(S_DISABLE);
                ui->clean->set_hp_button_status(S_DISABLE);
            }else{
                if(!m_isAimTemp)
                {
                    ui->point->set_hp_button_status(S_NORMAL);
                    ui->line->set_hp_button_status(S_NORMAL);
                    ui->rect->set_hp_button_status(S_NORMAL);
                    ui->clean->set_hp_button_status(S_NORMAL);
                }
                else
                {
                    ui->point->set_hp_button_status(S_DISABLE);
                    ui->line->set_hp_button_status(S_DISABLE);
                    ui->rect->set_hp_button_status(S_DISABLE);
                    ui->clean->set_hp_button_status(S_DISABLE);
                }
                ui->sebiao->set_hp_button_status(S_NORMAL);
            }
            qDebug() << __LINE__ << __func__;
            bak_video_sebiao = video_sebiao;
            video_sebiao = ui->display->get_jpg_sebiao();
            hpsebiao.set_sebiao(video_sebiao);

            ui->preview->set_hp_button_status(S_SELECT);
            if(define_brightmode)
            {
                ui->bright_mode->set_hp_button_status(S_DISABLE);
            }
            delaymsec(1000);
            hppreview->close();
            qDebug() << "htasssssssssssssssssssssssssssssssssssssssssssssssssssss" << __LINE__;
            hta->show();
            slot_set_twice_change_over();
        }
    }
    else
    {
        qDebug("slot_core_analysis_pic_twice_start:0x%02x",return_value);
    }
}

void MainWidget::slot_core_analysis_pic_twice_stop(unsigned char return_value)       //图片停止二次分析
{
    qDebug("slot_core_analysis_pic_twice_stop:return_value:0x%02x",return_value);
    if(return_value == RE_OK)
    {
        twice_analysis_start = false;
        hpsetting.ui->tabWidget->setTabEnabled(2,true);
        hpsetting.ui->tabWidget->setTabEnabled(3,true);
        hpsetting.ui->tabWidget->setTabEnabled(4,true);
        hpsetting.ui->tabWidget->setTabEnabled(5,true);
        hpsetting.ui->ScrollBar_ReferTemp->setValue(ReferTemp);
        if(hta->stop_twice_analysis("test.jpg"))
            qDebug()<<"stop_twice_analysis:true";
        else
            qDebug()<<"stop_twice_analysis:false";
        if(hta->voice_state)
        {
            signal_twice_voiceStop();
        }

        if(hp_dialog->isVisible())
        {
            hp_dialog->close();
        }
       if(true == twice_analysis_cut_pic)               //二次分析切换图片
       {
           signal_twice_pic_start();
           twice_analysis_cut_pic =false;

            ui->point->set_hp_button_status(S_NORMAL);
            ui->line->set_hp_button_status(S_NORMAL);
            ui->rect->set_hp_button_status(S_NORMAL);
            if(qrcode == true || hpsetting.guowangFlag)
                ui->mode->set_hp_button_status(S_DISABLE);
            else
                ui->mode->set_hp_button_status(S_NORMAL);
            ui->resize->set_hp_button_status(S_NORMAL);
            ui->sebiao->set_hp_button_status(S_NORMAL);
            ui->display->drawStatus = DS_NON;
            hta->slot_send_twice_text();//切换图片时更新注释

       }else{                                                               //没有切换图片，直接进入预览
            hppreview->update_dir_data(0);
           video_mode = bak_video_mode;
//           qDebug() << "----------------------------------------------------------hpmode.set_mode(video_mode)" << __LINE__;
            hpmode.set_mode(video_mode);
            video_sebiao = bak_video_sebiao;
            hpsebiao.set_sebiao(video_sebiao);

            ui->last_page->close();
            ui->next_page->close();
            //退出二次分析时，进入预览
            if(hta->play_state)
           {
              signal_twice_voicep_Stop();
           }
            hppreview->hp_text_input.setbtnTaskVisble(hppreview->Taskmode);
            ui->label_laserRange->close();
            hppreview->show();
            hta->close();
            preview_open = true;
            Twice_analysis=false;
            hppreview->pic_bad_exit_manage();
            twice_analysis_state=0;
        }
    }
    else
    {
    }

}
//PC发送给内核告诉可以运行视频模块了。（内核反馈已经收到）  当退出预览界面时用到
void MainWidget::slot_core_corectrl_start_encode(unsigned char return_value)
{
    qDebug("slot_core_corectrl_start_encode:return_value:0x%02x",return_value);
//    if(return_value != RE_OK)
//    {

//    }
    if(return_value == RE_OK)
    {
        hppreview->pic_type = 0;
        hppreview->video_current=0;          //视频当前页
        hppreview->picture_current=0;        //图片当前页
//        if(video_mode != 1 || (video_mode == 4 && FID_PID_MODE))//如果这里写了这一句会引发一个问题“可见光进入二次分析后，再退出，点线框无法选中，就是hp_list_restore没有保存或还原导致的”
//        {//但是不写好像不会发送什么，当初为什么要写呢？，这个判断的意思是如果为  可见光或者HSE模式，退出和进入预览时会保存点线框数据
            ui->display->hp_list_restore();
            hpsetting.ResetPreviewParameters();//高低温捕捉
//        }

        preview_open = false;
        update_main_show(MAIN_PREVIEW);

        pippara.nPIP_X =pippara_bak.nPIP_X ;
        pippara.nPIP_Y = pippara_bak.nPIP_Y;
        pippara.nPIP_W = pippara_bak.nPIP_W;
        pippara.nPIP_H = pippara_bak.nPIP_H;

        manualpara.ManualType = 1;
        auto_manual_flag = false;
        min_handle_flag = false;
        max_handle_flag = false;
        signal_pc_image_set_manual(manualpara);
        auto_manual_update();
        signal_pc_key_set_freeze(0);
        hppreview->close();
        previewShow();
        hp_dialog->setDelayClose(1500);
    }

    PreviewIconLimit(S_NORMAL);
    video_mode_hp = 0;
    hpmode.set_mode(video_mode_hp);
    signal_pc_image_set_mode(0);
    //恢复放大图标的状态
    if(video_mode == 0)
        ui->resize->set_hp_button_status(S_NORMAL);
    else
        ui->resize->set_hp_button_status(S_DISABLE);
    if(video_mode == 1)
    {
        ui->point->set_hp_button_status(S_DISABLE);
        ui->line->set_hp_button_status(S_DISABLE);
        ui->rect->set_hp_button_status(S_DISABLE);
        ui->sebiao->set_hp_button_status(S_DISABLE);
        ui->clean->set_hp_button_status(S_DISABLE);
    }else{
        if(!m_isAimTemp)
        {
            ui->point->set_hp_button_status(S_NORMAL);
            ui->line->set_hp_button_status(S_NORMAL);
            ui->rect->set_hp_button_status(S_NORMAL);
            ui->clean->set_hp_button_status(S_NORMAL);
        }
        ui->sebiao->set_hp_button_status(S_NORMAL);
    }
    if(video_mode != 0)
    {
        ui->resize->set_hp_button_status(S_DISABLE);
    }else{
        ui->resize->set_hp_button_status(S_NORMAL);
    }
    if(define_brightmode)
    {
        if( video_mode == 1 )
        {
            ui->bright_mode->set_hp_button_status(S_DISABLE);
        }
        else
        {
            ui->bright_mode->set_hp_button_status(S_NORMAL);
        }
    }
    if( (video_mode == 4) && fidpid)//若为HSE模式
    {
        ui->point->set_hp_button_status(S_DISABLE);
        ui->line->set_hp_button_status(S_DISABLE);
        ui->rect->set_hp_button_status(S_DISABLE);
        ui->clean->set_hp_button_status(S_DISABLE);
    }
    if(autocretify_pretime >= 60)
    {
        if(!twice_analysis_start)
        {
            delaymsec(1000);
            qDebug() << "QT signal_pc_key_auto_rectify" << __func__ <<__LINE__;
            signal_pc_key_auto_rectify();
            autocretify_pretime = 0;
        }
    }
    if(previewToAutoRecirft->isActive())
    {
        previewToAutoRecirft->stop();
        autocretify_pretime = 0;
    }

    hta->close();
    ui->label->close();
    ui->label_2->close();
    ui->next_page->close();
    ui->last_page->close();
}
//PC发送给内核告诉  停止视频模块了。（内核反馈已经收到）  进入预览界面时用到
void MainWidget::slot_core_corectrl_stop_encode(unsigned char return_value)
{
    //点击 正常的预览界面相应到
    video_mode_hp = video_mode;
    qDebug("slot_core_corectrl_stop_encode:return_value:0x%02x",return_value);
    if(return_value == RE_OK)
    {   //打开预览界面

        while(!hp_sorts->isSortOver())
        {
            qDebug() << "isSorting...";
            delaymsec(100);
        }
        hppreview->sortedFileList = hp_sorts->getSortFileList();
//        if(video_mode != 1 || (video_mode == 4 && FID_PID_MODE))
//        {
            ui->display->hp_list_save();
            hpsetting.StoragePreviewParameters();
//        }

//        hppreview->set_pc_image_hir_composite();
        hppreview->pic_type = 0;
        hppreview->video_current=0;          //视频当前页
        hppreview->picture_current=0;        //图片当前页
         hppreview->current_page=0;
        hppreview->update_dir_data(0);
        hppreview->hp_text_input.setbtnTaskVisble(hppreview->Taskmode);
        ui->label_laserRange->close();
        hppreview->show();
//        hppreview->previewTest();
         preview_open = true;
         hppreview->pic_bad_exit_manage();


         if(hp_dialog->isVisible())
             hp_dialog->close();
        // pippara_bak
         pippara_bak.nPIP_X =pippara.nPIP_X ;
         pippara_bak.nPIP_Y = pippara.nPIP_Y;
         pippara_bak.nPIP_W = pippara.nPIP_W;
         pippara_bak.nPIP_H = pippara.nPIP_H;
    }
    PreviewIconLimit(S_NORMAL);
    //读取放大图标的状态
    resize_state = ui->resize->get_hp_button_status();




    if(!previewToAutoRecirft->isActive())
    {
        previewToAutoRecirft->start();
    }
}

void MainWidget::slot_core_get_sdinsert(unsigned char return_value, int si)         //sd_info
{
    //    qDebug("slot_core_get_sdinsert:%02x value:%d",return_value,si);
    bool main_task_sd_old=true;
    static bool isFirst=true;
    main_task_sd_old = main_task_sd;
    if(return_value == RE_OK)
    {
        if(si == 0)
            main_task_sd = true;
        else
            main_task_sd = false;
    }
    else
    {
        main_task_sd = false;
    }
    if(main_task_sd_old != main_task_sd && !main_task_sd)
    {
        m_pmsUploadFlag = false;
        hpsetting.ui->checkBox_transmission->clicked(false);
        hpsetting.ui->checkBox_transmission->setChecked(false);
    }
//    if((si == 2 || si == 3))
//    {
//        hssw->warning(fError,fErrReInsert);
//        hssw->show();
//        main_task_sd = false;
//    }
    if( main_task_sd_old != main_task_sd || isFirst )//只有状态改变的时候才会进行更新操作
    {
        qDebug()<<"MainWidget::slot_core_get_sdinsert........................1main_task_sd_old != main_task_sd";
        if( !main_task_sd )
        {
            set_twice_text_about_preview();
            signal_sd_put_out_cap();
            hssw->warning(fError,fNoSD);
            hssw->setDelayClose(3000);
            hssw->show();
        }
        hppreview->setsdinsert(main_task_sd);
        hpsetting.hp_downLoad->sd_insert = main_task_sd;//设置sd卡状态
        if( !main_task_sd )
        {
            if( twice_analysis_start )//我们只有在红外分析的时候拔出SD卡才会退到预览模式
            {
                if(video_mode == 1) //需要进行可见光转红外再进行退出
                {
                    qDebug()<<"trans hongwai..........................................";
                    hpmode.ui->toolButton_hongwai->setChecked(true);
                    hpmode.ui->toolButton_hongwai->clicked(true);
                }
                hta->stop_twice_preview =true;
                  if(hta->play_state)
                 {
                    signal_twice_voicep_Stop();
                 }
//                  if(hta->voice_state==true)
//                  {
//                       signal_twice_voiceStop();
//                  }
                 signal_core_analysis_pic_twice_stop();
            }
            else if( hp_twice_kjg.isVisible() )
            {
                hp_twice_kjg.close();
            }
        }
        isFirst=false;
        if(main_task_sd)
        {
            signal_core_get_sd_info();
        }
    }
}
void MainWidget::slot_SetMainWifiDisconnect()
{
    hp_Wifi_search_Dialog->move((ui->display->width() - hp_Wifi_search_Dialog->width()) / 2 + ui->frame->width(),(ui->display->height() - hp_Wifi_search_Dialog->height()) / 2);
    hp_Wifi_search_Dialog->Set_label_text(tr("网络连接已断开"));
    hp_Wifi_search_Dialog->Set_button_text(tr("确定"));
    if(!hp_Wifi_search_Dialog->isVisible())
    {
        hp_Wifi_search_Dialog->show();
    }
    hp_Wifi_search_Dialog->setDelayClose(3000);
}
void MainWidget::slot_SetMainCameraCapDialog(QString str,int ret)
{
    hp_Wifi_search_Dialog->move((ui->display->width() - hp_Wifi_search_Dialog->width()) / 2 + ui->frame->width(),(ui->display->height() - hp_Wifi_search_Dialog->height()) / 2);
    hp_Wifi_search_Dialog->Set_label_text(str);

    QString para;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    if(para !=NULL)
    {
        if(para.toInt() == 0)
        {
            hp_Wifi_search_Dialog->Set_button_text(tr("确定"));
        }
        else if(para.toInt() == 1)
        {
            hp_Wifi_search_Dialog->Set_button_text(tr("確定"));
        }
        else if(para.toInt() == 2)//english
        {
            hp_Wifi_search_Dialog->Set_button_text(tr("OK"));
        }
        else if(para.toInt() == 3)//俄语
        {
            hp_Wifi_search_Dialog->Set_button_text(tr("ОК"));
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            hp_Wifi_search_Dialog->Set_button_text(tr("Igen"));
        }
        else if(para.toInt() == 5)//西班牙语
        {
            hp_Wifi_search_Dialog->Set_button_text(tr("OK"));
        }
    }

    if(!hp_Wifi_search_Dialog->isVisible())
    {
        hp_Wifi_search_Dialog->show();
    }
    if(ret == 1)
    {
        hp_Wifi_search_Dialog->setDelayClose(3000);
    }
}
void MainWidget::slot_core_get_usbinsert(unsigned char return_value, int ui)      //插入了USB
{
    if(return_value == RE_OK)
    {
        if(ui == 0){
           if(true == main_task_usb){

               if(main_task_eth)
               {
                   hpsetting.ui->checkBox_eth->setChecked(false);
                   hpsetting.ui->checkBox_eth->clicked(false);
                   main_task_eth = false;
                  // PreviewIconLimit(S_NORMAL);
               }
                hp_usb_insert.close();
                usb_uart_insert = true;
                isUSBPreviewLimit = true;
                QTimer::singleShot( 7000,this, SLOT(SlotUsbPreview()) );
           }
            main_task_usb = false;
            hpsetting.ui->checkBox_eth->setEnabled(false);
        }else{
            if(usb_uart_insert ==true)
            {
                    usleep(200000);
                if( 1 == usb_mode)
                {
                    //根据/dev/input 下面的文件夹判断是 输入设备。 还是USB传输
                    QDir myDir( "/dev/input");
                    if(! myDir.exists()){
                        qDebug( )<<" :/dev/input not exists";
                    }
                    //创建一个列表
                    QList<QString> my_list;
                    my_list = myDir.entryList();

                    for(int i=0; i<my_list.size();i++)
                    {
                        if( my_list.at(i).contains("by-id"))    //如果存在这个文件夹，表示是输入设备。不进行处理
                        {
                                usb_uart_insert = false;
                        } else{};
                    }

//                    if(usb_uart_insert ==true)
//                        hp_usb_insert.show();
                }
            }
           main_task_usb = true;
           hpsetting.ui->checkBox_eth->setEnabled(true);
           this->ui->preview->set_hp_button_status(S_DISABLE);
        }
    }
    else
    {
        if(true == main_task_usb){
             hp_usb_insert.close();
             usb_uart_insert = true;
        }
        main_task_usb = false;
    }
}
//拔出USB后的预览设置
void MainWidget::SlotUsbPreview()
{
    if( !hpmode.isVisible() && !hpsebiao.isVisible() && !hpresize.isVisible() )
        PreviewIconLimit(S_NORMAL);
    isUSBPreviewLimit = false;
}

void MainWidget::slot_core_get_sd_info(unsigned char return_value, sdinfo_t sdinfo)
{
    //    qDebug("slot_core_get_sd_info:0x%02x",return_value);
    if(return_value == RE_OK)
    {
        if(start_record)
        {
            if(sdinfo.totalMB == 0)
            {
                main_task_sd = false;
            }
            else
            {
                qDebug() << "SIZE1-->" << sdinfo.usedMB*100;
                qDebug() << "SIZE2-->" << sdinfo.totalMB;
                qDebug() << "SIZE3-->" << sdinfo.usedMB*100/sdinfo.totalMB;
                main_task_sd = true;
                if(sdinfo.usedMB*100/sdinfo.totalMB > 97)  //若只剩下%2时，不允许存入
                {
                    qDebug() << "-----IS ENATH-----";
                    sd_space_enough = true;
                    //以下为停止录制
                    if(HVI_mode == 1)
                    {
                        if (1 == avi_hir_mode)
                        {
                            avi_record_get_SDInfo->stop();
                            hpcameravideo.timer_stop();
                            signal_core_key_record_avi_stop();
                            avi_hir_mode = 0;
                        }else if(2 == avi_hir_mode)
                        {
                            avi_record_get_SDInfo->stop();
                            hpcameravideo.timer_stop();
                           signal_core_key_record_hir_stop();
                            avi_hir_mode = 0;
                        }else{};
                    }else if(HIR_Mode ==1)
                    {
                        if (1 == avi_hir_mode)
                        {
                            avi_record_get_SDInfo->stop();
                            hpcameravideo.timer_stop();
                            signal_core_key_record_avi_stop();
                        }else if(2 == avi_hir_mode)
                        {
                            avi_record_get_SDInfo->stop();
                            hpcameravideo.timer_stop();
                            signal_core_key_record_hir_stop();
                        }else{};
                    }
                    else
                    {
                        avi_record_get_SDInfo->stop();
                        hpcameravideo.timer_stop();
                        signal_core_key_record_avi_stop();                           //只有视频模式，需要时打开，然后屏蔽下面的 hvi模式
                    }
                    hssw->warning(fError,fautoStopVideo);
                    hssw->setDelayClose(3000);
                    hssw->show();
                }else{
                    sd_space_enough = false;
                }
            }
        }else{
            if(sdinfo.totalMB == 0)
            {
                main_task_sd = false;
            }
            else
            {
                main_task_sd = true;
                if(sdinfo.usedMB*100/sdinfo.totalMB >97)
                {
                    sd_space_enough = true;//注意：这个变量是反过来判断的，这里表示空间不足
                }else{
                    sd_space_enough = false;
                }
            }
        }
        hppreview->setSdInfo(sdinfo);
    }
    else
    {
        main_task_sd = false;
        hppreview->setSdInfo(sdinfo);
    }
}

void MainWidget::slot_core_get_battery(unsigned char return_value, int battery_value)
{
//    qDebug("slot_core_get_battery:0x%02x value:%d ",return_value,battery_value);
//    qDebug()<<"main_task_battery_charge:"<<main_task_battery_charge;
    if(return_value == RE_OK)
    {
        if(battery_value == 0x7fff)
        {
            if(main_task_battery_charge)
            {
                if(hp_power_w.battery_warn_state == true)
                {
                    signal_close_poweroff_warn();
                }
                ui->widget_task->update_battery_stylesheet("border-image:url(:/res/res/battery_chongdian.png);");
                ui->widget_task_1->update_battery_stylesheet("border-image:url(:/res/res/left/battery_chongdian.png);");
                ui->widget_task_2->update_battery_stylesheet("border-image:url(:/res/res/down/battery_chongdian.png);");
                ui->widget_task_3->update_battery_stylesheet("border-image:url(:/res/res/right/battery_chongdian.png);");
            }
            else
            {
                ui->widget_task->update_battery_stylesheet("border-image:url(:/res/res/battery_5_max.png);");
                ui->widget_task_1->update_battery_stylesheet("border-image:url(:/res/res/left/battery_5_max.png);");
                ui->widget_task_2->update_battery_stylesheet("border-image:url(:/res/res/down/battery_5_max.png);");
                ui->widget_task_3->update_battery_stylesheet("border-image:url(:/res/res/right/battery_5_max.png);");
            }
        }
        else
        {
            if(1)
            {
                if(battery_value>=BATTERY_MIN && battery_value<BATTERY_STEP1)               // 0=< X  <355.9
                {
                    //            QImage image(":/res/res/battery_min_1.png");
                    ui->widget_task->update_battery_stylesheet("border-image:url(:/res/res/battery_min_1.png);");
                    ui->widget_task_1->update_battery_stylesheet("border-image:url(:/res/res/left/battery_min_1.png);");
                    ui->widget_task_2->update_battery_stylesheet("border-image:url(:/res/res/down/battery_min_1.png);");
                    ui->widget_task_3->update_battery_stylesheet("border-image:url(:/res/res/right/battery_min_1.png);");
                }
                else if(battery_value>=BATTERY_STEP1 && battery_value<BATTERY_STEP2)        // 355.9=< X  <1423.6
                {
                    //            QImage image(":/res/res/battery_1_2.png");
                    ui->widget_task->update_battery_stylesheet("border-image:url(:/res/res/battery_1_2.png);");
                    ui->widget_task_1->update_battery_stylesheet("border-image:url(:/res/res/left/battery_1_2.png);");
                    ui->widget_task_2->update_battery_stylesheet("border-image:url(:/res/res/down/battery_1_2.png);");
                    ui->widget_task_3->update_battery_stylesheet("border-image:url(:/res/res/right/battery_1_2.png);");
                }
                else if(battery_value>=BATTERY_STEP2 && battery_value<BATTERY_STEP3)        // 1423.6=< X  <2847.2
                {
                    //            QImage image(":/res/res/battery_2_3.png");
                    ui->widget_task->update_battery_stylesheet("border-image:url(:/res/res/battery_2_3.png);");
                    ui->widget_task_1->update_battery_stylesheet("border-image:url(:/res/res/left/battery_2_3.png);");
                    ui->widget_task_2->update_battery_stylesheet("border-image:url(:/res/res/down/battery_2_3.png);");
                    ui->widget_task_3->update_battery_stylesheet("border-image:url(:/res/res/right/battery_2_3.png);");

                }
                else if(battery_value>=BATTERY_STEP3 && battery_value<BATTERY_STEP4)        // 2847.2=< X  <4270.8
                {
                    //            QImage image(":/res/res/battery_3_4.png");
                    ui->widget_task->update_battery_stylesheet("border-image:url(:/res/res/battery_3_4.png);");
                    ui->widget_task_1->update_battery_stylesheet("border-image:url(:/res/res/left/battery_3_4.png);");
                    ui->widget_task_2->update_battery_stylesheet("border-image:url(:/res/res/down/battery_3_4.png);");
                    ui->widget_task_3->update_battery_stylesheet("border-image:url(:/res/res/right/battery_3_4.png);");

                }
                else if(battery_value>=BATTERY_STEP4 && battery_value<BATTERY_STEP5)        // 4270.8=< X  <5694.4
                {
                    //            QImage image(":/res/res/battery_4_5.png");
                    ui->widget_task->update_battery_stylesheet("border-image:url(:/res/res/battery_4_5.png);");
                    ui->widget_task_1->update_battery_stylesheet("border-image:url(:/res/res/left/battery_4_5.png);");
                    ui->widget_task_2->update_battery_stylesheet("border-image:url(:/res/res/down/battery_4_5.png);");
                    ui->widget_task_3->update_battery_stylesheet("border-image:url(:/res/res/right/battery_4_5.png);");

                }
                else if(battery_value>=BATTERY_STEP5)                                                               // X  >=5694.4
                {
                    //            QImage image(":/res/res/battery_5_max.png");
                    ui->widget_task->update_battery_stylesheet("border-image:url(:/res/res/battery_5_max.png);");
                    ui->widget_task_1->update_battery_stylesheet("border-image:url(:/res/res/left/battery_5_max.png);");
                    ui->widget_task_2->update_battery_stylesheet("border-image:url(:/res/res/down/battery_5_max.png);");
                    ui->widget_task_3->update_battery_stylesheet("border-image:url(:/res/res/right/battery_5_max.png);");
                }

                //电量高于某个值时自动将 battery_warn设置为真。
                if(battery_value > (BATTERY_MIN+420))
                {
                    battery_warn = true;
                }
                //提示电量低，请及时充电
                if((battery_value < (BATTERY_MIN+400)) &&(battery_warn == true))
                {
                    hp_power_w.battery_warn_state = true;
                    hp_power_w.show();
                    battery_warn = false;
                }

                if(battery_value < (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*3/100))  //19104+(26222-19104)*3/100 =19104 + 213.54
                {
                    if(!hpd.get_shutting())
                    {
                        hpd.start_delay();
                        hpd.show();
                    }
                }
            }
            else
            {
                ui->widget_task->update_battery_stylesheet("border-image:url(:/res/res/battery_error.png);");
                ui->widget_task_1->update_battery_stylesheet("border-image:url(:/res/res/left/battery_error.png);");
                ui->widget_task_2->update_battery_stylesheet("border-image:url(:/res/res/down/battery_error.png);");
                ui->widget_task_3->update_battery_stylesheet("border-image:url(:/res/res/right/battery_error.png);");
            }
        }
    }
    else
    {
        qDebug()<<"get battery error";
    }
}

void MainWidget::slot_pc_sys_set_lcd_bright(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_lcd_bright:0x%02x",return_value);
}

void MainWidget::slot_core_get_battery_charge(unsigned char return_value, int charge)
{
//    qDebug("slot_core_get_battery_charge:0x%02x charge:%d",return_value,charge);
    if(return_value ==RE_OK)
    {
        if(charge == 0)
        {
            main_task_battery_charge = false;
        }
        else
        {
            main_task_battery_charge = true;
            //            ui->widget_task->update_battery_stylesheet("border-image:url(:/res/res/battery_chongdian.png);");
        }
    }
}

void MainWidget::slot_core_get_usbwifiinsert(unsigned char return_value, int uwi)
{
//       qDebug("slot_core_get_usbwifiinsert:0x%02x uwi:%d",return_value,uwi);
    if(return_value ==RE_OK)
    {
//        if(uwi == 0)
//        {
//            main_task_wifi_insert = false;

//            if(hpsetting.ui->checkBox_wifi->isChecked())
//            {
//                hpsetting.ui->checkBox_wifi->setChecked(false);
//                main_task_wifi = false;             //关闭wifi.
//                PreviewIconLimit(S_NORMAL);        //恢复预览按钮为正常状态
//            }
//        }
//        else
//        {
//            main_task_wifi_insert = true;
//        }

//        hpsetting.ui->checkBox_wifi->setEnabled(main_task_wifi_insert);
//        if((wifi_insert_first ==0) && (main_task_wifi_insert==true)){
//             wifi_insert_first =1;
//             ui->preview->set_hp_button_status(S_DISABLE);
//             main_task_wifi = true;
//        }
    }
}
void MainWidget::avi_record_get_SDInfoTimeOut()
{
    if(start_record)
    {
        signal_core_get_sd_info();
    }
}
void MainWidget::kjgToAutoRecirftTimeOut()
{
    if(autocretify_time >= 60)
    {

    }else{
        autocretify_time++;
    }
}
void MainWidget::settingToAutoRecirftTimeOut()
{
    if(autocretify_settime >= 60)
    {

    }else{
        autocretify_settime++;
    }
}
void MainWidget::previewToAutoRecirftTimeOut()
{
    if(autocretify_pretime >= 60)
    {

    }else{
        autocretify_pretime++;
    }
}
void MainWidget::autoUpdateGetStatusTimeOut()
{
    qDebug() << "MainWidget::autoUpdateGetStatusTimeOut";
    hpsetting.hp_autoupload_dialog->setFrame3Text(hpcameracap->UploadWrong);
    if(upload_mode == enum_AUP_ftp)
    {
        signal_pc_set_upload_break(1);
    }else if(upload_mode == enum_AUP_SERVER || upload_mode == enum_AUP_SERVER_PLUS)
    {
        hpsetting.hp_autoupload->slot_srvupload_cancel();
    }
}
void MainWidget::autoUpdateClose()
{
    qDebug() << "MainWidget::autoUpdateClose";
    if(autoupload_once == false)//如果说已经取消了
    {
        qDebug() << "Set == > hpcameracap->autoUpdateonce == false";
        hpcameracap->autoUpdateonce = false;//直到上传窗口关闭，才将这个变量放开
        hpsetting.hp_autoupload_dialog->close();
        return;
    }
    hpsetting.hp_autoupload_dialog->setFrame3Text(hpcameracap->CancelUploadOK);
    hpsetting.hp_autoupload_dialog->upload_break();//展示弹窗
    if(upload_mode == enum_AUP_ftp)
    {
        signal_pc_set_upload_break(1);
    }else if(upload_mode == enum_AUP_SERVER || upload_mode == enum_AUP_SERVER_PLUS)
    {
        hpsetting.hp_autoupload->slot_srvupload_cancel();
    }
}
void MainWidget::slot_pc_set_upload_break(unsigned char return_value)
{
    if(autoupload_once == false)//若不处于一键上传状态
    {
        return;
    }
    qDebug("MainWidget::slot_pc_set_upload_break:%02x",return_value);
    autoupload_once = false;
    hpsetting.hp_autoupload_dialog->upload_break();
    if(AutoUpdateGetStatus->isActive())
        AutoUpdateGetStatus->stop();
    file_list.clear();
    autoupload_num = 0;
}
void MainWidget::timer_3s_func()
{
    if(hpcameracap->isActiveWindow())
    {
        hpcameracap->close();
        signal_pc_key_set_freeze(0);
        qDebug("hpcameracap closed...");
    }
    else
    {

    }
}
void MainWidget::slot_start_hir_analyse(QString filename,bool checked)
{
    qDebug() << "slot_start_hir_analyse";
    hir_analyse = true;
    ui->display->isVisibleLight=false;//不知道为啥之前会限制，先写上
    signal_hir_twice_lockstatus(1);
    signal_hir_twice_get_zoom();
    signal_hir_twice_get_colorrule();
    ui->setting->hide();
    hppreview->hide();

    ui->mode->set_hp_button_status(S_DISABLE);
    ui->bright_mode->set_hp_button_status(S_DISABLE);
    ui->toolButton_pause->setChecked(checked);

    if(checked)
    {
        toolButton_pause_Clicked(checked);
    }else{
        ui->point->set_hp_button_status(S_DISABLE);
        ui->line->set_hp_button_status(S_DISABLE);
        ui->rect->set_hp_button_status(S_DISABLE);
        ui->clean->set_hp_button_status(S_DISABLE);
        ui->sebiao->set_hp_button_status(S_DISABLE);
        ui->resize->set_hp_button_status(S_DISABLE);
        ui->display->clear_selecte_status();                //清除选中
        ui->display->hir_stop = false;
    }
    ui->toolButton_pause->show();
    hppreview->hhp.hide();
    this->show();
}
void MainWidget::slot_stop_hir_analyse()
{
    if(!hir_analyse)//若不处于hir二次分析模式，则直接退出
    {
        return;
    }

    signal_hir_twice_lockstatus(0);
    ui->setting->show();
    ui->toolButton_pause->close();
    ui->mode->set_hp_button_status(S_NORMAL);
    if(define_brightmode)
    {
        if( video_mode == 1 )
        {
            ui->bright_mode->set_hp_button_status(S_DISABLE);
        }
        else
        {
            ui->bright_mode->set_hp_button_status(S_NORMAL);
        }
    }else{
        ui->bright_mode->set_hp_button_status(S_NORMAL);
    }
    hppreview->hhp.set_toolButton_pause_checked(ui->toolButton_pause->isChecked());
//    ui->display->isVisibleLight=true;
    ui->label_laserRange->close();
    hppreview->show();
    hppreview->hhp.show();
    hir_analyse = false;
}
void MainWidget::toolButton_pause_Clicked(bool click)
{
    qDebug() << "MainWidget::CHECK ==> " << click;
    if(click)
    {
        qDebug() << "ui->display->drawStatus == > " << ui->display->drawStatus;
        if(ui->display->drawStatus == DS_POINT)
        {
            ui->point->set_hp_button_status(S_SELECT);
        }else{
            ui->point->set_hp_button_status(S_NORMAL);
        }
        if(ui->display->drawStatus == DS_LINE)
        {
            ui->line->set_hp_button_status(S_SELECT);
        }else{
            ui->line->set_hp_button_status(S_NORMAL);
        }
        if(ui->display->drawStatus == DS_RECT)
        {
            ui->rect->set_hp_button_status(S_SELECT);
        }else{
            ui->rect->set_hp_button_status(S_NORMAL);
        }
        ui->clean->set_hp_button_status(S_NORMAL);
        ui->sebiao->set_hp_button_status(S_NORMAL);
        ui->resize->set_hp_button_status(S_NORMAL);
        slot_hir_analyse_get_measure();
        ui->display->hir_stop = true;
        signal_core_annlysis_hir_twice_suspend(1);//暂停
    }
    else
    {
        if(hpsebiao.isVisible())
        {
            on_sebiao_clicked(S_NORMAL);
            ui->preview->set_hp_button_status(S_NORMAL);
        }
        if(hpresize.isVisible())
        {
            on_resize_clicked(S_NORMAL);
            ui->preview->set_hp_button_status(S_NORMAL);
        }
        ui->point->set_hp_button_status(S_DISABLE);
        ui->line->set_hp_button_status(S_DISABLE);
        ui->rect->set_hp_button_status(S_DISABLE);
        ui->clean->set_hp_button_status(S_DISABLE);
        ui->sebiao->set_hp_button_status(S_DISABLE);
        ui->resize->set_hp_button_status(S_DISABLE);
        ui->display->clear_selecte_status();                //清除选中
        ui->display->hir_stop = false;
        signal_core_annlysis_hir_twice_suspend(0);//播放
    }
}
void MainWidget::slot_hir_twice_get_zoom(unsigned char return_value, int value)
{
    qDebug("slot_hir_twice_get_zoom:return_value:0x%02x  >> %d",return_value,value);
    hpresize.setValue(value);
}
void MainWidget::slot_hir_twice_get_colorrule(unsigned char return_value, int value)
{
    qDebug("slot_hir_twice_get_colorrule:return_value:0x%02x  >> %d",return_value,value);
    hpsebiao.set_sebiao(value);
}
void MainWidget::slot_hir_twice_lockstatus(unsigned char return_value)
{
    qDebug("slot_hir_twice_lockstatus:return_value:0x%02x",return_value);
}
void MainWidget::slot_pc_measure_tempcenter(unsigned char return_value)
{
    qDebug("slot_pc_measure_tempcenter:return_value:0x%02x",return_value);
}

void MainWidget::slot_pc_sys_set_analog_video(unsigned char return_value)
{
    qDebug() << __func__ << "m_testHirTime.elapsed()" << m_testHirTime.elapsed() << __LINE__;
    if(hp_dialog->isVisible())
    {
        hp_dialog->close();
    }
    if(2 == avi_hir_mode && m_hirRecordStarted)
    {
//        signal_core_key_record_hir_mode_start();
        m_hirRecordStarted = false;
    }
}
void MainWidget::preview_finish()                                                   //退出预览界面后。给的槽list_clean
{
    signal_core_corectrl_start_encode();
    if(!hpsetting.hpblesearchold.get_conn_status() && !hpsetting.hpblesearch.isLinked)
    {
        if(hpsetting.isNewBle && !hpsetting.isBleOpen && !hpsetting.ui->checkBox_ble->isChecked())
        {
            signal_pc_sys_set_ble_module(0);
            signal_pc_sys_set_ble_power(0);
            isBlePowerOn = false;
        }
    }
    hta->close();
    ui->label->close();
    ui->label_2->close();
    ui->next_page->close();
    ui->last_page->close();
}

void MainWidget::slot_set_main_analog_audio()
{
    if(hpsetting.isNewBle &&  !hpsetting.isBleOpen && !hpsetting.ui->checkBox_ble->isChecked())
    {
//        m_testHirTime.start();
        signal_pc_sys_set_analog_video(1);
//        hp_dialog->setText(hpcameracap->WaitShow);//借用
//        hp_dialog->show();
    }
}

void MainWidget::mode_hzh_adjust_finish()
{
    QRect rect = hpmodehzhadjust.getRect();
    if(ui->display->define_zoom)//这里S300是正确的
    {
        if(HP_S350_or_S300)
        {
            pippara.nPIP_X = rect.left()*100/167;
            pippara.nPIP_Y = rect.top()*100/167;
            pippara.nPIP_W = rect.width()*100/167;
            pippara.nPIP_H = rect.height()*100/167;
        }else{
            pippara.nPIP_X = rect.left()*100/167;
            pippara.nPIP_Y = rect.top()*100/176;
            pippara.nPIP_W = rect.width()*100/167;
            pippara.nPIP_H = rect.height()*100/176;
        }

    }else if(isHcf)
    {
        pippara.nPIP_X = rect.left();
        pippara.nPIP_Y = rect.top() * (512.0 / 480);
        pippara.nPIP_W = rect.width();
        pippara.nPIP_H = rect.height() * (512.0 / 480);
    }else
    {
        pippara.nPIP_X = rect.left();
        pippara.nPIP_Y = rect.top();
        pippara.nPIP_W = rect.width();
        pippara.nPIP_H = rect.height();
    }
    signal_pc_image_set_pip(pippara);
}

void MainWidget::mode_rdj_adjust_finish()
{
    fusionpara = hpmoderdjadjust.getFusion();
    signal_pc_image_set_fusion(fusionpara);
}

void MainWidget::slot_wifi_eth_close(int power)
{
    if(power==1)
    {
        main_task_wifi = false;
    }else
    {
        main_task_eth = false;
    }
}

void MainWidget::slot_hpsetting_eth(bool checked)
{
    main_task_eth = checked;
    if(false == checked){
        PreviewIconLimit(S_NORMAL);        //恢复预览按钮为正常状态
    }
}

void MainWidget::slot_hpsetting_wifi(bool checked)
{
    main_task_wifi = checked;
    PreviewIconLimit(S_NORMAL);
}

void MainWidget::slot_hpsetting_ble(bool checked)
{
    main_task_ble = checked;

}

void MainWidget::slot_hpblesearch_headset(bool f)
{
    main_task_headset = f;
}

void MainWidget::slot_hphidemenu_printscreen(bool checked)
{
    printscreen_checked = checked;
    //    qDebug()<<"slot_hphidemenu_printscreen:"<<printscreen_checked;
}
void MainWidget::slot_hir_analyse_get_measure()
{
    ui->display->pointIndex = 0;
    ui->display->lineIndex = 0;
    ui->display->rectIndex = 0;
    ui->display->hp_point_list.clear();
    ui->display->hp_line_list.clear();
    ui->display->hp_rect_list.clear();
    singal_pc_cfg_get_pointconfig();
    singal_pc_cfg_get_lineconfig();
    singal_pc_cfg_get_rectconfig();
    singal_pc_cfg_get_circleconfig();
}

void MainWidget::slot_hphide_biaoding_zn(int para)
{
    if(!m_isInitBiaoding)
    {
        m_isInitBiaoding = true;
        return;
    }
    if(m_keyORelease)
    {
        m_keyORelease = false;
        hpsetting.hphide_biaoding.show();
    }
}

void MainWidget::slot_hir_analyse_clear_measure()
{
    ui->display->pointIndex = 0;
    ui->display->lineIndex = 0;
    ui->display->rectIndex = 0;
    ui->display->hp_point_list.clear();
    ui->display->hp_line_list.clear();
    ui->display->hp_rect_list.clear();
}
void MainWidget::slot_hir_analyse_point_stop(int index,bool stop)
{
    qDebug() << "((((point Index == > " << index;
    if(index < 100)
    {
        if(stop)
        {
            signal_pc_measure_get_point(index);
        }
    }
}
void MainWidget::slot_hir_analyse_line_stop(int index,bool stop)
{
    qDebug() << "((((line Index == > " << index;
    if(index < 100)
    {
        if(stop)
        {
            signal_pc_measure_get_line(index);
        }
    }
}
void MainWidget::slot_hir_analyse_rect_stop(int index,bool stop)
{
    qDebug() << "((((rect Index == > " << index;
    if(index < 100)
    {
        if(stop)
        {
            signal_pc_measure_get_rect(index);
        }
    }
}
void MainWidget::update_main_show(MAIN_SHOW main_show)
{
//    qDebug()<<"update_main_show"<<main_show;
    slot_update_lcdoff_time(false);
    if(hp_panorama->isVisible() && main_show != MAIN_POINT
            && main_show != MAIN_LINE && main_show != MAIN_RECT && main_show != MAIN_CLEAN)
    {
        slot_open_panorama(true);
        return;
    }
    ui->checkBox_polygon->close();
    if(ui->polygon->isVisible())
        ui->polygon->close();
    if(ui->circle->isVisible())
        ui->circle->close();
    if(ui->display->m_isPolygonDraw)
    {
        ui->checkBox_polygon->setChecked(false);
        on_checkBox_polygon_clicked(false);
    }
    ui->pushButton_confirm->close();
    ui->display->clear_selecte_status();
    switch(main_show)
    {
    case MAIN_POINT:
        if(ui->point->get_hp_button_status() != S_DISABLE)
        {
            ui->point->set_hp_button_status(S_SELECT);
            if(ui->line->get_hp_button_status() == S_SELECT)
            {
                ui->line->set_hp_button_status(S_NORMAL);
            }
            if(ui->rect->get_hp_button_status() == S_SELECT)
            {
                ui->rect->set_hp_button_status(S_NORMAL);
            }
        }
        break;
    case MAIN_LINE:
        qDebug() << "ui->line->get_hp_button_status()" << ui->line->get_hp_button_status();
        if(ui->line->get_hp_button_status() != S_DISABLE)
        {
            ui->line->set_hp_button_status(S_SELECT);
            if(ui->point->get_hp_button_status() == S_SELECT)
            {
                ui->point->set_hp_button_status(S_NORMAL);
            }
            if(ui->rect->get_hp_button_status() == S_SELECT)
            {
                ui->rect->set_hp_button_status(S_NORMAL);
            }
        }
        break;
    case MAIN_RECT:
        if(ui->rect->get_hp_button_status() != S_DISABLE)
        {
            ui->rect->set_hp_button_status(S_SELECT);
            if(ui->point->get_hp_button_status() == S_SELECT)
            {
                ui->point->set_hp_button_status(S_NORMAL);
            }
            if(ui->line->get_hp_button_status() == S_SELECT)
            {
                ui->line->set_hp_button_status(S_NORMAL);
            }
        }
        break;
    case MAIN_CIRCLE:
        if(ui->circle->get_hp_button_status() != S_DISABLE)
        {
            if(ui->circle->get_hp_button_status() == S_SELECT)
            {
                ui->circle->set_hp_button_status(S_NORMAL);
            }
            if(ui->circle->get_hp_button_status() == S_SELECT)
            {
                ui->circle->set_hp_button_status(S_NORMAL);
            }
        }
        break;
    case MAIN_POLYGON:
        if(ui->polygon->get_hp_button_status() != S_DISABLE)
        {
            if(ui->polygon->get_hp_button_status() == S_SELECT)
            {
                ui->polygon->set_hp_button_status(S_NORMAL);
            }
            if(ui->polygon->get_hp_button_status() == S_SELECT)
            {
                ui->polygon->set_hp_button_status(S_NORMAL);
            }
        }
        break;
    case MAIN_MODE:
        if(ui->mode->get_hp_button_status() == S_SELECT)
        {
            main_task_open = true;
            ui->point->set_hp_button_status(S_DISABLE);
            ui->line->set_hp_button_status(S_DISABLE);
            ui->rect->set_hp_button_status(S_DISABLE);

            ui->sebiao->set_hp_button_status(S_DISABLE);
            ui->resize->set_hp_button_status(S_DISABLE);

            ui->preview->set_hp_button_status(S_DISABLE);
            ui->clean->set_hp_button_status(S_DISABLE);
            ui->setting->set_hp_button_status(S_DISABLE);

            if(define_brightmode)
            {
                ui->bright_mode->set_hp_button_status(S_DISABLE);
            }
        }
        else if(ui->mode->get_hp_button_status() == S_NORMAL)
        {
            main_task_open = false;
            if(!start_record)
            {
                if(video_mode == 0)
                {
                    ui->resize->set_hp_button_status(S_NORMAL);
                }else{
                    ui->resize->set_hp_button_status(S_DISABLE);
                }
                if(video_mode != 1)
                {
                    ui->sebiao->set_hp_button_status(S_NORMAL);
                }else{
                    ui->sebiao->set_hp_button_status(S_DISABLE);
                }
                PreviewIconLimit(S_NORMAL);
                if(video_mode != 1)
                {
                    ui->point->set_hp_button_status(S_NORMAL);
                    ui->line->set_hp_button_status(S_NORMAL);
                    ui->rect->set_hp_button_status(S_NORMAL);
                    ui->clean->set_hp_button_status(S_NORMAL);
                }else{
                    ui->point->set_hp_button_status(S_DISABLE);
                    ui->line->set_hp_button_status(S_DISABLE);
                    ui->rect->set_hp_button_status(S_DISABLE);
                    ui->clean->set_hp_button_status(S_DISABLE);
                }
                ui->setting->set_hp_button_status(S_NORMAL);

                if( define_brightmode && !twice_analysis_start )
                {
                    if(define_brightmode)
                    {
                        if( video_mode == 1 )
                        {
                            ui->bright_mode->set_hp_button_status(S_DISABLE);
                        }
                        else
                        {
                            ui->bright_mode->set_hp_button_status(S_NORMAL);
                        }
                    }
                }
//                if( video_mode == 1 )
//                    ui->bright_mode->set_hp_button_status(S_DISABLE);
                if(video_mode == 4)
                {
                    ui->point->set_hp_button_status(S_NORMAL);
                    ui->line->set_hp_button_status(S_NORMAL);
                    ui->rect->set_hp_button_status(S_NORMAL);
                    if(define_brightmode)
                    {
                        if( video_mode == 1 )
                        {
                            ui->bright_mode->set_hp_button_status(S_DISABLE);
                        }
                        else
                        {
                            ui->bright_mode->set_hp_button_status(S_NORMAL);
                        }
                    }
                    ui->clean->set_hp_button_status(S_NORMAL);
                }
                if( (video_mode == 4) && fidpid)
                {
                    ui->point->set_hp_button_status(S_DISABLE);
                    ui->line->set_hp_button_status(S_DISABLE);
                    ui->rect->set_hp_button_status(S_DISABLE);
                    ui->clean->set_hp_button_status(S_DISABLE);
                }
            }
        }
        break;
    case MAIN_SEBIAO:
        if(ui->sebiao->get_hp_button_status() == S_SELECT)
        {
            main_task_open = true;
            ui->point->set_hp_button_status(S_DISABLE);
            ui->line->set_hp_button_status(S_DISABLE);
            ui->rect->set_hp_button_status(S_DISABLE);
            ui->mode->set_hp_button_status(S_DISABLE);
            ui->resize->set_hp_button_status(S_DISABLE);

//            if(start_record == true || isUSBPreviewLimit || main_task_usb)
//            {
//                preview_tmp_s = S_NORMAL;
//            }else
//            {
//                preview_tmp_s = ui->preview->get_hp_button_status();
//            }
            ui->preview->set_hp_button_status(S_DISABLE);
            ui->clean->set_hp_button_status(S_DISABLE);
            ui->setting->set_hp_button_status(S_DISABLE);
            if(define_brightmode)
            {
                ui->bright_mode->set_hp_button_status(S_DISABLE);
            }
        }
        else if(ui->sebiao->get_hp_button_status() == S_NORMAL)
        {
            main_task_open = false;
            if(video_mode == 0)
            {
                ui->resize->set_hp_button_status(S_NORMAL);
            }
            if(qrcode == true || hpsetting.guowangFlag)
            {
                ui->mode->set_hp_button_status(S_DISABLE);
            }else{
                if(!hir_analyse)
                {
                    ui->mode->set_hp_button_status(S_NORMAL);
                }
            }

            if(!start_record)
            {
                PreviewIconLimit(S_NORMAL);
                ui->clean->set_hp_button_status(S_NORMAL);
                ui->setting->set_hp_button_status(S_NORMAL);
                ui->point->set_hp_button_status(S_NORMAL);
                ui->line->set_hp_button_status(S_NORMAL);
                ui->rect->set_hp_button_status(S_NORMAL);
                if( define_brightmode && !twice_analysis_start )
                {
                    if(define_brightmode)
                    {
                        if( video_mode == 1 )
                        {
                            ui->bright_mode->set_hp_button_status(S_DISABLE);
                        }
                        else
                        {
                            if(!hir_analyse)
                            {
                                ui->bright_mode->set_hp_button_status(S_NORMAL);
                            }
                        }
                    }
                }

           //     else
           //         ui->bright_mode->set_hp_button_status(S_NORMAL);
                if(video_mode == 4)
                {
                    ui->point->set_hp_button_status(S_NORMAL);
                    ui->line->set_hp_button_status(S_NORMAL);
                    ui->rect->set_hp_button_status(S_NORMAL);
                    if(define_brightmode)
                    {
                        if( video_mode == 1 )
                        {
                            ui->bright_mode->set_hp_button_status(S_DISABLE);
                        }
                        else
                        {
                            ui->bright_mode->set_hp_button_status(S_NORMAL);
                        }
                    }
                    ui->clean->set_hp_button_status(S_NORMAL);
                }
                if( (video_mode == 4) && fidpid)
                {
                    ui->point->set_hp_button_status(S_DISABLE);
                    ui->line->set_hp_button_status(S_DISABLE);
                    ui->rect->set_hp_button_status(S_DISABLE);
                    ui->clean->set_hp_button_status(S_DISABLE);
                }
            }
        }
        break;
    case MAIN_RESIZE:
        qDebug() << "MainWidget :: MAIN_RESIZE";
        if(ui->resize->get_hp_button_status() == S_SELECT)
        {
            ui->point->set_hp_button_status(S_DISABLE);
            ui->line->set_hp_button_status(S_DISABLE);
            ui->rect->set_hp_button_status(S_DISABLE);
            ui->mode->set_hp_button_status(S_DISABLE);
            ui->sebiao->set_hp_button_status(S_DISABLE);

//            if(start_record == true || isUSBPreviewLimit || main_task_usb)
//            {
//                preview_tmp_s = S_NORMAL;
//            }else
//            {
//                preview_tmp_s = ui->preview->get_hp_button_status();
//            }
            ui->preview->set_hp_button_status(S_DISABLE);
            ui->clean->set_hp_button_status(S_DISABLE);
            ui->setting->set_hp_button_status(S_DISABLE);
            if(define_brightmode)
            {
                ui->bright_mode->set_hp_button_status(S_DISABLE);
            }
        }
        else if(ui->resize->get_hp_button_status() == S_NORMAL)
        {
            if(qrcode == true || hpsetting.guowangFlag)
            {
                ui->mode->set_hp_button_status(S_DISABLE);
            }else{
                if(!hir_analyse)
                {
                    ui->mode->set_hp_button_status(S_NORMAL);
                }
            }
            ui->sebiao->set_hp_button_status(S_NORMAL);

            if(!start_record)
            {
                ui->point->set_hp_button_status(S_NORMAL);
                ui->line->set_hp_button_status(S_NORMAL);
                ui->rect->set_hp_button_status(S_NORMAL);

                PreviewIconLimit(S_NORMAL);
                ui->clean->set_hp_button_status(S_NORMAL);
                ui->setting->set_hp_button_status(S_NORMAL);
                if( define_brightmode && !twice_analysis_start )
                {
                    if(define_brightmode)
                    {
                        if( video_mode == 1 )
                        {
                            ui->bright_mode->set_hp_button_status(S_DISABLE);
                        }
                        else
                        {
                            if(!hir_analyse)
                            {
                                ui->bright_mode->set_hp_button_status(S_NORMAL);
                            }
                        }
                    }
                }
            }
        }
        break;
    case MAIN_PREVIEW:
    case MAIN_BRIGHT_MODE:
    case MAIN_CLEAN:
    case MAIN_SETTING:
    default:

        if(ui->point->get_hp_button_status() == S_SELECT)
        {
            ui->point->set_hp_button_status(S_NORMAL);
        }
        if(ui->line->get_hp_button_status() == S_SELECT)
        {
            ui->line->set_hp_button_status(S_NORMAL);
        }
        if(ui->rect->get_hp_button_status() == S_SELECT)
        {
            ui->rect->set_hp_button_status(S_NORMAL);
        }
        break;

    }

    if(m_isAimTemp)
    {
        ui->point->set_hp_button_status(S_DISABLE);
        ui->line->set_hp_button_status(S_DISABLE);
        ui->rect->set_hp_button_status(S_DISABLE);
        ui->clean->set_hp_button_status(S_DISABLE);
        if( ui->toolButton_AM->isVisible() )
        {
            qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
            ui->toolButton_AM->hide();
        }
        if( auto_manual_flag && ui->toolButton_max->isVisible() && ui->toolButton_min->isVisible() )
        {
            ui->toolButton_max->hide();
            ui->toolButton_min->hide();
        }
        return;
    }

}
void MainWidget::slot_StartAutoUpload_once(bool isTask)
{
    file_list.clear();
    autoupload_num = 0;
    autoupload_para = hpcameracap->StartAutoUpload_once();
    file_list = hppreview->StartAutoUpload_once(isTask);
//    for(int i = 0; i < file_list.size();i++)
//    {
//        qDebug() << file_list.at(i).fileName();//能读取到所有有相同尾字符的文件
//    }
    if(file_list.size() <= 0)
    {
        hpsetting.hp_autoupload_dialog->setFrame3Text(fNoTaskpic);
        hpsetting.hp_autoupload_dialog->upload_break();
        file_list.clear();
        autoupload_num = 0;
        return;
    }
    autoupload_once = true;
    hpcameracap->autoUpdateonce = true;
    hpsetting.autoupdate_once(1,file_list.size(),hpcameracap->IsInAutoUpload);
    slot_OnAutoUpload_once();

}
void MainWidget::slot_OnAutoUpload_once()
{
    QFileInfo fileInfo = file_list.at(autoupload_num);
    QString filename = fileInfo.filePath();
    if(upload_mode == enum_AUP_ftp)
    {
        strcpy(autoupload_para.FileName,filename.toLocal8Bit().data());
        signal_pc_cmd_set_pc_pic(autoupload_para);
        AutoUpdateGetStatus->start();
    }else if(upload_mode == enum_AUP_SERVER || upload_mode == enum_AUP_SERVER_PLUS)
    {
        QByteArray barray = filename.toUtf8();
        char *mm = barray.data();
        signal_pc_cmd_set_pc_pic_srv(mm);
    }
}


void MainWidget::slot_cameracap_panorama_errmsg(unsigned char return_value)
{
//    qDebug() << __func__ << __LINE__;
//    signal_core_key_panorama_cap(0);
}

void MainWidget::slot_pc_cmd_set_pc_pic(unsigned char return_value)
{
    return_value = (char)return_value;
    if(upload_mode == enum_AUP_ftp)
    {
        qDebug("MainWidget::slot_pc_cmd_set_pc_pic return_value:0x%02x",return_value);
    }else if(upload_mode == enum_AUP_SERVER || upload_mode == enum_AUP_SERVER_PLUS)
    {
        qDebug("MainWidget::slot_pc_cmd_set_pc_pic_srv return_value:0x%02x",return_value);
    }
    if(AutoUpdateGetStatus->isActive())
        AutoUpdateGetStatus->stop();
    if(autoupload_once == false)//判断是否处于一键上传
    {
        return;
    }
    if(return_value == RE_OK)
    {
        hpsetting.autoupdate_once(autoupload_num + 1,file_list.size(),file_list[autoupload_num].fileName().mid(0,20) + "..." + hpcameracap->UploadOK);
    }else
    {
        hpsetting.autoupdate_once(autoupload_num + 1,file_list.size(),file_list[autoupload_num].fileName().mid(0,20) + "..." + hpcameracap->UploadWrong);
        if(upload_mode == enum_AUP_SERVER || upload_mode == enum_AUP_SERVER_PLUS)//若是srv模式，则直接停止上传
        {
            qDebug() << "Set == > hpcameracap->autoUpdateonce == false";
            delaymsec(1000);
            hpsetting.hp_autoupload_dialog->close();
            hpcameracap->autoUpdateonce = false;
            autoupload_once = false;
            file_list.clear();
            autoupload_num = 0;

            if(upload_mode == enum_AUP_SERVER)//只有在这个模式下才断开连接
            {
                hpsetting.slot_srvupload_failed();
                delaymsec(1000);
                slot_SetMainCameraCapDialog(hpcameracap->fReconnect,0);
            }
            return;
        }
    }
    autoupload_num++;
//    qDebug() << autoupload_num << " / " << file_list.size();
    if(autoupload_num < file_list.size())
    {
        slot_OnAutoUpload_once();
    }else{
        qDebug() << "Set == > hpcameracap->autoUpdateonce == false";
        hpsetting.hp_autoupload_dialog->close();
        hpcameracap->autoUpdateonce = false;
        autoupload_once = false;
        file_list.clear();
        autoupload_num = 0;
    }
}
void MainWidget::slot_task_start()
{
    qDebug() << "      ---TaiZhang--- Start";   //1.当开始运行台账界面时触发
    //Task_win = 1;                               //2.设置标志位
    ui->display->hp_list_save();                //3.保存链表
    ui->display->sltStartTask();                //4.设置标志位
    hpcameracap->Taskmode = true;               //5.设置标志位
                                                //6.清除界面(好像不需要)
                                                //7.设置主界面控件状态，这里就不设置了，看看效果再设置
    ui->display->hpplredit->setTaskstyleSheet(true);
    Hp_TaskPkg::getInstance()->Open_Dlg();      //8.启动任务栏界面
}
/* 8. 信号 通知作业包已关闭 */
void MainWidget::slot_CloseDlg()
{
    if(!m_pmsWidgetOpenFlag)
    {
        hpcameracap->isSuperImage = hpcameracap->isSuperImage;;//使台账GW优先
    }
    qDebug() << "      ---TaiZhang--- 8.slot_CloseDlg == > " << hpcameracap->pms_filename.isEmpty(); //1.当设备树关闭时触发
    if(hpcameracap->pms_filename.isEmpty())
    {
        ui->display->clear_selecte_status();                //2.清除选中
        ui->display->hp_list_restore();                     //3.清除界面、重置链表
        ui->display->sltStopTask();                         //4.设置标志位
        hpsetting.slot_close_task();                        //5.重新设置设置界面作业控件状态
        hpcameracap->slot_HideTaskText();                   //6.关闭文本窗口
    //    Hp_TaskPkg::getInstance()->Close_Dlg();              //7.关闭树状图界面
        hpcameracap->Taskmode = false;                      //8.清除标志位
        ui->display->hpplredit->setTaskstyleSheet(false);
        hpcameracap->m_isPms = false;
        hp_Pms->close();
        hpcameracap->setIsPmsMode(false);

        Task_win = 0;
    }
}
/* 9. 信号 通知轮廓文件及分析底线框 */
void MainWidget::slot_ChangeAnaInfo(QString bmp, QVector<ANA_OUTLINE> ana_infos)
{
    qDebug() << "      ---TaiZhang--- 9.slot_ChangeAnaInfo " << "bmp == " << bmp;//1.当设备树有新的选中时触发
    ui->display->sltImageChange(bmp);                   //2.重新绘图
    ui->display->UpdateTaskRect(ana_infos);             //3.更新图像
}
/* 10. 信号 显示作业包选择界面 */
void MainWidget::slot_Show_TaskSelect()
{
    slot_update_lcdoff_time(true);
    qDebug() << "      ---TaiZhang--- 10.slot_Show_TaskSelect";//当打开任务界面时触发
    ui->display->Task_clear_measure();                  //清除画面
    Task_win = 1;
}

QString MainWidget::all_replace_delete_Tab(QString str)//删除tab
{
    char a = 0x09;
    str.replace(a,"    ");
    return str;
}

void MainWidget::slot_should_make_pms_json(QString real_file)
{
//    if(!m_pmsUploadFlag)
//    {
//        hp_Pms->hp_setListWidgetIndex(hp_Pms->hp_getNowIndex());
//        return;
//    }
    qDebug() << __func__ << __LINE__;
    QString fileCreateTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
    QString currClearance, currPointName;
    QString currClearanceSn, currPointSn;
    QFile file("/run/media/mmcblk2p1/DCIM/" + real_file);
    qDebug() << __func__ << __LINE__;
    if (!file.open(QIODevice::ReadWrite)) {
        qCritical() << "Failed to open file:" << file.errorString();
    }
    else
    {
        qDebug() << __func__ << __LINE__;
        pms_ir_atlas_t atlas;
        qint64 read_size = file.read(reinterpret_cast<char*>(&atlas), sizeof(pms_ir_atlas_t));

        if (read_size != sizeof(pms_ir_atlas_t)) {
            qCritical() << "Incomplete data read (expected"
                       << sizeof(pms_ir_atlas_t) << "bytes, got" << read_size << ")";
        }
        else
        {
            hp_Pms->hp_getCurrClearancePointName(currClearance, currPointName);
            hp_Pms->hp_getCurrClearanceSn(currClearanceSn, currPointSn);
            MainTask currMainTask = hp_Pms->hp_getMainTask();

            QString newDeviceName = currClearance;
            QString newDeviceCode = currClearanceSn;
            QString newTestPointName = currPointName;// ASCII
            QString newTestPointCode = currPointSn;  // ASCII

            memset(atlas.device_name, 0x00, 118);  // 先全部置零
            const ushort* utf16DataDeviceName = newDeviceName.utf16();
            int byteLength = newDeviceName.length() * 2;

            memcpy(atlas.device_name, utf16DataDeviceName, byteLength);
            if (byteLength < 118) {
                memset(atlas.device_name + byteLength, 0, 118 - byteLength);
            }

            memset(atlas.test_point_name, 0x00, 128);  // 先全部置零
            const ushort* utf16Data = newTestPointName.utf16();
            byteLength = newTestPointName.length() * 2;

            memcpy(atlas.test_point_name, utf16Data, byteLength);
            if (byteLength < 128) {
                memset(atlas.test_point_name + byteLength, 0, 128 - byteLength);
            }

            memset(atlas.device_code, 0x00, 42);  // 先全部置零
            std::string cNewDeviceCode = newDeviceCode.toLocal8Bit().toStdString();
            const char* cDeviceCode = cNewDeviceCode.c_str();  // 需要时获取C风格字符串
            std::copy(cDeviceCode, cDeviceCode + std::min(strlen(cDeviceCode)+1,
                      sizeof(atlas.device_code)), atlas.device_code);

            memset(atlas.test_point_code, 0x00, 32);  // 先全部置零
            std::string cNewTestPointCode = newTestPointCode.toLocal8Bit().toStdString();
            const char* cTestPointCode = cNewTestPointCode.c_str();  // 需要时获取C风格字符串
            std::copy(cTestPointCode, cTestPointCode + std::min(strlen(cTestPointCode)+1,
                      sizeof(atlas.test_point_code)), atlas.test_point_code);

            atlas.ir_atlas_capture_time = fileCreateTime.toLongLong();
            file.seek(0);
            file.write(reinterpret_cast<char*>(&atlas), sizeof(pms_ir_atlas_t));
            file.flush();  // 强制立即写入磁盘
        }
        file.close();  // 关闭文件释放锁
    }
    qDebug() << __func__ << __LINE__;
//    hp_createPdf->set_taisu_pdf_create_report("/run/media/mmcblk2p1/DCIM/" + real_file);
    QString fileNoEnd = hpcameracap->pms_xml;
    fileNoEnd.chop(fileNoEnd.length() - fileNoEnd.lastIndexOf("."));//去掉后几位
    QString pmspath = "/run/media/mmcblk2p1/" + fileNoEnd;//下发任务包的路径
    qDebug() << __func__ << __LINE__;
    QDir dirjson(pmspath);
    if(!dirjson.exists())//若不存在台账目录则创建
    {
        system(QString("mkdir " + pmspath).toUtf8().data());
        system("sync");
    }
    QString cmd = QString("mv /run/media/mmcblk2p1/DCIM/" + real_file + " " + pmspath + "/" + fileCreateTime + ".dat");

    qDebug() << __func__ << __LINE__;
    system(cmd.toUtf8().data());//拷贝文件
    system("sync");
//    QString cmd2 = QString("cp hp_pdf.pdf " + pmspath + "/" + fileCreateTime + ".pdf");
//    system(cmd2.toUtf8().data());
//    system("sync");
    qDebug() << __func__ << __LINE__;
    QString pmsDatPath = pmspath + "/" + fileCreateTime + ".dat";//新dat文件路径
    QString newTestPointId = hp_Pms->hp_getCurrTestpointId();
    modifyXmlFilename("pms_task.xml", pmsDatPath, newTestPointId);
    QString testPointID, clearanceID;
    hp_Pms->hp_getCurrClearancePointId(clearanceID, testPointID);
    qDebug() << __func__ << __LINE__ << "testPointID" << testPointID << "clearanceID" << clearanceID;
    if(hpcameracap->isErrPmsPhoto)
        m_errClearancePointFilenameMap[clearanceID][testPointID].append(pmsDatPath);
    else
        m_clearancePointFilenameMap[clearanceID][testPointID].append(pmsDatPath);
    qDebug() << __func__ << __LINE__ << "testPointID" << testPointID << "clearanceID" << clearanceID;
    QString equipType = hpsetting.ui->label_xinghao_text->text();
    QString equipSn = hpsetting.ui->label_bianhao_text->text();
    hp_Pms->hp_setListWidgetIndex(hp_Pms->hp_getNowIndex());
}

void MainWidget::modifyXmlFilename(const QString& filePath, const QString& newFilename, QString newTestPointId)
{
    // 1. 打开并解析XML文件
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "open file fail:" << filePath;
        return;
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        qWarning() << "xml read fail:" << filePath;
        file.close();
        return;
    }
    file.close();

    // 2. 查找并修改所有 <test_point> 的 filename 属性
    QDomElement root = doc.documentElement();
    QDomNodeList testPoints = root.elementsByTagName("test_point");
    qDebug() << "newTestPointId" << newTestPointId;
    for (int i = 0; i < testPoints.size(); ++i) {
        QDomElement testPoint = testPoints.at(i).toElement();
        qDebug() << "testPoint.attribute(id)" << testPoint.attribute("id");
        if (!testPoint.isNull() && testPoint.attribute("id") == newTestPointId) {
            if(!hpcameracap->isErrPmsPhoto)
            {
                QString xmlTestPointFileName = testPoint.attribute("filename");
                QString newDatFileNAme = newFilename.split("/").last().split(".").at(0) + ".dat";
                qDebug() << "newDatFileNAme" << newDatFileNAme;
                if(xmlTestPointFileName.count() > 5)
                {
                    newDatFileNAme = xmlTestPointFileName + ";" + newDatFileNAme;
                }
                testPoint.setAttribute("filename", newDatFileNAme);
                break;
            }
            else
            {
                QString xmlTestPointFileName = testPoint.attribute("bgfilename");

                QString xmlNormalTestPointFileName = testPoint.attribute("filename");
                QString newDatFileNAme = newFilename.split("/").last().split(".").at(0) + ".dat";
                qDebug() << "newDatFileNAme" << newDatFileNAme;
                if(xmlTestPointFileName.count() > 5)
                {
                    newDatFileNAme = xmlTestPointFileName + ";" + newDatFileNAme;
                }
                if(xmlNormalTestPointFileName.count() < 5)
                {
                    testPoint.setAttribute("filename", "");
                }
                testPoint.setAttribute("bgfilename", newDatFileNAme);
                break;
            }
        }
    }

    // 3. 重新写入文件
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qWarning() << "无法写入文件:" << filePath;
        return;
    }

    QTextStream stream(&file);
    stream << doc.toString(4);  // 缩进4个空格
    file.close();

    qDebug() << "xml modify success" << filePath;
    return;
}

void MainWidget::removeTestPointByFilename(QDomElement &parent, const QString &targetFilename)
{
    QDomNodeList clearances = parent.elementsByTagName("clearance");
    for (int i = clearances.count() - 1; i >= 0; --i) {
        QDomElement clearance = clearances.at(i).toElement();

        QDomNodeList testPoints = clearance.elementsByTagName("test_point");

        for (int j = testPoints.count() - 1; j >= 0; --j) {
            QDomElement testPoint = testPoints.at(j).toElement();
//            qDebug() << __func__ << "testPoint.attribute(\"filename\") " << testPoint.attribute("filename") << targetFilename;
            if (testPoint.attribute("filename") == targetFilename) {
//                qDebug() << "testPoint.attribute(\"filename\") == targetFilename" << targetFilename;
                testPoint.setAttribute("filename", "");
//                clearance.removeChild(testPoints.at(j));
            }
        }
    }
}

int MainWidget::removeEmptyClearance(QDomElement &parent) {
    QDomNodeList clearances = parent.elementsByTagName("clearance");
    int clearanceCount = clearances.count();
    for (int i = clearances.count() - 1; i >= 0; --i) {
        QDomElement clearance = clearances.at(i).toElement();
        if (clearance.elementsByTagName("test_point").count() == 0) {
//            parent.removeChild(clearances.at(i));
//            clearanceCount--;
        }
    }
    return clearanceCount;
}

void MainWidget::slot_upload_pms_dat()
{
    if(m_pmsUploadFlag)
    {
//        hp_Pms->hp_createModifiedXml("uploadPms.xml");
        system("cp pms_task.xml uploadPms.xml");
        system("sync");
        delaymsec(10);
        //打开上传的xml
        int fileTypeFlag = 0;//用于标志是否需要进行压缩，大于1则需要
        QFile file("uploadPms.xml");
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            qDebug() << "open uploadPms.xml file fail";
            return;
        }
        QDomDocument doc;
        if (!doc.setContent(&file)) {
            qDebug() << "XML phase fail";
            file.close();
            return;
        }

        QDomElement root = doc.documentElement();
        QDomElement mainTask = root.firstChildElement("main_task");
        QDomElement subTask = mainTask.firstChildElement("sub_task");
        //我的mainTask是顺序的，那么只需要根据选中表来进行确认上传就可
        MainTask currMainTask = hp_Pms->hp_getMainTask();
        QMap<int, bool> itemIndexSelectMap = hp_Pms->hp_getCurrSelectMap();
        int currClearanceCount = currMainTask.subTasks.at(0).clearances.count();
        int currIndex = 3;
        QStringList removeNameList;
        QStringList uploadFileList;
//        qDebug() << "m_clearancePointFilenameMap" << m_clearancePointFilenameMap;
        for(int i = 0; i < currClearanceCount; i++)
        {
            int currTestPointCount = currMainTask.subTasks.at(0).clearances.at(i).testPoints.count();
            QString currClearanceName = currMainTask.subTasks.at(0).clearances.at(i).name;
            QString currClearanceID = currMainTask.subTasks.at(0).clearances.at(i).id;
            for(int j = 0; j < currTestPointCount; j++)
            {
                QString currTestPointName = currMainTask.subTasks.at(0).clearances.at(i).testPoints.at(j).name;
                QString currTestPointId = currMainTask.subTasks.at(0).clearances.at(i).testPoints.at(j).id;
                int currTestPointFileCount = m_clearancePointFilenameMap[currClearanceID][currTestPointId].count();
                int currErrTestPointFileCount = m_errClearancePointFilenameMap[currClearanceID][currTestPointId].count();
                if(!itemIndexSelectMap.value(currIndex))
                {
                    if(currTestPointFileCount == 0)
                    {
                        removeNameList.append(QString::number(j));
                    }
                    else
                    {
                        for(int k = 0; k < currTestPointFileCount; k++)
                        {
                            QString fileNameRemove = m_clearancePointFilenameMap[currClearanceID][currTestPointId].at(k);
//                            qDebug() << "fileNameRemove" << fileNameRemove;
                            removeNameList.append(fileNameRemove);
    //                        modifyXmlFilename("uploadPms.xml", fileNameRemove, currTestPointId);
                        }
                        for(int k = 0; k < currErrTestPointFileCount; k++)
                        {
                            QString fileNameRemove = m_errClearancePointFilenameMap[currClearanceID][currTestPointId].at(k);
                            removeNameList.append(fileNameRemove);
                        }
                    }
                }
                else
                {
                    for(int k = 0; k < currTestPointFileCount; k++)
                    {
                        QString fileNameUpload = m_clearancePointFilenameMap[currClearanceID][currTestPointId].at(k);
//                        qDebug() << "fileNameUpload" << fileNameUpload;
                        uploadFileList.append(fileNameUpload);
//                        modifyXmlFilename("uploadPms.xml", fileNameUpload, currTestPointId);
                    }
                    for(int k = 0; k < currErrTestPointFileCount; k++)
                    {
                        QString fileNameUpload = m_errClearancePointFilenameMap[currClearanceID][currTestPointId].at(k);
//                        qDebug() << "fileNameUpload" << fileNameUpload;
                        uploadFileList.append(fileNameUpload);
//                        modifyXmlFilename("uploadPms.xml", fileNameUpload, currTestPointId);
                    }
                }
                currIndex++;
            }
            currIndex++;
        }



        if(uploadFileList.count() > 1)
        {
            fileTypeFlag = 1;
        }

        for(int i = 0; i < removeNameList.count(); i++)
        {
            QString targetFilename = removeNameList.at(i);
            removeTestPointByFilename(subTask, targetFilename);
            removeEmptyClearance(subTask);
        }

        QDomElement fileCount = mainTask.firstChildElement("file_count");
        QDomElement fileType = mainTask.firstChildElement("file_type");
        if (!fileCount.isNull()) {
            fileCount.firstChild().setNodeValue(QString::number(uploadFileList.count()));  // 更新 file_count
        } else {
            qDebug() << "not found  <file_count> ";
        }
        if (!fileType.isNull()) {
            fileType.firstChild().setNodeValue(QString::number(fileTypeFlag));  // 更新 file_type
        } else {
            qDebug() << "not found <file_type>";
        }
        qDebug() << __func__ << __LINE__;
        // 保存修改后的 XML
        file.resize(0);  // 清空原文件
        QTextStream out(&file);
        doc.save(out, 4);  // 缩进 4 空格

        qDebug() << __func__ << __LINE__;
        QString fileNoEnd = hpcameracap->pms_xml;
        fileNoEnd.chop(fileNoEnd.length() - fileNoEnd.lastIndexOf("."));//去掉后几位
        QString pmspath = "/run/media/mmcblk2p1/" + fileNoEnd;//台账目录
        QString xmlFiePath = pmspath + "/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz") + ".xml";
        QString cmd = QString("cp uploadPms.xml " + xmlFiePath);
        system(cmd.toUtf8().data());
        system("sync");
        //打包zip与上传

        qDebug() << __func__ << __LINE__ << "uploadFileList" << uploadFileList;
//        Hp_ProgressDialog->show();
        hp_Wifi_search_Dialog->move((ui->display->width() - hp_Wifi_search_Dialog->width()) / 2 + ui->frame->width(),(ui->display->height() - hp_Wifi_search_Dialog->height()) / 2);

        hp_Wifi_search_Dialog->Set_label_text(hpcameracap->IsInAutoUpload);
        hp_Wifi_search_Dialog->SetHideButton(true);
        hp_Wifi_search_Dialog->setDelayClose(1000);
        hp_Wifi_search_Dialog->show();
        delaymsec(50);
        if(uploadFileList.count() == 0)
            return;
        hpsetting.m_Transmission->hp_upload_xml_dat(uploadFileList, pmspath, xmlFiePath, fileTypeFlag);
//
    }
}

void MainWidget::slot_pms_key_release(QKeyEvent *ev)
{
    qDebug() << "MainWidget::slot_pms_key_release" << ev->key();
    keyReleaseEvent(ev);
}

void MainWidget::slot_pms_select_changed(int index)
{
    qDebug() << "MainWidget::slot_pms_select_changed index == > " << index;
    //设置文件名
    if(index < hp_Pms->hp_getTitleIndex())
    {
        hpcameracap->pms_filename.clear();
    }else{

        MainTask currMainTask = hp_Pms->hp_getMainTask();
        QString sub_task_name_ret = currMainTask.subTasks.at(0).name;
        sub_task_name_ret = all_replace_covert_char(sub_task_name_ret);

        QString clearance_name_ret = currMainTask.subTasks.at(0).clearances.at(0).name;
        clearance_name_ret = all_replace_covert_char(clearance_name_ret);

        QString test_point_name_ret = currMainTask.subTasks.at(0).clearances.at(0).testPoints.at(0).name;
        test_point_name_ret = all_replace_covert_char(test_point_name_ret);

        QString test_point_id_ret = currMainTask.subTasks.at(0).clearances.at(0).testPoints.at(0).id;
        test_point_id_ret = all_replace_covert_char(test_point_id_ret);

        hpcameracap->pms_filename = sub_task_name_ret + "-" + clearance_name_ret + "-" + test_point_name_ret + "--" + test_point_id_ret;
        qDebug() << "MainWidget::slot_pms_select_changed == > " << hpcameracap->pms_filename;
    }
}

QString MainWidget::all_replace_covert_char(QString s_text)
{
    //QString s_text = str;

    //s_text.replace( "-", "__0" );
    s_text.replace( "~", "__1" );
    s_text.replace( "`", "__2" );
    s_text.replace( "!", "__3" );
    s_text.replace( "@", "__4" );
    s_text.replace( "#", "__5" );
    s_text.replace( "$", "__6" );
    s_text.replace( "%", "__7" );
    s_text.replace( "^", "__8" );
    s_text.replace( "&", "__9" );
    s_text.replace( "*", "__a" );
    s_text.replace( "(", "__b" );
    s_text.replace( ")", "__c" );
    s_text.replace( "+", "__d" );
    s_text.replace( "=", "__e" );
    s_text.replace( "{", "__f" );
    s_text.replace( "}", "__g" );
    s_text.replace( "[", "__h" );
    s_text.replace( "]", "__i" );
    s_text.replace( "|", "__j" );
    s_text.replace( "\\", "__k" );
    s_text.replace( ":", "__l" );
    s_text.replace( ";", "__m" );
    s_text.replace( "\"", "__n" );
    s_text.replace( "\'", "__o" );
    s_text.replace( "<", "__p" );
    s_text.replace( ">", "__q" );
    s_text.replace( ",", "__r" );
    s_text.replace( ".", "__s" );
    s_text.replace( "?", "__t" );
    s_text.replace( "/", "__u" );
    s_text.replace( " ", "__v" );
    s_text.replace( "__w", "\t" );

    return s_text;
}

void MainWidget::slot_get_select_xml(QString str)
{
    hpcameracap->pms_xml = str;
    if(!hpcameracap->pms_xml.isEmpty())
    {
        slot_Show_TreeView();//打开树状图界面
        hpcameracap->m_isPms = true;
        m_pmsWidgetOpenFlag = true;
        m_clearancePointFilenameMap.clear();
        hp_Pms->hp_clearListWidget();
        hp_Pms->hp_parseTask("/run/media/mmcblk2p1/" + str);
        hp_Pms->hp_createModifiedXml("pms_task.xml");
        hp_Pms->show();
        hpcameracap->setIsPmsMode(true);
        hp_Pms->setFocus();
        if(hpsetting.ui->checkBox_transmission->isChecked())
        {
            m_pmsUploadFlag = true;
        }
    }else{//若未选中，则清空相关内容
        hpcameracap->pms_filename.clear();
        hpcameracap->pms_xml.clear();
        hpcameracap->m_isPms = false;
        m_pmsWidgetOpenFlag = false;
        hp_Pms->close();
        hpcameracap->setIsPmsMode(false);
    }
}
void MainWidget::slot_close_pms()
{

    qDebug() << "      ---PMS--- slot_close_pms";//当显示设备树时触发
    hpcameracap->pms_filename.clear();
    hpcameracap->pms_xml.clear();
    hpcameracap->m_isPms = false;
    m_pmsWidgetOpenFlag = false;
    slot_CloseDlg();
}
void MainWidget::slot_take_picture()
{
    qDebug() << __func__ << __LINE__;
    QKeyEvent* ev = new QKeyEvent(QEvent::KeyRelease, KEY_CAMERA_PICTURE, Qt::NoModifier, QString(), false, 1);
    slot_event_start_get_capture();
//    keyReleaseEvent(ev);
}

void MainWidget::slot_open_mode()
{
//    QKeyEvent* ev = new QKeyEvent(QEvent::KeyRelease, KEY_MODE, Qt::NoModifier, QString(), false, 1);
//    keyReleaseEvent(ev);
}
/* 11. 信号 显示设备拍摄界面 */
void MainWidget::slot_Show_TreeView()
{
    qDebug() << "      ---TaiZhang--- 11.slot_Show_TreeView == > " << StrOutsisToTask;//当显示设备树时触发
    Task_win = 2;

    if(OutsisToTask)
    {
        OutsisToTask = false;
        //武船站;-220kV;-1
        Hp_TaskPkg::getInstance()->Dump_to_index_by_name(StrOutsisToTask);
    }
}
/* 12. 信号 显示拍摄恢复提示界面 */
void MainWidget::slot_Show_MessageBox()
{
    qDebug() << "      ---TaiZhang--- 12.slot_Show_MessageBox";//当 “恢复上次拍摄设备” 弹窗出现时触发
    Task_win = 3;
}
/* 13. 信号 显示SD卡提示界面 */
void MainWidget::slot_Show_MessageDialog()
{
    qDebug() << "      ---TaiZhang--- 13.slot_Show_MessageDialog";
    Task_win = 4;
}
void MainWidget::slot_Show_AnalysisChart()
{
    qDebug() << "      ---TaiZhang--- 14.slot_Show_AnalysisChart";
    Task_win = 5;
}
void MainWidget::keyPressEvent(QKeyEvent *ev)
{
    qDebug("mainwidget ========================================================key press 0x%02x",ev->key());
    if(appcon_state == true)
    {
        qDebug()<<"app connect";
        return ;
    }
       switch(ev->key())
       {
       case KEY_CAMERA_VIDEO:                  //按键用来 视频 0x56     V键和长按拍照键
           if(ui->preview->get_hp_button_status() == S_SELECT)
               break;
           qDebug() << "MainWidget::keyReleaseEvent hpsetting.isTaskMode" << hpsetting.isTaskMode;
           if(hpsetting.isTaskMode)
           {
               break;
           }
           if(hpsetting.guowangFlag)
           {
               hssw->warning("提示","国网模式不支持视频拍摄");
               hssw->setDelayClose(3000);
               hssw->show();
               break;
           }

           if(start_record)
           {
               m_hirRecordStarted = false;
               if(autoSaveShowTimer != -1)
               {
                   isAutoSave = true;
                   PreviewIconLimit(S_DISABLE);
               }
               if (1 == avi_hir_mode)
               {
                   avi_record_get_SDInfo->stop();
                   hpcameravideo.timer_stop();
                   signal_core_key_record_avi_stop();
               }else if(2 == avi_hir_mode)
               {
                   avi_record_get_SDInfo->stop();
                   hpcameravideo.timer_stop();
                   signal_core_key_record_hir_stop();
               }
           }
           else
           {
               if(main_task_sd)
               {
                   isAutoSave = false;
                   if(!sd_space_enough)
                   {
                       if(avi_hir_mode==1)
                       {
                           //从这里开始，同样也会经过slot_core_key_record_avi_start槽函数
                           avi_record_get_SDInfo->start();
                           signal_core_key_record_avi_mode_start();
                       }else if(avi_hir_mode == 2)
                       {
                           avi_record_get_SDInfo->start();
                           signal_core_key_record_hir_mode_start();
                       }
                   }
                   else
                   {
                       hssw->warning(fError,fSDHasNoSpace);
                       hssw->setDelayClose(3000);
                       hssw->show();
                   }
               }
               else
               {
                   hssw->warning(fError,fNoSD);
                   hssw->setDelayClose(3000);
                   hssw->show();
               }
           }
           break;
       case KEY_LASER_LONG:
           if(consercutiveLaser && !timerConsercutiveLaser->isActive())
           {
               ui->widget_laser->show();
               timerConsercutiveLaser->start(5000);
                getLaserRangeOnce();
           }
           break;
       case 0x1000021:                                              //    键盘按下ctrl
           ctrl_ok =true;
           break;
       case 0x1000023:                                              //    键盘按下alt
           alt_ok =true;
           break;
       case 0x49:                     //  i    上   bad point
           if(hidemenu_laser && ui->widget_laser->isVisible())
           {
               if(ui->widget_laser->y() > -20)
               {
                   ui->widget_laser->move(ui->widget_laser->x(),ui->widget_laser->y() - 1);
                   qDebug() << "ui->widget_laser pos == > " << ui->widget_laser->pos();

                   int sum = ui->widget_laser->x() << 16 | ui->widget_laser->y();

                   singal_pc_sys_set_laserpos(sum);//ok 高位存x，低位存y
               }
               break;
           }
              if(true == ctrl_ok)
              {
                signal_del_badpixel_rect(1);
                break;
              };
            if(true == alt_ok)
              {
                 signal_del_badpixel_point(1);
               };
           break;
       case 0x4b:                     //  k     下
           if(hidemenu_laser && ui->widget_laser->isVisible())
           {
               if(ui->widget_laser->y() < 460)
               {
                   ui->widget_laser->move(ui->widget_laser->x(),ui->widget_laser->y() + 1);
                   qDebug() << "ui->widget_laser pos == > " << ui->widget_laser->pos();

                   int sum = ui->widget_laser->x() << 16 | ui->widget_laser->y();

                   singal_pc_sys_set_laserpos(sum);//ok 高位存x，低位存y
               }
               break;
           }
            if(true == ctrl_ok)
            {
                signal_del_badpixel_rect(2);
                break;
            };
            if(true == alt_ok)
            {
                 signal_del_badpixel_point(2);
            };
           break;
       case 0x4a:                     //  J     左
           if(hidemenu_laser && ui->widget_laser->isVisible())
           {
               if(ui->widget_laser->x() > -20)
               {
                   ui->widget_laser->move(ui->widget_laser->x() - 1,ui->widget_laser->y());
                   qDebug() << "ui->widget_laser pos == > " << ui->widget_laser->pos();


                   int sum = ui->widget_laser->x() << 16 | ui->widget_laser->y();

                   singal_pc_sys_set_laserpos(sum);//ok 高位存x，低位存y
               }
               break;
           }
          if(true == ctrl_ok)
          {
            signal_del_badpixel_rect(3);
            break;
          };
          if(true == alt_ok)
          {
             signal_del_badpixel_point(3);
          };
           break;
       case 0x4c:                     // L      右
           if(hidemenu_laser && ui->widget_laser->isVisible())
           {
               if(ui->widget_laser->x() < 620)
               {
                   ui->widget_laser->move(ui->widget_laser->x() + 1,ui->widget_laser->y());
                   qDebug() << "ui->widget_laser pos == > " << ui->widget_laser->pos();

                   int sum = ui->widget_laser->x() << 16 | ui->widget_laser->y();

                   singal_pc_sys_set_laserpos(sum);//ok 高位存x，低位存y
               }
               break;
           }
          if(true == ctrl_ok)
          {
            signal_del_badpixel_rect(4);
            break;
          };
          if(true == alt_ok)
          {
             signal_del_badpixel_point(4);
          };
           break;
       case KEY_AUTORECTIFY_LONG:
           if(hta->isVisible() || define_sis || !hpsetting.ui->checkBox_autoReg->isChecked())
               break;
           qDebug() << __func__ << "hpsetting.getLensCount()" << hpsetting.getLensCount();
           if(hpsetting.getLensCount() < 2)
               break;
           show_lens_info();
           ui->listWidget_jingtou->show();
           timer_jingtou->start(1700);
           break;
       default:
           break;
       }
}
void MainWidget::slot_pc_sys_set_laserpos(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_laserpos:return_value:0x%02x",return_value);
}

void MainWidget::slot_timeout_pc_key_auto_focus()
{
    qDebug() << "MainWidget::slot_timeout_pc_key_auto_focus";
    signal_pc_key_auto_focus();
}

void MainWidget::slot_timeout_close_laserRange()
{
    ui->label_laserRange->close();
}

void MainWidget::slot_pc_key_auto_focus(unsigned char return_value)
{
    qDebug("slot_pc_key_auto_focus:return_value:0x%02x",return_value);
    //if(LASER_RANGING)
    //{
        if(return_value == RE_OK)//防止自动聚焦时打挡片
        {
            if(hpsetting.fastfocusmode)//若开启激光测距，则运行
            {
                ui->display->auto_focus = true;
                ui->display->update();
                QTimer::singleShot(1500, this, SLOT(sltPCKeyLaser()));
            }
        }else
        {
            signal_pc_key_laser(0);
            delaymsec(100);
            if(!isLasertype)//若值大于1，则不需要这个0
            {
                signal_pc_sys_set_laser_power(0);
            }                                         //这个好像是菜单的时候使用，按键的情况下不使用
            laser_on = false;
            ui->widget_laser->hide();
        }

        signal_pc_measure_tempcenter(1);
        delaymsec(3000);
        signal_pc_measure_tempcenter(0);
    //}
}
void MainWidget::slot_event_start_get_capture()
{
    if(start_capture &&(hpcameracap->cap_state== false))
    {
        start_capture = false;
    }
    if(ui->preview->get_hp_button_status() == S_SELECT || start_record)
        return;
    if(true == preview_open)
        return;
    if(true == setting_open_state)
        return;
    qDebug() << "panorama_dialog.isVisible()" << panorama_dialog.isVisible();
    if(main_task_sd)
    {
        if(sd_format == true || auto_state ==true)
        {
            return;
        }
        if(!sd_space_enough)
        {
            if(!start_capture)
            {
//                if(printscreen_checked)
//                {
//                    qDebug() << "printscreen_checked" << printscreen_checked;
//                    hpcameracap->init_cap();
//                    hpcameracap->ModeEnable(video_mode);
//                    hpcameracap->setText("冻结成功");
//                    hpcameracap->show();
//                }
//                else
//                {
                    qDebug() << "printscreen_checked" << printscreen_checked;
                    if(hpsetting.getPanoramaFlag() && !hp_panorama->isVisible())
                    {
//                        disconnect(&panorama_dialog, SIGNAL(signal_panorama_start()), this, SLOT(slot_cap_camera_panorama()));
                        panorama_dialog.slot_panorama_dialog_type(0);

                        panorama_dialog.move((ui->display->width() - hp_Wifi_search_Dialog->width()) / 2 + ui->frame->width(),(ui->display->height() - hp_Wifi_search_Dialog->height()) / 2);
                        panorama_dialog.show();
                        return;
                    }
                    start_capture = true;
                    qDebug() << "MainWidget::slot_event_start_get_capture()" << hp_panorama->currPicNo;
                    if(hp_panorama->currPicNo == 6)
                    {
                        hp_panorama->slot_core_key_capture_stop(RE_OK, "zhagnsan");
                    }
                    if(hp_panorama->isVisible())
                        m_panorama_cap = true;
                    signal_pc_key_set_freeze(1);
                    if(!hpcameracap->pms_xml.isEmpty() && !hpcameracap->pms_filename.isEmpty())
                    {
                        return;//国网模式只拍摄普通图片
                    }
                    if(hpcameracap->isSuperImage && (!hpcameracap->isSisFlag) && (5 != video_mode))
                    {
                        hpcameracap->sr_baocunflag= true;
                        qDebug("MainWidget::keyReleaseEvent--0x02--");
                        signal_core_key_capture_start(0x02);
                    }else if(hpcameracap->isSuperImage && hpcameracap->isSisFlag)
                    {
                        hpcameracap->sr_baocunflag= true;
                        qDebug("MainWidget::keyReleaseEvent--0xa--");
                        signal_core_key_capture_start(0xa);
                    }
//                }
            }
        }
        else
        {
            hssw->warning(fError,fSDHasNoSpace);
            hssw->setDelayClose(3000);
            hssw->show();
        }
    }
    else
    {
        hssw->warning(fError,fNoSD);
        hssw->setDelayClose(3000);
        hssw->show();
    }
}
void MainWidget::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug("MainWidget::keyReleaseEvent(QKeyEvent *ev) ============ 0x%02x ",ev->key());   //打印键值
    if(appcon_state == true)
    {
        qDebug()<<"app connect";
        return ;
    }
    if(onlcdonce)
    {
        onlcdonce = false;
        return;
    }
    if(hpsetting.lcd_offed)
    {
        hpsetting.slot_lcd_ReOpen();
        return;
    }
    slot_update_lcdoff_time(true);
    if(hp_panorama->isVisible() && (ev->key() == KEY_CAMERA_VIDEO))
    {
        return;
    }


    if(consercutiveLaser)
    {
        timerConsercutiveLaser->stop();
        signal_pc_key_laser(0);
        delaymsec(100);
        if(!isLasertype)//若值大于1，则不需要这个0
        {
            signal_pc_sys_set_laser_power(0);
        }
        QTimer::singleShot(2000, this, SLOT(slot_close_laser_widget()));
        laser_on = false;
    }
    GasPara gasPara;
    QString para;
    switch(ev->key())
    {
    case KEY_AUTORECTIFY:       //板子上的A键。 调零
        if(twice_analysis_start == false)
        {
            qDebug() << "QT signal_pc_key_auto_rectify" << __func__ <<__LINE__;
             signal_pc_key_auto_rectify();
        }
        break;
    case KEY_AUTORECTIFY_LONG:
        qDebug() << "define_sis == > " << define_sis;
        if(!define_sis)//若没有扫一扫功能则直接返回
        {
            if(hta->isVisible())
                break;
            if(hpsetting.getLensCount() < 2)
                break;
            if(timer_jingtou->isActive())
                timer_jingtou->stop();
            ui->listWidget_jingtou->close();
            signal_set_current_lens(m_currLens);
            break;
        }
        if(!hpcameracap->isSisFlag)
        {
            hssw->warning(fError,fSisIsNotOpen);
            hssw->setDelayClose(3000);
            hssw->show();
            return;
        }
        signal_set_qrcode_switch(1);
        qDebug() << "KEY_AUTORECTIFY_LONG - temp_mode == > " << temp_mode;
        if(temp_mode==-1)//经实验，这个变量不在扫一扫模式时为-1，若进入以下判断，则变为当前所在的模式
        {
            on_clean_clicked(S_NORMAL);//这里默认会被清理，应该是原先规定的？？？
            temp_mode = video_mode;
            video_mode =1 ;
            hpmode.set_mode(video_mode);

            ui->point->set_hp_button_status(S_DISABLE);
            ui->line->set_hp_button_status(S_DISABLE);
            ui->rect->set_hp_button_status(S_DISABLE);
            ui->clean->set_hp_button_status(S_DISABLE);
            ui->sebiao->set_hp_button_status(S_DISABLE);
            ui->bright_mode->set_hp_button_status(S_DISABLE);

            ui->mode->set_hp_button_status(S_DISABLE);
            ui->resize->set_hp_button_status(S_DISABLE);
            qrcode = true;
            timer_500ms.start(1000);
        }
        break;
    case KEY_RETURN:
        ui->display->drawStatus = DS_NON;
        if(ui->checkBox_polygon->isChecked())
        {
            on_checkBox_polygon_clicked(false);
        }
         if(hir_analyse)
         {
             slot_stop_hir_analyse();
             break;
         }
         qDebug() << "case KEY_RETURN:" << hp_panorama->isVisible();
         if(hp_panorama->getDialogVisiable())
         {
             qDebug() << "case hp_panorama->getDialogVisiable():" << hp_panorama->getDialogVisiable();
             hp_panorama->setDialogVisiable(false);
             return;
         }
         if(panorama_dialog.isVisible())
         {
             qDebug() << "panorama_dialog.isVisible()" << panorama_dialog.isVisible();
             slot_cap_camera_stop();
             panorama_dialog.close();
             return;
         }
         if(hp_panorama->isVisible() && !hp_panorama->m_dialog.isVisible()){
             slot_close_panorama(false);
             return;
         }
         qDebug() << "isTwiceChangeOver" << isTwiceChangeOver << __LINE__;
         if(twice_analysis_cut_pic || isTwiceChangeOver)
         {
             return;
         }
        if(video_mode == 1)
        {
            if(twice_analysis_start == true)                //判断是否开始了二次分析
            {
                hssw->warning(fError,fkjgNotQuit);
                hssw->setDelayClose(3000);
                hssw->show();
                ui->preview->set_hp_button_status(S_SELECT);
                break;
            }
            slot_close_sis_mode(false);
            break;
        }
        if(((video_mode == 4)&&fidpid))
        {
            if(twice_analysis_start == true)                //判断是否开始了二次分析
            {
                hssw->warning(fError,fHSENotQuit);
                hssw->setDelayClose(3000);
                hssw->show();
                ui->preview->set_hp_button_status(S_SELECT);
                break;
            }
        }
        ui->display->drawStatus = DS_NON;

        if( twice_analysis_start )//hppreview->Twice_analysis == true
        {
//            previewShow();
            if(hta->play_state)
            {
                signal_twice_voicep_Stop();
            }
            if(hta->voice_state)
            {
                signal_twice_voiceStop();
            }
            on_preview_clicked(S_SELECT);
        }
        update_main_show((MAIN_SHOW)(100));
        break;
    case KEY_LASER_LONG:
        if(consercutiveLaser)
        {
            timerConsercutiveLaser->stop();
            signal_pc_key_laser(0);
            delaymsec(100);
            if(!isLasertype)//若值大于1，则不需要这个0
            {
                signal_pc_sys_set_laser_power(0);
            }
            QTimer::singleShot(2000, this, SLOT(slot_close_laser_widget()));
            laser_on = false;
        }
        break;
    case KEY_LASER:         //开激光。
        if(getRangeOnce){
            ui->widget_laser->show();
            m_laserRangeTimer = 0;
            if(!isLasertype)//若值大于1，则不需要这个1
            {
                signal_pc_sys_set_laser_power(1);
                delaymsec(100);
            }
            signal_pc_sys_set_laserrange();
            delaymsec(1000);
            signal_pc_sys_get_laserrange();
            laser_on = false;

            QTimer::singleShot(6000, this, SLOT(slot_close_laser_widget()));
            break;
        }

        //暂用激光切档
        if(laser_on)
        {
            signal_pc_key_laser(0);
            delaymsec(100);
            if(!isLasertype)//若值大于1，则不需要这个0
            {
                signal_pc_sys_set_laser_power(0);
            }
            laser_on = false;
            ui->widget_laser->setVisible(false);
        }
        else
        {
            if(laser_init == false)
            {
                initLaser();
            }
            qDebug("signal_pc_sys_set_laser_power(1);");
            signal_pc_sys_set_laser_power(1);
            delaymsec(100);
            signal_pc_key_laser(1);
            laser_on = true;
            ui->widget_laser->setVisible(true);
        }
        break;
    case KEY_CAMERA_PICTURE:                    //按键用来 获取图片 0x43
        if(m_hotKey0 == HOTKEY_CAMERA)
        {
            slot_event_start_get_capture();
        }
        else if(m_hotKey0 == HOTKEY_LED)
        {
            bool isChecked = hpsetting.ui->buguangdeng->isChecked();
            hpsetting.ui->buguangdeng->setChecked(!isChecked);
            hpsetting.ui->buguangdeng->clicked(!isChecked);
        }
        else if(m_hotKey0 == HOTKEY_SR)
        {
            bool isChecked = hpsetting.ui->checkBox_sr->isChecked();
            hpsetting.ui->checkBox_sr->setChecked(!isChecked);
            hpsetting.ui->checkBox_sr->clicked(!isChecked);
        }
        else if(m_hotKey0 == HOTKEY_WIFI)
        {
            bool isChecked = hpsetting.ui->checkBox_wifi->isChecked();
            hpsetting.ui->checkBox_wifi->setChecked(!isChecked);
            hpsetting.ui->checkBox_wifi->clicked(!isChecked);
        }
        else if(m_hotKey0 == HOTKEY_BLUETOOTH)
        {
            isHotKeyBle = true;
            bool isChecked = hpsetting.ui->checkBox_ble->isChecked();
            hpsetting.ui->checkBox_ble->setChecked(!isChecked);
            hpsetting.ui->checkBox_ble->clicked(!isChecked);
        }
        else if(m_hotKey0 == HOTKEY_PALLET)
        {
            if(!hpsebiao.isVisible())
            {
                ui->sebiao->set_hp_button_status(S_SELECT);
                on_sebiao_clicked(S_SELECT);
            }
            else
            {
                if(video_sebiao + 1 <= hpsetting.m_colorrulemaxid)
                {
                    hpsebiao.set_sebiao(video_sebiao + 1);
                }
                else
                {
                    video_sebiao = hpsetting.m_colorruleminid;
                    hpsebiao.set_sebiao(hpsetting.m_colorruleminid);
                }
            }
        }
        break;
    case 0x1000032:              //自动调焦短按，注意这里重复写了
        if(true == preview_open )
            break;
        qDebug() << "Mainwidget::keyreleaseEvent AUTOFOCUS" << hpsetting.fastfocusmode << fidpid << define_brightmode;
        if(m_hotKey1 == HOTKEY_FOCUS)
        {
            if(con_flag)
            {
                return;
            }
            if(hpsetting.fastfocusmode || fidpid)
            {
                if( define_brightmode || fidpid)
                {
                    if(laser_init == false)
                    {
                        initLaser();
                    }
                    if( laser_on)
                    {
                        signal_pc_key_laser(0);
                        delaymsec(100);
                        if(!isLasertype)//若值大于1，则不需要这个0
                        {
                            signal_pc_sys_set_laser_power(0);
                        }
                        ui->widget_laser->setVisible(false);
                        delaymsec(100);
                    }
                    if(hpsetting.fastfocusmode)
                        signal_pc_sys_set_laser_power(1);
                    delaymsec(100);
                    if(!fidpid)
                    {
                        signal_pc_key_auto_focus();
                    }
                    else
                    {
                        unsigned char res;
                        res = 0;
                        slot_pc_key_auto_focus(res);
                    }
                }
            }
            else
            {
                if(define_brightmode)
                {
                    if(!fidpid)
                    {
                        signal_pc_key_auto_focus();
                    }
                    else
                    {
                        unsigned char res;
                        res = 0;
                        slot_pc_key_auto_focus(res);
                    }
                }
            }
        }
        else if(m_hotKey1 == HOTKEY_LED)
        {
            bool isChecked = hpsetting.ui->buguangdeng->isChecked();
            hpsetting.ui->buguangdeng->setChecked(!isChecked);
            hpsetting.ui->buguangdeng->clicked(!isChecked);
        }
        else if(m_hotKey1 == HOTKEY_SR)
        {
            bool isChecked = hpsetting.ui->checkBox_sr->isChecked();
            hpsetting.ui->checkBox_sr->setChecked(!isChecked);
            hpsetting.ui->checkBox_sr->clicked(!isChecked);
        }
        else if(m_hotKey1 == HOTKEY_WIFI)
        {
            bool isChecked = hpsetting.ui->checkBox_wifi->isChecked();
            hpsetting.ui->checkBox_wifi->setChecked(!isChecked);
            hpsetting.ui->checkBox_wifi->clicked(!isChecked);
        }
        else if(m_hotKey1 == HOTKEY_BLUETOOTH)
        {
            isHotKeyBle = true;
            bool isChecked = hpsetting.ui->checkBox_ble->isChecked();
            hpsetting.ui->checkBox_ble->setChecked(!isChecked);
            hpsetting.ui->checkBox_ble->clicked(!isChecked);
        }
        else if(m_hotKey1 == HOTKEY_PALLET)
        {
            if(!hpsebiao.isVisible())
            {
                ui->sebiao->set_hp_button_status(S_SELECT);
                on_sebiao_clicked(S_SELECT);
            }
            else
            {
                if(video_sebiao + 1 <= hpsetting.m_colorrulemaxid)
                {
                    hpsebiao.set_sebiao(video_sebiao + 1);
                }
                else
                {
                    video_sebiao = hpsetting.m_colorruleminid;
                    hpsebiao.set_sebiao(hpsetting.m_colorruleminid);
                }
            }
        }
        break;
    case 0x4d:
        hpsetting.hphidemenu.show();
        break;
    case 0x50:
        if(adjust_cmd_show_flag)
        {
            hpadjustcmd.adjust_cmd_open = false;
            hpadjustcmd.stopBnTimer();
            hpadjustcmd.close();
            adjust_cmd_show_flag = false;
        }
        else
        {
            hpadjustcmd.adjust_cmd_open = true;
            hpadjustcmd.startBnTimer();
            hpadjustcmd.show();
            adjust_cmd_show_flag = true;
        }
        break;
 case 0x4f:			//键盘 O 键
    m_keyORelease = true;
    gasPara.SensibilityGain = 3;
    gasPara.SensibilityRange = 2;
    gasPara.SensibilitySwitch = 1;
    para = hpxmlreader.readXml("sys.xml","GASPARA","gain");
    if(para != NULL){
        gasPara.SensibilityGain = para.toInt();
    }
    para = hpxmlreader.readXml("sys.xml","GASPARA","range");
    if(para != NULL){
        gasPara.SensibilityRange = para.toInt();
    }
    para = hpxmlreader.readXml("sys.xml","GASPARA","on");
    if(para != NULL){
        gasPara.SensibilitySwitch = para.toInt();
    }
    siganl_image_set_gas_para(gasPara);
    QTimer::singleShot(500, this, SLOT(slot_pc_send_biaoding()));
    break;
 case 0x51:             //主界面调零   键盘信号q
    if(twice_analysis_start == false)
    {
        qDebug() << "QT signal_pc_key_auto_rectify" << __func__ <<__LINE__;
        signal_pc_key_auto_rectify();
    }
    break;
 case   0x1000021:              //ctrl
    ctrl_ok = false;
    break;
 case 0x1000023:                                              //    键盘按下alt
     alt_ok =false;
     break;
 case   0x41:                   //a
    if(true == ctrl_ok){
        signal_dandian_sidian();
    }
     break;
 case   0x53:                   //s
     if(true == ctrl_ok){
         signal_gaowen_sidian();
     }
     break;
 case   0x44:                   //d
     if(true == ctrl_ok){
          signal_diwen_sidian();
     }
     break;
 case 0x49:                     //  i    上   bad point
     break;
 case 0x4b:                     //  k     下
     break;
 case 0x4a:                     //  J     左
     break;
 case 0x4c:                     // L      右
        if(hidemenu_laser && ui->widget_laser->isVisible())
            return;
        hphidelaser.start_laser_adjust();
        hphidelaser.show();
     break;
 case Qt::Key_F:
     hpsetting.hpdidelaser.show();
     break;
 default:
        break;
    }
}

void MainWidget::mouseMoveEvent(QMouseEvent *ev)
{
  //  qDebug("\tmouseMoveEvent (%d,%d)",ev->pos().x(),ev->pos().y());
}

void MainWidget::mousePressEvent(QMouseEvent *ev)
{
}

void MainWidget::mouseReleaseEvent(QMouseEvent *ev)
{
 //   qDebug("\tmouseReleaseEvent (%d,%d)",ev->pos().x(),ev->pos().y());

}

bool MainWidget::get_headset_status()
{
    return main_task_headset;
}

void MainWidget::slot_mainset_lcd_offed_state()
{
    if(onlcdonce)
    {
        onlcdonce = false;
        return;
    }
    if(hpsetting.lcd_offed)
    {
        qDebug("lcd on....4");

        hpsetting.slot_lcd_ReOpen();
        return;
    }
}

bool MainWidget::eventFilter(QObject *o, QEvent *e)
{
    if(appcon_state == true)
    {
        qDebug()<<"app connect";
        return true;
    }
    if(QEvent::MouseButtonPress == e->type())               //先判断是鼠标点击事件
    {
        if(o->objectName() == "toolButton_max")          //判断想要打开的是哪个下拉框
        {
            if(max_handle_flag==true)
                max_handle_flag = false;
            else
                max_handle_flag = true;
             min_handle_flag = false;
            auto_manual_update();
        }
        if(o->objectName() == "toolButton_min")          //判断想要打开的是哪个下拉框
        {
            if(min_handle_flag==true)
                min_handle_flag = false;
            else
                min_handle_flag = true;
            max_handle_flag = false;
            auto_manual_update();
        }
    }
    if(o->objectName() != "MainWidget")
    {
        if(e->type() == QMouseEvent::MouseButtonPress || e->type() == QMouseEvent::MouseMove || e->type() == QMouseEvent::MouseButtonRelease)
        {
//            qDebug() << "o->objectName() == > " << o->objectName() << "  twice_analysis_start == > " << twice_analysis_start;
            if(o->objectName() == "Hp_Twice_Analysis" && twice_analysis_start)
            {
                QMouseEvent *ex = (QMouseEvent *)e;
                QPointF myPoint(ex->pos().x(),ex->pos().y() + hta->y());
                ex->setLocalPos(myPoint);
                QApplication::sendEvent(ui->display, ex);
                return true;
            }
        }
        if(e->type() == QKeyEvent::KeyPress)
        {
            QKeyEvent *key_event = (QKeyEvent *)e;
            if(key_event->key() == KEY_CAMERA_VIDEO)
            {
                if(QApplication::activeWindow()->objectName() == "HpPreview"
                        || QApplication::activeWindow()->objectName() == "HpSetting"
                        || QApplication::activeWindow()->objectName() == "Hp_Ble_Search" )
                {
                    return false;
                }
                qDebug() << "MainWidget::eventFilter hpsetting.isTaskMode" << hpsetting.isTaskMode;
                if(hpsetting.isTaskMode)
                {
                    return true;
                }
                if(start_record)
                {
                    m_hirRecordStarted = false;
                    qDebug() << "(key_event->key() == KEY_CAMERA_VIDEO) END 1 : " << avi_hir_mode;
                    if(HVI_mode == 1)
                    {
                        if (1 == avi_hir_mode)
                        {
                            avi_record_get_SDInfo->stop();
                            hpcameravideo.timer_stop();
                            signal_core_key_record_avi_stop();
                            avi_hir_mode = 0;
                        }else if(2 == avi_hir_mode)
                        {
                            avi_record_get_SDInfo->stop();
                            hpcameravideo.timer_stop();
                           signal_core_key_record_hir_stop();
                            avi_hir_mode = 0;
                        }else{};
                    }else if(HIR_Mode==1)
                    {
                        if (1 == avi_hir_mode)
                        {
                            avi_record_get_SDInfo->stop();
                            hpcameravideo.timer_stop();
                            signal_core_key_record_avi_stop();
                        }else if(2 == avi_hir_mode)
                        {
                            avi_record_get_SDInfo->stop();
                            hpcameravideo.timer_stop();
                           signal_core_key_record_hir_stop();
                        }else{};
                    }
                    else
                    {
                        avi_record_get_SDInfo->stop();
                        hpcameravideo.timer_stop();
                        signal_core_key_record_avi_stop();                           //只有视频模式，需要时打开，然后屏蔽下面的 hvi模式
                    }
                    if(autoSaveShowTimer != -1)
                    {
                        isAutoSave = true;
                        PreviewIconLimit(S_DISABLE);
                    }
                }
                else
                {
                    if(main_task_sd)
                    {
                        isAutoSave = false;
                        if(!sd_space_enough)
                        {
//                            if(!hpsetting.hpblesearchold.get_conn_status() && !hpsetting.hpblesearch.isLinked && !isBlePowerOn)
//                            {
//                                if(hpsetting.isNewBle &&  !hpsetting.isBleOpen && !hpsetting.ui->checkBox_ble->isChecked())
//                                {
//                                    signal_pc_sys_set_ble_power(1);
//                                    signal_pc_sys_set_ble_module(1);
//                                }
//                                delaymsec(200);

//                                if(avi_hir_mode == 2)
//                                {
//                                    m_hirRecordStarted = true;
//                                }
//                                signal_pc_sys_set_analog_video(1);
//                                delaymsec(200);
//                                isBlePowerOn = true;
//                            }
                            qDebug() << "(key_event->key() == KEY_CAMERA_VIDEO) start 1 : " << avi_hir_mode;
                            if(HVI_mode ==1)
                            {
                                hp_avimode.show();
                            }else if(HIR_Mode ==1)
                            {
                                if(avi_hir_mode==1)
                                {
                                    //从这里开始，同样也会经过slot_core_key_record_avi_start槽函数
                                    avi_record_get_SDInfo->start();
                                    signal_core_key_record_avi_mode_start();
                                }else if(avi_hir_mode == 2)
                                {
                                    avi_record_get_SDInfo->start();
//                                    if(hpsetting.hpblesearchold.get_conn_status() || hpsetting.hpblesearch.isLinked || isBlePowerOn)
//                                    {
                                        signal_core_key_record_hir_mode_start();
//                                    }
                                }else{};
                            }else
                            {
                                avi_record_get_SDInfo->start();
                                signal_core_key_record_avi_start();
                            }
                        }
                        else
                        {
                            hssw->warning(fError,fSDHasNoSpace);
                            hssw->setDelayClose(3000);
                            hssw->show();
                        }
                    }
                    else
                    {
                        hssw->warning(fError,fNoSD);
                        hssw->setDelayClose(3000);
                        hssw->show();
                    }

                }
            }
        }
        if(e->type() == QKeyEvent::KeyRelease)
        {
            if(onlcdonce)
            {
                onlcdonce = false;
                return true;
            }
            if(hpsetting.lcd_offed)
            {
                qDebug("lcd on....5");

                hpsetting.slot_lcd_ReOpen();
                return true;
            }
            if(Task_win == 4)//不知道什么界面
            {
                return true;
            }
            QKeyEvent *key_event = (QKeyEvent *)e;
            if(Task_win != 0 && Task_win != 2 && key_event->key() != KEY_RETURN)
            {
                return true;
            }
            if(key_event->key() == KEY_RETURN)
            {
                 if(panorama_dialog.isVisible())
                 {
                     panorama_dialog.close();
                     return true;
                 }
                 if(hp_panorama->isVisible() && !hp_panorama->m_dialog.isVisible())
                 {
                     qDebug() << "panorama close";
                     slot_close_panorama(false);
                     return true;
                 }

                 qDebug() << "hpDelEdit" << ui->display->nowselect.c << __LINE__;
                if(ui->display->m_filePathState)//是否处于台账模式
                {
                    qDebug()<<"MainWidget::eventFilter--- Task_win > " << Task_win;
                    if((qrcode == true) && define_sis)//是否处于扫一扫模式
                    {
                        slot_set_qrcode_state(false);
                        ui->display->TaskSouldBepaint = true;
                        ui->display->update();
                        return true;
                    }
                    if(Task_win == 5)//统计界面
                    {
                        Task_win = 2;
                        Hp_TaskPkg::getInstance()->GoBack_Dlg();
                    }else if(Task_win == 1)//任务选择界面
                    {
                        Hp_TaskPkg::getInstance()->Close_Dlg();
                    }else if(Task_win == 2){//若处于树状图界面
                        if(QApplication::activeWindow()->objectName() == "HpPLREdit")
                        {
                            QApplication::activeWindow()->close();
                        }else if(QApplication::activeWindow()->objectName() == "hpDelEdit"){
                            if(ui->display->nowselect.c != DS_NON)
                            {
                                OP_DATA op_data;
                                op_data.cmd_type = DS_NON;
                                op_data.id = -1;
                                ui->display->signal_pc_measure_active(op_data);
                                ui->display->nowselect.c = DS_NON;
                                ui->display->nowselect.s = -1;
                                ui->display->update();
                                ui->display->selectUpdate();
                            }
                        }else{
                            Task_win = 1;
                            Hp_TaskPkg::getInstance()->GoBack_Dlg();
                        }
                    }else if(Task_win == 3)//若处于“是否恢复上次”弹窗
                    {
                        QApplication::activeWindow()->close();
                        slot_CloseDlg();
                    }
                    return true;
                }
                else if(QApplication::activeWindow()->objectName() == "HpMode")
                {
                    ui->mode->set_hp_button_status(S_NORMAL);
                    on_mode_clicked(S_NORMAL);
                    return true;
                }
                else if(start_record == true)
                {
                    if( QApplication::activeWindow()->objectName() == "Hp_Mode_Rdj_Adjust" || QApplication::activeWindow()->objectName() == "Hp_Mode_Hzh_Adjust" )
                    {
                        return false;
                    }
                    return true;
                }
                else if(QApplication::activeWindow()->objectName() == "HpSebiao")
                {
                    ui->sebiao->set_hp_button_status(S_NORMAL);
                    on_sebiao_clicked(S_NORMAL);
                    return true;
                }
                else if(QApplication::activeWindow()->objectName() == "HpResize")
                {
                    ui->resize->set_hp_button_status(S_NORMAL);
                    on_resize_clicked(S_NORMAL);
                    return true;
                }
                else if(QApplication::activeWindow()->objectName() == "HpPreview")
                {
                    signal_core_corectrl_start_encode();
                    if(!hpsetting.hpblesearchold.get_conn_status() && !hpsetting.hpblesearch.isLinked)
                    {
                        if(hpsetting.isNewBle && !hpsetting.isBleOpen && !hpsetting.ui->checkBox_ble->isChecked())
                        {
                            signal_pc_sys_set_ble_module(0);
                            signal_pc_sys_set_ble_power(0);
                            isBlePowerOn = false;
                        }
                    }

                    hta->close();
                    ui->label->close();
                    ui->label_2->close();
                    ui->next_page->close();
                    ui->last_page->close();
                    return true;
                }
                else if(QApplication::activeWindow()->objectName() == "hpDelEdit")
                {
                    qDebug() << "hpDelEdit" << ui->display->nowselect.c << __LINE__;
                    if(ui->display->nowselect.c != DS_NON)
                    {
                        qDebug() << "hpDelEdit" << ui->display->nowselect.c << __LINE__;
                        OP_DATA op_data;
                        op_data.cmd_type = DS_NON;
                        op_data.id = -1;
                        qDebug() << "hpDelEdit" << ui->display->nowselect.c << __LINE__;
                        ui->display->signal_pc_measure_active(op_data);
                        ui->display->nowselect.c = DS_NON;
                        ui->display->nowselect.s = -1;
                        qDebug() << "hpDelEdit" << ui->display->nowselect.c << __LINE__;
                        ui->display->update();
                        ui->display->selectUpdate();
                    }
                    qDebug() << "hpDelEdit" << ui->display->nowselect.c << __LINE__;
                    return true;
                }
                else if(QApplication::activeWindow()->objectName() == "Hp_Media_Player")
                {
                    hppreview->hmp.stop_play_media();
                }
                else if(QApplication::activeWindow()->objectName() == "Hp_Media_Player_Gplay")
                {
                    hppreview->hmp2.stop_play_media();
                }
                else if(QApplication::activeWindow()->objectName() == "hp_Hir_Player")
                {
                    hppreview->hhp.on_toolButton_close_released();
                }
                else if(QApplication::activeWindow()->objectName() == "Hp_Adjust_Cmd")
                {
                    hpadjustcmd.adjust_cmd_open = false;
                    hpadjustcmd.stopBnTimer();
                    hpadjustcmd.close();
                    adjust_cmd_show_flag = false;
                    return true;
                }
                else if( QApplication::activeWindow()->objectName() == "HpPLREdit" )
                {
                    ui->display->pb_cancle_clicked();
                    ui->display->hpplredit->close();
                }else if(o->objectName() == "HpSetting")
                {
                    if(setting_open_state)
                    {
                        slot_setting_close();
                    }
                }

                else  if( QApplication::activeWindow()->objectName() == "MainWidget"&& preview_open )
                {
                    if(video_mode == 1)
                    {
                        hssw->warning(fError,fkjgNotQuit);
                        hssw->setDelayClose(3000);
                        hssw->show();
                        ui->preview->set_hp_button_status(S_SELECT);
                        return true;

                    }
                    else  if(((video_mode == 4)&&fidpid))
                    {
                        hssw->warning(fError,fHSENotQuit);
                        hssw->setDelayClose(3000);
                        hssw->show();
                        ui->preview->set_hp_button_status(S_SELECT);
                        return true;
                    }
                    else
                    {
                        qDebug() << "isTwiceChangeOver" << isTwiceChangeOver << __LINE__;
                        if(twice_analysis_cut_pic || isTwiceChangeOver)
                        {
                            return true;
                        }
                        hta->stop_twice_preview =true;
                        if(hta->play_state)
                       {
                          signal_twice_voicep_Stop();
                       }
                        on_preview_clicked(S_SELECT);
                    }
                }
                else if(QApplication::activeWindow()->objectName() == "MainWidget")
                {
                     return true;
                }
                else
                {
                    QApplication::activeWindow()->close();
                    return true;
                }
            }
            else if(key_event->key() == KEY_AUTORECTIFY)
            {
                if(twice_analysis_start == false)
                {
                     signal_pc_key_auto_rectify();
                }
                return true;
            }
            else if(key_event->key() == KEY_AUTORECTIFY_LONG)//若 扫一扫
            {
                if(!define_sis)//若没有扫一扫功能则直接返回
                {
                    return true;
                }
                if(!hpcameracap->isSisFlag)
                {
                    hssw->warning(fError,fSisIsNotOpen);
                    hssw->setDelayClose(3000);
                    hssw->show();
                    return true;
                }
                 signal_set_qrcode_switch(1);//开始扫一扫
                 qDebug() << "KEY_AUTORECTIFY_LONG - MainWidget::eventFilter == > " << temp_mode;
                 if(temp_mode==-1)//经实验，这个变量不在扫一扫模式时为-1，若进入以下判断，则变为当前所在的模式
                 {
                     temp_mode = video_mode;
                     video_mode =1 ;
                     hpmode.set_mode(video_mode);
                    ui->display->TaskSouldBepaint = false;
                    ui->display->update();
                     qrcode = true;
                     timer_500ms.start(1000);
                 }
            }
            else if(key_event->key() == 0x1000000)
            {
                hpadjustcmd.adjust_cmd_open = false;
                hpadjustcmd.stopBnTimer();
                hpadjustcmd.close();
                adjust_cmd_show_flag = false;
                return true;
            }
            else if(key_event->key() == KEY_CAMERA_PICTURE)
            {
                if(panorama_dialog.isVisible() || hp_panorama->m_dialog.isVisible())
                {
                    slot_cap_camera_panorama();
                }

                if(m_hotKey0 == HOTKEY_CAMERA)
                {
                    if(false == setting_open_state)
                    {
                        if(true == preview_open){
                            ;
                        }else{
                            if(sd_format == true || auto_state ==true)
                            {
                                return false;
                            }
                        if(!start_record)
                        {
    //                        qDebug() << " KEY_CAMERA_PICTURE 5 " << main_task_sd;
                            if(main_task_sd)
                            {
    //                            qDebug() << " KEY_CAMERA_PICTURE 6 " << sd_space_enough;
                                if(!sd_space_enough)
                                {

    //                                qDebug() << " KEY_CAMERA_PICTURE 7 " << start_capture;
                                    if(!start_capture)
                                    {
    //                                    qDebug() << " KEY_CAMERA_PICTURE 8 " << printscreen_checked;
                                        if(printscreen_checked)
                                        {
                                            hpcameracap->init_cap();
                                            hpcameracap->ModeEnable(video_mode);
                                            hpcameracap->setText("冻结成功");
                                            hpcameracap->show();
                                        }
                                        else
                                        {
                                            if(hpsetting.getPanoramaFlag() && !hp_panorama->isVisible() && !ui->display->hpplredit->isVisible() && !hpcameracap->Taskmode)
                                            {
                                                panorama_dialog.slot_panorama_dialog_type(0);
                                                panorama_dialog.move((ui->display->width() - hp_Wifi_search_Dialog->width()) / 2 + ui->frame->width(),(ui->display->height() - hp_Wifi_search_Dialog->height()) / 2);
                                                panorama_dialog.show();
                                                return true;
                                            }
                                            start_capture = true;
                                            signal_pc_key_set_freeze(1);
                                            if(hpcameracap->isSuperImage && (!hpcameracap->isSisFlag) && (5 != video_mode))
                                            {
                                                hpcameracap->sr_baocunflag= true;
                                                qDebug("eventfilter MainWidget::keyReleaseEvent--0x02--");
                                                signal_core_key_capture_start(0x02);    //开始拍照
                                            }else if(hpcameracap->isSuperImage && hpcameracap->isSisFlag)
                                            {
                                                hpcameracap->sr_baocunflag= true;
                                                qDebug("eventfilter MainWidget::keyReleaseEvent--0xa--");
                                                signal_core_key_capture_start(0xa);
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    hssw->warning(fError,fSDHasNoSpace);
                                    hssw->setDelayClose(3000);
                                    hssw->show();
                                }
                            }
                            else
                            {
                                hssw->warning(fError,fNoSD);
                                hssw->setDelayClose(3000);
                                hssw->show();
                            }
                        }
                        }
                    }
                }
                else if(m_hotKey0 == HOTKEY_LED)
                {
                    bool isChecked = hpsetting.ui->buguangdeng->isChecked();
                    hpsetting.ui->buguangdeng->setChecked(!isChecked);
                    hpsetting.ui->buguangdeng->clicked(!isChecked);
        //            system("./devtest 1 0");
        //            hpsetting.lcd_offed = true;
        //            hpsetting.lcdoff_clock_ret = 0;
        //            IsInlcdoff = false;
                }
                else if(m_hotKey0 == HOTKEY_SR)
                {
                    bool isChecked = hpsetting.ui->checkBox_sr->isChecked();
                    hpsetting.ui->checkBox_sr->setChecked(!isChecked);
                    hpsetting.ui->checkBox_sr->clicked(!isChecked);
                }
                else if(m_hotKey0 == HOTKEY_WIFI)
                {
                    bool isChecked = hpsetting.ui->checkBox_wifi->isChecked();
                    hpsetting.ui->checkBox_wifi->setChecked(!isChecked);
                    hpsetting.ui->checkBox_wifi->clicked(!isChecked);
                }
                else if(m_hotKey0 == HOTKEY_BLUETOOTH)
                {
                    isHotKeyBle = true;
                    bool isChecked = hpsetting.ui->checkBox_ble->isChecked();
                    hpsetting.ui->checkBox_ble->setChecked(!isChecked);
                    hpsetting.ui->checkBox_ble->clicked(!isChecked);
                }
                else if(m_hotKey0 == HOTKEY_PALLET)
                {
                    if(!hpsebiao.isVisible())
                    {
                        ui->sebiao->set_hp_button_status(S_SELECT);
                        on_sebiao_clicked(S_SELECT);
                    }
                    else
                    {
                        if(video_sebiao + 1 <= hpsetting.m_colorrulemaxid)
                        {
                            hpsebiao.set_sebiao(video_sebiao + 1);
                        }
                        else
                        {
                            video_sebiao = hpsetting.m_colorruleminid;
                            hpsebiao.set_sebiao(hpsetting.m_colorruleminid);
                        }
                    }
                }
            }
            else if(key_event->key() == KEY_LASER)
            {
                if(getRangeOnce){
                    m_laserRangeTimer = 0;

                    if(!isLasertype)//若值大于1，则不需要这个1
                    {
                        signal_pc_sys_set_laser_power(1);
                        delaymsec(100);
                    }
                    signal_pc_sys_set_laserrange();
                    delaymsec(1000);
                    signal_pc_sys_get_laserrange();
                    laser_on = false;
                    return true;
                }
                if(laser_on)
                {
                    signal_pc_key_laser(0);
                    delaymsec(100);
                    if(!isLasertype)//若值大于1，则不需要这个0
                    {
                        signal_pc_sys_set_laser_power(0);
                    }
                    laser_on = false;
                    ui->widget_laser->setVisible(false);
                }
                else
                {
                    signal_pc_sys_set_laser_power(1);
                    delaymsec(100);
                    signal_pc_key_laser(1);
                    laser_on = true;
                    ui->widget_laser->setVisible(true);
                }
            }

            else if(key_event->key() == 0x1000032)
            {
                if(true == preview_open || con_flag)
                    return false;
                if(m_hotKey1 == HOTKEY_FOCUS)
                {
                    if(hpsetting.fastfocusmode || fidpid)
                    {
                        if( define_brightmode  || fidpid)
                        {
                            if(laser_init == false)
                            {
                                initLaser();
                            }
                            if( laser_on )
                            {
                                signal_pc_key_laser(0);
                                delaymsec(100);
                                if(!isLasertype)//若值大于1，则不需要这个0
                                {
                                    signal_pc_sys_set_laser_power(0);
                                }
                                ui->widget_laser->setVisible(false);
                                laser_on = false;
                            }
                            delaymsec(100);
                            signal_pc_sys_set_laser_power(1);
                            delaymsec(100);
                            if(!fidpid)
                            {
                                signal_pc_key_auto_focus();
                            }
                            else
                            {
                                unsigned char res;
                                res = 0;
                                slot_pc_key_auto_focus(res);
                            }
                        }
                    }
                    else
                    {
                        if(define_brightmode)
                        {
                            if(main_auto_focus == true){
                                if(!fidpid)
                                {
                                    signal_pc_key_auto_focus();
                                }
                                else
                                {
                                    unsigned char res;
                                    res = 0;
                                    slot_pc_key_auto_focus(res);
                                }
                            }
                        }
                    }
                }
                else if(m_hotKey1 == HOTKEY_LED)
                {
                    bool isChecked = hpsetting.ui->buguangdeng->isChecked();
                    hpsetting.ui->buguangdeng->setChecked(!isChecked);
                    hpsetting.ui->buguangdeng->clicked(!isChecked);
                }
                else if(m_hotKey1 == HOTKEY_SR)
                {
                    bool isChecked = hpsetting.ui->checkBox_sr->isChecked();
                    hpsetting.ui->checkBox_sr->setChecked(!isChecked);
                    hpsetting.ui->checkBox_sr->clicked(!isChecked);
                }
                else if(m_hotKey1 == HOTKEY_WIFI)
                {
                    bool isChecked = hpsetting.ui->checkBox_wifi->isChecked();
                    hpsetting.ui->checkBox_wifi->setChecked(!isChecked);
                    hpsetting.ui->checkBox_wifi->clicked(!isChecked);
                }
                else if(m_hotKey1 == HOTKEY_BLUETOOTH)
                {
                    isHotKeyBle = true;
                    bool isChecked = hpsetting.ui->checkBox_ble->isChecked();
                    hpsetting.ui->checkBox_ble->setChecked(!isChecked);
                    hpsetting.ui->checkBox_ble->clicked(!isChecked);
                }
                else if(m_hotKey1 == HOTKEY_PALLET)
                {
                    if(!hpsebiao.isVisible())
                    {
                        on_sebiao_clicked(S_SELECT);
                    }
                    else
                    {
                        if(video_sebiao + 1 <= hpsetting.m_colorrulemaxid)
                        {
                            hpsebiao.set_sebiao(video_sebiao + 1);
                        }
                        else
                        {
                            video_sebiao = hpsetting.m_colorruleminid;
                            hpsebiao.set_sebiao(hpsetting.m_colorruleminid);
                        }
                    }
                }
            }
        }
    }
    else
    {
    }
    return false;
}

void MainWidget::initLaser()
{
    laser_on = false;
    ui->widget_laser->setVisible(false);
    laser_init= true;
}

void MainWidget::slot_hidemenu_laser(bool checked)
{
    hidemenu_laser = checked;
}
void MainWidget::on_toolButton_AM_clicked(bool checked)
{
    slot_update_lcdoff_time(false);
    if(checked)
    {
        signal_pc_image_get_manual();
    }
    else
    {
        manualpara.ManualType = 1;
        auto_manual_flag = false;

        min_handle_flag = false;
        max_handle_flag = false;
        signal_pc_image_set_manual(manualpara);
        auto_manual_update();
    }
}

void MainWidget::on_toolButton_min_clicked(bool checked)
{
    qDebug() << __func__ << checked;
    slot_update_lcdoff_time(false);
    min_handle_flag = checked;
    if(checked)
        max_handle_flag = false;
    auto_manual_update();
}

void MainWidget::on_toolButton_max_clicked(bool checked)
{
    qDebug() << __func__ << checked;
    slot_update_lcdoff_time(false);
    max_handle_flag = checked;
    if(checked)
        min_handle_flag = false;
    auto_manual_update();
}

void MainWidget::on_toolButton_up_released()
{
    slot_update_lcdoff_time(false);
    if(min_handle_flag)
    {
        if(min_value100+10<max_value100) //Min max
        {
            min_value100 += 10;
        }
    }
    if(max_handle_flag)
    {
        max_value100 += 10;
    }
    manualpara.TempLowest = min_value100;
    manualpara.TempHighest = max_value100;

    signal_pc_image_set_manual(manualpara);
    auto_manual_update();

}

void MainWidget::on_toolButton_down_released()
{
    slot_update_lcdoff_time(false);
    if(min_handle_flag)
    {
        min_value100 -= 10;
    }
    if(max_handle_flag)
    {
        if(max_value100>min_value100+10) //min max
        {
            max_value100 -= 10;
        }
    }

    manualpara.TempLowest = min_value100;
    manualpara.TempHighest = max_value100;
    signal_pc_image_set_manual(manualpara);

    auto_manual_update();
}

void MainWidget::slot_timer_task()
{
    ui->widget_task->update_sd(main_task_sd);
    ui->widget_task->update_wifi(main_task_wifi);
    ui->widget_task_1->update_sd(main_task_sd);
    ui->widget_task_1->update_wifi(main_task_wifi);
    ui->widget_task_2->update_sd(main_task_sd);
    ui->widget_task_2->update_wifi(main_task_wifi);
    ui->widget_task_3->update_sd(main_task_sd);
    ui->widget_task_3->update_wifi(main_task_wifi);
    signal_pc_sys_get_appcontrolstatus();
    if(twice_analysis_start== true && main_task_usb )   //usb插入时如果二次分析打开就关闭 然后退出到主界面
    {
        signal_core_analysis_pic_twice_stop();
        twice_analysis_start=false;
        signal_core_corectrl_start_encode();
    }

//2018.1.17
    if( (main_task_wifi || main_task_usb || main_task_eth) && ui->preview->get_hp_button_status() != S_DISABLE )
    {
        PreviewIconLimit(S_DISABLE);
    }

    ui->widget_task->update_usb(main_task_usb);
    ui->widget_task->update_ble(main_task_ble);
    ui->widget_task_1->update_usb(main_task_usb);
    ui->widget_task_1->update_ble(main_task_ble);
    ui->widget_task_2->update_usb(main_task_usb);
    ui->widget_task_2->update_ble(main_task_ble);
    ui->widget_task_3->update_usb(main_task_usb);
    ui->widget_task_3->update_ble(main_task_ble);
    signal_pc_sys_get_appcontrolstatus();
    if(hpsetting.isNewBle)
        main_task_headset = hpsetting.hpblesearch.isLinked;
    else
        main_task_headset = hpsetting.hpblesearchold.get_conn_status();
    if(!main_task_ble)
        main_task_headset = false;

    ui->widget_task->update_headset(main_task_headset);
    ui->widget_task_1->update_headset(main_task_headset);
    ui->widget_task_2->update_headset(main_task_headset);
    ui->widget_task_3->update_headset(main_task_headset);
    hpcameracap->voice_enable(main_task_headset);//这里表示如果蓝牙未连接，只有蓝牙打开才能录音

    switch(get_sd_count%5)
    {
    case 0:
        signal_core_get_sdinsert();
        break;
    case 1:
//        signal_pc_measure_get_temp();
//        signal_core_get_usbwifiinsert();
        break;
    case 2:
        signal_core_get_battery_charge();
        break;
    case 3:
  //      sleep(2);
        signal_core_get_usbinsert();              //usb，查看USB状态
        break;
    case 4:
        //        if(!main_task_battery_charge)
        //        {
        signal_core_get_battery();
        //        }
        break;
    default:
        break;

    }

    get_sd_count++;
}

void MainWidget::slot_language_changed_end()
{
//    hpd.show();
//    hp_power_w.show();
    if(manualpara.ManualType == 0)
    {
////        ui->toolButton_max->setText(QString::number(max_value100/100.0,'f',1));
////        ui->toolButton_min->setText(QString::number(min_value100/100.0,'f',1));
//        ui->toolButton_max->setVisible(auto_manual_flag);
//        ui->toolButton_max->setChecked(max_handle_flag);
//        ui->toolButton_min->setVisible(auto_manual_flag);
//        ui->toolButton_min->setChecked(min_handle_flag);
//        int temp_unit;
//        temp_unit = hpsetting.get_temp_unit_state();
//        slot_tempunit_value_changed(temp_unit);
        auto_manual_update();
    }
}

void MainWidget::slot_tempunit_value_changed(int temp_unit)   //切换温度单位
{
    int min_value100_unit, max_value100_unit;
    switch(temp_unit)
    {
    case 0:
        min_value100_unit = min_value100;
        max_value100_unit = max_value100;
        break;
    case 1:
        min_value100_unit = 9*min_value100/5+3200;
        max_value100_unit = 9*max_value100/5+3200;
        break;
    case 2:
        min_value100_unit = min_value100+27315;
        max_value100_unit = max_value100+27315;
        break;
    default:
        min_value100_unit = 0;
        max_value100_unit = 0;
        break;
    }
//    qDebug( )<<"@@@@ "<<max_value100<<min_value100;
//    qDebug( )<<"@@@@ "<<max_value100_unit<<min_value100_unit;
    ui->toolButton_max->setText(QString::number(max_value100_unit/100.0,'f',1));
    ui->toolButton_max->setinded1(QString::number(max_value100_unit/100.0,'f',1),trans_num);

    ui->toolButton_min->setText(QString::number(min_value100_unit/100.0,'f',1));
    ui->toolButton_min->setinded1(QString::number(min_value100_unit/100.0,'f',1),trans_num);
}

void MainWidget::slot_language_changed(int index)
{
    switch(index)
    {
    case 0:
        translator.load("./res/lang_qm/hp_zh_CN.qm");
        qApp->installTranslator(&translator);
        qDebug("mxw language_changed:%d",index);
        break;
    case 1:
        translator.load("./res/lang_qm/hp_zh_TW.qm");
        qApp->installTranslator(&translator);
        qDebug("mxw language_changed:%d",index);
        break;

    case 2:   //english
        translator.load("./res/lang_qm/hp_zh_EN.qm");
        qApp->installTranslator(&translator);
        qDebug("mxw language_changed:%d",index);
        break;

    case 3:  //俄语
        translator.load("./res/lang_qm/hp_zh_RU.qm");
        qApp->installTranslator(&translator);
        qDebug("mxw language_changed:%d",index);
        break;

    case 4:  //匈牙利语
          translator.load("./res/lang_qm/hp_zh_MA.qm");
          qApp->installTranslator(&translator);
          qDebug("mxw language_changed:%d",index);
          break;
    case 5:  //西班牙语
          translator.load("./res/lang_qm/hp_zh_ES.qm");
          qApp->installTranslator(&translator);
          qDebug("mxw language_changed:%d",index);
          break;
    default:
        break;
    }

    signal_core_fpga_get_ver();
}
/*
//2018.2.15
void MainWidget::wifi_enable_switch_int(int switch_value)
{
    wifi_enable_switch = switch_value;
}
*/
//biaoding
void MainWidget::slot_biaoding_ceshi_2()
{
}
//接收内核传过来的信息( zn的消息)
void MainWidget::slot_pc_send_biaoding()
{
    signal_pc_send_biaoding();
    if(!hpsetting.hphide_biaoding.isVisible())
    {
        QTimer::singleShot(500, this, SLOT(slot_pc_send_biaoding()));
    }
}

void MainWidget::slot_get_biaoding()
{
    qDebug() << __func__;
    if(!hpdomainthread->isGetBiaoDingPara)
        signal_pc_send_biaoding();
    else
        timerGetBiaodingPara.stop();
}

void MainWidget::slot_core_biaoding_zn(int para)
{
    if(!m_isInitBiaoding)
    {
        m_isInitBiaoding = true;
        return;
    }
    hpsetting.hphide_biaoding.slot_hphide_biaoding_zn(para);

    if(m_keyORelease)
    {

        m_keyORelease = false;
        hpsetting.hphide_biaoding.show();
    }
}
//tiaoling
void MainWidget::slot_all_tiaoling_2( )
{
    qDebug() << "QT signal_pc_key_auto_rectify" << __func__ <<__LINE__;
    signal_pc_key_auto_rectify();
}

void MainWidget::slot_set_usbmode(int index)
{
    usb_mode = index;
}

void MainWidget::slot_setting_close()
{
    setting_open_state = false;

    if(autocretify_settime >= 60)
    {
        if(!twice_analysis_start)
        {
            qDebug() << "QT signal_pc_key_auto_rectify" << __func__ <<__LINE__;
            signal_pc_key_auto_rectify();
            autocretify_settime = 0;
        }
    }
    if(settingToAutoRecirft->isActive())
    {
        settingToAutoRecirft->stop();
        autocretify_settime = 0;
    }
}
//设置录制视频模式。 avi 或者hir
void MainWidget::slot_avi_hir_mode(int mode)
{
    qDebug() << "MainWidget::slot_avi_hir_mode   Set_Air_Hir_Mode : " << mode;
    avi_hir_mode = mode;
}

void MainWidget::slot_sd_format_start()
{
    sd_format = true;
    QString para;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    if(para !=NULL)
    {
        if(para.toInt() == 0)
        {
            SDFormatDialog->setText(tr("SD卡格式化中"));
        }
        else if(para.toInt() == 1)
        {
            SDFormatDialog->setText(tr("SD卡格式化中"));
        }
        else if(para.toInt() == 2)//english
        {
            SDFormatDialog->setText(tr("SD card formatting"));
        }
        else if(para.toInt() == 3)//俄语
        {
            SDFormatDialog->setText(tr("Im SD-Kartenformat"));
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            SDFormatDialog->setText(tr("SD kártya formátumban"));
        }
        else if(para.toInt() == 5)//西班牙语
        {
            SDFormatDialog->setText(tr("Formato de tarjeta SD"));
        }
    }

    hp_sorts->clearSortList(true);
    SDFormatDialog->show();
}

void MainWidget::slot_sd_format_end(unsigned char return_value)
{
    sd_format = false;
    SDFormatDialog->close();
}


void MainWidget::slot_pc_sys_set_capturetime(int para)
{
    qDebug() << "MainWidget::slot_pc_sys_set_capturetime()" << __LINE__ << para;
    if( para > 7 )
    {
        isAutoSave = true;
        autoSaveShowTimer = para;
        QTimer::singleShot(para * 1000, this, SLOT(slot_show_auto_save()));
        PreviewIconLimit(S_DISABLE);
    }
    else
    {
        autoSaveShowTimer = -1;
        isAutoSave = false;
        PreviewIconLimit(S_NORMAL);
    }
}

void MainWidget::slot_key_auto_start()
{
    auto_state = true;
}

void MainWidget::slot_key_auto_end(unsigned char return_value)
{
    auto_state = false;
}

void MainWidget::slot_set_resize_nZoomRate10_value(int nZoomRate10)
{
    hpresize.ui->slider_resize->setValue(nZoomRate10);
}

void MainWidget::slot_set_nProcessType_value(int nProcessType, int nMaxTempHand100, int nMinTempHand100)
{
    ComManualPara manual_para;
    manual_para.ManualType = nProcessType;
    manual_para.TempHighest = nMaxTempHand100;
    manual_para.TempLowest = nMinTempHand100;
   if(manual_para.ManualType == 1)
    {
        auto_manual_flag = false;
    }else{
       auto_manual_flag = true;
   }

    min_value100 = manual_para.TempLowest;
    max_value100 = manual_para.TempHighest;
    auto_manual_update();
}

void MainWidget::slot_set_twice_hzh_adjust(int x, int y, int w, int h)
{
    pippara.nPIP_X = x;
    pippara.nPIP_Y = y;
    pippara.nPIP_W = w;
    pippara.nPIP_H = h;

}
void MainWidget::slot_show_auto_save()
{
    int temp=0;
    if(hpcameracap->isSuperImage && !hpcameracap->m_isPms && (video_mode != 5))
    {
        if(hpcameracap->m_isZoomSave && hpcameracap->m_isKjg )
            return;
        temp |= e_picture_super_gray;
    }
    if(hpcameracap->m_isZoomSave && hpcameracap->m_isKjg)
        temp = e_picture_resize;
    if(hpcameracap->isGuoWangFlag)
    {
        temp |= e_picture_guowang;
    }
    if(hpcameracap->isSisFlag && hpcameracap->isSisOK && !hpcameracap->Taskmode)//是否扫一扫
    {
        temp |= e_picture_qrcode;
    }
    if(!hpcameracap->pms_xml.isEmpty() && !hpcameracap->pms_filename.isEmpty())//若开启了pms
    {
        return;
    }
    if(m_imageFormat == 1 && !hpcameracap->Taskmode)
        temp |= e_picture_bmp;
    qDebug("Hp_Camera_Cap::on_toolButton_save_released--0X%x--",temp);
    ui->label_autosave->show();
    signal_core_key_capture_start(temp);
    if(isAutoSave && (autoSaveShowTimer != -1))
    {
        QTimer::singleShot(autoSaveShowTimer * 1000, this, SLOT(slot_show_auto_save()));
    }
    QTimer::singleShot(1000, this, SLOT(slot_close_auto_save()));
}

void MainWidget::slot_close_auto_save()
{
    ui->label_autosave->close();
}

//二次分析时图片的左右移动，和两个图标的按钮
void MainWidget::slot_pic_twice_begin()
{
//    if(HP_640_pro ==1)
//    {
//        ui->last_page->close();
//        ui->next_page->close();
//    }else
//    {
//        ui->last_page->show();
//        ui->next_page->show();
//    }
    ui->last_page->show();
    ui->next_page->show();
//    qDebug() << " ((((( Twice ))))) 2.1 ";
}
//两个图标的状态
void MainWidget::slot_pic_twice_type(int last_state, int next_state)
{
    if(0 == last_state)
    {
        ui->last_page->setEnabled(false);
    }else if(1 == last_state)
    {
        ui->last_page->setEnabled(true);
    }else
    {
        ;
    };
    if(0 == next_state)
    {
        ui->next_page->setEnabled(false);
    }else if(1 == next_state)
    {
        ui->next_page->setEnabled(true);
    }else
    {
        ;
    }

}

void MainWidget::on_last_page_released()
{
    slot_update_lcdoff_time(false);

    if(hta->stop_twice_preview)
    {
        return;
    }
    if(isTwiceChangeOver)
        return;
    if(twice_analysis_cut_pic == false)         //防止点击信号和关闭图片的信号不同步。如果点击的太快，会有事件差。
    {
        signal_twice_lastpage();
        if(ui->display->hpdeledit.isVisible())
            ui->display->hpdeledit.close();
        twice_analysis_cut_pic =true;

        isTwiceChangeOver = true;
    }
    if(hta->play_state )
    {
        signal_twice_voicep_Stop();
    }
    if(hta->voice_state)
    {
        signal_twice_voiceStop();
    }
}

void MainWidget::on_next_page_released()
{
    qDebug() << "MainWidget::on_next_page_released";
    slot_update_lcdoff_time(false);

    if(hta->stop_twice_preview)
    {
        return;
    }
    if(isTwiceChangeOver)
        return;
    if(hta->play_state )
    {
        signal_twice_voicep_Stop();
    }
    if(hta->voice_state)
    {
        signal_twice_voiceStop();
    }
    if(twice_analysis_cut_pic == false)
    {
        isTwiceChangeOver = true;
        signal_twice_nextpage();
        twice_analysis_cut_pic =true;
    }
}

void MainWidget::on_focus_near_pressed()            //近焦按压
{
    slot_update_lcdoff_time(false);
    if(con_flag)
        return;
    signal_pc_key_focus_near();
}

void MainWidget::on_focus_near_released()           //近焦松开
{
    slot_update_lcdoff_time(false);
    if(con_flag)
        return;
    signal_pc_key_focus_stop();
}

void MainWidget::on_focus_far_pressed()                 //远焦按压
{
    slot_update_lcdoff_time(false);
    signal_pc_key_focus_far();
}

void MainWidget::on_focus_far_released()                //远焦松开
{
    slot_update_lcdoff_time(false);
    signal_pc_key_focus_stop();
}

void MainWidget::slot_lable_focus_state(bool state)
{
//    qDebug() << "MainWidget::slot_lable_focus_state" <<state;
    if(state == true){
//        ui->label_focus->show();
    }else{
        ui->label_focus->setText("0.0");
        ui->label_focus->close();
        ui->label_focusWarning->close();
    }
}

void MainWidget::KJGModeLimit()
{
    mode_kjg = true;
    ui->display->isVisibleLight=true;
//    if(hpsetting.panoramaFlag)
//    {
//        ui->mode->set_hp_button_status(S_DISABLE);
        ui->point->set_hp_button_status(S_DISABLE);
        ui->line->set_hp_button_status(S_DISABLE);
        ui->rect->set_hp_button_status(S_DISABLE);
//    }
    if( ui->toolButton_AM->isVisible()  && !m_isAimTemp)
    {
        qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
        ui->toolButton_AM->hide();
    }
    if( auto_manual_flag && ui->toolButton_max->isVisible() && ui->toolButton_min->isVisible() )
    {
        ui->toolButton_max->hide();
        ui->toolButton_min->hide();
    }
}

void MainWidget::KJGModeRelieveLimit()
{
    mode_kjg = false;
    ui->display->isVisibleLight=false;
//    ui->point->set_hp_button_status(S_NORMAL);
//    ui->line->set_hp_button_status(S_NORMAL);
//    ui->rect->set_hp_button_status(S_NORMAL);
    if( ui->toolButton_AM->isHidden()  && !m_isAimTemp && video_mode != 5)
    {
        qDebug() << "ui->toolButton_AM->show()" << __LINE__;
        ui->toolButton_AM->show();
    }

    if(video_mode == 5)
    {
        qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
        ui->toolButton_AM->hide();
    }
    if( auto_manual_flag && ui->toolButton_max->isHidden() && ui->toolButton_min->isHidden() )
    {
        ui->toolButton_max->show();
        ui->toolButton_min->show();
    }
    ui->sebiao->set_hp_button_status(S_NORMAL);
    //如果fid_pid模式开启，video_mode等于4  意思就是开启了高灵敏度模式，此时这几个按钮需要隐藏
    if( (video_mode == 4) && fidpid)
    {
        qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
        ui->toolButton_AM->hide();
         ui->toolButton_max->hide();
         ui->toolButton_min->hide();
         ui->toolButton_up->hide();
         ui->toolButton_down->hide();
    }

}

void MainWidget::SlotContinuedFreezeTimer()
{
    if( hpcameracap->isContinuedFreeze )
        signal_pc_key_set_freeze(1);
    else
        ContinuedFreezeTimer->stop();
}

void MainWidget::SlotAutoSave(int SaveValue)
{
    if( SaveValue > 7 )
    {
        isAutoSave = true;
        PreviewIconLimit(S_DISABLE);
    }
    else
    {
        isAutoSave = false;
        PreviewIconLimit(S_NORMAL);
    }
}

void MainWidget::PreviewIconLimit(HP_BUTTON_STATUS status)
{
    ui->preview->set_hp_button_status(status);
    if( isAutoSave || main_task_wifi || main_task_usb ||start_record)
        ui->preview->set_hp_button_status(S_DISABLE);
}

//37 加了如下3个函数
void MainWidget::ModeAMLimit(bool checked)
{
    if(checked)//若选中了
    {
        emit ui->toolButton_AM->clicked(false);
        qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
        ui->toolButton_AM->hide();
    }else
    {
        if(video_mode == 5)
        {
            qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
            ui->toolButton_AM->hide();
        }else
        {
            qDebug() << "ui->toolButton_AM->show()" << __LINE__;
            ui->toolButton_AM->show();
        }
    }
}

void MainWidget::ColorAMLimit(bool checked)
{
    if(checked)//若选中了
    {
        emit ui->toolButton_AM->clicked(false);

        qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
        ui->toolButton_AM->hide();

    }else
    {
        if(video_mode != 1 && !(video_mode == 4 && fidpid))
        {
            if(video_mode == 5)
            {
                qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
                ui->toolButton_AM->hide();
            }
            else
            {
                qDebug() << "ui->toolButton_AM->show()" << __LINE__;
                ui->toolButton_AM->show();
            }
        }
    }
}

void MainWidget::ReciseAMLimit(bool checked)
{
    if(checked)//若选中了
    {
        emit ui->toolButton_AM->clicked(false);

         qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
         ui->toolButton_AM->hide();

    }else
    {
        if(video_mode == 5)
        {
            qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
            ui->toolButton_AM->hide();
        }
        {
            qDebug() << "ui->toolButton_AM->show()" << __LINE__;
            ui->toolButton_AM->show();
        }
    }
}

//延时函数
void MainWidget::delaymsec(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void MainWidget::sltPCKeyLaser()
{
    m_laserRangeTimer = 0;
    signal_pc_sys_set_laserrange();
    delaymsec(100);
    signal_pc_sys_get_laserrange();

    laser_on = false;
}

void MainWidget::getLaserRangeOnce()
{
    m_laserRangeTimer = 0;
    signal_pc_sys_set_laserrange();
    delaymsec(1000);
    signal_pc_sys_get_laserrange();
    laser_on = false;
    if(consercutiveLaser)
    {
        laser_on = false;
    }
    return;
}

void MainWidget::slt_pc_sys_get_laserrange(unsigned char return_value, int value)
{
    if(return_value != RE_OK)
    {
        qDebug() << "slt_pc_sys_get_laserrange" << return_value << value;
    }

    if( m_laserRangeTimer < 2400 && !laser_on)
    {
        m_laserRangeTimer += 600;
        if(value == 0 || ((value & 0x80000000) <= 0))
        {
            delaymsec(500);
            signal_pc_sys_set_laserrange();
            delaymsec(100);
            signal_pc_sys_get_laserrange();
            return;
        }
        else
        {
            delaymsec(400);
            if(!twice_analysis_start)
                value = value & 0x7fffffff;
            m_laserRange = value;
            m_laserRangeTimer = 10000;
        }
    }
    else
    {
        value = 0;
    }
    if(!isLasertype)//若值大于1，则不需要这个0
    {
        signal_pc_sys_set_laser_power(0);
    }
    if(consercutiveLaser)
    {
        value = m_laserRange;
    }

    QString str = QString::number((double)value/1000, 'f',2);
    qDebug() << __func__ << (double)value/1000.0 << hpsetting.ui->comboBox_baojingjuli->value();
    if((double)value/1000.0 > hpsetting.ui->comboBox_baojingjuli->value())
        ui->label_focusWarning->show();
    else
        ui->label_focusWarning->close();
    laser_on = false;
    if(getRangeOnce)
    {
        ui->label_laserRange->setText(str+"m");
        ui->label_laserRange->show();
        timer_5min->start(300000);
    }
    else
    {
        ui->label_focus->setText(str+"m");
        ui->label_focus->show();
    }
    hpsetting.ui->ScrollBar_Distance->setValue(str.toDouble());
    hpsetting.set_ScrollBar_Distance(double(value * 1.0) / 1000);

    qDebug() << value << hphidelaser.isVisible() << laserAdjust;
    if(value >= 10 && !hphidelaser.isVisible() && laserAdjust && (consercutiveLaser && timerConsercutiveLaser->isActive()))
    {
        int x = 480;
        int y = 240;
        if(this->width() == 480)
        {
            x = 384;
            y = 272 / 2;
        }
        int left = ui->display->width() / 2;
        int top = this->height() / 2;
        if(0 != laserParaX.at(0))
        {
            if(video_mode == 1)
            {
                x = laserParaX.at(0) * pow(log(value / 1000.0), 3) + laserParaX.at(1) * pow(log(value / 1000.0), 2) + laserParaX.at(2) * log(value / 1000.0) + laserParaX.at(3);
                y = laserParaY.at(0) * pow(log(value / 1000.0), 3) + laserParaY.at(1) * pow(log(value / 1000.0), 2) + laserParaY.at(2) * log(value / 1000.0) + laserParaY.at(3);
            }
            else
            {
                x = laserParaX_IR.at(0) * pow(log(value / 1000.0), 3) + laserParaX_IR.at(1) * pow(log(value / 1000.0), 2) + laserParaX_IR.at(2) * log(value / 1000.0) + laserParaX_IR.at(3);
                y = laserParaY_IR.at(0) * pow(log(value / 1000.0), 3) + laserParaY_IR.at(1) * pow(log(value / 1000.0), 2) + laserParaY_IR.at(2) * log(value / 1000.0) + laserParaY_IR.at(3);
            }
            ui->widget_laser->move(x + left - 10, top - y - 10);
            if(define_S6X0_S3X0)
            {
                ui->widget_laser->move(x + left - 8, top - y - 8);
            }
        }
        if(video_mode != 3)
            ui->widget_laser->show();
    }

    if(hphidelaser.isVisible() || (consercutiveLaser && timerConsercutiveLaser->isActive()))
    {
        hphidelaser.set_laser_range(value);
        if(!isLasertype)//若值大于1，则不需要这个1
        {
            signal_pc_sys_set_laser_power(1);
        }
        delaymsec(100);
        signal_pc_key_laser(1);
        if((consercutiveLaser && timerConsercutiveLaser->isActive()))
        {
            laser_on = false;
            getLaserRangeOnce();
        }
    }
}

void MainWidget::slot_pc_key_laser(unsigned char value)
{
    qDebug("slot_pc_key_laser return_value:0x%02x",value);
}

void MainWidget::slot_close_laser_widget()
{
    ui->widget_laser->close();
}

void MainWidget::slot_set_twice_text(bool state,QString text)
{
    qDebug("slot set text ************ %s", text.toLocal8Bit().data());
    if(text.length() > 16)
    {
        int line_2 = text.length() - 16;
        QString text_1 = text.left(16);
        QString text_2 = text.right(line_2);
        ui->label->setText(text_1);
        ui->label_2->setText(text_2);
    }
    else
    {
        ui->label->setText(text);
        ui->label_2->setText(" ");
    }
    twice_text_state = state;
    if(state == true)
    {
        ui->label->show();
        ui->label_2->show();
        text_label_show = true;
    }
    else
    {
        ui->label->close();
        ui->label_2->close();
        text_label_show = false;
    }

    if(preview_open == false)
    {
        ui->label->close();
        ui->label_2->close();
        text_label_show = false;
    }
}

void MainWidget::set_twice_text_about_preview()
{
    ui->label->close();
    ui->label_2->close();
    text_label_show = false;
}

void MainWidget::slot_to_set_twice_text(QString text)
{
    if(text.length() > 16)
    {
        int line_2 = text.length() - 16;
        QString text_1 = text.left(16);
        QString text_2 = text.right(line_2);
        ui->label->setText(text_1);
        ui->label_2->setText(text_2);
    }
    else
    {
        ui->label->setText(text);
        ui->label_2->setText(" ");
    }
    qDebug()<<text;
    hppreview->to_set_twice_text_show_or_not();
}

void MainWidget::slot_twice_text_show_or_not(int pic_video)
{
    if(pic_video == 0)
    {
        if(twice_text_state == true)
        {
            ui->label->show();
            ui->label_2->show();
            text_label_show = true;
        }
    }
}
void MainWidget::slot_set_define_Init(bool val)//初始化从配置文件读取内容
{
    if(val)
    {
        fidpid = true;
        hpcameracap->fidpid = true;
        hpmode.fidpid = true;
        hppreview->fidpid = true;
    }else{
        fidpid = false;
        hpcameracap->fidpid = false;
        hpmode.fidpid = false;
        hppreview->fidpid = false;
    }
}

void MainWidget::slot_un_freeze()
{
    signal_pc_key_set_freeze(0);
    start_capture = false;
}

void MainWidget::slot_hotkey_set_key_focus(KEYSETTING hotkey)
{
    m_hotKey1 = hotkey;
    hpxmlreader.writeXml("sys.xml", "HOTKEY", "focus", QString::number(m_hotKey1));
}

void MainWidget::slot_hotkey_set_key_camera(KEYSETTING hotkey)
{
    m_hotKey0 = hotkey;
    hpxmlreader.writeXml("sys.xml", "HOTKEY", "camera", QString::number(m_hotKey0));
}

//照片拍摄模式选择
void MainWidget::slot_temp_row_mode(int mode)
{
    if( mode == 0 )
        hpcameracap->isGuoWangFlag=true;
    else if( mode == 1 )
        hpcameracap->isGuoWangFlag=false;
    hpcameracap->init_cap();
    hpcameracap->setText(tr("冻结成功"));

    hpcameracap->show();
    start_capture = false;
  //  hpcameracap->isContinuedFreeze = true;
    ContinuedFreezeTimer->start();
}
void MainWidget::slot_wait_warn()
{
    wait_warn = true;
}
void MainWidget::slot_wait_warn_save()
{
    if(wait_warn == true)
    {
        hp_wait_w.show();
        wait_warn_state = true;
    }
}

void MainWidget::slot_stop_AviMode(bool checked)
{
    qDebug() << "MainWidget::slot_stop_AviMode" << checked;
    if(checked)
    {
        video_mode = 0;
        hpmode.set_mode(video_mode);
        ui->mode->set_hp_button_status(S_DISABLE);
    }
    else
    {
        wait_warn = false;
        wait_warn_state = false;
        ui->mode->set_hp_button_status(S_NORMAL);
    }
}

void MainWidget::slot_open_panorama(bool isOpen)
{
    if(isOpen && define_brightmode)
    {
        ui->bright_mode->set_hp_button_status(S_DISABLE);
        ui->mode->set_hp_button_status(S_DISABLE);
        ui->setting->set_hp_button_status(S_DISABLE);
        ui->preview->set_hp_button_status(S_DISABLE);
        ui->sebiao->set_hp_button_status(S_DISABLE);
        ui->resize->set_hp_button_status(S_DISABLE);
    }
    else
    {
        ui->bright_mode->set_hp_button_status(S_NORMAL);
        ui->mode->set_hp_button_status(S_NORMAL);
        ui->setting->set_hp_button_status(S_NORMAL);
        ui->preview->set_hp_button_status(S_NORMAL);
        ui->sebiao->set_hp_button_status(S_NORMAL);
        ui->resize->set_hp_button_status(S_NORMAL);
    }
}

void MainWidget::slot_cap_camera_panorama()
{
    //关闭不必要或者会遮挡的窗口
    qDebug() << "MainWidget::slot_cap_camera_panorama()";
    qDebug() << "hp_panorama->isVisible()" << hp_panorama->isVisible() << "panorama_dialog" << panorama_dialog.isVisible();
    if(panorama_dialog.isVisible())
    {
        panorama_dialog.close();
    }
    if(hp_panorama->getDialogVisiable())
    {
        hp_panorama->setDialogVisiable(false);
    }
    if(hpmode.isVisible())
    {
        hpmode.close();
    }
    if(hpresize.isVisible())
    {
        hpresize.close();
    }
    if(hpsebiao.isVisible())
    {
        hpsebiao.close();
    }

    if(!hp_panorama->isVisible() || panorama_quit)//这个负责启动
    {
        panorama_quit = false;
        hpmode.set_mode(0);//设置为红外模式
        signal_pc_image_set_mode(0);
        hpresize.ui->slider_resize->setValue(10);
        video_mode = 0;
        KJGModeRelieveLimit();//按钮禁用情况恢复

        signal_pc_sys_set_panorama_start(1);//开启全景
        hp_panorama->init_panorama();//全景初始化
        ui->display->clear_circle();
        delaymsec(100);
        hp_panorama->show();
        update_main_show(MAIN_AUTORECTIFY);
        return;
    }
    //下面的负责拍照
    qDebug() << "MainWidget::slot_cap_camera_panorama ";
    hp_panorama->stopTimer();
    signal_pc_sys_get_matching_degree(1);
    return;
}

void MainWidget::slot_check_panorama_photo(bool isShot)
{
    //    if(hp_panorama->getMatchDegree() < 30 )
    //    {
    //        hp_panorama->setDialogVisiable(false);
    //        panorama_dialog.setDialogText(hp_panorama->m_fusionDegreeMsg);
    //        panorama_dialog.move((ui->display->width() - hp_Wifi_search_Dialog->width()) / 2 + ui->frame->width(),(ui->display->height() - hp_Wifi_search_Dialog->height()) / 2);
    //        panorama_dialog.show();
    //        return;
    //    }

    int temp = 0;
    temp |= 0x80;
    signal_core_key_capture_start(temp);
}

void MainWidget::slot_cap_camera_stop()
{

    if(hp_panorama->getDialogVisiable())
    {
        hp_panorama->setDialogVisiable(false);
    }
    if(panorama_dialog.isVisible())
    {
        signal_pc_key_set_freeze(0);
        panorama_dialog.close();
        return;
    }
    qDebug() << "MainWidget::slot_cap_camera_stop() __Line__" << __LINE__;
}

void MainWidget::set_audio(bool flag, int type)
{
    qDebug() << "MainWidget::set_audio" << hpsetting.hpblesearchold.get_conn_status() << hpsetting.hpblesearch.isLinked << flag << type;
    if(hpsetting.hpblesearchold.get_conn_status() || hpsetting.hpblesearch.isLinked)
    {
        if(flag)
        {
            unsigned char res;
            res = 0;
            hpcameracap->slot_pc_sys_set_analog_video(res);
            return;
        }
    }
    else
    {

    }
}

void MainWidget::slot_close_panorama(bool setPanoramaStop)
{
    qDebug() << "MainWidget::slot_close_panorama" << panorama_quit;
    if(hp_panorama->getDialogVisiable())
    {
        hp_panorama->setDialogVisiable(false);
    }
    if(hp_panorama->isVisible() || !panorama_quit)
    {
        qDebug() << "MainWidget::slot_close_panorama" << __LINE__;
        panorama_quit = true;
        hp_panorama->over_panorama();

//        slot_noncool_unenable_plr(false);
        hp_panorama->close();
        if(!setPanoramaStop)
        {
            int temp=0;
            temp |= 0x20;
            signal_pc_sys_set_panorama_stop(0);
        }
        ui->mode->set_hp_button_status(S_NORMAL);
        ui->resize->set_hp_button_status(S_NORMAL);
        m_panorama_cap = false;
        start_capture = false;

        update_main_show(MAIN_RESIZE);
        return;
    }
}

void MainWidget::slot_start_panorama()
{

}

void MainWidget::slot_pc_sys_set_panorama_stop(unsigned char isSave, QString name)
{
    qDebug() << __func__ << isSave << name;
    if(name.contains(".jpgpg"))
    {
        name = name.split(".jpg").at(0) + ".jpg";
    }
    qDebug() << __func__ << isSave << name;
    if(RE_OK == isSave && hp_panorama->isSavePanorama)
    {
        hp_panorama->isSavePanorama = false;
        name = "/run/media/mmcblk2p1/DCIM/" + name;
        signal_sort_add_new_file(name);
    }
    else if(RE_OK == isSave && !hp_panorama->isSavePanorama)
    {
        QString path = "rm /run/media/mmcblk2p1/DCIM/" + name;
        system(path.toUtf8());
        system("sync");
    }
}


void MainWidget::slot_panorama_set_unsave(QString name)
{
    QString path = "/run/media/mmcblk2p1/DCIM/" + name;
    QString cmd = "rm " + path;
    qDebug() << __func__ << cmd;
    system(cmd.toUtf8());
    system("sync");
    hp_sorts->removeFile("/run/media/mmcblk2p1/DCIM/" + name);
}

void MainWidget::SlotSetImageSR(bool state)
{

}

void MainWidget::slot_set_compass_trans(int index)
{
    ui->compass->settrans(index);
}

void MainWidget::slot_timer_get_rotation_type()
{
    if(rot_type_state  == true)
    {
        signal_core_get_rotation_type();
    }
    else
    {
        timer_get_rotation_type.stop();
    }
}

void MainWidget::slot_core_get_rodation_type(unsigned char return_value, int ti)         //获取当前仪器选转方向
{
    //以下旋转目前好像没用到
    if(return_value == RE_OK)
    {
         if(ti==0)
         {
             trans_num=0;
            ui->frame_task->show();
            ui->frame_task_2->close();
            ui->frame_task_3->close();
            ui->frame_task_4->close();
            ui->frame_task->setGeometry(359,0,280,28);
            ui->compass->move(ui->frame->width() + 40, 350);
            ui->frame_tool->setGeometry(500, 32, 140,421);
            ui->toolButton_AM->setGeometry(85,10,30,30);
            ui->toolButton_max->setGeometry(70, 50, 66, 35);
            ui->toolButton_min->setGeometry(70, 375, 66, 35);
            ui->toolButton_up->setGeometry(0, 158, 66, 66);
            ui->toolButton_down->setGeometry(0, 247, 66, 66);
           ui->toolButton_AM-> setStyleSheet(ToolButtonAM);
           ui->toolButton_up-> setStyleSheet(ToolButtonUP);
           ui->toolButton_down-> setStyleSheet(ToolButtonDown);
            auto_manual_update();
         }else if(ti ==1)
         {
             trans_num=1;
             ui->frame_task->close();
             ui->frame_task_2->close();
             ui->frame_task_3->show();
             ui->frame_task_4->close();
             ui->compass->move(ui->frame->x() + 800 - 40 - ui->compass->width(), 350);
             ui->frame_tool->setGeometry(30, 0, 581, 140);
             ui->toolButton_AM->setGeometry(10, 10, 30, 30);
             ui->toolButton_max->setGeometry(50, 10, 35, 66);
             ui->toolButton_min->setGeometry(510, 10, 35, 66);
             ui->toolButton_up->setGeometry(170, 70, 66, 66);
             ui->toolButton_down->setGeometry(370, 70, 66, 66);

             ui->toolButton_AM-> setStyleSheet(ToolButtonAM_3);
             ui->toolButton_up-> setStyleSheet(ToolButtonUP_3);
             ui->toolButton_down-> setStyleSheet(ToolButtonDown_3);
             auto_manual_update();
         }else if(ti==2)
         {
             trans_num=2;
             ui->frame_task->close();
             ui->frame_task_2->show();
             ui->frame_task_3->close();
             ui->frame_task_4->close();
             ui->toolButton_AM->setGeometry(37,410,30,30);
             ui->compass->move(760 - ui->compass->width(), 50);
             ui->frame_tool->setGeometry(0, 30, 140, 421);
             ui->toolButton_AM->setGeometry(0, 380, 30, 30);
             ui->toolButton_max->setGeometry(5, 340, 66, 35);
             ui->toolButton_min->setGeometry(5, 10, 66, 35);
             ui->toolButton_up->setGeometry(75, 230, 66, 66);
             ui->toolButton_down->setGeometry(75, 130, 66, 66);
             ui->toolButton_AM-> setStyleSheet(ToolButtonAM_2);
             ui->toolButton_up-> setStyleSheet(ToolButtonUP_2);
             ui->toolButton_down-> setStyleSheet(ToolButtonDown_2);
             auto_manual_update();
         }else if(ti==3)
         {
             trans_num=3;
             ui->frame_task->close();
             ui->frame_task_2->close();
             ui->frame_task_3->close();
             ui->frame_task_4->show();
             ui->compass->move(ui->frame->width() + 40, 50);
             ui->toolButton_AM->setGeometry(545,420,30,30);
             ui->toolButton_max->setGeometry(510,395,34,80);
             ui->toolButton_min->setGeometry(45,395,34,80);
             ui->toolButton_up->setGeometry(310,320,66,66);
             ui->toolButton_down->setGeometry(220,320,66,66);
             ui->frame_tool->setGeometry(20, 340, 581, 140);
             ui->toolButton_AM->setGeometry(540, 90, 30, 30);
             ui->toolButton_max->setGeometry(490, 70, 35, 66);
             ui->toolButton_min->setGeometry(30, 70, 35, 66);
             ui->toolButton_up->setGeometry(390, 10, 66, 66);
             ui->toolButton_down->setGeometry(180, 10, 66, 66);

             ui->toolButton_AM-> setStyleSheet(ToolButtonAM_4);
             ui->toolButton_up-> setStyleSheet(ToolButtonUP_4);
             ui->toolButton_down-> setStyleSheet(ToolButtonDown_4);
             auto_manual_update();
         }else
         {
             qDebug()<<"slot_core_get_rodation_type      error";
         }
    }
}

void MainWidget::slot_timer_get_positiion_switch(int para)
{
    qDebug() << "MainWidget::slot_timer_get_positiion_switch" << para;
    if(para ==1)
    {
        ui->compass->show();
        compass_state = true;
        timer_compass.start(300);
    }
    else
    {
        ui->compass->close();
        compass_state= false;
        timer_compass.stop();
    }
    qDebug() << ui->compass->isVisible() << ui->compass->x() << ui->compass->y() << compass_state;
}

void MainWidget::slot_timer_get_rotation_switch(int index)
{
    //以下旋转目前好像没用到
    if(index == 1)
    {
        rot_type_state = true;
        timer_get_rotation_type.start(300);
    }
    else
    {
        rot_type_state= false;
        timer_get_rotation_type.stop();
        trans_num=0;
        ui->frame_task->show();
        ui->frame_task_2->close();
        ui->frame_task_3->close();
        ui->frame_task_4->close();
        ui->frame_task->setGeometry(359,0,280,28);
        ui->frame_tool->setGeometry(500, 32, 140,421);
        ui->toolButton_AM->setGeometry(85,10,30,30);
        ui->toolButton_max->setGeometry(70, 50, 66, 35);
        ui->toolButton_min->setGeometry(70, 375, 66, 35);
        ui->toolButton_up->setGeometry(0, 158, 66, 66);
        ui->toolButton_down->setGeometry(0, 247, 66, 66);
        ui->toolButton_AM-> setStyleSheet(ToolButtonAM);
        ui->toolButton_up-> setStyleSheet(ToolButtonUP);
        ui->toolButton_down-> setStyleSheet(ToolButtonDown);
        auto_manual_update();
    }
}

void MainWidget::slot_timer_get_compass_data()
{
    if(compass_state  == true)
    {
        signal_pc_sys_get_positiion_data();
    }
    else
    {
        timer_compass.stop();
    }
}

void MainWidget::slot_pc_sys_get_positiion_data(unsigned char return_value, int value)
{
    if(return_value == RE_OK)
    {
        ui->compass->setinded1(value + 90);
     //   qDebug()<<"tttttttttttttttttttttttttttttttttttttttt" <<value;
    }
}

void MainWidget::slot_noncool_unenable_plr(bool isAimTemp)
{
    m_isAimTemp = isAimTemp;
    if(isAimTemp)
    {
        OsdSetting osdNew = hpsetting.getOsdSetting();
        osdNew.color_ruler = 0;
        ui->toolButton_AM->close();
        auto_manual_flag = false;
        signal_pc_osd_set_osdstat(osdNew);
        on_clean_clicked(S_NORMAL);
        ui->point->set_hp_button_status(S_DISABLE);
        ui->line->set_hp_button_status(S_DISABLE);
        ui->rect->set_hp_button_status(S_DISABLE);
        ui->clean->set_hp_button_status(S_DISABLE);
        if(ui->toolButton_max->isVisible() || ui->toolButton_min->isVisible() )
        {
            ui->toolButton_max->hide();
            ui->toolButton_min->hide();
        }
    }
    else
    {
        if( !ui->toolButton_AM->isVisible())
        {
            qDebug() << "ui->toolButton_AM->show()" << __LINE__;
            ui->toolButton_AM->show();
        }
        if(video_mode == 5)
        {
            qDebug() << "ui->toolButton_AM->hide()" << __LINE__;
            ui->toolButton_AM->hide();
        }
        OsdSetting osdNew = hpsetting.getOsdSetting();
        osdNew.color_ruler = 1;
        signal_pc_osd_set_osdstat(osdNew);
        update_main_show(MAIN_MODE);
    }
}

void MainWidget::slot_show_gps_pixel(int para)
{
    if(para == 1)
    {
        ui->widget_task->update_auto_focus(true);
        ui->widget_task_1->update_auto_focus(true);
        ui->widget_task_2->update_auto_focus(true);
        ui->widget_task_3->update_auto_focus(true);
    }
    if(para == 0)
    {
        ui->widget_task->update_auto_focus(false);
        ui->widget_task_1->update_auto_focus(false);
        ui->widget_task_2->update_auto_focus(false);
        ui->widget_task_3->update_auto_focus(false);
    }
}

void MainWidget::slot_show_4G_pixel(int para)
{
    if(para == 1)
    {
        main_task_wifi = false;
        ui->widget_task->update_4g(true);
        ui->widget_task_1->update_4G(true);
        ui->widget_task_2->update_4G(true);
        ui->widget_task_3->update_4G(true);
    }
    if(para == 0)
    {
        ui->widget_task->update_4g(false);
        ui->widget_task_1->update_4G(false);
        ui->widget_task_2->update_4G(false);
        ui->widget_task_3->update_4G(false);
    }
}

void MainWidget::slot_tagTempAlarm_timeout()
{
    if(isShowAlarm < 3)
        isShowAlarm++;
    else
        isShowAlarm = 0;
    if(isShowAlarm == 0)
    {
        ui->label_alarm->close();
    }
    else
    {
        if(video_mode == 4)
            ui->label_alarm->show();
    }
}

void MainWidget::slot_get_tagRectTemp_timeout()
{
    if(!hpsetting.tempWengdangchange)//若不处于自动调整温档状态
    {
//        qDebug() << "MainWidget::slot_get_tagRectTemp_timeout()";
        signal_pc_get_measure_get_temp();
    }
}

void MainWidget::slot_set_show_avgTemp(bool isShow)
{
    m_isShowAvg = isShow;
    if(m_isShowAvg)
    {
        if(!get_tagRectTemp->isActive())
        {
            get_tagRectTemp->start();
            ui->label_tempAvg->show();
        }
    }
    else
    {
        if(get_tagRectTemp->isActive() && video_mode != 4)
        {
            get_tagRectTemp->stop();
        }
        ui->label_tempAvg->close();
    }
}

void MainWidget::slot_set_auto_reflect(bool isShow)
{
    if(isShow)
    {
        if(!get_tagRectTemp->isActive())
        {
            get_tagRectTemp->start();
        }
    }
    else
    {
        if(get_tagRectTemp->isActive())
        {
            get_tagRectTemp->stop();
        }
    }
}

void MainWidget::slot_pc_get_measure_get_temp(unsigned char return_value,RectTemp temp)
{
    if(m_isAutoReflect)
    {
        qDebug() << hpsetting.m_reflectType;
        if(hpsetting.m_reflectType == 0)
        {
            signal_measure_reflect_temp(temp.nMaxTemp100);
        }
        else if(hpsetting.m_reflectType == 1)
        {
            signal_measure_reflect_temp(temp.nMinTemp100);
        }
        else if(hpsetting.m_reflectType == 2)
        {
            signal_measure_reflect_temp(temp.nAvgTemp100);
        }
        return;
    }
    double maxTemp = (double)temp.nMaxTemp100 / 100.0;
    double minTemp = (double)temp.nMinTemp100 / 100.0;
    double aveTemp = (double)temp.nAvgTemp100 / 100.0;
    int alarmType = fusionpara.nFusionType;
    double alarmAvgMax = (double)fusionpara.nFusionAmongHighTemp100 / 100.0;
    double alarmAvgMin = (double)fusionpara.nFusionAmongLowTemp100 / 100.0;
    double alarmMax    = (double)fusionpara.nFusionAboveTemp100 / 100.0;
    double alarmMin    = (double)fusionpara.nFusionBelowTemp100 / 100.0;
    if(m_isShowAvg && (video_mode != 1))
    {
        ui->label_tempAvg->setText("ave:" + QString::number(aveTemp, 'f', 1) + "℃");
        ui->label_tempAvg->show();
    }
    else
    {
        ui->label_tempAvg->close();
    }
    if(alarmType == 0)
    {
        if(aveTemp < alarmAvgMax && alarmAvgMin < aveTemp && video_mode == 4)
        {
            ui->label_alarm->setText(tr("温度:") + QString::number(aveTemp, 'f', 1) + tr("℃报警"));
            tagTempAlarm->start();
        }
        else
        {
            ui->label_alarm->close();
            if(tagTempAlarm->isActive())
                tagTempAlarm->stop();
        }
    }
    if(alarmType == 1 )
    {
        if(maxTemp > alarmMax && video_mode == 4)
        {
            ui->label_alarm->setText(tr("温度:") + QString::number(maxTemp, 'f', 1) + "℃" + ">" + QString::number(alarmMax, 'f', 1) + tr("℃报警"));
            tagTempAlarm->start();
        }
        else
        {
            ui->label_alarm->close();
            if(tagTempAlarm->isActive())
                tagTempAlarm->stop();
        }
    }
    if(alarmType == 2)
    {
        if(minTemp < alarmMin && video_mode == 4)
        {
            ui->label_alarm->setText(tr("温度:") + QString::number(minTemp, 'f', 1) + "℃" + "<" + QString::number(alarmMin, 'f', 1) + tr("℃报警"));
            tagTempAlarm->start();
        }
        else
        {
            ui->label_alarm->close();
            if(tagTempAlarm->isActive())
                tagTempAlarm->stop();
        }
    }
}

void MainWidget::slot_set_twice_change_over()
{
    isTwiceChangeOver = false;
}

//void MainWidget::slot_clear_res_video_picture()
//{
//    QDir dir;
//    QStringList filters;
//    filters.append(QString("*.jpg"));
//    QStringList filters;
//    filters.append(QString("*.jpg"));
//    hp_sorts->getSortFileList();
//}

void MainWidget::on_checkBox_polygon_clicked(bool checked)
{
    qDebug() << __func__ << checked;
    ui->display->m_isPolygonDraw = checked;
    if(checked)
    {
        ui->point->set_hp_button_status(S_DISABLE);
        ui->line->set_hp_button_status(S_DISABLE);
        ui->rect->set_hp_button_status(S_DISABLE);
        ui->circle->set_hp_button_status(S_DISABLE);
        ui->polygon->set_hp_button_status(S_DISABLE);
        ui->clean->set_hp_button_status(S_DISABLE);
        ui->preview->set_hp_button_status(S_DISABLE);
        ui->setting->set_hp_button_status(S_DISABLE);
        ui->resize->set_hp_button_status(S_DISABLE);
        ui->sebiao->set_hp_button_status(S_DISABLE);
        ui->bright_mode->set_hp_button_status(S_DISABLE);
    }
    else
    {
        ui->point->set_hp_button_status(S_NORMAL);
        ui->line->set_hp_button_status(S_NORMAL);
        ui->rect->set_hp_button_status(S_NORMAL);
        ui->circle->set_hp_button_status(S_NORMAL);
        ui->polygon->set_hp_button_status(S_NORMAL);
        ui->clean->set_hp_button_status(S_NORMAL);
        ui->preview->set_hp_button_status(S_NORMAL);
        ui->setting->set_hp_button_status(S_NORMAL);
        ui->resize->set_hp_button_status(S_NORMAL);
        ui->sebiao->set_hp_button_status(S_NORMAL);
        ui->bright_mode->set_hp_button_status(S_NORMAL);
        ui->display->commit_current_polygon(false);
    }
    return;
}

void MainWidget::on_pushButton_confirm_clicked()
{
    ui->display->commit_current_polygon(true);
    ui->checkBox_polygon->setChecked(false);
    on_checkBox_polygon_clicked(false);
    ui->display->m_isPolygonDraw = false;
}


void MainWidget::slot_signal_sketch_switch(int index)
{
    if(index ==1)
    {
        ui->display->sketch_state= true;
    }
    else
    {
       ui->display->sketch_state= false;
    }
}

void MainWidget::slot_set_image_format(int imageFormat)
{
    m_imageFormat = imageFormat;
    hpcameracap->setImageFormat(imageFormat);
}

void MainWidget::setInsulation(bool isInsulation)
{
    if(isInsulation)
    {
        ui->display->setInsulation(true);
    }
}

void MainWidget::slot_show_insulation_warning(bool isShow, int id, int x, int y)
{
    if(id == -1)
    {
        ui->label_insulation->close();
        ui->label_insulation_2->close();
        ui->label_insulation_3->close();
        ui->label_insulation_4->close();
        ui->label_insulation_5->close();
        ui->label_insulation_6->close();
        ui->label_insulation_7->close();
        ui->label_insulation_8->close();
        ui->label_insulation_9->close();
        ui->label_insulation_10->close();
        ui->label_insulation_11->close();
        return;
    }
    if(id > 10 || id < 0)
        return;
    qDebug() << __func__ << "id" << id << x << y;
    QLabel *nowLabel = ui->label_insulation;
    switch(id)
    {
    case 0:
        nowLabel = ui->label_insulation;
        break;
    case 1:
        nowLabel = ui->label_insulation_2;
        break;
    case 2:
        nowLabel = ui->label_insulation_3;
        break;
    case 3:
        nowLabel = ui->label_insulation_4;
        break;
    case 4:
        nowLabel = ui->label_insulation_5;
        break;
    case 5:
        nowLabel = ui->label_insulation_6;
        break;
    case 6:
        nowLabel = ui->label_insulation_7;
        break;
    case 7:
        nowLabel = ui->label_insulation_8;
        break;
    case 8:
        nowLabel = ui->label_insulation_9;
        break;
    case 9:
        nowLabel = ui->label_insulation_10;
        break;
    case 10:
        nowLabel = ui->label_insulation_11;
        break;
    }
    nowLabel->move(x, y);
    if(isShow)
    {
        nowLabel->show();
        nowLabel->raise();
    }
    else
    {
        nowLabel->close();
    }
}
void MainWidget::show_lens_info()
{
    qDebug() << "ui->listWidget_jingtou->count()" << ui->listWidget_jingtou->count() << __func__ << __LINE__;
    if(ui->listWidget_jingtou->count() != 0)
    {
        return;
    }
    qDebug() << "m_lensCount" << m_lensCount << __func__ << __LINE__;
    m_lensCount = hpsetting.getLensCount();
    qDebug() << "m_lensCount" << m_lensCount << __func__ << __LINE__;
    for(int i = 0 ; i < m_lensCount; i++)
    {
        QString lenName = hpsetting.ui->listWidget_jingtou->item(i)->text();
        QListWidgetItem *listWidgetItem = new QListWidgetItem;
        listWidgetItem->setText(lenName);
        ui->listWidget_jingtou->addItem(listWidgetItem);
    }
    qDebug() << "m_lensCount" << m_lensCount << __func__ << __LINE__;
    ui->listWidget_jingtou->resize(243, 35 * m_lensCount);
    ui->listWidget_jingtou->move((ui->display->width() - ui->listWidget_jingtou->width()) / 2, 100);
    ui->listWidget_jingtou->setCurrentRow(0);
    qDebug() << "ui->listWidget_jingtou->count()" << ui->listWidget_jingtou->count() << __func__ << __LINE__;
}

void MainWidget::slot_timerout_jingtou_change()
{
    qDebug() << "MainWidget::slot_timerout_jingtou_change()" << m_currLens;
    if(m_currLens < m_lensCount - 1)
    {
        m_currLens++;
    }
    else
    {
        m_currLens = 0;
    }
    ui->listWidget_jingtou->item(m_currLens)->setSelected(true);
}
void MainWidget::slot_double_clicked_focus()
{
    if(con_flag)
        return;
    if(hpsetting.fastfocusmode)//只有在普通模式下才进行激光测距
    {
        if(!isLasertype)
        {
            signal_pc_sys_set_laser_power(1);
        }
        delaymsec(100);
    }
    signal_pc_key_auto_focus();
}

void MainWidget::slot_transmission_send_upload_success()
{
    if(hp_Wifi_search_Dialog->isVisible())
        hp_Wifi_search_Dialog->close();
    update();
    hp_Wifi_search_Dialog->Set_label_text(hpcameracap->UploadOK);
    hp_Wifi_search_Dialog->SetHideButton(false);
    hp_Wifi_search_Dialog->setDelayClose(3000);
    hp_Wifi_search_Dialog->show();
}


void MainWidget::slot_set_focus()
{
    if(con_flag)
        return;
    if(hpsetting.fastfocusmode || fidpid)
    {
        if( define_brightmode || fidpid)
        {
            if(laser_init == false)
            {
                initLaser();
            }
            if( laser_on)
            {
                signal_pc_key_laser(0);
                delaymsec(100);
                if(!isLasertype)//若值大于1，则不需要这个0
                {
                    signal_pc_sys_set_laser_power(0);
                }
                ui->widget_laser->setVisible(false);
                delaymsec(100);
            }
            if(hpsetting.fastfocusmode)
                signal_pc_sys_set_laser_power(1);
            delaymsec(100);
            if(!fidpid)
            {
                signal_pc_key_auto_focus();
            }
            else
            {
                unsigned char res;
                res = 0;
                slot_pc_key_auto_focus(res);
            }
        }
    }
    else
    {
        if(define_brightmode)
        {
            if(!fidpid)
            {
                signal_pc_key_auto_focus();
            }
            else
            {
                unsigned char res;
                res = 0;
                slot_pc_key_auto_focus(res);
            }
        }
    }
}

void MainWidget::slot_set_preset_mode(int presetMode)
{
    ui->display->clear_measure();
    ui->display->slot_set_preset_mode(presetMode);
}

void MainWidget::slot_stop_focus_aut(bool checked)
{
    con_flag = checked;
}
