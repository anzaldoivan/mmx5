#include "types.h"

extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800FB4EC_ovl56(u8* arg0) {
    u16 t = ++D_800D50DE;

    D_8009A42E += 0x20;
    D_80093E68 += 0x400;
    if (t >= 0x1F) {
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
