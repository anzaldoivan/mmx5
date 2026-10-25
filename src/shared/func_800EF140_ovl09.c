/* Shared body (DK-5), from the banked draft of func_800EF140_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern int DEDUP_CALLEE();

void DEDUP_NAME(Ovl09Obj800EF140* obj) {
    obj->unk58 = 0;
    obj->unk50 = 0;
    obj->unk54 = 0;
    obj->unk3 = 0;
    if (obj->unk93 == 0) {
        u8* p = obj->unk80;
        if (obj->unk95 != 0) {
            p[obj->unk2 + 0xF] = 0;
        }
        DEDUP_CALLEE(obj);
    } else {
        obj->unk93--;
    }
}
