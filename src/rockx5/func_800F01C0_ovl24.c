#include "types.h"

extern u16 D_800C9320;
extern u8 D_800D1C00[];

void func_800F01C0_ovl24(u8* a0) {
    u8* p;

    if (D_800C9320 & 0x8FF) {
        p = D_800D1C00;
        if ((u32)(p[0x26] - 1) < 8) {
            p[0x28] = 0x7F;
            a0[1] = 2;
        } else {
            p[0x28] = 0x7F;
            a0[1] = 3;
        }
        a0[2] = 0;
    }
}
