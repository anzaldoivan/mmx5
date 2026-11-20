/* Shared body (DK-5), from the banked draft of func_800F62C8_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FAE64_ovl09[])(Ent62C8*);

void DEDUP_NAME(Ent62C8* e) {
    if (e->unk94 < 0x50) {
        e->unk94 = 0x64;
    }
    D_800FAE64_ovl09[e->unk6](e);
    DEDUP_CALLEE(e, 0x64, 0x64);
}
