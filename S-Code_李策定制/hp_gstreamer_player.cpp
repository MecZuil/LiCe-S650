#include "hp_gstreamer_player.h"
#include  "ui_hp_gstreamer_player.h"

//element:一个可以安装垫板(pad)的模块，一个完整的pipeline(输入输出线路)由多个element模块组成，一个element的srcpad连接着下一级的sinkpad
//pad:垫板,分为srcpad(产生数据垫板)，sinkpad(消费数据垫板)，可以附着在element(模块)上，可同时附着多个
//bin:容器，用于管理多个element，我们可以通过bin，管理element，省的自己管理，pipeline继承于bin
//bus:总线，用于存储pipeline运行过程中产生的信息

//buffers：由src到sink之间的数据流
//events：事件
//Queries：获取总时长

//playbin：相当于一个bin，不过这个更省力，会自动选择所需的src、解码器、sink

//GST_BIN：强制转化为bin类型
//gst_bin_add_many (GST_BIN (pipeline), source, filter, sink, NULL);//把我们创建的element添加到pipeline中，按顺序
//if (gst_element_link_many (source, filter, sink, NULL) != TRUE) {//连接element
//g_object_set (source, "pattern", 0, NULL); //设置element的pattern属性可以控制测试图像的类型

//一个src pad只能与一个sink pad相连

