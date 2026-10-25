/* Shared body (DK-5), from the banked draft of func_800F7360_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Unk800F7360Obj* obj, Unk800F7360Arg* arg) {
    if (obj->unk54 != 0) {
        obj->unk54--;
    } else {
        obj->unk54 = 3;
        obj->unk8 = obj->unk5C->unk18;
        obj->unkC = obj->unk5C->unk1C;
    }
    if (arg->unk9A < 0) {
        obj->unk5++;
    }
}
