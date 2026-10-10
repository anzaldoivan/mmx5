/* Shared body (DK-5), from the banked draft of func_800F140C_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj4FE0*, s32);

void DEDUP_NAME(Obj4FE0* s) {
    s->unk6++;
    s->unk20 = 0;
    s->unk28 = 0;
    s->unk24 = 0x20000;
    s->unk2C = 0;
    DEDUP_CALLEE(s, 1);
}
