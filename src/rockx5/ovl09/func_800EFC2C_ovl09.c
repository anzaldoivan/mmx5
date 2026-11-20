#include "types.h"
#include "mmx5/graphics.h"

void func_800EFC2C_ovl09(u8* obj) {
    if (*(s16*)(obj + 0x7E) != 0) {
        *(s16*)(obj + 0x7E) = *(s16*)(obj + 0x7E) - 1;
        return;
    }
    set_animation(obj, 1);
    *(s16*)(obj + 0x7E) = 0x3C;
    obj[6] = 0;
}
