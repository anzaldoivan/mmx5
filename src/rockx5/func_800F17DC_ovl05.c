#include "types.h"

void func_800F17DC_ovl05(u8* a0) {
    s8 v;

    if (--*(s16*)(a0 + 0x88) == -1) {
        v = ((s8*)a0)[2];
        if (v >= 0) {
            if (v < 3) {
                *(s16*)(a0 + 0x88) = 30;
            } else if (v < 6) {
                *(s16*)(a0 + 0x88) = 60;
            }
        }
        a0[6]++;
    }
}
