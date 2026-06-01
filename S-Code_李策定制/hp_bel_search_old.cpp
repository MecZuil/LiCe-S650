#include "hp_bel_search_old.h"
#include "ui_hp_bel_search_old.h"

Hp_Bel_Search_Old::Hp_Bel_Search_Old(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Bel_Search_Old)
{
    ui->setupUi(this);
    connect_status = false;
    checked_clicked = false;

    qRegisterMetaType<BLE_DEVICE>("BLE_DEVICE");
    ui->toolButton_connect->setVisible(false);


    isInConnect = false;


    connect(&hba,SIGNAL(signal_search_end()),this,SLOT(slot_search_end()));
    connect(&hba,SIGNAL(signal_sync_searched_list()),this,SLOT(slot_sync_searched_list()));
    connect(&hba,SIGNAL(signal_sync_paired_list()),this,SLOT(slot_sync_paired_list()));
    connect(&hba,SIGNAL(signal_sync_connect(BLE_DEVICE)),this,SLOT(slot_sync_connect(BLE_DEVICE)));
    connect(&hba,SIGNAL(signal_sync_disconnect()),this,SLOT(slot_sync_disconnect()));

    connect(&hba,SIGNAL(signal_old_connect(bool)),this,SLOT(slot_old_connect(bool)));
    connect(&hba,SIGNAL(signal_add_string(QString)),this,SLOT(slot_add_string(QString)));

    connect(&hba,SIGNAL(signal_ui_add_string(QString, int)),this,SLOT(slot_ui_add_string(QString, int)));
    // void signal_ui_ble_state(int state_logo);
    connect(&hba,SIGNAL(signal_ui_label_state(int)),this,SLOT(slot_ui_label_state(int)));
    connect(&hba,SIGNAL(signal_ui_add_match_string(int)),this,SLOT(slot_ui_add_match_string(int)));

    connect(this,SIGNAL(signal_ble_dialog_type(int)),&hp_ble_dialog,SLOT(slot_ble_dialog_type(int)));

    connect(&hp_ble_dialog,SIGNAL(signal_ble_match_delete(int)),this,SLOT(slot_ble_match_delete(int)));
    ui->pushButton->close();


    listWidget_item_old = -2;
    listWidget_item_new = -1;

    QString para;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    if(para !=NULL)
    {
        if(para.toInt() == 0)
        {
            fDisConnnect=" 断开连接 ";
            fIsinSearch=" 搜索中";
            fEndSearch=" 搜索结束 ";
            fIsInConnnect="连接中";
            fConnnectOK=" 连接成功 ";
            fSwitching = "正在换挡";
            fSwitchingFailure = "换挡失败";
            fDisConnnectToDev="无法连接该设备";
            fConnnectfailed = "连接失败";
            fNoCard = "卡未插入";
            fNoModul = "模块未插入";
            fModulInit = "等待模块启动";
            fcancel = "取消";
        }
        else if(para.toInt() == 1)
        {
            fDisConnnect="斷開連接";
            fIsinSearch="搜索中";
            fEndSearch="搜索結束";
            fIsInConnnect="連接中";
            fConnnectOK="連接成功";
            fSwitching = "正在換擋";
            fSwitchingFailure = "換擋失敗";
            fDisConnnectToDev="無法連接該設備";
            fConnnectfailed = "連接失敗";
            fNoCard = "卡未插入";
            fNoModul = "模塊未插入";
            fModulInit = "等待模塊啟動";
            fcancel = "取消";
        }
        else if(para.toInt() == 2)//english
        {
            fDisConnnect="Disconnect";
            fIsinSearch="Searching";
            fEndSearch="Search End";
            fIsInConnnect="Connecting";
            fConnnectOK="Connecting Success";
            fSwitching = "Shifting gears";
            fSwitchingFailure = "Shift Fail";
            fDisConnnectToDev="Connection Fail";
            fConnnectfailed = "connection failed";
            fNoCard = "Card not inserted";
            fNoModul = "Module not inserted";
            fModulInit = "Wait for startup";
            fcancel = "Cancel";
        }
        else if(para.toInt() == 3)//俄语
        {
            fDisConnnect="Отключ-е";
            fIsinSearch="Поиск идет";
            fEndSearch="Конец поиска";
            fIsInConnnect="Соединение идет";
            fConnnectOK="Есть Соединение";
            fSwitching = "Переключение передач";
            fSwitchingFailure = "Переключение подключения";
            fDisConnnectToDev="Невозможно выполнить соед";
            fConnnectfailed = "Ошибка подключения";
            fNoCard = "карта не вставлена";
            fNoModul = "модуль не вставлен";
            fModulInit = "Ожидание запуска";
            fcancel = "Отм";
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            fDisConnnect="Lekapcsolás";
            fIsinSearch="Keresés";
            fEndSearch="Keresés vége";
            fIsInConnnect="Kapcsolódás";
            fConnnectOK="Sikeres kapcsolódás";
            fSwitching = "Görgetörnyezés";
            fSwitchingFailure = "Görgetörnyezés sikertelen";
            fDisConnnectToDev="Nem tud kapcsolódni";
            fConnnectfailed = "kapcsolat sikertelen";
            fNoCard = "Nincs beillesztve";
            fNoModul = "Modul be nem helyezve";
            fModulInit = "Indításra várva";
            fcancel = "Mégse";
        }
        else if(para.toInt() == 5)//西班牙语
        {
            fDisConnnect="Desconectar";
            fIsinSearch="Buscando";
            fEndSearch="Busqueda terminada";
            fIsInConnnect="Conectando";
            fConnnectOK="Conección exitosa";
            fSwitching = "Cambiando de marcha";
            fSwitchingFailure = "Cambiando fallida";
            fDisConnnectToDev="Es imposible conectar el dispositivo";
            fConnnectfailed = "Conexión fallida";
            fNoCard = "Tarjeta no insertada";
            fNoModul = "Módulo no insertado";
            fModulInit = "Esperando el inicio";
            fcancel = "Cancel";
        }
    }
}

