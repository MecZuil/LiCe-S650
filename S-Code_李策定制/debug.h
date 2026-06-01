#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

extern int debug_level;
extern int debug_object;
extern int debug_redirect;
extern FILE *debug_fp;

extern int debug_dev_level;
extern int debug_dev_object;

extern int malloc_switch;
extern int malloc_redirect;
extern FILE *malloc_fp;

#define DEBUG_CNTER		        	0x0000001	/*中心任务分发模块*/
#define DEBUG_VIDEO		    		0x0000002	/*实时视频管理模块*/
#define DEBUG_CAPTURE		    	0x0000004	/*捕获模块*/
#define DEBUG_DISPLAY		    	0x0000008	/*显示模块*/
#define DEBUG_ENC		    		0x0000010	/*编码模块*/
#define DEBUG_VIDEO_ALG		    	0x0000020	/*图像处理模块*/
#define DEBUG_TEMPER_OSD		    0x0000040	/*OSD叠加模块*/
#define DEBUG_XML_SYS		    	0x0000080	/*SYS XML读取*/
#define DEBUG_XML_ENC		    	0x0000100	/*ENC XML读取*/
#define DEBUG_XML_CONFIG		    0x0000200	/*CONFIG XML读取*/
#define DEBUG_CAL					0x0000400	/*计算模块*/
#define DEBUG_PIC_TWICE				0x0000800	/*照片二次分析模块*/
#define DEBUG_HIR_TWICE				0x0001000	/*灰度流二次分析模块*/
#define DEBUG_PACKAGE_JPEG			0x0002000	/*照片打包模块*/
#define DEBUG_NET_FTP				0x0004000	/*ftp模块*/
#define DEBUG_IAMGE_RESIZE			0x0008000	/*图像缩放处理模块*/
#define DEBUG_NET_RTSP				0x0010000	/*rtsp模块*/
#define DEBUG_NET_SESSION			0x0020000	/*服务器流会话模块*/
#define DEBUG_NET_CLIENT			0x0040000	/*客户端会话模块*/
#define DEBUG_SYSTEM_OPT			0x0080000	/*系统操作模块*/
#define DEBUG_AVI					0x0100000	/*AVI录像模块*/
#define DEBUG_MP4					0x0200000	/*MP4录像模块*/
#define DEBUG_XML_BASE				0x0400000	/*XML基础模块*/
#define DEBUG_CLIENT_CENTER			0x0800000	/*客户端中心模块*/
#define DEBUG_TEMPER_ALG			0x1000000	/*温度计算模块*/
#define DEBUG_ABNORMAL				0x2000000	/*异常处理模块*/
#define DEBUG_FIFO					0x4000000	/*FIFO处理模块*/
#define DEBUG_PMS_PKG				0x8000000	/*PMS打包处理模块*/

#define DEBUG_DEV		    		0x00001
#define DEBUG_DEV_LASER		    	0x00002
#define DEBUG_DEV_AUDIO				0x00004
#define DEBUG_DEV_LTE				0x00008
#define DEBUG_DEV_GPS				0x00010
#define DEBUG_DEV_FILE				0x00020
#define DEBUG_DEV_SERIAL			0x00040
#define DEBUG_DEV_SPEECH			0x00080
#define DEBUG_DEV_TEMP_HUM			0x00100
#define DEBUG_DEV_BLE				0x00200


#define ERR_LEVEL				0x01
#define WARN_LEVEL				0x02
#define INIT_LEVEL				0x04	/*初始化必打印消息*/
#define INFO_LEVEL				0x08	/*非常感兴趣的消息*/
#define DBG_LEVEL_LOW			0x10	/*用于详细调试非定时*/
#define DBG_LEVEL_MID			0x20	/*用于详细调试定时消息*/
#define DBG_LEVEL_HIGH			0x40	/*用于详细调试定时消息( < 1s)*/
#define RUD_LEVEL				0x80	/*用于完整调试、大量、定时、高发( < video frame)*/

#define object_debug(OBJECT, LEVEL, fmt, args...)  \
do {                                      \
    if ( (OBJECT & debug_object) && (LEVEL & debug_level) )  {             \
        if(debug_redirect && debug_fp){									\
            fprintf(debug_fp, fmt, ##args);   						\
            fflush(debug_fp);												\
        }															\
        else													\
            printf(fmt, ##args);   \
    }																\
} while(0)

#define object_printf(OBJECT, LEVEL, fmt, args...)  \
do {                                      \
    if ( (OBJECT & debug_object) && (LEVEL & debug_level) )  {             \
        if(debug_redirect && debug_fp){									\
            fprintf(debug_fp, "(%s:%d): " fmt, __func__, __LINE__, ##args);   \
            fflush(debug_fp);												\
        }																	\
        else													\
            printf("(%s:%d): " fmt, __func__, __LINE__, ##args);   \
    }																\
} while(0)

#define dev_debug(OBJECT, LEVEL, fmt, args...)  \
do {                                      \
    if ( (OBJECT & debug_dev_object) && (LEVEL & debug_dev_level) )  {             \
        if(debug_redirect && debug_fp){									\
            fprintf(debug_fp, fmt, ##args);   						\
            fflush(debug_fp);												\
        }															\
        else													\
            printf(fmt, ##args);   \
    }																\
} while(0)

#define dev_printf(OBJECT, LEVEL, fmt, args...)  \
do {                                      \
    if ( (OBJECT & debug_dev_object) && (LEVEL & debug_dev_level) )  {             \
        if(debug_redirect && debug_fp){									\
            fprintf(debug_fp, "(%s:%d): " fmt, __func__, __LINE__, ##args);   \
            fflush(debug_fp);												\
        }																	\
        else													\
            printf("(%s:%d): " fmt, __func__, __LINE__, ##args);   \
    }																\
} while(0)

#define malloc_printf(fmt, args...)  \
do {                                      \
    if ( malloc_switch )  {             \
        if(malloc_redirect && malloc_fp){									\
            fprintf(malloc_fp, fmt, ##args);   \
            fflush(malloc_fp);												\
        }																	\
        else													\
            printf(fmt, ##args);   \
    }																\
} while(0)

#define level_printf(LEVEL, fmt, args...)  \
do {                                      \
    if (LEVEL & debug_level) {             \
        if(debug_redirect && debug_fp){									\
            fprintf(debug_fp, "(%s:%d): " fmt, __func__, __LINE__, ##args);   \
            fflush(debug_fp);												\
        }																	\
        else														\
            printf("(%s:%d): " fmt, __func__, __LINE__, ##args);   \
    }																\
} while(0)

#define warn_printf(fmt, args...)   \
        level_printf(WARN_LEVEL, "\x1B[32mwarning: " fmt"\e[0m", ##args)
#define err_printf(fmt, args...)   \
        level_printf(ERR_LEVEL, "\x1B[31merror: " fmt"\e[0m", ##args)


#endif // DEBUG_H
