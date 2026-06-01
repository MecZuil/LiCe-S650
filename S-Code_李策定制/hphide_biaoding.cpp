#include  "hphide_biaoding.h"
#include  "ui_hphide_biaoding.h"
#include     <QDebug>
#include     <QKeyEvent>
#include     <QTime>
#include  <QtCore>
//#include  <time.h>

HpHide_Biaoding::HpHide_Biaoding(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HpHide_Biaoding)
{
    ui->setupUi(this);

    //设置各部件初始值
//    ui->label_inB->setText("B");
 //   ui->label_inmax->setText("max");
//    ui->label_inmin->setText("min");

    ui->spinBox_vs->setValue(100);
    ui->spinBox_vf->setValue(100);
    ui->spinBox_tnt->setValue(100);
    ui->spinBox_gain->setValue(100);

    ui->spinBox_facus->setMinimum(0);
    ui->spinBox_facus->setMaximum(255);

    ui->label_DDE->close();
    ui->checkBox_DDE->close();

    hp_hide_dialog = new Hphide_Dialog(this);
    hp_hide_dialog->close();

    hp_hide_dialog_lo = new Hphide_Dialog_LO(this);
    hp_hide_dialog_lo->close();

    hp_hide_dialog_save = new Hphide_Dialog_SAVE(this);
    hp_hide_dialog_save->close();


    connect(ui->checkBox_Sensibility,SIGNAL(clicked(bool)),this,SLOT(on_checkBox_Sensibility_click(bool)));
    connect(ui->spinBox_SensibilityGain,SIGNAL(valueChanged(int)),this,SLOT(on_spinBox_SensibilityGain_value_change(int)));
    connect(ui->spinBox_SensibilityRange,SIGNAL(valueChanged(int)),this,SLOT(on_spinBox_SensibilityRange_value_change(int)));
    define_S6X0_S3X0 = false;
    focusmode = 0;
    if(HP_640_pro == 1)
    {
        define_S6X0_S3X0 = true;
    }
    isStructSave = false;
//    QTimer *timer;
   timer = new QTimer(this);
    connect(timer,SIGNAL(timeout( )), this, SLOT(handleTimeout ( )));

    connect(ui->checkBox_DDE,SIGNAL(clicked(bool)),this,SLOT(hp_slot_DDE_checked(bool)));
    connect(ui->Button_save_focus,SIGNAL(pressed()),this,SLOT(hp_saveFocus()));
    connect(ui->spinBox_Para,SIGNAL(valueChanged(int)),this,SLOT(slot_spinBox_Para_valueChanged(int)));
    connect(ui->spinBox_Zoom,SIGNAL(valueChanged(int)),this,SLOT(slot_spinBox_Zoom_valueChanged(int)));
}

