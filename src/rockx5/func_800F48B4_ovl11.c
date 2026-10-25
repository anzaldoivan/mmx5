#include "types.h"

extern s32 func_8003D29C(s32, s32);
extern s16 D_8009A0AA;

void func_800F48B4_ovl11(u8* arg0) {
    if (D_8009A0AA >= 0x798) {
        func_8003D29C(0x1D, 0x40);
        arg0[5] = 5;
    }
}
