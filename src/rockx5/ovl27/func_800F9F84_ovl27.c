#include "types.h"

extern s32 func_80024548(s32);
extern u8 D_800D1C00[];

void func_800F9F84_ovl27(u8* a0) {
    u8* p = D_800D1C00;

    if (((s8*)p)[0x2B] != 0) {
        a0[0x5C] = 0;
        p[0x25] = 0;
        *(u8**)(p + 0x20) = a0;
        p[0xA2] = 0x40;
        func_80024548(1);
        p[0xA2] &= 0xFC;
        a0[6]++;
    }
}
