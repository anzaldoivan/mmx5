#include "types.h"

void func_800FB5BC_ovl27(u8* a0) {
    u8 st = a0[2];

    if ((u8)(st - 2) < 2) {
        if (--*(s16*)(a0 + 0x88) == 0) {
            *(s32*)(a0 + 0x20) = ((s8)st == 2) ? -0x4000 : 0x4000;
            *(s16*)(a0 + 0x88) = 0x40;
            a0[6] = 3;
        }
    }
}
