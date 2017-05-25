#ifndef HIERARCHY_RTP_H
#define HIERARCHY_RTP_H

#include <HierarchyBase.h>
#include "../NTP/NTPLib.h"

#define RTP_VERSION_PROTO 2
#define RTP_HEADER_SIZE 12

#define RTP_SEQ_MOD (1<<16)
#define RTP_SOURCE_DROPOUT_MAX 3000
#define RTP_SOURCE_MISORDER_MAX 100
#define RTP_SOURCE_SEQUENTIAL_MIN 2

typedef struct {
    ByteT VersionProto;
    BitT PaddingFlag;
    BitT ExtensionFlag;
    ByteT CSRCCount;
    BitT MarkerFlag;
    ByteT PayloadType;
    WordT Sequence;
    DWordT Timestamp;
    DWordT SSRC;
    DWordT CSRC[16];

    struct {
        WordT TypeByProfile;
        WordT DWordCount;
    } Extension;
} RTPHeaderT;

typedef void (RTPRecvCb)(const SocketAddressT *SourceAddress,
                         const RTPHeaderT *RTPHeader,
                         MemoryBufferT *Data,
                         void *Argument);

#include "../RTCP/RTCP.h"

typedef struct RTCPSessionStruct RTCPSessionT;

typedef struct {
    struct {
        WordT Seq;
        DWordT SSRC;
    } LocalSyncData;

    int Proto;
    void *RTPSocket;
    void *RTCPSocket;
    SocketAddressT RTPLocalAddress;
    SocketAddressT RTCPRemoteAddress;
    RTPRecvCb *RTPRecv;
    RTCPRecvCb *RTCPRecv;
    void *RecvArg;
    RTCPSessionT *RTCPSession;
    bool RTPRTCPMuxFlag;
} RTPSocketT;


struct RTCPSessionStruct {
    RTPSocketT *Socket;
    BinaryTreeT *MembersTree;
    TimerT SendingReportTimer;
    char *CName;
    DWordT MemberCount;
    DWordT SenderCount;
    DWordT SamplingRateTX;
    DWordT SamplingRateRX;

    LockT *LockTXStat;
    RTCPTXStatsT TXStat;
};

#endif
