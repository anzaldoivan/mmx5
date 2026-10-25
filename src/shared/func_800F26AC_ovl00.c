/* Shared body (DK-5), from the banked draft of func_800F26AC_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_CALLEE(ObjFE130* self);

void DEDUP_NAME(ObjFE130* self) {
    D_1F80004C.scr0b1c->unk80 = -0x1A - self->unk45;
    if (self->unk45 == 1) {
        /* 0x89 lies past Scr0B1C's proven fields */
        ((u8*)D_1F80004C.scr0b1c)[0x89] = 0;
        DEDUP_CALLEE(self);
    }
}
