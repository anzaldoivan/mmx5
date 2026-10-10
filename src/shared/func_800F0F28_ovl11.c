/* Shared body (DK-5), from the banked draft of func_800F0F28_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Ent08D8* e) {
    s32 v;

    if ((s8)e->unk67 == 0 && !(e->unk70 & 8)) {
        v = 6;
        e->unk5 = v;
        v = 0x4200;
        e->unk2C = v;
        e->unk6 = 0;
        e->unk24 = 0;
        e->unk20 = 0;
        e->unk28 = 0;
        e->unk67 = 1;
    }
}
