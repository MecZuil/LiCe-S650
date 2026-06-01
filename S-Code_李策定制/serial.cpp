#include "serial.h"
/**********************************************************************************************

    函 数 名     : set_speed
    功能描述     : 设置串口波特率
    输入参数     :
           int fd					串口句柄
           int speed				波特率值
    输出参数     : 无
    返 回 值     : int
           -1					失败
           0					成功
 ***********************************************************************************************/
static int set_speed(int fd, int speed)
{
    int   i;
    int   status;
    struct termios Opt;
    tcgetattr(fd, &Opt); 						//获取串口参数
    for ( i= 0;  i < sizeof(speed_arr) / sizeof(int);  i++) {
        if  (speed == name_arr[i]) { 			//查找对应波特率索引
            tcflush(fd, TCIOFLUSH);  			//清除所有正在发生的I/O数据
            cfsetispeed(&Opt, speed_arr[i]); 	//设置索引对应的输入波特率
            cfsetospeed(&Opt, speed_arr[i]);	//设置索引对应的输出波特率
            status = tcsetattr(fd, TCSANOW, &Opt);//设置参数，使波特率设置生效
            if  (status != 0) {
                err_printf("tcsetattr set fail !\n");
                return -1;
            }
            tcflush(fd,TCIOFLUSH);
            return 0;
        }
    }
    return 0;
}


/**********************************************************************************************

    函 数 名     : set_Parity
    功能描述     : 设置串口校验
    输入参数     :
           int fd				串口句柄
           int databits				数据位
           int stopbits				停止位
           int parity				校验方式
    输出参数     : 无
    返 回 值     : int
           0					成功
           其他					失败
 ***********************************************************************************************/
static int set_parity(int fd, int databits, int stopbits, int parity)
{
    struct termios options;

    if ( tcgetattr(fd,&options)!=0) { 	/*获取设备参数*/
        err_printf("tcgetattr set fail !\n");
        return -1;
    }

    /*设置数据位*/
    options.c_cflag &= ~CSIZE;/*先清空原先的数据位数大小*/
    switch (databits)
    {
    case 7:
        options.c_cflag |= CS7;
        break;
    case 8:
        options.c_cflag |= CS8;
        break;
    default:
        err_printf("Unsupported databits !\n");
        return -2;
    }

    /*设置校验位*/
    switch (parity)
    {
    case 'n':
    case 'N':
        options.c_cflag &= ~PARENB;/*校验不使能*/
        options.c_iflag &= ~INPCK;/*不启用校验检测*/
        break;
    case 'o':
    case 'O':
        options.c_cflag |= (PARODD | PARENB);/*设置为奇效验*/
        options.c_iflag |= INPCK;            /*启用校验检测*/
        break;
    case 'e':
    case 'E':
        options.c_cflag |= PARENB;   /*校验使能*/
        options.c_cflag &= ~PARODD;  /*转换为偶效验*/
        options.c_iflag |= INPCK;
        break;
    case 'S':
    case 's':
        options.c_cflag &= ~PARENB;
        options.c_cflag &= ~CSTOPB;	/*1个停止位*/
        break;
    default:
        err_printf("Unsupported parity !\n");
        return -3;
    }

    /* 设置停止位*/
    switch (stopbits)
    {
    case 1:
        options.c_cflag &= ~CSTOPB;
        break;
    case 2:
        options.c_cflag |= CSTOPB;
        break;
    default:
        err_printf("Unsupported stop bits !\n");
        return -4;
    }

    tcflush(fd,TCIFLUSH);		//清除所有正在发生的I/O数据

    /* 控制字符设置 */
    options.c_cc[VTIME] = 0;
    options.c_cc[VMIN] = 0;

    options.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);	//输入模式设置
    options.c_lflag &= ~(ICANON|ECHO|ECHONL|ISIG|IEXTEN|ECHOE);					//本地模式设置
    options.c_oflag &= ~OPOST;						          					//输出模式设置

    if (tcsetattr(fd,TCSANOW,&options) != 0) { 	/*设置参数，使校验设置生效*/
        err_printf("tcsetattr set fail !\n");
        return -5;
    }

    return 0;
}


/**********************************************************************************************

    函 数 名     : OpenDev
    功能描述     : 打开串口设备
    输入参数     :
           char *Dev				串口设备路径
    输出参数     : 无
    返 回 值     : int
           -1					失败
           其他					串口设备句柄
 ***********************************************************************************************/
static int open_dev(char *Dev)
{
    int	fd = open( Dev, O_RDWR | O_NOCTTY | O_NDELAY);
    if (-1 == fd) {
        err_printf("Can't Open Serial Port !\n");
        return -1;
    } else {
        return fd;
    }
}


