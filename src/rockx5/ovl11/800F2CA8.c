#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F2CA8_ovl11(u8* obj) {
    animate_object(obj);
    if (++D_1F80004C.bytes[0x81] == 60) {
        set_animation(obj, 1);
        obj[5] = 2;
        obj[6] = 0;
    }
}

#define D_8007BD4C D_800F9B74_ovl11

#define func_800532E0 func_800F2D0C_ovl11
#include "shared/func_800532E0.c"
#undef func_800532E0
