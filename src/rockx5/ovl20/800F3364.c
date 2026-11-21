#include "types.h"
#include "mmx5/globals.h"

void func_800F3364_ovl20(u8* arg0) {
    *(s16*)(arg0 + 0x38) += 4;
    if (*(s16*)(arg0 + 0x38) >= *(s16*)(arg0 + 0x3C)) {
        *(u16*)(arg0 + 0x38) = *(u16*)(arg0 + 0x3C);
        arg0[6]++;
    }
}

void func_800F33A4_ovl20(u8* arg0) {
    s32 v;

    v = *(u16*)(arg0 + 0x3A) + 3;
    *(s16*)(arg0 + 0x3A) = v;
    if ((s16)v >= *(s16*)(arg0 + 0x3E)) {
        *(s16*)(arg0 + 0x3A) = *(s16*)(arg0 + 0x3E);
        arg0[6]++;
        if (((s8*)arg0)[2] == 0) {
            D_800D1C28[1] = 0;
        }
    }
}

#define D_800EEC60_ovl00 func_800F33F4_ovl20
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
