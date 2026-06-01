#include  "hp_ble_dialog.h"
#include  "ui_hp_ble_dialog.h"

Hp_Ble_Dialog::Hp_Ble_Dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Ble_Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    isS3x0 = false;
    setGeometry(310,160,width(),height());
    signal_type = 0;
}

Hp_Ble_Dialog::~Hp_Ble_Dialog()
{
    delete ui;
}
void Hp_Ble_Dialog::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        isS3x0 = isSelect;
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

void Hp_Ble_Dialog::setSingleButton()
{
    if(!isS3x0)
    {
        ui->pushButton_cancel->close();
        ui->pushButton_ok->setGeometry(110,80,75,41);
    }
    else
    {
        ui->pushButton_cancel->close();
        ui->pushButton_ok->setGeometry(65,45,51,31);
    }
}

void Hp_Ble_Dialog::setDialogText(QString text)
{
    ui->label_text->setText(text);
}

void Hp_Ble_Dialog::on_pushButton_ok_released()
{
    signal_ble_match_delete(signal_type);
    if(!isS3x0)
    {
        ui->pushButton_cancel->setGeometry(160,80,75,41);
        ui->pushButton_ok->setGeometry(50,80,75,41);
    }
    else
    {
        ui->pushButton_cancel->setGeometry(100,45,51,31);
        ui->pushButton_ok->setGeometry(30,45,51,31);
    }
    this->close();
}

void Hp_Ble_Dialog::on_pushButton_cancel_released()
{
    if(!isS3x0)
    {
        ui->pushButton_cancel->setGeometry(160,80,75,41);
        ui->pushButton_ok->setGeometry(50,80,75,41);
    }
    else
    {
        ui->pushButton_cancel->setGeometry(100,45,51,31);
        ui->pushButton_ok->setGeometry(30,45,51,31);
    }
    this->close();
}

void Hp_Ble_Dialog::slot_ble_dialog_type(int type)
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
                    ui->label_text->setText("是否删除设备列表");
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
    case 1:
            para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
            if(para !=NULL)
            {
                if(para.toInt() == 0)
                {
                    ui->label_text->setText("此操作将断开链接");
                    ui->pushButton_ok->setText("确定");
                    ui->pushButton_cancel->setText("取消");
                }
                else if(para.toInt() == 1)
                {
                    ui->label_text->setText("此操作將斷開連接");
                    ui->pushButton_ok->setText("確定");
                    ui->pushButton_cancel->setText("取消");
                }
                else if(para.toInt() == 2)//english
                {
                    ui->label_text->setText("This action will break the link");
                    ui->pushButton_ok->setText("OK");
                    ui->pushButton_cancel->setText("Cancel");
                }
                else if(para.toInt() == 3)//俄语
                {
                    ui->label_text->setText("действие приведет к разъед");
                    ui->pushButton_ok->setText("ОК");
                    ui->pushButton_cancel->setText("Отм");
                }
                else if(para.toInt() == 4)//匈牙利语
                {
                    ui->label_text->setText("Ez a folyamat leáll");
                    ui->pushButton_ok->setText("Igen");
                    ui->pushButton_cancel->setText("Mégse");
                }
                else if(para.toInt() == 5)//西班牙语
                {
                    ui->label_text->setText("Esta acción desconectará el enlace");
                    ui->pushButton_ok->setText("OK");
                    ui->pushButton_cancel->setText("Cancel");
                }
            }
            signal_type = 1;
            this->show();
        break;
    default:
            break;
    }
}

void Hp_Ble_Dialog::changeEvent(QEvent *e)
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

