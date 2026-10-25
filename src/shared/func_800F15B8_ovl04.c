/* Shared body (DK-5), from the banked draft of func_800F15B8_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* DEDUP_CALLEE();

void DEDUP_NAME(u8* o, u8 arg1) {
    u8* c;

    c = DEDUP_CALLEE();
    if (c != 0) {
        c[0] = 0x41;
        c[1] = 3;
        c[2] = arg1;
        *(u16*)(c + 0xA) = *(u16*)(o + 0xA);
        *(u16*)(c + 0xE) = *(u16*)(o + 0xE);
        c[0x15] = o[0x15];
    }
}
