#include "types.h"

extern u8* func_8002D210();

void func_800FB308_ovl27(u8* o, u8 arg1) {
    u8* c;

    c = func_8002D210();
    if (c != 0) {
        c[0] = 0x41;
        c[1] = 0x19;
        c[2] = arg1;
        *(s32*)(c + 0x8) = *(s32*)(o + 0x8);
        *(s32*)(c + 0xC) = *(s32*)(o + 0xC);
        *(u8**)(c + 0x7C) = o;
        c[0x14] = o[0x14];
    }
}
