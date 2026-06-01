#include  "hphide_dialog_save.h"
#include  "ui_hphide_dialog_save.h"

Hphide_Dialog_SAVE::Hphide_Dialog_SAVE(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hphide_Dialog_SAVE)
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
            ui->label->setText("保存......");
        }
        else if(para.toInt() == 1)
        {
            ui->label->setText("保存......");
        }
        else if(para.toInt() == 2)//english
        {
            ui->label->setText("Saving......");
        }
        else if(para.toInt() == 3)//俄语
        {
            ui->label->setText("Сохранение......");
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            ui->label->setText("Mentés......");
        }
        else if(para.toInt() == 5)//西班牙语
        {
            ui->label->setText("Guardando......");
        }
    }
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout( )), this, SLOT(slot_handleTimeout ( )));
   timer->start(65*1000);
}

Hphide_Dialog_SAVE::~Hphide_Dialog_SAVE()
{
    delete ui;
}
void Hphide_Dialog_SAVE::hp_setDefine_S3x0(bool isSelect)
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
void Hphide_Dialog_SAVE::slot_handleTimeout()
{
    this->close();
}
