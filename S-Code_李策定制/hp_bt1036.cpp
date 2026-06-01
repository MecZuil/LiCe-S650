#include "hp_bt1036.h"
#include "hp_transmission.h"
/**********************************************************************************************

    函 数 名     : find_substr
    功能描述     : 定位字符的位置
    输入参数     :
           const char *str              用于查找的字符串
           int c                        查找的字符
           int c_pos                    查找的字符出现的第 c_pos 次
           int *substr_start            第 c_pos 次字符的起始位置(以0起始, 即 c_pos 次的 c 字符后一个字符位置)
           int *substr_stop             第 c_pos 次字符的结束位置(即 c_pos+1 次的 c 字符所在位置)
    输出参数     :
           无
    返 回 值     : int
           0                        成功
           -1                       失败

    补充 实际上对应第c_pos次的是substr_stop,混淆的原因是c_pos是以1起始的
 ***********************************************************************************************/
static int find_substr(const char *str, int c, int c_pos, int *substr_start, int *substr_stop)
{
    const char* substr_pos=NULL;
    int i=0;
    int start=0, stop=-1;
    for( i=0; i<c_pos; i++ )
    {
        substr_pos = strchr(str+stop+1, c);
        if( substr_pos != NULL ){
            if( i == c_pos-1 ){
                start = stop+1;
            }
            stop = substr_pos-str;
        }
        else{
            (*substr_start) = 0;
            (*substr_stop) = 0;
            return -1;
        }
    }
    (*substr_start) = start;
    (*substr_stop) = stop;

    return 0;
}


/**********************************************************************************************

    函 数 名     : ble_function_comm
    功能描述     : 模块通讯指令处理
    输入参数     :
           char *cmd                指令
           char *reply              回复头
           char *determine          回复数据
    输出参数     :
           无
    返 回 值     : int
            1                       成功
            -1                      失败
 ***********************************************************************************************/
/*注意我们当前有多个线程处理，在应用设计时，对于我们的串口文件流的访问需要进行进行梳理、异常控制，或者考虑加锁设置*/
int ble_function_comm(const char *cmd, char *reply, const char *determine)
{
    char out_buffer[200]={0};
    char *pos = NULL;
    char retry_count = 0;
    char retry_limit = 1;
    char comm_timeout=3;
    int is_function_valid=-1;
    struct timeval start={0}, stop={0};
    /*
    struct  timeval{
       long  tv_sec;  秒
       long  tv_usec; 微妙
    }；
    */
    if( g_ble_fp == NULL ) {//ble_transparent_transmission_init初始化了这个fp
        err_printf("ble fp invalid !\n");
        goto error;
    }

    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_HIGH, "CMD:%s !\n", cmd);//莫工的打印信息

    gettimeofday(&start, NULL);
    gettimeofday(&stop, NULL);/*初始化时间*/
    /*通讯加锁，防止我们主任务轮询线程中的回复与当前实时问询交叉，导致我们接收不到想要的反馈信息但是有回复将等待时间刷新*/
    pthread_mutex_lock(&g_ble_comm_lock);
    while(1) {
        MODULE_WRITE(cmd, g_ble_fp);  /*写入指令*/
        memset(out_buffer, 0 ,sizeof(out_buffer));
        while( (stop.tv_sec-start.tv_sec) <= comm_timeout )/*指令间隔*/
        {
            if( NULL != fgets(out_buffer, sizeof(out_buffer), g_ble_fp) ) {
                dev_printf(DEBUG_DEV_BLE, RUD_LEVEL, "out_buffer = %s reply = %s determine = %s\n",
                            out_buffer, reply, determine);
                gettimeofday(&start, NULL);/*重新更新起始时间*/
                if( (pos = strstr(out_buffer, reply)) != NULL ) {
                    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "pos=%s\n", pos);
                    if( determine == NULL ) {
                        is_function_valid = 1;
                    }
                    else {
                        if( (pos = strstr(out_buffer, determine)) != NULL ) {
                            dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "query success determine:%s\n", determine);
                            is_function_valid = 1;
                        }
                    }
                    break;
                }
                else if( (pos = strstr(out_buffer, "ERR")) != NULL ) {
                    warn_printf("ble function(%s) query error err msg is %s!\n", cmd, pos);
                    break;
                }
                memset(out_buffer, 0 ,sizeof(out_buffer));
            }
            gettimeofday(&stop ,NULL);
            usleep(1000);
        }
        retry_count++;
        dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "ble function query count:%d !\n", retry_count);

        if( is_function_valid < 0 && retry_count <= retry_limit ) {   /*如果未查询到结果并且查询次数未达到限制则进行等待再次查询*/
            gettimeofday(&start, NULL);/*重新更新起始时间*/
            usleep(500000);
        }
        else {
            break;
        }
    }
    pthread_mutex_unlock(&g_ble_comm_lock);/*通讯解锁*/

error:
    return is_function_valid;
}


/**********************************************************************************************

    函 数 名     : ble_scan_handle
    功能描述     : 蓝牙扫描结果处理
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : 无
 ***********************************************************************************************/
static void ble_scan_handle()
{
    char out_buffer[200] = {0};
    char *pos = NULL;
    int scan_timeout = 15;
    static struct timeval start = {0}, stop = {0};

    pthread_mutex_lock(&g_ble_comm_lock);/*通讯加锁，防止与即刻问询回复交叉*/
    if( g_ble_scan_state == 1 ) {/*重新开始扫描可连接蓝牙*/
        myfree("ble scan result", (void **)&g_ble_scan_result);
        g_ble_scan_length = 0;

        gettimeofday(&start ,NULL);
        gettimeofday(&stop ,NULL);/*初始化时间*/
        MODULE_WRITE(AT_BLE_SCAN, g_ble_fp);  /*写入指令*/

        /*这里其实不加锁也没关系，本身状态会被改变的只能是外部设置重刷新而当前就是刚处理了重刷新*/
        pthread_mutex_lock(&g_ble_handle_lock);/*状态改变加锁*/
        g_ble_scan_state = 2;/*设置为正在扫描可连接蓝牙*/
        pthread_mutex_unlock(&g_ble_handle_lock);/*解锁*/
    }

    /*每次扫描最多等待获取15s --- 这里如果使用 if 来判断通过线程去循环 需要考虑如果有其他任务的话的读写流的交叉问题*/
    while( (stop.tv_sec-start.tv_sec) <= scan_timeout && g_ble_scan_state == 2 )
    {
        memset(out_buffer, 0 ,sizeof(out_buffer));
        if( NULL != ( fgets(out_buffer, sizeof(out_buffer), g_ble_fp) ) ) {
            dev_printf(DEBUG_DEV_BLE, RUD_LEVEL, "out_buffer = %s \n", out_buffer);
            gettimeofday(&start ,NULL);/*重新更新起始时间*/
            if( (pos = strstr(out_buffer, "+SCAN=")) != NULL && g_ble_scan_state != 1 ) { /*加锁时不允许状态为重刷新*/
                dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "pos = %s\n", pos);

                pthread_mutex_lock(&g_ble_handle_lock);/*处理中可能会状态改变*/
                if( strstr(out_buffer, "+SCAN=E") != NULL ) {/*扫描结束 注：这里别再去赋值 pos 了，不然会让下面出错的*/
                    dev_printf(DEBUG_DEV_BLE, INFO_LEVEL, "ble scan finish !\n");

                    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "g_ble_scan_length:%d   g_ble_scan_result:\n%s",
                                        g_ble_scan_length, g_ble_scan_result);
                    g_ble_scan_state = 3;/*蓝牙完成扫描*/
                }
                else {
                    int info_length = 0;
                    int info_start = 0, info_stop = 0;
                    int pos_start = 0, pos_stop = 0;

                    find_substr(pos, ',', 4, &pos_start, &pos_stop);
                    info_start = pos_start;
                    info_stop = pos_stop+1;
                    find_substr(pos+info_stop, ',', 1, &pos_start, &pos_stop);
                    info_stop += pos_stop;
                    info_length = info_stop-info_start;

                    myrealloc("ble scan result", (void **)&g_ble_scan_result, g_ble_scan_length + info_length+1 + 1);/*+1:换行符 +1:结束符*/
                    if( g_ble_scan_result == NULL ) {
                        g_ble_scan_length = 0;
                        g_ble_scan_state = -1;/*扫描异常*/
                    }

                    memcpy( g_ble_scan_result+g_ble_scan_length, pos+info_start, info_length );
                    g_ble_scan_length += info_length;
                    g_ble_scan_result[g_ble_scan_length++]='\n';/*设置换行符*/
                    g_ble_scan_result[g_ble_scan_length]='\0';/*设置结束符*/
                }
                pthread_mutex_unlock(&g_ble_handle_lock);/*解锁*/
            }
        }
        gettimeofday(&stop ,NULL);
        usleep(1000);
    }
    pthread_mutex_unlock(&g_ble_comm_lock);/*通讯解锁*/
    /*本身获取进入就有超时判断不需要再通过标志去限制*/

    return;
}

/**********************************************************************************************

    函 数 名     : ble_conn_handle
    功能描述     : 蓝牙连接结果处理
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : 无
 ***********************************************************************************************/
