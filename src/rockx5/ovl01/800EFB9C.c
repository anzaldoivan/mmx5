#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800EFB9C_ovl01(u8* arg0) {
    arg0[0x18] = 0;
    arg0[0x19] = 0;
    arg0[4]++;
}

extern void func_800EFC40_ovl01();

void func_800EFBB4_ovl01(u8* p) {
    p[0x19]++;
    p[0x18] = (p[0x18] + 1) & 3;
    if (p[0x18] == 0) {
        func_800EFC40_ovl01();
    }
    if (p[0x19] > 120) {
        p[4]++;
    }
}

#define D_800EEBA0_ovl00 func_800EFC20_ovl01
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
