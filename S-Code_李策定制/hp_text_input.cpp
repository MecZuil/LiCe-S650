#include  "hp_text_input.h"
#include  "ui_hp_text_input.h"

Hp_Text_Input::Hp_Text_Input(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Text_Input)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    isPreview = false;
    connect(this,SIGNAL(signal_frminput_init()),ui->widget,SLOT(slot_frminput_init()));
    connect(ui->widget,SIGNAL(signalTask()),this,SLOT(slot_Task()));
    connect(ui->listWidget->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(slot_list_widget_vertical_value_change(int)));
}
void Hp_Text_Input::hp_setDefine_S3x0(bool isSelect)
{
    ui->widget->hp_setDefine_S3x0(isSelect);
    if(isSelect)
    {
        QFont font11;
        font11.setPointSize(11);
        QFont font15;
        font15.setPointSize(15);

        this->resize(480,272);
        ui->frame->setGeometry(0,0,96,272);
        ui->toolButton_back->setGeometry(10,10,71,31);
        ui->frame_2->setGeometry(96,0,384,272);
        ui->label->setGeometry(0,5,384,20);
        ui->lineEdit->setGeometry(2,25,380,32);
        ui->widget->setGeometry(0,60,384,210);
        ui->listWidget->setGeometry(0, 60, 380, 210);
        ui->toolButton_back->setFont(font11);
        ui->label->setFont(font11);
        ui->lineEdit->setFont(font15);
        ui->listWidget->setFont(font11);
        ui->listWidget->setMoveSpeed(25);
        ui->listWidget->setStyleSheet(LISTWIDGETSTYLESHEET1);
    }
}
Hp_Text_Input::~Hp_Text_Input()
{
    delete ui;
}
void Hp_Text_Input::slot_Task()
{
//    qDebug() << "--<Task Btn>-- 2 ";
    signalTask();
    //on_toolButton_back_released();
}
void Hp_Text_Input::setpage()
{
    ui->widget->setpage();
}
void Hp_Text_Input::setpage2(QString name)
{
    ui->widget->setpage2(name);
}
void Hp_Text_Input::setbtnTaskVisble(bool visble)
{
    ui->widget->setbtnTaskVisble(visble);
}

void Hp_Text_Input::setShowPrefix(bool isShow)
{
    if(!isShow)
        ui->listWidget->close();
}

void Hp_Text_Input::changeEvent(QEvent *e)
{
    QString para;
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        if(para !=NULL)
        {
            if(para.toInt() == 0)
            {
                ui->label->setText("输入：");
                ui->toolButton_back->setText("确定");
            }
            else if(para.toInt() == 1)
            {
                ui->label->setText("輸入：");
                ui->toolButton_back->setText("確定");
            }
            else if(para.toInt() == 2)//english
            {
                ui->label->setText("INPUT:");
                ui->toolButton_back->setText("OK");
            }
            else if(para.toInt() == 3)//俄语
            {
                ui->label->setText("вход:");
                ui->toolButton_back->setText("ОК");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                ui->label->setText("bemenet:");
                ui->toolButton_back->setText("Igen");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                ui->label->setText("Entrada:");
                ui->toolButton_back->setText("OK");
            }
        }
        break;
    default:
        break;
    }
}

void Hp_Text_Input::keyReleaseEvent(QKeyEvent *ev)
{
    signal_update_lcdoff_time(true);
    signal_frminput_set_lcd_offed_state();
    qDebug()<<"Hp_Text_Input::keyReleaseEvent(QKeyEvent *ev)............................."<<ev->key();
    switch( ev->key() )
    {
    case KEY_RETURN:
        //on_toolButton_back_released();
        ui->lineEdit->setText(Currenttext);
        signal_frminput_init();
        //ui->lineEdit->setText(" ");
        ui->widget->setVisible(false);
        //signal_Set_wifi_text(text);
        this->close();
        break;
    default:
        break;
    }
}

void Hp_Text_Input::setText(QString str)
{
    ui->lineEdit->setText(str);
    Currenttext = str;
    text = str;
}

QString Hp_Text_Input::getText()
{
    Currenttext = text;
    return text;
}

void Hp_Text_Input::on_lineEdit_textChanged(const QString &arg1)
{
    signal_update_lcdoff_time(false);
    text = arg1;
    mainText = arg1;
}

void Hp_Text_Input::on_toolButton_back_released()
{
    signal_update_lcdoff_time(false);
    signal_frminput_init();
    ui->widget->setVisible(false);
    sync_text();
    //signal_Set_wifi_text(text);

    if(!isPreview)
    {
        this->close();
    }
}

void Hp_Text_Input::on_listWidget_currentRowChanged(int currentRow)
{
    QString frontText = ui->listWidget->currentItem()->text().split(": ").at(1);
//    qDebug() << frontText;

//    for(int i = 0; i < ui->listWidget->count(); i++)
//    {
//        QString frontText2 = ui->listWidget->item(i)->text().split(": ").at(1);
//        frontText2 = frontText2.toLocal8Bit().data();
//        qDebug() << "frontText2" <<frontText2;
//        qDebug() << "text" <<text;
//        qDebug() << "text.indexOf(frontText2)" << text.indexOf(frontText2);
//        if(text.indexOf(frontText2) >= 0)
//        {
//            text.remove(frontText2);

//        }
//    }
    text = frontText;
    ui->lineEdit->setText(text);
    prefixText = frontText;
}

void Hp_Text_Input::on_lineEdit_selectionChanged()
{
    qDebug() << "Hp_Text_Input::on_lineEdit_selectionChanged";
}

void Hp_Text_Input::slot_list_widget_vertical_value_change(int value)
{
    qDebug() << __func__ << value << ui->listWidget->verticalScrollBar()->value();
}
