/*
 * hi384_protocol.h
 *
 *  Created on: 2017-6-22
 *      Author: root
 */

#ifndef HI384_PROTOCOL_H_
#define HI384_PROTOCOL_H_

#include  <stdio.h>
#define MYLOG qDebug() << "[" << __TIME__ << ":" << __func__<< ":" << __LINE__ << "] "


#pragma once

#define KEY_RETURN 0x01000000
#define KEY_AUTORECTIFY 0x1000031
#define KEY_AUTORECTIFY_LONG 0x5b

#define KEY_LASER 0x1000030
#define KEY_LASER_LONG 0x1000033
#define KEY_CAMERA_PICTURE  0x43
#define KEY_CAMERA_VIDEO 0x56

#define BATTERY_MIN 19104
#define BATTERY_MAX 26222

#define BATTERY_STEP1 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*5/100)            //7118 *5/100 = 355.9
#define BATTERY_STEP2 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*2/10)              //142.36
#define BATTERY_STEP3 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*4/10)              //284.72
#define BATTERY_STEP4 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*6/10)              //427.08
#define BATTERY_STEP5 (BATTERY_MIN+(BATTERY_MAX-BATTERY_MIN)*8/10)              //569.44

#include  <QList>

#define RENAMEFILE_TIME_NUMBER 1//以时间+编号形式重命名文件

#define HP_ReflectTemp 1                                        //反射温度宏定义，0为没有，1为有
#define HP_640_pro      0 //1 不使能蓝牙，不使能WIFI 传送坐标修改， xy *100/167。定制版本. 不使能图片左右切换  1 300/350  0 650/600   ,0也是S300？？？
                                                        //重要：S350  就是 167   S300就是176，这里要添加一个宏定义
#define HP_S350_or_S300  1          //1就是S350，0是S300，HP_640_pro为1时生效

#define HVI_mode    0                   //1表示hvi模式使能
#define HP_Time    1                    //1表示使能时间
#define Temptype_all   1             //1表示局部变量中测温类型所有值使能
#define SR_Mode  1       //1表示sr模式开启
#define FOCUS_MODE  1           // 1 表示启动自动调焦模式(650) 1  350/650   0 300/600
#define LASER_RANGING   1      //1表示启动激光测距
#define Area_Mode 0      //1表示area模式开启
#define FID_PID_MODE 0     //1表示fid和pid模式开启
#define ISOTHERM      0        //1表示等温线关闭  0 表示等温线开启
#define ISWIFISEARCH   1    //表示WIFI查找功能是否开启，若为1，则开启
#define HIR_Mode 1  //1表示HIR录制模式开启，HIR视频能被录制
#define TaiZhang_Mode 1  //1表示台账模式开启
#define Hir_Play 0          //为1则表示hir格式视频能被播放
#define HP_MEDIA_PLAYER 0 //为1表示打开视频旋转、快进快退等功能
#define SEBIAO15_SIZE   1 //1表示15色标和35倍红外放大关闭，已改为从配置文件中读取


typedef struct
{
    int minTemp;
    int maxTemp;
}DANGWEI;


///* 气体模式参数,pc->dev,dev->pc */
//typedef struct{
//    int SensibilitySwitch;      //灵敏度开关 0 - 关 1-开
//    int SensibilityRange;       //灵敏度档位 1-16
//    int SensibilityGain;        //灵敏度增益 1-9
//    int reserve[4];   //保留
//}GasPara;


//当前状态用
typedef enum
{
    DS_NON=-1,//编辑点线框，可以进行移动，删除操作
    DS_POINT,//增加点操作
    DS_LINE,//增加线操作
    DS_RECT,//增加框操作
    DS_CIRCLE,//增加圆操作
    DS_POLYGON,//增加多边形操作
}DS;


//使用五向键的主菜单内容切换
enum
{
     MAINMENU_POINT,  //点
     MAINMENU_LINE, //线
     MAINMENU_RECT, //框
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
enum TwiceAnalysisMENU//用于告诉主界面点击了哪个按钮
{
    TwiceAnalysis_TOOLBUTTON,
    TwiceAnalysis_TEXT,
    TwiceAnalysis_VOICE_R,
    TwiceAnalysis_VOICE_P,
    TwiceAnalysis_SAVE,
    TwiceAnalysis_CANSEL,
    TwiceAnalysis_NOTE,
    TwiceAnalysis_NEXT,
    TwiceAnalysis_LAST
};

enum enum_AutoUpload_mode
{
    enum_AUP_ftp,
    enum_AUP_SERVER,
    enum_AUP_SERVER_PLUS//新的服务器上传
};//自动上传模式
//选中时的参数，选中点，线，框重画时用
typedef struct
{
    char c;//选中的类型，点，线，框
    int s;//index
}__attribute__ ((packed))CS;


enum HP_BUTTON_STATUS
{
    S_NORMAL,
    S_SELECT,
    S_DISABLE,
};
enum DEFINE_XML
{
    XML_OLED = 1,
    XML_WIFI,
    XML_WIFI_SET,
    XML_SR,
    XML_BLE,
    XML_TRANS,
    XML_AREA,
    XML_BUGUANGDENG,
    XML_HDMI,
    XML_FOCUS,
    XML_FID,
    XML_PID,
    XML_SIS,
    XML_ETH,
    XML_4G,
    XML_GPS,
    XML_FLIP,
    XML_SKETCH,
    XML_COMPASS,
    XML_AUTOUPLOAD,
    XML_ONEUPLOAD,
    XML_AUTODOWNLOAD,
    XML_ISOTHERM,
    XML_SEBIAO15,
    XML_DELAYPHOTO,
    XML_HIRPLAY,
    XML_IMAGETYPE,
    XML_AUTOHUANDANG,
    XML_RECORDMODE,
    XML_USBMODE,
    XML_AUTOSAVE,
    XML_MULHOM,
    XML_GW,
    XML_PANORAMA,
    XML_ZOOMSAVE,
    XML_EPUSHBUTTON,
    XML_TEMPHUM,
    XML_ORIGINAL,
    XML_ORITOGGLE,
    XML_HOMOGENEITY,
    XML_STEPZERO,
    XML_NONCOOL,
    XML_SHOWAVGTEMP,
    XML_BMP,
    XML_AUTOREG,
    XML_PRESET1,
    XML_PRESET2,
    XML_CONTRAST,
};//设置界面中的XML预设
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

#define MIN_RECT_WIDTH 10
#define MIN_RECT_HEIGHT 10
enum MAIN_SHOW
{
    MAIN_POINT,
    MAIN_LINE,
    MAIN_RECT,
    MAIN_PREVIEW,
    MAIN_SEBIAO,
    MAIN_BRIGHT_MODE,
    MAIN_MODE,
    MAIN_RESIZE,
    MAIN_CLEAN,
    MAIN_SETTING,
    MAIN_AUTORECTIFY,
    MAIN_LASER,
    MAIN_CIRCLE,
    MAIN_POLYGON,
};

enum MODE_SHOW
{
    MODE_HONGWAI,
    MODE_KEJIAN,
    MODE_MSX,
    MODE_HZH,
    MODE_RDJ,
};

#include  "hp_file.h"

enum RE_CODE
{
        RE_OK = 0x00,						/*设置成功*/
        RE_ERR_INTER_INSTRUCT = 0x01,		/*内部指令错误*/
        RE_ERR_INTER_STATUS = 0x02,			/*内部状态错误*/
        RE_ERR_INTER_OPERATION = 0x03,		/*内部运行错误*/
        RE_ERR_PARA_RECV = 0x04,			/*参数接收错误*/
        RE_ERR_PARA_INVALID = 0x05,			/*参数无效*/
        RE_ERR_MEMORY = 0x06,				/*内存异常*/
        RE_ERR_ILLEGAL_OPERATION = 0x07,	/*非法操作*/

