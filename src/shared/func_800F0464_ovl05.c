#include "types.h"
#include "mmx5/graphics.h"

void func_800F0464_ovl05(u8* obj) {
    set_animation(obj, 4);
    *(u8*)(obj + 0x67) = 1;
    *(s32*)(obj + 0x20) = 0x10000;
    *(s32*)(obj + 0x24) = -0x2000;
    *(s32*)(obj + 0x2C) = 0x200;
    obj[6]++;
}
