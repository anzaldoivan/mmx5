#include "types.h"

void func_800F071C_ovl07(u8* p) {
    s32 x;
    u8 f;

    if (p[0x82] != p[0x83]) {
        f = p[0x80];
        if ((f & 1) && (*(s32*)(p + 0x80) & 0xFFFF0000) == 0x20000) {
            x = *(s32*)(p + 0x20);
            x = (x < 0 ? -x : x) * 2;
            *(s32*)(p + 0x2C) = 0x5000;
            p[0x6] = 2;
            p[0x80] = f | 2;
            *(s32*)(p + 0x24) = (x / 237) << 8;
        }
    }
}
