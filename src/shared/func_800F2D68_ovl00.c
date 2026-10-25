/* Shared body (DK-5), from the banked draft of func_800F2D68_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8* DEDUP_CALLEE();

void DEDUP_NAME(u8* arg0, u8 arg1) {
    u8* p;

    p = DEDUP_CALLEE();
    if (p != 0) {
        D_1F80004C.bytes[0x88] = 0;
        p[0] = 0x41;
        p[1] = arg0[1];
        p[2] = arg1;
        *(u16*)(p + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(arg0 + 0xE);
        *(s32*)(p + 0x10) = 0;
        p[0x15] = arg0[0x15];
        *(u8**)(p + 0x80) = arg0;
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
    }
}
