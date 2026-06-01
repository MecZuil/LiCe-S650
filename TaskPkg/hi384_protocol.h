/*
 * hi384_protocol.h
 *
 *  Created on: 2017-6-22
 *      Author: root
 */

#ifndef HI384_PROTOCOL_H_
#define HI384_PROTOCOL_H_

#include <stdio.h>


#pragma once


//#define KEY_RETURN 0x01000015

//#define KEY_AUTORECTIFY 0x01000012
#define KEY_AUTORECTIFY //0x1000031

#define KEY_LASER 0x01000013


#define KEY_RETURN 0x01000000     //返回键
#define KEY_CAMERA_PICTURE  0x43  //拍照键
#define KEY_CAMERA_VIDEO 0x56     //录像键

//后续增加的实体按键
#define KEY_MODE      0x1000030   //模式键（F1键开始）
#define KEY_MANUAL    0x1000031   //自动/手动切换
#define KEY_CUSTOM    0x1000032   //自定义键
#define KEY_AUTOFOCUS 0x1000033   //短按为自动调焦
#define KEY_FOCUS_SEL 0x1000034   //长按为电调和手调的切换
#define KEY_UP        0x1000037   //上
#define KEY_DOWN	  0x1000038	  //下
#define KEY_LEFT	  0x1000039	  //左
#define KEY_RIGHT	  0x1000025   //右
#define KEY_OK        0x1000004   //中
#define KEY_UP1       0x31        //慢加上
#define KEY_DOWN1	  0x32	      //慢加下
#define KEY_LEFT1	  0x33	      //慢加左
#define KEY_RIGHT1	  0x34        //慢加右
#define KEY_OK1       0x39        //长按
#define KEY_UP2       0x35        //快加上
#define KEY_DOWN2	  0x36 	      //快加下
#define KEY_LEFT2	  0x37	      //快加左
#define KEY_RIGHT2	  0x38        //快加右
#define KEY_LENS_W	  0x1000035	  //近焦
#define KEY_LENS_T	  0x1000036	  //远焦





//#define KEY_RETURN 0x01000003
//#define KEY_AUTORECTIFY 0x01000012
//#define KEY_LASER 0x4c
//#define KEY_CAMERA_PICTURE  0x43
//#define KEY_CAMERA_VIDEO 0x56

#define BATTERY_MIN 19104
#define BATTERY_MAX 26222

//#define BATTERY_STEP1 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*5/100)           //7118 *5/100 = 355.9
//#define BATTERY_STEP2 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*2/10)            //142.36
//#define BATTERY_STEP3 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*4/10)            //284.72
//#define BATTERY_STEP4 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*6/10)            //427.08
//#define BATTERY_STEP5 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*8/10)            //569.44

#define BATTERY_STEP1 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*5/100)             //7118 *5/100 = 355.9
#define BATTERY_STEP2 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*1/10)              //71.18
#define BATTERY_STEP3 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*2/10)              //142.36
#define BATTERY_STEP4 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*3/10)              //213.54
#define BATTERY_STEP5 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*4/10)              //284.72
#define BATTERY_STEP6 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*5/10)              //355.9
#define BATTERY_STEP7 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*6/10)              //427.08
#define BATTERY_STEP8 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*7/10)              //498.26
#define BATTERY_STEP9 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*8/10)              //569.44

#include <QList>

#define HP_ReflectTemp      1       //反射温度宏定义，0为没有，1为有
#define HP_640_pro          0       //1 不使能蓝牙，不使能WIFI 传送坐标修改， xy *100/167。定制版本. 不使能图片左右切换
#define HP_Drawing          0

