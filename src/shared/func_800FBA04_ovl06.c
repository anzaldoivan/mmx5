/* Shared body (DK-5), from the banked draft of func_800FBA04_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(ObjFBA04* obj) {
    if (obj->timer == 0) {
        set_animation(obj, 0x12);
        play_sound(2, 0x18, obj);
        obj->state++;
        obj->unk60 = 6;
        return;
    }
    obj->timer--;
}
