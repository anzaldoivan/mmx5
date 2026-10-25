/* Shared body (DK-5), from the banked draft of func_800F0658_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj0658*, s32);

void DEDUP_NAME(Obj0658* obj) {
    obj->unk24 = 0;
    obj->unk28 = 0;
    obj->unk2C = 0;
    if (obj->unk15 != 0) {
        obj->unk20 = 0x20000;
        obj->unk6 = 2;
    } else {
        obj->unk20 = -0x20000;
        obj->unk6 = 1;
    }
    DEDUP_CALLEE(obj, 0);
}
