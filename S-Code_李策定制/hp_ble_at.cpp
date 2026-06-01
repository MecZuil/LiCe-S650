#include  "hp_ble_at.h"

Hp_Ble_At::Hp_Ble_At(QObject *parent) : QThread(parent)
{
    running = false;
    ble_set_num= 0;					//2018.2.9
    ble_match_num = 0;

    ble_stete.IA_ble = 0;
    ble_stete.QS_ble = 0;
    ble_stete.IB_ble = 0;
    ble_stete.CD_ble = 0;
    ble_stete.CC_ble = 0;
    ble_stete.CV_ble = 0;

    ble_stete.ble_connect = false;
    ble_stete.ble_first_open =false;
    ble_stete.ble_mac_connecting = "";
    stop_ble_signal =false;

    ble_auto_connect_init();

//    for(int i=0; i<sizeof(ble_match_mac)/sizeof(ble_match_mac[0]); i++)
//    {
//        ble_match_mac[i]	="";
//        ble_match_name[i]="";
//    }

}

bool Hp_Ble_At::startSearchDevice()
{
    char *cmd = "AT#IQ\r\n";
    int ret;
    if(ble_fd < 0)
    {
        qDebug("ble device not opened");
        return false;
    }

    headset_searched_list.clear();
    ret = write(ble_fd,cmd,strlen(cmd));
    if(ret != strlen(cmd))
    {
        qDebug("write cmd failed");
        return false;
    }
    return true;
}

bool Hp_Ble_At::searchPairListInfo()
{
    char *cmd = "AT#PL\r\n";
    int ret;
    if(ble_fd < 0)
    {
        qDebug("ble device not opened");
        return false;
    }
    headset_paired_list.clear();

    ret = write(ble_fd,cmd,strlen(cmd));
    if(ret != strlen(cmd))
    {
        qDebug("write cmd failed");
        return false;
    }
    return true;
}

bool Hp_Ble_At::remove_all_headset()
{
    char *cmd = "AT#DA\r\n";
    int ret;
    if(ble_fd < 0)
    {
        qDebug("ble device not opened");
        return false;
    }
    headset_paired_list.clear();

    ret = write(ble_fd,cmd,strlen(cmd));
    if(ret != strlen(cmd))
    {
        qDebug("write cmd failed");
        return false;
    }

    searchPairListInfo();

    return true;
}

bool Hp_Ble_At::connect_headset(QString mac)           //µã»÷ Á¬½Ó À¶ÑÀ¶ú»úµÄÊ±ºòµ÷ÓÃ¡£
{												//Ó¦¸ÃÊÇÐ£ÑéÍ·¡£  这里前面删除了一个反斜杠  不知道会不会有影响，待学习！！！
                                                //搜qt三个、四个反斜杠？？？
    //    char *cmd = "AT#CC";					//Á¬½ÓÉè±¸Ö¸Áî
    char cmd[20] = {'\0'};
    int ret;
    if(ble_fd < 0)
    {
        qDebug("ble device not opened");
        return false;
    }

    QByteArray ba = mac.toLatin1();
    memcpy(cmd,"AT#CC",5);
    memcpy(cmd+5,ba.data(),12);
    memcpy(cmd+17,"\r\n",strlen("\r\n"));
    cmd[19] = '\0';


    ret = write(ble_fd,cmd,strlen(cmd));	//Ó¦¸ÃÊÇÐ´Êý¾Ýµ½ble_fdÖÐ
    if(ret != strlen(cmd))
    {
        qDebug("write cmd failed");
        return false;
    }
    return true;
}

bool Hp_Ble_At::send_cmd(QString str)
{
    qDebug()<<"send_cmd:"<<str;
    char cmd[20] = {'\0'};
    int ret;
    if(ble_fd < 0)
    {
        qDebug("ble device not opened");
        return false;
    }

    if(str.contains("AT#CC"))                       //连接耳机时，存储连接耳机的地址
    {
        ble_stete.ble_mac_connecting = str.mid(5,str.length()-5);;
    }

    QByteArray ba = str.toLatin1();
        ba.append("\r\n");				//添加字符串  /r/n;
    //qDebug()<<"send_cmd  --- 2:"<<str<<str.length();
    ret = write(ble_fd,ba.data(),ba.length());
    if(ret != strlen(ba.data()))
    {
        qDebug("write cmd failed");
        return false;
    }
    return true;
}



