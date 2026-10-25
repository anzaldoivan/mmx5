#include "types.h"

extern u16 D_8006FAE4[];
extern u8 D_8009A0A0[];

u16 func_8003D688(u16 mask) {
    u16 r;
    u16 bit;
    u32 i;
    u16* p;
    u8* g;
    u16 t;

    r = 0;
    bit = 1;
    i = 0;
    p = D_8006FAE4;
    do {
        if (*p & mask) {
            r |= bit;
        }
        bit <<= 1;
        i++;
        p++;
    } while (i < 16);
    if ((r & 3) == 3) {
        r &= ~3;
    }
    if ((r & 0xC) == 0xC) {
        r &= ~0xC;
    }
    g = D_8009A0A0;
    if (((s8*)g)[2] == 0) {
        t = (r << 1) & 0x20;
        if (r & 0x20) {
            t |= 0x10;
        }
        r &= ~0x30;
        r |= t;
    }
    return r;
}
