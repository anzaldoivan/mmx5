#include "types.h"

void func_80051588(u8* p) {
    s32 x = *(s32*)(p + 0x14);
    s32 v = *(s32*)(p + 0x3C);
    x -= v;
    *(s32*)(p + 0x14) = x;
    *(s32*)(p + 0x2C) -= v;
    *(s32*)(p + 0x3C) = v + 0x8000;
    if (x < 0x300000) {
        p[5]++;
    }
}
