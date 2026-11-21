#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;
extern u8 D_8009A197;

void func_800F2D28_ovl03(u8* a0) {
    a0[0x7D]++;
    if (a0[0x7D] >= 0x15) {
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C218();
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
        D_8009A197 = 0;
        a0[6]++;
    }
}

extern s16 D_800F9D0C_ovl03[][2];

void func_800F2DBC_ovl03(u8* a0) {
    u8 b;
    s32 t;

    b = a0[0x7C];
    if (b & 1) {
        b &= 0xFE;
    } else {
        b |= 1;
    }
    t = D_800F9D0C_ovl03[b][0];
    if (D_8009A0AA < t - 40 || t + 40 < D_8009A0AA) {
        a0[5] = 1;
        a0[6] = 0;
    }
}