static void ble_conn_handle()
{
    char out_buffer[200] = {0};
    char *pos = NULL;
    int conn_timeout = 10;
    static struct timeval start = {0}, stop = {0};

    pthread_mutex_lock(&g_ble_comm_lock);/*通讯加锁，防止与即刻问询回复交叉*/
    if( g_ble_conn_state == 1 ) {/*进行连接*/
        char cmd[strlen(AT_BLE_A2DPCONN)+sizeof(g_conn_mac_addr)+sizeof(AT_WRAP)+5];
        int cmd_len = 0;

        memset(cmd, 0x00, sizeof(cmd));
        strncpy(cmd+cmd_len, AT_BLE_A2DPCONN, sizeof(cmd)-cmd_len);
        cmd_len += strlen(AT_BLE_A2DPCONN);
        strncpy(cmd+cmd_len, g_conn_mac_addr, sizeof(cmd)-cmd_len);/*mac addr 为12位的数字码*/
        cmd_len += sizeof(g_conn_mac_addr);
        strncpy(cmd+cmd_len, AT_WRAP, sizeof(cmd)-cmd_len);

        MODULE_WRITE(cmd, g_ble_fp);  /*写入指令*/
        gettimeofday(&start ,NULL);
        gettimeofday(&stop ,NULL);/*初始化时间*/

        g_ble_conn_state = 3;/*正在获取状态*/
    }
    if( g_ble_conn_state == 2 ) {/*断开连接*/
        MODULE_WRITE(AT_BLE_A2DPDISC, g_ble_fp);  /*写入指令*/
        MODULE_WRITE(AT_BLE_HFPDISC, g_ble_fp);  /*写入指令*/
        gettimeofday(&start ,NULL);
        gettimeofday(&stop ,NULL);/*初始化时间*/

        g_ble_conn_state = 3;/*正在获取状态*/
    }

    /*每次扫描最多等待获取15s --- 这里如果使用 if 来判断通过线程去循环 需要考虑如果有其他任务的话的读写流的交叉问题*/
    while( (stop.tv_sec-start.tv_sec) <= conn_timeout && g_ble_conn_state == 3 )
    {
        memset(out_buffer, 0 ,sizeof(out_buffer));
        if( NULL != ( fgets(out_buffer, sizeof(out_buffer), g_ble_fp) ) ) {
            dev_printf(DEBUG_DEV_BLE, RUD_LEVEL, "out_buffer = %s \n", out_buffer);
            gettimeofday(&start ,NULL);/*重新更新起始时间*/
            /*获取流的时候可能会改变状态所以需要再判断一次*/
            if( (pos = strstr(out_buffer, "+A2DPSTAT=")) != NULL && g_ble_conn_state != 1 && g_ble_conn_state != 2 ) {
                pthread_mutex_lock(&g_ble_handle_lock);/*处理中会状态改变*/
                if( (pos = strstr(out_buffer, "+A2DPSTAT=1")) != NULL && g_ble_a2dp_state == 2 ) {/*当前为已连接检测到断开连接*/
                    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "pos = %s\n", pos);
                    g_ble_conn_state = 5;/*成功断开连接*/
                }
                // if( (pos = strstr(out_buffer, "+A2DPSTAT=2")) != NULL ) {/*正在连接*/
                //     dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "pos = %s\n", pos);
                // }
                else if( (pos = strstr(out_buffer, "+A2DPSTAT=3")) != NULL && g_ble_a2dp_state == 0 ) {/*当前为断开连接检测到连接成功*/
                    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "pos = %s\n", pos);
                    g_ble_conn_state = 4;/*成功连接*/
                }
                pthread_mutex_unlock(&g_ble_handle_lock);/*解锁*/
            }
        }
        gettimeofday(&stop ,NULL);
        usleep(1000);
    }
    pthread_mutex_unlock(&g_ble_comm_lock);/*通讯解锁*/
}


/**********************************************************************************************

    函 数 名     : ble_pair_handle
    功能描述     : 蓝牙配对记录处理
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : 无
 ***********************************************************************************************/
static void ble_pair_handle()
{
    char out_buffer[200] = {0};
    char *pos = NULL;
    int pairinfo_get_timeout = 10;
    static struct timeval start = {0}, stop = {0};

    pthread_mutex_lock(&g_ble_comm_lock);/*通讯加锁，防止与即刻问询回复交叉*/
    if( g_ble_pair_state == 1 ) {/*重新开始读取配对记录*/
        myfree("ble pair info", (void **)&g_ble_pair_info);
        g_ble_pair_info_length = 0;

        gettimeofday(&start ,NULL);
        gettimeofday(&stop ,NULL);/*初始化时间*/
        MODULE_WRITE(AT_BLE_PLIST, g_ble_fp);  /*写入指令*/

        g_ble_pair_state = 3;/*设置为正在读取配对信息*/
    }
    else if( g_ble_pair_state == 2 ) {/*清除配对记录*/
        MODULE_WRITE(AT_BLE_PLIST_CLEAR, g_ble_fp);  /*写入指令*/
        g_ble_pair_state = 5;/*设置清除成功*/
    }/*清除配对我们将不再获取反馈结果，默认是成功的*/

    /*每次扫描最多等待获取15s --- 这里如果使用 if 来判断通过线程去循环 需要考虑如果有其他任务的话的读写流的交叉问题*/
    while( (stop.tv_sec-start.tv_sec) <= pairinfo_get_timeout && g_ble_pair_state == 3 )
    {
        memset(out_buffer, 0 ,sizeof(out_buffer));
        if( NULL != ( fgets(out_buffer, sizeof(out_buffer), g_ble_fp) ) ) {
            dev_printf(DEBUG_DEV_BLE, RUD_LEVEL, "out_buffer = %s \n", out_buffer);
            gettimeofday(&start ,NULL);/*重新更新起始时间*/
            if( (pos = strstr(out_buffer, "+PLIST=")) != NULL && g_ble_pair_state != 1 && g_ble_pair_state != 2 ) {/*加锁时不允许状态为重刷新*/
                dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "pos = %s\n", pos);

                pthread_mutex_lock(&g_ble_handle_lock);/*处理中可能会状态改变*/
                if( strstr(out_buffer, "+PLIST=E") != NULL ) {/*扫描结束 注：这里别再去赋值 pos 了，不然会让下面出错的*/
                    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "g_ble_pair_info_length:%d   g_ble_pair_info:\n%s",
                                        g_ble_pair_info_length, g_ble_pair_info);
                    g_ble_pair_state = 4;/*蓝牙配对信息获取完成*/
                }
                else {
                    int info_length = 0;
                    int pos_start = 0, pos_stop = 0;

                    find_substr(pos, ',', 3, &pos_start, &pos_stop);/*配对信息结构 xxx,xxx,mac addr,name*/
                    info_length = strlen(pos+pos_start);

                    myrealloc("ble pair info", (void **)&g_ble_pair_info, g_ble_pair_info_length + info_length+1 + 1);/*+1:换行符 +1:结束符*/
                    if( g_ble_pair_info == NULL ) {
                        g_ble_pair_info_length = 0;
                        g_ble_pair_state = -1;/*状态异常*/
                    }

                    memcpy( g_ble_pair_info+g_ble_pair_info_length, pos+pos_start, info_length );
                    g_ble_pair_info_length += info_length;
                    g_ble_pair_info[g_ble_pair_info_length++]='\n';/*设置换行符*/
                    g_ble_pair_info[g_ble_pair_info_length]='\0';/*设置结束符*/
                }
                pthread_mutex_unlock(&g_ble_handle_lock);/*解锁*/
            }
        }
    }
    pthread_mutex_unlock(&g_ble_comm_lock);/*通讯解锁*/
}


/**********************************************************************************************

    函 数 名     : ble_a2dp_query
    功能描述     : 蓝牙连接状态查询
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : 无
 ***********************************************************************************************/
static void ble_a2dp_query()
{
    char out_buffer[200] = {0};
    char *pos = NULL;
    int query_timeout_ms = 30;/*实测响应时间在10ms以内*/
    static struct timeval start = {0}, stop = {0};

    pthread_mutex_lock(&g_ble_comm_lock);/*通讯加锁，防止与即刻问询回复交叉*/
    MODULE_WRITE(AT_BLE_A2DPSTAT, g_ble_fp);  /*写入指令*/
    gettimeofday(&start ,NULL);
    gettimeofday(&stop ,NULL);/*初始化时间*/

    while(1) {
        int query_time = 0;

        query_time = (stop.tv_sec-start.tv_sec)*1000+(stop.tv_usec-start.tv_usec)/1000;
        if( query_time <= query_timeout_ms ) {/*当前如果需要改变连接状态则不再获取*/
            memset(out_buffer, 0 ,sizeof(out_buffer));

            if( NULL != ( fgets(out_buffer, sizeof(out_buffer), g_ble_fp) ) ) {
                dev_printf(DEBUG_DEV_BLE, RUD_LEVEL, "out_buffer = %s \n", out_buffer);
                gettimeofday(&start ,NULL);/*重新更新起始时间*/
                if( (pos = strstr(out_buffer, "+A2DPSTAT=1")) != NULL ) {/*处于待机状态*/
                    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "pos = %s\n", pos);
                    g_ble_a2dp_state = 0;/*断开连接*/
                    break;
                }
                else if( (pos = strstr(out_buffer, "+A2DPSTAT=2")) != NULL ) {/*正在连接*/
                    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "pos = %s\n", pos);
                    g_ble_a2dp_state = 1;/*断开连接*/
                    break;
                }
                else if( (pos = strstr(out_buffer, "+A2DPSTAT=3")) != NULL ) {/*已经连接*/
                    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "pos = %s\n", pos);
                    g_ble_a2dp_state = 2;/*已连接*/
                    break;
                }
                else if( (pos = strstr(out_buffer, "+A2DPDEV=")) != NULL ) {/*连接的设备*/
                    char *dev_info = NULL;

                    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "pos = %s\n", pos);
                    memset(g_ble_conn_dev, 0x00, sizeof(g_ble_conn_dev));
                    dev_info = strchr(pos, '=');
                    dev_info++;/*跳过'='字符*/
                    g_ble_conn_dev_length = strlen(dev_info);
                    g_ble_conn_dev_length = g_ble_conn_dev_length>sizeof(g_ble_conn_dev)?sizeof(g_ble_conn_dev):g_ble_conn_dev_length;/*大小限制*/
                    memcpy(g_ble_conn_dev, dev_info, g_ble_conn_dev_length);/*拷贝数据*/

                    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "g_ble_conn_dev = %s   g_ble_conn_dev_length = %d \n",
                                    g_ble_conn_dev, g_ble_conn_dev_length);
                    break;
                }
            }

            gettimeofday(&stop ,NULL);
            usleep(1000);
        }
        else {
            break;
        }
    }
    pthread_mutex_unlock(&g_ble_comm_lock);/*通讯解锁*/
}


