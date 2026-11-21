#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define D_8007BD4C D_800FD288_ovl01

#define func_800532E0 func_800F6840_ovl01
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F67E4_ovl28 func_800F687C_ovl01
#include "shared/func_800F67E4_ovl28.c"
#undef func_800F67E4_ovl28

extern void func_800F6C74_ovl01(u8* obj, s32 state);

void func_800F68B8_ovl01(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        if (*(s8*)(obj + 3) != 0) {
            func_800F6C74_ovl01(obj, 0);
        }
        obj[5] = 4;
        obj[6] = 0;
        set_animation(obj, 0);
    } else {
        animate_object(obj);
    }
}

#define D_800EEC60_ovl00 func_800F6928_ovl01
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800F6930_ovl01
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
