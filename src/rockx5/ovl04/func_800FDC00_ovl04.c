#include "types.h"

extern u8 D_800D1C00[];

void func_800FDC00_ovl04(void) {
    u8* p = D_800D1C00;

    p[0x27] = 0;
    p[0x2A] = 0;
    p[0x28] = 0;
    p[0x29] = 0;
    p[0x2B] = 0;
}
