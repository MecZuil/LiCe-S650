#include  "hphide_dialog.h"
#include  "ui_hphide_dialog.h"

#include     <QTime>
#include     <QtCore>

Hphide_Dialog::Hphide_Dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hphide_Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    setGeometry(600,200,width(),height());
    setFixedSize(this->width(), this->height());

    QString para;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    if(para !=NULL)
    {
        if(para.toInt() == 0)
        {
            ui->label->setText("HI  取样......");
        }
        else if(para.toInt() == 1)
        {
            ui->label->setText("HI  取樣......");
        }
        else if(para.toInt() == 2)//english
        {
            ui->label->setText("HI sampling......");
        }
        else if(para.toInt() == 3)//俄语
        {
            ui->label->setText("HI  вычисление......");
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            ui->label->setText("HI  számítás......");
        }
        else if(para.toInt() == 5)//西班牙语
        {
            ui->label->setText("HI  Cálculo......");
        }
    }

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout( )), this, SLOT(slot_handleTimeout ( )));
   timer->start(4*1000);

}

Hphide_Dialog::~Hphide_Dialog()
{
    delete ui;
}
void Hphide_Dialog::hp_setDefine_S3x0(bool isSelect)
{
//    qDebug() << "Hphide_Dialog::hp_setDefine_S3x0 == > " << isSelect;
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);
//        qDebug() << "Hphide_Dialog::hp_setDefine_S3x0 1 ";
        this->setGeometry(370,30,80,30);
//        qDebug() << "Hphide_Dialog::hp_setDefine_S3x0 2 ";
        ui->frame->setGeometry(0,0,80,30);
//        qDebug() << "Hphide_Dialog::hp_setDefine_S3x0 3 ";
        ui->label->setGeometry(0,0,80,30);
//        qDebug() << "Hphide_Dialog::hp_setDefine_S3x0 4 ";

        ui->frame->setFont(font9);
        ui->label->setFont(font9);
    }
}
void Hphide_Dialog::on_pushButton_released()
{
    timer->start(4*1000);
}

void Hphide_Dialog::slot_handleTimeout()
{
    this->close();
}

void Hphide_Dialog::time_select(int time)
{
      timer->start(time*1000);
}

