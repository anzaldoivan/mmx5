/* Shared body (DK-5), from the banked draft of func_800EF424_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

s32 DEDUP_CALLEE(ObjF424* a0);
extern void (*D_800F5008_ovl05[])(ObjF424*);

void DEDUP_NAME(ObjF424* o) {
    if (o->unk84 == 0 && o->unk70 == 0) {
        DEDUP_CALLEE(o);
    }
    D_800F5008_ovl05[o->state](o);
}
