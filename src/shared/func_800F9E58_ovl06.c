/* Shared body (DK-5), from the banked draft of func_800F9E58_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(Obj*);

void DEDUP_NAME(Obj* o) {
    func_80017248(o);
    if (--o->timer == 0) {
        o->step++;
    }
}
