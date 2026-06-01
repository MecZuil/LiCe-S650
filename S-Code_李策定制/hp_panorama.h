#ifndef HP_PANORAMA_H
#define HP_PANORAMA_H

#include <QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <QStringList>
#include <QLabel>
#include <QImageReader>
#include <QDebug>
#include "hi384_protocol.h"
#include "hp_panorama_tips_dialog.h"
//#include <ctime>
//#include <unistd.h>

namespace Ui {
class Hp_Panorama;
}

class Hp_Panorama : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Panorama(QWidget *parent = 0);
    ~Hp_Panorama();
    void hp_setDefineS3X0(bool isDefine);
    void over_panorama();//结束全景拼接模式
    void init_panorama();//初始化全景拼接模式
//    void clean_removeList();
//    QStringList getRemoveList();
    void stop_comparsion();//取消拼接
    void splice_panorama();//拼接
    void set_language(int type);
    int  getMatchDegree();//获取匹配度
    void stopTimer();//停止计时器
    bool getDialogVisiable();
    void setDialogVisiable(bool isVisiable);//外部关闭弹窗
    bool getPreviewState();
    int currPicNo;//当前拼接到第几张
    QString m_fusionDegreeMsg;//匹配度提示信息
    QString m_confirmFusionMsg;//确认拼接信息
    QString m_previewMsg;//预览信息
    QString m_picFail;
    Hp_Panorama_Tips_Dialog m_dialog;//弹窗
    bool isSavePanorama;
signals:
    void signal_close_panorama(bool setPanoramaStop);//告知退出全景
    void signal_update_lcdoff_time(bool isScreenShot);//屏幕背光事件刷新
    void signal_cap_camera_panorama();//没用
    void signal_pc_key_set_freeze(int isFreeze);//画面冻结
    void signal_pc_sys_get_matching_degree(int flag);
    void signal_check_panorama_photo(bool flag);
    void signal_pc_sys_set_panorama_stop(int para);//告知底层退出全景
    void signal_sent_press_pos_to_display(QMouseEvent *event);
    void signal_sent_release_pos_to_display(QMouseEvent *event);
    void signal_panorama_set_unsave(QString filename);
public slots:
    void slot_cameracap_panorama_errmsg(unsigned char return_value);
    void slot_core_key_capture_stop(unsigned char return_value, QString name);
    void slot_pc_sys_get_matching_degree(unsigned char return_value, int degree);
private slots:
    void slot_timer_get_match_degree();//定时器获取匹配度
    void on_panorema_ok_clicked();//拼接结束
    void slot_ret_match_panorama();//展示拼接图像
    void show_preview_panorama();//放大预览拼接
    void on_panorema_cancel_clicked();//预览取消保存
    void on_panorema_save_clicked();//预览保存

private:
//    void uyvyToRgb(const uchar *uyvyData, uchar *rgbData, int width, int height);
    void show_next_panorama_pic(QLabel* view, QString filaPath, int height);//缩略图预览
    void scaleWidgetAndChildren(QWidget *widget, qreal scaleFactor);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


private:
    Ui::Hp_Panorama *ui;
    int m_mousePressPosX;//按下时的位置
    int m_panoramaStartPosX;//反的按下时的位置
    int m_mouseMoveMaxX;//移动上限
    int m_matchRet;//匹配度
    int m_degreeTimerStart;//定时器启动标识
    int m_saveCheck;
    int m_languageType;//语言
    bool m_isTooLong;//照片过长
    bool m_isMoveView;//是否在放大预览状态
    bool m_isS3X0;
    QTimer *m_degreeTimer;
    QStringList m_picNameList;
    QString panoremaPicPath;
    QString panoremaPicPath1;
    void changeEvent(QEvent *e);
};

#endif // HP_PANORAMA_H
