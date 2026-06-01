#include  "hpprotocolpkg.h"

HpProtocolPkg::HpProtocolPkg()
{
    morelen = 0;
    morelenret = 0;
    ismorelen = false;
}


/**********************************************************************************************
    函 数 名     : protocol_pkg_hp_create
    功能描述     : 对要发送的数据进行组包
    输入参数     :
           int buflen				组包数据缓存大小
           unsigned char cmd                    主命令
           unsigned char subcmd                 子命令
           unsigned char reture_value           返回码
           unsigned char *data                  数据
           int datalen				数据大小
           int notverify                        校验标记
    输出参数     :
           unsigned char *buf			组包数据
    返 回 值     : int
           -1					失败
           其他                                 数据包总长度
 ***********************************************************************************************/
int HpProtocolPkg::protocol_pkg_hp_create(unsigned char *buf, int buflen, unsigned char cmd, unsigned char subcmd, unsigned char reture_value, unsigned char *data, int datalen, int notverify)
{
    int totallen;
    package_head_t *head_t;
    package_end_t *end_t;
    unsigned char *tmp;
    int i;
    unsigned char verify = 0;

    if((datalen+sizeof(package_head_t)+sizeof(package_end_t)) > buflen){         //缓存不够
        return -1;
    }
    else{
        memset(buf, 0, buflen);

        /* 组包头 */
        head_t = (package_head_t *)buf;
        head_t->head = SEND_PRO_HEAD;   //发送的头标记
        head_t->cmd = cmd;
        head_t->sub_cmd = subcmd;
        //printf("sizeof(head_t->reserve)===%d\n", sizeof(head_t->reserve));
        head_t->return_value = reture_value;
        //memset(head_t->reserve,0, sizeof(head_t->reserve));
        head_t->reserve = 0;
        head_t->datalen = datalen;
        if(datalen > 0){
            memcpy(buf + sizeof(package_head_t), data, datalen); //组操作数据
        }

        tmp = (unsigned char *)&(head_t->cmd);
        //printf("(sizeof(package_head_t)-1+datalen)===%d\n", (sizeof(package_head_t)-1+datalen));
        if(notverify == 0){							//需要校验
            for(i = 0; i<(sizeof(package_head_t)-1+datalen); i++){
                //printf("*(tmp+i) = %.2x\n", *(tmp+i));
                verify ^= *(tmp+i);
            }
        }

        //printf("222verify==%.2x\n", verify);

        /* 组包尾 */
        end_t = (package_end_t *)(buf+sizeof(package_head_t)+datalen);
        end_t->verify = verify;
        end_t->end = SEND_PRO_END;					   //发送的包尾标记
        totallen = datalen+sizeof(package_head_t)+sizeof(package_end_t);   //整个数据包长度
    }
    return totallen;
}

/**********************************************************************************************

    函 数 名     : protocol_pkg_hp_analysis
    功能描述     : 对接收的数据包进行解析
    输入参数     :
           unsigned char *package		数据包
           int packagelen			数据包长度
    输出参数     :
           unsigned char *package		解析后不完整的数据包
           unsigned char *cmd                   主命令
           unsigned char *subcmd                子命令
           unsigned char *data                  操作数据
           int *datalen				操作数据长度
    返 回 值     : int
           -1					失败
           其他                                 未解析的数据包长度
 ***********************************************************************************************/
