#include "types.h"

void func_800F2AC8_ovl07(u8* p) {
    u16 t = *(u16*)(p + 0x88);

    if (t == 0) {
        p[5] = 2;
        p[6] = 0;
        return;
    }
    *(u16*)(p + 0x88) = t - 1;
}
