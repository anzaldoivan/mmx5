#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F2620_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 1);
        obj[5] = 3;
        obj[6] = 0;
    }
    animate_object(obj);
}
