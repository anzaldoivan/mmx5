/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/8002D30C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
extern u16 D_80093F70;

s32 func_8002DFB0(void) {
    s32 r;
    s32 ret;
    u32 t;
    u16 v;
    t = (u32)((D_80093F70 + D_80093F70 * 2) & 0xFFFF) >> 8;
    v = D_80093F70 + t;
    t <<= 8;
    v = (v & 0xFF) | t;
    D_80093F70 = v;
    r = v & 0xFF;
    ret = 1;
    if (r != 0) {
        ret = r;
    }
    return ret;
}
