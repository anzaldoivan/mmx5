#include "types.h"
#include "mmx5/graphics.h"

void func_800F8D54_ovl09(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        set_animation(obj, 1);
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x38000;
        *(s32*)(obj + 0x2C) = 0;
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
}
