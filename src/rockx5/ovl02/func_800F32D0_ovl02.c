#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F32D0_ovl02(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 3);
        obj[5] = 4;
        obj[6] = 0;
        obj[0x60] = 0x7F;
    }
}
