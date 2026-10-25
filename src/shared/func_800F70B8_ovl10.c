/* Shared body (DK-5), from the banked draft of func_800F70B8_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern int DEDUP_CALLEE();

void DEDUP_NAME(u8* arg0) {
    (*(u8**)(arg0 + 0x7C))[7] = 1;
    DEDUP_CALLEE(arg0);
}
