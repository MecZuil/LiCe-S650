#include "hp_wifi_search.h"
#include "ui_hp_wifi_search.h"

Hp_Wifi_Search::Hp_Wifi_Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Wifi_Search)
{
    ui->setupUi(this);


    ui->listWidget_Wifimode->setCurrentRow(0);
    //ui->listWidget_WifiNum->setCurrentRow(0);
    ui->label_Wifimode->setText(ui->listWidget_Wifimode->currentItem()->text());
    //ui->label_WifiNum->setText(ui->listWidget_WifiNum->currentItem()->text());
    ui->label_WifiNum->setText("");
    ui->listWidget_Wifimode->close();
    ui->listWidget_WifiNum->close();

    ui->frame_WifiNum->close();
    ui->label_2->close();
    ui->label_3->close();
    ui->wifi_Flush->close();
    ui->label_PassWord->close();
    ui->label_PassWord->setText("");

    listwidget_type = 0;
    IsOnClicked = false;
    isFlushEuqip = false;
    isSearchFinished = true;
    GetStatus = new QTimer();
    GetStatus->setInterval(1000);
    timezon = 0;
    timeGet = 0;
    isSelectServer = false;
    isDefineS3x0 = false;
    QString para;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    if(para !=NULL)
    {
        if(para.toInt() == 0)
        {
            fOK = "确定";
            fWaitSearch = "等待刷新";
            fConnectOK = "连接成功";
            fHasNoUsedNet = "没有可用的网络";
            fWrongLenPassword = "密码长度错误";
            fConnectIsBreak = "连接已断开";
            fPasswordError = "密码错误";
            fConOutTime = "连接超时";
        }
        else if(para.toInt() == 1)
        {
            fOK = "確定";
            fWaitSearch = "等待刷新";
            fConnectOK = "連接成功";
            fHasNoUsedNet = "沒有可用的網絡";
            fWrongLenPassword = "密碼長度錯誤";
            fConnectIsBreak = "連接已斷開";
            fPasswordError = "密碼錯誤";
            fConOutTime = "連接超時";
        }
        else if(para.toInt() == 2)//english
        {
            fOK = "OK";
            fWaitSearch = "waiting refresh";
            fConnectOK = "Connecting Success";
            fHasNoUsedNet = "No network available";
            fWrongLenPassword = "Password length error";
            fConnectIsBreak = "connection dropped";
            fPasswordError = "Password error";
            fConOutTime = "connection timed out";
        }
        else if(para.toInt() == 3)//俄语
        {
            fOK = "ОК";
            fWaitSearch = "Нет доступных сетей";
            fConnectOK = "Есть Соединение";
            fHasNoUsedNet = "Нет доступных сетей";
            fWrongLenPassword = "ошибка длины пароля";
            fConnectIsBreak = "Соединение разорвано";
            fPasswordError = "ошибка пароля";
            fConOutTime = "время ожидания соединения";
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            fOK = "Igen";
            fWaitSearch = "Nincs elérhető hálózat";
            fConnectOK = "Sikeres kapcsolódás";
            fHasNoUsedNet = "Nincs elérhető hálózat";
            fWrongLenPassword = "A jelszó hossza hiba";
            fConnectIsBreak = "kapcsolat megszakadt";
            fPasswordError = "Jelszóhiba";
            fConOutTime = "lejárt kapcsolat";
        }
        else if(para.toInt() == 5)//西班牙语
        {
            fOK = "OK";
            fWaitSearch = "No hay red disponible";
            fConnectOK = "Conección exitosa";
            fHasNoUsedNet = "No hay red disponible";
            fWrongLenPassword = "Error de longitud de contraseña";
            fConnectIsBreak = "Conexión desconectada";
            fPasswordError = "Error de contraseña";
            fConOutTime = "Tiempo de conexión";
        }
    }


    hp_Wifi_search_Dialog = new Hp_Wifi_search_Dialog(this);
    ui->label_6->close();
    ui->checkBox_localServer->close();
    hp_Wifi_search_Dialog->setGeometry(270,120,300,150);
    hp_Wifi_search_Dialog->close();
    ui->listWidget_equip->close();
    ui->frame_Wifimode->installEventFilter(this);
    ui->frame_WifiNum->installEventFilter(this);
    ui->label_PassWord->installEventFilter(this);
    ui->frame_equipment->installEventFilter(this);
    hp_setUiInit(false);
    connect(GetStatus,SIGNAL(timeout()),this,SLOT(slot_Time_out()));
    connect(&hti,SIGNAL(sync_text()),this,SLOT(slot_sync_text()));
    connect(hp_Wifi_search_Dialog,SIGNAL(signal_set_cancel()),this,SLOT(slot_SetDisConnect()));

    ui->listWidget_WifiNum->verticalScrollBar()->setStyleSheet("QScrollBar{background:#7CA6C9;width:35px;padding-top:0px;padding-bottom:0px;}");
}
Hp_Wifi_Search::~Hp_Wifi_Search()
{
    delete ui;
}
void Hp_Wifi_Search::hp_setDefine_S3x0(bool isSelect)
{
    isDefineS3x0 = isSelect;
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->setGeometry(0,0,480,272);

        ui->frame->setGeometry(0,0,480,106);
        ui->frame_Wifimode->setGeometry(ui->frame_Wifimode->x() / 1.7,ui->frame_Wifimode->y() / 1.7,146,25);
        ui->label_Wifimode->setGeometry(0,0,121,25);
        ui->label_Wifimode_2->setGeometry(121,1,23,23);
        ui->checkBox_wifi->move(ui->checkBox_wifi->x() / 1.7,10);
        ui->label->setGeometry(ui->label->x() / 1.7,ui->label->y() / 1.7,ui->label->width() / 1.7,ui->label->height() / 1.7);
        ui->listWidget_Wifimode->setGeometry(ui->frame_Wifimode->x(),ui->frame_Wifimode->y() + ui->frame_Wifimode->height(),ui->listWidget_Wifimode->width() / 1.7,ui->listWidget_Wifimode->height() / 1.7);
        ui->toolButton_back->setGeometry(0,0,ui->toolButton_back->width() / 1.7,ui->toolButton_back->height() / 1.7);
        ui->frame_2->setGeometry(0,ui->frame->height(),480,this->height() - ui->frame->height());
        ui->frame_WifiNum->setGeometry(ui->frame_WifiNum->x() / 1.7,ui->frame_WifiNum->y() / 1.7,146,25);
        ui->label_WifiNum->setGeometry(0,0,121,25);
        ui->label_WifiNum_2->setGeometry(121,1,23,23);
        ui->label_2->setGeometry(ui->label_2->x() / 1.7,ui->label_2->y() / 1.7,ui->label_2->width() / 1.7,ui->label_2->height() / 1.7);
        ui->label_3->setGeometry(ui->label_3->x() / 1.7,ui->label_3->y() / 1.7,ui->label_3->width() / 1.7,ui->label_3->height() / 1.7);
        ui->label_PassWord->setGeometry(ui->label_PassWord->x() / 1.7,ui->label_PassWord->y() / 1.7,ui->label_PassWord->width() / 1.7,ui->label_PassWord->height() / 1.7);
        ui->listWidget_WifiNum->setGeometry(ui->listWidget_WifiNum->x() / 1.7,ui->frame_WifiNum->y() + ui->frame_WifiNum->height(),ui->listWidget_WifiNum->width() / 1.7,ui->listWidget_WifiNum->height() / 1.7);
        ui->wifi_Flush->setGeometry(ui->wifi_Flush->x() / 1.7,ui->wifi_Flush->y() / 1.7,ui->wifi_Flush->width() / 1.7,ui->wifi_Flush->height() / 1.7);

        hp_Wifi_search_Dialog->move((this->width() - hp_Wifi_search_Dialog->width()) / 2,(this->height() - hp_Wifi_search_Dialog->height()) / 2);

        ui->label_Wifimode->setFont(font10);
        ui->label->setFont(font10);
        ui->listWidget_Wifimode->setFont(font10);
        ui->label_WifiNum->setFont(font10);
        ui->label_2->setFont(font10);
        ui->label_3->setFont(font10);
        ui->label_PassWord->setFont(font10);
        ui->listWidget_WifiNum->setFont(font10);
        ui->wifi_Flush->setFont(font10);

        ui->checkBox_wifi->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");

        ui->listWidget_WifiNum->verticalScrollBar()->setStyleSheet("QScrollBar{background:#7CA6C9;width:20px;padding-top:0px;padding-bottom:0px;}");
        ui->listWidget_WifiNum->horizontalScrollBar()->setStyleSheet("QScrollBar{height:0px;}");
        ui->listWidget_WifiNum->horizontalScrollBar()->hide();
    }

    hti.hp_setDefine_S3x0(isSelect);
    hp_Wifi_search_Dialog->hp_setDefine_S3x0(isSelect);
}


