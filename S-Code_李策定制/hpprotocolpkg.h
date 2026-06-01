#ifndef HPPROTOCOLPKG_H
#define HPPROTOCOLPKG_H

#include  <QDebug>
#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>
#include  <sys/types.h>
#include  <string.h>
#include  <sys/stat.h>
#include  <fcntl.h>
#include  <errno.h>
#include  <sys/ioctl.h>
#include  <sys/time.h>

#include  "hi384_protocol.h"

#pragma once

typedef struct package_head_s		//包头信息
{
    unsigned char head;		//包头标记
    unsigned char cmd;		//主命令
    unsigned char sub_cmd;		//子命令
    unsigned char return_value;	//返回码
    unsigned char reserve;		//保留字节
    int datalen;			//操作数据长度
}__attribute__((packed))package_head_t;

typedef struct package_end_s          //包尾信息
{
    unsigned char verify;         //校验值
    unsigned char end;	      //尾部标记
}__attribute__((packed))package_end_t;


#define ERRORCMD 0xff                            //错误命令
#define RECV_PRO_HEAD 0x5b			//接收的数据头标记
#define RECV_PRO_END 0xdf			//接收的数据尾标记
#define SEND_PRO_HEAD 0x5a			//发送的数据头标记
#define SEND_PRO_END 0xef			//发送的数据尾标记

class HpProtocolPkg
{
public:
    HpProtocolPkg();
    int protocol_pkg_hp_create(unsigned char *buf,int buflen, unsigned char cmd,unsigned char subcmd,unsigned char reture_value, unsigned char *data, int datalen, int notverify);
    int protocol_pkg_hp_analysis(unsigned char *package, int packagelen, unsigned char *cmd, unsigned char *subcmd,unsigned char *reture_value, unsigned char *data, int *datalen);
    int protocol_pkg_hp_morepackage(unsigned char *head,int headlen);
    int protocol_pkg_hp_morepackageret(unsigned char *head,int headlen);
    int protocol_pkg_hp_moregetdate(unsigned char *cmd, unsigned char *subcmd,unsigned char *reture_value, unsigned char **data, int *datalen);

    int morelen;
    int morelenret;
    bool ismorelen;
    char *morePackage;
};

#endif // HPPROTOCOLPKG_H
