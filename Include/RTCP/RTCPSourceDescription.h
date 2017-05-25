#ifndef HIERARCHY_RTCP_SOURCE_DESCRIPTION_H
#define HIERARCHY_RTCP_SOURCE_DESCRIPTION_H

#include "RTCP.h"
#include "RTCPSession.h"

ErrnoT RTCPSourceDescriptionInit(RTCPSessionT *Session,
                                 MemoryBufferT *Buffer);

ErrnoT RTCPSourceDescriptionParse(RTCPSDESMessageT *SourceDescription,
                                  MemoryBufferT *Buffer);

ErrnoT RTCPSourceDescriptionSerialize(MemoryBufferT *Buffer,
                                      DWordT SSRC,
                                      DWordT ItemCount, ...);

#endif
