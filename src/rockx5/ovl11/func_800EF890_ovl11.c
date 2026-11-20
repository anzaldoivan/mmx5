#include "types.h"

extern void func_800EF5A0_ovl11(u8* arg0);
extern void func_800EFC54_ovl11(s32);
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800EF890_ovl11(u8* p) {
    if (p[0x19] != 0) {
        p[0x19]--;
        return;
    }
    if (--p[0x1A] == 0) {
        func_800EF5A0_ovl11(p);
        p[0x1A] = 7;
    }
    p[0x18]++;
    if ((u8)(p[0x18] % 5) == 0) {
        D_800D50DE -= 2;
        D_8009A42E -= 0x40;
        D_80093E68 -= 0x800;
        if (D_800D50DE == 0) {
            p[4]++;
            func_800EFC54_ovl11(0);
        }
    }
}
