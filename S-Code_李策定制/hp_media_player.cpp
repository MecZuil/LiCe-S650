#include  "hp_media_player.h"
#include  "ui_hp_media_player.h"

Hp_Media_Player::Hp_Media_Player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Media_Player)
{
    ui->setupUi(this);
    isPause = true;
    m_pipeLineMsgTimer = new QTimer(this);
    connect(m_pipeLineMsgTimer, SIGNAL(timeout()), this, SLOT(query_position_and_duration()));
    ui->frame_display->setGeometry(80,0,640,480);
}

Hp_Media_Player::~Hp_Media_Player()
{
    delete ui;

}
void Hp_Media_Player::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        this->resize(480,272);
        ui->frame_control->setGeometry(0,0,48,272);
        ui->frame_control_2->setGeometry(48 + 384,0,48,272);
        ui->toolButton_close->setGeometry(3,60,45,40);
        ui->toolButton_pause->setGeometry(3,150,45,40);
        ui->frame_display->setGeometry(48,0,384,272);
        ui->hs_time->setGeometry(50,220,284,29);
    }else{
        ui->frame_display->setGeometry(80,0,640,480);
    }
}
void Hp_Media_Player::changeEvent(QEvent *e)
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
void Hp_Media_Player::keyReleaseEvent(QKeyEvent *ev)
{
    signal_update_lcdoff_time(true);
    signal_stop_video_analysis();
}

bool Hp_Media_Player::start_play_media(bool isAudio, QString filePath)
{
    QString SameScreenCmd;
    isPause = false;
    int Videoheight = this->height();
    int VideoWidth = ui->frame_display->width();
    if(isAudio)
    {
//        SameScreenCmd = "filesrc location=" + file + " ! decodebin name=dec dec. ! queue ! videoscale ! video/x-raw,height=" + QString::number(Videoheight) + ",width=" + QString::number(VideoWidth) + " ! tee name=t ! queue ! videoconvert ! fbdevsink device=/dev/fb0 t. ! queue ! videoconvert ! fbdevsink device=/dev/fb2 dec. ! queue ! audioconvert ! autoaudiosink";

        SameScreenCmd = "filesrc location=" + filePath + " ! decodebin name=dec dec. ! queue ! videoscale ! tee name=t ! queue ! videoconvert ! fbdevsink device=/dev/fb0 t. ! queue ! videoconvert ! fbdevsink device=/dev/fb2 dec. ! queue ! audioconvert ! autoaudiosink";
    }
    else
    {
        SameScreenCmd = "filesrc location=" + filePath + " ! decodebin ! videoscale ! video/x-raw,height=" + QString::number(Videoheight) + ",width=" + QString::number(VideoWidth) + " ! tee name=t ! queue ! videoconvert ! fbdevsink device=/dev/fb0 t. ! queue ! videoconvert ! fbdevsink device=/dev/fb2";
    }

    pipeline = gst_parse_launch(SameScreenCmd.toLocal8Bit().data(), NULL);

    if (!pipeline) {
        qDebug() << "Failed to create pipeline";
    }
    else
    {
        // 获取管道总线
        m_pipeLineMsgTimer->start(1000);
    }
    gst_element_set_state(pipeline, GST_STATE_PLAYING);//设置为播放状态GST_STATE_PLAYING， 暂停为GST_STATE_PAUSED,从暂停恢复播放只需要重新设置为PLAYING即可
    this->show();
    ui->hs_time->setValue(0);
    ui->hs_time->setVisible(false);
    ui->toolButton_pause->setChecked(true);
    toolButton_pauseStyleSet(true);
    toolButton_closeStyleSet(false);
    qDebug() << "Start -- avi";

    return true;
}

bool Hp_Media_Player::stop_play_media()
{
    on_toolButton_close_released();
}

void Hp_Media_Player::on_toolButton_close_released()
{
    signal_update_lcdoff_time(false);
    qDebug() << __func__;
    //结束播放释放管道
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(GST_OBJECT(pipeline));
    signal_stop_video_analysis();
    m_pipeLineMsgTimer->stop();
    toolButton_closeStyleSet(true);
    toolButton_pauseStyleSet(false);
    this->close();
}

void Hp_Media_Player::on_toolButton_pause_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
    if(!isPause)
    {
        isPause = true;
        gst_element_set_state(pipeline, GST_STATE_PAUSED);
    }
    else
    {
        isPause = false;
        gst_element_set_state(pipeline, GST_STATE_PLAYING);
    }
    toolButton_pauseStyleSet(true);
    toolButton_closeStyleSet(false);
}


void Hp_Media_Player::query_position_and_duration()
{
    qDebug() << __func__;
    gint64 position, duration;
    if (gst_element_query_position(pipeline, GST_FORMAT_TIME, &position) &&
        gst_element_query_duration(pipeline, GST_FORMAT_TIME, &duration)) {
        qDebug() << typeid(position).name() << position << duration;
        QString currTime = QString::number(position / 1000000000);
        QString totalTime = QString::number(duration / 1000000000);
        qDebug() << currTime.toInt() << totalTime.toInt() << currTime << totalTime;
        //gint64是long long int类型，单位是纳秒，所以要除1000000000才是正常的秒数
        if(currTime.toInt() >= totalTime.toInt() || (duration - position < 50000))
        {
            on_toolButton_close_released();
        }
    }
}

void Hp_Media_Player::toolButton_closeStyleSet(bool state)
{
    if(!state)
        ui->toolButton_close->setStyleSheet("QToolButton{ border-image:url(:/res/res/back_n.png); color:#79FFFF; width:146px; height:25px }");
    else
        ui->toolButton_close->setStyleSheet("QToolButton{ border-image:url(:/res/res/back_s.png); color:#79FFFF; width:146px; height:25px }");
}

void Hp_Media_Player::toolButton_pauseStyleSet(bool state)
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

