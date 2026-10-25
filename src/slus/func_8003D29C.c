#include "types.h"

extern u8 D_8009A0A0[];
extern s8 D_800D1C1C;

void func_8003D29C(s32 arg0, s32 arg1) {
    u8* p = D_8009A0A0;

    p[0xD0] = 1;
    p[0xD1] = arg0;
    p[0xD2] = arg1;
    p[0x7A] = 1;
    D_800D1C1C = 1;
}
