/* Shared body (DK-5), from the banked draft of func_800F4460_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800FA2E0_ovl29[][6];

void DEDUP_NAME(Ovl29Obj* obj) {
    if (obj->unk8F == 0) {
        obj->unk5 = D_800FA2E0_ovl29[obj->unk8D][obj->unk8E];
        obj->unk6 = 0;
        obj->unk8E++;
    } else {
        obj->unk8F--;
    }
}
