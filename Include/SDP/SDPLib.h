#ifndef HIERARCHY_SDP_LIB_H
#define HIERARCHY_SDP_LIB_H

#include "SDPAttribute.h"
#include "SDPBandwidth.h"
#include "SDPDirection.h"
#include "SDPExtMap.h"
#include "SDPFormat.h"
#include "SDPMedia.h"
#include "SDPMessage.h"
#include "SDPSession.h"

extern const struct SDPLibrary {
    struct {
        void (*Destroy)(void *SDPSessionV);

        ErrnoT (*Init)(SDPSessionT **Session,
                       const SocketAddressT *LocalAddress);

        void (*Debug)(const SDPSessionT *Session);
    } Session;

    struct {
        ErrnoT (*Parse)(SDPSessionT *Session,
                        MemoryBufferT *Buffer,
                        bool IsOffer);

        ErrnoT (*Serialize)(MemoryBufferT **Buffer,
                            SDPSessionT *Session,
                            bool IsOffer);
    } Message;
} SDPLib;


#endif
