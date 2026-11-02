#include "types.h"

extern u8 D_800D1C00[];

s32 func_8003E96C(u8* p) {
    u16 f80;
    u8* g;

    f80 = *(u16*)(p + 0x80);
    if (f80 & 0x10) {
        return 1;
    }
    if (f80 & 0x20) {
        return 1;
    }
    if (*(u16*)(p + 0x7C) & 0x10) {
        g = D_800D1C00;
        if (g[0x110] & 2) {
            return 1;
        }
    }
    g = D_800D1C00;
    if (*(u16*)(p + 0x7C) & 0x20) {
        if (g[0x110] & 2) {
            return 1;
        }
    }
    g = D_800D1C00;
    if ((g[0x110] & 1) && ((s8*)p)[0x93] == 0) {
        if ((*(s32*)(p + 0x7C) & 0x100010) == 0x100000) {
            return 1;
        }
        if ((*(s32*)(p + 0x7C) & 0x200020) == 0x200000) {
            return 1;
        }
    } else {
        if ((*(s32*)(p + 0x7C) & 0x100010) == 0x100000) {
            return 1;
        }
        if ((*(s32*)(p + 0x7C) & 0x200020) == 0x200000) {
            return 1;
        }
        if (p[0x9D] != 0 && !(*(u16*)(p + 0x7C) & 0x10)) {
            return 1;
        }
        if (p[0x9E] != 0 && !(*(u16*)(p + 0x7C) & 0x20)) {
            return 1;
        }
    }
    return 0;
}
