#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F26FC_ovl04(u8* obj) {
    D_1F80004C.bytes[0x84] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    switch (((s8*)obj)[2]) {
    case 0:
        set_animation(obj, 0);
        obj[6] = 1;
        break;
    case 1:
        set_animation(obj, 1);
        obj[6] = 2;
        break;
    case 2:
    case 3:
        set_animation(obj, 1);
        obj[6] = 3;
        break;
    }
    *(s16*)(obj + 0x7C) = 0xB4;
}

#define func_800F1818_ovl10 func_800F27AC_ovl04
#include "shared/func_800F1818_ovl10.c"
#undef func_800F1818_ovl10

#include "shared/func_800F27DC_ovl04.c"
