/* Shared body (DK-5), from the banked draft of func_800F0D10_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Ent0D10*);
extern s16 D_8009A0AA;

void DEDUP_NAME(Ent0D10* obj) {
    if (obj->unk8C != 1) {
        obj->unk8C--;
    }
    DEDUP_CALLEE(obj);
    if (--obj->unk7C == 0) {
        obj->unk89 = 0;
        obj->unk8A = 0;
        if ((obj->unk15 == 0 && D_8009A0AA > obj->unkA) ||
            (obj->unk15 != 0 && D_8009A0AA < obj->unkA)) {
            obj->unk7C = 20;
            obj->unk28 = 0;
            obj->unk24 = 0;
            obj->unk5 = 4;
        } else {
            obj->unk5 = 6;
        }
        obj->unk6 = 0;
    }
}
