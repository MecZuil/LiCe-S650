#include  "hp_main_task_3.h"
#include  "ui_hp_main_task_3.h"
#include  "hi384_protocol.h"
Hp_Main_Task_3::Hp_Main_Task_3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Main_Task_3)
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

Hp_Main_Task_3::~Hp_Main_Task_3()
{
    delete ui;
}

void Hp_Main_Task_3::hp_setDefine5_5(bool isSelect)
{
    if(isSelect)
    {
        this->resize(29, 240);
        ui->label_battery->setGeometry(0,0,28,44);//1
        ui->task_sd->setGeometry(0, 44,28,29);//2
        ui->task_wifi->setGeometry(0, 44 + 28,28,29);//3
        ui->task_usb->setGeometry(0, 44 + 28*2,28,29);//4
        ui->task_ble->setGeometry(0, 44 + 28*3,28,29);//5
        ui->task_headset->setGeometry(0, 44 + 28*4,28,29);//6
        ui->task_gps->setGeometry(0, 44 + 28*5,28,29);//7
        ui->task_4G->setGeometry(0, 44 + 28*6,28,29);//8
    }
}
void Hp_Main_Task_3::changeEvent(QEvent *e)
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

void Hp_Main_Task_3::update_sd(bool s)
{
    ui->task_sd->setVisible(s);
}
void Hp_Main_Task_3::update_wifi(bool s)
{
    ui->task_wifi->setVisible(s);
}
void Hp_Main_Task_3::update_4G(bool s)
{
    ui->task_4G->setVisible(s);
}
void Hp_Main_Task_3::update_usb(bool s)
{
    ui->task_usb->setVisible(s);
}
void Hp_Main_Task_3::update_ble(bool s)
{
    ui->task_ble->setVisible(s);
}
void Hp_Main_Task_3::update_headset(bool s)
{
    ui->task_headset->setVisible(s);
}

void Hp_Main_Task_3::update_battery_stylesheet(QString style)
{
    ui->label_battery->setStyleSheet(style);
}

void Hp_Main_Task_3::update_auto_focus(bool s)
{
    qDebug() << "Hp_Main_Task::update_auto_focus   " << s;
    if(s == true){
        ui->task_gps->setVisible(true);
    }else{

        ui->task_gps->setVisible(false);
    }
}
