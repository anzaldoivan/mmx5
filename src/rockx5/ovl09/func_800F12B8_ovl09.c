#include "types.h"
#include "mmx5/graphics.h"

void func_800F12B8_ovl09(u8* obj) {
    set_animation(obj, 0);
    *(s16*)(obj + 0x7C) = 0x78;
    obj[6]++;
}
