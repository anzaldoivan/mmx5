/* Shared body (DK-5), from the banked draft of func_800F0418_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define SCR0418 D_1F80004C.scr0418
void DEDUP_NAME(Obj* o) {
    Scr0418* s = SCR0418;

    if (s->unk88.h.hi >= 0x40 || s->unk87 != 0) {
        s->unk86 = 0x3C;
        o->step++;
        return;
    }
    s->unk88.w += s->unk8C;
    SCR0418->unk8C += 0x4000;
}
