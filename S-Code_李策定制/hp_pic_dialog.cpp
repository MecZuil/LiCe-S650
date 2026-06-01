#include  "hp_pic_dialog.h"
#include  "ui_hp_pic_dialog.h"

Hp_Pic_Dialog::Hp_Pic_Dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Pic_Dialog)
{
    ui->setupUi(this);
    setGeometry((800-width())/2,(402-height())/2,width(),height());

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout( )), this, SLOT(slot_handleTimeout ( )));
}

Hp_Pic_Dialog::~Hp_Pic_Dialog()
{
    delete ui;
}
void Hp_Pic_Dialog::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font14;
        font14.setPointSize(14);

        this->setGeometry((480-240)/2,(222-136)/2,240,136);
        ui->frame->setGeometry(0,0,240,136);
        ui->label_text->setGeometry(10,40,221,51);
        ui->pushButton_exit->setGeometry(209,0,31,31);

        ui->label_text->setFont(font14);
    }
}
void Hp_Pic_Dialog::time_select(int time)
{
    this->show();
    timer->start(time*1000);
}

void Hp_Pic_Dialog::on_pushButton_exit_released()
{
    this->close();
}

void Hp_Pic_Dialog::slot_handleTimeout()
{
    this->close();
}

void Hp_Pic_Dialog::changeEvent(QEvent *e)
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
                ui->label_text->setText("提示：图片已损坏");
            }
            else if(para.toInt() == 1)
            {
                ui->label_text->setText("提示：圖片已損壞");
            }
            else if(para.toInt() == 2)//english
            {
                ui->label_text->setText("Warning:Picture Error");
            }
            else if(para.toInt() == 3)//俄语
            {
                ui->label_text->setText("изображение повреждено");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                ui->label_text->setText("Figyelmeztetés: Képhiba");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                ui->label_text->setText("Cuidado: Error de Foto");
            }
        }
        break;
    default:
        break;
    }
}