bool Hp_Ble_At::startBle()
{
    ble_fd = open( "/dev/ttymxc2", O_RDWR | O_NOCTTY);
    if (ble_fd == -1)
    {
        qDebug("open ble device error");
        return false;
    }
    qDebug("open ble device success!!");

    if (!set_opt(ble_fd, 115200, 8, 'N', 1))
    {
        qDebug("SET  ble device tty error!!");
        close(ble_fd);
        return false;
    }
    running = true;
    start();
    return true;
}
/*
ble on init ble
cmd=5 para=1
audiopower===on
ble will on
SECCUSS OPEN -- >  28
open ble device success!!
set done!
send_cmd: "AT#QD" 5
send_cmd  --- 2: "AT#QD" 5
--------IS_RUN---------
--------IS_RUN--------- 1  +  28
*/
bool Hp_Ble_At::stopBle()
{
    running = false;
    return true;
}


QList<BLE_DEVICE> Hp_Ble_At::getPairedList()
{
    return headset_paired_list;
}

QList<BLE_DEVICE> Hp_Ble_At::getSearchedList()
{
    return headset_searched_list;
}

void Hp_Ble_At::run()
{
    char r_buf[1024];
    int index = 0;
    while(running && ble_fd > 0)
    {
        char ch;
        int ret = 0;
        int cnt = 0;
        memset(r_buf,0,1024);
        bool TIMEROUT = false;
        while(1)
        {
            ret = read(ble_fd,&ch,1);
            if(ret != 1)
            {
                qDebug("time out");
                TIMEROUT = true;
                break;
            }

            if(ch == '\n')
                break;
            if(ch != '\r')
            {
                r_buf[cnt++] = ch;//这里是内存泄露导致的卡住,像这种，往数组里面填值的，一定要限制范围！！！
                if(cnt > 1023)
                {
                    break;
                }
//                qDebug() << "--------IS_RUN--------- " << ble_fd << " ; " << (int)ch;
//                qDebug() << "--------IS_RUN--------- " << ble_fd << " ; " << ch;  //224 252 0 28
            }
//                if(ch <= 127)        //我后面加的，为了防止打开蓝牙后 死掉，因为接收的字符有些是错误的  基本上都接收到这些字符：//224 252 0 28
//                {
//                    //sleep(1000);
//                    //r_buf[cnt++] = ch;
//                    qDebug() << "--------IS_RUN--------- " << ble_fd << " ; " << (int)ch;
//                    qDebug() << "--------IS_RUN--------- " << ble_fd << " ; " << ch;  //224 252 0 28
//                }


        }
        if(TIMEROUT)
            continue;

        r_buf[cnt] = '\0';
        QString str = QLatin1String(r_buf);
        qDebug()<<"----------------- information : "<<str;
//        signal_add_string(str);                 //对应槽没有做事情

/*
         if(str.contains("IS"))             //蓝牙初始化成功
         {
            send_cmd("AT#QD");
         }
*/
//2018.2.9
//        qDebug()<<"---------------1-- information : "<<str;
    if(str.contains("QD"))      //OKQD  QD+地址+蓝牙名字
    {
        qDebug() << "information Has QD : Has Find Add And Name Record";
         if(str.length()>4)
         {
//             qDebug() << "str.contains(\"QD\") " << 1;
             QString str_2;
//             qDebug() << "str.contains(\"QD\") " << 11 << str.length();
             str_2=str.mid(14,str.length()-14);
//             qDebug() << "str.contains(\"QD\") " << 12 << str_2 << ble_match_num;
             ble_match_mac.append(str);                 //蓝牙地址及信息
//             qDebug() << "str.contains(\"QD\") " << 13 << ble_match_mac.count();
//             qDebug() << "str.contains(\"QD\") " << 13 << ble_match_name.count();
             ble_match_name.append(str_2);
//             qDebug() << "str.contains(\"QD\") " << 14;
             ble_match_num++;
//             qDebug() << "str.contains(\"QD\") " << 24;
         }else              //OKQD
         {
//             qDebug() << "str.contains(\"QD\") " << 3;
             signal_ui_add_match_string(ble_match_num);
//             qDebug() << "str.contains(\"QD\") " << 4;
             if( 0== ble_stete.IB_ble)
             {
                 qDebug() << "Ble Send CMD 13 : AT#QP  -- >> Please Search";
                 send_cmd("AT#QP");
             }
//             qDebug() << "str.contains(\"QD\") " << 5;
         }
         ble_stete.ble_first_open =false;
//         qDebug() << "str.contains(\"QD\") " << 6;

    }

//    qDebug()<<"----------------- information : "<<2;
    if(str.contains("QC"))			//搜索蓝牙设备，搜索到了蓝牙设备 QC+地址
    {
        qDebug() << "information Has QC : Has Find Add";
         if(str.length()>4)
            {
                    bool ble_exit;
                    ble_exit =false;

                    for(int i=0; i<ble_set_num;i++)
                    {
                        if(ble_set_mac[i].mid(2,12) == str.mid(2,12))                 //判断蓝牙设备数组中是否已经存在该蓝牙
                        {
                            ble_exit =true;
                            break;
                        }
                    }
                    if(ble_exit == false)
                    {   //发送搜索指定蓝牙设备
                        qDebug() << "Ble Send CMD 14 : AT#QN  -- >> Please Search I Want to Search";
                        QString str_QN = "AT#QN";
                        str_QN = str_QN.append(str.mid(2,str.length()-2));
                        send_cmd(str_QN);
                    }
            }
       }

//    qDebug()<<"----------------- information : "<<3;
    if(str.contains("QN"))	//搜索到蓝牙设备  OKQN  QN+地址+蓝牙名字
    {
        qDebug() << "information Has QN : Has Find Add And Name";
            if(str.length()>4)
            {
                    bool  ble_noexit;
                    ble_noexit =false;
                    for(int j=0; j<sizeof(ble_set_mac)/sizeof(ble_set_mac[0]); j++) //判断蓝牙是否已经记录到数组中
                    {
                        if(str  != ble_set_mac[j])
                        {
                            ble_noexit = true;
                        }
                        else{
                            ble_noexit = false;
                            break;
                        }
                    }
                    qDebug() << "BLE exit -- >"<< ble_noexit << " ; " << ble_set_num;
                    if(ble_noexit)										//若蓝牙设备未记录到数组中，将其记录到数组中
                    {
                      if( ble_set_num <= 19)          //如果ble_set_num大于19.  就不再添加数组元素， 数组最大20
                      {
                          QString str_2;
                          str_2=str.mid(14,str.length()-14);
                          ble_set_mac[ble_set_num] = str;                 //蓝牙地址及信息
                          ble_set_name[ble_set_num]=str_2;
                          qDebug() << "str_2 -- >"<< str_2;
                          ble_name_String(str_2);                               //添加蓝牙名字到界面
                          ble_set_num++;
                      }
                   }
                   //若在初始数组中存在，就不显示？？？
            }
       }
//    qDebug() << "ble--------------------------------" << 1;

    if(str.contains("CONNECT"))     //信号，HFP_CONNECT。耳机恢复出厂设置后，需要删除配对列表。再连接
        {
            //qDebug() << "information Has CONNECT : Delete Record";
            ble_stete.ble_connect = true;
             //删除指定列表
            //qDebug() << "Ble Send CMD 15 : AT#CV  -- >> Delete Connect Record";
            QString str_CV = "AT#CV";
            str_CV= str_CV.append(ble_stete.ble_mac_connecting);
            send_cmd(str_CV);
        }
//    qDebug() << "ble--------------------------------" << 2;
    if(str.contains("CV"))     //删除列表后处理
    {
        //qDebug() << "information Has CV : Had Deleted Record Operate";
        /*
        if(ble_stete.CV_ble == 1)
        {
            send_cmd("AT#QD");
            ble_stete.CV_ble=0;
        }else
        {
            //重新获取
            signal_ui_label_state(6);
        }
        */
        signal_ui_label_state(6);

        }
//    qDebug() << "ble--------------------------------" << 3;

    if(str.contains("OKCC"))
    {
        //qDebug() << "information Has OKCC : Connect New Dev";
        str_OKCC = true;
        ble_stete.CC_ble = 1;
    }
//    qDebug() << "ble--------------------------------" << 4;
    if(str.contains("IV"))	//等待连接，进行匹配
        {
        //qDebug() << "information Has IV : IsInMatch";
/*
            if(ble_stete.ble_connect)
            {
                str_OKCC = false;
                QString str_IV = "AT#Cp11";
                send_cmd(str_IV);                       //进行匹配
            };
*/
            if(str_OKCC)
            {
                //qDebug() << "Ble Send CMD 16 : AT#Cp11  -- >> IsInMatch";
                str_OKCC = false;
                QString str_IV = "AT#Cp11";
                send_cmd(str_IV);                       //进行匹配
            }

        }
        if(str.contains("OKCD"))
        {
            //qDebug() << "information Has OKCD : Sould Break";
            ble_stete.CD_ble =1;
        }
        if(str.contains("IB"))
        {
            //qDebug() << "information Has IB : Connect OK";
            ble_auto_connect_init();

            ble_stete.ble_connect = false;
            ble_stete.IB_ble = 1;
            ble_stete.CC_ble = 0;
            signal_ui_label_state(4);
        }
        else if(str.contains("IA"))     //蓝牙断开连接处理
        {
            //qDebug() << "information Has IA : Break Operate >> Breakflag : " << ble_stete.CD_ble << " ; Connectflag : " << ble_stete.CC_ble;
                if(stop_ble_signal == true)
                {
                    stopBle();
//                    system("./devtest 5 0");
                    //system("./devtest 6 0");
                    return;
                }

                ble_stete.IB_ble = 0;
                if( ble_stete.CD_ble == 1 && ble_stete.CC_ble ==1)  //此时断开一个耳机，连接另一个耳机失败
                {
                    ble_stete.CD_ble =0;
                    ble_stete.CC_ble =0;
                    signal_ui_label_state(7);
                    //qDebug() << "Ble Send CMD 17 : AT#QP  -- >> Please Search";
                    send_cmd("AT#QP");
                }else
                {
 //                   ble_stete.CD_ble =0;
                    ble_stete.CC_ble =0;
                    if(ble_stete.ble_first_open == true)
                    {
                        //qDebug() << "Ble Send CMD 18 : AT#QD  -- >> Init";
                        send_cmd("AT#QD");
                    }else
                    {
                        signal_ui_label_state(5);
                        if(ble_auto_connect.ble_connect == true)        //表示蓝牙自动连接时的断开
                        {
                            ble_send_message_order(1);
                        }else
                        {
                            if( ble_stete.QS_ble == 1)              //连接新耳机时断开耳机
                            {
                                ble_stete.QS_ble =0;
                            }else{
                                //qDebug() << "Ble Send CMD 19 : AT#QP  -- >> Please Search";
                                send_cmd("AT#QP");        //断开连接后继续搜索
                            }
                        }
                    }
                    ble_stete.QS_ble =0;
                }
        }
//        qDebug() << "ble--------------------------------" << 5;
//音频
       if(str.contains("MC"))
        {
           //qDebug() << "information Has MC : Init";
           //此时蓝牙将新的耳机添加到蓝牙列表中
           ble_stete.IB_ble = 1;
           ble_match_init( );
           /*
           for(int i=0; i<ble_match_num;i++)
           {
               ble_match_mac[i] = "";
               ble_match_name[i] = "";
           }
           ble_match_num = 0;
           */
           //qDebug() << "Ble Send CMD 20 : AT#QD  -- >> Init";
           send_cmd("AT#QD");
        }
        else if(str.contains("MD"))
        {
        }

       if(str.contains("QP"))
       {
           //qDebug() << "information Has QP : Break";
                ble_stete.CD_ble =0;
                 signal_ui_label_state(1);
       }
       if(str.contains("QS"))
        {
           //qDebug() << "information Has QS : Auto Connect";
   //正常情况下搜索结束
           if(0 ==  ble_stete.QS_ble)
           {
               if( 0== ble_match_num || 0==ble_set_num)     //已配对列表 或者可配对列表为0
               {
                   //qDebug() << "Ble Send CMD 21 : AT#QP  -- >> Please Search";
                   send_cmd("AT#QP");
               }else
               {
                    for(int j=0;j<ble_set_num;j++)
                    {
                        for(int i=0; i<ble_match_num; i++)
                        {
                            QString ble_match_i = ble_match_mac[i].mid(2,12);
                            QString ble_set_j = ble_set_mac[j].mid(2,12);
                            if( ble_match_i == ble_set_j)          //匹配成功.储存到 相应数组中
                            {
                                ble_auto_connect.ble_connect =true;
                                ble_auto_connect.ble_match_ok[ble_auto_connect.ble_match_ok_i] = ble_set_j;
                                if( ble_auto_connect.ble_match_ok_i<8)
                                {
                                    ble_auto_connect.ble_match_ok_i++;
                                }

                            }
                        }
                    }
                    ble_send_message_order(1);
                 }
            }
       }

//       qDebug() << "ble--------------------------------" << 6;
       /************************************以前的**********************************/
        if(str.contains("OKPL"))
        {
            for(int i=0;i<headset_paired_list.count();i++)
            {
                BLE_DEVICE bd = headset_paired_list.at(i);
            }
            continue;
        }

        if(str.contains("PL"))
        {
            QStringList str_list;
            str_list = str.split(QRegExp(","));

            if(str_list.count() == 4)
            {

                BLE_DEVICE bd;
                bd.mac = str_list.at(2);
                bd.name = str_list.at(3);

                headset_paired_list.append(bd);
                signal_sync_paired_list();
            }
            continue;

        }

        if(str.contains("SR"))
        {
            QStringList str_list;
            str_list = str.split(QRegExp(","));

            if(str_list.count() == 3)
            {
                BLE_DEVICE bd;
                bd.mac = str_list.at(1);
                bd.name = str_list.at(2);

                headset_searched_list.append(bd);
                signal_sync_searched_list();
            }
            continue;
        }

        if(str.contains("RM"))
        {
            QStringList str_list;
            str_list = str.split(QRegExp(","));

            if(str_list.count() == 4)
            {
                BLE_DEVICE bd;
                bd.mac = str_list.at(2);
                bd.name = str_list.at(3);
                signal_sync_connect(bd);
            }
            continue;
        }

        if(str.contains("I2,0"))
        {
            signal_sync_disconnect();
            continue;
        }

        if(str.contains("SE"))
        {
            signal_search_end();
            continue;
        }

        if(str.contains("OKDA"))
        {
            headset_paired_list.clear();
            signal_sync_paired_list();
            continue;
        }

//2018.2.8

//        qDebug() << "ble--------------------------------" << 8;

    }

//    qDebug() << "ble--------------------------------" << 7;
    close(ble_fd);
}



