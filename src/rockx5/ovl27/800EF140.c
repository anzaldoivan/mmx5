#include "types.h"
#include "mmx5/ovl27.h"
#include "mmx5/globals.h"

extern void func_8002C1C8(void);
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];
extern u16 D_800FC4F4_ovl27[][2];
extern u8 D_800FDC98_ovl27[];

void func_800EF140_ovl27(u8* arg0) {
    u8* p;
    s32 one;
    s32 n;

    D_800D50DC = 1;
    D_8009A42C = 1;
    D_80093E66 = 1;
    func_8002C1C8();
    one = 1;
    D_80093DD0[2] |= 0x02000000;
    n = 0x1F;
    *(s16*)(arg0 + 0x16) = 0;
    D_800D50DE = n;
    D_8009A42E = 0x3E0;
    D_80093E68 = 0x7C00;
    p = D_8009A1F8.u;
    p[0xF4] = one;
    p[0xAB] = 0;
    *(u16*)(p + 0xB2) = D_800FC4F4_ovl27[0][0];
    *(u16*)(p + 0xB6) = D_800FC4F4_ovl27[0][1];
    func_8002C3CC(D_800FDC98_ovl27, D_800FDC18_ovl27.u, 0x40, 0x1F, 0x1F);
    ((s32(*)())load_palette)(*(s16*)(arg0 + 0x1A), D_800FDC98_ovl27, 4);
    arg0[6]++;
}

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_800FDC98_ovl27[];
extern u8 D_800FDD38_ovl27[];
extern u8 D_800FDF58_ovl27[];

void func_800EF234_ovl27(u8* arg0) {
    if (++*(s16*)(arg0 + 0x16) >= 0x79) {
        *(s16*)(arg0 + 0x16) = 0;
        arg0[0x1C] = 0;
        D_8009A1F8.u[0x58] = 2;
        D_8009A1F8.u[0xA0] = 1;
        D_8009A1F8.u[0x57] = 1;
        func_8002C3CC(D_800FDF58_ovl27, D_800FDD58_ovl27.u, 0x100,
                      0x1F - arg0[0x1C], 0x1F);
        ((s32(*)())load_palette)(0x50, D_800FDF58_ovl27, 0x10);
        func_8002C3CC(D_800FDC98_ovl27, D_800FDC18_ovl27.u, 0x40,
                      0x1F - arg0[0x1C], 0x1F);
        ((s32(*)())load_palette)(*(s16*)(arg0 + 0x1A), D_800FDC98_ovl27, 4);
        func_8002C3CC(D_800FDD38_ovl27, D_800FDD18_ovl27.u, 0x10, arg0[0x1C],
                      0x1F);
        ((s32(*)())load_palette)(0x46, D_800FDD38_ovl27, 1);
        arg0[6]++;
    }
}

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_8009A2A3;
extern u8 D_800FDC98_ovl27[];
extern u8 D_800FDD38_ovl27[];
extern u8 D_800FDF58_ovl27[];

void func_800EF360_ovl27(u8* a0) {
    s16 t;

    t = ++*(s16*)(a0 + 0x16);
    if ((s16)(t % 2) * 20 == 0) {
        a0[0x1C]++;
        func_8002C3CC(D_800FDF58_ovl27, D_800FDD58_ovl27.u, 0x100,
                      0x1F - a0[0x1C], 0x1F);
        ((s32(*)())load_palette)(0x50, D_800FDF58_ovl27, 0x10);
        func_8002C3CC(D_800FDC98_ovl27, D_800FDC18_ovl27.u, 0x40,
                      0x1F - a0[0x1C], 0x1F);
        ((s32(*)())load_palette)(*(s16*)(a0 + 0x1A), D_800FDC98_ovl27, 4);
        func_8002C3CC(D_800FDD38_ovl27, D_800FDD18_ovl27.u, 0x10, a0[0x1C],
                      0x1F);
        ((s32(*)())load_palette)(0x46, D_800FDD38_ovl27, 1);
        if (a0[0x1C] >= 0x1F) {
            a0[6]++;
            D_8009A2A3 = 0;
            ((s32(*)())load_palette)(0x50, D_800FDD58_ovl27.u, 0x10);
            ((s32(*)())load_palette)(*(s16*)(a0 + 0x1A), D_800FDC18_ovl27.u, 4);
            ((s32(*)())load_palette)(0x46, D_800FDD18_ovl27.u, 1);
            ((s32(*)())load_palette)(0x45, D_800FE158_ovl27.u, 1);
        }
    }
}
