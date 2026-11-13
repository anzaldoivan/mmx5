#include "types.h"

extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);
extern void func_80050650(s32, s16, s16, s16, s16, s32);
extern s32 func_8002A5C4(s32, s32, s32);
extern void func_80028B18(s32, s32, s32, void*);
extern void func_80016490(s32, s32, void*);
extern s8 D_800D1C26;
extern u8 D_8009A244;
extern u8 D_800FB3A4_ovl00[];
extern u8 D_800FB3AC_ovl00[];
extern u8 D_800FB3BC_ovl00[];

void func_800F677C_ovl00(u8* arg0) {
    s8 state;
    s32 t;

    state = ((s8*)arg0)[2];
    if (state >= 0x7E) {
        if (((s8*)*(u8**)(arg0 + 0x7C))[4] == 2) {
            arg0[4] = 2;
            *(s32*)(arg0 + 0x20) = 0;
            func_8005019C(0x21, 2, arg0, 0x18, 4);
        }
        return;
    }
    t = arg0[0x80] + 1;
    arg0[0x80] = t & 0x3F;
    arg0[0x81]++;
    if ((t & 0xF) == 0) {
        if (state == 0) {
            func_80050650(0x20, 0x1140, 0x310, 0x1180, 0x3D0, 4);
        }
        if (((s8*)arg0)[2] == 1) {
            func_80050650(0x20, 0x1140, 0x160, 0x1160, 0x230, 4);
        }
        if (((s8*)arg0)[2] == 2) {
            func_80050650(0x20, 0x1060, 0x240, 0x1080, 0x310, 4);
        }
    }
    if (arg0[0x80] == 0 && D_800D1C26 == 0) {
        func_8002A5C4(0x20, 3, 1);
    }
    if (((s8*)arg0)[2] == 0) {
        if (arg0[0x81] & 0x1F) {
            func_80028B18(0, (s16)(*(s16*)(arg0 + 0xA) + 0x10), 0x300,
                          D_800FB3A4_ovl00);
            D_8009A244 = 1;
        }
        if (*(s16*)(arg0 + 0xA) < 0x1089) {
            func_80028B18(0, 0x1070, 0x300, D_800FB3A4_ovl00);
            func_80028B18(0, 0x1080, 0x300, D_800FB3A4_ovl00);
            D_8009A244 = 1;
            arg0[4] = 2;
            *(s32*)(arg0 + 0x20) = 0;
            if (D_800D1C26 == 0) {
                func_8002A5C4(0x20, 2, 1);
            }
            func_80050650(0x20, 0x1070, 0x310, 0x1080, 0x3D0, 8);
            func_80016490(5, 2, 0);
        }
    }
    if (((s8*)arg0)[2] == 1) {
        if (arg0[0x81] & 0x1F) {
            func_80028B18(0, (s16)(*(s16*)(arg0 + 0xA) + 0x10), 0x170,
                          D_800FB3AC_ovl00);
            D_8009A244 = 1;
        }
        if (*(s16*)(arg0 + 0xA) < 0x1089) {
            func_80028B18(0, 0x1070, 0x170, D_800FB3AC_ovl00);
            func_80028B18(0, 0x1080, 0x170, D_800FB3AC_ovl00);
            D_8009A244 = 1;
            arg0[4] = 2;
            *(s32*)(arg0 + 0x20) = 0;
            if (D_800D1C26 == 0) {
                func_8002A5C4(0x20, 2, 1);
            }
            func_80050650(0x20, 0x1070, 0x160, 0x1080, 0x230, 8);
            func_80016490(5, 0x14, 0);
            func_80016490(5, 2, 0);
        }
    }
    if (((s8*)arg0)[2] == 2) {
        if (arg0[0x81] & 0x1F) {
            func_80028B18(0, (s16)(*(s16*)(arg0 + 0xA) - 0x10), 0x240,
                          D_800FB3BC_ovl00);
            D_8009A244 = 1;
        }
        if (*(s16*)(arg0 + 0xA) >= 0x1137) {
            func_80028B18(0, 0x1130, 0x240, D_800FB3BC_ovl00);
            func_80028B18(0, 0x1140, 0x240, D_800FB3BC_ovl00);
            D_8009A244 = 1;
            arg0[4] = 2;
            *(s32*)(arg0 + 0x20) = 0;
            if (D_800D1C26 == 0) {
                func_8002A5C4(0x20, 2, 1);
            }
            func_80050650(0x20, 0x1140, 0x250, 0x1150, 0x3A0, 8);
            func_80016490(5, 2, 0);
        }
    }
}
