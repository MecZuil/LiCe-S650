#include "hp_hotkey.h"
#include "ui_hp_hotkey.h"

Hp_hotkey::Hp_hotkey(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_hotkey)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    ui->frame_keyCamera->installEventFilter(this);
    ui->frame_keyFocus->installEventFilter(this);
    ui->listWidget_keyFocus->close();
    ui->listWidget_keyCamera->close();

    ui->label_keyCamera->show();
    ui->frame_keyCamera->show();
}

Hp_hotkey::~Hp_hotkey()
{
    delete ui;
}

void Hp_hotkey::changeEvent(QEvent *e)
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

void Hp_hotkey::setFocusType(int keyType)
{
    qDebug() << __func__ << "--------------------------------------------------------" << keyType;
    if(keyType > 6 || keyType < 1)
    {
        if(keyType == 10)
        {
            ui->label_keyFocus->close();
            ui->frame_keyFocus->close();
            return;
        }
        ui->listWidget_keyFocus->setCurrentRow(0);
        on_listWidget_keyFocus_currentRowChanged(0);
        return;
    }
    ui->listWidget_keyFocus->setCurrentRow(keyType - 1);
    on_listWidget_keyFocus_currentRowChanged(keyType - 1);
}


void Hp_hotkey::setCameraType(int keyType)
{
    qDebug() << __func__ << "--------------------------------------------------------" << keyType;
    if(keyType > 6 || keyType < 1)
    {
        if(keyType == 10)
        {
            ui->label_keyCamera->close();
            ui->frame_keyCamera->close();
        }
        ui->listWidget_keyCamera->setCurrentRow(0);
        on_listWidget_keyCamera_currentRowChanged(0);
        return;
    }
    if(keyType != 0)
    {
        ui->listWidget_keyCamera->setCurrentRow(keyType - 1);
        on_listWidget_keyCamera_currentRowChanged(keyType - 1);
    }
    else
    {
        ui->listWidget_keyCamera->setCurrentRow(0);
        on_listWidget_keyCamera_currentRowChanged(0);
    }
}

void Hp_hotkey::showText()
{
    qDebug() << "Hp_hotkey camera" << ui->label_keyCamera_2->text();
    qDebug() << __func__ << "camera--------------------------------------------------------" << ui->listWidget_keyCamera->currentRow();
    qDebug() << "Hp_hotkey focus  " << ui->label_keyFocus_2->text();
    qDebug() << __func__ << "focus--------------------------------------------------------" << ui->listWidget_keyFocus->currentRow();
}

void Hp_hotkey::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->resize(480,272);
        ui->frame->setGeometry(0,0,480,272);
        ui->toolButton_back->setGeometry(0, 0, 60, 40);
        ui->label_keyFocus->setGeometry(60,40,111,25);
        ui->frame_keyFocus->setGeometry(200,40,125,25);
        ui->label_keyFocus_2->setGeometry(0,0,100,25);
        ui->label_keyFocus_3->setGeometry(100,0,25,25);
        ui->listWidget_keyFocus->setGeometry(ui->frame_keyFocus->x(), ui->frame_keyFocus->y() + 25, 125, 125);
        ui->label_keyCamera->setGeometry(60,100,111,25);
        ui->frame_keyCamera->setGeometry(200,100,125,25);
        ui->label_keyCamera_2->setGeometry(0,0,100,25);
        ui->label_keyCamera_3->setGeometry(100,0,25,25);
        ui->listWidget_keyCamera->setGeometry(ui->frame_keyCamera->x(), ui->frame_keyCamera->y() + 25, 125, 125);

        ui->label_keyCamera->setFont(font10);
        ui->label_keyCamera_2->setFont(font10);
        ui->label_keyCamera_3->setFont(font10);
        ui->label_keyFocus->setFont(font10);
        ui->label_keyFocus_2->setFont(font10);
        ui->label_keyFocus_3->setFont(font10);
        ui->listWidget_keyFocus->setFont(font10);
        ui->listWidget_keyCamera->setFont(font10);
    }
}

void Hp_hotkey::on_listWidget_keyCamera_currentRowChanged(int currentRow)
{
    qDebug() << __func__ << currentRow << __LINE__;
    if(currentRow != 0)
    {
        signal_hotkey_set_key_camera((KEYSETTING)(currentRow + 1));
    }
    else if(currentRow == 0)
    {
        signal_hotkey_set_key_camera((KEYSETTING)(currentRow));
    }
    ui->label_keyCamera_2->setText(ui->listWidget_keyCamera->currentItem()->text());
    qDebug() << __func__ << ui->listWidget_keyCamera->currentItem()->text() << __LINE__;
    qDebug() << __func__ << ui->label_keyCamera_2->text() << __LINE__;
    ui->listWidget_keyCamera->close();
}

void Hp_hotkey::on_listWidget_keyFocus_currentRowChanged(int currentRow)
{
    qDebug() << __func__ << currentRow << __LINE__;
    ui->label_keyFocus_2->setText(ui->listWidget_keyFocus->currentItem()->text());
    signal_hotkey_set_key_focus((KEYSETTING)(currentRow + 1));
    ui->listWidget_keyFocus->close();
}

void Hp_hotkey::on_toolButton_back_clicked()
{
    ui->listWidget_keyCamera->close();
    ui->listWidget_keyFocus->close();
    this->close();
}

bool Hp_hotkey::eventFilter(QObject *watched, QEvent *event)
{
    if(QEvent::MouseButtonPress == event->type())               //先判断是鼠标点击事件
    {
        QMouseEvent *mouse_event = (QMouseEvent *)event;
        QPoint pressPoint;
        pressPoint = mouse_event->pos();

        if(watched->objectName() == "frame_keyFocus" || watched->objectName() == "label_keyFocus_2" || watched->objectName() == "label_keyFocus_3")
        {
            ui->listWidget_keyFocus->show();
            ui->listWidget_keyFocus->raise();
            ui->listWidget_keyCamera->close();
        }
        else if(watched->objectName() == "frame_keyCamera" || watched->objectName() == "label_keyCamera_2" || watched->objectName() == "label_keyCamera_3")
        {
            ui->listWidget_keyFocus->close();
            ui->listWidget_keyCamera->show();
            ui->listWidget_keyCamera->raise();
        }
    }
    else if( event->type() == QKeyEvent::KeyRelease)               //按键松开事件
    {
        QKeyEvent *key_event = (QKeyEvent *)event;
        keyReleaseEvent(key_event);
    }else{};

    return true;
}


void Hp_hotkey::mousePressEvent(QMouseEvent* event)
{
    ui->listWidget_keyCamera->close();
    ui->listWidget_keyFocus->close();
}

void Hp_hotkey::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
   case KEY_RETURN:
         on_toolButton_back_clicked();
        break;
    }
}
