#include "types.h"

extern D1C00_80019DF0 D_800D1C00;

void func_80019DF0(u8* a0) {
    s32 idx = (s8)(((s8*)a0)[2] / 3);
    s32 v = D_800D1C00.f1B8[idx];

    if (idx != 0) {
        v = -v;
    }
    if (v < 0) {
        a0[0x47] = 14;
        a0[3] = 1;
    } else {
        a0[3] = 0;
    }
}
