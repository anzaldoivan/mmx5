#include "types.h"

extern u8 D_800D1C2A;
extern u8 D_800F6DF0_ovl20[];
extern u8 D_800F6DF6_ovl20;
extern u8 D_800F6DF7_ovl20;

void func_800F111C_ovl20(u8* arg0) {
    u8 v = D_800F6DF7_ovl20;

    D_800F6DF6_ovl20 = v;
    D_800D1C2A = D_800F6DF0_ovl20[(s8)v];
    arg0[2]++;
}
