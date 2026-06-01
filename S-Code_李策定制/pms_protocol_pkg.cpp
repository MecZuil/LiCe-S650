/**********************************************************************************************

                  版本所有（C）, 浙江红谱科技有限公司

 **********************************************************************************************

  文 件 名     : pms_protocol_pkg.c
  生成日期     : 2024-03-08
  功能描述     : PMS3.0 协议包处理模块功能设置
  函数列表     :

***********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

#include "debug.h"
#include "crc.h"
#include "pms_protocol_pkg.h"


FILE *g_pms_business_fp = NULL;
void addTextToMyLogFile(unsigned char *package, int packagelen) {
    if (!package || packagelen <= 0) return;

    // 线程安全锁
    pthread_mutex_lock(&file_mutex);

    // 打开文件（首次调用时初始化）
    if (!log_file) {
        log_file = fopen("/run/media/mmcblk2p1/pms_hex_log.txt", "a+");
        if (!log_file) {
            pthread_mutex_unlock(&file_mutex);
            return;
        }
    }

    // 写入十六进制数据
    for (int i = 0; i < packagelen; i++) {
        fprintf(log_file, "%02X ", package[i]); // 格式化为2位十六进制‌:ml-citation{ref="8" data="citationList"}
    }
    fprintf(log_file, "\n"); // 换行分隔每次调用‌:ml-citation{ref="1" data="citationList"}

    // 立即刷新缓冲区确保数据写入磁盘
    fflush(log_file);

    pthread_mutex_unlock(&file_mutex);
}

// 程序退出时关闭文件
void cleanup_log_file() {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}

int pms_task_add_xml_msg()
{
    FILE *fp;
    char buffer[4096];
    size_t bytesRead;

    fp = fopen("/home/root/pms_task.dat", "r");
    if (fp == NULL) {
        perror("无法打开输入文件");
        return 1;
    }

    bytesRead = fread(buffer, 1, 4096 - 1, fp);
    fclose(fp);
    buffer[bytesRead] = '\0';

    if (strstr(buffer, "<?xml") != NULL) {
        rename("/home/root/pms_task.dat", "/home/root/pms_down.xml");
        remove("pms_task.dat");
        qDebug("文件已包含XML声明\n");
        return 0;
    }

    FILE *temp = fopen("temp.xml", "w+");
    if (temp == NULL) {
        qDebug("无法创建临时文件");
        return 1;
    }

    // 4. 写入XML声明和原始内容
    fprintf(temp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fwrite(buffer, 1, bytesRead, temp);
    fclose(temp);

    // 5. 替换原始文件
    rename("/home/root/pms_task.dat", "/home/root/pms_down.xml");
    remove("pms_task.dat");

//    printf("已成功添加XML声明\n");
    return 0;
}

void analysis_pms_task_dat()
{
    if(0 == pms_task_add_xml_msg())
    {
        QStringList mainTaskNameList = m_xmlReader.readXml_more(PMS_BUSINESSFILE_XMLNAME,"main_task","name");
        if(mainTaskNameList.count() != 0)
        {
            qDebug() << "lzj test xml main_task name == > " << mainTaskNameList;
        }
        else
        {
            return;
        }
        QString newTaskFileName = mainTaskNameList.at(0);
        newTaskFileName = newTaskFileName.replace(' ', '_').replace("(", "_").replace(")", "_").replace("-", "_").replace(":", "_");
        qDebug() << "newTaskFileName.count" << newTaskFileName.count();
        if(newTaskFileName.count() > 17)
            newTaskFileName = newTaskFileName.left(17)+"…";
//        newTaskFileName = QString(newTaskFileName.toUtf8().toBase64());
        QString mainTaskName = "cp " + QString(PMS_BUSINESSFILE_XMLNAME) + " /run/media/mmcblk2p1/" + newTaskFileName + ".xml";
//        const char* newPmsXmlName = mainTaskName.toLatin1().constData();
        qDebug() << __func__ << mainTaskName << mainTaskName.toLocal8Bit().constData();
        system(mainTaskName.toLocal8Bit().constData());
        system("sync");
    }
}

/**********************************************************************************************

    函 数 名     : pms_protocol_pkg_analysis
    功能描述     : PMS协议解析
    输入参数     :
            unsigned char *package                  协议包数据
            int packagelen                          协议包长度
    输出参数     :
            g_pms_pkg_callb                         信息回调
    返 回 值     :
                无
 ***********************************************************************************************/
