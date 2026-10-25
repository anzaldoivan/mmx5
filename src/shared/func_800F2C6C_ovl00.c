/* Shared body (DK-5), from the banked draft of func_800F2C6C_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj2C6C*);

void DEDUP_NAME(Obj2C6C* obj) {
    if (obj->flags70 & 8) {
        obj->unk24 = 0;
        obj->unk2C = 0;
        obj->unk20 = 0;
        obj->unk28 = 0;
        obj->unk67 = 0;
        obj->state++;
    } else {
        DEDUP_CALLEE(obj);
    }
}
