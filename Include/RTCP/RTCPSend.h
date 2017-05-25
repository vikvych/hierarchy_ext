#ifndef HIERARCHY_RTCP_SEND_H
#define HIERARCHY_RTCP_SEND_H

#include "../RTP/RTPSocket.h"

ErrnoT RTCPSend(RTPSocketT *Socket,
                MemoryBufferT *Data);

ErrnoT RTCPSendAPP(RTPSocketT *Socket,
                   const char Name[4],
                   const ByteT *Data,
                   SizeT DataSize);

ErrnoT RTCPSendFIR(RTPSocketT *Socket,
                   DWordT SSRC);

ErrnoT RTCPSendNACK(RTPSocketT *Socket,
                    WordT SeqFirstLost,
                    WordT LostPacketsBitmask);

ErrnoT RTCPSendPLI(RTPSocketT *Socket,
                   DWordT FBSSRC);

#endif