HpHide_Biaoding::~HpHide_Biaoding()
{
    delete ui;
}
void HpHide_Biaoding::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);

        this->resize(480,272);

        ui->scrollArea->setGeometry(0,0,480,ui->scrollArea->height());
        ui->frame->setGeometry(0,0,ui->frame->width() / 1.7,ui->frame->height() / 1.7);
        ui->Button_HI->setGeometry(280,30,75,23);
        ui->Button_LO->setGeometry(280,70,75,23);
        ui->Button_save->setGeometry(280,110,75,23);
        ui->Button_set->setGeometry(280,150,75,23);
        ui->Button_cancel->setGeometry(280,190,75,23);
        ui->label_B->setGeometry   (10,220,30,25);
        ui->label_Gain->setGeometry(10,100,30,25);
        ui->label_INT->setGeometry (10,130,30,25);
        ui->label_Max->setGeometry (10,160,30,25);
        ui->label_Min->setGeometry (10,190,30,25);
        ui->label_VF->setGeometry  (10,70, 30,25);
        ui->label_VS->setGeometry  (10,40, 30,25);
        ui->label_ZN->setGeometry  (10,10, 30,25);
        ui->spinBox_b->setGeometry   (50,220,120,25);
        ui->spinBox_gain->setGeometry(50,100,120,25);
        ui->spinBox_max->setGeometry (50,160,120,25);
        ui->spinBox_min->setGeometry (50,190,120,25);
        ui->spinBox_tnt->setGeometry (50,130,120,25);
        ui->spinBox_vf->setGeometry  (50,70, 120,25);
        ui->spinBox_vs->setGeometry  (50,40, 120,25);
        ui->spinBox_zn->setGeometry  (50,10, 120,25);

        ui->label_INTCP->setGeometry (175,10 ,40,25);
        ui->label_ADGAIN->setGeometry(175,40 ,40,25);
        ui->label_SVRD->setGeometry  (175,70 ,40,25);
        ui->label_FOS->setGeometry   (175,100,40,25);
        ui->label_OCC->setGeometry   (175,130,40,25);
        ui->spinBox_intcp->setGeometry (220,10 ,120,25);
        ui->spinBox_adgain->setGeometry(220,40 ,120,25);
        ui->spinBox_svrd->setGeometry  (220,70 ,120,25);
        ui->spinBox_fos->setGeometry   (220,100,120,25);
        ui->checkBox_OCC->setGeometry  (220,130,40,25);

        ui->Button_HI->setGeometry    (350,30, 75,23);
        ui->Button_LO->setGeometry    (350,70, 75,23);
        ui->Button_save->setGeometry  (350,110,75,23);
        ui->Button_set->setGeometry   (350,150,75,23);
        ui->Button_cancel->setGeometry(350,190,75,23);

        ui->label_Para->setGeometry(ui->label_Para->x() / 1.7,ui->label_Para->y() / 1.7,ui->label_Para->width() / 1.7,ui->label_Para->height() / 1.7);
        ui->spinBox_Para->setGeometry(ui->spinBox_Para->x() / 1.7,ui->spinBox_Para->y() / 1.7,ui->spinBox_Para->width() / 1.7,ui->spinBox_Para->height() / 1.7);
        ui->label_Zoom->setGeometry(ui->label_Zoom->x() / 1.7,ui->label_Zoom->y() / 1.7,ui->label_Zoom->width() / 1.7,ui->label_Zoom->height() / 1.7);
        ui->spinBox_Zoom->setGeometry(ui->spinBox_Zoom->x() / 1.7,ui->spinBox_Zoom->y() / 1.7,ui->spinBox_Zoom->width() / 1.7,ui->spinBox_Zoom->height() / 1.7);

        ui->label_3DHDFF->setGeometry(ui->label_3DHDFF->x() / 1.7,ui->label_3DHDFF->y() / 1.7,ui->label_3DHDFF->width() / 1.7,ui->label_3DHDFF->height() / 1.7);
        ui->spinBox_3DHDFF->setGeometry(ui->spinBox_3DHDFF->x() / 1.7,ui->spinBox_3DHDFF->y() / 1.7,ui->spinBox_3DHDFF->width() / 1.7,ui->spinBox_3DHDFF->height() / 1.7);
        ui->label_3DSD->setGeometry(ui->label_3DSD->x() / 1.7,ui->label_3DSD->y() / 1.7,ui->label_3DSD->width() / 1.7,ui->label_3DSD->height() / 1.7);
        ui->spinBox_3DSD->setGeometry(ui->spinBox_3DSD->x() / 1.7,ui->spinBox_3DSD->y() / 1.7,ui->spinBox_3DSD->width() / 1.7,ui->spinBox_3DSD->height() / 1.7);

        ui->label_B_2->setGeometry(ui->label_B_2->x() / 1.7,ui->label_B_2->y() / 1.7,ui->label_B_2->width() / 1.7,ui->label_B_2->height() / 1.7);
        ui->spinBox_facus->setGeometry(ui->spinBox_facus->x() / 1.7,ui->spinBox_facus->y() / 1.7,ui->spinBox_facus->width() / 1.7,ui->spinBox_facus->height() / 1.7);
        ui->label_B_5->setGeometry(ui->label_B_5->x() / 1.7,ui->label_B_5->y() / 1.7,ui->label_B_5->width() / 1.7,ui->label_B_5->height() / 1.7);
        ui->spinBox_facus_2->setGeometry(ui->spinBox_facus_2->x() / 1.7,ui->spinBox_facus_2->y() / 1.7,ui->spinBox_facus_2->width() / 1.7,ui->spinBox_facus_2->height() / 1.7);
        ui->label_B_6->setGeometry(ui->label_B_6->x() / 1.7,ui->label_B_6->y() / 1.7,ui->label_B_6->width() / 1.7,ui->label_B_6->height() / 1.7);
        ui->spinBox_facus_3->setGeometry(ui->spinBox_facus_3->x() / 1.7,ui->spinBox_facus_3->y() / 1.7,ui->spinBox_facus_3->width() / 1.7,ui->spinBox_facus_3->height() / 1.7);
        ui->Button_save_focus->setGeometry(ui->Button_save_focus->x() / 1.7,ui->Button_save_focus->y() / 1.7,ui->Button_save_focus->width() / 1.7,ui->Button_save_focus->height() / 1.7);
        ui->label_oritoggle->setGeometry(ui->label_oritoggle->x() / 1.7,ui->label_oritoggle->y() / 1.7,ui->label_oritoggle->width() / 1.7,ui->label_oritoggle->height() / 1.7);
        ui->Button_oritoggle_0->setGeometry(ui->Button_oritoggle_0->x() / 1.7,ui->Button_oritoggle_0->y() / 1.7,ui->Button_oritoggle_0->width() / 1.7,ui->Button_oritoggle_0->height() / 1.7);
        ui->Button_oritoggle_1->setGeometry(ui->Button_oritoggle_1->x() / 1.7,ui->Button_oritoggle_1->y() / 1.7,ui->Button_oritoggle_1->width() / 1.7,ui->Button_oritoggle_1->height() / 1.7);
        ui->label_auto_badpixel->setGeometry(ui->label_auto_badpixel->x() / 1.7,ui->label_auto_badpixel->y() / 1.7,ui->label_auto_badpixel->width() / 1.7,ui->label_auto_badpixel->height() / 1.7);
        ui->spinBox_auto_badpixel->setGeometry(ui->spinBox_auto_badpixel->x() / 1.7,ui->spinBox_auto_badpixel->y() / 1.7,ui->spinBox_auto_badpixel->width() / 1.7,ui->spinBox_auto_badpixel->height() / 1.7);
        ui->checkBox_auto_badpixel->setGeometry(ui->checkBox_auto_badpixel->x() / 1.7,ui->checkBox_auto_badpixel->y() / 1.7,ui->checkBox_auto_badpixel->width() / 1.7,ui->checkBox_auto_badpixel->height() / 1.7);
        ui->Button_recover->setGeometry(ui->Button_recover->x() / 1.7,ui->Button_recover->y() / 1.7,ui->Button_recover->width() / 1.7,ui->Button_recover->height() / 1.7);
        ui->label_rotate->setGeometry(ui->label_rotate->x() / 1.7,ui->label_rotate->y() / 1.7,ui->label_rotate->width() / 1.7,ui->label_rotate->height() / 1.7);
        ui->checkBox_rotate->setGeometry(ui->checkBox_rotate->x() / 1.7,ui->checkBox_rotate->y() / 1.7,ui->checkBox_rotate->width() / 1.7,ui->checkBox_rotate->height() / 1.7);
        ui->label_DDE->setGeometry(ui->label_DDE->x() / 1.7,ui->label_DDE->y() / 1.7,ui->label_DDE->width() / 1.7,ui->label_DDE->height() / 1.7);
        ui->checkBox_DDE->setGeometry(ui->checkBox_DDE->x() / 1.7,ui->checkBox_DDE->y() / 1.7,ui->checkBox_DDE->width() / 1.7,ui->checkBox_DDE->height() / 1.7);
        ui->label_B_3->setGeometry(ui->label_B_3->x() / 1.7,ui->label_B_3->y() / 1.7,ui->label_B_3->width() / 1.7,ui->label_B_3->height() / 1.7);
        ui->label_B_4->setGeometry(ui->label_B_4->x() / 1.7,ui->label_B_4->y() / 1.7,ui->label_B_4->width() / 1.7,ui->label_B_4->height() / 1.7);
        ui->spinBox_x->setGeometry(ui->spinBox_x->x() / 1.7,ui->spinBox_x->y() / 1.7,ui->spinBox_x->width() / 1.7,ui->spinBox_x->height() / 1.7);
        ui->spinBox_y->setGeometry(ui->spinBox_y->x() / 1.7,ui->spinBox_y->y() / 1.7,ui->spinBox_y->width() / 1.7,ui->spinBox_y->height() / 1.7);
        ui->Button_X->setGeometry(ui->Button_X->x() / 1.7,ui->Button_X->y() / 1.7,ui->Button_X->width() / 1.7,ui->Button_X->height() / 1.7);
        ui->Button_Y->setGeometry(ui->Button_Y->x() / 1.7,ui->Button_Y->y() / 1.7,ui->Button_Y->width() / 1.7,ui->Button_Y->height() / 1.7);

        ui->label_INTCP->setFont(font9);
        ui->label_ADGAIN->setFont(font9);
        ui->label_SVRD->setFont(font9);
        ui->label_FOS->setFont(font9);
        ui->label_OCC->setFont(font9);
        ui->spinBox_intcp->setFont(font9);
        ui->spinBox_adgain->setFont(font9);
        ui->spinBox_svrd->setFont(font9);
        ui->spinBox_fos->setFont(font9);
        ui->checkBox_OCC->setFont(font9);
        ui->Button_HI->setFont(font9);
        ui->Button_LO->setFont(font9);
        ui->Button_save->setFont(font9);
        ui->Button_set->setFont(font9);
        ui->Button_cancel->setFont(font9);
        ui->label_B->setFont(font9);
        ui->label_Gain->setFont(font9);
        ui->label_INT->setFont(font9);
        ui->label_Max->setFont(font9);
        ui->label_Min->setFont(font9);
        ui->label_VF->setFont(font9);
        ui->label_VS->setFont(font9);
        ui->label_ZN->setFont(font9);
        ui->spinBox_b->setFont(font9);
        ui->spinBox_gain->setFont(font9);
        ui->spinBox_max->setFont(font9);
        ui->spinBox_min->setFont(font9);
        ui->spinBox_tnt->setFont(font9);
        ui->spinBox_vf->setFont(font9);
        ui->spinBox_vs->setFont(font9);
        ui->spinBox_zn->setFont(font9);
        ui->label_Para->setFont(font9);
        ui->spinBox_Para->setFont(font9);
        ui->label_Zoom->setFont(font9);
        ui->spinBox_Zoom->setFont(font9);
        ui->label_B_2->setFont(font9);
        ui->spinBox_facus->setFont(font9);
        ui->label_B_5->setFont(font9);
        ui->spinBox_facus_2->setFont(font9);
        ui->label_B_6->setFont(font9);
        ui->spinBox_facus_3->setFont(font9);
        ui->Button_save_focus->setFont(font9);
        ui->label_oritoggle->setFont(font9);
        ui->Button_oritoggle_0->setFont(font9);
        ui->Button_oritoggle_1->setFont(font9);
        ui->label_auto_badpixel->setFont(font9);
        ui->spinBox_auto_badpixel->setFont(font9);
        ui->Button_recover->setFont(font9);
        ui->label_DDE->setFont(font9);
        ui->label_rotate->setFont(font9);
        ui->label_B_3->setFont(font9);
        ui->label_B_4->setFont(font9);
        ui->spinBox_x->setFont(font9);
        ui->spinBox_y->setFont(font9);
        ui->Button_X->setFont(font9);
        ui->Button_Y->setFont(font9);
        ui->label_3DHDFF->setFont(font9);
        ui->label_3DSD->setFont(font9);
        ui->spinBox_3DHDFF->setFont(font9);
        ui->spinBox_3DSD->setFont(font9);
        ui->checkBox_OCC->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");

        ui->checkBox_rotate->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_DDE->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_auto_badpixel->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");

        ui->spinBox_gain->setStyleSheet(BIG_SPINBOX_STYLESHEET);
        ui->spinBox_tnt->setStyleSheet(BIG_SPINBOX_STYLESHEET);
        ui->spinBox_vf->setStyleSheet(BIG_SPINBOX_STYLESHEET);
        ui->spinBox_vs->setStyleSheet(BIG_SPINBOX_STYLESHEET);
        ui->spinBox_facus->setStyleSheet(BIG_SPINBOX_STYLESHEET);
        ui->spinBox_facus_2->setStyleSheet(BIG_SPINBOX_STYLESHEET);
        ui->spinBox_Para->setStyleSheet(BIG_SPINBOX_STYLESHEET);
        ui->spinBox_Zoom->setStyleSheet(BIG_SPINBOX_STYLESHEET);
        ui->spinBox_x->setStyleSheet(BIG_SPINBOX_STYLESHEET);
        ui->spinBox_y->setStyleSheet(BIG_SPINBOX_STYLESHEET);
        ui->spinBox_auto_badpixel->setStyleSheet(BIG_SPINBOX_STYLESHEET);
    }
}
void HpHide_Biaoding::hp_slot_DDE_checked(bool checked)
{
    if(checked)
    {
        signal_biaoding_DDE(0);
    }else{
        signal_biaoding_DDE(1);
    }
}

