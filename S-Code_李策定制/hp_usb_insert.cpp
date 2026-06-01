#include  "hp_usb_insert.h"
#include  "ui_hp_usb_insert.h"

HP_USB_insert::HP_USB_insert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HP_USB_insert)
{
    ui->setupUi(this);
}

HP_USB_insert::~HP_USB_insert()
{
    delete ui;
}
void HP_USB_insert::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        this->resize(480,272);
        ui->label->setGeometry(0,0,480,272);
    }
}
void HP_USB_insert::keyPressEvent(QKeyEvent *ev)
{

}

void HP_USB_insert::keyReleaseEvent(QKeyEvent *ev)
{
  //   this->close();
}

void HP_USB_insert::mousePressEvent(QMouseEvent *ev)
{


}

void HP_USB_insert::mouseReleaseEvent(QMouseEvent *ev)
{

}

void HP_USB_insert::mouseMoveEvent(QMouseEvent *ev)
{
 //     this->close();

}

