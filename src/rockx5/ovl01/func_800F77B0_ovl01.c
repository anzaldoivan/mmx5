#include "types.h"

extern s32 D_8009A0A8;

void func_800F77B0_ovl01(u8* p) {
    s32 g;
    u8 c;

    if (--*(s16*)(p + 0x8C) == -1) {
        g = D_8009A0A8;
        c = p[6];
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x24) = 0xFFFE0000;
        *(s32*)(p + 0x28) = 0;
        *(s32*)(p + 0x2C) = 0;
        *(s32*)(p + 0x8) = g;
        p[6] = c + 1;
    }
}
