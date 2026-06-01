#include  "hp_main_task.h"
#include  "ui_hp_main_task.h"
#include  "hi384_protocol.h"
Hp_Main_Task::Hp_Main_Task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Main_Task)
{
    ui->setupUi(this);
    ui->task_ble->setVisible(false);
    ui->task_headset->setVisible(false);
    ui->task_wifi->setVisible(false);
    ui->task_usb->setVisible(false);
    ui->task_sd->setVisible(false);
    ui->label_battery->setVisible(true);
    ui->task_4g->setVisible(false);
   #if 0
    if(FOCUS_MODE == 1){
        ui->task_focus->setVisible(true);
    }else{
        ui->task_focus->setVisible(false);
    }
   #else
        ui->task_focus->setVisible(false);
   #endif
}

Hp_Main_Task::~Hp_Main_Task()
{
    delete ui;
}

void Hp_Main_Task::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        this->resize(150,16);
        ui->label_battery->setGeometry(118,0,32,16);
        ui->task_ble->setGeometry(54,0,16,16);
        ui->task_focus->setGeometry(22,0,16,16);
        ui->task_headset->setGeometry(38,0,16,16);
        ui->task_sd->setGeometry(102,0,16,16);
        ui->task_usb->setGeometry(70,0,16,16);
        ui->task_wifi->setGeometry(86,0,16,16);
    }
}

void Hp_Main_Task::changeEvent(QEvent *e)
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

void Hp_Main_Task::update_sd(bool s)
{
    ui->task_sd->setVisible(s);
}

void Hp_Main_Task::update_wifi(bool s)
{
//    qDebug() << "_----------------------------------------------------------" << s << __func__ << __LINE__;
    if(s)
    {
        ui->task_4g->setVisible(false);
    }
    ui->task_wifi->setVisible(s);
}

void Hp_Main_Task::update_usb(bool s)
{
    ui->task_usb->setVisible(s);
}

void Hp_Main_Task::update_ble(bool s)
{
    ui->task_ble->setVisible(s);
}

void Hp_Main_Task::update_headset(bool s)
{
    ui->task_headset->setVisible(s);
}

void Hp_Main_Task::update_battery_stylesheet(QString style)
{
    ui->label_battery->setStyleSheet(style);
//    ui->label_battery->setVisible(true);
}

void Hp_Main_Task::update_auto_focus(bool s)
{
    ui->task_focus->setVisible(s);
}

void Hp_Main_Task::update_4g(bool s)
{
//    qDebug() << "_----------------------------------------------------------" << s << __func__ << __LINE__;
    if(s)
    {
        ui->task_wifi->setVisible(false);
    }
    ui->task_4g->setVisible(s);
}
