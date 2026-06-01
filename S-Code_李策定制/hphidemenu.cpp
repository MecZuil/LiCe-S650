#include  "hphidemenu.h"
#include  "ui_hphidemenu.h"

HpHideMenu::HpHideMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HpHideMenu)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    setFixedSize(this->width(), this->height());
    setGeometry(0,0,width(),height());

    hideMenuPara.ShowGrayEnable = 0;
    hideMenuPara.CollectEnable = 0;
    hideMenuPara.GlobalCompensate100 = 1;
    hideMenuPara.PrintScreen = 0;
    hideMenuPara.Homogeneity=0;

    hideMenuPara.PointDelBadFixel_En = 0;
    hideMenuPara.RectDelBadFixel_En = 0;

    ui->checkBox_gray->setChecked(hideMenuPara.ShowGrayEnable);
    ui->checkBox_cap->setChecked(hideMenuPara.CollectEnable);
    ui->checkBox_printscreen->setChecked(hideMenuPara.PrintScreen);
    ui->checkBox_laser->setChecked(false);
    m_collectDialog = new hp_DefaultDialog(this);
    m_collectDialog->hide();

 //   ui->checkBox_point->setCheckable(hideMenuPara.PointDelBadFixel_En);
 //   ui->checkBox_rect->setCheckable(hideMenuPara.RectDelBadFixel_En);
//    int aaaa=0;
//    ui->checkBox_point->setCheckable(aaaa);
    ui->label_para_22->close();
    ui->toolButton->close();
    ui->toolButton_2->close();
    ui->toolButton_3->close();
    ui->toolButton_4->close();
    connect(ui->checkBox_laser,SIGNAL(clicked(bool)),this,SLOT(slot_laser_enable(bool)));
    connect(ui->checkBox_cap,SIGNAL(clicked(bool)),this,SLOT(slot_cap_enable(bool)));
    connect(ui->checkBox_gray,SIGNAL(clicked(bool)),this,SLOT(slot_gray_enable(bool)));
    connect(ui->checkBox_point,SIGNAL(clicked(bool)),this,SLOT(slot_point_enable(bool)));
    connect(ui->checkBox_rect,SIGNAL(clicked(bool)),this,SLOT(slot_rect_enable(bool)));
    connect(ui->checkBox_homogeneity,SIGNAL(clicked(bool)),this,SLOT(slot_homogeneity_enable(bool)));
    connect(ui->toolButton,SIGNAL(clicked(bool)),this,SLOT(slot_gray_enable(bool)));
    connect(ui->toolButton_2,SIGNAL(clicked(bool)),this,SLOT(slot_point_enable(bool)));
    connect(ui->toolButton_3,SIGNAL(clicked(bool)),this,SLOT(slot_rect_enable(bool)));
    connect(ui->toolButton_4,SIGNAL(clicked(bool)),this,SLOT(slot_homogeneity_enable(bool)));
    connect(m_collectDialog, SIGNAL(signal_close_ble_lie()), this, SLOT(slot_start_get_gray()));
//    connect(ui->)
//    connect(ui->checkBox_printscreen,SIGNAL(clicked(bool)),

    m_collectDialog->hp_setTitleText("采集使能将覆盖原有数据是否开启");
    hidemenu_configpara_init();
}

HpHideMenu::~HpHideMenu()
{
    delete ui;
}

void HpHideMenu::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);
        QFont font12;
        font9.setPointSize(12);

        this->resize(480,272);
        ui->cancel->setGeometry(350,230,99,27);
        ui->checkBox_cap->setGeometry(20,120,111,51);
        ui->checkBox_gray->setGeometry(170,120,121,51);
        ui->checkBox_homogeneity->setGeometry(320,180,111,51);
        ui->checkBox_laser->setGeometry(20,220,111,51);
        ui->checkBox_point->setGeometry(20,180,111,51);
        ui->checkBox_printscreen->setGeometry(320,120,111,54);
        ui->checkBox_rect->setGeometry(170,180,111,51);
        ui->doubleSpinBox_21->setGeometry(180,40,141,20);
        ui->doubleSpinBox_23->setGeometry(180,80,141,20);
        ui->label_para_21->setGeometry(93,40,71,20);
        ui->label_para_23->setGeometry(93,80,71,20);
        ui->label_para_24->close();
        ui->label_para_25->close();
        ui->label_para_26->close();
        ui->label_para_27->close();
        ui->label_para_28->close();
        ui->label_para_29->close();
        ui->doubleSpinBox_hd->close();
        ui->doubleSpinBox_ht1->close();
        ui->doubleSpinBox_ht2->close();
        ui->doubleSpinBox_ld->close();
        ui->doubleSpinBox_lt1->close();
        ui->doubleSpinBox_lt2->close();
        ui->cancel_2->close();

        ui->cancel->setFont(font9);
        ui->checkBox_cap->setFont(font12);
        ui->checkBox_gray->setFont(font12);
        ui->checkBox_homogeneity->setFont(font12);
        ui->checkBox_laser->setFont(font12);
        ui->checkBox_point->setFont(font12);
        ui->checkBox_printscreen->setFont(font12);
        ui->checkBox_rect->setFont(font12);
        ui->doubleSpinBox_21->setFont(font9);
        ui->doubleSpinBox_23->setFont(font9);
        ui->label_para_21->setFont(font9);
        ui->label_para_23->setFont(font9);
        ui->toolButton->setFont(font9);
        ui->toolButton_2->setFont(font9);
        ui->toolButton_3->setFont(font9);
        ui->toolButton_4->setFont(font9);
        ui->label_para_22->setFont(font9);
    }
}

