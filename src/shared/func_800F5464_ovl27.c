/* Shared body (DK-5), from the banked draft of func_800F5464_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"

s32 DEDUP_CALLEE(Obj800F2688* obj, s32 a1, s32 a2, s32 a3);

void DEDUP_NAME(Obj800F2688* obj) {
    if (--obj->unk7C == 0) {
        obj->unk4 = 2;
    } else if (--obj->unk7E == 0) {
        DEDUP_CALLEE(obj, 1, 0x20, 0x20);
        obj->unk7E = 5;
    }
}
