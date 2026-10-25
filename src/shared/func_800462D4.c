/* Shared body (DK-5), from the banked draft of func_800462D4 by tools/wave/gate.py rescan. */
#include "types.h"

extern int DEDUP_CALLEE();
extern u8 D_8009A0A0[];

void DEDUP_NAME(s8* e) {
    D_8009A0A0[0x98]--;
    DEDUP_CALLEE(e);
}
