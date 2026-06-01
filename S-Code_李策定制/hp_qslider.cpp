#include  "hp_qslider.h"

#include  "qstyle.h"
#include  "QStyleOptionSlider"

hp_QSlider::hp_QSlider(QWidget *parent):QSlider(parent)
{
    flag = false;
}

hp_QSlider::~hp_QSlider()
{

}


void hp_QSlider::mousePressEvent(QMouseEvent *event)
{
    QStyleOptionSlider opt;
    initStyleOption(&opt);
    const QRect sliderRect = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);
    qDebug()<<sliderRect<<" pos:"<<event->pos()<<" "<<event->pos()-sliderRect.center()+sliderRect.topLeft()<<sliderRect.contains(event->pos());

    if(sliderRect.contains(event->pos()))
    {
        flag = false;
        QSlider::mousePressEvent(event);
    }
    else
    {
        p_pos = event->pos();
        flag = true;
    }

}

void hp_QSlider::mouseReleaseEvent(QMouseEvent *event)
{
    QStyleOptionSlider opt;
    initStyleOption(&opt);
    const QRect sliderRect = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);

    int slider_x;
    slider_x = (this->width())*((this->value()) - (this->minimum()) ) / ((this->maximum()) -(this->minimum()));

    if(!flag)
        QSlider::mouseReleaseEvent(event);
    else
    {
        int k = this->value();;
//        if(event->pos().x()>p_pos.x())
        if(event->pos().x()>slider_x)
        {
            k+=this->singleStep();
            if(k>this->maximum())
                k = this->maximum();
            this->setValue(k);
        }
//        else if(event->pos().x()<p_pos.x())
        else if(event->pos().x()<slider_x)
        {
            k-=this->singleStep();
            if(k<this->minimum())
                k = this->minimum();
            this->setValue(k);
        }
        else
        {
            if(event->pos().x()>sliderRect.right())
            {
                k+=this->pageStep();
                if(k>this->maximum())
                    k = this->maximum();
                this->setValue(k);
            }
            else
            {
                k-=this->pageStep();
                if(k<this->minimum())
                    k = this->minimum();
                this->setValue(k);
            }
        }
    }
    flag = false;

}

void hp_QSlider::mouseMoveEvent(QMouseEvent *event)
{
    if(!flag)
        QSlider::mouseMoveEvent(event);
}
