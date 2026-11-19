#include "types.h"

extern s8 D_800F5F7B_ovl24;
extern s8 D_800F5F7C_ovl24;
extern s8 D_800F5F7D_ovl24;
extern s8 D_800F5F7E_ovl24;

s32 func_800EFC48_ovl24(u8* a0);

void func_800F03B8_ovl24(u8* a0) {
    D_800F5F7B_ovl24 = 0;
    D_800F5F7C_ovl24 = 0;
    D_800F5F7D_ovl24 = 0;
    D_800F5F7E_ovl24 = func_800EFC48_ovl24(a0);
    a0[2]++;
}
