#ifndef HP_WIFI_SEARCH_H
#define HP_WIFI_SEARCH_H

#include <QWidget>
#include <QString>
#include <QEvent>
#include <QKeyEvent>
#include <string.h>
#include <QTimer>
#include <QScrollBar>
#include "hp_text_input.h"
#include "hi384_protocol.h"
#include "hp_wifi_search_dialog.h"
#include "hpxmlreader.h"

namespace Ui {
class Hp_Wifi_Search;
}

class Hp_Wifi_Search : public QWidget
{
    Q_OBJECT
public:
    explicit Hp_Wifi_Search(QWidget *parent = 0);
    ~Hp_Wifi_Search();

    QString fOK;
    QString fWaitSearch;
    QString fConnectOK;
    QString fHasNoUsedNet;
    QString fWrongLenPassword;
    QString fConnectIsBreak;
    QString fPasswordError;
    QString fConOutTime;

    bool IsOnClicked;
    Hp_Wifi_search_Dialog *hp_Wifi_search_Dialog;
    void On_set_click_Init();
    QTimer *GetStatus;
    Hp_Text_Input hti;
    void GoBack();
    void hp_setDefine_S3x0(bool isSelect);
    void hp_setUiInit(bool isServer);
signals:
    void signal_update_lcdoff_time(bool iskey);
    void signal_PC_SYS_GET_ESSID();
    void signal_PC_SYS_SET_WIFI_STA(ap_para ret);
    void signal_CORE_GET_WIFI_STA_STATUS();
    void signal_pc_sys_set_wifi_switch(int ret);
    void signal_SetMainWifiDisconnect();
    void signal_SetIsWifiSearch(bool checked);
    void signal_pc_sys_set_local_servrer(int isOpen);
    void signal_pc_sys_set_dev_active_search();
    void signal_key_dev_client_encode_start();
    void signal_key_dev_client_encode_stop();
    void signal_pc_sys_set_dev_client(ComDevClientInfo info);
protected:
    virtual bool eventFilter(QObject *w, QEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void changeEvent(QEvent *e);
public slots:
    //void slot_Set_label_Password_text(QString);
    void slot_Time_out();
    void slot_sync_text();
    void slot_SetDisConnect();
    void slot_PC_SYS_GET_ESSID(unsigned char return_value,QString name);
    void slot_PC_SYS_SET_WIFI_STA(unsigned char return_value);
    void slot_CORE_GET_WIFI_STA_STATUS(unsigned char return_value,int wifi_sta_status);
    void slot_pc_sys_set_dev_active_search(unsigned char return_value, QStringList dev_info);
    void slot_pc_sys_set_dev_client(unsigned char return_value);
private slots:
    void on_toolButton_back_clicked();

    void on_listWidget_Wifimode_currentRowChanged(int currentRow);

    void on_listWidget_WifiNum_currentRowChanged(int currentRow);

    void on_wifi_Flush_clicked();

    void on_checkBox_wifi_clicked(bool checked);

    void on_equip_Flush_2_clicked();

    void on_checkBox_equipment_clicked(bool checked);

    void on_listWidget_equip_currentRowChanged(int currentRow);

    void on_checkBox_getFlow_clicked(bool checked);

    void on_checkBox_localServer_clicked(bool checked);

private:
    Ui::Hp_Wifi_Search *ui;
    int  listwidget_type;                       //下拉框的状态，0--->没有下拉框打开。 1--->第一个下拉框打开。以此类推
    bool isSearchFinished;
    bool isDefineS3x0;
    bool isFlushEuqip;
    bool isSelectServer;
    HpXmlReader hpxmlreader;

    ap_para nowConnect;//上一次存储的连接值
    int timezon;//定时器总计时
    int timeGet;//是否需要弹窗，是否处于连接计时状态,0代表不需要弹窗，1代表检查是否连接成功，2代表是否在监视是否断开,3表示主动断开

    void listwidget_drop_manage_Wifimode(bool type);

    void listwidget_drop_manage_WifiNum(bool type);

    void listwidget_drop_manage_equipNum(bool type);
};

#endif // HP_WIFI_SEARCH_H
