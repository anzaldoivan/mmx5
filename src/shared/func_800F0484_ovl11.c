#include "types.h"
#include "mmx5/graphics.h"

void func_800F0484_ovl11(u8* a0) {
    u8 t;

    t = (*(u8**)(a0 + 0x50))[0x16];
    a0[3] = 0;
    a0[0x16] = t;
    set_animation(a0, 1);
    a0[4] = 1;
    t = (*(u8**)(a0 + 0x50))[7];
    a0[0x54] = 0;
    a0[7] = t;
}
