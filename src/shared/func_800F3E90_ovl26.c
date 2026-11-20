/* Shared body (DK-5), from the banked draft of func_800F3E90_ovl26 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_04/func_800F4910.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void DEDUP_NAME(void* arg0) {
    ((s32(*)())func_8003D29C)(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