        RE_ERR_FILE = 0x10,					/*文件异常*/
        RE_ERR_SDFULL = 0x11,				/*SD卡已满*/
        RE_ERR_SDFORMAT = 0x12,				/*SD卡正在格式化格式化*/

        RE_ERR_DEV_UNSUPPORT = 0x20,		/*外设不支持*/
        RE_ERR_DEV_NONEXISTENT = 0x21,		/*外设不存在*/
        RE_ERR_DEV_STATUS = 0x22,			/*外设状态错误*/
        RE_ERR_DEV_SD = 0x23,				/*SD卡错误*/
        RE_ERR_DEV_FPGA = 0x24,				/*FPGA设备错误*/
        RE_ERR_DEV_WIFI = 0x25,				/*WIFI设备错误*/
        RE_ERR_DEV_LTE = 0x26,				/*4G/5G设备错误*/
        RE_ERR_DEV_AUDIO = 0x27,			/*音频设备错误*/
        RE_ERR_DEV_GPS = 0x28,				/*GPS设备错误*/
        RE_ERR_DEV_LASER = 0x29,			/*激光设备错误*/
        RE_ERR_DEV_SERSOR = 0x2A,			/*传感器设备错误*/
        RE_ERR_DEV_BLE = 0x2B,				/*蓝牙设备错误*/
        RE_ERR_DEV_DETECTION = 0x2C,		/*外设IO探测错误*/
        RE_ERR_DEV_IOPMIC = 0x2D,			/*外设IO管理错误*/


        RE_ERR_NET_CONFLICT = 0x40,			/*网络冲突异常*/
        RE_ERR_NET_STATUS = 0x41,			/*网络状态错误*/
        RE_ERR_NET_INIT = 0x42,				/*网络初始化错误*/
        RE_ERR_NET_TRANS = 0x43,			/*网络传输错误*/
        RE_ERR_NET_IP_INVALID = 0x44,		/*网络IP无效*/
        RE_ERR_NET_RECV = 0x45,				/*网络接收错误*/

        RE_ERR_SERVER_RESPONSE = 0x50,		/*服务器响应错误*/
        /*~0x7F 保留字段*/

        /*0x80 之后为自定义字段*/
        RE_ERR_IMAGE_FREEZE = 0x81,			//画面冻结异常
        RE_ERR_DETECTOR_TYPE = 0x82,		//探测器类型错误

        RE_ERR_NOCMD = 0xFF,				/*命令不存在*/
};

enum CLIENT_CMD
{
    CLIENT_LINK = 0x39,					/*连接类*/
    CLIENT_IMAGE = 0x40,				/*图像类*/
    CLIENT_MEDIA = 0x41,				/*视频类*/
};

enum CLIENT_CMD_LINK
{
    CLIENT_LINK_LOGON = 0x00,			/*登录服务器*/
    CLIENT_LINK_LOGOUT = 0x01,			/*登出服务器*/
    CLIENT_LINK_HEARTBEAT = 0x02,		/*心跳*/
};

enum CLIENT_CMD_IMAGE
{
    CLIENT_IMAGE_SET_PIC = 0x00,		/*上传照片*/
};

enum CLIENT_CMD_MEDIA
{
    CLIENT_MEDIA_START_H264 = 0x00,		/*开始编码视频传输*/
    CLIENT_MEDIA_STOP_H264 = 0x01,		/*关闭编码视频传输*/
};

enum DEV_CMD
{
    DEV_HEART = 0x30,					//心跳
    DEV_ALARM = 0x31,					//报警
};

enum DEV_HEART_CMD
{
    DEV_HEART_ALARM = 0x00,				//心跳
};

enum DEV_ALARM_CMD
{
    DEV_ALARM_TEMP_OVER = 0x01,	 		//高温报警
};

enum PC_CMD
{
        PC_LINK = 0x00,						//连接类
        PC_CFG  = 0x02,						//配置类
        PC_MEASURE = 0x10,					//测温类
        PC_IMAGE,							//图像类
        PC_SYS,								//系统类
        PC_KEY,								//按键类
        PC_MCAST,							//多播类
        PC_PIC,								//抓图类
        PC_STREAM,							//实时传输类
        PC_OSD,								//OSD类
};

enum PC_CMD_LINK
{
    PC_LINK_CONNECT = 0x00,         	//连接
};

enum PC_CMD_CFG
{
    PC_CFG_GET_DEVICEINFO = 0x00,  		//获取设备信息
    PC_CFG_GET_SYSCONFIG = 0x10,		//获取系统配置
    PC_CFG_GET_TEMP_PARA,			    //未使用
    PC_CFG_SET_TEMP_CALIBPARA,		 	//未使用
    PC_CFG_SET_TEMP_USERPARA = 0x13, 	//设置用户测温参数
    PC_CFG_GET_REALTIME_PARA,			//未使用
    PC_CFG_GET_POINTCONFIG=0x20,		//获取仪器的点数量
    PC_CFG_GET_LINECONFIG,				//获取仪器的线数量
    PC_CFG_GET_RECTCONFIG,				//获取仪器的框数量
    PC_CFG_GET_CIRCLECONFIG,			//获取仪器的圆数量
};

enum PC_CMD_MEASURE
{
    PC_MEASURE_SET_POINT_ADD = 0x00,    //增加点温度
    PC_MEASURE_SET_POINT_UPDATE ,       //更新点测温
    PC_MEASURE_SET_POINT_DEL,           //删除点测温

    PC_MEASURE_SET_RECT_ADD = 0x03,		//增加区域测温
    PC_MEASURE_SET_RECT_UPDATE ,      	//更新区域测温
    PC_MEASURE_SET_RECT_DEL,         	//删除区域测温

    PC_MEASURE_SET_LINE_ADD = 0x06,		//增加线测温
    PC_MEASURE_SET_LINE_UPDATE ,      	//更新线测温
    PC_MEASURE_SET_LINE_DEL,          	//删除线测温

    PC_MEASURE_SET_REFERENCE = 0x09,	//设置参考温度
    PC_MEASURE_SET_TEMPUNIT = 0xa,		//设置测温单位
    PC_MEASURE_SET_TEMPRANGE = 0xb,		//切换测温档
    PC_MEASURE_AUTO_ADJUST_RANGE = 0xc, //自动切换档位
    PC_MEASURE_CLEAR = 0xd,            	//+所有测温点，线，框都清除
    PC_MEASURE_ACTIVE = 0x0e,          	//点、线、框选中状态
    PC_MEASURE_TEMPCAPTURE = 0x0f,		//高低温捕捉
    PC_MEASURE_TEMPADJUST = 0x10,		//设置基准温度
    PC_MEASURE_TEMPCENTER = 0x11,		//中心温度捕获
    PC_MEASURE_TEMPRANGE_QUERY = 0x12,	//查询挡位是否切换成功

    PC_MEASURE_SET_CIRCLE_ADD = 0x15,	//增加圆测温
    PC_MEASURE_SET_CIRCLE_UPDATE,      	//更新圆测温
    PC_MEASURE_SET_CIRCLE_DEL,          //删除圆测温

