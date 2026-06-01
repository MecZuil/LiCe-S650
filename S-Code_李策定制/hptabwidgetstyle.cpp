#include  "hptabwidgetstyle.h"

HpTabWidgetStyle::HpTabWidgetStyle()
{
    m_width = 160;
    m_height = 80;
}
QSize HpTabWidgetStyle::sizeFromContents(ContentsType type, const QStyleOption *option, const QSize &size, const QWidget *widget) const
{
    QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
    if (type == QStyle::CT_TabBarTab) {
        s.transpose();
 //       s.rwidth() = 96; // 设置每个tabBar中item的大小
 //       s.rheight() = 40;

          s.rwidth() = m_width; // 设置每个tabBar中item的大小 160，80
          s.rheight() = m_height;

    }
    return s;
}
void HpTabWidgetStyle::drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    if (element == CE_TabBarTabLabel) {

        if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option))
        {
            QRect allRect = tab->rect;
            if(tab->text == "back")
            {
                QImage image(":/res/res/setting_back.png");
            //    painter->drawImage(allRect.adjusted(20, 0, 20, -3),image,QRect(0,0,image.width(),image.height()));
                painter->drawImage(allRect.adjusted(3, 0, 0, -3),image,QRect(0,0,image.width(),image.height()));
            }
            else
            {
                if (tab->state & QStyle::State_Selected) {
                    painter->save();
                    QImage image(":/res/res/setting_selected.png");
                    painter->drawImage(allRect.adjusted(3, 0, 0, -3),image,QRect(0,0,image.width(),image.height()));

//                    painter->drawImage(allRect,image,QRect(0,0,image.width(),image.height()));
                    painter->restore();
                }

                QTextOption option;
                option.setAlignment(Qt::AlignCenter);
                if (tab->state & QStyle::State_Selected) {
                    painter->setPen(0xffffff);
                }
                else {
                    painter->setPen(0x7CA6C9);
                }

                painter->drawText(allRect.adjusted(3, 0, 0, -3), tab->text, option);       //偏移量 右 左 上 下
//                painter->drawText(allRect, tab->text, option);
            }
            return;
        }
    }


    if (element == CE_TabBarTab) {
        QProxyStyle::drawControl(element, option, painter, widget);
    }

}

