#include  "hp_avi_mode.h"
#include  "ui_hp_avi_mode.h"

HP_Avi_mode::HP_Avi_mode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HP_Avi_mode)
{
    ui->setupUi(this);
    setGeometry((640-width())/2+160,(480-height())/2,width(),height());  //384->640   96->160  272->480
    setFixedSize(this->width(), this->height());
}

HP_Avi_mode::~HP_Avi_mode()
{
    delete ui;
}
void HP_Avi_mode::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->resize(220,90);
        ui->frame->setGeometry(0,0,220,90);
        ui->label->setGeometry(50,0,131,31);
        ui->pushButton_avi->setGeometry(19,40,81,30);
        ui->pushButton_hir->setGeometry(120,40,81,30);
        ui->toolButton->setGeometry(200,0,21,20);

        ui->label->setFont(font10);
        ui->pushButton_avi->setFont(font10);
        ui->pushButton_hir->setFont(font10);
    }
}
void HP_Avi_mode::on_pushButton_avi_released()
{
    signal_core_key_record_avi_mode_start();
    signal_avi_hir_mode(1);
    this->close();
}

void HP_Avi_mode::on_pushButton_hir_released()
{
    signal_core_key_record_hir_mode_start();
    signal_avi_hir_mode(2);
    this->close();
}

void HP_Avi_mode::on_toolButton_released()
{
    this->close();
}

void HP_Avi_mode::changeEvent(QEvent *e)
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
                ui->label->setText("请选择模式：");
                ui->pushButton_avi->setText("视频流");
                ui->pushButton_hir->setText("辐射流");
            }
            else if(para.toInt() == 1)
            {
                ui->label->setText("請選擇模式：");
                ui->pushButton_avi->setText("視頻流");
                ui->pushButton_hir->setText("輻射流");
            }
            else if(para.toInt() == 2)//english
            {
                ui->label->setText("Please select mode :");
                ui->pushButton_avi->setText("Video flow");
                ui->pushButton_hir->setText("Radiant flow");
            }
            else if(para.toInt() == 3)//俄语
            {
                ui->label->setText("выберите режим");
                ui->pushButton_avi->setText("Поток видео");
                ui->pushButton_hir->setText("Радиометр видео");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                ui->label->setText("Válasszon üzemmódot:");
                ui->pushButton_avi->setText("Videófolyamat");
                ui->pushButton_hir->setText("Hökép-szekvencia");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                ui->label->setText("Por favor Seleccionar un modo:");
                ui->pushButton_avi->setText("Video en directo");
                ui->pushButton_hir->setText("Corriente de Radiación");
            }
        }
        break;
    default:
        break;
    }
}
