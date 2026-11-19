/* Shared body (DK-5), from the banked draft of func_800F08B4_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern s8 func_8002E024(Obj08B4*, u8*);

void DEDUP_NAME(Obj08B4* obj) {
    animate_object(obj);
    if (--obj->timer != 0) {
        return;
    }
    if (obj->flip == 0) {
        obj->x -= 6;
    } else {
        obj->x += 6;
    }
    obj->hit = func_8002E024(obj, g_Player);
    if (obj->flip == 0) {
        obj->x += 6;
    } else {
        obj->x -= 6;
    }
    obj->state = 2;
}
