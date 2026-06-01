#include  "hpsetting_adjust.h"
#include  "ui_hpsetting_adjust.h"

HpSetting_adjust::HpSetting_adjust(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HpSetting_adjust)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    setGeometry(360,176,width(),height());

}

HpSetting_adjust::~HpSetting_adjust()
{
    delete ui;
}

void HpSetting_adjust::on_pushButton_ok_released()
{
    signal_dangwei_jingtou_adjust(true);
    this->close();
}

void HpSetting_adjust::on_pushButton_cancel_released()
{
    signal_dangwei_jingtou_adjust(false);
    this->close();
}