void HpHide_Biaoding::on_checkBox_Sensibility_click(bool checked)
{
    if(checked)
    {
        GasPara gaspara;
        gaspara.SensibilityGain = ui->spinBox_SensibilityGain->value();
        gaspara.SensibilityRange = ui->spinBox_SensibilityRange->value();
        gaspara.SensibilitySwitch = 1;
        signal_image_set_gas(gaspara);
    }
    else
    {
        GasPara gaspara;
        gaspara.SensibilityGain = ui->spinBox_SensibilityGain->value();
        gaspara.SensibilityRange = ui->spinBox_SensibilityRange->value();
        gaspara.SensibilitySwitch = 0;
        signal_image_set_gas(gaspara);
    }
}

void HpHide_Biaoding::on_spinBox_SensibilityGain_value_change(int value)
{
    on_checkBox_Sensibility_click(true);
}

void HpHide_Biaoding::on_spinBox_SensibilityRange_value_change(int value)
{
    on_checkBox_Sensibility_click(true);
}

void HpHide_Biaoding::slot_biaoding_DDE(unsigned char return_value)
{
    qDebug("slot_biaoding_DDE return_value:0x%02x",return_value);
}
void HpHide_Biaoding::slot_setbiaoding_CheckBox_DDE(bool val)
{
    if(val)
    {
        ui->checkBox_DDE->setChecked(false);
        signal_biaoding_DDE(1);
    }else{
        ui->checkBox_DDE->setChecked(true);
        signal_biaoding_DDE(0);
    }
}
void HpHide_Biaoding::slot_biaoding_ceshi()
{

}

