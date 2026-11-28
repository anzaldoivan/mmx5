#include "types.h"
#include "mmx5/graphics.h"

void func_800533B4(u8* obj) {
    s8 state = ((s8*)obj)[2];

    if (state == 1) {
        obj[6] = state;
        return;
    }
    set_animation(obj, 1);
    obj[6] = 2;
}

#define D_800EEC60_ovl00 func_800533FC
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

void func_80053404(u8* a0) {
    if (*(s8*)(a0 + 0x45) != 0) {
        if (a0[0x84] == 0) {
            a0[0x15] = 0;
        } else {
            a0[0x15] = 0x40;
        }
        a0[0x5] = 4;
        a0[0x6] = 0;
    }
}
