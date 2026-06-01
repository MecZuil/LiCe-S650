#include  "hp_mode_rdj_adjust.h"
#include  "ui_hp_mode_rdj_adjust.h"
#include   "QDebug"

Hp_Mode_Rdj_Adjust::Hp_Mode_Rdj_Adjust(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Mode_Rdj_Adjust)
{
    ui->setupUi(this);
    ui->comboBox_rdj_type->close();

    ui->listWidget_rdj_type->close();
    listwidget_type =0;

    ui->listWidget_rdj_type->setGeometry(179,45,171,95);

    ui->frame_rdj_type->installEventFilter(this);
    ui->frame->installEventFilter(this);
    ui->frame_rdj->installEventFilter(this);
    ui->frame_all->installEventFilter(this);

}

Hp_Mode_Rdj_Adjust::~Hp_Mode_Rdj_Adjust()
{
    delete ui;
}
void Hp_Mode_Rdj_Adjust::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);
        QFont font10;
        font9.setPointSize(10);

        this->resize(480,272);
        ui->frame->setGeometry(0,0,96,272);
        ui->frame_back->setGeometry(-1,-1,100,275);
        ui->toolButton_default->setGeometry(2,50,92,40);
        ui->toolButton_finish->setGeometry(0,0,96,40);
        ui->frame_all->setGeometry(0,0,480,272);
        ui->frame_rdj->setGeometry(170,70,212,131);
        ui->comboBox_rdj_type->setGeometry(117,1,95,25);
        ui->doubleSpinBox_above->setGeometry(1,79,210,25);
        ui->doubleSpinBox_below->setGeometry(1,105,210,25);
        ui->doubleSpinBox_high->setGeometry(1,27,210,25);
        ui->doubleSpinBox_low->setGeometry(1,53,210,25);
        ui->frame_rdj_back->setGeometry(-1,-1,214,133);
        ui->frame_rdj_type->setGeometry(117,1,95,25);
        ui->label_rdj_type_2->setGeometry(0,0,70,25);
        ui->label_rdj_type_3->setGeometry(70,1,23,23);
        ui->label_rdj_type->setGeometry(1,1,115,25);
        ui->listWidget_rdj_type->setGeometry(117,26,95,20*3);

        ui->toolButton_default->setFont(font9);
        ui->comboBox_rdj_type->setFont(font9);
        ui->doubleSpinBox_above->hp_setFont(font10);
        ui->doubleSpinBox_below->hp_setFont(font10);
        ui->doubleSpinBox_high->hp_setFont(font10);
        ui->doubleSpinBox_low->hp_setFont(font10);
        ui->label_rdj_type_2->setFont(font10);
        ui->label_rdj_type->setFont(font10);
        ui->frame_rdj_type->setFont(font9);
        ui->listWidget_rdj_type->setFont(font10);

        ui->doubleSpinBox_above->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                               image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                               subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                               QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                               height: 24;}");
        ui->doubleSpinBox_below->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                               image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                               subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                               QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                               height: 24;}");
        ui->doubleSpinBox_high->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                               image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                               subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                               QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                               height: 24;}");
        ui->doubleSpinBox_low->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                               image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                               subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                               QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                               height: 24;}");

    }else{
        QFont font17;
        font17.setPointSize(17);
        ui->doubleSpinBox_above->hp_setFont(font17);
        ui->doubleSpinBox_below->hp_setFont(font17);
        ui->doubleSpinBox_high->hp_setFont(font17);
        ui->doubleSpinBox_low->hp_setFont(font17);
    }
}
void Hp_Mode_Rdj_Adjust::changeEvent(QEvent *e)
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


void Hp_Mode_Rdj_Adjust::setTempUnit(int unit)
{
    tempunit = unit;
}

void Hp_Mode_Rdj_Adjust::setTempRang(int min, int max)
{
    rang_min = min;
    rang_max = max;
}