void HpHide_Biaoding::on_spinBox_vs_valueChanged(int arg1)      //vs
{
    qDebug( )<<arg1;
}

void HpHide_Biaoding::on_spinBox_vf_valueChanged(int arg1)      //vf
{

}

void HpHide_Biaoding::on_spinBox_gain_valueChanged(int arg1)       //gain
{

}

void HpHide_Biaoding::on_spinBox_tnt_valueChanged(int arg1)         //tnt
{

}

void HpHide_Biaoding::on_Button_HI_released()                           //HI
{
    single_biaoding_HI( );

    hp_hide_dialog->show();

}

void HpHide_Biaoding::on_Button_LO_released()                           //LO
{
    single_biaoding_LO( );
    hp_hide_dialog_lo->show();
}

void HpHide_Biaoding::on_Button_save_released()                         //SAVE
{
//    signal_biaoding_ceshi_2();
    single_biaoding_SAVE( );
    hp_hide_dialog_save->show();
}

void HpHide_Biaoding::on_Button_set_released()
{
    //获取当前界面信息存到结构体中；
    fpgamenupara.Gain=ui->spinBox_gain->value();
    fpgamenupara.INT=ui->spinBox_tnt->value();
    fpgamenupara.VF=ui->spinBox_vf->value();
    fpgamenupara.VS=ui->spinBox_vs->value();

        //信号，将结构体信息发送 到内核。 FPGAMenuPara para
    single_pc_biaoding_canshu(fpgamenupara);
    signal_core_fpgamenu_noise_time_para(ui->spinBox_3DHDFF->value());
//    hpxmlreader.writeXml("config.xml", "NOISETIME", "content", QString::number(ui->spinBox_3DHDFF->value()));
    signal_core_fpgamenu_noise_airspace_para(ui->spinBox_3DSD->value());
//    hpxmlreader.writeXml("config.xml", "NOISEAIRSPACE", "content", QString::number(ui->spinBox_3DSD->value()));
}

