#ifndef HIERARCHY_RTP_SOURCE_H
#define HIERARCHY_RTP_SOURCE_H

#include "RTP.h"

void RTPSourceInitSequence(RTPSourceT *RTPSource,
                           WordT Sequence);

ErrnoT RTPSourceUpdateSequence(RTPSourceT *RTPSource,
                               WordT Sequence);

void RTPSourceJitterCalculate(RTPSourceT *RTPSource,
                              DWordT RTPIncomingTimestamp,
                              DWordT RTPArrivalTimestamp);

SDWordT RTPSourceLostCalculate(RTPSourceT *RTPSource);

ByteT RTPSourceLostFractionCalculate(RTPSourceT *RTPSource);

#endif
