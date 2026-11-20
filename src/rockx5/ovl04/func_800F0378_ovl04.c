#include "types.h"

extern s8 D_800D1C1D;
extern s16 D_80102FD4_ovl04;

void func_800F0378_ovl04(u8* a0) {
    a0[0x36] = 0x30;
    *(s16*)(a0 + 0x34) = 0x62B1;
    *(s8*)(a0 + 0x37) = -1;
    *(s16*)(a0 + 0xA) = 0;
    *(s16*)(a0 + 0xE) = 0;
    a0[0] |= 0x11;
    if (D_800D1C1D < 6) {
        if (D_800D1C1D < 4) {
            D_80102FD4_ovl04 = 0;
        } else {
            D_80102FD4_ovl04 = 0xF0;
        }
    } else {
        D_80102FD4_ovl04 = 0;
    }
    a0[3] = 0;
    a0[4]++;
}
