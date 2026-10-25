/* Shared body (DK-5), from the banked draft of func_800FA858_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(Obj0364*);
extern void func_800171E8(Obj0364*, s32);
extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];

void DEDUP_NAME(Obj0364* o) {
    func_80017248(o);
    if (o->mode == 1) {
        func_800171E8(o, 0x1C);
        o->p50 = D_800FF1CC_ovl06;
        o->p54 = D_800FF1D0_ovl06;
        o->timer = 0x30;
        o->h7E = 0;
        D_1F80004C.scr01a8->unk8A = 0;
        o->state++;
    }
}
