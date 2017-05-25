#ifndef HIERARCHY_SDP_MEDIA_H
#define HIERARCHY_SDP_MEDIA_H

#include <HierarchyBase.h>

#include "SDPBandwidth.h"
#include "SDPSession.h"
#include "SDPAttribute.h"
#include "SDPDirection.h"

#define RTP_PAYLOAD_TYPE_DYNAMIC_START 96
#define RTP_PAYLOAD_TYPE_DYNAMIC_END 127

typedef ErrnoT (SDPMediaEncodeCb)(MemoryBufferT *Data, bool IsOffer, void *Argument);

typedef struct {
    ListNodeT ListNode;
    ListT LocalFormatList;
    ListT RemoteFormatList;
    ListT LocalAttributeList;
    ListT RemoteAttributeList;

    SocketAddressT LocalAddressRTP;
    SocketAddressT RemoteAddressRTP;
    SocketAddressT LocalAddressRTCP;
    SocketAddressT RemoteAddressRTCP;

    SSizeT LocalBandwidthValue[SDP_BANDWIDTH_MAX];
    SSizeT RemoteBandwidthValue[SDP_BANDWIDTH_MAX];

    char *Name;
    char *Proto;
    char *ProtoValue[8];
    char *ProtoUnsupported;
    SDPMediaEncodeCb *EncodeCb;
    void *EncodeArgument;
    SDPDirectionT LocalDirection;
    SDPDirectionT RemoteDirection;
    bool IsFormatIgnore;
    bool IsDisabled;
    SSizeT DynamicPayloadType;
} SDPMediaT;

void SDPMediaDestroy(void *SDPMediaV);
ErrnoT SDPMediaInit(SDPMediaT **Media, ListT *MediaList);

ErrnoT SDPMediaAdd(SDPMediaT **Media,
                   SDPSessionT *Session,
                   const char *MediaName,
                   WordT Port,
                   const char *Proto);

ErrnoT SDPMediaRemoteAdd(SDPMediaT **Media,
                         SDPSessionT *Session,
                         const MemoryBlockT *MediaName,
                         const MemoryBlockT *Proto);

void SDPMediaRemoteReset(SDPMediaT *Media);

bool SDPMediaProtoIsEqual(SDPMediaT *Media,
                         const MemoryBlockT *Proto,
                         bool UpdateMediaProto);

SDPMediaT *SDPMediaSearch(const SDPSessionT *Session,
                          const MemoryBlockT *MediaName,
                          const MemoryBlockT *Proto,
                          bool UpdateProto);

void SDPMediaAlignFormats(SDPMediaT *Media, bool IsOffer);

ErrnoT SDPMediaProtoAltSet(SDPMediaT *Media,
                           SSizeT ProtoCount, ...);

void SDPMediaEncodeCbSet(SDPMediaT *Media,
                         SDPMediaEncodeCb *EncodeCb,
                         void *Argument);

void SDPMediaFormatIgnoreSet(SDPMediaT *Media,
                             bool IsFormatIgnore);

void SDPMediaDisabledSet(SDPMediaT *Media,
                         bool IsDisabled);

void SDPMediaLocalPortSet(SDPMediaT *Media,
                          WordT Port);

void SDPMediaLocalAddressSet(SDPMediaT *Media,
                             const SocketAddressT *LocalAddress);

void SDPMediaLocalBandwidthSet(SDPMediaT *Media,
                               SDPBandwidthT BandwidthType,
                               SSizeT Bandwidth);

void SDPMediaLocalPortRTCPSet(SDPMediaT *Media,
                              WordT Port);

void SDPMediaLocalAddressRTCPSet(SDPMediaT *Media,
                                 const SocketAddressT *LocalAddress);

void SDPMediaLocalDirectionSet(SDPMediaT *Media,
                               SDPDirectionT Direction);

ErrnoT SDPMediaLocalAttributeSet(SDPMediaT *Media,
                                 bool IsReplaceAttribute,
                                 const char *AttributeKey,
                                 const char *AttributeValue, ...);

void SDPMediaLocalAttributeDelete(SDPMediaT *Media,
                                  const char *AttributeKey);

const char *SDPMediaProtoGet(const SDPMediaT *Media);

WordT SDPMediaRemotePortGet(const SDPMediaT *Media);

const SocketAddressT *SDPMediaRemoteAddressGet(const SDPMediaT *Media);

const SocketAddressT *SDPMediaLocalAddressGet(const SDPMediaT *Media);

void SDPMediaRemoteAddressRTCPGet(const SDPMediaT *Media,
                                  SocketAddressT *RemoteAddress);

SSizeT SDPMediaRemoteBandwidthGet(const SDPMediaT *Media,
                                  SDPBandwidthT BandwidthType);

SDPDirectionT SDPMediaLocalDirectionGet(const SDPMediaT *Media);

SDPDirectionT SDPMediaRemoteDirectionGet(const SDPMediaT *Media);

SDPDirectionT SDPMediaDirectionGet(const SDPMediaT *Media);

#include "SDPFormat.h"

const SDPFormatT *SDPMediaLocalFormatGet(const SDPMediaT *Media,
                                         int PayloadType);

const SDPFormatT *SDPMediaRemoteFormatGet(const SDPMediaT *Media,
                                          const char *FormatName);

SDPFormatT *SDPMediaFormatGet(const SDPMediaT *Media,
                              bool IsLocalMedia,
                              const char *Id,
                              SSizeT PayloadType,
                              const char *FormatName,
                              SSizeT SamplingRate,
                              int8_t ChannelCount);

SDPFormatT *SDPMediaFormatApply(const SDPMediaT *Media,
                                   bool IsLocalMedia,
                                   const char *Id,
                                   SSizeT PayloadType,
                                   const char *FormatName,
                                   SSizeT SamplingRate,
                                   int8_t ChannelCount,
                                   SDPFormatCb *FormatCb,
                                   void *Argument);

const ListT *SDPMediaFormatList(const SDPMediaT *Media,
                                bool IsLocal);

const char *SDPMediaRemoteAttributeGet(const SDPMediaT *Media,
                                       const char *AttributeName);

const char *SDPMediaSessionRemoteAttributeGet(const SDPMediaT *Media,
                                              const SDPSessionT *Session,
                                              const char *AttributeName);

const char *SDPMediaRemoteAttributeApply(const SDPMediaT *Media,
                                         const char *AttributeName,
                                         SDPAttributeCb *AttributeCb,
                                         void *Argument);

const char *SDPMediaName(const SDPMediaT *Media);

void SDPMediaDebug(const SDPMediaT *Media);

#endif
