#ifndef HIERARCHY_NTP_LIB_H
#define HIERARCHY_NTP_LIB_H

#include "NTP.h"

extern const struct NTPLibrary {
    void (*FromTimeval)(NTPTimeT *NTPTime, const TimeValT *TimeVal);
    void (*ToTimeval)(TimeValT *TimeVal, const NTPTimeT *NTPTime);
    ErrnoT (*TimeGet)(NTPTimeT *NTPTime);
    NTPCompactTimeT (*ToCompact)(NTPTimeT *NTPTime);
    SizeT (*CompactToUS)(NTPCompactTimeT NTPCompact);
} NTPLib;

#endif
