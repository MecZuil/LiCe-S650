/***********************************************************
 * 三个按钮坐标位置
 * 3   120   240   360   ( y坐标 )
 * ******************************************************/
#include  "hp_ble_search.h"
#include  "ui_hp_ble_search.h"
#include  <QDebug>
#include  <QListWidget>
Hp_Ble_Search::Hp_Ble_Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Ble_Search)
{
    ui->setupUi(this);
    m_currGetInfoType = 4;
    m_functionMode = 4;
    m_isGetBleStatus = false;
    m_isStartGetAudio = false;
    m_macAddr = "!";
    isLinked = false;
    m_isCloseBle = false;
    m_devName = "";
    m_scanAddrNameMap.clear();
    m_matchAddrNameMap.clear();
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timer_pc_sys_set_ble_function()));
    m_timer->stop();
    m_linkFlag = false;
    m_closeTimer = new QTimer();
    connect(m_closeTimer, SIGNAL(timeout()), this, SLOT(send_close()));
    m_closeTimer->stop();

    m_bleStateTimer = new QTimer();
    connect(m_bleStateTimer, SIGNAL(timeout()), this, SLOT(timer_core_get_ble_state()));
    m_bleStateTimer->stop();
    m_currentItem = -1;
    ui->pushButton->setHidden(true);
    ui->toolButton_connect->setHidden(true);
    m_bleDialog = new Hp_Ble_Dialog(this);
    m_bleDialog->setGeometry((this->width()  - m_bleDialog->width()) / 2, (this->height() - m_bleDialog->height()) / 2, m_bleDialog->width(), m_bleDialog->height());
    connect(m_bleDialog, SIGNAL(signal_ble_match_delete(int)), this, SLOT(slot_ble_match_delete(int)));
}

Hp_Ble_Search::~Hp_Ble_Search()
{
    delete ui;
}

void Hp_Ble_Search::hp_define5_5(bool isDefine)
{

}

void Hp_Ble_Search::hp_setDefine_S3x0(bool isDefine)
{
    if(isDefine)
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

    m_bleDialog->hp_setDefine_S3x0(isDefine);
}

void Hp_Ble_Search::ble_on()
{
    isLinked = false;
    m_bleStateTimer->stop();
    m_currentItem = -1;
    m_isCloseBle = false;
    ui->listWidget->clear();
    ui->label->setText("");
    m_macAddr = "!";
//    m_functionMode = 4;
//    m_currGetInfoType = 4;
//    timer_pc_sys_set_ble_function();
    ui->label->setText(fIsinSearch);
    m_currGetInfoType = 1;
    m_functionMode = 1;
    timer_pc_sys_set_ble_function();
}

void Hp_Ble_Search::ble_off()
{
    m_currentItem = -1;
    qDebug() << "Hp_Ble_Search::ble_off()" << isLinked;
    if(m_bleStateTimer->isActive())
        m_bleStateTimer->stop();
    if(isLinked)
    {
        m_isCloseBle = true;
        isLinked = false;
        slot_ble_match_delete(1);

        m_closeTimer->start(3000);
    }
    else
    {
        signal_ble_set_close();
    }
}

void Hp_Ble_Search::on_listWidget_itemPressed(QListWidgetItem *item)
{
    m_isStartGetAudio = false;
    QString itemName = item->text();
    m_currentItem = ui->listWidget->currentRow();
    qDebug() << itemName;
    m_devName = itemName;
    if(isLinked)
    {
        isLinked = false;
        qDebug() << itemName << m_matchAddrNameMap.value(m_macAddr) << m_scanAddrNameMap.value(m_macAddr);
        if(m_macAddr == "!" || !m_matchAddrNameMap.value(m_macAddr).contains(itemName))
        {
            m_currGetInfoType = 2;
            m_functionMode = 2;//换一个连接
            timer_pc_sys_set_ble_function();
        }
        else if(m_matchAddrNameMap.value(m_macAddr).contains(itemName))
        {
            qDebug() << itemName << m_matchAddrNameMap.value(m_macAddr);
            m_bleDialog->setSingleButton();
            m_bleDialog->slot_ble_dialog_type(1);
            m_bleDialog->show();
            //已有蓝牙连接的情况下
        }
    }
    else
    {
        ui->label->setText(fIsInConnnect);
        qDebug() << itemName << m_devName;
        m_currGetInfoType = 2;
        m_functionMode = 2;
        timer_pc_sys_set_ble_function();
    }
}

