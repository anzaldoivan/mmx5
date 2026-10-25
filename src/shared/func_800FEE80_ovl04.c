/* Shared body (DK-5), from the banked draft of func_800FEE80_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern int DEDUP_CALLEE();
extern u8 D_800D1C00[];

void DEDUP_NAME(void) {
    D_800D1C00[0x26] |= 4;
    DEDUP_CALLEE();
}
