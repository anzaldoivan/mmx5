/* Shared body (DK-5), from the banked draft of func_800F5254_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj5254* obj) {
    obj->unk20 = 0xFFFE0000;
    obj->unk7C = 0xD0;
    DEDUP_CALLEE(obj, 3);
    obj->unk6++;
}
