#include  "hp_dialog.h"
#include  "ui_hp_dialog.h"

Hp_Dialog::Hp_Dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    isDelayClose = false;
    setGeometry((800 - width()) / 2, (480 - height()) / 2, width(), height());
    setFixedSize(this->width(), this->height());
}

Hp_Dialog::~Hp_Dialog()
{
    delete ui;
}
void Hp_Dialog::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);

        this->setGeometry((480 - 120) / 2, (272-70) / 2, 120, 70);
        this->setFixedSize(120,70);
        ui->label->setGeometry(0,0,120,80);

        ui->label->setFont(font9);
    }
}
void Hp_Dialog::changeEvent(QEvent *e)
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

void Hp_Dialog::setText(QString test)
{
    ui->label->setText(test);
}


void Hp_Dialog::setDelayClose(int msec)
{
    if(!isDelayClose)
    {
        isDelayClose = true;
        QTimer::singleShot(msec, this, SLOT(delayClose()));//只触发一次
    }
}

void Hp_Dialog::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << " Hp_Dialog::keyReleaseEvent" << event->nativeScanCode();
    switch(event->key())
    {
    case KEY_RETURN:
        signal_set_dialog_close(isDelayClose);
        break;
    }
}

void Hp_Dialog::delayClose()
{
    qDebug() << "Hp_Dialog::delayClose" << isDelayClose;
    isDelayClose = false;
    this->close();
}