void pms_protocol_pkg_analysis(unsigned char *package, int packagelen)
{
    g_pms_ble_link = 1;
    static char *p_pms_package_head = NULL;
    static char *p_pms_package_end = NULL;
    static unsigned long long stage_flag = e_STAGE_HEAD_NONE;  /*数据接收阶段标记 - 0x00 待处理报文 0x01 接收到报文头*/
    static unsigned long long business_write_len = 0;   /*业务数据已写长度*/
    static unsigned long long detection_write_len = 0;  /*检测数据已写长度*/
    static char pkg_detection_count = 0;
    static int is_crc32_cal = 0;
    int previous_index = -1;
    int i = 0;
    bool isxmlGet = false;
    for( i = 0; i < packagelen; i++ ) {
        stage_flag++;   /*保证我们判断的是连贯的数据*/
//        if(i == 0)
//        {
//            qDebug() << __func__ << __LINE__ << "stage_flag" << stage_flag;
//            qDebug() << package[0] << package[1] << package[2] << package[3];
//        }
        //逐字节进行报文头判断 报文头：0xEB90EB90
        if( (package[i] == PACKAGE_HEAD_1 && stage_flag == e_STAGE_HEAD_1)
                || (package[i] == PACKAGE_HEAD_2 && stage_flag == e_STAGE_HEAD_2)
                || (package[i] == PACKAGE_HEAD_3 && stage_flag == e_STAGE_HEAD_3)
                || (package[i] == PACKAGE_HEAD_4 && stage_flag == e_STAGE_HEAD_4) ) {    /*处理报文头*/
            if( stage_flag == e_STAGE_HEAD_1 ) {

//                qDebug() << __func__ << __LINE__;
                memset(&g_pms_package_head, 0x00, sizeof(pms_package_head_t));   /*清空报文头*/
                memset(&g_pms_package_end, 0x00, sizeof(pms_package_end_t));    /*清空报文尾*/
                p_pms_package_head = (char *)&g_pms_package_head;   /*初始化指针地址*/
                p_pms_package_end = (char *)&g_pms_package_end;     /*初始化指针地址*/
                business_write_len = 0; /*业务数据写入长度归零*/
                detection_write_len = 0;/*检测数据写入长度归零*/
                pkg_detection_count = 0;
                g_detection_datalen = 0;
                g_pms_get_link_msg = 0;
                g_crc32_value = 0xFFFFFFFF;
                is_crc32_cal = 1;   /*开始CRC32校验, 此处设置CRC校验之后但是如果后续比如第二个数据就错误了还要进行后续的CRC校验吗？*/
            }

            *p_pms_package_head++ = package[i];
        }
        else if( stage_flag > e_STAGE_HEAD_4 && stage_flag <= e_STAGE_HEAD_DATA && is_crc32_cal == 1 ) {   /*处理报文头结构数据*/
//            qDebug() << __func__ << __LINE__;
            *p_pms_package_head++ = package[i];
            if( stage_flag == e_STAGE_HEAD_DATA ) {   /*解析报文头*/
                int pkg_type_index = 0;
                /*实际接收数据需要进行高低字节转换*/
                g_pms_package_head.head = ntohl(g_pms_package_head.head);
                g_pms_package_head.number = ntohs(g_pms_package_head.number);
                g_pms_package_head.pkg_len = be64toh(g_pms_package_head.pkg_len);
                g_pms_package_head.pkg_type = ntohl(g_pms_package_head.pkg_type);
                g_pms_package_head.business_len = be64toh(g_pms_package_head.business_len);

                object_printf(DEBUG_PMS_PKG, DBG_LEVEL_LOW, "head:0x%08X   number:%d   pkg_len:%lld   pkg_type:0x%08X   business_len:%lld !\n",
                            g_pms_package_head.head, g_pms_package_head.number, g_pms_package_head.pkg_len,
                            g_pms_package_head.pkg_type, g_pms_package_head.business_len);

                for( pkg_type_index = 0; pkg_type_index < sizeof(g_pms_pkg_types)/sizeof(g_pms_pkg_types[0]); pkg_type_index++ ) {
                    if( (g_pms_pkg_types[pkg_type_index] == g_pms_package_head.pkg_type
                            && (g_pms_package_head.pkg_type>>31) == g_pms_package_head.request_flag) || g_pms_package_head.pkg_type == g_pms_pkg_types[e_PMS_PKG_TYPE_CONNECT_CONFIRM]) { /*包类型和请求情况一致*/
                        if( g_pms_package_head.business_len ) { /*存在业务数据，这里处理将业务数据写入到文件中*/
                            if( g_pms_business_fp == NULL ) {
                                g_pms_business_fp = fopen(PMS_BUSINESSFILE_NAME, "w+");
                                if( g_pms_business_fp == NULL ) {
                                    err_printf("%s open fail !\n", PMS_BUSINESSFILE_NAME);
                                }
                            }
                            else {
                                warn_printf("%s file has an abnormal status !\n", PMS_BUSINESSFILE_NAME);
                                fseek(g_pms_business_fp, 0, SEEK_SET);  /*跳转到文件头*/
                            }
                        }
                        break;
                    }
                }

                if( pkg_type_index >= sizeof(g_pms_pkg_types)/sizeof(g_pms_pkg_types[0]) ) {  /*报文头数据异常 未找到当前已知定义*/

                    qDebug("pms pkg error:request_flag:%d   pkg_type:0x%08X   business_format:%d !\n",
                                    g_pms_package_head.request_flag, g_pms_package_head.pkg_type, g_pms_package_head.business_format);
                    stage_flag = e_STAGE_HEAD_NONE;
                    if( g_pms_pkg_callb ) {
                        memset(&g_pms_pkg_info, 0x00, sizeof(g_pms_pkg_info));
                        g_pms_pkg_info.info_type = e_PMS_PKG_TYPE_UNKNOW;
                        g_pms_pkg_callb(g_pms_pkg_info);
                    }
                }
            }
        }
        else if( stage_flag >= e_STAGE_BUSINESS_RECV && business_write_len < g_pms_package_head.business_len ) {
//            qDebug() << __func__ << __LINE__;
            int handle_need_len = ( (g_pms_package_head.business_len-business_write_len) > (packagelen-i) ) ?
                                    (packagelen-i) : (g_pms_package_head.business_len-business_write_len);

            if( g_pms_business_fp != NULL ) {
                int write_len = 0;
                write_len = fwrite(package+i, 1, handle_need_len, g_pms_business_fp);
//                qDebug() << __func__ << "write_len" << write_len;
                if( write_len != handle_need_len ) {
                    warn_printf("%s file write fail !\n", PMS_BUSINESSFILE_NAME);
                }
            }

            i += handle_need_len-1;/*跳转到已处理的最后一个字节*/
            business_write_len += handle_need_len;/*已经处理掉的业务数据*/

            if( business_write_len == g_pms_package_head.business_len ) {
                object_printf(DEBUG_PMS_PKG, DBG_LEVEL_LOW, "business_write_len:%lld   i:%d   packagelen:%d !\n",
                                business_write_len, i, packagelen);
                if( g_pms_business_fp != NULL ) {
                    fclose(g_pms_business_fp);   /*关闭文件*/
                    g_pms_business_fp = NULL;
//                    qDebug() << __func__ << "g_pms_package_head.pkg_type" << g_pms_package_head.pkg_type;
//                    qDebug() << __func__ << "g_pms_pkg_types[e_PMS_PKG_TYPE_CONNECT_CONFIRM]" << g_pms_pkg_types[e_PMS_PKG_TYPE_CONNECT_CONFIRM];

                    if(g_pms_package_head.pkg_type != g_pms_pkg_types[e_PMS_PKG_TYPE_CONNECT_CONFIRM])
                        isxmlGet = true;
                }
            }
//            qDebug() << __func__ << __LINE__;
        }
        else if( stage_flag >= e_STAGE_BUSINESS_RECV && pkg_detection_count < 8
                    && business_write_len == g_pms_package_head.business_len ) {  /*获取检测数据文件大小*/
//            qDebug() << __func__ << __LINE__;
            /*将串口接收到的数据包（package[i]）按字节拼接成一个更长的整型变量*/
            g_detection_datalen = (g_detection_datalen << 8*pkg_detection_count) | package[i];
            pkg_detection_count++;
            if( pkg_detection_count == 8 ) {
                object_printf(DEBUG_PMS_PKG, DBG_LEVEL_LOW, "g_detection_datalen:%lld(0x%016llX) !\n",
                                g_detection_datalen, g_detection_datalen);
            }
//            qDebug() << __func__ << __LINE__;
        }
        else if( stage_flag >= e_STAGE_DETECTION_RECV && detection_write_len < g_detection_datalen ) {
            /*收到检测数据处理 --- 当前的协议中请求包中是不包含检测数据的，暂不处理*/
//            qDebug() << __func__ << __LINE__;
        }
        else if( stage_flag >= e_STAGE_DETECTION_RECV && detection_write_len == g_detection_datalen
                    && (int)p_pms_package_end < ((int)&g_pms_package_end+sizeof(pms_package_end_t)) ) {
//            qDebug() << __func__ << __LINE__;
            is_crc32_cal = 0;   /*结束CRC32校验*/
            *p_pms_package_end++ = package[i];  /*获取包尾数据*/
            if( (int)p_pms_package_end == ((int)&g_pms_package_end+sizeof(pms_package_end_t)) ) {   /*报文尾处理完成*/
                g_pms_package_end.verify = ntohl(g_pms_package_end.verify);/*实际接收数据需要进行高低字节转换*/
                object_printf(DEBUG_PMS_PKG, DBG_LEVEL_LOW, "crc32_value:0x%08X   verify:0x%08X   end:0x%02X !\n",
                                    g_crc32_value, g_pms_package_end.verify, g_pms_package_end.end );
                if( (g_pms_package_end.verify == g_crc32_value) && (g_pms_package_end.end == 0x03) ) {
                    int pkg_type_index = 0;

                    memset(&g_pms_pkg_info, 0x00, sizeof(g_pms_pkg_info));
                    g_pms_pkg_info.pkg_number = g_pms_package_head.number;  /*报文序号*/

                    for( pkg_type_index = 0; pkg_type_index < sizeof(g_pms_pkg_types)/sizeof(g_pms_pkg_types[0]); pkg_type_index++ ) {
                        if( g_pms_package_head.pkg_type == g_pms_pkg_types[pkg_type_index] ) {
                            if( g_pms_pkg_callb ) {
                                g_pms_pkg_info.info_type = pkg_type_index;//这里的回调会发包表示收到类似进行握手，那这里是不是应该+1？
                                if( g_pms_package_head.business_len ) {
                                    memcpy( g_pms_pkg_info.task_file, PMS_BUSINESSFILE_NAME,
                                        strlen(PMS_BUSINESSFILE_NAME)<sizeof(g_pms_pkg_info.task_file) ?
                                            strlen(PMS_BUSINESSFILE_NAME) : sizeof(g_pms_pkg_info.task_file) );
                                }
//                                qDebug() << __func__ << __LINE__;
                                g_pms_pkg_callb(g_pms_pkg_info);
                            }
                        }
                    }

                    stage_flag = e_STAGE_HEAD_NONE; /*收包状态重置*/
                    if(isxmlGet)
                    {
                        isxmlGet = false;
                        analysis_pms_task_dat();
                    }
                }
            }

//            qDebug() << __func__ << __LINE__;
        }
        else {  /*对于不满足上述处理条件的将重新处理*/
//            stage_flag = e_STAGE_HEAD_NONE;
//            if( g_pms_pkg_callb ) {
//                memset(&g_pms_pkg_info, 0x00, sizeof(g_pms_pkg_info));
//                g_pms_pkg_info.info_type = e_PMS_PKG_TYPE_UNKNOW;
//                qDebug() << __func__ << __LINE__;
                stage_flag = e_STAGE_HEAD_NONE;
//                g_pms_pkg_callb(g_pms_pkg_info);
//            }
        }

        if( is_crc32_cal ) {    /*正式进入数据处理阶段*/
            g_crc32_value = crc32_calculate(g_crc32_value, package+previous_index+1, i-previous_index);
        }

        previous_index = i;
    }

    g_pms_ble_link = 0;
    return ;
}


