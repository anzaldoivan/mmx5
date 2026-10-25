/* Shared body (DK-5), from the banked draft of func_800F5A88_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s8 D_8009A1F6;

void DEDUP_NAME(void) {
    if (D_8009A1F6 != 0) {
        D_1F80004C.bytes[0x87] = 1;
    }
}
