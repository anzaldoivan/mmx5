#include "types.h"

void func_800F6678_ovl01(u8* p) {
    s32 v;

    switch (((s8*)p)[2]) {
    case 0x30:
        v = 4;
        break;
    case 0:
    case 0x40:
        v = 3;
        break;
    default:
        return;
    }
    p[5] = v;
    p[6] = 0;
}
