/* Shared body (DK-5), from the banked draft of func_80046A6C by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern int DEDUP_CALLEE();

void DEDUP_NAME(void* a0) {
    D_8009A0A0[0x98]--;
    D_8009A0A0[0x99]--;
    DEDUP_CALLEE(a0);
}
