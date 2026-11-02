/* Shared body (DK-5), from the banked draft of func_800FBDC8_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);
extern u8 D_800FF724_ovl06[];

void DEDUP_NAME(u8* obj) {
    u8 sub;
    s32 kind;

    sub = obj[2];
    kind = ((s8*)obj)[2] & 0xF0;
    if (kind == 0) {
        obj[0x16] = D_800FF724_ovl06[sub & 0xF];
        DEDUP_CALLEE(obj, 0x12);
        obj[4] = 1;
        obj[3] = 0;
        obj[5] = 0;
        obj[6] = 0;
        *(u16*)(obj + 0x42) &= 0x7FFF;
        *(s16*)(obj + 0x54) = (obj[2] & 0xF) * 7;
    } else if (kind == 0x10) {
        obj[0x16] = 6;
        obj[0x47] = 0;
        obj[3] = 0;
        obj[4] = 1;
        obj[5] = 1;
        obj[6] = 0;
        *(u16*)(obj + 0x1A) = *(u16*)(obj + 0xA);
        *(u16*)(obj + 0x1E) = *(u16*)(obj + 0xE);
        *(u16*)(obj + 0x42) &= 0x7FFF;
    } else if (kind == 0x20) {
        obj[2] = sub & 0xF;
        obj[4] = 3;
        obj[5] = 0;
        obj[6] = 0;
    }
}
