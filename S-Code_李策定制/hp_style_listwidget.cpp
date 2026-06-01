#include "hp_style_listwidget.h"

hp_style_listwidget::hp_style_listwidget(QWidget *parent) : QListWidget(parent)
{
    scrollMoveSpeed = 3;
}

void hp_style_listwidget::setMoveSpeed(int val)
{
    QFont font11;
    font11.setPointSize(11);
    scrollMoveSpeed = val;
    setFont(font11);
}

//add_item->setBackground(QBrush(QImage(backGround)));
void hp_style_listwidget::mousePressEvent(QMouseEvent *event)
{
    QListWidget::mousePressEvent(event);
    mouse_press = event->globalPos();
    scrollStartValue = this->verticalScrollBar()->value();
    qDebug() << __func__ << mouse_press.y();
}
void hp_style_listwidget::mouseMoveEvent(QMouseEvent *event)
{
    msMv = true;
    int val = mouse_press.y() - event->globalPos().y();
    qDebug() << "mouse_press.y()" << mouse_press.y() << "event->globalPos().y()" << event->globalPos().y() << "move val" << val / scrollMoveSpeed;
    this->verticalScrollBar()->setValue((scrollStartValue + val / scrollMoveSpeed));
}
void hp_style_listwidget::mouseReleaseEvent(QMouseEvent *event)
{
    msMv = false;
}
