#include "types.h"
#include "mmx5/graphics.h"

void func_800FC7A4_ovl38(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0xE);
        *(s16*)(obj + 0x7C) = 50;
        obj[6]++;
    }
}
