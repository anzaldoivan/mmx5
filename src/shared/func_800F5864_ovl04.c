/* Shared body (DK-5), from the banked draft of func_800F5864_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern signed char D_800D1C0C;

void DEDUP_NAME(Obj5864* obj) {
    s32 goal = 0x70;

    if (D_800D1C0C != 12) {
        goal = 0x60;
    }
    if (obj->unk7C != 0) {
        if (--obj->unk7C == 0) {
            set_animation(obj, 3);
        }
        return;
    }
    if (goal < obj->unkE) {
        obj->unkE--;
    } else if (obj->unkE < goal) {
        obj->unkE++;
    } else {
        obj->unk7C = 30;
        obj->unk6++;
        set_animation(obj, 0x19);
    }
    animate_object(obj);
}