Hp_Bel_Search_Old::~Hp_Bel_Search_Old()
{
    delete ui;
}
void Hp_Bel_Search_Old::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);
        QFont font10;
        font10.setPointSize(10);
        QFont font12;
        font12.setPointSize(12);

        this->resize(480,272);
        ui->frame->setGeometry(0,0,96,272);
        ui->toolButton_back->setGeometry(3,10,90,40);
        ui->toolButton_connect->setGeometry(3,210,90,40);
        ui->toolButton_disconnect->setGeometry(3,140,90,40);
        ui->toolButton_search->setGeometry(3,70,90,40);
        ui->frame_2->setGeometry(96,0,384,272);
        ui->label->setGeometry(171,5,201,17);
        ui->label_2->setGeometry(90,140,181,17);
        ui->label_3->setGeometry(90,5,81,17);
        ui->listWidget->setGeometry(90,25,181,113);
        ui->listWidget_match->setGeometry(90,160,181,112);
        ui->pushButton->setGeometry(10,40,51,41);

        ui->toolButton_connect->setFont(font10);
        ui->toolButton_disconnect->setFont(font10);
        ui->toolButton_search->setFont(font10);
        ui->pushButton->setFont(font9);
        ui->listWidget->setFont(font10);
        ui->listWidget_match->setFont(font10);
        ui->label->setFont(font12);
        ui->label_2->setFont(font12);
        ui->label_3->setFont(font12);
    }

    hp_ble_dialog.hp_setDefine_S3x0(isSelect);
}

