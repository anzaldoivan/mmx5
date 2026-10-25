#include "types.h"

extern u8 D_800E9308;

s32 func_800310E4(u8* p, s16 a, s16 b, s32 c) {
    s32 ret;
    s16 t;

    D_800E9308 = 1;
    if (((s8*)p)[0x67] != 0 && c == 0 && (a & 0xF) < b) {
        return 0;
    }
    ret = -1;
    p[0x70] = 8;
    t = a - (b + (a & ~0xF));
    *(s16*)(p + 0xC) = 0;
    *(s16*)(p + 0xE) -= t;
    return ret;
}
