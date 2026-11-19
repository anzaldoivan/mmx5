/* Shared body (DK-5), from the banked draft of func_800F9364_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FB448_ovl00[][6];

void DEDUP_NAME(Ent9364* e) {
    if (e->unk46 == 0) {
        u8 t;
        set_animation(e, 0);
        t = D_800FB448_ovl00[e->unk8D][e->unk8E++];
        e->unk6 = 0;
        e->unk5 = t;
    }
    animate_object(e);
    apply_object_motion(e);
}
