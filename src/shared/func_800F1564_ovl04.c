/* Shared body (DK-5), from the banked draft of func_800F1564_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Ent1564*);

void DEDUP_NAME(Ent1564* self) {
    if (--self->timer == -1) {
        self->field16 = 3;
        self->state = 7;
        self->sub = 0;
        return;
    }
    DEDUP_CALLEE(self);
}
