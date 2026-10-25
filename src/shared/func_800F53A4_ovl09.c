/* Shared body (DK-5), from the banked draft of func_800F53A4_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(Obj53A4*);
extern void (*D_800FAD88_ovl09[])(Obj53A4*);
extern void (*D_800FAD94_ovl09[])(Obj53A4*);

void DEDUP_NAME(Obj53A4* o) {
    if (o->f2 == 1) {
        o->f18 = o->f8;
        o->f1C = o->fC;
        o->f3 = 0;
        D_800FAD88_ovl09[o->f4](o);
        DEDUP_CALLEE(o);
    } else {
        o->f18 = o->f8;
        o->f1C = o->fC;
        o->f3 = 0;
        D_800FAD94_ovl09[o->f4](o);
        DEDUP_CALLEE(o);
    }
}