void Hp_Ble_Search::send_close()
{
    if(m_timer->isActive())
        m_timer->stop();
    if( m_bleStateTimer->isActive())
        m_bleStateTimer->stop();
    if(m_closeTimer->isActive())
        m_closeTimer->stop();
    m_isCloseBle = false;
    signal_ble_set_close();
}

void Hp_Ble_Search::timer_pc_sys_set_ble_function()
{
    qDebug() << "Hp_Ble_Search::timer_pc_sys_set_ble_function()" << m_functionMode;
    m_isGetBleStatus = true;
    BleInfo bleInfo;
    bleInfo.function_mode = m_functionMode;
    if(2 == m_functionMode || 3 == m_functionMode )
    {
        isLinked = false;
        //连接时必须有地址
        qDebug() << "Hp_Ble_Search::timer_pc_sys_set_ble_function()" << m_scanAddrNameMap.key(m_devName).toLocal8Bit().data();
        strcpy(bleInfo.mac_addr , m_scanAddrNameMap.key(m_devName).toLocal8Bit().data());
    }
    signal_pc_sys_set_ble_function(bleInfo);
    m_bleStateTimer->start(1000);
}

void Hp_Ble_Search::timer_core_get_ble_state()
{
    signal_core_get_ble_status();
}

void Hp_Ble_Search::slot_pc_sys_set_ble_function(unsigned char return_value)
{
    qDebug("Hp_Ble_Search::slot_pc_sys_set_ble_function return_value = 0x0%x", return_value);
    if(return_value == RE_OK)
    {
        m_timer->stop();
        if(m_functionMode == 2)
        {
            m_matchAddrNameMap.insert(m_macAddr, m_devName);
            add_listWidget_match();
            m_currGetInfoType = 2;
        }
        if(m_functionMode == 3)
        {
            m_matchAddrNameMap.remove(m_devName);
            m_currGetInfoType = 3;
            m_bleStateTimer->start(1000);
        }
        if(m_functionMode == 4)
        {
            m_currGetInfoType = 4;
            signal_pc_sys_get_ble_info(2);
        }
        return;
    }
}
void Hp_Ble_Search::slot_pc_sys_get_ble_info(unsigned char return_value, QString data)
{
    qDebug() << __func__ << return_value << "isLInked" << isLinked << "m_currentItem" << m_currentItem << __LINE__;
    if(!this->isVisible())
    {
        return;
    }
    if(isLinked && (-1 == m_currentItem))
    {
        isLinked = false;
        if(data.isEmpty())
            return;
        QString mac_addr = data.split(",").at(0);
        QString dev_name = data.split(",").at(1);
        qDebug() << "linked err" << "mac_addr" << mac_addr << "dev_name" << dev_name << __LINE__;
        m_devName = dev_name;
        m_macAddr = mac_addr;
        m_currGetInfoType = 3;
        m_functionMode = 3;
        timer_pc_sys_set_ble_function();
        m_matchAddrNameMap.clear();
        return;
    }
    if(return_value == RE_OK)
    {
        QString addrNameMsg(data);
        QStringList addrNameList = addrNameMsg.split("\n");
        if(addrNameList.count() == 0)
            return;

        if(m_currGetInfoType == 3 || m_currGetInfoType == 2)
        {
            m_matchAddrNameMap.clear();
            for(QString addrName : addrNameList)
            {
                if(addrName.split(",").count() < 2)
                    break;
                QString mac_addr = addrName.split(",").at(0);
                QString dev_name = addrName.split(",").at(1);
                m_matchAddrNameMap.insert(mac_addr, dev_name);
                qDebug() << "mac_addr" << mac_addr << "dev_name" << dev_name;
            }
            add_listWidget_match();
        }
        else if(m_currGetInfoType == 1)
        {
            m_scanAddrNameMap.clear();
            for(QString addrName : addrNameList)
            {
                qDebug() << "add new ble";
                if(addrName.split(",").count() < 2)
                    break;
                QString mac_addr = addrName.split(",").at(0);
                QString dev_name = addrName.split(",").at(1);
                m_scanAddrNameMap.insert(mac_addr, dev_name);
                qDebug() << "mac_addr" << mac_addr << "dev_name" << dev_name;
            }
            add_listWidget();

            m_currGetInfoType = 0;
        }
        else if(m_currGetInfoType == 4)
        {

            if(addrNameMsg.isEmpty() || addrNameMsg.split(",").count() < 2)
                return;
            qDebug() << "m_currGetInfoType" << 4 << addrNameMsg;
            QString mac_addr = addrNameMsg.split(",").at(0);
            QString dev_name = addrNameMsg.split(",").at(1);
            qDebug() << "mac_addr" << mac_addr << "dev_name" << dev_name;
            m_devName = dev_name;
            m_macAddr = mac_addr;
            m_currGetInfoType = 3;
            m_functionMode = 3;
            timer_pc_sys_set_ble_function();
            m_matchAddrNameMap.clear();
        }
    }
}