void Hp_Wifi_Search::hp_setUiInit(bool isServer)
{
    isSelectServer = isServer;
    ui->checkBox_equipment->close();
    ui->equip_Flush_2->close();
    ui->frame_equipment->close();
    ui->checkBox_getFlow->close();
    ui->checkBox_equipment->close();
    ui->label_4->close();
    ui->label_5->close();
    ui->label_10->close();
    ui->listWidget_equip->close();
    if(isSelectServer)
    {
        if(isDefineS3x0)
        {

        }
        else
        {

        }
    }
}


void Hp_Wifi_Search::slot_sync_text()
{
    ui->label_PassWord->setText(hti.getText());
}
void Hp_Wifi_Search::slot_Time_out()
{
    signal_CORE_GET_WIFI_STA_STATUS();
    if(timeGet == 1)//若处于等待状态
    {
        timezon++;
    }
}
void Hp_Wifi_Search::on_toolButton_back_clicked()
{
    signal_update_lcdoff_time(false);
    if(listwidget_type == 2)
    {
        ui->listWidget_WifiNum->close();
    }
    if(listwidget_type == 1)
    {
        ui->listWidget_Wifimode->close();
    }
    listwidget_type = 0;
    this->close();//    这里由hide变为close，不知到会有什么影响，应该没有
}
void Hp_Wifi_Search::GoBack()
{
    on_toolButton_back_clicked();
}
void Hp_Wifi_Search::On_set_click_Init()
{
    if(timeGet == 0)//若是准备状态
    {
        //ui->listWidget_WifiNum->clear();
//        signal_PC_SYS_GET_ESSID();
        ui->label_PassWord->setText(fWaitSearch);
//        isSearchFinished = false;
        qDebug() << "ui->listWidget_Wifimode->currentRow() " << ui->listWidget_Wifimode->currentRow();
        qDebug() << "ui->listWidget_WifiNum->currentRow() " << ui->listWidget_WifiNum->currentRow();//若为-1则表示没选择！！！，以后死机要考虑这个
        if(ui->listWidget_Wifimode->count() > 0)
        {
            ui->label_Wifimode->setText(ui->listWidget_Wifimode->currentItem()->text());
        }else{
            ui->label_Wifimode->setText("");
        }
    }
    switch(listwidget_type)
    {
    case 1:
        listwidget_drop_manage_Wifimode(false);
        break;
    case 2:
        listwidget_drop_manage_WifiNum(false);
        break;
    }
}
void Hp_Wifi_Search::slot_SetDisConnect()
{
    qDebug() << "------------------==---------- :   10";
    timeGet = 0;
    timezon = 0;
    if(ui->listWidget_Wifimode->currentRow() == 0)//若选中AP
    {
        signal_pc_sys_set_wifi_switch(0);//发送AP停止信号
    }else if(ui->listWidget_Wifimode->currentRow() == 1)//若为STA
    {
        if(nowConnect.switch_value == 1)//若上一个连接未断开，则断开上一个连接
        {
            nowConnect.switch_value = 0;
            qDebug() << "signal_PC_SYS_SET_WIFI_STA IN --- > slot_SetDisConnect";
            signal_PC_SYS_SET_WIFI_STA(nowConnect);
        }
    }
    if(!ui->checkBox_wifi->isEnabled())
        ui->checkBox_wifi->setDisabled(false);
    if(!ui->wifi_Flush->isEnabled())
        ui->wifi_Flush->setDisabled(false);
    if(ui->checkBox_wifi->isChecked())
    {
        ui->checkBox_wifi->setChecked(false);//不触发事件
    }
    if(GetStatus->isActive())
    {
        GetStatus->stop();
    }
    signal_SetIsWifiSearch(false);
}
//当模式列表改变时执行
void Hp_Wifi_Search::on_listWidget_Wifimode_currentRowChanged(int currentRow)
{
    if( currentRow<0)
    {
        return;
    }
    QString str;
    str = ui->listWidget_Wifimode->currentItem()->text();
    ui->label_Wifimode->setText(str);//设置label内容
    if(ui->listWidget_Wifimode->currentRow() == 1)//若之前为AP
    {
        ui->label_PassWord->show();
        ui->frame_WifiNum->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->wifi_Flush->show();
        signal_pc_sys_set_wifi_switch(0);//发送AP停止信号
        signal_SetIsWifiSearch(false);
    }else if(ui->listWidget_Wifimode->currentRow() == 0){//若之前为STA
        ui->label_PassWord->close();
        ui->frame_WifiNum->close();
        ui->label_2->close();
        ui->label_3->close();
        ui->wifi_Flush->close();
        if(nowConnect.switch_value == 1)//若上一个连接未断开，则断开上一个连接
        {
            nowConnect.switch_value = 0;
            qDebug() << "signal_PC_SYS_SET_WIFI_STA IN --- > on_listWidget_Wifimode_currentRowChanged";
            signal_PC_SYS_SET_WIFI_STA(nowConnect);
        }
        ui->label_PassWord->clear();
        hti.setText("");
        signal_SetIsWifiSearch(false);
    }
    if(ui->checkBox_wifi->isChecked())
    {
        ui->checkBox_wifi->setChecked(false);
    }
    listwidget_drop_manage_Wifimode(false);//关闭下拉框
}

