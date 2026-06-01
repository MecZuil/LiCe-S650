#ifndef HP_MEDIA_PLAYER_GPLAY_H
#define HP_MEDIA_PLAYER_GPLAY_H

#include  <QWidget>
#include  <QTimer>
#include  <QDebug>
#include  <QProcess>
#include  <QKeyEvent>
#include  "hi384_protocol.h"
#include <libavformat/avformat.h>
#include <libavutil/time.h>
namespace Ui {
class Hp_Media_Player_Gplay;
}

class Hp_Media_Player_Gplay : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Media_Player_Gplay(QWidget *parent = nullptr);
    ~Hp_Media_Player_Gplay();
    bool start_play_media(QString filePath);
    bool stop_play_media();
    void hp_setDefine_S3x0(bool isSelect);

signals:
    void signal_update_lcdoff_time(bool iskey);
public slots:
    void on_toolButton_close_released();

private slots:
    void on_toolButton_pause_clicked(bool checked);
    void ReadData();
    //void HDMIReadData();

private:
    Ui::Hp_Media_Player_Gplay *ui;

    QProcess *process;
    bool running;
    bool rate_flag;
    void changeEvent(QEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *ev);
    void toolButton_pauseStyleSet(bool state);
    void toolButton_closeStyleSet(bool state);

    QString m_objectName;
};
#endif // HP_MEDIA_PLAYER_GPLAY_H