    PC_MEASURE_GET_POINT = 0x20,		//获取点温度
    PC_MEASURE_GET_RECT,				//获取区域测温
    PC_MEASURE_GET_LINE,				//获取线测温
    PC_MEASURE_GET_CIRCLE,				//获取圆测温
    PC_MEASURE_GET_TEMP = 0x30,			//获取全图温度信息
    PC_MEASURE_MULHOMOGENEITY,			//设置多区域测温
    PC_MEASURE_GET_LINE_INDEX,			//获取线测温的测温点信息
    PC_MEASURE_GET_REFERENCE,			//获取参考温度信息
    PC_MEASURE_GET_TEMPUNIT,			//获取测温单位
    PC_MEASURE_GET_RANGEINFO,			//获取所有的挡位信息
    PC_MEASURE_GET_CURRANGE,			//获取当前挡位信息
    PC_MEASURE_GET_COLLECT,			    //获取测温采集数据
};

enum PC_CMD_IMAGE
{
    PC_IMAGE_SET_ALARM = 0x10,	       	//设置报警信息
    PC_IMAGE_SET_COLORRULER,			//切换色标
    PC_IMAGE_SET_MANUAL,				//设置手动自动
    PC_IMAGE_SET_MODE,              	//图像模式
    PC_IMAGE_GET_MODE,               	//图像模式
    PC_IMAGE_GET_ALARM,               	//获取报警信息
    PC_IMAGE_SET_FUSION = 0x20,			//设置融合
    PC_IMAGE_GET_FUSION,				//获取融合
    PC_IMAGE_SET_PIP,					//设置画中画
    PC_IMAGE_GET_PIP,					//获取画中画
    PC_IMAGE_SET_GAS,			       	//设置气体模式参数
    PC_IMAGE_GET_GAS,			    	//获取气体模式参数
    PC_IMAGE_GET_MANUAL = 0x30,			//获取手动自动
    PC_IMAGE_GET_COLORRULER,			//获取色标条
    PC_IMAGE_SET_ISOTHERM,				//等温设置
    PC_IMAGE_SET_ABNORMALEXTEND = 0x3f,	//设置异常计算扩展设置
    PC_IMAGE_SET_ABNORMAL = 0x40,		//设置异常面积显示
    PC_IMAGE_SET_IMAGETYPE,				//成像模式设置
    PC_IMAGE_SET_SKETCH_DRAW,			//图像草图绘制信息
    PC_IMAGE_SET_SKETCH_CLEAR,			//清空图像草图绘制信息
    PC_IMAGE_SET_FLIP,					//设置图像翻转
    PC_IMAGE_SKETCH_DRAW_START,			//图像草图开始新的绘制
    PC_IMAGE_SET_GPS,					//设置GPS显示与否
    PC_IMAGE_HIR_COMPOSITE,				//HIR图片合成
    PC_IMAGE_SET_AUTOCAL,				//设置自动测算
    PC_IMAGE_SET_GASDETECTION,			//设置气体检测
    PC_IMAGE_GET_GASDETECTION,			//获取气体检测设置
    PC_IMAGE_SET_HUMIDITY_ALARM,        //设置湿度报警
    PC_IMAGE_SET_VERTICAL_HANDLE,		//设置竖纹处理
    PC_IMAGE_SET_SUPPRESSION_HANDLE,	//设置均匀面抑制处理
    PC_IMAGE_SET_SUBSTATION_SWITCH,     //设置变电识别开关
    PC_IMAGE_GET_SUBSTATION_INFO,       //获取变电识别信息
};

/* 系统类子命令 */
enum PC_CMD_SYS
{
    PC_SYS_SET_LANGUAGE = 0x10,			//语言设置
    PC_SYS_SET_DEFAULT,		  			//恢复出厂设置
    PC_SYS_SET_HIDEMENU,				//设置隐藏菜单
    PC_SYS_GET_HIDEMENU,				//获取隐藏菜单
    PC_SYS_SET_CAPTURETIME,				//设置自动拍照时间
    PC_SYS_SET_AUTORECTIFY,				//设置自动调零时间
    PC_SYS_GET_AUTORECTIFY,				//获取自动调零时间
    PC_SYS_SET_TIME_SEC = 0x30,			//设置系统时间，秒级
    PC_SYS_SET_FORMAT = 0x31,     		//格式化sd卡
    PC_SYS_SET_SCREENSLEEP,  			//设置屏幕休眠
    PC_SYS_SET_POWERDOWN,   			//设置自动下电
    PC_SYS_SET_USBMODE,           		//设置USB模式
    PC_SYS_GET_STANDARD,          		//获取定标数据
    PC_SYS_GET_BN,                		//获取BN值
    PC_SYS_GET_FOCUS_STEP,        		//获取调焦步数
    PC_SYS_FUSION_ADJUST,				//设置配准
    PC_SYS_SET_WIFI_SWITCH,				//wifi开关设置
    PC_SYS_SET_LCD_BRIGHT,      		//LCD屏幕白天黑夜
    PC_SYS_SET_HAND_FUSION,     		//手动配准
    PC_SYS_SET_OLED,          			//设置OLED开关
    PC_SYS_SET_LASERCMD,         		//激光命令
    PC_SYS_SET_HDMI = 0x3e,     		//设置HDMI开关
    PC_SYS_GET_LASERRANGE = 0x3f,		//获取激光距离值
    PC_SYS_SET_LASERRANGE = 0x40,		//设置激光测距命令
    PC_SYS_SET_FID = 0x41,				//3100获取FID PID值
    PC_SYS_GET_ZOOM,					//获取放大倍数
    PC_SYS_SET_LIGHT,        			//设置补光灯电源
    PC_SYS_GET_LIGHT,          			//获取补光灯电源状态
    PC_SYS_GET_LASER_POWER,          	//获取激光电源状态
    PC_SYS_SET_DUALLIGHTREC,			/*设置双光录像*/
    PC_SYS_SET_INDUCTION,				/*设置感应控制*/
    PC_SYS_GET_COLORRULE=0x4F,			//获取当前色标号
    PC_SYS_SET_FOCUS_STEP=0x50,			//设置调焦步数
    PC_SYS_SET_NET_FRAMENUM,			//设置网络传输帧率控制
    PC_SYS_SET_GAS_IR_OK,				//设置气体红外探测器稳定状态
    PC_SYS_GET_GAS_IR_OK,				//获取气体探测器稳定状态
    PC_SYS_GET_APPCONTROLSTATUS=0x56,	//app控制界面状态
    PC_SYS_GET_ESSID,					//获取可接入的网络
    PC_SYS_SET_WIFI_STA,				//设置要接入的网络
    PC_SYS_SET_UPLOAD_TARGET = 0x5a,	//设置上传目标网络
    PC_SYS_SET_UPLOAD_BREAK,			//设置上传中断
    PC_SYS_SET_LASERPOS,				//设置激光位置
    PC_SYS_SET_DOWNLOAD,				//设置ftp下载
    PC_SYS_SET_FILEQUERY,				//设置ftp文件查询
    PC_SYS_SET_LTE,						/*设置lte连接*/
    PC_SYS_SET_SERVICE = 0x60,			/*设置服务器连接*/
    PC_SYS_SET_GPSINFO,					/*设置GPS信息*/
    PC_SYS_SET_AUTOFOCUSMODE,			/*设置自动聚焦模式*/
    PC_SYS_SET_SEVSEND_BREAK,			/*设置服务器发送中断*/
    PC_SYS_GET_SPEECH_CMD,				/*获取语音识别模块指令*/
    PC_SYS_SET_LTE_DIAL,				/*设置lte模块拨号*/
    PC_SYS_SET_ETH_SWITCH,				/*网口开关*/
    PC_SYS_SET_QRCODE_SWITCH,			//设置二维码扫描开关
    PC_SYS_GET_QRCODE_INFO,				//获取二维码扫描信息
    PC_SYS_SET_MAG_CALSW_START,			//开始磁力计校准
    PC_SYS_SET_MAG_CALSW_STOP,			//结束磁力计校准
    PC_SYS_GET_POSITIION_DATA,			//获取方位数据
    PC_SYS_SET_MAG_OFFSET,				//磁力计偏移
    PC_SYS_SET_WIFI_POWER = 0x70,		/*设置wifi电源*/
    PC_SYS_SET_TEMP_HUM,				/*设置USB温湿度传感器*/
    PC_SYS_SET_LASER_POWER,				/*设置激光电源*/
    PC_SYS_SET_SPEECH_POWER,			/*设置语音识别模块电源*/
    PC_SYS_SET_LTE_POWER,				/*设置LTE电源*/
    PC_SYS_SET_BLE_POWER = 0x80,		/*设置ble电源*/
    PC_SYS_SET_BLE_MODULE,				/*设置ble模块*/
    PC_SYS_SET_BLE_SWITCH,				/*设置ble模式开关*/
    PC_SYS_SET_BLE_FUNCTION,			/*设置调用ble功能*/
    PC_SYS_GET_BLE_INFO,				/*获取蓝牙相关信息*/
    PC_SYS_SET_ANALOG_AUDIO,			/*设置模拟音频模式*/
    PC_SYS_SET_PANORAMA_START,			/*设置全景模式开始*/
    PC_SYS_SET_PANORAMA_STOP,			/*设置全景模式结束*/
    PC_SYS_GET_MATCHING_DEGREE,			/*获取拼接匹配度*/
    PC_SYS_SET_ENC_QUALITY,				/*设置编码质量*/
    PC_SYS_SET_STEP_ZERO,				/*设置阶梯调零*/
    PC_SYS_SET_GB28181_INFO,			/*设置GB28181参数*/
    PC_SYS_SET_LTE_APN,                 /*设置APN参数*/
    PC_SYS_SET_LOCAL_SERVICE = 0x90,    /*设置仪器本地服务*/
    PC_SYS_SET_DEV_ACTIVE_SEARCH,       /*设置设备主动搜索*/
    PC_SYS_SET_DEV_CLIENT,              /*设置设备客户端连接*/
    PC_SYS_SET_FINGERPRINT_VERIFY,          /*设置指纹验证*/
    PC_SYS_SET_FINGERPRINT_VERIFY_SWITCH,   /*设置指纹验证开关*/
    PC_SYS_SET_FINGERPRINT_GATHER,          /*设置指纹采集*/
    PC_SYS_SET_FINGERPRINT_REGISTER,        /*设置指纹保存*/
    PC_SYS_SET_FINGERPRINT_DELETE,          /*设置指纹删除*/
    PC_SYS_GET_CONNECT_PC_DEVICE = 0x9A,    /*获取PC处已连接的设备*/
    PC_SYS_SET_COLOR_BRIGHTNESS = 0xA0,    /*设置亮度*/
    PC_SYS_SET_IMAGE_CONTRAST = 0xA1,    /*设置对比度*/
};

/* 按键类子命令 */
enum PC_CMD_KEY
{
    PC_KEY_AUTO_RECTIFY = 0x10,			//调零
    PC_KEY_ZOOM,						//图像放大
    PC_KEY_SET_FREEZE,					//画面冻结
    PC_KEY_AUTO_FOCUS,					//自动调焦
    PC_KEY_FOCUS_NEAR,					//手动近焦
    PC_KEY_FOCUS_FAR,					//手动远焦
    PC_KEY_FOCUS_STOP,					//停止调焦
    PC_KEY_ZOOM_TELE,       			//视场变窄
    PC_KEY_ZOOM_WIDE,       			//视场变广
    PC_KEY_ZOOM_STOP,       			//变焦停止
    PC_KEY_RECODEAVI = 0x21,			//录像(avi)
    PC_KEY_RECODEIR,					//录像(灰度数据)
    PC_KEY_RECODESTOP,					//停止录像
    PC_KEY_FOCUS_ADJUST,            	//调焦模式切换
    PC_KEY_APP_RECSTART=0x25,       	//app录像开始键
    PC_KEY_APP_RECSTOP,         		//app录像停止键
    PC_KEY_APP_RECRESTART,   			//app录像重新开始键
    PC_KEY_APP_RECLOAD,         		//app下载视频按键
    PC_KEY_APP_CONTROL = 0x29,			//app连接按键
    PC_KEY_FLASHLIGHT,           		//补光灯开关
    PC_KEY_LASERPOWER,         			//激光开关
    PC_KEY_APP_3100DATASWITCH = 0x2C, 	//3100数据采集开始或停止 --- 气体
    PC_KEY_APP_SHUTDOWN,     			//软件控制关机 --- 气体
    PC_KEY_APP_FILELIST,         		//获取列表 --- 气体
    PC_KEY_FOCUS_SELECT = 0x40,			//选择聚焦模式
};

/* OSD 类子命令 */
enum PC_CMD_OSD
{
    PC_OSD_GET_OSDSTAT = 0x00,			//获取系统的OSD设置情况
    PC_OSD_SET_OSDSTAT = 0x01,			//设置系统的osd设置情况
    PC_OSD_SET_VIDEOOFFSET,				//设置视频的偏移值
};

/* 抓图类子命令 */
enum PC_CMD_PIC
{
    PC_PIC_GET_RAW = 0x01,				//获取灰度图片
    PC_PIC_GET_JPG,						//获取jpg图片
    PC_PIC_GET_BMP,						//获取BMP图片
    PC_PIC_SET_UPLOAD,					//图片上传(ftp)
    PC_PIC_SET_PIC,						//图片上传(client)
};

/* 实时传输类子命令 */
enum PC_CMD_STREAM
{
    PC_STREAM_GET_RAW = 0x15,			//获取灰度数据
    PC_STREAM_GET_RAW_HEAD  = 0x16,		//发送灰度头
    PC_STREAM_GET_RAW_FRAME = 0x17,		//发送灰度数据
    PC_STREAM_GET_RAW_STOP = 0x18,		//停止发送灰度数据
    PC_STREAM_GET_H264 = 0x20,			//获取H264数据
    PC_STREAM_GET_H264_FRAME  = 0x21,	//发送H264数据
    PC_STREAM_GET_H264_STOP  = 0x22,	//停止发送H264数据
    PC_STREAM_INSERT_KEY_FRAME = 0x25,	//插入AVI关键帧
};

/* 多播类子命令 */
enum PC_CMD_MCAST
{
    PC_MCAST_SEARCH_DEV = 0x01,    		//搜索设置
    PC_MCAST_SET_IP						//设置IP
};

/* 兼容仪器，主命令*/
enum CORE_CMD
{
    CORE_CTRLCORE = 0x01,				//控制类
    CORE_KEY = 0x05,					//按键类
    CORE_GET,							//获取类
    CORE_ANALYSIS = 0x09,				//分析类
    CORE_FPGAMENU,           			//FPGA前端菜单
};

/* 控制类子命令 */
enum CORE_CMD_CTRLCORE
{
    CORE_CTRLCORE_START_ENCODE = 0,		//视频模块开始运行
    CORE_CTRLCORE_STOP_ENCODE,			//视频模块停止运行
    CORE_CTRLCORE_EXIT_CORE = 0x04,		//应用程序退出
};

/* 按键类子命令 */
enum CORE_CMD_KEY
{
    CORE_KEY_RECORD_AVI_START = 0x00,	//avi开始录像
    CORE_KEY_RECORD_AVI_STOP = 0x01,	//avi停止录像
    CORE_KEY_CAPTURE_START = 0x02,		//开始拍照
    CORE_KEY_ADD_AUDIO_START = 0x03,	//开始加入音频
    CORE_KEY_ADD_AUDIO_STOP = 0x04,		//停止介入音频
    CORE_KEY_RECORD_IR_START = 0x05,    //IR 开始录像
    CORE_KEY_RECORD_IR_STOP = 0x06,		//IR停止录像
    CORE_KEY_ADD_TEXT = 0x21,			//加入文本
    CORE_KEY_CAPTURE_STOP = 0x22,		//停止拍照
    CORE_KEY_RTSP_START = 0x30,			//开始rtsp传输
    CORE_KEY_RTSP_STOP = 0x31,			//停止rtsp传输
    CORE_KEY_RECORD_MP4_START = 0x32,	//mp4开始录像
    CORE_KEY_RECORD_MP4_STOP = 0x33,	//mp4停止录像
    CORE_KEY_GB28181_START = 0x34,		//开始gb28181传输
    CORE_KEY_GB28181_STOP = 0x35,		//停止gb28181传输
    CORE_KEY_DEV_CLIENT_ENCODE_START = 0x40,    //开启设备客户端流传输
    CORE_KEY_DEV_CLIENT_ENCODE_STOP = 0x41,     //关闭设备客户端流传输
    CORE_KEY_PC_CLIENT_H264_DOWNLOAD_START,     //开启连入的服务器端流传输
    CORE_KEY_PC_CLIENT_H264_DOWNLOAD_STOP,      //关闭连入的服务器端流传输
};

/* 获取类子命令 */
enum CORE_CMD_GET
{
    CORE_GET_SD_INFO = 0x02,            //获取sd卡信息
    CORE_GET_USBINSERT = 0x05,          //获取USB插入状态
    CORE_GET_SDINSERT = 0x06,           //获取sd卡插入状态
    CORE_GET_BATTERY = 0x07,            //获取电池电量
    CORE_GET_USBWIFIINSERT,             //获取USBWIFI状态
    CORE_GET_CHARGE,                    //电池充电状态
    CORE_GET_GPS_VALUE,                 //GPS定位信息
    CORE_GET_ROTATION_TYPE = 0x10,      //获取当前仪器旋转方向
    CORE_GET_WIFI_STA_STATUS,           //获取WIFI连接AP状态
    CORE_GET_UPLOAD_STATUS,             //获取上传状态
    CORE_GET_HIR_PLAY_STATUS,           //获取HIR播放状态
    CORE_GET_LTE_STATUS,                /*获取LTE模块状态*/
    CORE_GET_SERVICE_STATUS,            /*获取服务端状态*/
    CORE_GET_BLE_STATUS,                /*获取蓝牙状态*/
    CORE_GET_TWICE_AUDIO_STATUS,        /*获取二次分析音频状态*/
    CORE_GET_LENS_ID,                   /*获取镜头ID*/
};

/* 分析类子命令 */
enum CORE_CMD_ANALYSIS
{
    CORE_ANALYSIS_PIC_TWICE_START = 0,      //开始二次分析
    CORE_ANALYSIS_PIC_TWICE_STOP,           //停止二次分析
    CORE_ANALYSIS_PIC_TWICE_GET_SYSCONFIG,  //获取二次分析下的系统信息
    CORE_ANALYSIS_PIC_TWICE_AUDIOCAP_START, //二次分析开始添加录音
    CORE_ANALYSIS_PIC_TWICE_AUDIOCAP_STOP,  //二次分析结束添加录音
    CORE_ANALYSIS_PIC_TWICE_AUDIOPLAY_START,//二次分析开始播放录音
    CORE_ANALYSIS_PIC_TWICE_AUDIOPLAY_STOP, //二次分析结束播放录音
    CORE_ANALYSIS_PIC_TWICE_ADDTEXT,        //二次分析添加文本
    CORE_ANALYSIS_PIC_TWICE_ADDAUDIO,       //二次分析添加录音
    CORE_ANALYSIS_PIC_TWICE_CANCELAUDIO,    //二次分析取消录音
    CORE_ANALYSIS_HIR_TWICE_START = 0x10,   //开始灰度流视频二次分析
    CORE_ANALYSIS_HIR_TWICE_STOP,           //停止灰度流视频二次分析
    CORE_ANALYSIS_HIR_TWICE_SUSPEND,        //暂停灰度流视频分析
    CORE_ANALYSIS_HIR_TWICE_LOCKSTATUS,     //灰度流视频分析锁定状态
};

/*FPGA前端控制菜单*/
enum CORE_CMD_FPGAMENU
{
    CORE_FPGAMENU_ZN,					//获取挡位号
    CORE_FPGAMENU_GET_PARA,				//获取VS VF GAIN INT参数
    CORE_FPGAMENU_SET_PARA,    			//设置VS VF GAIN INT参数
    CORE_FPGAMENU_HI,					//FPGA hi两点矫正
    CORE_FPGAMENU_LO,					//FPGA lo两点校正
    CORE_FPGAMENU_ZERO,					//FPGA调零设置
    CORE_FPGAMENU_SAVE,					//FPGA保存设置
    CORE_FPGAMENU_GET_VER,				//获取FPGA版本号
    CORE_FPGAMENU_GET_GRAY,				//获取调零灰度、最大灰度、最小灰度