void Hp_Wifi_Search::on_listWidget_WifiNum_currentRowChanged(int currentRow)
{
    if( currentRow<0)
    {
        return;
    }
    QString str;
    if(ui->listWidget_WifiNum->currentRow() >= 0)
    {
        str = ui->listWidget_WifiNum->currentItem()->text();
        ui->label_WifiNum->setText(str);
        ui->label_PassWord->clear();
    }
    listwidget_drop_manage_WifiNum(false);


}
void Hp_Wifi_Search::listwidget_drop_manage_Wifimode(bool type)       //wifi模式下拉框打开关闭处理
{
    if(type == true)
    {
        listwidget_type =1;//wifi模式下拉框
        ui->listWidget_Wifimode->show();
    }else
    {
        listwidget_type =0;
        ui->listWidget_Wifimode->close();
    }

}
void Hp_Wifi_Search::listwidget_drop_manage_WifiNum(bool type)       //wifi选项下拉框打开关闭处理
{
    if(type == true)
    {
//        if(ui->listWidget_WifiNum->count() == 0)
//        {
//            hp_Wifi_search_Dialog->Set_label_text(fHasNoUsedNet);
//            hp_Wifi_search_Dialog->show();
//            return;
//        }
        if(ui->listWidget_WifiNum->count() != 0)
        {
            listwidget_type =2;//wifi选项下拉框
            ui->listWidget_WifiNum->show();
        }
    }else
    {
        listwidget_type =0;
        ui->listWidget_WifiNum->close();
    }
}

