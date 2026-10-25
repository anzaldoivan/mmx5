/* Shared body (DK-5), from the banked draft of func_800F69E0_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(u8* arg0) {
    u8* src = *(u8**)(arg0 + 0x7C);

    *(u16*)(arg0 + 0xA) = *(u16*)(src + 0xA);
    *(u16*)(arg0 + 0xE) = *(u16*)(src + 0xE);
}
