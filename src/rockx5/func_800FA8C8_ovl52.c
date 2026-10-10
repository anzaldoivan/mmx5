#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern s32 D_8009A420;
extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u16 D_8009A42E;

void func_800FA8C8_ovl52(u8* arg0) {
    if (!(D_8009A420 & 1)) {
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
    }
    if (D_800D50DE == 0) {
        func_8002385C(0x47, 0xFF, 0);
        arg0[1]++;
    }
}
