#include "types.h"

extern void func_8003D29C(s32, s32);
extern u8 D_8009A0B5;
extern void (*D_800FB510_ovl09[])(u8*);

void func_800F8300_ovl09(u8* a0) {
    if (((s8*)a0)[5] != 0 && ((s8*)a0)[0x5C] <= 0) {
        func_8003D29C(0x14, D_8009A0B5);
        a0[0x5C] = 0;
        a0[4] = 2;
        a0[5] = 0;
        a0[6] = 0;
    } else {
        D_800FB510_ovl09[((s8*)a0)[5]](a0);
    }
}
