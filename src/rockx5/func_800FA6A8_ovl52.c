#include "types.h"

extern u8 D_80091C44;
extern void func_800132F8(s8 arg);

void func_800FA6A8_ovl52(Actor50* a) {
    if (D_80091C44 == 0) {
        func_800132F8(0x20);
        a->step++;
    }
}
