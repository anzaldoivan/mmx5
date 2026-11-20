#include "types.h"

extern u8 D_800D1F3C;
extern void func_800177B0(s32, s32);

void func_800FA79C_ovl57(Actor50* a) {
    if (D_800D1F3C == 0) {
        func_800177B0(0x1C, 0x7F);
        a->step++;
    }
}
