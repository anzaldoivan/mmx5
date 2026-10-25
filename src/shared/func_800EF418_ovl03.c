/* Shared body (DK-5), from the banked draft of func_800EF418_ovl03 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC2D8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D760(void*, void*); /* extern */
M2C_UNK func_8002D7A0(void*, void*); /* extern */
extern u16 D_800D1C0C;

void DEDUP_NAME(void* arg0) {
    if ((D_800D1C0C == 2) || (M2C_FIELD(arg0, s8*, 4) == 3)) {
        func_8002D7A0(arg0, arg0);
        return;
    }
    func_8002D760(arg0, arg0);
}
