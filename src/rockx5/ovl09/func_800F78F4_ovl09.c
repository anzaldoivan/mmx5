#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_8009A0B5;

void func_800F78F4_ovl09(u8* obj) {
    u8* child = *(u8**)(obj + 0x80);
    s8 v = *(s8*)(child + 0x45);

    if (v == 1) {
        set_animation(child, 4);
        *(*(u8**)(obj + 0x7C) + 0x54) = v;
        *(s16*)(obj + 0x84) = 0;
        ((s32(*)())func_8003D29C)(0x16, D_8009A0B5);
        obj[6]++;
    }
}
