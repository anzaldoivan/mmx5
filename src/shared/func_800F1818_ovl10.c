/* Shared body (DK-5), from the banked draft of func_800F1818_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(X4_Obj* self) {
    if (--self->unk7C == -1) {
        self->unk5 = 3;
        self->unk6 = 0;
    }
}
