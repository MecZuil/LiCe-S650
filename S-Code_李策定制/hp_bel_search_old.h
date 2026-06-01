#ifndef HP_BEL_SEARCH_OLD_H
#define HP_BEL_SEARCH_OLD_H

#include  <QWidget>
#include  <QDebug>
#include  <QFile>
#include  <QKeyEvent>

#include  <QTimer>
#include  <QListWidget>
#include  "hp_ble_at.h"
#include  "hp_ble_dialog.h"
#include  "hpxmlreader.h"

namespace Ui {
class Hp_Bel_Search_Old;
}

class Hp_Bel_Search_Old : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Bel_Search_Old(QWidget *parent = nullptr);
    ~Hp_Bel_Search_Old();
    void ble_on();
    void ble_off();
    bool get_conn_status();

    bool flush_ui_device();                     //刷新界面的可用设备
    void hp_setDefine_S3x0(bool isSelect);


    QString fDisConnnect;//用于翻译
    QString fIsinSearch;//用于翻译
    QString fEndSearch;//用于翻译
    QString fIsInConnnect;//用于翻译
    QString fConnnectOK;//用于翻译
    QString fSwitching;//用于翻译
    QString fSwitchingFailure;//用于翻译
    QString fDisConnnectToDev;//用于翻译
    QString fConnnectfailed;//用于翻译
    QString fUsbisInsert;
    QString fNoCard;
    QString fNoModul;
    QString fModulInit;
    QString fcancel;
public slots:
    void ble_off_close();
signals:
    void signal_update_lcdoff_time(bool iskey);
    void signal_headset_status(bool f);
    void signal_ble_dialog_type(int type);         //传递信号，ble_dialog界面显示的类型
private slots:
    void on_toolButton_search_released();
    void on_toolButton_connect_released();
    void on_toolButton_disconnect_released();


    void slot_search_end();
    void slot_sync_searched_list();
    void slot_sync_paired_list();
    void slot_sync_connect(BLE_DEVICE headset);
    void slot_sync_disconnect();

    void slot_old_connect(bool conn);
    void slot_ui_label_state(int state_ble );


    void slot_add_string(QString str);
    void slot_ui_add_string(QString str, int position);                 //界面添加蓝牙可配对列表
    void slot_ui_add_match_string(int count);                           //界面添加蓝牙已配对列表

    void slot_ble_match_delete(int signal_type);                                                   //删除匹配的蓝牙槽

    void on_listWidget_clicked(const QModelIndex &index);

    void on_listWidget_activated(const QModelIndex &index);

    void on_pushButton_released();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_listWidget_itemPressed(QListWidgetItem *item);

    void on_listWidget_match_itemClicked(QListWidgetItem *item);
    void on_toolButton_back_clicked();

private:
    Ui::Hp_Bel_Search_Old *ui;
    Hp_Ble_At hba;
    Hp_Ble_Dialog hp_ble_dialog;

    bool connect_status;
    int selectRow;

    HpXmlReader hpxmlreader;

//2018.2.10
    bool checked_clicked;
    int listWidget_item_old;
    int listWidget_item_new;

    bool isInConnect;//标志着是否在连接状态中，用于有时候在连接时出现断开连接的情况

    int ble_dis_type;             //蓝牙断开连接的类别  1->搜索按钮使其断开。 2->连接另一个耳机时断开

    void changeEvent(QEvent *e);
};

#endif // HP_BEL_SEARCH_OLD_H
