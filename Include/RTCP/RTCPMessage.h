#ifndef HIERARCHY_RTCP_MESSAGE_H
#define HIERARCHY_RTCP_MESSAGE_H

#include "RTCP.h"
#include "RTCPHeader.h"
#include "RTCPReceptionReport.h"

ErrnoT RTCPMessageVSerialize(MemoryBufferT *Buffer,
                             RTCPPacketTypeT Type,
                             DWordT Count,
                             va_list ArgsPtr);

ErrnoT RTCPMessageSerialize(MemoryBufferT *Buffer,
                            RTCPPacketTypeT Type,
                            DWordT Count, ...);

RTCPMessageT *RTCPMessageParse(MemoryBufferT *Buffer);

void RTRTCPMessageDebug(const RTCPMessageT *Message);

#endif
