/* Shared body (DK-5), from the banked draft of func_800F2258_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_CALLEE(Obj800F2688* obj, s32 a1, s32 a2, s32 a3);

void DEDUP_NAME(Obj800F2688* obj) {
    if (--obj->unk7C == 0) {
        obj->unk7C = 2;
        obj->unk4 = 3;
    } else if (--obj->unk7E == 0) {
        obj->pad0[3] = 0;
        DEDUP_CALLEE(obj, 1, 0x20, 0x20);
        obj->unk7E = 5;
    }
}
