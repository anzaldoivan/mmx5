#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F443C_ovl26(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0x1A);
        obj[6]++;
    }
}
