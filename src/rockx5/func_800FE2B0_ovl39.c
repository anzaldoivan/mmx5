#include "types.h"

void func_800FE2B0_ovl39(u8* arg0) {
    s32 t;

    arg0[3] ^= 1;
    t = *(u16*)(arg0 + 0x8C) - 1;
    *(u16*)(arg0 + 0x8C) = t;
    if ((t & 0xFFFF) == 0) {
        if (((s8*)arg0)[2] == 5) {
            (*(u8**)(arg0 + 0x7C))[0x8A] = 1;
        }
        arg0[4] = 2;
    }
}