int HpProtocolPkg::protocol_pkg_hp_analysis(unsigned char *package, int packagelen, unsigned char *cmd, unsigned char *subcmd, unsigned char *reture_value,unsigned char *data, int *datalen)
{
    if(ismorelen)
    {
        int moreretrtn = protocol_pkg_hp_morepackageret(package, packagelen);
        if(moreretrtn == -4)
        {
            return -4;
        }
        return -3;
    }
    int head_flag = 0;
    package_head_t *head_t;
    package_end_t *end_t;
    unsigned char *tmp;
    int i = 0;
    int j = 0;
    int len = 0;
    unsigned char verify = 0;
    int valid_len = 0;
    for(i=0; i < packagelen; i++){
        if(*(package+i) == RECV_PRO_HEAD){              //接收头标记
            if((packagelen-i) > (sizeof(package_head_t)-1)){       //长度出错
                head_t = (package_head_t *)(package+i);		//头信息
                memcpy(&len, &(head_t->datalen), 4);		//获取操作数据长度
                if(i + len + sizeof(package_head_t) + sizeof(package_end_t) > 1024)//若包长度过长
                {
                    ismorelen = true;
                    morelen = len + sizeof(package_head_t) + sizeof(package_end_t);
                    protocol_pkg_hp_morepackage((unsigned char *)head_t, packagelen - i);//第一次不会每次都读到1024，原1024-i
                    return -3;
                }
//                if((head_t->sub_cmd == 0x85 && head_t->cmd== 0x12) || (head_t->sub_cmd == 0x05 && head_t->cmd== 0x05))
//                {
//                    printf("---------------------------------- = i = %d\n", i);
//                    printf("============================================== = head_t->head);         = %02x\n", head_t->head);
//                    printf("============================================== = head_t->cmd);          = %02x\n", head_t->cmd);
//                    printf("============================================== = head_t->sub_cmd);      = %02x\n", head_t->sub_cmd);
//                    printf("============================================== = head_t->return_value); = %02x\n", head_t->return_value);
//                    printf("============================================== = head_t->reserve);      = %02x\n", head_t->reserve);
//                    printf("============================================== = head_t->datalen);      = %02x\n", head_t->datalen);
//                }

                if((packagelen-i-sizeof(package_head_t)) > len){   //表示包含完整操作数据
                    *cmd = head_t->cmd;                  //获取主命令
                    *subcmd = head_t->sub_cmd;	     //获取子命令
                    *reture_value = head_t->return_value;
                    if(len > 0){
                        memcpy(data, package+i+sizeof(package_head_t), len);      //获取操作数据
                    }
                    tmp = (unsigned char *)&(head_t->cmd);
                    for(j = 0; j<(sizeof(package_head_t)-1+len); j++){   //从头部主命令这里开始做校验
                        verify ^= *(tmp+j);
                    }
                    end_t = (package_end_t *)(package+i+sizeof(package_head_t)+len);  //获取尾部信息，注意：这里如果长度过长，可能会触发段错误

                    if(verify == end_t->verify && end_t->end == RECV_PRO_END){  //校验检查和接收尾部标记检查
                        //if(end_t->end == RECV_PRO_END){
                        *datalen = len;                //操作数据长度
                        valid_len = sizeof(package_head_t)+len+sizeof(package_end_t);  //整个数据包长度
                    }
                    else{
                        continue;
                    }

//                    if((head_t->sub_cmd == 0x85 && head_t->cmd== 0x12) || (head_t->sub_cmd == 0x05 && head_t->cmd== 0x05))
//                    {
//                        printf("---------------------------------- = i = %d \n", i);
//                        printf("+++++++++++++++++++++++++++++++++ = head_t->head);        = %02x\n", head_t->head);
//                        printf("+++++++++++++++++++++++++++++++++ = head_t->cmd);         = %02x\n", head_t->cmd);
//                        printf("+++++++++++++++++++++++++++++++++ = head_t->sub_cmd);     = %02x\n", head_t->sub_cmd);
//                        printf("+++++++++++++++++++++++++++++++++ = head_t->return_value) = %02x\n", head_t->return_value);
//                        printf("+++++++++++++++++++++++++++++++++ = head_t->reserve);     = %02x\n", head_t->reserve);
//                        printf("+++++++++++++++++++++++++++++++++ = head_t->datalen);     = %02x\n", head_t->datalen);
//                    }
                    break;
                }
                else{                       //表示操作数据不完整
                    head_flag = 1;
                    break;
                }
            }
            else{
                head_flag = 2;
                break;
            }
        }
    }
    if(head_flag >= 1){
//        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! = head_flag = %d\n", head_flag);
        memcpy(package, package+i, packagelen-i);  // 该帧不完整的数据
        return packagelen-i;
    }
    if(valid_len > 0){
        if(packagelen-i-valid_len > 0){
            memcpy(package, package+i+valid_len, packagelen-i-valid_len); // 剩余内容
        }

//        if((head_t->sub_cmd == 0x85 && head_t->cmd== 0x12) || (head_t->sub_cmd == 0x05 && head_t->cmd== 0x05))
//        {
//            printf("---------------------------------- = valid_len = %d\n", valid_len);
//            printf("---------------------------------- = i = %d\n", i);
//            printf("---------------------------------- = packagelen = %d\n", packagelen);

//            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! = head_t->head);        = %02x\n", head_t->head);
//            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! = head_t->cmd);         = %02x\n", head_t->cmd);
//            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! = head_t->sub_cmd);     = %02x\n", head_t->sub_cmd);
//            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! = head_t->return_value) = %02x\n", head_t->return_value);
//            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! = head_t->reserve);     = %02x\n", head_t->reserve);
//            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! = head_t->datalen);     = %02x\n", head_t->datalen);
//        }
        return packagelen-i-valid_len;  //返回未解析的数据包长度
    }
    return -1;

}
//当数据量过大时触发
int HpProtocolPkg::protocol_pkg_hp_morepackage(unsigned char *head,int headlen)//(包总长,包头开始地址，包头长)
{
    qDebug() << "========================== IS MORE PACKAGE ==========================";
    morePackage = (char *)malloc(morelen);//创建包那么长的空间
    morelenret = headlen;
    memcpy(morePackage, head, headlen);//复制包头信息

    qDebug("morePackage Adress = %x",morePackage);
    qDebug() << "morelen ==> " << morelen << "  ; morelenret ==> " << morelenret << " ; thisPkglen == > " << headlen;

//    qDebug() << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ head recv";
//    for(int i = 0;i < headlen;i++)
//    {
//        printf("%c",head[i]);
//    }
//    qDebug() << "################################### head recv";

    return 0;
}
int HpProtocolPkg::protocol_pkg_hp_morepackageret(unsigned char *head,int headlen)
{
    qDebug() << "========================== protocol_pkg_hp_morepackageret ==========================";
    char *moreret = morePackage + morelenret;
    if(morelen - morelenret > headlen)
    {
        memcpy(moreret,head,headlen);
    }else{
        memcpy(moreret,head,morelen - morelenret);
    }



    morelenret = morelenret + headlen;

    qDebug() << "morelen ==> " << morelen << "  ; morelenret ==> " << morelenret << " ; thisPkglen == > " << headlen;

    if(morelen - morelenret <= 0)
    {
//        qDebug() << " break;";
        return -4;
    }
    return 0;
}

