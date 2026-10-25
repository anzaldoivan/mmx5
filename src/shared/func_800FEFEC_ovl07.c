/* Shared body (DK-5), from the banked draft of func_800FEFEC_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(EntFEFEC*);

void DEDUP_NAME(EntFEFEC* self) {
    ParentFEFEC* parent = self->parent;

    if (parent->unk4 == 2 || parent->unk92 == 0) {
        self->unk4 = 2;
        self->unk3 = 0;
    } else {
        self->unk15 = parent->unk15;
        self->unkA = parent->unkA;
        self->unkE = parent->unkE;
        DEDUP_CALLEE(self);
        self->unk3 = 1;
    }
}
