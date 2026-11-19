#include "types.h"
#include "mmx5/globals.h"

extern void silence_sound(s32, s32);
extern void start_pad_vibration(s32);
extern u8 D_800D1C00[];

void func_8003D868(u8* p) {
    u8* g;

    silence_sound(1, 5);
    silence_sound(1, 7);
    start_pad_vibration(0);
    if (((s8*)p)[0xD5] != 0) {
        p[3] = 0;
        p[0xD7] = 1;
    } else {
        g = D_800D1C00;
        g[0x12] = 1;
        g[0x13] = 1;
        g[0x14] = 1;
        g[0x15] = 1;
        g[0x16] = 1;
        g[0x17] = 1;
        g[0x18] = 1;
        g[0x19] = 1;
        g[0x1A] = 1;
        p[0xD7] = 8;
        func_8003B33C(p, 0x21);
    }
    p[5]++;
}
