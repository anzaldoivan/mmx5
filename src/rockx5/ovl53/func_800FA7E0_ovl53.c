#include "types.h"

extern u8 D_80091C44;
extern void func_800177B0(s32, s32);

void func_800FA7E0_ovl53(Actor50* a) {
    if (D_80091C44 == 0) {
        func_800177B0(3, 0x7F);
        a->step++;
    }
}
