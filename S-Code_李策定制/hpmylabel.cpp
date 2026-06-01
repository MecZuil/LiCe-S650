#include  "hpmylabel.h"


hpmylabel::hpmylabel(QWidget *parent):QLabel(parent)
{
    this->setWordWrap(true);


}


void hpmylabel::setinded1(QString buf,int num)
{
    temp=buf;
    number=num;
    update();
}

void hpmylabel::paintEvent(QPaintEvent *)//罗盘主界面的翻转
{
    QPainter painter(this);
    QTransform transform;
    if(0==number)
    {
        transform.rotate(+0);
        painter.setWorldTransform(transform);
        painter.drawText(QRect(0,0,this->width(),this->height()),Qt::AlignCenter,temp);
    }
    else if(1==number)
    {
        transform.rotate(+270);
        painter.setWorldTransform(transform);
        painter.drawText(-(this->height())+20,this->width()-12,temp);
    }
    else if(2==number)
    {
        transform.rotate(+180);
        painter.setWorldTransform(transform);
        painter.drawText(-55,-10,temp);
    }
    else if(3==number)
    {
        transform.rotate(+90);
        painter.setWorldTransform(transform);
        painter.drawText(this->height()/4,-(this->width()/3),temp);
    }
}




