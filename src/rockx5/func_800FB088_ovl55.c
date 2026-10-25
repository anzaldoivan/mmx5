#include "types.h"

extern u8 D_8009A1F8[];
extern void func_8002385C(s32, s32, s32);

void func_800FB088_ovl55(u8* a0) {
    u8* p = D_8009A1F8;

    p[0xF4] = 1;
    *(s32*)(p + 0xB0) += 0x10000;
    if (*(s32*)(p + 0xB0) > 0xBFFFFF) {
        *(s32*)(p + 0xB0) = 0xC00000;
        a0[1]++;
        *(s16*)(a0 + 4) = 0;
        func_8002385C(0x5D, 0xFF, 0);
    }
}
