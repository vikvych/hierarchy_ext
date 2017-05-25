#ifndef HIERARCHY_RTP_HEADER_H
#define HIERARCHY_RTP_HEADER_H

#include "RTP.h"

ErrnoT RTPHeaderSerialize(MemoryBufferT *Buffer,
                          const RTPHeaderT *RTPHeader);

ErrnoT RTPHeaderParse(RTPHeaderT *RTPHeader,
                      MemoryBufferT *Data);

#endif
