/* Shared body (DK-5), from the banked draft of func_800F43AC_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800FBE00_ovl10[];

void DEDUP_NAME(u8* o) {
    if (*(s8*)(*(u8**)(o + 0x80) + 6) == 6) {
        return;
    }
    if (*(s8*)(o + 0x87) != 0) {
        o[0x87]--;
        return;
    }
    if (o[0x8A] == 2) {
        if (*(s8*)(o + 2) != 0) {
            o[5] = 6;
            o[6] = 0;
            return;
        }
        o[5] = D_800FBE00_ovl10[++o[0x88] + (o[0x8A] * 2 + o[0x89]) * 5];
        o[6] = 0;
        return;
    }
    if (o[0x8E] != 0) {
        o[0x8E] = 0;
        o[0x88] = 0;
        o[5] = D_800FBE00_ovl10[(o[0x8A] * 2 + o[0x89]) * 5];
    } else {
        o[5] = D_800FBE00_ovl10[++o[0x88] + (o[0x8A] * 2 + o[0x89]) * 5];
    }
    o[6] = 0;
}
