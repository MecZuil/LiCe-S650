#include  "hp_button.h"


hp_button::hp_button(QWidget *parent) : QWidget(parent)
{
    hp_button_status = S_NORMAL;
}




void hp_button::mousePressEvent(QMouseEvent *ev)
{

    Q_UNUSED(ev);

    if(hp_button_status == S_DISABLE)
        return;

    if(checked_enable)
    {
        if(hp_button_status == S_NORMAL)
        {
            hp_button_status = S_SELECT;
        }
        else if(hp_button_status == S_SELECT)
        {
            hp_button_status = S_NORMAL;
        }
        else
        {

        }

    }
    else
    {
        hp_button_status = S_SELECT;
    }
    clicked(hp_button_status);
    update();
}


void hp_button::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    if(hp_button_status == S_DISABLE)
        return;

    if(!checked_enable)
    {
        hp_button_status = S_NORMAL;
        clicked(hp_button_status);
        update();
    }

}
void hp_button::paintEvent(QPaintEvent *ev)
{

    Q_UNUSED(ev);
    QPainter painter(this);

    switch(hp_button_status)
    {
    case S_NORMAL:
        painter.drawImage(QRect(0,0,width(),height()),QImage(image_normal),QRect(0,0,QImage(image_normal).width(),QImage(image_normal).height()));
        break;
    case S_SELECT:
        painter.drawImage(QRect(0,0,width(),height()),QImage(image_select),QRect(0,0,QImage(image_select).width(),QImage(image_select).height()));
        break;
    case S_DISABLE:
        painter.drawImage(QRect(0,0,width(),height()),QImage(image_disable),QRect(0,0,QImage(image_disable).width(),QImage(image_disable).height()));
        break;
    default:
        break;

    }

}

void hp_button::set_hp_button_status_image_normal(const QString &str)
{
    if(str != image_normal)
    {
        image_normal = str;
        update();
    }
}
void hp_button::set_hp_button_status_image_select(const QString &str)
{
    if(str != image_select)
    {
        image_select = str;
        update();
    }
}void hp_button::set_hp_button_status_image_disable(const QString &str)
{
    if(str != image_disable)
    {
        image_disable = str;
        update();
    }
}


void hp_button::set_hp_button_checked_enable(bool flag)
{
    checked_enable = flag;
}

void hp_button::set_hp_button_status(HP_BUTTON_STATUS status)
{
    if(hp_button_status != status)
    {
        hp_button_status = status;
        update();
    }
}

HP_BUTTON_STATUS hp_button::get_hp_button_status()
{
    return hp_button_status;
}

