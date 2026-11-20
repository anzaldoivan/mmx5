#include "types.h"
#include "mmx5/graphics.h"

void func_800F2FE8_ovl08(u8* obj) {
    set_animation(obj, 4);
    obj[0x16] = 0x20;
    obj[3] = 0;
    obj[0x15] = 0;
    obj[4] = 1;
    obj[5] = 0;
    obj[6] = 0;
}
