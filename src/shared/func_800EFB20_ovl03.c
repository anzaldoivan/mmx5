/* Shared body (DK-5), from the banked draft of func_800EFB20_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* a0, s32 a1, s32 a2);
extern u8 D_800F959C_ovl03[];
extern u8 D_800F95A4_ovl03[];

void DEDUP_NAME(u8* arg0) {
    s32 t = *(u16*)(arg0 + 0x7C) - 1;

    *(u16*)(arg0 + 0x7C) = t;
    if ((s16)t == 0) {
        *(u8**)(arg0 + 0x54) = D_800F959C_ovl03;
        *(u8**)(arg0 + 0x50) = D_800F95A4_ovl03;
        arg0[6] = 0;
        arg0[5] = arg0[7];
    } else if (t & 1) {
        DEDUP_CALLEE(arg0, 0x20, 0x20);
    } else {
        arg0[3] = 0;
    }
}
