#include "hp_panorama_dialog.h"
#include "ui_hp_panorama_dialog.h"

Hp_Panorama_Dialog::Hp_Panorama_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hp_Panorama_Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    setGeometry(310,160,width(),height());
}

Hp_Panorama_Dialog::~Hp_Panorama_Dialog()
{
    delete ui;
}
void Hp_Panorama_Dialog::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font12;
        font12.setPointSize(12);

        this->setGeometry(186,90,181,85);
        ui->frame->setGeometry(0,0,181,85);
        ui->label_text->setGeometry(1,1,179,40);
        ui->pushButton_cancel->setGeometry(100,45,51,31);
        ui->pushButton_ok->setGeometry(30,45,51,31);

        ui->label_text->setFont(font12);
        ui->pushButton_cancel->setFont(font12);
        ui->pushButton_ok->setFont(font12);
    }
}

void Hp_Panorama_Dialog::setDialogText(QString text)
{
    ui->label_text->setText(text);
}

void Hp_Panorama_Dialog::on_pushButton_ok_released()
{
    qDebug() << "Hp_Panorama_Dialog::on_pushButton_ok_released ";
    signal_update_lcdoff_time(true);
    signal_panorama_start();

    this->close();
}

void Hp_Panorama_Dialog::on_pushButton_cancel_released()
{
    signal_update_lcdoff_time(true);
    this->close();
}

void Hp_Panorama_Dialog::slot_panorama_dialog_type(int type)
{
    QString para;

    switch(type)
    {
    case 0:
            para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
            if(para !=NULL)
            {
                if(para.toInt() == 0)
                {
                    ui->label_text->setText("是否进入全景拍照模式");
                    ui->pushButton_ok->setText("确定");
                    ui->pushButton_cancel->setText("取消");
                }
                else if(para.toInt() == 1)
                {
                    ui->label_text->setText("是否删除設備清單");
                    ui->pushButton_ok->setText("確定");
                    ui->pushButton_cancel->setText("取消");
                }
                else if(para.toInt() == 2)//english
                {
                    ui->label_text->setText("Delete device list");
                    ui->pushButton_ok->setText("OK");
                    ui->pushButton_cancel->setText("Cancel");
                }
                else if(para.toInt() == 3)//俄语
                {
                    ui->label_text->setText("Удалить список устройств");
                    ui->pushButton_ok->setText("ОК");
                    ui->pushButton_cancel->setText("Отм");
                }
                else if(para.toInt() == 4)//匈牙利语
                {
                    ui->label_text->setText("Eszkzlista trlése");
                    ui->pushButton_ok->setText("Igen");
                    ui->pushButton_cancel->setText("Mégse");
                }
                else if(para.toInt() == 5)//西班牙语
                {
                    ui->label_text->setText("Eliminar la lista de dispositivos");
                    ui->pushButton_ok->setText("OK");
                    ui->pushButton_cancel->setText("Cancel");
                }
            }
            this->show();
            break;
    default:
            break;
    }
}

void Hp_Panorama_Dialog::changeEvent(QEvent *e)
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