int HpProtocolPkg::protocol_pkg_hp_moregetdate(unsigned char *cmd, unsigned char *subcmd,unsigned char *reture_value, unsigned char **data, int *datalen)
{
    qDebug() << "========================== protocol_pkg_hp_moregetdate ==========================";
    int head_flag = 0;
    package_head_t *head_t;
    package_end_t *end_t;
    int i = 0;
    int j = 0;
    int len = 0;
    //printf("protocol_pkg_hp_analysis=========1packagelen===%d\n", packagelen);
    for(i=0; i<morelen; i++){
//        qDebug("%d :  *(morePackage+i) = %x", i,*(morePackage+i));
        if(*(morePackage+i) == RECV_PRO_HEAD){              //接收头标记
//            qDebug() << " (morelen-i) = " << (morelen-i) << "  : (sizeof(package_head_t)-1) = " << (sizeof(package_head_t)-1);
            if((morelen-i) > (sizeof(package_head_t)-1)){       //长度出错
                head_t = (package_head_t *)(morePackage+i);		//头信息
                memcpy(&len, &(head_t->datalen), 4);		//获取操作数据长度
//                qDebug() << " (morelen-i-sizeof(package_head_t)) = " << (morelen-i-sizeof(package_head_t)) << "  : len = " << len;
                *cmd = head_t->cmd;                  //获取主命令
                *subcmd = head_t->sub_cmd;	     //获取子命令
                *reture_value = head_t->return_value;
//                qDebug() << " len = " << len;
                if(len > 0){
                    (*data) = (unsigned char *)morePackage+i+sizeof(package_head_t);
                }
                *datalen = len;
                break;
            }
            else{
                head_flag = 1;
                break;
            }
        }
    }
//    qDebug("data Adress = %x",data);
    morelenret = 0;
    morelen = 0;
    ismorelen = false;
    return -1;
}
