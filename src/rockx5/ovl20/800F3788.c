#include "types.h"
#include "mmx5/globals.h"

void func_800F3788_ovl20(u8* a0) {
    u16 v;

    *(s16*)(a0 + 0x3C) -= 4;
    if (*(s16*)(a0 + 0x3C) < -*(s16*)(a0 + 0x38)) {
        *(s16*)(a0 + 0x3C) = -*(s16*)(a0 + 0x38);
        a0[5]++;
        if (((s8*)a0)[2] == 0) {
            D_800D1C28[1] = 0;
        }
    }
    v = *(u16*)(a0 + 0x3C);
    *(s16*)(a0 + 0x16) = v;
    *(s16*)(a0 + 0x2E) = v;
}

#define D_800EEC60_ovl00 func_800F37E8_ovl20
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define func_800F20C4_ovl20 func_800F37F0_ovl20
#define func_800F2108_ovl20 func_800F3834_ovl20
#define func_800F2190_ovl20 func_800F38BC_ovl20
#include "shared/func_800F20C4_ovl20.c"
#undef func_800F20C4_ovl20
#undef func_800F2108_ovl20
#undef func_800F2190_ovl20
