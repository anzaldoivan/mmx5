/* Shared body (DK-5), from the banked draft of func_800F0820_ovl24 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(s8 arg);

void DEDUP_NAME(u8* arg0) {
    DEDUP_CALLEE(8);
    arg0[2]++;
}
