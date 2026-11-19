/* Shared body (DK-5), from the banked draft of func_800FAE14_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void start_pad_vibration(s32);

void DEDUP_NAME(ObjFA284* o) {
    apply_object_motion(o);
    func_8002FB58(o);
    animate_object(o);
    if (o->flags70 & 8) {
        start_pad_vibration(5);
        play_sound(2, 7, o);
        o->timer = 0x14;
        o->step++;
    }
}
