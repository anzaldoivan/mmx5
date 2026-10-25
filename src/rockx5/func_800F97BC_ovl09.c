#include "types.h"

extern u8 D_800FB5AC_ovl09[];
extern u8 D_800FB5A8_ovl09[];

void func_800F97BC_ovl09(u8* a0) {
    if (*(s8*)(a0 + 0x45) == 1) {
        *(u8**)(a0 + 0x50) =
            (*(s8*)(a0 + 2) == 0) ? D_800FB5AC_ovl09 : D_800FB5A8_ovl09;
    }
    if (*(s8*)(*(u8**)(a0 + 0x7C) + 5) != 3) {
        a0[4] = 2;
        a0[3] = 0;
    }
}