void Hp_Ble_Search::slot_get_ble_state(unsigned char return_value, BleState bleState)
{
    if(!this->isVisible())
    {
        if(bleState.conn_state != 2)
        {
            isLinked = false;
            ui->label->setText(fConnnectfailed);
            if(m_bleStateTimer->isActive())
                m_bleStateTimer->stop();
            if(m_timer->isActive())
                m_timer->stop();
            ble_off();
        }
        return;
    }
    if(return_value == RE_OK)
    {
        qDebug("Hp_Ble_Search::slot_get_ble_state 0x0%x， bleState.conn_state %d, bleState.pair_state %d, scan_state %d， currGetInfoType :%d", return_value, bleState.conn_state,
               bleState.pair_state, bleState.scan_state, m_currGetInfoType);
        m_isGetBleStatus = false;
        int connState = bleState.conn_state;
        int pairState = bleState.pair_state;
        int scanState = bleState.scan_state;
        if(m_currGetInfoType == 0)
        {
            m_bleStateTimer->stop();
        }
        if(m_currGetInfoType == 1)//当前是扫描可用蓝牙时关注这个
        {
            if(scanState == -1)
            {
                //异常
                m_currGetInfoType = 0;
            }
            if(connState == 2)
            {
                if(m_currentItem != -1)
                    isLinked = true;
                m_functionMode = 2;
                m_bleStateTimer->stop();
                signal_pc_sys_get_ble_info(2);
//                ui->label->setText(fConnnectOK);
//                isLinked = true;
//                m_bleDialog->setSingleButton();
//                m_bleDialog->setDialogText(fConnnectOK);
//                m_bleDialog->show();
//                qDebug() << m_scanAddrNameMap.values().at(0);
//                ui->listWidget->addItems(m_scanAddrNameMap.values());
                return;
            }
            if(scanState == 3)
            {
                    ui->label->setText(fEndSearch);
                    m_bleStateTimer->stop();
                    signal_pc_sys_get_ble_info(1);
            }
        }
        if(m_currGetInfoType == 2)//当前是连接蓝牙时关注这个
        {
            if(connState == -1)
            {
                //异常
                m_currGetInfoType = 0;
            }
            else{
                if(connState == 0)
                {
                    if(isLinked)
                    {
                        ui->label->setText(fDisConnnect);
                        isLinked = false;
                    }
                }
                else if(connState == 2)
                {
                    m_functionMode = 2;
                    m_macAddr = m_scanAddrNameMap.key(m_devName);
                    m_devName = ui->listWidget->currentItem()->text();
                    m_bleStateTimer->stop();
                    slot_start_test_audio();
                    if(!m_isStartGetAudio)
                        m_isStartGetAudio = true;
                }
            }
        }
        if(m_currGetInfoType == 3)
        {
            if(connState == 0 && m_functionMode == 3)
            {
                isLinked = false;
                ui->label->setText(fDisConnnect);
                m_bleStateTimer->stop();
                if(m_isCloseBle)
                {
                    m_isCloseBle = false;
                    signal_ble_set_close();
                }
                else
                {
//                    m_bleDialog->setSingleButton();
//                    m_bleDialog->setDialogText(fDisConnnect);
//                    m_bleDialog->show();
                    slot_ble_match_delete(1);
                    signal_reset_ble_power();
                }
            }
        }
        if(m_currGetInfoType == 4)//当前是配对蓝牙时关注这个
        {
            qDebug() << "m_currGetInfoType" << m_currGetInfoType << pairState << connState;
            if(pairState == -1)
            {
                //异常
            }
            else{
                //直到配对信息检测完毕之后
                if(pairState == 4 || connState == 2)
                {
                    m_bleStateTimer->stop();
                    signal_pc_sys_get_ble_info(2);
                }
            }
        }
    }
}

