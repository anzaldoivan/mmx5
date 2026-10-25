#include "types.h"

extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800EEACC_ovl11(u8* a0) {
    u8* p = D_8009A1F8;
    s8* g;

    *(s32*)(p + 0xB0) -= *(s32*)(a0 + 0x14);
    *(s32*)(p + 0xB4) += *(s32*)(a0 + 0x14);
    if (*(s16*)(p + 0xB2) < 0x2C0) {
        *(s16*)(p + 0xB2) += 0x400;
        p[0xF4] = 1;
    }
    if (*(s16*)(p + 0xB6) > 0x400) {
        *(s16*)(p + 0xB6) -= 0x400;
        p[0xF4] = 1;
    }
    g = (s8*)D_800D1C00;
    if (g[0x1D] >= 2) {
        p[0x58] = 2;
    }
    if (g[0x1D] == 3) {
        p[0x4B] = 6;
    }
}
