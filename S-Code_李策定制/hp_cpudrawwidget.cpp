#include  "hp_cpudrawwidget.h"

Hp_CpuDrawWidget::Hp_CpuDrawWidget(QWidget *parent) : QWidget(parent)
{

}

void Hp_CpuDrawWidget::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);

    QPainter painter(this);

    painter.setPen(Qt::green);

    painter.eraseRect(QRect(0,0,200,110));

    painter.drawRect(QRect(0,0,width()-1,height()-1));

    while(list.length() > width()-1)
    {
        list.removeFirst();
    }

    QPoint p0,p1;
    int value;

    QListIterator<int> item(list);

    int i = 0;
    while(item.hasNext())
    {
        p0 = p1;

        p1.setX(i);
        value = item.next();
        p1.setY(height()-value-5);
        //painter.drawPoint(p1);
        painter.drawLine(p0,p1);
        i++;
    }

    if(value < 0)
        value = 0;
    if(value > 100)
        value = 100;

    QString str = QString("CPU:%1%").arg(value);
    painter.drawText(3,16,str);

}
