/* Shared body (DK-5), from the banked draft of func_800F9E58_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(Obj* o) {
    animate_object(o);
    if (--o->timer == 0) {
        o->step++;
    }
}