#define HVI_mode            0       //1表示hvi模式使能
#define HP_Time             1       //1表示使能时间
#define Temptype_all        1       //1表示局部变量中测温类型所有值使能
#define FOCUS_MODE          0       // 1 表示启动自动调焦模式
#define isTempCapture       1
#define NETVERSION          0       //1表示网口版 0表示正常版
#define PICTURE_T_R_MODE    1
#define GW_mode             1       //0表示开启国网拍照模式，1表示关闭国网拍照模式
#define SR_mode             1       //1表示sr模式开启，0表示sr模式关闭
#define Area_mode           0       //1表示面积模式开始，0表示面积模式关闭
#define ISOTHERM            1       //1表示等温线关闭  0 表示等温线开启
#define Focusing_Mode       0       //1变焦模式开启
#define Record_Mode         1       //1表示录制模式开启
#define OLED_SWITCH         0       //1表示oled关闭
#define SEBIAO15_SIZE       1       //1表示15色标和35倍红外放大关闭
#define ETH_MODE            0       //1表示网口开关开启
#define SIS_MODE            0       //11表示扫一扫功能和成像模式启动  在最全的版本
#define COMPASS_MODE        0       //1表示罗盘模式开启，0表示罗盘模式关闭
#define DelayPhoto          1       //1表示延时拍照关闭，0表示延时拍照打开

typedef struct
{
    int minTemp;
    int maxTemp;
}DANGWEI;


//当前状态用
typedef enum
{
    DS_NON=-1,  //编辑点线框，可以进行移动，删除操作
    DS_POINT,   //增加点操作
    DS_LINE,    //增加线操作
    DS_RECT,    //增加框操作
}DS;

/* @ description : 屏幕列表 */
typedef enum {
    SCREEN_480_272 = 0x00,
    SCREEN_800_480,
    SCREEN_800_480_2,
    SCREEN_853_480,
    SCREEN_1920_1080,
} SCREEN_SIZE;

//使用五向键的主菜单内容切换
enum
{
     MAINMENU_POINT,        //点
     MAINMENU_LINE,         //线
     MAINMENU_RECT,         //框
     MAINMENU_CLEAN,
     MAINMENU_MODE,
     MAINMENU_SETTING,
     MAINMENU_AUTORECTIFY,
     MAINMENU_PREVIEW,
     MAINMENU_SEBIAO,
     MAINMENU_RESIZE,
     MAINMENU_LIGHT,
     MAINMENU_LASER,
};



enum HP_BUTTON_STATUS
{
    S_NORMAL,
    S_SELECT,
    S_DISABLE,
};

enum SEBIAO_SHOW
{
    SEBIAO01,
    SEBIAO02,
    SEBIAO03,
    SEBIAO04,
    SEBIAO05,
    SEBIAO06,
    SEBIAO07,
    SEBIAO08,
    SEBIAO09,
    SEBIAO10,
    SEBIAO11,
    SEBIAO12,
    SEBIAO13,
    SEBIAO14,
    SEBIAO15,
};

enum MAIN_SHOW
{
    MAIN,
    MAIN_POINT,             // 点
    MAIN_LINE,              // 线
    MAIN_RECT,              // 框
    MAIN_PREVIEW,           // 预览
    MAIN_SEBIAO,            // 色标
    MAIN_BRIGHT_MODE,       // 背光
    MAIN_MODE,              // 工作模式
    MAIN_RESIZE,            // 缩放
    MAIN_CLEAN,             // 清除
    MAIN_SETTING,           // 设置
    MAIN_AUTORECTIFY,       // 自动矫正
    MAIN_LASER,             // 激光
    MAIN_TASK,              // 任务包
    MAIN_MESS,              // 提示弹窗
};

enum MODE_SHOW
{
    MODE_HONGWAI,
    MODE_KEJIAN,
    MODE_MSX,
    MODE_HZH,
    MODE_RDJ,
};

#include "hp_file.h"

/* 融合校准参数命令字 */
enum ADJUST_CMD
{
    ADJUST_N1 = 0,          //距离1
    ADJUST_X1,				//水平视场角1
    ADJUST_Y1,				//垂直视场角1
    ADJUST_N2,				//距离2
    ADJUST_X2,				//水平视场角2
    ADJUST_Y2,				//垂直视场角2
    ADJUST_N3,				//距离3
    ADJUST_X3,				//水平视场角3
    ADJUST_Y3,				//垂直视场角3
    ADJUST_N4,				//距离4
    ADJUST_X4,				//水平视场角4
    ADJUST_Y4,				//垂直视场角4
    ADJUST_N5,				//距离5
    ADJUST_X5,				//水平视场角5
    ADJUST_Y5,				//垂直视场角5
    ADJUST_N6,				//最小距离
    ADJUST_Z,				//可见光放大倍率
};


