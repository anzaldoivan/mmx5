/* Shared body (DK-5), from the banked draft of func_800F0938_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Ent08D8* e) {
    if (!(e->unk70 & 8)) {
        e->unk5 = 6;
        e->unk6 = 0;
        e->unk2C = 0x4200;
        e->unk24 = 0;
        e->unk20 = 0;
        e->unk28 = 0;
        e->unk67 = 1;
    }
}
