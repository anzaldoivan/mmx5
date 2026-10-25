/* Shared body (DK-5), from the banked draft of func_800FC2E8_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Unk800FC2E8Obj* obj, Unk800F7360Arg* arg) {
    if (obj->unk54 != 0) {
        obj->unk54--;
    } else {
        obj->unk54 = 10;
        obj->unk8 = obj->unk5C->unk18;
        obj->unkC = obj->unk5C->unk1C;
    }
    if (arg->unk9A < 0) {
        obj->unk6++;
    }
}