bool Hp_Ble_At::set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop)
{
    struct termios newtio,oldtio;
    if  ( tcgetattr( fd,&oldtio)  !=  0) {
        perror("SetupSerial 1");
        return false;
    }
    bzero( &newtio, sizeof( newtio ) );
    newtio.c_cflag  |=  CLOCAL | CREAD; //CLOCAL:å¿½ç¥modemæ§å¶çº¿  CREADï¼æå¼æ¥åè
    newtio.c_cflag &= ~CSIZE; //å­ç¬¦é¿åº¦æ©ç ãåå¼ä¸ºï¼CS5ï¼CS6ï¼CS7æCS8

    newtio.c_lflag  &= ~(ICANON | ECHO | ECHOE | ISIG);  /*Input*/
    newtio.c_oflag  &= ~OPOST;   /*Output*/

    switch( nBits )
    {
    case 7:
        newtio.c_cflag |= CS7;
        break;
    case 8:
        newtio.c_cflag |= CS8;
        break;
    }

    switch( nEvent )
    {
    case 'O':
        newtio.c_cflag |= PARENB; //åè®¸è¾åºäº§çå¥å¶ä¿¡æ¯ä»¥åè¾å¥å°å¥å¶æ ¡éª
        newtio.c_cflag |= PARODD;  //è¾å¥åè¾åºæ¯å¥åæ ¡éª
        newtio.c_iflag |= (INPCK | ISTRIP); // INPACK:å¯ç¨è¾å¥å¥å¶æ£æµï¼ISTRIPï¼å»æç¬¬å«ä½
        break;
    case 'E':
        newtio.c_iflag |= (INPCK | ISTRIP);
        newtio.c_cflag |= PARENB;
        newtio.c_cflag &= ~PARODD;
        break;
    case 'N':
        newtio.c_cflag &= ~PARENB;
        break;
    }

    switch( nSpeed )
    {
    case 2400:
        cfsetispeed(&newtio, B2400);
        cfsetospeed(&newtio, B2400);
        break;
    case 4800:
        cfsetispeed(&newtio, B4800);
        cfsetospeed(&newtio, B4800);
        break;
    case 9600:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
    case 115200:
        cfsetispeed(&newtio, B115200);
        cfsetospeed(&newtio, B115200);
        break;
    case 460800:
        cfsetispeed(&newtio, B460800);
        cfsetospeed(&newtio, B460800);
        break;
    default:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
    }

    if( nStop == 1 )
        newtio.c_cflag &=  ~CSTOPB; //CSTOPB:è®¾ç½®ä¸¤ä¸ªåæ­¢ä½ï¼èä¸æ¯ä¸ä¸ª
    else if ( nStop == 2 )
        newtio.c_cflag |=  CSTOPB;

    newtio.c_cc[VTIME]  = 0; //VTIME:écannoicalæ¨¡å¼è¯»æ¶çå»¶æ¶ï¼ä»¥ååä¹ä¸ç§ä½åä½
    newtio.c_cc[VMIN] = 1; //VMIN:écanonicalæ¨¡å¼è¯»å°æå°å­ç¬¦æ°
    tcflush(fd,TCIFLUSH); // æ¹åå¨ææåå¥ fd å¼ç¨çå¯¹è±¡çè¾åºé½è¢«ä¼ è¾åçæï¼ææå·²æ¥åä½æªè¯»å¥çè¾å¥é½å¨æ¹ååçåä¸¢å¼ã
    if((tcsetattr(fd,TCSANOW,&newtio))!=0) //TCSANOW:æ¹åç«å³åç
    {
        perror("com set error");
        return false;
    }
    printf("set done!\n\r");
    return true;
}