void Hp_Mode_Rdj_Adjust::setFusion(FusionPara fp)
{
    fusionpara = fp;
    bak_fusionpara = fp;


    mode_rdj_signal_slot_init(false);

    //ui->spinBox_type->setValue(fusionpara.nFusionType);
    //ui->comboBox_rdj_type->setCurrentIndex(fusionpara.nFusionType);
    ui->listWidget_rdj_type->setCurrentRow(fusionpara.nFusionType);
   
      switch(fusionpara.nFusionType)
    {
    case 0:
        ui->doubleSpinBox_high->setEnabled(true);
        ui->doubleSpinBox_low->setEnabled(true);
        ui->doubleSpinBox_above->setEnabled(false);
        ui->doubleSpinBox_below->setEnabled(false);
        break;
    case 1:
        ui->doubleSpinBox_high->setEnabled(false);
        ui->doubleSpinBox_low->setEnabled(false);
        ui->doubleSpinBox_above->setEnabled(true);
        ui->doubleSpinBox_below->setEnabled(false);
        break;
    case 2:
        ui->doubleSpinBox_high->setEnabled(false);
        ui->doubleSpinBox_low->setEnabled(false);
        ui->doubleSpinBox_above->setEnabled(false);
        ui->doubleSpinBox_below->setEnabled(true);
        break;
    }

    ui->doubleSpinBox_high->setMinimum(rang_min);
    ui->doubleSpinBox_high->setMaximum(rang_max);
    ui->doubleSpinBox_high->setSuffix(htuc.getTempUnitString(tempunit));
    ui->doubleSpinBox_high->setValue(htuc.getTempValue(tempunit,fusionpara.nFusionAmongHighTemp100)/100.0);

    ui->doubleSpinBox_low->setMinimum(rang_min);
    ui->doubleSpinBox_low->setMaximum(rang_max);
    ui->doubleSpinBox_low->setSuffix(htuc.getTempUnitString(tempunit));
    ui->doubleSpinBox_low->setValue(htuc.getTempValue(tempunit,fusionpara.nFusionAmongLowTemp100)/100.0);

    ui->doubleSpinBox_above->setMinimum(rang_min);
    ui->doubleSpinBox_above->setMaximum(rang_max);
    ui->doubleSpinBox_above->setSuffix(htuc.getTempUnitString(tempunit));
    ui->doubleSpinBox_above->setValue(htuc.getTempValue(tempunit,fusionpara.nFusionAboveTemp100)/100.0);

    ui->doubleSpinBox_below->setMinimum(rang_min);
    ui->doubleSpinBox_below->setMaximum(rang_max);
    ui->doubleSpinBox_below->setSuffix(htuc.getTempUnitString(tempunit));
    ui->doubleSpinBox_below->setValue(htuc.getTempValue(tempunit,fusionpara.nFusionBelowTemp100)/100.0);

    mode_rdj_signal_slot_init(true);
}

FusionPara Hp_Mode_Rdj_Adjust::getFusion()
{
    return fusionpara;
}
/*
void Hp_Mode_Rdj_Adjust::on_spinBox_type_valueChanged(int arg1)
{
    qDebug("nFusionType:%d",arg1);
    fusionpara.nFusionType = arg1;
    switch(arg1)
    {
    case 0:
        ui->doubleSpinBox_high->setEnabled(true);
        ui->doubleSpinBox_low->setEnabled(true);
        ui->doubleSpinBox_above->setEnabled(false);
        ui->doubleSpinBox_below->setEnabled(false);
        break;
    case 1:
        ui->doubleSpinBox_high->setEnabled(false);
        ui->doubleSpinBox_low->setEnabled(false);
        ui->doubleSpinBox_above->setEnabled(true);
        ui->doubleSpinBox_below->setEnabled(false);
        break;
    case 2:
        ui->doubleSpinBox_high->setEnabled(false);
        ui->doubleSpinBox_low->setEnabled(false);
        ui->doubleSpinBox_above->setEnabled(false);
        ui->doubleSpinBox_below->setEnabled(true);
        break;
    }
}*/

