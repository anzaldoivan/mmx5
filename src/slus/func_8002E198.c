/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002D4F4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern u16 D_8009A120;

s32 func_8002E198(void) {
    s32 var_v0;

    var_v0 = (D_8009A120 & 0xF) != 0;
    if (D_8009A120 & 0x1B0) {
        var_v0 += 1;
    }
    return var_v0;
}
