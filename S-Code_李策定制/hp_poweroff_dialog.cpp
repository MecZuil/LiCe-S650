#include  "hp_poweroff_dialog.h"
#include  "ui_hp_poweroff_dialog.h"

Hp_PowerOff_Dialog::Hp_PowerOff_Dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_PowerOff_Dialog)
{
    ui->setupUi(this);
    shutting = false;
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    setGeometry((640-width())/2+160,(480-height())/2,width(),height());  //384->640   96->160  272->480
    setFixedSize(this->width(), this->height());
    connect(&timer_1s,SIGNAL(timeout()),this,SLOT(timer_out()));
}

Hp_PowerOff_Dialog::~Hp_PowerOff_Dialog()
{
    delete ui;
}
void Hp_PowerOff_Dialog::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);
        QFont font13;
        font13.setPointSize(13);

        this->setGeometry((384-220)/2+96,(272-80)/2,220,80);
        this->setFixedSize(220,80);
        ui->frame->setGeometry(0,0,220,80);
        ui->label->setGeometry(0,0,220,40);
        ui->label_timer->setGeometry(0,40,220,40);

        ui->label->setFont(font9);
        ui->label_timer->setFont(font13);
    }
}
void Hp_PowerOff_Dialog::changeEvent(QEvent *e)
{
    QString para;
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        if(para !=NULL)
        {
            if(para.toInt() == 0)
            {
                ui->label->setText("电量低，系统即将关机");
            }
            else if(para.toInt() == 1)
            {
                ui->label->setText("電量低，系統即將關機");
            }
            else if(para.toInt() == 2)//english
            {
                ui->label->setText("Low power, system is about to shut down");
            }
            else if(para.toInt() == 3)//俄语
            {
                ui->label->setText("Батарея разряжена!");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                ui->label->setText("Akku lemerült, lekapcsolás");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                ui->label->setText("Abtería baja, el sistema está a punto de apagarse");
            }
        }
        break;
    default:
        break;
    }
}

void Hp_PowerOff_Dialog::start_delay()
{
    timer_1s.start(1000);
    shutting = true;
    timer_cnt = 3;
    ui->label_timer->setText(QString::number(timer_cnt));
}

void Hp_PowerOff_Dialog::timer_out()
{
    qDebug()<<"timer_out:"<<timer_cnt;
    if(timer_cnt>0)
    {
        timer_cnt--;
        ui->label_timer->setText(QString::number(timer_cnt));
    }
    else
    {
        timer_1s.stop();
        signal_pc_sys_set_powerdown(1);
    }
}

bool Hp_PowerOff_Dialog::get_shutting()
{
    return shutting;
}

