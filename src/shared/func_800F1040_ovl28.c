/* Shared body (DK-5), from the banked draft of func_800F1040_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define SCRATCH_CTX D_1F80004C.ctx1040
void DEDUP_NAME(Ent* a0) {
    Ctx1040* c;

    c = SCRATCH_CTX;
    if (c->unk82 >= 3) {
        a0->state++;
        SCRATCH_CTX->unk82 = 0;
        SCRATCH_CTX->unk80 = 20;
        return;
    }
    if (--c->unk80 == 0) {
        a0->state--;
    }
}
