#include "types.h"
#include "mmx5/graphics.h"

void func_800F4C80_ovl26(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0xD);
        obj[6]++;
    }
}
