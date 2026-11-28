#include "types.h"
#include "mmx5/globals.h"

void func_800FB484_ovl49(u8* arg0) {
    u16 t = ++D_800D50DE;

    D_8009A42E += 0x20;
    D_80093E68 += 0x400;
    if (t == 0x1F) {
        func_8002385C(0x36, 0xFF, 0);
        arg0[1]++;
    }
}