void Hp_Bel_Search_Old::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    QString para;
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        if(para !=NULL)
        {

            if(para.toInt() == 0)
            {
                fDisConnnect=" 断开连接 ";
                fIsinSearch=" 搜索中";
                fEndSearch=" 搜索结束 ";
                fIsInConnnect="连接中";
                fConnnectOK=" 连接成功 ";
                fSwitching = "正在换挡";
                fSwitchingFailure = "换挡失败";
                fDisConnnectToDev="无法连接该设备";
                fConnnectfailed = "连接失败";
                fNoCard = "卡未插入";
                fNoModul = "模块未插入";
                fModulInit = "等待模块启动";
                fcancel = "取消";
            }
            else if(para.toInt() == 1)
            {
                fDisConnnect="斷開連接";
                fIsinSearch="搜索中";
                fEndSearch="搜索結束";
                fIsInConnnect="連接中";
                fConnnectOK="連接成功";
                fSwitching = "正在換擋";
                fSwitchingFailure = "換擋失敗";
                fDisConnnectToDev="無法連接該設備";
                fConnnectfailed = "連接失敗";
                fNoCard = "卡未插入";
                fNoModul = "模塊未插入";
                fModulInit = "等待模塊啟動";
                fcancel = "取消";
            }
            else if(para.toInt() == 2)//english
            {
                fDisConnnect="Disconnect";
                fIsinSearch="Searching";
                fEndSearch="Search End";
                fIsInConnnect="Connecting";
                fConnnectOK="Connecting Success";
                fSwitching = "Shifting gears";
                fSwitchingFailure = "Shift Fail";
                fDisConnnectToDev="Connection Fail";
                fConnnectfailed = "connection failed";
                fNoCard = "Card not inserted";
                fNoModul = "Module not inserted";
                fModulInit = "Wait for startup";
                fcancel = "Cancel";
            }
            else if(para.toInt() == 3)//俄语
            {
                fDisConnnect="Отключ-е";
                fIsinSearch="Поиск идет";
                fEndSearch="Конец поиска";
                fIsInConnnect="Соединение идет";
                fConnnectOK="Есть Соединение";
                fSwitching = "Переключение передач";
                fSwitchingFailure = "Переключение подключения";
                fDisConnnectToDev="Невозможно выполнить соед";
                fConnnectfailed = "Ошибка подключения";
                fNoCard = "карта не вставлена";
                fNoModul = "модуль не вставлен";
                fModulInit = "Ожидание запуска";
                fcancel = "Отм";
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                fDisConnnect="Lekapcsolás";
                fIsinSearch="Keresés";
                fEndSearch="Keresés vége";
                fIsInConnnect="Kapcsolódás";
                fConnnectOK="Sikeres kapcsolódás";
                fSwitching = "Görgetörnyezés";
                fSwitchingFailure = "Görgetörnyezés sikertelen";
                fDisConnnectToDev="Nem tud kapcsolódni";
                fConnnectfailed = "kapcsolat sikertelen";
                fNoCard = "Nincs beillesztve";
                fNoModul = "Modul be nem helyezve";
                fModulInit = "Indításra várva";
                fcancel = "Mégse";
            }
            else if(para.toInt() == 5)//西班牙语
            {
                fDisConnnect="Desconectar";
                fIsinSearch="Buscando";
                fEndSearch="Busqueda terminada";
                fIsInConnnect="Conectando";
                fConnnectOK="Conección exitosa";
                fSwitching = "Cambiando de marcha";
                fSwitchingFailure = "Cambiando fallida";
                fDisConnnectToDev="Es imposible conectar el dispositivo";
                fConnnectfailed = "Conexión fallida";
                fNoCard = "Tarjeta no insertada";
                fNoModul = "Módulo no insertado";
                fModulInit = "Esperando el inicio";
                fcancel = "Cancel";
            }
        }
        break;
    default:
        break;
    }
}


void Hp_Bel_Search_Old::ble_on()
{
    //qDebug()<<"ble will on";
    hba.startBle();
    //qDebug() << "Label Set --> Init Set Null 1";
    ui->label->setText("");
//    hba.send_cmd("AT#CZ\r\n");
//    hba.searchPairListInfo();
    //获取蓝牙配对列表
    hba.ble_stete.ble_first_open =true;

    hba.stop_ble_signal = false;

    //qDebug() << "Ble Send CMD 1 : AT#QD  -- >> Init";
    hba.send_cmd("AT#QD");
    //开机自动搜索耳机
 //   hba.send_cmd("AT#QP");
}



void Hp_Bel_Search_Old::ble_off()
{
    connect_status =false;
//    flush_ui_device();
    qDebug() << "Ble Send CMD 2 : AT#CD  -- >> DisConnect";
    hba.send_cmd("AT#CD");		//断开链接
    //清空列表
    flush_ui_device();
    hba.ble_match_init();
    ui->listWidget_match->clear();
    hba.ble_stete.QS_ble =0;
    hba.ble_stete.IB_ble = 0;
    hba.stop_ble_signal = true;
//    hba.stopBle();
}

bool Hp_Bel_Search_Old::get_conn_status()
{
    return connect_status;
}



