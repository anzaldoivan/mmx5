/* Shared body (DK-5), from the banked draft of func_800F03F4_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

#define G (*(u8**)0x1F80004C)

void DEDUP_NAME(u8* obj) {
    *(s32*)(G + 0x8C) = 0x10000;
    obj[6]++;
}
