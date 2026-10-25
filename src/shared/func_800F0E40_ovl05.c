/* Shared body (DK-5), from the banked draft of func_800F0E40_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800F5374_ovl05[];
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8004FD24(u8* a0);

void DEDUP_NAME(u8* a0) {
    if (((s8*)a0)[2] != 0) {
        a0[3] = 0;
        func_8004D4F4(3, D_800F5374_ovl05, a0);
        func_8004FD24(a0);
    }
    a0[4] = 2;
}