void Hp_Ble_Search::add_listWidget()
{
    ui->listWidget->clear();
    QMap<QString, QString>::const_iterator itMap = m_scanAddrNameMap.constBegin();
    for(; itMap != m_scanAddrNameMap.constEnd(); itMap++)
    {
        QString ble_name = itMap.value();
        ui->listWidget->addItem(ble_name);
    }
}

void Hp_Ble_Search::add_listWidget_match()
{
    qDebug() << "Hp_Ble_Search::add_listWidget_match()";
    ui->listWidget_match->clear();
    QMap<QString, QString>::const_iterator itMap = m_matchAddrNameMap.constBegin();
    for(; itMap != m_matchAddrNameMap.constEnd(); itMap++)
    {
        QString ble_name = itMap.value();
        ui->listWidget_match->addItem(ble_name);
    }
}

void Hp_Ble_Search::slot_ble_match_delete(int type)
{
    qDebug() << "Hp_Ble_Search::slot_ble_match_delete";
    if(isLinked)
    {
        signal_pc_sys_get_ble_info(2);
        m_bleStateTimer->stop();
        return;
    }
    if(type == 1)
    {
        BleInfo bleInfo;

        m_currGetInfoType = 3;
        m_functionMode = 3;
        timer_pc_sys_set_ble_function();
        bleInfo.function_mode = m_functionMode;
    }
}

void Hp_Ble_Search::on_toolButton_search_clicked()
{
    ui->label->setText(fIsinSearch);
    m_currGetInfoType = 1;
    m_functionMode = 1;
    timer_pc_sys_set_ble_function();
}

void Hp_Ble_Search::on_toolButton_disconnect_clicked()
{
    isLinked = false;
    slot_ble_match_delete(1);
//    m_currGetInfoType = 3;
//    m_functionMode = 3;
//    isLinked = false;
//    timer_pc_sys_set_ble_function();
}

void Hp_Ble_Search::on_toolButton_connect_clicked()
{
    return;
}

void Hp_Ble_Search::on_toolButton_back_clicked()
{
    m_isGetBleStatus = false;
    m_timer->stop();
    if(m_bleStateTimer->isActive())
        m_bleStateTimer->stop();
    if(isLinked)
        m_bleStateTimer->start(1000);
    this->close();
}

void Hp_Ble_Search::on_pushButton_clicked()
{
    return;
}

