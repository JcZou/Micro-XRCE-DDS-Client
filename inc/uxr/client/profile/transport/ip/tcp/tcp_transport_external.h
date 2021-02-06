#ifndef UXR_CLIENT_PROFILE_TRANSPORT_IP_TCP_EXTERNAL_H_
#define UXR_CLIENT_PROFILE_TRANSPORT_IP_TCP_EXTERNAL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include "netdb.h"
#include <rtthread.h>

typedef struct uxrTCPPlatform
{
    int sock;
} uxrTCPPlatform;

#ifdef __cplusplus
}
#endif

#endif // UXR_CLIENT_PROFILE_TRANSPORT_IP_TCP_EXTERNAL_H_