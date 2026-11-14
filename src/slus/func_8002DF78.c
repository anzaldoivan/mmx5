/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/system/random_byte.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
extern u16 D_80093F70;

// 0x8002D2D4 func_8002DF78: steps the random seed and returns its low byte.
// basis: code src/shared/SLUS_013.95/func_8002DF78.c:13 via=D_80093F70
// callers: drop_item, fire_charged_shot, func_8001D60C
s32 func_8002DF78(void) {
    u16 v;
    u32 t;
    u32 hi;

    v = D_80093F70;
    t = (u16)(v + v * 2) >> 8;
    v += t;
    hi = t << 8;
    v &= 0xFF;
    v |= hi;
    D_80093F70 = v;
    return v & 0xFF;
}
