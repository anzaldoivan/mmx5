/* Shared body (DK-5), from the banked draft of func_800F7D8C_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(Obj7D8C* obj);
extern void func_8002DED4(Obj7D8C* obj);

void DEDUP_NAME(Obj7D8C* obj) {
    if (++obj->timer == 20) {
        if (obj->kind == 2) {
            obj->vel = 0x30000;
        } else {
            obj->vel = -0x30000;
        }
        obj->timer = 1;
        obj->step++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
