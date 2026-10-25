/* Shared body (DK-5), from the banked draft of func_800F4FD4_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(Obj4FD4*);
extern void func_8002DF54(Obj4FD4*);
extern void func_800171E8(Obj4FD4*, s32);

void DEDUP_NAME(Obj4FD4* obj) {
    obj->unk3 = 1;
    func_80017248(obj);
    func_8002DF54(obj);
    if (--obj->timer == 0) {
        obj->state++;
        func_800171E8(obj, 0);
    }
}
