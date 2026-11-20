#include "types.h"
#include "mmx5/graphics.h"

void func_800F454C_ovl06(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        set_animation(obj, 2);
        obj[6] = 1;
    }
}
