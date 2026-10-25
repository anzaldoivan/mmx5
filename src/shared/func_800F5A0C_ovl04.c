/* Shared body (DK-5), from the banked draft of func_800F5A0C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(u8* arg0) {
    u8 t = arg0[0x8D];

    if (t == 0) {
        arg0[7]++;
        return;
    }
    arg0[0x8D] = t - 1;
}
