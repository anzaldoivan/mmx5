#include "types.h"

extern X4_BackgroundObj D_8009A24C[3];

void func_800EEDA8_ovl02(u8* a0) {
    if (++*(s16*)(a0 + 0x14) >= 0xC9) {
        D_8009A24C[0].unk3 = 1;
        *(s16*)(a0 + 0x14) = 0;
        a0[4]++;
    }
}
