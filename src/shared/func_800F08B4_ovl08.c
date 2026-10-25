/* Shared body (DK-5), from the banked draft of func_800F08B4_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern void func_80017248(Obj08B4*);
extern s8 func_8002E024(Obj08B4*, u8*);

void DEDUP_NAME(Obj08B4* obj) {
    func_80017248(obj);
    if (--obj->timer != 0) {
        return;
    }
    if (obj->flip == 0) {
        obj->x -= 6;
    } else {
        obj->x += 6;
    }
    obj->hit = func_8002E024(obj, D_8009A0A0);
    if (obj->flip == 0) {
        obj->x += 6;
    } else {
        obj->x -= 6;
    }
    obj->state = 2;
}