/**********************************************************************************************

    函 数 名     : pms_protocol_pkg_create_head
    功能描述     : PMS协议包头组建
    输入参数     :
            int pkg_number                                  协议包序号
            int pkg_type                                    协议包类型
            unsigned long long business_len                 业务数据长度
            unsigned long long detection_len                检测数据长度
    输出参数     :
            pms_package_head_t *pms_package_head            协议包头
    返 回 值     : int
            0                                               成功
            -1                                              失败
 ***********************************************************************************************/
int pms_protocol_pkg_create_head(pms_package_head_t *pms_package_head, int pkg_number, int pkg_type,
                            unsigned long long business_len, unsigned long long detection_len)
{
    if( pms_package_head == NULL ) {
        err_printf("Invalid header pointer !\n");
        goto error;
    }
    if( pkg_type < 0 || pkg_type >= (sizeof(g_pms_pkg_types)/sizeof(g_pms_pkg_types[0])) ) {
        err_printf("Invalid pkg type(value:%d   range:%d~%d) !\n",
                        pkg_type, 0, sizeof(g_pms_pkg_types)/sizeof(g_pms_pkg_types[0]));
        goto error;
    }

    pms_package_head->head = (PACKAGE_HEAD_1<<24)|(PACKAGE_HEAD_2<<16)|(PACKAGE_HEAD_3<<8)|PACKAGE_HEAD_4;
    pms_package_head->version = 1;
    pms_package_head->number = pkg_number;
    pms_package_head->request_flag = g_pms_pkg_types[pkg_type] >> 31;
    pms_package_head->pkg_len = business_len+detection_len+sizeof(pms_package_head_t)+sizeof(pms_package_end_t);
    pms_package_head->pkg_type = g_pms_pkg_types[pkg_type];
    pms_package_head->manufacturer = 0x00;
    if( pms_package_head->pkg_type == g_pms_pkg_types[e_PMS_PKG_TYPE_TASK_CONFIRM]
            || pms_package_head->pkg_type == g_pms_pkg_types[e_PMS_PKG_TYPE_CONNECT_REQUEST] ) {    /*下发任务确认*/
        pms_package_head->compress_flag = 0x00;
        pms_package_head->encryption_flag = 0x00;
        pms_package_head->business_format = 0x01;
    }
    else if( pms_package_head->pkg_type == g_pms_pkg_types[e_PMS_PKG_TYPE_DETECTION_UPLOAD] ) {
        pms_package_head->compress_flag = 0x00;
        pms_package_head->encryption_flag = 0x00;
        pms_package_head->business_format = 0x01;
    }
    pms_package_head->direction_len = detection_len;
    pms_package_head->business_len = business_len;

    object_printf(DEBUG_PMS_PKG, DBG_LEVEL_LOW, "head:0x%08X   number:%d   pkg_len:%lld   pkg_type:0x%08X   business_len:%lld detection_len:%lld!\n",
                            pms_package_head->head, pms_package_head->number, pms_package_head->pkg_len,
                            pms_package_head->pkg_type, pms_package_head->business_len, detection_len);

    /*实际发送数据需要进行高低字节转换*/
    pms_package_head->head = htonl( pms_package_head->head );
    pms_package_head->number = htons( pms_package_head->number );
    pms_package_head->pkg_len = htobe64( pms_package_head->pkg_len );
    pms_package_head->pkg_type = htonl( pms_package_head->pkg_type );
    pms_package_head->business_len = htobe64( pms_package_head->business_len );

    return 0;

error:
    return -1;
}

