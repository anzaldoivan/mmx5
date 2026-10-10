/* Shared body (DK-5), from the banked draft of func_800F1B34_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Ent08D8*);

void DEDUP_NAME(Ent08D8* e) {
    DEDUP_CALLEE(e);
    if (e->unk70 & 8) {
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk20 = 0;
        e->unk28 = 0;
        e->unk67 = 0;
        e->unk5 = 2;
        e->unk6 = 0;
    }
}
