#include  "hpdomainapi.h"

HpDomainApi::HpDomainApi()
{

}

/**********************************************************************************************

    函 数 名     : Domain_client_init
    功能描述     : 本地SOCKET客户端初始化
    输入参数     :
           char *name          本地socket文件名字
    输出参数     : 无
    返 回 值     : int
           -1                  创建句柄失败
           -2                  连接失败
           其他                客户端socket句柄
 ***********************************************************************************************/
int HpDomainApi::Domain_client_init(char *name)//返回connect之后的socket
{
    int len;
    int sockfd;
    int ret;
    struct sockaddr_un address;
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);  //创建本地socket
    if (sockfd < 0) {
        qDebug("HpDomainApi socket:");
        return -1;
    }
    // sock addr
    address.sun_family=AF_UNIX;
    strcpy(address.sun_path, name);
    len = sizeof(address);

    ret = connect(sockfd, (struct sockaddr *)&address, len);  //连接服务端
    if (ret < 0) {
//        qDebug("HpDomainApi connect");
        close(sockfd);
        return -2;
    }
    return sockfd;
}

int HpDomainApi::Domain_client_uinit(int *sock)
{
    if(*sock > 0){
        close(*sock);
        *sock = -1;     //客户端句柄值设置
    }
    return 0;

}

int HpDomainApi::Domain_recv(int sock, unsigned char *buf, int buflen)
{

    int readlen;
    readlen = read(sock, buf, buflen);   //读出数据
    if (readlen < 0) {                   //失败
        perror("Domain_recv < 0");
        return readlen;
    } else if (readlen == 0) {
        printf("1==socket broken, quit\n");
        return -2;
    }
//    if((buf[1] == 0x12 && buf[2]== 0x85) || (buf[1] == 0x05 && buf[2] == 0x05))
//    {
//        printf("Domain_recv readlen %d - ", readlen);
//        for(int i = 0; i < readlen; i++)
//        {
//            printf("%x - ", buf[i]);
//        }
//    }
    return readlen;
}


int HpDomainApi::Domain_send(int sock, unsigned char *buf, int buflen)
{
    int sendlen = 0;

    sendlen = write(sock, buf, buflen);  //写入数据

    if (sendlen < 0) {
        perror("Domain_send");
    }
    return sendlen;
}
