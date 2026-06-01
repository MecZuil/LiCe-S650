#include  "hp_adjust_cmd.h"
#include  "ui_hp_adjust_cmd.h"

Hp_Adjust_Cmd::Hp_Adjust_Cmd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Adjust_Cmd)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    setGeometry(160,0,width(),height());
    setFixedSize(this->width(), this->height());
//    if(FOCUS_MODE == 1)     //自动调焦
//    {
//        focus_mode = 0;
//    }else{
//        focus_mode = 1;
//    }
    focus_mode = 0;
    QString para;
    para = xml.readXml("sys.xml","FOCUSMODE","content");
    if(para != NULL)
    {
        focus_mode = para.toInt();
    }

    //当前镜头号
    QString lenid;
    lenid = xml.readXml("config.xml","LENSSET","lensid");
    if(lenid != NULL)
        lens_id= lenid.toInt();
    else
        lens_id = 0;

    init_flag = false;
    adjust_cmd_open = false;
    set_spinbox_value();

    bnTimer = new QTimer(this);
    connect(bnTimer,SIGNAL(timeout()),this,SLOT(slot_bn_timer()));
    ui->label_b->close();
    ui->label_s->close();
}
void Hp_Adjust_Cmd::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->setGeometry(96,0,384,272);
        ui->label->setGeometry(200,250,61,20);
        ui->label_2->setGeometry(110,250,60,20);
        ui->label_b->setGeometry(180,250,20,20);
        ui->label_s->setGeometry(90,250,20,20);
        ui->spinBox_N1->setGeometry(10,20,121,20);
        ui->spinBox_N2->setGeometry(10,50,121,20);
        ui->spinBox_N3->setGeometry(10,200,121,20);
        ui->spinBox_N4->setGeometry(10,230,121,20);
        ui->spinBox_X1->setGeometry(150,20,100,20);
        ui->spinBox_X2->setGeometry(150,50,100,20);
        ui->spinBox_X3->setGeometry(150,200,100,20);
        ui->spinBox_X4->setGeometry(150,230,100,20);
        ui->spinBox_Y1->setGeometry(260,20,100,20);
        ui->spinBox_Y2->setGeometry(260,50,100,20);
        ui->spinBox_Y3->setGeometry(260,200,100,20);
        ui->spinBox_Y4->setGeometry(260,230,100,20);

        ui->label->setFont(font10);
        ui->label_2->setFont(font10);
        ui->label_b->setFont(font10);
        ui->label_s->setFont(font10);
        ui->spinBox_N1->setFont(font10);
        ui->spinBox_N2->setFont(font10);
        ui->spinBox_N3->setFont(font10);
        ui->spinBox_N4->setFont(font10);
        ui->spinBox_X1->setFont(font10);
        ui->spinBox_X2->setFont(font10);
        ui->spinBox_X3->setFont(font10);
        ui->spinBox_X4->setFont(font10);
        ui->spinBox_Y1->setFont(font10);
        ui->spinBox_Y2->setFont(font10);
        ui->spinBox_Y3->setFont(font10);
        ui->spinBox_Y4->setFont(font10);

        ui->spinBox_N1->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
            subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
            width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
            subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
            width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
ui->spinBox_N2->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
    subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
    width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
    subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
    width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
ui->spinBox_N3->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
    subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
    width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
    subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
    width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
ui->spinBox_N4->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
    subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
    width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
    subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
    width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
ui->spinBox_X1->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
    subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
    width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
    subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
    width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
ui->spinBox_X2->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
    subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
    width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
    subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
    width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
ui->spinBox_X3->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
    subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
    width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
    subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
    width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
ui->spinBox_X4->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
    subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
    width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
    subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
    width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
ui->spinBox_Y1->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
    subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
    width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
    subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
    width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
ui->spinBox_Y2->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
    subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
    width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
    subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
    width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
ui->spinBox_Y3->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
    subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
    width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
    subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
    width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
