#include "types.h"

extern u8 D_8009A1F8[];

void func_800EF0B8_ovl21(u8* a0) {
    u8* p;

    *(s16*)(a0 + 4) += 1;
    if (*(s16*)(a0 + 4) >= 9) {
        p = D_8009A1F8;
        *(s32*)(p + 0x8) = 0x4000000;
        *(s32*)(p + 0xC) = 0;
        p[0x4C] = 1;
        p[3] = 1;
        *(s16*)(a0 + 4) = 0;
        a0[1]++;
    }
}
