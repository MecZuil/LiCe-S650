#include  "hp_picture_mode.h"
#include  "ui_hp_picture_mode.h"
#include  <QDebug>

hp_picture_mode::hp_picture_mode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hp_picture_mode)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    setGeometry((640-width())/2+80,(480-height())/2,width(),height());  //384->640   96->160  272->480

    isTempMode = true;

    setTempButton(isTempMode);
    setRowButton(!isTempMode);
}

hp_picture_mode::~hp_picture_mode()
{
    delete ui;
}

void hp_picture_mode::keyReleaseEvent(QKeyEvent *ev)
{
    switch(ev->key())
    {
    case KEY_RETURN:
        this->close();
         signal_un_freeze();
        break;
//    case KEY_LEFT:
//        if( isTempMode )
//            isTempMode = false;
//        else
//            isTempMode = true;
//        setTempButton(isTempMode);
//        setRowButton(!isTempMode);
//        break;
//    case KEY_RIGHT:
//        if( isTempMode )
//            isTempMode = false;
//        else
//            isTempMode = true;
//        setTempButton(isTempMode);
//        setRowButton(!isTempMode);
//        break;
//    case KEY_OK:
//        if( isTempMode )
//            on_pushButton_temp_clicked();
//        else
//            on_pushButton_row_clicked();
//        break;
    default:
        break;
    }
}

void hp_picture_mode::on_pushButton_temp_clicked()
{
    if( !isTempMode )
        isTempMode = true;
    signal_temp_row_mode(0);
    this->close();
    signal_wait_warn();
}

void hp_picture_mode::on_pushButton_row_clicked()
{
    if( isTempMode )
        isTempMode = false;
    signal_temp_row_mode(1);
    this->close();
}

void hp_picture_mode::on_toolButton_clicked()
{
    this->close();
    signal_un_freeze();
}

void hp_picture_mode::setTempButton(bool state)
{
    if(!state)
        ui->pushButton_temp->setStyleSheet("border-image:url(:/res/res/mode_button_n.png);color:#7CA6C9;");
    else
        ui->pushButton_temp->setStyleSheet("border-image:url(:/res/res/mode_button_s.png);color:#7CA6C9;");
}

void hp_picture_mode::setRowButton(bool state)
{
    if(!state)
        ui->pushButton_row->setStyleSheet("border-image:url(:/res/res/mode_button_n.png);color:#7CA6C9;");
    else
        ui->pushButton_row->setStyleSheet("border-image:url(:/res/res/mode_button_s.png);color:#7CA6C9;");
}
