#ifndef HP_DISPLAY_H
#define HP_DISPLAY_H

#include  <QWidget>
#include  <QTimer>
#include  <QPoint>
#include  <QTimerEvent>
#include  <QMouseEvent>
#include  <QKeyEvent>
#include  <QDebug>
#include  <QPalette>
#include  <QLabel>
#include  <QMap>
#include  <stdio.h>
#include <unistd.h>

#include  <QToolTip>
#include  "mainwidget.h"
#include  "hp_button.h"
#include  "hpdeledit.h"
#include  "hpplredit.h"
#include  "hptempunitconvert.h"
#include  "hp_polygon.h"
#include  "hi384_protocol.h"

#include "../TaskPkg/hp_statement.h"
#include "../TaskPkg/hp_taskpkg.h"

extern "C" {
#include  "hp_file.h"
extern void hp_jpg_read(QString path,QString file);
}

#include  "hpxmlreader.h"

#define SCF_Y_MUL      1.07
#define SCF_Y_CONMUL   0.9375

 //====2018.4.20   sidian=========
typedef struct{
    int rect_x;
    int rect_y;
    int rect_widget;
    int rect_hight;
}Painter_Rect;

typedef struct{
    bool press_shape;            //按下图片
    bool release_shape;         //松开图片
    bool shape_was_pich;        //图片被选中.

}Decide_State;                          //判断图形所处的状态

typedef struct{
    int begin_x;                            //选中状态时，每次按下时上一个 框的状态
    int begin_y;
    int begin_widget;
    int begin_hight;

    int press_x;                              //记录按压下时的位置。用来判断进行哪种处理.并记录处理前上一个图片状态
    int press_y;

    int wai_widget;                      //选中状态时，允许波动额范围. 半边长。
    int nei_widget;
    int zhong_widget;                   //中间框 半高（设置未正方形）改变框的位置. 范围与角或者边冲突时，边角优先级》框
    int change_style;                   //改变方式。 左中右 1--->3. (十位)。上中下 1--->3(各位)
}Fu_Zhu;

typedef struct{
    int  point_x;
    int  point_y;

    int begin_x;                    //记录按压下时的位置。用来判断进行哪种处理.并记录处理前上一个图片状态
    int begin_y;
    int press_x;
    int press_y;
    int point_widget;               //中心点到图片的长度。  半边距

    bool point_select;
}Hp_Point;

 //====================







class Hp_Display : public QWidget
{
    Q_OBJECT
public:
    explicit Hp_Display(QWidget *parent = 0);

    int pointIndex,bak_pointIndex;
    int lineIndex,bak_lineIndex;
    int rectIndex,bak_rectIndex;
    int circleIndex,bak_circleIndex;
    int polygonIndex, bak_polygonIndex;
    bool sketch_state;
    int point_id;
    int line_id;
    int rect_id;
    int circle_id;
    int points[100];
    int lines[100];
    int rects[100];
    int circles[100];
    int points1[100];
    int lines1[100];
    int rects1[100];
    int circles1[100];
    int tmp;
    int bottom_edge;
    bool auto_focus;                                //自动调焦功能
    bool time_event;

    MainWidget *hp_parrent;

    QString m_filePath;//用于存储图像路径
    bool m_filePathState;//标识是否处于台账绘图状态
    bool m_taskChangeState;//标识是否处于设备树改变状态
    bool m_isPolygonSelectMove;
    int m_polygonSelectMoveIndex;
    bool m_isPolygonDraw;
    bool gray_enable;
    bool cap_enable;
    bool isVisibleLight;
    bool hir_analyse;//用于标识是否开始HIR灰度视频开始二次分析模式
    bool hir_stop;//用于标识是否为hir视频播放停止状态
    bool TaskSouldBepaint;//台账图片允许被画

//    bool define_S6X0_S3X0;//相当于宏定义HP_640_pro
    bool define_zoom;//点线框是否进行缩放，是否为S300
    bool define_640_512;
    bool define_brightmode;//相当于宏定义FOCUS_MODE
    bool m_isInsulation;

    QLabel *gray_disp;

    QList<ComPointPara> hp_point_list;
    QList<ComRectPara> hp_rect_list;
    QList<ComLinePara> hp_line_list;
    QList<ComCirclePara> hp_circle_list;
    QList<ComPolygonPara> hp_polygon_list;

    QList<ComPointPara> bak_hp_point_list;
    QList<ComRectPara> bak_hp_rect_list;
    QList<ComLinePara> bak_hp_line_list;
    QList<ComCirclePara> bak_hp_circle_list;
    QList<ComPolygonPara> bak_hp_polygon_list;

    QList<QRect> m_polygonSelectRectList;

    int drawStatus;//-1:非点线框模式，0:点，1：线，2：框
    int m_currSebiao;
    CS nowselect;//选中的项目

    void delete_item();
    void clear_selecte_status();
    void clear_measure();
    void clear_measure2();
    void clear_circle();
    void selectUpdate();

