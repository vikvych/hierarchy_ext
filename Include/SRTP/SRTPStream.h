#ifndef HIERARCHY_SRTP_STREAM_H
#define HIERARCHY_SRTP_STREAM_H

#include "SRTP.h"
#include "SRTPReplay.h"

typedef struct {
    ListNodeT ListNode;
    SRTPReplayT RTPReplay;
    SRTPReplayT RTCPReplay;
    DWordT SSRC;
    DWordT RollOverCounter;
    WordT Seq;
    bool IsSeqInit;
    DWordT RTCPIndex;
} SRTPStreamT;

SRTPStreamT *SRTPStreamGet(SRTPSessionT *Session,
                           DWordT SSRC);

SRTPStreamT *SRTPStreamGetSeq(SRTPSessionT *Session,
                              DWordT SSRC,
                              WordT Seq);

#endif
