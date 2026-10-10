/* Shared body (DK-5), from the banked draft of func_8004B1AC by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern int DEDUP_CALLEE();

void DEDUP_NAME(s8* e) {
    if (e[2] == 0) {
        D_8009A0A0[0x98]--;
        D_8009A0A0[0x99]--;
    }
    DEDUP_CALLEE(e);
}
