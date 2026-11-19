#include "types.h"
#include "mmx5/graphics.h"

void func_800F1934_ovl10(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        set_animation(obj, 2);
        obj[6]++;
    }
}
