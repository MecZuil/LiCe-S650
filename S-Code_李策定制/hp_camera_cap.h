#ifndef HP_CAMERA_CAP_H
#define HP_CAMERA_CAP_H

#include  <QWidget>
#include  <QTimer>
#include  "hp_text_input.h"
#include  "hi384_protocol.h"
#include  "hpxmlreader.h"
#include  "hpdomainapi.h"
#include <unistd.h>

#define SAVE_IMAGE_PATH             "/run/media/mmcblk2p1/DCIM/"
#include "../TaskPkg/hp_statement.h"
#include "../TaskPkg/hp_taskpkg.h"

namespace Ui {
class Hp_Camera_Cap;
}

class Hp_Camera_Cap : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Camera_Cap(QWidget *parent = 0);
    ~Hp_Camera_Cap();
    void setText(QString str);
    void voice_enable(bool checked);
    void init_cap();
    void ModeEnable(int mode);
    bool VoiceStatus;
    bool cancelflag; //
    bool cap_state;
    bool isErrPmsPhoto;
    bool m_isZoomSave;
    bool isSuperImage;     //sr模式是否打开
    bool sr_baocunflag;
    bool sr_canceflag;
    bool autoUpdateIsChecked;       //标识自动上传是否被选中
    bool autoUpdateWhoEmit;         //用于判断是否需要触发自动上传，当按下保存时，和按下取消时是不同的
    bool autoUpdateonce;    //用于标识是否按下一键上传
    bool fidpid;        //用于标识fidpid是否开启
    bool isInSrvCancelUpload;//标志是否为srv模式下的取消上传
    bool m_isPms;
    bool m_isKjg;
    bool saveflag;
    bool isGuoWangFlag;
    bool isSisFlag;
    bool isSisOK;//标志扫一扫成功捕获到数据
    QTimer *AutoUpdateGetStatus;//获取自动上传状态定时器
    HpXmlReader hpxmlreader;
    QString HasNorelease;//为翻译而生
    QString Hasrelease;//为翻译而生
    QString StartVoice;//为翻译而生
    QString EndVoice;//为翻译而生
    QString SaveOK;//为翻译而生
    QString RecordError;//为翻译而生
    QString WaitShow;//为翻译而生
    QString analysisError;
    QString IsInCancelUpload;
    QString CancelUploadOK;
    QString UploadOK;
    QString UploadWrong;
    QString IsInAutoUpload;
    QString fReconnect;
    QString pms_xml;//pms_xml的名称
    QString pms_filename;//pms图片的名称
    QString isPanorama;//是否进入全景拼接
    //bool IsWifiSearch;          //标识wifi是否打开

    QString dateFolderPath;//3.26需求创建时间文件夹 记录当前保存图片的文件夹路径

    enum_AutoUpload_mode mymode;
    bool IsInAotuUpdate;//处于自动上传模式
    bool IsClickCancelUpload;//表示是否点击了取消上传
    Hp_Text_Input hti;
    bool Taskmode;//标志着是否为台账模式

    QStringList getFileList();
    ftp_para StartAutoUpload_once();
    void hp_setDefine_S3x0(bool isSelect);
    void hp_setMaxAudioTime(int Time);
    QString getNewFileName(QString filename);//获取当前时间_编号为格式的文件名
public:
    bool isContinuedFreeze;

protected:
    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void keyReleaseEvent(QKeyEvent *ev);

