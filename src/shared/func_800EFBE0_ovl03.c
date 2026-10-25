/* Shared body (DK-5), from the banked draft of func_800EFBE0_ovl03 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC978.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
M2C_UNK func_800171E8(void*, M2C_UNK);
M2C_UNK func_80017248();
extern u8 D_800F959C_ovl03[];

void DEDUP_NAME(void* arg0) {
    *(u8**)((u8*)arg0 + 0x50) = D_800F959C_ovl03;
    func_800171E8(arg0, 3);
    ((void (*)())func_80017248)(arg0);
    *(s32*)((u8*)arg0 + 0x88) = 1;
    *(s16*)((u8*)arg0 + 0x7C) = 0x12C;
    *((u8*)arg0 + 6) += 1;
}