hp_gstreamer_player::hp_gstreamer_player(QWidget *parent) : QWidget(parent),
    ui(new Ui::hp_gstreamer_player)
{
    ui->setupUi(this);

    m_objectName = HP_GST_SELECT_CLOSE;

    duration = GST_CLOCK_TIME_NONE;
    playbin2 = NULL;
    display_HDMI = false;
    isStoped = false;
    ui->toolButton_speed->close();
    ui->verticalSlider->close();

//    displayWnd = new QVideoWidget(this);
//    displayWnd->setStyleSheet("background-color:#000000");
//    displayWnd->setGeometry(160,20,this->width() - 320,this->height()-65);

    queryTimer = new QTimer();
    connect(queryTimer,SIGNAL(timeout()),this,SLOT(slotTimerout()));
}
hp_gstreamer_player::~hp_gstreamer_player()
{
    delete ui;
}
void hp_gstreamer_player::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        this->resize(480,272);
        ui->frame_control_2->setGeometry(96,0,384,272);
        ui->toolButton_speed->setGeometry(6,235,54,41);
        ui->toolButton_close->setGeometry(2,0,88,41);
        ui->checkBox->setGeometry(2,47,88,41);
        ui->verticalSlider->setGeometry(65,94,24,222);
    }
}
void hp_gstreamer_player::hp_gst_play(QString file)
{
    playbin2 = gst_element_factory_make ("playbin", "playbin2");//新建元件,单个元素作为管道  (element类型、element名称)，设置名称后应该可以用factory_find查找
    if (!playbin2)
    {
      qDebug() << "Not all elements could be created.";
      return ;
    }

    {
        qDebug() << "==============================================================";
//        // 创建管道
//           GstElement *pipeline = gst_pipeline_new("video-player");
//           qDebug() << "==============================================================" << __LINE__;

//           // 创建元素
//           GstElement *filesrc = gst_element_factory_make("filesrc", "source");
//           qDebug() << "==============================================================" << __LINE__;
//           GstElement *decodebin = gst_element_factory_make("decodebin", "decoder");
//           qDebug() << "==============================================================" << __LINE__;
//           GstElement *videoscale = gst_element_factory_make("videoscale", "videoscale");
//           qDebug() << "==============================================================" << __LINE__;
//           GstElement *videoconvert1 = gst_element_factory_make("videoconvert", "videoconvert1");
//           qDebug() << "==============================================================" << __LINE__;
//           GstElement *videoconvert2 = gst_element_factory_make("videoconvert", "videoconvert2");
//           qDebug() << "==============================================================" << __LINE__;
//           GstElement *tee = gst_element_factory_make("tee", "tee");
//           qDebug() << "==============================================================" << __LINE__;
//           GstElement *queue1 = gst_element_factory_make("queue", "queue1");
//           qDebug() << "==============================================================" << __LINE__;
//           GstElement *queue2 = gst_element_factory_make("queue", "queue2");
//           qDebug() << "==============================================================" << __LINE__;
//           GstElement *fbdevsink1 = gst_element_factory_make("fbdevsink", "fbdevsink1");
//           qDebug() << "==============================================================" << __LINE__;
//           GstElement *fbdevsink2 = gst_element_factory_make("fbdevsink", "fbdevsink2");
//           qDebug() << "==============================================================" << __LINE__;

//           // 检查元素是否创建成功
//           if (!pipeline || !filesrc || !decodebin || !videoscale || !videoconvert1 || !videoconvert2 ||
//               !tee || !queue1 || !queue2 || !fbdevsink1 || !fbdevsink2) {
//               qDebug() << "==============================================================" << __LINE__;
//           }

//           qDebug() << "==============================================================" << __LINE__;
//           // 设置文件路径
//           g_object_set(G_OBJECT(filesrc), "location", "/run/media/mmcblk2p1/DCIM/VID_20240723_112852.avi", NULL);
//           qDebug() << "==============================================================" << __LINE__;

//           // 将所有元素添加到管道中
//           gst_bin_add_many(GST_BIN(pipeline), filesrc, decodebin, videoscale, videoconvert1, videoconvert2,
//                            tee, queue1, queue2, fbdevsink1, fbdevsink2, NULL);
//           qDebug() << "==============================================================" << __LINE__;

//           // 连接元素
//           gboolean link_ok = gst_element_link(filesrc, decodebin);
//           if(link_ok)
//           {
//               qDebug() << "gst_element_link(filesrc, decodebin) link_ok";
//           }
//           qDebug() << "==============================================================" << __LINE__;
//           link_ok &= gst_element_link_many(decodebin, videoscale, videoconvert1, tee, NULL);
//           if(link_ok)
//           {
//               qDebug() << "gst_element_link_many(decodebin, videoscale, videoconvert1, tee, NULL) link_ok";
//           }
//           qDebug() << "==============================================================" << __LINE__ ;
//           link_ok &= gst_element_link_many(tee, queue1, videoconvert2, fbdevsink1, NULL);
//           if(link_ok)
//           {
//               qDebug() << "gst_element_link_many(tee, queue1, videoconvert2, fbdevsink1, NULL) link_ok";
//           }
//           qDebug() << "==============================================================" << __LINE__;
//           link_ok &= gst_element_link_many(tee, queue2, fbdevsink2, NULL);
//           if(link_ok)
//           {
//               qDebug() << "gst_element_link_many(tee, queue2, fbdevsink2, NULL) link_ok";
//           }
//           qDebug() << "==============================================================" << __LINE__;

//           if (!link_ok) {
//               qDebug() << "==============================================================" << __LINE__;
//           }

//           // 设置fbdevsink设备路径
//           qDebug() << "==============================================================" << __LINE__;
//           g_object_set(G_OBJECT(fbdevsink1), "device", "/dev/fb0", NULL);
//           g_object_set(G_OBJECT(fbdevsink2), "device", "/dev/fb2", NULL);
//        loop = g_main_loop_new(NULL, FALSE);
        pipeline = gst_parse_launch("filesrc location=/run/media/mmcblk2p1/DCIM/VID_20240723_112852.avi ! decodebin ! videoscale ! video/x-raw,height=480 ! tee name=t ! queue ! videoconvert ! fbdevsink device=/dev/fb0 t. ! queue ! videoconvert ! fbdevsink device=/dev/fb2", NULL);

        if (!pipeline) {
            qDebug() << "Failed to create pipeline";
        }
        isStoped = false;

        // Start playing
        gst_element_set_state(pipeline, GST_STATE_PLAYING);
           qDebug() << "==============================================================";
    }
    qDebug("Running...\n");
//    g_main_loop_run(loop);

    // Out of the main loop, clean up nicely
    qDebug("Stopping...\n");

//    QString fileName = "file:////run/media/mmcblk2p1/DCIM/" + file;
//    g_object_set(playbin2, "uri", fileName.toUtf8().data(), NULL);//初始化元件属性

//    duration = GST_CLOCK_TIME_NONE;//这个非常重要，不然就是上一次的总时长

//    g_object_set(G_OBJECT(playbin2), "volume", 50*1.0/100, NULL);//设置这个管道的音量
//    g_object_set(G_OBJECT(playbin2), "mute", FALSE, NULL);//设置这个管道是否静音

//    GstElement *video_sink = gst_element_factory_make ("overlaysink", NULL);
//    g_object_set(playbin2,"video-sink",video_sink,NULL);
//    g_object_set(G_OBJECT(video_sink), "display-master", TRUE, NULL);//控制是否在LCD屏输出
//    g_object_set(G_OBJECT(video_sink), "display-slave", FALSE, NULL);//控制是否HDMI输出


//    GstStateChangeReturn ret;
//    ret = gst_element_set_state (playbin2, GST_STATE_PLAYING);//设置元件状态为播放
//    if(ret == GST_STATE_CHANGE_FAILURE)
//    {
//        qDebug() << "Unable to set the pipeline to the playing state.";
//        return;
//    }
//    else
//    {

//    }

//    isStoped = false;
//    speed = 0;
//    oldcurrent = -1;
//    ui->toolButton_speed->setText("1X");

//    queryTimer->start(1000);
}

