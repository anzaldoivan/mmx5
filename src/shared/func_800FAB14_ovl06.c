/* Shared body (DK-5), from the banked draft of func_800FAB14_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void start_pad_vibration(s32);
extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];

void DEDUP_NAME(ObjFA284* o) {
    apply_object_motion(o);
    func_8002FB58(o);
    animate_object(o);
    if (o->flags70 & 8) {
        start_pad_vibration(5);
        play_sound(2, 7, o);
        set_animation(o, 0x15);
        o->p50 = D_800FF1CC_ovl06;
        o->p54 = D_800FF1D0_ovl06;
        o->timer = 0x3C;
        o->step++;
    }
}
