#include "hp_media_player_gplay.h"
#include "ui_hp_media_player_gplay.h"

char *cmd_rate = "c\r\n1\r\n";        //改播放速率 0.5-1
char *cmd_pause = "a\r\n";

Hp_Media_Player_Gplay::Hp_Media_Player_Gplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Media_Player_Gplay)
{
    ui->setupUi(this);
    running = false;
    ui->frame_display->setGeometry(80,0,640,480);
    process = new QProcess(this);
    connect(process,SIGNAL(readyRead()),this,SLOT(ReadData()));
}

Hp_Media_Player_Gplay::~Hp_Media_Player_Gplay()
{
    delete ui;
}

void Hp_Media_Player_Gplay::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        this->resize(480,272);
        ui->frame_control->setGeometry(0,0,96,272);
        ui->toolButton_close->setGeometry(3,60,90,40);
        ui->toolButton_pause->setGeometry(3,150,90,40);
        ui->frame_display->setGeometry(96,0,384,272);
        ui->hs_time->setGeometry(50,220,284,29);

    }else{
        ui->frame_display->setGeometry(160,0,640,480);
    }
}
void Hp_Media_Player_Gplay::changeEvent(QEvent *e)
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
void Hp_Media_Player_Gplay::keyReleaseEvent(QKeyEvent *ev)
{
    signal_update_lcdoff_time(true);
}

bool Hp_Media_Player_Gplay::start_play_media(QString filePath)
{
//    AVFormatContext *formatCtx = NULL;
//    const char* cstr = qPrintable("/run/media/mmcblk2p1/DCIM/" + file);
//    const char *filename = cstr;
//    qDebug() << "fileName" << filename;
//    // 初始化 FFmpeg
//    av_register_all();

//    // 打开文件
//    if (avformat_open_input(&formatCtx, filename, NULL, NULL) < 0) {
//        printf("无法打开文件\n");
//    }

//    // 读取文件信息
//    if (avformat_find_stream_info(formatCtx, NULL) < 0) {
//        printf("无法获取流信息\n");
//        avformat_close_input(&formatCtx);
//    }

//    // 获取视频总时长
//    int64_t duration = formatCtx->duration; // 时长，单位：微秒
//    printf("视频时长: %lld 微秒\n", duration);
//    qDebug() << "deration " <<duration;
//    // 转换为秒
//    double duration_in_seconds = (double)duration / AV_TIME_BASE;
//    printf("视频时长: %.2f 秒\n", duration_in_seconds);

    // 释放资源
//    avformat_close_input(&formatCtx);

    QString SameScreenCmd;
    std::string strSameScrValue = " --video-sink=\"overlaysink display-master=true display-slave=true \"";
    QByteArray stdSameScrByte = QByteArray::fromStdString(strSameScrValue);
    QString SameScreenCmdPara = stdSameScrByte;
    SameScreenCmd = "gplay-1.0 "+filePath+SameScreenCmdPara;
    qDebug()<<SameScreenCmd;
    running = true;
    rate_flag = false;
    ui->hs_time->setValue(0);
    ui->hs_time->setVisible(false);
    process->start(SameScreenCmd);
    ui->toolButton_pause->setChecked(true);
    m_objectName = "toolButton_pause";
    toolButton_pauseStyleSet(true);
    toolButton_closeStyleSet(false);
    qDebug() << "Start -- avi";

    return true;
}

bool Hp_Media_Player_Gplay::stop_play_media()
{
    on_toolButton_close_released();
}

void Hp_Media_Player_Gplay::on_toolButton_close_released()
{
    signal_update_lcdoff_time(false);
 //   qDebug()<<"running:"<<running;
    ui->toolButton_pause->setChecked(false);
    if(running)
    {
        process->close();
        close();
    }
    m_objectName = "toolButton_close";
    toolButton_closeStyleSet(true);
    toolButton_pauseStyleSet(false);
}

void Hp_Media_Player_Gplay::on_toolButton_pause_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
    if(running)
    {
        process->write(cmd_pause);
    }
    m_objectName = "toolButton_pause";
    toolButton_pauseStyleSet(true);
    toolButton_closeStyleSet(false);
}

/*
 *
 * "EOS Found\n"
"Total showed frames (3192), display master blited (3192), playing for (0:04:15.353069364), fps (12.5"
"getNextItem No next item!\n"
"No more media file, exit gplay!\n"
"Exit display thread\n"
"FSL_PLAYENGINE_UI_MSG_EXIT\n"
"fsl_player_deinit\n"
 *
 */

void Hp_Media_Player_Gplay::ReadData()                //应该是播放
{
    ui->hs_time->setVisible(false);     //使它不使能
    while (!process->atEnd()) {
        QString s = QLatin1String(process->readLine());
        qDebug()<<s;
        if(s.indexOf("[Playing (No Repeated)][Vol=1.0][00:00:00/00:00:00]")>=0)
        {
            qDebug()<<s;
            if(!rate_flag)
            {
                process->write(cmd_rate);
                rate_flag = true;
            }
            if(!this->isVisible())
                this->show();//为了防止刚进入avi视频播放时黑屏的方法
        }
        if(s.indexOf("[SF (0.5X)(No Repeated)][Vol=1.0]"))
        {

            int pos = s.lastIndexOf("[");

            if(pos == 34)
            {

                QString t_str = s.mid(pos+1,17);
                QString total_str = t_str.mid(9,8);
                QString now_str = t_str.mid(0,8);

                QString total_hh,total_mm,total_ss;
                total_hh = total_str.mid(0,2);
                total_mm = total_str.mid(3,2);
                total_ss = total_str.mid(6,2);

                int total_sec = total_hh.toInt()*3600+total_mm.toInt()*60+total_ss.toInt();

                QString now_hh,now_mm,now_ss;
                now_hh = now_str.mid(0,2);
                now_mm = now_str.mid(3,2);
                now_ss = now_str.mid(6,2);
                int now_sec = now_hh.toInt()*3600+now_mm.toInt()*60+now_ss.toInt();
                qDebug() << total_sec << now_sec;
                ui->hs_time->setMaximum(total_sec);
                ui->hs_time->setValue(now_sec);

            }
        }

        if(s.indexOf("EOS Found")!=-1)
        {
            ui->hs_time->setVisible(false);                         //新加
            close();
        }
    }
}

void Hp_Media_Player_Gplay::toolButton_closeStyleSet(bool state)
{
    if(!state)
        ui->toolButton_close->setStyleSheet("QToolButton{ border-image:url(:/res/res/back_n.png); color:#79FFFF; width:146px; height:25px }");
    else
        ui->toolButton_close->setStyleSheet("QToolButton{ border-image:url(:/res/res/back_s.png); color:#79FFFF; width:146px; height:25px }");
}

void Hp_Media_Player_Gplay::toolButton_pauseStyleSet(bool state)
{
    if(!state)
    {
        if(!ui->toolButton_pause->isChecked() )
            ui->toolButton_pause->setStyleSheet("QToolButton{ border-image:url(:/res/res/media_play.png); color:#79FFFF; }");
        else
            ui->toolButton_pause->setStyleSheet("QToolButton{ border-image:url(:/res/res/media_pause.png); color:#79FFFF; }");
    }
    else
    {
        if( !ui->toolButton_pause->isChecked() )
            ui->toolButton_pause->setStyleSheet("QToolButton{ border-image:url(:/res/res/media_play.png); color:#79FFFF; }");
        else
            ui->toolButton_pause->setStyleSheet("QToolButton{ border-image:url(:/res/res/media_pause.png); color:#79FFFF; }");

    }
}

