#include "types.h"

void func_800F1A44_ovl04(u8* a0) {
    s32 n;

    n = *(u16*)(a0 + 0x7E) - 1;
    *(u16*)(a0 + 0x7E) = n;
    if ((n << 16) == 0) {
        *(u16*)(a0 + 0x86) = *(u16*)(a0 + 0xE);
        *(s32*)(a0 + 0x2C) = -*(s32*)(a0 + 0x2C);
        a0[0x81]++;
    }
}
