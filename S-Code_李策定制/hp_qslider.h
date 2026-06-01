#ifndef HP_QSLIDER_H
#define HP_QSLIDER_H
#include  <QSlider>
#include  <QDebug>
#include  <QLabel>
#include  <QMouseEvent>
#include  <QPoint>

class hp_QSlider : public QSlider
{
public:
    hp_QSlider(QWidget *parent=0);

    ~hp_QSlider();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

private:
    double v;
    bool flag;
    QPoint p_pos;

};

#endif // HP_QSLIDER_H