void Hp_Mode_Rdj_Adjust::on_doubleSpinBox_high_valueChanged(double arg1)
{
    signal_update_lcdoff_time(false);
    fusionpara.nFusionAmongHighTemp100 = htuc.getCTempValue(tempunit,arg1*100);
}

void Hp_Mode_Rdj_Adjust::on_doubleSpinBox_low_valueChanged(double arg1)
{
    signal_update_lcdoff_time(false);
    fusionpara.nFusionAmongLowTemp100 = htuc.getCTempValue(tempunit,arg1*100);
}

void Hp_Mode_Rdj_Adjust::on_doubleSpinBox_above_valueChanged(double arg1)
{
    signal_update_lcdoff_time(false);
    fusionpara.nFusionAboveTemp100 = htuc.getCTempValue(tempunit,arg1*100);
}

void Hp_Mode_Rdj_Adjust::on_doubleSpinBox_below_valueChanged(double arg1)
{
    signal_update_lcdoff_time(false);
    fusionpara.nFusionBelowTemp100 = htuc.getCTempValue(tempunit,arg1*100);
}

void Hp_Mode_Rdj_Adjust::on_toolButton_default_released()
{
    signal_update_lcdoff_time(false);
    if( listwidget_type == 1)
    {
        listwidget_drop_manage_rdj_type(false);
    }

    setFusion(bak_fusionpara);
}

void Hp_Mode_Rdj_Adjust::on_toolButton_finish_released()
{
    signal_update_lcdoff_time(false);
    if( listwidget_type == 1)
    {
        listwidget_drop_manage_rdj_type(false);
    }
    sync_fusion_para();
    close();
}

void Hp_Mode_Rdj_Adjust::rdj_current_current_index_changed(int value)
{
    signal_update_lcdoff_time(false);
    qDebug("nFusionType:%d",value);
    fusionpara.nFusionType = value;
    switch(value)
    {
    case 0:
        ui->doubleSpinBox_high->setEnabled(true);
        ui->doubleSpinBox_low->setEnabled(true);
        ui->doubleSpinBox_above->setEnabled(false);
        ui->doubleSpinBox_below->setEnabled(false);
        break;
    case 1:
        ui->doubleSpinBox_high->setEnabled(false);
        ui->doubleSpinBox_low->setEnabled(false);
        ui->doubleSpinBox_above->setEnabled(true);
        ui->doubleSpinBox_below->setEnabled(false);
        break;
    case 2:
        ui->doubleSpinBox_high->setEnabled(false);
        ui->doubleSpinBox_low->setEnabled(false);
        ui->doubleSpinBox_above->setEnabled(false);
        ui->doubleSpinBox_below->setEnabled(true);
        break;
    }
}

