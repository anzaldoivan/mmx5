/* Shared body (DK-5), from the banked draft of func_800F04D0_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Ent04D0*);

void DEDUP_NAME(Ent04D0* obj) {
    DEDUP_CALLEE(obj);
    if (--obj->unk7C == 0) {
        obj->unk8C = 0;
        obj->unk7C = 90;
        if (obj->unk80 == 0) {
            obj->unk5 = 3;
            obj->unk6 = 0;
        } else {
            obj->unk20 = 0;
            obj->unk2C = 0x4000;
            obj->unk5 = 4;
            obj->unk6 = 1;
        }
        if (obj->unk2 == 1) {
            obj->unk5 = 5;
            obj->unk6 = 0;
            obj->unk7C = 60;
        }
    }
}
