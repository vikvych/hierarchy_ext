#ifndef HIERARCHY_RTCP_H
#define HIERARCHY_RTCP_H

#include <HierarchyBase.h>
#include "../NTP/NTPLib.h"

#define RTCP_VERSION 2

#define RTCP_HEADER_SIZE 4

#define RTCP_SRC_SIZE 4
#define RTCP_SR_SIZE 20
#define RTCP_RR_SIZE 24

#define RTCP_APP_PACKET_SIZE 8
#define RTCP_FIR_PACKET_SIZE 4
#define RTCP_NACK_PACKET_SIZE 8
#define RTCP_FB_PACKET_SIZE 8

#define RTCP_SDES_MIN_SIZE 1
#define RTCP_SDES_MAX_SIZE 255
#define RTCP_PACKETS_HEADROOM 4

#define RTCP_SERDING_REPORT_INTERVAL_MS 5000

#define RTCP_MAX_MEMBERS 8

#define RTCP_GNACK_SIZE 4
#define RTCP_SLI_SIZE 4

typedef enum {
    RTCP_PACKET_TYPE_FIR = 192,
    RTCP_PACKET_TYPE_NACK = 193,
    RTCP_PACKET_TYPE_SR = 200,
    RTCP_PACKET_TYPE_RR = 201,
    RTCP_PACKET_TYPE_SDES = 202,
    RTCP_PACKET_TYPE_BYE = 203,
    RTCP_PACKET_TYPE_APP = 204,
    RTCP_PACKET_TYPE_RTPFB = 205,
    RTCP_PACKET_TYPE_PSFB = 206,
    RTCP_PACKET_TYPE_XR = 207,
    RTCP_PACKET_TYPE_AVB = 208
} RTCPPacketTypeT;

typedef enum {
    RTCP_SDES_TYPE_END = 0,
    RTCP_SDES_TYPE_CNAME = 1,
    RTCP_SDES_TYPE_NAME = 2,
    RTCP_SDES_TYPE_EMAIL = 3,
    RTCP_SDES_TYPE_PHONE = 4,
    RTCP_SDES_TYPE_LOC = 5,
    RTCP_SDES_TYPE_TOOL = 6,
    RTCP_SDES_TYPE_NOTE = 7,
    RTCP_SDES_TYPE_PRIV = 8
} RTCPSourceDescriptionTypeT;

typedef enum {
    RTCP_FEEDBACK_TYPE_GNACK = 1
} RTCPFBTypeT;

typedef enum {
    RTCP_FEEDBACK_TYPE_PLI = 1,
    RTCP_FEEDBACK_TYPE_SLI = 2,
    RTCP_FEEDBACK_TYPE_APP = 15
} RTCPPSFBTypeT;

typedef struct {
    struct {
        DWordT RTPPacketCount;
        SDWordT LostPacketCount;
        DWordT InterArrivalJitterUS;
    } Tx;

    struct {
        DWordT RxPTPPacketCount;
        SDWordT LostPacketCount;
        DWordT InterArrivalJitterUS;
    } Rx;

    DWordT RoundTripTime;
} RTCPStatsT;

typedef struct {
    DWordT ProtoVersion:2;
    DWordT PaddingFlag:1;
    DWordT ItemCount:5;
    DWordT PacketType:8;
    WordT PacketSize;
} RTCPHeaderT;

typedef struct {
    SocketAddressT IPAddress;
    WordT SeqMax;
    DWordT SeqCycles;
    DWordT SeqBase;
    DWordT SeqBad;
    DWordT Probation;
    DWordT PacketReceivedCount;
    DWordT SeqExpected;
    DWordT SeqReceived;
    DWordT RelativeTransitTimestamp;
    DWordT EstimatedJitter;
    SizeT ByteReceivedCount;
    QWordT SRReceivedLastTime;
    NTPTimeT SRNTPLast;
    DWordT Timestamp;
    DWordT PacketSentCount;
    DWordT OctetSentCount;
} RTPSourceT;

typedef struct {
    BinaryTreeT *MembersTree;
    RTPSourceT *Source;
    DWordT SSRC;
    SDWordT PacketLostCount;
    DWordT JitterUS;
    DWordT RoundTripTimeUS;
} RTCPMemberT;

typedef struct {
    WordT First;
    WordT Number;
    ByteT PictureId;
} RTCPSliceLossIndicationT;

typedef ErrnoT (RTCPMessageEncodeCb)(MemoryBufferT *Buffer,
                                     void *Argument);

typedef struct {
    DWordT SSRC;
    DWordT LostPacketFraction:8;
    SDWordT LostPacketCount:24;
    DWordT SeqLast;
    DWordT InterArrivalJitter;
    DWordT SRPacketLast;
    DWordT SRPacketLastDelay;
} RTCPReceptionReportT;

typedef struct {
    RTCPSourceDescriptionTypeT Type;
    ByteT OctetSize;
    char *Data;
} RTCPSDESItemT;




typedef struct rtcp_sdes {
    DWordT SSRC;
    RTCPSDESItemT *ItemsValues;
    DWordT ItemCount;
} RTCPSDESMessageT;

typedef struct {
    DWordT SSRC;
    DWordT NTPSeconds;
    DWordT NTPFraction;
    DWordT RTPTimestamp;
    DWordT RTPPacketSentCount;
    DWordT RTPOctetSentCount;
    RTCPReceptionReportT *RRBlockValues;
} RTCPSenderReportMessageT;


typedef struct {
    DWordT SSRC;
    RTCPReceptionReportT *RRBlockValues;
} RTCPReceptionReportMessageT;

typedef struct {
    DWordT *SSRCValues;
    char *Reason;
} RTCPByeMessageT;

typedef struct {
    DWordT SSRC;
    char Name[4];
    ByteT *Data;
    SizeT DataSize;
} RTCPAPPMessageT;


typedef struct {
    DWordT SSRC;
} RTCPFIRMessageT;

typedef struct {
    DWordT SSRC;
    WordT SeqFirstLost;
    WordT LostPacketsBitmask;
} RTCPNACKMessageT;

typedef struct {
    WordT PictureId;
    WordT LostPacketsBitmask;
} RTCPGNACKT;

typedef struct {
    DWordT SSRCPacket;
    DWordT SSRCMedia;
    DWordT ItemCount;

    union {
        RTCPGNACKT *GNACKValues;
        RTCPSliceLossIndicationT *SLIValues;
        MemoryBufferT *APPFB;
        void *PSFB;
    } FBCI;
} RTCPFBMessageT;

typedef struct {
    RTCPHeaderT Header;
    union {
        RTCPSenderReportMessageT SenderReport;
        RTCPReceptionReportMessageT ReceptionReport;
        RTCPSDESMessageT *SourceDescription;
        RTCPByeMessageT Bye;
        RTCPAPPMessageT APP;
        RTCPFIRMessageT FIR;
        RTCPNACKMessageT NACK;
        RTCPFBMessageT FB;
    } Data;
} RTCPMessageT;

typedef void (RTCPRecvCb)(const SocketAddressT *SourceAddress,
                          RTCPMessageT *Message,
                          void *Argument);

typedef struct {
    DWordT PacketSent;
    DWordT OctetsSent;
    QWordT RTPRefTimestamp;
    DWordT TimestampRef;
    BitT TimestampSyncFlag;
} RTCPTXStatsT;

const char *RTCPPacketTypeString(RTCPPacketTypeT Type);
const char *RTCPSourceDescriptionTypeString(RTCPSourceDescriptionTypeT Type);

#endif
