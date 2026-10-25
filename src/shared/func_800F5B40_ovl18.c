/* Shared body (DK-5), from the banked draft of func_800F5B40_ovl18 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800F7F9C_ovl18[])(Obj5B40*);

void DEDUP_NAME(Obj5B40* self) {
    if (((Obj5B40*)self->unk14)->unk4 == 2) {
        self->unk4 = 2;
    }
    D_800F7F9C_ovl18[self->unk4](self);
}
