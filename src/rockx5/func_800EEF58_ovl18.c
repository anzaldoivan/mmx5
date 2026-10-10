#include "types.h"

extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800EEF58_ovl18(u8* arg0) {
    if ((s16)(++*(s16*)(arg0 + 0x16) % 3) == 0) {
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        if (D_800D50DE == 0) {
            arg0[6] = 0;
            arg0[5]++;
        }
    }
}
