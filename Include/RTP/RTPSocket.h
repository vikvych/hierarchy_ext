#ifndef HIERARCHY_RTP_SOCKET_H
#define HIERARCHY_RTP_SOCKET_H

#include "RTP.h"

#define RTP_SOCKET_LISTEN_TRIES 0x40

RTPSocketT *RTPSocketInit();

RTPSocketT *RTPListen(int Proto,
                      const SocketAddressT *LocalIP,
                      WordT PortMin,
                      WordT PortMax,
                      bool IsRTCPEnabled,
                      RTPRecvCb *RecvCbRTP,
                      RTCPRecvCb *RecvCbRTCP,
                      void *Argument);

const SocketAddressT *RTPSocketGetLocalAddress(const RTPSocketT *Socket);
void *RTPSocketGet(const RTPSocketT *Socket);

#endif
