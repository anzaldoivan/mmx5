#include "types.h"
#include "mmx5/graphics.h"

void func_8004795C(u8* obj) {
    set_animation(obj, 1);
    obj[0x67] = 0;
    if (obj[0x15] != 0) {
        *(s32*)(obj + 0x20) = 0x50000;
    } else {
        *(s32*)(obj + 0x20) = -0x50000;
    }
    *(s32*)(obj + 0x24) = 0;
    obj[0x5] = 1;
}
