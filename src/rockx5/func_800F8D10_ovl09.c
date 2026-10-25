#include "types.h"

extern u8 D_800FB2D0_ovl09[];
extern u8 D_800FB2DC_ovl09[];

void func_800F8D10_ovl09(u8* a0) {
    a0[0x62] = 2;
    a0[0x60] = 8;
    *(u8**)(a0 + 0x50) = D_800FB2D0_ovl09;
    *(u8**)(a0 + 0x68) = D_800FB2DC_ovl09;
    *(u16*)(a0 + 0x42) &= 0x7FFF;
    a0[6]++;
}
