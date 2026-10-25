#include "types.h"

void func_800F1FDC_ovl05(u8* a0) {
    s8 s;
    u8 u;

    s = ((s8*)a0)[0x45];
    u = a0[0x45];
    if (s == 1) {
        a0[0x91] = s;
        a0[0x5] = 2;
        a0[0x6] = 0;
        return;
    }
    a0[0x8C] = -u;
    a0[0x8E] = u;
}
