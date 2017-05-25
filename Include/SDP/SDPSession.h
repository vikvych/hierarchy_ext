#ifndef HIERARCHY_SDP_SESSION_H
#define HIERARCHY_SDP_SESSION_H

#include <HierarchyBase.h>
#include "SDPBandwidth.h"
#include "SDPDirection.h"
#include "SDPAttribute.h"

typedef struct {
    ListT LocalMediaList;
    ListT MediaList;
    ListT LocalAttributeList;
    ListT RemoteAttributeList;
    SocketAddressT LocalAddress;
    SocketAddressT RemoteAddress;
    SSizeT LocalBandwidthValue[SDP_BANDWIDTH_MAX];
    SSizeT RemoteBandwidthValue[SDP_BANDWIDTH_MAX];
    QWordT Id;
    QWordT Ver;
    SDPDirectionT RemoteDirection;
} SDPSessionT;



void SDPSessionDestroy(void *SDPSessionV);

ErrnoT SDPSessionInit(SDPSessionT **Session,
                      const SocketAddressT *LocalAddress);

void SDPSessionLocalAddressSet(SDPSessionT *Session,
                               const SocketAddressT *LocalAddress);

void SDPSessionLocalBandwidthSet(SDPSessionT *Session,
                                 SDPBandwidthT BandwidthType,
                                 SSizeT Bandwidth);

ErrnoT SDPSessionLocalAttributeSet(SDPSessionT *Session,
                                   bool ReplaceExcitingAttributes,
                                   const char *AttributeKey,
                                   const char *AttributeValue, ...);

void SDPSessionLocalAttributeDelete(SDPSessionT *Session,
                                    const char *AttributeKey);

SSizeT SDPSessionLocalBandwidthGet(const SDPSessionT *Session,
                                   SDPBandwidthT BandwidthType);

SSizeT SDPSessionRemoteBandwidthGet(const SDPSessionT *Session,
                                    SDPBandwidthT BandwidthType);

const char *SDPSessionRemoteAttributeGet(const SDPSessionT *Session,
                                         const char *AttributeKey);

void SDPSessionRemoteReset(SDPSessionT *Session);

const char *SDPSessionRemoteAttributeApply(const SDPSessionT *Session,
                                           const char *AttributeKey,
                                           SDPAttributeCb *AttributeCb,
                                           void *Argument);

const ListT *SDPSessionMediaListGet(const SDPSessionT *Session,
                                    bool IsLocal);

void SDPSessionDebug(const SDPSessionT *Session);

#endif
