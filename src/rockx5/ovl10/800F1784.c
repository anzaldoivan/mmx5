#include "types.h"
#include "mmx5/system.h"

void func_800F1784_ovl10(Obj* arg0) {
    arg0->timer = 0xB4;
    if ((random_byte() & 3) == 0) {
        arg0->step = 1;
    } else {
        arg0->step = 2;
    }
}

extern s32 func_800F1B88_ovl10(u8* e);

void func_800F17C4_ovl10(u8* e) {
    if (func_800F1B88_ovl10(e) != 0) {
        e[5] = 4;
        e[6] = 0;
    } else if (--*(s16*)(e + 0x7C) == -1) {
        e[5] = 3;
        e[6] = 0;
    }
}

#include "shared/func_800F1818_ovl10.c"

#define D_8007BD4C D_800FB6F8_ovl10

#define func_800532E0 func_800F1848_ovl10
#include "shared/func_800532E0.c"
#undef func_800532E0
