/* Shared body (DK-5), from the banked draft of func_800F5928_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj5928*);

void DEDUP_NAME(Obj5928* obj) {
    if (--obj->timer == 0) {
        obj->timer = 60;
        obj->unk98 = 0;
        obj->state = 3;
        obj->sub = 0;
    }
    DEDUP_CALLEE(obj);
}