void Hp_Bel_Search_Old::on_toolButton_search_released()		//lcy  搜索耳机
{
    qDebug()<<" search_released";
    signal_update_lcdoff_time(true);
    ui->listWidget->clear(  );
    checked_clicked = false;
    if(true == connect_status)      //耳机已经连接的时候进行搜索，设置值，便于处理和判断
    {
        ble_dis_type=1;
    };
//初始化一些数据
    hba.ble_set_num = 0;
    for(int i=0; i<sizeof(hba.ble_set_mac)/sizeof(hba.ble_set_mac[0]); i++)
    {
        hba.ble_set_mac[i]	="";
        hba.ble_set_name[i]="";
    }
    //qDebug() << "Ble Send CMD 3 : AT#QP  -- >> Please Search";
    hba.send_cmd("AT#QP");								//发送搜索命令
    //qDebug() << "Label Set --> Please Search 2";
    ui->label->setText(fIsinSearch);

}

void Hp_Bel_Search_Old::on_toolButton_connect_released()	    //连接耳机
{
    signal_update_lcdoff_time(true);
    listWidget_item_new = ui->listWidget->currentRow();
    if(listWidget_item_new <0)
    {
        //qDebug( )<<" Please select new  item";
        return;
    }
/*
    if( listWidget_item_old == listWidget_item_new)
    {
        qDebug( )<<" Please select new listWidget item";
        return;
    }
    */
    listWidget_item_old =listWidget_item_new;

    if(true == connect_status)
    {
        hba.ble_stete.CD_ble = 1;
        //qDebug() << "Ble Send CMD 4 : AT#CD  -- >> DisConnect";
        hba.send_cmd("AT#CD");    //断开当前耳机.
        ble_dis_type=2;
        hba.ble_stete.QS_ble = 1;       //连接新耳机时断开连接
        return;
    };

            QString str_ui_text;
            str_ui_text = ui->listWidget->currentItem()->text();
            int str_ui_i = ui->listWidget->currentRow();
            str_ui_i = ui->listWidget->currentRow();
            if( str_ui_text == hba.ble_set_mac[str_ui_i].mid(14, hba.ble_set_mac[str_ui_i].length()-14))
            {
                //qDebug() << "Ble Send CMD 5 : AT#CC  -- >> IsInConnect";
                QString ble_send_str = "AT#CC";
               ble_send_str = ble_send_str.append(hba.ble_set_mac[str_ui_i].mid(2,12));
               hba.send_cmd(ble_send_str);
            }else
            {
                //qDebug() << "Label Set --> DisConnnectToDev 3";
                ui->label->setText(fDisConnnectToDev);
            }
            //qDebug() << "Label Set --> IsInConnect 4";
            ui->label->setText(fIsInConnnect);
}


//断开连接
void Hp_Bel_Search_Old::on_toolButton_disconnect_released()		//断开耳机
{
    signal_update_lcdoff_time(true);
    //qDebug() << "Ble Send CMD 6 : AT#CD  -- >> DisConnect";
    hba.send_cmd("AT#CD");
}


void Hp_Bel_Search_Old::slot_search_end()
{

}

void Hp_Bel_Search_Old::slot_sync_searched_list()
{

}

void Hp_Bel_Search_Old::slot_sync_paired_list()
{

}


void Hp_Bel_Search_Old::slot_sync_connect(BLE_DEVICE headset)
{

}

void Hp_Bel_Search_Old::slot_sync_disconnect()
{

}

void Hp_Bel_Search_Old::slot_old_connect(bool conn)
{
    connect_status = conn;                                  //true:
    //qDebug() << "Label Set --> ConnnectOK 5";
    ui->label->setText(fConnnectOK);
    isInConnect = false;
}

void Hp_Bel_Search_Old::slot_add_string(QString str)	//
{
}


void Hp_Bel_Search_Old::slot_ui_add_string(QString str,int position)	//添加可用列表
{
    //qDebug() << "str -- > ble Search --> " << str;
    QListWidgetItem *listWidgetItem = new QListWidgetItem;
    listWidgetItem->setText(str);
//    listWidgetItem->setIcon(QIcon("../myblue2/xxx.png"));
    listWidgetItem->setTextColor(QColor(255,255,255));
    ui->listWidget->addItem(listWidgetItem);
//    ui->listWidget->insertItem(position,str);

}

