#include  "hp_isotherm.h"
#include  "ui_hp_isotherm.h"

hp_Isotherm::hp_Isotherm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hp_Isotherm)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    ui->frame_dengwense->installEventFilter(this);
    ui->listWidget_dengwense->close();
    ui->listWidget_dengwense->setGeometry(300,140,240,19*16-3);
    listwidget_type=0;

    para_init();
}

hp_Isotherm::~hp_Isotherm()
{
    delete ui;
}
void hp_Isotherm::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->resize(480,272);
        ui->frame->setGeometry(0,0,480,272);
        ui->comboBox_dengwengaodu->setGeometry(170,170,220,25);
        ui->comboBox_dengwenwendu->setGeometry(170,120,221,25);
        ui->frame_dengwense->setGeometry(170,70,151,25);
        ui->label_dengwen->setGeometry(0,0,121,25);
        ui->label_dengwen_2->setGeometry(126,1,23,23);
        ui->label_15->setGeometry(20,70,111,25);
        ui->label_16->setGeometry(20,120,111,25);
        ui->label_17->setGeometry(20,170,111,25);
        ui->listWidget_dengwense->setGeometry(170,90,151,19*10-3);

        ui->comboBox_dengwengaodu->setFont(font10);
        ui->comboBox_dengwenwendu->setFont(font10);
        ui->label_dengwen->setFont(font10);
        ui->label_dengwen_2->setFont(font10);
        ui->label_15->setFont(font10);
        ui->label_16->setFont(font10);
        ui->label_17->setFont(font10);
        ui->frame->setFont(font10);
        ui->listWidget_dengwense->setFont(font10);
    }
}
void hp_Isotherm::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug() << "hp_Isotherm::keyReleaseEvent >> " << ev->key();
    switch(ev->key())
    {
    case KEY_CAMERA_PICTURE:                    //按键用来 获取图片 0x43
        break;
   case KEY_RETURN:
         signal_pc_image_set_Isotemp(Isotherm);
        this->close();
        break;
    }
}

bool hp_Isotherm::eventFilter(QObject *w, QEvent *e)
{
    if(QEvent::MouseButtonPress == e->type())               //先判断是鼠标点击事件
    {
        QMouseEvent *mouse_event = (QMouseEvent *)e;
        QPoint pressPoint;
        pressPoint = mouse_event->pos();

        switch(listwidget_type)
        {
        case 0:
        {
            if(w->objectName() == "frame_dengwense")
            {
                listwidget_drop_manage_dengwense(true);
            }
            break;
        }
        case 1:
            listwidget_drop_manage_dengwense(false);
            break;
        default:
            break;
        }
    }
    else if( e->type() == QKeyEvent::KeyRelease)               //按键松开事件
    {
        QKeyEvent *key_event = (QKeyEvent *)e;
        keyReleaseEvent(key_event);
    }else{};

    return true;
}

void hp_Isotherm::slot_pc_image_set_Isotherm(unsigned char return_value)
{
    qDebug("slot_pc_image_set_Isotherm return_value:0x%02x",return_value);
}

void hp_Isotherm::para_init()
{
    QString str,para;

    para = hpxmlreader.readXml("sys.xml","TEMPPARA","tempunit");
      if(para != NULL)
      {
          tempunit = para.toInt();
      }

    para = hpxmlreader.readXml("sys.xml","ISOTHERM","color");
    if(para!=NULL)
        Isotherm.IsoTempColorId = para.toInt();
    else
        Isotherm.IsoTempColorId = 0;

    para = hpxmlreader.readXml("sys.xml","ISOTHERM","temp100");
    if(para!= NULL)
        Isotherm.IsoTemp100 = para.toInt();
    else
       Isotherm.IsoTemp100 =3500;

     para = hpxmlreader.readXml("sys.xml","ISOTHERM","tempheight100");
     if(para != NULL)
         Isotherm.IsoTempHigh100 = para.toInt();
     else
         Isotherm.IsoTempHigh100 = 200;
    para = hpxmlreader.readXml("sys.xml","ALARM","temp100");

     ui->listWidget_dengwense->setCurrentRow(Isotherm.IsoTempColorId);
     ui->comboBox_dengwenwendu->setValue(hptempunitconvert.getTempValue(tempunit,Isotherm.IsoTemp100)/100.0);
     ui->comboBox_dengwengaodu->setValue(hptempunitconvert.getCTempValue(tempunit,Isotherm.IsoTempHigh100)/100.0);
}

void hp_Isotherm::listwidget_drop_manage_dengwense(bool type)
{
    if(type == true)
    {
        listwidget_type=1;
//        ui->listWidget_dengwense->setGeometry(300,140,240,19*16-3);
        ui->listWidget_dengwense->show();
        ui->comboBox_dengwengaodu->setEnabled(false);
        ui->comboBox_dengwenwendu->setEnabled(false);
    }
    else
    {
        listwidget_type=0;
        ui->listWidget_dengwense->close();
        ui->comboBox_dengwengaodu->setEnabled(true);
        ui->comboBox_dengwenwendu->setEnabled(true);
    }
}

void hp_Isotherm::changeEvent(QEvent *e)
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


void hp_Isotherm::on_listWidget_dengwense_currentRowChanged(int currentRow)
{
    if( currentRow<0)
    {
        return;
    }
    QString str;
    str= ui->listWidget_dengwense->currentItem()->text();
    ui->label_dengwen->setText(str);
    listwidget_drop_manage_dengwense(false);
    Isotherm.IsoTempColorId = currentRow;
    //signal_pc_image_set_Isotemp(Isotherm);
    update();
}

void hp_Isotherm::on_comboBox_dengwenwendu_valueChanged(double value)
{
    qDebug("cwfw_dengwenwendu_value_changed:unit:%d value:%f cvalue:%d",tempunit,value,hptempunitconvert.getCTempValue(tempunit,value*100));
    Isotherm.IsoTemp100 = hptempunitconvert.getCTempValue(tempunit,value*100);
    //signal_pc_image_set_Isotemp(Isotherm);
    update();
}

void hp_Isotherm::on_comboBox_dengwengaodu_valueChanged(double value)
{
    qDebug("cwfw_dengwengaodu_value_changed:unit:%d value:%f cvalue:%d",tempunit,value,hptempunitconvert.getCTempValue(tempunit,value*100));
    Isotherm.IsoTempHigh100=hptempunitconvert.getCTempValue(tempunit,value*100);
    //signal_pc_image_set_Isotemp(Isotherm);
    update();
}
