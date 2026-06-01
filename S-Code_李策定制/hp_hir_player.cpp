#include "hp_hir_player.h"
#include "ui_hp_hir_player.h"

hp_hir_player::hp_hir_player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hp_Hir_Player)
{
    ui->setupUi(this);
    fileName.clear();

    playstatus = new QTimer();
    playstatus->setInterval(500);

//    getmeasure = new QTimer();
//    getmeasure->setInterval(3000);

    connect(playstatus,SIGNAL(timeout()),this,SLOT(playstatusTimeout()));
//    connect(getmeasure,SIGNAL(timeout()),this,SLOT(getmeasureTimeout()));
}
hp_hir_player::~hp_hir_player()
{
    delete ui;

}
void hp_hir_player::changeEvent(QEvent *e)
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
void hp_hir_player::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        this->resize(480,272);
        ui->frame_control->setGeometry(0,0,96,272);
        ui->toolButton_close->setGeometry(3,24,90,40);
        ui->toolButton_pause->setGeometry(3,118,90,40);
        ui->toolButton_hir_analyse->setGeometry(3,206,90,40);
        ui->frame_display->setGeometry(96,0,384,272);
    }
}
void hp_hir_player::Start_Hir_video(QString filename)
{
    qDebug() << "HIR Play Start test ==> " << filename;
    fileName = filename;
    ui->toolButton_pause->setChecked(false);
    QByteArray barray = filename.toLatin1();
    char *mm = barray.data();
    signal_core_analysis_hir_twice_start(mm);
    playstatus->start();
//    getmeasure->start();
}
void hp_hir_player::playstatusTimeout()
{
    signal_core_get_hir_play_status();
}
//void hp_hir_player::getmeasureTimeout()
//{
//    signal_hir_analyse_get_measure();//获取视频的点线框内容
//}
void hp_hir_player::slot_core_get_hir_play_status(unsigned char return_value, int value)
{
//    qDebug("hp_hir_player::slot_core_get_hir_play_status:%02x",return_value);

    if(value == 1)
    {
        signal_playstatusTimeout();
        on_toolButton_close_released();
        if(playstatus->isActive())
            playstatus->stop();
//        if(getmeasure->isActive())
//            getmeasure->stop();
    }
}
void hp_hir_player::on_toolButton_close_released()
{
    qDebug() << "hir_mode CLOSE << " << (!ui->toolButton_pause->isChecked());
    if(!ui->toolButton_pause->isChecked())//不然下一次进来就是暂停状态
    {
        signal_core_annlysis_hir_twice_suspend(0);//播放
    }
    signal_core_analysis_hir_twice_stop_cut();
    signal_clear_measure();//清除屏幕的框
    if(playstatus->isActive())
        playstatus->stop();
//    if(getmeasure->isActive())
//        getmeasure->stop();
    close();
}

void hp_hir_player::on_toolButton_pause_clicked(bool checked)
{
    qDebug() << "hp_hir_player::CHECK ==> " << checked;
    if(checked)
        signal_core_annlysis_hir_twice_suspend(1);//暂停
    else
        signal_core_annlysis_hir_twice_suspend(0);//播放
}

void hp_hir_player::on_toolButton_hir_analyse_released()
{
    qDebug() << "hp_hir_player::on_toolButton_hir_analyse_released";
    signal_start_hir_analyse(fileName,ui->toolButton_pause->isChecked());
//    this->hide();
}
void hp_hir_player::set_toolButton_pause_checked(bool checked)
{
    ui->toolButton_pause->setChecked(checked);
}
void hp_hir_player::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug() << "hp_hir_player::keyReleaseEvent";
    if(ev->key() == KEY_RETURN)
    {
        on_toolButton_close_released();
    }
}