void Hp_Bel_Search_Old::slot_ui_add_match_string( int count)            //添加匹配列表
{
    qDebug() << "Hp_Bel_Search_Old::slot_ui_add_match_string" << 1;
    ui->listWidget_match->clear();
    if(count > 6)
    {
        count = 6;
    }
    for(int i=0; i<count; i++)
    {
        QListWidgetItem *listWidgetItem = new QListWidgetItem;
        listWidgetItem->setText(hba.ble_match_name.at(i));
        listWidgetItem->setTextColor(QColor(255,255,255));
        ui->listWidget_match->addItem(listWidgetItem);

    }
}

void Hp_Bel_Search_Old::slot_ble_match_delete(int signal_type)
{
    switch(signal_type)
    {
     case 1:         //此时断开链接
        //qDebug() << "Ble Send CMD 7 : AT#CD  -- >> DisConnect";
            hba.send_cmd("AT#CD");
        break;
    default:
        break;
    }

}
void Hp_Bel_Search_Old::slot_ui_label_state(int state_ble)
{
    if(1 == state_ble){
        //qDebug() << "{-=--=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=} 111";//确认是这里出问题了
        //ui->label->setText(fIsinSearch);
    }else if(2 == state_ble){
        //qDebug() << "Label Set --> ConnnectOK 6";
        ui->label->setText(fEndSearch);
    }else if(3 == state_ble){
        //qDebug() << "Label Set --> IsInConnnect 7";
         ui->label->setText(fIsInConnnect);
    }else if(4 == state_ble){
        //qDebug() << "Label Set --> ConnnectOK 8";
        connect_status = true;                                          //耳机图标设置
        ui->label->setText(fConnnectOK);
        isInConnect = false;
    }else  if(5 == state_ble){
        connect_status = false;
        if(!isInConnect)//防止在连接过程中出现断开连接的情况，具体原因，以后要仔细研究
        {
            //qDebug() << "Label Set --> DisConnnect 9";
            ui->label->setText(fDisConnnect);
        }
        if( 2==ble_dis_type)                                            //连接另一个耳机的时候断开.连接耳机
        {
            ble_dis_type=0;

            int str_ui_i;
            str_ui_i = ui->listWidget->currentRow();
            if( str_ui_i<0)
            {
                return;
            }
            QString str_ui_text;
            str_ui_text = ui->listWidget->currentItem()->text();
            if( str_ui_text == hba.ble_set_mac[str_ui_i].mid(14, hba.ble_set_mac[str_ui_i].length()-14))
            {
                //qDebug() << "Ble Send CMD 8 : AT#CC  -- >> IsInConnect";
                QString ble_send_str = "AT#CC";
               ble_send_str = ble_send_str.append(hba.ble_set_mac[str_ui_i].mid(2,12));
//               hba.ble_stete.ble_mac_connecting = hba.ble_set_mac[str_ui_i].mid(2,12);
               hba.send_cmd(ble_send_str);
            }else
            {
                /*
                qDebug( )<<"^^^^^^^^^^^^^^^^^^^ OK22222";
                for(int i=0;  i<hba.ble_set_num; i++)
                {
                    if(hba.ble_set_name[i] == str_ui_text)
                    {
                         QString ble_send_str = "AT#CC";
                        ble_send_str = ble_send_str.append(hba.ble_set_mac[i].mid(2,12));
                        hba.ble_stete.ble_mac_connecting = hba.ble_set_mac[i].mid(2,12);
                        hba.send_cmd(ble_send_str);
                        break;
                    };
                }
                */
                //qDebug() << "Label Set --> DisConnnectToDev 10";
                ui->label->setText(fDisConnnectToDev);
            }

        }else if(1 == ble_dis_type)                                 //搜索时断开
        {
            //qDebug() << "Label Set --> IsinSearch 11";
            ui->label->setText(fIsinSearch);
            ble_dis_type=0;
        }else{
            ble_dis_type=0;
        }

    }else if(6 == state_ble){                           //信号，HFP_CONNECT。耳机恢复出厂设置后，需要删除配对列表。再连接
  //      ui->label->setText(tr(" 耳机恢复出厂设置"));

        int str_ui_i;
        str_ui_i = ui->listWidget->currentRow();
        if(str_ui_i <0)
        {
            //qDebug() << "Ble Send CMD 9 : AT#CC  -- >> IsInConnect";
            QString ble_send_str = "AT#CC";
           ble_send_str = ble_send_str.append(hba.ble_stete.ble_mac_connecting);
           hba.send_cmd(ble_send_str);
           return;
        }

        QString str_ui_text;
 //       qDebug( )<<" && "<<ui->listWidget->currentRow();
        str_ui_text = ui->listWidget->currentItem()->text();

 //       qDebug( )<<" && "<<str_ui_i;
        if( str_ui_text == hba.ble_set_mac[str_ui_i].mid(14, hba.ble_set_mac[str_ui_i].length()-14))
        {
            //qDebug() << "Ble Send CMD 10 : AT#CC  -- >> IsInConnect";
            QString ble_send_str = "AT#CC";
           ble_send_str = ble_send_str.append(hba.ble_set_mac[str_ui_i].mid(2,12));
  //         hba.ble_stete.ble_mac_connecting = hba.ble_set_mac[str_ui_i].mid(2,12);
 //          qDebug( )<<" && "<<str_ui_i;
           hba.send_cmd(ble_send_str);
        }else
        {
            //qDebug() << "Label Set --> DisConnnectToDev 12";
            ui->label->setText(fDisConnnectToDev);
            /*
            qDebug( )<<"^^^^^^^^^^^^^^^^^^^ OK22222";
            for(int i=0;  i<hba.ble_set_num; i++)
            {
                if(hba.ble_set_name[i] == str_ui_text)
                {
                     QString ble_send_str = "AT#CC";
                    ble_send_str = ble_send_str.append(hba.ble_set_mac[i].mid(2,12));
                    hba.ble_stete.ble_mac_connecting = hba.ble_set_mac[i].mid(2,12);
                    hba.send_cmd(ble_send_str);
                    break;
                };
            }
            */
        }
    }else if(7 == state_ble){
        //qDebug() << "Label Set --> DisConnnectToDev 13";
        ui->label->setText(fDisConnnectToDev);
    }else
    {
        //qDebug() << "Label Set --> Null 14";
        ui->label->setText(tr(""));
    }
}

