#include  "hpplredit.h"
#include  "ui_hpplredit.h"
#include    <QDebug>
#include     <QScrollBar>

HpPLREdit::HpPLREdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HpPLREdit)
{
    ui->setupUi(this);
    listwidget_type =0;
    language_changing = false;
    plr_onject=ehs_radiance;

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    setGeometry((640-width())/2+160,(480-height())/2,width(),height());////384->640   96->160  272->480
    setFixedSize(this->width(), this->height());
    setStyleSheet("color:black;background:white;");

    ui->hs_rectTemp->close();
    ui->cb_rectTemp->close();

    ui->listWidget_temptype->setGeometry(133,254,385,171);

    QFont font17;
    font17.setPointSize(17);
    ui->hs_distance->hp_setFont(font17);
    ui->hs_radiance->hp_setFont(font17);
    ui->hs_reflect->hp_setFont(font17);
    ui->hs_rectTemp->hp_setFont(font17);
    ui->cb_temptype->close();
    ui->listWidget_temptype->close();
    ui->cb_linedepth->setVisible(false);
    part_radTable_switch = 0;
    part_radTable_id = 0;
    ui->listWidget_radiance->setCurrentRow(0);
    ui->label_radiance_2->setText(ui->listWidget_radiance->currentItem()->text());
    part_radTable_value100 = part_radTable_value[0];

    ui->frame_radiance->setGeometry(133,50,385,45);
    ui->frame_radiance->close();
    ui->listWidget_radiance->setGeometry(133,95,386,30*11+2);
    ui->listWidget_radiance->close();

    ui->frame->installEventFilter(this);
    ui->frame_temptype->installEventFilter(this);
    ui->frame_radiance->installEventFilter(this);
    memset(&abnormalpara,0,sizeof(ComAbnormalExtendPara));
}

HpPLREdit::~HpPLREdit()
{
    delete ui;
}

void HpPLREdit::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->setGeometry((384-384)/2+96,(272-272)/2,384,272);
        ui->frame->setGeometry(0,0,384,272);
        ui->cb_refer->setGeometry(80,90,221,25);
        ui->cb_temptype->setGeometry(20,10,111,25);
        ui->checkBox_radiance->setGeometry(23,30,42,23);
        ui->frame_radiance->setGeometry(78,30,231,25);
        ui->label_radiance_2->setGeometry(0,0,206,25);
        ui->label_radiance_3->setGeometry(207,1,23,23);
        ui->frame_temptype->setGeometry(80,120,231,25);
        ui->label_temptype_2->setGeometry(0,0,206,25);
        ui->label_temptype_3->setGeometry(207,1,23,23);
        ui->hs_distance->setGeometry(78,60,231,25);
        ui->hs_radiance->setGeometry(78,30,231,25);
        ui->hs_reflect->setGeometry(80,150,231,25);
        ui->cb_linedepth->setGeometry(80,185,221,25);
        ui->pb_cancle->setGeometry(80,210,71,25);
        ui->pb_finish->setGeometry(240,210,71,25);
        ui->listWidget_radiance->setGeometry(ui->frame_radiance->x(),ui->frame_radiance->y() + ui->frame_radiance->height(),ui->frame_radiance->width(),131);
        ui->listWidget_temptype->setGeometry(80,145,231,21*5);

        ui->cb_temptype->setFont(font10);
        ui->cb_refer->setFont(font10);
        ui->cb_linedepth->setFont(font10);
        ui->label_radiance_2->setFont(font10);
        ui->label_radiance_3->setFont(font10);
        ui->label_temptype_2->setFont(font10);
        ui->label_temptype_3->setFont(font10);
        ui->hs_distance->hp_setFont(font10);
        ui->hs_radiance->hp_setFont(font10);
        ui->hs_reflect->hp_setFont(font10);
        ui->listWidget_radiance->setFont(font10);
        ui->listWidget_temptype->setFont(font10);
        ui->pb_cancle->setFont(font10);
        ui->pb_finish->setFont(font10);
        ui->cb_rectTemp->setFont(font10);
        ui->hs_rectTemp->setFont(font10);

        ui->checkBox_radiance->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->checkBox_radiance->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->cb_refer->setStyleSheet("QCheckBox{background:transparent;color:#7CA6C9;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
        ui->cb_linedepth->setStyleSheet("QCheckBox{background:transparent;color:#7CA6C9;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");

        ui->hs_radiance->setStyleSheet("QSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                            image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QSpinBox::up-button:pressed{ \
                                            subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                            QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                            height: 24;}");
        ui->hs_distance->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                            image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                            subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                            QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                            height: 24;}");
        ui->hs_reflect->setStyleSheet("QDoubleSpinBox{background-color:transparent;background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QDoubleSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right; \
                                            image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png);width: 24;height: 24;}QDoubleSpinBox::up-button:pressed{ \
                                            subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QDoubleSpinBox::down-button:pressed{subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;} \
                                            QDoubleSpinBox::down-arrow:disabled,QDoubleSpinBox::down-arrow:off {border-image: url(:/res/res/left_arrow_d.png);width: 24;height: 24;}QDoubleSpinBox::up-arrow:disabled,QDoubleSpinBox::up-arrow:off { border-image: url(:/res/res/right_arrow_d.png);width: 24; \
                                            height: 24;}");
    }
}
void HpPLREdit::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    int c_temptype;
    switch (e->type())
    {
    case QEvent::LanguageChange:
        language_changing = true;
        c_temptype = ui->cb_temptype->currentIndex();
        ui->retranslateUi(this);
        if(c_temptype<0)
        {
            c_temptype =0;
        }

        ui->listWidget_temptype->setCurrentRow(c_temptype);
        ui->label_temptype_2->setText(ui->listWidget_temptype->currentItem()->text());
        if(c_temptype == 3)
        {
            ui->cb_refer->setChecked(false);
            ui->cb_refer->setEnabled(false);
            signal_cb_refer_clicked(false);
        }
        language_changing = false;
        break;
    default:
        break;
    }
}

