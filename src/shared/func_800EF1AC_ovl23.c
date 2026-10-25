/* Shared body (DK-5), from the banked draft of func_800EF1AC_ovl23 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_19/func_800EA078.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800D1C44;

void DEDUP_NAME(void* arg0) {
    if (D_800D1C44 == 0) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        return;
    }
    M2C_FIELD(arg0, s8*, 3) = 0;
}
