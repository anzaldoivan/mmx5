#include "types.h"
#include "addr.h"

void func_80019D24(u8* o) {
    s32 t;
    s32 c;

    *(s16*)(o + 0x40) = 0x1F00;
    t = *(s32*)D_801F3000;
    *(s8*)(o + 0x14) = -1;
    c = *(s8*)(o + 2);
    o[0x16] = 0xFF;
    o[0x15] = 0;
    *(s16*)(o + 0x42) = 0x7845;
    *(s32*)(o + 0x3C) = t + (s32)D_801F3000;
    switch (c) {
    case 0:
    case 3:
        o[5] = 0;
        break;
    case 1:
    case 4:
        o[5] = 1;
        break;
    case 2:
    case 5:
        o[5] = 2;
        break;
    case 6:
        o[0x47] = 0;
        o[5] = 3;
        break;
    case 7:
        o[0x47] = 1;
        o[5] = 3;
        break;
    case 8:
        o[0x47] = 0xD;
        o[5] = 3;
        break;
    case 9:
        o[0x47] = 0xC;
        o[5] = 3;
        break;
    }
    o[4]++;
}