/**********************************************************************************************

    函 数 名     : ble_handle_thread
    功能描述     : 蓝牙轮询处理线程
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : 无
 ***********************************************************************************************/
static void *ble_handle_thread(void *arg)
{
    struct timeval tv_now;
    struct timeval tv_a2dp_query;
    int msec_a2dp_query;

    dev_printf(DEBUG_DEV_BLE, INFO_LEVEL, "ble handle start !\n");

    gettimeofday(&tv_now, NULL);
    gettimeofday(&tv_a2dp_query, NULL);

    while( !g_ble_thread_quit )/*指令间隔*/
    {
        gettimeofday(&tv_now, NULL);

        if( g_ble_fp == NULL ) {
            err_printf("ble fp invalid !\n");
            break;
        }

        msec_a2dp_query = (tv_now.tv_sec * 1000 + tv_now.tv_usec / 1000 - tv_a2dp_query.tv_sec * 1000 - tv_a2dp_query.tv_usec / 1000);
        if( msec_a2dp_query >= 1000 ) {
            ble_a2dp_query();
            gettimeofday(&tv_a2dp_query, NULL);
        }
        if(g_ble_get_info++ > 20)
        {
            g_ble_scan_state = 3;
        }
        ble_scan_handle();/*蓝牙扫描*/
        ble_conn_handle();/*蓝牙连接*/
        ble_pair_handle();/*读写蓝牙配对记录*/

        usleep(10000);
    }

    g_ble_thread_quit = 1;/*更新线程标记为退出状态*/

    return NULL;
}


/**********************************************************************************************

    函 数 名     : ble_gatt_handle_thread
    功能描述     : 蓝牙串口数据接收线程
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : 无
 ***********************************************************************************************/
static void *ble_gatt_handle_thread(void *arg)
{
    (void)arg;
    char out_buffer[128] = {0};
    int read_len = 0;
    char *pos = NULL;

    dev_printf(DEBUG_DEV_BLE, INFO_LEVEL, "ble gatt handle start !\n");

    while( !g_gatt_thread_quit ) {
        if( g_ble_fp == NULL ) {
            err_printf("ble fp invalid !\n");
            break;
        }

        memset(out_buffer, 0 ,sizeof(out_buffer));
        /*因为传递的数据中会有换行符，所以需要使用 fread 进行读取数据*/
        if( ( read_len = fread(out_buffer, 1, sizeof(out_buffer), g_ble_fp) ) != 0 ) {
            if( (pos = strstr(out_buffer, "+GATTDATA=")) != NULL ) {
                int recv_datalen = 0;
                int index = 0;

                dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "pos = %s\n", pos);

                index = strlen("+GATTDATA=");
                while( pos[index] != ',' ) {
                    recv_datalen = recv_datalen*10+(pos[index]-0x30);
                    index++;
                }
                index++;    /*转到实际数据处*/
                dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "data len=%d !\n", recv_datalen);

                if( g_ble_data_call ) {/*检查回调函数是否注册*/
                    g_ble_data_call((unsigned char *)(pos+index), recv_datalen);
                }
            }
        }

        usleep(10000);
    }

    g_ble_thread_quit = 1;/*更新线程标记为退出状态*/

    return NULL;
}

#define GATT_FEEDBACK       1
#define GATT_DELAY          0
/**********************************************************************************************

    函 数 名     : ble_gatt_send
    功能描述     : 蓝牙串口数据发送
    输入参数     :
           char* data                   发送数据
           int data_len                 数据长度
    输出参数     :
           无
    返 回 值     :
            0                           失败
           >0                           发送成功的字节数
 ***********************************************************************************************/
int ble_gatt_send(char* data, int data_len)
{
    __attribute__((unused))char out_buffer[50]={0};/*__attribute__用于抑制未使用变量的警告*/
    __attribute__((unused))char *pos = NULL;
    char send_buffer[512] = AT_GATTSEND;
    int send_buffer_len = strlen(AT_GATTSEND);
    char gatt_data_len_str[5] = {0};
    int itoa_str_len = 0;
    int write_cumulative_len = 0;
    struct timeval start={0}, stop={0};
    __attribute__((unused))int read_len = 0;
    __attribute__((unused))char comm_timeout_ms = 20;
    __attribute__((unused))int serial_speed = 1000000 * 8 / (g_serial_baudrate/5*4);/*波特率115200 最终结果为86.81*/
    __attribute__((unused))int send_data_index = 0;
    __attribute__((unused))int feedback_time = 0;
    __attribute__((unused))int write_time = 0;
    __attribute__((unused))int i = 0;

    if( g_ble_fp == NULL ) {
        err_printf("ble fp invalid !\n");
        goto error;
    }

    data_len = (data_len>492) ? 492 : data_len; /*单次发送数据包最大为492个字节*/

    pthread_mutex_lock(&g_ble_comm_lock);

    /*发送组包*/
    itoa_str_len = _itoa_(data_len, gatt_data_len_str);
    memcpy(send_buffer+send_buffer_len, gatt_data_len_str, itoa_str_len);    /*拷贝发送数据长度字符串*/
    send_buffer_len += itoa_str_len;
    send_buffer[send_buffer_len++] = ',';
    send_data_index = send_buffer_len;
    memcpy(send_buffer+send_buffer_len, data, data_len);    /*拷贝发送数据*/
    send_buffer_len += data_len;
    memcpy(send_buffer+send_buffer_len, "\r\n", strlen("\r\n"));    /*添加结尾标识*/
    send_buffer_len += strlen("\r\n");

    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_HIGH, "send data(len:%d data len:%d): \n", send_buffer_len, data_len);
    for( i = 0; i<send_buffer_len; i++  ) {
        dev_debug(DEBUG_DEV_BLE, DBG_LEVEL_HIGH, "0x%02X(%c) ", send_buffer[i], send_buffer[i]);
    }
    dev_debug(DEBUG_DEV_BLE, DBG_LEVEL_HIGH, "\n");

    gettimeofday(&start, NULL);
    write_cumulative_len = fwrite(send_buffer, 1, send_buffer_len, g_ble_fp);   /*写入指令*/
#if GATT_DELAY
    gettimeofday(&stop, NULL);
    write_time = (stop.tv_sec - start.tv_sec)*1000000+(stop.tv_usec - start.tv_usec);
    serial_speed *= data_len;

    if( serial_speed > write_time ) {
        usleep(serial_speed-write_time);    /*当前为非阻塞模式发送数据，需要进行延迟等待*/
    }
#endif

#if GATT_FEEDBACK
    /*发送反馈校验*/
    gettimeofday(&start, NULL);
    gettimeofday(&stop, NULL);/*初始化时间*/
    while( (stop.tv_sec-start.tv_sec)*1000+(stop.tv_usec-start.tv_usec)/1000 <= comm_timeout_ms )/*指令间隔*/
    {
        if( ( read_len = fread(out_buffer, 1, sizeof(out_buffer), g_ble_fp) != 0 ) ) {
            dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_HIGH, "out_buffer = %s   read_len:%d \n", out_buffer, read_len);
            if( (pos = strstr(out_buffer, "OK")) != NULL ) {
                write_cumulative_len = data_len;
                break;
            }
            else if( (pos = strstr(out_buffer, "ERR")) != NULL ) {
                warn_printf("gatt send feedback error !\n");
                break;
            }
            memset(out_buffer, 0 ,sizeof(out_buffer));
        }
        gettimeofday(&stop ,NULL);
        usleep(500);
    }
    feedback_time = (stop.tv_sec-start.tv_sec)*1000000+(stop.tv_usec-start.tv_usec);
#endif

    pthread_mutex_unlock(&g_ble_comm_lock);/*通讯解锁*/

error:
    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_HIGH, "write_cumulative_len:%d   feedback time:%d !\n",
                    write_cumulative_len, feedback_time);

    return write_cumulative_len;
}


/**********************************************************************************************

    函 数 名     : ble_transparent_handle_thread
    功能描述     : 蓝牙串口数据透传接收线程
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : 无
 ***********************************************************************************************/
static void *ble_transparent_handle_thread(void *arg)
{
    char out_buffer[128] = {0};
    int read_len = 0;
    struct timeval tv_now;
    struct timeval tv_spp_query;
    int msec_spp_query;
    int trans_timeout = 5000;

    dev_printf(DEBUG_DEV_BLE, INFO_LEVEL, "ble transparent handle start !\n");

    gettimeofday(&tv_now, NULL);
    gettimeofday(&tv_spp_query, NULL);

    while( !g_transparent_thread_quit ) {
//        if( g_ble_fp == NULL ) {
//            err_printf("ble fp invalid !\n");
//            break;
//        }

        memset(out_buffer, 0 ,sizeof(out_buffer));
        if( (read_len = serial_recv_timeout(g_ble_fd, (unsigned char *)out_buffer, sizeof(out_buffer), 100000)) != 0 ) {
            printf("read_len:%d !\n", read_len);
            gettimeofday(&tv_spp_query, NULL);
            if( g_ble_data_call ) {
                g_ble_data_call((unsigned char *)out_buffer, read_len);
            }
        }

        gettimeofday(&tv_now, NULL);

        usleep(10000);
    }

    g_transparent_thread_quit = 1;/*更新线程标记为退出状态*/

    return NULL;
}


