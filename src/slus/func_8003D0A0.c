/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/graphics/animation_8003D10C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern void func_8003B33C(u8*, s32);
extern u8 D_800D1C00[];

void func_8003D0A0(u8* p) {
    s32 t;
    s32 i = *(s8*)(p + 2);
    u8* e = D_800D1C00;
    t = (s8)(e - -i)[0x47] / 3;
    if (*(s8*)(p + 0x5C) >= (s8)t) {
        func_8003B33C(p, 5);
    } else {
        func_8003B33C(p, 6);
    }
}
