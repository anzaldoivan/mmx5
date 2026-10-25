/* Shared body (DK-5), from the banked draft of func_800F9AD8_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj9AD8*, s32);
extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];

void DEDUP_NAME(Obj9AD8* obj) {
    DEDUP_CALLEE(obj, 2);
    obj->unk50 = D_800FF1CC_ovl06;
    obj->unk54 = D_800FF1D0_ovl06;
    obj->timer = 120;
    obj->state++;
}
