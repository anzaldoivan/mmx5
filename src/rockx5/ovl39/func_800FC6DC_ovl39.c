#include "types.h"

extern u8* func_8002D210();

void func_800FC6DC_ovl39(u8* a0) {
    s32 i;
    u8* o;

    for (i = 0; i < 2; i++) {
        o = func_8002D210();
        if (o != 0) {
            o[0] = 0x61;
            o[1] = 0x1D;
            o[2] = i;
            *(u16*)(o + 0x40) = *(u16*)(a0 + 0x40);
            *(s32*)(o + 0x30) = *(s32*)(a0 + 0x30);
            *(s32*)(o + 0x3C) = *(s32*)(a0 + 0x3C);
            *(u16*)(o + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
            *(u8**)(o + 0x7C) = a0;
            o[4] = 0;
        }
    }
    a0[7] = 0x11;
    *(s16*)(a0 + 0x7C) = 2;
    a0[6]++;
}
