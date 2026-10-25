/* Shared body (DK-5), from the banked draft of func_800F0364_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 D_800FC574_ovl01[];
extern s32 D_800FC578_ovl01[];
extern void func_800F0810_ovl01(Obj0364*);
extern void func_800171E8(Obj0364*, s32);

void DEDUP_NAME(Obj0364* obj) {
    if (obj->mode == 2) {
        obj->p54 = D_800FC574_ovl01;
        obj->p50 = D_800FC578_ovl01;
    }
    if (--obj->timer == 0) {
        func_800F0810_ovl01(obj);
        func_800171E8(obj, 2);
        obj->h7E = 3;
        obj->state = 2;
    }
}
