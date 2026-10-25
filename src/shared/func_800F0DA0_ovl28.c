/* Shared body (DK-5), from the banked draft of func_800F0DA0_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define SCR_4C D_1F80004C.ctx0f18
extern void DEDUP_CALLEE(Ent0DA0*, s32);

void DEDUP_NAME(Ent0DA0* e) {
    s32 v;

    v = -0x8000;
    e->unk67 = 1;
    e->unk6++;
    if (e->unk15 != 0) {
        v = 0x8000;
    }
    e->unk20 = v;
    e->unk28 = 0;
    e->unk24 = 0;
    e->unk2C = 0;
    SCR_4C->unk80 = 0x30;
    DEDUP_CALLEE(e, 0);
}
