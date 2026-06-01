#ifndef HP_BLE_AT_H
#define HP_BLE_AT_H

#include  <QThread>
#include  <QObject>
#include  <QMap>
#include  <QDebug>
#include  "hi384_protocol.h"

#include  <stdio.h>
#include  <pthread.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include  <fcntl.h>
#include  <termios.h>
#include  <string.h>

typedef struct
{
    QString mac;
    QString name;
}BLE_DEVICE;

typedef struct
{
     int QS_ble;                       //蓝牙搜索结束的原因。 0-->开机自动搜索结束时（初始状态）。1--->设置为停止搜索时
     int IA_ble;                        //蓝牙断开的原因。        0-->初始状态
     int IB_ble;                        //蓝牙连接状态。 0--->未连接。 1--->连接成功
     int ble_try_connect;          //连接蓝牙种类。
     int CD_ble;                        //OKCD 断开连接， 0-->初始状态。1--->断开一个耳机连接另一个耳机
     int CC_ble;                        //连接新耳机。    0--->初始状态， 1--->连接新耳机命令

     int CV_ble;                        //删除指定地址。0--->耳机初始化后连接耳机时， 1--->点击删除配对列表

     bool ble_connect;                          //耳机恢复出厂设置时相关处理
     QString ble_mac_connecting;       //正在连接的蓝牙地址。 纯地址。删除指定蓝牙列表时用到

     bool ble_first_open;

}BLE_STATE;

//蓝牙自动搜索，连接相关结构体
typedef struct
{
    bool ble_connect;                         //自动搜索后连接蓝牙功能开启
    int ble_connect_i;                          //尝试自动连接的第几个蓝牙
    int ble_match_ok_i;                       //搜索 与已经匹配的蓝牙的数量
    QString ble_match_ok[8];              //搜索到的蓝牙和已经匹配到的蓝牙相对应的 地址集合(纯地址)

}BLE_AUTO_CONNECT;




class Hp_Ble_At : public QThread
{
    Q_OBJECT
public:
    explicit Hp_Ble_At(QObject *parent = 0);

    bool startSearchDevice();
    bool searchPairListInfo();
    bool startBle();
    bool stopBle();
    bool stop_ble_signal;           //关闭蓝牙

    QList<BLE_DEVICE> getPairedList();
    QList<BLE_DEVICE> getSearchedList();

    bool remove_all_headset();
    bool connect_headset(QString mac);

    bool send_cmd(QString str);

    QString ble_set_mac[20];			//搜索到的 蓝牙地址     QN+地址+蓝牙名字
    QString ble_set_name[20];	//搜索到的 蓝牙名字
    int ble_set_num;				//搜索到的 蓝牙数量
    bool str_OKCC;

//    QString ble_match_mac[8];           //已经匹配的 蓝牙地址
//    QString ble_match_name[8];          //已经匹配的蓝牙名字
    QStringList ble_match_mac;           //已经匹配的 蓝牙地址
    QStringList ble_match_name;          //已经匹配的蓝牙名字
    int ble_match_num;

    BLE_STATE ble_stete;
    BLE_AUTO_CONNECT ble_auto_connect;
    void ble_send_message_order( int type );        //根据传递的信息类型给蓝牙传递相应的消息
    void ble_auto_connect_init( );                          //启动自动连接蓝牙的初始化。 @1:开机 @2：连接成功某个蓝牙 @3：所有蓝牙都连接超时
    void ble_match_init();                                      //以匹配列表初始化
    void ble_match_init_clean();                         //清空连接的蓝牙列表

signals:
    void signal_search_end();
    void signal_sync_searched_list();
    void signal_sync_paired_list();
    void signal_sync_connect(BLE_DEVICE headset);
    void signal_sync_disconnect();


    void signal_old_connect(bool conn);

    void signal_add_string(QString str);

    void signal_ui_add_string(QString str, int position);	//界面添加蓝牙可配对列表

    void signal_ui_add_match_string(int count);	//界面添加蓝牙已配对列表
    void signal_ui_label_state(int state_ble);					       //界面上  (lable)  显示蓝牙处于的状态


protected:
    void run();
private:
    bool set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop);
    bool running;
    int ble_fd;

    void	ble_name_String(QString);
    QList<BLE_DEVICE> headset_searched_list;//<mac,name>
    QList<BLE_DEVICE> headset_paired_list;
};

#endif // HP_BLE_AT_H
