#ifndef HIERARCHY_RTP_SEND_H
#define HIERARCHY_RTP_SEND_H

#include "RTP.h"
#include "RTPSocket.h"

ErrnoT RTPSend(RTPSocketT *RTPSocket,
               const SocketAddressT *DestAddress,
               BitT MarkerFlag,
               ByteT PayloadType,
               DWordT Timestamp,
               MemoryBufferT *Payload);

#endif
