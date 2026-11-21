#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800534B4(u8* obj) {
    set_animation(obj, 2);
    if (obj[0x84] != 0) {
        *(s32*)(obj + 0x20) = 0x8000;
    } else {
        *(s32*)(obj + 0x20) = -0x8000;
    }
    obj[6]++;
}

#define func_800F27DC_ovl04 func_80053500
#include "shared/func_800F27DC_ovl04.c"
#undef func_800F27DC_ovl04