void HpHide_Biaoding::on_Button_cancel_released()
{
    this->close();          //退出界面
}

void HpHide_Biaoding::slot_hphide_biaoding_zn(int zn_value)
{
    ui->spinBox_zn->setValue(zn_value);
    ui->spinBox_zn->setMaximum(zn_value);
    ui->spinBox_zn->setMinimum(zn_value);
}

// slot 表示信号是内核发送过来的
void HpHide_Biaoding::slot_core_biaoding_canshu(FPGAMenuPara data)
{
//    qDebug() << " slot_core_biaoding_canshu" ;
    QString parasLen("0");//标识当前挡位号
    for(int i = 0; i < 10; i++)
    {
        parasLen = hpxmlreader.readXml("config.xml","LENSSET","lensid");
        if(!hpxmlreader.errorRead)
        {
            break;
        }
    }
    QString parasRange("0");//标识当前挡位号
    for(int i = 0; i < 10; i++)
    {
        parasRange = hpxmlreader.readXml("config.xml","LENSSET","rangeid");
        if(!hpxmlreader.errorRead)
        {
            break;
        }
    }
    QString parasRangeNum("0");//标识当前挡位号
    for(int i = 0; i < 10; i++)
    {
        parasRangeNum = hpxmlreader.readXml("config.xml","LENSSET","rangenum");
        if(!hpxmlreader.errorRead)
        {
            break;
        }
    }
    qDebug() << parasLen << parasRange << parasRangeNum;
    int tempType = parasRange.toInt() + parasLen.toInt() * parasRangeNum.toInt();
    qDebug() << tempType;
    QString para;
    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.readXml("config.xml", "NOISETIME", "diameter" + QString::number(tempType + 1));
        if(!hpxmlreader.errorRead)
        {
            qDebug() << __func__ << "spinBox_3DHFSS" << para.toInt();
            ui->spinBox_3DHDFF->setValue(para.toInt());
            on_spinBox_3DHDFF_valueChanged(para.toInt());
            break;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.readXml("config.xml", "NOISEAIRSPACE", "diameter" + QString::number(tempType + 1));
        if(!hpxmlreader.errorRead)
        {
            qDebug() << __func__ << "spinBox_3DSD" << para.toInt();
            ui->spinBox_3DSD->setValue(para.toInt());
            on_spinBox_3DSD_valueChanged(para.toInt());
            break;
        }
    }
    int separa = 0;
    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.readXml("config.xml", "SEPARA", "diameter" + QString::number(tempType + 1));
        if(!hpxmlreader.errorRead)
        {
            qDebug() << __func__ << "SEPARA" << para.toInt();
            ui->spinBox_Para->setValue(para.toInt());
            slot_spinBox_Para_valueChanged(para.toInt());
            break;
        }
    }
    int sezoom = 0;
    for(int i = 0; i < 10; i++)
    {
        para = hpxmlreader.readXml("config.xml", "SEZOOM", "diameter" + QString::number(tempType + 1));
        if(!hpxmlreader.errorRead)
        {
            qDebug() << __func__ << "SEZOOM" << para.toInt();
            ui->spinBox_Zoom->setValue(para.toInt());
            slot_spinBox_Zoom_valueChanged(para.toInt());
            break;
        }
    }
    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.readXml("config.xml", "VERTICAL", QString("on"));
        if(!hpxmlreader.errorRead)
        {
            qDebug() << __func__ << "VERTICAL" << para.toInt();
            if(para.toInt() == 1)
            {
                ui->checkBox_VERTICAL->setChecked(true);
                ui->checkBox_VERTICAL->clicked(true);
            }
            if(para.toInt() == 0)
            {
                ui->checkBox_VERTICAL->setChecked(false);
                ui->checkBox_VERTICAL->clicked(false);
            }
            break;
        }
    }

    for(int i = 0;i < 10;i++)
    {
        para = hpxmlreader.readXml("config.xml", "SUPPRESSION", QString("on"));
        qDebug() << __func__ << "SUPPRESSION" << para.toInt();
        if(!hpxmlreader.errorRead)
        {
            if(para.toInt() == 1)
            {
                ui->checkBox_SUPPRESSION->setChecked(true);
//                ui->checkBox_SUPPRESSION->clicked(true);
                signal_pc_image_set_suppression_handle(1);
            }
            if(para.toInt() == 0)
            {
                ui->checkBox_SUPPRESSION->setChecked(false);
//                ui->checkBox_SUPPRESSION->clicked(false);
                signal_pc_image_set_suppression_handle(0);
            }
            break;
        }
    }
    FPGAMenuPara    fpgamenu_para = data;           //强制转换
    //将收到的参数显示到界面上

    qDebug() << " slot_core_biaoding_canshu VS" <<fpgamenu_para.VS;
    qDebug() << " slot_core_biaoding_canshu VF" <<fpgamenu_para.VF;
    qDebug() << " slot_core_biaoding_canshu Gain" <<fpgamenu_para.Gain;
    qDebug() << " slot_core_biaoding_canshu INT" <<fpgamenu_para.INT;
    fpgamenupara.Reserve[0]=fpgamenu_para.Reserve[0];
    fpgamenupara.Reserve[1]=fpgamenu_para.Reserve[1];

    ui->spinBox_vs->setValue(fpgamenu_para.VS);
    ui->spinBox_vf->setValue(fpgamenu_para.VF);
    ui->spinBox_gain->setValue(fpgamenu_para.Gain);
    ui->spinBox_tnt->setValue(fpgamenu_para.INT);

    signal_biaoding_para_ok( );
    signal_core_fpga_get_svrd();
    signal_core_fpga_get_adgain();
    signal_core_fpga_get_intcp();
    signal_core_fpga_get_fos();
}
void HpHide_Biaoding::slot_core_biaoding_gray(FPGAMenuGray data)
{
//    FPGAMenuGray    *fpgamenu_gray= (FPGAMenuGray*)data;
    //将收到的参数显示到界面上
    ui->spinBox_max->setValue(data.MaxGray);
    ui->spinBox_max->setMaximum(data.MaxGray);
    ui->spinBox_max->setMinimum(data.MaxGray);
//    qDebug() << __LINE__ << __func__ << "MaxGray:" << data.MaxGray;

    ui->spinBox_min->setValue(data.MinGray);
    ui->spinBox_min->setMaximum(data.MinGray);
    ui->spinBox_min->setMinimum(data.MinGray);
//    qDebug() << __LINE__ << __func__ << "MinGray:" << data.MinGray;

    ui->spinBox_b->setValue(data.ZeroGray);
    ui->spinBox_b->setMaximum(data.ZeroGray);
    ui->spinBox_b->setMinimum(data.ZeroGray);
//    qDebug() << __LINE__ << __func__ << "ZeroGray:" << data.ZeroGray;

}

