#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

void func_800EFBB4_ovl09(u8* obj) {
    if (*(s16*)(obj + 0x7E) != 0) {
        ((s32(*)())move_object)(obj);
        *(s16*)(obj + 0x7E) -= 1;
    } else {
        set_animation(obj, 1);
        *(s16*)(obj + 0x7E) = 0x40;
        obj[6] += 1;
        *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
    }
}

void func_800EFC2C_ovl09(u8* obj) {
    if (*(s16*)(obj + 0x7E) != 0) {
        *(s16*)(obj + 0x7E) = *(s16*)(obj + 0x7E) - 1;
        return;
    }
    set_animation(obj, 1);
    *(s16*)(obj + 0x7E) = 0x3C;
    obj[6] = 0;
}
