/* Shared body (DK-5), from the banked draft of func_800F28B4_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

#define G (*(u8**)0x1F80004C)

void DEDUP_CALLEE(void);

void DEDUP_NAME(void) {
    if (G[0x8A] == 0) {
        DEDUP_CALLEE();
    }
}
