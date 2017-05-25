#ifndef HIERARCHY_RTP_SESSION_H
#define HIERARCHY_RTP_SESSION_H

#include "RTP.h"
#include "RTPSocket.h"
#include "../RTCP/RTCPMessage.h"

DWordT RTPSessionSSRC(const RTPSocketT *RTPSocket);

#endif
