#ifndef HIERARCHY_RTCP_SOCKET_H
#define HIERARCHY_RTCP_SOCKET_H

#include "RTCP.h"
#include "../RTP/RTPSocket.h"

void *RTCPSocketGet(const RTPSocketT *RTPSocket);

void RTCPSocketStartSession(RTPSocketT *RTPSocket,
                            const char *CName,
                            const SocketAddressT *PeerAddress);

void  RTCPSocketEnableMUX(RTPSocketT *RTPSocket,
                          bool IsMuxEnabled);

void  RTCPSocketSetSamplingRate(RTPSocketT *RTPSocket,
                                DWordT SamplingRateTX,
                                DWordT SamplingRateRX);

void  RTCPSocketSetSamplingRateTX(RTPSocketT *RTPSocket,
                                  DWordT SamplingRateTX);

void  RTCPSocketSetSamplingRateRX(RTPSocketT *RTPSocket,
                                  DWordT SamplingRateRX);

ErrnoT RTCPStats(RTCPStatsT *Stats,
                 RTPSocketT *Socket,
                 DWordT SyncSource);

#endif
