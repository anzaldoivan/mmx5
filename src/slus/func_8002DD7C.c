/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002D0D8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern u32 D_800731AC[];

s32 func_8002DD7C(s32 x, s32 y) {
    s32 sx;
    s32 sy;
    s32 q;
    // !FAKE: pins v to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 v asm("$2");
    // !FAKE: pins t to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 t asm("$3");
    s16 a;
    u32* p;

    v = y;
    if (x < 0) {
        sx = 1;
        x = -x;
    } else {
        sx = -1;
    }
    sy = 1;
    if (y < 0) {
        sy = -1;
        v = -y;
    }
    t = v >> 16;
    if (t != 0) {
        q = x / t;
        if (q <= 0xFFFF) {
            p = &D_800731AC[4];
            while (q < *p) {
                p--;
            }
            a = p - D_800731AC;
        } else {
            p = &D_800731AC[5];
            while (*p < q) {
                p++;
            }
            a = (p - D_800731AC) - 1;
        }
    } else {
        a = 8;
    }
    if (sy < 0) {
        if (sx > 0) {
            if (a == 8) {
                return 0;
            }
            return (u8)(a + 0x18);
        }
        return (u8)(0x18 - a);
    } else if (sx > 0) {
        return (u8)(8 - a);
    } else {
        return (u8)(a + 8);
    }
}
