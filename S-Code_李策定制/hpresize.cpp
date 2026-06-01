#include  "hpresize.h"
#include  "ui_hpresize.h"

HpResize::HpResize(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HpResize)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);


    setGeometry((640-width())/2+160, 480 - height(), width(), height());  //384->640   96->158  170->352
    setFixedSize(this->width(), this->height());
    connect(ui->slider_resize,SIGNAL(valueChanged(int)),this,SLOT(slider_value_changed(int)));
    connect(ui->slider_contrast,SIGNAL(valueChanged(int)),this,SLOT(slider_contrast_value_changed(int)));
    connect(ui->slider_brightness,SIGNAL(valueChanged(int)),this,SLOT(slider_brightness_value_changed(int)));
    ui->slider_resize->setValue(10);
    ui->label->setText("1.0X");
//    ui->label->setStyleSheet("color:white;");

}

HpResize::~HpResize()
{
    delete ui;
}

void HpResize::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font15;
        font15.setPointSize(13);

        this->setGeometry((384 - 310) / 2 + 96,200,310,40);
        ui->label->setGeometry(0,0,52,40);
        ui->slider_resize->setGeometry(52,0,200,40);

        ui->label->setFont(font15);
        ui->slider_resize->setStyleSheet("QSlider::groove:horizontal{height:1px;background:qlineargradient(x1:1, y1:0, x2:0, y2:0, stop:1 #5F80AA, stop:0 #5F80AA);  }  QSlider::handle:horizontal \
                                         {width: 16px;height: 30px;margin: -12px 0px -12px 0px;border: 0px solid #000810;border-image:url(./res/zh/huakuai.png);}");
        //亮度对比度功能没加
    }
}

void HpResize::set_resize35(int resize35)
{
    ui->slider_resize->setMaximum(resize35 * 10);
}

void HpResize::slider_value_changed(int v)
{
    qDebug() << " HpResize::slider_value_changed" << v;
    signal_update_lcdoff_time(false);
    QString s=QString::number(v/10.0,'f',1)+"X";
    ui->label->setText(s);
}


void HpResize::setValue(int v)
{
    ui->slider_resize->setValue(v);
    QString s=QString::number(v/10.0,'f',1)+"X";
    ui->label->setText(s);
}

void HpResize::changeEvent(QEvent *e)
{
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
