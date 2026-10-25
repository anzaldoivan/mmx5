/* Shared body (DK-5), from the banked draft of func_800F1544_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Ent800FE04C* e) {
    e->unk6++;
    e->unk20 = 0x30000;
    *(s16*)((u8*)e + 0x7C) = 0x28;
}
