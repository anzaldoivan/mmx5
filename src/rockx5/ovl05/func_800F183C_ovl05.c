#include "types.h"

void func_800F183C_ovl05(u8* arg0) {
    s32 t;

    t = *(u16*)(arg0 + 0x88) - 1;
    *(u16*)(arg0 + 0x88) = t;
    if ((s16)t == -1) {
        arg0[6]++;
        return;
    }
    if (t & 1) {
        arg0[0x91] = 1;
        return;
    }
    arg0[0x91] = 2;
}
