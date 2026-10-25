/* Shared body (DK-5), from the banked draft of func_800FDBC0_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_80101E88_ovl07[])(Ovl07Ent*);

void DEDUP_NAME(Ovl07Ent* e) {
    if (e->unk8E != 0 && ((Ovl07Ent*)e->unk7C)->unk8E == 2) {
        e->unk24 = -0x18000;
        e->unk20 = 0;
        e->unk8E = 0;
        e->unk5 = 5;
        e->unk6 = 0;
        return;
    }
    D_80101E88_ovl07[e->unk6](e);
}
