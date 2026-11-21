#include "types.h"
#include "mmx5/graphics.h"

void func_800F0D2C_ovl04(u8* obj) {
    set_animation(obj, 11);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0x50000;
    obj[6]++;
}
