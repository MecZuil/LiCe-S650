#ifndef HP_DOWNLOAD_H
#define HP_DOWNLOAD_H

#include <QWidget>
#include <QDebug>
#include <QScrollBar>
#include <QStringList>
#include <QListWidgetItem>
#include <QList>
#include <QColor>
#include <QTimer>
#include "hi384_protocol.h"
#include "hp_autoupload_dialog.h"
#include "hpprotocolpkg.h"
#include "hpxmlreader.h"

namespace Ui {
class hp_DownLoad;
}

class hp_download : public QWidget
{
    Q_OBJECT
public:
    explicit hp_download(QWidget *parent = 0);
    ~hp_download();



    QString fonload;
    QString ffailload;
    QString ffaildownload;
    QString fokdownload;
    QString fnoSD;
    QString fselectupload;
    QString ftask;
    QString fnormal;

    QStringList filelist;
    bool sd_insert;
    bool go_up;//为解决  自动下载界面，进入二级目录时，点击返回至第一级目录时，未显示选中加载时的目录，而是显示选中第一级最上方的目录  问题之前，用于判断是否按下返回上一级按钮
    QString go_up_name;//为解决  自动下载界面，进入二级目录时，点击返回至第一级目录时，未显示选中加载时的目录，而是显示选中第一级最上方的目录  问题之前，用于记录上一级文件名
    QTimer *dialog_timer;//弹窗定时器，用于延时弹窗
    QTimer *dialog_wait_timer;//弹窗出现后定时器，用于警告连接已断开
    Hp_Autoupload_Dialog *hp_autoupload_dialog;//借用一下WIFI_search的弹窗
    void Start_download();
    void download_shearch(QString GetWho,bool fatherOrchild);//true为获取文件夹，false为获取文件
    QString GetFilename();
    bool setbtgoDown();
    bool setbtgetFile();
    bool setbtgoup();
    void setBtstatus();
    void hp_setDefine_S3x0(bool isDefine);
signals:
    void signal_pc_sys_set_filequery(ftp_para para);
    void signal_pc_sys_set_download(ftp_para para);
public slots:
    void slot_pc_sys_set_filequery(unsigned char return_value,QString name,char *data,int returnlen);
    void slot_pc_sys_set_download(unsigned char return_value);
    void slot_set_IP_Account_Password(QString ip,QString account,QString password,int errorMsg);
    void slot_dialog_timer_timeout();
    void slot_dialog_wait_timer_timeout();
private slots:
    void on_toolButton_back_clicked();

    void on_wifi_Flush_clicked();

    void on_get_file_clicked();

    void on_listWidget_father_currentRowChanged(int currentRow);

    void on_listWidget_father_itemClicked(QListWidgetItem *item);

    void on_listWidget_child_itemClicked(QListWidgetItem *item);

    void on_godown_clicked();

    void on_goup_clicked();

    void on_listWidget_child_currentRowChanged(int currentRow);

private:
    Ui::hp_DownLoad *ui;
    void changeEvent(QEvent *e);

    bool fatherorchild;//判断目前获取的是目录还是文件
    bool isInchilddir;//判断目前是否处于获取子目录状态
    bool isInfatherfile;//判断目前是否处于获取主文件状态
//    QString NowFile;

    HpXmlReader hpxmlreader;

    QString IP;         //自动上传的IP
    QString Account;    //自动上传的账号
    QString Password;   //自动上传的密码
};

#endif // HP_DOWNLOAD_H
