#include "types.h"

extern u8* func_8002C938();

void func_800F6DF4_ovl01(u8* arg0) {
    u8* p;

    p = func_8002C938();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x10;
        p[2] = 0x30;
        *(u16*)(p + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(arg0 + 0xE);
        *(s32*)(p + 0x10) = 0;
        *(u8**)(p + 0x80) = arg0;
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
    }
    p = func_8002C938();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x10;
        p[2] = 0x40;
        *(u16*)(p + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(arg0 + 0xE);
        *(s32*)(p + 0x10) = 0;
        *(u8**)(p + 0x80) = arg0;
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
    }
}
