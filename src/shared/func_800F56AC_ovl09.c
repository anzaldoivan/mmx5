/* Shared body (DK-5), from the banked draft of func_800F56AC_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002D9EC(Obj56AC*, s32, s32);
extern void func_800171E8(Obj56AC*, s32);
extern void func_80017248(Obj56AC*);
extern void func_8002DED4(Obj56AC*);

void DEDUP_NAME(Obj56AC* obj) {
    if (++obj->timer == 100) {
        obj->timer = 0;
        obj->state++;
        func_8002D9EC(obj, 0x40, 0x40);
    }
    if (obj->flag46 == 0) {
        func_800171E8(obj, 0);
    }
    func_80017248(obj);
    func_8002DED4(obj);
    if (obj->timer >= 31 || (obj->timer & 1)) {
        func_8002D9EC(obj, 0x40, 0x40);
    }
}
