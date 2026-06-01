#include  "mylabel.h"

// 指南针的旋转
myLabel::myLabel(QWidget *parent):QLabel(parent)
{
    this->setWordWrap(true);
    index2 = 0;
    scroll_num = 0;
    scroll_zon = 0;
    labelname = MYLABEL_WHO_COMPASS;
}



void myLabel::setPixmap(const QString &imgPath)
{
    if(QFile::exists(imgPath))
    {
        mPix.load(imgPath);
      //  mPix = mPix.scaled(72,72);
    }
}

void myLabel::trans(int index)
{
    static int angle=0;
    angle+=index;
    QMatrix matrix;;
    matrix.translate(mPix.width()/2,mPix.height()/2);
    matrix.rotate(angle);
    matrix.translate(-mPix.width()/2,-mPix.height()/2);
    auto tmp =mPix.transformed(matrix);;
    this->QLabel::setPixmap(tmp);
    QApplication::processEvents();



//    QPixmap pix(mPix.size());
//    QPainter painter(&pix);
//    painter.setBrush(Qt::transparent);
//    painter.setPen(Qt::red);
//    auto srcRect = mPix.rect();
//    painter.translate(srcRect.center());
//    painter.rotate(index);
//    int cubeWidth = qMin(mPix.width(),mPix.height())/2;
//    painter.drawEllipse(QPoint(0,0),cubeWidth,cubeWidth);

//    painter.translate(-srcRect.center());
//    painter.drawPixmap(QPoint(-1,-1),mPix);

   // this->QLabel::setPixmap(tmp);
    //QApplication::processEvents();

//    return pix;
}

void myLabel::setinded1(int index)
{
//    if(index<0)
//    {
//        index1=index+360;
//    }else if(index>0)
//    {
//        index1=index;
//    }
    index1=index;
    update();
}

void myLabel::settrans(int index)
{
    angle =index;
    update();
}

void myLabel::setMyname(MYLABEL_WHO name)
{
    labelname = name;
    update();
}

void myLabel::hp_scroll_setzon(int zon)
{
    scroll_zon = zon + 1;
    update();
}
void myLabel::hp_updateScroll(int num)
{
    scroll_num = num;
    update();
}
void myLabel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(labelname == MYLABEL_WHO_COMPASS)
    {
        QPixmap disc(":/res/res/N3.png");
        painter.translate(36,36);
        index2=index1+angle;
        painter.rotate(index2);
        painter.translate(-36,-36);
        painter.drawPixmap(0,0,72,72,disc);
    }else if(labelname == MYLABEL_WHO_SCROLL)
    {
        QPen pen;
//        qDebug() << "myLabel::paintEvent == > "<< scroll_num << " ; " << scroll_zon;
        if(scroll_zon > 1)
        {
            int scroll_h = (this->height() - 15 * scroll_zon) / 2;
            for(int i = 0;i < scroll_zon;i++)
            {
                if(i == scroll_num)
                {
                    pen.setColor(QColor("#5efaf9"));
                    painter.setBrush(QColor("#5efaf9"));
                }else{
                    pen.setColor(QColor("#b3c6f8"));
                    painter.setBrush(QColor("#b3c6f8"));
                }
                painter.setPen(pen);
                painter.drawEllipse(this->width() / 2,scroll_h + i * 15,4,4);//画点
            }
        }
    }
}
