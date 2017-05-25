#ifndef HIERARCHY_SDP_BANDWIDTH_H
#define HIERARCHY_SDP_BANDWIDTH_H

typedef enum {
    SDP_BANDWIDTH_MIN = 0,
    SDP_BANDWIDTH_CT = 0,  //Conference Total
    SDP_BANDWIDTH_AS = 1,  //Application Specific
    SDP_BANDWIDTH_RS = 2,  //RTCP Senders
    SDP_BANDWIDTH_RR = 3,  //RTCP Receivers
    SDP_BANDWIDTH_TIAS = 4,//Transport Independent Application Specific Maximum
    SDP_BANDWIDTH_MAX = 5
} SDPBandwidthT;

const char *SDPBandwidthString(SDPBandwidthT Bandwidth);

#endif