/**********************************************************************************************

    函 数 名     : ble_transparent_send
    功能描述     : 蓝牙串口数据透传发送
    输入参数     :
            char* data                   发送数据
            int data_len                 数据长度
    输出参数     :
            无
    返 回 值     :
            0                           失败
           >0                           发送成功的字节数
 ***********************************************************************************************/
int ble_transparent_send(const char* data, int data_len)
{
//    // 打开文件，以追加模式写入，如果不存在则创建
//    FILE *file = fopen("ble_data.log", "ab+");
//    if (file == NULL) {
//        return -1; // 文件打开失败
//    }

//    // 写入数据
//    size_t written = fwrite(data, 1, data_len, file);
//    fclose(file);

//    return written; // 返回写入结果

    int write_cumulative_len = 0;
    unsigned char* write_data = (unsigned char*)data;
    struct timeval start, stop;
    int write_time = 0;
    /*每个字节发送的时间(us) --- 时间计算基准波特率进行人为的降低*/
    int serial_speed = 1000000 * 8 / (g_serial_baudrate/5*4);/*115200*/

    if( g_ble_fp == NULL ) {
        err_printf("ble fp invalid !\n");
        goto error;
    }

    if( !g_serial_transparent_block_type ) {
        gettimeofday(&start, NULL);
    }
    while( write_cumulative_len < data_len ) {
        int write_len = 0;

//        write_len = fwrite(write_data+write_cumulative_len, 1, data_len-write_cumulative_len, g_ble_fp);
        write_len = serial_send(g_ble_fd, write_data+write_cumulative_len, data_len-write_cumulative_len);
        if( write_len <= 0 ) {
            err_printf("ble transparent send fail !\n");
            break;
        }
        write_cumulative_len += write_len;
    }
    if( write_cumulative_len != data_len ) {
        write_cumulative_len = 0;
    }

    if( !g_serial_transparent_block_type ) {
        gettimeofday(&stop, NULL);
        write_time = (stop.tv_sec - start.tv_sec)*1000000+(stop.tv_usec - start.tv_usec);
        serial_speed *= write_cumulative_len;

        if( serial_speed > write_time ) {
            usleep(serial_speed-write_time);    /*当前为非阻塞模式发送数据，需要进行延迟等待*/
        }
    }

error:
    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_HIGH, "accumulated sending length:%d !\n",
                        write_cumulative_len);

    return write_cumulative_len;
}


/**********************************************************************************************

    函 数 名     : ble_audio_init
    功能描述     : 模块音频模式设置初始化
    输入参数     :
           int i2s_mode                 I2S模式(0 - I2S Master   1 - I2S Slave)
           int ble_mode                 蓝牙模式(0 - 模拟信号模式   1 - 蓝牙模式)
           int analog_mode              模拟模式选择(0 - MIC输入 I2S输出   1 - I2S输入 SPK输出)
    输出参数     :
           无
    返 回 值     : int
            0                           成功
            -1                          失败
 ***********************************************************************************************/
int ble_audio_init(int i2s_mode, int ble_mode, int analog_mode)
{
    int is_i2s_mode_vaild = 0;
    int is_audroute_vaild = 0;
    int is_audloop_vaild = 0;
    const char *ble_i2s_mode;
    const char *i2s_mode_determine;
    const char *ble_analog_mode;
    const char *analog_mode_determine;

    if( ble_mode == 1 ) {
        ble_function_comm(AT_RESTORE, "OK", NULL);/*模块重启*/
    }

    /*设置I2S模式*/
    ble_i2s_mode = (i2s_mode == 1)?AT_I2SCFG_SLAVE:AT_I2SCFG_MASTER;/*0-master 1-slave*/
    i2s_mode_determine = (i2s_mode == 1)?"3":"1";/*0-master 1-slave*/
    is_i2s_mode_vaild = ble_function_comm(AT_I2SCFG, "+I2SCFG=", i2s_mode_determine);/*确认模块的I2S模式*/
    if( is_i2s_mode_vaild < 0 ) {
        is_i2s_mode_vaild = ble_function_comm(ble_i2s_mode, "OK", NULL);/*设置我们所需的I2S模式*/
        if( is_i2s_mode_vaild < 0 ) {
            err_printf("Failed to set ble i2s mode !\n");
            goto error;
        }
        else {
            is_i2s_mode_vaild = ble_function_comm(AT_I2SCFG, "+I2SCFG=", i2s_mode_determine);/*再次确认模块的I2S模式*/
            if( is_i2s_mode_vaild < 0 ) {
                err_printf("Failed to set ble i2s mode !\n");
                goto error;
            }
        }
    }

    if( ble_mode == 0 ) {/*模拟信号模式*/
        /*测试发现如果有路由模式后设置I2S模式，会导致功能还是无法正常，所以这里不再查询模式。而是直接去设置一次*/
        is_audroute_vaild =  ble_function_comm(AT_AUDROUTE_BLE, "+AUDROUTE=", "2");/*先设置为通话对讲模式*/
        if(is_audroute_vaild < 0) {
            err_printf("Failed to set audroute mode !\n");
            goto error;
        }
        is_audroute_vaild =  ble_function_comm(AT_AUDROUTE_ANALOG, "+AUDROUTE=", "0");/*设置为普通模式*/
        if(is_audroute_vaild < 0) {
            err_printf("Failed to set audroute mode !\n");
            goto error;
        }

        ble_analog_mode = (analog_mode == 1)?AT_AUDLOOP_SPK:AT_AUDLOOP_MIC;/*0-MIC 1-SPK*/
        analog_mode_determine = (analog_mode == 1)?"3":"2";/*0-MIC 1-SPK*/
        ble_function_comm(AT_AUDLOOP_CLOSE, "OK", NULL);/*取消回环设置*/
        ble_function_comm(ble_analog_mode, "OK", NULL);
        is_audloop_vaild = ble_function_comm(AT_AUDLOOP, "+AUDLOOP=", analog_mode_determine);/*确认回环模式*/
        if(is_audloop_vaild < 0) {
            err_printf("Failed to set audloop mode !\n");
            goto error;
        }
    }
    else if( ble_mode == 1 ){/*蓝牙模式*/
        ble_function_comm(AT_AUDLOOP_CLOSE, "OK", NULL);/*取消回环设置*/
        /*测试发现如果有路由模式后设置I2S模式，会导致功能还是无法正常，所以这里不再查询模式。而是直接去设置一次*/
        is_audroute_vaild =  ble_function_comm(AT_AUDROUTE_ANALOG, "+AUDROUTE=", "0");/*先设置为普通模式*/
        if(is_audroute_vaild < 0) {
            err_printf("Failed to set audroute mode !\n");
            goto error;
        }
        is_audroute_vaild =  ble_function_comm(AT_AUDROUTE_BLE, "+AUDROUTE=", "2");/*设置为通话对讲模式*/
        if(is_audroute_vaild < 0) {
            err_printf("Failed to set audroute mode !\n");
            goto error;
        }
    }

    return 0;

error:
    return -1;
}


/**********************************************************************************************

    函 数 名     : ble_get_pair_info_length
    功能描述     : 配对记录信息长度获取
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : int                  配对信息长度
 ***********************************************************************************************/
int ble_get_pair_info_length()
{
    if( g_ble_pair_state == 4 ) {/*读取完成*/
        dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "pair info length:%d !\n", g_ble_pair_info_length);
        return g_ble_pair_info_length;
    }
    else {
        return 0;
    }
}


/**********************************************************************************************

    函 数 名     : ble_copy_pair_info
    功能描述     : 配对记录信息获取
    输入参数     :
           无
    输出参数     :
           char *save_pair_info         配对信息
    返 回 值     : int
                -1                      失败
                0                       成功
 ***********************************************************************************************/
int ble_copy_pair_info(char *save_pair_info)
{
    if( save_pair_info == NULL ) {
        err_printf("save pair info pointer is illegal !\n");
        return -1;
    }

    memcpy(save_pair_info, g_ble_pair_info, g_ble_pair_info_length);

    return 0;
}


/**********************************************************************************************

    函 数 名     : ble_pair_init
    功能描述     : 配对记录功能设置
    输入参数     :
           int pair_flag                配对记录操作模式(0 - 清除配对记录   1 - 获取配对记录)
    输出参数     :
           无
    返 回 值     : int
                0                       成功
                其他                    失败
 ***********************************************************************************************/
int ble_pair_init(int pair_flag)
{

    dev_printf(DEBUG_DEV_BLE, INFO_LEVEL, "ble pair flag:%d !\n", pair_flag);

    pthread_mutex_lock(&g_ble_handle_lock);/*处理中会状态改变*/
    if( pair_flag == 0 ) {/*清除配对记录*/
        g_ble_pair_state = 2;/*设置为清除配对记录*/
    }
    else if( pair_flag == 1 ){/*开始获取配对记录*/
        g_ble_pair_state = 1;/*设置为开始获取已配对成功信息*/
    }
    pthread_mutex_unlock(&g_ble_handle_lock);/*状态改变解锁*/

    return 0;
}


/**********************************************************************************************

    函 数 名     : ble_get_conn_dev_length
    功能描述     : 已连接设备信息长度获取
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : int                  已连接设备信息长度
 ***********************************************************************************************/
int ble_get_conn_dev_length()
{
    if( g_ble_a2dp_state == 2 ) {/*已连接*/
        dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "conn dev length:%d !\n", g_ble_conn_dev_length);
        return g_ble_conn_dev_length;
    }
    else {
        return 0;
    }
}


