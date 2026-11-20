#include "types.h"

extern u8 D_800D1C00[];

void func_800FEF40_ovl04(u8* obj) {
    s32 limit = 300;

    D_800D1C00[0x28] &= ~obj[0x93];
    if (D_800D1C00[0x26] & 2) {
        limit = 50;
    }
    if (++*(s32*)(obj + 0x84) >= limit) {
        *(s32*)(obj + 0x84) = 0;
        obj[5]++;
    }
}
