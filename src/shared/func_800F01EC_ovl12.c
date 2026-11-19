/* Shared body (DK-5), from the banked draft of func_800F01EC_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Ent* e) {
    set_animation(e, 4);
    if (D_8009A0AA > e->y) {
        e->flag15 = 0x40;
    } else {
        e->flag15 = 0;
    }
    e->state++;
    animate_object(e);
    apply_object_motion(e);
}
