#include "types.h"

extern void func_8002DF54(u8* a0);

void func_800FA65C_ovl27(u8* a0) {
    s32 hit;

    if (*(s32*)(a0 + 0x20) > 0) {
        hit = a0[0x70] & 1;
    } else {
        hit = a0[0x70] & 2;
    }
    if (hit) {
        *(s32*)(a0 + 0x20) = 0;
        *(s32*)(a0 + 0x24) = 0;
        *(s16*)(a0 + 0x7C) = 0x50;
        a0[6] = 1;
    } else {
        func_8002DF54(a0);
    }
}
