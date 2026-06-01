#ifndef HPPREVIEW_H
#define HPPREVIEW_H

#include  <QWidget>
#include  <QFileDialog>
#include  <QStringList>
#include  <QDir>
#include  <QDirIterator>
#include  <QDebug>
#include  <QListView>
#include  <QTreeWidget>
#include  <QListWidgetItem>
#include  <QDebug>
#include  <QMessageBox>
#include  <QFileInfo>
#include <QTime>

#include  "hi384_protocol.h"
#include  "hpdomainthread.h"
#include  "hp_media_player.h"
#include  "hp_dialog.h"
#include  "hp_text_input.h"
#include  "hp_pic_dialog.h"
#include  "hpxmlreader.h"
#include  "hp_hir_player.h"
#include  "hp_gstreamer_player.h"
#include  "hp_media_player_gplay.h"
#include  "hp_sd_space_warning.h"


namespace Ui {
class HpPreview;
}

class HpPreview : public QWidget
{
    Q_OBJECT

public:
    explicit HpPreview(QWidget *parent = 0);
    ~HpPreview();

    Ui::HpPreview *ui;

    Hp_Media_Player_Gplay hmp2;
    Hp_Media_Player hmp;
    hp_hir_player hhp;
    hp_gstreamer_player gstPlayer;

    Hp_Pic_Dialog pic_dialog;
    Hp_Dialog * hp_dialog;
    Hp_Sd_Space_Warning *hssw;
    Hp_Text_Input hp_text_input;
    bool m_isVideoPlaying;
    int set_current_page;
    int current_page,total_pages;
    int pic_type;           //0->pic, 1->video;
    bool isFirstVideo;
    int all_avi;
    int all_hir;            //记录共有几个hir视频
    int video_current;          //视频当前页
    int picture_current;        //图片当前页
    int picture_now;            //当前页的第几张图片
    int  picture_now_all;      //当前页共有几个图片
    int twice_type;              // 0->点击图片然后开始。 1->界面点击上一张按钮。2->界面点击下一张按钮。
    bool define_640_512;
    bool Taskmode;//标识是否为台账模式
    bool fidpid;    //标识fidpid宏定义
    int define_s3X0;

    QStringList m_fileNameList;
    QFileInfoList file_list;
    QFileInfoList sortedFileList;
    int pic_video;//0-1    0-图片   1-视频
    int compositeCount;
    bool define_hirplay;

    QString file_name;
    QString file_name_close;
    QString direct;
    QStringList getFileList();
    void update_dir_data(int type);
    QFileInfoList StartAutoUpload_once(bool isTask);
    void delete_preview_pointer();
    void hp_setDefine_S3x0(bool isSelect);

    void setSdInfo(sdinfo_t sdinfo);
    void setsdinsert(bool f);
     ti600s_picInfo_t g_picInfo_pre;
     int VideoForPNG(QString file,QString filename);

//     void previewTest();
     bool pic_bad_exit;                       //是否存在坏图片
     bool isDefineS300;
     QString avi_bad_name;
     QString hir_bad_name;              //损坏的hir名称
     void pic_bad_exit_manage( );
    void set_pc_image_hir_composite( );
signals:
    void signal_update_lcdoff_time(bool iskey);
    void signal_core_analysis_pic_twice_start(char *name);


    void signal_preview_close();
    void signal_core_get_sd_info();


    void signal_pic_twice_begin();                                              //图片二次分析开始信号。传给主界面左右移动按钮。
    void signal_core_analysis_pic_twice_stop_cut( );                       //停止二次分析的信号
    void signal_pc_sys_set_analog_video(int );
    void signal_pc_measure_move_display(ti_pos pos);
    void signal_pic_twice_type( int last_state, int next_state);                                  //二次分析状态
    void signal_pic_kjg_open(QString file);
    void signal_pic_kjg_on(QString file);
    void signal_send_twice_text();
    void signal_twice_text_show_or_not(int pic_or_video);
    void signal_pc_image_hir_composite(char *name);
    void signal_set_audio(bool para, int type);
    void signal_set_main_analog_audio();
protected:
    bool eventFilter(QObject *o, QEvent *e);
public  slots:
    void slot_stop_video_analysis();
    void setpage();
    void slot_sd_formatting();
    void slot_twice_lastpage();                 //二次分析上一张
    void slot_twice_nextpage();                 //二次分析下一张
    void slot_twice_pic_start();
    void to_set_twice_text_show_or_not();

    void slot_Show_TaskPic();
    void slot_pc_image_hir_composite(unsigned char return_value);
private slots:


    void on_last_page_clicked();

    void on_next_page_clicked();

    void show_pic_clicked();//原on_show_pic_clicked()

    void show_video_clicked();//原on_show_video_clicked()

    //void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void slot_preview_close();   //退出预览界面

    void on_twice_analisys_clicked();   //打开图片
    void on_listWidget_itemSelectionChanged();

    void slot_core_get_sd_info(unsigned char return_value,sdinfo_t sdinfo);

    void on_delete_pic_clicked();

    void on_list_type_released();


private:

    bool sdinsert;
    bool sd_format;
    void update_button_status();
    void show_current_page(int page);
    void show_page_info();
    void delaymsec(int msec);
    void getAllFiles(const QString &directory, QStringList &fileList);//递归进行深度搜索


    QString getListWidgetCurrentFilePath();
    bool sd_insert;
    void changeEvent(QEvent *e);

   //type 1->text.show   , 2->voice.show 。0->all close   num :第几个
    void text_voice_init(int type, int num);
    int get_pic_mode(QString file_name);                                 //获取当前图片的模式 红外/可见光/画中画等   。1为可见光
    int getAudioSize(const QString fileName);
    void StartCheckFile();

    HpXmlReader hpxmlreader;
    QStringList hirFileNameLists;
    QImage *maskImage;
    tagnum_t tagnum;
    taginfo_t taginfo[8];
    voiceinfo_t voiceinfo;
    textinfo_t textinfo;
    QWidget *hp_parent;
    Hp_Text_Input hp_text;
     QString text;
     QString first_pic_name;
     QString last_pic_name;

      char *p_jpg_data;
    int pre_pic_mode[8] = {0};
    int pre_pic_mode_i;                                             //数组中有多少个元素

    QList<QString>damaged_pic_list;
    QString dateFolderPath;//当前日期文件夹路径

};

#endif // HPPREVIEW_H
