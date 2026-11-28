#include "types.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F24E8_ovl11(u8* arg0) {
    u8* scr;
    u8 n;
    s16 d;
    s32 dy;
    u16 x;

    if (*(s8*)(arg0 + 0x67) != 0) {
        return;
    }
    if (*(s8*)(arg0 + 5) == 6) {
        return;
    }
    {
        u8* s0 = D_1F80004C.bytes;
        u8 c = s0[0x83];
        if (c != 0) {
            s0[0x83] = c - 1;
            return;
        }
    }
    x = *(u16*)(arg0 + 0xA);
    {
        u8* g1 = g_Player;
        d = (*(s16*)(arg0 + 0xA) - *(s16*)(g1 + 0xA) >= 0)
                ? x - *(u16*)(g1 + 0xA)
                : *(u16*)(g1 + 0xA) - x;
    }
    if (d >= 0x81) {
        return;
    }
    {
        u8* g2 = g_Player;
        if ((s16)x > *(s16*)(g2 + 0xA)) {
            arg0[0x15] = 0;
        } else {
            arg0[0x15] = 0x40;
        }
    }
    scr = D_1F80004C.bytes;
    n = scr[0x85];
    if (n == 1 || (n == 2 && *(s8*)(arg0 + 2) != 0)) {
        scr[0x82] = 0x40;
    } else {
        u8* g3 = g_Player;
        dy = *(s16*)(arg0 + 0xE) - *(s16*)(g3 + 0xE);
        if (dy >= 0x21) {
            D_1F80004C.bytes[0x82] = 0x80;
        } else if (dy < -0x10) {
            D_1F80004C.bytes[0x82] = 0x82;
        } else {
            D_1F80004C.bytes[0x82] = 0x81;
        }
    }
    set_animation(arg0, 0xA);
    arg0[5] = 6;
    arg0[6] = 0;
}
