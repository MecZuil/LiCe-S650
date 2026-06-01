#ifndef HP_BLE_SEARCH_H
#define HP_BLE_SEARCH_H

#include  <QWidget>
#include  <QDebug>
#include  <QMap>
#include  <stdio.h>
#include  <unistd.h>
#include  <QFile>
#include  <QList>
#include  <QTimer>
#include  <QListWidget>
#include  <QKeyEvent>
#include  <QEvent>
#include  <QMouseEvent>

#include  "hi384_protocol.h"
#include  "hp_ble_dialog.h"
#include  "hpxmlreader.h"

#define BLE_ToolButtonFalse  "QToolButton {border-image:url(:/res/res/mode_button_n.png); color:#7CA6C9;}\
                              QToolButton:pressed{border-image:url(:/res/res/mode_button_s.png);}"

#define BLE_ToolButtonTrue  "QToolButton {border-image:url(:/res/res/mode_button_s.png); color:#7CA6C9;}\
                              QToolButton:pressed{border-image:url(:/res/res/mode_button_s.png);}"

#define BLE_WidgetFalse  "QListWidget{border-top-color: rgb(19, 31, 200);\
                          border-right-color: rgb(255, 255, 0);border-bottom-color: rgb(255, 0, 0);\
                          border-left-color: rgb(255, 255, 127);}"

#define BLE_WidgetTrue   "QListWidget{border-top-color: rgb(19, 31, 200);\
                          border-right-color: rgb(255, 255, 0);border-bottom-color: rgb(255, 0, 0);\
                          border-left-color: rgb(255, 255, 127);border: 1px solid #64f9ff;}"


namespace Ui {
class Hp_Ble_Search;
}

class Hp_Ble_Search : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Ble_Search(QWidget *parent = 0);
    ~Hp_Ble_Search();
    QString fBleStart;
    QString fDisConnnect;//用于翻译
    QString fIsinSearch;//用于翻译
    QString fEndSearch;//用于翻译
    QString fIsInConnnect;//用于翻译
    QString fConnnectOK;//用于翻译
    QString fDisConnnectToDev;//用于翻译
    QString fConnnectfailed;//用于翻译
    QString fNoCard;//用于翻译
    QString fNoModul;//用于翻译
    QString fModulInit;//用于翻译
    QString fcancel;//用于翻译
    bool    isLinked;
    bool    m_isCloseBle;
public:
    void ble_on();//蓝牙开启
    void ble_off();
    void hp_define5_5(bool isDefine);
    void hp_setDefine_S3x0(bool isDefine);
    void hp_setConnectOK();
public slots:
    void slot_pc_sys_set_ble_function(unsigned char return_value);
    void slot_pc_sys_get_ble_info(unsigned char return_value, QString data);
    void slot_get_ble_state(unsigned char return_value, BleState bleState);

    void slot_core_key_add_audio_start(unsigned char return_value);
    void slot_core_key_add_audio_stop(unsigned char return_value, int audioLenth);
private slots:
    void on_listWidget_itemPressed(QListWidgetItem *item);

    void timer_core_get_ble_state();

    void send_close();

    void timer_pc_sys_set_ble_function();

    void add_listWidget();//添加一搜索到的蓝牙

    void add_listWidget_match();//添加已配对的蓝牙

    void slot_ble_match_delete(int type);

    void on_toolButton_search_clicked();

    void on_toolButton_disconnect_clicked();

    void on_toolButton_connect_clicked();

    void on_toolButton_back_clicked();

    void on_pushButton_clicked();

    //新蓝牙确认连接机制 6.21
    void slot_start_test_audio();
signals:
    void signal_pc_sys_set_analog_audio(int bleType);
    void signal_reset_ble_power();
    void signal_ble_set_close();
    void signal_pc_sys_set_ble_function(BleInfo bleInfo);
    void signal_pc_sys_get_ble_info(int msgType);
    void signal_core_get_ble_status();
    void signal_update_lcdoff_time(bool screen);
    //新蓝牙确认连接机制 6.21
    void signal_core_key_add_audio_start();
    void signal_core_key_add_audio_stop();
protected:
    void changeEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void keyReleaseEvent(QKeyEvent *ev);

private:
    Ui::Hp_Ble_Search      *ui;
    int                    m_currentItem;
    int                    m_currGetInfoType;//当前通过SYS_GET_BLE_INFO获取的ble信息类型1-扫描信息 2-已连接设备信息 3-配对设备信息
    int                    m_functionMode;   /*1-扫描 2-连接 3-断开连接 4-获取配对记录 5-清除配对记录*/
    bool                   m_isGetBleStatus;
    QString                m_macAddr;        //要连接的蓝牙mac地址
    QString                m_devName;
    QMap<QString, QString> m_scanAddrNameMap; //获取到的可连接的地址和名称的映射
    QMap<QString, QString> m_matchAddrNameMap;//获取到的已配对的地址和名称的映射
    QTimer*                m_timer;          //定时发送ble功能处理
    QTimer*                m_closeTimer;          //定时发送ble功能处理
    QTimer*                m_bleStateTimer;
    Hp_Ble_Dialog*         m_bleDialog;
    HpXmlReader            m_hpxmlreader;
    //新蓝牙确认连接机制 6.21
    bool m_isStartGetAudio;
    int m_recordAudioCount;
    bool m_linkFlag;//当原有连接方式连接成功的时候将这个设置为真
};

#endif // HP_BLE_SEARCH_H
