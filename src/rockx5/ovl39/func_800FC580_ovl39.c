#include "types.h"

extern u8 D_800C9310;
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800FC580_ovl39(u8* arg0) {
    if ((s16)(++*(s16*)(arg0 + 0x7C) % 5) == 0) {
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        if (D_800D50DE == 0) {
            D_800C9310 = 1;
            arg0[6]++;
        }
    }
}