/**********************************************************************************************

    函 数 名     : ble_copy_dev_info
    功能描述     : 已连接设备信息获取
    输入参数     :
           无
    输出参数     :
           char *save_dev_info         已连接设备信息
    返 回 值     : int
                -1                      失败
                0                       成功
 ***********************************************************************************************/
int ble_copy_dev_info(char *save_dev_info)
{
    if( save_dev_info == NULL ) {
        err_printf("save dev info pointer is illegal !\n");
        return -1;
    }

    memcpy(save_dev_info, g_ble_conn_dev, g_ble_conn_dev_length);

    return 0;
}


/**********************************************************************************************

    函 数 名     : ble_a2dp_connect
    功能描述     : 蓝牙连接设置
    输入参数     :
           char *mac_addr               连接设备MAC地址
           int conn_flag                连接操作(0 - 断开连接   1 - 进行连接)
    输出参数     :
           无
    返 回 值     : int
                0                       成功
                其他                    失败
 ***********************************************************************************************/
int ble_a2dp_connect(char *mac_addr, int conn_flag)
{
    int ret = 0;

    dev_printf(DEBUG_DEV_BLE, INFO_LEVEL, "ble connect flag:%d   mac addr:%s !\n", conn_flag, mac_addr);

    pthread_mutex_lock(&g_ble_handle_lock);/*处理中会状态改变*/
    if( conn_flag == 1 ) {/*进行连接*/
        if( mac_addr == NULL ) {
            err_printf("mac addr error !\n");
            ret = -1;
            goto quit;
        }

        memcpy(g_conn_mac_addr, mac_addr, sizeof(g_conn_mac_addr));
        g_ble_conn_state = 1;/*设置为开始连接蓝牙*/
    }
    else if( conn_flag == 0 ) {/*断开连接*/
        g_ble_conn_state = 2;/*设置为断开连接蓝牙*/
    }
    pthread_mutex_unlock(&g_ble_handle_lock);/*状态改变解锁*/

quit:
    return ret;
}


/**********************************************************************************************

    函 数 名     : ble_get_scan_result_length
    功能描述     : 可连接设备信息长度获取
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : int                  可连接设备信息长度
 ***********************************************************************************************/
int ble_get_scan_result_length()
{
    if( g_ble_scan_state == 3 ) {/*扫描完成*/
        dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "scan result length:%d !\n", g_ble_scan_length);
        return g_ble_scan_length;
    }
    else {
        return 0;
    }
}


/**********************************************************************************************

    函 数 名     : ble_copy_scan_result
    功能描述     : 可连接设备信息获取
    输入参数     :
           无
    输出参数     :
           char *save_result         可连接设备信息
    返 回 值     : int
                -1                      失败
                0                       成功
 ***********************************************************************************************/
int ble_copy_scan_result(char *save_result)
{
    if( save_result == NULL ) {
        err_printf("save result pointer is illegal !\n");
        return -1;
    }

    memcpy(save_result, g_ble_scan_result, g_ble_scan_length);

    return 0;
}


/**********************************************************************************************

    函 数 名     : ble_scan_init
    功能描述     : 蓝牙扫描设置
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : int
                0                       成功
                其他                    失败
 ***********************************************************************************************/
int ble_scan_init()
{
    dev_printf(DEBUG_DEV_BLE, INFO_LEVEL, "ble scan init !\n");

    pthread_mutex_lock(&g_ble_handle_lock);/*状态改变加锁*/
    g_ble_scan_state = 1;/*设置为开始扫描可连接蓝牙*/
    pthread_mutex_unlock(&g_ble_handle_lock);/*状态改变解锁*/

    return 0;
}


/**********************************************************************************************

    函 数 名     : ble_get_state
    功能描述     : 获取蓝牙的各种状态
    输入参数     :
           无
    输出参数     :
           int *scan_state              扫描状态
           int *a2dp_state              连接状态
           int *pair_state              配对状态
    返 回 值     : void
 ***********************************************************************************************/
void ble_get_state(int *scan_state, int *a2dp_state, int *pair_state)
{
    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "g_ble_scan_state:%d   g_ble_a2dp_state:%d   g_ble_pair_state:%d !\n",
                    g_ble_scan_state, g_ble_a2dp_state, g_ble_pair_state);
    if( scan_state != NULL ) {
        *scan_state = g_ble_scan_state;
    }
    if( a2dp_state != NULL ) {
        *a2dp_state = g_ble_a2dp_state;
    }
    if( pair_state != NULL ) {
        *pair_state = g_ble_pair_state;
    }

    return;
}


/**********************************************************************************************

    函 数 名     : ble_mode_init
    功能描述     : 蓝牙模式初始化，开启蓝牙连接、配对等信息轮询线程
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : int
                0                       成功
                其他                    失败
 ***********************************************************************************************/
int ble_mode_init()
{
    dev_printf(DEBUG_DEV_BLE, INIT_LEVEL, "ble mode init !\n");

    if( !g_module_init ) {
        err_printf("ble mode initialization failed, module not started !\n");
        return -1;
    }

    /*创建蓝牙处理线程*/
    if( g_ble_thread_id == 0 ) {
        int pthread_ret = 0;

        g_ble_thread_quit = 0;/*标记线程为非退出状态*/
        /*蓝牙处理*/
//        pthread_ret = pthread_create(&g_gatt_thread_id, NULL, ble_gatt_handle_thread, NULL);
        pthread_ret = pthread_create(&g_ble_thread_id, NULL, ble_handle_thread, NULL);
        if( pthread_ret != 0 ) {
            err_printf("can't create thread ret:%d error:%s\n", pthread_ret, strerror(pthread_ret));
            return -1;
        }
    }

    return 0;
}


/**********************************************************************************************

    函 数 名     : ble_mode_uninit
    功能描述     : 蓝牙模式反初始化
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : int
                0                       成功
                其他                    失败
 ***********************************************************************************************/
int ble_mode_uninit()
{
    pthread_mutex_lock(&g_ble_handle_lock);/*状态改变加锁*/
    /*重置状态也将使得我们快速退出处理过程*/
    g_ble_scan_state = 0;/*标志初始化*/
    g_ble_conn_state = 0;
    g_ble_get_info = 0;
    pthread_mutex_unlock(&g_ble_handle_lock);/*状态改变解锁*/

    if( g_ble_thread_id > 0 ) { /*存在蓝牙处理线程则退出处理*/
        int pthread_ret = 0;

        g_ble_thread_quit = 1;//设置线程为退出状态
        pthread_ret = pthread_join(g_ble_thread_id, NULL);//等待线程退出
        if( pthread_ret )
            err_printf("scan pthread_join fail !!! ret:%d error:%s\n", pthread_ret, strerror(pthread_ret));
        g_ble_thread_id = 0;
    }

    myfree("ble pair info", (void **)&g_ble_pair_info); /*清空蓝牙配对记录*/
    g_ble_pair_info_length = 0;

    myfree("ble scan result", (void **)&g_ble_scan_result); /*清空蓝牙扫描结果*/
    g_ble_scan_length = 0;

    dev_printf(DEBUG_DEV_BLE, INIT_LEVEL, "ble mode uninit !\n");

    return 0;
}


/**********************************************************************************************

    函 数 名     : ble_gatt_init
    功能描述     : 蓝牙GATT服务初始化
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : int
                0                       成功
                其他                    失败
 ***********************************************************************************************/
int ble_gatt_init(int (*ble_data_call)(unsigned char *data, int datalen))
{
    dev_printf(DEBUG_DEV_BLE, INIT_LEVEL, "ble gatt init !\n");

    if( !g_module_init ) {
        err_printf("GATT initialization failed, module not started !\n");
        return -1;
    }

    if( ble_data_call != NULL ) {
        g_ble_data_call = ble_data_call;
    }
    else {
        g_ble_data_call = NULL;
    }

    if( g_gatt_thread_id == 0 ) {
        int pthread_ret = 0;

        g_gatt_thread_quit = 0;/*标记线程为非退出状态*/
        /*蓝牙处理*/
        pthread_ret = pthread_create(&g_gatt_thread_id, NULL, ble_gatt_handle_thread, NULL);
        if( pthread_ret != 0 ) {
            err_printf("can't create gatt thread ret:%d error:%s\n", pthread_ret, strerror(pthread_ret));
            return -1;
        }
    }
    else {
        err_printf("gatt thread already started !\n");
        return -1;
    }

    return 0;
}


/**********************************************************************************************

    函 数 名     : ble_gatt_uninit
    功能描述     : 蓝牙GATT服务反初始化
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : int
                0                       成功
                其他                    失败
 ***********************************************************************************************/
int ble_gatt_uninit()
{
    dev_printf(DEBUG_DEV_BLE, INIT_LEVEL, "ble gatt uninit !\n");

    if( g_gatt_thread_id ) {
        int pthread_ret = 0;

        g_gatt_thread_quit = 1;/*设置线程退出*/
        pthread_ret = pthread_join(g_gatt_thread_id, NULL);//等待线程退出
        if( pthread_ret )
            err_printf("gatt pthread_join fail !!! ret:%d error:%s\n", pthread_ret, strerror(pthread_ret));
        g_gatt_thread_id = 0;
    }

    return 0;
}