int pms_protocol_pkg_create_dat(pms_package_dat_t *pms_package_dat)
{
}

/**********************************************************************************************

    函 数 名     : pms_protocol_pkg_create_end
    功能描述     : PMS协议包尾组建
    输入参数     :
            无
    输出参数     :
            pms_package_end_t *pms_package_end              协议包尾
    返 回 值     : int
            0                                               成功
            -1                                              失败
 ***********************************************************************************************/
int pms_protocol_pkg_create_end(pms_package_end_t *pms_package_end)
{
    if( pms_package_end == NULL ) {
        err_printf("Invalid end pointer !\n");
        goto error;
    }

    pms_package_end->verify = 0xFFFFFFFF;
    pms_package_end->end = 0x03;

    return 0;

error:
    return -1;
}


/**********************************************************************************************

    函 数 名     : pms_protocol_pkg_update_end
    功能描述     : PMS协议包尾校验更新
    输入参数     :
            void *buffer                                    校验数据
            unsigned int size                               校验数据长度
    输出参数     :
            pms_package_end_t *pms_package_end              协议包尾
    返 回 值     : int
            0                                               成功
            -1                                              失败
 ***********************************************************************************************/
int pms_protocol_pkg_update_end(pms_package_end_t *pms_package_end, void *buffer, unsigned int size)
{
    if( pms_package_end == NULL ) {
        err_printf("Invalid end pointer !\n");
        goto error;
    }

    pms_package_end->verify = crc32_calculate(pms_package_end->verify, buffer, size);

    return 0;

error:
    return -1;
}


/**********************************************************************************************

    函 数 名     : pms_protocol_init
    功能描述     : PMS协议初始化
    输入参数     :
            int (*pms_pkg_callb)(pms_pkg_callback_info_t pms_pkg_info)      解析回调函数
    输出参数     :
            无
    返 回 值     : int
            0                                               成功
            -1                                              失败
 ***********************************************************************************************/
int pms_protocol_init(int (*pms_pkg_callb)(pms_pkg_callback_info_t pms_pkg_info))
{
    g_pms_pkg_callb = pms_pkg_callb;

    return 0;
}


/**********************************************************************************************

    函 数 名     : pms_protocol_uninit
    功能描述     : PMS协议反初始化
    输入参数     :
            无
    输出参数     :
            无
    返 回 值     : 无
 ***********************************************************************************************/
void pms_protocol_uninit()
{
    g_pms_pkg_callb = NULL;

    return ;
}

