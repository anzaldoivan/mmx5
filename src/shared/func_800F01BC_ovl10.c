/* Shared body (DK-5), from the banked draft of func_800F01BC_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 func_80030AE4(Obj01BC*, s16, s16);
extern void func_800171E8(Obj01BC*, s32);
extern void func_8002DF54(Obj01BC*);
extern s16 D_8009A0AA;

void DEDUP_NAME(Obj01BC* obj) {
    if (func_80030AE4(obj, obj->x, obj->y) == 0x2D) {
        obj->state++;
        if (obj->f2 == 0) {
            obj->state = 4;
            func_800171E8(obj, 5);
        } else {
            func_800171E8(obj, 1);
        }
        obj->sub = 0;
        /* non-struct store: keeps the D_8009A0AA load after it (alias heuristic) */
        /* non-struct store: keeps the D_8009A0AA load after it (alias heuristic) */
        *(s16*)((u8*)obj + 0x7C) = 0;
        if (D_8009A0AA > obj->x) {
            obj->f20 = 0x10000;
        } else {
            obj->f20 = -0x10000;
        }
        obj->f24 = 0;
        obj->f28 = 0;
        obj->f2C = 0;
    } else {
        obj->f20 = 0;
        obj->f24 = -0x10000;
        func_8002DF54(obj);
    }
}
