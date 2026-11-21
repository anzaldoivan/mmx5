#include "types.h"
#include "mmx5/globals.h"

void func_800F1BF4_ovl20(u8* arg0) {
    func_8002385C(0xD, 0xFF, 0);
    arg0[2]++;
}

#define func_800F1A30_ovl20 func_800F1C30_ovl20
#include "shared/func_800F1A30_ovl20.c"
#undef func_800F1A30_ovl20
