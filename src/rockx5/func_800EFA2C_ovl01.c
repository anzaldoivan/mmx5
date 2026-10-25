#include "types.h"

extern s32 func_8003D29C(s32, s32);
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800EFA2C_ovl01(u8* p) {
    p[0x19]++;
    if ((u8)(p[0x19] % 5) == 0) {
        D_800D50DE -= 4;
        D_8009A42E -= 0x80;
        D_80093E68 -= 0x1000;
        if (D_800D50DE == 0) {
            func_8003D29C(0x14, 0x40);
            p[5]++;
        }
    }
}
