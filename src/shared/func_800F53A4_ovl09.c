#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FAD88_ovl09[])(Obj53A4*);
extern void (*D_800FAD94_ovl09[])(Obj53A4*);

void func_800F53A4_ovl09(Obj53A4* o) {
    if (o->f2 == 1) {
        o->f18 = o->f8;
        o->f1C = o->fC;
        o->f3 = 0;
        D_800FAD88_ovl09[o->f4](o);
        func_8002FB58(o);
    } else {
        o->f18 = o->f8;
        o->f1C = o->fC;
        o->f3 = 0;
        D_800FAD94_ovl09[o->f4](o);
        func_8002FB58(o);
    }
}
