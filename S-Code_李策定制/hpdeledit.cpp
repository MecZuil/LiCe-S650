#include  "hpdeledit.h"
#include  "ui_hpdeledit.h"

hpDelEdit::hpDelEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hpDelEdit)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    setGeometry(160+(640-width())/2,3,width(),height());// 96->160  384->640
    setFixedSize(this->width(), this->height());


}

hpDelEdit::~hpDelEdit()
{
    delete ui;
}
void hpDelEdit::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        this->setGeometry(96+(384-width())/2,3,80,40);
        this->setFixedSize(80,40);
        ui->frame->setGeometry(0,0,80,40);
        ui->del->setGeometry(2,2,36,36);
        ui->edit->setGeometry(40,2,36,36);
    }
}
void hpDelEdit::changeEvent(QEvent *e)
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

