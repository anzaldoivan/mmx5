/* Shared body (DK-5), from the banked draft of func_800EFE4C_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(s32 a0, void* a1, u8* a2);
extern u8 D_800F52B4_ovl05[];

void DEDUP_NAME(u8* arg0) {
    DEDUP_CALLEE(6, D_800F52B4_ovl05, arg0);
    arg0[3] = 0;
    *(s16*)(arg0 + 0x7C) = 0xF;
    *(s16*)(arg0 + 0x7E) = 5;
    arg0[4] = 5;
}
