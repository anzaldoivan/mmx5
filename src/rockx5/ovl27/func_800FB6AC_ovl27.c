#include "types.h"

extern s8 D_8009A0A2;
extern u8 D_800D1C49;
extern u8 D_800FDB90_ovl27[];

void func_800FB6AC_ovl27(u8* a0) {
    if (*(u16*)(a0 + 0x88) & 1) {
        a0[3] = 0;
    } else {
        a0[3] = 1;
    }
    if (--*(s16*)(a0 + 0x88) == 0) {
        a0[3] = 1;
        if (D_8009A0A2 == 0 && D_800D1C49 == 3) {
            *(s32*)(a0 + 0x50) = 0;
        } else {
            *(u8**)(a0 + 0x50) = D_800FDB90_ovl27;
        }
        a0[7]++;
    }
}
