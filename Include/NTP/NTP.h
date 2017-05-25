#ifndef HIERARCHY_NTP_H
#define HIERARCHY_NTP_H

#include <stdint.h>
#include <HierarchyBase.h>

#define NTP_OFFSET 0x83aa7e80

typedef struct timeval TimeValT;

typedef struct {
    DWordT High;
    DWordT Low;
} NTPTimeT;

typedef DWordT NTPCompactTimeT;

void NTPFromTimeval(NTPTimeT *NTPTime, const TimeValT *TimeVal);
void NTPToTimeval(TimeValT *TimeVal, const NTPTimeT *NTPTime);
ErrnoT NTPTimeGet(NTPTimeT *NTPTime);
NTPCompactTimeT NTPToCompact(NTPTimeT *NTPTime);
SizeT NTPCompactToUS(NTPCompactTimeT NTPCompact);

#endif
