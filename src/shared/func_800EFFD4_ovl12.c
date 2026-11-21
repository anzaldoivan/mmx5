#include "types.h"
#include "mmx5/graphics.h"

void func_800EFFD4_ovl12(u8* obj) {
    if (*(s8*)(obj + 7) != 0) {
        set_animation(obj, 3);
        obj[6]++;
    }
}
