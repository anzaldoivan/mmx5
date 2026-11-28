#include "types.h"
#include "mmx5/graphics.h"

void func_800479B0(u8* obj) {
    set_animation(obj, 2);
    obj[0x67] = 1;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0xFFFB0000;
    obj[0x5] = 2;
}