    void hp_list_save();
    void hp_list_restore();
    void hp_jpg_read(QString path,QString file);
    int get_jpg_mode();
    int get_jpg_sebiao();
    void Task_clear_measure();
    void commit_current_polygon(bool isCommit);
    void display_set_max_num(int point, int line, int rect, int circle, int polygon);
    temper_info_t get_jpg_wdxz();
    Hp_Polygon m_polygonCal;
    ti600s_picInfo_t g_picInfo;
    temper_info_t pic_temper_info;


    hpDelEdit hpdeledit;

    HpPLREdit *hpplredit;

    ComPointPara tmp_point_para;
    ComCirclePara tmp_circle_para;
    ComPolygonPara tmp_polygon_para;
    ComRectPara tmp_rect_para;
    ComLinePara tmp_line_para;
    ComRectPara max_rect_para;//最大的框
void initMaxRectPara();//初始化读取xml内保存的最大框信息
    int max_point_num;
    int max_line_num;
    int max_rect_num;
    int max_circle_num;
    int max_polygon_num;
    HpXmlReader hpxmlreader;

    ComPointBadPixel com_point_pixel;
    ComRectBadPixel com_rect_pixel;
    QTimer *timerGetRectTemp;
    QVector<ANA_OUTLINE> display_aya_infos;
    void reset_taskIndex() {taskIndex = 0;}
    QVector<ANA_OUTLINE> get_taskAnalys() {return display_aya_infos;}
    int taskIndex;//display_aya_infos的动态标识指针
    void UpdatePMSRect();//目前默认就一个矩形
    int task_errid;//台账错误码
    void setDoubleClickFocusFlag(bool flag);//双击聚焦
    int  m_doubleClickCounter;
    bool m_doubleClickFocusFlag;
protected:

    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void mouseMoveEvent(QMouseEvent *ev);
/*
    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void keyReleaseEvent(QKeyEvent *ev);
*/
    void timerEvent(QTimerEvent *event);
private:
    QPoint movePos;
    QPoint pressPoint;
    QPoint releasePoint;   //鼠标点击事件 松开的点
    QList<QPointF> m_polygonsPosList;//当前绘制|选中的多边形坐标
    int id1;
    void clear_reference_set();

    QTimer *timer,*timer_battery_1min;

    //反射率的全局变量
    int g_distance100;      //距离100
    int g_radiance100;      //辐射
    int g_ReflectTemp100;    //反射温度

    int g_radTable_switch;         //默认为0--->辐射率 。1--->辐射率表。
    int g_radTable_id;
    int g_radTable_value100;

    int g_battery;
    int tempunit;

    int jpg_mode;
    int jpg_sebiao;

    QList<POINT_PARA_t> m_pointList;
    QList<LINE_PARA_t> m_lineList;
    QList<RECT_PARA_t> m_rectList;
    QList<CIRCLE_PARA_t> m_circleList;
    QList<POLYGON_PARA_t> m_polygonList;
    QMap<int, double> m_selectInsValueMap;
    QMap<int, int> m_selectIdRectIdMap;
    QPoint getTopLeft(QPoint p,int width,int height);
//2018.2.27
    bool isDrawing;
    int mouse_start_x;
    int mouse_start_y;
    int mouse_end_x;
    int mouse_end_y;
    QPoint circle_centre_select;              //记录圆被选中时的中心坐标
    QPoint rect_centre_select;              //记录框被选中时的中心坐标
    QPoint rect_start_press;                          //记录手按压的坐标
//====2018.4.20   sidian=========
    Painter_Rect rect;
    Decide_State decide_state;
    Fu_Zhu  fu_zhu;
    Hp_Point point;
    QLabel *lable_sidian;
    bool mouse_move;                //开始画框的标志
    bool    hidemenu_rect;          //隐藏菜单画框功能开始的判断
    bool    hidemenu_point;

    void rect_struct_copy();        //对框的结构体。赋值发送信号
    void point_struct_copy();
    void getMaxRect();//保存最大框信息
    ComRectPara m_maxRect;//当前最大框
    bool compareComRectPara(const ComRectPara& a, const ComRectPara& b);//比较框变化

 //========================
    //计算点到线的距离
    int point_line_distance(int a1, int b1, int a2, int b2, int x, int y);
signals:
    void signal_pc_image_set_sketch_start(sketch_point sketch);
    void signal_pc_image_set_sketch_draw(sketch_point sketch);
    void signal_update_lcdoff_time(bool iskey);
    void signal_pc_sys_get_standard();

    void signal_pc_measure_active(OP_DATA op_data);
    void signal_pc_measure_clear();

    void signal_pc_measure_set_point_add(ComPointPara point);
    void signal_pc_measure_set_point_update(ComPointPara point);
    void signal_pc_measure_set_point_del(ComPointPara point);

    void signal_pc_measure_set_line_add(ComLinePara line);
    void signal_pc_measure_set_line_update(ComLinePara line);
    void signal_pc_measure_set_line_del(ComLinePara line);

