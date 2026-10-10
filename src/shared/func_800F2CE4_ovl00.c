/* Shared body (DK-5), from the banked draft of func_800F2CE4_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Ent08D8* e) {
    if (!(e->unk70 & 8)) {
        e->unk5 = 8;
        e->unk6 = 0;
        e->unk2C = 0x4200;
        e->unk24 = 0;
        e->unk20 = 0;
        e->unk28 = 0;
        e->unk67 = 1;
    }
}
