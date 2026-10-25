/* Shared body (DK-5), from the banked draft of func_800FC308_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes
void DEDUP_CALLEE(ObjFC308* self);

void DEDUP_NAME(ObjFC308* self) {
    if (--self->timer == -1) {
        G[0x92] = 0;
        DEDUP_CALLEE(self);
    }
}
