#include "types.h"
#include "mmx5/globals.h"

#define D_8007BD4C D_800FD2AC_ovl01

#define func_800532E0 func_800F6AFC_ovl01
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

extern void func_800F6C74_ovl01(u8* obj, s32 state);

void func_800F6B38_ovl01(u8* obj) {
    animate_object(obj);
    if (D_8009A0AA >= *(s16*)(obj + 0xA) - 0x5C) {
        *(s16*)(obj + 0x7C) = 0x5A;
        func_800F6C74_ovl01(obj, 1);
        obj[6]++;
    }
}

#define func_800F6AB0_ovl01 func_800F6B98_ovl01
#include "shared/func_800F6AB0_ovl01.c"
#undef func_800F6AB0_ovl01
