#include "types.h"
#include "mmx5/graphics.h"

void func_800F029C_ovl05(u8* obj) {
    obj[0x67] = 1;
    set_animation(obj, 3);
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0x400;
    obj[6]++;
}