static void *recv_thread(void *arg)
{
    struct timeval timeout;
    unsigned char  buf[1024] = {0};
    fd_set         readset;
    int recvlen;
    int ret;
    int i=0;

    object_printf(DEBUG_CNTER, INIT_LEVEL, " thread satrt !\n");

    while (!g_transparent_thread_quit) {

        FD_ZERO (&readset);//清空可读集合
        FD_SET (g_serial_fd, &readset);
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000;

        ret = select(g_serial_fd + 1, &readset, NULL, NULL, &timeout);//监听激光句柄的可读状态

        // printf("timeout.tv_sec:%ld   timeout.tv_usec:%ld !\n",
        //             timeout.tv_sec, timeout.tv_usec);

        if (ret > 0) {//有可读的数据
            recvlen = serial_recv(g_ble_fd, buf, sizeof(buf));//接收串口数据

            if( g_ble_data_call  && (0 != recvlen)) {
                g_ble_data_call((unsigned char *)buf, recvlen);
            }
//            object_printf(DEBUG_CNTER, INFO_LEVEL, "laser recv data(length:%d): \n", recvlen);
//            for( i =0;i<recvlen;i++)
//            {
//                object_debug(DEBUG_CNTER, INFO_LEVEL, "(0x%02X)%c", buf[i], buf[i]);
//                object_debug(DEBUG_CNTER, INFO_LEVEL, "%c", buf[i]);
//            }
//            object_debug(DEBUG_CNTER, INFO_LEVEL, "\n");
        }
        else if(ret == 0){//没有可读的数据
            continue;
        }
    }

    g_transparent_thread_quit = 1;/*更新线程标记为退出状态*/
    return 0;
}


int ble_baud_modify(char *dev_name, int serial_baudrate)
{
    int baud_list[3] = {115200, 460800, 921600};
    char baudrate[20] = {0};
    int curr_buad = 0;  /*当前波特率*/
    int i = 0;
    int ret = 0;

    for( i=0; i<sizeof(baud_list)/sizeof(baud_list[0]); i++ ) {

        g_ble_fd = serial_init(dev_name, baud_list[i]);//初始化通信串口
        if( g_ble_fd < 0 ) {
            err_printf("init %s error\n", dev_name);
            goto error;
        }
        serial_attribute_set(g_ble_fd, 0, 0, 0, ICANON);/*更新串口属性设置*/
        /*fp->fd:fileno()*/
        g_ble_fp = fdopen(g_ble_fd, "w+");/*获取文件指针*/

        memset(baudrate, 0x00, sizeof(baudrate));
        _itoa_(baud_list[i], baudrate);

        ret = ble_function_comm(AT_BAUD, "+BAUD=", baudrate, 0, 0);/*确认模块当前波特率*/
        qDebug() << __func__ << "ret" << ret;
        if( ret > 0 ) { /*查询到了对应的波特率*/
            break;
        }
        if(g_ble_fp) {
            fclose(g_ble_fp);
            g_ble_fp = NULL;
            g_ble_fd = 0;
        }
    }

    if( i < sizeof(baud_list)/sizeof(baud_list[0]) ) {
        curr_buad = baud_list[i];
        dev_printf(DEBUG_DEV_BLE, INFO_LEVEL, "Current baud rate:%d !\n", curr_buad);
    }
    else {
        err_printf("Unable to match a valid baud rate !\n");
        goto error;
    }

    if( curr_buad != serial_baudrate ) {    /*当前波特率不匹配*/
        char cmd[30] = {0};

        sprintf(cmd, "AT+BAUD=%d\r\n", serial_baudrate);
        ret = ble_function_comm(cmd, "OK", NULL, 3, 1);/*设置波特率*/
        if( ret < 0 ) {
            err_printf("Baud rate(%s) setting failed !\n", cmd);
            goto error;
        }
    }

    if(g_ble_fp) {
        fclose(g_ble_fp);
        g_ble_fp = NULL;
        g_ble_fd = 0;
    }

    return 0;
error:
    if(g_ble_fp) {
        fclose(g_ble_fp);
        g_ble_fp = NULL;
        g_ble_fd = 0;
    }

    return -1;
}
/**********************************************************************************************

    函 数 名     : ble_function_comm
    功能描述     : 模块通讯指令处理
    输入参数     :
           char *cmd                指令
           char *reply              回复头
           char *determine          回复数据
           char comm_timeout        通讯超时时间
           int retry_limit          通讯查询限制次数
    输出参数     :
           无
    返 回 值     : int
            1                       成功
            -1                      失败
 ***********************************************************************************************/
/*注意我们当前有多个线程处理，在应用设计时，对于我们的串口文件流的访问需要进行进行梳理、异常控制，或者考虑加锁设置*/
int ble_function_comm(char *cmd, char *reply, char *determine, char comm_timeout, int retry_limit)
{
    char out_buffer[200]={0};
    char *pos = NULL;
    char retry_count = 0;
    int is_function_valid=-1;
    struct timeval start={0}, stop={0};

    if( g_ble_fp == NULL ) {
        err_printf("ble fp invalid !\n");
        goto error;
    }

    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_HIGH, "CMD:%s !\n", cmd);

    gettimeofday(&start, NULL);
    gettimeofday(&stop, NULL);/*初始化时间*/
    /*通讯加锁，防止我们主任务轮询线程中的回复与当前实时问询交叉，导致我们接收不到想要的反馈信息但是有回复将等待时间刷新*/
    //qDebug() << __func__ << __LINE__;
    pthread_mutex_lock(&g_ble_comm_lock);
    //qDebug() << __func__ << __LINE__;
    while(1) {
        MODULE_WRITE(cmd, g_ble_fp);  /*写入指令*/
        memset(out_buffer, 0 ,sizeof(out_buffer));
        //qDebug() << __func__ << __LINE__;
        while( (stop.tv_sec-start.tv_sec) <= comm_timeout )/*指令间隔*/
        {
            //qDebug() << __func__ << __LINE__;
            if( NULL != fgets(out_buffer, sizeof(out_buffer), g_ble_fp) ) {
                dev_printf(DEBUG_DEV_BLE, RUD_LEVEL, "out_buffer = %s reply = %s determine = %s\n",
                            out_buffer, reply, determine);
                //qDebug() << __func__ << __LINE__;
                gettimeofday(&start, NULL);/*重新更新起始时间*/
                if( (pos = strstr(out_buffer, reply)) != NULL ) {
                    dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "pos=%s\n", pos);
                    //qDebug() << __func__ << __LINE__;
                    if( determine == NULL ) {
                        is_function_valid = 1;
                        //qDebug() << __func__ << __LINE__;
                    }
                    else {
                        //qDebug() << __func__ << __LINE__;
                        if( (pos = strstr(out_buffer, determine)) != NULL ) {
                            //qDebug() << __func__ << __LINE__;
                            dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_LOW, "query success determine:%s\n", determine);
                            is_function_valid = 1;
                        }
                    }
                    break;
                }
                else if( (pos = strstr(out_buffer, "ERR")) != NULL ) {
                    //qDebug() << __func__ << __LINE__;
                    warn_printf("ble function(%s) query error !\n", cmd);
                    break;
                }
                memset(out_buffer, 0 ,sizeof(out_buffer));
                //qDebug() << __func__ << __LINE__;
            }
            //qDebug() << __func__ << __LINE__;
            gettimeofday(&stop ,NULL);
            usleep(1000);
        }
        //qDebug() << __func__ << __LINE__;
        retry_count++;
        dev_printf(DEBUG_DEV_BLE, DBG_LEVEL_MID, "ble function query count:%d !\n", retry_count);

        //qDebug() << __func__ << __LINE__;
        if( is_function_valid < 0 && retry_count <= retry_limit ) {   /*如果未查询到结果并且查询次数未达到限制则进行等待再次查询*/
            //qDebug() << __func__ << __LINE__;
            gettimeofday(&start, NULL);/*重新更新起始时间*/
            usleep(500000);
        }
        else {
            break;
            //qDebug() << __func__ << __LINE__;
        }
    }
    pthread_mutex_unlock(&g_ble_comm_lock);/*通讯解锁*/

error:
    return is_function_valid;
}

