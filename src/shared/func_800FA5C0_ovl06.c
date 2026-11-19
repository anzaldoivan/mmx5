/* Shared body (DK-5), from the banked draft of func_800FA5C0_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_800FAF38_ovl06(EntFA5C0*, s32, s32, s32);

void DEDUP_NAME(EntFA5C0* obj) {
    animate_object(obj);
    if (--obj->timer == 0) {
        func_800FAEF8_ovl06(obj);
        set_animation(obj, 7);
        obj->timer = 90;
        if (--obj->count == 0) {
            obj->state++;
        }
    }
    if (obj->mode == 2) {
        play_sound(2, 30, obj);
        func_800FAF38_ovl06(obj, obj->x, obj->y, 0);
    }
}
