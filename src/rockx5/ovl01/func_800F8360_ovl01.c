#include "types.h"
#include "mmx5/graphics.h"

void func_800F8360_ovl01(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        set_animation(obj, 3);
        obj[6]++;
    }
}