signals:
    void SingalSendDateFolderPath(QString path);
    void signal_cameracap_panorama_errmsg(unsigned char return_value);
    void signal_cam_key_capture_stop(unsigned char return_value,QString name);
    void signal_sort_add_new_file(QString name);
    void signal_should_make_pms_json(QString filename);
    void signal_core_get_upload_status();
    void signal_update_lcdoff_time(bool iskey);
    void signal_pc_cmd_set_pc_pic(ftp_para para);
    void signal_set_audio(bool para, int type);
    void signal_pc_cmd_set_pc_pic_srv(char *photoname);//server模式
    void signal_pc_set_upload_break(int status);//取消上传
    void signal_core_key_capture_start(int flag);
    void signal_core_key_add_audio_start();
    void signal_core_key_add_audio_stop();
    void signal_core_key_add_text(char *text);
    void signal_core_key_capture_stop(int type);                //0--->取消   1--->结束
    void signal_core_key_panorama_pic_stop(int type);
    void signal_pc_key_set_freeze(int freeze);
    void signal_cameracap_set_lcd_offed_state();

    void signal_set_Dialog(QString str,int ret);//1表示成功，-1表示失败
    void signal_srvupload_failed();//srv自动上传失败
    void signal_srvupload_cancel();//取消上传
    void signal_wait_warn_save(); //保存按下，如果是国网模式，择等待框弹出
public slots:
    void slot_pc_sys_set_analog_video(unsigned char return_value);
    void slot_Time_out();
    void slot_core_get_upload_status(unsigned char return_value,int upload_status);
    void slot_pc_set_upload_break(unsigned char return_value);
    void slot_autoUpdate_setchecked(bool checked);
    void slot_pc_cmd_set_pc_pic(unsigned char return_value);
    void slot_set_IP_Account_Password(QString ip,QString account,QString password,int errorMsg);
    /* 设置冻结界面信息*/
    void slot_setTaskTest(QString flag, QString title, QString text);
    void slot_HideTaskText();
    void slot_set_cancel_autoupload_state();
    void setIsPmsMode(bool isPmsMode);
    void setImageFormat(int imageFormat);
    //void slot_sendLinkToCameracap(bool IsSuccess);
private slots:
    void SlotCheckAndCreateDateFolder();//检查并创建日期文件
    void slot_set_picture_zoom_save(bool isZoomSave);
    void on_toolButton_text_released();
    void on_toolButton_save_released();
    void on_toolButton_voice_toggled(bool checked);
    void slot_core_key_capture_start(unsigned char return_value);
    void slot_core_key_panorama_pic_start(unsigned char return_value);
    void slot_core_key_add_audio_start(unsigned char return_value);
    void slot_core_key_add_audio_stop(unsigned char return_value);
    void slot_core_key_add_text(unsigned char return_value);
    void slot_core_key_capture_stop(unsigned char return_value,QString name);
    void slot_pc_cmd_set_pc_pic_srv(unsigned char return_value);
    void slot_timer_1s();
    void slot_timer_3s();
    void slot_sync_text();
    void on_toolButton_cancel_released();
    void slot_cameracap_set_lcd_offed_state();
    void  slot_camera_cap_cannal(); //slot_camera_cap_cannal
    void SlotSetImageSR(bool isSelect);
    void SlotSetImageSis(bool isSelect);
    void slot_stop_TextVoice(bool checked); //ture 打开    false 关闭
    void on_toolButton_error_clicked(bool checked);

private:
    Ui::Hp_Camera_Cap *ui;

    int mainmode;//主界面模式
    int m_imageFormat;
    QVector<ANA_OUTLINE> m_taskTempInfos;
    ti600s_picInfo_t g_picInfo;
    bool voiceflag;
    bool textflag;
    QString IP;         //自动上传的IP
    QString Account;    //自动上传的账号
    QString Password;   //自动上传的密码
    bool isS3X0;
    QTimer timer1s,timer3s;
    int voice_timer;


    QList<POINT_PARA_t> m_pointList;
    QList<LINE_PARA_t> m_lineList;
    QList<RECT_PARA_t> m_rectList;
    QList<CIRCLE_PARA_t> m_circleList;
    QList<POLYGON_PARA_t> m_polygonList;
//    bool guowangflag;


    void changeEvent(QEvent *e);
    void delaymsec(int msec);
    void getTaskPicInfo(QString filename_ret);
    void changeTaskfilename(QString &filename_ret);
};

#endif // HP_CAMERA_CAP_H
