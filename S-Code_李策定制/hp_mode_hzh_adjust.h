#ifndef HP_MODE_HZH_ADJUST_H
#define HP_MODE_HZH_ADJUST_H

#include  <QWidget>
#include  <QDebug>
#include  <QMouseEvent>
#include  <QPainter>
#include  "hi384_protocol.h"

namespace Ui {
class Hp_Mode_Hzh_Adjust;
}

class Hp_Mode_Hzh_Adjust : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Mode_Hzh_Adjust(QWidget *parent = 0);
    ~Hp_Mode_Hzh_Adjust();

    void setRect(QRect rect);
    QRect getRect();

    void hp_setDefine_S3x0(bool isSelect);

    bool define_S3x0;
signals:
    void sync_pippara_rect();
    void signal_update_lcdoff_time(bool iskey);
private:
    Ui::Hp_Mode_Hzh_Adjust *ui;
    QRect adjust_rect,bak_rect;

    QRect rect_nine[9];
    int rect_selected;

    void update_rect_nine();
    int search_selected(QPoint p);

    QPoint pressPoint;
    bool move_valid;

    void changeEvent(QEvent *e);



    virtual void MousePressEvent(QMouseEvent *ev);
    virtual void MouseReleaseEvent(QMouseEvent *ev);
    virtual void MouseMoveEvent(QMouseEvent *ev);

protected:
    virtual bool eventFilter(QObject *w, QEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *ev);
    //    virtual void paintEvent(QPaintEvent *event);
    //    virtual void mousePressEvent(QMouseEvent *ev);
    //    virtual void mouseReleaseEvent(QMouseEvent *ev);
    //    virtual void mouseMoveEvent(QMouseEvent *ev);

private slots:
    void on_toolButton_finish_released();
    void on_toolButton_default_released();
};

#endif // HP_MODE_HZH_ADJUST_H