ui->spinBox_Y4->setStyleSheet("QSpinBox{background-color: rgb(0, 8, 16);background-image:url(:/res/res/spinbox_text_bg.png);color:#7CA6C9;border:0px;}QSpinBox::up-button {subcontrol-origin:border; \
    subcontrol-position:right;image: url(:/res/res/right_arrow_n.png);width: 24;height: 24;}QSpinBox::down-button {subcontrol-origin:border;subcontrol-position:left;border-image: url(:/res/res/left_arrow_n.png); \
    width: 24;height: 24;}QSpinBox::up-button:pressed{subcontrol-origin:border;subcontrol-position:right;image: url(:/res/res/right_arrow_s.png);width: 24;height: 24;}QSpinBox::down-button:pressed{ \
    subcontrol-position:left;image: url(:/res/res/left_arrow_s.png);width: 24;height: 24;}QSpinBox::down-arrow:disabled,QSpinBox::down-arrow:off{border-image: url(:/res/res/left_arrow_d.png); \
    width: 24;height: 24;}QSpinBox::up-arrow:disabled,QSpinBox::up-arrow:off{border-image: url(:/res/res/right_arrow_d.png);width: 24;height: 24;}");
    }
}
Hp_Adjust_Cmd::~Hp_Adjust_Cmd()
{
    delete ui;
}
int Hp_Adjust_Cmd::get_focus_mode()
{
    qDebug() << __func__ << "focusmode" << focus_mode;
    return focus_mode;
}
void Hp_Adjust_Cmd::on_spinBox_N1_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_N1_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_N1;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::on_spinBox_N2_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_N2_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_N2;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::on_spinBox_N3_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_N3_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_N3;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::on_spinBox_N4_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_N4_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_N4;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::on_spinBox_X1_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_X1_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_X1;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::on_spinBox_X2_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_X2_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_X2;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::on_spinBox_X3_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_X3_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_X3;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::on_spinBox_X4_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_X4_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_X4;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::on_spinBox_Y1_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_Y1_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_Y1;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::on_spinBox_Y2_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_Y2_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_Y2;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::on_spinBox_Y3_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_Y3_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_Y3;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::on_spinBox_Y4_valueChanged(int arg1)
{
    if(init_flag)
        return;
    qDebug("on_spinBox_Y4_valueChanged:%d",arg1);
    FusionAdjust fa;
    fa.cmd = ADJUST_Y4;
    fa.value = arg1;
    signal_FusionAdjust(fa);
}

void Hp_Adjust_Cmd::slot_FusionAdjust(unsigned char return_value)
{
    qDebug("slot_FusionAdjust return_value:%x",return_value);
}

void Hp_Adjust_Cmd::slot_bn_timer()
{
    signal_pc_sys_get_bn();
    signal_pc_sys_get_focus();
    ui->label_b->show();
    ui->label_s->show();
}

void Hp_Adjust_Cmd::slot_pc_sys_get_bn(unsigned char return_value, int bn)
{
    if(return_value == RE_OK)
    {
        if(adjust_cmd_open == true)
        {
            bnTimer->start(2000);
            ui->label->setText(QString::number(bn));
        }else{
            bnTimer->stop();
        }
    }
    else
    {
        ui->label->setText("ERROR");
    }
}

void Hp_Adjust_Cmd::slot_pc_sys_get_focus(unsigned char return_value, int bn)
{
    if(return_value == RE_OK)
    {

        ui->label_2->setText(QString::number(bn));
    }
    else
    {
        ui->label_2->setText("ERROR");
    }
}

void Hp_Adjust_Cmd::set_focus_styles(bool AF_focus)     //聚焦模式。 0--->自动调焦，1--->手动调焦
{

    if(AF_focus == true)
    {
        focus_mode = 0;
    }else
    {
        focus_mode =1;
    }
    set_spinbox_value();
}

void Hp_Adjust_Cmd::slot_pc_measure_set_temprange_ok(unsigned char return_value)  //镜头id  0--->3
{
    QString lenid;
    lenid = xml.readXml("config.xml","LENSSET","lensid");
    if(lenid != NULL)
        lens_id= lenid.toInt();
    else
        lens_id = 0;

    set_spinbox_value();
}

void Hp_Adjust_Cmd::startBnTimer()
{
    bnTimer->start(3000);
}

void Hp_Adjust_Cmd::stopBnTimer()
{
    bnTimer->stop();
    adjust_cmd_open = false;
}

void Hp_Adjust_Cmd::set_spinbox_value()
{
//    int lens_id;                //镜头id  0--->3
//    int focus_mode;         //聚焦模式。 0--->自动调焦，1--->手动调焦
    init_flag = true;

     int adjust_id;
    adjust_id = 4*focus_mode+lens_id;
    QString adjust_name;
    switch(adjust_id)
    {
    case 0:
        adjust_name = "AFLEN1";
        break;
    case 1:
        adjust_name = "AFLEN2";
        break;
    case 2:
        adjust_name = "AFLEN3";
        break;
    case 3:
        adjust_name = "AFLEN4";
        break;
    case 4:
        adjust_name = "MFLEN1";
        break;
    case 5:
        adjust_name = "MFLEN2";
        break;
    case 6:
        adjust_name = "MFLEN3";
        break;
    case 7:
        adjust_name = "MFLEN4";
        break;
    default:
        adjust_name = "MFLEN1";
        break;
    }
    change_spinbox_value(adjust_name);
}

