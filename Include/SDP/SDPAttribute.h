#ifndef HIERARCHY_SDP_ATTRIBUTE_H
#define HIERARCHY_SDP_ATTRIBUTE_H

#include <HierarchyBase.h>

typedef bool (SDPAttributeCb)(const char *Key,
                              const char *Value,
                              void *Argument);

typedef struct {
    ListNodeT ListNode;
    char *Key;
    char *Value;
} SDPAttributeT;

ErrnoT SDPAttributeAdd(ListT *AttributeList,
                       MemoryBlockT *Key,
                       MemoryBlockT *Value);

ErrnoT SDPAttributeVAdd(ListT *AttributeList,
                        const char *Key,
                        const char *Value,
                        va_list ArgsPtr);

void SDPAttributeDelete(const ListT *AttributeList,
                        const char *Key);

const char *SDPAttributeApply(const ListT *AttributeList,
                              const char *Key,
                              SDPAttributeCb *AttributeCb,
                              void *Argument);

ErrnoT SDPAttributePrint(PrintT *Print,
                         const SDPAttributeT *Attribute);

ErrnoT SDPAttributeDebug(PrintT *Print,
                         const SDPAttributeT *Attribute);

#endif
