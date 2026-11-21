#include "types.h"
#include "mmx5/globals.h"

void func_800F1DC8_ovl20(u8* arg0) {
    func_8002385C(0x10, 0xFF, 0);
    arg0[2]++;
}

#define func_800F1A30_ovl20 func_800F1E04_ovl20
#include "shared/func_800F1A30_ovl20.c"
#undef func_800F1A30_ovl20