void Hp_Adjust_Cmd::change_spinbox_value(QString adjust_name)
{
    QString s;
    //N1
    s = xml.readXml("adjust.xml",adjust_name,"Para1");
    ui->spinBox_N1->setValue(s.toInt());
    FusionAdjust fa_n1;
    fa_n1.cmd = ADJUST_N1;
    fa_n1.value = s.toInt();
    signal_FusionAdjust(fa_n1);

    //x1
    s = xml.readXml("adjust.xml",adjust_name,"Para2");
    ui->spinBox_X1->setValue(s.toInt());
    FusionAdjust fa_x1;
    fa_x1.cmd = ADJUST_X1;
    fa_x1.value = s.toInt();
    signal_FusionAdjust(fa_x1);
    //y1
    s = xml.readXml("adjust.xml",adjust_name,"Para3");
    ui->spinBox_Y1->setValue(s.toInt());
    FusionAdjust fa_y1;
    fa_y1.cmd = ADJUST_Y1;
    fa_y1.value = s.toInt();
    signal_FusionAdjust(fa_y1);

    //N2
    s = xml.readXml("adjust.xml",adjust_name,"Para4");
    ui->spinBox_N2->setValue(s.toInt());
    FusionAdjust fa_n2;
    fa_n2.cmd = ADJUST_N2;
    fa_n2.value = s.toInt();
    signal_FusionAdjust(fa_n2);
    //x2
    s = xml.readXml("adjust.xml",adjust_name,"Para5");
    ui->spinBox_X2->setValue(s.toInt());
    FusionAdjust fa_x2;
    fa_x2.cmd = ADJUST_X2;
    fa_x2.value = s.toInt();
    signal_FusionAdjust(fa_x2);
    //y2
    s = xml.readXml("adjust.xml",adjust_name,"Para6");
    ui->spinBox_Y2->setValue(s.toInt());
    FusionAdjust fa_y2;
    fa_y2.cmd = ADJUST_Y2;
    fa_y2.value = s.toInt();
    signal_FusionAdjust(fa_y2);

    //N3
    s = xml.readXml("adjust.xml",adjust_name,"Para7");
    ui->spinBox_N3->setValue(s.toInt());
    FusionAdjust fa_n3;
    fa_n3.cmd = ADJUST_N3;
    fa_n3.value = s.toInt();
    signal_FusionAdjust(fa_n3);

    //x3
    s = xml.readXml("adjust.xml",adjust_name,"Para8");
    ui->spinBox_X3->setValue(s.toInt());
    FusionAdjust fa_x3;
    fa_x3.cmd = ADJUST_X3;
    fa_x3.value = s.toInt();
    signal_FusionAdjust(fa_x3);

    //y3
    s = xml.readXml("adjust.xml",adjust_name,"Para9");
    ui->spinBox_Y3->setValue(s.toInt());
    FusionAdjust fa_y3;
    fa_y3.cmd = ADJUST_Y3;
    fa_y3.value = s.toInt();
    signal_FusionAdjust(fa_y3);

    //N4
    s = xml.readXml("adjust.xml",adjust_name,"Para10");
    ui->spinBox_N4->setValue(s.toInt());
    FusionAdjust fa_n4;
    fa_n4.cmd = ADJUST_N4;
    fa_n4.value = s.toInt();
    signal_FusionAdjust(fa_n4);

    //x4
    s = xml.readXml("adjust.xml",adjust_name,"Para11");
    ui->spinBox_X4->setValue(s.toInt());
    FusionAdjust fa_x4;
    fa_x4.cmd = ADJUST_X4;
    fa_x4.value = s.toInt();
    signal_FusionAdjust(fa_x4);

    //y4
    s = xml.readXml("adjust.xml",adjust_name,"Para12");
    ui->spinBox_Y4->setValue(s.toInt());
    FusionAdjust fa_y4;
    fa_y4.cmd = ADJUST_Y4;
    fa_y4.value = s.toInt();
    signal_FusionAdjust(fa_y4);

    init_flag = false;
}



