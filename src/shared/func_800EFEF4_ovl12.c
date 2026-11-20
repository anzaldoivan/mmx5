/* Shared body (DK-5), from the banked draft of func_800EFEF4_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Ent* e) {
    DEDUP_CALLEE(e, 2);
    if (D_8009A0AA > e->y) {
        e->flag15 = 0x40;
    } else {
        e->flag15 = 0;
    }
    e->state++;
}
