#include "types.h"

extern u8 D_8009A1F8[];

void func_800FACFC_ovl52(u8* arg0) {
    u8* p = D_8009A1F8;

    p[0xA0] = 1;
    *(s32*)(p + 0x5C) += 0x100000;
    if (*(s32*)(p + 0x5C) > 0x33FFFFF) {
        *(s32*)(p + 0x5C) = 0x3400000;
        *(s16*)(arg0 + 4) = 0;
        *(s16*)(arg0 + 6) = 0;
        arg0[1]++;
    }
}
