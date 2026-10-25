/* Shared body (DK-5), from the banked draft of func_800F77E8_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;
extern void func_80017248(Obj77E8*);
extern void func_800171E8(Obj77E8*, s32);

void DEDUP_NAME(Obj77E8* obj) {
    func_80017248(obj);
    if (--obj->timer == 0) {
        if (obj->x > D_8009A0AA) {
            obj->flip = 0;
        } else {
            obj->flip = 0x40;
        }
        func_800171E8(obj, 9);
        obj->state++;
    }
}
