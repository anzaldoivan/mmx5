/* Shared body (DK-5), from the banked draft of func_800EEFB4_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(Ent08D8* e) {
    animate_object(e);
    if (e->unk70 & 8) {
        e->unk5 = 2;
        e->unk6 = 0;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk67 = 0;
    } else {
        apply_object_motion(e);
    }
}