    CORE_FPGAMENU_POINT_BADPIXEL,       //点去死点
    CORE_FPGAMENU_RECT_BADPIXEL,        //区域去死点
    CORE_FPGAMENU_DEL_BADPIXEL,         //确定死点
    CORE_FPGAMENU_FOCUSOFFSET,			//FPGA偏移值设置---在线设置通道
    CORE_FPGA_SET_IMAGE_MODE,			/*图像模式 0是开启DDE 1是关闭 --- 在线*/
    CORE_FPGA_SET_DDE_PARA,				//DDE参数 --- 在线
    CORE_FPGA_SET_DDE_ZOOM,				//DDE放大倍数 --- 在线

    CORE_FPGA_SET_DIRECTION = 0x10,		//图像方向 --- 在线
    CORE_FPGA_GET_FOCUS_OFFSET,			//获取调焦偏移值 --- 兼容老的在线
    CORE_FPGA_GET_IMAGE_MODE,			//获取DDE图像模式 --- 兼容老的在线
    CORE_FPGA_GET_DDE_PARA,				//获取DDR参数 --- 兼容老的在线
    CORE_FPGA_GET_DDE_ZOOM,				//获取DDE放大倍数 --- 兼容老的在线
    CORE_FPGA_GET_DIRECTION,			//获取图像方向 --- 兼容老的在线
    CORE_FPGA_BADLINE_X,				//打横线 --- 兼容老的在线
    CORE_FPGA_BADLINE_Y,				//打竖线 --- 兼容老的在线
    CORE_FPGA_GET_NEW_VER,				//获取新版本 --- 兼容老的在线
    CORE_FPGA_SET_FOCUS_STEP = 0x19,	//设置步进值
    CORE_FPGA_GET_FOCUS_STEP,			//获取步进值