void Hp_Ble_Search::changeEvent(QEvent *e)
{
    signal_update_lcdoff_time(false);
    QWidget::changeEvent(e);
    QString para;
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        para = m_hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        if(para !=NULL)
        {
            if(para.toInt() == 0)
            {
                fBleStart=" 蓝牙启动中 ";
                fDisConnnect=" 断开连接 ";
                fIsinSearch=" 搜索中";
                fEndSearch=" 搜索结束 ";
                fIsInConnnect="连接中";
                fConnnectOK=" 连接成功 ";
                fDisConnnectToDev="无法连接该设备";
            }
            else if(para.toInt() == 1)
            {
                fBleStart=" 藍牙啓動中 ";
                fDisConnnect="斷開連接";
                fIsinSearch="搜索中";
                fEndSearch="搜索結束";
                fIsInConnnect="連接中";
                fConnnectOK="連接成功";
                fDisConnnectToDev="無法連接該設備";
            }
            else if(para.toInt() == 2)//english
            {
                fBleStart=" Bluetooth starting ";
                fDisConnnect="Disconnect";
                fIsinSearch="Searching";
                fEndSearch="Search End";
                fIsInConnnect="Connecting";
                fConnnectOK="Connecting Success";
                fDisConnnectToDev="Connection Fail";
            }
            else if(para.toInt() == 3)//俄语
            {
                fBleStart=" Запуск Bluetooth ";
                fDisConnnect="Отключ-е";
                fIsinSearch="Поиск идет";
                fEndSearch="Конец поиска";
                fIsInConnnect="Соединение идет";
                fConnnectOK="Есть Соединение";
                fDisConnnectToDev="Невозможно выполнить соед";
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                fBleStart=" Bluetooth indítása ";
                fDisConnnect="Lekapcsolás";
                fIsinSearch="Keresés";
                fEndSearch="Keresés vége";
                fIsInConnnect="Kapcsolódás";
                fConnnectOK="Sikeres kapcsolódás";
                fDisConnnectToDev="Nem tud kapcsolódni";
            }
            else if(para.toInt() == 5)//西班牙语
            {
                fBleStart=" Iniciando Bluetooth ";
                fDisConnnect="Desconectar";
                fIsinSearch="Buscando";
                fEndSearch="Busqueda terminada";
                fIsInConnnect="Conectando";
                fConnnectOK="Conección exitosa";
                fDisConnnectToDev="Es imposible conectar el dispositivo";
            }
        }
        break;
    default:
        break;
    }
}

void Hp_Ble_Search::mousePressEvent(QMouseEvent *e)
{
    signal_update_lcdoff_time(false);
}

void Hp_Ble_Search::keyReleaseEvent(QKeyEvent *ev)
{
    signal_update_lcdoff_time(true);
}

void Hp_Ble_Search::slot_start_test_audio()
{
    if(!m_isStartGetAudio && !isLinked)
    {
        m_recordAudioCount = 0;
        m_linkFlag = false;
        signal_core_key_add_audio_start();
    }
}

void Hp_Ble_Search::slot_core_key_add_audio_start(unsigned char return_value)
{
    if(!this->isVisible())
        return;
    qDebug() << __func__ << "return value:" << __LINE__;
    sleep(1);
    signal_core_key_add_audio_stop();
}

void Hp_Ble_Search::slot_core_key_add_audio_stop(unsigned char return_value, int audioLenth)
{
    if(!this->isVisible())
        return;
    qDebug() << __func__ << "return value:" << audioLenth;
    if(0 == audioLenth)
    {
        if(m_recordAudioCount++ > 3)
        {
            m_recordAudioCount = 0;
            m_linkFlag = false;
            m_isStartGetAudio = false;
            m_bleStateTimer->start(1000);
            on_toolButton_disconnect_clicked();
            ui->label->setText(fConnnectfailed);
            return;
        }
        signal_core_key_add_audio_start();
    }
    else
    {
        m_linkFlag = true;
        hp_setConnectOK();
    }
}

void Hp_Ble_Search::hp_setConnectOK()
{
    m_isStartGetAudio = false;
    ui->label->setText(fConnnectOK);
    m_bleDialog->setSingleButton();
    m_bleDialog->setDialogText(fConnnectOK);
    if(!isLinked)
    {
        isLinked = true;
        m_bleDialog->show();
//        signal_pc_sys_set_analog_audio(2);
    }
    m_bleStateTimer->start(1000);
}
