#ifndef HIERARCHY_SDP_DIRECTION_H
#define HIERARCHY_SDP_DIRECTION_H

typedef enum {
    SDP_DIRECTION_INACTIVE = 0,
    SDP_DIRECTION_RECVONLY = 1,
    SDP_DIRECTION_SENDONLY = 2,
    SDP_DIRECTION_SENDRECV = 3,
} SDPDirectionT;

const char *SDPDirectionString(SDPDirectionT Direction);

#endif
