/* Shared body (DK-5), from the banked draft of func_800FDDB4_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(u8* obj) {
    *(s32*)(obj + 0x20) = -0x18000;
    *(s32*)(obj + 0x24) = 0;
    obj[6]++;
}
