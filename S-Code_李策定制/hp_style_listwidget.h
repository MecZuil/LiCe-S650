#ifndef HP_STYLE_LISTWIDGET_H
#define HP_STYLE_LISTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QImage>
#include <QBrush>
#include <QMouseEvent>
#include <QScrollBar>
#include <QDebug>
#include "hi384_protocol.h"

#include <QCoreApplication>
#include <QEventLoop>
#include <QTime>

#define LISTWIDGETSTYLESHEET1 "QListWidget{border:0px solid #ffffff;background-image:url(:/res/res/setting_background.png);}\
QListWidget::Item{height:30px;color:#7CA6C9;}\
QListWidget::Item:selected{height:30px;color:#ffffff;}\
QScrollBar:vertical {border:0px solid #7CA6C9;background-color:#32CC99;width:40px;margin:40 0 40 0px;}\
QScrollBar::handle:vertical {background-color: rgb(83, 166, 249);border:1px solid #7CA6C9;height:30px;max-height:20px;}\
QScrollBar::add-line:vertical {border:0px solid #7CA6C9;background-color:transparent;width:40px;height:40px;subcontrol-position:bottom;subcontrol-origin:margin;border-image: url(:/res/res/m_down_arrow_s.png);}\
QScrollBar::sub-line:vertical {border:0px solid #7CA6C9;background-color:transparent;width:40px;height:40px;subcontrol-position:top;subcontrol-origin:margin;border-image: url(:/res/res/m_up_arrow_s.png);}\
QScrollBar::up-arrow:vertical,QScrollBar::down-arrow:vertical {border:0px;width:40px;height:40px;}\
QScrollBar::add-page:vertical {background-color:transparent;}\
QScrollBar::sub-page:vertical {background-color:transparent;}"


class hp_style_listwidget : public QListWidget
{
    Q_OBJECT
public:
    explicit hp_style_listwidget(QWidget *parent = 0);
    void setMoveSpeed(int val);
signals:
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
public slots:
private slots:
private:
    QPoint mouse_press;//世界坐标系
    int scrollMoveSpeed;
    int scrollStartValue;
    bool msMv;//mouseIsMove标识鼠标是否经过移动
};

#endif // HP_STYLE_LISTWIDGET_H
