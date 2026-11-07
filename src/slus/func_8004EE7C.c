#include "types.h"
#include "addr.h"

extern u8 D_800D1C03;

void func_8004EE7C(u8* p) {
    s32 t;

    p[0] = 1;
    *(s8*)(p + 0x14) = -1;
    p[0x15] = 0;
    t = p[2] & 0xF;
    switch (t) {
    case 0: {
        s32 x;
        p[0x16] = 2;
        x = D_801F3018;
        *(s16*)(p + 0x40) = 0x1F00;
        *(s16*)(p + 0x42) = 0x7800;
        *(s32*)(p + 0x3C) = x + 0x801F3000;
        p[0x47] = D_800D1C03;
        p[5] = 0;
        break;
    }
    case 1: {
        s32 x;
        p[0x16] = 2;
        x = D_801F300C;
        *(s16*)(p + 0x40) = 0x1D00;
        *(s16*)(p + 0x42) = 0x780A;
        p[0x47] = t;
        p[5] = t;
        *(s32*)(p + 0x3C) = x + 0x801F3000;
        break;
    }
    case 2: {
        s32 x;
        p[0x16] = t;
        x = D_801F300C;
        *(s16*)(p + 0x40) = 0x1D00;
        *(s16*)(p + 0x42) = 0x780A;
        p[0x47] = 0x32;
        p[5] = t;
        *(s32*)(p + 0x3C) = x + 0x801F3000;
        break;
    }
    }
    p[4]++;
}
