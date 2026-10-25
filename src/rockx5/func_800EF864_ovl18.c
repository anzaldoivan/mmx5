#include "types.h"

extern s32 func_8003D29C(s32, s32);
extern u8 D_8009A0B5;

void func_800EF864_ovl18(u8* a0) {
    if (--*(s16*)(a0 + 0x7C) == 0) {
        func_8003D29C(0x16, D_8009A0B5);
        *(s16*)(a0 + 0x7C) = 0x28;
        a0[6] = a0[6] + 1;
    }
}
