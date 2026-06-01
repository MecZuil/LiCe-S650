#include  "hp_camera_video.h"
#include  "ui_hp_camera_video.h"

Hp_Camera_Video::Hp_Camera_Video(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Camera_Video)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    setGeometry(160,0,width(),height());         //  96->160
    setFixedSize(this->width(), this->height());

    connect(&timer,SIGNAL(timeout()),this,SLOT(timer_func()));
}

Hp_Camera_Video::~Hp_Camera_Video()
{
    delete ui;
}
void Hp_Camera_Video::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);

        this->setGeometry(96,0,384,272);
        ui->label->setGeometry(230,0,67,17);
        ui->label_second->setGeometry(310,0,67,17);

        ui->label->setFont(font9);
        ui->label_second->setFont(font9);
    }
}
void Hp_Camera_Video::changeEvent(QEvent *e)
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

void Hp_Camera_Video::timer_start()
{
    timer_cnt = 0;
    show_second(timer_cnt);
    timer.start(1000);
}
void Hp_Camera_Video::timer_stop()
{

//    timer_cnt = 0;
//    show_second(timer_cnt);
    timer.stop();
//    close();
}

void Hp_Camera_Video::timer_func()
{
    timer_cnt++;
    show_second(timer_cnt);

}

void Hp_Camera_Video::show_second(int s)
{
    int hh,mm,ss;
    hh = s/3600;
    mm=(s%3600)/60;
    ss=s%60;
    QString str = QString("%1:%2:%3").arg(hh,2,10,QLatin1Char('0')).arg(mm,2,10,QLatin1Char('0')).arg(ss,2,10,QLatin1Char('0'));
    ui->label_second->setText(str);

}
