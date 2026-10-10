/* Shared body (DK-5), from the banked draft of func_800FA08C_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(ObjFA284*);

void DEDUP_NAME(ObjFA284* o) {
    DEDUP_CALLEE(o);
    if (((signed char*)o)[0x45] == 1) {
        o->timer = 0xF;
        o->step++;
    }
}
