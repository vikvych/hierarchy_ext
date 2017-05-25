#ifndef HIERARCHY_SRTP_REPLAY_H
#define HIERARCHY_SRTP_REPLAY_H

#include "SRTP.h"

typedef struct {
    QWordT State;
    QWordT LastRecvdIndex;
} SRTPReplayT;

void SRTPReplayInit(SRTPReplayT *Replay);

bool SRTPReplayCheck(SRTPReplayT *Replay,
                     QWordT Index);

#endif
