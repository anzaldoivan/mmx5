/* Shared body (DK-5), from the banked draft of func_800F546C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[6] = 3;
    }
}