void HpHideMenu::update_hidemenuparam()
{
    signal_pc_sys_set_hidemenu(hideMenuPara);
}

void HpHideMenu::slot_cap_enable(bool checked)
{
    if(checked)
    {
        hideMenuPara.CollectEnable = 1;
        update_hidemenuparam();
//        ui->checkBox_cap->setChecked(false);
//        m_collectDialog->raise();
//        m_collectDialog->show();
        return;
    }
    hideMenuPara.CollectEnable = 0;
    update_hidemenuparam();
}

void HpHideMenu::slot_start_get_gray()
{
    ui->checkBox_cap->setChecked(true);
    hideMenuPara.CollectEnable = 1;
    update_hidemenuparam();
}

void HpHideMenu::slot_laser_enable(bool checked)
{
    signal_laser_enable(checked);
}
/*
void HpHideMenu::slot_solid_value_change(int v)
{
    qDebug("value:%d",v);
    QString msg = QString("%1").arg(v);
    ui->label_value->setText(msg);
    hideMenuPara.GlobalCompensate100 = v;
    update_hidemenuparam();
}
*/
void HpHideMenu::slot_gray_enable(bool checked)
{
    if(checked)
        hideMenuPara.ShowGrayEnable = 1;
    else
        hideMenuPara.ShowGrayEnable = 0;

    update_hidemenuparam();
    signal_gray_enable(checked);
}


void HpHideMenu::slot_pc_sys_set_hidemenu(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_hidemenu:return_value:0x%02x",return_value);
}


void HpHideMenu::on_checkBox_printscreen_clicked(bool checked)          //截图功能
{
    if(checked)
        hideMenuPara.PrintScreen =1;
    else
        hideMenuPara.PrintScreen =0;
    update_hidemenuparam();
    signal_printscreen_checked(checked);
}



void HpHideMenu::slot_point_enable(bool checked)
{

    if(checked)
        hideMenuPara.PointDelBadFixel_En =1;
    else
        hideMenuPara.PointDelBadFixel_En =0;

    update_hidemenuparam();
    signal_painter_point(checked);
    signal_point_enable(checked);

}



void HpHideMenu::slot_rect_enable(bool checked)
{
    if(checked){

        hideMenuPara.RectDelBadFixel_En =1;
     }
    else{
        hideMenuPara.RectDelBadFixel_En =0;
     }

    update_hidemenuparam();

    signal_painter_rect(checked);
    signal_rect_enable(checked);
}

void HpHideMenu::slot_homogeneity_enable(bool checked)          //homogeneity 。均匀性测试
{
    if(checked){

        hideMenuPara.Homogeneity =1;
     }
    else{
        hideMenuPara.Homogeneity=0;
     }
    update_hidemenuparam();
    signal_pc_sys_set_hidemenu(hideMenuPara);                           //发送结构体给内核

}


void HpHideMenu::on_doubleSpinBox_21_valueChanged(double arg1)
{
    //类型转换
    float float_21;
    float_21 = (float)arg1;

     hideMenuPara.GlobalCompensate100 = float_21;
    signal_pc_sys_set_hidemenu(hideMenuPara);
}

void HpHideMenu::on_doubleSpinBox_23_valueChanged(double arg1)
{
    //类型转换

    float float_23;
    float_23 = (float)arg1;

    hideMenuPara.ConfigPara23 = float_23;
      signal_pc_sys_set_hidemenu(hideMenuPara);
}

