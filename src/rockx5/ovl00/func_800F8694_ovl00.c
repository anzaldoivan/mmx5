#include "types.h"
#include "mmx5/graphics.h"

void func_800F8694_ovl00(u8* obj) {
    set_animation(obj, 0);
    obj[0x8F] = 0x5A;
    obj[6]++;
}