void HpHide_Biaoding::slot_pc_focus_offset(unsigned char return_value)
{
//        qDebug("slot_pc_focus_offset return_value:0x%02x",return_value);
}
void HpHide_Biaoding::slot_biaoding_focus_offset(bool focusSaveMth, int laserfocus,int generalfocus,int fastFocus)
{
    isStructSave = focusSaveMth;
    ui->spinBox_facus->setValue(laserfocus);
    ui->spinBox_facus_2->setValue(generalfocus);
    ui->spinBox_facus_3->setValue(fastFocus);
    hp_saveFocus();
}

void HpHide_Biaoding::hp_saveFocus()
{
    //两个高字节用作当前是激光聚焦模式还是普通聚焦模式的设置 低两个字节是用作offset的值
    int sum = 0;
//    qDebug() << "HpHide_Biaoding::hp_saveFocus == > " << focusmode << " ; " << ui->spinBox_facus->value() << " ; " << ui->spinBox_facus_2->value();
    if(focusmode == 0)
    {
        qDebug() << "HpHide_Biaoding::hp_saveFocus == 1 == == > " << ui->spinBox_facus_2->value();
        sum = focusmode << 16 | ui->spinBox_facus_2->value();
    }else{
        qDebug() << "HpHide_Biaoding::hp_saveFocus === 2 === == > " << ui->spinBox_facus->value();
        sum = focusmode << 16 | ui->spinBox_facus->value();
    }

    qDebug() << "HpHide_Biaoding::hp_saveFocus === sum === == > " << sum;
    if(!isStructSave)
    {
        signal_pc_save_focus_offset(sum);//同时保存两个focus值
        return;
    }
    ComFocusOffset focusVal;
    focusVal.autofocus_mode = focusmode;
    focusVal.fast_focousoffset = ui->spinBox_facus_3->value();
    focusVal.general_focousoffset = ui->spinBox_facus_2->value();
    focusVal.laser_focousoffset = ui->spinBox_facus->value();
    qDebug()<<"HPBIAODING::slot_pc_focus_offset CORE_FPGAMENU_FOCUS_OFFSET Send == > " << focusVal.autofocus_mode << focusVal.general_focousoffset << focusVal.laser_focousoffset;
    signal_pc_focus_offset(focusVal);//同时保存两个focus值
}

