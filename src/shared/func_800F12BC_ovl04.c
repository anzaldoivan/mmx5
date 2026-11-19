/* Shared body (DK-5), from the banked draft of func_800F12BC_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"

void DEDUP_NAME(Ent12BC* self) {
    if (--self->timer == -1) {
        self->state = 8;
        self->sub = 0;
    }
    DEDUP_CALLEE(self);
}
