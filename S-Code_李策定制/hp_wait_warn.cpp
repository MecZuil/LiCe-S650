#include  "hp_wait_warn.h"
#include  "ui_hp_wait_warn.h"
#include     <QDebug>
#include     <QKeyEvent>
Hp_wait_warn::Hp_wait_warn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_wait_warn)
{
    ui->setupUi(this);
    setGeometry((540-width())/2+160,(600-height())/2,width(),height());
    setWindowFlags(Qt::WindowStaysOnTopHint);

    QString para;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    if(para !=NULL)
    {
        if(para.toInt() == 0)
        {
            ui->label_2->setText("图片处理中，请等待");
        }
        else if(para.toInt() == 1)
        {
            ui->label_2->setText("圖片處理中，請等待");
        }
        else if(para.toInt() == 2)//english
        {
            ui->label_2->setText("processing");
        }
        else if(para.toInt() == 3)//俄语
        {
            ui->label_2->setText("пожалуйста");
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            ui->label_2->setText("kérem várjon");
        }
        else if(para.toInt() == 5)//西班牙语
        {
            ui->label_2->setText("Espere");
        }
    }
}

Hp_wait_warn::~Hp_wait_warn()
{
    delete ui;
}

void Hp_wait_warn::hp_setS3X0(bool isS3X0)
{
    qDebug() << ">> Hp_wait_warn::hp_setS3X0 <<";
    if(isS3X0)
    {
        QFont font11;
        font11.setPointSize(11);
        this->setGeometry(this->x() / 1.7 + 10,this->y() / 1.7,this->width() / 1.7,this->height() / 1.7);
        ui->label_2->setGeometry(ui->label_2->x() / 1.7,ui->label_2->y() / 1.7,ui->label_2->width() / 1.7,ui->label_2->height() / 1.7);
        ui->label_2->setFont(font11);
    }
}

void Hp_wait_warn::changeEvent(QEvent *e)
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
                ui->label_2->setText("图片处理中，请等待");
            }
            else if(para.toInt() == 1)
            {
                ui->label_2->setText("圖片處理中，請等待");
            }
            else if(para.toInt() == 2)//english
            {
                ui->label_2->setText("processing");
            }
            else if(para.toInt() == 3)//俄语
            {
                ui->label_2->setText("пожалуйста");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                ui->label_2->setText("kérem várjon");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                ui->label_2->setText("Espere");
            }
        }
        break;
    default:
        break;
    }
}
void Hp_wait_warn::keyReleaseEvent(QKeyEvent *ev)
{

}
