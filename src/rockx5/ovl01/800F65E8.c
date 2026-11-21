#include "types.h"
#include "mmx5/globals.h"

#define D_8007BD4C D_800FD278_ovl01

#define func_800532E0 func_800F65E8_ovl01
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F6624_ovl01.c"

void func_800F6678_ovl01(u8* p) {
    s32 v;

    switch (((s8*)p)[2]) {
    case 0x30:
        v = 4;
        break;
    case 0:
    case 0x40:
        v = 3;
        break;
    default:
        return;
    }
    p[5] = v;
    p[6] = 0;
}
