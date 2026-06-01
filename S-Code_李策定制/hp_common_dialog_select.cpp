#include "hp_common_dialog_select.h"
#include "ui_hp_common_dialog_select.h"

hp_common_dialog_select::hp_common_dialog_select(QWidget *parent) : QWidget(parent),
    ui(new Ui::hp_common_dialog_select)
{
    ui->setupUi(this);

//    this->setGeometry((800 - this->width()) / 2,(480 - this->height()) / 2,this->width(),this->height());
}
hp_common_dialog_select::~hp_common_dialog_select()
{
    delete ui;
}
void hp_common_dialog_select::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

//        this->setGeometry(78,89,this->width() / 1.7,this->height() / 1.7);

        ui->frame->setGeometry(ui->frame->x() / 1.7,ui->frame->y() / 1.7,ui->frame->width() / 1.7,ui->frame->height() / 1.7);
        ui->pushButton_task->setGeometry(ui->pushButton_task->x() / 1.7,ui->pushButton_task->y() / 1.7,ui->pushButton_task->width() / 1.7,ui->pushButton_task->height() / 1.7);
        ui->pushButton_normal->setGeometry(ui->pushButton_normal->x() / 1.7,ui->pushButton_normal->y() / 1.7,ui->pushButton_normal->width() / 1.7,ui->pushButton_normal->height() / 1.7);
        ui->pushButton_cancel->setGeometry(ui->pushButton_cancel->x() / 1.7,ui->pushButton_cancel->y() / 1.7,ui->pushButton_cancel->width() / 1.7,ui->pushButton_cancel->height() / 1.7);
        ui->label->setGeometry(ui->label->x() / 1.7,ui->label->y() / 1.7,ui->label->width() / 1.7,ui->label->height() / 1.7);

        ui->pushButton_task->setFont(font10);
        ui->pushButton_normal->setFont(font10);
        ui->pushButton_cancel->setFont(font10);
        ui->label->setFont(font10);
    }
}

void hp_common_dialog_select::hp_setBt1Text(QString text)
{
    ui->pushButton_task->setText(text);
}
void hp_common_dialog_select::hp_setBt2Text(QString text)
{
    ui->pushButton_normal->setText(text);
}
void hp_common_dialog_select::hp_setBt3Text(QString text)
{
    ui->pushButton_cancel->setText(text);
}
void hp_common_dialog_select::hp_setLabelText(QString text)
{
    ui->label->setText(text);
}
void hp_common_dialog_select::on_pushButton_task_clicked(bool checked)
{
    hp_signal_bt_click(1);
}

void hp_common_dialog_select::on_pushButton_normal_clicked(bool checked)
{
    hp_signal_bt_click(2);
}

void hp_common_dialog_select::on_pushButton_cancel_clicked(bool checked)
{
    hp_signal_bt_click(3);
}
