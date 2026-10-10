/* Shared body (DK-5), from the banked draft of func_800F1040_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct Ctx1040 {
    u8 pad0[0x80];
    signed char unk80;
    u8 pad81;
    signed char unk82;
} Ctx1040;

#define SCRATCH_CTX (*(Ctx1040**)0x1F80004C)

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
