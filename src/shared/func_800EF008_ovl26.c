#include "types.h"
#include "mmx5/globals.h"

void func_800EF008_ovl26(u8* arg0) {
    if ((s16)(++*(s16*)(arg0 + 0x16) % 3) == 0) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
        if (D_800D50DE >= 0x1F) {
            *(s16*)(arg0 + 0x18) = 0;
            arg0[6] = 0;
            arg0[5]++;
        }
    }
}
