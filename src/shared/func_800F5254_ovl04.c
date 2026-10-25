/* Shared body (DK-5), from the banked draft of func_800F5254_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj5254*, s32);

void DEDUP_NAME(Obj5254* obj) {
    obj->unk20 = 0xFFFE0000;
    obj->unk7C = 0xD0;
    DEDUP_CALLEE(obj, 3);
    obj->unk6++;
}
