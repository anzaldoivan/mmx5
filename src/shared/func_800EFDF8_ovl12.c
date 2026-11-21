#include "types.h"
#include "mmx5/graphics.h"

void func_800EFDF8_ovl12(u8* obj) {
    set_animation(obj, 1);
    obj[0x85] = 0x3C;
    obj[6]++;
}
