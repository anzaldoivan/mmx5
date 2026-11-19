#include "types.h"

extern u8 D_800D1C00[];
extern u8 D_8009A169;

void func_800F0254_ovl24(u8* a0) {
    u8* p = D_800D1C00;
    u8* q;

    if (((s8*)p)[0x27] == 0 && !((D_8009A169 >> (((s8*)p)[0x26] - 1)) & 1)) {
        a0[2] = 1;
        return;
    }
    q = D_800D1C00;
    if (q[0xA1] != q[0xCC]) {
        a0[2] = 5;
    } else {
        a0[1] = 3;
        a0[2] = 0;
    }
}
