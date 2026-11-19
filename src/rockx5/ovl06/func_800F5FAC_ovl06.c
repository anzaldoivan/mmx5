#include "types.h"

extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];

void func_800F5FAC_ovl06(u8* arg0) {
    arg0[5] = 2;
    arg0[6] = 0;
    arg0[0x88] = 0;
    arg0[0x86] = 0;
    arg0[0x87] = 0;
    *(u8**)(arg0 + 0x54) = D_800FE914_ovl06;
    *(u8**)(arg0 + 0x50) = D_800FE918_ovl06;
    arg0[0x60] = 5;
}
