#ifndef HIERARCHY_SDP_MESSAGE_H
#define HIERARCHY_SDP_MESSAGE_H

#include "SDPSession.h"

#define SDP_VERSION 0

#define SDP_MESSAGE_ATTRIBUTE_FMTP "fmtp"
#define SDP_MESSAGE_ATTRIBUTE_MAXPTIME "maxptime"
#define SDP_MESSAGE_ATTRIBUTE_PTIME "ptime"
#define SDP_MESSAGE_ATTRIBUTE_RTCP "rtcp"
#define SDP_MESSAGE_ATTRIBUTE_RTPMAP "rtpmap"

#define SDP_MESSAGE_MEDIA_AUDIO "audio"
#define SDP_MESSAGE_MEDIA_VIDEO "video"
#define SDP_MESSAGE_MEDIA_TEXT "text"

#define SDP_MESSAGE_PROTO_RTPAVP "RTP/AVP"
#define SDP_MESSAGE_PROTO_RTPSAVP "RTP/SAVP"

ErrnoT SDPMessageEncode(MemoryBufferT **Buffer,
                        SDPSessionT *Session,
                        bool IsOffer);

ErrnoT SDPMessageDecode(SDPSessionT *Session,
                        MemoryBufferT *Buffer,
                        bool IsOffer);

#endif
