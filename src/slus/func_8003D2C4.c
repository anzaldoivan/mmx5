#include "types.h"

extern u8 D_8009A0A0[];
extern s8 D_800D1C1C;

void func_8003D2C4(void) {
    u8* p = D_8009A0A0;

    p[0xD0] = 0;
    if (((s8*)p)[0x14B] >= 0 || ((s8*)p)[2] == 0) {
        p[0x7A] = 0;
    }
    D_800D1C1C = 0;
}
