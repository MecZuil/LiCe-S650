#include  "hpmode.h"
#include  "ui_hpmode.h"
#include     <QDebug>
HpMode::HpMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HpMode)
{

    ui->setupUi(this);

    fidpid = false;
    if(FID_PID_MODE)
    {
        fidpid = true;
    }

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    this->setGeometry(160,30,this->width(),this->height());   // 96->160
    setFixedSize(this->width(), this->height());

}

HpMode::~HpMode()
{
    delete ui;
}

void HpMode::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->setGeometry(96,17,302,255);
        ui->frame->setGeometry(86,190,212,44);
        ui->toolButton_hongwai->setGeometry(2,2,40,40);
        ui->toolButton_hzh->setGeometry(128,2,40,40);
        ui->toolButton_kejian->setGeometry(44,2,40,40);
        ui->toolButton_msx->setGeometry(86,2,40,40);
        ui->toolButton_rdj->setGeometry(170,2,40,40);
        ui->frame_2->setGeometry(40,190,44,44);
        ui->toolButton_handfusion->setGeometry(2,2,40,40);
        ui->frame_handfution->setGeometry(40,50,44,126);
        ui->widget_handfution->setGeometry(0,0,44,126);
        ui->frame_pip->setGeometry(86,6,212,44);
        ui->toolButton_1_2->setGeometry(44,2,40,40);
        ui->toolButton_1_4->setGeometry(86,2,40,40);
        ui->toolButton_3_4->setGeometry(128,2,40,40);
        ui->toolButton_auto->setGeometry(2,2,40,40);
        ui->toolButton_rect_adjust->setGeometry(170,2,40,40);
        ui->frame_rdj->setGeometry(170,2,40,40);
        ui->frame_rdj_2->setGeometry(170,2,40,40);

        ui->toolButton_rdj_adjust->setGeometry(0,0,40,40);
        ui->toolButton_rdj_adjust_2->setGeometry(0,0,40,40);

        ui->toolButton_hongwai->setFont(font10);
        ui->toolButton_hzh->setFont(font10);
        ui->toolButton_kejian->setFont(font10);
        ui->toolButton_msx->setFont(font10);
        ui->toolButton_rdj->setFont(font10);
        ui->toolButton_handfusion->setFont(font10);
        ui->widget_handfution->setFont(font10);
        ui->toolButton_1_2->setFont(font10);
        ui->toolButton_1_4->setFont(font10);
        ui->toolButton_3_4->setFont(font10);
        ui->toolButton_auto->setFont(font10);
        ui->toolButton_rect_adjust->setFont(font10);
        ui->toolButton_rdj_adjust->setFont(font10);
        ui->toolButton_rdj_adjust_2->setFont(font10);
    }

    ui->widget_handfution->hp_setDefine_S3x0(isSelect);
}

void HpMode::changeEvent(QEvent *e)
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



bool HpMode::set_mode(int m)
{
    signal_update_lcdoff_time(false);
    mode = m;
    qDebug("############## SET MODE ============  %d",m);
    switch(m)
    {
    case 0:
        ui->toolButton_hongwai->setChecked(true);
        ui->frame_pip->setVisible(false);
        ui->frame_rdj->setVisible(false);
        ui->frame_rdj_2->setVisible(false);
        break;
    case 1:
        ui->toolButton_kejian->setChecked(true);
        ui->frame_pip->setVisible(false);
        ui->frame_rdj->setVisible(false);
        ui->frame_rdj_2->setVisible(false);
        break;
    case 2:
        ui->toolButton_msx->setChecked(true);
        ui->frame_pip->setVisible(false);
        ui->frame_rdj->setVisible(false);
        ui->frame_rdj_2->setVisible(false);
        break;
    case 3:
        ui->toolButton_hzh->setChecked(true);
        ui->frame_pip->setVisible(true);
        ui->frame_rdj->setVisible(false);
        ui->frame_rdj_2->setVisible(false);
        break;
    case 4:
        ui->toolButton_rdj->setChecked(true);
        ui->frame_pip->setVisible(false);
//        ui->frame_rdj->setVisible(true);
        ui->frame_rdj_2->setVisible(true);
//        qDebug() << "rdj" << ui->frame_rdj->isVisible() << ui->toolButton_rdj_adjust->isVisible() << ui->frame_rdj->pos() << ui->toolButton_rdj_adjust->pos();
        break;
    case 5:
        ui->toolButton_rdj->setChecked(true);
        ui->frame_pip->setVisible(false);
        ui->frame_rdj->setVisible(false);
        break;
    default:
        ui->toolButton_hongwai->setChecked(true);
        ui->frame_pip->setVisible(false);
        ui->frame_rdj->setVisible(false);
//        if(FID_PID_MODE)
//            ui->frame_rdj->setVisible(false);
//        else
//            ui->frame_rdj->setVisible(true);
        break;
    }
    return true;
}

int HpMode::get_mode()
{
    return mode;
}

void HpMode::on_toolButton_rdj_adjust_2_clicked()
{
    qDebug() << "HpMode::on_toolButton_rdj_adjust_2_clicked";
    signal_rdj_set_adjust();
}