void HpHideMenu::slot_core_hidemenu_get_para(ComHideMenuPara data)
{
    qDebug() << "CollectEnable" << data.CollectEnable;
    qDebug() << "ShowGrayEnable" << data.ShowGrayEnable;
    qDebug() << "Homogeneity" << data.Homogeneity;
    qDebug() << "PointDelBadFixel_En" << data.PointDelBadFixel_En;
    ui->checkBox_cap->setChecked(data.CollectEnable);
    ui->checkBox_gray->setChecked(data.ShowGrayEnable);
    ui->checkBox_homogeneity->setChecked(data.Homogeneity);
    ui->checkBox_point->setChecked(data.PointDelBadFixel_En);
    ui->checkBox_printscreen->setChecked(data.PrintScreen);
    ui->checkBox_rect->setChecked(data.RectDelBadFixel_En);
}

//初始化 configpara
void HpHideMenu::hidemenu_configpara_init()
{
    QString lensid,rangeid;        //当前镜头号，挡位号
    lensid = hpxmlreader.readXml("config.xml","LENSSET","lensid");
    rangeid = hpxmlreader.readXml("config.xml","LENSSET","rangeid");
    qDebug() << __func__ << "---------------------------------------------------------------lensid" << lensid;
    qDebug() << __func__ << "---------------------------------------------------------------rangeid" << rangeid;
    int lensid_int,rangeid_int;       //将镜头号，挡位号转换为int类型
    lensid_int = lensid.toInt();
    rangeid_int = rangeid.toInt();

    QString para_21,para_23;
    para_21 = hpxmlreader.readXml("config.xml","LENS"+QString::number(lensid_int*3+rangeid_int+1),"Para21");
    para_23 = hpxmlreader.readXml("config.xml","LENS"+QString::number(lensid_int*3+rangeid_int+1),"Para23");

    qDebug() << __func__ << "---------------------------------------------------------------para_21" << para_21;
    qDebug() << __func__ << "---------------------------------------------------------------para_23" << para_23;
    double   para21_double,para23_double;
    para21_double = para_21.toDouble();
    para23_double = para_23.toDouble();

    ui->doubleSpinBox_21->setValue(para21_double);           //para_21
    ui->doubleSpinBox_23->setValue(para23_double);

//    signal_pc_sys_set_hidemenu(hideMenuPara);                           //发送结构体给内核
}

void HpHideMenu::slot_set_para_2123()           //改变镜头或者挡位后，重新设置 para_ 的值。已经屏蔽
{
    hidemenu_configpara_init();
}

void HpHideMenu::setStartPower(bool isOpen)
{
    if(isOpen)
    {
        hideMenuPara.CollectEnable = 1;
        ui->checkBox_cap->setChecked(hideMenuPara.CollectEnable);
        signal_pc_sys_set_hidemenu(hideMenuPara);
    }
}

void HpHideMenu::setDefineCompass(bool isDefineCompass)
{
//    qDebug() << " = = HpHideMenu::setDefineCompass == > " << isDefineCompass;
    if(!isDefineCompass)//就等于COMPASS_MODE
    {
        ui->toolButton->hide();
        ui->toolButton_2->hide();
        ui->toolButton_3->hide();
        ui->toolButton_4->hide();
        ui->label_para_22->hide();
    }else{
        ui->toolButton->show();
        ui->toolButton_2->show();
        ui->toolButton_3->show();
        ui->toolButton_4->show();
        ui->label_para_22->show();
    }
}


void HpHideMenu::on_toolButton_clicked()
{
//    signal_update_lcdoff_time(false);
    signal_pc_sys_mag_calsw_start();
}

void HpHideMenu::on_toolButton_2_clicked()
{
//    signal_update_lcdoff_time(false);
    signal_pc_sys_mag_calsw_stop();
}

void HpHideMenu::on_toolButton_3_clicked()
{
//    signal_update_lcdoff_time(false);
    trans+=3;
    signal_pc_sys_set_mag_affset(trans);
    signal_set_compass_trans(trans);
    ui->label_para_22->setText(QString::number(trans));
    qDebug()<<"eeeeeeeeeeeeeeeeeeeeeeeeeeeeee" <<trans;

}

void HpHideMenu::on_toolButton_4_clicked()
{
//    signal_update_lcdoff_time(false);
    trans-=3;
    signal_pc_sys_set_mag_affset(trans);
    signal_set_compass_trans(trans);
    ui->label_para_22->setText(QString::number(trans));
    qDebug()<<"eeeeeeeeeeeeeeeeeeeeeeeeeeeeee" <<trans;
}



void HpHideMenu::on_save_sys_2_clicked()
{

    if(ui->checkBox_cap->isChecked())
    {
        ui->label_para_30->show();
    }
    else
    {
        ui->label_para_30->close();
        signal_pc_get_measure_get_collect(1);
    }
}

void HpHideMenu::on_save_sys_3_clicked()
{
    if(ui->checkBox_cap->isChecked())
    {
        ui->label_para_30->show();
    }
    else
    {
        ui->label_para_30->close();
        signal_pc_get_measure_get_collect(0);
    }
}