/**********************************************************************************************

    函 数 名     : serial_attribute_set
    功能描述     : 设置串口属性
    输入参数     :
           unsigned short c_iflag					输入模式标志
           unsigned short c_oflag					输出模式标志
           unsigned short c_cflag					控制模式标志
           unsigned short c_lflag					区域模式标志或本地模式标志或局部模式
    输出参数     : 无
    返 回 值     : int
           -1					失败
           0					成功
 ***********************************************************************************************/
int serial_attribute_set(int fd, unsigned short c_iflag, unsigned short c_oflag, unsigned short c_cflag, unsigned short c_lflag)
{
    struct termios options;

    if ( tcgetattr(fd,&options)!=0) { 	/*获取设备参数*/
        err_printf("tcgetattr set fail !\n");
        return -1;
    }

    /*
        属性关联行为说明：
            ICANON 表示的是规范行为。
                在规范模式下，输入数据通常会被缓冲，并且需要满足一定条件才会被传递给程序。最典型的条件就是输入行终结符（通常是换行符）。
                只有当接收到换行符时，或者缓冲区已满时，数据才会被传递给程序进行处理。
                在非规范模式下，输入数据会立即可用，而不需要等待特定的控制字符或结束符。
            OPOST 表示的是输出处理
                当 OPOST 被设置时，输出数据将会被系统进行处理，而不是直接发送到串口。
                在默认情况下（ OPOST 被启用），系统会对输出的数据进行一些处理，比如将换行符转换为回车加换行符、执行输出字符的本地转义等操作。
                这种处理可以使输出更符合终端设备的要求，但也可能会导致某些特定需求下的输出问题。
                当 OPOST 属性被禁用时，在输出时系统不会对数据进行处理，需要手动控制输出的格式和特殊字符，比如需要手动添加换行符才能进行输出。
    */
    /*
        通过 stty -F /dev/ttyxxx -a 可以查看当前的串口属性
        前面加 - 表示该功能设置被清除
    */
    /*
    c_iflag:
        [-]BRKINT           	任务中断会触发中断信号
        [-]ICRNL              	将回车转换为换行符
        [-]IGNBRK           	忽略中断字符
        [-]IGNCR             	忽略回车
        [-]IGNPAR           	忽略含有奇偶不对称错误的字符
        * [-]IMAXBEL        	发出终端响铃但不刷新字符的完整输入缓冲
        [-]INLCR              	将换行符转换为回车
        [-]INPCK            	启用输入奇偶性校验
        [-]ISTRIP             	剥除输入字符的高8 位比特
        * [-]IUTF8              假定输入字符都是UTF-8 编码
        * [-]IUCLC              将大写字母转换为小写
        * [-]IXANY             	使得任何字符都会重启输出，不仅仅是起始字符
        [-]IXOFF               	启用开始/停止字符传送
        [-]IXON               	启用XON/XOFF 流控制
        [-]PARMRK           	标记奇偶校验错误 (结合255-0 字符序列)
        [-]TANDEM          		等于[-]IXOFF
    */
    options.c_iflag |= c_iflag;						//输入模式设置
    /*
    c_oflag:
        * BSN          		退格延迟的风格，N 的值为0 至1
        * CRN           	回车延迟的风格，N 的值为0 至3
        * FFN            	换页延迟的风格，N 的值为0 至1
        * NLN           	换行延迟的风格，N 的值为0 至1
        * [-]OCRNL     		将回车转换为换行符
        * [-]OFDEL     		使用删除字符代替空字符作填充
        * [-]OFILL        	延迟时使用字符填充代替定时器同步
        * [-]OLCUC     		转换小写字母为大写
        * [-]ONLCR     		将换行符转换为回车
        * [-]ONLRET    		使得换行符的行为表现和回车相同
        * [-]ONOCR    		不在第一列输出回车
        [-]OPOST     		后续进程输出
        * TABN         		水平制表符延迟的风格，N 的值为0 至3
        * TABS          	等于tab0
        * -TABS         	等于tab3
        * VTN            	垂直制表符延迟的风格，N 的值为0 至1
    */
    options.c_oflag |= c_oflag;						//输出模式设置
    /*
    c_cflag:
        CSIZE(CSN)			字符长度掩码（传送或接收字元时用的位数）。取值为 CS5（传送或接收字元时用5bits）, CS6, CS7, 或 CS8
        [-]CLOCAL          	禁用调制解调器控制信号
        [-]CREAD          	允许接收输入
        [-]CRTSCTS        	启用RTS/CTS 握手
        [-]CSTOPB        	每个字符使用2 位停止位 (要恢复成1 位配合"-"即可)
        [-]HUP             	当最后一个进程关闭标准终端后发送挂起信号
        [-]HUPCL           	等于[-]HUP
        [-]PARENB         	对输出生成奇偶校验位并等待输入的奇偶校验位
        [-]PARODD         	设置校验位为奇数 (配合"-"则为偶数)
    */
    options.c_cflag |= c_cflag;						//控制模式设置
    /*
    c_lflag:
        [-]CRTERASE  		擦除字符回显为退格符
        * CRTKILL          	依照 ECHOPRT 和 ECHOE 的设置清除所有行
        * -CRTKILL         	依照 ECHOCTL 和 echol 的设置清除所有行
        * [-]CTLECHO   		在头字符中输出控制符号("^c")
        [-]ECHO       		回显输入字符
        * [-]ECHOCTL  		等于[-]CTLECHO
        [-]ECHOE     		如果同时设置了 ICANON，字符 ERASE 擦除前一个输入字符，WERASE 擦除前一个词。
        [-]ECHOK     		如果同时设置了 ICANON，字符 KILL 删除当前行。
        * [-]ECHOKE    		等于[-]CRTKILL 意义相同
        [-]ECHONL    		如果同时设置了 ICANON，回显字符 NL，即使没有设置 ECHO。
        * [-]ECHOPRT   		在"\"和"/"之间向后显示擦除的字符
        [-]ICANON    		启用标准模式 (canonical mode)。启用 erase kill werase 和 rprnt 等特殊字符，以及按行的缓冲。
        [-]IEXTEN      		允许POSIX 标准以外的特殊字符
        [-]ISIG          	启用 interrupt quit 和 suspend 等特殊字符，产生相应的信号。
        [-]NOFLSH      		在 interrupt 和 quit 特殊字符后禁止刷新
        * [-]PRTERASE  		等于[-]ECHOPRT
        * [-]TOSTOP     	中止尝试向终端写入数据的后台任务
        * [-]XCASE     		和 ICANON 配合使用，用转义符"\"退出大写状态
    */
    options.c_lflag |= c_lflag;						//本地模式设置

    if (tcsetattr(fd,TCSANOW,&options) != 0) { 	/*设置参数，使校验设置生效*/
        err_printf("tcsetattr set fail !\n");
        return -1;
    }

    return 0;
}


