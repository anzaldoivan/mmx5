/* Shared body (DK-5), from the banked draft of func_800EF5A0_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* DEDUP_CALLEE();

void DEDUP_NAME(u8* o) {
    s32 i;
    u8* c;
    s8* f;

    for (i = 0; i < 3; i++) {
        f = (s8*)o + 0x90;
        if (f[i] != 0) {
            continue;
        }
        f[i] = 1;
        c = DEDUP_CALLEE();
        if (c == 0) {
            continue;
        }
        c[0] = 0x41;
        c[1] = o[1];
        c[2] = i + 1;
        *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
        *(u16*)(c + 0x42) = *(u16*)(o + 0x42);
        *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
        *(u8**)(c + 0x80) = o + 0x80;
        if (((s8*)o)[0x94] != 0) {
            c[7] = 1;
        }
    }
    o[0x94] = 0;
    o[0x95] = 1;
}
