#include "types.h"

extern u8 D_800D1F3C;
extern u8 D_8009A1F8[];

void func_800EED08_ovl21(u8* a0) {
    u8* p;

    if (D_800D1F3C == 2) {
        p = D_8009A1F8;
        *(s32*)(p + 0xC) += -0x88888;
        p[0x4C] = 1;
        *(s16*)(a0 + 4) += 1;
        if (*(s16*)(a0 + 4) >= 30) {
            *(s32*)(p + 0x8) = 0x800000;
            *(s32*)(p + 0xC) = 0x1000000;
            *(s32*)(p + 0x5C) = 0;
            *(s32*)(p + 0x60) = 0x1000000;
            p[0x4C] = 1;
            p[0xA0] = 1;
            *(s16*)(a0 + 4) = 0;
            a0[1]++;
        }
    }
}
