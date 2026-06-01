#include "hp_common_dialog_cancel.h"
#include "ui_hp_common_dialog_cancel.h"

hp_common_dialog_cancel::hp_common_dialog_cancel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hp_common_dialog_cancel)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::ApplicationModal);
}
hp_common_dialog_cancel::~hp_common_dialog_cancel()
{
    delete ui;
}
void hp_common_dialog_cancel::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->resize(this->width() / 1.7,this->height() / 1.7);
        this->move((480 - this->width()) / 2,(272 - this->height()) / 2);

        ui->frame->resize(this->width(),this->height());

        ui->label_3->setGeometry(ui->label_3->x() / 1.7,ui->label_3->y() / 1.7,ui->label_3->width() / 1.7,ui->label_3->height() / 1.7);
        ui->pushButton_ok->setGeometry(ui->pushButton_ok->x() / 1.7,ui->pushButton_ok->y() / 1.7,ui->pushButton_ok->width() / 1.7,ui->pushButton_ok->height() / 1.7);

        ui->label_3->setFont(font10);
        ui->pushButton_ok->setFont(font10);
    }
}
void hp_common_dialog_cancel::Set_label_text(QString str)
{
    ui->label_3->setText(str);
}
void hp_common_dialog_cancel::Set_button_text(QString str)
{
    ui->pushButton_ok->setText(str);
}
void hp_common_dialog_cancel::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug() << "hp_common_dialog_cancel == > hp_common_dialog_cancel KeyRelease ";
    if(ev->type() == QKeyEvent::KeyRelease)
    {
        QKeyEvent *key_event = (QKeyEvent *)ev;
        if(key_event->key() == KEY_RETURN)
        {
            hp_signal_on_cancel_clicked();
        }/*else if(key_event->key() == KEY_OK)
        {
            hp_signal_on_cancel_clicked();
        }*/
    }
}

void hp_common_dialog_cancel::on_pushButton_ok_clicked()
{
    hp_signal_on_cancel_clicked();
    this->close();
}
