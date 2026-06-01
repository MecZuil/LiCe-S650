#include  "hp_mode_hzh_adjust.h"
#include  "ui_hp_mode_hzh_adjust.h"

Hp_Mode_Hzh_Adjust::Hp_Mode_Hzh_Adjust(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Mode_Hzh_Adjust)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    this->setGeometry(0,0,width(),height());
    setFixedSize(width(), height());

    ui->adjust_area->installEventFilter(this);
}

Hp_Mode_Hzh_Adjust::~Hp_Mode_Hzh_Adjust()
{
    delete ui;
}
void Hp_Mode_Hzh_Adjust::hp_setDefine_S3x0(bool isSelect)
{
    define_S3x0 = isSelect;
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);

        this->resize(480,272);
        ui->adjust_area->setGeometry(96,0,384,272);
        ui->frame->setGeometry(0,0,96,272);
        ui->toolButton_default->setGeometry(2,50,92,40);
        ui->toolButton_finish->setGeometry(0,0,96,40);

        ui->toolButton_default->setFont(font9);
    }
}
void Hp_Mode_Hzh_Adjust::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Hp_Mode_Hzh_Adjust::update_rect_nine()
{
    rect_nine[0] = QRect(adjust_rect.left(),adjust_rect.top(),adjust_rect.width()/3,adjust_rect.height()/3);                                                    //左上角
    rect_nine[1] = QRect(adjust_rect.left()+adjust_rect.width()/3,adjust_rect.top(),adjust_rect.width()/3,adjust_rect.height()/3);                  //上
    rect_nine[2] = QRect(adjust_rect.left()+adjust_rect.width()*2/3,adjust_rect.top(),adjust_rect.width()/3,adjust_rect.height()/3);                //右下角

    rect_nine[3] = QRect(adjust_rect.left(),adjust_rect.top()+adjust_rect.height()/3,adjust_rect.width()/3,adjust_rect.height()/3);                 //左中右
    rect_nine[4] = QRect(adjust_rect.left()+adjust_rect.width()/3,adjust_rect.top()+adjust_rect.height()/3,adjust_rect.width()/3,adjust_rect.height()/3);
    rect_nine[5] = QRect(adjust_rect.left()+adjust_rect.width()*2/3,adjust_rect.top()+adjust_rect.height()/3,adjust_rect.width()/3,adjust_rect.height()/3);

    rect_nine[6] = QRect(adjust_rect.left(),adjust_rect.top()+adjust_rect.height()*2/3,adjust_rect.width()/3,adjust_rect.height()/3);                   //左下角，下边，右下角
    rect_nine[7] = QRect(adjust_rect.left()+adjust_rect.width()/3,adjust_rect.top()+adjust_rect.height()*2/3,adjust_rect.width()/3,adjust_rect.height()/3);
    rect_nine[8] = QRect(adjust_rect.left()+adjust_rect.width()*2/3,adjust_rect.top()+adjust_rect.height()*2/3,adjust_rect.width()/3,adjust_rect.height()/3);
}

int Hp_Mode_Hzh_Adjust::search_selected(QPoint p)
{

    for(int i=0;i<9;i++)
    {
        if(rect_nine[i].contains(p.x(),p.y()))
        {
            return i;
        }
    }
    return -1;
}

bool Hp_Mode_Hzh_Adjust::eventFilter(QObject *w, QEvent *e)
{
    if(w->objectName() == "adjust_area")
    {
        QMouseEvent *mouse_event;
        QPainter painter;
        switch(e->type())
        {
        case QEvent::MouseButtonPress:
            mouse_event = static_cast<QMouseEvent *>(e);
            MousePressEvent(mouse_event);
            signal_update_lcdoff_time(false);
            break;
        case QEvent::MouseButtonRelease:
            mouse_event = static_cast<QMouseEvent *>(e);
            MouseReleaseEvent(mouse_event);
            break;
        case QEvent::MouseMove:
            mouse_event = static_cast<QMouseEvent *>(e);
            MouseMoveEvent(mouse_event);
            signal_update_lcdoff_time(false);
            break;
        case QEvent::Paint:
            if(define_S3x0)
            {
                if(painter.begin(ui->adjust_area))
                {
                    painter.setPen(QColor(124,166,201));//#7CA6C9               //lcy

                    if(adjust_rect.width() <30)
                    {
                        adjust_rect.setWidth(30);
                    }

                    if(adjust_rect.height() <30)
                    {
                        adjust_rect.setHeight(30);
                    }

                    if(adjust_rect.x() > 384-30)
                    {
                        adjust_rect.setX(384-30);
                    };

                    if(adjust_rect.y() > 272-30)
                    {
                        adjust_rect.setY(272-30);
                    }
                    painter.drawRect(adjust_rect);
                    painter.end();
                }
            }
            else{
                if(painter.begin(ui->adjust_area))
                {
                    painter.setPen(QColor(124,166,201));//#7CA6C9               //lcy

                    if(adjust_rect.width() <40)
                    {
                        adjust_rect.setWidth(40);
                    }

                    if(adjust_rect.height() <40)
                    {
                        adjust_rect.setHeight(40);
                    }

                    if(adjust_rect.x() > 640-40)
                    {
                        adjust_rect.setX(640-40);
                    };

                    if(adjust_rect.y() > 480-40)
                    {
                        adjust_rect.setY(480-40);
                    }
                    painter.drawRect(adjust_rect);
                    painter.end();
                }
            }
            break;
        default:
            break;
        }
    }
    return false;
}