void Hp_Mode_Rdj_Adjust::mode_rdj_signal_slot_init(bool flag)
{
    if(flag)
    {
        //connect(ui->spinBox_type,SIGNAL(valueChanged(int)),this,SLOT(on_spinBox_type_valueChanged(int)));
        //connect(ui->comboBox_rdj_type,SIGNAL(currentIndexChanged(int)),this,SLOT(rdj_current_current_index_changed(int)));

        //connect(ui->listWidget_rdj_type,SIGNAL(currentRowChanged(int)),this,SLOT(rdj_current_current_index_changed(int)));
        connect(ui->doubleSpinBox_high,SIGNAL(valueChanged(double)),this,SLOT(on_doubleSpinBox_high_valueChanged(double)));
        connect(ui->doubleSpinBox_low,SIGNAL(valueChanged(double)),this,SLOT(on_doubleSpinBox_low_valueChanged(double)));
        connect(ui->doubleSpinBox_above,SIGNAL(valueChanged(double)),this,SLOT(on_doubleSpinBox_above_valueChanged(double)));
        connect(ui->doubleSpinBox_below,SIGNAL(valueChanged(double)),this,SLOT(on_doubleSpinBox_below_valueChanged(double)));
    }
    else
    {
       // disconnect(ui->spinBox_type,SIGNAL(valueChanged(int)),this,SLOT(on_spinBox_type_valueChanged(int)));
        //disconnect(ui->comboBox_rdj_type,SIGNAL(currentIndexChanged(int)),this,SLOT(rdj_current_current_index_changed(int)));

        //disconnect(ui->listWidget_rdj_type,SIGNAL(currentRowChanged(int)),this,SLOT(rdj_current_current_index_changed(int)));
        disconnect(ui->doubleSpinBox_high,SIGNAL(valueChanged(double)),this,SLOT(on_doubleSpinBox_high_valueChanged(double)));
        disconnect(ui->doubleSpinBox_low,SIGNAL(valueChanged(double)),this,SLOT(on_doubleSpinBox_low_valueChanged(double)));
        disconnect(ui->doubleSpinBox_above,SIGNAL(valueChanged(double)),this,SLOT(on_doubleSpinBox_above_valueChanged(double)));
        disconnect(ui->doubleSpinBox_below,SIGNAL(valueChanged(double)),this,SLOT(on_doubleSpinBox_below_valueChanged(double)));
    }
}

void Hp_Mode_Rdj_Adjust::listwidget_drop_manage_rdj_type(bool type)
{
    if(type == true)                    //即将打开下拉框
    {
         listwidget_type =1;
//         ui->listWidget_rdj_type->setGeometry(179,45,171,95);
         ui->listWidget_rdj_type->show();

         ui->doubleSpinBox_high->setEnabled(false);
         ui->doubleSpinBox_low->setEnabled(false);
         ui->doubleSpinBox_above->setEnabled(false);
         ui->doubleSpinBox_below->setEnabled(false);

    }else
    {
         listwidget_type =0;
         ui->listWidget_rdj_type->close();

         int value = ui->listWidget_rdj_type->currentRow(); //获取当前下拉框的值，设置其它框的状态
         if(value >= 0)
         {
            rdj_current_current_index_changed( value);
         }
    }
}

bool Hp_Mode_Rdj_Adjust::eventFilter(QObject *w, QEvent *e)
{
    if(QEvent::MouseButtonPress == e->type())               //先判断是鼠标点击事件
    {
        switch(listwidget_type)
        {

        case 0:                                                                      //表示还没有下拉框点开
        {
            if(w->objectName() == "frame_rdj_type")          //判断想要打开的是哪个下拉框
            {
                listwidget_drop_manage_rdj_type(true);
            };
            break;
        }
        case 1:                                                                     //表示第一个下拉框已经点开，进行处理
            listwidget_drop_manage_rdj_type(false);
            break;
        default:
            break;
        }
    }
    if(e->type() == QKeyEvent::KeyRelease)
    {
        QKeyEvent *key_event = (QKeyEvent *)e;
        if(key_event->key()  == KEY_RETURN)
        {
            on_toolButton_finish_released();
            return true;
        }
    }
return true;

}

void Hp_Mode_Rdj_Adjust::keyReleaseEvent(QKeyEvent *ev)
{
    signal_update_lcdoff_time(true);
    qDebug()<<"Hp_Mode_Rdj_Adjust::keyReleaseEvent(QKeyEvent *ev)............................................."<<ev->key();
    switch( ev->key() )
    {
    case KEY_RETURN:
        on_toolButton_finish_released();
        break;
    default:
        break;
    }
}

void Hp_Mode_Rdj_Adjust::on_listWidget_rdj_type_currentRowChanged(int currentRow)
{
    signal_update_lcdoff_time(false);
    if(currentRow < 0)
    {
        return;
    }
    ui->label_rdj_type_2->setText(ui->listWidget_rdj_type->currentItem()->text());
    listwidget_drop_manage_rdj_type(false);

}
