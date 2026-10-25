/* Shared body (DK-5), from the banked draft of func_800FA55C_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800FAEF8_ovl06(Obj0364*);
extern void func_800171E8(Obj0364*, s32);
extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];

void DEDUP_NAME(Obj0364* o) {
    func_800FAEF8_ovl06(o);
    func_800171E8(o, 7);
    o->p50 = D_800FF1CC_ovl06;
    o->p54 = D_800FF1D0_ovl06;
    o->timer = 1;
    o->h7E = 2;
    o->state++;
}
