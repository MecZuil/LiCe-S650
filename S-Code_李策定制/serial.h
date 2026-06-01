#ifndef SERIAL_H
#define SERIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>

#include "debug.h"

static int speed_arr[] = {B115200, B57600, B38400, B19200, B9600, B4800, B2400, B1200, B300, B230400, B460800, B921600};	//波特率属性，和值对应
static int name_arr[]  = {115200,  57600,  38400,  19200,  9600,  4800,  2400,  1200,  300,  230400,  460800,  921600};		//波特率值，和属性对应



int serial_init(char *dev_name, int baudrate);
int serial_uinit(int fd);
int serial_attribute_set(int fd, unsigned short c_iflag, unsigned short c_oflag, unsigned short c_cflag, unsigned short c_lflag);
int serial_attribute_clean(int fd, unsigned short c_iflag, unsigned short c_oflag, unsigned short c_cflag, unsigned short c_lflag);
int serial_recv(int fd, unsigned char *buf, int wantlen);
int serial_send(int fd, unsigned char *buf, int buflen);
int serial_recv_timeout(int fd, unsigned char *buf, int wantlen, int timeout_usec);
int serial_write_timeout(int fd, unsigned char *buf, int wantlen, int timeout_usec);


#endif // SERIAL_H
