/* Shared body (DK-5), from the banked draft of func_800FEBCC_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* DEDUP_CALLEE();

void DEDUP_NAME(u8* self, s16 x, s16 y, u8 sub) {
    u8* p;

    p = DEDUP_CALLEE();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xC;
        *(u8**)(p + 0x7C) = self;
        p[2] = sub;
        *(s16*)(p + 0xA) = x;
        *(s16*)(p + 0xE) = y;
        *(u16*)(p + 0x42) = *(u16*)(self + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(self + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(self + 0x3C);
        *(u16*)(p + 0x40) = *(u16*)(self + 0x40);
        p[0x14] = self[0x14];
    }
}
