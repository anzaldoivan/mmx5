/* Shared body (DK-5), from the banked draft of func_800F5C58_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(Ent800F5C58* e) {
    s16 x = e->unkA;

    if (D_8009A0AA < x) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
}
