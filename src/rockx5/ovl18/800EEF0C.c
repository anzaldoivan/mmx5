#include "types.h"
#include "mmx5/globals.h"

#define D_800EEBA0_ovl00 func_800EEF0C_ovl18
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00

#include "shared/func_800EEF2C_ovl18.c"

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
