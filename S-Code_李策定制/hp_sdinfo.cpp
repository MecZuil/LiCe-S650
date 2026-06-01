#include  "hp_sdinfo.h"

Hp_SdInfo::Hp_SdInfo(QWidget *parent) : QWidget(parent)
{

    sdinsert = false;
    sdinfo.totalMB = 0;
    sdinfo.usedMB = 0;
    image_sd_error = ":/res/res/sd_ok.png";
    image_sd_ok = ":/res/res/sd_error.png";
}

void Hp_SdInfo::update_sd_info(sdinfo_t si)
{

    qDebug("SD INFO:%d/%d",si.usedMB,si.totalMB);
    sdinfo.totalMB = si.totalMB;
    sdinfo.usedMB = si.usedMB;
    update();
}

void Hp_SdInfo::update_sd_insert(bool f)
{
    sdinsert = f;
    update();
}
/*
void Hp_SdInfo::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    //    if(sdinfo.totalMB == 0 && sdinfo.usedMB == 0)
    painter.setPen(QColor(Qt::red));
    if(sdinsert)
    {
        if(sdinfo.totalMB == 0)
        {
            painter.drawText(QRect(0,0,width(),height()),Qt::AlignCenter,tr("卡错误"));
        }
        else
        {
            painter.setPen(QColor(125,165,198));
            painter.setBrush(Qt::transparent);
            painter.drawRect(QRect(0,height()/4,width()-1,height()/2));

            int user_width = sdinfo.usedMB*width()/sdinfo.totalMB;
            if(sdinfo.usedMB*100/sdinfo.totalMB >90)
            {
                painter.setPen(QColor(148,17,17));
                painter.setBrush(QBrush(QColor(148,17,17),Qt::SolidPattern));
            }
            else
            {
                painter.setPen(QColor(0,108,246));
                painter.setBrush(QBrush(QColor(0,108,246),Qt::SolidPattern));
            }
            painter.drawRect(QRect(1,height()/4+1,user_width-2,height()/2-2));
        }
    }
    else
    {
        painter.drawText(QRect(0,0,width(),height()),Qt::AlignCenter,tr("卡没插入"));
    }

}
*/
