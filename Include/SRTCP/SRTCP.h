#ifndef HIERARCHY_SRTCP_H
#define HIERARCHY_SRTCP_H

#include <HierarchyBase.h>

#include "../SRTP/SRTP.h"
#include "../SRTP/SRTPStream.h"

ErrnoT SRTCPEncrypt(SRTPSessionT *SRTPSession,
                    MemoryBufferT *Buffer);

ErrnoT SRTCPDecrypt(SRTPSessionT *Session,
                    MemoryBufferT *Buffer);

#endif
