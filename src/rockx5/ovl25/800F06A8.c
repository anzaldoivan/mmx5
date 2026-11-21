#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s8 D_800D1C01;

void func_800F06A8_ovl25(u8* arg0) {
    if (D_800D1C01 >= 7) {
        arg0[4]++;
    }
}

#define D_800EEBA0_ovl00 func_800F06D8_ovl25
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
