#ifndef HIERARCHY_RTP_MESSAGE_H
#define HIERARCHY_RTP_MESSAGE_H

#include "RTP.h"
#include "RTPHeader.h"
#include "RTPSocket.h"

ErrnoT RTPPacketEncode(MemoryBufferT *Buffer,
                       RTPSocketT *RTPSocket,
                       BitT MarkerFlag,
                       ByteT PayloadType,
                       DWordT Timestamp);

ErrnoT RTPPacketDecode(RTPHeaderT *RTPHeader,
                       RTPSocketT *RTPSocket,
                       MemoryBufferT *Buffer);

#endif
