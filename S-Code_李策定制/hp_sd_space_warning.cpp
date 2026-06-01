#include  "hp_sd_space_warning.h"
#include  "ui_hp_sd_space_warning.h"

Hp_Sd_Space_Warning::Hp_Sd_Space_Warning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Sd_Space_Warning)
{
    ui->setupUi(this);

    setGeometry((640-width())/2+160,(480-height())/2,width(),height());  //384->640   96->160  272->480
    setFixedSize(this->width(), this->height());
}

Hp_Sd_Space_Warning::~Hp_Sd_Space_Warning()
{
    delete ui;
}
void Hp_Sd_Space_Warning::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);

        this->setGeometry((384-260)/2+96,(272-80)/2,260,80);
        ui->frame->setGeometry(0,0,260,30);
        ui->label_title->setGeometry(0,0,221,30);
        ui->toolButton->setGeometry(230,3,24,24);
        ui->label_text->setGeometry(0,30,260,51);

        ui->label_title->setFont(font9);
        ui->label_text->setFont(font9);
    }
}
void Hp_Sd_Space_Warning::changeEvent(QEvent *e)
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

void Hp_Sd_Space_Warning::warning(QString title, QString text)
{
    ui->label_title->setText(title);
    ui->label_text->setText(text);
}

void Hp_Sd_Space_Warning::setDelayClose(int ms)
{
    QTimer::singleShot(ms, this, SLOT(timer_finish()));
}

void Hp_Sd_Space_Warning::timer_finish()
{
    close();
}
