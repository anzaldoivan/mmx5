#include "types.h"

extern u8 D_800C9310;
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_80100104_ovl04(u8* p) {
    if (--p[0x19] == 0) {
        D_800C9310 |= 1;
        p[0x18] = 0x5A;
        p[0x19] = 4;
        p[0x1A] ^= 1;
        D_800D50DE = 0;
        D_8009A42E = 0;
        D_80093E68 = 0;
        p[0x1B] = 0;
    } else {
        D_800D50DE = 0x1F;
        D_8009A42E = 0;
        D_80093E68 = 0;
    }
}
