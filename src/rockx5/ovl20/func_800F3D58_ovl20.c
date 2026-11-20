#include "types.h"
#include "mmx5/globals.h"

extern D1C00_800F3D58 D_800D1C00;
extern s32 D_800F51F0_ovl20[];

void func_800F3D58_ovl20(u8* a0) {
    if (D_800F51F0_ovl20[((s8*)a0)[2]] & D_800D1C00.mask[D_800D1C00.idx]) {
        func_8002D89C(a0);
    } else {
        a0[3] = 0;
    }
}