void Hp_Wifi_Search::listwidget_drop_manage_equipNum(bool type)
{
    if(type == true)
    {
        if(ui->listWidget_equip->count() != 0)
        {
            listwidget_type = 3;
            ui->listWidget_equip->show();
        }
    }else
    {
        listwidget_type = 0;
        ui->listWidget_equip->close();
    }

}

void Hp_Wifi_Search::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug() << "eventFilter == > Hp_Wifi_Search KeyRelease w->objectName() PP ";
    if(ev->type() == QKeyEvent::KeyRelease)
    {
        QKeyEvent *key_event = (QKeyEvent *)ev;
        if(key_event->key() == KEY_RETURN)//注意：有些时候按键事件被父窗口接收，不知道为什么
        {
            on_toolButton_back_clicked();
        }
    }
}
void Hp_Wifi_Search::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug() << " mouseReleaseEvent " << IsOnClicked << " : " << listwidget_type;
    if(!IsOnClicked)
    {
        switch(listwidget_type)
        {
        case 1:
            listwidget_drop_manage_Wifimode(false);
            break;
        case 2:
            listwidget_drop_manage_WifiNum(false);
            break;
        case 3:
            listwidget_drop_manage_equipNum(false);
            break;
        }
    }
    IsOnClicked = false;
}
bool Hp_Wifi_Search::eventFilter(QObject *w, QEvent *e)//事件过滤，很值得学习，千万注意，这个函数默认返回false！！！
{
    if(QEvent::MouseButtonPress == e->type())               //先判断是鼠标点击事件
    {
        qDebug() << "eventFilter == > Hp_Wifi_Search MouseButtonPress w->objectName() >> " << w->objectName();
        signal_update_lcdoff_time(false);
        switch(listwidget_type)
        {
        case 0:
        {
            if(w->objectName() == "frame_Wifimode")          //判断想要打开的是哪个下拉框
            {
                if(timeGet != 1 && timeGet != 2)//若不处于连接状态 和不处于监视状态
                {
                    IsOnClicked = true;
                    listwidget_drop_manage_Wifimode(true);
                }

            }else if( w->objectName() == "frame_WifiNum" )
            {
                if(timeGet != 1 && timeGet != 2)//若不处于连接状态 和不处于监视状态
                {
                    IsOnClicked = true;
                    listwidget_drop_manage_WifiNum(true);
                }
            }else if( w->objectName() == "label_PassWord" )
            {
                if(timeGet != 1 && timeGet != 2 && isSearchFinished)//若不处于连接状态 和不处于监视状态
                {
                    hti.setText(ui->label_PassWord->text());
                    hti.show();
                }
            }else if(w->objectName() == "frame_equipment")
            {
                listwidget_drop_manage_equipNum(true);
            }
        }
            break;
        case 1:
            listwidget_drop_manage_Wifimode(false);
            break;
        case 2:
            listwidget_drop_manage_WifiNum(false);
            break;
        case 3:
            listwidget_drop_manage_equipNum(false);
            break;
        }
        return false;
    }

    return false;
}
void Hp_Wifi_Search::on_wifi_Flush_clicked()
{
    signal_update_lcdoff_time(false);
    if(listwidget_type == 2 || ui->listWidget_WifiNum->isVisible())
    {
        ui->listWidget_WifiNum->close();
    }
    listwidget_type = 0;//这个变量不靠谱，慎用
    if(!isSearchFinished)
    {
        return;
    }
    ui->label_PassWord->setText(fWaitSearch);
    signal_PC_SYS_GET_ESSID();
    isSearchFinished = false;
}
void Hp_Wifi_Search::slot_PC_SYS_GET_ESSID(unsigned char return_value,QString name)
{
    qDebug("slot_PC_SYS_GET_ESSID return_value:0x%02x",name);
    isSearchFinished = true;
    ui->label_PassWord->setText("");

    if(return_value == RE_OK)
    {

        QString ret = name;
        if(ui->listWidget_WifiNum->count() != 0)
        {
            ui->listWidget_WifiNum->clear();
        }
        if(name.isEmpty() || name == "")
        {
            ui->label_WifiNum->setText(fHasNoUsedNet);
            return;
        }
        qDebug() << "===============";
        qDebug() << name;
        qDebug() << "===============";
        QStringList strs = name.split("\n");
        foreach(QString s,strs)
        {
            if(s[0] == '\"')//因为返回的值，有时候缺少引号
            {
                s = s.remove(0,1);
            }
            if(s[s.length() - 1] == '\"')
            {
                s.chop(1);
            }
            if(s.contains("\\x00\\x00"))
            {
                continue;
            }
            if(s.contains("\\x"))//尝试屏蔽\x
            {
                continue;
            }
            if(s != "")//这里不能多级判断，不知道为啥
            {
                if(ui->listWidget_WifiNum->findItems(s,Qt::MatchExactly).count() == 0)
                {
                    ui->listWidget_WifiNum->addItem(s);
                }
            }
        }
        if(ui->listWidget_WifiNum->count() >= 0)
        {
            ui->listWidget_WifiNum->setCurrentRow(0);
            ui->label_WifiNum->setText(ui->listWidget_WifiNum->currentItem()->text());
        }
        else{
            ui->label_WifiNum->setText(fHasNoUsedNet);
        }
        if(!hti.isVisible())
        {
            ui->label_PassWord->clear();
            hti.setText("");
        }
//        ui->label_PassWord->clear();
//        hti.setText("");
    }
}
void Hp_Wifi_Search::slot_PC_SYS_SET_WIFI_STA(unsigned char return_value)
{
    qDebug("slot_PC_SYS_SET_WIFI_STA return_value:0x%02x",return_value);
    if(return_value == 0x30)
    {
        if(hp_Wifi_search_Dialog->isVisible())
        {
            hp_Wifi_search_Dialog->Set_label_text("连接失败");
            hp_Wifi_search_Dialog->SetControlEnabled(1, true);
        }
    }
}
void Hp_Wifi_Search::slot_CORE_GET_WIFI_STA_STATUS(unsigned char return_value,int wifi_sta_status)
{
    qDebug("slot_CORE_GET_WIFI_STA_STATUS return_value:0x%02x",return_value);
    qDebug() << "slot_CORE_GET_WIFI_STA_STATUS return value : " << wifi_sta_status;
    qDebug() << "timezon : " << timezon << " timeGet : " << timeGet;
    if(return_value == RE_OK)
    {
        if(wifi_sta_status == -1)
        {
            if(timeGet == 1)//若处于弹窗状态(等待连接)
            {
                qDebug() << "------------------==---------- :   6.1 ";
                slot_SetDisConnect();
                if(GetStatus->isActive())
                    GetStatus->stop();//关闭定时器
                timezon = 0;
                timeGet = 0;//不处于等待状态
                hp_Wifi_search_Dialog->Iscancel = false;
                hp_Wifi_search_Dialog->Set_label_text(fPasswordError);
                hp_Wifi_search_Dialog->Set_button_text(fOK);
                if(!hp_Wifi_search_Dialog->isVisible())
                {
                    hp_Wifi_search_Dialog->show();
                }

                if(!ui->checkBox_wifi->isEnabled())
                    ui->checkBox_wifi->setDisabled(false);
                if(!ui->wifi_Flush->isEnabled())
                    ui->wifi_Flush->setDisabled(false);
                if(ui->checkBox_wifi->isChecked())
                    ui->checkBox_wifi->setChecked(false);
                signal_SetIsWifiSearch(false);
            }
        }
        else if(wifi_sta_status == -2 || wifi_sta_status == -3)
        {
            if(timeGet == 1)//若处于弹窗状态(等待连接)
            {
                if(timezon >= 20)//若总计时大于等于20秒
                {
                    qDebug() << "------------------==---------- :   6 ";
                    slot_SetDisConnect();
                    if(GetStatus->isActive())
                        GetStatus->stop();//关闭定时器
                    timezon = 0;
                    timeGet = 0;//不处于等待状态
                    hp_Wifi_search_Dialog->Iscancel = false;
                    hp_Wifi_search_Dialog->Set_label_text(fConOutTime);
                    hp_Wifi_search_Dialog->Set_button_text(fOK);
                    if(!hp_Wifi_search_Dialog->isVisible())
                    {
                        hp_Wifi_search_Dialog->show();
                    }

                    if(!ui->checkBox_wifi->isEnabled())
                        ui->checkBox_wifi->setDisabled(false);
                    if(!ui->wifi_Flush->isEnabled())
                        ui->wifi_Flush->setDisabled(false);
                    if(ui->checkBox_wifi->isChecked())
                        ui->checkBox_wifi->setChecked(false);
                    signal_SetIsWifiSearch(false);
                }
            }else if(timeGet == 3)//若处于监视状态
            {
                qDebug() << "------------------==---------- :   7";
                slot_SetDisConnect();
                ui->checkBox_wifi->setChecked(false);
                if(GetStatus->isActive())
                    GetStatus->stop();//关闭定时器
                timezon = 0;
                timeGet = 0;//不处于等待状态
                hp_Wifi_search_Dialog->Iscancel = false;
                signal_SetMainWifiDisconnect();
                hp_Wifi_search_Dialog->Set_label_text(fConnectIsBreak);
                hp_Wifi_search_Dialog->Set_button_text(fOK);
                if(!hp_Wifi_search_Dialog->isVisible())
                {
                    hp_Wifi_search_Dialog->show();
                }
                if(!ui->checkBox_wifi->isEnabled())
                    ui->checkBox_wifi->setDisabled(false);
                if(!ui->wifi_Flush->isEnabled())
                    ui->wifi_Flush->setDisabled(false);
                if(ui->checkBox_wifi->isChecked())
                    ui->checkBox_wifi->setChecked(false);
                signal_SetIsWifiSearch(false);
//                ui->listWidget_WifiNum->clear();
//                ui->label_WifiNum->setText("");
            }
            return;
        }
        else if(wifi_sta_status == 3)//若IP分配成功，则连接成功
        {
            if(timeGet == 1)//若是处于弹窗状态，即等待状态
            {
                signal_SetIsWifiSearch(true);
                qDebug() << "------------------==---------- :   8";
                timeGet = 2;//设置为监视是否断开状态
                hp_Wifi_search_Dialog->Iscancel = false;
                hp_Wifi_search_Dialog->Set_label_text(fConnectOK);
                hp_Wifi_search_Dialog->Set_button_text(fOK);
                if(!hp_Wifi_search_Dialog->isVisible())
                {
                    hp_Wifi_search_Dialog->show();
                }
                hp_Wifi_search_Dialog->setDelayClose(3000);
                if(!ui->checkBox_wifi->isEnabled())
                    ui->checkBox_wifi->setDisabled(false);
            }
            return;
        }
    }
}

