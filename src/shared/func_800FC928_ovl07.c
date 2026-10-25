/* Shared body (DK-5), from the banked draft of func_800FC928_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(ObjFC928*, s32);
extern u8 D_80101808_ovl07[];
extern u8 D_80101804_ovl07[];

void DEDUP_NAME(ObjFC928* obj) {
    obj->p54 = D_80101808_ovl07;
    obj->p50 = D_80101804_ovl07;
    D_1F80004C.bytes[0x92] = 0;
    DEDUP_CALLEE(obj, 0x16);
    obj->timer = 40;
    obj->state++;
}
