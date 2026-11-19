#include "types.h"
#include "mmx5/graphics.h"

void func_800F1330_ovl09(u8* obj) {
    set_animation(obj, 1);
    *(s16*)(obj + 0x7E) = 0x14;
    obj[6]++;
}
