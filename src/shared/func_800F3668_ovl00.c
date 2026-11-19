/* Shared body (DK-5), from the banked draft of func_800F3668_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AE;

s32 DEDUP_NAME(u8* obj) {
    s32 v;
    s8 n;

    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    if (D_8009A0AE >= *(s16*)(obj + 0xE)) {
        v = 0xFFFF0000;
        n = 1;
    } else {
        v = 0x10000;
        n = 2;
    }
    *(s32*)(obj + 0x24) = v;
    obj[6] = n;
    return v;
}
