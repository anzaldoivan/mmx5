/* Shared body (DK-5), from the banked draft of func_800F0FC8_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define SCRATCH_CTX D_1F80004C.ctx0f18
void DEDUP_NAME(Ent0FC8* a0) {
    a0->unk20 = 0;
    a0->unk28 = 0;
    a0->unk24 = 0;
    a0->unk2C = 0;
    a0->unk6++;
    if (a0->unk2 == 3) {
        SCRATCH_CTX->unk80 = 1;
    } else {
        SCRATCH_CTX->unk80 = 20;
    }
}