void Hp_Wifi_Search::on_checkBox_wifi_clicked(bool checked)
{
    if(ui->listWidget_Wifimode->isVisible())
    {
        ui->listWidget_Wifimode->close();
    }
    if(ui->listWidget_WifiNum->isVisible())
    {
        ui->listWidget_WifiNum->close();
    }
    listwidget_type = 0;
    signal_update_lcdoff_time(false);
    qDebug() << "------------------==---------- :   1";
    if(checked)
    {
        if(ui->listWidget_Wifimode->currentRow() == 0)//若是AP模式
        {
            signal_pc_sys_set_wifi_switch(1);       //发送打开信号
            if(!isSelectServer)
            {
                on_checkBox_localServer_clicked(true);
            }
        }else if(ui->listWidget_Wifimode->currentRow() == 1)//若是STA模式
        {
            qDebug() << "------------------==---------- :   2";
            if(ui->label_PassWord->text().count() < 8)//若密码长度过短，则返回
            {
                hp_Wifi_search_Dialog->Set_label_text(fWrongLenPassword);
                hp_Wifi_search_Dialog->show();
                ui->checkBox_wifi->setChecked(false);
                return;
            }
            if(ui->listWidget_WifiNum->count() == 0)//若没有可用网络，则返回
            {
                hp_Wifi_search_Dialog->Set_label_text(fHasNoUsedNet);
                hp_Wifi_search_Dialog->show();
                ui->checkBox_wifi->setChecked(false);
                return;
            }
            if(nowConnect.switch_value == 1)//若上一个连接未断开，则断开上一个连接
            {
                nowConnect.switch_value = 0;
                qDebug() << "signal_PC_SYS_SET_WIFI_STA IN --- > on_checkBox_wifi_clicked -- > 1";
                signal_PC_SYS_SET_WIFI_STA(nowConnect);
                qDebug() << "------------------==---------- :   3";
            }
            ap_para ret;//获取新的连接
            strcpy(ret.ssid,ui->label_WifiNum->text().toLocal8Bit().data());
            strcpy(ret.password,ui->label_PassWord->text().toLocal8Bit().data());
            ret.switch_value = 1;

            strcpy(nowConnect.ssid,ui->label_WifiNum->text().toLocal8Bit().data());
            strcpy(nowConnect.password,ui->label_PassWord->text().toLocal8Bit().data());
            nowConnect.switch_value = 1;//赋值新的连接
            qDebug() << "Wifi name == > " << ui->label_WifiNum->text();
            qDebug() << "Password  == > " << ui->label_PassWord->text();
            signal_PC_SYS_SET_WIFI_STA(ret);
            if(!GetStatus->isActive())
                GetStatus->start();//开始计时
            timezon = 0;
            timeGet = 1;//处于等待连接状态
            qDebug() << "------------------==---------- :   4";
            hp_Wifi_search_Dialog->Set_label_wait();

            if(ui->checkBox_wifi->isEnabled())
                ui->checkBox_wifi->setDisabled(true);
            if(ui->wifi_Flush->isEnabled())
                ui->wifi_Flush->setDisabled(true);
        }
    }else{//若关闭
        qDebug() << "------------------==---------- :   9";
        timeGet = 0;
        timezon = 0;
        if(ui->listWidget_Wifimode->currentRow() == 0)//若选中AP
        {
            if(!isSelectServer)
            {
                on_checkBox_localServer_clicked(false);
            }
            signal_pc_sys_set_wifi_switch(0);//发送AP停止信号
        }else if(ui->listWidget_Wifimode->currentRow() == 1)//若为STA
        {
            if(nowConnect.switch_value == 1)//若上一个连接未断开，则断开上一个连接
            {
                nowConnect.switch_value = 0;
                qDebug() << "signal_PC_SYS_SET_WIFI_STA IN --- > on_checkBox_wifi_clicked -- > 3";
                signal_PC_SYS_SET_WIFI_STA(nowConnect);
            }
        }
        if(!ui->checkBox_wifi->isEnabled())
            ui->checkBox_wifi->setDisabled(false);
        if(!ui->wifi_Flush->isEnabled())
            ui->wifi_Flush->setDisabled(false);
        if(GetStatus->isActive())
        {
            GetStatus->stop();
        }
        signal_SetIsWifiSearch(false);
    }
}
void Hp_Wifi_Search::changeEvent(QEvent *e)
{//有时候会导致卡住？？？
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
                fOK = "确定";
                fConnectOK = "连接成功";
                fHasNoUsedNet = "没有可用的网络";
                fWrongLenPassword = "密码长度错误";
                fConnectIsBreak = "连接已断开";
                fPasswordError = "密码错误";
                fConOutTime = "连接超时";
            }
            else if(para.toInt() == 1)
            {
                fOK = "確定";
                fConnectOK = "連接成功";
                fHasNoUsedNet = "沒有可用的網絡";
                fWrongLenPassword = "密碼長度錯誤";
                fConnectIsBreak = "連接已斷開";
                fPasswordError = "密碼錯誤";
                fConOutTime = "連接超時";
            }
            else if(para.toInt() == 2)//english
            {
                fOK = "OK";
                fConnectOK = "Connecting Success";
                fHasNoUsedNet = "No network available";
                fWrongLenPassword = "Password length error";
                fConnectIsBreak = "connection dropped";
                fPasswordError = "Password error";
                fConOutTime = "connection timed out";
            }
            else if(para.toInt() == 3)//俄语
            {
                fOK = "ОК";
                fConnectOK = "Есть Соединение";
                fHasNoUsedNet = "Нет доступных сетей";
                fWrongLenPassword = "ошибка длины пароля";
                fConnectIsBreak = "Соединение разорвано";
                fPasswordError = "ошибка пароля";
                fConOutTime = "время ожидания соединения";
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                fOK = "Igen";
                fConnectOK = "Sikeres kapcsolódás";
                fHasNoUsedNet = "Nincs elérhető hálózat";
                fWrongLenPassword = "A jelszó hossza hiba";
                fConnectIsBreak = "kapcsolat megszakadt";
                fPasswordError = "Jelszóhiba";
                fConOutTime = "lejárt kapcsolat";
            }
            else if(para.toInt() == 5)//西班牙语
            {
                fOK = "OK";
                fConnectOK = "Conección exitosa";
                fHasNoUsedNet = "No hay red disponible";
                fWrongLenPassword = "Error de longitud de contraseña";
                fConnectIsBreak = "Conexión desconectada";
                fPasswordError = "Error de contraseña";
                fConOutTime = "Tiempo de conexión";
            }
        }

        break;
    default:
        break;
    }
}


