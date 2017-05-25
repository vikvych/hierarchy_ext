#ifndef HIERARCHY_SRTP_SRTP_H
#define HIERARCHY_SRTP_SRTP_H

#include <HierarchyBase.h>
#include "../RTP/RTP.h"

#define SRTP_MAX_STREAM_COUNT 8
#define SRTP_SALT_SIZE 14
#define SRTP_UNSECURE_SRTCP (1<<1)
#define SRTP_MAX_KEY_SIZE 32
#define SRTP_SPACE_SIZE 64

typedef union {
    QWordT QWords[2];
    DWordT DWords[4];
    WordT Words[8];
    ByteT Bytes[16];
} Vector128T;

typedef struct {
    AESCTRT *AESContext;
    HMAC_SHA1ContextT *HMACContext;
    Vector128T DerivedSaltingKey;
    SizeT AuthTagSize;
} SRTPProtoSessionT;

typedef struct {
    SRTPProtoSessionT RTP;
    SRTPProtoSessionT RTCP;

    ListT StreamList;
} SRTPSessionT;

const char *SRTPSuiteDebug(SRTPSuiteT Suite);

void SRTPIVCalculate(Vector128T *IV,
                     const Vector128T *DerivedSaltingKey,
                     DWordT SSRC,
                     QWordT Index);

ErrnoT SRTPKeyDerive(ByteT *Output,
                     SizeT OutputSize,
                     ByteT Label,
                     ByteT *MasterKey,
                     SizeT MasterKeySize,
                     ByteT *MasterSalt,
                     SizeT MasterSaltSize);

SRTPSessionT *SRTPSessionInit(SRTPSuiteT Suite,
                              const ByteT *Key,
                              SizeT KeySize,
                              int Flags);

ErrnoT SRTPEncrypt(SRTPSessionT *Session,
                   MemoryBufferT *Buffer);

ErrnoT SRTPDecrypt(SRTPSessionT *Session, MemoryBufferT *Buffer);

#endif
