#include "types.h"

extern u8 D_80091C44;
extern void func_800177B0(s32, s32);

void func_800FA6D4_ovl46(Actor50* a) {
    if (D_80091C44 == 0) {
        func_800177B0(0x16, 0x7F);
        a->step++;
    }
}
