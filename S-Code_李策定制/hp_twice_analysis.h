#ifndef HP_TWICE_ANALYSIS_H
#define HP_TWICE_ANALYSIS_H

#include  <QWidget>
#include  <QTimer>

#include  <QProcess>

#include  "hi384_protocol.h"
#include  "hp_file.h"
#include  "hp_text_input.h"

using namespace std;

namespace Ui {
class Hp_Twice_Analysis;
}

class Hp_Twice_Analysis : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Twice_Analysis(QWidget *parent = 0);
    ~Hp_Twice_Analysis();

    bool start_twice_analysis(QString file);

    bool stop_twice_analysis(QString file);

    bool stop_twice_analysis_name(QString file_old, QString file_now);        //获取关闭二次分析的图片名字.根据需要提取处理的是上一张图片还是当前张

    bool stop_twice_preview;
    bool play_state;                 //播放的状态
    bool voice_state;               //dui wai录音的状态

    Hp_Text_Input hti;
    void hp_setDefine_S3x0(bool isSelect);

    void hp_setMaxAudioTime(int Time);

signals:
    void signal_core_get_twice_audio_status();

    void signal_core_analysis_pic_twice_audioplay_start();

    void signal_core_analysis_pic_twice_audioplay_stop();

    void signal_core_analysis_pic_twice_audiocap_start();

    void signal_core_analysis_pic_twice_audiocap_stop();

    void signal_update_lcdoff_time(bool iskey);

    void signal_twiceanalysis_set_lcd_offed_state();

    void signal_set_twice_text(bool state,QString text);

    void signal_to_send_twice_text(QString text);

    void signal_core_analysis_pic_twice_addtext(char* text);

    void signal_core_analysis_pic_twice_addaudio();

    void signal_core_analysis_pic_twice_cancelaudio();

public slots:
    void slot_get_audio_status();
    void slot_core_get_twice_audio_status(unsigned char return_value, int status);
    void slot_core_analysis_pic_twice_audioplay_start(unsigned char return_value);
    void slot_core_analysis_pic_twice_audioplay_stop(unsigned char return_value);
    void slot_core_analysis_pic_twice_audiocap_start(unsigned char return_value);
    void slot_core_analysis_pic_twice_audiocap_stop(unsigned char return_value);
    void slot_twiceanalysis_set_lcd_offed_state();
    void on_toolButton_voice_p_clicked(bool checked);
    void on_toolButton_voice_r_clicked(bool checked);
    void slot_return_close_voice_r();
    void slot_return_close_voice_p();
    void slot_send_twice_text();

private slots:
    void on_toolButton_clicked(bool checked);

    void ReadData();

    void slot_timer_1s_out();

    void slot_sync_text();

    void on_toolButton_text_released();

    void on_toolButton_save_released();

    void on_toolButton_cancle_released();

    void on_toolButton_text_2_released();

private:
    Ui::Hp_Twice_Analysis *ui;


    bool headset_status;
    bool init_flag;
    int voice_r_clicked_save;               //根据值来判断是否进行语音保存
    int voice_r_clicked;

    QString allfilename;
    QString allfilename_old;
    QString allfilename_now;

    bool readDataFromJpg(QString file);
    bool writeDataToJpg(QString file);

    QWidget *hp_parent;
    char *p_jpg_data;

    tagnum_t tagnum;
    taginfo_t taginfo[8];
    voiceinfo_t voiceinfo;
    textinfo_t textinfo;

    QString taskFileName;
    QString taskFileName_src;


    QString text,new_text;

    QString jpg_voicefile_open;          //读取即将打开图片的语音
    QString jpg_voice_new;      //保存录制的新语音
    QString jpg_voice_close;          //保存即将关闭的图片的语音

    QProcess *process;

    QTimer timer_1s;
    int timer_1s_count;

    bool needsave;
    bool save_state;                //保存按钮的状态
    bool cancle_state;              //取消按钮的状态
    bool record_state;              //录音的状态

    bool twice_text_state;

protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
};

#endif // HP_TWICE_ANALYSIS_H
