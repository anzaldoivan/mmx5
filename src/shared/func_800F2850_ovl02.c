/* Shared body (DK-5), from the banked draft of func_800F2850_ovl02 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_03/func_800ED984.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 1);
    ((u8*)arg0)[6]++;
}
