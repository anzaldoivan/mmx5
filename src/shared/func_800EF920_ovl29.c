/* Shared body (DK-5), from the banked draft of func_800EF920_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(EntF920* obj) {
    s32 v = obj->velX;
    if ((v >= 0 ? v : -v) <= 0xFFFF || ((obj->flags & 2) && obj->unk15 == 0) ||
        ((obj->flags & 1) && obj->unk15 != 0)) {
        obj->unk60 = 3;
        obj->velX = 0;
        obj->unk28 = 0;
        obj->state = 7;
        obj->substate = 0;
    }
    apply_object_motion(obj);
    animate_object(obj);
}
