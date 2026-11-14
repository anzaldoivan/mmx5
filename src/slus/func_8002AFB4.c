/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/80029D18.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
extern X4_BackgroundObj background_objects[3];
extern u8 D_800D1CA0;

extern X4_BackgroundObj background_objects[3];
void func_80029F38(s16, s16, s16, s16, u8);

#include "types.h"
extern X4_BackgroundObj background_objects[3];
extern u8 D_800D1CA0;

s32 func_8002AFB4(D80101480_t* rec, s16 arg1, s16 arg2, s16 arg3) {
    u32 n;
    u8 g;
    u8 t;
    s32 hi;

    n = rec->b[3] & 0xF;
    if (n >= 3 || (g = D_800D1CA0) == 3) {
        return 0;
    }
    if (g < n) {
        return 1;
    }
    t = rec->b[3];
    hi = t & 0xF0;
    switch (hi) {
    case 0:
        rec->b[3] = t + 0x10;
        return 0;
    case 0x20:
        rec->b[3] = t + 0x10;
        return 1;
    case 0x40:
        if (g == 0) {
            return 1;
        }
        rec->b[3] = (t & 0xF) + 0x10;
        return 0;
    case 0x60:
        if (g == 0) {
            return 1;
        }
        rec->b[3] = (t & 0xF) + 0x30;
        return 1;
    }
    return 1;
}
