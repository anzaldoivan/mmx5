#include "types.h"

void func_800F1E84_ovl08(u8* p) {
    s32 t;

    t = *(u16*)(p + 0x7C) - 1;
    *(u16*)(p + 0x7C) = t;
    if ((s16)t >= 0x3D) {
        if (t & 1) {
            *(s16*)(p + 0xE) -= 1;
        } else {
            *(s16*)(p + 0xE) += 1;
        }
        return;
    }
    *(s16*)(p + 0xE) = *(s16*)(p + 0x7E) + *(s16*)(p + 0x80);
    p[6]++;
}
