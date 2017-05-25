#ifndef HIERARCHY_RTCP_MEMBER_H
#define HIERARCHY_RTCP_MEMBER_H

#include "RTCP.h"

#include "../RTP/RTPSource.h"

void RTCPMemberDestroy(void *RTCPMemberV);

RTCPMemberT *RTCPMemberInit(BinaryTreeT *MembersTree,
                            DWordT SSRC);

RTCPMemberT *RTCPMemberSearch(BinaryTreeT *Tree,
                              DWordT SSRC);

#endif
