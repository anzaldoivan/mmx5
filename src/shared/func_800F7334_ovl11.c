/* Shared body (DK-5), from the banked draft of func_800F7334_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void DEDUP_NAME(Ent7334* e) {
    if (e->x < D_800FA056_ovl11) {
        e->x += 2;
    } else if (D_800FA058_ovl11 < e->x) {
        e->x -= 2;
    }
    move_object(e);
    animate_object(e);
    if (--e->timer == 0) {
        set_animation(e, 2);
        e->timer = 90;
        e->state++;
    }
}
