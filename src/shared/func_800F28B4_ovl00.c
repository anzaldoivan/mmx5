/* Shared body (DK-5), from the banked draft of func_800F28B4_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes
void DEDUP_CALLEE(void);

void DEDUP_NAME(void) {
    if (G[0x8A] == 0) {
        DEDUP_CALLEE();
    }
}
