#include "types.h"

extern u8 D_8009A1F8[];

void func_800EED98_ovl21(u8* a0) {
    u8* p;

    p = D_8009A1F8;
    *(s32*)(p + 0x8) += -0x40000;
    *(s32*)(p + 0xC) += -0x80000;
    *(s16*)(a0 + 4) += 1;
    if (*(s16*)(a0 + 4) >= 30) {
        p[3] = 0;
        *(s16*)(a0 + 4) = 0;
        a0[1]++;
    }
}
