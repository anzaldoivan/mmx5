#include "types.h"

#define func_800F0820_ovl24 func_800F08EC_ovl24
#include "shared/func_800F0820_ovl24.c"
#undef func_800F0820_ovl24

extern s8 D_8009A424;

void func_800F0920_ovl24(u8* arg0) {
    if (D_8009A424 == 0) {
        arg0[1] = 10;
        arg0[2] = 0;
    }
}
