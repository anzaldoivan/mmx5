#include "types.h"
#include "mmx5/graphics.h"

void func_800F0BFC_ovl12(u8* obj) {
    if (++*(s16*)(obj + 0x7C) == 60) {
        set_animation(obj, 1);
        obj[5] = 4;
        obj[6] = 0;
    }
}
