/* Shared body (DK-5), from the banked draft of func_800F5A88_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s8 func_8002E024(Obj5A88*, u8*);

void DEDUP_NAME(Obj5A88* obj) {
    s8 v;

    if (--obj->timer == 0) {
        set_animation(obj, 4);
        v = func_8002E024(obj, g_Player);
        obj->unk92 = v;
        if ((u8)v < 9) {
            obj->unk92 = 0x1F;
        } else if ((u8)(v - 9) < 8) {
            obj->unk92 = 0x11;
        }
        obj->unk84 = 0;
        obj->unk88 = 0x2000;
        obj->timer = 0;
        obj->state++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
