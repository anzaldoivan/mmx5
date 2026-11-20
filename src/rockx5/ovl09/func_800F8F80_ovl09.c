#include "types.h"

extern u8* func_8002D210();

void func_800F8F80_ovl09(u8* a0) {
    u8* o;

    o = func_8002D210();
    if (o != 0) {
        o[0] = 0x41;
        o[1] = 0x18;
        o[2] = 0;
        *(u16*)(o + 0xA) = *(u16*)(a0 + 0xA);
        *(u16*)(o + 0xE) = *(u16*)(a0 + 0xE);
        *(u8**)(o + 0x7C) = a0;
        o[0x14] = a0[0x14];
    }
}
