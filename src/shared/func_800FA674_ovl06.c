/* Shared body (DK-5), from the banked draft of func_800FA674_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(EntFA5C0*);
extern void func_80016490(s32, s32, void*);
extern void func_800FAF38_ovl06(EntFA5C0*, s32, s32, s32);
extern void func_800F9180_ovl06(EntFA5C0*);

void DEDUP_NAME(EntFA5C0* obj) {
    func_80017248(obj);
    if (obj->mode == 2) {
        func_80016490(2, 30, obj);
        func_800FAF38_ovl06(obj, obj->x, obj->y, 0);
    }
    if (--obj->timer == 0) {
        func_800F9180_ovl06(obj);
    }
}
