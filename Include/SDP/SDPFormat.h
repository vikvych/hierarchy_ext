#ifndef HIERARCHY_SDP_FORMAT_H
#define HIERARCHY_SDP_FORMAT_H

struct SDPFormatStruct;

typedef int (SDPFormatFMTPEncodeCb)(MemoryBufferT *Buffer,
                                    const struct SDPFormatStruct *Format,
                                    bool IsOfferFlag,
                                    void *Data);

typedef bool(SDPFormatFMTPCompareCb)(const char *Params1,
                                     const char *Params2,
                                     void *Data);

typedef struct SDPFormatStruct {
    ListNodeT ListNode;
    char *Id;
    char *Params;
    char *RemoteParams;
    char *Name;
    SDPFormatFMTPEncodeCb *FMTPEncodeCb;
    SDPFormatFMTPCompareCb *FMTPCompareCb;
    void *Data;
    bool Refd;
    bool IsSupported;
    SSizeT PayloadType;
    DWordT SamplingRate;
    ByteT ChannelCount;
} SDPFormatT;


typedef bool (SDPFormatCb)(SDPFormatT *Format, void *Argument);

#include "SDPMedia.h"

ErrnoT SDPFormatAdd(SDPFormatT **Format,
                    SDPMediaT *Media,
                    bool ISPrepend,
                    const char *Id,
                    const char *FormatName,
                    DWordT SamplingRate,
                    ByteT ChannelCount,
                    SDPFormatFMTPEncodeCb *FMTPEncodeCb,
                    SDPFormatFMTPCompareCb *FMTPCompareCb,
                    void *Data,
                    bool IsRefd,
                    const char *Params, ...);

ErrnoT SDPFormatRemoteAdd(SDPMediaT *Media,
                          const MemoryBlockT *Id);

SDPFormatT *SDPFormatSearch(const ListT *lst,
                            const MemoryBlockT *Id);

ErrnoT SDPFormatSetParams(SDPFormatT *Format,
                           const char *FormatParams, ...);

bool SDPFormatIsEqual(const SDPFormatT *Format1,
                      const SDPFormatT *Format2);

ErrnoT SDPFormatDebug(PrintT *Print,
                      const SDPFormatT *Format);

#endif