/* 返回码 */
enum RE_CODE
{
    RE_OK = 0x00,                       //成功
    RE_ERR_INTER = 0x0a,				//内部错误
    RE_ERR_MAXCLIENT = 0x0b,			//客户端连接数超出错误
    RE_ERR_BADCMD = 0x14,				//命令错误
    RE_ERR_BADARG = 0x15,				//参数错误
    RE_ERR_SD = 0x1e,                   //SD卡错误
    RE_ERR_SDFULL = 0x1f,				//SD卡已满错误
    RE_ERR_STAT_CAP = 0x28, 			//拍照状态错误
    RE_ERR_STAT_REC = 0x29, 			//录像状态错误，正在录像
    RE_ERR_STAT_NOREC = 0x2a,			//录像状态错误，已经停止录像
    RE_ERR_STAT_TRANS_RAW = 0x2b,       //正在灰度传输错误
    RE_ERR_STAT_TRANS_NO_AVI = 0x2c, 	//没有AVI录像错误
    RE_ERR_SET_IP = 0x32,				//IP设置错误
    RE_ERR_SET_ROUTE = 0x33,			//路由设置错误
    RE_ERR_SET_POINT  = 0x34,			//点设置错误
    RE_ERR_SET_RECT = 0x35,				//区域设置错误
    RE_ERR_SET_LINE = 0x36,				//线设置错误
    RE_ERR_SET_HIDE_MENU = 0x37,		//隐藏菜单设置错误
    RE_ERR_SET_TEMP_USERPARA = 0x38,	//用户测温参数设置错误
    RE_ERR_SET_OBJECT = 0x39,			//测温对象使能设置错误
    RE_ERR_SET_TEMPUNIT = 0x3a,			//设置温度单位错误
    RE_ERR_SET_ALARM = 0x3b,			//设置报警错误
    RE_ERR_SET_COLORRULER = 0x3c,		//设置色标错误
    RE_ERR_SET_TIME = 0x3d,				//设置时间错误
    RE_ERR_READFILE = 0x46,				//读文件错误
    RE_ERR_ANALYSIS = 0x50,				//二次分析状态错误
    RE_ERR_ANALYSIS_TYPE = 0x51,		//二次分析视频模式错误
    RE_ERR_NOCMD = 0xff,				//命令不存在错误
};

/* 主命令 */
enum PC_CMD
{
    PC_LINK = 0x00,				//连接类
    PC_CFG  = 0x02,				//配置类
    PC_MEASURE = 0x10,			//测温类
    PC_IMAGE,                   //图像类
    PC_SYS,                     //系统类
    PC_KEY,                     //按键类
    PC_MCAST,                   //多播类
    PC_PIC,                     //抓图类
    PC_STREAM,                  //实时传输类
    PC_OSD                      //osd类
};

/* 主命令，用来实时报警  */
enum DEV_CMD
{
    DEV_HEART = 0x30,			//心跳
    DEV_ALARM = 0x31,			//报警
};

/* 心跳子命令 */
enum DEV_HEART_CMD
{
    DEV_HEART_ALARM = 0x00,			//心跳
};

/* 报警子命令 */
enum DEV_ALARM_CMD
{
    DEV_ALARM_TEMP_OVER = 0x01,	 	//高温报警     unsigend char[](灰度头+灰度数据+测温参数)
};

/* 连接类子命令 */
enum PC_CMD_LINK
{
    PC_LINK_CONNECT = 0x00,         	//连接	                        NULL
};

