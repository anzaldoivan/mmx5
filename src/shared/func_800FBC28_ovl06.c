/* Shared body (DK-5), from the banked draft of func_800FBC28_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) != 0) {
        arg0[4] = 2;
    }
}
