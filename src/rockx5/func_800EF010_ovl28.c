#include "types.h"

extern s8 D_800D1C1D;
extern void func_800EF064_ovl28(u8* arg0);

void func_800EF010_ovl28(u8* arg0) {
    if (D_800D1C1D >= 2) {
        arg0[5] = 1;
    } else {
        arg0[5] = 0;
    }
    arg0[6] = 0;
    *(s16*)(arg0 + 0x14) = 0;
    *(s16*)(arg0 + 0x18) = 0;
    arg0[4]++;
    func_800EF064_ovl28(arg0);
}
