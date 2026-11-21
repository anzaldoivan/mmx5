#include "types.h"
#include "mmx5/graphics.h"

void func_800F8694_ovl00(u8* obj) {
    set_animation(obj, 0);
    obj[0x8F] = 0x5A;
    obj[6]++;
}

#define D_800FA2E0_ovl29 D_800FB448_ovl00

#define func_800F4460_ovl29 func_800F86D0_ovl00
#include "shared/func_800F4460_ovl29.c"
#undef func_800F4460_ovl29