void HpHide_Biaoding::hp_setautofocusmode(int mode)
{
    focusmode = mode;
    hp_saveFocus();
}
//按键事件  //     signal_biaoding_gray();
void HpHide_Biaoding::keyReleaseEvent(QKeyEvent *ev)
{
    switch(ev->key())
    {
        case 0x51:      //q
            single_biaoding_tiaoling( );
            break;
        case 0x1000031://0x1000012
            single_biaoding_tiaoling( );
            break;
        default:
            break;
    }
}


void HpHide_Biaoding::slot_image_set_gas(GasPara para)
{
    qDebug() << "HpHide_Biaoding::slot_image_set_gas" << para.SensibilityRange;
    ui->spinBox_SensibilityGain->setValue(para.SensibilityGain);
    ui->spinBox_SensibilityRange->setValue(para.SensibilityRange);

    if(para.SensibilitySwitch == 1)
    {
        ui->checkBox_Sensibility->clicked(true);
    }
    if(para.SensibilitySwitch == 0)
    {
        ui->checkBox_Sensibility->clicked(false);
    }
}

//定时器事件

void HpHide_Biaoding::handleTimeout( )
{
    //  ui->labe_warn->setText("");
}

void HpHide_Biaoding::slot_set_core_fpgamenu_badline_x(unsigned char return_value)
{
    qDebug("slot_set_core_fpgamenu_badline_x return_value:0x%02x",return_value);
}

void HpHide_Biaoding::slot_set_core_fpgamenu_badline_y(unsigned char return_value)
{
    qDebug("slot_set_core_fpgamenu_badline_y return_value:0x%02x",return_value);
}

//void HpHide_Biaoding::on_spinBox_facus_valueChanged(int arg1)
//{
//    qDebug()<<"on_spinBox_facus_valueChanged  xxxxxx" <<arg1;
//    signal_pc_focus_offset(arg1);
//}

void HpHide_Biaoding::on_Button_X_released()
{
    int badline_x = ui->spinBox_x->value();
//    if(define_S6X0_S3X0)
//    {
//        badline_x = badline_x*100/67;
//    }

    qDebug() << "HpHide_Biaoding::on_Button_X_released == > " << badline_x;
    signal_set_core_fpgamenu_badline_x(badline_x);
}

void HpHide_Biaoding::on_Button_Y_released()
{
   int badline_y = ui->spinBox_y->value();

//   if(define_S6X0_S3X0)
//   {
//       badline_y = badline_y*100/67;
//   }

   qDebug() << "HpHide_Biaoding::on_Button_Y_released == > " << badline_y;
   signal_set_core_fpgamenu_badline_y(badline_y);
}

void HpHide_Biaoding::setStructSave(bool structSave)
{
    isStructSave = structSave;
}

void HpHide_Biaoding::setCheckboxrotate(int val)
{
    qDebug() << "HpHide_Biaoding::setCheckboxrotate == > " << val;
    if(val == 1)
    {
        ui->checkBox_rotate->setChecked(true);
//        signal_pc_checkbox_rotate(true);
    }else if(val == 0){
        ui->checkBox_rotate->setChecked(false);
//        signal_pc_checkbox_rotate(false);
    }
}
void HpHide_Biaoding::on_checkBox_rotate_clicked(bool checked)
{
    qDebug() << "HpHide_Biaoding::on_checkBox_rotate_clicked == > " << checked;
    signal_pc_checkbox_rotate(checked);
}
void HpHide_Biaoding::slot_pc_checkbox_rotate(unsigned char return_value)
{
    qDebug("slot_pc_checkbox_rotate return_value:0x%02x",return_value);
}
void HpHide_Biaoding::slot_core_fpgamenu_oritoggle(unsigned char return_value)
{
    qDebug("slot_core_fpgamenu_oritoggle return_value:0x%02x",return_value);
}
void HpHide_Biaoding::slot_core_fpgamenu_auto_badixel(unsigned char return_value)
{
    qDebug("slot_core_fpgamenu_auto_badixel return_value:0x%02x",return_value);
}
void HpHide_Biaoding::slot_core_fpgamenu_badpixel_recover(unsigned char return_value)
{
    qDebug("slot_core_fpgamenu_badpixel_recover return_value:0x%02x",return_value);
}

