#ifndef HIERARCHY_RTCP_SESSION_H
#define HIERARCHY_RTCP_SESSION_H

#include "RTCP.h"
#include "RTCPSend.h"

void RTCPSessionDestroy(void *RTCPSessionV);
RTCPSessionT *RTCPSessionInit(RTPSocketT *RTPSocket);
RTCPSessionT *RTCPSessionGet(const RTPSocketT *RTPSocket);

DWordT RTCPSessionSSRC(const RTPSocketT *RTPSocket);
void RTCPSessionSchedule(RTCPSessionT *RTCPSession);

ErrnoT RTCPSessionRTCPEnable(RTCPSessionT *RTCPSession,
                   bool IsRTCPEnabled,
                   const char *CName);

void RTCPSessionDataCb(RTCPSessionT *Session, RTCPMessageT *Message);

void RTCPSessionRTPTX(RTCPSessionT *Session,
                      DWordT Timestamp,
                      SizeT PayloadSize);

void RTCPSessionRTPRX(RTCPSessionT *RTCPSession,
                      WordT Sequence,
                      DWordT Timestamp,
                      DWordT SSRC,
                      SizeT PayloadSize,
                      const SocketAddressT *PeerAddress);

#endif
