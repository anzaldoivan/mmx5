/* Shared body (DK-5), from the banked draft of func_800F1074_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* DEDUP_CALLEE();
extern u8 D_800F9854_ovl11[];

void DEDUP_NAME(u8* arg0) {
    u8* p;
    u8 i;

    for (i = 0; i < 2; i++) {
        p = DEDUP_CALLEE();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x1D;
            p[2] = i;
            *(u8**)(p + 0x7C) = arg0;
            *(s16*)(p + 0x42) = *(s16*)(arg0 + 0x42);
            *(u8**)(p + 0x30) = D_800F9854_ovl11;
            *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(s16*)(p + 0x40) = *(s16*)(arg0 + 0x40);
            p[0x15] = arg0[0x15];
            p[0x14] = arg0[0x14];
            p[0x16] = 4;
        }
    }
}
