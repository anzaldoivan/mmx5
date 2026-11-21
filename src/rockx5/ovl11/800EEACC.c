#include "types.h"
#include "mmx5/globals.h"

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

void func_800EEACC_ovl11(u8* a0);
extern s8 D_8009A243;
extern s8 D_800D1C1D;

void func_800EEB74_ovl11(u8* a0) {
    *(s32*)(a0 + 0x14) = 0x18000;
    a0[4]++;
    func_800EEACC_ovl11(a0);
    if (D_800D1C1D == 3) {
        D_8009A243 = 6;
    }
}

extern u8 D_8009A1F8[];

void func_800EEBC4_ovl11(u8* arg0) {
    u8* p = D_8009A1F8;

    p[0xAB] = 0;
    p[0xEC] = 0;
    func_8002D720(arg0);
}
