#ifndef HP_BT1036_H
#define HP_BT1036_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <fcntl.h>
#include <QString>
#include <QDebug>
#include <termios.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#include "debug.h"
#include "mymalloc.h"
#include "serial.h"
#include "mycstdlib.h"

using namespace std;

#define MODULE_WRITE(cmd,fd)        fwrite(cmd, 1, strlen(cmd), fd)

#define AT_WRAP                     "\r\n"

#define AT_BAUD                     "AT+BAUD\r\n"               //波特率查询
#define AT_STAT                     "AT+STAT\r\n"               //查询BLE模块profile当前状态
#define AT_RESTORE                  "AT+RESTORE\r\n"            //恢复出厂设置
#define AT_REBOOT                   "AT+REBOOT\r\n"             //重启模块
#define AT_ADDR                     "AT+ADDR\r\n"             //重启模块
#define AT_PROFILE                  "AT+PROFILE\r\n"             //重启模块
#define AT_MODE_SPP                 "AT+MODE=1\r\n"            //查询BLE模块当前模式
#define AT_PROFILE_MODE             "AT+PROFILE=339\r\n"        //设置BLE模块模式
#define AT_BLE_SCAN                 "AT+SCAN=1\r\n"             //扫描周围可连接的蓝牙名称
#define AT_BLE_A2DPCONN             "AT+A2DPCONN="              //连接蓝牙 --- 不需要加 /r/n
#define AT_SPPCONN                  "AT+SPPCONN="               //透传模式指定手机蓝牙
#define AT_BLE_SPPCONN              "AT+SPPCONN=c42b44d2c054\r\n"  //SPP模式指定手机蓝牙
#define AT_BLE_SPPDISC              "AT+SPPDISC\r\n"               //SPP模式指定手机蓝牙
#define AT_BLE_SPPSTAT              "AT+SPPSTAT\r\n"               //SPP模式状态
#define AT_BLE_STAT                 "AT+STAT\r\n"               //SPP模式状态
#define AT_BLE_A2DPDISC             "AT+A2DPDISC\r\n"           //断开A2DP蓝牙
#define AT_BLE_HFPDISC              "AT+HFPDISC\r\n"            //断开HFP蓝牙
#define AT_BLE_VER                  "AT+VER\r\n"                //断开HFP蓝牙
#define AT_BLE_DSCA                 "AT+DSCA\r\n"               //断开所有连接
#define AT_BLE_A2DPSTAT             "AT+A2DPSTAT\r\n"           //查询蓝牙连接状态
#define AT_BLE_PLIST                "AT+PLIST\r\n"              //查询蓝牙配对记录
#define AT_BLE_PLIST_CLEAR          "AT+PLIST=0\r\n"            //清除所有的蓝牙配对记录
#define AT_BAUD_460800              "AT+BAUD=460800\r\n"            //设置波特率
#define AT_BLE_AUTOCONN_OFF         "AT+AUTOCONN=0\r\n"         //关闭自动连接

#define AT_I2SCFG                   "AT+I2SCFG\r\n"             //查询I2S模式
#define AT_I2SCFG_MASTER            "AT+I2SCFG=1\r\n"           //设置模块的I2S为主机模式
#define AT_I2SCFG_SLAVE             "AT+I2SCFG=3\r\n"           //设置模块的I2S为从机模式
#define AT_AUDROUTE                 "AT+AUDROUTE\r\n"           //查询音频路由模式
#define AT_AUDROUTE_ANALOG          "AT+AUDROUTE=0\r\n"         //设置为普通模式
#define AT_AUDROUTE_BLE             "AT+AUDROUTE=2\r\n"         //设置为通话对讲模式
#define AT_AUDLOOP                  "AT+AUDLOOP\r\n"            //查询音频回环模式
#define AT_AUDLOOP_CLOSE            "AT+AUDLOOP=0\r\n"          //取消音频回环模式---转换回环模式的时候需要先取消再设置
#define AT_AUDLOOP_MIC              "AT+AUDLOOP=2\r\n"          //设置模拟输入，I2S输出
#define AT_AUDLOOP_SPK              "AT+AUDLOOP=3\r\n"          //设置I2S输入，模拟输出

#define AT_GATTSEND                 "AT+GATTSEND="              //GATT串口通讯

#define AT_TPMODE                   "AT+TPMODE\r\n"             //透传模式查询
#define AT_TPMODE_OPEN              "AT+TPMODE=1\r\n"           //透传模式开启
#define AT_TPMODE_CLOSE             "AT+TPMODE=0\r\n"           //透传模式关闭
#define AT_TPMODE_STOP_AUTO         "AT+AUTOCONN=0\r\n"         //透传模式关闭自动连接
#define AT_SPPCONN_C42B44D2C054     "AT+SPPCONN=C42B44D2C054\r\n"

/*为了省电我们是在需要蓝牙的时候才会开启蓝牙，刚上电时进行指令校验查询比较慢，所以我们提供自我记录来设置默认模块的状态*/
static int g_module_init = 0;
static int g_ble_profile_init = 0;
static int g_ble_trans_mode = 0;   /* 0-指令模式 1-透传模式 */

