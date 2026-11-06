#include "types.h"

s32 func_800182D8(u16* src, u16* dst) {
    u32 flags;
    u32 mask;
    s32 n;
    u32 off;
    u32 len;
    u32 hi;
    u16* p;

    flags = *src++;
    mask = 0x8000;
    n = 16;
    do {
        if (!(mask & flags)) {
            *dst++ = *src++;
        } else {
            off = *src++;
            hi = off & 0xF800;
            if (hi) {
                len = hi >> 11;
                off &= 0x7FF;
            } else {
                len = *src++;
            }
            if ((len | off) == 0) {
                return;
            }
            if (off == 0) {
                while (len) {
                    *dst++ = 0;
                    len--;
                }
            } else {
                p = dst - off;
                while (len) {
                    *dst++ = *p++;
                    len--;
                }
            }
        }
        mask >>= 1;
        n--;
    } while (n);
    return func_800182D8(src, dst);
}
