#include "hp_mulhom_edit.h"
#include "ui_hp_mulhom_edit.h"

hp_mulhom_edit::hp_mulhom_edit(QWidget *parent) : QWidget(parent),
    ui(new Ui::hp_mulhom_edit)
{
     ui->setupUi(this);

     max_temp = 600;

     connect(ui->ScrollBar_mulhom,SIGNAL(signal_mouseRelease()),this,SLOT(scrollBar_mulhom_mouseRelease()));
}
hp_mulhom_edit::~hp_mulhom_edit()
{
    delete ui;
}
void hp_mulhom_edit::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->resize(480,272);
        ui->frame->setGeometry(0,0,480,272);

        ui->label_16->setGeometry(ui->label_16->x() / 1.7,ui->label_16->y() / 1.7,ui->label_16->width(),ui->label_16->height() / 1.7);
        ui->ScrollBar_mulhom->setGeometry(ui->ScrollBar_mulhom->x() / 1.7,ui->ScrollBar_mulhom->y() / 1.7,ui->ScrollBar_mulhom->width(),ui->ScrollBar_mulhom->height() / 1.7);

        ui->label_16->setFont(font10);
        ui->ScrollBar_mulhom->hp_setFont(font10);
        ui->frame->setFont(font10);
    }else{
        QFont font17;
        font17.setPointSize(17);

        ui->ScrollBar_mulhom->hp_setFont(font17);
    }
}
//void hp_mulhom_edit::on_ScrollBar_mulhom_valueChanged(int arg1)
//{
//    max_temp = arg1;
//    signal_update_lcdoff_time(false);
//    hp_mulhom_edit_value_changed(max_temp);
//}
void hp_mulhom_edit::mulhom_value_init(int val)
{
    qDebug() << "hp_mulhom_edit::mulhom_value_init ---- > " << val;
    double ret = val / (double)100;
//    qDebug() << "hp_mulhom_edit ---- > mulhom_value_init --ret-- > " << ret;
    ui->ScrollBar_mulhom->setValue(ret);
    max_temp = ui->ScrollBar_mulhom->value();
}
void hp_mulhom_edit::scrollBar_mulhom_mouseRelease()
{
//    qDebug() << "hp_mulhom_edit::scrollBar_mulhom_mouseRelease == > " << ret;
    max_temp = ui->ScrollBar_mulhom->value();
    signal_update_lcdoff_time(false);
    hp_mulhom_edit_value_changed(max_temp);
}

void hp_mulhom_edit::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug() << "hp_Isotherm::keyReleaseEvent >> " << ev->key();
    signal_update_lcdoff_time(true);
    switch(ev->key())
    {
        case KEY_CAMERA_PICTURE:                    //按键用来 获取图片 0x43
            break;
        case KEY_RETURN:
            on_toolButton_back_clicked();
        break;
    }
}


void hp_mulhom_edit::on_toolButton_back_clicked()
{
    this->close();
}

void hp_mulhom_edit::changeEvent(QEvent *e)
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
