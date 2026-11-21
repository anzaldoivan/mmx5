#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F0CF8_ovl11(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 5);
        *(s16*)(obj + 0x7C) = 0x29;
        obj[6]++;
    }
}