int ble_profile_update(int ble_mode)
{
    char profile[10] = {0};
    int ret = 0;

    ret = ble_function_comm(AT_PROFILE, "+PROFILE=", profile, 3, 1);/*确认模块的模式是否为339*/
    if( ret < 0 ) {
        ret = ble_function_comm(AT_PROFILE_MODE, "OK", NULL, 3, 1);/*设置我们所需的BLE模式*/
        if( ret < 0 ) {
            err_printf("Failed to set ble profile mode !\n");
            goto error;
        }
        else {
            ret = ble_function_comm(AT_PROFILE, "+PROFILE=", profile, 3, 1);/*再次确认模块的模式是否为339*/
            if( ret < 0 ) {
                err_printf("Failed to set ble profile mode !\n");
                goto error;
            }

            ret = ble_function_comm(AT_STAT, "+STAT=", "1,1,1,1,1", 3, 5);/*确认模块已能正常响应*/
            if( ret < 0 ) {
                err_printf("Failed to get ble devstat !\n");
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}


int ble_transparent_transmission_update(int switch_value)
{
    int ret = 0;

    if( switch_value ) {    /*开启透传*/
        ret = ble_function_comm(AT_TPMODE, "+TPMODE=", "1", 3, 1);/*确认模块是否已经是透传模式*/
        //qDebug() << __func__ << __LINE__;
        if( ret < 0 ) {
            //qDebug() << __func__ << __LINE__;
            ret = ble_function_comm(AT_TPMODE_OPEN, "OK", NULL, 3, 1);/*开启透传模式*/
            if( ret < 0 ) {
                //qDebug() << __func__ << __LINE__;
                err_printf("Failed to set ble tp mode !\n");
                goto error;
            }
            else {
                //qDebug() << __func__ << __LINE__;
                ret = ble_function_comm(AT_TPMODE, "+TPMODE=", "1", 3, 1);/*再次确认模块模式是否是透传模式*/
                if( ret < 0 ) {
                    err_printf("Failed to set ble tp mode !\n");
                    goto error;
                }
            }

            //qDebug() << __func__ << __LINE__;
            ret = ble_function_comm(AT_REBOOT, "OK", NULL, 3, 1); /*模块重启保证透传模式设置生效*/
            if( ret < 0 ) {
                err_printf("Failed to reboot ble !\n");
                goto error;
            }
            //qDebug() << __func__ << __LINE__;
        }
    }
    else {
        //qDebug() << __func__ << __LINE__;
        ret = ble_function_comm(AT_TPMODE, "+TPMODE=", "0", 3, 1);/*确认模块是否是指令模式*/
        if( ret < 0 ) {
            //qDebug() << __func__ << __LINE__;
            ret = ble_function_comm(AT_TPMODE_CLOSE, "OK", NULL, 3, 1);/*关闭透传模式*/
            if( ret < 0 ) {
                err_printf("Failed to close ble tp mode !\n");
                goto error;
            }
            else {
                //qDebug() << __func__ << __LINE__;
                ret = ble_function_comm(AT_TPMODE, "+TPMODE=", "0", 3, 1);/*再次确认模块模式是否是透传模式*/
                if( ret < 0 ) {
                    err_printf("Failed to query ble tp mode !\n");
                    goto error;
                }
                //qDebug() << __func__ << __LINE__;
            }

            ret = ble_function_comm(AT_REBOOT, "OK", NULL, 3, 1); /*模块重启保证指令模式设置生效*/
            if( ret < 0 ) {
                err_printf("Failed to reboot ble !\n");
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}

/**********************************************************************************************

    函 数 名     : ble_transparent_transmission_init
    功能描述     : 蓝牙透传服务初始化
    输入参数     :
    dev_name
    serial_baudrate 串口波特率
    block_type 是否阻塞
           无
    输出参数     :
           无
    返 回 值     : int
                0                       成功
                其他                    失败
 ***********************************************************************************************/
int ble_transparent_transmission_init(char *dev_name, int serial_baudrate, int (*ble_data_call)(unsigned char *data, int datalen), int block_type, int ble_mode)
{
    __attribute__((unused))int file_flags = 0;
    int ret = 0;
    int temp = ble_mode;
    char temp_char[10];
    _itoa_(temp , temp_char);
    dev_printf(DEBUG_DEV_BLE, INIT_LEVEL, "ble transparent transmission init !\n");

    if( ble_data_call != NULL ) {
        g_ble_data_call = ble_data_call;
    }
    else {
        g_ble_data_call = NULL;
    }


    if( g_ble_fd != 0 || g_ble_fp != NULL ) {
        err_printf("ble file handle status error !\n");
        goto error;
    }

    ble_baud_modify(dev_name, serial_baudrate);

    g_serial_baudrate = serial_baudrate;
    g_ble_fd = serial_init(dev_name, g_serial_baudrate);//初始化通信串口
    if( g_ble_fd < 0 ) {
        err_printf("init %s error\n", dev_name);
        goto error;
    }
    serial_attribute_set(g_ble_fd, 0, 0, 0, ICANON);/*更新串口属性设置*/
    /*fp->fd:fileno()*/
    g_ble_fp = fdopen(g_ble_fd, "w+");/*获取文件指针*/

    MODULE_WRITE(AT_BLE_DSCA, g_ble_fp);                /*断开所有连接*/
    MODULE_WRITE(AT_BLE_SPPDISC, g_ble_fp);             /*断开SPP连接*/
    MODULE_WRITE(AT_BLE_AUTOCONN_OFF, g_ble_fp);        /*关闭自动连接*/
    ble_profile_update(ble_mode);
    ble_transparent_transmission_update(1);
    usleep(100);
//    ble_transmission_start(QString("CC15312C21B6"));
    g_serial_transparent_block_type = block_type;

    serial_attribute_clean(g_ble_fd, 0, 0, 0, ICANON);/*更新串口属性设置*/
    if( g_serial_transparent_block_type ) {
        file_flags = fcntl(g_ble_fd, F_GETFL, 0);
        file_flags &= ~O_NONBLOCK;/*设置流为阻塞模式*/
        fcntl(g_ble_fd, F_SETFL, file_flags);
    }
    else {
        file_flags = fcntl(g_ble_fd, F_GETFL, 0);
        file_flags |= O_NONBLOCK;/*设置流为非阻塞模式*/
        fcntl(g_ble_fd, F_SETFL, file_flags);
    }
    if( g_transparent_thread_id == 0 ) {
        int pthread_ret = 0;

        g_transparent_thread_quit = 0;/*标记线程为非退出状态*/
        /*蓝牙处理*/
        pthread_ret = pthread_create(&g_transparent_thread_id, NULL, ble_transparent_handle_thread, NULL);
        if( pthread_ret != 0 ) {
            err_printf("can't create transparent thread ret:%d error:%s\n", pthread_ret, strerror(pthread_ret));
            goto error;
        }
    }
    else {
        err_printf("transparent thread already started !\n");
        goto error;
    }
    return 0;
error:
    return -1;
}

void ble_transmission_reset()
{
    int ret = 0;
    ret = ble_function_comm(AT_RESTORE, "OK", NULL);
    if( ret < 0 ) {
        err_printf("AT_RESTORE SET %d !\n" , ret);
        ret = ble_function_comm(AT_RESTORE, "OK", NULL);
    }
    return;
}

int ble_transmission_start(QString addr)
{
    int ret = 0;
    g_ble_spp_link = 1;
    QString cmd = QString("AT+SPPCONN=") + addr + QString("\r\n");
    qDebug() << __func__ << cmd.toLocal8Bit().data();
    ret = ble_function_comm(cmd.toLocal8Bit().data(), "+SPPSTAT", NULL, 3, 1);
    if( ret < 0 ) {
        qDebug() << __func__ << addr;
        ret = ble_function_comm(cmd.toLocal8Bit().data(), "OK", NULL);
    }
    return 0;
error:
    return -1;
}

void ble_transmission_stop()//蓝牙关闭透传模式
{
    int ret = 0;
    if( g_ble_trans_mode == 1 ) {
        err_printf("start set ble transmode!\n");
        ret = ble_function_comm(AT_TPMODE, "+TPMODE=", "0");/*确认模块是否已经是关闭透传模式*/
        if( ret < 0 ) {
            ret = ble_function_comm(AT_TPMODE_CLOSE, "OK", NULL);/*关闭透传模式*/
            if( ret < 0 ) {
                err_printf("Failed to set ble tp mode 0!\n");
                return;
            }
            else {
                ret = ble_function_comm(AT_TPMODE, "+TPMODE=", "0");/*再次确认模块模式是否是透传模式*/
                if( ret < 0 ) {
                    err_printf("Failed to set ble tp mode 0!\n");
                    return;
                }
            }
        }
        g_ble_trans_mode = 0;   /*记录当前为非透传模式*/
    }
    ret = ble_function_comm(AT_BLE_DSCA, "OK", NULL);
    if( ret < 0 ) {
        err_printf("AT_BLE_DSCA SET 1%d !\n" , ret);
        ret = ble_function_comm(AT_BLE_DSCA, "OK", NULL);
        err_printf("AT_BLE_DSCA SET2 %d !\n" , ret);
    }
}
/**********************************************************************************************

    函 数 名     : ble_transparent_transmission_uninit
    功能描述     : 蓝牙透传服务反初始化
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : int
                0                       成功
                其他                    失败
 ***********************************************************************************************/
int ble_transparent_transmission_uninit()
{
    dev_printf(DEBUG_DEV_BLE, INIT_LEVEL, "ble transparent transmission uninit !\n");
    if( g_transparent_thread_id ) {
        int pthread_ret = 0;

        g_transparent_thread_quit = 1;/*设置线程退出*/
        pthread_ret = pthread_join(g_transparent_thread_id, NULL);//等待线程退出
        if( pthread_ret )
            err_printf("gatt pthread_join fail !!! ret:%d error:%s\n", pthread_ret, strerror(pthread_ret));
        g_transparent_thread_id = 0;
    }

    MODULE_WRITE(AT_BLE_DSCA, g_ble_fp);                /*断开所有连接*/
    MODULE_WRITE(AT_BLE_SPPDISC, g_ble_fp);             /*断开SPP连接*/
    MODULE_WRITE(AT_BLE_AUTOCONN_OFF, g_ble_fp);        /*关闭自动连接*/
    if(g_ble_fp) {
        fclose(g_ble_fp);
        g_ble_fp = NULL;
        g_ble_fd = 0;
    }
    return 0;
}


/**********************************************************************************************

    函 数 名     : bt1036_module_init
    功能描述     : 蓝牙模块初始化，获取设备流
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : int
                0                       成功
                其他                    失败
 ***********************************************************************************************/
int bt1036_module_init(char *dev_name, int serial_baudrate, int ble_mode)
{
    int file_flags = 0;

    dev_printf(DEBUG_DEV_BLE, INIT_LEVEL, "bt1036 module init !\n");

    if( g_ble_fd != 0 || g_ble_fp != NULL ) {
        err_printf("ble file handle status error !\n");
        goto error;
    }

    g_serial_baudrate = serial_baudrate;
    g_ble_fd = serial_init(dev_name, g_serial_baudrate);//初始化通信串口
    if( g_ble_fd < 0 ) {
        err_printf("init %s error\n", dev_name);
        goto error;
    }
    serial_attribute_set(g_ble_fd, 0, 0, 0, ICANON);/*更新串口属性设置*/
    /*fp->fd:fileno()*/
    g_ble_fp = fdopen(g_ble_fd, "w+");/*获取文件指针*/

    file_flags = fcntl(g_serial_fd, F_GETFL, 0);
    file_flags &= ~O_NONBLOCK;/*设置流为阻塞模式*/
    // file_flags |= O_NONBLOCK;/*设置流为非阻塞模式*/
    fcntl(g_serial_fd, F_SETFL, file_flags);

    ble_profile_update(ble_mode);

    if( g_ble_trans_mode != 0 ) {
        ble_transparent_transmission_update(0);
        g_ble_trans_mode = 0;   /*记录当前的传输模式*/
    }

    /*每次启动都主动断开一次所有的连接*/
    MODULE_WRITE(AT_BLE_DSCA, g_ble_fp);            /*写入指令*/
    MODULE_WRITE(AT_BLE_AUTOCONN_OFF, g_ble_fp);    /*关闭自动连接*/

    g_module_init = 1;

    return 0;
error:
    return -1;
}


/**********************************************************************************************

    函 数 名     : bt1036_module_uninit
    功能描述     : 蓝牙模块反初始化
    输入参数     :
           无
    输出参数     :
           无
    返 回 值     : int
                0                       成功
                其他                    失败
 ***********************************************************************************************/
int bt1036_module_uninit()
{
    if(g_ble_fp) {
        fclose(g_ble_fp);
        g_ble_fp = NULL;
        g_ble_fd = 0;
    }

    g_module_init = 0;

    dev_printf(DEBUG_DEV_BLE, INIT_LEVEL, "bt1036 module uninit !\n");

    return 0;
}

int bt1036_scan_ble_info()
{
    bt1036_module_init("/dev/ttymxc2", 115200, 0);

    ble_mode_uninit();/*清空之前的模式的数据*/

    int scan_state = 0;
    int a2dp_state = 0;
    int pair_state = 0;

    ble_mode_init();
    QString bleInfo;
    ble_scan_init();
    do {
        ble_get_state(&scan_state, &a2dp_state, &pair_state);
        usleep(3000000);
    } while(scan_state != 3 && scan_state != -1);
    printf("scan_state:%d !\n", scan_state);

    if( scan_state == 3 ) {
        int scan_length = ble_get_scan_result_length();
        char scan_info[scan_length];

        memset(scan_info, 0x00, scan_length);
        ble_copy_scan_result(scan_info);
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        bleInfo = codec->toUnicode(scan_info);
        printf("scan_info:%s !\n", scan_info);
    }
    qDebug() << bleInfo;
    hp_transmission::getInstance()->slot_stop_get_bleInfo(bleInfo);

    ble_mode_uninit();

    bt1036_module_uninit();
}


int bt986_mode_update()
{
    char profile[10] = {0};
    char profile_cmd[50] = {0};
    int ret = 0;

    serial_send(g_ble_fd, (unsigned char *)AT_MODE_SPP, strlen(AT_MODE_SPP));
    usleep(500000);
    return 0;
error:
    return -1;
}

int bt986_transmission_tpmode(int switch_value)
{
    int ret = 0;
    if( switch_value ) {    /*开启透传*/
        serial_send(g_ble_fd, (unsigned char *)AT_TPMODE_OPEN, strlen(AT_TPMODE_OPEN));
        usleep(500000);
    }
    else {
        serial_send(g_ble_fd, (unsigned char *)AT_TPMODE_CLOSE, strlen(AT_TPMODE_CLOSE));
        usleep(500000);
    }

    return 0;
error:
    return -1;
}

int bt986_transmission_init(char *dev_name, int serial_baudrate, int (*ble_data_call)(unsigned char *data, int datalen))
{
    int file_flags = 0;

    if( ble_data_call != NULL ) {
        g_ble_data_call = ble_data_call;
    }
    else {
        g_ble_data_call = NULL;
    }

    if( g_ble_fd != 0 || g_ble_fp != NULL ) {
        err_printf("ble file handle status error !\n");
        goto error;
    }

    g_ble_fd = serial_init(dev_name, serial_baudrate);/*460800 115200*/
    if( g_ble_fd <= 0 ) {
        goto error;
    }

    file_flags = fcntl(g_ble_fd, F_GETFL, 0);
    file_flags &= ~O_NONBLOCK;/*设置流为阻塞模式*/
    fcntl(g_ble_fd, F_SETFL, file_flags);

    if( g_transparent_thread_id == 0 ) {
        int pthread_ret = 0;

        g_transparent_thread_quit = 0;/*标记线程为非退出状态*/
        /*蓝牙处理*/
        pthread_ret = pthread_create(&g_transparent_thread_id, NULL, recv_thread, NULL);
        if( pthread_ret != 0 ) {
            err_printf("can't create transparent thread ret:%d error:%s\n", pthread_ret, strerror(pthread_ret));
            goto error;
        }
    }
    else {
        err_printf("transparent thread already started !\n");
        goto error;
    }
    g_serial_transparent_block_type = 1;
    g_serial_recv_quit = 0;
    qDebug() << __func__ << "AT_BLE_DSCA";
    serial_send(g_ble_fd, (unsigned char *)AT_BLE_DSCA, strlen(AT_BLE_DSCA));
    usleep(500000);
    qDebug() << __func__ << "AT_BLE_AUTOCONN_OFF";
    serial_send(g_ble_fd, (unsigned char *)AT_BLE_AUTOCONN_OFF, strlen(AT_BLE_AUTOCONN_OFF));
    usleep(500000);
    qDebug() << __func__ << "AT_TPMODE_CLOSE";
    serial_send(g_ble_fd, (unsigned char *)AT_TPMODE_CLOSE, strlen(AT_TPMODE_CLOSE));
    usleep(100000);

    return 0;
error:
    return -1;
}

int bt986_transmission_uninit()
{
    dev_printf(DEBUG_DEV_BLE, INIT_LEVEL, "ble transparent transmission uninit !\n");
    serial_send(g_ble_fd, (unsigned char *)AT_TPMODE_CLOSE, strlen(AT_TPMODE_CLOSE));
    usleep(100000);
    serial_send(g_ble_fd, (unsigned char *)AT_BLE_DSCA, strlen(AT_BLE_DSCA));
    usleep(500000);
    serial_send(g_ble_fd, (unsigned char *)AT_BLE_SPPDISC, strlen(AT_BLE_SPPDISC));
    usleep(500000);
    serial_send(g_ble_fd, (unsigned char *)AT_BLE_AUTOCONN_OFF, strlen(AT_BLE_AUTOCONN_OFF));
    usleep(500000);

    if( g_transparent_thread_id ) {
        int pthread_ret = 0;

        g_transparent_thread_quit = 1;/*设置线程退出*/
        pthread_ret = pthread_join(g_transparent_thread_id, NULL);//等待线程退出
        if( pthread_ret )
            err_printf("gatt pthread_join fail !!! ret:%d error:%s\n", pthread_ret, strerror(pthread_ret));
        g_transparent_thread_id = 0;
    }
    g_ble_fd = 0;
    return 0;
}

int bt986_transmission_start(QString addr)
{
    int ret = 0;
    g_ble_spp_link = 1;
    QString cmd = QString("AT+SPPCONN=") + addr + QString("\r\n");
    qDebug() << __func__ << "AT_SPPCONN_C42B44D2C054" << strlen(AT_SPPCONN_C42B44D2C054);
    serial_send(g_ble_fd, (unsigned char *)cmd.toLatin1().data(), strlen(AT_SPPCONN_C42B44D2C054));
    usleep(500000);
    qDebug() << __func__ << "AT_TPMODE_OPEN";
    serial_send(g_ble_fd, (unsigned char *)AT_TPMODE_OPEN, strlen(AT_TPMODE_OPEN));
    usleep(500000);
    return 0;
error:
    return -1;
}

int bt986_scan_ble_info()
{
    bt1036_module_init("/dev/ttyACM0", 115200, 0);

    ble_mode_uninit();/*清空之前的模式的数据*/

    int scan_state = 0;
    int a2dp_state = 0;
    int pair_state = 0;

    ble_mode_init();
    QString bleInfo;
    ble_scan_init();
    do {
        ble_get_state(&scan_state, &a2dp_state, &pair_state);
        usleep(3000000);
    } while(scan_state != 3 && scan_state != -1);
    printf("scan_state:%d !\n", scan_state);

    if( scan_state == 3 ) {
        int scan_length = ble_get_scan_result_length();
        char scan_info[scan_length];

        memset(scan_info, 0x00, scan_length);
        ble_copy_scan_result(scan_info);
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        bleInfo = codec->toUnicode(scan_info);
        printf("scan_info:%s !\n", scan_info);
    }
    qDebug() << bleInfo;
    hp_transmission::getInstance()->slot_stop_get_bleInfo(bleInfo);

    ble_mode_uninit();

    bt1036_module_uninit();
}

int bt986_transmission_save(const char* data, int data_len)
{
    // 打开文件，以追加模式写入，如果不存在则创建
    FILE *file = fopen("/run/media/mmcblk2p1/ble_data.log", "ab+");
    if (file == NULL) {
        qDebug() << __func__ << "open file failure";
        return -1; // 文件打开失败
    }

    // 写入数据
    size_t written = fwrite(data, 1, data_len, file);
    fclose(file);

    return written; // 返回写入结果
}

int bt986_transmission_send(const char* sdata, int data_len)
{//    // 打开文件，以追加模式写入，如果不存在则创建
//    FILE *file = fopen("ble_data.log", "ab+");
//    if (file == NULL) {
//        return -1; // 文件打开失败
//    }

//    // 写入数据
//    size_t written = fwrite(sdata, 1, data_len, file);
//    fclose(file);

//    return written; // 返回写入结果
    int ret = 0;
//    for( int i = 0; i < 5; i++ ) {
        ret = serial_write_timeout(g_ble_fd, (unsigned char *)sdata, data_len, 100000);
        if(ret == data_len)
            return ret;
        else
        {
            return 0;
            qDebug() << __func__ << "ret" << ret << data_len;
        }
//    }
    return 0;
}
