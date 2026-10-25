/* Shared body (DK-5), from the banked draft of func_800F7744_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Obj*, s32);
extern void func_8002DED4(Obj*);
extern void func_8002D9EC(Obj*, s32, s32);
extern void func_80017248(Obj*);

void DEDUP_NAME(Obj* obj) {
    if (++obj->timer == 300) {
        func_800171E8(obj, 0);
    }
    if (obj->timer >= 300) {
        func_8002DED4(obj);
        func_8002D9EC(obj, 0x40, 0x40);
    }
    if (obj->timer >= 350) {
        func_80017248(obj);
    }
    if (obj->timer == 450) {
        func_800171E8(obj, 2);
        obj->timer = 0;
        obj->step++;
    }
}
