/* Shared body (DK-5), from the banked draft of func_800EF9D4_ovl03 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC894.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void DEDUP_NAME(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    M2C_FIELD(arg0, s16*, 0x7C) = (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
}
