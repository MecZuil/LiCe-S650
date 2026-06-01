#ifndef HP_FFMPEG_PLAYER_H
#define HP_FFMPEG_PLAYER_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QByteArray>
#include <QMutex>
#include <QObject>
#include <QThread>
#include <QString>
#include <QAudioOutput>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QFile>
#include <QLineEdit>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDebug>
#include <QBuffer>
#include <QIODevice>
#include <QCoreApplication>
#include <QEventLoop>
#include <QMatrix>
#include <QPixmap>
#include <QImage>
#include "hp_ffmpeg_audio.h"

class hp_ffmpeg_player : public QWidget
{
    Q_OBJECT
public:
    explicit hp_ffmpeg_player(QWidget *parent = 0);

    void hp_Video_Play(QString filename,QLabel *labelname);//也可也传入大小
    void hp_Video_setWH(int width,int height);
    void hp_Video_setLowSpeedOffset(int offset);
    void hp_Video_setHighSpeedOffset(int offset);
    void hp_Video_setSpeed(Player_speed speed);
    void hp_Video_setIndex(double index);//传入时间占比总长
    void hp_Video_setRotate(double rotate);
    void hp_Video_setStop(bool stop);
    void hp_Video_setClose();
    double hp_Video_getDuration();
    double hp_Video_getNowTime();
    bool hp_Video_getSeekOK();
signals:
    void hp_Video_player_close();
private slots:
    void seekok();
private:
    void delay(int msec);

    bool audioIsClose;

    hp_ffmpeg_audio *audio_thread;

    QMatrix matrix;
    int64_t player_index;
    int64_t duration;

    double input_index;
    bool player_changeindex;//是否处于跳转状态

    int fastnum;
    bool player_fastspeed;
    int lowoffset;
    int highoffset;

    double player_rotate;
    int player_width;
    int player_height;

    double player_nowTime;
    int64_t player_zonFrame;
    int64_t player_nowFrame;

    Player_status player_status = statu_free;
};

#endif // HP_FFMPEG_PLAYER_H