void Hp_Mode_Hzh_Adjust::keyReleaseEvent(QKeyEvent *ev)
{
    signal_update_lcdoff_time(true);
    qDebug()<<"Hp_Mode_Rdj_Adjust::keyReleaseEvent(QKeyEvent *ev)............................................."<<ev->key();
    switch( ev->key() )
    {
    case KEY_RETURN:
        on_toolButton_finish_released();
        break;
    default:
        break;
    }
}

void Hp_Mode_Hzh_Adjust::MouseMoveEvent(QMouseEvent *ev)
{
    int op = search_selected(pressPoint);
//    qDebug( )<<" ************************ == op"<<op;
    if(op == 0)                                                             //左上角
    {
        QPoint lefttop = adjust_rect.topLeft();
        QPoint diff = ev->pos()-pressPoint;
        adjust_rect.setTopLeft(lefttop + diff);
    }
    else if(op == 1)                                                        //上边
    {
        int top = adjust_rect.top();
        int diff = ev->pos().y()-pressPoint.y();
        adjust_rect.setTop(top+diff);
    }
    else if(op == 2)                                                        //右上角
    {
        QPoint righttop = adjust_rect.topRight();
        QPoint diff = ev->pos()-pressPoint;
        adjust_rect.setTopRight(righttop+diff);
    }
    else if(op == 3)                                                            //左边
    {
        int left = adjust_rect.left();
        int diff = ev->pos().x()-pressPoint.x();
        adjust_rect.setLeft(left+diff);
    }
    else if(op == 4)                                                                //整体移动
    {
        QPoint topleft = adjust_rect.topLeft();
        QPoint diff = ev->pos()-pressPoint;
        adjust_rect.moveTo(topleft+diff);
    }
    else if(op == 5)                                                                //右边
    {
        int right = adjust_rect.right();
        int diff = ev->pos().x()-pressPoint.x();
        adjust_rect.setRight(right+diff);
    }
    else if(op == 6)                                                                //左下角
    {
        QPoint leftbottom = adjust_rect.bottomLeft();
        QPoint diff = ev->pos()-pressPoint;
        adjust_rect.setBottomLeft(leftbottom+diff);
    }
    else if(op == 7)                                                            //下边
    {
        int bottom = adjust_rect.bottom();
        int diff = ev->pos().y()-pressPoint.y();
        adjust_rect.setBottom(bottom+diff);
    }
    else if(op == 8)                                                        //右下角
    {
        QPoint bottomright = adjust_rect.bottomRight();
        QPoint diff = ev->pos()-pressPoint;
        adjust_rect.setBottomRight(bottomright+diff);
    }
    else
    {
        return;
    }


    pressPoint = ev->pos();

    if(adjust_rect.left()<0)
        adjust_rect.setLeft(0);
    if(adjust_rect.top() < 0)
        adjust_rect.setTop(0);
    if(adjust_rect.right()> ui->adjust_area->width())
        adjust_rect.setRight(ui->adjust_area->width()-1);

    if(adjust_rect.bottom()> ui->adjust_area->height())
        adjust_rect.setBottom(ui->adjust_area->height()-1);

    update_rect_nine();
    ui->adjust_area->update();
}

void Hp_Mode_Hzh_Adjust::MousePressEvent(QMouseEvent *ev)
{
    pressPoint = ev->pos();
}

void Hp_Mode_Hzh_Adjust::MouseReleaseEvent(QMouseEvent *ev)
{
    sync_pippara_rect();
}

void Hp_Mode_Hzh_Adjust::on_toolButton_finish_released()
{
    signal_update_lcdoff_time(false);
    sync_pippara_rect();
    close();
}

void Hp_Mode_Hzh_Adjust::setRect(QRect rect)
{
    bak_rect = rect;
    adjust_rect = rect;
    update_rect_nine();
}

QRect Hp_Mode_Hzh_Adjust::getRect()                 //lcy
{
    /*
    if(adjust_rect.width() <40)
    {
        adjust_rect.setWidth(40);
    }

    if(adjust_rect.height() <20)
    {
        adjust_rect.setHeight(20);
    }
*/


    return adjust_rect;
}

void Hp_Mode_Hzh_Adjust::on_toolButton_default_released()
{
    adjust_rect = bak_rect;
    update_rect_nine();
    ui->adjust_area->update();
    sync_pippara_rect();
}
