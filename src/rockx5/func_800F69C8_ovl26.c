#include "types.h"

extern s16 D_8009A0AE;
extern s16 D_8009A0AA;

#define ABS(v) ((v) < 0 ? -(v) : (v))

void func_800F69C8_ovl26(u8* a0) {
    if (a0[2] < 2) {
        if (ABS(D_8009A0AE - *(s16*)(a0 + 0xE)) < 0x11) {
            a0[5] = 1;
            a0[6] = 0;
        }
    } else {
        if (ABS(D_8009A0AA - *(s16*)(a0 + 0xA)) < 0x11) {
            a0[5] = 1;
            a0[6] = 0;
        }
    }
}
