/* Shared body (DK-5), from the banked draft of func_800F02E4_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Ob5*);

void DEDUP_NAME(Ob5* o) {
    DEDUP_CALLEE(o);
    if (o->b45 == 1) {
        o->b6++;
    }
}
