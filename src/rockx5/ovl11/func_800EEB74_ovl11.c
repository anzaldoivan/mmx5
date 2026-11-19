#include "types.h"

void func_800EEACC_ovl11(u8* a0);
extern s8 D_8009A243;
extern s8 D_800D1C1D;

void func_800EEB74_ovl11(u8* a0) {
    *(s32*)(a0 + 0x14) = 0x18000;
    a0[4]++;
    func_800EEACC_ovl11(a0);
    if (D_800D1C1D == 3) {
        D_8009A243 = 6;
    }
}
