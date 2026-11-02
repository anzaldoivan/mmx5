#include "types.h"

extern void func_8001296C(s32);
extern void func_80016490(s32, s32, void*);
extern void func_80016D54(s32, s32);
extern s32 func_80028B18(s32, s32, s32, void*);
extern s32 func_8002A5C4(s32, s32, s32);
extern void func_8002DF54(u8* a0);
extern u8 D_8009A0A0[];
extern u8 D_8009A244;
extern s8 D_800D1C00[];
extern u8 D_800F9BB8_ovl11[];
extern u8 D_800F9BC0_ovl11[];
extern u8 D_800F9BC8_ovl11[];

void func_800F36E8_ovl11(u8* a0) {
    u8* g;
    u8* h;
    u8 t;

    g = D_8009A0A0;
    if (((s8*)g)[0xF3] == 0) {
        func_8002DF54(a0);
    } else if ((u32)(g[0xFA] - 2) >= 2U) {
        func_8002DF54(a0);
    }
    if (*(s16*)(a0 + 0xE) == 0x490 && a0[0x82] == 0) {
        func_8001296C(3);
        func_80028B18(0, 0x800, 0x4B0, D_800F9BB8_ovl11);
        D_8009A244 = 1;
        a0[7] = 3;
        a0[0x82]++;
    } else if (*(s16*)(a0 + 0xE) == 0x580 && (t = a0[0x82]) == 1) {
        func_8001296C(3);
        func_80028B18(0, 0x7A0, 0x5A0, D_800F9BC0_ovl11);
        a0[7] = 4;
        D_8009A244 = 1;
        a0[0x82]++;
    } else if (*(s16*)(a0 + 0xE) == 0x670 && a0[0x82] == 2) {
        func_8001296C(3);
        func_80028B18(0, 0x800, 0x690, D_800F9BC8_ovl11);
        a0[7] = 5;
        D_8009A244 = 1;
    }
    h = D_8009A0A0;
    if (*(s16*)(h + 0xA) >= 0x930 && D_800D1C00[0x29] == 0) {
        func_80016D54(5, 0x1D);
        D_800D1C00[0x29] = 1;
    }
    if (*(s16*)(a0 + 0xE) >= 0x850) {
        a0[5] = 8;
        if (D_800D1C00[0x1D] < 2) {
            if (D_800D1C00[0x29] == 0) {
                func_80016D54(5, 0x1D);
                D_800D1C00[0x29] = 1;
            }
            func_80016490(5, 0x1B, a0);
            func_8002A5C4(0x20, 4, 1);
        }
    }
}
