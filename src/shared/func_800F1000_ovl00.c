/* Shared body (DK-5), from the banked draft of func_800F1000_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(u8* a0) {
    u8* p = *(u8**)(a0 + 0x50);

    a0[0x47] = *(s16*)(p + 0x8A) / 16 + 0x12;
    *(u16*)(a0 + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(a0 + 0xE) = *(u16*)(p + 0xE);
}
