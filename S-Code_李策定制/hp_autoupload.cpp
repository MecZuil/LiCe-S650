#include "hp_autoupload.h"
#include "ui_hp_autoupload.h"

hp_AutoUpLoad::hp_AutoUpLoad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hp_AutoUpLoad)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);//这两句决定了事件会不会被父类接收
    NowEdit = 1;

    mymode = enum_AUP_SERVER;
    changeMode(1);

    ServeIP = "";
    ServePort = "";
    is4Gopen = false;

    isClientOpen = false;

    hp_Wifi_search_Dialog = new Hp_Wifi_search_Dialog(this);
    hp_Wifi_search_Dialog->setGeometry((this->width() - hp_Wifi_search_Dialog->width()) / 2,(this->height() - hp_Wifi_search_Dialog->height()) / 2,300,150);
    hp_Wifi_search_Dialog->close();

    hp_Common_dialog_cancel = new hp_common_dialog_cancel(this);
    hp_Common_dialog_cancel->move((this->width() - hp_Common_dialog_cancel->width()) / 2,(this->height() - hp_Common_dialog_cancel->height()) / 2);
    hp_Common_dialog_cancel->close();

    ui->label_IP->installEventFilter(this);
    ui->label_Account->installEventFilter(this);
    ui->label_Password->installEventFilter(this);
    ui->label_server_act->installEventFilter(this);
    ui->label_server_paswd->installEventFilter(this);

    QString para;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    if(para !=NULL)
    {
        if(para.toInt() == 0)
        {
            fusername = "用户名";
            fconnectOk = "连接成功";
            fconnectfalse = "连接失败";
            f4GOpen = "4G未打开";
            fport = "端口";
            fIsInConnnect="连接中";
            fcancel = "取消";
        }
        else if(para.toInt() == 1)
        {
            fusername = "用戶名";
            fconnectOk = "連接成功";
            fconnectfalse = "連接失敗";
            f4GOpen = "4G未打開";
            fport = "埠";
            fIsInConnnect="連接中";
            fcancel = "取消";
        }
        else if(para.toInt() == 2)//english
        {
            fusername = "user name";
            fconnectOk = "Connecting Success";
            fconnectfalse = "connection failed";
            f4GOpen = "4G not open";
            fport = "port";
            fIsInConnnect="Connecting";
            fcancel = "Cancel";
        }
        else if(para.toInt() == 3)//俄语
        {
            fusername = "Имя пользователя";
            fconnectOk = "Есть Соединение";
            fconnectfalse = "Ошибка подключения";
            f4GOpen = "4G не открывается";
            fport = "Порт";
            fIsInConnnect="Соединение идет";
            fcancel = "Отм";
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            fusername = "felhasználónév";
            fconnectOk = "Sikeres kapcsolódás";
            fconnectfalse = "kapcsolat sikertelen";
            f4GOpen = "4G nem nyitva";
            fport = "kikötő";
            fIsInConnnect="Kapcsolódás";
            fcancel = "Mégse";
        }
        else if(para.toInt() == 5)//西班牙语
        {
            fusername = "Nombre de usuario";
            fconnectOk = "Buscando";
            fconnectfalse = "Conexión fallida";
            f4GOpen = "4G no abierto";
            fport = "Puerto";
            fIsInConnnect="Conectando";
            fcancel = "Cancel";
        }
    }

    if(mymode == enum_AUP_ftp)
    {
        ui->label_3->setText(fusername);
    }else{
        ui->label_3->setText(fport);
    }


    connect(&hti,SIGNAL(sync_text()),this,SLOT(slot_sync_text()));
    connect(hp_Wifi_search_Dialog,SIGNAL(signal_IsEmpty()),this,SLOT(slot_IsEmpty()));
    connect(hp_Common_dialog_cancel,SIGNAL(hp_signal_on_cancel_clicked()),this,SLOT(slot_common_dialog_cancel()));
}
hp_AutoUpLoad::~hp_AutoUpLoad()
{
    delete ui;
}
void hp_AutoUpLoad::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->resize(480,272);
        ui->frame->setGeometry(0,0,480,272);
        ui->toolButton_back->setGeometry(0,0,ui->toolButton_back->width() / 1.7,ui->toolButton_back->height() / 1.7);
        ui->label_2->setGeometry(ui->label_2->x() / 1.7,ui->label_2->y() / 1.7,ui->label_2->width() / 1.7,ui->label_2->height() / 1.7);
        ui->label_3->setGeometry(ui->label_3->x() / 1.7,ui->label_3->y() / 1.7,ui->label_3->width() / 1.7,ui->label_3->height() / 1.7);
        ui->label_4->setGeometry(ui->label_4->x() / 1.7,ui->label_4->y() / 1.7,ui->label_4->width() / 1.7,ui->label_4->height() / 1.7);
        ui->label_6->setGeometry(ui->label_6->x() / 1.7,ui->label_6->y() / 1.7,ui->label_6->width() / 1.7,ui->label_6->height() / 1.7);
        ui->label_7->setGeometry(ui->label_7->x() / 1.7,ui->label_7->y() / 1.7,ui->label_7->width() / 1.7,ui->label_7->height() / 1.7);
        ui->label_Account->setGeometry(ui->label_Account->x() / 1.7,ui->label_Account->y() / 1.7,ui->label_Account->width() / 1.7,ui->label_Account->height() / 1.7);
        ui->label_IP->setGeometry(ui->label_IP->x() / 1.7,ui->label_IP->y() / 1.7,ui->label_IP->width() / 1.7,ui->label_IP->height() / 1.7);
        ui->label_Password->setGeometry(ui->label_Password->x() / 1.7,ui->label_Password->y() / 1.7,ui->label_Password->width() / 1.7,ui->label_Password->height() / 1.7);
        ui->label_server_act->setGeometry(ui->label_server_act->x() / 1.7,ui->label_server_act->y() / 1.7,ui->label_server_act->width() / 1.7,ui->label_server_act->height() / 1.7);
        ui->label_server_paswd->setGeometry(ui->label_server_paswd->x() / 1.7,ui->label_server_paswd->y() / 1.7,ui->label_server_paswd->width() / 1.7,ui->label_server_paswd->height() / 1.7);

        ui->checkBox_srvopen->setGeometry(ui->checkBox_srvopen->x() / 1.7,ui->checkBox_srvopen->y() / 1.7,ui->checkBox_srvopen->width() / 1.7,ui->checkBox_srvopen->height() / 1.7);
        ui->label_5->setGeometry(ui->label_5->x() / 1.7,ui->label_5->y() / 1.7,ui->label_5->width() / 1.7,ui->label_5->height() / 1.7);

        ui->label_2->setFont(font10);
        ui->label_3->setFont(font10);
        ui->label_4->setFont(font10);
        ui->label_5->setFont(font10);
        ui->label_6->setFont(font10);
        ui->label_7->setFont(font10);
        ui->label_Account->setFont(font10);
        ui->label_IP->setFont(font10);
        ui->label_Password->setFont(font10);
        ui->label_server_act->setFont(font10);
        ui->label_server_paswd->setFont(font10);

        ui->checkBox_srvopen->setStyleSheet("QCheckBox{background:transparent;}QCheckBox::indicator:unchecked {image: url(:/res/res/switch_off_sx0.png);}QCheckBox::indicator:checked {image: url(:/res/res/switch_on_sx0.png);}");
    }
    hp_Wifi_search_Dialog->hp_setDefine_S3x0(isSelect);
    hti.hp_setDefine_S3x0(isSelect);
    hp_Common_dialog_cancel->hp_setDefine_S3x0(isSelect);


    hp_Wifi_search_Dialog->move((this->width() - hp_Wifi_search_Dialog->width()) / 2,(this->height() - hp_Wifi_search_Dialog->height()) / 2);
    hp_Common_dialog_cancel->move((this->width() - hp_Common_dialog_cancel->width()) / 2,(this->height() - hp_Common_dialog_cancel->height()) / 2);
}
void hp_AutoUpLoad::changeMode(int newmode)
{
    if(newmode == 0)
    {
        ui->label_3->setText(fusername);
        ui->label_4->show();
        ui->label_Password->show();
        ui->label_5->close();
        ui->checkBox_srvopen->close();
        ui->label_2->move(80,110);
        ui->label_IP->move(390,100);
        ui->label_3->move(80,230);
        ui->label_Account->move(390,220);
        ui->label_4->move(80,350);
        ui->label_Password->move(390,340);
        ui->label_6->close();
        ui->label_7->close();
        ui->label_server_act->close();
        ui->label_server_paswd->close();
//        signal_mode_change(0);
        mymode = enum_AUP_ftp;
    }else if(newmode == 1)
    {
        ui->label_3->setText(fport);
        ui->label_4->close();
        ui->label_Password->close();
        ui->label_5->show();
        ui->checkBox_srvopen->show();
        ui->label_2->move(80,110);
        ui->label_IP->move(350,100);
        ui->label_3->move(80,230);
        ui->label_Account->move(350,220);
        ui->label_4->move(80,350);
        ui->label_Password->move(350,340);
        ui->label_5->move(80,350);
        ui->checkBox_srvopen->move(350,340);
        ui->label_6->close();
        ui->label_7->close();
        ui->label_server_act->close();
        ui->label_server_paswd->close();
//        signal_mode_change(1);
        mymode = enum_AUP_SERVER;
    }else if(newmode == 2)
    {
        ui->label_6->show();
        ui->label_server_act->show();
        ui->label_7->show();
        ui->label_server_paswd->show();
        ui->label_3->setText(fport);
        ui->label_4->close();
        ui->label_Password->close();
        ui->label_5->show();
        ui->checkBox_srvopen->show();
        ui->label_2->move(80,210);
        ui->label_IP->move(390,200);
        ui->label_3->move(80,270);
        ui->label_Account->move(390,260);
        ui->label_4->move(80,330);
        ui->label_Password->move(390,320);
        ui->label_5->move(80,330);
        ui->checkBox_srvopen->move(390,320);
//        signal_mode_change(1);
        mymode = enum_AUP_SERVER_PLUS;
    }

}
void hp_AutoUpLoad::SetSettingInit(QString IP_Account_password,int num)
{
    if(num == 1)
    {
        ui->label_IP->setText(IP_Account_password);
    }else if(num == 2)
    {
        ui->label_Account->setText(IP_Account_password);
    }else if(num == 3)
    {
        ui->label_Password->setText(IP_Account_password);
    }
    if((!ui->label_IP->text().isEmpty()) && (!ui->label_Account->text().isEmpty()) && (!ui->label_Password->text().isEmpty()))
    {
        signal_set_IP_Account_Password(ui->label_IP->text(),ui->label_Account->text(),ui->label_Password->text(),0);//设置账号密码
    }
}
void hp_AutoUpLoad::slot_sync_text()
{
    if(NowEdit == 1)
    {
        ui->label_IP->setText(hti.getText());
    }else if(NowEdit == 2)
    {
        ui->label_Account->setText(hti.getText());
    }else if(NowEdit == 3)
    {
        ui->label_Password->setText(hti.getText());
    }else if(NowEdit == 4)
    {
        ui->label_server_act->setText(hti.getText());
    }else if(NowEdit == 5)
    {
        ui->label_server_paswd->setText(hti.getText());
    }
}
void hp_AutoUpLoad::on_toolButton_back_clicked()
{
    signal_update_lcdoff_time(false);
    if(mymode == enum_AUP_ftp)
    {
        if(ui->label_IP->text().isEmpty() || ui->label_Account->text().isEmpty() || ui->label_Password->text().isEmpty())
        {
            QString para;
            para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
            qDebug("read language index:%d",para.toInt());
            if( para.toInt() == 1 )
            {
                hp_Wifi_search_Dialog->Set_label_text("有條目輸入為空");
            }
            else if(para.toInt() == 2)
            {
                hp_Wifi_search_Dialog->Set_label_text("Entry is null");
            }
            else if(para.toInt() == 3)
            {
                hp_Wifi_search_Dialog->Set_label_text("ввод пустой");
            }
            else if(para.toInt() == 4)
            {
                hp_Wifi_search_Dialog->Set_label_text("A bejegyzés nulla");
            }
            else if(para.toInt() == 5)
            {
                hp_Wifi_search_Dialog->Set_label_text("Entrada vacía");
            }else
            {
                hp_Wifi_search_Dialog->Set_label_text("有条目输入为空");
            }
            hp_Wifi_search_Dialog->show();
            hp_Wifi_search_Dialog->IsEmpty = true;
            //signal_Set_Unchecked();//关闭checkedBox
        }else
        {
            ftp_para para;
            //文件名是否不用上传？？？
            strcpy(para.HostIP,ui->label_IP->text().toLocal8Bit().data());
            strcpy(para.UserName,ui->label_Account->text().toLocal8Bit().data());
            strcpy(para.Password,ui->label_Password->text().toLocal8Bit().data());
            signal_pc_sys_set_upload_target(para);//掉电保存
            signal_set_IP_Account_Password(ui->label_IP->text(),ui->label_Account->text(),ui->label_Password->text(),0);//设置账号密码
            this->close();
        }
    }else if(mymode == enum_AUP_SERVER || enum_AUP_SERVER_PLUS)
    {
        this->close();
    }
}
void hp_AutoUpLoad::GoBack()
{
    on_toolButton_back_clicked();
}
void hp_AutoUpLoad::slot_close()
{
    on_toolButton_back_clicked();
}
void hp_AutoUpLoad::slot_IsEmpty()
{
    signal_Set_Unchecked();
    this->close();
}
void hp_AutoUpLoad::slot_pc_sys_set_upload_target(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_upload_target:%02x",return_value);
}
bool hp_AutoUpLoad::eventFilter(QObject *w, QEvent *e)//事件过滤，很值得学习，千万注意，这个函数默认返回false！！！
{
    if(QEvent::MouseButtonPress == e->type())               //先判断是鼠标点击事件
    {
        signal_update_lcdoff_time(false);
        if(mymode == enum_AUP_ftp)
        {
            hti.setpage2("enum_AUP_ftp");
        }else if(mymode == enum_AUP_SERVER)
        {
            hti.setpage2("enum_AUP_SERVER");
        }else if(mymode == enum_AUP_SERVER_PLUS)
        {
            if(w->objectName() == "label_server_act" || w->objectName() == "label_server_paswd")
            {
                hti.setpage2("enum_AUP_ftp");//字母键盘
            }else if(w->objectName() == "label_IP" || w->objectName() == "label_Account")
            {
                hti.setpage2("enum_AUP_SERVER");//数字键盘
            }
        }

        if(isClientOpen)//若4G打开则无法输入
        {
            return true;
        }
        if(w->objectName() == "label_IP")
        {
            hti.setText(ui->label_IP->text());
            NowEdit = 1;
        }else if( w->objectName() == "label_Account" )
        {
            hti.setText(ui->label_Account->text());
            NowEdit = 2;
        }else if( w->objectName() == "label_Password" )
        {
            hti.setText(ui->label_Password->text());
            NowEdit = 3;
        }else if( w->objectName() == "label_server_act" )
        {
            hti.setText(ui->label_server_act->text());
            NowEdit = 4;
        }else if( w->objectName() == "label_server_paswd" )
        {
            hti.setText(ui->label_server_paswd->text());
            NowEdit = 5;
        }
        if(ui->checkBox_srvopen->isChecked())
        {
            return false;//若已连接
        }
        hti.show();
        return false;
    }
    return false;
}
void hp_AutoUpLoad::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->type() == QKeyEvent::KeyRelease)
    {
        QKeyEvent *key_event = (QKeyEvent *)ev;
        signal_update_lcdoff_time(true);
        if(key_event->key() == KEY_RETURN)//注意：有些时候按键事件被父窗口接收，不知道为什么
        {
            on_toolButton_back_clicked();
        }
    }
}
void hp_AutoUpLoad::changeEvent(QEvent *e)
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
                fusername = "用户名";
                fconnectOk = "连接成功";
                fconnectfalse = "连接失败";
                f4GOpen = "4G未打开";
                fport = "端口";
                fIsInConnnect="连接中";
                fcancel = "取消";
            }
            else if(para.toInt() == 1)
            {
                fusername = "用戶名";
                fconnectOk = "連接成功";
                fconnectfalse = "連接失敗";
                f4GOpen = "4G未打開";
                fport = "埠";
                fIsInConnnect="連接中";
                fcancel = "取消";
            }
            else if(para.toInt() == 2)//english
            {
                fusername = "user name";
                fconnectOk = "Connecting Success";
                fconnectfalse = "connection failed";
                f4GOpen = "4G not open";
                fport = "port";
                fIsInConnnect="Connecting";
                fcancel = "Cancel";
            }
            else if(para.toInt() == 3)//俄语
            {
                fusername = "Имя пользователя";
                fconnectOk = "Есть Соединение";
                fconnectfalse = "Ошибка подключения";
                f4GOpen = "4G не открывается";
                fport = "Порт";
                fIsInConnnect="Соединение идет";
                fcancel = "Отм";
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                fusername = "felhasználónév";
                fconnectOk = "Sikeres kapcsolódás";
                fconnectfalse = "kapcsolat sikertelen";
                f4GOpen = "4G nem nyitva";
                fport = "kikötő";
                fIsInConnnect="Kapcsolódás";
                fcancel = "Mégse";
            }
            else if(para.toInt() == 5)//西班牙语
            {
                fusername = "Nombre de usuario";
                fconnectOk = "Buscando";
                fconnectfalse = "Conexión fallida";
                f4GOpen = "4G no abierto";
                fport = "Puerto";
                fIsInConnnect="Conectando";
                fcancel = "Cancel";
            }
        }

        if(mymode == enum_AUP_ftp)
        {
            ui->label_3->setText(fusername);
        }else{
            ui->label_3->setText(fport);
        }
        break;
    default:
        break;
    }
}
void hp_AutoUpLoad::on_checkBox_srvopen_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
    if(checked)
    {
        if(mymode == enum_AUP_SERVER)
        {
            if(!is4Gopen)
            {
                hp_Wifi_search_Dialog->Set_label_text("f4GOpen");
                ui->checkBox_srvopen->setChecked(false);
                return;
            }
            if(ui->label_IP->text().isEmpty() || ui->label_Account->text().isEmpty())
            {
                QString para;
                para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
                qDebug("read language index:%d",para.toInt());
                if( para.toInt() == 1 )
                {
                    hp_Wifi_search_Dialog->Set_label_text("有條目輸入為空");
                }
                else if(para.toInt() == 2)
                {
                    hp_Wifi_search_Dialog->Set_label_text("Entry is null");
                }
                else if(para.toInt() == 3)
                {
                    hp_Wifi_search_Dialog->Set_label_text("ввод пустой");
                }
                else if(para.toInt() == 4)
                {
                    hp_Wifi_search_Dialog->Set_label_text("A bejegyzés nulla");
                }
                else if(para.toInt() == 5)
                {
                    hp_Wifi_search_Dialog->Set_label_text("Entrada vacía");
                }else
                {
                    hp_Wifi_search_Dialog->Set_label_text("有条目输入为空");
                }
                hp_Wifi_search_Dialog->show();
                hp_Wifi_search_Dialog->IsEmpty = true;
                ui->checkBox_srvopen->setChecked(false);
                //signal_Set_Unchecked();//关闭checkedBox
            }else
            {
                hp_Common_dialog_cancel->Set_label_text(fIsInConnnect);
                hp_Common_dialog_cancel->Set_button_text(fcancel);
                hp_Common_dialog_cancel->show();
                client_para srv_para;
                ServeIP = ui->label_IP->text();
                ServePort = ui->label_Account->text();
                int ret = ServePort.toInt();
                srv_para.switch_value = 1;
                srv_para.ServicePort = ret;
                strcpy(srv_para.ServiceIP,ServeIP.toLocal8Bit().data());
                qDebug() << "Send connect To Server";
                qDebug() << "IP == > " << ServeIP;
                qDebug() << "Port == > " << ServePort;
                siganl_pc_sys_set_serve_con(srv_para);
            }
        }else if(mymode == enum_AUP_SERVER_PLUS)
        {
            if(ui->label_IP->text().isEmpty() || ui->label_Account->text().isEmpty() || ui->label_server_act->text().isEmpty() || ui->label_server_paswd->text().isEmpty())
            {
                QString para;
                para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
                qDebug("read language index:%d",para.toInt());
                if( para.toInt() == 1 )
                {
                    hp_Wifi_search_Dialog->Set_label_text("有條目輸入為空");
                }
                else if(para.toInt() == 2)
                {
                    hp_Wifi_search_Dialog->Set_label_text("Entry is null");
                }
                else if(para.toInt() == 3)
                {
                    hp_Wifi_search_Dialog->Set_label_text("ввод пустой");
                }
                else if(para.toInt() == 4)
                {
                    hp_Wifi_search_Dialog->Set_label_text("A bejegyzés nulla");
                }
                else if(para.toInt() == 5)
                {
                    hp_Wifi_search_Dialog->Set_label_text("Entrada vacía");
                }else
                {
                    hp_Wifi_search_Dialog->Set_label_text("有条目输入为空");
                }
                hp_Wifi_search_Dialog->show();
                hp_Wifi_search_Dialog->IsEmpty = true;
                ui->checkBox_srvopen->setChecked(false);
                //signal_Set_Unchecked();//关闭checkedBox
            }else
            {
                hp_Common_dialog_cancel->Set_label_text(fIsInConnnect);
                hp_Common_dialog_cancel->Set_button_text(fcancel);
                hp_Common_dialog_cancel->show();
                server_para srv_para;
                ServeIP = ui->label_IP->text();
                ServePort = ui->label_Account->text();
                ServeUsr = ui->label_server_act->text();
                ServePass = ui->label_server_paswd->text();
                int ret = ServePort.toInt();
                srv_para.switch_value = 1;
                srv_para.ServicePort = ret;
                strcpy(srv_para.ServiceIP,ServeIP.toLocal8Bit().data());
                strcpy(srv_para.ServiceUser,ServeUsr.toLocal8Bit().data());
                strcpy(srv_para.ServicePassword,ServePass.toLocal8Bit().data());
                qDebug() << "Send connect To Server";
                qDebug() << "Usr == > " << ServeUsr;
                qDebug() << "Password == > " << ServePass;
                qDebug() << "IP == > " << ServeIP;
                qDebug() << "Port == > " << ServePort;
                siganl_pc_sys_set_newserve_con(srv_para);
            }
        }
    }else//关闭
    {
        if(mymode == enum_AUP_SERVER)
        {
            client_para srv_para2;
            srv_para2.switch_value = 0;
            int ret = ServePort.toInt();
            srv_para2.ServicePort = ret;
            strcpy(srv_para2.ServiceIP,ServeIP.toLocal8Bit().data());
            qDebug() << "enum_AUP_SERVER Send disconnect To Server";
            qDebug() << "IP == > " << ServeIP;
            qDebug() << "Port == > " << ServePort;
            signal_pc_sys_cancel_autoupload(srv_para2);
            isClientOpen = false;
            siganl_client_isOn(false);
        }else if(mymode == enum_AUP_SERVER_PLUS){
            server_para srv_para2;
            srv_para2.switch_value = 0;
            int ret = ServePort.toInt();
            srv_para2.ServicePort = ret;
            strcpy(srv_para2.ServiceIP,ServeIP.toLocal8Bit().data());
            strcpy(srv_para2.ServiceUser,ServeUsr.toLocal8Bit().data());
            strcpy(srv_para2.ServicePassword,ServePass.toLocal8Bit().data());
            qDebug() << "enum_AUP_SERVER_PLUS Send disconnect To Server";
            qDebug() << "Usr == > " << ServeUsr;
            qDebug() << "Password == > " << ServePass;
            qDebug() << "IP == > " << ServeIP;
            qDebug() << "Port == > " << ServePort;
            signal_pc_sys_newcancel_autoupload(srv_para2);
            isClientOpen = false;
            siganl_client_isOn(false);
        }
    }
}
void hp_AutoUpLoad::slot_common_dialog_cancel()
{
    qDebug() << "hp_AutoUpLoad::slot_common_dialog_cancel";
    hp_Common_dialog_cancel->close();
    ui->checkBox_srvopen->setChecked(false);
    on_checkBox_srvopen_clicked(false);
}
void hp_AutoUpLoad::slot_pc_sys_set_serve_con(unsigned char return_value)
{
    qDebug("hp_AutoUpLoad::slot_pc_sys_set_serve_con:return_value:0x%02x",return_value);
//    if(isInReconnect)//若是处于重连取消，则不弹窗
//    {
//        isInReconnect = false;
//        if(isInDisConnect == false)
//        {
//            signal_set_cancel_autoupload_state();//必须两个都为false才发送
//            //这里实际上和hp_AutoUpLoad::slot_pc_sys_cancel_autoupload中是互相的
//            //若那里触发了，这里就不会触发
//            //若这里触发了，那里就不会触发，总的来说，只会触发一次
//        }
//        return;
//    }
    hp_Common_dialog_cancel->close();
    if(return_value == RE_OK)
    {
        if(ui->checkBox_srvopen->isChecked())
        {
            hp_Wifi_search_Dialog->Set_label_text(fconnectOk);
            hp_Wifi_search_Dialog->show();
            isClientOpen = true;
            siganl_client_isOn(true);
        }
    }else{
        if(ui->checkBox_srvopen->isChecked())
        {
            hp_Wifi_search_Dialog->Set_label_text(fconnectfalse);
            hp_Wifi_search_Dialog->show();
            ui->checkBox_srvopen->setChecked(false);
            isClientOpen = false;
            siganl_client_isOn(false);
        }
    }
}
void hp_AutoUpLoad::set4Gstatu(bool checked)
{
    is4Gopen = checked;
    if(!checked)
    {
        if(ui->checkBox_srvopen->isChecked())
        {
            emit ui->checkBox_srvopen->clicked(false);
            ui->checkBox_srvopen->setChecked(false);
        }
//        ui->checkBox_srvopen->setCheckable(false);
    }else{
        ui->checkBox_srvopen->setCheckable(true);
    }
}
void hp_AutoUpLoad::setCloseClient()
{
    emit ui->checkBox_srvopen->clicked(false);
    ui->checkBox_srvopen->setChecked(false);
}
void hp_AutoUpLoad::slot_srvupload_cancel()
{
    //中断上传
    signal_pc_sys_set_sevsend_break();
}
void hp_AutoUpLoad::slot_pc_sys_set_sevsend_break(unsigned char return_value)
{
    qDebug() << "hp_AutoUpLoad::slot_pc_sys_set_sevsend_break == > " << return_value;
}
void hp_AutoUpLoad::slot_pc_sys_cancel_autoupload(unsigned char return_value)
{
    qDebug("hp_AutoUpLoad::slot_pc_sys_cancel_autoupload:return_value:0x%02x",return_value);
    qDebug() << "cancel autoUpload OK";
}
