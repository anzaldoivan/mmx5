#include "types.h"

void func_800F2BD4_ovl07(u8* p) {
    u16 t;

    if (p[0x87] == 0) {
        t = *(u16*)(p + 0x88);
        if (t < 60) {
            p[6]++;
            return;
        }
        *(u16*)(p + 0x88) = t - 1;
    }
}
