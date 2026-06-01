#include  "hp_sis_content.h"
#include  "ui_hp_sis_content.h"

hp_sis_content::hp_sis_content(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hp_sis_content)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    setGeometry(230,160,width(),height());
    signal_type = 0;
    m_objectName == "pushButton_ok";
    setOkButton(true);
    setCannelButton(false);
}

hp_sis_content::~hp_sis_content()
{
    delete ui;
}
void hp_sis_content::hp_setDefine_S3x0(bool isSelect)//设置宏定义中是否为5.5寸屏，从配置文件中读取
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);

        this->setGeometry((384-235)/2+96,(272-105)/2,235,105);
        this->setFixedSize(235,105);

        ui->label_text->setGeometry(0,0,235,53);
        ui->pushButton_ok->setGeometry(ui->pushButton_ok->x() / 1.7,ui->pushButton_ok->y() / 1.7,ui->pushButton_ok->width() / 1.7,ui->pushButton_ok->height() / 1.7);
        ui->pushButton_cancel->setGeometry(ui->pushButton_cancel->x() / 1.7,ui->pushButton_cancel->y() / 1.7,ui->pushButton_cancel->width() / 1.7,ui->pushButton_cancel->height() / 1.7);

        ui->label_text->setFont(font9);
        ui->pushButton_ok->setFont(font9);
        ui->pushButton_cancel->setFont(font9);
    }
}
void hp_sis_content::slot_set_label_text(unsigned char *data)
{
    char *str1 = (char *)data;
//    QString temp = QString(QLatin1String(str1));
//   ui->label_text->setText(temp);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString strname = codec->toUnicode(str1);
    qDebug()<< "hp_sis_content::slot_set_label_text == > " << strname;
    ui->label_text->setText(strname);
//    Hp_TaskPkg::getInstance()->d
}
void hp_sis_content::on_pushButton_ok_released()
{
//    ui->label_text->setText("NUll");
    signal_on_pushButton_ok_or_cannal(1,ui->label_text->text());
    this->close();
}

void hp_sis_content::on_pushButton_cancel_released()
{
//    ui->label_text->setText("NUll");
    signal_on_pushButton_ok_or_cannal(0,ui->label_text->text());
    this->close();
}

void hp_sis_content::changeEvent(QEvent *e)
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

void hp_sis_content::setOkButton(bool state)
{
    if(!state)
        ui->pushButton_ok->setStyleSheet("border: 1px solid  #7CA6C9;background-color: rgba(255, 255, 255, 0);color:#7CA6C9;");
    else
        ui->pushButton_ok->setStyleSheet("border: 2px solid  #7CA6C9;background-color: rgba(255, 255, 255, 0);color:#7CA6C9;");
}

void hp_sis_content::setCannelButton(bool state)
{
    if(!state)
        ui->pushButton_cancel->setStyleSheet("border: 1px solid  #7CA6C9;background-color: rgba(255, 255, 255, 0);color:#7CA6C9;");
    else
        ui->pushButton_cancel->setStyleSheet("border: 2px solid  #7CA6C9;background-color: rgba(255, 255, 255, 0);color:#7CA6C9;");
}

void hp_sis_content::keyReleaseEvent(QKeyEvent *ev)
{
//    switch(ev->key())
//    {
//    case KEY_RIGHT:
//        if(m_objectName == "pushButton_ok")
//        {
//            m_objectName ="pushButton_cancel";
//            setOkButton(false);
//            setCannelButton(true);
//        }

//        break;
//    case KEY_LEFT:
//        if(m_objectName == "pushButton_cancel")
//        {
//            m_objectName = "pushButton_ok";
//            setOkButton(true);
//            setCannelButton(false);
//        }
//        break;
//    case KEY_OK:
//        if(m_objectName == "pushButton_cancel")
//            on_pushButton_cancel_released();
//        else if(m_objectName == "pushButton_ok")
//            on_pushButton_ok_released();

//        break;
//    }
}
