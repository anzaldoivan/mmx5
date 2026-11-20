/* Shared body (DK-5), from the banked draft of func_800F79C0_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl01.h"

void DEDUP_CALLEE(s32, s16, s16, u8*);
extern u8 D_800FD30C_ovl01[];

void DEDUP_NAME(u8* a0) {
    u8* p;

    if (--((s8*)a0)[0x18] == 0) {
        p = *(u8**)(a0 + 0x1C) + ((s8*)a0)[0x1A] * 4;
        *(u8**)(a0 + 0x1C) = p;
        a0[0x18] = p[0];
        a0[0x19] = p[1];
        a0[0x1A] = p[2];
        a0[0x1B] = p[3];
        DEDUP_CALLEE(((s8*)a0)[0x14],
                     *(s16*)(a0 + 0xA) - D_800FD408_ovl01[((s8*)a0)[2]][1],
                     *(s16*)(a0 + 0xE) - D_800FD408_ovl01[((s8*)a0)[2]][2],
                     D_800FD30C_ovl01 + a0[0x1B] * 8);
    }
}
