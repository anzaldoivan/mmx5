#include "types.h"

extern void func_80044DD0(s32 a0);
extern u8 D_80091C44;

void func_800FAEF8_ovl01(u8* arg0) {
    if (D_80091C44 == 0) {
        *(s16*)(arg0 + 0x7C) = 4;
        *(s16*)(arg0 + 0x7E) = 3;
        arg0[6] = 7;
        func_80044DD0(7);
    }
}
