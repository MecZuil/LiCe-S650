#ifndef HP_CPUDRAWWIDGET_H
#define HP_CPUDRAWWIDGET_H

#include  <QWidget>
#include  <QLine>
#include  <QPainter>
#include  <QDebug>

#define JIANGE 10

class Hp_CpuDrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit Hp_CpuDrawWidget(QWidget *parent = 0);

    QList<int> list;

signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *ev);

};

#endif // HP_CPUDRAWWIDGET_H
