#ifndef HIERARCHY_SDP_EXTMAP_H
#define HIERARCHY_SDP_EXTMAP_H

#include <HierarchyBase.h>

#include "SDPDirection.h"

typedef struct {
    MemoryBlockT Name;
    MemoryBlockT Attributes;
    SDPDirectionT Direction;
    bool DirectionIsSet;
    DWordT Id;
} SDPExtMapT;

ErrnoT SDPExtMapDecode(SDPExtMapT *ExtMap, const char *Value);

#endif
