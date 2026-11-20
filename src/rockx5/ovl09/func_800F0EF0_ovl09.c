#include "types.h"
#include "mmx5/globals.h"

void func_800F0EF0_ovl09(u8* a0) {
    u8* p;
    u8* q;
    s16 x;
    s16 y;
    s32 d;
    s16 x2;
    s16 y2;
    s32 d2;

    p = g_Player;
    x = *(s16*)(p + 0xA);
    y = *(s16*)(a0 + 0xA);
    d = x - y;
    if ((d >= 0 ? (x - y) : (y - x)) < 0x141) {
        q = g_Player;
        x2 = *(s16*)(q + 0xE);
        y2 = *(s16*)(a0 + 0xE);
        d2 = x2 - y2;
        if ((d2 >= 0 ? (x2 - y2) : (y2 - x2)) < 0x141) {
            if (--*(s16*)(a0 + 0x7C) == -1) {
                a0[5] = 3;
                a0[6] = 0;
            }
        }
    }
}
