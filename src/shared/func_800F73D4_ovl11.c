/* Shared body (DK-5), from the banked draft of func_800F73D4_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void DEDUP_NAME(Obj73D4* o) {
    apply_object_motion(o);
    animate_object(o);
    if (o->x <= D_800FA056_ovl11 - 0x18) {
        o->x = D_800FA056_ovl11 - 0x18;
    } else if (o->x >= D_800FA058_ovl11 + 0x18) {
        o->x = D_800FA058_ovl11 + 0x18;
    }
    if (o->flags & 8) {
        set_animation(o, 0);
        o->timer = 0x14;
        o->state = 5;
        o->unk24 = 0;
        o->unk2C = 0;
        if (o->facing == 0) {
            o->vx = -0x40000;
        } else {
            o->vx = 0x40000;
        }
        set_animation(o, 4);
        o->vy = -0x1999;
    }
}
