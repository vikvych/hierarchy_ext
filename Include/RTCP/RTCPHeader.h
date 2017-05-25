#ifndef HIERARCHY_RTCP_HEADER_H
#define HIERARCHY_RTCP_HEADER_H

#include "RTCP.h"

ErrnoT RTCPHeaderSerialize(MemoryBufferT *Buffer,
                           ByteT SubElementCount,
                           RTCPPacketTypeT PacketType,
                           WordT PacketSize);

ErrnoT RTCPHeaderParse(RTCPHeaderT *Header,
                       MemoryBufferT *Buffer);

#endif
