#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F2B6C_ovl01(u8* obj) {
    animate_object(obj);
    move_object(obj);
    set_animation(obj, 3);
    obj[5] = 5;
    obj[6] = 0;
    *(s32*)(obj + 0x2C) = 0x1800;
    *(s32*)(obj + 0x24) = 0x2E000;
    *(s32*)(obj + 0x28) = 0;
    obj[0x67] = 1;
}
