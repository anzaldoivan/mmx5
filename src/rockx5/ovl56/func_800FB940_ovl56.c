#include "types.h"

extern signed char D_8009A424;
extern void func_800177B0(s32, s32);

void func_800FB940_ovl56(Actor50* a) {
    if (D_8009A424 == 0) {
        func_800177B0(2, 0x7F);
        a->step++;
    }
}
