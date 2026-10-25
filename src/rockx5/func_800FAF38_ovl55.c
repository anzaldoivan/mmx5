#include "types.h"

extern s32 D_8009A420;
extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u16 D_8009A42E;

void func_800FAF38_ovl55(u8* arg0) {
    if (D_8009A420 % 3 == 0) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
    }
    if (D_800D50DE >= 0x1F) {
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
