/* Shared body (DK-5), from the banked draft of func_800F1080_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8* DEDUP_CALLEE(void);

void DEDUP_NAME(u8* arg0) {
    u8* p;

    if (!(D_1F80004C.bytes[0x81]++ & 3)) {
        p = DEDUP_CALLEE();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 7;
            p[2] = arg0[2];
            *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
            *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
            p[0x14] = arg0[0x14];
            *(s32*)(p + 0x8) = *(s32*)(arg0 + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(arg0 + 0xC);
            p[0x15] = arg0[0x15];
            *(u8**)(p + 0x50) = arg0;
            p[4] = 0;
        }
    }
}
