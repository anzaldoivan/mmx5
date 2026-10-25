#include "types.h"

extern s8 D_800D1C28[];
extern u8 D_800F5FE0_ovl20[];
extern u8 D_800F5FE9_ovl20;

void func_800F1914_ovl20(u8* arg0) {
    s32 i;
    u8 v;

    if (D_800D1C28[1] == 0) {
        *(s16*)(arg0 + 8) = 0;
        *(s16*)(arg0 + 0xA) = 0;
        for (i = 0; i < 9; i++) {
            if (i < 4) {
                D_800F5FE0_ovl20[i] = 1;
            } else {
                D_800F5FE0_ovl20[i] = 0;
            }
        }
        if (arg0[0x79] < 5 && (v = arg0[0x10F]) != 2 && v != 4) {
            D_800F5FE9_ovl20 = 8;
        } else {
            D_800F5FE9_ovl20 = 9;
        }
        arg0[1] = 3;
        arg0[2] = 2;
        arg0[0x79] = 2;
    }
}
