#include "types.h"
#include "mmx5/globals.h"

extern u8 D_8009A0B5;
extern void (*D_800FB510_ovl09[])(u8*);

void func_800F8300_ovl09(u8* a0) {
    if (((s8*)a0)[5] != 0 && ((s8*)a0)[0x5C] <= 0) {
        func_8003D29C(0x14, D_8009A0B5);
        a0[0x5C] = 0;
        a0[4] = 2;
        a0[5] = 0;
        a0[6] = 0;
    } else {
        D_800FB510_ovl09[((s8*)a0)[5]](a0);
    }
}

#define D_800FA214_ovl00 D_800FB51C_ovl09

#define func_800EEB64_ovl00 func_800F8388_ovl09
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
