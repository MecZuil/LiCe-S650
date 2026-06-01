#include "hp_autoupload_dialog.h"
#include "ui_hp_autoupload_dialog.h"

Hp_Autoupload_Dialog::Hp_Autoupload_Dialog(QWidget *parent) :
    QWidget(parent),
  ui(new Ui::Hp_Autoupload_Dialog)
{
    ui->setupUi(this);

    ui->frame_3->close();
    isdownload_dialog = false;
}
Hp_Autoupload_Dialog::~Hp_Autoupload_Dialog()
{
    delete ui;
}
void Hp_Autoupload_Dialog::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->resize(480,272);

        ui->frame_3->setGeometry(ui->frame_3->x() / 1.7,ui->frame_3->y() / 1.7,ui->frame_3->width() / 1.7,ui->frame_3->height() / 1.7);
        ui->label_5->setGeometry(ui->label_5->x() / 1.7,ui->label_5->y() / 1.7,ui->label_5->width() / 1.7,ui->label_5->height() / 1.7);
        ui->pushButton_ok_3->setGeometry(ui->pushButton_ok_3->x() / 1.7,ui->pushButton_ok_3->y() / 1.7,ui->pushButton_ok_3->width() / 1.7,ui->pushButton_ok_3->height() / 1.7);
        ui->frame_2->setGeometry(ui->frame_2->x() / 1.7,ui->frame_2->y() / 1.7,ui->frame_2->width() / 1.7,ui->frame_2->height() / 1.7);
        ui->label_2->setGeometry(ui->label_2->x() / 1.7,ui->label_2->y() / 1.7,ui->label_2->width() / 1.7,ui->label_2->height() / 1.7);
        ui->pushButton_cancel->setGeometry(ui->pushButton_cancel->x() / 1.7,ui->pushButton_cancel->y() / 1.7,ui->pushButton_cancel->width() / 1.7,ui->pushButton_cancel->height() / 1.7);
        ui->pushButton_ok->setGeometry(ui->pushButton_ok->x() / 1.7,ui->pushButton_ok->y() / 1.7,ui->pushButton_ok->width() / 1.7,ui->pushButton_ok->height() / 1.7);
        ui->frame->setGeometry(ui->frame->x() / 1.7,ui->frame->y() / 1.7,ui->frame->width() / 1.7,ui->frame->height() / 1.7);
        ui->label->setGeometry(ui->label->x() / 1.7,ui->label->y() / 1.7,ui->label->width() / 1.7,ui->label->height() / 1.7);
        ui->label_3->setGeometry(ui->label_3->x() / 1.7,ui->label_3->y() / 1.7,ui->label_3->width() / 1.7,ui->label_3->height() / 1.7);
        ui->progressBar->setGeometry(ui->progressBar->x() / 1.7,ui->progressBar->y() / 1.7,ui->progressBar->width() / 1.7,ui->progressBar->height() / 1.7);

        ui->label->setFont(font10);
        ui->label_3->setFont(font10);
        ui->label_2->setFont(font10);
        ui->pushButton_cancel->setFont(font10);
        ui->pushButton_ok->setFont(font10);
        ui->label_5->setFont(font10);
        ui->pushButton_ok_3->setFont(font10);
    }
}
void Hp_Autoupload_Dialog::setText(int page,int zon,QString content)
{
    ui->label->setText(QString::number(page) + "/" + QString::number(zon));
    ui->progressBar->setMaximum(zon);
    ui->progressBar->setValue(page);
    ui->label_3->setText(content);
}
void Hp_Autoupload_Dialog::setFrame3Text(QString content)
{
    ui->label_5->setText(content);
}
void Hp_Autoupload_Dialog::setFrame(bool ret)
{
    if(ret)
    {
        ui->frame_3->close();
        ui->frame_2->close();
        ui->frame->move((this->width() - ui->frame->width()) / 2,(this->height() - ui->frame->height()) / 2);
        ui->frame->show();
    }else{
        ui->frame_3->close();
        ui->frame->close();
        ui->frame_2->move((this->width() - ui->frame_2->width()) / 2,(this->height() - ui->frame_2->height()) / 2);
        ui->frame_2->show();
    }
}
void Hp_Autoupload_Dialog::upload_break()
{
    ui->frame->close();
    ui->frame_2->close();
    ui->frame_3->move((this->width() - ui->frame_3->width()) / 2,(this->height() - ui->frame_3->height()) / 2);
    ui->frame_3->show();
}
void Hp_Autoupload_Dialog::down_load(int ret)//作为download界面处理函数
{
    if(ret == 1)
    {
        ui->frame->close();
        ui->frame_2->close();
        ui->frame_3->close();
    }else if(ret == 2){
        ui->frame->close();
        ui->frame_2->close();
        ui->frame_3->show();
    }
}
void Hp_Autoupload_Dialog::on_pushButton_cancel_clicked()
{
    close();
}

void Hp_Autoupload_Dialog::on_pushButton_ok_clicked()
{
    signal_StartAutoUpload_once(true);//这个弹窗是只有在ftp上传模式时才会被触发，所以，只能上传台账图片
}

void Hp_Autoupload_Dialog::on_pushButton_ok_3_clicked()
{
    if(isdownload_dialog)
    {
        close();
    }else{
        signal_close();//也是为了清除主界面标志位
    }
}
void Hp_Autoupload_Dialog::changeEvent(QEvent *e)
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

