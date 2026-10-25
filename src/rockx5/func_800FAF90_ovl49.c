#include "types.h"

extern s32 D_8009A420;
extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u16 D_8009A42E;

void func_800FAF90_ovl49(u8* arg0) {
    if (D_8009A420 & 1) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
    }
    if (D_800D50DE == 0x1F) {
        arg0[1]++;
    }
}
