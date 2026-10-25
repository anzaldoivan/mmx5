/* Shared body (DK-5), from the banked draft of func_800F0E50_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj0E50*, s32);

void DEDUP_NAME(Obj0E50* obj) {
    obj->u16 = 7;
    switch (obj->state) {
    case 0:
    case 1:
        DEDUP_CALLEE(obj, 4);
        obj->u15 = 0;
        obj->u5 = 0;
        break;
    case 2:
        DEDUP_CALLEE(obj, 7);
        obj->u15 = 0;
        obj->u5 = 1;
        break;
    case 3:
        DEDUP_CALLEE(obj, 7);
        obj->u15 = 0x40;
        obj->u5 = 2;
        break;
    }
    obj->u20 = 0;
    obj->u28 = 0;
    obj->u24 = 0;
    obj->u2C = 0;
    obj->u4 = 1;
}
