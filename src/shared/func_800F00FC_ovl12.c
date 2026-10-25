/* Shared body (DK-5), from the banked draft of func_800F00FC_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj0470*, s32);
extern u8 D_800F1F94_ovl12[][6];

void DEDUP_NAME(Obj0470* obj) {
    if (++obj->unk7C == 100) {
        DEDUP_CALLEE(obj, 9);
    }
    if (obj->unk46 == 0) {
        DEDUP_CALLEE(obj, 1);
        obj->unk5 = D_800F1F94_ovl12[obj->unk86][obj->unk87++];
        obj->unk6 = 0;
    }
}
