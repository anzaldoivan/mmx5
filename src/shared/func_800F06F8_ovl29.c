/* Shared body (DK-5), from the banked draft of func_800F06F8_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Ent06F8* obj) {
    apply_object_motion(obj);
    animate_object(obj);
    if (obj->unk24 == 0 && obj->unk8C != 0) {
        obj->unk2C = 0;
        obj->state = 2;
        obj->substate = 0;
    }
    if (obj->flags70 & 8) {
        obj->unk24 = 0;
        obj->unk2C = 0;
        set_animation(obj, 0x11);
        obj->substate = 2;
    }
}
