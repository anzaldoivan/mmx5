#include "types.h"

void func_8002C3CC(u16* dst, u16* src, s32 n, s32 lvl, s32 max) {
    u32 r, g, b;
    u32 c;

    if (lvl >= max) {
        lvl = max;
    }
    if (lvl == max) {
        if (n > 0) {
            do {
                *dst++ = 0;
            } while (--n != 0);
        }
        return;
    }
    if (n <= 0) {
        return;
    }
    do {
        c = *src++;
        r = (c & 0x1F) << 8;
        g = (c & 0x3E0) << 8;
        b = (c & 0x7C00) << 8;
        r = (r - (r * lvl) / max) >> 8;
        g = (g - (g * lvl) / max) >> 8;
        b = (b - (b * lvl) / max) >> 8;
        if (g < 0x20) {
            g = 0;
        }
        if (b < 0x400) {
            b = 0;
        }
        r &= 0x1F;
        g &= 0x3E0;
        b &= 0x7C00;
        *dst++ = r | g | b | (c & 0x8000);
    } while (--n != 0);
}
