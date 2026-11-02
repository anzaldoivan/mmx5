#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern u16 D_800C931C[];
extern u8 D_800D1C00[];
extern u8 D_800F6DF0_ovl20[];
extern u8 D_800F6DF6_ovl20;
extern u8 D_800F6DF7_ovl20;
extern u8 D_800F6DFB_ovl20;

void func_800F0210_ovl20(u8* arg0) {
    s8 old;

    old = D_800F6DF6_ovl20;
    if (D_800C931C[2] & 0x8000) {
        D_800F6DF6_ovl20--;
        if ((s8)D_800F6DF6_ovl20 < 0) {
            D_800F6DF6_ovl20 = D_800F6DFB_ovl20 - 1;
        }
    } else if (D_800C931C[2] & 0x2000) {
        D_800F6DF6_ovl20++;
        if ((s8)D_800F6DF6_ovl20 >= D_800F6DFB_ovl20) {
            D_800F6DF6_ovl20 = 0;
        }
    }
    if (old != (s8)D_800F6DF6_ovl20) {
        func_80016490(5, 0, 0);
    }
    D_800D1C00[0x2A] = D_800F6DF0_ovl20[(s8)D_800F6DF6_ovl20];
    if (D_800C931C[2] & 0x840) {
        func_80016490(5, 1, 0);
        if ((s8)D_800F6DF7_ovl20 == (s8)D_800F6DF6_ovl20) {
            arg0[1] = 6;
            arg0[2] = 0;
            return;
        }
        D_800D1C00[0x29] = 1;
        D_800F6DF7_ovl20 = D_800F6DF6_ovl20;
        arg0[2]++;
        return;
    }
    if ((D_800C931C[2] & 4) && D_800D1C00[0x79] < 5) {
        func_80016490(5, 0, 0);
        arg0[1] = 7;
        arg0[2] = 0;
    } else if (D_800C931C[2] & 8) {
        func_80016490(5, 0, 0);
        arg0[1] = 10;
        arg0[2] = 0;
    }
}
