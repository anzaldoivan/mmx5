#include "types.h"

extern u8* func_8002D0E4(void);

void func_800F6ABC_ovl28(u8* a0) {
    u8* p = func_8002D0E4();
    if (p != 0) {
        p[0] = 0x61;
        p[1] = 0xB;
        p[2] = 3;
        *(u16*)(p + 0x40) = *(u16*)(a0 + 0x40);
        *(s32*)(p + 0x30) = *(s32*)(a0 + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(a0 + 0x3C);
        *(u16*)(p + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
        p[0x15] = a0[0x15];
        *(s32*)(p + 0x8) = *(s32*)(a0 + 0x8);
        *(s32*)(p + 0xC) = *(s32*)(a0 + 0xC);
        *(u8**)(p + 0x50) = a0;
    }
}