void HpHide_Biaoding::on_Button_oritoggle_0_clicked()
{
    signal_core_fpgamenu_oritoggle(0);
}

void HpHide_Biaoding::on_Button_oritoggle_1_clicked()
{
    signal_core_fpgamenu_oritoggle(1);
}

void HpHide_Biaoding::on_checkBox_auto_badpixel_clicked(bool checked)
{
    int val = 0;
    if(checked)
    {
        signal_core_fpgamenu_auto_badixel(1);
    }else{
        signal_core_fpgamenu_auto_badixel(0);
    }
    signal_core_fpgamenu_value_badixel(ui->spinBox_auto_badpixel->value());
}

void HpHide_Biaoding::on_Button_recover_clicked()
{
    signal_core_fpgamenu_badpixel_recover();
}
void HpHide_Biaoding::slot_spinBox_Para_valueChanged(int val)
{
    signal_pc_spinbox_para(val);
}
void HpHide_Biaoding::slot_spinBox_Zoom_valueChanged(int val)
{
    signal_pc_spinbox_zoom(val);
}
void HpHide_Biaoding::slot_pc_spinbox_para(unsigned char return_value)
{
    qDebug("slot_pc_spinbox_para return_value:0x%02x",return_value);
}
void HpHide_Biaoding::slot_pc_spinbox_zoom(unsigned char return_value)
{
    qDebug("slot_pc_spinbox_zoom return_value:0x%02x",return_value);
}
void HpHide_Biaoding::slot_setbiaoding_Para(int val)
{
    ui->spinBox_Para->setValue(val);
    signal_pc_spinbox_para(val);
}

void HpHide_Biaoding::slot_setbiaoding_Zoom(int val)
{
    ui->spinBox_Zoom->setValue(val);
    signal_pc_spinbox_zoom(val);
}

void HpHide_Biaoding::on_spinBox_facus_3_valueChanged(int arg1)
{

}

void HpHide_Biaoding::on_spinBox_fos_valueChanged(int arg1)
{
    signal_core_fpgamenu_set_fos(arg1);
}

void HpHide_Biaoding::on_spinBox_svrd_valueChanged(int arg1)
{
    signal_core_fpgamenu_set_svrd(arg1);
}

void HpHide_Biaoding::on_spinBox_adgain_valueChanged(int arg1)
{
    signal_core_fpgamenu_set_adgain(arg1);
}

void HpHide_Biaoding::on_spinBox_intcp_valueChanged(int arg1)
{
    signal_core_fpgamenu_set_intcp(arg1);
}

void HpHide_Biaoding::on_checkBox_OCC_clicked(bool checked)
{
    signal_core_fpgamenu_occ_enable(checked);
}

void HpHide_Biaoding::slot_setbiaoding_3DHDFF(int val)
{
}

void HpHide_Biaoding::slot_setbiaoding_3DSD(int val)
{
}

void HpHide_Biaoding::on_spinBox_3DHDFF_valueChanged(int arg1)
{
}

void HpHide_Biaoding::on_spinBox_3DSD_valueChanged(int arg1)
{
}

void HpHide_Biaoding::slot_core_fpga_get_fos(unsigned char return_value, int val)
{
    ui->spinBox_fos->setValue(val);
    on_spinBox_fos_valueChanged(val);
}

void HpHide_Biaoding::slot_core_fpga_get_intcp(unsigned char return_value, int val)
{
    ui->spinBox_intcp->setValue(val);
    on_spinBox_intcp_valueChanged(val);
}

void HpHide_Biaoding::slot_core_fpga_get_adgain(unsigned char return_value, int val)
{
    ui->spinBox_adgain->setValue(val);
    on_spinBox_adgain_valueChanged(val);
}

void HpHide_Biaoding::slot_core_fpga_get_svrd(unsigned char return_value, int val)
{
    ui->spinBox_svrd->setValue(val);
    on_spinBox_svrd_valueChanged(val);
}

void HpHide_Biaoding::on_checkBox_VERTICAL_clicked(bool checked)
{
    if(checked)
        signal_pc_image_set_vertical_handle(1);
    else
        signal_pc_image_set_vertical_handle(0);
}

void HpHide_Biaoding::on_checkBox_SUPPRESSION_clicked(bool checked)
{
    if(checked)
        signal_pc_image_set_suppression_handle(1);
    else
        signal_pc_image_set_suppression_handle(0);
}
