#include "types.h"
#include "mmx5/globals.h"

void func_800F5990_ovl18(u8* a0) {
    s32 y = D_8009A0AA;
    s32 x = *(s16*)(a0 + 0xA);
    if ((((y - x) < 0) ? (x - y) : (y - x)) < 0xB1) {
        a0[0x7C] = 0x3C;
        a0[6]++;
    }
}
