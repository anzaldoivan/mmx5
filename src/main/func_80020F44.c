/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/8001E6E4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

s32 func_80020F44(void* arg0) {
    s8* p = arg0;
    s8 temp_a0;

    if (p[0xC] != 0xC) {
        return 0;
    }
    temp_a0 = p[0x1D];
    if (temp_a0 < 2) {
        return 0;
    }
    return temp_a0 < 0xA;
}
