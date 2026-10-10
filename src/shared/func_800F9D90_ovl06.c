/* Shared body (DK-5), from the banked draft of func_800F9D90_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(ObjFA284*);
extern void func_800F9180_ovl06(ObjFA284*);

void DEDUP_NAME(ObjFA284* o) {
    func_80017248(o);
    if (--o->timer == 0) {
        func_800F9180_ovl06(o);
    }
}
