/* Shared body (DK-5), from the banked draft of func_800F074C_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj074C*, s32);

void DEDUP_NAME(Obj074C* obj) {
    if (obj->unk88 != 0) {
        obj->unk8C = 1;
        obj->unk80 = 2;
        DEDUP_CALLEE(obj, 1);
        obj->unk60 = 4;
        obj->unk84 = 1;
        obj->state5 = 5;
        obj->state6 = 0;
    }
}
