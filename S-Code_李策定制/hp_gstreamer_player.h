#ifndef HP_GSTREAMER_PLAYER_H
#define HP_GSTREAMER_PLAYER_H

#include <QWidget>
#include <gst/gst.h>
#include <gst/audio/streamvolume.h>
#include <gst/video/videooverlay.h>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCloseEvent>
#include <QTimer>
#include <QStackedWidget>
#include <QVideoWidget>
#include <QDebug>
#include "hi384_protocol.h"

namespace Ui {
class hp_gstreamer_player;
}

enum HP_GST_SELECT{
    HP_GST_SELECT_SPEED,//选中的按钮
    HP_GST_SELECT_CLOSE,
    HP_GST_SELECT_PAUSE,
};

class hp_gstreamer_player : public QWidget
{
    Q_OBJECT
public:
    explicit hp_gstreamer_player(QWidget *parent = 0);
    ~hp_gstreamer_player();
    void hp_gst_play(QString file);//全路径
//    void hp_gst_setStop();//暂停
//    void hp_gst_setRePlay();//播放
    void hp_gst_setSpeed(double speed);
//    void hp_gst_setIndex(int value);
//    void hp_gst_setVolum(int value);
//    void hp_gst_setEnd();
//    gint64 hp_gst_getDuration();
//    gint64 hp_gst_getCurrent();
    bool display_HDMI;
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_update_lcdoff_time(bool iskey);
public slots:
    void slotTimerout();
private slots:
    void on_checkBox_clicked(bool checked);

    void on_toolButton_close_clicked();

    void on_verticalSlider_sliderMoved(int position);

    void on_toolButton_speed_clicked();
protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
private:
    Ui::hp_gstreamer_player *ui;
    GstElement *playbin2;
    GstElement *pipeline;
    GMainLoop *loop;
    QTimer *queryTimer;
    gint64 duration;
    int speed;
    GstElement *appPipeline;
    GstBus *bus;
    bool isStoped;//标识是否停止播放
    gint64 oldcurrent;//标识旧的播放
    bool isStop;
    HP_GST_SELECT m_objectName;//表示当前选中

    QVideoWidget *displayWnd;
    bool check_audio_stream(GstElement *pipeline);
    void toolButton_pauseStyleSet(bool state);
    void toolButton_closeStyleSet(bool state);
    void toolButton_speedStyleSet(bool state);
};

#endif // HP_GSTREAMER_PLAYER_H
