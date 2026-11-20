#include "types.h"
#include "mmx5/graphics.h"

void func_800F2E38_ovl08(u8* obj) {
    *(u16*)(obj + 0x42) &= 0x7FFF;
    set_animation(obj, 1);
    obj[0x75] = 0;
    obj[6]++;
}
