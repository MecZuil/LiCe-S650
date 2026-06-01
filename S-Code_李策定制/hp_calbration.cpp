#include "hp_calbration.h"
#include "ui_hp_calbration.h"

hp_calbration::hp_calbration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hp_calbration)
{
    ui->setupUi(this);
}

hp_calbration::~hp_calbration()
{
    delete ui;
}

void hp_calbration::slot_pc_sys_mag_calsw_start(unsigned char return_value)
{
    qDebug("slot_pc_sys_mag_calsw_start return_value:0x%02x",return_value);
}

void hp_calbration::slot_pc_sys_mag_calsw_stop(unsigned char return_value)
{
    qDebug("slot_pc_sys_mag_calsw_stop return_value:0x%02x",return_value);
}

void hp_calbration::on_toolButton_clicked()
{
    signal_pc_sys_mag_calsw_stop();
    ui->toolButton->show();
    ui->pushButton->show();
    ui->toolButton_2->close();
}

void hp_calbration::on_toolButton_2_clicked()
{
    this->close();
}

void hp_calbration::on_pushButton_clicked()
{
    signal_pc_sys_mag_calsw_start();
    ui->toolButton->close();
    ui->pushButton->close();
    ui->toolButton_2->show();
}


void hp_calbration::mousePressEvent(QMouseEvent* e)
{

    signal_update_lcdoff_time(false);
}

void hp_calbration::keyReleaseEvent(QKeyEvent *ev)
{
    signal_update_lcdoff_time(false);
    switch(ev->key())
    {
         case KEY_RETURN:
                this->close();
                break;
        default:
            break;
    }
}

void hp_calbration::changeEvent(QEvent *e)
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
