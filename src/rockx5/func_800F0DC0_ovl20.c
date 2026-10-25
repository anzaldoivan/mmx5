#include "types.h"

extern s8 D_800D1C28[];
extern u8 D_800F5FE0_ovl20[];
extern u8 D_800F5FE9_ovl20;

void func_800F0DC0_ovl20(u8* a0) {
    s32 i;

    if (D_800D1C28[1] == 0) {
        *(s16*)(a0 + 8) = 0;
        *(s16*)(a0 + 0xA) = 0;
        a0[2]++;
        for (i = 0; i < 9; i++) {
            D_800F5FE0_ovl20[i] = 0;
        }
        if (a0[0x79] >= 5 || a0[0x10F] == 2 || a0[0x10F] == 4) {
            D_800F5FE9_ovl20 = 9;
        } else {
            D_800F5FE9_ovl20 = 8;
        }
    }
}
