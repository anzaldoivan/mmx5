#include "types.h"

extern s8 D_800D1C1D;
extern s32 D_800E92F8;
extern u8 D_8009A1F8[];

void func_800F15E0_ovl07(u8* arg0) {
    arg0[4]++;
    if (D_800D1C1D == 0) {
        arg0[5] = 0;
        return;
    }
    D_800E92F8 = 1;
    if (D_800D1C1D != 4) {
        D_8009A1F8[0xAC] = 1;
        *(s16*)(D_8009A1F8 + 0xE8) = 0xC80;
        *(s16*)(D_8009A1F8 + 0xEA) = 0xF0;
        D_8009A1F8[0xF4] = 1;
    } else {
        D_8009A1F8[0xAC] = 0xB;
        *(s16*)(D_8009A1F8 + 0xE8) = 0;
        *(s16*)(D_8009A1F8 + 0xEA) = -0x238;
        D_8009A1F8[0xF4] = 1;
    }
    arg0[4]++;
}
