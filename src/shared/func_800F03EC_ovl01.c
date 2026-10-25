/* Shared body (DK-5), from the banked draft of func_800F03EC_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(Ent03EC*);
extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);

void DEDUP_NAME(Ent03EC* obj) {
    if (--obj->x84 == 0) {
        obj->x84 = 20;
    }
    func_80017248(obj);
    if (--obj->x7E == 0) {
        func_8005019C(1, 2, obj, 8, 1);
        obj->x7E = 3;
    }
    if (obj->x45 != 0) {
        if (obj->x15 == 0) {
            obj->x20 = -0x40000;
        } else {
            obj->x20 = 0x40000;
        }
        obj->x6 = 3;
    }
}
