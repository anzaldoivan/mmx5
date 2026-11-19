#include "types.h"

extern u8 D_8009A1F8[];

void func_800FB60C_ovl55(u8* e) {
    u8* p;
    s32 v;

    p = D_8009A1F8;
    p[0xA0] = 1;
    v = *(s32*)(p + 0x5C) + 0x100000;
    *(s32*)(p + 0x5C) = v;
    if (v > 0x33FFFFF) {
        *(s32*)(p + 0x5C) = 0x3400000;
        *(s16*)(e + 4) = 0;
        e[1]++;
    }
}