/**********************************************************************************************

    函 数 名     : serial_attribute_clean
    功能描述     : 清除串口属性
    输入参数     :
           unsigned short c_iflag					输入模式标志
           unsigned short c_oflag					输出模式标志
           unsigned short c_cflag					控制模式标志
           unsigned short c_lflag					区域模式标志或本地模式标志或局部模式
    输出参数     : 无
    返 回 值     : int
           -1					失败
           0					成功
 ***********************************************************************************************/
int serial_attribute_clean(int fd, unsigned short c_iflag, unsigned short c_oflag, unsigned short c_cflag, unsigned short c_lflag)
{
    struct termios options;

    if ( tcgetattr(fd,&options)!=0) { 	/*获取设备参数*/
        err_printf("tcgetattr set fail !\n");
        return -1;
    }

    options.c_iflag &= ~c_iflag;						//输入模式设置
    options.c_oflag &= ~c_oflag;						//输出模式设置
    options.c_cflag &= ~c_cflag;						//控制模式设置
    options.c_lflag &= ~c_lflag;						//本地模式设置

    if (tcsetattr(fd,TCSANOW,&options) != 0) { 	/*设置参数，使校验设置生效*/
        err_printf("tcsetattr set fail !\n");
        return -1;
    }

    return 0;
}


/**********************************************************************************************

    函 数 名     : serial_init
    功能描述     : 串口初始化
    输入参数     :
           char *dev_name				串口设备路径
           int baudrate					波特率
    输出参数     : 无
    返 回 值     : int
           -1					失败
           其他					串口设备句柄
 ***********************************************************************************************/
int serial_init(char *dev_name, int baudrate)
{
    int fd = open_dev(dev_name);
    if(fd <= 0){
        return -1;
    }
    set_speed(fd, baudrate);
    set_parity(fd, 8, 1, 'N');

    return fd;
}


/**********************************************************************************************

    函 数 名     : serial_uinit
    功能描述     : 串口反初始化
    输入参数     :
           int fd				串口设备句柄
    输出参数     : 无
    返 回 值     : int
           0					成功
 ***********************************************************************************************/
int serial_uinit(int fd)
{
    if(fd > 0){
        close(fd);
    }
    return 0;
}


/**********************************************************************************************

    函 数 名     : serial_recv
    功能描述     : 接收串口数据
    输入参数     :
           int fd				串口设备句柄
           int wantlen			希望接收长度
    输出参数     :
           unsigned char *buf			数据
    返 回 值     : int					实际接收长度
 ***********************************************************************************************/
