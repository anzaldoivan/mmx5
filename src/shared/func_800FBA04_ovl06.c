/* Shared body (DK-5), from the banked draft of func_800FBA04_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(ObjFBA04*, s32);
extern s32 func_80016490(s32, s32, void*);

void DEDUP_NAME(ObjFBA04* obj) {
    if (obj->timer == 0) {
        func_800171E8(obj, 0x12);
        func_80016490(2, 0x18, obj);
        obj->state++;
        obj->unk60 = 6;
        return;
    }
    obj->timer--;
}
