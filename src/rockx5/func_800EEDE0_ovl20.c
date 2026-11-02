#include "types.h"

extern u8 D_800F6DF0_ovl20[];
extern u8 D_800F6DF6_ovl20;
extern u8 D_800F6DF7_ovl20;
extern u8 D_800F6DFB_ovl20;

void func_800EEDE0_ovl20(u8* arg0) {
    D_800F6DF6_ovl20 = 0;
    D_800F6DF7_ovl20 = 0;
    D_800F6DFB_ovl20 = 1;
    D_800F6DF0_ovl20[0] = 0;
    if (arg0[0x4A] & 1) {
        D_800F6DFB_ovl20 = 2;
        D_800F6DF0_ovl20[1] = 1;
    }
    if (arg0[0x4A] & 4) {
        D_800F6DF0_ovl20[D_800F6DFB_ovl20++] = 3;
    }
    if (arg0[0x4A] & 2) {
        D_800F6DF0_ovl20[D_800F6DFB_ovl20++] = 2;
    }
    if (arg0[0x79] < 5 || (arg0[0xCB] & 0x80)) {
        D_800F6DF0_ovl20[D_800F6DFB_ovl20++] = 5;
    }
    if (arg0[0x4A] & 8) {
        D_800F6DF0_ovl20[D_800F6DFB_ovl20++] = 4;
    }
}
