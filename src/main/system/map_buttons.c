#include "types.h"
#include "mmx5/globals.h"

extern u16 g_button_map[];

u16 map_buttons(u16 mask) {
    u16 r;
    u16 bit;
    u32 i;
    u16* p;
    u8* g;
    u16 t;

    r = 0;
    bit = 1;
    i = 0;
    p = g_button_map;
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
    g = g_Player;
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
