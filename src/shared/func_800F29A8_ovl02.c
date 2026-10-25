/* Shared body (DK-5), from the banked draft of func_800F29A8_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_NAME(u8* arg0) {
    if (*(signed char*)(arg0 + 0x45) == 1) {
        D_1F80004C.scr82->flags82 = 2;
        arg0[6]++;
    }
}
