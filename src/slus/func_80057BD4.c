#include "types.h"

extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_80057BD4(u8* p) {
    (*(u16*)(p + 0x14))++;
    if (*(u16*)(p + 0x14) % 5 == 0) {
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        if (D_800D50DE == 0) {
            p[4]++;
        }
    }
}
