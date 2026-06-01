#include  "hp_main_task_2.h"
#include  "ui_hp_main_task_2.h"
#include  "hi384_protocol.h"
Hp_Main_Task_2::Hp_Main_Task_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Main_Task_2)
{
    ui->setupUi(this);
    ui->task_ble->setVisible(false);
    ui->task_headset->setVisible(false);
    ui->task_wifi->setVisible(false);
    ui->task_4G->setVisible(false);
    ui->task_usb->setVisible(false);
    ui->task_gps->setVisible(false);
    ui->task_sd->setVisible(false);
    ui->label_battery->setVisible(true);

    ui->task_gps->setVisible(false);
}

Hp_Main_Task_2::~Hp_Main_Task_2()
{
    delete ui;
}

void Hp_Main_Task_2::hp_setDefine5_5(bool isSelect)
{
    if(isSelect)
    {
        this->resize(240,29);
        ui->label_battery->setGeometry(0,0,44,28);//1
        ui->task_sd->setGeometry(44,0,28,29);//2
        ui->task_wifi->setGeometry(44 + 28,0,28,29);//3
        ui->task_usb->setGeometry(44 + 28*2,0,28,29);//4
        ui->task_ble->setGeometry(44 + 28*3,0,28,29);//5
        ui->task_headset->setGeometry(44 + 28*4,0,28,29);//6
        ui->task_gps->setGeometry(44 + 28*5,0,28,29);//7
        ui->task_4G->setGeometry(44 + 28*6,0,28,29);//8
    }
}
void Hp_Main_Task_2::changeEvent(QEvent *e)
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

void Hp_Main_Task_2::update_sd(bool s)
{
    ui->task_sd->setVisible(s);
}
void Hp_Main_Task_2::update_wifi(bool s)
{
    ui->task_wifi->setVisible(s);
}
void Hp_Main_Task_2::update_4G(bool s)
{
    ui->task_4G->setVisible(s);
}
void Hp_Main_Task_2::update_usb(bool s)
{
    ui->task_usb->setVisible(s);
}
void Hp_Main_Task_2::update_ble(bool s)
{
    ui->task_ble->setVisible(s);
}
void Hp_Main_Task_2::update_headset(bool s)
{
    ui->task_headset->setVisible(s);
}

void Hp_Main_Task_2::update_battery_stylesheet(QString style)
{
    ui->label_battery->setStyleSheet(style);
}

void Hp_Main_Task_2::update_auto_focus(bool s)
{
    qDebug() << "Hp_Main_Task::update_auto_focus   " << s;
    if(s == true){
        ui->task_gps->setVisible(true);
    }else{

        ui->task_gps->setVisible(false);
    }
}
