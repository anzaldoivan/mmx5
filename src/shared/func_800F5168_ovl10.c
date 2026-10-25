/* Shared body (DK-5), from the banked draft of func_800F5168_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj5CF0*);

void DEDUP_NAME(Obj5CF0* obj) {
    DEDUP_CALLEE(obj);
    if (--obj->unk7C == 0) {
        obj->unk20 = 0;
        obj->unk28 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0x3800;
        obj->state = 2;
    }
}
