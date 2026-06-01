#include  "hp_twice_pic.h"
#include  "ui_hp_twice_pic.h"

HP_Twice_Pic::HP_Twice_Pic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HP_Twice_Pic)
{
    picture = "";
    ui->setupUi(this);
     update();
     dateFolderPath = "/run/media/mmcblk2p1/DCIM";
}

HP_Twice_Pic::~HP_Twice_Pic()
{
    delete ui;
}
void HP_Twice_Pic::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        this->resize(480,272);
        ui->frame->setGeometry(0,0,480,272);
        ui->frame_2->setGeometry(80,60,321,152);
        ui->frame_3->setGeometry(0,0,80,212);
        ui->frame_4->setGeometry(0,212,480,60);
        ui->pushButton_cut->setGeometry(260,10,91,41);
        ui->pushButton_return->setGeometry(360,10,91,41);
        ui->frame_5->setGeometry(80,0,320,60);
        ui->label_name->setGeometry(0,5,291,40);
        ui->frame_6->setGeometry(400,0,80,212);
    }
}
void HP_Twice_Pic::paintEvent(QPaintEvent *ev)
{
//    QString picture_path;
//    picture_path = "/run/media/mmcblk2p1/DCIM/"+picture;
    QImage img(picture);
    QPixmap pix = QPixmap::fromImage(img);

    qDebug( )<<"  @@@@@@@@@@@@ width"<<pix.width();
    qDebug( )<<"  @@@@@@@@@@@@ height"<<pix.height();

    QPainter painter(this);
    painter.drawPixmap(160,60,480,360,pix);

}

void HP_Twice_Pic::slot_pic_kjg_open(QString file)
{
        qDebug( )<<" @@@@@@@@@ file = "<<file;
        picture = dateFolderPath + file;
        qDebug( )<<" @@@@@@@@@ picture = "<<picture;
        ui->label_name->setText(file);
        this->show();
  //      update();
}


void HP_Twice_Pic::on_pushButton_return_released()
{
    signal_update_lcdoff_time(false);
    picture = "";
    this->close();
}

void HP_Twice_Pic::on_pushButton_cut_released()
{
    signal_update_lcdoff_time(false);
     update();
}

void HP_Twice_Pic::SlotSendDateFolderPath(QString path)
{
    dateFolderPath = path;
}

