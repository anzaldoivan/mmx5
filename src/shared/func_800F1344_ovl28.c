/* Shared body (DK-5), from the banked draft of func_800F1344_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_CALLEE();

void DEDUP_NAME(Obj* arg0) {
    if (D_1F80004C.scr1344->unk82 < 9) {
        DEDUP_CALLEE();
        arg0->step -= 2;
    } else {
        arg0->step++;
    }
}