    CORE_FPGAMENU_GEAR_SET = 0x20,		/*外档号设置*/
    CORE_FPGAMENU_IAMGE_ENHANCE,   		/*图像模式 0是开启DDE 1是关闭*/
    CORE_FPGAMENU_SEZOOM1,     			//SEZOOM1
    CORE_FPGAMENU_LENSTEMP,       		//镜头温度
    CORE_FPGAMENU_DOTCLEAR,   			//获取死点清楚个数
    CORE_FPGAMENU_SEPARA,   			//DDE参数
    CORE_FPGAMENU_SEZOOM,   			//DDE放大倍数
    CORE_FPGAMENU_STEPOFFSET,  			//设置调焦偏移值---气体设置通道
    CORE_FPGAMENU_BADLINE_X,    		//死线X轴坐标列死线
    CORE_FPGAMENU_BADLINE_Y,    		//死线Y轴坐标行死线
    CORE_FPGAMENU_AUTO_BADPIXEL,		/*自动打死点*/
    CORE_FPGAMENU_BADPIXEL_RECOVER,		/*死点恢复*/
    CORE_FPGAMENU_BADPIXEL_PARA,		/*设置死点参数*/
    CORE_FPGAMENU_SEZOOM2,        		//SEZOOM2
    CORE_FPGAMENU_3DPARA,         		//3DPARA

