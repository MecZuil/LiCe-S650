#ifndef PMS_PROTOCOL_PKG_H
#define PMS_PROTOCOL_PKG_H

#include <QDebug>
#include <QString>
#include <QStringList>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

#include "debug.h"
#include "crc.h"
#include "hpxmlreader.h"
#include "hp_bt1036.h"

typedef struct {
    int pkg_number;         /*报文序号*/
    int info_type;          /*回调信息类型*/
    char task_file[30];     /*业务数据文件*/
} pms_pkg_callback_info_t;

#pragma pack (1)
typedef struct pms_package_head_s	//包头信息
{
    unsigned int head;		        //报文头 - 0xEB90EB90
    unsigned char version;		    //版本号
    unsigned short number;	        //报文序号
    unsigned char request_flag;	    //请求标记  请求:0x00 响应:0x01
    unsigned long long pkg_len;		//整个数据包长度，包含包头和包尾
    unsigned int pkg_type;          //报文类型
    unsigned char compress_flag;    //压缩标记  无压缩:0x00 gzip压缩:0x01
    unsigned char encryption_flag;  //加密标记  无加密:0x00 加密:0x01
    unsigned char manufacturer;     //厂商 FLIR:0x50    其他厂家:0x00
    unsigned char reserve[15];      //预留-填充0
    unsigned char business_format;  //业务数据格式  XML:0x01
    unsigned long long business_len;//业务数据长度
    unsigned long long direction_len;//业务数据长度
}__attribute__((packed))pms_package_head_t;

typedef struct pms_package_end_s	//包头信息
{
    unsigned int verify;            //校验值 采用 CRC32 从报文头至检测数据文件部分的CRC校验
    unsigned char end;              //尾部标记
}__attribute__((packed))pms_package_end_t;
#pragma pack()


typedef struct pms_package_dat_s	    //dat通用报文信息
{
    int fileLength;            //文件长度
    unsigned char version[4];               //版本号
    long long fileCreateTime;	//文件生成时间
    char device_name[118];		//站点名称
    char device_code[42];          //站点ID
    unsigned char weather;              //天气
    float ir_ambient_temp;              //温度
    int8_t ir_relative_humidity;                  //湿度
    char equipFactory[32];     //厂商
    char equipType[32];        //仪器型号
    char equipId[4];           //仪器版本号
    char equipSn[32];          //仪器序列号
    float systemP;
    short datNum;	            //图谱数量
    double longitude;           //经度（不支持
    double latitude;           //纬度（不支持
    int height;           //海拔（不支持
    unsigned char reversse[204];           //预留
}__attribute__((packed))pms_package_dat_t;

typedef enum {
    e_PMS_PKG_TYPE_TASK_DISTRIBUTE,  //任务下发
    e_PMS_PKG_TYPE_TASK_CONFIRM,     //任务接收确认
    e_PMS_PKG_TYPE_CONNECT_REQUEST,  //请求连接
    e_PMS_PKG_TYPE_CONNECT_CONFIRM,  //请求连接确认
    e_PMS_PKG_TYPE_DETECTION_UPLOAD, //检测数据文件上传
    e_PMS_PKG_TYPE_DETECTION_CONFIRM,//检测数据文件接收确认
    e_PMS_PKG_TYPE_MAX,
    e_PMS_PKG_TYPE_UNKNOW,
} E_PMS_PKG_TYPE;

#define PMS_BUSINESSFILE_NAME                    "/home/root/pms_task.dat"
#define PMS_BUSINESSFILE_XMLNAME                 "/home/root/pms_down.xml"

#define PACKAGE_HEAD_1              0xEB
#define PACKAGE_HEAD_2              0x90
#define PACKAGE_HEAD_3              0xEB
#define PACKAGE_HEAD_4              0x90
#define PACKAGE_END                 0x03

static unsigned int g_pms_pkg_types[e_PMS_PKG_TYPE_MAX] = {
    0x00000001, /*e_PMS_PKG_TYPE_TASK_DISTRIBUTE*/
    0x80000001, /*e_PMS_PKG_TYPE_TASK_CONFIRM*/
    0x00000002, /*e_PMS_PKG_TYPE_CONNECT_REQUEST*/
    0x80000002, /*e_PMS_PKG_TYPE_CONNECT_CONFIRM*/
    0x00000003, /*e_PMS_PKG_TYPE_DETECTION_UPLOAD*/
    0x80000003, /*e_PMS_PKG_TYPE_DETECTION_CONFIRM*/
};

typedef enum {
    e_STAGE_HEAD_NONE = 0x00,
    e_STAGE_HEAD_1 = 0x01,
    e_STAGE_HEAD_2 = 0x02,
    e_STAGE_HEAD_3 = 0x03,
    e_STAGE_HEAD_4 = 0x04,
    e_STAGE_HEAD_DATA = 0x2F,           /*sizeof(pms_package_head_t)*/
    e_STAGE_BUSINESS_RECV = 0x30,
    e_STAGE_DETECTION_RECV = 0x32,
} E_STAGE_FLAG;


static HpXmlReader m_xmlReader;
static pms_package_head_t g_pms_package_head = {0};
static pms_package_end_t g_pms_package_end = {0};
static pms_pkg_callback_info_t g_pms_pkg_info = {0};
static unsigned long long g_detection_datalen = 0;
static unsigned int g_crc32_value = 0xFFFFFFFF;
static int (*g_pms_pkg_callb)(pms_pkg_callback_info_t pms_pkg_info);

#include <stdio.h>
#include <pthread.h>

// 全局文件指针和互斥锁
static FILE *log_file = NULL;
static pthread_mutex_t file_mutex = PTHREAD_MUTEX_INITIALIZER;

void cleanup_log_file();
void addTextToMyLogFile(unsigned char *package, int packagelen);

void analysis_pms_task_dat();
void pms_protocol_pkg_analysis(unsigned char *package, int packagelen);
int pms_protocol_pkg_create_head(pms_package_head_t *pms_package_head, int pkg_number, int pkg_type,
                            unsigned long long business_len, unsigned long long detection_len);
int pms_protocol_pkg_dat_head(pms_package_dat_t *pms_package_head);
int pms_protocol_pkg_create_end(pms_package_end_t *pms_package_end);

int pms_protocol_pkg_update_end(pms_package_end_t *pms_package_end, void *buffer, unsigned int size);
int pms_protocol_init(int (*pms_pkg_callb)(pms_pkg_callback_info_t pms_pkg_info));
void pms_protocol_uninit();

#endif // PMS_PROTOCOL_PKG_H
