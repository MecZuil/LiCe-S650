#include "hp_wifi_search_dialog.h"
#include "ui_hp_wifi_search_dialog.h"

Hp_Wifi_search_Dialog::Hp_Wifi_search_Dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Wifi_search_Dialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    Iscancel = false;
    IsEmpty = false;
}
Hp_Wifi_search_Dialog::~Hp_Wifi_search_Dialog()
{
    delete ui;
}
void Hp_Wifi_search_Dialog::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->resize(this->width() / 1.7,this->height() / 1.7);
        this->move((480 - this->width()) / 2,(272 - this->height()) / 2);

        ui->frame->resize(this->width(),this->height());

        ui->label_3->setGeometry(ui->label_3->x() / 1.7,ui->label_3->y() / 1.7,ui->label_3->width() / 1.7,ui->label_3->height() / 1.7);
        ui->pushButton_ok->setGeometry(ui->pushButton_ok->x() / 1.7,ui->pushButton_ok->y() / 1.7,ui->pushButton_ok->width() / 1.7,ui->pushButton_ok->height() / 1.7);

        ui->label_3->setFont(font10);
        ui->pushButton_ok->setFont(font10);
    }
}
void Hp_Wifi_search_Dialog::Set_label_text(QString str)
{
    ui->label_3->setText(str);
}

void Hp_Wifi_search_Dialog::SetHideButton(bool ishide)
{
    if(ishide)
    {
        ui->pushButton_ok->hide();
//        ui->label_3->setGeometry(10, 50, 281, 46);
    }else{
        ui->pushButton_ok->show();
//        ui->label_3->setGeometry(10, 20, 281, 46);
    }
}

void Hp_Wifi_search_Dialog::Set_button_text(QString str)
{
    ui->pushButton_ok->setText(str);
}
void Hp_Wifi_search_Dialog::SetControlEnabled(int i,bool ret)
{
    ui->pushButton_ok->setEnabled(ret);
}
void Hp_Wifi_search_Dialog::on_pushButton_ok_clicked()
{
    if(IsEmpty)
    {
        IsEmpty = false;
        signal_IsEmpty();
    }
    if(Iscancel)
    {
        Iscancel = false;
        signal_set_cancel();
    }
    this->close();
}
void Hp_Wifi_search_Dialog::setDelayClose(int ms)
{
    QTimer::singleShot(ms, this, SLOT(timer_finish()));//只触发一次
}
void Hp_Wifi_search_Dialog::timer_finish()
{
    this->close();
}
void Hp_Wifi_search_Dialog::slot_close()
{
    on_pushButton_ok_clicked();
}
void Hp_Wifi_search_Dialog::Set_label_wait()
{
    QString para;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    if(para !=NULL)
    {
        if(para.toInt() == 0)
        {
            ui->label_3->setText(tr("Wifi连接中，请等待..."));
            ui->pushButton_ok->setText("取消");
        }
        else if(para.toInt() == 1)
        {
            ui->label_3->setText(tr("WIFI連接中，請稍等..."));
            ui->pushButton_ok->setText("取消");
        }
        else if(para.toInt() == 2)//english
        {
            ui->label_3->setText(tr("WiFi connection in progress"));
            ui->pushButton_ok->setText("Cancel");
        }
        else if(para.toInt() == 3)//俄语
        {
            ui->label_3->setText(tr("соединение WIFI"));
            ui->pushButton_ok->setText("Отм");
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            ui->label_3->setText(tr("WiFi kapcsolat folyamatban"));
            ui->pushButton_ok->setText("Mégse");
        }
        else if(para.toInt() == 5)//西班牙语
        {
            ui->label_3->setText(tr("Conexión wifi"));
            ui->pushButton_ok->setText("Cancel");
        }
    }
    Iscancel = true;
    this->show();
}
void Hp_Wifi_search_Dialog::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == KEY_RETURN)
    {
        this->close();
    }
}
void Hp_Wifi_search_Dialog::changeEvent(QEvent *e)
{//有时候会导致卡住？？？
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