void Hp_Wifi_Search::on_equip_Flush_2_clicked()
{
    qDebug() << __func__ << "isFlushEuqip" << isFlushEuqip << __LINE__;
    if(isFlushEuqip)
        return;
    isFlushEuqip = true;
    signal_pc_sys_set_dev_active_search();
}

void Hp_Wifi_Search::on_checkBox_equipment_clicked(bool checked)
{
    qDebug() << __func__ << "checked" << checked << __LINE__;
    if(!checked && ui->checkBox_getFlow->isChecked())
    {
        signal_key_dev_client_encode_stop();
        ui->checkBox_getFlow->setChecked(false);
    }
    ComDevClientInfo info;
    info.client_switch = checked;
    qDebug() << ui->label_equipment->text().toLatin1().constData();
    strncpy(info.ip_addr, ui->label_equipment->text().toLocal8Bit().data(), 15);
    signal_pc_sys_set_dev_client(info);
}

void Hp_Wifi_Search::slot_pc_sys_set_dev_client(unsigned char return_value)
{
    qDebug() << __func__ << return_value;
    if(return_value == RE_OK && ui->checkBox_equipment->isChecked())
    {
        ui->checkBox_getFlow->setEnabled(true);
    }
    else
    {
        ui->checkBox_getFlow->setEnabled(false);
    }
}

