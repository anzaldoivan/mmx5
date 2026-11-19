#include "types.h"
#include "mmx5/graphics.h"

void func_800F27C4_ovl10(u8* obj) {
    if (obj[0x90] == 0) {
        set_animation(obj, 11);
        obj[0x15] = 0x40;
    } else {
        set_animation(obj, 11);
        obj[0x15] = 0;
    }
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = -0x13000;
    obj[6]++;
}
