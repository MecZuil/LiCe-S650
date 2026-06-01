#ifndef HP_STYLE_SCROLLAREA_H
#define HP_STYLE_SCROLLAREA_H

#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include <QMouseEvent>
#include <QDebug>

class hp_style_scrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit hp_style_scrollArea(QWidget *parent = 0);
    void hp_setMouseEnable(bool isEnabled);
    void hp_setMaxPage(int page);
    int hp_getNowPage();
    void hp_setPage(int page);

    int pagesize;
signals:
    void signal_page_changed(int page);
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
public slots:
private:
    void hp_dataInit();
    QPoint mouse_press;

    bool mouseEnable;//使能鼠标事件

    int setting_index;
    int maxpage;
};

#endif // HP_STYLE_SCROLLAREA_H
