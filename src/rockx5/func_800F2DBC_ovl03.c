#include "types.h"

extern s16 D_800F9D0C_ovl03[][2];
extern s16 D_8009A0AA;

void func_800F2DBC_ovl03(u8* a0) {
    u8 b;
    s32 t;

    b = a0[0x7C];
    if (b & 1) {
        b &= 0xFE;
    } else {
        b |= 1;
    }
    t = D_800F9D0C_ovl03[b][0];
    if (D_8009A0AA < t - 40 || t + 40 < D_8009A0AA) {
        a0[5] = 1;
        a0[6] = 0;
    }
}
