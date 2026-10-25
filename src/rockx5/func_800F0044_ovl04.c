#include "types.h"

extern s32 func_8003D29C(s32, s32);
extern s16 D_8009A0AA;

void func_800F0044_ovl04(u8* arg0) {
    if (D_8009A0AA >= 0x12EE) {
        func_8003D29C(0x14, 0x40);
        arg0[6]++;
    }
}