    CORE_FPGAMENU_FOCUS_OFFSET = 0x40,	//FPGA偏移值设置---便携设置通道
    CORE_FPGAMENU_IMAGE_ROTATE, 		//设置FPGA图像翻转
    CORE_FPGAMENU_ERASE,				/*程序擦除*/
    CORE_FPGAMENU_GEAR_CAPTURE,			/*外档采集*/
    CORE_FPGAMENU_ORITOGGLE,			/*原始两点切换*/
    CORE_FPGAMENU_NONCOOL_CORRECT,		/*非制冷矫正*/
    CORE_FPGAMENU_SET_INTCP,		/*设置积分电容*/
    CORE_FPGAMENU_SET_ADGAIN,		/*设置AD增益*/
    CORE_FPGAMENU_SET_SVRD,		    /*设置盲元和像元偏差范围*/
    CORE_FPGAMENU_SET_FOS,		    /*设置全局矫正*/
    CORE_FPGAMENU_SET_OCC_ENABLE,	/*设置OCC使能*/
    CORE_FPGAMENU_NOISE_TIME_PARA,		/*3D降噪时域参数*/
    CORE_FPGAMENU_NOISE_AIRSPACE_PARA,	/*3D降噪空域参数*/
    CORE_FPGAMENU_GET_INTCP,			/*获取积分电容*/
    CORE_FPGAMENU_GET_ADGAIN,			/*获取ADC增益范围*/
    CORE_FPGAMENU_GET_SVRD,				/*获取盲元和像元偏压范围*/
    CORE_FPGAMENU_GET_FOS,				/*获取全局矫正*/
};

typedef struct {
    char ip_addr[16];                   //IP地址
    unsigned char mac_addr[8];          //MAC地址
    int dev_id;                         //设备ID
} dev_client_dev_ip_info;

typedef struct {
    dev_client_dev_ip_info ip_info[10];
    int search_num;
} dev_client_dev_search_info;

typedef struct {
    char ip_addr[16];                   //IP地址
    int client_switch;                  //客户端开关设置
} ComDevClientInfo;

/* 搜索结构, dev->pc*/
typedef struct{
    int dev_id;                  		//设备id
    unsigned char mac_addr[8];       	//MAC地址
    int reserve[16];                  	//16字节保留
}__attribute__ ((packed)) DevInfo;

/* 设置ip结构,pc->dev */
typedef struct{
    int dev_id;                     	//设备id
    unsigned char ip[16];           	//IP
    unsigned char netmask[16];       	//子网掩码
    unsigned char gateway[16];      	//网关
    int reserve[16];                 	//16字节保留
}__attribute__ ((packed)) SetIPInfo;

/* 设备信息结构 ，Dev->pc */
typedef struct {
    char DeviceType[32];			//内部型号
    char OEMDeviceType[32];			//贴牌型号
    char DataProtocal[32];			//数据协议
    char SerialNumber[20];			//序列号
    char ProduceTime[16];			//生产日期
    char SoftwareVersion[16];		//软件版本
    char HardwareVersion[16];		//硬件版本
    int  TempCalcType;				//测温算法编号
    int  ImageCalcType;				//图像算法编号
    int  DetectorWidth;				//探测器像素宽
    int  DetectorHeight;			//探测器高
    int  BitsPerPixel;				//像素位数
    int  BytesPerPixel;				//像素字节数
    int  ImageWidth;				//图像宽
    int  ImageHeight;                                   //图像高
    int Reserved[25];				// 预留
}__attribute__ ((packed))ComDeviceInfo;

/* 系统信息结构,dev->pc */
typedef struct {
    int Emissivity100; 				//辐射率
    int Repair100; 					//用户修正系数100倍
    int RepairTemp100;				//用户修正温度
    int Distance100;				//距离100倍
    int Humidity100;				//湿度100倍
    int ReflectTemp100; 			//反射温度

    int TempRangeID;				//挡位号
    int OtherLensID;				//镜头ID
    int TempClass;					//挡位
    int TempUnit;					//温度单位
    int RefeTempType;				//参考温度类型
    int RefeTemp100;				//参考温度100倍

    int AlarmColorID;				//报警色
    int AlarmSwitch;				//报警温度开关 0关闭 1最高温 2最低温
    int AlarmTemp100;				//报警温度100倍

    int IsothermColorID;			//等温色
    int IsothermTemp100;			//等温温度100倍
    int IsothermHight100;			//等温高度100倍

    int ColorRulerID;				//色标ID
    int ReverseImage;				//图像反相
    int ManualType;					//手自动模式
    int TempHigh100;				//全图最高温度
    int TempLow100;					//全图最低温度

    int LanguageID;					//语言ID
    int AutoZeroTime;				//自动调零时间
    int AutoCapTime;				//自动捕获时间
    int BlackBodyTemp100;			//黑体温度100倍
    int ZoomRate;					//倍率

    int MonitorMode;				//视频制式
    char TimeString[16];			//时间
    int ShowGrayEnable;				//灰度显示使能
    int CollectEnable;				//采集使能

        int InterCorrectTemp100;		//内部修温
    int InterCorrectFact100;		//内部修系
    int AlarmLevel;			  		//当前报警等级
    int AlarmLevelNum;				//报警等级数量

    int Transmission100;			//透射率
    int AmbientTempManu100;			//手动设置环境温度100倍

    int nradTable_switch;     		//默认为0--->辐射率 。1--->辐射率表。
    int nradTable_id;
    int nradTable_value100;
    int nradTable100;        		//设置值

    int SebiaoMax;					//支持的最大色标
    int ZoomMax;					//支持的最大放大倍数

    int Reserve[21];				//保留
}__attribute__ ((packed))ComSysConfig;

/* 用户测温参数结构,pc->dev */
typedef struct {
    int Radiance100;   				//辐射率100倍
    int Distance100;   				//距离100倍
    int Humidity100;   				//湿度100倍
    int ReflectTemp100;        		//+加反射温度
    int transmission100;  			//透射率100倍
    int AmbientTempManu100;			//环境温度100倍

    int RadTable_switch;           	//默认为0--->辐射率 。1--->辐射率表。
    int RadTable_id;
    int RadTable_value100;

    char reserve[12];     			//24个字节的预留空间
}__attribute__ ((packed))ComTempUserPara;

/* 点测温参数， pc->dev, dev->pc */
typedef struct {
    int point_id;        			//测温点编号[1,100]；
    int p_xcoord;        			//点x坐标；
    int p_ycoord;        			//点y坐标;
    int p_radiance100;   			//点辐射率100倍[1,100];
    int refer_flag;      			//设为参考[0,1]
    int p_distance100;      		//+距离
    int p_vaild;                 	//+是否选中状态

    int p_radTable_switch;     		//默认为0--->辐射率 。1--->辐射率表。
    int p_radTable_id;
    int p_radTable_value100;

    int temp100;      			//温度100倍
    char deviceType[2];

    char reserve[6];
}__attribute__ ((packed))ComPointPara;

/* 区域测温参数,pc->dev, dev->pc */
typedef struct {
    int rect_id;     	  			//区域编号[1,20];
    int temptype;       			//区域测温类型[0,2]:其中0=最高温，1=最低温，2=平均温;
    int origin_xcoord;  			//区域x;区域起点（左上角点）的x坐标
    int origin_ycoord;  			//区域y;区域起点（左上角点）的y坐标
    int rect_wide;      			//区域w;区域的宽度。
    int rect_high;      			//区域h;区域的高度。
    int r_radiance100;  			//辐射率100倍[1,100];
    int refer_flag;     			//设为参考[0,1];
    int rect_distance100;           //+距离
    int rect_vaild;            		//+是否有效
    int rect_ReflectTemp100;     	//+加反射温度

    int r_radTable_switch;        	//默认为0--->辐射率 。1--->辐射率表。
    int r_radTable_id;
    int r_radTable_value100;

    short remapping_switch;
    short remapping_color_id;

    int mintemp100;   			//区域最低温100倍
    int maxtemp100;				//区域最高温100倍
    int avgtemp100;   			//区域平均温100倍
    short MaxX;						//区域最高温X坐标
    short MaxY;						//区域最高温Y坐标
    short MinX;         			//区域最低温X坐标
    short MinY;						//区域最低温Y坐标
    char deviceType[2];
    char subStationType;            //变电设备类型

    char reserve[1];        		//2个字节的预留空间
}__attribute__ ((packed))ComRectPara;

/* 线测温,pc->dev, dev->pc */
typedef struct {
    int line_id;   					//线编号[1，20]:0为水平线 1为垂直线;
    int l_xcoord;   				//坐标x;
    int l_ycoord;   				//坐标y;
    int l_x1coord;   				//+终点坐标x
    int l_y1coord;   				//+终点坐标y
    short refer_flag;     			//设为参考[0,1];
    short line_vaild;      			//+是否有效

    int l_radiance100;				//辐射率100倍[1,100]
    int l_distance100;    			//+距离
    int l_temptype;     			// 测温类型[0,2]:其中0=最高温，1=最低温，2=平均温;
    int l_ReflectTemp100;			//+加反射温度

    int l_radTable_switch; 			//默认为0--->辐射率 。1--->辐射率表。
    int l_radTable_id;
    int l_radTable_value100;
    int refer_temptype ;   			//[0:最高温1: 最低温 2:平均温]

    int mintemp100;   				//区域最低温100倍
    int maxtemp100;					//区域最高温100倍
    int avgtemp100;   				//区域平均温100倍
    short MaxX;						//区域最高温X坐标
    short MaxY;						//区域最高温Y坐标
    short MinX;         			//区域最低温X坐标
    short MinY;						//区域最低温Y坐标
    char tempGain;					//温度增益0-100倍 1-10倍
    char name[2];

    char reserve[1];       			//14个字节的预留空间
}__attribute__ ((packed))ComLinePara;

/* 圆测温,pc->dev, dev->pc */
typedef struct {
    int circle_id;     			//区域编号[0,2];
    int center_xcoord;  		//圆心x坐标
    int center_ycoord;  		//圆心y坐标
    int radius;      			//半径

    int refer_flag;     		//设为参考[0,1];
    short circle_vaild;      	//+是否有效

    int c_distance100;  		//+距离
    int c_radiance100;  		//辐射率100倍[1,100];
    int c_ReflectTemp100;				//反射温度
    int c_temptype;    			//区域测温类型[0,2]:其中0=最高温，1=最低温，2=平均温;

    int c_radTable_switch; 		//默认为0--->辐射率 。1--->辐射率表。
    int c_radTable_id;
    int c_radTable_value100;

    int mintemp100;   		//区域最低温100倍
    int maxtemp100;			//区域最高温100倍
    int avgtemp100;  			//区域平均温100倍
    short MaxX;		    		//区域最高温X坐标
    short MaxY;		    		//区域最高温Y坐标
    short MinX;         		//区域最低温X坐标
    short MinY;					//区域最低温Y坐标
    char tempGain;				//温度增益0-100倍 1-10倍
    char name[2];

    char reserve[14];   		//14个字节的预留空间
}__attribute__ ((packed))ComCirclePara;


/* 多边形测温,pc->dev, dev->pc */
typedef struct {
    int polygon_id;     				//区域编号[0,2];
    int nX[POINT_POLYGON_NODE_NUM];		//多边形X坐标
    int nY[POINT_POLYGON_NODE_NUM];		//多边形Y坐标
    int nNode;							//节点个数

    int refer_flag;     				//设为参考[0,1];
    short polygon_vaild;      			//+是否有效

    int p_distance100;  				//+距离
    int p_radiance100;  				//辐射率100倍[1,100];
    int p_ReflectTemp100;				//+加反射温度
    int p_temptype;    					//区域测温类型[0,2]:其中0=最高温，1=最低温，2=平均温;

    int p_radTable_switch; 				//默认为0--->辐射率 。1--->辐射率表。
    int p_radTable_id;
    int p_radTable_value100;

    int mintemp100;   					//区域最低温100倍
    int maxtemp100;						//区域最高温100倍
    int avgtemp100;  					//区域平均温100倍
    short MaxX;		    				//区域最高温X坐标
    short MaxY;		    				//区域最高温Y坐标
    short MinX;         				//区域最低温X坐标
    short MinY;							//区域最低温Y坐标
    char name[2];

    char reserve[14];   				//14个字节的预留空间
}__attribute__ ((packed))ComPolygonPara;

typedef struct {
    unsigned char bvolume_enable;		/*体积计算使能*/
    unsigned char blinedepth_enable;	/*线长度赋值深度使能*/
    unsigned char belevation_enable;	/*俯仰角辅助计算使能*/
}__attribute__ ((packed))ComAbnormalExtendPara;

/* 全局参考参数,pc->dev */
typedef struct {
    int enable;              	//使能，0关闭 1打开
    int ReferTemp100;        	//参考温度100倍
}__attribute__ ((packed))ComTempReference;

/* 测温档位参数,pc->dev */
typedef struct {
    int TempRangeID;		 	//档位号
    int LensId;    			 	//镜头号
    char ImageRotate;			//镜头翻转设置
    char reserve[7];     		//7个字节的预留空间
}__attribute__ ((packed))ComTempRange;

/* 区域温度参数,dev->pc */
typedef struct tagRectTemp{
    int nMinTemp100; 			//区域最低温100倍
    int nMaxTemp100; 			//区域最高温100倍
    int nAvgTemp100;			//区域平均温100倍
    int nMinX;       			//区域最低温X坐标
    int nMiny;	   	  			//区域最低温y坐标
    int nMaxX;	    			//区域最高温X坐标
    int nMaxy;		    		//区域最高温y坐标
    char reserve[10];   		//保留
}__attribute__ ((packed))RectTemp;

/* 等温参数，  PC->DEV */
typedef struct {
    int IsoTemp100;    			//等温温度100倍
    int IsoTempHigh100;			//等温高度100倍
    int IsoTempColorId; 		//等温色的ID
    char reserve[8];           	//8个字节的预留空间
}__attribute__ ((packed))ComIsothermTemp;

/* 报警参数，PC->DEV */
typedef struct {
    int AlarmSwitch;			//报警开关[0,2]：0关闭报警，1最高温报警，2最低温报警;
    int AlarmTemp100;			//报警温度100倍
    int AlarmColorId;			//报警色
    char reserve[8];     		//8个字节的预留空间
}__attribute__ ((packed))ComAlarmTemp;

/* 隐藏配置参数 ，pc->dev， dev->pc */
typedef struct {
    int ShowGrayEnable;		  	//灰度OSD显示
    int CollectEnable;		    //标定数据采集使能
    float GlobalCompensate100;		//当前全局补偿系数100倍
    int BenchmarkTemp100;      	//当前基准温度100倍
    int BenchmarkComTemp100;   	//基准温度补偿的100倍
    int RangeSubFactNum;       	//当前量程分段系数，共几段
    int RangeSubFact1000[5];    //当前量程分段系数的1000倍，预留5段系数
    int ZeroCompensateFact100; 	//调零间补偿系数的100倍
    float  ConfigPara23;   		//para23系数的100倍
    int PrintScreen;         	//截图功能
    int PointDelBadFixel_En;     //单点打死点
    int RectDelBadFixel_En;          //区域打死点
    int Homogeneity;          	//均匀性测试
}__attribute__ ((packed))ComHideMenuPara;

/* 手动自动模式参数,pc->dev,dev->pc  */
typedef struct {
    int ManualType;				//手自动类型
    int TempHighest;  			//手动设置的最高温
    int TempLowest; 			//手动设置的最低温
    char reserve[16];   		//16个字节的预留空间
}__attribute__ ((packed))ComManualPara;

/* osd参数,pc->dev,dev->pc */
typedef struct{
    char color_ruler;   		//色标显示
    char max_temp_obj;  		//最高温显示
    char measure_obj;   		//测温标记
    char time;          		//osd时间
    char min_temp_obj;  		//最低温显示
    char avg_temp_obj;			//平均温显示
    char gps;           		//gps显示
    char video_mode;	  		//视频模式显示
    char emissivity;			//辐射率显示
    char fid3100;               //3100数据
    char pid3100;               //3100数据
    char reserve[8];	 		//保留
}__attribute__ ((packed)) OsdSetting;

/* 融合模式参数,pc->dev,dev->pc */
typedef struct{
    int nFusionType;          	//融合类型[0,2]：0之间，1之上，2之下
    int nFusionAmongHighTemp100;//之间高温100倍
    int nFusionAmongLowTemp100;	//之间低温100倍
    int nFusionAboveTemp100;	//之上温度100倍
    int nFusionBelowTemp100;	//之下温度100倍
    int reserve[8];				//保留
}FusionPara;

/* 画中画模式参数,pc->dev,dev->pc */
typedef struct{
    int nPIP_X;					//画中画X坐标
    int nPIP_Y;					//画中画Y坐标
    int nPIP_W;					//画中画宽度
    int nPIP_H;					//画中画高度
    int nPIP_RATE100;			//倍率
    int reserve[8];				//保留
}PipPara;

/* 定标参数，dev->pc */
typedef struct{
    int ch1100;					//CH1温度100倍
    int ch2100;					//CH2温度100倍
    int ch3100;					//CH3温度100倍
    int ch4100;					//CH4温度100倍
    int ch5100;					//CH5温度100倍
    int ch6100;					//CH6温度100倍
    int BenchmarkTemp100;     	//当前基准温度的100倍
    int BenchmarkComTemp100;  	//基准温度补偿的100倍
    int RangeSubFactNum;      	//当前量程分段系数,共几段
    int RangeSubFact1000[5];   	//当前量程分段系数的1000倍,预留5段系数
    int ZeroCompensateFact100;	//调零间补偿系数的100倍
    int reserve[8];				//保留
}StandardInfo;

/* 融合校准参数命令字 */
enum ADJUST_CMD
{
    ADJUST_N1 = 0,
    ADJUST_X1,
    ADJUST_Y1,
    ADJUST_N2,
    ADJUST_X2,
    ADJUST_Y2,
    ADJUST_N3,
    ADJUST_X3,
    ADJUST_Y3,
    ADJUST_N4,
    ADJUST_X4,
    ADJUST_Y4,
    ADJUST_N5,
    ADJUST_X5,
    ADJUST_Y5,
    ADJUST_N6,
    ADJUST_Z,
};

/* 融合校准参数 ，pc->dev */
typedef struct{
    int cmd;				//命令字
    int value;				//值
    int reserve[8];			//保留
}FusionAdjust;

/* 采集数据参数 */
typedef struct hide_recode_t
{
    int black;				//黑体温度100倍
    float ch1;				//ch1温度
    float ch2;				//ch2温度
    float ch3;				//ch3温度
    float ch4;				//ch4温度
    float ch5;				//ch5温度
    int zero;				//暂时没用，0
    int spot1_g;			//点0的灰度
    int spot2_g;			//点1的灰度
    int rect0_g;			//区域最高灰度
    int rect1_g;         	//区域1最高灰度
    float spot1_t;			//点0温度
    float spot2_t;			//点1温度
    float rect0_t;			//区域最高温度
    float rect1_t;	       	//区域1最高温度

    int zero1;				//暂时没用，0
    int fpga_g;				//调零灰度
    int zero2;				//暂时没用，0
    int zero3;				//暂时没用，0
    int second;				//开机时间
    int zero4;				//暂时没用，0
    float ch1_zero;			//ch1调零温度
    float ch2_zero;			//ch2调零温度
    float ch3_zero;			//ch3调零温度
    float ch4_zero;			//ch4调零温度
    float ch5_zero;			//ch5调零温度
}hide_recode_s;

/* sd卡容量参数，dev->pc */
typedef struct sdinfo_s
{
    int totalMB;			//sd卡总大小
    int usedMB;				//sd卡已使用大小
    int reserver[4];		//保留
}sdinfo_t;

/* 二次分析系统信息结构,dev->pc */
typedef struct {
    int Emissivity100; 				//辐射率100倍
    int Distance100;				//距离100倍
    int Humidity100;				//湿度100倍
    int Transmission100;  			//透射率100倍
    int AmbientTempManu100;			//环境温度100倍
    int  ReflectTemp100;			//+加反射温度
    int TempUnit;					//测温单位
    temp_reference_para_t PartRefeTemp;	//局部参考
    int RefeTemp100;				//参考温度100倍
    int AlarmColorID;				//报警色
    int AlarmSwitch;				//报警温度开关 0关闭 1最高温 2最低温
    int AlarmTemp100;				//报警温度100倍
    int IsothermColorID;			//等温色
    int IsothermTemp100;			//等温温度100倍
    int IsothermHight100;			//等温高度100倍
    int ColorRulerID;				//色标ID
    int VideoMode;               	//图像模式
    int ZoomRate10;					//视频放大倍率10倍
    int Reserve[24];				//保留
}__attribute__ ((packed))ComSysConfigTwice;

/* 生成标定界面参数,pc->dev,dev->pc */
typedef struct{
    int VS;					//VS值
    int VF;					//VF值
    int Gain;				//Gain值
    int INT;				//INT值
    int Reserve[2];			//保留
}FPGAMenuPara;

typedef struct{
    int ZeroGray;	       	//调零灰度
    int MaxGray;			//灰度最大值
    int MinGray;			//灰度最小值
    int Reserve[2];			//保留
}FPGAMenuGray;

typedef struct {
    int xcoord;   			//坐标x;
    int ycoord;   			//坐标y;
    int reserve[2];       	//-2个字节的预留空间
}__attribute__ ((packed))ComPointBadPixel;

typedef struct {
    int start_x;   			//坐标x;
    int start_y;   			//坐标y;
    int width;
    int high;
    int reserve[2];       	//-2个字节的预留空间
}__attribute__ ((packed))ComRectBadPixel;

typedef struct {
    int autofocus_mode;
    int laser_focousoffset;
    int general_focousoffset;
    int fast_focousoffset;
}ComFocusOffset;

typedef struct {
    char mac_addr[20];/*需要连接的设备的MAC地址*/
    int function_mode;/*1-扫描 2-连接 3-断开连接 4-获取配对记录 5-清除配对记录*/
}BleInfo;

typedef struct {
    int scan_state;/*蓝牙扫描状态 -1-异常 0-初始化 1-开始扫描 2-正在扫描 3-扫描完成*/
    int conn_state;/*0-断开连接 1-正在连接 2-已连接*/
    int pair_state;/*蓝牙配对信息状态 -1-异常 0-初始化 1-开始读取 2-开始清除 3-正在读取 4-读取完成 5-清除成功*/
}BleState;

/* 气体模式参数,pc->dev,dev->pc */
typedef struct{
    int SensibilitySwitch;      //灵敏度开关 0 - 关 1-开
    int SensibilityRange;       //灵敏度档位 1-16
    int SensibilityGain;        //灵敏度增益 1-9
    int reserve[4];             //保留
}GasPara;

typedef struct
{
    char latitude[20];/*纬度*/
    char longitude[20];/*经度*/
}__attribute__ ((packed))ComGPSValue ;
/* @ description : 屏幕列表 */
typedef enum {
    SCREEN_480_272 = 0x00,
    SCREEN_800_480,
    SCREEN_1920_1080,
} SCREEN_SIZE;

struct IntArrayData {
    QVector<int> data;
    int length;
};

//struct IntArrayData {
//    QSharedPointer<int> data;
//    int length;
//};

#endif /* HI384_PROTOCOL_H_ */
