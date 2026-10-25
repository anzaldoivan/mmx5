#include "types.h"

extern u8 D_8009A0A0[];
extern void (*D_800FD2B4_ovl01[])(u8*);
extern s16 D_800FD204_ovl01[][2];

void func_800F63E4_ovl01(u8* a0) {
    u8* base = D_8009A0A0;
    s16 v;
    s32 i;

    if (base[0xF7] == 0) {
        D_800FD2B4_ovl01[((s8*)a0)[5]](a0);
    }
    i = a0[2] & 0xF;
    v = *(s16*)(base + 0xA);
    if (v >= D_800FD204_ovl01[i][0] && v <= D_800FD204_ovl01[i][1]) {
        a0[3] = 1;
    } else {
        a0[3] = 0;
    }
}
