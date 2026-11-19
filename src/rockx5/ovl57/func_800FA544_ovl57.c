#include "types.h"

extern signed char D_8009A424;
extern void func_800177B0(s32, s32);

void func_800FA544_ovl57(Actor50* a) {
    if (D_8009A424 == 0) {
        func_800177B0(0x13, 0x7F);
        a->step++;
    }
}