void Hp_Ble_At::ble_name_String(QString blu_name)
{
     signal_ui_add_string(blu_name,0);
}

void Hp_Ble_At::ble_send_message_order(int type)
{
//    qDebug( )<<"   ble_send_message_order : message_type = "<<type;
    switch(type)
    {
    case 0:
        break;
    case 1:                     //自动连接的相关处理
        if( ble_auto_connect.ble_connect )          //开始处理
        {
            if( ble_auto_connect.ble_connect_i < ble_auto_connect.ble_match_ok_i)   //从第0个元素开始尝试连接。如果连接失败就继续.全部失败后重新搜索
            {
                //qDebug() << "Ble Send CMD 22 : AT#CC  -- >> IsInConnect";
                QString str_CC = "AT#CC";
                str_CC = str_CC.append(ble_auto_connect.ble_match_ok[ble_auto_connect.ble_connect_i]);
                ble_auto_connect.ble_connect_i ++;
                send_cmd(str_CC);
            }else
            {
                //qDebug() << "Ble Send CMD 23 : AT#CC  -- >> Please Search";
                ble_auto_connect_init();
                send_cmd("AT#QP");
            }
        }else
        {
            //qDebug() << "Ble Send CMD 24 : AT#QP  -- >> Please Search";
            //都不匹配，重新搜索
            send_cmd("AT#QP");
        }


        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }

}

void Hp_Ble_At::ble_auto_connect_init()
{
    ble_auto_connect.ble_connect = false;
    ble_auto_connect.ble_connect_i = 0;
    ble_auto_connect.ble_match_ok_i = 0;
    for(int i=0; i<sizeof(ble_auto_connect.ble_match_ok)/sizeof(ble_auto_connect.ble_match_ok[0]);i++)
    {
        ble_auto_connect.ble_match_ok[i] = "";
    }

}

void Hp_Ble_At::ble_match_init()
{

    for(int i=0;i < ble_match_num;i++)
    {
        ble_match_mac [i] = "";
        ble_match_name [i] = "";
    }
    ble_match_num = 0;


}

void Hp_Ble_At::ble_match_init_clean()
{
    ble_match_mac.clear();
    ble_match_name.clear();
    ble_match_num = 0;
    char *cmd = "AT#CV\r\n";
    int ret;
    if(ble_fd < 0)
    {
        qDebug("ble device not opened");
        return ;
    }
    headset_paired_list.clear();
    ret = write(ble_fd,cmd,strlen(cmd));
    if(ret != strlen(cmd))
    {
        qDebug("write cmd failed");
        return ;
    }
}









