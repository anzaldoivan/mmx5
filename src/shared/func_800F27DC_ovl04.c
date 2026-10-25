/* Shared body (DK-5), from the banked draft of func_800F27DC_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern Obj66A0 D_8009A0A0;
extern void DEDUP_CALLEE(Obj66A0*);

void DEDUP_NAME(Obj66A0* e) {
    s32 d;

    d = D_8009A0A0.unkE - e->unkE;
    if (d >= 0 ? d >= 4 : e->unkE - D_8009A0A0.unkE >= 4) {
        if (D_8009A0A0.unkE >= e->unkE) {
            e->unk24 = -0x10000;
        } else {
            e->unk24 = 0x10000;
        }
    } else {
        e->unk24 = 0;
    }
    DEDUP_CALLEE(e);
    if (--e->unk7C == -1) {
        e->unk5 = 3;
        e->pad6[0] = 0;
    }
}
