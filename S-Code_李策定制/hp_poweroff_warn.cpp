#include  "hp_poweroff_warn.h"
#include  "ui_hp_poweroff_warn.h"
#include     <QDebug>
#include     <QKeyEvent>

HP_Poweroff_Warn::HP_Poweroff_Warn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HP_Poweroff_Warn)
{
    battery_warn_state =true;
     ui->setupUi(this);
    setGeometry((640-width())/2+160,(480-height())/2,width(),height());
    setWindowFlags(Qt::WindowStaysOnTopHint);

    //  setFixedSize(this->width(), this->height());
 //   setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
 //   setWindowModality(Qt::WindowModal);

}
void HP_Poweroff_Warn::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);

        this->setGeometry((384-220)/2+96,(272-80)/2,220,80);
        this->setFixedSize(220,80);
        ui->frame->setGeometry(0,0,220,80);
        ui->label->setGeometry(0,40,220,41);
        ui->label_2->setGeometry(0,-1,220,41);
        ui->toolButton->setGeometry(196,0,24,24);

        ui->label->setFont(font9);
        ui->label_2->setFont(font9);
    }
}
HP_Poweroff_Warn::~HP_Poweroff_Warn()
{
    delete ui;
}

void HP_Poweroff_Warn::chongdian_on_toolButton_clicked()
{
    battery_warn_state = false;
        this->close();
}

void HP_Poweroff_Warn::on_toolButton_clicked(bool checked)
{
    battery_warn_state = false;
    this->close();
}

void HP_Poweroff_Warn::changeEvent(QEvent *e)
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
                ui->label_2->setText("电量低");
                ui->label->setText("请及时充电");
            }
            else if(para.toInt() == 1)
            {
                ui->label_2->setText("電量低");
                ui->label->setText("請及時充電");
            }
            else if(para.toInt() == 2)//english
            {
                ui->label_2->setText("Low power");
                ui->label->setText("Please change");
            }
            else if(para.toInt() == 3)//俄语
            {
                ui->label_2->setText("Батарея разряжена");
                ui->label->setText("заряжайте вовремя");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                ui->label_2->setText("Akku lemerült");
                ui->label->setText("Alacsony energia");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                ui->label_2->setText("Abtería baja");
                ui->label->setText("Por favor, cargar a tiempo");
            }
        }
        break;
    default:
        break;
    }
}

void HP_Poweroff_Warn::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key() == 0x1000000){
        battery_warn_state = false;
         this->close();
    }
}
