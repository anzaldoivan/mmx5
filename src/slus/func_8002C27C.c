#include "types.h"

extern s32 D_80093DD0[];
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u16 D_800D50DE;

void func_8002C27C(void) {
    s32 i;

    D_80093E68 = 0;
    D_8009A42E = 0;
    D_800D50DE = 0;
    for (i = 0; i < 16; i++) {
        D_80093DD0[i] = -1;
    }
}
