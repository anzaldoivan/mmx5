#include "types.h"

extern u8 D_8009A1F8[];

void func_800EEE00_ovl21(u8* a0) {
    u8* p;

    p = D_8009A1F8;
    *(s32*)(p + 0x5C) += 0x2AAAA;
    *(s16*)(a0 + 4) += 1;
    if (*(s16*)(a0 + 4) >= 60) {
        *(s32*)(p + 0x5C) = 0;
        *(s32*)(p + 0x60) = 0x2000000;
        p[0xA0] = 1;
        *(s16*)(a0 + 4) = 0;
        *(s16*)(a0 + 6) = 0;
        a0[1]++;
    }
}
