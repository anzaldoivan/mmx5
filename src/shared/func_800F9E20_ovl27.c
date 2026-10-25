/* Shared body (DK-5), from the banked draft of func_800F9E20_ovl27 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80042214.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK DEDUP_CALLEE();

void DEDUP_NAME(void* arg0) {
    if (--*(s16*)((u8*)arg0 + 0x7C) == 0) {
        DEDUP_CALLEE();
    }
}