void Hp_Wifi_Search::slot_pc_sys_set_dev_active_search(unsigned char return_value, QStringList dev_info)
{
    qDebug() << __func__ << return_value << dev_info.count();
    isFlushEuqip = false;
    int devNum = 0;
    if(dev_info.count() > 10)
    {
        devNum = 10;
    }
    devNum = dev_info.count();
    if(devNum == 0)
    {
        ui->label_equipment->setText(tr("无"));
    }
    else
    {
        ui->frame_equipment->setEnabled(true);
        ui->label_equipment->setEnabled(true);
        ui->label_equipment_2->setEnabled(true);
        ui->checkBox_equipment->setEnabled(true);
    }
    for(int i = 0; i < devNum; i++)
    {
        QString name = dev_info.at(i);
        qDebug() << __func__ << name;
        ui->listWidget_equip->addItem(name);
        if(i == 0)
        {
            ui->label_equipment->setText(name);
        }
    }

}

void Hp_Wifi_Search::on_listWidget_equip_currentRowChanged(int currentRow)
{
    qDebug() << __func__ << "currentRow" << currentRow << __LINE__;
    ui->label_equipment->setText(ui->listWidget_equip->item(currentRow)->text());
    listwidget_drop_manage_equipNum(false);
}

void Hp_Wifi_Search::on_checkBox_getFlow_clicked(bool checked)
{
    qDebug() << __func__ << "checked" << checked << __LINE__;
    if(checked)
    {
        signal_key_dev_client_encode_start();
    }
    else
    {
        signal_key_dev_client_encode_stop();
    }
}

void Hp_Wifi_Search::on_checkBox_localServer_clicked(bool checked)
{
    if(checked)
    {
        signal_pc_sys_set_local_servrer(1);
    }
    else
    {
        signal_pc_sys_set_local_servrer(0);
    }
}
