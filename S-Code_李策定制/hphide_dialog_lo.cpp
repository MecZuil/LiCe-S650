#include  "hphide_dialog_lo.h"
#include  "ui_hphide_dialog_lo.h"

Hphide_Dialog_LO::Hphide_Dialog_LO(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hphide_Dialog_LO)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    setGeometry(600,200,width(),height());
    setFixedSize(this->width(), this->height());

    state_lo=0;


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout( )), this, SLOT(slot_handleTimeout ( )));


    QString para;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    if(para !=NULL)
    {
        if(para.toInt() == 0)
        {
            ui->label->setText("LO  取样......");
        }
        else if(para.toInt() == 1)
        {
            ui->label->setText("LO  取樣......");
        }
        else if(para.toInt() == 2)//english
        {
            ui->label->setText("LO sampling......");
        }
        else if(para.toInt() == 3)//俄语
        {
            ui->label->setText("LO  вычисление......");
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            ui->label->setText("LO  számítás......");
        }
        else if(para.toInt() == 5)//西班牙语
        {
            ui->label->setText("LO  Cálculo......");
        }
    }

     timer->start(4*1000);

}

Hphide_Dialog_LO::~Hphide_Dialog_LO()
{
    delete ui;
}
void Hphide_Dialog_LO::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);

        this->setGeometry(370,30,80,30);
        ui->frame->setGeometry(0,0,80,30);
        ui->label->setGeometry(0,0,80,30);

        ui->frame->setFont(font9);
        ui->label->setFont(font9);
    }
}
void Hphide_Dialog_LO::on_pushButton_released()
{

}

void Hphide_Dialog_LO::slot_handleTimeout()
{
    if(0 == state_lo)
    {
        QString para;
        para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        if(para !=NULL)
        {
            if(para.toInt() == 0)
            {
                ui->label->setText("计算......");
            }
            else if(para.toInt() == 1)
            {
                ui->label->setText("計算......");
            }
            else if(para.toInt() == 2)//english
            {
                ui->label->setText("calculation......");
            }
            else if(para.toInt() == 3)//俄语
            {
                ui->label->setText("вычисление......");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                ui->label->setText("számítás......");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                ui->label->setText("Cálculo......");
            }
        }


         timer->start(57*1000);     //57秒
         state_lo=100;
    }else if( 1 == state_lo)
    {
        QString para;
        para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        if(para !=NULL)
        {
            if(para.toInt() == 0)
            {
                ui->label->setText("计算......");
            }
            else if(para.toInt() == 1)
            {
                ui->label->setText("計算......");
            }
            else if(para.toInt() == 2)//english
            {
                ui->label->setText("calculation......");
            }
            else if(para.toInt() == 3)//俄语
            {
                ui->label->setText("вычисление......");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                ui->label->setText("számítás......");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                ui->label->setText("Cálculo......");
            }
        }
    }else{
        this->close();
    }

}

void Hphide_Dialog_LO::time_select(int time)
{

}