/* 配置类子命令 */
enum PC_CMD_CFG
{
    PC_CFG_GET_DEVICEINFO = 0x00,    	//获取设备信息				ComDeviceInfo
    PC_CFG_GET_SYSCONFIG = 0x10,		//获取系统配置				ComSysConfig
    PC_CFG_GET_TEMP_PARA,			//暂时没用
    PC_CFG_SET_TEMP_CALIBPARA,		//暂时没用
    PC_CFG_SET_TEMP_USERPARA = 0x13, 	//设置测温参数(对用户开放)		ComTempUserPara
    PC_CFG_GET_REALTIME_PARA,		//暂时没用
    PC_CFG_GET_POINTCONFIG=0x20,   //获取仪器的点的具体信息
    PC_CFG_GET_LINECONFIG,     //获取仪器的线的具体信息
    PC_CFG_GET_RECTCONFUG,  //获取仪器的框的具体信息

};

/* 测温参数子命令 */
enum PC_CMD_MEASURE
{
    PC_MEASURE_SET_POINT_ADD = 0x00,            //增加点温度					ComPointPara
    PC_MEASURE_SET_POINT_UPDATE ,                //更新点测温
    PC_MEASURE_SET_POINT_DEL,                       //删除点测温

    PC_MEASURE_SET_RECT_ADD=0x03,			         //增加区域测温				        ComRectPara
    PC_MEASURE_SET_RECT_UPDATE ,                //更新区域测温
    PC_MEASURE_SET_RECT_DEL,                      //删除点测温


    PC_MEASURE_SET_LINE_ADD=0x06,			         //增加线测温					ComLinePara
    PC_MEASURE_SET_LINE_UPDATE ,                //更新线测温
    PC_MEASURE_SET_LINE_DEL,                       //删除线测温


    //PC_MEASURE_SET_OBJECT,//上面三个命令之后，都要发下这个命令,设置对象使能标记		ComTempObject
    PC_MEASURE_SET_REFERENCE=0x09,		//设置参考温度				        ComTempRange
    PC_MEASURE_SET_TEMPUNIT=0xa,		//设置测温单位				        enumTempUnit
    PC_MEASURE_SET_TEMPRANGE=0xb,		//切换测温档					ComTempRange
    PC_MEASURE_AUTO_ADJUST_RANGE=0xc,      //+自动切换档位
    PC_MEASURE_CLEAR=0xd,                               //+所有测温点，线，框都清除
    PC_MEASURE_ACTIVE=0x0e,
    PC_MEASURE_TEMPCAPTURE=0x0f,
    PC_MEASURE_TEMPADJUST =0X10,
    PC_MEASURE_HEITI_TEMPADJUST=0X11,

    PC_MEASURE_GET_POINT = 0x20,		//获取点温度					ComPointPara
    PC_MEASURE_GET_RECT,			//获取区域测温					ComRectPara
    PC_MEASURE_GET_LINE,			//获取线测温					ComLinePara
    //PC_MEASURE_GET_OBJECT,			//获取对象使能标记				ComTempObject
    //PC_MEASURE_GET_MAXTEMP_START,		//开始获取图像最高温度				NULL
    //PC_MEASURE_GET_MAXTEMP_STREAM,		//最高温传输					int
    //PC_MEASURE_GET_MAXTEMP_STOP,		//停止获取图像最高温度				NULL
    //PC_MEASURE_GET_MAXTEMP_SERIAL,		//获取最高温					int
    PC_MEASURE_GET_TEMP,			//获取全图温度信息			     	RectTemp
    //PC_MEASURE_SET_FOUR,			//设置四分图状态				FourSet
    //PC_MEASURE_GET_FOUR,			//获取四分图状态				FourSet
    //PC_MEASURE_GET_FOUR_TEMP,		//获取四分图温度				RectTemp x 4
    //PC_MEASURE_SET_CIRCLE,			//设置圆形区域测温				ComCirclePara
    //PC_MEASURE_GET_CIRCLE,			//获取圆形区域测温				ComCirclePara
};

