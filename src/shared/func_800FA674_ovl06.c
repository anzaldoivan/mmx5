/* Shared body (DK-5), from the banked draft of func_800FA674_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern void func_800FAF38_ovl06(EntFA5C0*, s32, s32, s32);

void DEDUP_NAME(EntFA5C0* obj) {
    animate_object(obj);
    if (obj->mode == 2) {
        play_sound(2, 30, obj);
        func_800FAF38_ovl06(obj, obj->x, obj->y, 0);
    }
    if (--obj->timer == 0) {
        func_800F9180_ovl06(obj);
    }
}
