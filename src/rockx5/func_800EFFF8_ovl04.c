#include "types.h"

extern s32 func_8003D29C(s32, s32);
extern s8 D_8009A0A5;

void func_800EFFF8_ovl04(u8* arg0) {
    if (D_8009A0A5 == 0x14) {
        func_8003D29C(0x1D, 0x40);
        arg0[6]++;
    }
}
