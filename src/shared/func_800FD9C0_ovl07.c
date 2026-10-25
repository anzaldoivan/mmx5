/* Shared body (DK-5), from the banked draft of func_800FD9C0_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(EntFD9C0*);

void DEDUP_NAME(EntFD9C0* e) {
    DEDUP_CALLEE(e);
    if (e->unk7 == 0) {
        e->unk90 = 60;
        e->unk7++;
    } else if (e->unk7 == 1) {
        if (e->unk90 & 1) {
            e->unk3 = 1;
        } else {
            e->unk3 = 0;
        }
        if (--e->unk90 == -1) {
            e->unk4 = 2;
        }
    }
}
