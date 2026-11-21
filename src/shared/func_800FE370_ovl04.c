#include "types.h"

extern u8 D_800D1C00[];

void func_800FE370_ovl04(u8* arg0) {
    s32 limit;

    limit = 300;
    D_800D1C00[0x28] &= ~arg0[0x93];
    D_800D1C00[0x29] &= ~arg0[0x93];
    if (D_800D1C00[0x26] & 2) {
        limit = 50;
    }
    if (++*(s32*)(arg0 + 0x84) >= limit) {
        *(s32*)(arg0 + 0x84) = 0;
        arg0[5]++;
    }
}

extern u8 D_800D1C00[];

void func_800FE3EC_ovl04(u8* arg0) {
    D_800D1C00[0x28] &= ~arg0[0x93];
    D_800D1C00[0x29] &= ~arg0[0x93];
    arg0[3] = 0;
}
