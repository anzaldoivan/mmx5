#include "types.h"

extern void func_80028B18(s32, s32, s32, void*);
extern void func_8002385C(s32, s32, s32);
extern u8 D_800FB9E8_ovl55[];
extern u8 D_8009A298;

void func_800FADD8_ovl55(u8* a0) {
    if (++*(s16*)(a0 + 4) >= 20) {
        func_80028B18(1, 0x20, 0x160, D_800FB9E8_ovl55);
        D_8009A298 = 1;
        a0[1]++;
        func_8002385C(0x5B, 0xFF, 0);
    }
}
