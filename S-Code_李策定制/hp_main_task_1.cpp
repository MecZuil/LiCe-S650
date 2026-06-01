#include  "hp_main_task_1.h"
#include  "ui_hp_main_task_1.h"
#include  "hi384_protocol.h"
Hp_Main_Task_1::Hp_Main_Task_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Main_Task_1)
{
    ui->setupUi(this);
    ui->task_ble->setVisible(false);
    ui->task_headset->setVisible(false);
    ui->task_wifi->setVisible(false);
    ui->task_4G->setVisible(false);
    ui->task_usb->setVisible(false);
    ui->task_sd->setVisible(false);
    ui->task_gps->setVisible(false);
    ui->label_battery->setVisible(true);
    ui->task_gps->setVisible(false);
}

Hp_Main_Task_1::~Hp_Main_Task_1()
{
    delete ui;
}
void Hp_Main_Task_1::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        this->resize(16, 150);
        ui->task_4G->setGeometry(0,0,16,16);//1
        ui->task_gps->setGeometry(0,16,16,16);//2
        ui->task_headset->setGeometry(0,56,16,16);//3
        ui->task_ble->setGeometry(0,16*3,16,16);//4
        ui->task_usb->setGeometry(0,16*4,16,16);//5
        ui->task_wifi->setGeometry(0,16*5,16,16);//6
        ui->task_sd->setGeometry(0,16*6,16,16);//7
        ui->label_battery->setGeometry(0,16*7,16,32);//8
    }
}
void Hp_Main_Task_1::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Hp_Main_Task_1::update_sd(bool s)
{
    ui->task_sd->setVisible(s);
}
void Hp_Main_Task_1::update_wifi(bool s)
{
    ui->task_wifi->setVisible(s);
}
void Hp_Main_Task_1::update_4G(bool s)
{
    ui->task_4G->setVisible(s);
}
void Hp_Main_Task_1::update_usb(bool s)
{
    ui->task_usb->setVisible(s);
}
void Hp_Main_Task_1::update_ble(bool s)
{
    ui->task_ble->setVisible(s);
}
void Hp_Main_Task_1::update_headset(bool s)
{
    ui->task_headset->setVisible(s);
}

void Hp_Main_Task_1::update_battery_stylesheet(QString style)
{
    ui->label_battery->setStyleSheet(style);
}

void Hp_Main_Task_1::update_auto_focus(bool s)
{
    qDebug() << "Hp_Main_Task::update_auto_focus   " << s;
    if(s == true){
        ui->task_gps->setVisible(true);
    }else{

        ui->task_gps->setVisible(false);
    }
}
