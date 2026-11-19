/* Shared body (DK-5), from the banked draft of func_800F63B4_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(Ent08D8* e) {
    if (e->unk70 & 8) {
        e->unk24 = 0x40000;
        e->unk2C = 0x6000;
        e->unk6++;
    }
    animate_object(e);
    apply_object_motion(e);
}