void HpPLREdit::on_cb_temptype_currentIndexChanged(int index)
{
    if(language_changing)
        return;
    signal_temptype_changed(index);
}
void HpPLREdit::setTaskstyleSheet(bool IsTask)
{
}
/**************************************下拉框****************************************************/
bool HpPLREdit::eventFilter(QObject *w, QEvent *e)
{
    if(QEvent::MouseButtonPress == e->type())               //先判断是鼠标点击事件
    {
        switch(listwidget_type)
        {

        case 0:                                                                      //表示还没有下拉框点开
        {
            if(w->objectName() == "frame_temptype")          //判断想要打开的是哪个下拉框
            {
                listwidget_drop_manage_temptype(true);
            }else if(w->objectName() =="frame_radiance")
            {
                listwidget_drop_manage_radiance( true);
            }else{};
            break;
        }
        case 1:                                                                     //表示第一个下拉框已经点开，进行处理
            if(w->objectName() =="frame_temptype")
            {
                listwidget_drop_manage_temptype(false);
            }
            break;
        case 2:                                                                     //表示第一个下拉框已经点开，进行处理
            if(w->objectName() =="frame_radiance")
            {
                listwidget_drop_manage_radiance(false);
            }
            break;
        default:
            break;
        }
    }
    if(e->type() == QKeyEvent::KeyRelease)
    {
        QKeyEvent *key_event = (QKeyEvent *)e;

        if(key_event->key() == KEY_RETURN)
        {
            if(listwidget_type != 0)
            {
                listwidget_type_manage();
                listwidget_type = 0;
            }
            SignalRefreshDisplayMaxRect();
            this->close();
        }
        if(key_event->key() == KEY_CAMERA_PICTURE)
        {
            qDebug() << "20220513 -- > " << key_event->key();
            return false;
        }
    }
return true;
}

void HpPLREdit::on_listWidget_temptype_currentRowChanged(int currentRow)
{
    if(currentRow < 0)
    {
        return;
    }
    if(language_changing)
        return;
    signal_temptype_changed(currentRow);

    ui->label_temptype_2->setText(ui->listWidget_temptype->currentItem()->text());
    listwidget_drop_manage_temptype(false);
    if(currentRow == 3)
    {
        ui->cb_refer->setChecked(false);
        ui->cb_refer->setEnabled(false);
        signal_cb_refer_clicked(false);
    }else{
        ui->cb_refer->setEnabled(true);
    }

}

