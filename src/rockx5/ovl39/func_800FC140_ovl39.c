#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void func_800FC140_ovl39(u8* a0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        a0[5]++;
        *(s16*)(p + 0x96) = 0;
        p[0xA0] = 1;
        *(s16*)(a0 + 0x7C) = 0x7F;
        *(s16*)(a0 + 0x7E) = 25;
        a0[0x61] = 25;
        *(u16*)(a0 + 0x42) &= 0x7FFF;
    }
}
