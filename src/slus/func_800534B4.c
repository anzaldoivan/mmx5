#include "types.h"
#include "mmx5/graphics.h"

void func_800534B4(u8* obj) {
    set_animation(obj, 2);
    if (obj[0x84] != 0) {
        *(s32*)(obj + 0x20) = 0x8000;
    } else {
        *(s32*)(obj + 0x20) = -0x8000;
    }
    obj[6]++;
}