void HpPLREdit::on_listWidget_radiance_currentRowChanged(int currentRow)
{
    if(currentRow < 0)
    {
        return;
    }
    if(language_changing)
        return;

    part_radTable_id = currentRow;
    part_radTable_value100 = part_radTable_value[currentRow];

    signal_part_radTable_change(part_radTable_id,part_radTable_value100);
    ui->label_radiance_2->setText(ui->listWidget_radiance->currentItem()->text());
    listwidget_drop_manage_radiance(false);
}

void HpPLREdit::listwidget_drop_manage_temptype(bool type)
{
    if(type == true)                    //打开下拉框
    {
         listwidget_type =1;
         ui->listWidget_temptype->show();
         ui->listWidget_temptype->raise();

         ui->hs_radiance->setEnabled(false);
         ui->hs_distance->setEnabled(false);
         ui->cb_refer->setEnabled(false);
         ui->hs_reflect->setEnabled(false);

    }else
    {
         listwidget_type =0;
         ui->listWidget_temptype->close();

         ui->hs_radiance->setEnabled(true);
         ui->hs_distance->setEnabled(true);
         ui->cb_refer->setEnabled(true);
         ui->hs_reflect->setEnabled(true);
    }
}

void HpPLREdit::listwidget_drop_manage_radiance(bool type)
{
    if(type == true)                    //打开下拉框
    {
         listwidget_type =2;
         ui->listWidget_radiance->show();
         ui->listWidget_radiance->raise();

         ui->hs_radiance->setEnabled(false);
         ui->hs_distance->setEnabled(false);
         ui->cb_refer->setEnabled(false);
         ui->hs_reflect->setEnabled(false);

    }else
    {
         listwidget_type =0;
         ui->listWidget_radiance->close();

         ui->hs_radiance->setEnabled(true);
         ui->hs_distance->setEnabled(true);
         ui->cb_refer->setEnabled(true);
         ui->hs_reflect->setEnabled(true);
    }

}

void HpPLREdit::listwidget_type_manage()
{
    switch(listwidget_type)
    {
    case 1:                                                                     //表示第一个下拉框已经点开，进行处理
        listwidget_drop_manage_temptype(false);
        break;
    case 2:
        listwidget_drop_manage_radiance(false);
        break;
    default:
        break;
        }
}

void HpPLREdit::on_checkBox_radiance_clicked(bool checked)
{
    listwidget_type_manage( );

    if(checked)
    {
        ui->frame_radiance->show();
        ui->hs_radiance->hide();
        part_radTable_switch =1;
        signal_part_radTable_mode(part_radTable_switch);

        if( ui->listWidget_radiance->currentRow() == 0)
        {
                 part_radTable_id = ui->listWidget_radiance->currentRow();
                 if( part_radTable_id <0)
                      part_radTable_id = 0;
                 part_radTable_value100 = part_radTable_value[part_radTable_id];
                 signal_part_radTable_change(part_radTable_id,part_radTable_value100);
        }
    }else{
        ui->hs_radiance->show();
        ui->frame_radiance->hide();
        part_radTable_switch =0;
        signal_part_radTable_mode(part_radTable_switch);
    }
}

void HpPLREdit::set_checkBox_radiance_state(bool checked)
{
    ui->checkBox_radiance->setChecked(checked);
    if(checked)
    {
        ui->frame_radiance->show();
        ui->hs_radiance->hide();
        part_radTable_switch =1;
        signal_part_radTable_mode(part_radTable_switch);
    }else{
        ui->hs_radiance->show();
        ui->frame_radiance->hide();
        part_radTable_switch =0;
        signal_part_radTable_mode(part_radTable_switch);
    }
}


void HpPLREdit::on_pb_cancle_clicked()
{
     listwidget_type_manage( );
}

void HpPLREdit::on_pb_finish_clicked()
{
     listwidget_type_manage( );
}

void HpPLREdit::AssemblyStyleSet(PLR_OBJECTNAME objectSel,bool state)
{
    signal_update_lcdoff_time(false);
    switch(objectSel)
    {
        break;
    }
}
