#include <uxr/client/profile/transport/ip/tcp/tcp_transport_external.h>
#include "tcp_transport_internal.h"

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/select.h>

#ifdef UCLIENT_PLATFORM_LINUX
static void sigpipe_handler(int fd)
{
    (void)fd;
}
#endif

bool uxr_init_tcp_platform(
        struct uxrTCPPlatform* platform,
        uxrIpProtocol ip_protocol,
        const char* ip,
        const char* port)
{
    bool rv = false;
    struct hostent *host = RT_NULL;
    struct sockaddr_in server_addr;

    if (ip_protocol != UXR_IPv4) {
        printf("Unsupported ip protocol\n");
        goto __exit;
    }

    host = (struct hostent *)gethostbyname(ip);
    if (host == RT_NULL)
    {
        printf("Get host by name failed!");
        goto __exit;
    }

    if((platform->sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Create socket error\n");
        goto __exit;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    rt_memset(&(server_addr.sin_zero), 0, sizeof(server_addr.sin_zero));

    if (connect(platform->sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        printf("Connect fail!\n");
        if (platform->sock >= 0)
        {
            closesocket(platform->sock);
            platform->sock = -1;
        }
        goto __exit;
    }

    rv = true;
__exit:
    return rv;
}

bool uxr_close_tcp_platform(
        struct uxrTCPPlatform* platform)
{
    if (platform->sock >= 0)
    {
        closesocket(platform->sock);
        platform->sock = -1;
    }
    return true;
}

size_t uxr_write_tcp_data_platform(
        struct uxrTCPPlatform* platform,
        const uint8_t* buf,
        size_t len,
        uint8_t* errcode)
{
    size_t rv = 0;
    ssize_t bytes_sent = send(platform->sock, (void*)buf, len, 0);
    if (-1 != bytes_sent)
    {
        rv = (size_t)bytes_sent;
        *errcode = 0;
    }
    else
    {
        *errcode = 1;
    }
    return rv;
}

size_t uxr_read_tcp_data_platform(
        struct uxrTCPPlatform* platform,
        uint8_t* buf,
        size_t len,
        int timeout,
        uint8_t* errcode)
{
    size_t rv = 0;
    fd_set readset;
    struct timeval timeout_val;
    timeout_val.tv_sec = timeout/1000;
    timeout_val.tv_usec = (timeout % 1000) * 1000;

    FD_ZERO(&readset);
    FD_SET(platform->sock, &readset);

    int poll_rv = select(platform->sock + 1, &readset, RT_NULL, RT_NULL, &timeout_val);

    if (0 < poll_rv)
    {
        ssize_t bytes_received = recv(platform->sock, (void*)buf, len, 0);
        if (-1 != bytes_received)
        {
            rv = (size_t)bytes_received;
            *errcode = 0;
        }
        else
        {
            *errcode = 1;
        }
    }
    else
    {
        *errcode = (0 == poll_rv) ? 0 : 1;
    }

    return rv;
}

void uxr_disconnect_tcp_platform(
        struct uxrTCPPlatform* platform)
{
    if (platform->sock >= 0)
    {
        closesocket(platform->sock);
        platform->sock = -1;
    }
    return;
}
