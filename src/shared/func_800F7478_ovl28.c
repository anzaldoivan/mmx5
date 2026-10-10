/* Shared body (DK-5), from the banked draft of func_800F7478_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(u8* a0, u8* a1) {
    s32* p;

    if (*(signed char*)(a1 + 0x9A) > 0) {
        *(s16*)(a0 + 0x54) = 3;
        *(s16*)(a0 + 0x56) = 8;
        *(s16*)(a0 + 0x58) = (5 - *(signed char*)(a0 + 2)) * 2;
        *(s32*)(a0 + 8) = *(s32*)(a1 + 8);
        *(s32*)(a0 + 0xC) = *(s32*)(a1 + 0xC);
        a0[4] = 1;
        a0[5] = 0;
        return;
    }
    if (*(s16*)(a0 + 0x58) != 0) {
        p = *(s32**)(a0 + 0x5C);
        *(s32*)(a0 + 8) = p[6];
        *(s32*)(a0 + 0xC) = p[7];
        *(s16*)(a0 + 0x58) -= 1;
    } else {
        a0[3] = 0;
        a0[4] = 0;
        if (*(signed char*)(a0 + 2) == 2) {
            a1[0x9A] = 0;
        }
    }
}
