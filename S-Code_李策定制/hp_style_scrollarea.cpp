#include "hp_style_scrollarea.h"

hp_style_scrollArea::hp_style_scrollArea(QWidget *parent) : QScrollArea(parent)
{
    hp_dataInit();
}
void hp_style_scrollArea::hp_dataInit()
{
    mouseEnable = true;
    maxpage = 3;
    setting_index = 0;
    pagesize = 570;
}
int  hp_style_scrollArea::hp_getNowPage()
{
    return setting_index;
}
void  hp_style_scrollArea::hp_setPage(int page)
{
    if(page == setting_index)
    {
        return;
    }
    setting_index = page;
    this->horizontalScrollBar()->setValue(setting_index * 570);
}
void hp_style_scrollArea::mousePressEvent(QMouseEvent *event)
{
    mouse_press = event->pos();
}
void hp_style_scrollArea::mouseMoveEvent(QMouseEvent *event)
{
//    qDebug() << " hp_style_scrollArea::mouseMoveEvent " << event->pos().x() << " ; " << mouse_press.x();
    if(mouseEnable)
    {

    }
}
void hp_style_scrollArea::mouseReleaseEvent(QMouseEvent *event)
{
//    qDebug() << "setting_index start == > " << setting_index << " ; " << pagesize;
    if(event->pos().y() - mouse_press.y() > 50)
    {
        setting_index--;
        if(setting_index < 0)
        {
            setting_index = maxpage;
        }
        this->horizontalScrollBar()->setValue(setting_index * pagesize);
    }else if(mouse_press.y() - event->pos().y() > 50){
        setting_index++;
        if(setting_index > maxpage)
        {
            setting_index = 0;
        }
        this->horizontalScrollBar()->setValue(setting_index * pagesize);
    }
    signal_page_changed(setting_index);
//    qDebug() << "setting_index end == > " << setting_index << " ; " << setting_index * pagesize;
}
void hp_style_scrollArea::hp_setMouseEnable(bool isEnabled)
{
    mouseEnable = isEnabled;
}
void hp_style_scrollArea::hp_setMaxPage(int page)
{
    maxpage = page;
}
