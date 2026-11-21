#include "types.h"
#include "mmx5/graphics.h"

void func_800F8264_ovl01(u8* obj) {
    set_animation(obj, 0);
    *(s16*)(obj + 0x7C) = 90;
    obj[6]++;
}

#define func_800F1818_ovl10 func_800F82A0_ovl01
#include "shared/func_800F1818_ovl10.c"
#undef func_800F1818_ovl10