    void signal_pc_measure_set_rect_add(ComRectPara rect);
    void signal_pc_measure_set_rect_update(ComRectPara rect);
    void signal_pc_measure_set_rect_del(ComRectPara rect);

    void signal_pc_measure_set_circle_add(ComCirclePara circle);
    void signal_pc_measure_set_circle_update(ComCirclePara circle);
    void signal_pc_measure_set_circle_del(ComCirclePara circle);

    void signal_pc_measure_set_polygon_add(ComPolygonPara polygon);
    void signal_pc_measure_set_polygon_update(ComPolygonPara polygon);
    void signal_pc_measure_set_polygon_del(ComPolygonPara polygon);

    void signal_display_rect(unsigned char *data,int recv_datalen);
    void signal_display_point( unsigned char *data,int recv_datalen);

    void signal_dev_get_parameter();                    //设备获取一些全局参数
    void signal_set_resize_nZoomRate10_value(int nZoomRate10);      //设置resize放大倍数
    void signal_set_nProcessType_value(int nProcessType, int nMaxTempHand100,int nMinTempHand100);      //设置右边方式和值， 自动或者手动
    void signal_set_globle_ReferTemp(bool checked);

    void signal_set_twice_hzh_adjust(int x, int y,  int w,  int h);
    void signal_lable_focus_state(bool state);
    void signal_JPGTemCaptrue_Switch(int isOpen);
    void signal_read_img_process(int index);
    void signal_setTaskTest(QString flag, QString title, QString text);
    void signal_hir_analyse_point_stop(int index,bool stop);
    void signal_hir_analyse_line_stop(int index,bool stop);
    void signal_hir_analyse_rect_stop(int index,bool stop);
    void signal_pc_measure_get_rect(int rect_id);
    void signal_show_insulation_warning(bool isShow, int id, int x, int y);
    void signal_double_clicked_focus();
public slots:
    void SlotClearMaxRectPara();
    void SlotRefreshDisplayMaxRect();
    void sltDoubleClickFocus();
    void slot_sent_press_pos_to_display(QMouseEvent *event);
    void slot_sent_release_pos_to_display(QMouseEvent *event);
    void slot_pc_sys_get_standard(unsigned char return_value,StandardInfo msg);

    void slot_pc_measure_active(unsigned char return_value);
    void slot_pc_measure_clear(unsigned char return_value);

    void slot_pc_measure_set_point_add(unsigned char return_value);
    void slot_pc_measure_set_point_update(unsigned char return_value);
    void slot_pc_measure_set_point_del(unsigned char return_value);

    void slot_pc_measure_set_line_add(unsigned char return_value);
    void slot_pc_measure_set_line_update(unsigned char return_value);
    void slot_pc_measure_set_line_del(unsigned char return_value);

    void slot_pc_measure_set_rect_add(unsigned char return_value);
    void slot_pc_measure_set_rect_update(unsigned char return_value);
    void slot_pc_measure_set_rect_del(unsigned char return_value);

    void slot_pc_measure_get_point(unsigned char return_value,ComPointPara point);
    void slot_pc_measure_get_line(unsigned char return_value,ComLinePara line);
    void slot_pc_measure_get_rect(unsigned char return_value,ComRectPara rect);
    void slot_pc_measure_get_circle(unsigned char return_value, ComCirclePara circle);

    //加多边形
    void del_widget_click();
    void edit_widget_click();

    void hs_radiance_value_changed(int value);
    void slot_part_radTable_change(int id, int value);
    void slot_part_radTable_mode(int mode);

    void slot_global_radiance_value_changed(int value);

    void slot_global_radTable_value_changed(int id, int value);
    void slot_global_radTable_mode_changed(int mode);

    void hs_distance_value_changed(double value);
    void slot_global_distance_value_changed(int value);

    void hs_reflect_value_changed(double value);
    void slot_global_reflect_value_changed(int value);


    void cb_temptype_current_index_channed(int value);

    void cb_refer_clicked(bool checked);
    void pb_cancle_clicked();
    void pb_finish_clicked();

    void slot_hidemenu_gray(bool checked);
    void slot_timer();

    void slot_tempunit_changed(int unit);

    //隐藏界面， 画框，点
    void  slot_painter_rect(bool checked);
    void  slot_painter_point(bool checked);
    //移动点和框
    void slot_del_badpixel_point(int direction );                                      //点的移动 1234  上下左右
    void slot_del_badpixel_rect(int direction );

    void slot_set_part_ReferTemp(bool checked);
    void sltImageChange(QString file_path);
    void sltStartTask();
    void sltStopTask();
    void UpdateTaskRect(QVector<ANA_OUTLINE> ana_infos);
    void setInsulation(bool isInsulation);
    void slot_timer_get_rect_index();
    void slot_set_preset_mode(int presetMode);
};

#endif // HP_DISPLAY_H
