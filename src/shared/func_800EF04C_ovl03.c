/* Shared body (DK-5), from the banked draft of func_800EF04C_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(u8* arg0) {
    if (*(s8*)(arg0 + 0x67) == 0 && !(arg0[0x70] & 8)) {
        arg0[5] = 3;
        arg0[6] = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x2C) = 0x2000;
        arg0[0x67] = 1;
    }
}
