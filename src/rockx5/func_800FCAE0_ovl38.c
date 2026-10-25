#include "types.h"

extern u8* func_8002C938();

void func_800FCAE0_ovl38(u8* a0, u8 a1) {
    u8* p;

    p = func_8002C938();
    if (p) {
        p[0] = 0x61;
        p[1] = 0x42;
        p[2] = a1;
        *(s32*)(p + 0x10) = 0;
        *(u8**)(p + 0x80) = a0;
        *(u16*)(p + 0x40) = *(u16*)(a0 + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
        *(s32*)(p + 0x3C) = *(s32*)(a0 + 0x3C);
        *(s32*)(p + 0x30) = *(s32*)(a0 + 0x30);
        p[0x14] = a0[0x14];
    }
}
