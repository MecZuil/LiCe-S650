#ifndef HP_MEDIA_PLAYER_H
#define HP_MEDIA_PLAYER_H

#include  <QWidget>
#include  <QTimer>
#include  <QDebug>
#include  <QProcess>
#include  <QKeyEvent>
#include  "hi384_protocol.h"

#include <gst/gst.h>
#include <gst/audio/streamvolume.h>
#include <gst/video/videooverlay.h>

namespace Ui {
class Hp_Media_Player;
}

class Hp_Media_Player : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Media_Player(QWidget *parent = 0);
    ~Hp_Media_Player();
    void hp_setDefine_S3x0(bool isSelect);
    bool start_play_media(bool isAudio, QString filePath);
    bool stop_play_media();
signals:
    void signal_set_audio(bool para, int type);
    void signal_update_lcdoff_time(bool iskey);
    void signal_stop_video_analysis();
public slots:
    void on_toolButton_close_released();

private slots:
    void on_toolButton_pause_clicked(bool checked);
    void query_position_and_duration();

private:
    Ui::Hp_Media_Player *ui;
    QTimer *    m_pipeLineMsgTimer;
    GstElement *pipeline;
    bool        isPause;
    void changeEvent(QEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *ev);
    void toolButton_pauseStyleSet(bool state);
    void toolButton_closeStyleSet(bool state);
};

#endif // HP_MEDIA_PLAYER_H
