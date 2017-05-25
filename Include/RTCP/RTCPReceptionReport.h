#ifndef HIERARCHY_RTCP_RECEPTION_REPORT_H
#define HIERARCHY_RTCP_RECEPTION_REPORT_H

#include "RTCP.h"

RTCPReceptionReportT *RTCPReceptionReportInit(SizeT Count);

ErrnoT RTCPReceptionReportEncode(MemoryBufferT *Buffer,
                                 const RTCPReceptionReportT *Report);

ErrnoT RTCPReceptionReportDecode(RTCPReceptionReportT *Report,
                                 MemoryBufferT *Buffer);

#endif