void Hp_Bel_Search_Old::on_listWidget_clicked(const QModelIndex &index)
{
    signal_update_lcdoff_time(true);
    checked_clicked = true;
}

void Hp_Bel_Search_Old::on_listWidget_activated(const QModelIndex &index)
{
}


void Hp_Bel_Search_Old::on_pushButton_released()
{
    signal_update_lcdoff_time(true);
    flush_ui_device( );

}


void Hp_Bel_Search_Old::on_listWidget_currentRowChanged(int currentRow)
{
    signal_update_lcdoff_time(true);
    /*
    if( currentRow<0)
    {
        return ;
    }

    //    qDebug()<<"************************connect_released";
        //判断是否已经连接上，连接上了就断开，重新连接
        //连接成功时 connect_status = true.断开时为 false， 按照这个为判断条件。 没有设置新的条件进行判断
        if(true == connect_status)
        {
            hba.send_cmd("AT#CD");    //断开当前耳机.
            ble_dis_type=2;
            hba.ble_stete.QS_ble = 1;       //连接新耳机时断开连接
            return;
        };

            QString str_ui_text;
            str_ui_text = ui->listWidget->currentItem()->text();
            int str_ui_i = currentRow;
            str_ui_i = ui->listWidget->currentRow();
            if( str_ui_text == hba.ble_set_mac[str_ui_i].mid(14, hba.ble_set_mac[str_ui_i].length()-14))
            {
                qDebug( )<<"^^^^^^^^^^^^^^^^^^^ OK11111";
  //              hba.ble_stete.QS_ble = 1;
                QString ble_send_str = "AT#CC";
               ble_send_str = ble_send_str.append(hba.ble_set_mac[str_ui_i].mid(2,12));
               hba.send_cmd(ble_send_str);
            }else
            {
                /*
                qDebug( )<<"^^^^^^^^^^^^^^^^^^^ OK22222";
                for(int i=0;  i<hba.ble_set_num; i++)
                {
                    if(hba.ble_set_name[i] == str_ui_text)
                    {
  //                      hba.ble_stete.QS_ble = 1;
                         QString ble_send_str = "AT#CC";
                        ble_send_str = ble_send_str.append(hba.ble_set_mac[i].mid(2,12));
                        hba.send_cmd(ble_send_str);
                        break;
                    };
                }
                */
/*
                ui->label->setText(tr("无法连接该设备"));

            }
            ui->label->setText(tr("连接中"));
*/
}

