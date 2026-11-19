#include "types.h"

extern s8 D_800D1C26;

void func_800F4CD4_ovl11(u8* p) {
    if (D_800D1C26 == 1) {
        p[0x87] = 3;
        p[0x84] = 0x78;
        p[0x83] = 0x1E;
        p[0x6] = 0;
    }
}