static char g_ble_conn_dev[100] = {0};/*成功连接的蓝牙*/
static int g_ble_conn_dev_length = 0;/*成功连接的蓝牙信息长度*/
static char *g_ble_scan_result = NULL;/*扫描后的可连接的蓝牙*/
static int g_ble_scan_length = 0;/*扫描结果长度*/
static char *g_ble_pair_info = NULL;/*当前模块配对成功的设备信息*/
static int g_ble_pair_info_length = 0;/*配对成功的设备信息长度*/
static pthread_t g_ble_thread_id = 0;/*蓝牙扫描线程ID*/
static int g_ble_thread_quit = 1;/*蓝牙扫描线程退出标记*/
static pthread_t g_gatt_thread_id = 0;/*蓝牙GATT串口通讯线程ID*/
static int g_gatt_thread_quit = 1;/*蓝牙GATT串口通讯线程退出标记*/
static pthread_t g_transparent_thread_id = 0;/*蓝牙透传串口通讯线程ID*/
static int g_transparent_thread_quit = 1;/*蓝牙透传串口通讯线程退出标记*/
static int g_ble_spp_link = 0;
//static int g_ble_spp_link = 0;
static int g_pms_ble_link = 0;
static int g_serial_fd = 0;
static int g_serial_recv_quit = 0;
static pthread_t g_recv_thread_id;
static char g_conn_mac_addr[12] = {0};/*蓝牙连接的MAC地址*/
static FILE *g_ble_fp = NULL;/*通讯文件指针*/
static FILE *g_serial_fp = NULL;/*通讯文件指针*/
static int g_ble_fd = 0;
static int g_ble_get_info = 0;
static int g_serial_baudrate = 0;
static int g_serial_transparent_block_type = 0;     /*0-不阻塞 1-阻塞*/

/*为了防止我们设置重刷新后再处理过程中进行了标志重置导致重刷新的不响应这里进行线程锁处理*/
static pthread_mutex_t g_ble_handle_lock = PTHREAD_MUTEX_INITIALIZER;       //蓝牙处理的读写锁
static pthread_mutex_t g_ble_comm_lock = PTHREAD_MUTEX_INITIALIZER;         //蓝牙通讯的读写锁
/*为了防止我们的连接、扫描等操作状态彼此不受干扰，这里进行标志区分设置*/
static int g_ble_scan_state = 0;/*蓝牙扫描状态 -1-异常 0-初始化 1-开始扫描 2-正在扫描 3-扫描完成*/
static int g_ble_conn_state = 0;/*蓝牙连接状态 -1-异常 0-初始化 1-开始连接 2-断开连接 3-正在获取状态 4-连接完成 5-断开成功*/
static int g_ble_pair_state = 0;/*蓝牙配对信息状态 -1-异常 0-初始化 1-开始读取 2-开始清除 3-正在读取 4-读取完成 5-清除成功*/
/*查询的状态修改和设置的连接状态修改进行区分设置*/
static int g_ble_a2dp_state = 0;/*0-断开连接 1-正在连接 2-已连接*/
static int g_pms_get_link_msg = 0;

static int (*g_ble_data_call)(unsigned char *data, int datalen);

int ble_function_comm(const char *cmd, char *reply, const char *determine);
int ble_transparent_send(const char* data, int data_len);
int ble_gatt_send(char* data, int data_len);
int ble_audio_init(int i2s_mode, int ble_mode, int analog_mode);
int ble_get_pair_info_length();
int ble_copy_pair_info(char *save_pair_info);//配对记录信息获取
int ble_pair_init(int pair_flag);//配对记录功能设置
int ble_get_conn_dev_length();//已连接设备信息长度获取
int ble_copy_dev_info(char *save_dev_info);//已连接设备信息获取
int ble_a2dp_connect(char *mac_addr, int conn_flag);//蓝牙连接设置
int ble_get_scan_result_length();//可连接设备信息长度获取
int ble_copy_scan_result(char *save_result);//可连接设备信息获取
int ble_scan_init();//蓝牙扫描设置
void ble_get_state(int *scan_state, int *a2dp_state, int *pair_state);//获取蓝牙的各种状态
int ble_mode_init();//蓝牙模式初始化，开启蓝牙连接、配对等信息轮询线程
int ble_mode_uninit();//蓝牙模式反初始化
void ble_transmission_reset();//蓝牙模式重置
int ble_gatt_init(int (*ble_data_call)(unsigned char *data, int datalen));//蓝牙GATT服务初始化
int ble_gatt_uninit();//蓝牙GATT服务反初始化
int ble_transmission_start(QString addr);//蓝牙设置透传模式
void ble_transmission_stop();//蓝牙关闭透传模式
int ble_profile_update(int ble_mode);
int ble_transparent_transmission_update(int switch_value);
int ble_function_comm(char *cmd, char *reply, char *determine, char comm_timeout, int retry_limit);
int ble_baud_modify(char *dev_name, int serial_baudrate);
int ble_transparent_transmission_init(char *dev_name, int serial_baudrate,
                    int (*ble_data_call)(unsigned char *data, int datalen), int block_type, int ble_mode);//蓝牙透传服务初始化
int ble_transparent_transmission_uninit();//蓝牙透传服务反初始化
int bt1036_module_init(char *dev_name, int serial_baudrate);//蓝牙模块初始化，获取设备流
int bt1036_module_uninit();//蓝牙模块反初始化
int bt1036_scan_ble_info();

int bt986_mode_update();
int bt986_transmission_tpmode(int switch_value);
int bt986_transmission_init(char *dev_name, int serial_baudrate,
                            int (*ble_data_call)(unsigned char *data, int datalen));
int bt986_transmission_uninit();
int bt986_transmission_start(QString addr);
int bt986_scan_ble_info();
int bt986_transmission_save(const char* data, int data_len);
int bt986_transmission_send(const char* sdata, int data_len);

#endif // HP_BT1036_H
