/* Shared body (DK-5), from the banked draft of func_800F9D90_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/globals.h"

void DEDUP_NAME(ObjFA284* o) {
    animate_object(o);
    if (--o->timer == 0) {
        func_800F9180_ovl06(o);
    }
}
