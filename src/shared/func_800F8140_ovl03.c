/* Shared body (DK-5), from the banked draft of func_800F8140_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj8140*, s32, s32);
extern void (*D_800FA1C4_ovl03[])(Obj8140*);

void DEDUP_NAME(Obj8140* e) {
    if (e->unk90 < 0x50) {
        e->unk90 = 0x64;
    }
    D_800FA1C4_ovl03[e->unk6](e);
    DEDUP_CALLEE(e, 0x64, 0x64);
}
