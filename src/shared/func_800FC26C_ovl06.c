/* Shared body (DK-5), from the banked draft of func_800FC26C_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800FF744_ovl06[])(Fc26cObj*);

void DEDUP_NAME(Fc26cObj* o) {
    Fc26cObj* p = o->unk50;

    o->unkA = p->unkA;
    o->unkE = p->unkE;
    o->unk15 = p->unk15;
    o->unk42 &= 0x7FFF;
    o->unk42 |= p->unk42 & 0x8000;
    D_800FF744_ovl06[o->unk6](o);
}
