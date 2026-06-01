#ifndef HPDOMAINAPI_H
#define HPDOMAINAPI_H

#include  <QDebug>
#include  <stdio.h>
#include  <sys/types.h>
#include  <sys/socket.h>
#include  <sys/un.h>
#include  <stddef.h>
#include  <unistd.h>
#include  <fcntl.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include  <fcntl.h>

class HpDomainApi
{
public:
    HpDomainApi();

    int Domain_client_init(char *name);
    int Domain_client_uinit(int *sock);

    int Domain_send(int sock, unsigned char *buf, int buflen);
    int Domain_recv(int sock, unsigned char *buf, int buflen);
};

#endif // HPDOMAINAPI_H
