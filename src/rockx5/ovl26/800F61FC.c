#include "types.h"
#include "mmx5/globals.h"

#define D_8007BD4C D_800FA244_ovl26

#define func_800532E0 func_800F61FC_ovl26
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

void func_800F6238_ovl26(u8* obj) {
    animate_object(obj);
    if ((*(u8**)(obj + 0x7C))[0x93] == 0) {
        obj[4] = 2;
    }
}