int serial_recv(int fd, unsigned char *buf, int wantlen)
{
    int ret;

    int i;
    ret = read (fd, buf, wantlen);
    dev_printf(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "fd:%d serial_recv   want recv len:%d, recv len:%d  \n", fd, wantlen, ret);
    dev_printf(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "fd:%d serial_recv:   ", fd);
    for(i = 0; i<ret; i++){
        dev_debug(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "%.2x ", *(buf+i));
    }
    dev_debug(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "\n");

    return ret;
}


/**********************************************************************************************

    函 数 名     : serial_send
    功能描述     : 发送串口数据
    输入参数     :
           int fd				串口设备句柄
           unsigned char *buf			数据
           int buflen				数据长度
    输出参数     :
           无
    返 回 值     : int					实际发送长度
 ***********************************************************************************************/
int serial_send(int fd, unsigned char *buf, int buflen)
{
    int ret;

    int i;
    dev_printf(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "fd:%d serial_send   ", fd);
    for(i = 0; i<buflen; i++){
        dev_debug(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "%.2x ", *(buf+i));
    }
    dev_debug(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "\n");

    ret = write(fd, buf, buflen);

    dev_debug(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "serial send ret: %d\n", ret);

    return ret;
}




/**********************************************************************************************

    函 数 名     : serial_recv_timeout
    功能描述     : 定时接收串口数据
    输入参数     :
           int fd						串口设备句柄
           int wantlen					希望接收长度
           int timeout_usec				超时接收时间(us)
    输出参数     :
           unsigned char *buf			数据
    返 回 值     : int					实际接收长度
 ***********************************************************************************************/
int serial_recv_timeout(int fd, unsigned char *buf, int wantlen, int timeout_usec)
{
    fd_set         readset;
    struct timeval timeout;
    struct timeval recv_start, recv_stop;
    int recv_time = 0;
    int recvlen = 0;
    int recvlen_sum = 0;
    int ret = 0;

    gettimeofday(&recv_start, NULL);

    while( recv_time <= timeout_usec ) {

        FD_ZERO(&readset); //清空可读集合
        FD_SET(fd, &readset);       //将当前机芯上位机通讯句柄加入可读集合
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000;                               	/*设置每次超时时间为100ms*/

        ret = select(fd + 1, &readset, NULL, NULL, &timeout);    //监听机芯上位机句柄的可读状态
        if (ret > 0) {  //有可读的数据

            recvlen = read(fd, buf, wantlen-recvlen_sum);
            recvlen_sum += recvlen;

            dev_printf(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "fd:%d serial_recv_timeout   want recv len:%d, recv sum len:%d, recv len:%d  \n",
                                            fd, wantlen, recvlen_sum, recvlen);
            dev_printf(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "fd:%d serial_recv_timeout:   ", fd);
            for(int i=0; i<recvlen; i++){
                dev_debug(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "%.2x ", *(buf+i));
            }
            dev_debug(DEBUG_DEV_SERIAL, DBG_LEVEL_MID, "\n");

            if( recvlen_sum == wantlen ) {
                break;
            }
        }
        else if(ret == 0){	//没有可读的数据
            usleep(100);
        }
        else{//监听出错
            err_printf("select err !\n");
            break;
        }

        usleep(100);
        gettimeofday(&recv_stop, NULL);
        recv_time = (recv_stop.tv_sec-recv_start.tv_sec)*1000000+(recv_stop.tv_usec-recv_start.tv_usec);
    }

    return recvlen_sum;
}

int serial_write_timeout(int fd, unsigned char *buf, int wantlen, int timeout_usec)
{
    fd_set         writeset;
    struct timeval timeout;
    struct timeval write_start, write_stop;
    int write_time = 0;
    int writelen = 0;
    int writelen_sum = 0;
    int ret = 0;

    gettimeofday(&write_start, NULL);

    while( write_time <= timeout_usec ) {

        FD_ZERO(&writeset); //清空可读集合
        FD_SET(fd, &writeset);       //将当前机芯上位机通讯句柄加入可读集合
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000;                               	/*设置每次超时时间为100ms*/

        ret = select(fd + 1, NULL, &writeset, NULL, &timeout);    //监听机芯上位机句柄的可读状态
        if (ret > 0) {  //有可读的数据

            writelen = write(fd, buf, wantlen-writelen_sum);
            writelen_sum += writelen;

            if( writelen_sum == wantlen ) {
                break;
            }
        }
        else if(ret == 0){	//没有可读的数据
            usleep(100);
        }
        else{//监听出错
            err_printf("select err !\n");
            break;
        }

        usleep(100);
        gettimeofday(&write_stop, NULL);
        write_time = (write_stop.tv_sec-write_start.tv_sec)*1000000+(write_stop.tv_usec-write_start.tv_usec);
    }

    return writelen_sum;
}
