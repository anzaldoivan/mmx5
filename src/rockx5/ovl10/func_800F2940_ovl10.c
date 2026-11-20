#include "types.h"
#include "mmx5/graphics.h"

void func_800F2940_ovl10(u8* obj) {
    if (obj[0x90] == 0) {
        set_animation(obj, 8);
        obj[0x15] = 0;
    } else {
        set_animation(obj, 8);
        obj[0x15] = 0;
    }
    *(s32*)(obj + 0x20) = -0x13000;
    *(s32*)(obj + 0x24) = 0;
    obj[6]++;
}
