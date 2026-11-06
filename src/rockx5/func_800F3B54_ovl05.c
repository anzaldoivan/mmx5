#include "types.h"

extern s32 func_8002B5B4(s32);
extern s32 func_8002C338(s32, void*, s32);
extern u8 D_8009A1F8[];
extern s8 D_800D1C1D;
extern u8 D_800F5648_ovl05[];
extern u8 D_800F5668_ovl05[];
extern s16 D_800F595C_ovl05;
extern s16 D_800F595E_ovl05;
extern u8 D_800F5964_ovl05[];

void func_800F3B54_ovl05(u8* arg0) {
    u8* p;
    s16 t;
    u16 a;

    if (D_800D1C1D == 2) {
        p = D_8009A1F8;
        a = *(u16*)(p + 0xA);
        *(s16*)(arg0 + 0xE) = 0xB40;
        *(s16*)(arg0 + 0xA) = a - 0x10;
        D_800F595C_ovl05 = 0x600;
        D_800F595E_ovl05 = 0xA00;
        D_800F5964_ovl05[1] = 0;
        p[0xA6] = 0;
        p[0x57] = 0;
        p[0x98] = 0;
        arg0[0x80] = 0;
        *(s16*)(arg0 + 0x7C) = 0;
        arg0[4]++;
        t = ((func_8002B5B4(0x25) << 16) >> 14) + 0x1A;
        func_8002C338(0x61, D_800F5648_ovl05, 1);
        func_8002C338(t, D_800F5668_ovl05, 1);
    }
}