void hp_gstreamer_player::hp_gst_setSpeed(double speed)
{
    if(playbin2 == NULL)
    {
        return;
    }
    gdouble rate = speed;

    gint64 current = -1;
    if(!gst_element_query_position(playbin2,GST_FORMAT_TIME,&current))
    {
        qDebug() << "Get Current Time Error";
        return;
    }
    GstEvent *seek_event;//新建事件
    seek_event = gst_event_new_seek(rate,GST_FORMAT_TIME,(GstSeekFlags)(GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_ACCURATE),GST_SEEK_TYPE_SET,current,GST_SEEK_TYPE_END,0);//若速率小于0，则是另一种写法

    GstElement *video_sink = NULL;
    g_object_get(playbin2,"video-sink",&video_sink,NULL);

    gst_element_send_event(video_sink,seek_event);
}

void hp_gstreamer_player::on_checkBox_clicked(bool checked)
{
    qDebug() << "hp_gstreamer_player::on_checkBox_clicked";
    if(!isStoped)
    {
        isStoped = true;
        gst_element_set_state(pipeline, GST_STATE_PAUSED);
    }
    else
    {
        gst_element_set_state(pipeline, GST_STATE_PLAYING);
        isStoped = false;
    }
//    gst_object_unref(GST_OBJECT(pipeline));
//    g_main_loop_unref(loop);

//    this->close();
//    m_objectName = HP_GST_SELECT_PAUSE;
//    signal_update_lcdoff_time(false);
//    if(checked)
//    {
//        GstStateChangeReturn ret;
//        ret = gst_element_set_state (playbin2, GST_STATE_PLAYING);//设置元件状态为播放
//        isStoped = false;
//        if (ret == GST_STATE_CHANGE_FAILURE)
//        {

//        }
//    }else{
//        if(playbin2 != NULL)
//        {
//            GstStateChangeReturn ret;
//            isStoped = true;
//            ret = gst_element_set_state(playbin2,GST_STATE_PAUSED);
//            if (ret == GST_STATE_CHANGE_FAILURE)
//            {

//            }
//        }
//    }
}
void hp_gstreamer_player::slotTimerout()
{
    GstFormat fmt = GST_FORMAT_TIME;
    if (!GST_CLOCK_TIME_IS_VALID (duration))//判断总时长是否无效，若没有总时长
    {
        if (!gst_element_query_duration (playbin2, fmt, &duration))//查询总时长，这里为什么查询的是音频的总时长？？？
        {
            qDebug() << "Could not query current duration.";
        }else
        {
            ui->verticalSlider->setRange(0,(gdouble)duration/GST_SECOND);
        }
    }

//    qDebug() << "the playbin duration is" << QString::number(duration);

    gint64 current = -1;
    if (gst_element_query_position (playbin2, fmt, &current))//获取当前时间
    {
        gchar *infor;
        infor  = g_strdup_printf("%" GST_TIME_FORMAT " / %" GST_TIME_FORMAT "\r",
                 GST_TIME_ARGS (current), GST_TIME_ARGS (duration));
        qDebug() << QString(infor);//设置时间label
        if(current >= duration)
        {
            if(queryTimer->isActive())
            {
                queryTimer->stop();
            }
            on_toolButton_close_clicked();
        }/*else if(current == oldcurrent && !isStoped && oldcurrent != -1){
            qDebug() << "is In End AVI == > " << current << " ; " << oldcurrent << " ; " << (!isStoped) << " ; " << (oldcurrent);
            if(queryTimer->isActive())
            {
                queryTimer->stop();
            }
            on_toolButton_close_clicked();
        }*/
        qDebug() << "compare avi = " << (current == oldcurrent) << (!isStoped) << (oldcurrent != -1);
        oldcurrent = current;

        if(!ui->verticalSlider->isSliderDown())//若没按下
        {
            ui->verticalSlider->setValue(current/GST_SECOND);//设置时间轴
        }
    }
}

