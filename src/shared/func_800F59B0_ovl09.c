/* Shared body (DK-5), from the banked draft of func_800F59B0_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;
extern void (*D_800FADFC_ovl09[])(Ent59B0*);
extern void DEDUP_CALLEE(Ent59B0* obj, s32 a, s32 b);

void DEDUP_NAME(Ent59B0* obj) {
    if (D_8009A0AA > obj->unkA) {
        obj->unk15 = 0x40;
    } else {
        obj->unk15 = 0;
    }
    D_800FADFC_ovl09[obj->unk6](obj);
    DEDUP_CALLEE(obj, 0x40, 0x40);
}
