#ifndef HP_AUTOUPLOAD_H
#define HP_AUTOUPLOAD_H

#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include "hp_text_input.h"
#include "hp_wifi_search_dialog.h"
#include "hi384_protocol.h"
#include "hpxmlreader.h"
#include "hp_common_dialog_cancel.h"

namespace Ui {
class hp_AutoUpLoad;
}

class hp_AutoUpLoad : public QWidget
{
    Q_OBJECT
public:
    explicit hp_AutoUpLoad(QWidget *parent = 0);
    ~hp_AutoUpLoad();
    Hp_Wifi_search_Dialog *hp_Wifi_search_Dialog;//借用一下WIFI_search的弹窗
    hp_common_dialog_cancel *hp_Common_dialog_cancel;
    Hp_Text_Input hti;
    bool is4Gopen;//4G是否打开
    bool isClientOpen;//客户端是否
    QString fusername;
    QString fport;
    QString fconnectOk;
    QString fconnectfalse;
    QString f4GOpen;
    QString fIsInConnnect;//用于翻译
    QString fcancel;
    enum_AutoUpload_mode mymode;

    void set4Gstatu(bool checked);
    void setCloseClient();
    void SetSettingInit(QString IP_Account_password,int num);
    void GoBack();
    void hp_setDefine_S3x0(bool isSelect);
    void changeMode(int newmode);
signals:
    void signal_update_lcdoff_time(bool iskey);
    void signal_set_IP_Account_Password(QString ip,QString account,QString password,int errorMsg);
    void signal_Set_Unchecked();
    void signal_pc_sys_set_upload_target(ftp_para para);
    void siganl_pc_sys_set_serve_con(client_para para);
    void signal_pc_sys_cancel_autoupload(client_para para);
    void siganl_pc_sys_set_newserve_con(server_para para);//新的4G服务器传输
    void signal_pc_sys_newcancel_autoupload(server_para para);
    void signal_pc_sys_set_sevsend_break();
    void siganl_client_isOn(bool ischecked);
protected:
    virtual bool eventFilter(QObject *w, QEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *ev);
public slots:
    void slot_srvupload_cancel();
    void slot_pc_sys_set_sevsend_break(unsigned char return_value);
    void slot_pc_sys_cancel_autoupload(unsigned char return_value);
    void slot_close();
    void slot_sync_text();
    void slot_IsEmpty();
    void slot_pc_sys_set_upload_target(unsigned char return_value);
    void slot_common_dialog_cancel();
    void slot_pc_sys_set_serve_con(unsigned char return_value);
private slots:
    void on_toolButton_back_clicked();

    void on_checkBox_srvopen_clicked(bool checked);
private:
    Ui::hp_AutoUpLoad *ui;

    int NowEdit;        //目前编辑的框、1：IP、2：Account、3：password
    QString ServeIP;    //自动上传的服务器IP
    QString ServePort;   //自动上传的服务器端口
    QString ServeUsr;    //自动上传的服务器用户名
    QString ServePass;   //自动上传的服务器密码

    HpXmlReader hpxmlreader;

    void changeEvent(QEvent *e);
};

#endif // HP_AUTOUPLOAD_H
