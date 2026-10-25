/* Shared body (DK-5), from the banked draft of func_800F077C_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE();

void DEDUP_NAME(u8* arg0) {
    DEDUP_CALLEE();
    if (*(s8*)(arg0 + 0x45) != 0) {
        arg0[0x80] = 0;
        arg0[5] = 3;
        arg0[6] = 0;
    }
}
