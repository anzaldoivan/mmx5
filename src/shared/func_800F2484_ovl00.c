/* Shared body (DK-5), from the banked draft of func_800F2484_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj800EFBC4*, s32);

void DEDUP_NAME(Obj800EFBC4* o) {
    s32 vx;

    if (--o->unk7C == -1) {
        DEDUP_CALLEE(o, 4);
        vx = -0x28000;
        if (o->unk15) {
            vx = 0x28000;
        }
        o->unk20 = vx;
        o->unk24 = 0;
        o->unk28 = 0;
        o->unk2C = 0;
        o->unk6++;
    }
}
