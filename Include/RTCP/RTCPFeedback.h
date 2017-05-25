#ifndef HIERARCHY_RTCP_FEEDBACK_H
#define HIERARCHY_RTCP_FEEDBACK_H

#include "RTCP.h"
#include "RTCPMessage.h"

ErrnoT RTCPFBGNACKSerialize(MemoryBufferT *Buffer,
                            WordT PictureId,
                            WordT LostPacketsBitmask);

ErrnoT RTCPPSFBSLISerialize(MemoryBufferT *Buffer,
                            WordT MacroBlockLostFirstAddress,
                            WordT MacroBlockLostCount,
                            ByteT PictureId);

ErrnoT RTCPFBParse(RTCPMessageT *Message,
                   MemoryBufferT *Buffer);

ErrnoT RTCPPSFBParse(RTCPMessageT *Message,
                     MemoryBufferT *Buffer);

#endif