void hp_gstreamer_player::on_toolButton_close_clicked()
{
    m_objectName = HP_GST_SELECT_CLOSE;
    signal_update_lcdoff_time(false);
    GstStateChangeReturn ret;
    if(playbin2 != NULL)
    {
        ret = gst_element_set_state (playbin2, GST_STATE_READY);
        if (ret == GST_STATE_CHANGE_FAILURE)
        {

        }
    }

    if(queryTimer->isActive())
    {
        queryTimer->stop();
    }
    gst_element_set_state (playbin2, GST_STATE_NULL);
    gst_object_unref (playbin2);
    playbin2 = NULL;

    this->close();
}

void hp_gstreamer_player::on_verticalSlider_sliderMoved(int position)
{
    double value = ui->verticalSlider->value();
    gst_element_seek_simple(playbin2,GST_FORMAT_TIME,GstSeekFlags(GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_KEY_UNIT),(gint64)(value * GST_SECOND));
}

void hp_gstreamer_player::on_toolButton_speed_clicked()
{
    m_objectName = HP_GST_SELECT_SPEED;
    signal_update_lcdoff_time(false);
    speed++;
    if(speed > 8)
    {
        speed = 0;
    }
    if(speed == 0)
    {
        hp_gst_setSpeed(1.0);
        ui->toolButton_speed->setText("1X");
    }else if(speed == 1)
    {
        hp_gst_setSpeed(1.25);
        ui->toolButton_speed->setText("1.25X");
    }else if(speed == 2)
    {
        hp_gst_setSpeed(1.5);
        ui->toolButton_speed->setText("1.5X");
    }else if(speed == 3)
    {
        hp_gst_setSpeed(2.0);
        ui->toolButton_speed->setText("2.0X");
    }else if(speed == 4)
    {
        hp_gst_setSpeed(2.5);
        ui->toolButton_speed->setText("2.5X");
    }else if(speed == 5)
    {
        hp_gst_setSpeed(3.0);
        ui->toolButton_speed->setText("3.0X");
    }else if(speed == 6)
    {
        hp_gst_setSpeed(0.25);
        ui->toolButton_speed->setText("0.25X");
    }else if(speed == 7)
    {
        hp_gst_setSpeed(0.5);
        ui->toolButton_speed->setText("0.5X");
    }else if(speed == 8)
    {
        hp_gst_setSpeed(0.75);
        ui->toolButton_speed->setText("0.75X");
    }
}
void hp_gstreamer_player::toolButton_closeStyleSet(bool state)
{
    if(!state)
        ui->toolButton_close->setStyleSheet("QToolButton {border-image:url(:/res/res/back_n.png);background:transparent;}  ");
    else
        ui->toolButton_close->setStyleSheet("QToolButton {border-image:url(:/res/res/back_n.png);background:transparent;background-color:rgba(97,223,249,45);}  ");
}

void hp_gstreamer_player::toolButton_speedStyleSet(bool state)
{
    if(!state)
        ui->toolButton_speed->setStyleSheet("QToolButton { \
                                            color:#7CA6C9; \
                                            border:0px solid #000000; \
                                            background:transparent; \
                                        }");
    else
        ui->toolButton_speed->setStyleSheet("QToolButton { \
                                            color:#7CA6C9; \
                                            border:0px solid #000000; \
                                            background:transparent; \
                                            background-color:rgba(97,223,249,45); \
                                        }");
}
void hp_gstreamer_player::toolButton_pauseStyleSet(bool state)
{
    if(!state)
        ui->checkBox->setStyleSheet("QCheckBox{ \
                                    background:transparent; \
                                    } \
                                    QCheckBox::indicator:unchecked { \
                                        border-image:url(':/res/res/media_pause.png'); \
                                        width:150px; \
                                        height:70px; \
                                    } \
                                    QCheckBox::indicator:checked { \
                                        border-image:url(':/res/res/media_play.png'); \
                                        width:150px; \
                                        height:70px; \
                                    }"
                                    );
    else
        ui->checkBox->setStyleSheet("QCheckBox{ \
                                    background:transparent; \
                                    } \
                                    QCheckBox::indicator:unchecked { \
                                        border-image:url(':/res/res/media_pause.png'); \
                                        background-color:rgba(97,223,249,45); \
                                        width:150px; \
                                        height:70px; \
                                    } \
                                    QCheckBox::indicator:checked { \
                                        border-image:url(':/res/res/media_play.png'); \
                                        background-color:rgba(97,223,249,45); \
                                        width:150px; \
                                        height:70px; \
                                    }"
                                    );
}
void hp_gstreamer_player::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug() << "hp_gstreamer_player::keyReleaseEvent == > " << ev->key() << " ; " << m_objectName;
    signal_update_lcdoff_time(true);
    switch(ev->key())
    {
    case KEY_RETURN:
        on_toolButton_close_clicked();
        break;
    }
}
