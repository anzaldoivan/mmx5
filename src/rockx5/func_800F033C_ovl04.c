#include "types.h"

extern u8 D_8009A0A0[];

s32 func_800F033C_ovl04(void) {
    u8* p = D_8009A0A0;
    s32 r;

    r = 0;
    if (((s8*)p)[0xF3] == 0 || (u32)(p[0xFA] - 2) >= 2) {
        r = 1;
    }
    return r;
}
