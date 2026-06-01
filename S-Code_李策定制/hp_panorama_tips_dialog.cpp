#include "hp_panorama_tips_dialog.h"
#include "ui_hp_panorama_tips_dialog.h"

Hp_Panorama_Tips_Dialog::Hp_Panorama_Tips_Dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Panorama_Tips_Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::ApplicationModal);
    ui->label_text->setWordWrap(true);
    setGeometry(360,160,width(),height());

    QFont font10;
    font10.setPointSize(10);
    ui->label_text->setFont(font10);
    ui->pushButton_ok->setFont(font10);
    ui->pushButton_cancel->setFont(font10);
}

Hp_Panorama_Tips_Dialog::~Hp_Panorama_Tips_Dialog()
{
    delete ui;
}
void Hp_Panorama_Tips_Dialog::hp_setDefine5_5(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->resize(300 / 1.7,150 / 1.7);
        this->move((372 - this->width()) / 2,(272 - this->height()) / 2);
        ui->label_text->setGeometry(10 / 1.7,10 / 1.7,280 / 1.7,65 / 1.7);
        ui->pushButton_cancel->setGeometry(175 / 1.7,100 / 1.7,75 / 1.7,40 / 1.7);
        ui->pushButton_ok->setGeometry(50 / 1.7,100 / 1.7,75 / 1.7,40 / 1.7);

        ui->label_text->setFont(font10);
        ui->pushButton_ok->setFont(font10);
        ui->pushButton_cancel->setFont(font10);
    }
}

void Hp_Panorama_Tips_Dialog::setDialogText(QString text)
{
    ui->label_text->setText(text);
}

void Hp_Panorama_Tips_Dialog::on_pushButton_ok_released()
{
    qDebug() << "Hp_Panorama_Tips_Dialog::on_pushButton_ok_released ";
    signal_panorama_start();

    this->close();
}

void Hp_Panorama_Tips_Dialog::on_pushButton_cancel_released()
{
    signal_update_lcdoff_time(true);
    signal_panorama_stop();
    this->close();
}


void Hp_Panorama_Tips_Dialog::keyReleaseEvent(QKeyEvent *event)
{
    signal_update_lcdoff_time(true);
    qDebug() << " Hp_Panorama_Tips_Dialog::keyReleaseEvent" << event->key();
    switch(event->key())
    {
    case KEY_LASER:
        signal_panorama_start();
        break;
    case KEY_CAMERA_PICTURE:
//        this->close();
        signal_panorama_start();
        break;
    case KEY_RETURN:
//        this->close();
        signal_panorama_stop();
        break;
    }
}

void Hp_Panorama_Tips_Dialog::slot_panorama_dialog_type(int type)
{
    QString para;
    para = "1";
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    switch(type)
    {
    case 0:
        if(para != NULL)
        {
            qDebug() << "slot_panorama_dialog_type" << 4;
            if(para.toInt() == 0)
            {
                qDebug() << "slot_panorama_dialog_type" << 5;
                ui->label_text->setText("按确定或聚焦进入全景拍照模式");
                ui->pushButton_ok->setText("确定");
                ui->pushButton_cancel->setText("取消");
            }
            else if(para.toInt() == 1)
            {
                qDebug() << "slot_panorama_dialog_type" << 6;
                ui->label_text->setText("聚焦键进入全景拍照模式");
                ui->pushButton_ok->setText("確定");
                ui->pushButton_cancel->setText("取消");
            }
            else if(para.toInt() == 2)//english
            {
                qDebug() << "slot_panorama_dialog_type" << 7;
                ui->label_text->setText("Whether to enter panoramic mode");
                ui->pushButton_ok->setText("OK");
                ui->pushButton_cancel->setText("Cancel");
            }
            else if(para.toInt() == 3)//俄语
            {
                qDebug() << "slot_panorama_dialog_type" << 8;
                ui->label_text->setText("Войти в режим панорамной съемки");
                ui->pushButton_ok->setText("ОК");
                ui->pushButton_cancel->setText("NO");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                qDebug() << "slot_panorama_dialog_type" << 9;
                ui->label_text->setText("Belépni a panoráma üzemmódba");
                ui->pushButton_ok->setText("Igen");
                ui->pushButton_cancel->setText("Mégse");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                qDebug() << "slot_panorama_dialog_type" << 11;
                ui->label_text->setText("Si entrar en modo de fotografía panorámica");
                ui->pushButton_ok->setText("OK");
                ui->pushButton_cancel->setText("Cancel");
            }
            qDebug() << "slot_panorama_dialog_type" << 12;
        }
        this->show();
        break;
    case 1:
        if(para !=NULL)
        {
            if(para.toInt() == 0)
            {
                ui->label_text->setText("融合度过低是否继续");
                ui->pushButton_ok->setText("确定");
                ui->pushButton_cancel->setText("取消");
            }
            else if(para.toInt() == 1)
            {
                ui->label_text->setText("融合度过低是否继续");
                ui->pushButton_ok->setText("確定");
                ui->pushButton_cancel->setText("取消");
            }
            else if(para.toInt() == 2)//english
            {
                ui->label_text->setText("Fusion ");
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

void Hp_Panorama_Tips_Dialog::changeEvent(QEvent *e)
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