/* 图像类子命令 */
enum PC_CMD_IMAGE
{
    //PC_IMAGE_SET_ISOTEMP = 0x10,	        //等温设置					ComIsothermTemp
    PC_IMAGE_SET_ALARM = 0x10,	       		//设置报警					ComAlarmTemp
    PC_IMAGE_SET_COLORRULER,		//切换色标 0~11					int
    //PC_IMAGE_SET_REVERSE,			//设置反相					NULL
    PC_IMAGE_SET_MANUAL,			//设置手动自动					int 0-1
    PC_IMAGE_SET_MODE,                      //图像模式                              	int 0-6
    PC_IMAGE_GET_MODE,                      //图像模式                              	int 0-6
    PC_IMAGE_SET_FUSION = 0x20,		//设置融合					FusionPara
    PC_IMAGE_GET_FUSION,			//获取融合					FusionPara
    PC_IMAGE_SET_PIP,			//设置画中画					PipPara
    PC_IMAGE_GET_PIP,			//获取画中画					PipPara
    PC_IMAGE_GET_MANUAL = 0x30,		//获取手动自动					int 0-1
    PC_IMAGE_SET_ABNORMAL = 0x40,		//设置异常区域					int 0-1
    PC_IMAGE_SET_ISOTHERM,   //等温设置     ComIsothermTemp
    PC_IMAGE_SET_IMAGETYPE,		//成像模式设置
    PC_IMAGE_SET_SKETCH_DRAW,  //图像草图汇制信息
    PC_IMAGE_SET_SKETCH_CLEAR, //清空图像草图绘制
    PC_IMAGE_SET_FLIP,   //设置图像翻转
    PC_IMAGE_SKETCH_DRAW_START, //图像草图开始新的绘制
    PC_IMAGE_SET_GPS, //设置GPS与否
};

/* 系统类子命令 */
enum PC_CMD_SYS
{
    PC_SYS_SET_LANGUAGE = 0x10,		//语言设置				int id
    //PC_SYS_SET_TIME,			//设置系统时间				char[13],0-3:YEAR;4-12:TIME
    PC_SYS_SET_DEFAULT,			//恢复出厂设置				NULL
    PC_SYS_SET_HIDEMENU,			//设置隐藏信息				ComHideMenuPara     //sys_hidemenu
    PC_SYS_GET_HIDEMENU,			//获取隐藏信息				ComHideMenuPara

    PC_SYS_SET_CAPTURETIME,			//设置抓拍时间				int
    //PC_SYS_SET_CALIBRATE,			//暂时没用
    //PC_SYS_SET_SHOWGRAY,			//暂时没用
    PC_SYS_SET_AUTORECTIFY,			//设置自动调零时间			int
    //PC_SYS_SET_BLACKBODYTEMP,		//设置黑体温度100倍			int
    //PC_SYS_SET_MONITOR_MODE = 0x20,		//设置视频输出制式			int
    //PC_SYS_GET_ALARM_LV_TEMP= 0x20,			//获取报警等级温度			int x alarm_lv_num
    //PC_SYS_SET_ALARM_LV_TEMP,		//设置报警等级温度			int x alarm_lv_num
    //PC_SYS_SET_ALARM_LV,			//设置报警信息				ComAlarmLVTemp
    PC_SYS_SET_TIME_SEC = 0x30,		//设置系统时间，精确到秒                char[21],0-3:YEAR;4-14:TIME 15-20预留
    PC_SYS_SET_FORMAT = 0x31,               //设置格式化               		NULL
    PC_SYS_SET_SCREENSAVETIMEID,            //设置屏保                  		int
    PC_SYS_SET_POWERSAVETIMEID,             //设置自动关机时间           		int
    PC_SYS_SET_USBMODE,                     //设置usb模式                		int
    //PC_SYS_SET_OLED,                        //设置OLED开关               	        int
    PC_SYS_GET_STANDARD,                    //获取定标数据              		StandardInfo
    PC_SYS_GET_BN,                          //获取bn值                   		int
    PC_SYS_GET_FOCUS_STEP,                  //获取步进电机值            		int
    PC_SYS_FUSION_ADJUST,                   //配准                     	        FusionAdjust
    //PC_SYS_SET_VIDEO_OUT = 0x40,            // 视频输出模式，1表示ARM输出，0表示FPGA输出   VideoOut
    //PC_SYS_SET_CAPTURE_OVERLAY,		//拍照叠加菜单				int 1叠加， 0不叠加
    PC_SYS_SET_WIFI_SWITCH,			//wifi开关设置				int 1打开， 0关闭
    PC_SYS_SET_LCD_BRIGHT,                      //LCD 屏幕白天黑夜
    PC_SYS_SET_HAND_FUSION,
    PC_SYS_SET_OLED,                        //设置OLED开关               	        int
    PC_SYS_SET_LASERCMD,                    //激光测距命令
    PC_SYS_SET_HDMI,
    PC_SYS_GET_LASERRANGE,
    PC_SYS_SET_ETH_SWITCH=0X50,//网口开关
    PC_SYS_SET_QRCODE_SWITCH,//设置二维码扫描开关
    PC_SYS_GET_QRCODE_INFO,//获取二维码扫描信息
    PC_SYS_SET_MAG_CALSW_START,//开始磁力计校准
    PC_SYS_SET_MAG_CALSW_STOP,//结束磁力计校准
    PC_SYS_GET_POSITIION_DATA,//获取方位数据
    PC_SYS_GET_APPCONTROLSTATUS,//app控制界面状态
    PC_SYS_SET_MAG_OFFSET, //磁力计偏移
};

