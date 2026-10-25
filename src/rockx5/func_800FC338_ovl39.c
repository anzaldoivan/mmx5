#include "types.h"

extern void func_8003D29C(s32, s32);
extern s16 D_8009A0AA;

void func_800FC338_ovl39(u8* a0) {
    if (D_8009A0AA >= 0x1211) {
        func_8003D29C(0x1D, 0);
    } else {
        func_8003D29C(0x1D, 0x40);
    }
    a0[6]++;
}
