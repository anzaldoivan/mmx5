#include "types.h"

extern s32 rsin(s32);

void func_800FD044_ovl38(u8* p) {
    s32 t;

    p[3] = 1;
    if (p[0x15] == 0) {
        *(s32*)(p + 0x20) = -0x20000;
    } else {
        *(s32*)(p + 0x20) = 0x20000;
    }
    t = rsin(*(s16*)(p + 0x90)) << 4;
    if (*(s8*)(p + 2) == 0) {
        *(u16*)(p + 0x90) += 0x46;
    } else {
        *(u16*)(p + 0x90) -= 0x46;
    }
    *(u16*)(p + 0x90) &= 0xFFF;
    if (t != 0) {
        t <<= 5;
    }
    *(s32*)(p + 8) += *(s32*)(p + 0x20);
    *(s32*)(p + 0xC) = *(s32*)(p + 0x8C) - t;
    p[6]++;
}
