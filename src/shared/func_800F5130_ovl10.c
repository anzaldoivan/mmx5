#include "types.h"
#include "mmx5/graphics.h"

void func_800F5130_ovl10(u8* obj) {
    set_animation(obj, 0x13);
    *(s16*)(obj + 0x7C) = 0x3C;
    obj[6] = 1;
}
