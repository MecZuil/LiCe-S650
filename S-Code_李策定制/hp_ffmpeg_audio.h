#ifndef HP_FFMPEG_AUDIO_H
#define HP_FFMPEG_AUDIO_H

#include <QThread>
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
#include <QTime>
#include <QTimer>
#include <QBuffer>
#include <QLabel>
#include <QIODevice>
#include <QCoreApplication>
#include <QEventLoop>
#include <QMatrix>
#include <QQueue>
#include <QFile>

extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
    #include <libavformat/version.h>
    #include <libavutil/time.h>
    #include <libavutil/mathematics.h>
    #include <libavutil/imgutils.h>
    #include <libswresample/swresample.h>
}

enum Player_status
{
    statu_free,//空闲
    statu_play,//播放
    statu_stop,//暂停
    statu_close//关闭
};

enum Player_speed
{
    speed_0_25 = 0,//1.5
    speed_0_5,//0.5
    speed_0_75,//1.5
    speed_1_0,//1
    speed_1_25,//1.25
    speed_1_5,//1.5
    speed_2_0,//2.0
    speed_2_5,//2.5
    speed_3_0//3.0
};

class hp_ffmpeg_audio : public QThread
{
    Q_OBJECT
public:
    explicit hp_ffmpeg_audio(QWidget *parent = 0);

    void hp_Audio_play(QString filePath);
    void hp_Audio_setLowSpeedOffset(int offset);
    void hp_Audio_setHighSpeedOffset(int offset);
    void hp_Audio_setSpeed(Player_speed speed);
    void hp_Audio_setIndex(double index);//传入时间占比总长
    void hp_Audio_setStop(bool stop);
    void hp_Audio_setClose();
    double hp_Audio_getAudioTime();
    void hp_Video_setIndex(double index);
signals:
    void seekOK();
protected:
    void run();
public slots:
private:
    bool initAudio(int SampleRate);
    void runAudio();

    double nowTime;

    QString filename;
    QAudioOutput* audio;//音频输出对象

    void delay(int msec);

    int64_t player_index;
    int64_t duration;

    double input_index;
    bool player_changeindex;

    int fastnum;
    bool player_fastspeed;
    int lowoffset;
    int highoffset;
    Player_status player_status;
};

#endif // HP_FFMPEG_AUDIO_H
