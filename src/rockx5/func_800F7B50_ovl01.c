#include "types.h"

extern s32 func_8002D800(u8* a0);
extern u8 D_800FD408_ovl01[][6];
extern u8* D_800FD3F4_ovl01[];

void func_800F7B50_ovl01(u8* a0) {
    s8 idx;
    u8* p;

    if (func_8002D800(a0) == 0) {
        idx = ((s8*)a0)[2];
        a0[0x14] = D_800FD408_ovl01[idx][0];
        p = D_800FD3F4_ovl01[idx];
        *(u8**)(a0 + 0x1C) = p;
        a0[0x18] = p[0];
        a0[0x19] = p[1];
        a0[0x1A] = p[2];
        a0[0x1B] = p[3];
        a0[4]++;
    }
}