bool Hp_Bel_Search_Old::flush_ui_device()
{
    //可用设备框清屏
    ui->listWidget->clear();
    hba.ble_set_num = 0;
    //搜索到的蓝牙地址数组初始化
    for(int i=0; i<sizeof(hba.ble_set_mac)/sizeof(hba.ble_set_mac[0]); i++)
    {
        hba.ble_set_mac[i]	="";
        hba.ble_set_name[i]="";
    }
/*
    //已配对设备初始化
    for(int i=0; i<sizeof(hba.ble_match_mac)/sizeof(hba.ble_match_mac[0]); i++)
    {
        hba.ble_match_mac[i] = "";
        hba.ble_match_name[i] = "";
    }
    hba.ble_match_num = 0;
*/
    //自动搜索相关结构体初始化

    for(int i=0; i<sizeof(hba.ble_auto_connect.ble_match_ok)/sizeof(hba.ble_auto_connect.ble_match_ok[0]);i++)
    {
        hba.ble_auto_connect.ble_match_ok[0] = "";
    }
    hba.ble_auto_connect.ble_connect_i = 0;
    hba.ble_auto_connect.ble_match_ok_i =0;

    return true;
}

void Hp_Bel_Search_Old::ble_off_close()
{
    hba.ble_match_init_clean();
        ui->listWidget_match->clear();
        hba.ble_stete.QS_ble =0;
        hba.ble_stete.IB_ble = 0;
        hba.stop_ble_signal = true;
}



void Hp_Bel_Search_Old::on_listWidget_itemPressed(QListWidgetItem *item)
{
    listWidget_item_new = ui->listWidget->currentRow();
    if( listWidget_item_old == listWidget_item_new)
    {
        if(true == connect_status)          //耳机已经链接上的时候
        {
            signal_ble_dialog_type(1);
            return;
        }
    }
    listWidget_item_old =listWidget_item_new;

        //判断是否已经连接上，连接上了就断开，重新连接
        //连接成功时 connect_status = true.断开时为 false， 按照这个为判断条件。 没有设置新的条件进行判断
    if(true == connect_status)
    {
        hba.ble_stete.CD_ble = 1;
        //qDebug() << "Ble Send CMD 11 : AT#CD  -- >> DisConnect";
        hba.send_cmd("AT#CD");    //断开当前耳机.
        ble_dis_type=2;
        hba.ble_stete.QS_ble = 1;       //连接新耳机时断开连接
        return;
    };

            QString str_ui_text;
            str_ui_text = ui->listWidget->currentItem()->text();
            int str_ui_i = ui->listWidget->currentRow();
            str_ui_i = ui->listWidget->currentRow();
            if( str_ui_text == hba.ble_set_mac[str_ui_i].mid(14, hba.ble_set_mac[str_ui_i].length()-14))
            {
                //先判断耳机是否存在，如果不存在就不断开耳机
  //              hba.ble_stete.QS_ble = 1;
               //qDebug() << "Ble Send CMD 12 : AT#CC  -- >> IsInConnect";
               QString ble_send_str = "AT#CC";
               ble_send_str = ble_send_str.append(hba.ble_set_mac[str_ui_i].mid(2,12));
               //qDebug() << "Is Connect to --> " << ble_send_str;
               hba.send_cmd(ble_send_str);
            }else
            {
                //qDebug() << "Label Set --> DisConnnectToDev 15";
                ui->label->setText(fDisConnnectToDev);
            }
            isInConnect = true;
            //qDebug() << "Label Set --> IsInConnnect 16";
            ui->label->setText(fIsInConnnect);
}

void Hp_Bel_Search_Old::on_listWidget_match_itemClicked(QListWidgetItem *item)      //点击匹配列表后 对条条目进行处理
{
    signal_update_lcdoff_time(true);
//    signal_ble_dialog_type(0);

}

void Hp_Bel_Search_Old::on_toolButton_back_clicked()
{
    this->close();
    hba.ble_match_num = 0;
}
