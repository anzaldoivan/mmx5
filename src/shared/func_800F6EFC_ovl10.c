/* Shared body (DK-5), from the banked draft of func_800F6EFC_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800FBF88_ovl10[])(Actor7C*);

void DEDUP_NAME(Actor7C* obj) {
    Actor7CLink* other;

    obj->unk18 = obj->unk8;
    obj->unk1C = obj->unkC;
    other = obj->unk7C;
    D_800FBF88_ovl10[obj->state](obj);
    if (other->state == 2) {
        obj->state = 3;
    }
}