/* 按键类子命令 */
enum PC_CMD_KEY
{
    PC_KEY_AUTO_RECTIFY = 0x10,	//调零          		NULL
    PC_KEY_ZOOM,			//图像放大		        int	1-8倍

    //PC_KEY_ZOOM_IN,			//图像放大      		NULL
    //PC_KEY_ZOOM_OUT,		//图像缩小      		NULL
    PC_KEY_SET_FREEZE,

    PC_KEY_AUTO_FOCUS,		//自动调焦      		NULL
    PC_KEY_FOCUS_NEAR,		//手动近焦	 		NULL
    PC_KEY_FOCUS_FAR,		//手动远焦	 		NULL
    PC_KEY_FOCUS_STOP,		//停止调焦      		NULL

    PC_KEY_RECODEAVI = 0x21,		//录像(avi)      		NULL
    PC_KEY_RECODEIR,		//录像(灰度数据) 		NULL
    PC_KEY_RECODESTOP,		//停止录像       		NULL
    PC_KEY_FOCUS_ADJUST,            //调焦模式切换                  NULL
    PC_KEY_FOCUS_SELECT,        //发送值为int 0为自动聚焦 1为连续聚焦
};

/* OSD 类子命令 */
enum PC_CMD_OSD
{
    PC_OSD_GET_OSDSTAT = 0x00,	//获取系统的OSD设置情况		OsdSetting
    PC_OSD_SET_OSDSTAT = 0x01,	//设置系统的osd设置情况		OsdSetting
    PC_OSD_SET_VIDEOOFFSET
};

/* 抓图类子命令 */
enum PC_CMD_PIC
{
    PC_PIC_GET_RAW = 0x01,	//获取灰度图片	  char[]
    PC_PIC_GET_JPG,		//获取jpg图片	  char[]
    PC_PIC_GET_BMP,		//获取BMP图片	  char[]
};

/* 实时传输类子命令 */
enum PC_CMD_STREAM
{
    PC_STREAM_GET_RAW = 0x10,		//获取灰度数据             		NULL
    PC_STREAM_GET_RAW_HEAD  = 0x11,		//发送灰度头              		RawFileHead
    PC_STREAM_GET_RAW_FRAME = 0x12,		//发送灰度数据			   	unsigend char[]
    PC_STREAM_GET_RAW_STOP = 0x13,		//停止发送灰度数据			null
    PC_STREAM_GET_AVI = 0x20,		//获取AVI数据              		NULL
    PC_STREAM_GET_AVI_FRAME  = 0x21,	//发送AVI数据             		unsigend char[]
    PC_STREAM_GET_AVI_STOP  = 0x22,		//停止发送AVI数据             		NULL
    PC_STREAM_INSERT_KEY_FRAME = 0x25,	//插入AVI关键帧           		NULL
};



#endif /* HI384_PROTOCOL_H_ */
