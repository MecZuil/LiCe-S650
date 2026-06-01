#ifndef HP_CAMERA_VIDEO_H
#define HP_CAMERA_VIDEO_H

#include  <QWidget>
#include  <QTimer>

namespace Ui {
class Hp_Camera_Video;
}

class Hp_Camera_Video : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Camera_Video(QWidget *parent = 0);
    ~Hp_Camera_Video();
    void timer_start();
    void timer_stop();

    void hp_setDefine_S3x0(bool isSelect);
public slots:
    void timer_func();

private:
    int timer_cnt;
    Ui::Hp_Camera_Video *ui;
    QTimer timer;

    void show_second(int s);

    void changeEvent(QEvent *e);

};

#endif // HP_CAMERA_VIDEO_H
